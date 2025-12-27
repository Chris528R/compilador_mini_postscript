#ifndef COMPILADOR_H
#define COMPILADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ESTRUCTURAS ---
typedef struct {
    char name[64];
    char type[32];   // "variable", "line", "rect", "circle", "proc"
    char value[512]; // Valor o contenido del array PostScript
    int is_global;   // 1 = Global, 0 = Local
} Symbol;

// --- VARIABLES GLOBALES ---
extern Symbol symbol_table[1000];
extern int symbol_count;

extern int line_num;
extern FILE* output_file;
extern char output_filename[256];

// Control de Procedimientos
extern int in_proc;
extern char current_proc[64];
extern char param_names[20][64];
extern int param_count_def;

// --- PROTOTIPOS DE FUNCIONES ---
void init_compiler(char* filename);
void finish_compiler();
void add_symbol(const char* name, const char* type, const char* value);
Symbol* find_symbol(const char* name);
void generate_ps_header();
void generate_ps_footer();

#endif