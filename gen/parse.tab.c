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
#line 1 "source/parse.y"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdbool.h>

// symbol table
#include "../include/symtab/symtab.h"

// for logging
#include <time.h>


/* ------ Function declaration ------ */
int yylex(void);
void yyerror(char*);
extern FILE* yyin;


/* ------ Auxiliar function declaration ------ */
void print_iden(char*, atributs);
void print_expr(atributs);
int check_types_assig(atributs, atributs);
int check_types(atributs, atributs);
int check_types_intfl(atributs, atributs);


/* ------ Auxiliar variables ------ */
FILE* fp; // pointer to the log file created each execution
int line = 1; // run-time line counter
atributs aux;
char* name;
bool err; // error flag


//TODO: check if logs can get types and operations 

#line 108 "gen/parse.tab.c"

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

#include "parse.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INT = 3,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 4,                    /* T_FLOAT  */
  YYSYMBOL_T_STRING = 5,                   /* T_STRING  */
  YYSYMBOL_T_IDEN = 6,                     /* T_IDEN  */
  YYSYMBOL_T_BOOL = 7,                     /* T_BOOL  */
  YYSYMBOL_ASSIG = 8,                      /* ASSIG  */
  YYSYMBOL_SYM_OB = 9,                     /* SYM_OB  */
  YYSYMBOL_SYM_CB = 10,                    /* SYM_CB  */
  YYSYMBOL_OP_ADD = 11,                    /* OP_ADD  */
  YYSYMBOL_OP_SUB = 12,                    /* OP_SUB  */
  YYSYMBOL_OP_MUL = 13,                    /* OP_MUL  */
  YYSYMBOL_OP_DIV = 14,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 15,                    /* OP_MOD  */
  YYSYMBOL_OP_POW = 16,                    /* OP_POW  */
  YYSYMBOL_OP_LT = 17,                     /* OP_LT  */
  YYSYMBOL_OP_LE = 18,                     /* OP_LE  */
  YYSYMBOL_OP_GT = 19,                     /* OP_GT  */
  YYSYMBOL_OP_GE = 20,                     /* OP_GE  */
  YYSYMBOL_OP_EQ = 21,                     /* OP_EQ  */
  YYSYMBOL_OP_INEQ = 22,                   /* OP_INEQ  */
  YYSYMBOL_BOOL_OP_NOT = 23,               /* BOOL_OP_NOT  */
  YYSYMBOL_BOOL_OP_AND = 24,               /* BOOL_OP_AND  */
  YYSYMBOL_BOOL_OP_OR = 25,                /* BOOL_OP_OR  */
  YYSYMBOL_CONST_PI = 26,                  /* CONST_PI  */
  YYSYMBOL_EOL = 27,                       /* EOL  */
  YYSYMBOL_CMD_EXIT = 28,                  /* CMD_EXIT  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_start = 30,                     /* start  */
  YYSYMBOL_line = 31,                      /* line  */
  YYSYMBOL_statement = 32,                 /* statement  */
  YYSYMBOL_expr = 33,                      /* expr  */
  YYSYMBOL_bool_and = 34,                  /* bool_and  */
  YYSYMBOL_bool_not = 35,                  /* bool_not  */
  YYSYMBOL_relexpr = 36,                   /* relexpr  */
  YYSYMBOL_arith = 37,                     /* arith  */
  YYSYMBOL_term = 38,                      /* term  */
  YYSYMBOL_unary = 39,                     /* unary  */
  YYSYMBOL_pow = 40,                       /* pow  */
  YYSYMBOL_factor = 41,                    /* factor  */
  YYSYMBOL_assignment = 42                 /* assignment  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   68

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  61

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    67,    70,    71,    72,    75,    76,    79,
      80,    97,    98,   115,   129,   132,   133,   163,   194,   225,
     256,   287,   320,   321,   385,   419,   420,   452,   495,   529,
     547,   550,   588,   593,   603,   604,   605,   606,   607,   612
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
  "\"end of file\"", "error", "\"invalid token\"", "T_INT", "T_FLOAT",
  "T_STRING", "T_IDEN", "T_BOOL", "ASSIG", "SYM_OB", "SYM_CB", "OP_ADD",
  "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_POW", "OP_LT", "OP_LE",
  "OP_GT", "OP_GE", "OP_EQ", "OP_INEQ", "BOOL_OP_NOT", "BOOL_OP_AND",
  "BOOL_OP_OR", "CONST_PI", "EOL", "CMD_EXIT", "$accept", "start", "line",
  "statement", "expr", "bool_and", "bool_not", "relexpr", "arith", "term",
  "unary", "pow", "factor", "assignment", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -38,     1,   -38,   -38,   -38,   -38,     3,   -38,    13,    34,
      34,   -38,   -38,   -38,   -18,   -10,    -3,   -38,    37,    33,
      53,   -38,   -38,     7,   -38,    13,   -38,     2,   -38,    37,
     -38,    13,    13,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    44,   -10,   -38,    -3,   -38,    33,
      33,    33,    33,    33,    33,    53,    53,   -38,   -38,   -38,
     -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,    34,    35,    36,    33,    37,     0,     0,
       0,     4,     6,     3,     0,     7,     9,    11,    14,    15,
      22,    25,    30,    32,     8,     0,    33,     0,    29,    13,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    38,    10,    12,    18,
      19,    16,    17,    20,    21,    23,    24,    26,    27,    28,
      31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -38,     6,    -5,    -2,    25,    27,   -37,
      -9,     8,   -38,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,     2,    55,    56,     3,     4,     5,     6,     7,    30,
       8,    25,    46,     9,    27,    31,     3,     4,     5,    26,
       7,    32,     8,    44,    10,     9,    47,    31,    11,    12,
      48,    45,    57,    58,    59,    29,    10,     3,     4,     5,
      26,     7,     0,     8,    39,    40,     9,     3,     4,     5,
      26,     7,    60,     8,    33,    34,    35,    36,    37,    38,
      49,    50,    51,    52,    53,    54,    41,    42,    43
};

static const yytype_int8 yycheck[] =
{
       9,     0,    39,    40,     3,     4,     5,     6,     7,    27,
       9,     8,    10,    12,     8,    25,     3,     4,     5,     6,
       7,    24,     9,    16,    23,    12,    31,    25,    27,    28,
      32,    25,    41,    42,    43,    10,    23,     3,     4,     5,
       6,     7,    -1,     9,    11,    12,    12,     3,     4,     5,
       6,     7,    44,     9,    17,    18,    19,    20,    21,    22,
      33,    34,    35,    36,    37,    38,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,     0,     3,     4,     5,     6,     7,     9,    12,
      23,    27,    28,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     8,     6,    33,    39,    36,
      27,    25,    24,    17,    18,    19,    20,    21,    22,    11,
      12,    13,    14,    15,    16,    33,    10,    34,    35,    37,
      37,    37,    37,    37,    37,    38,    38,    39,    39,    39,
      40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    31,    32,    32,    33,
      33,    34,    34,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    37,    37,    37,    38,    38,    38,    38,    39,
      39,    40,    40,    41,    41,    41,    41,    41,    41,    42
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       3,     1,     3,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3
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
  case 4: /* line: EOL  */
#line 70 "source/parse.y"
                                        { line++; err = false; }
#line 1172 "gen/parse.tab.c"
    break;

  case 5: /* line: statement EOL  */
#line 71 "source/parse.y"
                                        { line++; err = false; }
#line 1178 "gen/parse.tab.c"
    break;

  case 6: /* line: CMD_EXIT  */
#line 72 "source/parse.y"
                                        { exit(0); }
#line 1184 "gen/parse.tab.c"
    break;

  case 7: /* statement: expr  */
#line 75 "source/parse.y"
                                        { if(!err) print_expr((yyvsp[0].attrs)); }
#line 1190 "gen/parse.tab.c"
    break;

  case 8: /* statement: assignment  */
#line 76 "source/parse.y"
                                        { if(!err) print_iden(name, (yyvsp[0].attrs)); }
#line 1196 "gen/parse.tab.c"
    break;

  case 9: /* expr: bool_and  */
#line 79 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1202 "gen/parse.tab.c"
    break;

  case 10: /* expr: expr BOOL_OP_OR bool_and  */
#line 80 "source/parse.y"
                                        {	if(!err){ 
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if((res == 2) && ((yyvsp[-2].attrs).type == (yyvsp[0].attrs).type)){
								(yyval.attrs).boolean = (yyvsp[-2].attrs).boolean || (yyvsp[0].attrs).boolean ? true : false;
								(yyval.attrs).type = 3;
								fprintf(fp, "%s reduced by the rule: expr -> expr(%s) || bool_and(%s)\n", 
									(yyval.attrs).boolean ? "true" : "false", (yyvsp[-2].attrs).boolean ? "true" : "false",
									(yyvsp[0].attrs).boolean ? "true" : "false");
							}
							else{
								yyerror("semantic error: cannot compute logical and on non-boolean values");
								err = true;
							}
						}
    					}
#line 1222 "gen/parse.tab.c"
    break;

  case 11: /* bool_and: bool_not  */
#line 97 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1228 "gen/parse.tab.c"
    break;

  case 12: /* bool_and: bool_and BOOL_OP_AND bool_not  */
#line 98 "source/parse.y"
                                        { 	if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if((res == 2) && ((yyvsp[-2].attrs).type == (yyvsp[0].attrs).type)){
								(yyval.attrs).boolean = (yyvsp[-2].attrs).boolean && (yyvsp[0].attrs).boolean ? true : false;
								(yyval.attrs).type = 3;
								fprintf(fp, "%s reduced by the rule: bool_and -> bool_and(%s) && bool_not(%s)\n", 
									(yyval.attrs).boolean ? "true" : "false", (yyvsp[-2].attrs).boolean ? "true" : "false",
									(yyvsp[0].attrs).boolean ? "true" : "false");
						}
							else{
								yyerror("semantic error: cannot compute logical and on non-boolean values");
								err = true;
							}
						}
 					}
#line 1248 "gen/parse.tab.c"
    break;

  case 13: /* bool_not: BOOL_OP_NOT relexpr  */
#line 115 "source/parse.y"
                                        { 	if(!err){
							if((yyvsp[0].attrs).type == 3){
								fprintf(fp, "BOOL_OP_NOT relexpr\n");
								(yyval.attrs).boolean = (yyvsp[0].attrs).boolean ? false : true;
								(yyval.attrs).type = 3;
								fprintf(fp, "%s reduced by the rule: bool_not -> ! relexpr(%s)\n", 
									(yyval.attrs).boolean ? "true" : "false", (yyvsp[0].attrs).boolean ? "true" : "false");
							}
							else{
								yyerror("semantic error: cannot compute logical not on non-boolean values");
								err = true;
							}
						}
					}
#line 1267 "gen/parse.tab.c"
    break;

  case 14: /* bool_not: relexpr  */
#line 129 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1273 "gen/parse.tab.c"
    break;

  case 15: /* relexpr: arith  */
#line 132 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1279 "gen/parse.tab.c"
    break;

  case 16: /* relexpr: relexpr OP_GT arith  */
#line 133 "source/parse.y"
                                        {	if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								res = check_types_intfl((yyvsp[-2].attrs), (yyvsp[0].attrs));
								switch(res){
									case 0: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer > (yyvsp[0].attrs).integer ? true : false;
										break;
									case 1: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer > (yyvsp[0].attrs).floating ? true : false;
										break;
									case 2: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating > (yyvsp[0].attrs).integer ? true : false;
										break;
									case 3: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating > (yyvsp[0].attrs).floating ? true : false;
										break;
								}
								(yyval.attrs).type = 3;
								fprintf(fp, "relexpr OP_GT arith\n");
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compare a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compare a boolean value");
								}
								err = true;
							}
						}
					}
#line 1314 "gen/parse.tab.c"
    break;

  case 17: /* relexpr: relexpr OP_GE arith  */
#line 163 "source/parse.y"
                                        {
						if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "relexpr OP_GE arith\n");
								res = check_types_intfl((yyvsp[-2].attrs), (yyvsp[0].attrs));
								switch(res){
									case 0: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer >= (yyvsp[0].attrs).integer ? true : false;
										break;
									case 1: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer >= (yyvsp[0].attrs).floating ? true : false;
										break;
									case 2: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating >= (yyvsp[0].attrs).integer ? true : false;
										break;
									case 3: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating >= (yyvsp[0].attrs).floating ? true : false;
										break;
								}
								(yyval.attrs).type = 3;
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compare a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compare a boolean value");
								}
								err = true;
							}
						}
					}
#line 1350 "gen/parse.tab.c"
    break;

  case 18: /* relexpr: relexpr OP_LT arith  */
#line 194 "source/parse.y"
                                        {
						if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "relexpr OP_LT arith\n");
								res = check_types_intfl((yyvsp[-2].attrs), (yyvsp[0].attrs));
								switch(res){
									case 0: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer < (yyvsp[0].attrs).integer ? true : false;
										break;
									case 1: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer < (yyvsp[0].attrs).floating ? true : false;
										break;
									case 2: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating < (yyvsp[0].attrs).integer ? true : false;
										break;
									case 3: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating < (yyvsp[0].attrs).floating ? true : false;
										break;
								}
								(yyval.attrs).type = 3;
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compare a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compare a boolean value");
								}
								err = true;
							}
						}
					}
#line 1386 "gen/parse.tab.c"
    break;

  case 19: /* relexpr: relexpr OP_LE arith  */
#line 225 "source/parse.y"
                                        {
						if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "relexpr OP_LE arith\n");
								res = check_types_intfl((yyvsp[-2].attrs), (yyvsp[0].attrs));
								switch(res){
									case 0: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer <= (yyvsp[0].attrs).integer ? true : false;
										break;
									case 1: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer <= (yyvsp[0].attrs).floating ? true : false;
										break;
									case 2: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating <= (yyvsp[0].attrs).integer ? true : false;
										break;
									case 3: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating <= (yyvsp[0].attrs).floating	? true : false;
										break;
								}
								(yyval.attrs).type = 3;
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compare a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compare a boolean value");
								}
								err = true;
							}
						}
					}
#line 1422 "gen/parse.tab.c"
    break;

  case 20: /* relexpr: relexpr OP_EQ arith  */
#line 256 "source/parse.y"
                                        {
						if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "relexpr OP_EQ arith\n");
								res = check_types_intfl((yyvsp[-2].attrs), (yyvsp[0].attrs));
								switch(res){
									case 0: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer == (yyvsp[0].attrs).integer ? true : false;
										break;
									case 1: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer == (yyvsp[0].attrs).floating ? true : false;
										break;
									case 2: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating == (yyvsp[0].attrs).integer ? true : false;
										break;
									case 3: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating == (yyvsp[0].attrs).floating ? true : false;
										break;
								}
								(yyval.attrs).type = 3;
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compare a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compare a boolean value");
								}
								err = true;
							}
						}
					}
#line 1458 "gen/parse.tab.c"
    break;

  case 21: /* relexpr: relexpr OP_INEQ arith  */
#line 287 "source/parse.y"
                                        { 	if(!err){
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "relexpr OP_INEQ arith\n");
								res = check_types_intfl((yyvsp[-2].attrs), (yyvsp[0].attrs));
								switch(res){
									case 0: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer != (yyvsp[0].attrs).integer ? true : false;
										break;
									case 1: (yyval.attrs).boolean = (yyvsp[-2].attrs).integer != (yyvsp[0].attrs).floating ? true : false;
										break;
									case 2: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating != (yyvsp[0].attrs).integer ? true : false;
										break;
									case 3: (yyval.attrs).boolean = (yyvsp[-2].attrs).floating != (yyvsp[0].attrs).floating ? true : false;
										break;
								}
								(yyval.attrs).type = 3;
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compare a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compare a boolean value");
								}
								err = true;
							}
						}
					}
#line 1493 "gen/parse.tab.c"
    break;

  case 22: /* arith: term  */
#line 320 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1499 "gen/parse.tab.c"
    break;

  case 23: /* arith: arith OP_ADD term  */
#line 321 "source/parse.y"
                                        { 	if(!err){
							fprintf(fp, "arith OP_ADD term\n"); 
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								if((yyvsp[-2].attrs).type == 0){
									if((yyvsp[0].attrs).type == 0){
										(yyval.attrs).integer = (yyvsp[-2].attrs).integer + (yyvsp[0].attrs).integer;
										(yyval.attrs).type = 0;
									}
									else{
										(yyval.attrs).floating = (yyvsp[-2].attrs).integer + (yyvsp[0].attrs).floating;
										(yyval.attrs).type = 1;
									}
								}
								else{
									(yyval.attrs).floating = ((yyvsp[0].attrs).type == 0) ? (yyvsp[-2].attrs).floating + (yyvsp[0].attrs).integer : (yyvsp[-2].attrs).floating + (yyvsp[0].attrs).floating;
									(yyval.attrs).type = 1;
								}
							}
							else{
								// concatenation
								if(res == 1){
									char* temp = strdup((yyvsp[-2].attrs).string);
									char* aux = strdup((yyvsp[0].attrs).string);

									if(((yyvsp[-2].attrs).type == 2) != ((yyvsp[0].attrs).type == 2)){
										if((yyvsp[-2].attrs).type == 2){
											switch((yyvsp[0].attrs).type){
												case 0: asprintf(&aux, "%d", (yyvsp[0].attrs).integer);
													break;
												case 1: asprintf(&aux, "%lf", (yyvsp[0].attrs).floating);
													break;
												case 3: asprintf(&aux, "%s", (yyvsp[-2].attrs).boolean ? "true" : "false");
													//aux = $3.boolean ? "true" : "false";
													break;
											}
										}
										else{
											switch((yyvsp[-2].attrs).type){
												case 0: asprintf(&temp, "%d", (yyvsp[-2].attrs).integer);
													break;
												case 1: asprintf(&temp, "%lf", (yyvsp[-2].attrs).floating);
													break;
												case 3: asprintf(&temp, "%s", (yyvsp[-2].attrs).boolean ? "true" : "false");
													//temp = $1.boolean ? "true" : "false";
													break;
											}
										}
									}
									strcat(temp, aux);
									(yyval.attrs).string = strdup(temp);
									(yyval.attrs).type = 2;	
									
									// free all memory allocated
									free(temp);
									free(aux);
								}
								else{
									yyerror("semantic error: cannot compute addition of boolean values");
									err = true;
								}
							}
						}
					}
#line 1568 "gen/parse.tab.c"
    break;

  case 24: /* arith: arith OP_SUB term  */
#line 385 "source/parse.y"
                                        {	if(!err){
							// check types and make appropiate conversion if needed	
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "num_expr OP_SUB term\n");
								if((yyvsp[-2].attrs).type == 0){
									(yyval.attrs).type = 1;
									if((yyvsp[0].attrs).type == 0){
										(yyval.attrs).integer = (yyvsp[-2].attrs).integer - (yyvsp[0].attrs).integer;
										(yyval.attrs).type = 0;
									}
									else{
										(yyval.attrs).floating = (yyvsp[-2].attrs).integer - (yyvsp[0].attrs).floating;
									}
								}
								else{
									(yyval.attrs).floating = ((yyvsp[0].attrs).type == 0) ? (yyvsp[-2].attrs).floating - (yyvsp[0].attrs).integer : (yyvsp[-2].attrs).floating - (yyvsp[0].attrs).floating;
								}
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compute the subtraction of a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compute the subtraction of a boolean value");
								}
								err = true;
							}
						}
					}
#line 1605 "gen/parse.tab.c"
    break;

  case 25: /* term: unary  */
#line 419 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1611 "gen/parse.tab.c"
    break;

  case 26: /* term: term OP_MUL unary  */
#line 420 "source/parse.y"
                                        { 	if(!err){
							// check types and make appropiate conversion if needed
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "term OP_MUL unary\n");
								(yyval.attrs).type = 1;
								if((yyvsp[-2].attrs).type == 0){
									if((yyvsp[0].attrs).type == 0){
										(yyval.attrs).integer = (yyvsp[-2].attrs).integer * (yyvsp[0].attrs).integer;
										(yyval.attrs).type = 0;
									}
									else{
										(yyval.attrs).floating = (yyvsp[-2].attrs).integer * (yyvsp[0].attrs).floating;
									}
								}
								else{
									(yyval.attrs).floating = ((yyvsp[0].attrs).type == 0) ? (yyvsp[-2].attrs).floating * (yyvsp[0].attrs).integer : (yyvsp[-2].attrs).floating * (yyvsp[0].attrs).floating;
								}
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compute the division of a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compute the division of a boolean value");
								}
								err = true;
							}
						}
					}
#line 1648 "gen/parse.tab.c"
    break;

  case 27: /* term: term OP_DIV unary  */
#line 452 "source/parse.y"
                                        { 	if(!err){
							// check types and make appropiate conversion if needed
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "term OP_DIV unary\n");
								// control division by 0
								if((yyvsp[0].attrs).type == 0){
									if((yyvsp[0].attrs).integer == 0){
										yyerror("semantic error: cannot divide by 0"); 
										err = true;
									}
								}
								else{
									if((yyvsp[0].attrs).floating == 0.0f){
										yyerror("semantic error: cannot divide by 0.0"); 
										err = true;
									}
								}

								if(!err){
									if((yyvsp[-2].attrs).type == 0){
										(yyval.attrs).floating = ((yyvsp[0].attrs).type == 0) ? (yyvsp[-2].attrs).integer / (yyvsp[0].attrs).integer : (yyvsp[-2].attrs).integer / (yyvsp[0].attrs).floating;
									}
									else{
										(yyval.attrs).floating = ((yyvsp[0].attrs).type == 0) ? (yyvsp[-2].attrs).floating / (yyvsp[0].attrs).integer : (yyvsp[-2].attrs).floating / (yyvsp[0].attrs).floating;
									}
									(yyval.attrs).type = 1;
								}
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compute the division of a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compute the division of a boolean value");
								}
								err = true;
							}
						}

					}
#line 1696 "gen/parse.tab.c"
    break;

  case 28: /* term: term OP_MOD unary  */
#line 495 "source/parse.y"
                                        { 	if(!err){
							// check types and make appropiate conversion if needed
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "term OP_MOD unary\n");
								(yyval.attrs).type = 1;
								if((yyvsp[-2].attrs).type == 0){
									if((yyvsp[0].attrs).type == 0){
										(yyval.attrs).integer = (yyvsp[-2].attrs).integer % (yyvsp[0].attrs).integer;
										(yyval.attrs).type = 0;
									}
									else{
										(yyval.attrs).floating = fmod((yyvsp[-2].attrs).integer,(yyvsp[0].attrs).floating);
									}
								}
								else{
									(yyval.attrs).floating = ((yyvsp[0].attrs).type == 0) ? fmod((yyvsp[-2].attrs).floating, (yyvsp[0].attrs).integer) : fmod((yyvsp[-2].attrs).floating, (yyvsp[0].attrs).floating);
								}
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compute the division of a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compute the division of a boolean value");
								}
								err = true;
							}
						}	
					}
#line 1733 "gen/parse.tab.c"
    break;

  case 29: /* unary: OP_SUB unary  */
#line 529 "source/parse.y"
                                        { 	if(!err){
							if(((yyvsp[0].attrs).type == 0) || ((yyvsp[0].attrs).type == 1)){
								fprintf(fp, "OP_SUB unary\n");
								if((yyvsp[0].attrs).type == 0){
									(yyval.attrs).integer = -(yyvsp[0].attrs).integer;
									(yyval.attrs).type = 0;
								}
								else{
									(yyval.attrs).floating = -(yyvsp[0].attrs).floating;
									(yyval.attrs).type = 1;
								}
							}
							else{
								yyerror("semantic error: cannot negate non-numeric values");
								err = true;
							}
						}
					}
#line 1756 "gen/parse.tab.c"
    break;

  case 30: /* unary: pow  */
#line 547 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1762 "gen/parse.tab.c"
    break;

  case 31: /* pow: factor OP_POW pow  */
#line 550 "source/parse.y"
                                        { 	if(!err){
							// check types and make appropiate conversion if needed
							int res = check_types((yyvsp[-2].attrs), (yyvsp[0].attrs));
							if(res == 0){
								fprintf(fp, "factor OP_POW pow\n");
								if((yyvsp[-2].attrs).type == 0){
									if((yyvsp[0].attrs).type == 0){
										(yyval.attrs).integer = pow((yyvsp[-2].attrs).integer, (yyvsp[0].attrs).integer);
										(yyval.attrs).type = 0;
									}
									else{
										(yyval.attrs).floating = pow((yyvsp[-2].attrs).integer, (yyvsp[0].attrs).floating);
										(yyval.attrs).type = 1;
									}
								}
								else{
									if((yyvsp[0].attrs).type == 0){
										(yyval.attrs).floating = pow((yyvsp[-2].attrs).floating, (yyvsp[0].attrs).integer);
									}
									else{
										(yyval.attrs).floating = pow((yyvsp[-2].attrs).floating, (yyvsp[0].attrs).floating);
									}
									(yyval.attrs).type = 1;
								}
							}
							else{
								// string arguments are not valid
								if(res == 1){
									yyerror("semantic error: cannot compute the power of a string argument");
								}
								// boolean arguments are not valid either
								else{
									yyerror("semantic error: cannot compute the power of a boolean value");
								}
								err = true;
							}
						}
					}
#line 1805 "gen/parse.tab.c"
    break;

  case 32: /* pow: factor  */
#line 588 "source/parse.y"
                                        { (yyval.attrs) = (yyvsp[0].attrs); }
#line 1811 "gen/parse.tab.c"
    break;

  case 33: /* factor: T_IDEN  */
#line 593 "source/parse.y"
                                        {	int found = sym_lookup((yyvsp[0].attrs).string, &aux);
      						if(found == 0){
							name = (yyvsp[0].attrs).string;
							(yyval.attrs) = aux;
						}
						else{
							yyerror("syntax error: undeclared identifier");
							err = true;
						}
					}
#line 1826 "gen/parse.tab.c"
    break;

  case 34: /* factor: T_INT  */
#line 603 "source/parse.y"
                                        { fprintf(fp, "T_INT "); (yyval.attrs) = (yyvsp[0].attrs); (yyval.attrs).type = 0; }
#line 1832 "gen/parse.tab.c"
    break;

  case 35: /* factor: T_FLOAT  */
#line 604 "source/parse.y"
                                        { fprintf(fp, "T_FLOAT "); (yyval.attrs) = (yyvsp[0].attrs); (yyval.attrs).type = 1; }
#line 1838 "gen/parse.tab.c"
    break;

  case 36: /* factor: T_STRING  */
#line 605 "source/parse.y"
                                        { fprintf(fp, "T_STRING "); (yyval.attrs) = (yyvsp[0].attrs); (yyval.attrs).type = 2; }
#line 1844 "gen/parse.tab.c"
    break;

  case 37: /* factor: T_BOOL  */
#line 606 "source/parse.y"
                                        { fprintf(fp, "T_BOOL "); (yyval.attrs) = (yyvsp[0].attrs); (yyval.attrs).type = 3; }
#line 1850 "gen/parse.tab.c"
    break;

  case 38: /* factor: SYM_OB expr SYM_CB  */
#line 607 "source/parse.y"
                                        { fprintf(fp, "(expr) "); (yyval.attrs) = (yyvsp[-1].attrs); /*TODO: check this pls*/}
#line 1856 "gen/parse.tab.c"
    break;

  case 39: /* assignment: T_IDEN ASSIG expr  */
#line 612 "source/parse.y"
                                        { 	if(!err){ // check if there were any errors in the calculations of the expr to be assigned
							int found = sym_lookup((yyvsp[-2].attrs).string, &aux); // 1. search identifier
							name = (yyvsp[-2].attrs).string;
						
							// 2. if exists, check types
							if(found == 0){
								// 2a. if types are compatible then change var value
								if(check_types_assig(aux, (yyvsp[0].attrs)) == 1){
									aux = (yyvsp[0].attrs);
									sym_enter(name, &aux);
								}
								// 2b. if types aren't compatible then there's a semantic error
								else{
									yyerror("semantic error: identifier and expression type missmatch"); 
									err = true;
								}
							}
							else{
								// 3. if identifier doesn't exist then we have to create a new entry
								if(found == 2){
									aux = (yyvsp[0].attrs);
									sym_add(name, &aux);
								}
							}

							// 4. if the assignment succeeded log grammar production
							if(!err) {
								fprintf(fp, "reducido por T_IDEN ASSIG expr\n"); // TODO: change log message to something more meaningful
								(yyval.attrs) = (yyvsp[0].attrs);
							}
						}
					}
#line 1893 "gen/parse.tab.c"
    break;


#line 1897 "gen/parse.tab.c"

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

#line 646 "source/parse.y"


void yyerror(char *str)
{
  fprintf(stderr, "Compiler error:%d: %s.\n", line, str);
}

int main(int argc, char **argv)
{ 
  // get current date and time 
  time_t t = time(NULL); 
  struct tm tm = *localtime(&t);

  // set log file name
  char* path;
  if(0 > asprintf(&path, "log/%d-%02d-%02d_%02d:%02d:%02d.log",
        tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour,
        tm.tm_min, tm.tm_sec)) {
		fprintf(stderr, "Couldn't create log file...");
		return 1;
  }
  
  // create log file
  fp = fopen(path, "w");
  free(path);

  yyparse();

  fclose(fp);
  return 0;
}


/*---------------------------------------------*/
/*------------- Auxiliar functions ------------*/
/*---------------------------------------------*/

// could potentially add formatting from float to integer or reverse
int check_types_assig(atributs a, atributs b){ //TODO: if no more usages of function, delete it, just one line of code...
  // could do something along the lines of 
  // 0 for not compatible types
  // 1 for equal types
  // 2 for compatible types i.e float and integer and reverse
  return a.type == b.type;
}


int check_types(atributs a, atributs b){
  if((a.type == 2) || (b.type == 2)){
	return 1;
  }
  else{
  	if((a.type == 3) || (b.type == 3)){
		return 2;
  	}
	else return 0;
  }
}

// return 0: both integers
// return 1: $1 integer, $3 float
// return 2: $1 float, $3 integer
// return 3: both float
int check_types_intfl(atributs a, atributs b){
  if((a.type == 0) && (b.type == 0)){
  	return 0;
  }
  else{
  	if((a.type == 1) && (b.type == 1)){
		return 3;
	}
	else{
		if(a.type == 0){
			return 1;
		}
		else{
			return 2;
		}
	}
  }
}

void print_iden(char* name, atributs assig){
  switch(assig.type){
	case 0: printf("Assignment name: %s\ttype: int\tvalue: %d\n", name, assig.integer); 
		break;
	case 1: printf("Assignment name: %s\ttype: float\tvalue: %lf\n", name, assig.floating); 
		break;
	case 2: printf("Assignment name: %s\ttype: string\tvalue: '%s'\n", name, assig.string); 
		break;
	case 3: printf("Assignment name: %s\ttype: boolean\tvalue: %s\n", name, assig.boolean ? "true" : "false"); 
		break;
  }
}

void print_expr(atributs expr){ 
  switch(expr.type){
	case 0: printf("Expression of type: int\tvalue: %d\n", expr.integer); 
		break;
	case 1: printf("Expression of type: float\tvalue: %lf\n", expr.floating); 
		break;
	case 2: printf("Expression of type: string\tvalue: '%s'\n", expr.string); 
		break;
	case 3: printf("Expression of type: boolean\tvalue: %s\n", expr.boolean ? "true" : "false"); 
		break;
  }
}
