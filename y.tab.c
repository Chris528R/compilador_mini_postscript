/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./postscript.y"

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

#line 105 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 35 "./postscript.y"

    int num;
    double fnum;
    char* str;

#line 262 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_PARAM = 4,                      /* PARAM  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_BEGIN_TOKEN = 8,                /* BEGIN_TOKEN  */
  YYSYMBOL_END_TOKEN = 9,                  /* END_TOKEN  */
  YYSYMBOL_LINE = 10,                      /* LINE  */
  YYSYMBOL_CIRCLE = 11,                    /* CIRCLE  */
  YYSYMBOL_RECT = 12,                      /* RECT  */
  YYSYMBOL_COLOR = 13,                     /* COLOR  */
  YYSYMBOL_STROKE = 14,                    /* STROKE  */
  YYSYMBOL_FILL = 15,                      /* FILL  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_FUNCTION = 20,                  /* FUNCTION  */
  YYSYMBOL_PROC = 21,                      /* PROC  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_SETLINEWIDTH = 23,              /* SETLINEWIDTH  */
  YYSYMBOL_MOVETO = 24,                    /* MOVETO  */
  YYSYMBOL_LINETO = 25,                    /* LINETO  */
  YYSYMBOL_SHOWPAGE = 26,                  /* SHOWPAGE  */
  YYSYMBOL_PRINT = 27,                     /* PRINT  */
  YYSYMBOL_FUENTE = 28,                    /* FUENTE  */
  YYSYMBOL_TEXTO = 29,                     /* TEXTO  */
  YYSYMBOL_HELVETICA = 30,                 /* HELVETICA  */
  YYSYMBOL_TIMES = 31,                     /* TIMES  */
  YYSYMBOL_COURIER = 32,                   /* COURIER  */
  YYSYMBOL_SIN = 33,                       /* SIN  */
  YYSYMBOL_COS = 34,                       /* COS  */
  YYSYMBOL_TAN = 35,                       /* TAN  */
  YYSYMBOL_SQRT = 36,                      /* SQRT  */
  YYSYMBOL_ABS = 37,                       /* ABS  */
  YYSYMBOL_POW = 38,                       /* POW  */
  YYSYMBOL_EXP = 39,                       /* EXP  */
  YYSYMBOL_LOG = 40,                       /* LOG  */
  YYSYMBOL_FLOOR = 41,                     /* FLOOR  */
  YYSYMBOL_CEIL = 42,                      /* CEIL  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_NEQ = 44,                       /* NEQ  */
  YYSYMBOL_LEQ = 45,                       /* LEQ  */
  YYSYMBOL_GEQ = 46,                       /* GEQ  */
  YYSYMBOL_AND = 47,                       /* AND  */
  YYSYMBOL_OR = 48,                        /* OR  */
  YYSYMBOL_49_ = 49,                       /* '<'  */
  YYSYMBOL_50_ = 50,                       /* '>'  */
  YYSYMBOL_51_ = 51,                       /* '+'  */
  YYSYMBOL_52_ = 52,                       /* '-'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_54_ = 54,                       /* '/'  */
  YYSYMBOL_UMINUS = 55,                    /* UMINUS  */
  YYSYMBOL_56_ = 56,                       /* ';'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* '('  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* ')'  */
  YYSYMBOL_61_ = 61,                       /* '{'  */
  YYSYMBOL_62_ = 62,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_statements = 66,                /* statements  */
  YYSYMBOL_statement = 67,                 /* statement  */
  YYSYMBOL_optional_semicolon = 68,        /* optional_semicolon  */
  YYSYMBOL_assignment = 69,                /* assignment  */
  YYSYMBOL_color_def = 70,                 /* color_def  */
  YYSYMBOL_line_def = 71,                  /* line_def  */
  YYSYMBOL_circle_def = 72,                /* circle_def  */
  YYSYMBOL_rect_def = 73,                  /* rect_def  */
  YYSYMBOL_draw_command = 74,              /* draw_command  */
  YYSYMBOL_primitive_command = 75,         /* primitive_command  */
  YYSYMBOL_text_command = 76,              /* text_command  */
  YYSYMBOL_font_name = 77,                 /* font_name  */
  YYSYMBOL_print_statement = 78,           /* print_statement  */
  YYSYMBOL_control_structure = 79,         /* control_structure  */
  YYSYMBOL_if_block = 80,                  /* if_block  */
  YYSYMBOL_81_2 = 81,                      /* $@2  */
  YYSYMBOL_if_statement = 82,              /* if_statement  */
  YYSYMBOL_83_3 = 83,                      /* $@3  */
  YYSYMBOL_84_4 = 84,                      /* $@4  */
  YYSYMBOL_while_statement = 85,           /* while_statement  */
  YYSYMBOL_86_5 = 86,                      /* $@5  */
  YYSYMBOL_87_6 = 87,                      /* $@6  */
  YYSYMBOL_for_statement = 88,             /* for_statement  */
  YYSYMBOL_89_7 = 89,                      /* $@7  */
  YYSYMBOL_90_8 = 90,                      /* $@8  */
  YYSYMBOL_proc_def = 91,                  /* proc_def  */
  YYSYMBOL_92_9 = 92,                      /* $@9  */
  YYSYMBOL_proc_call = 93,                 /* proc_call  */
  YYSYMBOL_arg_list = 94,                  /* arg_list  */
  YYSYMBOL_condition = 95,                 /* condition  */
  YYSYMBOL_expression = 96,                /* expression  */
  YYSYMBOL_term = 97,                      /* term  */
  YYSYMBOL_factor = 98,                    /* factor  */
  YYSYMBOL_math_function = 99,             /* math_function  */
  YYSYMBOL_param_def_list = 100,           /* param_def_list  */
  YYSYMBOL_param_def_item = 101            /* param_def_item  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   419

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,    60,    53,    51,    59,    52,     2,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
      49,    57,    50,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    66,    84,    86,    90,    91,    92,    93,
      94,    95,    96,    97,   100,   102,   106,   115,   124,   133,
     142,   154,   163,   172,   181,   190,   221,   247,   251,   255,
     259,   265,   269,   295,   296,   297,   301,   307,   308,   309,
     314,   314,   319,   321,   318,   326,   332,   332,   332,   338,
     338,   338,   344,   344,   366,   371,   373,   377,   384,   388,
     392,   396,   400,   404,   408,   412,   415,   421,   427,   436,
     439,   445,   454,   459,   464,   469,   481,   484,   490,   496,
     502,   508,   514,   520,   526,   532,   538,   544,   554,   555,
     559,   563
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "PARAM",
  "FLOAT", "IDENTIFIER", "STRING", "BEGIN_TOKEN", "END_TOKEN", "LINE",
  "CIRCLE", "RECT", "COLOR", "STROKE", "FILL", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "PROC", "RETURN", "SETLINEWIDTH", "MOVETO", "LINETO",
  "SHOWPAGE", "PRINT", "FUENTE", "TEXTO", "HELVETICA", "TIMES", "COURIER",
  "SIN", "COS", "TAN", "SQRT", "ABS", "POW", "EXP", "LOG", "FLOOR", "CEIL",
  "EQ", "NEQ", "LEQ", "GEQ", "AND", "OR", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "';'", "'='", "'('", "','", "')'", "'{'", "'}'",
  "$accept", "program", "$@1", "statements", "statement",
  "optional_semicolon", "assignment", "color_def", "line_def",
  "circle_def", "rect_def", "draw_command", "primitive_command",
  "text_command", "font_name", "print_statement", "control_structure",
  "if_block", "$@2", "if_statement", "$@3", "$@4", "while_statement",
  "$@5", "$@6", "for_statement", "$@7", "$@8", "proc_def", "$@9",
  "proc_call", "arg_list", "condition", "expression", "term", "factor",
  "math_function", "param_def_list", "param_def_item", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    -1,    38,  -188,  -188,  -188,   305,   -45,  -188,   -18,
     -15,     3,     6,    11,    17,    29,    34,    50,    62,    65,
      78,    81,  -188,    42,    42,    42,    42,    42,  -188,   124,
    -188,  -188,  -188,  -188,    42,   198,   238,   145,   148,   264,
    -188,   162,   114,   238,   238,   238,   113,   167,    40,   238,
    -188,  -188,  -188,  -188,  -188,  -188,   166,  -188,  -188,  -188,
    -188,  -188,   135,   141,   160,   163,   191,   197,   203,   204,
     207,   223,   230,   234,   236,   254,   304,   238,  -188,  -188,
    -188,  -188,    15,    41,  -188,  -188,    51,    15,   200,   205,
     264,   229,   202,   264,   256,   259,   321,   -16,    55,   154,
    -188,   275,  -188,  -188,  -188,   277,   266,   199,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,    41,    -2,   304,   304,   304,   304,   238,  -188,
     351,   353,   293,     2,   311,   238,   238,   238,   238,   238,
     238,   301,  -188,  -188,   352,   316,  -188,   238,   238,  -188,
     238,   238,  -188,   315,   317,   319,   328,     5,    37,    39,
     101,   104,   330,   111,   118,   140,   206,  -188,    41,    41,
    -188,  -188,    15,   354,   355,  -188,  -188,    15,    15,    15,
      15,    15,    15,  -188,   264,   327,   371,   231,   233,   235,
     332,  -188,   238,   238,   238,   238,  -188,  -188,  -188,  -188,
    -188,   238,  -188,  -188,  -188,  -188,  -188,  -188,  -188,   329,
     336,  -188,  -188,  -188,  -188,  -188,   396,     1,   334,   343,
     345,   347,   296,   103,  -188,  -188,  -188,   346,  -188,   238,
     238,   238,   238,  -188,  -188,   119,   162,   161,   401,   349,
     298,   358,   300,  -188,   356,  -188,   359,   238,  -188,   238,
    -188,   350,  -188,   303,   313,  -188,  -188,  -188,   201,  -188
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     4,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,    14,    14,    14,    14,    14,     8,    45,
      37,    38,    39,     9,    14,     0,    55,     0,     0,     0,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     6,     7,    12,    13,    11,     0,    10,    72,    74,
      73,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    16,    65,    69,    77,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    88,     0,     0,     0,
      30,     0,    33,    34,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,     0,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    90,     0,    89,    27,     0,     0,    36,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    66,    67,
      70,    71,    57,     0,     0,    64,    40,    58,    59,    62,
      63,    60,    61,    47,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,    78,    79,    80,    81,
      82,     0,    84,    85,    86,    87,    25,    26,     4,     0,
       0,    52,    91,    28,    29,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     4,    50,     4,     0,    44,     0,
       0,     0,     0,    83,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,    53,     0,     0,    23,     0,
      21,     0,    32,     0,     0,     4,    22,    24,     0,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,  -188,  -187,  -188,     7,   -38,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,   -88,   -35,   -65,    23,  -188,  -188,  -188
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     6,    22,    51,    23,    78,    79,    80,
      81,    24,    25,    26,   105,    27,    28,    29,   208,    30,
      56,   191,    31,    93,   209,    32,   184,   236,    33,   226,
      34,    86,    91,    92,    83,    84,    85,   144,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    87,   132,    95,   217,   141,     3,     7,    97,    98,
      99,   122,    35,    36,   106,     9,    10,    11,     1,    12,
      13,   223,    14,    42,    15,    16,    17,    18,    19,    20,
      21,    52,    53,    54,    55,   124,   125,   235,     4,   237,
      37,    57,   123,    38,   146,   135,   136,   137,   138,   124,
     125,   139,   140,   124,   125,   133,   124,   125,   167,   168,
     169,    39,   167,   228,    40,   196,   124,   125,   258,    41,
     102,   103,   104,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,    43,   124,   125,
     124,   125,    44,   172,   126,   127,   210,   197,    50,   198,
     177,   178,   179,   180,   181,   182,   124,   125,    45,     7,
     128,   129,   187,   188,   147,   189,   190,     9,    10,    11,
      46,    12,    13,    47,    14,     7,    15,    16,    17,    18,
      19,    20,    21,     9,    10,    11,    48,    12,    13,    49,
      14,   -42,    15,    16,    17,    18,    19,    20,    21,   170,
     171,    88,   124,   125,    89,   124,   125,   218,   219,   220,
     221,   199,   124,   125,   200,   234,   222,     7,    94,   124,
     125,   202,    96,   100,   101,     9,    10,    11,   203,    12,
      13,   243,    14,   107,    15,    16,    17,    18,    19,    20,
      21,   124,   125,   108,   239,   240,   241,   242,   244,   109,
     204,    58,    59,    60,    61,   124,   125,     7,    62,    63,
      64,    65,   253,   148,   254,     9,    10,    11,   110,    12,
      13,   111,    14,   245,    15,    16,    17,    18,    19,    20,
      21,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    58,    59,    60,    61,   135,   136,   137,   138,   112,
      76,   139,   140,   124,   125,   113,    77,   124,   125,   130,
     152,   114,   115,   259,   131,   116,   205,    58,    59,    60,
      61,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   117,   124,   125,   124,   125,   124,   125,   118,   134,
      76,   213,   119,   214,   120,   215,    77,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    58,    59,    60,
      61,     7,   121,    35,     8,   142,    76,   124,   125,     9,
      10,    11,    90,    12,    13,   151,    14,   143,    15,    16,
      17,    18,    19,    20,    21,   149,   150,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,   124,   125,   124,
     125,   124,   125,   175,   124,   125,   233,   173,   248,   174,
     250,   183,    77,   256,   124,   125,   124,   125,   124,   125,
     124,   125,   176,   257,   192,   186,   193,   212,   194,   124,
     125,   124,   125,   124,   125,   124,   125,   195,   211,   201,
     224,   216,   225,   229,   124,   125,   124,   125,   124,   125,
     124,   125,   230,   227,   231,   238,   232,   246,   247,   124,
     125,   255,   185,     0,   206,   207,   251,   249,     0,   252
};

static const yytype_int16 yycheck[] =
{
      35,    36,    90,    41,   191,    93,     7,     6,    43,    44,
      45,    76,    57,    58,    49,    14,    15,    16,     8,    18,
      19,   208,    21,     6,    23,    24,    25,    26,    27,    28,
      29,    24,    25,    26,    27,    51,    52,   224,     0,   226,
      58,    34,    77,    58,    60,    43,    44,    45,    46,    51,
      52,    49,    50,    51,    52,    90,    51,    52,    60,   124,
     125,    58,    60,    62,    58,    60,    51,    52,   255,    58,
      30,    31,    32,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    58,    51,    52,
      51,    52,    58,   128,    53,    54,   184,    60,    56,    60,
     135,   136,   137,   138,   139,   140,    51,    52,    58,     6,
      59,    60,   147,   148,    59,   150,   151,    14,    15,    16,
      58,    18,    19,    58,    21,     6,    23,    24,    25,    26,
      27,    28,    29,    14,    15,    16,    58,    18,    19,    58,
      21,    17,    23,    24,    25,    26,    27,    28,    29,   126,
     127,     6,    51,    52,     6,    51,    52,   192,   193,   194,
     195,    60,    51,    52,    60,    62,   201,     6,     6,    51,
      52,    60,    58,    60,     7,    14,    15,    16,    60,    18,
      19,    62,    21,    17,    23,    24,    25,    26,    27,    28,
      29,    51,    52,    58,   229,   230,   231,   232,   236,    58,
      60,     3,     4,     5,     6,    51,    52,     6,    10,    11,
      12,    13,   247,    59,   249,    14,    15,    16,    58,    18,
      19,    58,    21,    62,    23,    24,    25,    26,    27,    28,
      29,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     3,     4,     5,     6,    43,    44,    45,    46,    58,
      52,    49,    50,    51,    52,    58,    58,    51,    52,    59,
      61,    58,    58,    62,    59,    58,    60,     3,     4,     5,
       6,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    58,    51,    52,    51,    52,    51,    52,    58,    60,
      52,    60,    58,    60,    58,    60,    58,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     3,     4,     5,
       6,     6,    58,    57,     9,    56,    52,    51,    52,    14,
      15,    16,    58,    18,    19,    59,    21,     6,    23,    24,
      25,    26,    27,    28,    29,    60,    59,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    51,    52,    51,
      52,    51,    52,    60,    51,    52,    60,     6,    60,     6,
      60,    60,    58,    60,    51,    52,    51,    52,    51,    52,
      51,    52,    61,    60,    59,    59,    59,     6,    59,    51,
      52,    51,    52,    51,    52,    51,    52,    59,    61,    59,
      61,    59,    56,    59,    51,    52,    51,    52,    51,    52,
      51,    52,    59,     7,    59,    59,    59,     6,    59,    51,
      52,    61,    60,    -1,    60,    60,    60,    59,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    64,     7,     0,    65,    66,     6,     9,    14,
      15,    16,    18,    19,    21,    23,    24,    25,    26,    27,
      28,    29,    67,    69,    74,    75,    76,    78,    79,    80,
      82,    85,    88,    91,    93,    57,    58,    58,    58,    58,
      58,    58,     6,    58,    58,    58,    58,    58,    58,    58,
      56,    68,    68,    68,    68,    68,    83,    68,     3,     4,
       5,     6,    10,    11,    12,    13,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    52,    58,    70,    71,
      72,    73,    96,    97,    98,    99,    94,    96,     6,     6,
      58,    95,    96,    86,     6,    69,    58,    96,    96,    96,
      60,     7,    30,    31,    32,    77,    96,    17,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    97,    96,    51,    52,    53,    54,    59,    60,
      59,    59,    95,    96,    60,    43,    44,    45,    46,    49,
      50,    95,    56,     6,   100,   101,    60,    59,    59,    60,
      59,    59,    61,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    60,    97,    97,
      98,    98,    96,     6,     6,    60,    61,    96,    96,    96,
      96,    96,    96,    60,    89,    60,    59,    96,    96,    96,
      96,    84,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    59,    60,    60,    60,    60,    60,    60,    81,    87,
      95,    61,     6,    60,    60,    60,    59,    66,    96,    96,
      96,    96,    96,    66,    61,    56,    92,     7,    62,    59,
      59,    59,    59,    60,    62,    66,    90,    66,    59,    96,
      96,    96,    96,    62,    69,    62,     6,    59,    60,    59,
      60,    60,    60,    96,    96,    61,    60,    60,    66,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    65,    64,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    68,    68,    69,    69,    69,    69,
      69,    70,    71,    72,    73,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    79,    79,    79,
      81,    80,    83,    84,    82,    82,    86,    87,    85,    89,
      90,    88,    92,    91,    93,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    97,
      97,    97,    98,    98,    98,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     0,     2,     2,     2,     1,     1,
       2,     2,     2,     2,     0,     1,     3,     3,     3,     3,
       3,     8,    10,     8,    10,     6,     6,     4,     6,     6,
       3,     6,    10,     1,     1,     1,     4,     1,     1,     1,
       0,     8,     0,     0,     7,     1,     0,     0,     9,     0,
       0,    13,     0,     9,     4,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     2,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     4,     4,
       4,     4,     4,     6,     4,     4,     4,     4,     0,     1,
       1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 66 "./postscript.y"
                       {
        char* filename = (yyvsp[0].str) + 1;
        filename[strlen(filename)-1] = '\0';
        strcpy(output_filename, filename);
        output_file = fopen(output_filename, "w");
        if (!output_file) {
            fprintf(stderr, "Error: No se puede crear el archivo %s\n", output_filename);
            exit(1);
        }
        generate_ps_header();
    }
#line 1547 "y.tab.c"
    break;

  case 3: /* program: BEGIN_TOKEN STRING $@1 statements END_TOKEN  */
#line 77 "./postscript.y"
                         {
        generate_ps_footer();
        fclose(output_file);
        printf("Archivo PostScript generado: %s\n", output_filename);
    }
#line 1557 "y.tab.c"
    break;

  case 16: /* assignment: IDENTIFIER '=' expression  */
#line 106 "./postscript.y"
                              {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        } else {
            add_symbol((yyvsp[-2].str), "variable", (yyvsp[0].str));
            fprintf(output_file, "/%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str)); 
        }
        free((yyvsp[0].str));
    }
#line 1571 "y.tab.c"
    break;

  case 17: /* assignment: IDENTIFIER '=' color_def  */
#line 115 "./postscript.y"
                               {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        } else {
            add_symbol((yyvsp[-2].str), "color", (yyvsp[0].str));
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        }
        free((yyvsp[0].str));
    }
#line 1585 "y.tab.c"
    break;

  case 18: /* assignment: IDENTIFIER '=' line_def  */
#line 124 "./postscript.y"
                              {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        } else {
            add_symbol((yyvsp[-2].str), "line", (yyvsp[0].str));
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        }
        free((yyvsp[0].str));
    }
#line 1599 "y.tab.c"
    break;

  case 19: /* assignment: IDENTIFIER '=' circle_def  */
#line 133 "./postscript.y"
                                {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        } else {
            add_symbol((yyvsp[-2].str), "circle", (yyvsp[0].str));
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        }
        free((yyvsp[0].str));
    }
#line 1613 "y.tab.c"
    break;

  case 20: /* assignment: IDENTIFIER '=' rect_def  */
#line 142 "./postscript.y"
                              {
        if (in_proc) {
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        } else {
            add_symbol((yyvsp[-2].str), "rect", (yyvsp[0].str));
            fprintf(output_file, "  /%s %s def\n", (yyvsp[-2].str), (yyvsp[0].str));
        }
        free((yyvsp[0].str));
    }
#line 1627 "y.tab.c"
    break;

  case 21: /* color_def: COLOR '(' expression ',' expression ',' expression ')'  */
#line 154 "./postscript.y"
                                                           {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s 255 div %s 255 div %s 255 div ]", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-5].str)); free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1638 "y.tab.c"
    break;

  case 22: /* line_def: LINE '(' expression ',' expression ',' expression ',' expression ')'  */
#line 163 "./postscript.y"
                                                                         {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s %s %s %s ]", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-7].str)); free((yyvsp[-5].str)); free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1649 "y.tab.c"
    break;

  case 23: /* circle_def: CIRCLE '(' expression ',' expression ',' expression ')'  */
#line 172 "./postscript.y"
                                                            {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s %s %s ]", (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-5].str)); free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1660 "y.tab.c"
    break;

  case 24: /* rect_def: RECT '(' expression ',' expression ',' expression ',' expression ')'  */
#line 181 "./postscript.y"
                                                                         {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "[ %s %s %s %s ]", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-7].str)); free((yyvsp[-5].str)); free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1671 "y.tab.c"
    break;

  case 25: /* draw_command: STROKE '(' IDENTIFIER ',' IDENTIFIER ')'  */
#line 190 "./postscript.y"
                                             {
        // Lógica unificada para Proc y Global
        // En ambos casos generamos código que asume que las variables existen en PS
        
        fprintf(output_file, "  gsave\n");
        
        // 1. Configurar color
        // Usamos el identificador del color directamente
        fprintf(output_file, "  %s aload pop setrgbcolor\n", (yyvsp[-1].str)); 
        
        // 2. Determinar tipo de forma y dibujar
        // Ponemos el array de la forma en la pila SIN desempaquetarlo aun
        fprintf(output_file, "  %s \n", (yyvsp[-3].str)); 
        
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
#line 1706 "y.tab.c"
    break;

  case 26: /* draw_command: FILL '(' IDENTIFIER ',' IDENTIFIER ')'  */
#line 221 "./postscript.y"
                                           {
        fprintf(output_file, "  gsave\n");
        
        // 1. Configurar color
        fprintf(output_file, "  %s aload pop setrgbcolor\n", (yyvsp[-1].str));
        
        // 2. Determinar tipo de forma
        fprintf(output_file, "  %s \n", (yyvsp[-3].str));
        
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
#line 1734 "y.tab.c"
    break;

  case 27: /* primitive_command: SETLINEWIDTH '(' expression ')'  */
#line 247 "./postscript.y"
                                    {
        fprintf(output_file, "%s setlinewidth\n", (yyvsp[-1].str));
        free((yyvsp[-1].str));
    }
#line 1743 "y.tab.c"
    break;

  case 28: /* primitive_command: MOVETO '(' expression ',' expression ')'  */
#line 251 "./postscript.y"
                                               {
        fprintf(output_file, "%s %s moveto\n", (yyvsp[-3].str), (yyvsp[-1].str));
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1752 "y.tab.c"
    break;

  case 29: /* primitive_command: LINETO '(' expression ',' expression ')'  */
#line 255 "./postscript.y"
                                               {
        fprintf(output_file, "%s %s lineto\n", (yyvsp[-3].str), (yyvsp[-1].str));
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1761 "y.tab.c"
    break;

  case 30: /* primitive_command: SHOWPAGE '(' ')'  */
#line 259 "./postscript.y"
                       {
        fprintf(output_file, "showpage\n");
    }
#line 1769 "y.tab.c"
    break;

  case 31: /* text_command: FUENTE '(' font_name ',' expression ')'  */
#line 265 "./postscript.y"
                                            {
        fprintf(output_file, "/%s findfont %s scalefont setfont\n", (yyvsp[-3].str), (yyvsp[-1].str));
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 1778 "y.tab.c"
    break;

  case 32: /* text_command: TEXTO '(' expression ',' expression ',' STRING ',' IDENTIFIER ')'  */
#line 269 "./postscript.y"
                                                                        {
        if (in_proc) {
            char* text = (yyvsp[-3].str) + 1;
            text[strlen(text)-1] = '\0';
            fprintf(output_file, "  gsave\n");
            fprintf(output_file, "  %s aload pop setrgbcolor\n", (yyvsp[-1].str));
            fprintf(output_file, "  %s %s moveto\n", (yyvsp[-7].str), (yyvsp[-5].str));
            fprintf(output_file, "  (%s) show\n", text);
            fprintf(output_file, "  grestore\n");
        } else {
            Symbol* color = find_symbol((yyvsp[-1].str));
            if (color) {
                char* text = (yyvsp[-3].str) + 1;
                text[strlen(text)-1] = '\0';
                fprintf(output_file, "gsave\n");
                fprintf(output_file, "%s aload pop setrgbcolor\n", color->value);
                fprintf(output_file, "%s %s moveto\n", (yyvsp[-7].str), (yyvsp[-5].str));
                fprintf(output_file, "(%s) show\n", text);
                fprintf(output_file, "grestore\n");
            }
        }
        free((yyvsp[-7].str)); free((yyvsp[-5].str));
    }
#line 1806 "y.tab.c"
    break;

  case 33: /* font_name: HELVETICA  */
#line 295 "./postscript.y"
              { (yyval.str) = strdup("Helvetica"); }
#line 1812 "y.tab.c"
    break;

  case 34: /* font_name: TIMES  */
#line 296 "./postscript.y"
            { (yyval.str) = strdup("Times-Roman"); }
#line 1818 "y.tab.c"
    break;

  case 35: /* font_name: COURIER  */
#line 297 "./postscript.y"
              { (yyval.str) = strdup("Courier"); }
#line 1824 "y.tab.c"
    break;

  case 36: /* print_statement: PRINT '(' STRING ')'  */
#line 301 "./postscript.y"
                         {
        fprintf(output_file, "%% Print: %s\n", (yyvsp[-1].str));
    }
#line 1832 "y.tab.c"
    break;

  case 40: /* $@2: %empty  */
#line 314 "./postscript.y"
                             { fprintf(output_file, "{\n"); }
#line 1838 "y.tab.c"
    break;

  case 42: /* $@3: %empty  */
#line 319 "./postscript.y"
      { fprintf(output_file, "}\n"); }
#line 1844 "y.tab.c"
    break;

  case 43: /* $@4: %empty  */
#line 321 "./postscript.y"
          { fprintf(output_file, "{\n"); }
#line 1850 "y.tab.c"
    break;

  case 44: /* if_statement: if_block $@3 ELSE '{' $@4 statements '}'  */
#line 322 "./postscript.y"
      {
        fprintf(output_file, "} ifelse\n");
      }
#line 1858 "y.tab.c"
    break;

  case 45: /* if_statement: if_block  */
#line 326 "./postscript.y"
             {
        fprintf(output_file, "} if\n");
    }
#line 1866 "y.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 332 "./postscript.y"
              { fprintf(output_file, "{\n"); }
#line 1872 "y.tab.c"
    break;

  case 47: /* $@6: %empty  */
#line 332 "./postscript.y"
                                                             { fprintf(output_file, "  not { exit } if\n"); }
#line 1878 "y.tab.c"
    break;

  case 48: /* while_statement: WHILE '(' $@5 condition ')' $@6 '{' statements '}'  */
#line 332 "./postscript.y"
                                                                                                                                 {
        fprintf(output_file, "} loop\n");
    }
#line 1886 "y.tab.c"
    break;

  case 49: /* $@7: %empty  */
#line 338 "./postscript.y"
                           { fprintf(output_file, "{\n"); }
#line 1892 "y.tab.c"
    break;

  case 50: /* $@8: %empty  */
#line 338 "./postscript.y"
                                                                          { fprintf(output_file, "  not { exit } if\n"); }
#line 1898 "y.tab.c"
    break;

  case 51: /* for_statement: FOR '(' assignment ';' $@7 condition ';' $@8 assignment ')' '{' statements '}'  */
#line 338 "./postscript.y"
                                                                                                                                                             {
        fprintf(output_file, "} loop\n");
    }
#line 1906 "y.tab.c"
    break;

  case 52: /* $@9: %empty  */
#line 344 "./postscript.y"
                                               {
        fprintf(output_file, "/%s {\n", (yyvsp[-4].str));
        
        // NUEVO: Generar definiciones dinámicas en orden INVERSO
        // PostScript es una pila (LIFO), el último argumento está arriba.
        for (int i = param_count_def - 1; i >= 0; i--) {
            fprintf(output_file, "  /%s exch def\n", param_names[i]);
        }
        
        // Reiniciar contador para la próxima vez
        param_count_def = 0;
        
        strcpy(current_proc, (yyvsp[-4].str));
        in_proc = 1;
    }
#line 1926 "y.tab.c"
    break;

  case 53: /* proc_def: PROC IDENTIFIER '(' param_def_list ')' '{' $@9 statements '}'  */
#line 358 "./postscript.y"
                     {
        fprintf(output_file, "} def\n\n");
        in_proc = 0;
        current_proc[0] = '\0';
    }
#line 1936 "y.tab.c"
    break;

  case 54: /* proc_call: IDENTIFIER '(' arg_list ')'  */
#line 366 "./postscript.y"
                                {
        fprintf(output_file, "  %s\n", (yyvsp[-3].str));
    }
#line 1944 "y.tab.c"
    break;

  case 56: /* arg_list: expression  */
#line 373 "./postscript.y"
                 {
        fprintf(output_file, "%s ", (yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1953 "y.tab.c"
    break;

  case 57: /* arg_list: arg_list ',' expression  */
#line 377 "./postscript.y"
                              {
        fprintf(output_file, "%s ", (yyvsp[0].str));
        free((yyvsp[0].str));
    }
#line 1962 "y.tab.c"
    break;

  case 58: /* condition: expression EQ expression  */
#line 384 "./postscript.y"
                             {
        fprintf(output_file, "%s %s eq\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1971 "y.tab.c"
    break;

  case 59: /* condition: expression NEQ expression  */
#line 388 "./postscript.y"
                                {
        fprintf(output_file, "%s %s ne\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1980 "y.tab.c"
    break;

  case 60: /* condition: expression '<' expression  */
#line 392 "./postscript.y"
                                {
        fprintf(output_file, "%s %s lt\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1989 "y.tab.c"
    break;

  case 61: /* condition: expression '>' expression  */
#line 396 "./postscript.y"
                                {
        fprintf(output_file, "%s %s gt\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1998 "y.tab.c"
    break;

  case 62: /* condition: expression LEQ expression  */
#line 400 "./postscript.y"
                                {
        fprintf(output_file, "%s %s le\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 2007 "y.tab.c"
    break;

  case 63: /* condition: expression GEQ expression  */
#line 404 "./postscript.y"
                                {
        fprintf(output_file, "%s %s ge\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 2016 "y.tab.c"
    break;

  case 65: /* expression: term  */
#line 412 "./postscript.y"
         {
        (yyval.str) = (yyvsp[0].str);
    }
#line 2024 "y.tab.c"
    break;

  case 66: /* expression: expression '+' term  */
#line 415 "./postscript.y"
                          {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s add", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 2035 "y.tab.c"
    break;

  case 67: /* expression: expression '-' term  */
#line 421 "./postscript.y"
                          {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s sub", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 2046 "y.tab.c"
    break;

  case 68: /* expression: '-' term  */
#line 427 "./postscript.y"
                            {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s neg", (yyvsp[0].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[0].str));
    }
#line 2057 "y.tab.c"
    break;

  case 69: /* term: factor  */
#line 436 "./postscript.y"
           {
        (yyval.str) = (yyvsp[0].str);
    }
#line 2065 "y.tab.c"
    break;

  case 70: /* term: term '*' factor  */
#line 439 "./postscript.y"
                      {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s mul", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 2076 "y.tab.c"
    break;

  case 71: /* term: term '/' factor  */
#line 445 "./postscript.y"
                      {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s div", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 2087 "y.tab.c"
    break;

  case 72: /* factor: NUMBER  */
#line 454 "./postscript.y"
           {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%d", (yyvsp[0].num));
        (yyval.str) = strdup(buffer);
    }
#line 2097 "y.tab.c"
    break;

  case 73: /* factor: FLOAT  */
#line 459 "./postscript.y"
            {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "%f", (yyvsp[0].fnum));
        (yyval.str) = strdup(buffer);
    }
#line 2107 "y.tab.c"
    break;

  case 74: /* factor: PARAM  */
#line 464 "./postscript.y"
            {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "p%d", (yyvsp[0].num));
        (yyval.str) = strdup(buffer);
    }
#line 2117 "y.tab.c"
    break;

  case 75: /* factor: IDENTIFIER  */
#line 469 "./postscript.y"
                 {
        if (in_proc) {
            (yyval.str) = strdup((yyvsp[0].str));
        } else {
            Symbol* sym = find_symbol((yyvsp[0].str));
            if (sym && strcmp(sym->type, "variable") == 0) {
                (yyval.str) = strdup((yyvsp[0].str));
            } else {
                (yyval.str) = strdup((yyvsp[0].str));
            }
        }
    }
#line 2134 "y.tab.c"
    break;

  case 76: /* factor: '(' expression ')'  */
#line 481 "./postscript.y"
                         {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 2142 "y.tab.c"
    break;

  case 77: /* factor: math_function  */
#line 484 "./postscript.y"
                    {
        (yyval.str) = (yyvsp[0].str);
    }
#line 2150 "y.tab.c"
    break;

  case 78: /* math_function: SIN '(' expression ')'  */
#line 490 "./postscript.y"
                           {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s 57.2958 mul sin", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2161 "y.tab.c"
    break;

  case 79: /* math_function: COS '(' expression ')'  */
#line 496 "./postscript.y"
                             {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s 57.2958 mul cos", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2172 "y.tab.c"
    break;

  case 80: /* math_function: TAN '(' expression ')'  */
#line 502 "./postscript.y"
                             {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s dup 57.2958 mul sin exch 57.2958 mul cos div", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2183 "y.tab.c"
    break;

  case 81: /* math_function: SQRT '(' expression ')'  */
#line 508 "./postscript.y"
                              {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s sqrt", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2194 "y.tab.c"
    break;

  case 82: /* math_function: ABS '(' expression ')'  */
#line 514 "./postscript.y"
                             {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s abs", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2205 "y.tab.c"
    break;

  case 83: /* math_function: POW '(' expression ',' expression ')'  */
#line 520 "./postscript.y"
                                            {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s %s exp", (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
    }
#line 2216 "y.tab.c"
    break;

  case 84: /* math_function: EXP '(' expression ')'  */
#line 526 "./postscript.y"
                             {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s exp", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2227 "y.tab.c"
    break;

  case 85: /* math_function: LOG '(' expression ')'  */
#line 532 "./postscript.y"
                             {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s ln", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2238 "y.tab.c"
    break;

  case 86: /* math_function: FLOOR '(' expression ')'  */
#line 538 "./postscript.y"
                               {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s floor", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2249 "y.tab.c"
    break;

  case 87: /* math_function: CEIL '(' expression ')'  */
#line 544 "./postscript.y"
                              {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "%s ceiling", (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
        free((yyvsp[-1].str));
    }
#line 2260 "y.tab.c"
    break;

  case 88: /* param_def_list: %empty  */
#line 554 "./postscript.y"
                 { param_count_def = 0; }
#line 2266 "y.tab.c"
    break;

  case 90: /* param_def_item: IDENTIFIER  */
#line 559 "./postscript.y"
               {
        strcpy(param_names[param_count_def], (yyvsp[0].str));
        param_count_def++;
    }
#line 2275 "y.tab.c"
    break;

  case 91: /* param_def_item: param_def_item ',' IDENTIFIER  */
#line 563 "./postscript.y"
                                    {
        strcpy(param_names[param_count_def], (yyvsp[0].str));
        param_count_def++;
    }
#line 2284 "y.tab.c"
    break;


#line 2288 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 569 "./postscript.y"


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
