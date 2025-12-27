/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUMBER = 258,                  /* NUMBER  */
    PARAM = 259,                   /* PARAM  */
    FLOAT = 260,                   /* FLOAT  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    STRING = 262,                  /* STRING  */
    BEGIN_TOKEN = 263,             /* BEGIN_TOKEN  */
    END_TOKEN = 264,               /* END_TOKEN  */
    LINE = 265,                    /* LINE  */
    CIRCLE = 266,                  /* CIRCLE  */
    RECT = 267,                    /* RECT  */
    COLOR = 268,                   /* COLOR  */
    STROKE = 269,                  /* STROKE  */
    FILL = 270,                    /* FILL  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    WHILE = 273,                   /* WHILE  */
    FOR = 274,                     /* FOR  */
    FUNCTION = 275,                /* FUNCTION  */
    PROC = 276,                    /* PROC  */
    RETURN = 277,                  /* RETURN  */
    SETLINEWIDTH = 278,            /* SETLINEWIDTH  */
    MOVETO = 279,                  /* MOVETO  */
    LINETO = 280,                  /* LINETO  */
    SHOWPAGE = 281,                /* SHOWPAGE  */
    PRINT = 282,                   /* PRINT  */
    FUENTE = 283,                  /* FUENTE  */
    TEXTO = 284,                   /* TEXTO  */
    HELVETICA = 285,               /* HELVETICA  */
    TIMES = 286,                   /* TIMES  */
    COURIER = 287,                 /* COURIER  */
    SIN = 288,                     /* SIN  */
    COS = 289,                     /* COS  */
    TAN = 290,                     /* TAN  */
    SQRT = 291,                    /* SQRT  */
    ABS = 292,                     /* ABS  */
    POW = 293,                     /* POW  */
    EXP = 294,                     /* EXP  */
    LOG = 295,                     /* LOG  */
    FLOOR = 296,                   /* FLOOR  */
    CEIL = 297,                    /* CEIL  */
    EQ = 298,                      /* EQ  */
    NEQ = 299,                     /* NEQ  */
    LEQ = 300,                     /* LEQ  */
    GEQ = 301,                     /* GEQ  */
    AND = 302,                     /* AND  */
    OR = 303,                      /* OR  */
    UMINUS = 304                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define PARAM 259
#define FLOAT 260
#define IDENTIFIER 261
#define STRING 262
#define BEGIN_TOKEN 263
#define END_TOKEN 264
#define LINE 265
#define CIRCLE 266
#define RECT 267
#define COLOR 268
#define STROKE 269
#define FILL 270
#define IF 271
#define ELSE 272
#define WHILE 273
#define FOR 274
#define FUNCTION 275
#define PROC 276
#define RETURN 277
#define SETLINEWIDTH 278
#define MOVETO 279
#define LINETO 280
#define SHOWPAGE 281
#define PRINT 282
#define FUENTE 283
#define TEXTO 284
#define HELVETICA 285
#define TIMES 286
#define COURIER 287
#define SIN 288
#define COS 289
#define TAN 290
#define SQRT 291
#define ABS 292
#define POW 293
#define EXP 294
#define LOG 295
#define FLOOR 296
#define CEIL 297
#define EQ 298
#define NEQ 299
#define LEQ 300
#define GEQ 301
#define AND 302
#define OR 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "./postscript.y"

    int num;
    double fnum;
    char* str;

#line 171 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
