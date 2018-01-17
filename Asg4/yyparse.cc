/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

// $Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void* yycalloc (size_t size);


/* Line 371 of yacc.c  */
#line 87 "yyparse.cc"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ROOT = 258,
     TOK_IDENT = 259,
     NUMBER = 260,
     TOK_VOID = 261,
     TOK_BOOL = 262,
     TOK_CHAR = 263,
     TOK_INT = 264,
     TOK_STRING = 265,
     TOK_RETURN = 266,
     TOK_IF = 267,
     TOK_ELSE = 268,
     TOK_WHILE = 269,
     TOK_FALSE = 270,
     TOK_TRUE = 271,
     TOK_NULL = 272,
     TOK_EQ = 273,
     TOK_LT = 274,
     TOK_GT = 275,
     TOK_GE = 276,
     TOK_LE = 277,
     TOK_NE = 278,
     TOK_INTCON = 279,
     TOK_CHARCON = 280,
     TOK_STRINGCON = 281,
     TOK_STRUCT = 282,
     TOK_ORD = 283,
     TOK_CHR = 284,
     TOK_ARRAY = 285,
     TOK_NEW = 286,
     TOK_ROOT = 287,
     TOK_FIELD = 288,
     TOK_DECLID = 289,
     TOK_TYPEID = 290,
     TOK_INDEX = 291,
     TOK_POS = 292,
     TOK_NEG = 293,
     TOK_CALL = 294,
     TOK_NEWARRAY = 295,
     TOK_NEWSTRING = 296,
     TOK_IFELSE = 297,
     TOK_RETURNVOID = 298,
     TOK_BLOCK = 299,
     TOK_VARDECL = 300,
     TOK_FUNCTION = 301,
     TOK_PARAMLIST = 302,
     TOK_PROTOTYPE = 303,
     POS = 304,
     NEG = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "yyparse.cc"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   622

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    54,     2,     2,
      58,    62,    52,    50,    63,    51,    57,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      45,    46,    47,    48,    64,    65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    13,    18,    23,    27,
      31,    34,    38,    40,    42,    44,    46,    51,    56,    61,
      66,    70,    73,    76,    80,    82,    85,    88,    91,    94,
      96,    98,   100,   102,   104,   107,   112,   118,   124,   132,
     136,   139,   142,   145,   149,   153,   157,   161,   165,   169,
     172,   176,   180,   184,   188,   192,   195,   198,   202,   204,
     206,   208,   210,   212,   214,   219,   225,   231,   235,   238,
     242,   246,   248,   253,   257,   259,   261,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      68,     0,    -1,    68,    69,    -1,    68,    73,    -1,    68,
      78,    -1,    -1,    27,     4,    59,    60,    -1,    27,     4,
      70,    60,    -1,    59,    71,    61,    -1,    70,    71,    61,
      -1,    72,     4,    -1,    72,    30,     4,    -1,     6,    -1,
       9,    -1,    10,    -1,    35,    -1,    75,    58,    62,    76,
      -1,    75,    58,    62,    61,    -1,    75,    74,    62,    61,
      -1,    75,    74,    62,    76,    -1,    74,    63,    75,    -1,
      58,    75,    -1,    72,     4,    -1,    72,    30,     4,    -1,
      61,    -1,    59,    60,    -1,    77,    60,    -1,    59,    78,
      -1,    77,    78,    -1,    76,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    61,    -1,    75,    49,    83,
      61,    -1,    14,    58,    83,    62,    78,    -1,    12,    58,
      83,    62,    78,    -1,    12,    58,    83,    62,    78,    13,
      78,    -1,    11,    83,    61,    -1,    11,    61,    -1,    29,
      83,    -1,    28,    83,    -1,    83,    18,    83,    -1,    83,
      23,    83,    -1,    83,    19,    83,    -1,    83,    20,    83,
      -1,    83,    22,    83,    -1,    83,    21,    83,    -1,    55,
      83,    -1,    83,    49,    83,    -1,    83,    50,    83,    -1,
      83,    51,    83,    -1,    83,    52,    83,    -1,    83,    53,
      83,    -1,    50,    83,    -1,    51,    83,    -1,    58,    83,
      62,    -1,     4,    -1,     5,    -1,    84,    -1,    85,    -1,
      87,    -1,    88,    -1,    31,     4,    58,    62,    -1,    31,
      10,    58,    83,    62,    -1,    31,    72,    56,    83,    66,
      -1,     4,    58,    62,    -1,    86,    62,    -1,     4,    58,
      83,    -1,    86,    63,    83,    -1,     4,    -1,    83,    56,
      83,    66,    -1,    83,    57,    33,    -1,    24,    -1,    25,
      -1,    26,    -1,    17,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    62,    63,    64,    67,    68,    71,    72,
      75,    76,    79,    80,    81,    82,    85,    86,    87,    88,
      91,    92,    95,    96,    99,   100,   101,   104,   105,   108,
     109,   110,   111,   112,   113,   116,   119,   122,   123,   126,
     127,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   156,   157,   158,   160,   161,   163,
     164,   167,   168,   170,   172,   173,   174,   175
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ROOT", "TOK_IDENT", "NUMBER",
  "TOK_VOID", "TOK_BOOL", "TOK_CHAR", "TOK_INT", "TOK_STRING",
  "TOK_RETURN", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_FALSE", "TOK_TRUE",
  "TOK_NULL", "TOK_EQ", "TOK_LT", "TOK_GT", "TOK_GE", "TOK_LE", "TOK_NE",
  "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON", "TOK_STRUCT", "TOK_ORD",
  "TOK_CHR", "TOK_ARRAY", "TOK_NEW", "TOK_ROOT", "TOK_FIELD", "TOK_DECLID",
  "TOK_TYPEID", "TOK_INDEX", "TOK_POS", "TOK_NEG", "TOK_CALL",
  "TOK_NEWARRAY", "TOK_NEWSTRING", "TOK_IFELSE", "TOK_RETURNVOID",
  "TOK_BLOCK", "TOK_VARDECL", "TOK_FUNCTION", "TOK_PARAMLIST",
  "TOK_PROTOTYPE", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['",
  "'.'", "'('", "'{'", "'}'", "';'", "')'", "','", "POS", "NEG", "']'",
  "$accept", "program", "structde", "s_stmts", "fielddec", "basetype",
  "func", "paramli", "identdec", "block", "b_stmts", "stmt", "vardecl",
  "while", "ifelse", "return", "expr", "allocator", "call", "c_args",
  "variable", "constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    61,
      43,    45,    42,    47,    37,    33,    91,    46,    40,   123,
     125,    59,    41,    44,   304,   305,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    73,    73,
      74,    74,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    79,    80,    81,    81,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    87,    88,    88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     4,     4,     3,     3,
       2,     3,     1,     1,     1,     1,     4,     4,     4,     4,
       3,     2,     2,     3,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     2,     4,     5,     5,     7,     3,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     3,     2,     3,
       3,     1,     4,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     1,    58,    59,    12,    13,    14,     0,     0,
       0,    77,    74,    75,    76,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,    24,     2,     0,     3,     0,
      29,     0,     4,    30,    31,    32,    33,     0,    60,    61,
       0,    62,    63,     0,    40,     0,     0,     0,     0,    42,
      41,     0,    14,     0,    55,    56,    49,     0,    25,     0,
      27,    22,     0,     0,     0,     0,    26,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    68,     0,    67,    69,    39,     0,     0,     0,
       0,     0,     0,     0,    57,    23,     0,     0,    21,     0,
       0,    43,    45,    46,    48,    47,    44,    50,    51,    52,
      53,    54,     0,    73,    70,     0,     0,     6,     0,     0,
       7,     0,    64,     0,     0,    35,    17,    16,    18,    19,
      20,    72,    37,    36,     8,    10,     0,     9,    65,    66,
       0,    11,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    26,    90,   118,    27,    28,    65,    59,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -57
static const yytype_int16 yypact[] =
{
     -57,    93,   -57,   -56,   -57,   -57,   -57,   -57,   282,   -43,
     -37,   -57,   -57,   -57,   -57,    22,   310,   310,    78,   -57,
     310,   310,   310,   310,   151,   -57,   -57,     5,   -57,   -27,
     -57,   209,   -57,   -57,   -57,   -57,   -57,   495,   -57,   -57,
     -15,   -57,   -57,    -1,   -57,   508,   310,   310,   -25,   565,
     565,     1,    21,     7,   565,   565,   -18,   375,   -57,    34,
     -57,   -57,    82,   310,    23,    52,   -57,   -57,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
      62,   -57,   -57,   310,   -57,   565,   -57,   391,   436,     2,
      46,    39,   310,   310,   -57,   -57,   552,    -8,   -57,    35,
     102,    79,    79,    79,    79,    79,    79,   565,   -11,   -11,
     -18,   -18,   326,   -57,   565,   267,   267,   -57,    48,     6,
     -57,    65,   -57,   450,   351,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   114,   -57,   -57,   -57,   129,   -57,   -57,   -57,
     267,   -57,   -57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   -57,    44,   -12,   -57,   -57,     0,    26,
     -57,   -24,   -57,   -57,   -57,   -57,    -3,   -57,   -57,   -57,
     -57,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,    29,    43,     3,     4,    45,    53,    67,     5,    61,
     135,     6,     7,    49,    50,    46,    11,    54,    55,    56,
      57,    47,    63,    12,    13,    14,    48,    16,    17,     5,
      18,    64,     6,     7,    89,    62,   136,    19,    79,    80,
      85,    77,    78,    87,    88,    79,    80,    82,    83,    20,
      21,    24,     5,   126,    22,     6,     7,    23,    19,    91,
      96,    84,   117,    93,    98,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   119,   119,    92,
     114,    19,    51,    63,     5,    97,    95,     6,    52,   123,
     124,   132,   133,     2,    24,   113,   128,     3,     4,     5,
     130,   122,     6,     7,     8,     9,   120,    10,     5,   134,
      11,     6,     7,    19,    99,   100,   142,    12,    13,    14,
      15,    16,    17,   127,    18,   129,   137,   140,    19,    75,
      76,    77,    78,   141,   121,    79,    80,    19,     0,     0,
       0,     0,     0,    20,    21,     0,     0,     0,    22,     0,
       0,    23,    24,     0,    25,     3,     4,     5,     0,     0,
       6,     7,     8,     9,     0,    10,     0,     0,    11,     0,
       0,     0,     0,     0,     0,    12,    13,    14,     0,    16,
      17,     0,    18,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,    22,     0,     0,    23,
      24,    58,    25,     3,     4,     5,     0,     0,     6,     7,
       8,     9,     0,    10,     0,     0,    11,     0,     0,     0,
       0,     0,     0,    12,    13,    14,     0,    16,    17,     0,
      18,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      21,     0,     0,     0,    22,     0,     0,    23,    24,    66,
      25,     3,     4,     5,     0,     0,     6,     7,     8,     9,
       0,    10,     0,     0,    11,     0,     3,     4,     0,     0,
       0,    12,    13,    14,     0,    16,    17,     0,    18,    11,
       0,     0,    19,     0,     0,     0,    12,    13,    14,     0,
      16,    17,     0,    18,     3,     4,     0,    20,    21,     0,
       0,     0,    22,     0,     0,    23,    24,    11,    25,     0,
       0,     0,    20,    21,    12,    13,    14,    22,    16,    17,
      23,    18,     0,    44,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    21,     0,     0,     0,    22,     0,     0,    23,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,   131,    68,    69,    70,    71,    72,    73,     0,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    68,
      69,    70,    71,    72,    73,     0,     0,   139,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,     0,    94,     0,     0,
      74,    75,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,     0,   115,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,     0,   116,    74,
      75,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,     0,   138,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    74,    75,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    86,
      68,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,   125,    74,    75,    76,    77,    78,     0,
       0,    79,    80
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      24,     1,    58,     4,     5,     8,    18,    31,     6,     4,
       4,     9,    10,    16,    17,    58,    17,    20,    21,    22,
      23,    58,    49,    24,    25,    26,     4,    28,    29,     6,
      31,    58,     9,    10,    59,    30,    30,    35,    56,    57,
      43,    52,    53,    46,    47,    56,    57,    62,    63,    50,
      51,    59,     6,    61,    55,     9,    10,    58,    35,    58,
      63,    62,    60,    56,    64,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    89,    90,    58,
      83,    35,     4,    49,     6,    62,     4,     9,    10,    92,
      93,   115,   116,     0,    59,    33,    61,     4,     5,     6,
     100,    62,     9,    10,    11,    12,    60,    14,     6,    61,
      17,     9,    10,    35,    62,    63,   140,    24,    25,    26,
      27,    28,    29,    97,    31,    99,    61,    13,    35,    50,
      51,    52,    53,     4,    90,    56,    57,    35,    -1,    -1,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    61,     4,     5,     6,    -1,    -1,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    28,
      29,    -1,    31,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,    58,
      59,    60,    61,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    -1,    28,    29,    -1,
      31,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,    60,
      61,     4,     5,     6,    -1,    -1,     9,    10,    11,    12,
      -1,    14,    -1,    -1,    17,    -1,     4,     5,    -1,    -1,
      -1,    24,    25,    26,    -1,    28,    29,    -1,    31,    17,
      -1,    -1,    35,    -1,    -1,    -1,    24,    25,    26,    -1,
      28,    29,    -1,    31,     4,     5,    -1,    50,    51,    -1,
      -1,    -1,    55,    -1,    -1,    58,    59,    17,    61,    -1,
      -1,    -1,    50,    51,    24,    25,    26,    55,    28,    29,
      58,    31,    -1,    61,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    55,    -1,    -1,    58,    18,
      19,    20,    21,    22,    23,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    18,    19,    20,    21,    22,    23,    -1,
      49,    50,    51,    52,    53,    -1,    -1,    56,    57,    18,
      19,    20,    21,    22,    23,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    -1,    56,    57,    -1,
      -1,    -1,    -1,    62,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    62,    49,
      50,    51,    52,    53,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    62,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    61,    49,    50,    51,
      52,    53,    -1,    -1,    56,    57,    -1,    -1,    -1,    61,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    -1,    56,    57,
      -1,    -1,    -1,    61,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,     0,     4,     5,     6,     9,    10,    11,    12,
      14,    17,    24,    25,    26,    27,    28,    29,    31,    35,
      50,    51,    55,    58,    59,    61,    69,    72,    73,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    58,    61,    83,    58,    58,     4,    83,
      83,     4,    10,    72,    83,    83,    83,    83,    60,    75,
      78,     4,    30,    49,    58,    74,    60,    78,    18,    19,
      20,    21,    22,    23,    49,    50,    51,    52,    53,    56,
      57,    61,    62,    63,    62,    83,    61,    83,    83,    59,
      70,    58,    58,    56,    62,     4,    83,    62,    75,    62,
      63,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    33,    83,    62,    62,    60,    71,    72,
      60,    71,    62,    83,    83,    61,    61,    76,    61,    76,
      75,    66,    78,    78,    61,     4,    30,    61,    62,    66,
      13,     4,    78
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* ROOT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1343 "yyparse.cc"
        break;
      case 4: /* TOK_IDENT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1350 "yyparse.cc"
        break;
      case 5: /* NUMBER */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1357 "yyparse.cc"
        break;
      case 6: /* TOK_VOID */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1364 "yyparse.cc"
        break;
      case 7: /* TOK_BOOL */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1371 "yyparse.cc"
        break;
      case 8: /* TOK_CHAR */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1378 "yyparse.cc"
        break;
      case 9: /* TOK_INT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1385 "yyparse.cc"
        break;
      case 10: /* TOK_STRING */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1392 "yyparse.cc"
        break;
      case 11: /* TOK_RETURN */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1399 "yyparse.cc"
        break;
      case 12: /* TOK_IF */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1406 "yyparse.cc"
        break;
      case 13: /* TOK_ELSE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1413 "yyparse.cc"
        break;
      case 14: /* TOK_WHILE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1420 "yyparse.cc"
        break;
      case 15: /* TOK_FALSE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1427 "yyparse.cc"
        break;
      case 16: /* TOK_TRUE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1434 "yyparse.cc"
        break;
      case 17: /* TOK_NULL */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1441 "yyparse.cc"
        break;
      case 18: /* TOK_EQ */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1448 "yyparse.cc"
        break;
      case 19: /* TOK_LT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1455 "yyparse.cc"
        break;
      case 20: /* TOK_GT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1462 "yyparse.cc"
        break;
      case 21: /* TOK_GE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1469 "yyparse.cc"
        break;
      case 22: /* TOK_LE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1476 "yyparse.cc"
        break;
      case 23: /* TOK_NE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1483 "yyparse.cc"
        break;
      case 24: /* TOK_INTCON */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1490 "yyparse.cc"
        break;
      case 25: /* TOK_CHARCON */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1497 "yyparse.cc"
        break;
      case 26: /* TOK_STRINGCON */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1504 "yyparse.cc"
        break;
      case 27: /* TOK_STRUCT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1511 "yyparse.cc"
        break;
      case 28: /* TOK_ORD */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1518 "yyparse.cc"
        break;
      case 29: /* TOK_CHR */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1525 "yyparse.cc"
        break;
      case 30: /* TOK_ARRAY */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1532 "yyparse.cc"
        break;
      case 31: /* TOK_NEW */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1539 "yyparse.cc"
        break;
      case 32: /* TOK_ROOT */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1546 "yyparse.cc"
        break;
      case 33: /* TOK_FIELD */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1553 "yyparse.cc"
        break;
      case 34: /* TOK_DECLID */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1560 "yyparse.cc"
        break;
      case 35: /* TOK_TYPEID */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1567 "yyparse.cc"
        break;
      case 36: /* TOK_INDEX */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1574 "yyparse.cc"
        break;
      case 37: /* TOK_POS */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1581 "yyparse.cc"
        break;
      case 38: /* TOK_NEG */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1588 "yyparse.cc"
        break;
      case 39: /* TOK_CALL */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1595 "yyparse.cc"
        break;
      case 40: /* TOK_NEWARRAY */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1602 "yyparse.cc"
        break;
      case 41: /* TOK_NEWSTRING */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1609 "yyparse.cc"
        break;
      case 42: /* TOK_IFELSE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1616 "yyparse.cc"
        break;
      case 43: /* TOK_RETURNVOID */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1623 "yyparse.cc"
        break;
      case 44: /* TOK_BLOCK */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1630 "yyparse.cc"
        break;
      case 45: /* TOK_VARDECL */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1637 "yyparse.cc"
        break;
      case 46: /* TOK_FUNCTION */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1644 "yyparse.cc"
        break;
      case 47: /* TOK_PARAMLIST */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1651 "yyparse.cc"
        break;
      case 48: /* TOK_PROTOTYPE */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1658 "yyparse.cc"
        break;
      case 49: /* '=' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1665 "yyparse.cc"
        break;
      case 50: /* '+' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1672 "yyparse.cc"
        break;
      case 51: /* '-' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1679 "yyparse.cc"
        break;
      case 52: /* '*' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1686 "yyparse.cc"
        break;
      case 53: /* '/' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1693 "yyparse.cc"
        break;
      case 54: /* '%' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1700 "yyparse.cc"
        break;
      case 55: /* '!' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1707 "yyparse.cc"
        break;
      case 56: /* '[' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1714 "yyparse.cc"
        break;
      case 57: /* '.' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1721 "yyparse.cc"
        break;
      case 58: /* '(' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1728 "yyparse.cc"
        break;
      case 59: /* '{' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1735 "yyparse.cc"
        break;
      case 60: /* '}' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1742 "yyparse.cc"
        break;
      case 61: /* ';' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1749 "yyparse.cc"
        break;
      case 62: /* ')' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1756 "yyparse.cc"
        break;
      case 63: /* ',' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1763 "yyparse.cc"
        break;
      case 64: /* POS */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1770 "yyparse.cc"
        break;
      case 65: /* NEG */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1777 "yyparse.cc"
        break;
      case 66: /* ']' */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1784 "yyparse.cc"
        break;
      case 68: /* program */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1791 "yyparse.cc"
        break;
      case 69: /* structde */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1798 "yyparse.cc"
        break;
      case 70: /* s_stmts */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1805 "yyparse.cc"
        break;
      case 71: /* fielddec */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1812 "yyparse.cc"
        break;
      case 72: /* basetype */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1819 "yyparse.cc"
        break;
      case 73: /* func */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1826 "yyparse.cc"
        break;
      case 74: /* paramli */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1833 "yyparse.cc"
        break;
      case 75: /* identdec */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1840 "yyparse.cc"
        break;
      case 76: /* block */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1847 "yyparse.cc"
        break;
      case 77: /* b_stmts */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1854 "yyparse.cc"
        break;
      case 78: /* stmt */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1861 "yyparse.cc"
        break;
      case 79: /* vardecl */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1868 "yyparse.cc"
        break;
      case 80: /* while */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1875 "yyparse.cc"
        break;
      case 81: /* ifelse */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1882 "yyparse.cc"
        break;
      case 82: /* return */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1889 "yyparse.cc"
        break;
      case 83: /* expr */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1896 "yyparse.cc"
        break;
      case 84: /* allocator */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1903 "yyparse.cc"
        break;
      case 85: /* call */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1910 "yyparse.cc"
        break;
      case 86: /* c_args */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1917 "yyparse.cc"
        break;
      case 87: /* variable */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1924 "yyparse.cc"
        break;
      case 88: /* constant */
/* Line 1398 of yacc.c  */
#line 26 "parser.y"
        { error_destructor ((*yyvaluep)); };
/* Line 1398 of yacc.c  */
#line 1931 "yyparse.cc"
        break;

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

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
/* Line 1792 of yacc.c  */
#line 61 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 62 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 63 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    { (yyval) = new_parseroot(); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {change_sym((yyvsp[(2) - (4)]),TOK_TYPEID); (yyval) = adopt1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));free_ast2((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {change_sym((yyvsp[(2) - (4)]),TOK_TYPEID); (yyval) = adopt2((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]));free_ast((yyvsp[(4) - (4)]));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 71 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]));free_ast((yyvsp[(3) - (3)]));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]));free_ast((yyvsp[(3) - (3)]));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    {change_sym((yyvsp[(2) - (2)]),TOK_FIELD); (yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 76 "parser.y"
    {change_sym((yyvsp[(3) - (3)]),TOK_FIELD); (yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 85 "parser.y"
    { (yyval) = adopt3(new_astree(TOK_FUNCTION,(yyvsp[(1) - (4)])->filenr,(yyvsp[(1) - (4)])->linenr,(yyvsp[(1) - (4)])->offset,""),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));free_ast((yyvsp[(3) - (4)]));}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    { (yyval) = adopt2(new_astree(TOK_PROTOTYPE,(yyvsp[(1) - (4)])->filenr,(yyvsp[(1) - (4)])->linenr,(yyvsp[(1) - (4)])->offset,""),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));free_ast2((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    { (yyval) = adopt2(new_astree(TOK_PROTOTYPE,(yyvsp[(1) - (4)])->filenr,(yyvsp[(1) - (4)])->linenr,(yyvsp[(1) - (4)])->offset,""),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));free_ast2((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    { (yyval) = adopt3(new_astree(TOK_FUNCTION,(yyvsp[(1) - (4)])->filenr,(yyvsp[(1) - (4)])->linenr,(yyvsp[(1) - (4)])->offset,""),(yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(4) - (4)]));free_ast((yyvsp[(3) - (4)]));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    { (yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));free_ast((yyvsp[(2) - (3)]));}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    { (yyval) = adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_PARAMLIST);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    {change_sym((yyvsp[(2) - (2)]),TOK_DECLID);(yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {change_sym((yyvsp[(3) - (3)]),TOK_DECLID);(yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    {change_sym((yyvsp[(1) - (2)]),TOK_BLOCK);(yyval) = (yyvsp[(1) - (2)]);free_ast((yyvsp[(2) - (2)]));}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 101 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]); free_ast((yyvsp[(2) - (2)]));}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 104 "parser.y"
    {(yyval) = adopt1sym((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]),TOK_BLOCK);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {(yyval) = adopt1((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]);free_ast((yyvsp[(2) - (2)]));}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { (yyval) = adopt1(adopt1sym((yyvsp[(2) - (4)]),(yyvsp[(1) - (4)]),TOK_VARDECL),(yyvsp[(3) - (4)]));free_ast((yyvsp[(4) - (4)]));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 119 "parser.y"
    {(yyval) = adopt2((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));free_ast2((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));free_ast2((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)]));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    { (yyval) = adopt2(adopt1sym((yyvsp[(1) - (7)]),(yyvsp[(3) - (7)]),TOK_IFELSE),(yyvsp[(5) - (7)]),(yyvsp[(7) - (7)]));free_ast2((yyvsp[(2) - (7)]),(yyvsp[(4) - (7)]));free_ast((yyvsp[(6) - (7)]));}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));free_ast((yyvsp[(3) - (3)]));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    { change_sym((yyvsp[(1) - (2)]),TOK_RETURNVOID);(yyval) = (yyvsp[(1) - (2)]);free_ast((yyvsp[(2) - (2)]));}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 136 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 143 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), POS); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    { (yyval) = adopt1sym ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]), NEG); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    { free_ast2 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 148 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {change_sym((yyvsp[(2) - (4)]),TOK_TYPEID);(yyval) = adopt1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]));free_ast2((yyvsp[(3) - (4)]),(yyvsp[(4) - (4)]));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {(yyval) = adopt1sym((yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]),TOK_NEWSTRING);free_ast((yyvsp[(2) - (5)]));free_ast2((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 158 "parser.y"
    {(yyval) = adopt1(adopt1sym((yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),TOK_NEWARRAY),(yyvsp[(4) - (5)])); free_ast((yyvsp[(3) - (5)]));free_ast((yyvsp[(5) - (5)])); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 160 "parser.y"
    {(yyval) = adopt1(adopt1sym((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),TOK_CALL),(yyvsp[(3) - (3)]));}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)]); free_ast((yyvsp[(2) - (2)]));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    {(yyval) = adopt1(adopt1sym((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),TOK_CALL),(yyvsp[(3) - (3)]));}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    {(yyval) = adopt1((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); free_ast((yyvsp[(2) - (3)]));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    {(yyval) = adopt1(adopt1sym((yyvsp[(2) - (4)]),(yyvsp[(1) - (4)]),TOK_INDEX),(yyvsp[(3) - (4)]));
							free_ast((yyvsp[(4) - (4)]));}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    {change_sym((yyvsp[(2) - (3)]),TOK_FIELD);(yyval) = adopt2((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;


/* Line 1792 of yacc.c  */
#line 2678 "yyparse.cc"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 177 "parser.y"


const char* get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

RCSC("$Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $")

