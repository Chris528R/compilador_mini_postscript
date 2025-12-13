%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postscript.h"
#include "symbol.h"

int yylex(void);
int yyerror(const char *s);
void execerror(char *s, char *t);
void defnonly(char *s);
void fpecatch();

extern int lineno;
extern Inst prog[];
int indef = 0;

#define code2(c1, c2)   code(c1); code(c2)
#define code3(c1, c2, c3)   code(c1); code(c2); code(c3)
%}

%union{
    Symbol *sym;
    Inst *inst;
    double dval;
    int narg;
    char *string;
}


%token <dval> NUMBER
%token <string> STRING
%token <sym> VAR FUNCTION PROCEDURE
%token <narg> ARG
%token BEGIN_POST END_POST
%token LINEA CIRCULO RECTANGULO
%token COLOR STROKE FILL SETLINEWIDTH
%token IF ELSE WHILE FOR FUNC PROC RETURN PRINT
%token GT GE LT LE EQ NE AND OR NOT

%type <inst> list stmt stmtlist expr asgn fig_stmt dibujar_stmt
%type <inst> cond while if end for forexpr begin
%type <sym> procname
%type <narg> arglist

%right '='
%left OR
%left AND
%left GT GE LT LE EQ NE
%left '+' '-'
%left '*' '/'
%left NOT UNARYMINUS

%%
list: /* nada */
    | list '\n'
    | list postscript
    | list defn
    | list error '\n'   { yyerrok; }
    ;

postscript: 
    BEGIN_POST STRING {
          ps_begin_document($2);
          initcode();
      } 
      post_content 
      END_POST {
          ps_end_document();
          printf("Documento PostScript generado: %s\n", $2);
          free($2);
      }
    ;

post_content:
      /* vacío */
    | post_content '\n'
    | post_content stmt '\n' {
        if($2){
            code(STOP);
            execute($2);
            progbase = progp;
        }
    }
    | post_content defn '\n'
    ;

fig_stmt:
      VAR '=' LINEA '(' expr ',' expr ',' expr ',' expr ')' {
          // line = linea(x1, y1, x2, y2)
          $$ = $5;  /* Inicio del código */
          code(create_line_shape);
          code3(varpush, (Inst)$1, assign);
      }
    | VAR '=' CIRCULO '(' expr ',' expr ',' expr ')' {
          // circ = circulo(x, y, r)
          $$ = $5;
          code(create_circle_shape);
          code3(varpush, (Inst)$1, assign);
      }
    | VAR '=' RECTANGULO '(' expr ',' expr ',' expr ',' expr ')' {
          // rect = rectangulo(x, y, w, h)
          $$ = $5;
          code(create_rect_shape);
          code3(varpush, (Inst)$1, assign);
      }
    | VAR '=' COLOR '(' expr ',' expr ',' expr ')' {
          // rojo = color(r, g, b)
          $$ = $5;
          code(create_color);
          code3(varpush, (Inst)$1, assign);
      }
    ;

dibujar_stmt:
      STROKE '(' VAR ',' VAR ')' {
          // stroke(shape, color)
          Inst *start = code3(varpush, (Inst)$3, eval); //SHAPE
          code3(varpush, (Inst)$5, eval); //COLOR
          code(ps_stroke);
      }
    | FILL '(' VAR ',' VAR ')' {
          // fill(shape, color)
          Inst *start = code3(varpush, (Inst)$3, eval);
          code3(varpush, (Inst)$5, eval);
          code(ps_fill);
      }
    | SETLINEWIDTH '(' expr ')' {
          $$ = $3;
          code(ps_setlinewidth);
      }
    ;

stmt: 
      expr { code(pop1); $$ = $1; }
    | asgn
    | fig_stmt
    | dibujar_stmt 
    | RETURN { defnonly("return"); code(procret); $$= progp; }
    | RETURN expr { defnonly("return"); $$=$2; code(funcret); }
    | PRINT expr { $$ = $2; code(print); }
    | while cond stmt end {
          ($1)[1] = (Inst)$3;
          ($1)[2] = (Inst)$4;
          $$ = $1;
      }
    | if cond stmt end {
          ($1)[1] = (Inst)$3;
          ($1)[3] = (Inst)$4;
          $$ = $1;
      }
    | if cond stmt end ELSE stmt end {
          ($1)[1] = (Inst)$3;
          ($1)[2] = (Inst)$6;
          ($1)[3] = (Inst)$7;
          $$ = $1;
      }
    | for '(' forexpr ';' forexpr ';' forexpr ')' stmt end {
          ($1)[1] = (Inst)$3;
          ($1)[2] = (Inst)$5;
          ($1)[3] = (Inst)$7;
          ($1)[4] = (Inst)$9;
          ($1)[5] = (Inst)$10;
          $$ = $1;
      }
    | '{' stmtlist '}' { $$ = $2; }
    | PROCEDURE begin '(' arglist ')' {
          $$ = $2;
          code3(call, (Inst)$1, (Inst)(long)$4);
      }
    ;

for: FOR { $$ = code3(forcode, STOP, STOP); code3(STOP, STOP, STOP); }
    ;

forexpr: expr { code(STOP); $$ = $1; }
    ;

begin: { $$ = progp; }
    ;

cond: '(' expr ')' { code(STOP); $$ = $2; }
    ;

while: WHILE { $$ = code3(whilecode, STOP, STOP); }
    ;

if: IF { $$ = code(ifcode); code3(STOP, STOP, STOP); }
    ;

end: /* vacío */ { code(STOP); $$ = progp; }
    ;

stmtlist: 
      /* vacío */ { $$ = progp; }
    | stmtlist '\n'
    | stmtlist stmt '\n' { $$ = $1; }
    ;

asgn: 
      VAR '=' expr {
          code3(varpush, (Inst)$1, assign);
          $$ = $3;
      }
    | ARG '=' expr {
          defnonly("$");
          code2(argassign, (Inst)(long)$1);
          $$ = $3;
      }
    ;

expr: 
      NUMBER { 
          $$ = code(constpush_n); 
          code_double($1); 
      }
    | VAR { 
          $$ = code3(varpush, (Inst)$1, eval); 
      }
    | ARG { 
          defnonly("$"); 
          $$ = code2(arg, (Inst)(long)$1); 
      }
    | asgn
    | FUNCTION begin '(' arglist ')' {
          $$ = $2;
          code3(call, (Inst)$1, (Inst)(long)$4);
      }
    | expr '+' expr { code(add); $$ = $1; }
    | expr '-' expr { code(sub); $$ = $1; }
    | expr '*' expr { code(mul); $$ = $1; }
    | expr '/' expr { code(divide); $$ = $1; }
    | '-' expr %prec UNARYMINUS { code(negate); $$ = $2; }
    | '(' expr ')' { $$ = $2; }
    | expr GT expr { code(gt); $$ = $1; }
    | expr GE expr { code(ge); $$ = $1; }
    | expr LT expr { code(lt); $$ = $1; }
    | expr LE expr { code(le); $$ = $1; }
    | expr EQ expr { code(eq); $$ = $1; }
    | expr NE expr { code(ne); $$ = $1; }
    | expr AND expr { code(and_op); $$ = $1; }
    | expr OR expr { code(or_op); $$ = $1; }
    | NOT expr { code(not_op); $$ = $2; }
    ;


defn: 
      FUNC procname { $2->type = TYPE_FUNCTION; indef = 1; }
      '(' ')' stmt { 
          code(procret); 
          define($2); 
          indef = 0; 
      }
    | PROC procname { $2->type = TYPE_PROCEDURE; indef = 1; }
      '(' ')' stmt { 
          code(procret); 
          define($2); 
          indef = 0; 
      }
    ;

procname: VAR
    ;

arglist: 
      /* vacío */ { $$ = 0; }
    | expr { $$ = 1; }
    | arglist ',' expr { $$ = $1 + 1; }
    ;

%%


#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

extern FILE *yyin;

jmp_buf begin_jmp;
char *progname;

int main(int argc, char *argv[]) {
    progname = argv[0];
    
    if (argc > 1) {
        FILE *f = fopen(argv[1], "r");
        if (!f) {
            fprintf(stderr, "No se puede abrir %s\n", argv[1]);
            return 1;
        }
        yyin = f;
    }
    
    setjmp(begin_jmp);
    signal(SIGFPE, fpecatch);
    initcode();
    ps_init();
    
    yyparse();
    
    return 0;
}

void execerror(char *s, char *t) {
    fprintf(stderr, "%s: %s", progname, s);
    if (t)
        fprintf(stderr, " %s", t);
    fprintf(stderr, " cerca de la línea %d\n", lineno);
    longjmp(begin_jmp, 0);
}

void defnonly(char *s) {
    if (!indef)
        execerror(s, "usado fuera de definición");
}

void fpecatch() {
    execerror("excepción de punto flotante", (char *)0);
}

int yyerror(const char *s) {
    fprintf(stderr, "%s: %s cerca de la línea %d\n", progname, s, lineno);
    return 0;
}