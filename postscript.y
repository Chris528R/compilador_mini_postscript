%{
#include "compilador.h"

extern int yylex();
void yyerror(const char* s);
extern FILE* yyin;

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
        init_compiler($2);
    }
    statements END_TOKEN {
        finish_compiler();
    }
    ;

statements:
    /* vacío */
    | statements statement
    ;

statement:
    assignment
    | draw_command
    | control_structure
    | proc_def
    | proc_call
    | print_statement
    | primitive_command
    | text_command
    ;

assignment:
    IDENTIFIER '=' expression {
        // 1. Buscamos si la variable ya existe
        Symbol* s = find_symbol($1);
        
        // 2. Registramos/Actualizamos en la tabla (esto setea is_global si es nueva)
        add_symbol($1, "variable", $3);
        
        // 3. Si la variable era nueva, find_symbol devolvió NULL antes, 
        // así que la buscamos de nuevo para ver qué decidió add_symbol.
        if (!s) s = find_symbol($1);

        if (in_proc) {
            // DENTRO DE UN PROCEDIMIENTO
            if (s && s->is_global) {
                // Es una global (ej: x, y, dir) -> Usamos store para actualizarla
                fprintf(output_file, "  /%s %s store\n", $1, $3);
            } else {
                // Es local nueva o existente local (ej: prev, nx) -> Usamos def
                fprintf(output_file, "  /%s %s def\n", $1, $3);
            }
        } else {
            // EN EL MAIN (Siempre def)
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
        // CAMBIO: Registramos el tipo SIEMPRE, estemos en proc o no.
        add_symbol($1, "line", $3); 
        
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            fprintf(output_file, "/%s %s def\n", $1, $3);
        }
        free($3);
    }
    | IDENTIFIER '=' circle_def {
        add_symbol($1, "circle", $3); // <-- Sacado del else
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            fprintf(output_file, "/%s %s def\n", $1, $3);
        }
        free($3);
    }
    | IDENTIFIER '=' rect_def {
        add_symbol($1, "rect", $3); // <-- Sacado del else
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", $1, $3);
        } else {
            fprintf(output_file, "/%s %s def\n", $1, $3);
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
        fprintf(output_file, "  gsave\n");
        fprintf(output_file, "  %s aload pop setrgbcolor\n", $5);
        
        // Buscamos qué tipo de variable es (line, rect, circle)
        Symbol* sym = find_symbol($3);
        
        if (sym && strcmp(sym->type, "line") == 0) {
            // ES UNA LÍNEA: [x1 y1 x2 y2] -> moveto lineto
            fprintf(output_file, "  %s aload pop moveto lineto stroke\n", $3);
        } 
        else if (sym && strcmp(sym->type, "rect") == 0) {
            // ES UN RECTÁNGULO: [x y w h] -> rectstroke
            fprintf(output_file, "  %s aload pop rectstroke\n", $3);
        }
        else if (sym && strcmp(sym->type, "circle") == 0) {
            // ES UN CÍRCULO: [x y r] -> arc
            fprintf(output_file, "  %s aload pop 0 360 arc stroke\n", $3);
        }
        else {
            // FALLBACK DINÁMICO (Para parámetros de funciones donde no sabemos el tipo)
            // Si es un parámetro, usamos la lógica de longitud, pero asumimos RECT por defecto para 4
            fprintf(output_file, "  %s \n", $3);
            fprintf(output_file, "  dup length 3 eq {\n");
            fprintf(output_file, "    aload pop 0 360 arc stroke\n");
            fprintf(output_file, "  } {\n");
            fprintf(output_file, "    aload pop rectstroke\n");
            fprintf(output_file, "  } ifelse\n");
        }
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
        
        fprintf(output_file, "  20 dict begin\n"); 

        // Generar definiciones de parámetros (orden inverso)
        for (int i = param_count_def - 1; i >= 0; i--) {
            fprintf(output_file, "  /%s exch def\n", param_names[i]);
        }
        
        param_count_def = 0;
        strcpy(current_proc, $2);
        in_proc = 1;
    } statements '}' {
        fprintf(output_file, "  end\n");
        
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
    
    printf("Compilador a PostScript:\n");
    yyparse();
    printf("Transpilación completada exitosamente.\n");
    
    return 0;
}