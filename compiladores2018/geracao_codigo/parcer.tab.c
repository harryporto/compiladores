/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parcer.y" /* yacc.c:339  */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
extern FILE *yyout;


int i=0,j=0,x,y,m=0,f=0;
void arvore(noAst *eixo);
noAst *constante(int valor_constante);
noAst *ident(char id[20]);
noAst *insertAst(int tok, int nunf, ...);
noAst *raiz;
//int yyerror(char *s){fprintf(yyout,"yyerror : %s\n",s);}
void yyerror(char *s){return ;}


#line 92 "parcer.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parcer.tab.h".  */
#ifndef YY_YY_PARCER_TAB_H_INCLUDED
# define YY_YY_PARCER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIS = 258,
    MENOS = 259,
    VEZES = 260,
    DIV = 261,
    ABRE_PAR = 262,
    FECHA_PAR = 263,
    MAIOR = 264,
    MAIOR_IGUAL = 265,
    MENOR = 266,
    MENOR_IGUAL = 267,
    IGUAL_IGUAL = 268,
    DIFERENTE = 269,
    ABRE_CHA = 270,
    FECHA_CHA = 271,
    ABRE_COL = 272,
    FECHA_COL = 273,
    VIRG = 274,
    PVIRG = 275,
    IGUAL = 276,
    ID = 277,
    NUM = 278,
    IF = 279,
    INT = 280,
    WHILE = 281,
    RETURN = 282,
    ELSE = 283,
    VOID = 284,
    P = 285,
    D = 286,
    LD = 287,
    C = 288,
    AR = 289,
    SL = 290,
    PAR = 291,
    PVIRGs = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 28 "parcer.y" /* yacc.c:355  */

  char valor[100];
  int inteiro;
  noAst *ast;

#line 176 "parcer.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARCER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 193 "parcer.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  104

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    81,    82,    84,    85,    87,    88,    90,
      91,    93,    94,    96,    97,    99,   100,   102,   104,   105,
     107,   108,   110,   111,   112,   113,   114,   116,   117,   119,
     120,   122,   124,   125,   127,   128,   130,   131,   134,   135,
     136,   137,   138,   139,   140,   143,   144,   145,   147,   148,
     149,   151,   152,   153,   154,   156,   158,   159,   161,   162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIS", "MENOS", "VEZES", "DIV",
  "ABRE_PAR", "FECHA_PAR", "MAIOR", "MAIOR_IGUAL", "MENOR", "MENOR_IGUAL",
  "IGUAL_IGUAL", "DIFERENTE", "ABRE_CHA", "FECHA_CHA", "ABRE_COL",
  "FECHA_COL", "VIRG", "PVIRG", "IGUAL", "ID", "NUM", "IF", "INT", "WHILE",
  "RETURN", "ELSE", "VOID", "P", "D", "LD", "C", "AR", "SL", "PAR",
  "PVIRGs", "$accept", "Program", "Decl_list", "Decl", "Var_decl",
  "Type_esp", "Params", "Param_list", "Param", "Comp", "Local_decl",
  "Stat_list", "Statement", "Expr_stmt", "Selection", "Iteration",
  "Return", "Expr", "Var", "SimExpr", "AddExpr", "Term", "Factor", "Call",
  "Args", "Arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -13

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      17,   -95,   -95,    13,    17,   -95,   -95,   -11,   -95,   -95,
      33,    18,    31,   -95,    51,    61,    78,    68,   -95,    70,
      72,    75,    17,    71,    74,   -95,   -95,   -95,   -95,   -95,
      17,   -95,    73,    -6,    24,    26,   -95,   -95,    -5,   -95,
      86,    87,     8,   -95,   -95,   -95,   -95,   -95,   -95,    76,
      77,   -95,    52,     0,   -95,   -95,    89,    26,    26,    26,
      26,   -95,   -95,   -95,    26,    26,    26,    26,    26,    26,
      26,    26,    26,    26,    26,   -95,   -95,    91,    80,    83,
      94,    95,   -95,   -95,     0,     0,    48,    48,    48,    48,
      48,    48,   -95,   -95,   -95,    26,   -95,    12,    12,   -95,
      79,   -95,    12,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     4,     5,     0,     1,     3,
       0,     0,     0,     7,    10,     0,     0,    11,    14,     0,
      15,     0,     0,     0,     0,    19,     6,    13,     8,    16,
      21,    18,     0,     0,     0,     0,    17,    28,    36,    54,
       0,     0,     0,    23,    20,    22,    24,    25,    26,     0,
      52,    35,    44,    47,    50,    53,     0,    57,     0,     0,
       0,    32,    33,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,    59,     0,    56,     0,
       0,     0,    34,    52,    45,    46,    40,    41,    39,    38,
      42,    43,    48,    49,    55,     0,    37,     0,     0,    58,
      29,    31,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -95,   -95,   -95,   100,    81,    15,   -95,   -95,    84,    88,
     -95,   -95,   -94,   -95,   -95,   -95,   -95,   -35,     2,   -95,
      10,    -8,    11,   -95,   -95,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    16,    17,    18,    43,
      30,    33,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    77,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      56,    35,    57,   100,   101,    73,    74,    62,   103,    25,
      36,    10,    58,     8,    37,    35,    38,    39,    40,    35,
      41,    42,    76,    79,    80,    81,    15,    25,    61,    82,
      38,    39,    37,    35,    38,    39,    40,    15,    41,    42,
      11,    12,     1,     1,    13,    32,     2,    14,    38,    39,
      12,    65,    66,    13,    19,    65,    66,    84,    85,   -12,
      99,    67,    68,    69,    70,    71,    72,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    86,    87,    88,
      89,    90,    91,    20,    92,    93,    21,    22,    23,    24,
      25,    28,    29,    59,    60,    34,    63,    75,    64,    94,
      95,    96,    97,    98,     9,     0,    27,   102,     0,    26,
       0,    31
};

static const yytype_int8 yycheck[] =
{
      35,     7,     7,    97,    98,     5,     6,    42,   102,    15,
      16,    22,    17,     0,    20,     7,    22,    23,    24,     7,
      26,    27,    57,    58,    59,    60,    11,    15,    20,    64,
      22,    23,    20,     7,    22,    23,    24,    22,    26,    27,
       7,    17,    25,    25,    20,    30,    29,    29,    22,    23,
      17,     3,     4,    20,    23,     3,     4,    65,    66,     8,
      95,     9,    10,    11,    12,    13,    14,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    67,    68,    69,
      70,    71,    72,    22,    73,    74,     8,    19,    18,    17,
      15,    20,    18,     7,     7,    22,    20,     8,    21,     8,
      20,    18,     8,     8,     4,    -1,    22,    28,    -1,    21,
      -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    29,    39,    40,    41,    42,    43,     0,    41,
      22,     7,    17,    20,    29,    43,    44,    45,    46,    23,
      22,     8,    19,    18,    17,    15,    47,    46,    20,    18,
      48,    42,    43,    49,    22,     7,    16,    20,    22,    23,
      24,    26,    27,    47,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    55,     7,    17,     7,
       7,    20,    55,    20,    21,     3,     4,     9,    10,    11,
      12,    13,    14,     5,     6,     8,    55,    62,    63,    55,
      55,    55,    55,    56,    59,    59,    58,    58,    58,    58,
      58,    58,    60,    60,     8,    20,    18,     8,     8,    55,
      50,    50,    28,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    57,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    61,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     6,     3,     6,     1,
       1,     1,     1,     3,     1,     2,     4,     4,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     5,     2,     2,     3,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     4,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 79 "parcer.y" /* yacc.c:1646  */
    {raiz = (yyval.ast);}
#line 1344 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(D,2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1350 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 82 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1356 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 84 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1362 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(ABRE_PAR,4,(yyvsp[-5].ast),ident((yyvsp[-4].valor)),(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1368 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 87 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(PVIRG,2,(yyvsp[-2].ast),ident((yyvsp[-1].valor)));}
#line 1374 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 88 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(ABRE_COL,3,(yyvsp[-5].ast),ident((yyvsp[-4].valor)),(yyvsp[-2].inteiro));}
#line 1380 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 90 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(INT,0);}
#line 1386 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 91 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(VOID,0);}
#line 1392 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 93 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1398 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 94 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(VOID,0);}
#line 1404 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 96 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(VIRG,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1410 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 97 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1416 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 99 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(P,2,(yyvsp[-1].ast),ident((yyvsp[0].valor)));}
#line 1422 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 100 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(PAR,2,(yyvsp[-3].ast),ident((yyvsp[-2].valor)));}
#line 1428 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 102 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(ABRE_CHA,2,(yyvsp[-2].ast),(yyvsp[-1].ast));}
#line 1434 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 104 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(LD,2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1440 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 105 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1446 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 107 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(SL,2,(yyvsp[-1].ast),(yyvsp[0].ast));}
#line 1452 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 108 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1458 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1464 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 111 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1470 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 112 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1476 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 113 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1482 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 114 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1488 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 1494 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1500 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(IF,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1506 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(ELSE,3,(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1512 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 122 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(WHILE,1,(yyvsp[-2].ast));}
#line 1518 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 124 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(RETURN,0);}
#line 1524 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 125 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(RETURN,1,(yyvsp[0].ast));}
#line 1530 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 127 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(IGUAL,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1536 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 128 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1542 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 130 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(ID,1,ident((yyvsp[0].valor)));}
#line 1548 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 131 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(ID,2,ident((yyvsp[-3].valor)),(yyvsp[-1].ast));}
#line 1554 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 134 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(MENOR_IGUAL,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1560 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 135 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(MENOR,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1566 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 136 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(MAIOR,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1572 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 137 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(MAIOR_IGUAL,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1578 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 138 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(IGUAL_IGUAL,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1584 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 139 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(DIFERENTE,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1590 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 140 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1596 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 143 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(MAIS,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1602 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 144 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(MENOS,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1608 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 145 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1614 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 147 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(VEZES,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1620 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 148 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(DIV,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1626 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 149 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1632 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 151 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 1638 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 152 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1644 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 153 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1650 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 154 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(NUM,1,constante((yyvsp[0].inteiro)));}
#line 1656 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 156 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(C,2,ident((yyvsp[-3].valor)),(yyvsp[-1].ast));}
#line 1662 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 158 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1668 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 159 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = NULL;}
#line 1674 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 161 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = insertAst(AR,2,(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1680 "parcer.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 162 "parcer.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1686 "parcer.tab.c" /* yacc.c:1646  */
    break;


#line 1690 "parcer.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 164 "parcer.y" /* yacc.c:1906  */


noAst *insertAst(int tok, int numf, ...) {
   va_list ap;
    noAst *an = malloc(sizeof(noAst));
    int i;
	
	an->astn.filhos = malloc(numf * sizeof(noAst *));
	va_start(ap, numf);
    
    an->tipoNodo = Ast;
    an->astn.tokenOpr = tok;
    an->astn.n_filhos = numf;
    //fprintf(yyout, "token  %c:\n",tok);

    i = 0;
    while (i < numf) {
		an->astn.filhos[i] = va_arg(ap, noAst*);
		i++;
    }
         
    va_end(ap);
    return an;
}

noAst *constante(int valor_constante) {
    noAst *an = malloc(sizeof(noAst));

    an->tipoNodo = Tok;
    fprintf(yyout, "token  %d:\n",valor_constante);
    an->token.val = valor_constante;

    return an;
}

noAst *ident(char value[50]) {
    noAst *an = malloc(sizeof(noAst));

     an->tipoNodo = Ident;
     strcpy(an->constant.val, value);

    return an;
}

void arvore (noAst *eixo){
char op[2];
fprintf(yyout,"X %i : %i \n",eixo->astn.tokenOpr,eixo->astn.n_filhos);  
if(eixo != NULL) {
    switch(eixo->astn.tokenOpr) {
	 fprintf(yyout," %d , ",eixo->astn.tokenOpr);
	case D:
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case ABRE_PAR:
            fprintf(yyout," [var-declaration1");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
            arvore(eixo->astn.filhos[2]);
            arvore(eixo->astn.filhos[3]);
          fprintf(yyout,"]");
        break;
	case PVIRG:
            fprintf(yyout," [var-declaration2");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
	case ABRE_COL:
            fprintf(yyout," [var-declaration3");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
            arvore(eixo->astn.filhos[2]);
          fprintf(yyout,"]");
        break;
	case VIRG:
            fprintf(yyout," funcao:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break; 
	case P:
            fprintf(yyout," [parametros: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
	case PAR:
            fprintf(yyout," [parametros2: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
	case ABRE_CHA:
            fprintf(yyout," funcao:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case LD:
            fprintf(yyout," declaracao local:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case SL:
            fprintf(yyout," lista:");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case IF:
            fprintf(yyout," If: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
        break;
	case ELSE:
            fprintf(yyout," else: ");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
            arvore(eixo->astn.filhos[2]);
        break;
	case WHILE:
            fprintf(yyout," while: ");
            arvore(eixo->astn.filhos[0]);
        break; 
	case RETURN:
            fprintf(yyout," return: ");
	    if(eixo->astn.filhos[0]){
            	arvore(eixo->astn.filhos[0]);
	    }
        break;	        
	case IGUAL:
            fprintf(yyout," [=");
            arvore(eixo->astn.filhos[0]);
            arvore(eixo->astn.filhos[1]);
          fprintf(yyout,"]");
        break;
        case MAIS:
          fprintf(yyout," [+");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MENOS:
          fprintf(yyout," [-");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case VEZES:
          fprintf(yyout," [*");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case DIV:
          fprintf(yyout," [/");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MAIOR:
          fprintf(yyout," [>");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MENOR:
          fprintf(yyout," [<");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MAIOR_IGUAL:
          fprintf(yyout," [>=");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case MENOR_IGUAL:
          fprintf(yyout," [<=");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case IGUAL_IGUAL:
          fprintf(yyout," [==");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
	case DIFERENTE:
          fprintf(yyout," [!=");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
  	  fprintf(yyout,"]");
        break;
        case ID:
          fprintf(yyout," [%d]", eixo->astn.filhos[0]->token.val);
        break;
 	case NUM:
          fprintf(yyout,"li $a0, %d /n", eixo->astn.filhos[0]->token.val);
        break;
	case C:
          fprintf(yyout," chamada:");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
        break;
	case AR:
          fprintf(yyout," argumentos:");
          arvore(eixo->astn.filhos[0]);
  	  arvore(eixo->astn.filhos[1]);
        break;
    	}
   }
}
int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");
	fprintf(yyout,"[program");
	do{
		yyparse();
	}while(!feof(yyin));
	arvore(raiz);
	fprintf(yyout,"]");
	fclose(yyin);
	fclose(yyout);
	return 0;
}


