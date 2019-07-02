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
#line 1 "parser.y" /* yacc.c:339  */

#include "k.h"
#include "yystype.h"

#include "diagnosis.h"
#include "scanner.h"
#include "symboltable.h"

extern kc::module root;

#line 77 "parser.cc" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    KEY_ARRAY = 258,
    KEY_BEGIN = 259,
    KEY_CHAR = 260,
    KEY_CONST = 261,
    KEY_DO = 262,
    KEY_ELSE = 263,
    KEY_ELSIF = 264,
    KEY_END = 265,
    KEY_FOR = 266,
    KEY_IF = 267,
    KEY_INTEGER = 268,
    KEY_MODULE = 269,
    KEY_OF = 270,
    KEY_PROCEDURE = 271,
    KEY_REAL = 272,
    KEY_REPEAT = 273,
    KEY_RETURN = 274,
    KEY_THEN = 275,
    KEY_TO = 276,
    KEY_TYPE = 277,
    KEY_UNTIL = 278,
    KEY_VAR = 279,
    KEY_WHILE = 280,
    ASSIGN = 281,
    OR = 282,
    AND = 283,
    EQ = 284,
    NE = 285,
    LE = 286,
    GE = 287,
    LEQ = 288,
    GEQ = 289,
    PLUS = 290,
    MINUS = 291,
    ASTERISK = 292,
    SLASH = 293,
    DIV = 294,
    MOD = 295,
    NOT = 296,
    SEMICOLON = 297,
    PERIOD = 298,
    COLON = 299,
    COMMA = 300,
    LPAREN = 301,
    RPAREN = 302,
    LBRACK = 303,
    RBRACK = 304,
    RANGE = 305,
    C_STRING = 306,
    C_CHAR = 307,
    IDENT = 308,
    C_INTEGER = 309,
    C_REAL = 310
  };
#endif

/* Value type.  */

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 193 "parser.cc" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    90,    92,    89,    97,   103,   104,   110,
     111,   116,   118,   120,   122,   128,   129,   135,   136,   142,
     143,   149,   148,   155,   154,   161,   160,   167,   169,   166,
     174,   180,   181,   186,   188,   193,   193,   198,   198,   200,
     205,   207,   209,   211,   213,   218,   223,   225,   227,   229,
     231,   233,   235,   237,   242,   244,   250,   254,   259,   259,
     265,   266,   271,   273,   278,   283,   289,   290,   296,   297,
     302,   307,   312,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   338,   340,   342,   344,   346,   348,   350,
     352,   354,   359,   361,   363,   365
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEY_ARRAY", "KEY_BEGIN", "KEY_CHAR",
  "KEY_CONST", "KEY_DO", "KEY_ELSE", "KEY_ELSIF", "KEY_END", "KEY_FOR",
  "KEY_IF", "KEY_INTEGER", "KEY_MODULE", "KEY_OF", "KEY_PROCEDURE",
  "KEY_REAL", "KEY_REPEAT", "KEY_RETURN", "KEY_THEN", "KEY_TO", "KEY_TYPE",
  "KEY_UNTIL", "KEY_VAR", "KEY_WHILE", "ASSIGN", "OR", "AND", "EQ", "NE",
  "LE", "GE", "LEQ", "GEQ", "PLUS", "MINUS", "ASTERISK", "SLASH", "DIV",
  "MOD", "NOT", "SEMICOLON", "PERIOD", "COLON", "COMMA", "LPAREN",
  "RPAREN", "LBRACK", "RBRACK", "RANGE", "C_STRING", "C_CHAR", "IDENT",
  "C_INTEGER", "C_REAL", "$accept", "module", "$@1", "$@2", "$@3", "block",
  "declaration_list", "opt_begin_and_statement", "declaration",
  "constant_declaration_list", "type_declaration_list",
  "variable_declaration_list", "constant_declaration", "$@4",
  "type_declaration", "$@5", "variable_declaration", "$@6",
  "procedure_declaration", "$@7", "$@8", "parameters",
  "opt_parameter_list", "parameter_list", "parameter", "$@9",
  "variable_designator", "$@10", "type_denoter", "subrange", "statement",
  "statement_sequence", "empty_statement", "assignment_statement",
  "function_call", "$@11", "opt_expression_list", "expression_list",
  "return_statement", "if_statement", "ELSIF_list", "opt_ELSE",
  "while_statement", "repeat_statement", "for_statement", "expression",
  "constant_literal", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -59

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -12,   -55,    10,   -44,   -55,   -55,   -25,    16,   -41,   -38,
     -32,   -29,   -28,    19,    16,   -55,    -1,   -55,   -41,   -55,
       5,   -55,   -32,    -9,   -55,   -29,   -55,     8,    27,   -55,
     -10,   -55,     0,     1,   -55,     1,   -55,     6,     7,   -10,
       8,   -10,   -10,    17,   -19,    11,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -10,   -10,   -55,   -55,
     -55,   -55,     4,   -55,   329,   -55,    40,    29,    26,   -55,
     -55,   -55,   -55,    34,    37,   -55,   -55,   -18,   241,    57,
     345,   143,   -55,    35,   -10,   -10,     8,   -55,   255,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -55,    30,    38,   -55,    42,     1,   -10,
      67,   -55,   -55,   -10,     8,   -10,     8,   -10,   345,   195,
     -55,   -55,   357,   357,   122,   122,    32,    32,    32,    32,
      18,    18,   -55,   -55,   -55,   -55,   -55,    44,   -55,    40,
      49,   171,     1,   -55,   -55,   296,    77,   345,    85,    50,
     -55,   310,   -55,     1,   -55,    16,   -10,   -55,   -10,   -10,
      88,   -55,   -55,   -10,   -55,    60,   218,   157,   276,     8,
     104,   -55,   -55,    73,   -55,     8,     8,   -55,   -55,   -55,
     106,    77,   -55,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     0,     7,    15,     0,
      17,    19,     0,     9,     7,    14,     0,    11,    15,    27,
       0,    12,    17,     0,    13,    19,     4,    56,     0,     8,
       0,    16,     0,     0,    18,     0,    20,     0,     0,     0,
      56,     0,     0,    37,     0,    54,    10,    46,    47,    48,
      49,    50,    51,    52,    53,     6,     0,     0,    95,    94,
      92,    93,    75,    76,     0,    77,    31,     0,     0,    43,
      41,    42,    40,     0,     0,     5,    37,     0,     0,     0,
      64,     0,    38,     0,     0,     0,    56,    74,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,    32,    33,     0,     0,
       0,    23,    25,     0,    56,     0,    56,    60,    57,     0,
      55,    73,    86,    91,    78,    79,    80,    81,    82,    83,
      84,    85,    87,    88,    89,    90,    22,     0,    30,     0,
       0,     0,     0,    24,    26,     0,    66,    71,     0,     0,
      61,    62,    39,     0,    34,     7,     0,    44,     0,     0,
      68,    70,    59,     0,    35,     0,     0,     0,     0,    56,
       0,    63,    36,     0,    45,    56,    56,    69,    65,    28,
       0,    66,    29,    72,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   -55,   -55,   -55,   -36,   103,   -55,   -55,   102,
      99,   100,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -13,   -55,   -55,   -27,   -55,   -30,   -55,
     -55,   -39,   -55,   -55,   -24,   -55,   -55,   -35,   -55,   -55,
     -54,   -55,   -55,   -55,   -55,     9,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    37,    12,    13,    28,    14,    17,
      21,    24,    18,   136,    22,   143,    25,   144,    15,    32,
     182,    67,   105,   106,   107,   172,    62,    82,    73,   110,
      45,    46,    47,    48,    63,    83,   149,   150,    50,    51,
     160,   170,    52,    53,    54,   151,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    79,     1,    49,    68,    74,    69,    84,   113,     5,
       4,    77,    16,    44,    70,    19,    49,     7,    71,    38,
      39,    20,     8,    27,    23,    26,    40,    41,    30,    85,
      85,    56,     9,    42,    33,    35,    57,    55,    10,    64,
      11,    58,    59,    43,    60,    61,    66,   120,    78,    75,
      80,    81,    85,    86,    72,    99,   100,   101,   102,    44,
      76,    43,    49,   -58,   104,    87,    88,    97,    98,    99,
     100,   101,   102,   108,   109,   146,   111,   148,   140,   112,
     115,   117,   142,   137,   139,   138,   159,    44,   153,    44,
      49,   155,    49,   118,   119,   161,   169,   162,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   157,   173,   178,   179,   183,    29,   141,   165,
      31,    34,   145,   164,   147,    36,   154,   184,   171,     0,
     177,     0,     0,     0,     0,     0,   180,   181,     0,     0,
       0,     0,    44,     0,     0,    49,     0,     0,    44,    44,
     116,    49,    49,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   175,   166,     0,   167,   168,     0,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   156,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,   152,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   114,     0,     0,     0,     0,     0,   174,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   176,     0,     0,     0,
       0,     0,   121,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   158,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,     0,   163,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   103,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

static const yytype_int16 yycheck[] =
{
      27,    40,    14,    27,     3,    35,     5,    26,    26,    53,
       0,    38,    53,    40,    13,    53,    40,    42,    17,    11,
      12,    53,     6,     4,    53,    53,    18,    19,    29,    48,
      48,    41,    16,    25,    29,    44,    46,    10,    22,    30,
      24,    51,    52,    53,    54,    55,    46,    86,    39,    43,
      41,    42,    48,    42,    53,    37,    38,    39,    40,    86,
      53,    53,    86,    46,    24,    56,    57,    35,    36,    37,
      38,    39,    40,    44,    48,   114,    42,   116,   108,    42,
      23,    46,    15,    53,    42,    47,     9,   114,    44,   116,
     114,    42,   116,    84,    85,    10,     8,    47,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   142,    53,    10,    42,    10,    14,   109,   155,
      18,    22,   113,   153,   115,    25,   139,   181,   163,    -1,
     169,    -1,    -1,    -1,    -1,    -1,   175,   176,    -1,    -1,
      -1,    -1,   169,    -1,    -1,   169,    -1,    -1,   175,   176,
       7,   175,   176,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,     7,   156,    -1,   158,   159,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    49,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    20,    -1,    -1,    -1,
      -1,    -1,    47,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    21,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    42,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    57,    58,     0,    53,    59,    42,     6,    16,
      22,    24,    61,    62,    64,    74,    53,    65,    68,    53,
      53,    66,    70,    53,    67,    72,    53,     4,    63,    62,
      29,    65,    75,    29,    66,    44,    67,    60,    11,    12,
      18,    19,    25,    53,    82,    86,    87,    88,    89,    90,
      94,    95,    98,    99,   100,    10,    41,    46,    51,    52,
      54,    55,    82,    90,   101,   102,    46,    77,     3,     5,
      13,    17,    53,    84,    84,    43,    53,    82,   101,    87,
     101,   101,    83,    91,    26,    48,    42,   101,   101,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    42,    24,    78,    79,    80,    44,    48,
      85,    42,    42,    26,    20,    23,     7,    46,   101,   101,
      87,    47,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,    69,    53,    47,    42,
      84,   101,    15,    71,    73,   101,    87,   101,    87,    92,
      93,   101,    49,    44,    79,    42,    50,    84,    21,     9,
      96,    10,    47,    45,    84,    61,   101,   101,   101,     8,
      97,    93,    81,    53,    49,     7,    20,    87,    10,    42,
      87,    87,    76,    10,    96
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    58,    59,    60,    57,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    69,    68,    71,    70,    73,    72,    75,    76,    74,
      77,    78,    78,    79,    79,    81,    80,    83,    82,    82,
      84,    84,    84,    84,    84,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    89,    91,    90,
      92,    92,    93,    93,    94,    95,    96,    96,    97,    97,
      98,    99,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,     9,     3,     0,     2,     0,
       2,     2,     2,     2,     1,     0,     2,     0,     2,     0,
       2,     0,     5,     0,     5,     0,     5,     0,     0,    11,
       3,     0,     1,     1,     3,     0,     5,     0,     2,     4,
       1,     1,     1,     1,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     3,     0,     5,
       0,     1,     1,     3,     2,     7,     0,     5,     0,     2,
       5,     4,     9,     3,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "parser.y" /* yacc.c:1661  */
    { SymbolTable::pushScope(); }
#line 1550 "parser.cc" /* yacc.c:1661  */
    break;

  case 3:
#line 90 "parser.y" /* yacc.c:1661  */
    { SymbolTable::define((yyvsp[0].yt_casestring)->name, MODULE, (yylsp[0])); }
#line 1556 "parser.cc" /* yacc.c:1661  */
    break;

  case 4:
#line 92 "parser.y" /* yacc.c:1661  */
    { SymbolTable::use((yyvsp[0].yt_casestring)->name, (yylsp[0])); SymbolTable::popScope(); }
#line 1562 "parser.cc" /* yacc.c:1661  */
    break;

  case 5:
#line 93 "parser.y" /* yacc.c:1661  */
    { root = (yyval.yt_module) = kc::Module((yyvsp[-6].yt_casestring), (yyvsp[-3].yt_block)); }
#line 1568 "parser.cc" /* yacc.c:1661  */
    break;

  case 6:
#line 98 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_block) = kc::Block((yyvsp[-2].yt_declaration_list), (yyvsp[-1].yt_statement_sequence)); }
#line 1574 "parser.cc" /* yacc.c:1661  */
    break;

  case 7:
#line 103 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_declaration_list) = kc::Nildeclaration_list(); }
#line 1580 "parser.cc" /* yacc.c:1661  */
    break;

  case 8:
#line 105 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_declaration_list) = kc::Consdeclaration_list((yyvsp[-1].yt_declaration), (yyvsp[0].yt_declaration_list)); }
#line 1586 "parser.cc" /* yacc.c:1661  */
    break;

  case 9:
#line 110 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement_sequence) = kc::Nilstatement_sequence(); }
#line 1592 "parser.cc" /* yacc.c:1661  */
    break;

  case 10:
#line 112 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement_sequence) = (yyvsp[0].yt_statement_sequence); }
#line 1598 "parser.cc" /* yacc.c:1661  */
    break;

  case 11:
#line 117 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_declaration) = kc::ConstantDeclarationList((yyvsp[0].yt_constant_declaration_list)); }
#line 1604 "parser.cc" /* yacc.c:1661  */
    break;

  case 12:
#line 119 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_declaration) = kc::TypeDeclarationList((yyvsp[0].yt_type_declaration_list)); }
#line 1610 "parser.cc" /* yacc.c:1661  */
    break;

  case 13:
#line 121 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_declaration) = kc::VariableDeclarationList((yyvsp[0].yt_variable_declaration_list)); }
#line 1616 "parser.cc" /* yacc.c:1661  */
    break;

  case 14:
#line 123 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_declaration) = kc::ProcedureDeclaration((yyvsp[0].yt_procedure_declaration)); }
#line 1622 "parser.cc" /* yacc.c:1661  */
    break;

  case 15:
#line 128 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_declaration_list) = kc::Nilconstant_declaration_list(); }
#line 1628 "parser.cc" /* yacc.c:1661  */
    break;

  case 16:
#line 130 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_declaration_list) = kc::Consconstant_declaration_list((yyvsp[-1].yt_constant_declaration), (yyvsp[0].yt_constant_declaration_list)); }
#line 1634 "parser.cc" /* yacc.c:1661  */
    break;

  case 17:
#line 135 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_declaration_list) = kc::Niltype_declaration_list(); }
#line 1640 "parser.cc" /* yacc.c:1661  */
    break;

  case 18:
#line 137 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_declaration_list) = kc::Constype_declaration_list((yyvsp[-1].yt_type_declaration), (yyvsp[0].yt_type_declaration_list)); }
#line 1646 "parser.cc" /* yacc.c:1661  */
    break;

  case 19:
#line 142 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_variable_declaration_list) = kc::Nilvariable_declaration_list(); }
#line 1652 "parser.cc" /* yacc.c:1661  */
    break;

  case 20:
#line 144 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_variable_declaration_list) = kc::Consvariable_declaration_list((yyvsp[-1].yt_variable_declaration), (yyvsp[0].yt_variable_declaration_list)); }
#line 1658 "parser.cc" /* yacc.c:1661  */
    break;

  case 21:
#line 149 "parser.y" /* yacc.c:1661  */
    { SymbolTable::define((yyvsp[-3].yt_casestring)->name, CONSTANT, (yylsp[-3])); }
#line 1664 "parser.cc" /* yacc.c:1661  */
    break;

  case 22:
#line 150 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_declaration) = kc::ConstantDeclaration((yyvsp[-4].yt_casestring), (yyvsp[-2].yt_expression)); }
#line 1670 "parser.cc" /* yacc.c:1661  */
    break;

  case 23:
#line 155 "parser.y" /* yacc.c:1661  */
    { SymbolTable::define((yyvsp[-3].yt_casestring)->name, TYPE, (yylsp[-3])); }
#line 1676 "parser.cc" /* yacc.c:1661  */
    break;

  case 24:
#line 156 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_declaration) = kc::TypeDeclaration((yyvsp[-4].yt_casestring), (yyvsp[-2].yt_type_denoter)); }
#line 1682 "parser.cc" /* yacc.c:1661  */
    break;

  case 25:
#line 161 "parser.y" /* yacc.c:1661  */
    { SymbolTable::define((yyvsp[-3].yt_casestring)->name, VARIABLE, (yylsp[-3])); }
#line 1688 "parser.cc" /* yacc.c:1661  */
    break;

  case 26:
#line 162 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_variable_declaration) = kc::VariableDeclaration((yyvsp[-4].yt_casestring), (yyvsp[-2].yt_type_denoter)); }
#line 1694 "parser.cc" /* yacc.c:1661  */
    break;

  case 27:
#line 167 "parser.y" /* yacc.c:1661  */
    { SymbolTable::define((yyvsp[0].yt_casestring)->name, PROCEDURE, (yylsp[0])); SymbolTable::pushScope(); }
#line 1700 "parser.cc" /* yacc.c:1661  */
    break;

  case 28:
#line 169 "parser.y" /* yacc.c:1661  */
    { SymbolTable::popScope(); SymbolTable::use((yyvsp[-1].yt_casestring)->name, (yylsp[-1])); }
#line 1706 "parser.cc" /* yacc.c:1661  */
    break;

  case 29:
#line 170 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_procedure_declaration) = Procedure((yyvsp[-9].yt_casestring), (yyvsp[-7].yt_parameter_list), (yyvsp[-5].yt_type_denoter), (yyvsp[-3].yt_block)); }
#line 1712 "parser.cc" /* yacc.c:1661  */
    break;

  case 30:
#line 175 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_parameter_list) = (yyvsp[-1].yt_parameter_list); }
#line 1718 "parser.cc" /* yacc.c:1661  */
    break;

  case 31:
#line 180 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_parameter_list) = kc::Nilparameter_list(); }
#line 1724 "parser.cc" /* yacc.c:1661  */
    break;

  case 32:
#line 182 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_parameter_list) = (yyvsp[0].yt_parameter_list); }
#line 1730 "parser.cc" /* yacc.c:1661  */
    break;

  case 33:
#line 187 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_parameter_list) = kc::Consparameter_list((yyvsp[0].yt_parameter), kc::Nilparameter_list()); }
#line 1736 "parser.cc" /* yacc.c:1661  */
    break;

  case 34:
#line 189 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_parameter_list) = kc::Consparameter_list((yyvsp[-2].yt_parameter), (yyvsp[0].yt_parameter_list)); }
#line 1742 "parser.cc" /* yacc.c:1661  */
    break;

  case 35:
#line 193 "parser.y" /* yacc.c:1661  */
    { SymbolTable::define((yyvsp[-2].yt_casestring)->name, VARIABLE, (yylsp[-2])); }
#line 1748 "parser.cc" /* yacc.c:1661  */
    break;

  case 36:
#line 194 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_parameter) = kc::Parameter((yyvsp[-3].yt_casestring), (yyvsp[-1].yt_type_denoter)); }
#line 1754 "parser.cc" /* yacc.c:1661  */
    break;

  case 37:
#line 198 "parser.y" /* yacc.c:1661  */
    { SymbolTable::use((yyvsp[0].yt_casestring)->name, (yylsp[0])); }
#line 1760 "parser.cc" /* yacc.c:1661  */
    break;

  case 38:
#line 199 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_variable_designator) = kc::VariableDesignator((yyvsp[-1].yt_casestring)); }
#line 1766 "parser.cc" /* yacc.c:1661  */
    break;

  case 39:
#line 201 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_variable_designator) = kc::IndexedVariableDesignator((yyvsp[-3].yt_variable_designator), (yyvsp[-1].yt_expression)); }
#line 1772 "parser.cc" /* yacc.c:1661  */
    break;

  case 40:
#line 206 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_denoter) = kc::TypeIdent((yyvsp[0].yt_casestring)); }
#line 1778 "parser.cc" /* yacc.c:1661  */
    break;

  case 41:
#line 208 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_denoter) = kc::TypeInteger(); }
#line 1784 "parser.cc" /* yacc.c:1661  */
    break;

  case 42:
#line 210 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_denoter) = kc::TypeReal(); }
#line 1790 "parser.cc" /* yacc.c:1661  */
    break;

  case 43:
#line 212 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_denoter) = kc::TypeChar(); }
#line 1796 "parser.cc" /* yacc.c:1661  */
    break;

  case 44:
#line 214 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_type_denoter) = kc::TypeArray((yyvsp[-2].yt_subrange), (yyvsp[0].yt_type_denoter)); }
#line 1802 "parser.cc" /* yacc.c:1661  */
    break;

  case 45:
#line 219 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_subrange) = kc::Subrange((yyvsp[-3].yt_expression), (yyvsp[-1].yt_expression)); }
#line 1808 "parser.cc" /* yacc.c:1661  */
    break;

  case 46:
#line 224 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::EmptyStatement((yyvsp[0].yt_empty_statement)); }
#line 1814 "parser.cc" /* yacc.c:1661  */
    break;

  case 47:
#line 226 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::AssignmentStatement((yyvsp[0].yt_assignment_statement)); }
#line 1820 "parser.cc" /* yacc.c:1661  */
    break;

  case 48:
#line 228 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::FunctionCallStatement((yyvsp[0].yt_function_call)); }
#line 1826 "parser.cc" /* yacc.c:1661  */
    break;

  case 49:
#line 230 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::ReturnStatement((yyvsp[0].yt_return_statement)); }
#line 1832 "parser.cc" /* yacc.c:1661  */
    break;

  case 50:
#line 232 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::IfStatement((yyvsp[0].yt_if_statement)); }
#line 1838 "parser.cc" /* yacc.c:1661  */
    break;

  case 51:
#line 234 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::WhileStatement((yyvsp[0].yt_while_statement)); }
#line 1844 "parser.cc" /* yacc.c:1661  */
    break;

  case 52:
#line 236 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::RepeatStatement((yyvsp[0].yt_repeat_statement)); }
#line 1850 "parser.cc" /* yacc.c:1661  */
    break;

  case 53:
#line 238 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement) = kc::ForStatement((yyvsp[0].yt_for_statement)); }
#line 1856 "parser.cc" /* yacc.c:1661  */
    break;

  case 54:
#line 243 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement_sequence) = kc::Consstatement_sequence((yyvsp[0].yt_statement), kc::Nilstatement_sequence()); }
#line 1862 "parser.cc" /* yacc.c:1661  */
    break;

  case 55:
#line 245 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_statement_sequence) = kc::Consstatement_sequence((yyvsp[-2].yt_statement), (yyvsp[0].yt_statement_sequence)); }
#line 1868 "parser.cc" /* yacc.c:1661  */
    break;

  case 56:
#line 250 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_empty_statement) = kc::Empty(); }
#line 1874 "parser.cc" /* yacc.c:1661  */
    break;

  case 57:
#line 255 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_assignment_statement) = kc::Assignment((yyvsp[-2].yt_variable_designator), (yyvsp[0].yt_expression)); }
#line 1880 "parser.cc" /* yacc.c:1661  */
    break;

  case 58:
#line 259 "parser.y" /* yacc.c:1661  */
    { SymbolTable::use((yyvsp[0].yt_casestring)->name, (yylsp[0])); }
#line 1886 "parser.cc" /* yacc.c:1661  */
    break;

  case 59:
#line 260 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_function_call) = kc::FunctionCall((yyvsp[-4].yt_casestring), (yyvsp[-1].yt_expression_list)); }
#line 1892 "parser.cc" /* yacc.c:1661  */
    break;

  case 60:
#line 265 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression_list) = kc::Nilexpression_list(); }
#line 1898 "parser.cc" /* yacc.c:1661  */
    break;

  case 61:
#line 267 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression_list) = (yyvsp[0].yt_expression_list); }
#line 1904 "parser.cc" /* yacc.c:1661  */
    break;

  case 62:
#line 272 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression_list) = kc::Consexpression_list((yyvsp[0].yt_expression), kc::Nilexpression_list()); }
#line 1910 "parser.cc" /* yacc.c:1661  */
    break;

  case 63:
#line 274 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression_list) = kc::Consexpression_list((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression_list)); }
#line 1916 "parser.cc" /* yacc.c:1661  */
    break;

  case 64:
#line 279 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_return_statement) = kc::Return((yyvsp[0].yt_expression)); }
#line 1922 "parser.cc" /* yacc.c:1661  */
    break;

  case 65:
#line 284 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_if_statement) = kc::If((yyvsp[-5].yt_expression), (yyvsp[-3].yt_statement_sequence), (yyvsp[-2].yt_elsif_list), (yyvsp[-1].yt_opt_else)); }
#line 1928 "parser.cc" /* yacc.c:1661  */
    break;

  case 66:
#line 289 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_elsif_list) = kc::Nilelsif_list(); }
#line 1934 "parser.cc" /* yacc.c:1661  */
    break;

  case 67:
#line 291 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_elsif_list) = kc::Conselsif_list(kc::Elsif((yyvsp[-3].yt_expression), (yyvsp[-1].yt_statement_sequence)), (yyvsp[0].yt_elsif_list)); }
#line 1940 "parser.cc" /* yacc.c:1661  */
    break;

  case 68:
#line 296 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_opt_else) = kc::NoElse(); }
#line 1946 "parser.cc" /* yacc.c:1661  */
    break;

  case 69:
#line 298 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_opt_else) = kc::Else((yyvsp[0].yt_statement_sequence)); }
#line 1952 "parser.cc" /* yacc.c:1661  */
    break;

  case 70:
#line 303 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_while_statement) = kc::While((yyvsp[-3].yt_expression), (yyvsp[-1].yt_statement_sequence)); }
#line 1958 "parser.cc" /* yacc.c:1661  */
    break;

  case 71:
#line 308 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_repeat_statement) = kc::Repeat((yyvsp[-2].yt_statement_sequence), (yyvsp[0].yt_expression)); }
#line 1964 "parser.cc" /* yacc.c:1661  */
    break;

  case 72:
#line 314 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_for_statement) = For((yyvsp[-7].yt_variable_designator), (yyvsp[-5].yt_expression), (yyvsp[-3].yt_expression), (yyvsp[-1].yt_statement_sequence)); }
#line 1970 "parser.cc" /* yacc.c:1661  */
    break;

  case 73:
#line 319 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = (yyvsp[-1].yt_expression); }
#line 1976 "parser.cc" /* yacc.c:1661  */
    break;

  case 74:
#line 321 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Not((yyvsp[0].yt_expression)); }
#line 1982 "parser.cc" /* yacc.c:1661  */
    break;

  case 75:
#line 323 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::ExVariableDesignator((yyvsp[0].yt_variable_designator)); }
#line 1988 "parser.cc" /* yacc.c:1661  */
    break;

  case 76:
#line 325 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::ExFunctionCall((yyvsp[0].yt_function_call)); }
#line 1994 "parser.cc" /* yacc.c:1661  */
    break;

  case 77:
#line 327 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::ConstantLiteral((yyvsp[0].yt_constant_literal)); }
#line 2000 "parser.cc" /* yacc.c:1661  */
    break;

  case 78:
#line 329 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Eq((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2006 "parser.cc" /* yacc.c:1661  */
    break;

  case 79:
#line 331 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Ne((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2012 "parser.cc" /* yacc.c:1661  */
    break;

  case 80:
#line 333 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Le((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2018 "parser.cc" /* yacc.c:1661  */
    break;

  case 81:
#line 335 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Ge((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2024 "parser.cc" /* yacc.c:1661  */
    break;

  case 82:
#line 337 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Leq((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2030 "parser.cc" /* yacc.c:1661  */
    break;

  case 83:
#line 339 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Geq((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2036 "parser.cc" /* yacc.c:1661  */
    break;

  case 84:
#line 341 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Plus((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2042 "parser.cc" /* yacc.c:1661  */
    break;

  case 85:
#line 343 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Minus((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2048 "parser.cc" /* yacc.c:1661  */
    break;

  case 86:
#line 345 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Or((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2054 "parser.cc" /* yacc.c:1661  */
    break;

  case 87:
#line 347 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Asterisk((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2060 "parser.cc" /* yacc.c:1661  */
    break;

  case 88:
#line 349 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Slash((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2066 "parser.cc" /* yacc.c:1661  */
    break;

  case 89:
#line 351 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Div((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2072 "parser.cc" /* yacc.c:1661  */
    break;

  case 90:
#line 353 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::Mod((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2078 "parser.cc" /* yacc.c:1661  */
    break;

  case 91:
#line 355 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_expression) = kc::And((yyvsp[-2].yt_expression), (yyvsp[0].yt_expression)); }
#line 2084 "parser.cc" /* yacc.c:1661  */
    break;

  case 92:
#line 360 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_literal) = kc::IntegerConstant((yyvsp[0].yt_integer)); }
#line 2090 "parser.cc" /* yacc.c:1661  */
    break;

  case 93:
#line 362 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_literal) = kc::RealConstant((yyvsp[0].yt_real)); }
#line 2096 "parser.cc" /* yacc.c:1661  */
    break;

  case 94:
#line 364 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_literal) = kc::CharConstant((yyvsp[0].yt_casestring)); }
#line 2102 "parser.cc" /* yacc.c:1661  */
    break;

  case 95:
#line 366 "parser.y" /* yacc.c:1661  */
    { (yyval.yt_constant_literal) = kc::StringConstant((yyvsp[0].yt_casestring)); }
#line 2108 "parser.cc" /* yacc.c:1661  */
    break;


#line 2112 "parser.cc" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 369 "parser.y" /* yacc.c:1906  */

