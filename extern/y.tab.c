/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     XINTEGER = 258,
     TDOUBLE = 259,
     TBOOL = 260,
     IDENTIFIER = 261,
     TSTRING = 262,
     OPERATOR_X__ = 263,
     OP_CALC = 264,
     AND_OP = 265,
     OR_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     FUNC_OP = 271,
     INC_OP = 272,
     DEC_OP = 273,
     FUNC_CALL = 274,
     VAR_DECLAR = 275,
     RESTRICT = 276,
     THIS = 277,
     EXTENDS = 278,
     ARRAY_ELE = 279,
     XTRY = 280,
     XCATCH = 281,
     ADD_EQ = 282,
     SUB_EQ = 283,
     MUL_EQ = 284,
     DIV_EQ = 285,
     LEFT_SHIFT = 286,
     RIGHT_SHIFT = 287,
     MOD_EQ = 288,
     XPUBLIC = 289,
     XSET = 290,
     XIS = 291,
     SCOPE = 292,
     SCOPE_FUNC_CALL = 293,
     REQUIRE = 294,
     REQUIRE_ONCE = 295,
     REF = 296,
     XCONTINUE = 297,
     XCONST = 298,
     XLOCAL = 299,
     AUTO = 300,
     IF = 301,
     ELSE = 302,
     WHILE = 303,
     FOR = 304,
     DELETE = 305,
     BREAK = 306,
     RETURN = 307,
     SWITCH = 308,
     CASE = 309,
     DEFAULT = 310,
     CASE_LIST = 311,
     CLAXX_BODY = 312,
     NEW = 313,
     CLAXX_MEMBER = 314,
     CLAXX_FUNC_CALL = 315,
     XNULL = 316,
     XINCLUDE = 317,
     ANNOTATION = 318,
     NONASSOC = 319,
     IFX = 320,
     PRIORITY3 = 321,
     PRIORITY2 = 322,
     PRIORITY1 = 323,
     UMINUS = 324
   };
#endif
/* Tokens.  */
#define XINTEGER 258
#define TDOUBLE 259
#define TBOOL 260
#define IDENTIFIER 261
#define TSTRING 262
#define OPERATOR_X__ 263
#define OP_CALC 264
#define AND_OP 265
#define OR_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define FUNC_OP 271
#define INC_OP 272
#define DEC_OP 273
#define FUNC_CALL 274
#define VAR_DECLAR 275
#define RESTRICT 276
#define THIS 277
#define EXTENDS 278
#define ARRAY_ELE 279
#define XTRY 280
#define XCATCH 281
#define ADD_EQ 282
#define SUB_EQ 283
#define MUL_EQ 284
#define DIV_EQ 285
#define LEFT_SHIFT 286
#define RIGHT_SHIFT 287
#define MOD_EQ 288
#define XPUBLIC 289
#define XSET 290
#define XIS 291
#define SCOPE 292
#define SCOPE_FUNC_CALL 293
#define REQUIRE 294
#define REQUIRE_ONCE 295
#define REF 296
#define XCONTINUE 297
#define XCONST 298
#define XLOCAL 299
#define AUTO 300
#define IF 301
#define ELSE 302
#define WHILE 303
#define FOR 304
#define DELETE 305
#define BREAK 306
#define RETURN 307
#define SWITCH 308
#define CASE 309
#define DEFAULT 310
#define CASE_LIST 311
#define CLAXX_BODY 312
#define NEW 313
#define CLAXX_MEMBER 314
#define CLAXX_FUNC_CALL 315
#define XNULL 316
#define XINCLUDE 317
#define ANNOTATION 318
#define NONASSOC 319
#define IFX 320
#define PRIORITY3 321
#define PRIORITY2 322
#define PRIORITY1 323
#define UMINUS 324




/* Copy the first part of user declarations.  */
#line 1 "a.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

extern int getParseLineNo();
extern int column; 
extern char * yytext;

char *namespaceNameCat(char *,char *);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "a.y"
{
 int intValue;
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
}
/* Line 193 of yacc.c.  */
#line 265 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 278 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1869

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  243
/* YYNRULES -- Number of states.  */
#define YYNSTATES  475

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,    94,    77,    70,     2,
      80,    81,    75,    73,    66,    74,    84,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,    89,
      72,    67,    71,     2,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,    68,    91,    79,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    85,    86,    87,    88
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    18,
      20,    22,    25,    28,    31,    35,    40,    46,    54,    56,
      58,    60,    63,    65,    67,    69,    72,    74,    77,    80,
      83,    86,    89,    94,    96,   100,   105,   111,   117,   124,
     130,   137,   144,   152,   153,   156,   158,   161,   163,   166,
     168,   170,   174,   181,   185,   189,   193,   197,   204,   208,
     215,   222,   232,   239,   246,   250,   258,   265,   272,   280,
     286,   292,   296,   300,   301,   305,   307,   311,   312,   315,
     316,   319,   323,   329,   336,   342,   349,   355,   362,   364,
     366,   372,   380,   388,   390,   393,   398,   402,   408,   418,
     419,   421,   423,   425,   427,   429,   431,   434,   436,   438,
     440,   442,   444,   446,   448,   451,   453,   455,   458,   463,
     468,   473,   475,   480,   482,   486,   490,   491,   493,   495,
     499,   501,   503,   505,   507,   509,   511,   513,   515,   517,
     519,   521,   523,   525,   529,   531,   533,   535,   539,   543,
     547,   551,   555,   559,   563,   567,   571,   574,   578,   582,
     584,   586,   588,   590,   594,   600,   602,   604,   606,   608,
     611,   614,   616,   618,   620,   622,   624,   626,   628,   630,
     632,   634,   636,   638,   641,   645,   649,   653,   657,   661,
     665,   669,   673,   677,   680,   683,   686,   689,   691,   693,
     695,   697,   699,   701,   703,   705,   707,   709,   711,   713,
     715,   717,   719,   721,   723,   725,   727,   729,   731,   733,
     735,   737,   739,   743,   747,   751,   755,   760,   765,   770,
     775,   780,   785,   790,   795,   800,   804,   806,   808,   810,
     814,   818,   822,   826
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      96,     0,    -1,    97,    -1,    97,    98,    -1,    -1,    89,
      -1,   102,    -1,   126,    -1,   132,    89,    -1,    99,    -1,
     100,    -1,    39,   153,    -1,    40,   153,    -1,    62,   153,
      -1,    41,   109,    89,    -1,    25,    90,   124,    91,    -1,
      25,    90,   124,    91,   101,    -1,    26,    80,   149,    81,
      90,   124,    91,    -1,   119,    -1,   125,    -1,   110,    -1,
     108,    89,    -1,   106,    -1,   107,    -1,   103,    -1,    92,
     110,    -1,   105,    -1,   104,   105,    -1,    92,     6,    -1,
      43,   125,    -1,    44,   125,    -1,    44,   110,    -1,    35,
      34,    67,   109,    -1,     6,    -1,   109,    84,     6,    -1,
       6,   111,    90,    91,    -1,     6,   111,    90,   112,    91,
      -1,    45,     6,   111,    90,    91,    -1,    45,     6,   111,
      90,   112,    91,    -1,   104,     6,   111,    90,    91,    -1,
     104,     6,   111,    90,   112,    91,    -1,   104,    45,     6,
     111,    90,    91,    -1,   104,    45,     6,   111,    90,   112,
      91,    -1,    -1,    23,     6,    -1,   113,    -1,   112,   113,
      -1,   125,    -1,   162,    89,    -1,   119,    -1,    22,    -1,
      22,    84,   149,    -1,    22,    84,   149,    80,   139,    81,
      -1,    22,    84,   149,    -1,    22,    84,   116,    -1,   149,
      84,   149,    -1,   117,    84,   149,    -1,     6,    80,   139,
      81,    84,   149,    -1,   116,    84,   149,    -1,   149,    84,
     149,    80,   139,    81,    -1,   164,    84,   149,    80,   139,
      81,    -1,     6,    80,   139,    81,    84,   149,    80,   139,
      81,    -1,   116,    84,   149,    80,   139,    81,    -1,   117,
      84,   149,    80,   139,    81,    -1,   149,    37,   149,    -1,
      79,     6,    16,   122,    90,   124,    91,    -1,     6,    16,
     122,    90,   124,    91,    -1,     8,    16,   122,    90,   124,
      91,    -1,    80,   123,    81,    16,    90,   124,    91,    -1,
       6,    16,    90,   124,    91,    -1,   121,    16,    90,   124,
      91,    -1,     6,    66,     6,    -1,   121,    66,     6,    -1,
      -1,    80,   123,    81,    -1,     6,    -1,   123,    66,     6,
      -1,    -1,   124,    98,    -1,    -1,   149,    89,    -1,   149,
      66,   125,    -1,     6,    82,     3,    83,    89,    -1,     6,
      82,     3,    83,    66,   125,    -1,     6,    82,     6,    83,
      89,    -1,     6,    82,     6,    83,    66,   125,    -1,     6,
      82,   136,    83,    89,    -1,     6,    82,   136,    83,    66,
     125,    -1,   127,    -1,   130,    -1,    46,    80,   157,    81,
     142,    -1,    46,    80,   157,    81,   142,    47,   142,    -1,
      53,    80,   149,    81,    90,   128,    91,    -1,   129,    -1,
     128,   129,    -1,    54,   151,    93,   124,    -1,    55,    93,
     124,    -1,    48,    80,   157,    81,   142,    -1,    49,    80,
     131,    89,   157,    89,   131,    81,   142,    -1,    -1,   166,
      -1,   125,    -1,   159,    -1,   133,    -1,   166,    -1,   136,
      -1,    50,     6,    -1,   135,    -1,   148,    -1,   134,    -1,
      42,    -1,   137,    -1,   159,    -1,    21,    -1,    21,   150,
      -1,    51,    -1,    52,    -1,    52,   160,    -1,    52,    90,
     140,    91,    -1,   164,    80,   139,    81,    -1,     6,    80,
     139,    81,    -1,   117,    -1,   118,    80,   139,    81,    -1,
     138,    -1,   136,    68,   138,    -1,   136,    68,   136,    -1,
      -1,   140,    -1,   141,    -1,   140,    66,   141,    -1,   120,
      -1,   150,    -1,   151,    -1,     6,    -1,   153,    -1,   152,
      -1,   136,    -1,   145,    -1,   164,    -1,   116,    -1,   118,
      -1,   148,    -1,    94,    -1,    90,   124,    91,    -1,    98,
      -1,   151,    -1,   144,    -1,    80,   161,    81,    -1,   147,
      73,   147,    -1,   147,    74,   147,    -1,   147,    75,   147,
      -1,   147,    76,   147,    -1,   147,    77,   147,    -1,   146,
      70,   146,    -1,   146,    68,   146,    -1,   146,    69,   146,
      -1,    79,   146,    -1,   146,    31,   146,    -1,   146,    32,
     146,    -1,     3,    -1,   149,    -1,   161,    -1,   145,    -1,
      80,   145,    81,    -1,    58,   149,    80,   139,    81,    -1,
       6,    -1,     5,    -1,     4,    -1,     3,    -1,    74,   143,
      -1,    74,   149,    -1,     7,    -1,    61,    -1,   149,    -1,
     136,    -1,   116,    -1,   114,    -1,   161,    -1,   145,    -1,
     150,    -1,   154,    -1,   156,    -1,   158,    -1,    78,   155,
      -1,   156,    71,   156,    -1,   156,    72,   156,    -1,   156,
      12,   156,    -1,   156,    13,   156,    -1,   156,    14,   156,
      -1,   156,    15,   156,    -1,   157,    10,   157,    -1,   157,
      11,   157,    -1,   149,    36,   149,    -1,    17,   149,    -1,
      18,   149,    -1,   149,    17,    -1,   149,    18,    -1,   151,
      -1,   152,    -1,   150,    -1,   145,    -1,   136,    -1,   120,
      -1,   149,    -1,   153,    -1,   159,    -1,   148,    -1,   116,
      -1,   154,    -1,   114,    -1,   164,    -1,   118,    -1,   151,
      -1,   152,    -1,   153,    -1,   136,    -1,   149,    -1,   159,
      -1,   116,    -1,   118,    -1,   114,    -1,   164,    -1,   149,
      67,   160,    -1,   149,    67,   162,    -1,   116,    67,   160,
      -1,   115,    67,   160,    -1,     6,    82,     3,    83,    -1,
       6,    82,     6,    83,    -1,     6,    82,     7,    83,    -1,
     116,    82,     3,    83,    -1,   116,    82,     6,    83,    -1,
     116,    82,     7,    83,    -1,   136,    82,     3,    83,    -1,
     136,    82,     6,    83,    -1,   136,    82,     7,    83,    -1,
     164,    67,   160,    -1,   162,    -1,   163,    -1,   165,    -1,
     149,    27,   161,    -1,   149,    28,   161,    -1,   149,    29,
     161,    -1,   149,    30,   161,    -1,   149,    33,   161,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    83,    84,    87,    88,    89,    90,    91,
      92,    97,    98,    99,   100,   105,   106,   110,   115,   116,
     117,   118,   119,   120,   121,   126,   130,   131,   135,   140,
     145,   146,   151,   155,   156,   161,   162,   163,   164,   165,
     166,   167,   168,   173,   174,   179,   180,   184,   185,   186,
     191,   192,   194,   199,   200,   205,   206,   207,   208,   213,
     214,   215,   216,   217,   222,   228,   229,   230,   235,   236,
     237,   241,   242,   246,   247,   251,   252,   253,   257,   258,
     263,   264,   265,   266,   267,   268,   269,   270,   275,   276,
     281,   282,   283,   287,   288,   292,   293,   297,   298,   303,
     304,   305,   306,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   324,   329,   330,   334,   335,   336,   337,   342,
     343,   344,   345,   349,   350,   354,   358,   359,   363,   364,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   384,   385,   391,   392,   397,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   418,
     419,   424,   426,   427,   432,   436,   440,   444,   445,   449,
     450,   454,   458,   462,   463,   464,   465,   470,   471,   472,
     473,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   493,   498,   499,   500,   501,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   539,   540,   544,   545,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   564,   569,   570,   571,   572,
     573,   574,   575,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "XINTEGER", "TDOUBLE", "TBOOL",
  "IDENTIFIER", "TSTRING", "OPERATOR_X__", "OP_CALC", "AND_OP", "OR_OP",
  "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "FUNC_OP", "INC_OP", "DEC_OP",
  "FUNC_CALL", "VAR_DECLAR", "RESTRICT", "THIS", "EXTENDS", "ARRAY_ELE",
  "XTRY", "XCATCH", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "LEFT_SHIFT",
  "RIGHT_SHIFT", "MOD_EQ", "XPUBLIC", "XSET", "XIS", "SCOPE",
  "SCOPE_FUNC_CALL", "REQUIRE", "REQUIRE_ONCE", "REF", "XCONTINUE",
  "XCONST", "XLOCAL", "AUTO", "IF", "ELSE", "WHILE", "FOR", "DELETE",
  "BREAK", "RETURN", "SWITCH", "CASE", "DEFAULT", "CASE_LIST",
  "CLAXX_BODY", "NEW", "CLAXX_MEMBER", "CLAXX_FUNC_CALL", "XNULL",
  "XINCLUDE", "ANNOTATION", "NONASSOC", "IFX", "','", "'='", "'|'", "'^'",
  "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "'('", "')'", "'['", "']'", "'.'", "PRIORITY3", "PRIORITY2", "PRIORITY1",
  "UMINUS", "';'", "'{'", "'}'", "'@'", "':'", "'$'", "$accept", "program",
  "statement_list", "statement", "require_stmt", "try_stmt",
  "catch_block_stmt", "declar_stmt", "annotation_declar_stmt",
  "annotation_use_stmt", "annotation_use_single_stmt", "const_declar_stmt",
  "local_declar_stmt", "namespace_declar_stmt", "namespace_name_stmt",
  "class_declar_stmt", "extends_stmt", "class_body", "class_body_stmt",
  "this_stmt", "this_member_stmt", "class_member_stmt",
  "class_member_func_stmt", "static_member_stmt", "func_declar_stmt",
  "lambda_stmt", "lambda_args_stmt", "param_list", "parameter",
  "expr_list", "var_declar_stmt", "con_ctl_stmt", "selection_stmt",
  "case_stmt_list", "case_stmt", "loop_stmt", "for_1_stmt", "simple_stmt",
  "self_compute_stmt", "restrict_stmt", "interrupt_stmt", "call_statement",
  "call_statement_piping", "call_statement_piping_single", "args_list",
  "args_expr", "args_expr_collection", "block", "double_or_ps_expr",
  "parentheses_stmt", "arithmetic_stmt", "bit_opr_factor",
  "arithmetic_stmt_factor", "new_expr", "id_expr", "t_bool_expr",
  "double_expr", "uminus_expr", "string_expr", "null_expr",
  "not_expr_value", "bool_param_expr", "logic_stmt", "type_judge_stmt",
  "self_inc_dec_stmt", "assign_stmt_value", "assign_stmt_value_eq",
  "single_assign_stmt", "class_member_assign_stmt", "array_ele_stmt",
  "array_ele_assign_stmt", "assign_stmt", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    44,    61,   124,    94,
      38,    62,    60,    43,    45,    42,    47,    37,    33,   126,
      40,    41,    91,    93,    46,   321,   322,   323,   324,    59,
     123,   125,    64,    58,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    97,    97,    98,    98,    98,    98,    98,
      98,    99,    99,    99,    99,   100,   100,   101,   102,   102,
     102,   102,   102,   102,   102,   103,   104,   104,   105,   106,
     107,   107,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   113,
     114,   114,   114,   115,   115,   116,   116,   116,   116,   117,
     117,   117,   117,   117,   118,   119,   119,   119,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   131,   131,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   133,   134,   134,   135,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   142,   142,   143,   143,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   146,
     146,   147,   147,   147,   148,   149,   150,   151,   151,   152,
     152,   153,   154,   155,   155,   155,   155,   156,   156,   156,
     156,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   158,   159,   159,   159,   159,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   162,   162,   163,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   165,   166,   166,   166,   166,
     166,   166,   166,   166
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       1,     2,     2,     2,     3,     4,     5,     7,     1,     1,
       1,     2,     1,     1,     1,     2,     1,     2,     2,     2,
       2,     2,     4,     1,     3,     4,     5,     5,     6,     5,
       6,     6,     7,     0,     2,     1,     2,     1,     2,     1,
       1,     3,     6,     3,     3,     3,     3,     6,     3,     6,
       6,     9,     6,     6,     3,     7,     6,     6,     7,     5,
       5,     3,     3,     0,     3,     1,     3,     0,     2,     0,
       2,     3,     5,     6,     5,     6,     5,     6,     1,     1,
       5,     7,     7,     1,     2,     4,     3,     5,     9,     0,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     4,     4,
       4,     1,     4,     1,     3,     3,     0,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     1,
       1,     1,     1,     3,     5,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     1,     1,     1,     3,
       3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   165,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,     0,     0,     5,
       0,     3,     9,    10,     6,    24,     0,    26,    22,    23,
       0,    20,     0,     0,   121,     0,    18,    19,     7,    88,
      89,     0,   103,   109,   107,   105,   111,   123,   108,     0,
     112,   236,   237,     0,   238,   104,    73,     0,   126,     0,
       0,    73,   165,   193,   194,   166,   114,     0,    79,     0,
     171,    11,    12,    33,     0,   165,    29,     0,   165,     0,
      31,    30,    43,     0,     0,    99,   106,   168,   167,   165,
      50,   172,     0,     0,    77,     0,   220,   218,   219,   202,
       0,   215,   162,     0,     0,   206,   160,   199,   212,   213,
     214,   208,   217,   117,   161,   221,     0,     0,    13,     0,
      28,    25,    43,     0,    27,    21,     0,     0,     0,     0,
       0,   126,     8,     0,     0,   195,   196,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,   126,     0,
      77,     0,    44,   165,   142,   220,   218,   219,   130,   215,
       0,   127,   128,   162,   141,   216,   131,   212,   213,   214,
     217,   221,     0,   165,     0,     0,     0,     0,     0,     0,
       0,   165,    54,     0,    53,     0,     0,     0,    14,     0,
      28,     0,     0,     0,   218,   219,   215,   178,   216,   179,
     212,   213,   214,   180,   181,     0,   182,   177,   221,     0,
     165,   101,     0,   102,   100,     0,     0,     0,     0,   168,
       0,   169,   146,   170,   145,   159,   156,   160,   165,     0,
     162,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,    73,     0,    43,   225,
     224,     0,     0,     0,    58,    56,     0,   125,   124,     0,
       0,     0,   216,   239,   240,   241,   242,   243,    64,    81,
     160,   222,   223,    55,   235,     0,     0,    75,     0,    79,
     120,     0,   226,   227,   228,     0,   165,    35,     0,    45,
      49,    47,     0,     0,    79,    15,    78,    32,    34,     0,
     165,     0,   176,   175,   174,   173,   183,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      71,     0,     0,    51,     0,     0,     0,   163,   118,    79,
      72,   157,   158,   154,   155,   153,   162,   148,   149,   150,
     151,   152,     0,     0,     0,     0,     0,   229,   230,   231,
     126,   126,   122,     0,   232,   233,   234,   126,   119,   126,
      74,     0,     0,   129,     0,    82,     0,    84,     0,    86,
      36,    46,    48,     0,     0,    16,     0,     0,    37,     0,
     192,   186,   187,   188,   189,   184,   185,   190,   191,    79,
     144,    90,    97,     0,     0,   226,   227,   126,   147,    76,
       0,     0,     0,   164,    79,    39,     0,     0,     0,     0,
     125,     0,     0,    66,    57,    83,    85,    87,    67,     0,
      38,     0,     0,    99,    69,     0,    79,    70,     0,     0,
       0,    93,     0,    40,    41,     0,    62,    63,    59,    60,
     126,     0,   143,    91,     0,    52,     0,     0,    79,    92,
      94,    65,    42,     0,     0,     0,    68,    79,    96,    61,
      79,    98,    95,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   306,    32,    33,   385,    34,    35,    36,
      37,    38,    39,    40,    84,    41,    70,   298,   299,   165,
      42,   204,    44,    45,    46,   168,   110,   161,   239,   195,
      47,    48,    49,   440,   441,    50,   222,    51,    52,    53,
      54,   206,    56,    57,   170,   171,   172,   401,   231,   232,
     173,   113,   114,    58,   175,   176,   210,   211,   212,   213,
     316,   214,   215,   216,   180,   123,   124,    61,    62,   218,
      64,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -312
static const yytype_int16 yypact[] =
{
    -312,    18,  1722,  -312,   183,    31,    60,    60,    54,    -7,
      39,    73,    87,    87,    82,  -312,   178,     3,   213,   149,
     179,   230,   289,  -312,   275,   241,    60,    87,   326,  -312,
      11,  -312,  -312,  -312,  -312,  -312,    13,  -312,  -312,  -312,
     246,  -312,   299,   174,   293,   314,  -312,  -312,  -312,  -312,
    -312,   315,  -312,  -312,  -312,    50,  -312,  -312,  -312,  1759,
    -312,  -312,  -312,   420,  -312,  -312,   330,   407,    32,   372,
     332,   330,  -312,  -312,  -312,  -312,  -312,   417,  -312,   391,
    -312,  -312,  -312,  -312,   327,   392,  -312,     8,   143,   482,
    -312,  -312,   457,   598,   598,   342,  -312,   459,  -312,    -4,
     424,  -312,    81,   265,  1084,    32,   -60,   317,   476,  -312,
      17,   471,    38,   480,   587,  -312,   615,  -312,   151,   227,
     367,  -312,   379,  -312,  -312,   451,    60,   418,  -312,   485,
      30,  -312,   457,   503,  -312,  -312,  1003,  1003,   500,    60,
      60,    32,  -312,   417,   527,  -312,  -312,   592,   592,   592,
     592,   592,    60,   178,  1003,    60,  -312,  1003,    32,    60,
     512,   432,  -312,   302,  -312,  -312,   760,   271,  -312,   368,
     443,   460,  -312,    -9,  -312,   739,  -312,   181,   247,   305,
    -312,   614,   453,   402,   463,   344,    80,    -3,   357,    19,
     469,   373,   344,   465,    -3,  1168,    82,   557,  -312,   298,
    -312,   477,   216,  1720,   344,   314,   465,   655,  1785,  -312,
    -312,  -312,  -312,  -312,   405,    21,  -312,   661,   357,    58,
     414,  -312,   475,  -312,  -312,   479,   572,   580,    60,  -312,
     592,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   194,   186,
     507,   -21,   502,   583,   265,   265,   265,   265,   265,  1720,
    1720,  1720,  1720,  1720,   516,    32,   330,   504,   457,  -312,
    -312,   510,   517,   523,   532,   533,   526,   142,  -312,   534,
     536,   543,    91,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
     554,  -312,  -312,   560,  -312,   553,   561,  -312,   224,  -312,
     564,    32,   101,   107,  -312,   145,     7,  -312,    65,  -312,
    -312,  -312,   105,   556,  -312,   625,  -312,   569,  -312,   575,
     542,   207,  -312,   344,   465,    -3,  -312,    60,  1117,  1117,
    1117,  1117,  1117,  1117,   598,   598,  1223,  1223,   598,  -312,
    -312,   582,   585,   589,   574,   667,   658,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,   499,   499,  -312,
    -312,  -312,   596,   606,   607,   208,   610,  -312,  -312,  -312,
      32,    32,  -312,   417,  -312,  -312,  -312,    32,  -312,    32,
    -312,  1282,    60,  -312,   178,  -312,   178,  -312,   178,  -312,
    -312,  -312,  -312,  1337,   599,  -312,   101,   107,  -312,   212,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   692,  -312,
    -312,   659,  -312,    53,  1392,  -312,  -312,    32,  -312,  -312,
     617,  1447,   336,  -312,  -312,  -312,   215,   294,   628,   629,
     465,   630,   637,  -312,   640,  -312,  -312,  -312,  -312,    60,
    -312,  1502,  1223,   342,  -312,   641,  -312,  -312,   353,   631,
     -11,  -312,  1557,  -312,  -312,   321,  -312,  -312,  -312,  -312,
      32,   645,  -312,  -312,   665,  -312,  1612,   647,  -312,  -312,
    -312,  -312,  -312,   668,   660,  1223,  -312,  -312,  1722,  -312,
    -312,  -312,  1722,  1667,  -312
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,  -312,     4,  -312,  -312,  -312,  -312,  -312,  -312,
     712,  -312,  -312,  -312,   558,    69,   -90,  -304,  -285,    55,
    -312,   112,  -312,   709,  -181,   -14,  -312,   -68,   595,   103,
     268,  -312,  -312,  -312,   318,  -312,   328,  -312,  -312,  -312,
    -312,   356,  -312,   616,  -130,   657,   473,  -311,  -312,  -312,
     847,   -43,   648,   679,    -2,    22,   384,   750,    28,    41,
    -312,   474,   -74,  -312,   310,   308,   825,  -128,  -312,   513,
    -312,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -217
static const yytype_int16 yytable[] =
{
      59,   224,   201,   190,    73,    74,    31,   389,   300,    88,
     109,   266,   225,   381,    87,    87,   402,   130,     3,   132,
     219,  -209,   116,    66,   127,   296,   282,     5,   285,  -209,
      76,   324,   325,   242,   152,    97,    98,    75,   163,    80,
      81,    82,   257,   438,   439,   291,   117,    71,    18,     6,
       7,   416,   120,    67,   100,   128,    18,  -137,   133,    75,
     236,   303,   226,   324,   325,   121,    72,   187,   324,   325,
     338,   296,  -137,     5,   153,   194,    68,    77,   227,   106,
     459,   155,  -137,   243,   229,    98,    90,    72,    83,   199,
      26,   208,   208,    59,    80,    89,   179,   156,    28,   131,
     233,   237,   326,    89,   381,    89,   102,    79,   145,   146,
     297,   103,   104,   445,    43,   209,   209,   300,   143,  -200,
     -43,   453,   109,   109,   254,   353,   164,  -200,   152,    78,
     300,   381,   144,   179,   116,   116,   107,   264,   265,   327,
     109,   187,   433,   109,    28,   272,   272,   272,   272,   272,
     278,    87,   280,   283,   471,   116,   380,   286,   117,   117,
     381,   230,   144,   295,   120,   120,    67,   374,   356,   179,
     303,   153,   154,   376,   300,   155,   117,   121,   121,   117,
     166,   185,   120,   303,    85,   120,   179,   302,   354,   192,
     375,   106,   106,    59,   156,   121,   377,   187,   121,    66,
     315,   341,   342,   343,   344,   345,    67,    43,   300,   106,
     363,   378,   106,   296,   296,     5,     5,   166,   296,    92,
       5,   296,   191,     5,   144,   199,   333,   303,   272,    93,
     418,   419,  -197,   -43,   379,   300,   300,   421,   100,   422,
    -197,   137,   237,   237,   237,   237,   237,  -132,   107,   107,
     397,   398,   335,   166,   403,   185,   138,   312,   139,    94,
     -75,   303,  -132,    68,   300,    69,   107,   336,   235,   107,
     166,    72,  -132,   -43,    68,   -75,   227,   435,    97,    98,
      75,    99,    80,   179,    86,    91,    28,    28,   303,   303,
     335,    28,     6,     7,    28,    96,   302,   100,   388,   415,
     296,   309,     5,   430,   310,   370,   443,    43,  -198,   302,
      95,   185,    60,  -135,   313,   390,  -198,   303,   225,   179,
     463,   126,   208,   208,    59,    59,   208,   296,  -135,     5,
     400,   400,   129,    26,   122,   135,   101,  -140,  -135,   224,
     209,   209,   209,   209,   209,   209,   209,   209,   220,   102,
     209,   141,  -140,   302,   103,   104,   229,    98,    55,     6,
       7,   187,  -140,   221,     9,   105,   136,   166,  -133,    59,
     424,  -134,    87,    28,    87,   182,    87,   140,   183,   184,
     111,    59,    68,  -133,   227,   444,  -134,   302,   179,   179,
     438,   439,   371,  -133,   141,   179,  -134,   179,  -207,   138,
      28,   139,    59,   166,   142,   223,  -207,   383,   118,    59,
     160,   197,   462,   162,   302,   302,   198,   318,   319,   320,
     321,   279,   189,   191,   169,   186,   138,   451,   139,    59,
      59,    59,   404,   193,  -136,   179,   400,   158,    43,    43,
      59,   159,   411,   302,   259,   260,   122,   122,  -204,  -136,
     144,   193,   177,    68,    59,   227,  -204,   301,   196,  -136,
    -205,   169,   281,    59,   122,   284,    59,   122,  -205,   400,
      59,    59,   166,   166,   199,   185,   322,   323,   179,   166,
      67,   166,    68,    43,   227,   293,   234,   157,   200,   177,
    -159,  -159,   111,   111,    68,    43,    69,   169,   255,   267,
     158,   256,   431,   261,   159,    60,   262,   263,   228,   258,
     111,   244,   245,   111,   169,    63,    43,   442,   287,   166,
     118,   118,   289,    43,   290,   177,   291,  -159,  -159,  -159,
     269,   158,  -210,   270,   271,   159,   292,   125,   118,   456,
    -210,   118,   177,    43,    43,    43,   294,   144,   246,   247,
     248,    55,  -201,   144,    43,   186,   141,  -211,   314,   304,
    -201,   468,   166,   308,   328,  -211,   301,   311,    43,   329,
     472,   145,   146,   473,   251,   252,   253,    43,   330,   301,
      43,   181,   188,   331,    43,    43,   332,   184,   337,   340,
     188,   152,   339,   357,   355,   229,    98,   352,   191,    80,
     358,    97,    98,    75,   191,    80,   359,   362,    63,     6,
       7,   169,   360,   361,   100,     6,     7,   364,   181,   365,
     100,   154,    68,   301,   227,   387,   366,  -216,  -216,  -216,
    -216,  -216,   145,   146,   368,  -203,    60,    60,   155,   177,
     367,   369,   425,  -203,   426,   382,   427,   169,   372,   125,
     125,   384,   152,   197,   181,   408,   188,   301,   386,   101,
     249,   250,   251,   252,   253,   405,   102,   125,   406,   407,
     125,   181,   102,   409,   410,   177,   202,   103,   203,   429,
    -138,    60,    55,    55,   301,   301,   412,   413,  -216,  -216,
    -216,  -216,  -216,    60,   158,  -138,  -203,   414,   159,   155,
     417,   221,   324,   115,  -203,  -138,   432,   436,    63,   446,
     447,   448,   188,   301,    60,   188,   169,   169,   449,   420,
     450,    60,   455,   169,   458,   169,   464,    55,  -162,  -162,
    -162,  -162,  -162,   108,  -161,  -161,  -161,  -161,  -161,    55,
     467,    60,    60,   223,   177,   177,   465,   174,   134,   469,
     470,   177,    60,   177,   307,   288,   145,   146,   460,   268,
      55,   454,   241,   169,   373,     0,    60,    55,   181,     0,
    -160,  -160,     0,     0,   119,    60,   152,   167,    60,     0,
       0,     0,    60,    60,   174,     0,     0,    55,    55,   193,
       0,   177,   391,   392,   393,   394,   395,   396,    55,     0,
       0,     0,   205,   205,   181,     0,   169,  -160,  -160,  -160,
       0,     0,    55,   205,   167,   115,   115,     0,   178,     0,
     174,    55,   457,   155,    55,     0,  -139,     0,    55,    55,
       0,     0,     0,   115,   177,     0,   115,   174,     0,    63,
      63,  -139,   138,     0,   139,   108,   108,     0,     0,     0,
     167,  -139,     0,     0,     0,   178,   205,   205,   205,   205,
     205,     0,     0,   108,     0,     0,   108,   167,     0,     0,
       0,   112,     0,   181,   181,     0,   188,     0,     0,     0,
     181,     0,   181,     0,    63,     0,   119,   119,     0,     0,
       0,   178,     0,     0,     0,     0,    63,   347,   348,   349,
     350,   351,     0,     0,   119,     0,     0,   119,   178,     0,
       0,     0,   205,     0,     0,     0,     0,    63,   217,   217,
     181,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   174,     0,     0,     0,     0,   205,
     207,   207,     0,     0,    63,    63,    63,     0,     0,     0,
       0,   240,     0,     0,     0,    63,     0,     0,   205,   205,
     205,   205,   205,   181,   167,     0,     0,     0,     0,    63,
     174,     0,   273,   274,   275,   276,   277,     0,    63,     0,
       0,    63,     0,   112,   112,    63,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,   112,     0,     0,   112,   178,    97,    98,    75,    99,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     0,     0,     0,   100,     0,   205,   205,   205,
     205,   205,   205,   205,   205,     0,     0,   205,     0,   174,
     174,   178,     0,     0,     0,     0,   174,     0,   174,     0,
     240,     0,     0,     0,     0,   334,     0,     0,     0,     0,
       0,    26,     0,     0,   101,     0,     0,     0,     0,   167,
     167,     0,     0,     0,     0,     0,   167,   102,   167,     0,
       0,     0,   103,   104,     0,     0,   174,    97,    98,     0,
     238,    80,     0,     0,     0,     0,   346,   346,   346,   346,
     346,     6,     7,     0,     0,     0,   100,     0,     0,     0,
     178,   178,     0,     0,     0,     0,   167,   178,     0,   178,
      97,    98,    75,   191,    80,     0,     0,     0,     0,   174,
       0,     0,     0,     0,     6,     7,     0,     0,     0,   100,
       0,     0,     0,   217,   217,   217,   217,   217,   217,   217,
     217,     0,     0,   217,     0,     0,     0,   178,   102,   167,
       0,     0,     0,   103,   203,   207,   207,   207,   207,   207,
     207,   207,   207,     0,     4,   207,     5,     0,   101,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     8,
       9,   102,     0,    10,     0,     0,   103,   203,     0,     0,
     178,     0,     0,    11,     0,     0,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     0,     0,     4,
      27,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     0,     0,     8,     9,     0,    28,    10,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    11,   305,
      30,     0,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     0,     0,     0,    27,     0,     0,     4,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,    28,     8,     9,     0,     0,    10,     0,     0,
       0,     0,    29,   399,     0,    30,     0,    11,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     4,    27,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,    28,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    11,   423,    30,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     4,    27,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,     0,     8,     9,     0,    28,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    11,   428,    30,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     4,    27,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,    28,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    11,   434,    30,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     4,    27,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,     0,     8,     9,     0,    28,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    11,   437,    30,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     4,    27,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,    28,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    11,   452,    30,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     4,    27,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,     0,     8,     9,     0,    28,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    11,   461,    30,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     0,     0,     4,    27,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,    28,    10,     0,     0,     0,     0,     0,     0,     0,
       0,    29,    11,   466,    30,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,    97,    98,    26,   191,    80,     4,    27,
       5,     0,     0,     0,     0,     0,     0,     6,     7,     6,
       7,     0,   100,     8,     9,     0,    28,    10,     0,     0,
       0,     0,     0,     0,     0,     0,    29,    11,   474,    30,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,   145,   146,     0,     0,
      26,     0,     0,     0,    27,     0,   147,   148,   149,   150,
       0,     0,   151,     0,   102,     0,   152,     0,     0,   103,
     203,    28,   145,   146,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    30,     0,  -160,  -160,     0,     0,
       0,   317,   152,     0,     0,   153,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   155,     0,     0,     0,     0,   156,     0,
       0,     0,     0,  -160,  -160,  -160,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   155
};

static const yytype_int16 yycheck[] =
{
       2,    95,    92,    71,     6,     7,     2,   311,   189,     6,
      24,   141,    16,   298,    16,    17,   327,     6,     0,     6,
      94,    81,    24,    16,    26,     6,   154,     8,   158,    89,
       8,    10,    11,    16,    37,     3,     4,     5,     6,     7,
      12,    13,   132,    54,    55,    66,    24,    16,    45,    17,
      18,   355,    24,    23,    22,    27,    45,    66,    45,     5,
     103,   189,    66,    10,    11,    24,     6,    69,    10,    11,
      91,     6,    81,     8,    66,    77,    80,    84,    82,    24,
      91,    84,    91,    66,     3,     4,    17,     6,     6,    82,
      58,    93,    94,    95,     7,    92,    68,    89,    79,    30,
     102,   103,    81,    92,   389,    92,    74,    34,    17,    18,
      91,    79,    80,   417,     2,    93,    94,   298,    68,    81,
      90,   432,   136,   137,   126,   255,    94,    89,    37,    90,
     311,   416,    82,   105,   136,   137,    24,   139,   140,    81,
     154,   143,    89,   157,    79,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   465,   157,    91,   159,   136,   137,
     445,    80,    82,    83,   136,   137,    23,    66,   258,   141,
     298,    66,    67,    66,   355,    84,   154,   136,   137,   157,
      68,    69,   154,   311,     6,   157,   158,   189,   256,    77,
      89,   136,   137,   195,    89,   154,    89,   199,   157,    16,
     202,   244,   245,   246,   247,   248,    23,    95,   389,   154,
      68,    66,   157,     6,     6,     8,     8,   105,     6,     6,
       8,     6,     6,     8,    82,    82,   228,   355,   230,    80,
     360,   361,    81,    90,    89,   416,   417,   367,    22,   369,
      89,    67,   244,   245,   246,   247,   248,    66,   136,   137,
     324,   325,    66,   141,   328,   143,    82,   202,    84,    80,
      66,   389,    81,    80,   445,    82,   154,    81,     3,   157,
     158,     6,    91,    90,    80,    81,    82,   407,     3,     4,
       5,     6,     7,   255,    16,    17,    79,    79,   416,   417,
      66,    79,    17,    18,    79,     6,   298,    22,    91,    91,
       6,     3,     8,    91,     6,    81,    91,   195,    81,   311,
      80,   199,     2,    66,   202,   317,    89,   445,    16,   291,
     450,    80,   324,   325,   326,   327,   328,     6,    81,     8,
     326,   327,     6,    58,    24,    89,    61,    66,    91,   433,
     318,   319,   320,   321,   322,   323,   324,   325,     6,    74,
     328,    80,    81,   355,    79,    80,     3,     4,     2,    17,
      18,   363,    91,    95,    22,    90,    67,   255,    66,   371,
     372,    66,   374,    79,   376,     3,   378,    84,     6,     7,
      24,   383,    80,    81,    82,    91,    81,   389,   360,   361,
      54,    55,   289,    91,    80,   367,    91,   369,    81,    82,
      79,    84,   404,   291,    89,    95,    89,   304,    24,   411,
      80,    84,    91,     6,   416,   417,    89,    12,    13,    14,
      15,   153,    90,     6,    68,    69,    82,   429,    84,   431,
     432,   433,   329,    77,    66,   407,   432,    80,   326,   327,
     442,    84,   339,   445,   136,   137,   136,   137,    81,    81,
      82,    95,    68,    80,   456,    82,    89,   189,    67,    91,
      81,   105,   154,   465,   154,   157,   468,   157,    89,   465,
     472,   473,   360,   361,    82,   363,    71,    72,   450,   367,
      23,   369,    80,   371,    82,    83,   102,    67,     6,   105,
      31,    32,   136,   137,    80,   383,    82,   141,    80,   143,
      80,    16,   399,     3,    84,   195,     6,     7,    84,     6,
     154,    31,    32,   157,   158,     2,   404,   414,     6,   407,
     136,   137,    90,   411,    81,   141,    66,    68,    69,    70,
       3,    80,    81,     6,     7,    84,    83,    24,   154,   436,
      89,   157,   158,   431,   432,   433,    83,    82,    68,    69,
      70,   195,    81,    82,   442,   199,    80,    81,   202,    90,
      89,   458,   450,     6,    89,    89,   298,    90,   456,    90,
     467,    17,    18,   470,    75,    76,    77,   465,     6,   311,
     468,    68,    69,     3,   472,   473,     6,     7,    81,     6,
      77,    37,    90,    83,    90,     3,     4,    81,     6,     7,
      83,     3,     4,     5,     6,     7,    83,    81,    95,    17,
      18,   255,    80,    80,    22,    17,    18,    83,   105,    83,
      22,    67,    80,   355,    82,    83,    83,    73,    74,    75,
      76,    77,    17,    18,    81,    81,   326,   327,    84,   255,
      80,    80,   374,    89,   376,    89,   378,   291,    84,   136,
     137,    26,    37,    84,   141,    81,   143,   389,    83,    61,
      73,    74,    75,    76,    77,    83,    74,   154,    83,    80,
     157,   158,    74,     6,    16,   291,    78,    79,    80,    80,
      66,   371,   326,   327,   416,   417,    90,    81,    73,    74,
      75,    76,    77,   383,    80,    81,    81,    90,    84,    84,
      90,   433,    10,    24,    89,    91,    47,    90,   195,    81,
      81,    81,   199,   445,   404,   202,   360,   361,    81,   363,
      80,   411,    81,   367,    93,   369,    81,   371,    73,    74,
      75,    76,    77,    24,    73,    74,    75,    76,    77,   383,
      93,   431,   432,   433,   360,   361,    81,    68,    36,    81,
      90,   367,   442,   369,   196,   160,    17,    18,   440,   143,
     404,   433,   105,   407,   291,    -1,   456,   411,   255,    -1,
      31,    32,    -1,    -1,    24,   465,    37,    68,   468,    -1,
      -1,    -1,   472,   473,   105,    -1,    -1,   431,   432,   433,
      -1,   407,   318,   319,   320,   321,   322,   323,   442,    -1,
      -1,    -1,    93,    94,   291,    -1,   450,    68,    69,    70,
      -1,    -1,   456,   104,   105,   136,   137,    -1,    68,    -1,
     141,   465,   438,    84,   468,    -1,    66,    -1,   472,   473,
      -1,    -1,    -1,   154,   450,    -1,   157,   158,    -1,   326,
     327,    81,    82,    -1,    84,   136,   137,    -1,    -1,    -1,
     141,    91,    -1,    -1,    -1,   105,   147,   148,   149,   150,
     151,    -1,    -1,   154,    -1,    -1,   157,   158,    -1,    -1,
      -1,    24,    -1,   360,   361,    -1,   363,    -1,    -1,    -1,
     367,    -1,   369,    -1,   371,    -1,   136,   137,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,   383,   249,   250,   251,
     252,   253,    -1,    -1,   154,    -1,    -1,   157,   158,    -1,
      -1,    -1,   203,    -1,    -1,    -1,    -1,   404,    93,    94,
     407,    -1,    -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,    -1,   230,
      93,    94,    -1,    -1,   431,   432,   433,    -1,    -1,    -1,
      -1,   104,    -1,    -1,    -1,   442,    -1,    -1,   249,   250,
     251,   252,   253,   450,   255,    -1,    -1,    -1,    -1,   456,
     291,    -1,   147,   148,   149,   150,   151,    -1,   465,    -1,
      -1,   468,    -1,   136,   137,   472,   473,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,   154,    -1,    -1,   157,   255,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    22,    -1,   318,   319,   320,
     321,   322,   323,   324,   325,    -1,    -1,   328,    -1,   360,
     361,   291,    -1,    -1,    -1,    -1,   367,    -1,   369,    -1,
     203,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    61,    -1,    -1,    -1,    -1,   360,
     361,    -1,    -1,    -1,    -1,    -1,   367,    74,   369,    -1,
      -1,    -1,    79,    80,    -1,    -1,   407,     3,     4,    -1,
       6,     7,    -1,    -1,    -1,    -1,   249,   250,   251,   252,
     253,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,    -1,
     360,   361,    -1,    -1,    -1,    -1,   407,   367,    -1,   369,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,   450,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,    -1,   318,   319,   320,   321,   322,   323,   324,
     325,    -1,    -1,   328,    -1,    -1,    -1,   407,    74,   450,
      -1,    -1,    -1,    79,    80,   318,   319,   320,   321,   322,
     323,   324,   325,    -1,     6,   328,     8,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    74,    -1,    25,    -1,    -1,    79,    80,    -1,    -1,
     450,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,
      62,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    79,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,
      92,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    -1,    -1,     6,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    79,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    89,    90,    -1,    92,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,     3,     4,    58,     6,     7,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    17,
      18,    -1,    22,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    17,    18,    -1,    -1,
      58,    -1,    -1,    -1,    62,    -1,    27,    28,    29,    30,
      -1,    -1,    33,    -1,    74,    -1,    37,    -1,    -1,    79,
      80,    79,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    92,    -1,    31,    32,    -1,    -1,
      -1,    36,    37,    -1,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,    97,     0,     6,     8,    17,    18,    21,    22,
      25,    35,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    58,    62,    79,    89,
      92,    98,    99,   100,   102,   103,   104,   105,   106,   107,
     108,   110,   115,   116,   117,   118,   119,   125,   126,   127,
     130,   132,   133,   134,   135,   136,   137,   138,   148,   149,
     159,   162,   163,   164,   165,   166,    16,    23,    80,    82,
     111,    16,     6,   149,   149,     5,   150,    84,    90,    34,
       7,   153,   153,     6,   109,     6,   125,   149,     6,    92,
     110,   125,     6,    80,    80,    80,     6,     3,     4,     6,
      22,    61,    74,    79,    80,    90,   114,   116,   118,   120,
     121,   136,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   159,   160,   161,   164,    80,   149,   153,     6,
       6,   110,     6,    45,   105,    89,    67,    67,    82,    84,
      84,    80,    89,    68,    82,    17,    18,    27,    28,    29,
      30,    33,    37,    66,    67,    84,    89,    67,    80,    84,
      80,   122,     6,     6,    94,   114,   116,   118,   120,   136,
     139,   140,   141,   145,   148,   149,   150,   151,   152,   153,
     159,   164,     3,     6,     7,   116,   136,   149,   164,    90,
     122,     6,   116,   136,   149,   124,    67,    84,    89,    82,
       6,   111,    78,    80,   116,   118,   136,   145,   149,   150,
     151,   152,   153,   154,   156,   157,   158,   161,   164,   157,
       6,   125,   131,   159,   166,    16,    66,    82,    84,     3,
      80,   143,   144,   149,   151,     3,   146,   149,     6,   123,
     145,   140,    16,    66,    31,    32,    68,    69,    70,    73,
      74,    75,    76,    77,   149,    80,    16,   111,     6,   160,
     160,     3,     6,     7,   149,   149,   139,   136,   138,     3,
       6,     7,   149,   161,   161,   161,   161,   161,   149,   125,
     149,   160,   162,   149,   160,   139,   149,     6,   123,    90,
      81,    66,    83,    83,    83,    83,     6,    91,   112,   113,
     119,   125,   149,   162,    90,    91,    98,   109,     6,     3,
       6,    90,   114,   116,   136,   149,   155,    36,    12,    13,
      14,    15,    71,    72,    10,    11,    81,    81,    89,    90,
       6,     3,     6,   149,   161,    66,    81,    81,    91,    90,
       6,   146,   146,   146,   146,   146,   145,   147,   147,   147,
     147,   147,    81,   139,   122,    90,   111,    83,    83,    83,
      80,    80,    81,    68,    83,    83,    83,    80,    81,    80,
      81,   124,    84,   141,    66,    89,    66,    89,    66,    89,
      91,   113,    89,   124,    26,   101,    83,    83,    91,   112,
     149,   156,   156,   156,   156,   156,   156,   157,   157,    90,
      98,   142,   142,   157,   124,    83,    83,    80,    81,     6,
      16,   124,    90,    81,    90,    91,   112,    90,   139,   139,
     136,   139,   139,    91,   149,   125,   125,   125,    91,    80,
      91,   124,    47,    89,    91,   139,    90,    91,    54,    55,
     128,   129,   124,    91,    91,   112,    81,    81,    81,    81,
      80,   149,    91,   142,   131,    81,   124,   151,    93,    91,
     129,    91,    91,   139,    81,    81,    91,    93,   124,    81,
      90,   142,   124,   124,    91
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 3:
#line 83 "a.y"
    { execAndFreeNode((yyvsp[(2) - (2)].node));}
    break;

  case 5:
#line 87 "a.y"
    { (yyval.node) = opr(';' , 0 ); }
    break;

  case 6:
#line 88 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 89 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:
#line 90 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 9:
#line 91 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
#line 92 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
#line 97 "a.y"
    { (yyval.node) = opr(REQUIRE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 12:
#line 98 "a.y"
    { (yyval.node) = opr(REQUIRE_ONCE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 13:
#line 99 "a.y"
    { (yyval.node) = opr(XINCLUDE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 14:
#line 100 "a.y"
    { (yyval.node) = opr(REF , 1, string((yyvsp[(2) - (3)].sValue))); }
    break;

  case 15:
#line 105 "a.y"
    { (yyval.node) = opr(XTRY, 2,(yyvsp[(3) - (4)].node),NULL); }
    break;

  case 16:
#line 106 "a.y"
    { (yyval.node) = opr(XTRY, 2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); }
    break;

  case 17:
#line 110 "a.y"
    { (yyval.node) = opr(XCATCH, 2, (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); }
    break;

  case 18:
#line 115 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 116 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 20:
#line 117 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:
#line 118 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 22:
#line 119 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 23:
#line 120 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:
#line 121 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 25:
#line 126 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 26:
#line 130 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 27:
#line 131 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 28:
#line 135 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 29:
#line 140 "a.y"
    { (yyval.node) = opr(XCONST , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 30:
#line 145 "a.y"
    { (yyval.node) = opr(XLOCAL , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 31:
#line 146 "a.y"
    { (yyval.node) = opr(XLOCAL , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 32:
#line 151 "a.y"
    { (yyval.node) = changeNameSpace((yyvsp[(4) - (4)].sValue)); }
    break;

  case 33:
#line 155 "a.y"
    { (yyval.sValue) = (yyvsp[(1) - (1)].sValue) ; }
    break;

  case 34:
#line 156 "a.y"
    { (yyval.sValue) = namespaceNameCat((yyvsp[(1) - (3)].sValue),(yyvsp[(3) - (3)].sValue)) ; }
    break;

  case 35:
#line 161 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(1) - (4)].sValue) , (yyvsp[(2) - (4)].sValue), NULL,false); }
    break;

  case 36:
#line 162 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(1) - (5)].sValue) , (yyvsp[(2) - (5)].sValue), (yyvsp[(4) - (5)].node),false); }
    break;

  case 37:
#line 163 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(2) - (5)].sValue) , (yyvsp[(3) - (5)].sValue), NULL,true); }
    break;

  case 38:
#line 164 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(2) - (6)].sValue) , (yyvsp[(3) - (6)].sValue), (yyvsp[(5) - (6)].node), true); }
    break;

  case 39:
#line 165 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(2) - (5)].sValue) , (yyvsp[(3) - (5)].sValue), NULL,false); }
    break;

  case 40:
#line 166 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(2) - (6)].sValue) , (yyvsp[(3) - (6)].sValue), (yyvsp[(5) - (6)].node),false); }
    break;

  case 41:
#line 167 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(3) - (6)].sValue) , (yyvsp[(4) - (6)].sValue), NULL,true); }
    break;

  case 42:
#line 168 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(3) - (7)].sValue) , (yyvsp[(4) - (7)].sValue), (yyvsp[(6) - (7)].node), true); }
    break;

  case 43:
#line 173 "a.y"
    { (yyval.sValue) = NULL; }
    break;

  case 44:
#line 174 "a.y"
    { (yyval.sValue) = (yyvsp[(2) - (2)].sValue); }
    break;

  case 45:
#line 179 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 46:
#line 180 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 47:
#line 184 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 48:
#line 185 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 49:
#line 186 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 50:
#line 191 "a.y"
    { (yyval.node) = opr(THIS , 0 ); }
    break;

  case 51:
#line 192 "a.y"
    {  (yyval.node) = opr(THIS,1,(yyvsp[(3) - (3)].node)); }
    break;

  case 52:
#line 194 "a.y"
    { (yyval.node) = opr(THIS, 1 , opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 53:
#line 199 "a.y"
    {  (yyval.node) = opr(THIS,1,(yyvsp[(3) - (3)].node)); }
    break;

  case 54:
#line 200 "a.y"
    {  (yyval.node) = opr(THIS, 1, (yyvsp[(3) - (3)].node) ); }
    break;

  case 55:
#line 205 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 56:
#line 206 "a.y"
    { (yyval.node) =  opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 57:
#line 207 "a.y"
    { (yyval.node) = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var((yyvsp[(1) - (6)].sValue)), argsNode((yyvsp[(3) - (6)].args)) ) , (yyvsp[(6) - (6)].node)); }
    break;

  case 58:
#line 208 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 59:
#line 213 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[(1) - (6)].node), opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) );}
    break;

  case 60:
#line 214 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[(1) - (6)].node), opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) );}
    break;

  case 61:
#line 215 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var((yyvsp[(1) - (9)].sValue)), argsNode((yyvsp[(3) - (9)].args)) ) , opr(FUNC_CALL,2, (yyvsp[(6) - (9)].node), argsNode((yyvsp[(8) - (9)].args)) )); }
    break;

  case 62:
#line 216 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[(1) - (6)].node),opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 63:
#line 217 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[(1) - (6)].node),opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 64:
#line 222 "a.y"
    { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)) ; }
    break;

  case 65:
#line 228 "a.y"
    { (yyval.node) = dtrt((yyvsp[(2) - (7)].sValue),(yyvsp[(4) - (7)].params),(yyvsp[(6) - (7)].node));}
    break;

  case 66:
#line 229 "a.y"
    { (yyval.node) = func((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].params),(yyvsp[(5) - (6)].node));}
    break;

  case 67:
#line 230 "a.y"
    { (yyval.node) = func((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].params),(yyvsp[(5) - (6)].node));}
    break;

  case 68:
#line 235 "a.y"
    { (yyval.node) = lambda((yyvsp[(2) - (7)].params),(yyvsp[(6) - (7)].node)) ;}
    break;

  case 69:
#line 236 "a.y"
    { (yyval.node) = lambda(params(NULL, (yyvsp[(1) - (5)].sValue)),(yyvsp[(4) - (5)].node)) ; }
    break;

  case 70:
#line 237 "a.y"
    { (yyval.node) = lambda((yyvsp[(1) - (5)].params),(yyvsp[(4) - (5)].node)) ; }
    break;

  case 71:
#line 241 "a.y"
    { (yyval.params) = params2((yyvsp[(1) - (3)].sValue),(yyvsp[(3) - (3)].sValue));  }
    break;

  case 72:
#line 242 "a.y"
    { (yyval.params) = params((yyvsp[(1) - (3)].params),(yyvsp[(3) - (3)].sValue));  }
    break;

  case 73:
#line 246 "a.y"
    { (yyval.params) = NULL; }
    break;

  case 74:
#line 247 "a.y"
    { (yyval.params) = (yyvsp[(2) - (3)].params); }
    break;

  case 75:
#line 251 "a.y"
    { (yyval.params) = params(NULL, (yyvsp[(1) - (1)].sValue)); }
    break;

  case 76:
#line 252 "a.y"
    { (yyval.params) = params((yyvsp[(1) - (3)].params),(yyvsp[(3) - (3)].sValue)); }
    break;

  case 77:
#line 253 "a.y"
    { (yyval.params) = NULL; }
    break;

  case 78:
#line 257 "a.y"
    { (yyval.node) = opr(';',2,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 79:
#line 258 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 80:
#line 263 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 81:
#line 264 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 82:
#line 265 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 1, arrayNode((yyvsp[(1) - (5)].sValue),(yyvsp[(3) - (5)].intValue),NULL) ); }
    break;

  case 83:
#line 266 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 2, arrayNode((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].intValue),NULL),(yyvsp[(6) - (6)].node)); }
    break;

  case 84:
#line 267 "a.y"
    {  (yyval.node) = opr(VAR_DECLAR , 1, arrayNode((yyvsp[(1) - (5)].sValue),-1,var((yyvsp[(3) - (5)].sValue))) ); }
    break;

  case 85:
#line 268 "a.y"
    {  (yyval.node) = opr(VAR_DECLAR , 2, arrayNode((yyvsp[(1) - (6)].sValue),-1,var((yyvsp[(3) - (6)].sValue))),(yyvsp[(6) - (6)].node)); }
    break;

  case 86:
#line 269 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 1, arrayNode((yyvsp[(1) - (5)].sValue),-1, (yyvsp[(3) - (5)].node)) ); }
    break;

  case 87:
#line 270 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 2, arrayNode((yyvsp[(1) - (6)].sValue),-1, (yyvsp[(3) - (6)].node)),(yyvsp[(6) - (6)].node) ); }
    break;

  case 88:
#line 275 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 89:
#line 276 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 90:
#line 281 "a.y"
    { (yyval.node) = opr(IF ,2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)) ; }
    break;

  case 91:
#line 282 "a.y"
    { (yyval.node) = opr(IF ,3,(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(7) - (7)].node)) ; }
    break;

  case 92:
#line 283 "a.y"
    { (yyval.node) = opr(SWITCH, 2 , (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); pretreatSwitch( (yyval.node) ) ; }
    break;

  case 93:
#line 287 "a.y"
    { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[(1) - (1)].node) ); }
    break;

  case 94:
#line 288 "a.y"
    { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node) ); }
    break;

  case 95:
#line 292 "a.y"
    { (yyval.node) = opr(CASE, 2 , (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 96:
#line 293 "a.y"
    { (yyval.node) = opr(DEFAULT , 1, (yyvsp[(3) - (3)].node)); }
    break;

  case 97:
#line 297 "a.y"
    { (yyval.node) = opr(WHILE , 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node) ); }
    break;

  case 98:
#line 298 "a.y"
    { (yyval.node) = opr(FOR,4,(yyvsp[(3) - (9)].node),(yyvsp[(5) - (9)].node),(yyvsp[(7) - (9)].node),(yyvsp[(9) - (9)].node)); }
    break;

  case 99:
#line 303 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 100:
#line 304 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 101:
#line 305 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 102:
#line 306 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 103:
#line 311 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 104:
#line 312 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 105:
#line 313 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 106:
#line 314 "a.y"
    { (yyval.node) = opr(DELETE, 1 ,(yyvsp[(2) - (2)].sValue) ); }
    break;

  case 107:
#line 315 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 108:
#line 316 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 109:
#line 317 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 110:
#line 318 "a.y"
    { (yyval.node) = opr(XCONTINUE , 0 ); }
    break;

  case 111:
#line 319 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 112:
#line 324 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 113:
#line 329 "a.y"
    { (yyval.node) = opr(RESTRICT,0);}
    break;

  case 114:
#line 330 "a.y"
    { (yyval.node) = opr(RESTRICT,1,(yyvsp[(2) - (2)].node)); }
    break;

  case 115:
#line 334 "a.y"
    { (yyval.node) = opr(BREAK, 0); }
    break;

  case 116:
#line 335 "a.y"
    { (yyval.node) = opr(RETURN , 0); }
    break;

  case 117:
#line 336 "a.y"
    { (yyval.node) = opr(RETURN , 1 ,(yyvsp[(2) - (2)].node));}
    break;

  case 118:
#line 337 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 119:
#line 342 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, (yyvsp[(1) - (4)].node), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 120:
#line 343 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, var((yyvsp[(1) - (4)].sValue)), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 121:
#line 344 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 122:
#line 345 "a.y"
    { (yyval.node) = opr(SCOPE_FUNC_CALL,2,(yyvsp[(1) - (4)].node),argsNode((yyvsp[(3) - (4)].args))); }
    break;

  case 123:
#line 349 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 124:
#line 350 "a.y"
    { (yyval.node) = NULL ;}
    break;

  case 125:
#line 354 "a.y"
    { (yyval.node) = NULL ;}
    break;

  case 126:
#line 358 "a.y"
    { (yyval.args) = NULL; }
    break;

  case 127:
#line 359 "a.y"
    { (yyval.args) = (yyvsp[(1) - (1)].args); }
    break;

  case 128:
#line 363 "a.y"
    { (yyval.args) = xArgs(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 129:
#line 364 "a.y"
    { (yyval.args) = xArgs((yyvsp[(1) - (3)].args), (yyvsp[(3) - (3)].node)); }
    break;

  case 130:
#line 368 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 131:
#line 369 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 132:
#line 370 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 133:
#line 371 "a.y"
    { /*printf("IDENTIFIER $1= %s\n" , $1);*/ (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 134:
#line 372 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 135:
#line 373 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 136:
#line 374 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 137:
#line 375 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 138:
#line 376 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 139:
#line 377 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 140:
#line 378 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 141:
#line 379 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 142:
#line 380 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 143:
#line 384 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 144:
#line 385 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 145:
#line 391 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 146:
#line 392 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 147:
#line 397 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 148:
#line 403 "a.y"
    { (yyval.node) = opr('+',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 149:
#line 404 "a.y"
    { (yyval.node) = opr('-',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 150:
#line 405 "a.y"
    { (yyval.node) = opr('*',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 151:
#line 406 "a.y"
    { (yyval.node) = opr('/',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 152:
#line 407 "a.y"
    { (yyval.node) = opr('%',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 153:
#line 408 "a.y"
    { (yyval.node) = opr('&',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 154:
#line 409 "a.y"
    { (yyval.node) = opr('|',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 155:
#line 410 "a.y"
    { (yyval.node) = opr('^',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 156:
#line 411 "a.y"
    { /* printf("get a ~ opr.\n"); */ (yyval.node) = opr('~',1,(yyvsp[(2) - (2)].node)); }
    break;

  case 157:
#line 412 "a.y"
    { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 158:
#line 413 "a.y"
    { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 159:
#line 418 "a.y"
    { (yyval.node) = xint((yyvsp[(1) - (1)].intValue)); }
    break;

  case 160:
#line 419 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 161:
#line 424 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 162:
#line 426 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 163:
#line 427 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node) ; }
    break;

  case 164:
#line 432 "a.y"
    { (yyval.node) = opr(NEW ,2, (yyvsp[(2) - (5)].node) , argsNode((yyvsp[(4) - (5)].args)) ); }
    break;

  case 165:
#line 436 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 166:
#line 440 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 167:
#line 444 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 168:
#line 445 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].intValue)); }
    break;

  case 169:
#line 449 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 170:
#line 450 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 171:
#line 454 "a.y"
    { (yyval.node) = string((yyvsp[(1) - (1)].sValue)); }
    break;

  case 172:
#line 458 "a.y"
    { (yyval.node) = xnull();}
    break;

  case 173:
#line 462 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 174:
#line 463 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 175:
#line 464 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 176:
#line 465 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 177:
#line 470 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 178:
#line 471 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 179:
#line 472 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 180:
#line 473 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 181:
#line 478 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 182:
#line 479 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 183:
#line 480 "a.y"
    { (yyval.node) = opr('!', 1, (yyvsp[(2) - (2)].node));}
    break;

  case 184:
#line 481 "a.y"
    { (yyval.node) = opr('>',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 185:
#line 482 "a.y"
    { (yyval.node) = opr('<',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 186:
#line 483 "a.y"
    { (yyval.node) = opr( LE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 187:
#line 484 "a.y"
    { (yyval.node) = opr( GE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 188:
#line 485 "a.y"
    { (yyval.node) = opr( EQ_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 189:
#line 486 "a.y"
    { (yyval.node) = opr( NE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 190:
#line 487 "a.y"
    { (yyval.node) = opr(AND_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 191:
#line 488 "a.y"
    { (yyval.node) = opr(OR_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 192:
#line 493 "a.y"
    { (yyval.node) = opr(XIS ,2 , (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 193:
#line 498 "a.y"
    { (yyval.node) = opr(INC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 194:
#line 499 "a.y"
    { (yyval.node) = opr(DEC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 195:
#line 500 "a.y"
    { (yyval.node) = sopr(INC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 196:
#line 501 "a.y"
    { (yyval.node) = sopr(DEC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 197:
#line 506 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:
#line 507 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 199:
#line 508 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 200:
#line 509 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:
#line 510 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:
#line 511 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:
#line 512 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:
#line 513 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 205:
#line 514 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 206:
#line 515 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:
#line 516 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 208:
#line 517 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 209:
#line 518 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 210:
#line 519 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 211:
#line 520 "a.y"
    { (yyval.node) =(yyvsp[(1) - (1)].node) ;}
    break;

  case 212:
#line 525 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 213:
#line 526 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 214:
#line 527 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 215:
#line 528 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 216:
#line 529 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 217:
#line 530 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 218:
#line 531 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 219:
#line 532 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 220:
#line 533 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 221:
#line 534 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 222:
#line 539 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 223:
#line 540 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node) ); }
    break;

  case 224:
#line 544 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 225:
#line 545 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 226:
#line 550 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), (yyvsp[(3) - (4)].intValue), NULL); }
    break;

  case 227:
#line 551 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 228:
#line 552 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 229:
#line 553 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].intValue), NULL) ; }
    break;

  case 230:
#line 554 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 231:
#line 555 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 232:
#line 556 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node),  (yyvsp[(3) - (4)].intValue), NULL ) ; }
    break;

  case 233:
#line 557 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 234:
#line 558 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 235:
#line 564 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 236:
#line 569 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 237:
#line 570 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 238:
#line 571 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 239:
#line 572 "a.y"
    { (yyval.node) = opr(ADD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 240:
#line 573 "a.y"
    { (yyval.node) = opr(SUB_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 241:
#line 574 "a.y"
    { (yyval.node) = opr(MUL_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 242:
#line 575 "a.y"
    { (yyval.node) = opr(DIV_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 243:
#line 576 "a.y"
    { (yyval.node) = opr(MOD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;


/* Line 1267 of yacc.c.  */
#line 3410 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 579 "a.y"


void yyerror(char *s) {
	fprintf(stderr, "%s on file %s line %d,column %d. near by '%s' \n", s , getParsingFilename() , getParseLineNo(),column , yytext  );
}

char *namespaceNameCat(char *arg1,char *arg2){
	int len = strlen(arg1) + strlen(arg2) + 1;
	char *p = (char*)calloc(1, len + 1);
	strcat(p,arg1);
	strcat(p,".");
	strcat(p,arg2);
	p[len] = '\0' ;
	
	free(arg1);
	free(arg2);
	return p;
}

int main(int argc, char *argv[]){
	if(argc <= 1){
		printf("no input file.\n");
		return 1;
	}
	
	initLangX();
	
	for(int i = 1; i < argc; i++)
		doFile(argv[i]);
	
	closeLangX();
	
	//printf("parse over!\n");
	return 0;
}

