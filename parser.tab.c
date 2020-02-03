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
#line 2 "parser.y" /* yacc.c:339  */

 
 #include <iostream> 
 

 using namespace std;
 static long long Cur_Mem_tmp=104;
 bool verbose;
 bool pre;
 int out;
 int yylineNum=0;
 string lastScope;
 int labelCnt=0;

 void yyerror(const char* error);
 void error(const char * error)
 {
	 char temp[500];
	 sprintf(temp,"error :\n\t%s\n> line number: #%d",error,yylineNum+1);
	 yyerror(temp);
 }
 void warning(const char * warn)
 {
	 printf("warning :\n\t%s\n> line number: #%d",warn,yylineNum+1);
 }
 
 #include "myDef.h"
 
 extern FILE* yyin;
 extern int yylex();
 
 
 FILE* f1;

 extern long long PC; 
 

 int yyparse();
	

#line 107 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    NUM = 258,
    ifKeyWord = 259,
    elseKeyWord = 260,
    whileKeyWord = 261,
    forKeyWord = 262,
    OperatorPP = 263,
    OperatorMM = 264,
    VoidKeyWord = 265,
    IntKeyWord = 266,
    returnKeyWord = 267,
    OpenBrace = 268,
    CloseBrace = 269,
    OpenParenthesis = 270,
    CloseParenthesis = 271,
    Semicolon = 272,
    Comma = 273,
    OperatorSmallEqual = 274,
    OperatorSmall = 275,
    OperatorBigEqual = 276,
    OperatorBig = 277,
    OperatorNotEqual = 278,
    OperatorEqual = 279,
    OperatorAssign = 280,
    OperatorAdd = 281,
    OperatorMinus = 282,
    OperatorMult = 283,
    OperatorDiv = 284,
    OperatorOR = 285,
    OperatorAnd = 286,
    OperatorXOR = 287,
    BinaryOR = 288,
    BinaryAnd = 289,
    BinaryNot = 290,
    UnaryNot = 291,
    ID = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "parser.y" /* yacc.c:355  */

	int iVal;
	char name[100];
	long long address;

#line 191 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

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
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   126,   117,   130,   131,   129,   133,   133,
     134,   132,   136,   136,   137,   135,   139,   139,   140,   138,
     142,   142,   143,   141,   144,   147,   147,   150,   151,   154,
     155,   156,   158,   159,   160,   163,   163,   163,   176,   177,
     181,   176,   204,   205,   209,   213,   217,   218,   221,   222,
     225,   228,   232,   247,   271,   275,   304,   307,   323,   328,
     344,   347,   363,   367,   389,   411,   415,   438,   461,   484,
     507,   512,   528,   544,   548,   564,   593,   598,   607,   623,
     637,   657,   662,   681,   682,   683,   687,   687,   688,   688,
     691,   692,   693,   694,   695,   699,   700,   700,   704,   705,
     706,   707,   717,   718,   721,   722
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ifKeyWord", "elseKeyWord",
  "whileKeyWord", "forKeyWord", "OperatorPP", "OperatorMM", "VoidKeyWord",
  "IntKeyWord", "returnKeyWord", "OpenBrace", "CloseBrace",
  "OpenParenthesis", "CloseParenthesis", "Semicolon", "Comma",
  "OperatorSmallEqual", "OperatorSmall", "OperatorBigEqual", "OperatorBig",
  "OperatorNotEqual", "OperatorEqual", "OperatorAssign", "OperatorAdd",
  "OperatorMinus", "OperatorMult", "OperatorDiv", "OperatorOR",
  "OperatorAnd", "OperatorXOR", "BinaryOR", "BinaryAnd", "BinaryNot",
  "UnaryNot", "ID", "$accept", "PROGRAM", "$@1", "$@2", "PGM", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "STMTS", "STMT", "other_statement", "STMT_WHILE",
  "$@17", "$@18", "STMT_FOR", "$@19", "$@20", "$@21", "matched",
  "unmatched", "IF_ELSE", "IF", "BLOCK", "EXP", "TERM9", "TERM8", "TERM7",
  "TERM6", "TERM5", "TERM4", "TERM3", "TERM2", "TERM", "FACTOR",
  "STMT_DECLARE", "$@22", "$@23", "EXP_FUNCTIONCALL", "IDS", "$@24",
  "STMT_ASSIGN", "STMT_RETURN", "TYPE", YY_NULLPTR
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

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -145,     4,     1,  -145,   -20,  -145,     3,    60,     8,    15,
    -145,  -145,  -145,    -5,    14,    28,    84,    44,  -145,  -145,
    -145,    84,    84,    84,    84,    47,    57,  -145,    52,    45,
      80,    81,    92,   102,    70,    67,    99,  -145,    23,     8,
     101,  -145,  -145,  -145,  -145,  -145,     0,  -145,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,  -145,     5,  -145,  -145,  -145,    13,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,   116,  -145,    78,  -145,    84,    46,
    -145,    59,    86,   121,   122,   123,    61,  -145,    97,   126,
      46,  -145,  -145,  -145,  -145,  -145,     7,     7,   124,  -145,
    -145,  -145,   130,  -145,   107,  -145,    84,    84,  -145,     1,
    -145,   128,   129,   131,    84,  -145,  -145,    46,  -145,  -145,
    -145,  -145,   142,   144,  -145,    46,  -145,    91,    98,   134,
      84,  -145,  -145,  -145,  -145,   135,    60,   137,  -145,  -145,
     139,   141,  -145,   118,  -145,    84,  -145,   140,    84,  -145,
    -145,  -145,  -145,    46,  -145,   143,   145,  -145,   146,    60,
     148,   147,  -145,  -145,   151,  -145,  -145,  -145,    46,  -145,
      46,    84,    60,   152,   154,   155,  -145,  -145,  -145,    46,
    -145,   156,    60,   157,   160,  -145,  -145,    46,    60,   161,
    -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,    86,    24,    95,     0,
     105,   104,     4,     0,     0,     0,     0,     0,    96,    87,
      77,     0,     0,     0,     0,    82,     0,    52,    54,    56,
      58,    60,    62,    65,    70,    73,    76,    85,     0,    95,
       0,    78,    80,    79,    83,    84,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,    97,    81,    90,     0,    53,
      55,    57,    59,    61,    64,    63,    67,    66,    69,    68,
      71,    72,    74,    75,     0,     8,     0,    91,     0,    26,
       9,     0,     0,     0,     0,     0,     0,    34,    82,     0,
      26,    43,    32,    33,    27,    28,     0,     0,     0,    29,
      30,    31,     0,    12,     0,    92,     0,     0,    35,     0,
     103,     0,    83,    84,     0,     6,    25,    26,    42,    46,
      47,    44,    27,    45,   101,    26,    13,     0,     0,     0,
       0,    38,   102,    99,   100,     0,    24,     0,    48,    49,
       0,     0,    16,     0,    93,     0,    50,     0,     0,    98,
       7,    51,    10,    26,    17,     0,     0,    36,     0,    24,
       0,     0,    20,    94,     0,    39,    11,    14,    26,    21,
      26,     0,    24,     0,     0,     0,    40,    15,    18,    26,
      37,     0,    24,     0,     0,    19,    22,    26,    24,     0,
      23,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,  -144,  -145,  -145,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   -94,
      50,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,    24,
      62,  -145,  -145,    51,   -16,  -145,   132,   125,   120,   127,
     133,    79,    10,    75,   -15,    -1,  -145,  -145,  -145,   138,
    -145,  -145,  -145,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    12,    84,   146,    90,   112,   169,
     136,   151,   182,   164,   171,   192,   179,   184,   198,    99,
     100,   101,   102,   140,   174,   103,   158,   181,   191,   104,
     105,   106,   107,   130,   108,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,   109,     8,     9,    37,    15,
      39,   110,   111,    13
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      26,     5,   160,    20,     3,    40,   126,    41,    42,    43,
      20,    93,     4,    94,    95,    21,    67,     6,     4,    96,
     127,    85,    21,    86,    97,   176,    14,    22,   -88,    87,
      68,    88,    17,   147,    22,    23,    24,    25,   187,    63,
      16,   150,    23,    24,    98,    19,    82,    83,   195,    20,
      93,    18,    94,    95,   200,    44,    45,     4,    96,    38,
      64,    21,    46,    97,    20,    76,    77,    78,    79,   170,
      10,    11,    92,    22,    47,   113,    21,   114,   120,    49,
     121,    23,    24,    98,   183,    48,   185,    20,    22,    55,
      56,    57,    58,    59,    60,   193,    23,    24,    25,    21,
     138,   139,   115,   199,   116,   122,   123,   152,   145,   153,
      50,    22,    46,    51,   154,    91,   155,    66,   141,    23,
      24,    25,   124,    52,   157,    53,    54,    61,    62,    89,
     128,   132,    74,    75,    80,    81,   117,   118,   119,   166,
     125,   134,   168,   135,   137,   142,   143,   148,   144,   149,
     156,   161,   159,   162,   163,   165,   167,   131,   133,   172,
     178,   173,   177,   175,   180,   186,   188,   189,   129,   190,
      71,   196,   194,   197,    70,   201,     0,    65,    72,     0,
      69,     0,     0,     0,     0,    73
};

static const yytype_int16 yycheck[] =
{
      16,     2,   146,     3,     0,    21,   100,    22,    23,    24,
       3,     4,    11,     6,     7,    15,    16,    37,    11,    12,
      13,    16,    15,    18,    17,   169,    18,    27,    25,    16,
      46,    18,    37,   127,    27,    35,    36,    37,   182,    16,
      25,   135,    35,    36,    37,    17,    61,    62,   192,     3,
       4,    37,     6,     7,   198,     8,     9,    11,    12,    15,
      37,    15,    15,    17,     3,    55,    56,    57,    58,   163,
      10,    11,    88,    27,    17,    16,    15,    18,    17,    34,
      96,    35,    36,    37,   178,    33,   180,     3,    27,    19,
      20,    21,    22,    26,    27,   189,    35,    36,    37,    15,
     116,   117,    16,   197,    18,     8,     9,    16,   124,    18,
      30,    27,    15,    32,    16,    37,    18,    16,   119,    35,
      36,    37,    25,    31,   140,    23,    24,    28,    29,    13,
     106,   107,    53,    54,    59,    60,    15,    15,    15,   155,
      14,    17,   158,    13,    37,    17,    17,     5,    17,     5,
      16,    14,    17,    14,    13,    37,    16,   107,   107,    16,
      13,    16,    14,    17,    13,   181,    14,    13,   106,    14,
      50,    14,    16,    13,    49,    14,    -1,    39,    51,    -1,
      48,    -1,    -1,    -1,    -1,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    40,     0,    11,    83,    37,    41,    84,    85,
      10,    11,    42,    91,    18,    87,    25,    37,    37,    17,
       3,    15,    27,    35,    36,    37,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    86,    15,    88,
      72,    82,    82,    82,     8,     9,    15,    17,    33,    34,
      30,    32,    31,    23,    24,    19,    20,    21,    22,    26,
      27,    28,    29,    16,    37,    87,    16,    16,    72,    74,
      75,    76,    77,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    82,    82,    43,    16,    18,    16,    18,    13,
      45,    37,    72,     4,     6,     7,    12,    17,    37,    57,
      58,    59,    60,    63,    67,    68,    69,    70,    72,    83,
      89,    90,    46,    16,    18,    16,    18,    15,    15,    15,
      17,    72,     8,     9,    25,    14,    57,    13,    67,    68,
      71,    58,    67,    71,    17,    13,    48,    37,    72,    72,
      61,    83,    17,    17,    17,    72,    44,    57,     5,     5,
      57,    49,    16,    18,    16,    18,    16,    72,    64,    17,
      42,    14,    14,    13,    51,    37,    72,    16,    72,    47,
      57,    52,    16,    16,    62,    17,    42,    14,    13,    54,
      13,    65,    50,    57,    55,    57,    72,    42,    14,    13,
      14,    66,    53,    57,    16,    42,    14,    13,    56,    57,
      42,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    40,    41,    39,    43,    44,    42,    45,    46,
      47,    42,    48,    49,    50,    42,    51,    52,    53,    42,
      54,    55,    56,    42,    42,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    61,    62,    60,    64,    65,
      66,    63,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    77,    77,    78,    78,    78,    79,    79,    79,    79,
      79,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    84,    83,    85,    83,
      86,    86,    86,    86,    86,    87,    88,    87,    89,    89,
      89,    89,    90,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     0,    10,     0,     0,
       0,    12,     0,     0,     0,    14,     0,     0,     0,    16,
       0,     0,     0,    18,     0,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     0,     9,     0,     0,
       0,    13,     2,     1,     2,     2,     2,     2,     3,     3,
       4,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     2,     2,
       2,     3,     1,     2,     2,     1,     0,     5,     0,     6,
       3,     4,     6,     8,    10,     0,     0,     4,     4,     3,
       3,     2,     3,     2,     1,     1
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
#line 117 "parser.y" /* yacc.c:1646  */
    {pb.push_back(".data:");
    pb.push_back("err_string: .asciiz \"\\ndivide by zero error!\\n\"");
    pb.push_back("nextline_string: .asciiz \"\\n\"");
    pb.push_back(".text:");
	pb.push_back("li $s0, 500");
	pb.push_back("sw $s0, 100($gp)");
	pb.push_back("li $s0, 0");
	pb.push_back("sw $s0, 96($gp)");

	}
#line 1439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 126 "parser.y" /* yacc.c:1646  */
    {makeGolobal(); }
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 130 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-2].name),0,(yyvsp[-3].name));}
#line 1451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "parser.y" /* yacc.c:1646  */
    { functionFinished(0,(yyvsp[-6].name));}
#line 1457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-3].name),1,(yyvsp[-4].name));}
#line 1463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 133 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-2].name),1);}
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 134 "parser.y" /* yacc.c:1646  */
    { functionFinished(1,(yyvsp[-8].name));}
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-5].name),2,(yyvsp[-6].name));}
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 136 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-4].name),1);fun_var((yyvsp[-2].name),2);}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 137 "parser.y" /* yacc.c:1646  */
    { functionFinished(2,(yyvsp[-10].name));}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 139 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-7].name),3,(yyvsp[-8].name));}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 139 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-6].name),1);fun_var((yyvsp[-4].name),2);fun_var((yyvsp[-2].name),3);}
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 140 "parser.y" /* yacc.c:1646  */
    { functionFinished(3,(yyvsp[-12].name));}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 142 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-9].name),4,(yyvsp[-10].name));}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-8].name),1);fun_var((yyvsp[-6].name),2);fun_var((yyvsp[-4].name),3);fun_var((yyvsp[-2].name),4);}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "parser.y" /* yacc.c:1646  */
    { functionFinished(4,(yyvsp[-14].name));}
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 144 "parser.y" /* yacc.c:1646  */
    {}
#line 1535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 147 "parser.y" /* yacc.c:1646  */
    {}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 160 "parser.y" /* yacc.c:1646  */
    {semantic_stack.top();}
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 163 "parser.y" /* yacc.c:1646  */
    {push(pb.size());}
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 163 "parser.y" /* yacc.c:1646  */
    {save();}
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 163 "parser.y" /* yacc.c:1646  */
    {whileJump();}
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 176 "parser.y" /* yacc.c:1646  */
    {push(pb.size());}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 177 "parser.y" /* yacc.c:1646  */
    {	
	 save();
	 pb.push_back("");
 }
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 181 "parser.y" /* yacc.c:1646  */
    {
	 pb.push_back("lw $v1, 0($sp)");pb.push_back("addi $sp, $sp,4");	

	 int a=pop();
	 pb[a+1]="j a"+to_string(pb.size()+2);
	 instJump.push(pb.size()+2);
	 int b=pop()+1;
	 pb.push_back("j a"+to_string(b));
	 instJump.push(b);
	 push(a);
  }
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 192 "parser.y" /* yacc.c:1646  */
    {forJump();}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "parser.y" /* yacc.c:1646  */
    {jump();}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 209 "parser.y" /* yacc.c:1646  */
    {
	  pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);
	  instJump.push(pb.size()+1);
  }
#line 1617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 213 "parser.y" /* yacc.c:1646  */
    {
	  pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);
	  instJump.push(pb.size()+1);
  }
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 217 "parser.y" /* yacc.c:1646  */
    {jump();}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "parser.y" /* yacc.c:1646  */
    {jump();}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 221 "parser.y" /* yacc.c:1646  */
    {saveJump();}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 222 "parser.y" /* yacc.c:1646  */
    {saveJump();}
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 225 "parser.y" /* yacc.c:1646  */
    {save();}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 232 "parser.y" /* yacc.c:1646  */
    {
	  char tmp[500];
	  (yyval.address) = ((yyvsp[0].iVal));
	  
      //$$=getFree();
	  //pb.push_back("lw $s0,0($sp)");
	  //pb.push_back("laddi $sp,$sp,4");
	  //sprintf(tmp,"sw $s0,%llu($gp)",$$);
	  //pb.push_back(tmp);

	  
	  }
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 248 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1)||($3);	 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4");

	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4");  
	
	pb.push_back("bne $s0,$zero,BinaryOR_True"+to_string(labelCnt)); //age sefr nabood boro be true
	
	pb.push_back("bne $s1,$zero,BinaryOR_True"+to_string(labelCnt)); //age sefr nabood boro be true
	//age false shod
	pb.push_back("li $s0,0");  
	pb.push_back("j BinaryOR_write"+to_string(labelCnt));  
	
	//age true shod
	pb.push_back("BinaryOR_True"+to_string(labelCnt)+": li $s0,1");  
	 
	 
	pb.push_back("BinaryOR_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 276 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1)&&($3);	 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 

			 					 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$zero,BinaryAnd_False"+to_string(labelCnt)); //age sefr bood boro be false
	
	
	pb.push_back("beq $s1,$zero,BinaryAnd_False"+to_string(labelCnt)); //age sefr bood boro be false
	
	//age hardo sefr naboodan yani javab true mishod					 
	
	 
	pb.push_back("li $s0,1");  
	pb.push_back("j BinaryAnd_write"+to_string(labelCnt));  
	
	//age true shod
	pb.push_back("BinaryAnd_False"+to_string(labelCnt)+": li $s0,0");  
	 
	 
	pb.push_back("BinaryAnd_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1740 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 304 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 308 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1) | ($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("or $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 323 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 329 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1)^($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("xor $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1798 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 348 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1)&($3); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("and $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 363 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1824 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 368 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1)==($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("beq $s0,$s1,OperatorEqual_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorEqual_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorEqual_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 390 "parser.y" /* yacc.c:1646  */
    {
	//$$ = ($1)!=($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$s1,OperatorNotEqual_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorNotEqual_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorNotEqual_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorNotEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 411 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)= ((yyvsp[0].iVal));}
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 416 "parser.y" /* yacc.c:1646  */
    {							//    s1 < s0
	//$$ = ($1)<($3); 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s1, $s0,OperatorSmall_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorSmall_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorSmall_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorSmall_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1908 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 439 "parser.y" /* yacc.c:1646  */
    {								//          s1  > s0 => false
								//          s0  < s1 => false
    //$$ = ($1)<=($3);	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s0, $s1,OperatorSmallEqual_false"+to_string(labelCnt)); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorSmallEqual_write"+to_string(labelCnt)); 
	
	//false bood
	pb.push_back("OperatorSmallEqual_false"+to_string(labelCnt)+": li $s0, 0"); 
	pb.push_back("OperatorSmallEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 462 "parser.y" /* yacc.c:1646  */
    {						   // 		 s1 > s0
  						   // 		 s0 < s1
    //$$ = ($1)>($3);	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s0, $s1,OperatorBig_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorBig_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorBig_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorBig_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 485 "parser.y" /* yacc.c:1646  */
    {								//          s1  < s0 => false
								 
	//$$ = ($1)>=($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s1, $s0,OperatorBigEqual_false"); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorBigEqual_write"+to_string(labelCnt)); 
	
	//false bood
	pb.push_back("OperatorBigEqual_false"+to_string(labelCnt)+": li $s0, 0"); 
	pb.push_back("OperatorBigEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
 }
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 507 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 513 "parser.y" /* yacc.c:1646  */
    {
	(yyval.iVal) = ((yyvsp[-2].iVal)) + ((yyvsp[0].iVal)); 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("add $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 2015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 529 "parser.y" /* yacc.c:1646  */
    {								//    s1     s0
	(yyval.iVal) = ((yyvsp[-2].iVal)) - ((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("sub $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 544 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)= ((yyvsp[0].iVal));}
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 549 "parser.y" /* yacc.c:1646  */
    {								//    s1     s0
	(yyval.iVal) = ((yyvsp[-2].iVal)) * ((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("mul $s2,$s1,$s0"); 
	//????????????????????????????????????
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 565 "parser.y" /* yacc.c:1646  */
    {								  //    s1     s0

	if((yyvsp[0].iVal)==0)
	{
		error("divide by zero error!!");
		exit(-100);
	}
 	(yyval.iVal) = ((yyvsp[-2].iVal)) / ((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("bne $s0,$zero,skip"+to_string(labelCnt));
	pb.push_back("li $v0,4");
	pb.push_back("la $a0,err_string");
	pb.push_back("syscall");
	pb.push_back("li $v0, 10");
	pb.push_back("syscall");
	pb.push_back("skip"+to_string(labelCnt++)+":lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("div $s1,$s0"); 
	pb.push_back("mflo $s2"); 
	 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 593 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 2100 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 598 "parser.y" /* yacc.c:1646  */
    {
	 (yyval.iVal) = (yyvsp[0].iVal);
	 char tmp[500];
	 //sprintf(tmp,"movl $%d, %%eax",$1);
	 sprintf(tmp,"li $s0 , %d",(yyvsp[0].iVal));
	 pb.push_back(string(tmp));
	 pb.push_back("addi $sp,$sp,-4");
	 pb.push_back("sw $s0,0($sp)");
	 }
#line 2114 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 608 "parser.y" /* yacc.c:1646  */
    {								//   
    (yyval.iVal) = -((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("li $s1,-1"); 
	
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
   }
#line 2134 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 624 "parser.y" /* yacc.c:1646  */
    {								//   
	(yyval.iVal) = ~((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	 
	
	pb.push_back("not $s2,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
#line 2152 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 638 "parser.y" /* yacc.c:1646  */
    {								//   
	(yyval.iVal) = !((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("beq $s0,$zero,BinaryNot_return"+to_string(labelCnt)); 
	pb.push_back("li $s2,0"); 
	
	pb.push_back("j BinaryNot_save"+to_string(labelCnt)); 
	
	pb.push_back("BinaryNot_return"+to_string(labelCnt)+" : li $s2,1"); 
	
	
	
	pb.push_back("BinaryNot_save"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 658 "parser.y" /* yacc.c:1646  */
    {
		(yyval.iVal) = (yyvsp[-1].address);
		 //not thing
	 }
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 663 "parser.y" /* yacc.c:1646  */
    {
		(yyval.iVal) = 123; 
		char temp[500];
		if(symbolTable[(yyvsp[0].name)].TYPE != SEM_TYPE_VARIABLE_INT)
		{
			error("variable has not been declared properly!");
			exit(-10);
		}
		pb.push_back("lw $s1,96($gp)");
		pb.push_back("addi $s2,$s1,"+to_string(symbolTable[(yyvsp[0].name)].address));
		pb.push_back("add $s2,$s2,$gp");
		pb.push_back("lw $s0,0($s2)");
		//sprintf(temp,"lw $s0,%llu($gp)",symbolTable[$1].address);
		//pb.push_back(temp);
		pb.push_back("addi $sp, $sp,-4"); 
		pb.push_back("sw $s0,0($sp)");
		printf("i am called:%s!!\n",(yyvsp[0].name));
	}
#line 2208 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 681 "parser.y" /* yacc.c:1646  */
    {plusPlus((yyvsp[-1].name),1,1);printf("+ am called:%s!!\n",(yyvsp[-1].name));}
#line 2214 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 682 "parser.y" /* yacc.c:1646  */
    {plusPlus((yyvsp[-1].name),-1,1);}
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 683 "parser.y" /* yacc.c:1646  */
    {}
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 687 "parser.y" /* yacc.c:1646  */
    {declare_IntVariable((yyvsp[0].name));}
#line 2232 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 688 "parser.y" /* yacc.c:1646  */
    {declare_IntVariable((yyvsp[0].name));}
#line 2238 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 688 "parser.y" /* yacc.c:1646  */
    {assignto((yyvsp[-4].name));}
#line 2244 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 691 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-2].name),0);}
#line 2250 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 692 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-3].name),1,(yyvsp[-1].address));}
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 693 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-5].name),2,(yyvsp[-3].address),(yyvsp[-1].address));}
#line 2262 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 694 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-7].name),3,(yyvsp[-5].address),(yyvsp[-3].address),(yyvsp[-1].address));}
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 695 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-9].name),4,(yyvsp[-7].address),(yyvsp[-5].address),(yyvsp[-3].address),(yyvsp[-1].address));}
#line 2274 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 699 "parser.y" /* yacc.c:1646  */
    {}
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 700 "parser.y" /* yacc.c:1646  */
    {declare_IntVariable((yyvsp[0].name));}
#line 2286 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 704 "parser.y" /* yacc.c:1646  */
    { assignto((yyvsp[-3].name));}
#line 2292 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 705 "parser.y" /* yacc.c:1646  */
    {plusPlus((yyvsp[-2].name),1);}
#line 2298 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 706 "parser.y" /* yacc.c:1646  */
    {plusPlus((yyvsp[-2].name),-1);}
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 708 "parser.y" /* yacc.c:1646  */
    {
	pb.push_back("lw $v1, 0($sp)");
	pb.push_back("addi $sp, $sp,4");
	if((yyvsp[-1].address)!=-10)
		warning("useless epression!");
  }
#line 2315 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 717 "parser.y" /* yacc.c:1646  */
    {returnHandle(lastScope);}
#line 2321 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 718 "parser.y" /* yacc.c:1646  */
    {voidReturn(lastScope);}
#line 2327 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 721 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.name),"int"); }
#line 2333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 722 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.name),"void");}
#line 2339 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2343 "parser.tab.c" /* yacc.c:1646  */
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
#line 724 "parser.y" /* yacc.c:1906  */



void yyerror(const char *s) {
 fprintf(stderr, "%s\n", s);
}
void help()
{
	printf("compiler help!\n\n\tout put file is \'output.mips\'\n\n");
			cout<<"\tfirst argument is source file path\n";
			cout<<"\t--show enable some log in each compile step\n";
			cout<<"\t--pre first pre process the source then compile it"<<endl;
			cout<<"\t--def enable define out put for processor"<<endl;
			cout<<"\t-o name name of preProcessor output"<<endl;
			cout<<"\t-h show help(this page!)"<<endl;

}
int main(int argc, char *argv[])
{
	char cmd[100];
	char def[10];
	strcpy(def," NoDef");
	pre=0;
	out=0;
	if(argc<=1)
	{
		help();
		return(0);
	}
	for(int i=2;i<argc;i++)
	{
		if(strcmp("--show",argv[i])==0)
		{
			verbose=1;
		}
		if(strcmp("--pre",argv[i])==0)
		{
			pre=1;
		}
		if(strcmp("-o",argv[i])==0 && (i+1<argc))
		{
			out=i+1;
		}
		if(strcmp("--def",argv[i])==0)
		{
			def[0]=0;
		}
		if(strcmp("-h",argv[i])==0)
		{
			help();
			return(0);
		}
		
	}
	if(pre)
	{
		if(out)
		{
			sprintf(cmd,"./pre %s %s %s",argv[1],argv[out],def);
		}else
			sprintf(cmd,"./pre %s output_pre.c %s",argv[1],def);
		system(cmd);
		yyin = fopen(argv[out], "r");
	}else
		yyin = fopen(argv[1], "r");
	f1=fopen("output.mips","w");

	/* print built in function*/
	Node tmp=Node();
    tmp.address=-10;
    tmp.scope=-1;
	tmp.numOfArguments=1;
	tmp.TYPE=SEM_TYPE_FUNCTION_VOID;
	tmp.output=1;
    symbolTable["print"]=tmp;
	tmp.numOfArguments=0;
	tmp.TYPE=SEM_TYPE_FUNCTION_INT;
	symbolTable["scan"]=tmp;
	/**/

    if(!yyparse())
		printf("\nParsing complete\n");
	else
	{
		printf("\nParsing failed\n");
		exit(-1);
	}
	int return_address;
	if(PC!=0)
	{
		return_address=pop();
		pb[return_address]="li $s0,500";
		pb[return_address+1]="sw $s0, 96($gp)";
		pb[return_address+2]="jal main";
		pb[return_address+3]="li $v0, 17";
		pb[return_address+4]="lw $a0, 0($sp)";
		pb[return_address+5]="addi $sp, $sp,4";
		pb[return_address+6]="syscall";
	}	
	else{
		error("main function Not Found!");
		exit(-4);
	}
	while(!instJump.empty())
	{
		int top=instJump.top();
		pb[top-1]="a"+to_string(top)+": "+pb[top-1];
		instJump.pop();
	}
	
	printf("MIPS CODE is saves in output file!\n");
	if(verbose)
		printf("Code:\n");
	for(int j=0;j<pb.size();j++)
	{
		fprintf(f1,"%s\n",pb[j].c_str());
		if(verbose)
			printf("%s\n",pb[j].c_str());
	}
    fprintf(f1,"\n");
    
	fclose(yyin);
	fclose(f1);
	symbolTableShow();
	cout<<"PC is: "<<PC<<endl;
	
    return 0;
}
