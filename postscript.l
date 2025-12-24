%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

extern int line_num;
%}

%option noyywrap
%option yylineno

%%

"begin"         { return BEGIN_TOKEN; }
"end"           { return END_TOKEN; }
"line"          { return LINE; }
"linea"         { return LINE; }
"circle"        { return CIRCLE; }
"circulo"       { return CIRCLE; }
"rect"          { return RECT; }
"rectangulo"    { return RECT; }
"color"         { return COLOR; }
"stroke"        { return STROKE; }
"fill"          { return FILL; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"function"      { return FUNCTION; }
"funcion"       { return FUNCTION; }
"proc"          { return PROC; }
"procedure"     { return PROC; }
"procedimiento" { return PROC; }
"return"        { return RETURN; }
"setlinewidth"  { return SETLINEWIDTH; }
"moveto"        { return MOVETO; }
"lineto"        { return LINETO; }
"showpage"      { return SHOWPAGE; }
"print"         { return PRINT; }
"fuente"        { return FUENTE; }
"font"          { return FUENTE; }
"texto"         { return TEXTO; }
"text"          { return TEXTO; }
"HELVETICA"     { return HELVETICA; }
"TIMES"         { return TIMES; }
"COURIER"       { return COURIER; }
"sin"           { return SIN; }
"cos"           { return COS; }
"tan"           { return TAN; }
"sqrt"          { return SQRT; }
"abs"           { return ABS; }
"pow"           { return POW; }
"exp"           { return EXP; }
"log"           { return LOG; }
"floor"         { return FLOOR; }
"ceil"          { return CEIL; }

\$[0-9]+                { yylval.num = atoi(yytext+1); return PARAM; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
[0-9]+                  { yylval.num = atoi(yytext); return NUMBER; }
[0-9]+\.[0-9]+          { yylval.fnum = atof(yytext); return FLOAT; }
\"[^\"]*\"              { yylval.str = strdup(yytext); return STRING; }

"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return '<'; }
">"             { return '>'; }
"&&"            { return AND; }
"||"            { return OR; }

"="             { return '='; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"("             { return '('; }
")"             { return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
","             { return ','; }
";"             { return ';'; }

"//"[^\n]*      { /* Comentarios de línea */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Comentarios de bloque */ }

[ \t\r]+        { /* Ignorar espacios */ }
\n              { line_num++; }

.               { printf("Carácter no reconocido: %s\n", yytext); }

%%