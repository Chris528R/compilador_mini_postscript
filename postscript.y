%{
#include "hoc.h"
#include <math.h>
#include <setjmp.h>
#include <signal.h>

#define code2(c1, c2)   code(c1); code(c2)
#define code3(c1, c2, c3)   code(c1); code(c2); code(c3)
}%

%union{
    Symbol *sym;
    Inst *inst;
    double num;
}


list: /* nada */
    | list '\n'
    | list asgn '\n'    { code2(pop_void, STOP); return 1; }
    | list stmt '\n'    { code(STOP); return 1; }
    | list expr '\n'    { code2(print, STOP); return 1; }
    | list error '\n'   { yyerrok; }
    | list defn '\n'
    ;

asgn: VAR '=' expr      { $$ = $3; code3(varpush, (Inst) $1, assign); }
    ;

stmt: expr              { code(pop_void); $$ = $1; }
    ;

expr: NUMBER                    { $$ = code2(constpush, (Inst) $1); }
    | VAR                       { $$ = code3(varpush, (Inst) $1, eval); }
    | figura                    
    | asgn                      { $$ = $1; }
    | '(' expr ')'              { $$ = $2; }
    | expr '+' expr             { $$ = $1; code(add); }
    | expr '-' expr             { $$ = $1; code(sub); }
    | expr '*' expr             { $$ = $1; code(mul); }
    | expr '/' expr             { $$ = $1; code(divop); }
    | expr '^' expr             { $$ = $1; code(power); }
    | '-' expr %prec UNARYMINUS { $$ = $2; code(negate); }
    | expr GT expr              { $$ = $1; code(gt); }
    | expr GE expr              { $$ = $1; code(ge); }
    | expr LT expr              { $$ = $1; code(lt); }
    | expr LE expr              { $$ = $1; code(le); }
    | expr EQ expr              { $$ = $1; code(eq); }
    | expr NE expr              { $$ = $1; code(ne); }
    | expr AND expr             { $$ = $1; code(and); }
    | expr OR expr              { $$ = $1; code(or); }
    | NOT expr                  { $$ = $2; code(not); }
    ;

figura: LINEA NUMBER NUMBER NUMBER NUMBER
      | CIRCULO NUMBER NUMBER NUMBER
      | RECTANGULO NUMBER NUMBER NUMBER NUMBER