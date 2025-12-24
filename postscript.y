%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

int line_num = 1;
FILE* output_file = NULL;
char output_filename[256];
int in_proc = 0;
char current_proc[64] = "";
char param_names[20][64]; // Máximo 20 parámetros
int param_count_def = 0;

typedef struct {
    char name[64];
    char type[32];
    char value[512];
} Symbol;

Symbol symbol_table[100];
int symbol_count = 0;

void add_symbol(const char* name, const char* type, const char* value);
Symbol* find_symbol(const char* name);
void generate_ps_header();
void generate_ps_footer();
%}

%union {
    int num;
    double fnum;
    char* str;
}

%token <num> NUMBER PARAM
%token <fnum> FLOAT
%token <str> IDENTIFIER STRING
%token BEGIN_TOKEN END_TOKEN LINE CIRCLE RECT COLOR STROKE FILL
%token IF ELSE WHILE FOR FUNCTION PROC RETURN
%token SETLINEWIDTH MOVETO LINETO SHOWPAGE PRINT
%token FUENTE TEXTO HELVETICA TIMES COURIER
%token SIN COS TAN SQRT ABS POW EXP LOG FLOOR CEIL
%token EQ NEQ LEQ GEQ AND OR

%type <str> expression term factor
%type <str> color_def line_def circle_def rect_def
%type <str> font_name math_function

%left OR
%left AND
%left EQ NEQ
%left '<' '>' LEQ GEQ
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

program:
    BEGIN_TOKEN STRING {
        char* filename = $2 + 1;
        filename[strlen(filename)-1] = '\0';
        strcpy(output_filename, filename);
        output_file = fopen(output_filename, "w");
        if (!output_file) {
            fprintf(stderr, "Error: No se puede crear el archivo %s\n", output_filename);
            exit(1);
        }
        generate_ps_header();
    }
    statements END_TOKEN {
        generate_ps_footer();
        fclose(output_file);
        printf("Archivo PostScript generado: %s\n", output_filename);
    }
    ;

statements:
    /* vacío */
    | statements statement
    ;

statement:
    assignment optional_semicolon
    | draw_command optional_semicolon
    | control_structure
    | proc_def
    | proc_call optional_semicolon
    | print_statement optional_semicolon
    | primitive_command optional_semicolon
    | text_command optional_semicolon
    ;

optional_semicolon:
    /* vacío - el ; es opcional */
    | ';'
    ;

assignment:
    IDENTIFIER '=' expression {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            add_symbol($1, "variable", $3);
            fprintf(output_file, "/%s %s def\n", $1, $3); 
        }
        free($3);
    }
    | IDENTIFIER '=' color_def {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            add_symbol($1, "color", $3);
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        }
        free($3);
    }
    | IDENTIFIER '=' line_def {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            add_symbol($1, "line", $3);
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        }
        free($3);
    }
    | IDENTIFIER '=' circle_def {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            add_symbol($1, "circle", $3);
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        }
        free($3);
    }
    | IDENTIFIER '=' rect_def {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            add_symbol($1, "rect", $3);
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        }
        free($3);
    }
    ;

color_def:
    COLOR '(' expression ',' expression ',' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s 255 div %s 255 div %s 255 div ]", $3, $5, $7);
        $$ = strdup(buffer);
        free($3); free($5); free($7);
    }
    ;

line_def:
    LINE '(' expression ',' expression ',' expression ',' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s %s %s %s ]", $3, $5, $7, $9);
        $$ = strdup(buffer);
        free($3); free($5); free($7); free($9);
    }
    ;

circle_def:
    CIRCLE '(' expression ',' expression ',' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s %s %s ]", $3, $5, $7);
        $$ = strdup(buffer);
        free($3); free($5); free($7);
    }
    ;

rect_def:
    RECT '(' expression ',' expression ',' expression ',' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s %s %s %s ]", $3, $5, $7, $9);
        $$ = strdup(buffer);
        free($3); free($5); free($7); free($9);
    }
    ;

draw_command:
    STROKE '(' IDENTIFIER ',' IDENTIFIER ')' {
        // Lógica unificada para Proc y Global
        // En ambos casos generamos código que asume que las variables existen en PS
        
        fprintf(output_file, "  gsave\n");
        
        // 1. Configurar color
        // Usamos el identificador del color directamente
        fprintf(output_file, "  %s aload pop setrgbcolor\n", $5); 
        
        // 2. Determinar tipo de forma y dibujar
        // Ponemos el array de la forma en la pila SIN desempaquetarlo aun
        fprintf(output_file, "  %s \n", $3); 
        
        // Verificamos longitud: [x y r] tiene 3, [x y w h] tiene 4
        fprintf(output_file, "  dup length 3 eq {\n");
        
        // RAMA CIRCULO (Longitud 3: x y r)
        // [x y r] -> aload -> x y r. Agregamos 0 360 arc.
        fprintf(output_file, "    aload pop 0 360 arc stroke\n");
        
        fprintf(output_file, "  } {\n");
        
        // RAMA RECTANGULO (Longitud 4: x y w h)
        // [x y w h] -> aload -> x y w h. Usamos rectstroke directo.
        fprintf(output_file, "    aload pop rectstroke\n");
        
        fprintf(output_file, "  } ifelse\n");
        fprintf(output_file, "  grestore\n");
    }
    |
    FILL '(' IDENTIFIER ',' IDENTIFIER ')' {
        fprintf(output_file, "  gsave\n");
        
        // 1. Configurar color
        fprintf(output_file, "  %s aload pop setrgbcolor\n", $5);
        
        // 2. Determinar tipo de forma
        fprintf(output_file, "  %s \n", $3);
        
        fprintf(output_file, "  dup length 3 eq {\n");
        
        // RAMA CIRCULO
        fprintf(output_file, "    aload pop 0 360 arc fill\n");
        
        fprintf(output_file, "  } {\n");
        
        // RAMA RECTANGULO
        // Usamos rectfill nativo
        fprintf(output_file, "    aload pop rectfill\n");
        
        fprintf(output_file, "  } ifelse\n");
        fprintf(output_file, "  grestore\n");
    }
    ;

primitive_command:
    SETLINEWIDTH '(' expression ')' {
        fprintf(output_file, "%s setlinewidth\n", $3);
        free($3);
    }
    | MOVETO '(' expression ',' expression ')' {
        fprintf(output_file, "%s %s moveto\n", $3, $5);
        free($3); free($5);
    }
    | LINETO '(' expression ',' expression ')' {
        fprintf(output_file, "%s %s lineto\n", $3, $5);
        free($3); free($5);
    }
    | SHOWPAGE '(' ')' {
        fprintf(output_file, "showpage\n");
    }
    ;

text_command:
    FUENTE '(' font_name ',' expression ')' {
        fprintf(output_file, "/%s findfont %s scalefont setfont\n", $3, $5);
        free($3); free($5);
    }
    | TEXTO '(' expression ',' expression ',' STRING ',' IDENTIFIER ')' {
        if (in_proc) {
            char* text = $7 + 1;
            text[strlen(text)-1] = '\0';
            fprintf(output_file, "  gsave\n");
            fprintf(output_file, "  %s aload pop setrgbcolor\n", $9);
            fprintf(output_file, "  %s %s moveto\n", $3, $5);
            fprintf(output_file, "  (%s) show\n", text);
            fprintf(output_file, "  grestore\n");
        } else {
            Symbol* color = find_symbol($9);
            if (color) {
                char* text = $7 + 1;
                text[strlen(text)-1] = '\0';
                fprintf(output_file, "gsave\n");
                fprintf(output_file, "%s aload pop setrgbcolor\n", color->value);
                fprintf(output_file, "%s %s moveto\n", $3, $5);
                fprintf(output_file, "(%s) show\n", text);
                fprintf(output_file, "grestore\n");
            }
        }
        free($3); free($5);
    }
    ;

font_name:
    HELVETICA { $$ = strdup("Helvetica"); }
    | TIMES { $$ = strdup("Times-Roman"); }
    | COURIER { $$ = strdup("Courier"); }
    ;

print_statement:
    PRINT '(' STRING ')' {
        fprintf(output_file, "%% Print: %s\n", $3);
    }
    ;

control_structure:
    if_statement
    | while_statement
    | for_statement
    ;

/* Definición de la primera parte del IF (común para ambos casos) */
if_block:
    IF '(' condition ')' '{' { fprintf(output_file, "{\n"); } statements '}'
    ;

if_statement:
    if_block
      { fprintf(output_file, "}\n"); }  /* <--- ESTA ES LA LÍNEA QUE FALTA: Cierra el bloque True */
      ELSE 
      '{' { fprintf(output_file, "{\n"); } statements '}' 
      {
        fprintf(output_file, "} ifelse\n");
      }
    | 
    if_block {
        fprintf(output_file, "} if\n");
    }
    ;

while_statement:
    WHILE '(' { fprintf(output_file, "{\n"); } condition ')' { fprintf(output_file, "  not { exit } if\n"); } '{' statements '}' {
        fprintf(output_file, "} loop\n");
    }
    ;

for_statement:
    FOR '(' assignment ';' { fprintf(output_file, "{\n"); } condition ';' { fprintf(output_file, "  not { exit } if\n"); } assignment ')' '{' statements '}' {
        fprintf(output_file, "} loop\n");
    }
    ;

proc_def:
    PROC IDENTIFIER '(' param_def_list ')' '{' {
        fprintf(output_file, "/%s {\n", $2);
        
        // NUEVO: Generar definiciones dinámicas en orden INVERSO
        // PostScript es una pila (LIFO), el último argumento está arriba.
        for (int i = param_count_def - 1; i >= 0; i--) {
            fprintf(output_file, "  /%s exch def\n", param_names[i]);
        }
        
        // Reiniciar contador para la próxima vez
        param_count_def = 0;
        
        strcpy(current_proc, $2);
        in_proc = 1;
    } statements '}' {
        fprintf(output_file, "} def\n\n");
        in_proc = 0;
        current_proc[0] = '\0';
    }
    ;

proc_call:
    IDENTIFIER '(' arg_list ')' {
        fprintf(output_file, "  %s\n", $1);
    }
    ;

arg_list:
    /* vacío */
    | expression {
        fprintf(output_file, "%s ", $1);
        free($1);
    }
    | arg_list ',' expression {
        fprintf(output_file, "%s ", $3);
        free($3);
    }
    ;

condition:
    expression EQ expression {
        fprintf(output_file, "%s %s eq\n", $1, $3);
        free($1); free($3);
    }
    | expression NEQ expression {
        fprintf(output_file, "%s %s ne\n", $1, $3);
        free($1); free($3);
    }
    | expression '<' expression {
        fprintf(output_file, "%s %s lt\n", $1, $3);
        free($1); free($3);
    }
    | expression '>' expression {
        fprintf(output_file, "%s %s gt\n", $1, $3);
        free($1); free($3);
    }
    | expression LEQ expression {
        fprintf(output_file, "%s %s le\n", $1, $3);
        free($1); free($3);
    }
    | expression GEQ expression {
        fprintf(output_file, "%s %s ge\n", $1, $3);
        free($1); free($3);
    }
    | '(' condition ')'
    ;

expression:
    term {
        $$ = $1;
    }
    | expression '+' term {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s add", $1, $3);
        $$ = strdup(buffer);
        free($1); free($3);
    }
    | expression '-' term {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s sub", $1, $3);
        $$ = strdup(buffer);
        free($1); free($3);
    }
    | '-' term %prec UMINUS {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s neg", $2);
        $$ = strdup(buffer);
        free($2);
    }
    ;

term:
    factor {
        $$ = $1;
    }
    | term '*' factor {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s mul", $1, $3);
        $$ = strdup(buffer);
        free($1); free($3);
    }
    | term '/' factor {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s div", $1, $3);
        $$ = strdup(buffer);
        free($1); free($3);
    }
    ;

factor:
    NUMBER {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d", $1);
        $$ = strdup(buffer);
    }
    | FLOAT {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%f", $1);
        $$ = strdup(buffer);
    }
    | PARAM {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "p%d", $1);
        $$ = strdup(buffer);
    }
    | IDENTIFIER {
        if (in_proc) {
            $$ = strdup($1);
        } else {
            Symbol* sym = find_symbol($1);
            if (sym && strcmp(sym->type, "variable") == 0) {
                $$ = strdup($1);
            } else {
                $$ = strdup($1);
            }
        }
    }
    | '(' expression ')' {
        $$ = $2;
    }
    | math_function {
        $$ = $1;
    }
    ;

math_function:
    SIN '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s 57.2958 mul sin", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | COS '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s 57.2958 mul cos", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | TAN '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s dup 57.2958 mul sin exch 57.2958 mul cos div", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | SQRT '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s sqrt", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | ABS '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s abs", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | POW '(' expression ',' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s exp", $3, $5);
        $$ = strdup(buffer);
        free($3); free($5);
    }
    | EXP '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s exp", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | LOG '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s ln", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | FLOOR '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s floor", $3);
        $$ = strdup(buffer);
        free($3);
    }
    | CEIL '(' expression ')' {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s ceiling", $3);
        $$ = strdup(buffer);
        free($3);
    }
    ;

// Regla para lista de parámetros en la DEFINICIÓN
param_def_list:
    /* vacío */ { param_count_def = 0; }
    | param_def_item
    ;

param_def_item:
    IDENTIFIER {
        strcpy(param_names[param_count_def], $1);
        param_count_def++;
    }
    | param_def_item ',' IDENTIFIER {
        strcpy(param_names[param_count_def], $3);
        param_count_def++;
    }
    ;

%%

void add_symbol(const char* name, const char* type, const char* value) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            strcpy(symbol_table[i].type, type);
            strcpy(symbol_table[i].value, value);
            return;
        }
    }
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    strcpy(symbol_table[symbol_count].value, value);
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
    fprintf(output_file, "%%%%Title: Generado por Transpilador\n");
    fprintf(output_file, "%%%%Creator: Transpilador con Funciones Matemáticas\n");
    fprintf(output_file, "%%%%EndComments\n\n");
    fprintf(output_file, "%% Definir constante PI\n");
    fprintf(output_file, "/pi 3.14159265359 def\n\n");
    fprintf(output_file, "1 setlinewidth\n");
    fprintf(output_file, "/Helvetica findfont 12 scalefont setfont\n\n");
}

void generate_ps_footer() {
    fprintf(output_file, "\n%% Fin del programa\n");
    fprintf(output_file, "showpage\n");
}

void yyerror(const char* s) {
    fprintf(stderr, "Error en línea %d: %s\n", line_num, s);
}

int main(int argc, char** argv) {
    if (argc > 1) {
        FILE* input = fopen(argv[1], "r");
        if (!input) {
            fprintf(stderr, "Error: No se puede abrir el archivo %s\n", argv[1]);
            return 1;
        }
        yyin = input;
    }
    
    printf("Transpilador de PostScript con funciones matemáticas iniciado...\n");
    yyparse();
    printf("Transpilación completada exitosamente.\n");
    
    return 0;
}