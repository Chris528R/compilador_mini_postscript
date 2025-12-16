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
    UNARYMINUS = 293               /* UNARYMINUS  */
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
#define UNARYMINUS 293

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

#line 231 "y.tab.c"

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
  YYSYMBOL_38_ = 38,                       /* '='  */
  YYSYMBOL_39_ = 39,                       /* '+'  */
  YYSYMBOL_40_ = 40,                       /* '-'  */
  YYSYMBOL_41_ = 41,                       /* '*'  */
  YYSYMBOL_42_ = 42,                       /* '/'  */
  YYSYMBOL_UNARYMINUS = 43,                /* UNARYMINUS  */
  YYSYMBOL_44_n_ = 44,                     /* '\n'  */
  YYSYMBOL_45_ = 45,                       /* '('  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_list = 52,                      /* list  */
  YYSYMBOL_postscript = 53,                /* postscript  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_post_content = 55,              /* post_content  */
  YYSYMBOL_fig_stmt = 56,                  /* fig_stmt  */
  YYSYMBOL_dibujar_stmt = 57,              /* dibujar_stmt  */
  YYSYMBOL_stmt = 58,                      /* stmt  */
  YYSYMBOL_for = 59,                       /* for  */
  YYSYMBOL_forexpr = 60,                   /* forexpr  */
  YYSYMBOL_begin = 61,                     /* begin  */
  YYSYMBOL_cond = 62,                      /* cond  */
  YYSYMBOL_while = 63,                     /* while  */
  YYSYMBOL_if = 64,                        /* if  */
  YYSYMBOL_end = 65,                       /* end  */
  YYSYMBOL_stmtlist = 66,                  /* stmtlist  */
  YYSYMBOL_asgn = 67,                      /* asgn  */
  YYSYMBOL_expr = 68,                      /* expr  */
  YYSYMBOL_defn = 69,                      /* defn  */
  YYSYMBOL_70_2 = 70,                      /* $@2  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_procname = 72,                  /* procname  */
  YYSYMBOL_arglist = 73                    /* arglist  */
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
#define YYLAST   716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      45,    47,    41,    39,    46,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    59,    60,    61,    62,    66,    66,    78,
      80,    81,    88,    92,    98,   104,   110,   119,   125,   131,
     138,   139,   140,   141,   142,   143,   144,   145,   150,   155,
     161,   169,   170,   174,   188,   215,   218,   221,   224,   227,
     230,   233,   237,   238,   239,   243,   247,   255,   259,   262,
     266,   267,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   290,   290,   296,
     296,   304,   308,   309,   310
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
  "FUENTE", "'='", "'+'", "'-'", "'*'", "'/'", "UNARYMINUS", "'\\n'",
  "'('", "','", "')'", "';'", "'{'", "'}'", "$accept", "list",
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

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -138,     6,  -138,   -39,    13,    26,    26,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,   -13,   -10,   180,   -11,
      -7,  -138,    -1,  -138,  -138,     4,  -138,    -2,     0,     1,
    -138,  -138,  -138,   231,   231,   231,     7,     9,   231,  -138,
     231,  -138,  -138,  -138,     5,    30,    32,    32,    38,   658,
      34,   225,   225,    82,    35,    36,   231,    74,    81,   231,
      53,  -138,   658,   658,  -138,   231,    83,  -138,   250,   132,
    -138,   231,   231,   225,   225,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,  -138,  -138,  -138,
      48,    54,    55,    56,   658,   231,   231,   658,    52,    57,
     271,   231,   418,    58,  -138,  -138,  -138,    84,    77,   658,
     292,  -138,  -138,   -31,   -31,   -31,   -31,   -31,   -31,   674,
      79,   -29,   -29,  -138,  -138,   231,   231,   231,   231,   658,
     -32,   -28,    97,   125,  -138,   231,   231,  -138,   231,  -138,
    -138,   111,   438,   458,   478,   498,   231,  -138,  -138,    85,
      86,   518,   313,    93,   225,   231,   231,   231,   231,   658,
    -138,  -138,   138,  -138,   231,  -138,   538,   558,   578,   598,
     101,   108,  -138,   231,   231,   231,   231,   151,   225,   618,
     334,   638,   355,   112,  -138,   231,  -138,   231,  -138,  -138,
    -138,   376,   397,  -138,  -138
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     3,     4,     5,
       6,     7,    71,    67,    69,     9,     0,     0,     0,     0,
       0,    47,    48,    37,    37,    49,     8,     0,     0,     0,
      40,    39,    35,    24,     0,     0,     0,     0,     0,    10,
       0,    42,    22,    23,     0,     0,     0,     0,    50,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,    50,    25,    26,    66,     0,     0,    56,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    68,    70,
       0,     0,     0,     0,    45,    72,    72,    46,     0,     0,
       0,     0,     0,     0,    57,    43,    31,     0,     0,    36,
       0,    41,    41,    58,    59,    60,    61,    62,    63,    64,
      65,    52,    53,    54,    55,     0,     0,     0,     0,    73,
       0,     0,     0,     0,    19,     0,     0,    44,     0,    38,
      27,    28,     0,     0,     0,     0,     0,    51,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      17,    18,     0,    33,     0,    41,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,    14,     0,    16,    34,
      30,     0,     0,    13,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   -49,  -138,  -137,
     141,   119,  -138,  -138,  -108,  -138,   -18,   -12,   152,  -138,
    -138,   165,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     8,    15,    18,    42,    43,    44,    45,   108,
      54,    73,    46,    47,   140,    69,    61,    49,     9,    16,
      17,    13,   130
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   153,    88,    89,   141,    10,     2,     3,    83,    84,
      85,    86,    85,    86,   146,   147,     4,    11,   146,   148,
     107,    62,    63,    64,   111,   112,    67,   171,    68,     5,
       6,    12,    19,    48,    48,    20,    51,    53,   -21,   -21,
      52,    94,    56,    57,    97,    58,    59,   100,   -21,    70,
       7,    48,    65,   102,    66,    48,    48,   172,   -21,   109,
     110,   -21,   -21,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,    71,   190,    72,    87,    98,
      95,    96,   -21,   129,   129,    21,    99,    60,    23,    94,
      25,   101,   103,   125,    90,    91,    92,    93,   132,   126,
     127,   128,   149,   133,   136,   165,    75,    76,    77,    78,
      79,    80,    81,   142,   143,   144,   145,    35,    83,    84,
      85,    86,    38,   151,   152,   138,   109,    40,   137,   184,
     150,   154,   160,   161,   159,    21,    48,    22,    23,    24,
      25,   164,   170,   166,   167,   168,   169,   177,    27,    28,
      29,    30,   109,    31,    32,   178,   183,    33,    34,   189,
      48,   179,   180,   181,   182,    55,    74,    35,    36,    37,
      50,    14,    38,   191,   131,   192,   105,    40,     0,     0,
       0,    41,   106,    21,     0,    22,    23,    24,    25,     0,
       0,    26,     0,     0,     0,     0,    27,    28,    29,    30,
       0,    31,    32,     5,     6,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,     0,
      38,     0,     0,     0,    39,    40,     0,     0,    21,    41,
      22,    23,    24,    25,    21,     0,    60,    23,     0,    25,
       0,    27,    28,    29,    30,     0,    31,    32,     0,     0,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    37,     0,     0,    38,    35,     0,     0,     0,
      40,    38,     0,     0,    41,     0,    40,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,    83,
      84,    85,    86,     0,     0,     0,     0,   104,    75,    76,
      77,    78,    79,    80,    81,    82,     0,     0,     0,     0,
      83,    84,    85,    86,     0,     0,     0,     0,   134,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
       0,    83,    84,    85,    86,     0,     0,     0,     0,   139,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,    83,    84,    85,    86,     0,     0,     0,     0,
     163,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,    83,    84,    85,    86,     0,     0,     0,
       0,   186,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,    83,    84,    85,    86,     0,     0,
       0,     0,   188,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,    83,    84,    85,    86,     0,
       0,     0,     0,   193,    75,    76,    77,    78,    79,    80,
      81,    82,     0,     0,     0,     0,    83,    84,    85,    86,
       0,     0,     0,     0,   194,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   135,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   155,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   156,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   157,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   158,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   162,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   173,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   174,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   175,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   176,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   185,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,     0,     0,     0,   187,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,    83,    84,    85,
      86,    75,    76,    77,    78,    79,    80,     0,     0,     0,
       0,     0,     0,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
      18,   138,    51,    52,   112,    44,     0,     1,    39,    40,
      41,    42,    41,    42,    46,    47,    10,     4,    46,    47,
      69,    33,    34,    35,    73,    74,    38,   164,    40,    23,
      24,     5,    45,    51,    52,    45,    47,    38,     0,     1,
      47,    53,    38,    45,    56,    45,    45,    59,    10,    44,
      44,    69,    45,    65,    45,    73,    74,   165,    20,    71,
      72,    23,    24,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    45,   184,    45,    44,     5,
      45,    45,    44,    95,    96,     3,     5,     5,     6,   101,
       8,    38,     9,    45,    12,    13,    14,    15,    46,    45,
      45,    45,     5,    46,    46,   154,    27,    28,    29,    30,
      31,    32,    33,   125,   126,   127,   128,    35,    39,    40,
      41,    42,    40,   135,   136,    48,   138,    45,    44,   178,
       5,    20,    47,    47,   146,     3,   154,     5,     6,     7,
       8,    48,     4,   155,   156,   157,   158,    46,    16,    17,
      18,    19,   164,    21,    22,    47,     5,    25,    26,    47,
     178,   173,   174,   175,   176,    24,    47,    35,    36,    37,
      18,     6,    40,   185,    96,   187,    44,    45,    -1,    -1,
      -1,    49,    50,     3,    -1,     5,     6,     7,     8,    -1,
      -1,    11,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    37,    -1,    -1,
      40,    -1,    -1,    -1,    44,    45,    -1,    -1,     3,    49,
       5,     6,     7,     8,     3,    -1,     5,     6,    -1,     8,
      -1,    16,    17,    18,    19,    -1,    21,    22,    -1,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    40,    35,    -1,    -1,    -1,
      45,    40,    -1,    -1,    49,    -1,    45,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    47,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    47,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      47,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    47,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    47,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    47,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    47,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    46,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,     0,     1,    10,    23,    24,    44,    53,    69,
      44,     4,     5,    72,    72,    54,    70,    71,    55,    45,
      45,     3,     5,     6,     7,     8,    11,    16,    17,    18,
      19,    21,    22,    25,    26,    35,    36,    37,    40,    44,
      45,    49,    56,    57,    58,    59,    63,    64,    67,    68,
      69,    47,    47,    38,    61,    61,    38,    45,    45,    45,
       5,    67,    68,    68,    68,    45,    45,    68,    68,    66,
      44,    45,    45,    62,    62,    27,    28,    29,    30,    31,
      32,    33,    34,    39,    40,    41,    42,    44,    58,    58,
      12,    13,    14,    15,    68,    45,    45,    68,     5,     5,
      68,    38,    68,     9,    47,    44,    50,    58,    60,    68,
      68,    58,    58,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    45,    45,    45,    45,    68,
      73,    73,    46,    46,    47,    46,    46,    44,    48,    47,
      65,    65,    68,    68,    68,    68,    46,    47,    47,     5,
       5,    68,    68,    60,    20,    46,    46,    46,    46,    68,
      47,    47,    46,    47,    48,    58,    68,    68,    68,    68,
       4,    60,    65,    46,    46,    46,    46,    46,    47,    68,
      68,    68,    68,     5,    58,    46,    47,    46,    47,    47,
      65,    68,    68,    47,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    52,    52,    52,    54,    53,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    70,    69,    71,
      69,    72,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     0,     5,     0,
       2,     3,     3,    12,    10,    12,    10,     6,     6,     4,
       1,     1,     1,     1,     1,     2,     2,     4,     4,     7,
      10,     3,     5,     6,    10,     1,     1,     0,     3,     1,
       1,     0,     0,     2,     3,     3,     3,     1,     1,     1,
       1,     5,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     0,     6,     0,
       6,     1,     0,     1,     3
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
#line 1505 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 66 "postscript.y"
                      {
          ps_begin_document((yyvsp[0].string));
          initcode();
      }
#line 1514 "y.tab.c"
    break;

  case 8: /* postscript: BEGIN_POST STRING $@1 post_content END_POST  */
#line 71 "postscript.y"
               {
          ps_end_document();
          printf("Documento PostScript generado: %s\n", (yyvsp[-3].string));
          free((yyvsp[-3].string));
      }
#line 1524 "y.tab.c"
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
#line 1536 "y.tab.c"
    break;

  case 13: /* fig_stmt: VAR '=' LINEA '(' expr ',' expr ',' expr ',' expr ')'  */
#line 92 "postscript.y"
                                                            {
          // line = linea(x1, y1, x2, y2)
          (yyval.inst) = (yyvsp[-7].inst);  /* Inicio del código */
          code(create_line_shape);
          code3(varpush, (Inst)(yyvsp[-11].sym), assign);
      }
#line 1547 "y.tab.c"
    break;

  case 14: /* fig_stmt: VAR '=' CIRCULO '(' expr ',' expr ',' expr ')'  */
#line 98 "postscript.y"
                                                     {
          // circ = circulo(x, y, r)
          (yyval.inst) = (yyvsp[-5].inst);
          code(create_circle_shape);
          code3(varpush, (Inst)(yyvsp[-9].sym), assign);
      }
#line 1558 "y.tab.c"
    break;

  case 15: /* fig_stmt: VAR '=' RECTANGULO '(' expr ',' expr ',' expr ',' expr ')'  */
#line 104 "postscript.y"
                                                                 {
          // rect = rectangulo(x, y, w, h)
          (yyval.inst) = (yyvsp[-7].inst);
          code(create_rect_shape);
          code3(varpush, (Inst)(yyvsp[-11].sym), assign);
      }
#line 1569 "y.tab.c"
    break;

  case 16: /* fig_stmt: VAR '=' COLOR '(' expr ',' expr ',' expr ')'  */
#line 110 "postscript.y"
                                                   {
          // rojo = color(r, g, b)
          (yyval.inst) = (yyvsp[-5].inst);
          code(create_color);
          code3(varpush, (Inst)(yyvsp[-9].sym), assign);
      }
#line 1580 "y.tab.c"
    break;

  case 17: /* dibujar_stmt: STROKE '(' VAR ',' VAR ')'  */
#line 119 "postscript.y"
                                 {
          // stroke(shape, color)
          (yyval.inst) = code3(varpush, (Inst)(yyvsp[-3].sym), eval);
          code3(varpush, (Inst)(yyvsp[-1].sym), eval); //COLOR
          code(ps_stroke);
      }
#line 1591 "y.tab.c"
    break;

  case 18: /* dibujar_stmt: FILL '(' VAR ',' VAR ')'  */
#line 125 "postscript.y"
                               {
          // fill(shape, color)
          (yyval.inst) = code3(varpush, (Inst)(yyvsp[-3].sym), eval);
          code3(varpush, (Inst)(yyvsp[-1].sym), eval);
          code(ps_fill);
      }
#line 1602 "y.tab.c"
    break;

  case 19: /* dibujar_stmt: SETLINEWIDTH '(' expr ')'  */
#line 131 "postscript.y"
                                {
          (yyval.inst) = (yyvsp[-1].inst);
          code(ps_setlinewidth);
      }
#line 1611 "y.tab.c"
    break;

  case 20: /* stmt: expr  */
#line 138 "postscript.y"
           { code(pop1); (yyval.inst) = (yyvsp[0].inst); }
#line 1617 "y.tab.c"
    break;

  case 24: /* stmt: RETURN  */
#line 142 "postscript.y"
             { defnonly("return"); code(procret); (yyval.inst)= progp; }
#line 1623 "y.tab.c"
    break;

  case 25: /* stmt: RETURN expr  */
#line 143 "postscript.y"
                  { defnonly("return"); (yyval.inst)=(yyvsp[0].inst); code(funcret); }
#line 1629 "y.tab.c"
    break;

  case 26: /* stmt: PRINT expr  */
#line 144 "postscript.y"
                 { (yyval.inst) = (yyvsp[0].inst); code(print); }
#line 1635 "y.tab.c"
    break;

  case 27: /* stmt: while cond stmt end  */
#line 145 "postscript.y"
                          {
          ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-3].inst))[2] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-3].inst);
      }
#line 1645 "y.tab.c"
    break;

  case 28: /* stmt: if cond stmt end  */
#line 150 "postscript.y"
                       {
          ((yyvsp[-3].inst))[1] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-3].inst))[3] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-3].inst);
      }
#line 1655 "y.tab.c"
    break;

  case 29: /* stmt: if cond stmt end ELSE stmt end  */
#line 155 "postscript.y"
                                     {
          ((yyvsp[-6].inst))[1] = (Inst)(yyvsp[-4].inst);
          ((yyvsp[-6].inst))[2] = (Inst)(yyvsp[-1].inst);
          ((yyvsp[-6].inst))[3] = (Inst)(yyvsp[0].inst);
          (yyval.inst) = (yyvsp[-6].inst);
      }
#line 1666 "y.tab.c"
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
#line 1679 "y.tab.c"
    break;

  case 31: /* stmt: '{' stmtlist '}'  */
#line 169 "postscript.y"
                       { (yyval.inst) = (yyvsp[-1].inst); }
#line 1685 "y.tab.c"
    break;

  case 32: /* stmt: PROCEDURE begin '(' arglist ')'  */
#line 170 "postscript.y"
                                      {
          (yyval.inst) = (yyvsp[-3].inst);
          code3(call, (Inst)(yyvsp[-4].sym), (Inst)(long)(yyvsp[-1].narg));
      }
#line 1694 "y.tab.c"
    break;

  case 33: /* stmt: FUENTE '(' FONT_ID ',' expr ')'  */
#line 174 "postscript.y"
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
#line 1713 "y.tab.c"
    break;

  case 34: /* stmt: TEXTO '(' expr ',' expr ',' STRING ',' VAR ')'  */
#line 188 "postscript.y"
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
#line 1743 "y.tab.c"
    break;

  case 35: /* for: FOR  */
#line 215 "postscript.y"
         { (yyval.inst) = code3(forcode, STOP, STOP); code3(STOP, STOP, STOP); }
#line 1749 "y.tab.c"
    break;

  case 36: /* forexpr: expr  */
#line 218 "postscript.y"
              { code(STOP); (yyval.inst) = (yyvsp[0].inst); }
#line 1755 "y.tab.c"
    break;

  case 37: /* begin: %empty  */
#line 221 "postscript.y"
       { (yyval.inst) = progp; }
#line 1761 "y.tab.c"
    break;

  case 38: /* cond: '(' expr ')'  */
#line 224 "postscript.y"
                   { code(STOP); (yyval.inst) = (yyvsp[-1].inst); }
#line 1767 "y.tab.c"
    break;

  case 39: /* while: WHILE  */
#line 227 "postscript.y"
             { (yyval.inst) = code3(whilecode, STOP, STOP); }
#line 1773 "y.tab.c"
    break;

  case 40: /* if: IF  */
#line 230 "postscript.y"
       { (yyval.inst) = code(ifcode); code3(STOP, STOP, STOP); }
#line 1779 "y.tab.c"
    break;

  case 41: /* end: %empty  */
#line 233 "postscript.y"
                  { code(STOP); (yyval.inst) = progp; }
#line 1785 "y.tab.c"
    break;

  case 42: /* stmtlist: %empty  */
#line 237 "postscript.y"
                   { (yyval.inst) = progp; }
#line 1791 "y.tab.c"
    break;

  case 44: /* stmtlist: stmtlist stmt '\n'  */
#line 239 "postscript.y"
                         { (yyval.inst) = (yyvsp[-2].inst); }
#line 1797 "y.tab.c"
    break;

  case 45: /* asgn: VAR '=' expr  */
#line 243 "postscript.y"
                   {
          code3(varpush, (Inst)(yyvsp[-2].sym), assign);
          (yyval.inst) = (yyvsp[0].inst);
      }
#line 1806 "y.tab.c"
    break;

  case 46: /* asgn: ARG '=' expr  */
#line 247 "postscript.y"
                   {
          defnonly("$");
          code2(argassign, (Inst)(long)(yyvsp[-2].narg));
          (yyval.inst) = (yyvsp[0].inst);
      }
#line 1816 "y.tab.c"
    break;

  case 47: /* expr: NUMBER  */
#line 255 "postscript.y"
             { 
          (yyval.inst) = code(constpush_n); 
          code_double((yyvsp[0].dval)); 
      }
#line 1825 "y.tab.c"
    break;

  case 48: /* expr: VAR  */
#line 259 "postscript.y"
          { 
          (yyval.inst) = code3(varpush, (Inst)(yyvsp[0].sym), eval); 
      }
#line 1833 "y.tab.c"
    break;

  case 49: /* expr: ARG  */
#line 262 "postscript.y"
          { 
          defnonly("$"); 
          (yyval.inst) = code2(arg, (Inst)(long)(yyvsp[0].narg)); 
      }
#line 1842 "y.tab.c"
    break;

  case 51: /* expr: FUNCTION begin '(' arglist ')'  */
#line 267 "postscript.y"
                                     {
          (yyval.inst) = (yyvsp[-3].inst);
          code3(call, (Inst)(yyvsp[-4].sym), (Inst)(long)(yyvsp[-1].narg));
      }
#line 1851 "y.tab.c"
    break;

  case 52: /* expr: expr '+' expr  */
#line 271 "postscript.y"
                    { code(add); (yyval.inst) = (yyvsp[-2].inst); }
#line 1857 "y.tab.c"
    break;

  case 53: /* expr: expr '-' expr  */
#line 272 "postscript.y"
                    { code(sub); (yyval.inst) = (yyvsp[-2].inst); }
#line 1863 "y.tab.c"
    break;

  case 54: /* expr: expr '*' expr  */
#line 273 "postscript.y"
                    { code(mul); (yyval.inst) = (yyvsp[-2].inst); }
#line 1869 "y.tab.c"
    break;

  case 55: /* expr: expr '/' expr  */
#line 274 "postscript.y"
                    { code(divide); (yyval.inst) = (yyvsp[-2].inst); }
#line 1875 "y.tab.c"
    break;

  case 56: /* expr: '-' expr  */
#line 275 "postscript.y"
                                { code(negate); (yyval.inst) = (yyvsp[0].inst); }
#line 1881 "y.tab.c"
    break;

  case 57: /* expr: '(' expr ')'  */
#line 276 "postscript.y"
                   { (yyval.inst) = (yyvsp[-1].inst); }
#line 1887 "y.tab.c"
    break;

  case 58: /* expr: expr GT expr  */
#line 277 "postscript.y"
                   { code(gt); (yyval.inst) = (yyvsp[-2].inst); }
#line 1893 "y.tab.c"
    break;

  case 59: /* expr: expr GE expr  */
#line 278 "postscript.y"
                   { code(ge); (yyval.inst) = (yyvsp[-2].inst); }
#line 1899 "y.tab.c"
    break;

  case 60: /* expr: expr LT expr  */
#line 279 "postscript.y"
                   { code(lt); (yyval.inst) = (yyvsp[-2].inst); }
#line 1905 "y.tab.c"
    break;

  case 61: /* expr: expr LE expr  */
#line 280 "postscript.y"
                   { code(le); (yyval.inst) = (yyvsp[-2].inst); }
#line 1911 "y.tab.c"
    break;

  case 62: /* expr: expr EQ expr  */
#line 281 "postscript.y"
                   { code(eq); (yyval.inst) = (yyvsp[-2].inst); }
#line 1917 "y.tab.c"
    break;

  case 63: /* expr: expr NE expr  */
#line 282 "postscript.y"
                   { code(ne); (yyval.inst) = (yyvsp[-2].inst); }
#line 1923 "y.tab.c"
    break;

  case 64: /* expr: expr AND expr  */
#line 283 "postscript.y"
                    { code(and_op); (yyval.inst) = (yyvsp[-2].inst); }
#line 1929 "y.tab.c"
    break;

  case 65: /* expr: expr OR expr  */
#line 284 "postscript.y"
                   { code(or_op); (yyval.inst) = (yyvsp[-2].inst); }
#line 1935 "y.tab.c"
    break;

  case 66: /* expr: NOT expr  */
#line 285 "postscript.y"
               { code(not_op); (yyval.inst) = (yyvsp[0].inst); }
#line 1941 "y.tab.c"
    break;

  case 67: /* $@2: %empty  */
#line 290 "postscript.y"
                    { (yyvsp[0].sym)->type = TYPE_FUNCTION; indef = 1; }
#line 1947 "y.tab.c"
    break;

  case 68: /* defn: FUNC procname $@2 '(' ')' stmt  */
#line 291 "postscript.y"
                   { 
          code(procret); 
          define((yyvsp[-4].sym)); 
          indef = 0; 
      }
#line 1957 "y.tab.c"
    break;

  case 69: /* $@3: %empty  */
#line 296 "postscript.y"
                    { (yyvsp[0].sym)->type = TYPE_PROCEDURE; indef = 1; }
#line 1963 "y.tab.c"
    break;

  case 70: /* defn: PROC procname $@3 '(' ')' stmt  */
#line 297 "postscript.y"
                   { 
          code(procret); 
          define((yyvsp[-4].sym)); 
          indef = 0; 
      }
#line 1973 "y.tab.c"
    break;

  case 72: /* arglist: %empty  */
#line 308 "postscript.y"
                   { (yyval.narg) = 0; }
#line 1979 "y.tab.c"
    break;

  case 73: /* arglist: expr  */
#line 309 "postscript.y"
           { (yyval.narg) = 1; }
#line 1985 "y.tab.c"
    break;

  case 74: /* arglist: arglist ',' expr  */
#line 310 "postscript.y"
                       { (yyval.narg) = (yyvsp[-2].narg) + 1; }
#line 1991 "y.tab.c"
    break;


#line 1995 "y.tab.c"

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

#line 313 "postscript.y"



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
