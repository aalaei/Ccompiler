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
 bool ERROR_occurred=0;
 int out;
 int mid;
 int yylineNum=0;
 string lastScope;
 string lastScope_BLOCK;
 int labelCnt=0;

 void yyerror(const char* error);
 void myerror(const char * er,int errCode)
 {
	 char temp[500];
	 sprintf(temp,"error occurred Code %d :\n\t%s\n> line number: #%d\n",-errCode,er,yylineNum+1);
	 yyerror(temp);	 
	 ERROR_occurred=1;

 }
 void warning(const char * warn)
 {
	 printf("warning :\n\t%s\n> line number: #%d\n",warn,yylineNum+1);
 }
 #define MAIN_OFFSET 200
 #define ARRAY_OFFSET 1000
 #define DYNAMIC_OFFSET_LOC 96
 static long long ARRAY_CNT=ARRAY_OFFSET;

 #include "myDef.h"
 
 extern FILE* yyin;
 extern int yylex();
 
 
 FILE* f1;

 extern long long PC; 
 

 int yyparse();
	

#line 116 "parser.tab.c" /* yacc.c:339  */

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
    ID = 292,
    OpenBracket = 293,
    CloseBracket = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 52 "parser.y" /* yacc.c:355  */

	int iVal;
	char name[100];
	long long address;

#line 202 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   129,   137,   138,   136,   140,   140,   141,
     139,   143,   143,   144,   142,   146,   146,   147,   145,   149,
     149,   150,   148,   151,   154,   154,   158,   159,   162,   163,
     164,   166,   167,   168,   171,   171,   171,   184,   185,   189,
     184,   201,   202,   206,   201,   229,   230,   234,   238,   242,
     243,   246,   247,   250,   253,   254,   254,   257,   258,   258,
     261,   261,   266,   281,   305,   309,   338,   341,   357,   362,
     378,   381,   397,   401,   423,   445,   449,   477,   511,   540,
     573,   578,   594,   610,   614,   630,   659,   664,   673,   689,
     703,   723,   728,   751,   773,   774,   775,   776,   777,   781,
     782,   786,   786,   787,   788,   789,   792,   792,   795,   795,
     799,   800,   801,   802,   803,   807,   808,   808,   812,   813,
     814,   815,   818,   825,   829,   830,   831,   834,   835
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
  "UnaryNot", "ID", "OpenBracket", "CloseBracket", "$accept", "PROGRAM",
  "$@1", "PGM", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9",
  "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "STMTS", "STMT",
  "other_statement", "STMT_WHILE", "$@16", "$@17", "STMT_FOR", "$@18",
  "$@19", "$@20", "$@21", "$@22", "$@23", "matched", "unmatched",
  "IF_ELSE", "IF", "BLOCK", "$@24", "BLOCK_FUN", "$@25", "BLOCK_L", "$@26",
  "EXP", "TERM9", "TERM8", "TERM7", "TERM6", "TERM5", "TERM4", "TERM3",
  "TERM2", "TERM", "FACTOR", "STMT_DECLARE", "$@27", "STMT_DECLARE_ASSL",
  "$@28", "STMT_DECLARE_L", "$@29", "EXP_FUNCTIONCALL", "IDS", "$@30",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -124

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-124)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,   -24,    20,  -124,    26,    41,     7,  -124,    60,  -124,
    -124,  -124,  -124,    22,    10,    32,  -124,  -124,  -124,    25,
       5,    73,    44,  -124,   102,    66,  -124,    73,    73,    73,
      73,    21,  -124,  -124,   128,    96,   125,   105,   103,    82,
     107,   136,   129,  -124,  -124,     0,  -124,   151,   157,  -124,
    -124,  -124,  -124,  -124,    50,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    32,  -124,   117,  -124,  -124,  -124,   122,   137,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,   161,  -124,   140,  -124,    73,
     156,    57,  -124,  -124,   130,   131,  -124,  -124,   163,   164,
     165,     4,  -124,   116,   101,    57,  -124,  -124,  -124,  -124,
    -124,    11,    11,    78,  -124,  -124,  -124,    60,   161,  -124,
     144,  -124,    73,    73,  -124,    86,  -124,  -124,   166,    73,
      73,  -124,  -124,  -124,  -124,  -124,  -124,  -124,   106,  -124,
     177,   179,  -124,  -124,  -124,  -124,  -124,   134,   135,   169,
      73,  -124,  -124,  -124,    97,   147,   173,    57,  -124,  -124,
    -124,  -124,    60,   161,  -124,   154,  -124,    73,  -124,   172,
      73,    73,  -124,  -124,    48,  -124,  -124,   178,  -124,  -124,
    -124,   180,   181,  -124,   176,   182,    73,  -124,    60,   161,
    -124,  -124,   185,  -124,  -124,   115,  -124,  -124,  -124,  -124,
      73,    73,  -124,  -124,    60,   161,  -124,  -124,  -124,  -124,
     184,   186,    60,   185,   185,  -124,  -124,  -124
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,   108,     1,    23,   105,
     104,   100,    99,     0,     0,   115,   128,   127,     3,     0,
       0,     0,     0,   109,     0,     0,    87,     0,     0,     0,
       0,    92,   107,    62,    64,    66,    68,    70,    72,    75,
      80,    83,    86,    98,   116,     0,   103,     0,     0,    88,
      90,    89,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     4,     0,   102,    91,   110,     0,     0,    63,
      65,    67,    69,    71,    74,    73,    77,    76,    79,    78,
      81,    82,    84,    85,   117,     0,     7,     0,   111,     0,
      93,    25,     5,     8,     0,     0,    96,    97,     0,     0,
       0,     0,    33,    92,     0,    25,    46,    31,    32,    26,
      27,     0,     0,     0,    28,    29,    30,    23,     0,    11,
       0,   112,     0,     0,    34,     0,   126,   125,     0,     0,
       0,    58,    57,    24,    60,    45,    49,    50,     0,    47,
      26,    48,   123,   122,     6,     9,    12,     0,     0,     0,
       0,    37,    41,   124,     0,     0,     0,    25,    55,    54,
      51,    52,    23,     0,    15,     0,   113,     0,    53,     0,
       0,     0,   119,   118,    93,    59,    61,     0,    10,    13,
      16,     0,     0,    35,     0,     0,     0,    56,    23,     0,
      19,   114,     0,    38,    42,     0,    14,    17,    20,    36,
       0,     0,   121,   120,    23,     0,    39,    43,    18,    21,
       0,     0,    23,     0,     0,    22,    40,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,  -123,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -112,    72,
    -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,  -124,
    -124,    45,    74,  -124,  -124,  -120,  -124,  -119,  -124,  -124,
    -124,   -21,  -124,   145,   146,   148,   149,   150,   108,    79,
     104,   -18,     1,  -124,  -124,  -124,  -124,  -124,  -124,   133,
    -124,    70,  -124,  -124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    18,    95,   127,   103,   128,   172,   156,
     173,   198,   190,   199,   214,   208,   215,   222,   114,   115,
     116,   117,   160,   202,   118,   180,   210,   220,   181,   211,
     221,   119,   120,   121,   122,   147,   187,   102,   166,   148,
     167,   123,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   124,    47,     4,    14,     5,    15,    43,    23,
      71,   125,   126,    19
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,     3,   151,   143,   154,   136,    48,    26,     1,   155,
      49,    50,    51,     6,    26,   108,    72,   109,   110,    27,
       7,   137,     1,   111,   144,    20,    27,     9,   112,    52,
      53,    28,  -106,    77,    78,    21,    54,    73,    28,    29,
      30,    31,    11,    10,    25,    13,    29,    30,   113,   188,
      22,    92,    93,    26,   189,   186,   106,   107,    12,    55,
      26,   108,    24,   109,   110,    27,    76,    46,     1,   111,
      16,    17,    27,   196,   112,   206,    26,    28,   105,   152,
     207,    44,   209,  -101,    28,    29,    30,    31,    27,    26,
     138,   218,    29,    30,   113,   153,   219,     1,   182,   225,
      28,    27,   141,   226,   227,    61,    62,   168,    29,    30,
      31,   158,   159,    28,   183,   142,   212,    45,   164,   165,
     169,    29,    30,   113,    52,    53,    63,    64,    65,    66,
      57,    54,   213,    96,    60,    97,   161,    59,    98,   179,
      99,   139,    86,    87,    88,    89,   129,   131,   130,   132,
     174,   176,   175,   177,   140,    58,   192,    69,    70,   194,
     195,    56,    67,    68,   106,   107,   145,   150,    74,    84,
      85,    90,    91,    75,   101,   205,   100,   104,   133,   134,
     135,   157,   170,   163,   171,   178,   184,   185,   193,   216,
     217,   191,   197,   203,   149,   146,   200,   201,   144,   204,
     223,    79,   224,    80,    94,   162,    81,     0,    82,     0,
      83
};

static const yytype_int16 yycheck[] =
{
      21,     0,   122,   115,   127,     1,    27,     3,    11,   128,
      28,    29,    30,    37,     3,     4,    16,     6,     7,    15,
       0,    17,    11,    12,    13,     3,    15,     1,    17,     8,
       9,    27,    25,    54,    55,    25,    15,    37,    27,    35,
      36,    37,     1,    17,    39,    38,    35,    36,    37,   172,
      18,    69,    70,     3,   173,   167,     8,     9,    17,    38,
       3,     4,    37,     6,     7,    15,    16,     1,    11,    12,
      10,    11,    15,    25,    17,   198,     3,    27,    99,     1,
     199,    37,   202,    17,    27,    35,    36,    37,    15,     3,
     111,   214,    35,    36,    37,    17,   215,    11,     1,   222,
      27,    15,     1,   223,   224,    23,    24,     1,    35,    36,
      37,   132,   133,    27,    17,    14,     1,    15,   139,   140,
      14,    35,    36,    37,     8,     9,    19,    20,    21,    22,
      34,    15,    17,    16,    31,    18,   135,    32,    16,   160,
      18,    25,    63,    64,    65,    66,    16,    16,    18,    18,
      16,    16,    18,    18,    38,    30,   177,    28,    29,   180,
     181,    33,    26,    27,     8,     9,   121,   122,    17,    61,
      62,    67,    68,    16,    13,   196,    39,    37,    15,    15,
      15,    37,     5,    17,     5,    16,    39,    14,    16,   210,
     211,    37,    14,    17,   122,   121,    16,    16,    13,    17,
      16,    56,    16,    57,    71,   135,    58,    -1,    59,    -1,
      60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    41,    92,    94,    96,    37,     0,    42,     1,
      17,     1,    17,    38,    95,    97,    10,    11,    43,   103,
       3,    25,    18,    99,    37,    39,     3,    15,    27,    35,
      36,    37,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    98,    37,    15,     1,    93,    81,    91,
      91,    91,     8,     9,    15,    38,    33,    34,    30,    32,
      31,    23,    24,    19,    20,    21,    22,    26,    27,    28,
      29,   100,    16,    37,    17,    16,    16,    81,    81,    83,
      84,    85,    86,    87,    88,    88,    89,    89,    89,    89,
      90,    90,    91,    91,    99,    44,    16,    18,    16,    18,
      39,    13,    77,    46,    37,    81,     8,     9,     4,     6,
       7,    12,    17,    37,    58,    59,    60,    61,    64,    71,
      72,    73,    74,    81,    92,   101,   102,    45,    47,    16,
      18,    16,    18,    15,    15,    15,     1,    17,    81,    25,
      38,     1,    14,    58,    13,    71,    72,    75,    79,    59,
      71,    75,     1,    17,    43,    77,    49,    37,    81,    81,
      62,    92,   101,    17,    81,    81,    78,    80,     1,    14,
       5,     5,    48,    50,    16,    18,    16,    18,    16,    81,
      65,    68,     1,    17,    39,    14,    58,    76,    43,    77,
      52,    37,    81,    16,    81,    81,    25,    14,    51,    53,
      16,    16,    63,    17,    17,    81,    43,    77,    55,    75,
      66,    69,     1,    17,    54,    56,    81,    81,    43,    77,
      67,    70,    57,    16,    16,    43,    75,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    44,    45,    43,    46,    47,    48,
      43,    49,    50,    51,    43,    52,    53,    54,    43,    55,
      56,    57,    43,    43,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    62,    63,    61,    65,    66,    67,
      64,    68,    69,    70,    64,    71,    71,    72,    72,    72,
      72,    73,    73,    74,    75,    76,    75,    77,    78,    77,
      80,    79,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    90,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    92,    92,    92,    92,    95,    94,    97,    96,
      98,    98,    98,    98,    98,    99,   100,    99,   101,   101,
     101,   101,   101,   101,   102,   102,   102,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     8,     0,     0,     0,
      10,     0,     0,     0,    12,     0,     0,     0,    14,     0,
       0,     0,    16,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     7,     0,     0,     0,
      11,     0,     0,     0,    11,     2,     1,     2,     2,     2,
       2,     3,     3,     4,     2,     0,     4,     3,     0,     5,
       0,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     1,     2,     2,
       2,     3,     1,     4,     2,     2,     5,     5,     1,     2,
       2,     0,     7,     6,     2,     2,     0,     5,     0,     4,
       3,     4,     6,     8,    10,     0,     0,     4,     4,     4,
       7,     7,     2,     2,     3,     2,     2,     1,     1
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
#line 129 "parser.y" /* yacc.c:1646  */
    {makeGolobal(); }
#line 1463 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-2].name),0,(yyvsp[-3].name));}
#line 1469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 138 "parser.y" /* yacc.c:1646  */
    { functionFinished(0,(yyvsp[-4].name));}
#line 1475 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 140 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-3].name),1,(yyvsp[-4].name));}
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 140 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-2].name),1);}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "parser.y" /* yacc.c:1646  */
    { functionFinished(1,(yyvsp[-6].name));}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-5].name),2,(yyvsp[-6].name));}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-4].name),1);fun_var((yyvsp[-2].name),2);}
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 144 "parser.y" /* yacc.c:1646  */
    { functionFinished(2,(yyvsp[-8].name));}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-7].name),3,(yyvsp[-8].name));}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 146 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-6].name),1);fun_var((yyvsp[-4].name),2);fun_var((yyvsp[-2].name),3);}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 147 "parser.y" /* yacc.c:1646  */
    { functionFinished(3,(yyvsp[-10].name));}
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 149 "parser.y" /* yacc.c:1646  */
    {declare_Function((yyvsp[-9].name),4,(yyvsp[-10].name));}
#line 1535 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 149 "parser.y" /* yacc.c:1646  */
    {fun_var((yyvsp[-8].name),1);fun_var((yyvsp[-6].name),2);fun_var((yyvsp[-4].name),3);fun_var((yyvsp[-2].name),4);}
#line 1541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 150 "parser.y" /* yacc.c:1646  */
    { functionFinished(4,(yyvsp[-12].name));}
#line 1547 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "parser.y" /* yacc.c:1646  */
    {}
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 154 "parser.y" /* yacc.c:1646  */
    {}
#line 1559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 168 "parser.y" /* yacc.c:1646  */
    {semantic_stack.top();}
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 171 "parser.y" /* yacc.c:1646  */
    {push(pb.size());}
#line 1571 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 171 "parser.y" /* yacc.c:1646  */
    {save();}
#line 1577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 171 "parser.y" /* yacc.c:1646  */
    {whileJump();}
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 184 "parser.y" /* yacc.c:1646  */
    {push(pb.size());}
#line 1589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 185 "parser.y" /* yacc.c:1646  */
    {	
	 save();
	 pb.push_back("");
 }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 189 "parser.y" /* yacc.c:1646  */
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
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 200 "parser.y" /* yacc.c:1646  */
    {forJump();}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 201 "parser.y" /* yacc.c:1646  */
    {push(pb.size());}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 202 "parser.y" /* yacc.c:1646  */
    {	
	 save();
	 pb.push_back("");
 }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 206 "parser.y" /* yacc.c:1646  */
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
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 217 "parser.y" /* yacc.c:1646  */
    {forJump();}
#line 1657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 229 "parser.y" /* yacc.c:1646  */
    {jump();}
#line 1663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 234 "parser.y" /* yacc.c:1646  */
    {
	  pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);
	  instJump.push(pb.size()+1);
  }
#line 1672 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "parser.y" /* yacc.c:1646  */
    {
	  pb[pop()]="beq $s0,$zero, a"+to_string(pb.size()+1);
	  instJump.push(pb.size()+1);
  }
#line 1681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 242 "parser.y" /* yacc.c:1646  */
    {jump();}
#line 1687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 243 "parser.y" /* yacc.c:1646  */
    {jump();}
#line 1693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 246 "parser.y" /* yacc.c:1646  */
    {saveJump();}
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 247 "parser.y" /* yacc.c:1646  */
    {saveJump();}
#line 1705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 250 "parser.y" /* yacc.c:1646  */
    {save();}
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 253 "parser.y" /* yacc.c:1646  */
    {lastScope_BLOCK=lastScope;removeLocal();}
#line 1717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 254 "parser.y" /* yacc.c:1646  */
    {myerror("} is missing!!",21);lastScope_BLOCK=lastScope;removeLocal();}
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 258 "parser.y" /* yacc.c:1646  */
    {myerror("} is missing!!",21);removeLocal();}
#line 1729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 261 "parser.y" /* yacc.c:1646  */
    {lastScope_BLOCK="BLK";}
#line 1735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 266 "parser.y" /* yacc.c:1646  */
    {
	  char tmp[500];
	  (yyval.address) = ((yyvsp[0].iVal));
	  
      //$$=getFree();
	  //pb.push_back("lw $s0,0($sp)");
	  //pb.push_back("laddi $sp,$sp,4");
	  //sprintf(tmp,"sw $s0,%llu($gp)",$$);
	  //pb.push_back(tmp);

	  
	  }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 282 "parser.y" /* yacc.c:1646  */
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
#line 1780 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 305 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 310 "parser.y" /* yacc.c:1646  */
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
#line 1819 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 338 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 342 "parser.y" /* yacc.c:1646  */
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
#line 1845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 357 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 363 "parser.y" /* yacc.c:1646  */
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
#line 1871 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1877 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 382 "parser.y" /* yacc.c:1646  */
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
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 397 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 1903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 402 "parser.y" /* yacc.c:1646  */
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
#line 1929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 424 "parser.y" /* yacc.c:1646  */
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
#line 1955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 445 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)= ((yyvsp[0].iVal));}
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 450 "parser.y" /* yacc.c:1646  */
    {							//    s1 < s0
	//$$ = ($1)<($3); 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("slt $s0,$s1, $s0");  
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	/*
	pb.push_back("blt $s1, $s0,OperatorSmall_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorSmall_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorSmall_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorSmall_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	*/
 }
#line 1992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 478 "parser.y" /* yacc.c:1646  */
    {								//          s1  > s0 => false
								//          s0  < s1 => false
    //$$ = ($1)<=($3);	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 

	pb.push_back("slt $s0,$s0, $s1");  
	pb.push_back("neg $s0,$s0");  
	pb.push_back("addi $s0,$s0,1");  

	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	/*
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s0, $s1,OperatorSmallEqual_false"+to_string(labelCnt)); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorSmallEqual_write"+to_string(labelCnt)); 
	
	//false bood
	pb.push_back("OperatorSmallEqual_false"+to_string(labelCnt)+": li $s0, 0"); 
	pb.push_back("OperatorSmallEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	*/
	
 }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 512 "parser.y" /* yacc.c:1646  */
    {						   // 		 s1 > s0
  						   // 		 s0 < s1
    //$$ = ($1)>($3);	 					 
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	
	pb.push_back("slt $s0,$s0, $s1");  
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	
	/*pb.push_back("blt $s0, $s1,OperatorBig_true"+to_string(labelCnt)); 
	
	//age false bood
	pb.push_back("li $s0, 0"); 
	pb.push_back("j OperatorBig_write"+to_string(labelCnt)); 
	
	//true bood
	pb.push_back("OperatorBig_true"+to_string(labelCnt)+": li $s0, 1"); 
	pb.push_back("OperatorBig_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); */
	
 }
#line 2063 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 541 "parser.y" /* yacc.c:1646  */
    {								//          s1  < s0 => false
								 
	//$$ = ($1)>=($3);
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 


	pb.push_back("slt $s0,$s1, $s0");  
	pb.push_back("neg $s0,$s0");  
	pb.push_back("addi $s0,$s0,1");  

	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 

	/*
	 //blt $t0, $t4, VIP_LESS  # if $t0 < $t4 then VIP
	pb.push_back("blt $s1, $s0,OperatorBigEqual_false"+to_string(labelCnt)); 
	
	//age true bood
	pb.push_back("li $s0, 1"); 
	pb.push_back("j OperatorBigEqual_write"+to_string(labelCnt)); 
	
	//false bood
	pb.push_back("OperatorBigEqual_false"+to_string(labelCnt)+": li $s0, 0"); 
	pb.push_back("OperatorBigEqual_write"+to_string(labelCnt++)+": addi $sp, $sp,-4"); 
	pb.push_back("sw $s0,0($sp)"); 
	*/
 }
#line 2100 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 573 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 2106 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 579 "parser.y" /* yacc.c:1646  */
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
#line 2126 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 595 "parser.y" /* yacc.c:1646  */
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
#line 2146 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 610 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)= ((yyvsp[0].iVal));}
#line 2152 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 615 "parser.y" /* yacc.c:1646  */
    {								//    s1     s0
	(yyval.iVal) = ((yyvsp[-2].iVal)) * ((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("lw $s1, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
 }
#line 2172 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 631 "parser.y" /* yacc.c:1646  */
    {								  //    s1     s0

	if((yyvsp[0].iVal)==0)
	{
		myerror("divide by zero error!!",100);
		
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
#line 2205 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 659 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = ((yyvsp[0].iVal));}
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 664 "parser.y" /* yacc.c:1646  */
    {
	 (yyval.iVal) = (yyvsp[0].iVal);
	 char tmp[500];
	 //sprintf(tmp,"movl $%d, %%eax",$1);
	 sprintf(tmp,"li $s0 , %d",(yyvsp[0].iVal));
	 pb.push_back(string(tmp));
	 pb.push_back("addi $sp,$sp,-4");
	 pb.push_back("sw $s0,0($sp)");
	 }
#line 2225 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 674 "parser.y" /* yacc.c:1646  */
    {								//   
    (yyval.iVal) = -((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
						 
	pb.push_back("li $s1,-1"); 
	
	
	pb.push_back("mul $s2,$s1,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
   }
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 690 "parser.y" /* yacc.c:1646  */
    {								//   
	(yyval.iVal) = ~((yyvsp[0].iVal));
	pb.push_back("lw $s0, 0($sp)"); 
	pb.push_back("addi $sp, $sp,4"); 
	
	 
	
	pb.push_back("not $s2,$s0"); 
	
	pb.push_back("addi $sp, $sp,-4"); 
	pb.push_back("sw $s2,0($sp)"); 
	
    }
#line 2263 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 704 "parser.y" /* yacc.c:1646  */
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
#line 2287 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 724 "parser.y" /* yacc.c:1646  */
    {
		(yyval.iVal) = (yyvsp[-1].address);
		 //not thing
	 }
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 729 "parser.y" /* yacc.c:1646  */
    {
		(yyval.iVal) = 123; 
		char temp[500];
		if(symbolTable[(yyvsp[0].name)].TYPE != SEM_TYPE_VARIABLE_INT)
		{
			myerror("variable has not been declared properly!",10);
			
		}
		if(symbolTable[(yyvsp[0].name)].scope==0)
		{
			pb.push_back("li $s1,0");
		}else
			pb.push_back("lw $s1,"+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");
		pb.push_back("addi $s2,$s1,"+to_string(symbolTable[(yyvsp[0].name)].address));
		pb.push_back("add $s2,$s2,$gp");
		pb.push_back("lw $s0,0($s2)");
		//sprintf(temp,"lw $s0,%llu($gp)",symbolTable[$1].address);
		//pb.push_back(temp);
		pb.push_back("addi $sp, $sp,-4"); 
		pb.push_back("sw $s0,0($sp)");
		
	}
#line 2323 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 751 "parser.y" /* yacc.c:1646  */
    {
		(yyval.iVal) = 123; 
		char temp[500];
		if(symbolTable[(yyvsp[-3].name)].TYPE != SEM_TYPE_VARIABLE_ARRAY_INT)
		{
			myerror("variable has not been declared properly!",10);
			
		}
		pb.push_back("lw $s0,0($sp)");
		pb.push_back("addi $sp, $sp,4"); 

		pb.push_back("li $s4, 4"); //4
		pb.push_back("mul $s0,$s0, $s4");

		pb.push_back("add $s1,$s0,$gp");

		pb.push_back("lw $s0,"+to_string(symbolTable[(yyvsp[-3].name)].address)+"($s1)");


		pb.push_back("addi $sp, $sp,-4"); 
		pb.push_back("sw $s0,0($sp)");
	}
#line 2350 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 773 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=-10;plusPlus((yyvsp[-1].name),1,1);}
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 774 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=-10;plusPlus((yyvsp[-1].name),-1,1);}
#line 2362 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 775 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=-10;plusPlusar((yyvsp[-4].name),1,1);}
#line 2368 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 776 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=-10;plusPlusar((yyvsp[-4].name),-1,1);}
#line 2374 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 777 "parser.y" /* yacc.c:1646  */
    {}
#line 2380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 782 "parser.y" /* yacc.c:1646  */
    {myerror("error after declaration!",30);}
#line 2386 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 786 "parser.y" /* yacc.c:1646  */
    {declare_IntArray((yyvsp[-3].name),(yyvsp[-1].iVal));}
#line 2392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 787 "parser.y" /* yacc.c:1646  */
    {myerror("; after array declaration is missed!",20);}
#line 2398 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 789 "parser.y" /* yacc.c:1646  */
    {myerror("; after array declaration is missed!",20);}
#line 2404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 792 "parser.y" /* yacc.c:1646  */
    {declare_IntVariable((yyvsp[0].name));}
#line 2410 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 792 "parser.y" /* yacc.c:1646  */
    {assignto((yyvsp[-3].name));}
#line 2416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 795 "parser.y" /* yacc.c:1646  */
    {declare_IntVariable((yyvsp[0].name));}
#line 2422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 799 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-2].name),0);}
#line 2428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 800 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-3].name),1,(yyvsp[-1].address));}
#line 2434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 801 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-5].name),2,(yyvsp[-3].address),(yyvsp[-1].address));}
#line 2440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 802 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-7].name),3,(yyvsp[-5].address),(yyvsp[-3].address),(yyvsp[-1].address));}
#line 2446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 803 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal)=functionCall((yyvsp[-9].name),4,(yyvsp[-7].address),(yyvsp[-5].address),(yyvsp[-3].address),(yyvsp[-1].address));}
#line 2452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 807 "parser.y" /* yacc.c:1646  */
    {}
#line 2458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 808 "parser.y" /* yacc.c:1646  */
    {declare_IntVariable((yyvsp[0].name));}
#line 2464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 812 "parser.y" /* yacc.c:1646  */
    { assignto((yyvsp[-3].name));}
#line 2470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 813 "parser.y" /* yacc.c:1646  */
    { myerror("; after assignment is missed!",20);}
#line 2476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 814 "parser.y" /* yacc.c:1646  */
    { assigntoar((yyvsp[-6].name));}
#line 2482 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 815 "parser.y" /* yacc.c:1646  */
    { myerror("; after assinment is missed!",20);}
#line 2488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 819 "parser.y" /* yacc.c:1646  */
    {
	pb.push_back("lw $v1, 0($sp)");
	pb.push_back("addi $sp, $sp,4");
	if((yyvsp[-1].address)!=-10)
		warning("useless epression!");
  }
#line 2499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 825 "parser.y" /* yacc.c:1646  */
    {myerror("; is missed!",20);}
#line 2505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 829 "parser.y" /* yacc.c:1646  */
    {returnHandle(lastScope);}
#line 2511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 830 "parser.y" /* yacc.c:1646  */
    {voidReturn(lastScope);}
#line 2517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 831 "parser.y" /* yacc.c:1646  */
    {myerror("probably ; is missed after return",20);}
#line 2523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 834 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.name),"int"); }
#line 2529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 835 "parser.y" /* yacc.c:1646  */
    {strcpy((yyval.name),"void");}
#line 2535 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2539 "parser.tab.c" /* yacc.c:1646  */
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
#line 837 "parser.y" /* yacc.c:1906  */



void yyerror(const char *s) {
 fprintf(stderr, "%s\n", s);
}
void help()
{
	printf("compiler help!\n\n\tenjoy own compiler!\n\n");
			cout<<"\tfirst argument is source file path\n";
			cout<<"\t--show enable some log in each compile step\n";
			cout<<"\t--pre first pre process the source then compile it"<<endl;
			cout<<"\t--def enable define output for processor"<<endl;
			cout<<"\t-p name of preProcessor c source output"<<endl;
			cout<<"\t-o name of mips code output"<<endl;
			cout<<"\t-h show help(this page!)"<<endl;

}
int main(int argc, char *argv[])
{
	char cmd[100];
	char def[10];
	strcpy(def," NoDef");
	pre=0;
	out=0;
	mid=0;
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
		if(strcmp("-p",argv[i])==0 && (i+1<argc))
		{
			mid=i+1;
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
		if(mid)
		{
			sprintf(cmd,"./pre %s %s %s",argv[1],argv[mid],def);
		}else
			sprintf(cmd,"./pre %s output_pre.c %s",argv[1],def);
		system(cmd);
		if(mid)
			yyin = fopen(argv[mid], "r");
		else
			yyin = fopen("output_pre.c", "r");
	}else
		yyin = fopen(argv[1], "r");
	if(out)
	{
		f1=fopen(argv[out],"w");
	}else
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

	/*initial codes */

	pb.push_back(".data");
    pb.push_back("err_string: .asciiz \"\\ndivide by zero error!\\n\"");
    pb.push_back("nextline_string: .asciiz \"\\n\"");
    pb.push_back(".text");
	/*pb.push_back("li $s0, 200");
	pb.push_back("sw $s0, 100($gp)");*/
	pb.push_back("li $s0, 0");
	pb.push_back("sw $s0, "+to_string(DYNAMIC_OFFSET_LOC)+"($gp)");

	/*finished!!*/
    if(!yyparse())
		printf("\nParsing complete\n");
	else
	{
		myerror("\nParsing failed\n",1);
	}
	int return_address;
	if(PC!=0)
	{
		return_address=pop();
		pb[return_address]="li $s0,"+to_string(MAIN_OFFSET);
		pb[return_address+1]="sw $s0, "+to_string(DYNAMIC_OFFSET_LOC)+"($gp)";
		pb[return_address+2]="jal main";
		pb[return_address+3]="li $v0, 17";
		pb[return_address+4]="lw $a0, 0($sp)";
		pb[return_address+5]="addi $sp, $sp,4";
		pb[return_address+6]="syscall";
	}	
	else{
		myerror("main function Not Found!",4);
		
	}
	if(ERROR_occurred)
		return -1;
	while(!instJump.empty())
	{
		int top=instJump.top();
		string ap="a"+to_string(top)+":";
		
		if (pb[top-1].rfind(ap, 0) != 0) {
			pb[top-1]="a"+to_string(top)+": "+pb[top-1];
		}
		instJump.pop();
	}
	
	printf("MIPS CODE is saved in output file!\n");
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

	if(verbose)
	{
		cout<<"starting program:"<<endl;
		if(out)
		{
			sprintf(cmd,"spim  -file %s",argv[out]);
			system(cmd);
		}
		else
			system("spim  -file output.mips");
	}
	
    return 0;
}
