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
#line 1 "postscript.y"

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

#define NPROG 50000
int indef = 0;

#define code2(c1, c2)   code(c1); code(c2)
#define code3(c1, c2, c3)   code(c1); code(c2); code(c3)

#line 94 "y.tab.c"

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
    STRING = 259,                  /* STRING  */
    VAR = 260,                     /* VAR  */
    FUNCTION = 261,                /* FUNCTION  */
    PROCEDURE = 262,               /* PROCEDURE  */
    ARG = 263,                     /* ARG  */
    FONT_ID = 264,                 /* FONT_ID  */
    BEGIN_POST = 265,              /* BEGIN_POST  */
    END_POST = 266,                /* END_POST  */
    LINEA = 267,                   /* LINEA  */
    CIRCULO = 268,                 /* CIRCULO  */
    RECTANGULO = 269,              /* RECTANGULO  */
    COLOR = 270,                   /* COLOR  */
    STROKE = 271,                  /* STROKE  */
    FILL = 272,                    /* FILL  */
    SETLINEWIDTH = 273,            /* SETLINEWIDTH  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    FOR = 277,                     /* FOR  */
    FUNC = 278,                    /* FUNC  */
    PROC = 279,                    /* PROC  */
    RETURN = 280,                  /* RETURN  */
    PRINT = 281,                   /* PRINT  */
    GT = 282,                      /* GT  */
    GE = 283,                      /* GE  */
    LT = 284,                      /* LT  */
    LE = 285,                      /* LE  */
    EQ = 286,                      /* EQ  */
    NE = 287,                      /* NE  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    NOT = 290,                     /* NOT  */
    TEXTO = 291,                   /* TEXTO  */
    FUENTE = 292,                  /* FUENTE  */
    SIN = 293,                     /* SIN  */
    COS = 294,                     /* COS  */
    UNARYMINUS = 295               /* UNARYMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUMBER 258
#define STRING 259
#define VAR 260
#define FUNCTION 261
#define PROCEDURE 262
#define ARG 263
#define FONT_ID 264
#define BEGIN_POST 265
#define END_POST 266
#define LINEA 267
#define CIRCULO 268
#define RECTANGULO 269
#define COLOR 270
#define STROKE 271
#define FILL 272
#define SETLINEWIDTH 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define FOR 277
#define FUNC 278
#define PROC 279
#define RETURN 280
#define PRINT 281
#define GT 282
#define GE 283
#define LT 284
#define LE 285
#define EQ 286
#define NE 287
#define AND 288
#define OR 289
#define NOT 290
#define TEXTO 291
#define FUENTE 292
#define SIN 293
#define COS 294
#define UNARYMINUS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "postscript.y"

    Symbol *sym;
    Inst *inst;
    double dval;
    int narg;
    char *string;

#line 235 "y.tab.c"

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
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_FUNCTION = 6,                   /* FUNCTION  */
  YYSYMBOL_PROCEDURE = 7,                  /* PROCEDURE  */
  YYSYMBOL_ARG = 8,                        /* ARG  */
  YYSYMBOL_FONT_ID = 9,                    /* FONT_ID  */
  YYSYMBOL_BEGIN_POST = 10,                /* BEGIN_POST  */
  YYSYMBOL_END_POST = 11,                  /* END_POST  */
  YYSYMBOL_LINEA = 12,                     /* LINEA  */
  YYSYMBOL_CIRCULO = 13,                   /* CIRCULO  */
  YYSYMBOL_RECTANGULO = 14,                /* RECTANGULO  */
  YYSYMBOL_COLOR = 15,                     /* COLOR  */
  YYSYMBOL_STROKE = 16,                    /* STROKE  */
  YYSYMBOL_FILL = 17,                      /* FILL  */
  YYSYMBOL_SETLINEWIDTH = 18,              /* SETLINEWIDTH  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_FUNC = 23,                      /* FUNC  */
  YYSYMBOL_PROC = 24,                      /* PROC  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_PRINT = 26,                     /* PRINT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_GE = 28,                        /* GE  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_EQ = 31,                        /* EQ  */
  YYSYMBOL_NE = 32,                        /* NE  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_TEXTO = 36,                     /* TEXTO  */
  YYSYMBOL_FUENTE = 37,                    /* FUENTE  */
  YYSYMBOL_SIN = 38,                       /* SIN  */
  YYSYMBOL_COS = 39,                       /* COS  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_UNARYMINUS = 45,                /* UNARYMINUS  */
  YYSYMBOL_46_n_ = 46,                     /* '\n'  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* ')'  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_list = 54,                      /* list  */
  YYSYMBOL_postscript = 55,                /* postscript  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_post_content = 57,              /* post_content  */
  YYSYMBOL_fig_stmt = 58,                  /* fig_stmt  */
  YYSYMBOL_dibujar_stmt = 59,              /* dibujar_stmt  */
  YYSYMBOL_stmt = 60,                      /* stmt  */
  YYSYMBOL_for = 61,                       /* for  */
  YYSYMBOL_forexpr = 62,                   /* forexpr  */
  YYSYMBOL_begin = 63,                     /* begin  */
  YYSYMBOL_cond = 64,                      /* cond  */
  YYSYMBOL_while = 65,                     /* while  */
  YYSYMBOL_if = 66,                        /* if  */
  YYSYMBOL_end = 67,                       /* end  */
  YYSYMBOL_stmtlist = 68,                  /* stmtlist  */
  YYSYMBOL_asgn = 69,                      /* asgn  */
  YYSYMBOL_expr = 70,                      /* expr  */
  YYSYMBOL_defn = 71,                      /* defn  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_procname = 74,                  /* procname  */
  YYSYMBOL_arglist = 75                    /* arglist  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   888

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  211

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      46,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    49,    43,    41,    48,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    59,    60,    61,    62,    66,    66,    78,
      80,    81,    88,    92,    98,   104,   110,   119,   125,   131,
     138,   139,   140,   141,   142,   143,   144,   145,   150,   155,
     161,   169,   170,   174,   179,   193,   220,   223,   226,   229,
     232,   235,   238,   242,   243,   244,   248,   252,   260,   264,
     267,   271,   272,   276,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     301,   309,   309,   315,   315,   323,   327,   328,   329
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "STRING",
  "VAR", "FUNCTION", "PROCEDURE", "ARG", "FONT_ID", "BEGIN_POST",
  "END_POST", "LINEA", "CIRCULO", "RECTANGULO", "COLOR", "STROKE", "FILL",
  "SETLINEWIDTH", "IF", "ELSE", "WHILE", "FOR", "FUNC", "PROC", "RETURN",
  "PRINT", "GT", "GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT", "TEXTO",
  "FUENTE", "SIN", "COS", "'='", "'+'", "'-'", "'*'", "'/'", "UNARYMINUS",
  "'\\n'", "'('", "','", "')'", "';'", "'{'", "'}'", "$accept", "list",
  "postscript", "$@1", "post_content", "fig_stmt", "dibujar_stmt", "stmt",
  "for", "forexpr", "begin", "cond", "while", "if", "end", "stmtlist",
  "asgn", "expr", "defn", "$@2", "$@3", "procname", "arglist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -142,    57,  -142,   -35,    39,    43,    43,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,    -3,     3,   217,     2,
       4,  -142,   -28,  -142,  -142,    12,  -142,    17,    18,    21,
    -142,  -142,  -142,   288,   288,   288,    23,    24,    25,    26,
     288,  -142,   288,  -142,  -142,  -142,     9,    27,    29,    29,
       8,   819,    13,   264,   264,   304,    32,    38,    52,   288,
      81,    95,   288,   -27,  -142,   819,   819,  -142,   288,    96,
     288,   288,  -142,   325,   167,  -142,   288,   288,   264,   264,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,  -142,  -142,  -142,    59,    63,    65,    66,   819,
     288,   288,   288,   819,    56,    67,   348,   288,    69,   555,
      70,   371,   394,  -142,  -142,  -142,    71,    72,   819,   417,
    -142,  -142,   -20,   -20,   -20,   -20,   -20,   -20,   844,   837,
     -29,   -29,  -142,  -142,   288,   288,   288,   288,   819,   -32,
     -22,   -15,   114,   118,  -142,   288,   288,   288,  -142,  -142,
    -142,   288,  -142,  -142,   106,   577,   599,   621,   643,   288,
     101,  -142,  -142,    78,    79,   -11,   665,   440,    80,   264,
     288,   288,   288,   288,   819,  -142,  -142,  -142,   125,  -142,
     288,  -142,   687,   709,   731,   753,    83,    84,  -142,   288,
     288,   288,   288,   127,   264,   775,   463,   797,   486,    85,
    -142,   288,  -142,   288,  -142,  -142,  -142,   509,   532,  -142,
    -142
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     3,     4,     5,
       6,     7,    75,    71,    73,     9,     0,     0,     0,     0,
       0,    48,    49,    38,    38,    50,     8,     0,     0,     0,
      41,    40,    36,    24,     0,     0,     0,     0,     0,     0,
       0,    10,     0,    43,    22,    23,     0,     0,     0,     0,
      51,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,    51,    25,    26,    68,     0,     0,
       0,     0,    58,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    72,    74,     0,     0,     0,     0,    46,
      76,    76,    76,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    44,    31,     0,     0,    37,     0,
      42,    42,    60,    61,    62,    63,    64,    65,    66,    67,
      54,    55,    56,    57,     0,     0,     0,     0,    77,     0,
       0,     0,     0,     0,    19,    76,     0,     0,    69,    70,
      45,     0,    39,    27,    28,     0,     0,     0,     0,     0,
      53,    52,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    78,    17,    18,    53,     0,    34,
       0,    42,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      42,     0,    14,     0,    16,    35,    30,     0,     0,    13,
      15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,  -142,  -142,  -142,  -142,   -49,  -142,  -141,
     -17,    86,  -142,  -142,  -118,  -142,   -18,     7,   119,  -142,
    -142,   130,  -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     8,    15,    18,    44,    45,    46,    47,   117,
      56,    78,    48,    49,   153,    74,    64,    51,     9,    16,
      17,    13,   139
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   140,   141,   154,    93,    94,    57,    58,   -21,   -21,
     168,    10,    55,   107,    90,    91,   159,   160,   -21,   -38,
     -38,    88,    89,    90,    91,   116,   159,   161,   -21,   120,
     121,   -21,   -21,   159,   162,    50,    50,   159,   177,   187,
      65,    66,    67,    11,    19,   165,   108,    72,    12,    73,
      20,    53,    59,    54,   -21,    75,    50,     2,     3,    92,
      50,    50,    99,   188,    60,    61,   103,     4,    62,   106,
      68,    69,    70,    71,    76,   109,    77,   111,   112,   100,
       5,     6,   206,   118,   119,   101,   104,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   102,
     105,   -33,   -33,     7,   142,   110,   134,   138,   138,   138,
     135,   -33,   136,   137,    99,   143,   145,   150,   147,   163,
     181,   -33,   151,   164,   -33,   -33,   169,   175,   176,   186,
     180,   193,   199,   194,   205,    79,    14,    52,     0,     0,
       0,   155,   156,   157,   158,   200,     0,   -33,     0,     0,
       0,    50,   138,   166,   167,     0,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
      21,     0,    22,    23,    24,    25,    50,   182,   183,   184,
     185,     0,     0,    27,    28,    29,    30,   118,    31,    32,
       0,     0,    33,    34,     0,     0,   195,   196,   197,   198,
       0,     0,    35,    36,    37,    38,    39,     0,   207,    40,
     208,     0,     0,   114,    42,     0,     0,     0,    43,   115,
      21,     0,    22,    23,    24,    25,     0,     0,    26,     0,
       0,     0,     0,    27,    28,    29,    30,     0,    31,    32,
       5,     6,    33,    34,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    37,    38,    39,     0,     0,    40,
       0,     0,     0,    41,    42,     0,     0,    21,    43,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
      27,    28,    29,    30,     0,    31,    32,     0,     0,    33,
      34,    21,     0,    63,    23,     0,    25,     0,     0,    35,
      36,    37,    38,    39,     0,     0,    40,    21,     0,    63,
      23,    42,    25,     0,     0,    43,    95,    96,    97,    98,
       0,     0,     0,    35,     0,     0,    38,    39,     0,     0,
      40,     0,     0,     0,     0,    42,     0,     0,     0,    35,
       0,     0,    38,    39,     0,     0,    40,     0,     0,     0,
       0,    42,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,     0,     0,     0,   113,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,     0,     0,     0,   144,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,     0,     0,     0,
     148,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
       0,     0,     0,   149,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,     0,     0,     0,   152,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,     0,     0,     0,   179,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,     0,
       0,     0,   202,    80,    81,    82,    83,    84,    85,    86,
      87,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,     0,     0,     0,   204,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,     0,     0,     0,   209,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,     0,     0,
       0,   210,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,     0,     0,   146,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,     0,     0,   170,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,     0,     0,   171,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,     0,     0,   172,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,     0,
       0,   173,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,     0,     0,   178,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,     0,     0,   189,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,     0,     0,   190,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,     0,     0,   191,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,     0,
       0,   192,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,     0,     0,   201,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,     0,     0,   203,    80,    81,    82,    83,
      84,    85,    86,    87,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,    80,    81,    82,    83,    84,    85,
      86,    80,    81,    82,    83,    84,    85,     0,    88,    89,
      90,    91,     0,     0,     0,    88,    89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      18,   101,   102,   121,    53,    54,    23,    24,     0,     1,
     151,    46,    40,    40,    43,    44,    48,    49,    10,    47,
      47,    41,    42,    43,    44,    74,    48,    49,    20,    78,
      79,    23,    24,    48,    49,    53,    54,    48,    49,   180,
      33,    34,    35,     4,    47,   145,    63,    40,     5,    42,
      47,    49,    40,    49,    46,    46,    74,     0,     1,    46,
      78,    79,    55,   181,    47,    47,    59,    10,    47,    62,
      47,    47,    47,    47,    47,    68,    47,    70,    71,    47,
      23,    24,   200,    76,    77,    47,     5,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    47,
       5,     0,     1,    46,    48,     9,    47,   100,   101,   102,
      47,    10,    47,    47,   107,    48,    47,    46,    48,     5,
     169,    20,    50,     5,    23,    24,    20,    49,    49,     4,
      50,    48,     5,    49,    49,    49,     6,    18,    -1,    -1,
      -1,   134,   135,   136,   137,   194,    -1,    46,    -1,    -1,
      -1,   169,   145,   146,   147,    -1,    -1,    -1,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,   194,   170,   171,   172,
     173,    -1,    -1,    16,    17,    18,    19,   180,    21,    22,
      -1,    -1,    25,    26,    -1,    -1,   189,   190,   191,   192,
      -1,    -1,    35,    36,    37,    38,    39,    -1,   201,    42,
     203,    -1,    -1,    46,    47,    -1,    -1,    -1,    51,    52,
       3,    -1,     5,     6,     7,     8,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    46,    47,    -1,    -1,     3,    51,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    -1,    21,    22,    -1,    -1,    25,
      26,     3,    -1,     5,     6,    -1,     8,    -1,    -1,    35,
      36,    37,    38,    39,    -1,    -1,    42,     3,    -1,     5,
       6,    47,     8,    -1,    -1,    51,    12,    13,    14,    15,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    35,
      -1,    -1,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    49,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    -1,    49,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      49,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    49,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    49,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    49,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    49,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    49,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    49,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    49,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    48,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    27,    28,    29,    30,    31,    32,
      33,    27,    28,    29,    30,    31,    32,    -1,    41,    42,
      43,    44,    -1,    -1,    -1,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,     0,     1,    10,    23,    24,    46,    55,    71,
      46,     4,     5,    74,    74,    56,    72,    73,    57,    47,
      47,     3,     5,     6,     7,     8,    11,    16,    17,    18,
      19,    21,    22,    25,    26,    35,    36,    37,    38,    39,
      42,    46,    47,    51,    58,    59,    60,    61,    65,    66,
      69,    70,    71,    49,    49,    40,    63,    63,    63,    40,
      47,    47,    47,     5,    69,    70,    70,    70,    47,    47,
      47,    47,    70,    70,    68,    46,    47,    47,    64,    64,
      27,    28,    29,    30,    31,    32,    33,    34,    41,    42,
      43,    44,    46,    60,    60,    12,    13,    14,    15,    70,
      47,    47,    47,    70,     5,     5,    70,    40,    63,    70,
       9,    70,    70,    49,    46,    52,    60,    62,    70,    70,
      60,    60,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    47,    47,    47,    47,    70,    75,
      75,    75,    48,    48,    49,    47,    48,    48,    49,    49,
      46,    50,    49,    67,    67,    70,    70,    70,    70,    48,
      49,    49,    49,     5,     5,    75,    70,    70,    62,    20,
      48,    48,    48,    48,    70,    49,    49,    49,    48,    49,
      50,    60,    70,    70,    70,    70,     4,    62,    67,    48,
      48,    48,    48,    48,    49,    70,    70,    70,    70,     5,
      60,    48,    49,    48,    49,    49,    67,    70,    70,    49,
      49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    54,    56,    55,    57,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    72,    71,    73,    71,    74,    75,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     0,     5,     0,
       2,     3,     3,    12,    10,    12,    10,     6,     6,     4,
       1,     1,     1,     1,     1,     2,     2,     4,     4,     7,
      10,     3,     5,     5,     6,    10,     1,     1,     0,     3,
       1,     1,     0,     0,     2,     3,     3,     3,     1,     1,
       1,     1,     5,     5,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     4,
       4,     0,     6,     0,     6,     1,     0,     1,     3
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
  case 6: /* list: list error '\n'  */
#line 62 "postscript.y"
                        { yyerrok; }
#line 1551 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 66 "postscript.y"
                      {
          ps_begin_document((yyvsp[0].string));
          initcode();
      }
#line 1560 "y.tab.c"
    break;

  case 8: /* postscript: BEGIN_POST STRING $@1 post_content END_POST  */
#line 71 "postscript.y"
               {
          ps_end_document();
          printf("Documento PostScript generado: %s\n", (yyvsp[-3].string));
          free((yyvsp[-3].string));
      }
#line 1570 "y.tab.c"
    break;

  case 11: /* post_content: post_content stmt '\n'  */
#line 81 "postscript.y"
                             {
        if((yyvsp[-1].inst)){
            code(STOP);
            execute((yyvsp[-1].inst));
            progbase = progp;
        }
    }
#line 1582 "y.tab.c"
    break;

  case 13: /* fig_stmt: VAR '=' LINEA '(' expr ',' expr ',' expr ',' expr ')'  */
#line 92 "postscript.y"
                                                            {
          // line = linea(x1, y1, x2, y2)
          (yyval.inst) = (yyvsp[-7].inst);  /* Inicio del código */
          code(create_line_shape);
          code3(varpush, (Inst)(yyvsp[-11].sym), assign);
      }
#line 1593 "y.tab.c"
    break;

  case 14: /* fig_stmt: VAR '=' CIRCULO '(' expr ',' expr ',' expr ')'  */
#line 98 "postscript.y"
                                                     {
          // circ = circulo(x, y, r)
          (yyval.inst) = (yyvsp[-5].inst);
          code(create_circle_shape);
          code3(varpush, (Inst)(yyvsp[-9].sym), assign);
      }
#line 1604 "y.tab.c"
    break;

  case 15: /* fig_stmt: VAR '=' RECTANGULO '(' expr ',' expr ',' expr ',' expr ')'  */
#line 104 "postscript.y"
                                                                 {
          // rect = rectangulo(x, y, w, h)
          (yyval.inst) = (yyvsp[-7].inst);
          code(create_rect_shape);
          code3(varpush, (Inst)(yyvsp[-11].sym), assign);
      }
#line 1615 "y.tab.c"
    break;

  case 16: /* fig_stmt: VAR '=' COLOR '(' expr ',' expr ',' expr ')'  */
#line 110 "postscript.y"
                                                   {
          // rojo = color(r, g, b)
          (yyval.inst) = (yyvsp[-5].inst);
          code(create_color);
          code3(varpush, (Inst)(yyvsp[-9].sym), assign);
      }
#line 1626 "y.tab.c"
    break;

  case 17: /* dibujar_stmt: STROKE '(' VAR ',' VAR ')'  */
#line 119 "postscript.y"
                                 {
          // stroke(shape, color)
          (yyval.inst) = code3(varpush, (Inst)(yyvsp[-3].sym), eval);
          code3(varpush, (Inst)(yyvsp[-1].sym), eval); //COLOR
          code(ps_stroke);
      }
#line 1637 "y.tab.c"
    break;

  case 18: /* dibujar_stmt: FILL '(' VAR ',' VAR ')'  */
#line 125 "postscript.y"
                               {
          // fill(shape, color)
          (yyval.inst) = code3(varpush, (Inst)(yyvsp[-3].sym), eval);
          code3(varpush, (Inst)(yyvsp[-1].sym), eval);
          code(ps_fill);
      }
#line 1648 "y.tab.c"
    break;

  case 19: /* dibujar_stmt: SETLINEWIDTH '(' expr ')'  */
#line 131 "postscript.y"
                                {
          (yyval.inst) = (yyvsp[-1].inst);
          code(ps_setlinewidth);
      }
#line 1657 "y.tab.c"
    break;

  case 20: /* stmt: expr  */
#line 138 "postscript.y"
           { code(pop1); (yyval.inst) = (yyvsp[0].inst); }
#line 1663 "y.tab.c"
    break;

  case 21: /* stmt: asgn  */
#line 139 "postscript.y"
           { code(pop1); }
#line 1669 "y.tab.c"
    break;

  case 24: /* stmt: RETURN  */
#line 142 "postscript.y"
             { defnonly("return"); code(procret); (yyval.inst)= progp; }
#line 1675 "y.tab.c"
    break;

  case 25: /* stmt: RETURN expr  */
#line 143 "postscript.y"
                  { defnonly("return"); (yyval.inst)=(yyvsp[0].inst); code(funcret); }
#line 1681 "y.tab.c"
    break;

  case 26: /* stmt: PRINT expr  */
#line 144 "postscript.y"
                 { (yyval.inst) = (yyvsp[0].inst); code(print); }
#line 1687 "y.tab.c"
    break;

  case 27: /* stmt: while cond stmt end  */
#line 145 "postscript.y"
                          {
          ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-3].inst))[2] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-3].inst);
      }
#line 1697 "y.tab.c"
    break;

  case 28: /* stmt: if cond stmt end  */
#line 150 "postscript.y"
                       {
          ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-3].inst))[3] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-3].inst);
      }
#line 1707 "y.tab.c"
    break;

  case 29: /* stmt: if cond stmt end ELSE stmt end  */
#line 155 "postscript.y"
                                     {
          ((yyvsp[-6].inst))[1] = (Inst)(yyvsp[-4].inst);
          ((yyvsp[-6].inst))[2] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-6].inst))[3] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-6].inst);
      }
#line 1718 "y.tab.c"
    break;

  case 30: /* stmt: for '(' forexpr ';' forexpr ';' forexpr ')' stmt end  */
#line 161 "postscript.y"
                                                           {
          ((yyvsp[-9].inst))[1] = (Inst)(yyvsp[-7].inst);
          ((yyvsp[-9].inst))[2] = (Inst)(yyvsp[-5].inst);
          ((yyvsp[-9].inst))[3] = (Inst)(yyvsp[-3].inst);
          ((yyvsp[-9].inst))[4] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-9].inst))[5] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-9].inst);
      }
#line 1731 "y.tab.c"
    break;

  case 31: /* stmt: '{' stmtlist '}'  */
#line 169 "postscript.y"
                       { (yyval.inst) = (yyvsp[-1].inst); }
#line 1737 "y.tab.c"
    break;

  case 32: /* stmt: PROCEDURE begin '(' arglist ')'  */
#line 170 "postscript.y"
                                      {
          (yyval.inst) = (yyvsp[-3].inst);
          code3(call, (Inst)(yyvsp[-4].sym), (Inst)(long)(yyvsp[-1].narg));
      }
#line 1746 "y.tab.c"
    break;

  case 33: /* stmt: VAR begin '(' arglist ')'  */
#line 174 "postscript.y"
                                {
        /* Permitir llamadas a procedimientos aún no definidos */
        (yyval.inst) = (yyvsp[-3].inst);
        code3(call, (Inst)(yyvsp[-4].sym), (Inst)(long)(yyvsp[-1].narg));
    }
#line 1756 "y.tab.c"
    break;

  case 34: /* stmt: FUENTE '(' FONT_ID ',' expr ')'  */
#line 179 "postscript.y"
                                      {
          /* El código empieza donde empieza la expresión del tamaño ($5) */
          (yyval.inst) = (yyvsp[-1].inst); 
          
          /* Generación de código:
             1. expr ($5) ya generó el código para empujar el TAMAÑO.
             2. Ahora generamos código para empujar el ID DE FUENTE.
          */
          code(constpush_n);
          code_double((double)(yyvsp[-3].narg)); 
          
          code(ps_setup_font);

    }
#line 1775 "y.tab.c"
    break;

  case 35: /* stmt: TEXTO '(' expr ',' expr ',' STRING ',' VAR ')'  */
#line 193 "postscript.y"
                                                     {
          /* Estructura: texto(x, y, "Hola", rojo) */
          /* $3=x, $5=y, $7="Hola", $9=rojo(VAR) */
          
          Inst *start = (yyvsp[-7].inst); /* Guardamos inicio de X */
          
          /* 1. X y Y ya generaron su código (expr) */
          
          /* 2. Empujar el String Literal */
          code(constpush_str);
          
          if ((char*)progp + sizeof(char*) > (char*)&prog[NPROG])
                execerror("program too big (string)", (char *)0);
          *(char **)progp = (yyvsp[-3].string); 
          progp = (Inst *)((char **)progp + 1);

          /* 3. Empujar y Evaluar la Variable de COLOR ($9) */
          /* Esto busca 'rojo' y pone su valor en la pila */
          code3(varpush, (Inst)(yyvsp[-1].sym), eval); 

          /* 4. Llamar a dibujar */
          code(ps_draw_text);
          
          (yyval.inst) = start; 
    }
#line 1805 "y.tab.c"
    break;

  case 36: /* for: FOR  */
#line 220 "postscript.y"
         { (yyval.inst) = code3(forcode, STOP, STOP); code3(STOP, STOP, STOP); }
#line 1811 "y.tab.c"
    break;

  case 37: /* forexpr: expr  */
#line 223 "postscript.y"
              { code(STOP); (yyval.inst) = (yyvsp[0].inst); }
#line 1817 "y.tab.c"
    break;

  case 38: /* begin: %empty  */
#line 226 "postscript.y"
       { (yyval.inst) = progp; }
#line 1823 "y.tab.c"
    break;

  case 39: /* cond: '(' expr ')'  */
#line 229 "postscript.y"
                   { code(STOP); (yyval.inst) = (yyvsp[-1].inst); }
#line 1829 "y.tab.c"
    break;

  case 40: /* while: WHILE  */
#line 232 "postscript.y"
             { (yyval.inst) = code3(whilecode, STOP, STOP); }
#line 1835 "y.tab.c"
    break;

  case 41: /* if: IF  */
#line 235 "postscript.y"
       { (yyval.inst) = code(ifcode); code3(STOP, STOP, STOP); }
#line 1841 "y.tab.c"
    break;

  case 42: /* end: %empty  */
#line 238 "postscript.y"
                  { code(STOP); (yyval.inst) = progp; }
#line 1847 "y.tab.c"
    break;

  case 43: /* stmtlist: %empty  */
#line 242 "postscript.y"
                   { (yyval.inst) = progp; }
#line 1853 "y.tab.c"
    break;

  case 45: /* stmtlist: stmtlist stmt '\n'  */
#line 244 "postscript.y"
                         { (yyval.inst) = (yyvsp[-2].inst); }
#line 1859 "y.tab.c"
    break;

  case 46: /* asgn: VAR '=' expr  */
#line 248 "postscript.y"
                   {
          code3(varpush, (Inst)(yyvsp[-2].sym), assign);
          (yyval.inst) = (yyvsp[0].inst);
      }
#line 1868 "y.tab.c"
    break;

  case 47: /* asgn: ARG '=' expr  */
#line 252 "postscript.y"
                   {
          defnonly("$");
          code2(argassign, (Inst)(long)(yyvsp[-2].narg));
          (yyval.inst) = (yyvsp[0].inst);
      }
#line 1878 "y.tab.c"
    break;

  case 48: /* expr: NUMBER  */
#line 260 "postscript.y"
             { 
          (yyval.inst) = code(constpush_n); 
          code_double((yyvsp[0].dval)); 
      }
#line 1887 "y.tab.c"
    break;

  case 49: /* expr: VAR  */
#line 264 "postscript.y"
          { 
          (yyval.inst) = code3(varpush, (Inst)(yyvsp[0].sym), eval); 
      }
#line 1895 "y.tab.c"
    break;

  case 50: /* expr: ARG  */
#line 267 "postscript.y"
          { 
          defnonly("$"); 
          (yyval.inst) = code2(arg, (Inst)(long)(yyvsp[0].narg)); 
      }
#line 1904 "y.tab.c"
    break;

  case 52: /* expr: FUNCTION begin '(' arglist ')'  */
#line 272 "postscript.y"
                                     {
          (yyval.inst) = (yyvsp[-3].inst);
          code3(call, (Inst)(yyvsp[-4].sym), (Inst)(long)(yyvsp[-1].narg));
      }
#line 1913 "y.tab.c"
    break;

  case 53: /* expr: VAR begin '(' arglist ')'  */
#line 276 "postscript.y"
                                {
        /* Permitir llamadas a funciones aún no definidas */
        (yyval.inst) = (yyvsp[-3].inst);
        code3(call, (Inst)(yyvsp[-4].sym), (Inst)(long)(yyvsp[-1].narg));
    }
#line 1923 "y.tab.c"
    break;

  case 54: /* expr: expr '+' expr  */
#line 281 "postscript.y"
                    { code(add); (yyval.inst) = (yyvsp[-2].inst); }
#line 1929 "y.tab.c"
    break;

  case 55: /* expr: expr '-' expr  */
#line 282 "postscript.y"
                    { code(sub); (yyval.inst) = (yyvsp[-2].inst); }
#line 1935 "y.tab.c"
    break;

  case 56: /* expr: expr '*' expr  */
#line 283 "postscript.y"
                    { code(mul); (yyval.inst) = (yyvsp[-2].inst); }
#line 1941 "y.tab.c"
    break;

  case 57: /* expr: expr '/' expr  */
#line 284 "postscript.y"
                    { code(divide); (yyval.inst) = (yyvsp[-2].inst); }
#line 1947 "y.tab.c"
    break;

  case 58: /* expr: '-' expr  */
#line 285 "postscript.y"
                                { code(negate); (yyval.inst) = (yyvsp[0].inst); }
#line 1953 "y.tab.c"
    break;

  case 59: /* expr: '(' expr ')'  */
#line 286 "postscript.y"
                   { (yyval.inst) = (yyvsp[-1].inst); }
#line 1959 "y.tab.c"
    break;

  case 60: /* expr: expr GT expr  */
#line 287 "postscript.y"
                   { code(gt); (yyval.inst) = (yyvsp[-2].inst); }
#line 1965 "y.tab.c"
    break;

  case 61: /* expr: expr GE expr  */
#line 288 "postscript.y"
                   { code(ge); (yyval.inst) = (yyvsp[-2].inst); }
#line 1971 "y.tab.c"
    break;

  case 62: /* expr: expr LT expr  */
#line 289 "postscript.y"
                   { code(lt); (yyval.inst) = (yyvsp[-2].inst); }
#line 1977 "y.tab.c"
    break;

  case 63: /* expr: expr LE expr  */
#line 290 "postscript.y"
                   { code(le); (yyval.inst) = (yyvsp[-2].inst); }
#line 1983 "y.tab.c"
    break;

  case 64: /* expr: expr EQ expr  */
#line 291 "postscript.y"
                   { code(eq); (yyval.inst) = (yyvsp[-2].inst); }
#line 1989 "y.tab.c"
    break;

  case 65: /* expr: expr NE expr  */
#line 292 "postscript.y"
                   { code(ne); (yyval.inst) = (yyvsp[-2].inst); }
#line 1995 "y.tab.c"
    break;

  case 66: /* expr: expr AND expr  */
#line 293 "postscript.y"
                    { code(and_op); (yyval.inst) = (yyvsp[-2].inst); }
#line 2001 "y.tab.c"
    break;

  case 67: /* expr: expr OR expr  */
#line 294 "postscript.y"
                   { code(or_op); (yyval.inst) = (yyvsp[-2].inst); }
#line 2007 "y.tab.c"
    break;

  case 68: /* expr: NOT expr  */
#line 295 "postscript.y"
               { code(not_op); (yyval.inst) = (yyvsp[0].inst); }
#line 2013 "y.tab.c"
    break;

  case 69: /* expr: SIN '(' expr ')'  */
#line 296 "postscript.y"
                       { 
        /* Genera código para expr primero, luego la instrucción sin */
        (yyval.inst) = (yyvsp[-1].inst); 
        code(ps_sin); 
    }
#line 2023 "y.tab.c"
    break;

  case 70: /* expr: COS '(' expr ')'  */
#line 301 "postscript.y"
                       { 
        (yyval.inst) = (yyvsp[-1].inst); 
        code(ps_cos); 
    }
#line 2032 "y.tab.c"
    break;

  case 71: /* $@2: %empty  */
#line 309 "postscript.y"
                    { (yyvsp[0].sym)->type = TYPE_FUNCTION; indef = 1; }
#line 2038 "y.tab.c"
    break;

  case 72: /* defn: FUNC procname $@2 '(' ')' stmt  */
#line 310 "postscript.y"
                   { 
          code(procret); 
          define((yyvsp[-4].sym)); 
          indef = 0; 
      }
#line 2048 "y.tab.c"
    break;

  case 73: /* $@3: %empty  */
#line 315 "postscript.y"
                    { (yyvsp[0].sym)->type = TYPE_PROCEDURE; indef = 1; }
#line 2054 "y.tab.c"
    break;

  case 74: /* defn: PROC procname $@3 '(' ')' stmt  */
#line 316 "postscript.y"
                   { 
          code(procret); 
          define((yyvsp[-4].sym)); 
          indef = 0; 
      }
#line 2064 "y.tab.c"
    break;

  case 76: /* arglist: %empty  */
#line 327 "postscript.y"
                   { (yyval.narg) = 0; }
#line 2070 "y.tab.c"
    break;

  case 77: /* arglist: expr  */
#line 328 "postscript.y"
           { (yyval.narg) = 1; }
#line 2076 "y.tab.c"
    break;

  case 78: /* arglist: arglist ',' expr  */
#line 329 "postscript.y"
                       { (yyval.narg) = (yyvsp[-2].narg) + 1; }
#line 2082 "y.tab.c"
    break;


#line 2086 "y.tab.c"

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

#line 332 "postscript.y"



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
