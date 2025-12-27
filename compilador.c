#include "compilador.h"

// --- IMPLEMENTACIÓN DE VARIABLES GLOBALES ---
Symbol symbol_table[1000];
int symbol_count = 0;

int line_num = 1;
FILE* output_file = NULL;
char output_filename[256];

int in_proc = 0;
char current_proc[64] = "";

char param_names[20][64];
int param_count_def = 0;

// --- IMPLEMENTACIÓN DE FUNCIONES ---

void init_compiler(char* filename) {
    // Limpiar comillas del nombre de archivo si vienen del token STRING
    char* clean_name = filename; 
    if(filename[0] == '"') clean_name++;
    
    strcpy(output_filename, clean_name);
    // Elimina comilla final si existe
    if(output_filename[strlen(output_filename)-1] == '"') 
        output_filename[strlen(output_filename)-1] = '\0';
        
    output_file = fopen(output_filename, "w");
    if (!output_file) {
        fprintf(stderr, "Error crítico: No se puede crear %s\n", output_filename);
        exit(1);
    }
    generate_ps_header();
}

void finish_compiler() {
    generate_ps_footer();
    if(output_file) fclose(output_file);
    printf("Transpilación exitosa. Archivo generado: %s\n", output_filename);
}

void add_symbol(const char* name, const char* type, const char* value) {
    // 1. Buscar si ya existe para actualizarlo
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            strcpy(symbol_table[i].type, type);
            strcpy(symbol_table[i].value, value);
            return;
        }
    }
    // 2. Si no existe, crear nuevo
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    strcpy(symbol_table[symbol_count].value, value);
    
    // Si estamos fuera de un proc, es Global. Si no, es Local.
    symbol_table[symbol_count].is_global = (in_proc == 0);
    
    symbol_count++;
}

Symbol* find_symbol(const char* name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return &symbol_table[i];
        }
    }
    return NULL;
}

void generate_ps_header() {
    fprintf(output_file, "%%!PS-Adobe-3.0\n");
    fprintf(output_file, "%%%%BoundingBox: 0 0 612 792\n");
    fprintf(output_file, "%%%%Creator: Compilador a PostScript\n");
    fprintf(output_file, "/pi 3.14159265359 def\n");
    fprintf(output_file, "1 setlinewidth\n");
    fprintf(output_file, "/Helvetica findfont 12 scalefont setfont\n\n");
}

void generate_ps_footer() {
    fprintf(output_file, "\nshowpage\n");
    fprintf(output_file, "%% Fin del programa\n");
}