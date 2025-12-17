%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postscript.h"
#include "symbol.h"
#include "y.tab.h"

extern YYSTYPE yylval;
int lineno = 1;

int follow(int expect, int ifyes, int ifno);
%}

digit       [0-9]
integer     {digit}+
double      ({digit}+\.{digit}*|\.{digit}+)
number      ({integer}|{double})
id          [a-zA-Z_][a-zA-Z0-9_]*
ws          [ \t]+
string      \"[^\"]*\"

%%

"begin"         { return BEGIN_POST; }
"end"           { return END_POST; }

"linea"         { return LINEA; }
"circulo"       { return CIRCULO; }
"rectangulo"    { return RECTANGULO; }

"color"         { return COLOR; }
"stroke"        { return STROKE; }
"fill"          { return FILL; }
"setlinewidth"  { return SETLINEWIDTH; }

"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }

"func"          { return FUNC; }
"proc"          { return PROC; }
"return"        { return RETURN; }
"print"         { return PRINT; }

"function"      { return FUNCTION; }
"procedure"     { return PROCEDURE; }

"texto"         { return TEXTO; }
"fuente"        { return FUENTE; }

"HELVETICA"     { yylval.narg = 0; return FONT_ID; }
"TIMES"         { yylval.narg = 1; return FONT_ID; }
"COURIER"       { yylval.narg = 2; return FONT_ID; }

"sin"           { return SIN; }
"cos"           { return COS; }

{id} {
    Symbol *s = lookup(yytext);
    if (!s)
        s = install(yytext, INDEF_TYPE);
    
    yylval.sym = s;

    if (s->type == TYPE_FUNCTION) {
        return FUNCTION;
    }
    if (s->type == TYPE_PROCEDURE) {
        return PROCEDURE;
    }

    return VAR;
}

{number} {
    yylval.dval = atof(yytext);
    return NUMBER;
}

{string} {
    // Remover comillas
    yytext[strlen(yytext)-1] = '\0';
    yylval.string = strdup(yytext + 1);
    return STRING;
}

\$[0-9]+ {
    int n = atoi(yytext + 1);
    yylval.narg = n;
    return ARG;
}

">"             { return follow('=', GE, GT); }
"<"             { return follow('=', LE, LT); }
"=="            { return EQ; }
"!="            { return NE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"             { return ';'; }
","             { return ','; }
"="             { return '='; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }

[\n]            { lineno++; return '\n'; }
{ws}            { /* ignorar espacios */ }
"//"[^\n]*      { /* comentarios */ }

.               { return *yytext; }

%%

int follow(int expect, int ifyes, int ifno) {
    int c = input();
    if (c == expect)
        return ifyes;
    unput(c);
    return ifno;
}