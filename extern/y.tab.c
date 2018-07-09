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
#define YYLAST   1833

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNRULES -- Number of states.  */
#define YYNSTATES  474

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
     419,   421,   423,   425,   427,   429,   432,   434,   436,   438,
     440,   442,   444,   447,   449,   451,   454,   459,   464,   469,
     471,   476,   478,   482,   486,   487,   489,   491,   495,   497,
     499,   501,   503,   505,   507,   509,   511,   513,   515,   517,
     519,   521,   525,   527,   529,   531,   535,   539,   543,   547,
     551,   555,   559,   563,   567,   570,   574,   578,   580,   582,
     584,   586,   590,   596,   598,   600,   602,   604,   607,   610,
     612,   614,   616,   618,   620,   622,   624,   626,   628,   630,
     632,   634,   637,   641,   645,   649,   653,   657,   661,   665,
     669,   673,   676,   679,   682,   685,   687,   689,   691,   693,
     695,   697,   699,   701,   703,   705,   707,   709,   711,   713,
     715,   717,   719,   721,   723,   725,   727,   729,   731,   733,
     735,   739,   743,   747,   751,   756,   761,   766,   771,   776,
     781,   786,   791,   796,   800,   802,   804,   806,   810,   814,
     818,   822
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      96,     0,    -1,    97,    -1,    97,    98,    -1,    -1,    89,
      -1,   102,    -1,   126,    -1,   132,    89,    -1,    99,    -1,
     100,    -1,    39,   152,    -1,    40,   152,    -1,    62,   152,
      -1,    41,   109,    89,    -1,    25,    90,   124,    91,    -1,
      25,    90,   124,    91,   101,    -1,    26,    80,   148,    81,
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
      -1,   125,    -1,   161,    89,    -1,   119,    -1,    22,    -1,
      22,    84,   148,    -1,    22,    84,   148,    80,   138,    81,
      -1,    22,    84,   148,    -1,    22,    84,   116,    -1,   148,
      84,   148,    -1,   117,    84,   148,    -1,     6,    80,   138,
      81,    84,   148,    -1,   116,    84,   148,    -1,   148,    84,
     148,    80,   138,    81,    -1,   163,    84,   148,    80,   138,
      81,    -1,     6,    80,   138,    81,    84,   148,    80,   138,
      81,    -1,   116,    84,   148,    80,   138,    81,    -1,   117,
      84,   148,    80,   138,    81,    -1,   148,    37,   148,    -1,
      79,     6,    16,   122,    90,   124,    91,    -1,     6,    16,
     122,    90,   124,    91,    -1,     8,    16,   122,    90,   124,
      91,    -1,    80,   123,    81,    16,    90,   124,    91,    -1,
       6,    16,    90,   124,    91,    -1,   121,    16,    90,   124,
      91,    -1,     6,    66,     6,    -1,   121,    66,     6,    -1,
      -1,    80,   123,    81,    -1,     6,    -1,   123,    66,     6,
      -1,    -1,   124,    98,    -1,    -1,   148,    89,    -1,   148,
      66,   125,    -1,     6,    82,     3,    83,    89,    -1,     6,
      82,     3,    83,    66,   125,    -1,     6,    82,     6,    83,
      89,    -1,     6,    82,     6,    83,    66,   125,    -1,     6,
      82,   135,    83,    89,    -1,     6,    82,   135,    83,    66,
     125,    -1,   127,    -1,   130,    -1,    46,    80,   156,    81,
     141,    -1,    46,    80,   156,    81,   141,    47,   141,    -1,
      53,    80,   148,    81,    90,   128,    91,    -1,   129,    -1,
     128,   129,    -1,    54,   150,    93,   124,    -1,    55,    93,
     124,    -1,    48,    80,   156,    81,   141,    -1,    49,    80,
     131,    89,   156,    89,   131,    81,   141,    -1,    -1,   165,
      -1,   125,    -1,   158,    -1,   165,    -1,   135,    -1,    50,
       6,    -1,   134,    -1,   147,    -1,   133,    -1,    42,    -1,
     136,    -1,    21,    -1,    21,   149,    -1,    51,    -1,    52,
      -1,    52,   159,    -1,    52,    90,   139,    91,    -1,   163,
      80,   138,    81,    -1,     6,    80,   138,    81,    -1,   117,
      -1,   118,    80,   138,    81,    -1,   137,    -1,   135,    68,
     137,    -1,   135,    68,   135,    -1,    -1,   139,    -1,   140,
      -1,   139,    66,   140,    -1,   120,    -1,   149,    -1,   150,
      -1,     6,    -1,   152,    -1,   151,    -1,   135,    -1,   144,
      -1,   163,    -1,   116,    -1,   118,    -1,   147,    -1,    94,
      -1,    90,   124,    91,    -1,    98,    -1,   150,    -1,   143,
      -1,    80,   160,    81,    -1,   146,    73,   146,    -1,   146,
      74,   146,    -1,   146,    75,   146,    -1,   146,    76,   146,
      -1,   146,    77,   146,    -1,   145,    70,   145,    -1,   145,
      68,   145,    -1,   145,    69,   145,    -1,    79,   145,    -1,
     145,    31,   145,    -1,   145,    32,   145,    -1,     3,    -1,
     148,    -1,   160,    -1,   144,    -1,    80,   144,    81,    -1,
      58,   148,    80,   138,    81,    -1,     6,    -1,     5,    -1,
       4,    -1,     3,    -1,    74,   142,    -1,    74,   148,    -1,
       7,    -1,    61,    -1,   148,    -1,   135,    -1,   116,    -1,
     114,    -1,   160,    -1,   144,    -1,   149,    -1,   153,    -1,
     155,    -1,   157,    -1,    78,   154,    -1,   155,    71,   155,
      -1,   155,    72,   155,    -1,   155,    12,   155,    -1,   155,
      13,   155,    -1,   155,    14,   155,    -1,   155,    15,   155,
      -1,   156,    10,   156,    -1,   156,    11,   156,    -1,   148,
      36,   148,    -1,    17,   148,    -1,    18,   148,    -1,   148,
      17,    -1,   148,    18,    -1,   150,    -1,   151,    -1,   149,
      -1,   144,    -1,   135,    -1,   120,    -1,   148,    -1,   152,
      -1,   158,    -1,   147,    -1,   116,    -1,   153,    -1,   114,
      -1,   163,    -1,   118,    -1,   150,    -1,   151,    -1,   152,
      -1,   135,    -1,   148,    -1,   158,    -1,   116,    -1,   118,
      -1,   114,    -1,   163,    -1,   148,    67,   159,    -1,   148,
      67,   161,    -1,   116,    67,   159,    -1,   115,    67,   159,
      -1,     6,    82,     3,    83,    -1,     6,    82,     6,    83,
      -1,     6,    82,     7,    83,    -1,   116,    82,     3,    83,
      -1,   116,    82,     6,    83,    -1,   116,    82,     7,    83,
      -1,   135,    82,     3,    83,    -1,   135,    82,     6,    83,
      -1,   135,    82,     7,    83,    -1,   163,    67,   159,    -1,
     161,    -1,   162,    -1,   164,    -1,   148,    27,   160,    -1,
     148,    28,   160,    -1,   148,    29,   160,    -1,   148,    30,
     160,    -1,   148,    33,   160,    -1
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
     318,   323,   324,   328,   329,   330,   331,   336,   337,   338,
     339,   343,   344,   348,   352,   353,   357,   358,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   378,   379,   385,   386,   391,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   412,   413,   418,
     420,   421,   426,   430,   434,   438,   439,   443,   444,   448,
     452,   456,   457,   458,   459,   464,   465,   466,   467,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     487,   492,   493,   494,   495,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     533,   534,   538,   539,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   558,   563,   564,   565,   566,   567,   568,
     569,   570
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
  "restrict_stmt", "interrupt_stmt", "call_statement",
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
     132,   133,   133,   134,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   137,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   141,   141,   142,   142,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   145,   145,   146,
     146,   146,   147,   148,   149,   150,   150,   151,   151,   152,
     153,   154,   154,   154,   154,   155,   155,   155,   155,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   158,   158,   158,   158,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   161,   162,   162,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   164,   165,   165,   165,   165,   165,   165,
     165,   165
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
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     4,     4,     4,     1,
       4,     1,     3,     3,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     1,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     1,     1,     1,     3,     3,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   163,     0,   111,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,     5,     0,     3,
       9,    10,     6,    24,     0,    26,    22,    23,     0,    20,
       0,     0,   119,     0,    18,    19,     7,    88,    89,     0,
     108,   106,   104,   110,   121,   107,     0,   234,   235,     0,
     236,   103,    73,     0,   124,     0,     0,    73,   164,   112,
       0,    79,     0,   169,    11,    12,    33,     0,   163,    29,
       0,   163,     0,    31,    30,    43,     0,     0,    99,   105,
     166,   165,   163,     0,     0,    50,   170,     0,     0,    77,
       0,   218,   216,   217,   200,     0,   213,   160,     0,     0,
     204,   158,   197,   210,   211,   212,   206,   215,   115,   159,
     219,     0,   163,     0,    13,     0,    28,    25,    43,     0,
      27,    21,     0,     0,     0,     0,     0,   124,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,   124,     0,    77,     0,    44,   163,   140,   218,
     216,   217,   128,   213,     0,   125,   126,   160,   139,   214,
     129,   210,   211,   212,   215,   219,     0,   163,     0,     0,
       0,     0,     0,     0,     0,   163,    54,     0,    53,     0,
       0,     0,    14,     0,    28,     0,     0,     0,   216,   217,
     213,   176,   214,   177,   210,   211,   212,   178,   179,     0,
     180,   175,   219,     0,   163,   101,     0,     0,   102,   100,
       0,     0,     0,   191,   192,     0,   166,     0,   167,   144,
     168,   143,   157,   154,   158,   163,     0,   160,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   193,   194,     0,   124,    73,     0,    43,   223,   222,
       0,     0,     0,    58,    56,     0,   123,   122,     0,     0,
       0,   214,   237,   238,   239,   240,   241,    64,    81,   158,
     220,   221,    55,   233,     0,     0,    75,     0,    79,   118,
       0,   224,   225,   226,     0,   163,    35,     0,    45,    49,
      47,     0,     0,    79,    15,    78,    32,    34,     0,   163,
       0,   174,   173,   172,   171,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,    71,
       0,     0,    51,     0,     0,     0,   161,   116,    79,    72,
     155,   156,   152,   153,   151,   160,   146,   147,   148,   149,
     150,     0,     0,     0,     0,     0,   227,   228,   229,   124,
     124,   120,     0,   230,   231,   232,   124,   117,   124,    74,
       0,     0,   127,     0,    82,     0,    84,     0,    86,    36,
      46,    48,     0,     0,    16,     0,     0,    37,     0,   190,
     184,   185,   186,   187,   182,   183,   188,   189,    79,   142,
      90,    97,     0,     0,   224,   225,   124,   145,    76,     0,
       0,     0,   162,    79,    39,     0,     0,     0,     0,   123,
       0,     0,    66,    57,    83,    85,    87,    67,     0,    38,
       0,     0,    99,    69,     0,    79,    70,     0,     0,     0,
      93,     0,    40,    41,     0,    62,    63,    59,    60,   124,
       0,   141,    91,     0,    52,     0,     0,    79,    92,    94,
      65,    42,     0,     0,     0,    68,    79,    96,    61,    79,
      98,    95,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   305,    30,    31,   384,    32,    33,    34,
      35,    36,    37,    38,    77,    39,    66,   297,   298,   159,
      40,   198,    42,    43,    44,   162,   105,   155,   236,   189,
      45,    46,    47,   439,   440,    48,   216,    49,    50,    51,
     200,    53,    54,   164,   165,   166,   400,   228,   229,   167,
     108,   109,    55,   169,   170,   204,   205,   206,   207,   315,
     208,   209,   210,   174,   118,   119,    57,    58,   212,    60,
      61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -312
static const yytype_int16 yypact[] =
{
    -312,    14,  1717,  -312,   273,    36,    57,   -44,     7,   128,
     181,   181,   192,  -312,   211,    10,   245,   182,   201,   213,
     314,  -312,   684,   274,   368,   181,   384,  -312,    11,  -312,
    -312,  -312,  -312,  -312,    15,  -312,  -312,  -312,   294,  -312,
     329,   198,   322,   327,  -312,  -312,  -312,  -312,  -312,   334,
    -312,  -312,   -50,  -312,  -312,  -312,  1744,  -312,  -312,   134,
    -312,  -312,   376,   467,   642,   102,   386,   376,  -312,  -312,
     473,  -312,   425,  -312,  -312,  -312,  -312,   113,   440,  -312,
     -30,   147,   505,  -312,  -312,   501,   991,   991,   446,  -312,
     350,  -312,    -5,   368,   368,   445,  -312,   266,   265,  1095,
     642,   277,   377,   276,  -312,    21,   262,   283,   449,   506,
    -312,   470,  -312,   313,   316,   336,  -312,   365,  -312,  -312,
     252,   368,  -312,   450,  -312,   515,    22,  -312,   501,   526,
    -312,  -312,   819,   819,   585,   368,   368,   642,  -312,   473,
     591,   381,   381,   381,   381,   381,   368,   211,   819,   368,
    -312,   819,   642,   368,   533,   458,  -312,   268,  -312,  -312,
     356,   172,  -312,   220,   459,   484,  -312,   -17,  -312,   888,
    -312,   139,   226,   246,  -312,   429,   503,   361,   513,   256,
     279,    -8,   148,    19,   463,   409,   256,   502,    -8,  1146,
     192,   549,  -312,   421,  -312,   512,    32,  1127,   256,   327,
     502,   609,   662,  -312,  -312,  -312,  -312,  -312,   486,    78,
    -312,   707,   148,   155,   441,  -312,   519,  1276,  -312,  -312,
     522,   608,   600,  -312,  -312,   368,  -312,   381,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,   369,   -15,   534,   -18,   531,
     624,   265,   265,   265,   265,   265,  1127,  1127,  1127,  1127,
    1127,  -312,  -312,   550,   642,   376,   542,   501,  -312,  -312,
     551,   554,   555,   560,   562,   569,     1,  -312,   568,   571,
     572,   137,  -312,  -312,  -312,  -312,  -312,  -312,  -312,   552,
    -312,  -312,   563,  -312,   576,   578,  -312,    86,  -312,   579,
     642,   -19,     5,  -312,    24,    18,  -312,    20,  -312,  -312,
    -312,   221,   573,  -312,   626,  -312,   582,  -312,   584,   403,
      27,  -312,   256,   502,    -8,  -312,   368,   984,   984,   984,
     984,   984,   984,   991,   991,  1218,  1218,   991,  -312,  -312,
     586,   612,   616,   611,   691,   687,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,   427,   427,  -312,  -312,
    -312,   618,   628,   620,    35,   622,  -312,  -312,  -312,   642,
     642,  -312,   473,  -312,  -312,  -312,   642,  -312,   642,  -312,
    1277,   368,  -312,   211,  -312,   211,  -312,   211,  -312,  -312,
    -312,  -312,  1332,   638,  -312,   -19,     5,  -312,    59,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,   709,  -312,  -312,
     676,  -312,    47,  1387,  -312,  -312,   642,  -312,  -312,   634,
    1442,   324,  -312,  -312,  -312,   116,   117,   644,   647,   502,
     648,   652,  -312,   654,  -312,  -312,  -312,  -312,   368,  -312,
    1497,  1218,   446,  -312,   657,  -312,  -312,   408,   646,   118,
    -312,  1552,  -312,  -312,   121,  -312,  -312,  -312,  -312,   642,
     659,  -312,  -312,   660,  -312,  1607,   650,  -312,  -312,  -312,
    -312,  -312,   663,   645,  1218,  -312,  -312,  1717,  -312,  -312,
    -312,  1717,  1662,  -312
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,  -312,     3,  -312,  -312,  -312,  -312,  -312,  -312,
     713,  -312,  -312,  -312,   567,   178,   -82,  -301,  -287,    28,
    -312,   146,  -312,   715,  -139,    71,  -312,   -65,   598,   187,
      16,  -312,  -312,  -312,   320,  -312,   321,  -312,  -312,  -312,
     345,  -312,   621,  -133,   661,   476,  -311,  -312,  -312,   893,
     -59,   637,   656,    -2,   244,   617,   797,   167,   158,  -312,
     355,   -79,  -312,   -16,   442,   -63,  -141,  -312,   472,  -312,
     -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -215
static const yytype_int16 yytable[] =
{
      56,   219,   184,   195,   265,    29,   117,   281,   213,   388,
     380,   220,    80,    80,     3,   401,    81,   126,   139,   284,
     111,   128,   123,   211,   211,   295,   295,     5,     5,   146,
      79,    84,   140,   295,    62,     5,   147,   239,   185,   233,
      70,   295,   302,     5,   299,    63,   256,   373,   290,  -135,
     101,   334,    67,   415,    95,    16,    16,   323,   324,   150,
     129,   221,    68,   181,  -135,   295,   335,     5,   188,   362,
     374,   375,   218,   337,  -135,    64,   149,   222,   272,   273,
     274,   275,   276,   140,   202,   202,   217,   240,   323,   324,
     377,   223,   224,   104,   376,   230,   234,    71,    26,    26,
     193,   380,    82,    82,   215,   176,    26,    82,   177,   178,
     296,   379,   -43,   378,    26,   444,   117,   117,   387,   253,
     452,   352,   295,   295,     5,     5,   414,   295,   380,     5,
     111,   111,   117,   263,   264,   117,   432,   181,    26,   271,
     271,   271,   271,   271,   277,    80,   279,   282,    41,   111,
     429,   285,   334,   470,   251,   252,   302,   380,   299,   325,
     101,   101,    72,   278,   333,   323,   324,   369,   102,   302,
      63,   299,   437,   438,   146,   355,   101,    74,    75,   101,
     116,   301,   340,   341,   342,   343,   344,    56,    73,   115,
     353,   181,   124,    83,   314,    26,    26,   191,    76,   300,
      26,   151,   192,   104,   104,  -130,   127,   442,   443,   458,
     160,   179,   461,   302,   152,   299,   186,    78,   153,   104,
    -130,   149,   104,   332,   311,   271,   417,   418,   152,   193,
    -130,   173,   153,   420,    41,   421,   326,   -43,  -138,   234,
     234,   234,   234,   234,   396,   397,   160,   302,   402,   299,
      69,    85,   137,  -138,   211,   211,   211,   211,   211,   211,
     211,   211,    86,  -138,   211,   133,   112,   173,   232,   226,
      91,   122,   122,   434,   302,   302,   299,   299,   102,   102,
     134,    87,   135,   160,   220,   179,  -134,   147,   148,    62,
     116,   116,  -133,    88,   102,   301,    63,   102,   160,   115,
     115,  -134,   140,   302,   173,   299,   116,  -133,   301,   116,
     150,  -134,  -132,   300,   389,   115,   462,  -133,   115,   173,
      89,   202,   202,    56,    56,   202,   300,  -132,   399,   399,
     203,   203,   152,  -208,  -131,    41,   153,  -132,   134,   179,
     135,  -208,   312,  -199,   140,   219,   227,    52,    64,  -131,
     222,  -199,   301,    64,   121,    65,   137,  -209,  -207,  -131,
     181,   140,   294,   -43,  -198,  -209,  -207,   106,    56,   423,
     300,    80,  -198,    80,   122,    80,   112,   112,   437,   438,
      56,  -157,  -157,   131,   226,    91,   301,   185,    73,   424,
     125,   425,   112,   426,  -195,   112,   132,  -196,    93,    94,
     160,    56,  -195,    95,   300,  -196,   136,   137,    56,   163,
     180,   226,    91,   301,   301,   187,   218,  -202,  -157,  -157,
    -157,   173,  -137,   138,   308,  -202,   450,   309,    56,    56,
     217,   300,   300,   187,   399,   -75,   160,  -137,   134,    56,
     135,    64,   301,   222,   292,   163,  -203,  -137,   215,    64,
     -75,   222,   214,    56,  -203,    97,   154,   173,  -205,   134,
     300,   135,    56,    93,    94,    56,  -205,   399,     7,    56,
      56,    41,    41,   156,    59,   370,   183,   106,   106,   185,
     241,   242,   163,    64,   266,   222,   386,   251,   252,    64,
     382,   222,   190,   106,   120,  -136,   106,   163,   317,   318,
     319,   320,   248,   249,   250,   160,   160,   146,   179,   152,
    -136,   194,   160,   153,   160,   403,    41,   243,   244,   245,
    -136,    64,   193,    65,    63,   410,   173,   173,    41,   225,
     254,   255,   257,   173,    52,   173,   175,   182,   180,   286,
     289,   313,   182,  -214,  -214,  -214,  -214,  -214,   288,    41,
     290,  -201,   160,   303,   149,   307,    41,   321,   322,  -201,
      59,   203,   203,   203,   203,   203,   203,   203,   203,   251,
     252,   203,   175,   173,   258,   259,    41,    41,    41,   246,
     247,   248,   249,   250,   140,   430,   291,    41,   260,   146,
     280,   261,   262,   283,   268,   160,   293,   269,   270,   163,
     441,    41,   310,   330,   120,   120,   331,   178,   327,   175,
      41,   182,   328,    41,   329,   336,   173,    41,    41,   148,
     120,   338,   455,   120,   175,  -214,  -214,  -214,  -214,  -214,
     339,   351,   354,  -201,   356,   163,   149,   357,   358,   113,
     359,  -201,   360,   366,   467,    90,    91,    68,   157,    73,
     361,   363,   383,   471,   364,   365,   472,   367,   368,    93,
      94,    59,   381,   371,    95,   182,   191,   385,   182,   404,
      52,    52,   390,   391,   392,   393,   394,   395,   110,   251,
     252,   171,  -160,  -160,  -160,  -160,  -160,    90,    91,    68,
      92,    73,   407,  -158,  -158,   405,   406,   408,   316,   146,
      24,    93,    94,   409,   163,   163,    95,   419,   411,   412,
     413,   163,   416,   163,   231,    52,    97,   171,   428,   323,
     168,    98,    99,   431,   435,   445,   175,    52,   446,   447,
    -158,  -158,  -158,   448,   449,   469,   158,   103,   454,   457,
     463,   464,    24,   466,   468,    96,   149,   130,    52,   113,
     113,   163,   287,   453,   171,    52,   168,   306,    97,   459,
     267,   238,   175,    98,    99,   113,   372,     0,   113,   171,
       0,     0,     0,     0,   100,    52,    52,   187,     0,   161,
    -159,  -159,  -159,  -159,  -159,     0,    52,     0,   110,   110,
       0,     0,     0,   168,   163,     0,     0,    59,    59,     0,
      52,   199,   199,     0,   110,     0,     0,   110,   168,    52,
       0,     0,    52,     0,   199,   161,    52,    52,     0,   114,
       0,     0,    90,    91,    68,    92,    73,     0,     0,     0,
       0,   175,   175,     0,   182,     0,    93,    94,   175,     0,
     175,    95,    59,     0,     0,     0,     0,   103,   103,     0,
       0,     0,   161,     0,    59,     0,   199,   199,   199,   199,
     199,   172,     0,   103,     0,     0,   103,   161,     0,     0,
       0,   171,     0,     0,     0,    59,     0,    24,   175,     0,
      96,     0,    59,   346,   347,   348,   349,   350,     0,     0,
       0,     0,     0,    97,     0,     0,     0,   172,    98,    99,
       0,     0,    59,    59,    59,   251,   252,   171,     0,     0,
     168,     0,   199,    59,     0,   107,     0,     0,     0,  -158,
    -158,   175,     0,     0,     0,   146,     0,    59,     0,   114,
     114,     0,     0,     0,   172,     0,    59,     0,     0,    59,
       0,     0,   199,    59,    59,   114,   168,     0,   114,   172,
       0,     0,     0,     0,     0,     0,  -158,  -158,  -158,     0,
       0,   199,   199,   199,   199,   199,     0,     0,     0,   161,
       0,     0,   149,     0,     0,     0,   171,   171,     0,   201,
     201,     0,     0,   171,     0,   171,     0,    90,    91,    68,
     185,    73,   237,     0,    90,    91,    68,   185,    73,     0,
       0,    93,    94,     0,     0,   161,    95,     0,    93,    94,
       0,     0,     0,    95,     0,   168,   168,     0,     0,     0,
       0,     0,   168,   171,   168,   107,   107,     0,     0,     0,
       0,     0,   199,   199,   199,   199,   199,   199,   199,   199,
       0,   107,   199,     0,   107,    96,     0,     0,     0,     0,
       0,   172,    96,     0,   456,     0,     0,     0,    97,     0,
       0,     0,   168,    98,   197,    97,   171,     0,     0,   196,
      98,   197,     0,     0,   161,   161,     0,     0,     0,     0,
       0,   161,     0,   161,     0,     0,     0,   172,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,    90,    91,
       0,   235,    73,     0,     0,   168,     0,     0,     0,     0,
       0,     0,    93,    94,     0,     0,     0,    95,     0,     0,
       0,   161,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,     0,   185,    73,     0,     0,     0,     0,   345,
     345,   345,   345,   345,    93,    94,     0,     0,     0,    95,
       0,     0,     4,     0,     5,     0,   172,   172,     0,     0,
       0,     0,     0,   172,   161,   172,     0,     6,     7,    97,
       0,     8,     0,     0,    98,   197,     0,     0,     0,     0,
       0,     9,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,     0,    18,    19,    20,    21,    22,    23,
       0,    97,     0,   172,    24,     0,    98,   197,    25,     0,
     201,   201,   201,   201,   201,   201,   201,   201,     0,     0,
     201,     0,     0,     0,     4,    26,     5,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,   304,    28,     6,
       7,     0,     0,     8,     0,     0,   172,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,    17,     0,    18,    19,    20,    21,
      22,    23,     0,     0,     0,     0,    24,     0,     0,     0,
      25,     0,     0,     4,     0,     5,     0,     0,     0,     0,
       0,     0,     0,   251,   252,     0,     0,    26,     6,     7,
       0,     0,     8,   141,   142,   143,   144,    27,   398,   145,
      28,     0,     9,   146,     0,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     0,     4,    25,
       5,     0,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,    26,     8,     0,     0,
     149,     0,     0,     0,     0,   150,    27,     9,   422,    28,
       0,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     4,    25,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,    26,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     9,   427,    28,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     0,     4,    25,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,    26,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     9,   433,    28,
       0,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     4,    25,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,    26,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     9,   436,    28,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     0,     4,    25,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,    26,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     9,   451,    28,
       0,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     4,    25,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,    26,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     9,   460,    28,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     0,     4,    25,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,    26,     8,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     9,   465,    28,
       0,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     4,    25,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,    26,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     9,   473,    28,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,   141,   142,   143,   144,    24,     0,   145,     0,    25,
       0,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,     0,    28,
     147,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   149,     0,
       0,     0,     0,   150
};

static const yytype_int16 yycheck[] =
{
       2,    88,    67,    85,   137,     2,    22,   148,    87,   310,
     297,    16,    14,    15,     0,   326,     6,     6,    68,   152,
      22,     6,    24,    86,    87,     6,     6,     8,     8,    37,
      14,    15,    82,     6,    16,     8,    66,    16,     6,    98,
      84,     6,   183,     8,   183,    23,   128,    66,    66,    66,
      22,    66,    16,   354,    22,    45,    45,    10,    11,    89,
      45,    66,     5,    65,    81,     6,    81,     8,    70,    68,
      89,    66,    88,    91,    91,    80,    84,    82,   141,   142,
     143,   144,   145,    82,    86,    87,    88,    66,    10,    11,
      66,    93,    94,    22,    89,    97,    98,    90,    79,    79,
      82,   388,    92,    92,    88,     3,    79,    92,     6,     7,
      91,    91,    90,    89,    79,   416,   132,   133,    91,   121,
     431,   254,     6,     6,     8,     8,    91,     6,   415,     8,
     132,   133,   148,   135,   136,   151,    89,   139,    79,   141,
     142,   143,   144,   145,   146,   147,   148,   149,     2,   151,
      91,   153,    66,   464,    17,    18,   297,   444,   297,    81,
     132,   133,    34,   147,   227,    10,    11,    81,    22,   310,
      23,   310,    54,    55,    37,   257,   148,    10,    11,   151,
      22,   183,   241,   242,   243,   244,   245,   189,     7,    22,
     255,   193,    25,    15,   196,    79,    79,    84,     6,   183,
      79,    67,    89,   132,   133,    66,    28,    91,    91,    91,
      64,    65,    91,   354,    80,   354,    70,     6,    84,   148,
      81,    84,   151,   225,   196,   227,   359,   360,    80,    82,
      91,    64,    84,   366,    88,   368,    81,    90,    66,   241,
     242,   243,   244,   245,   323,   324,   100,   388,   327,   388,
       6,     6,    80,    81,   317,   318,   319,   320,   321,   322,
     323,   324,    80,    91,   327,    67,    22,   100,     3,     3,
       4,     6,     6,   406,   415,   416,   415,   416,   132,   133,
      82,    80,    84,   137,    16,   139,    66,    66,    67,    16,
     132,   133,    66,    80,   148,   297,    23,   151,   152,   132,
     133,    81,    82,   444,   137,   444,   148,    81,   310,   151,
      89,    91,    66,   297,   316,   148,   449,    91,   151,   152,
       6,   323,   324,   325,   326,   327,   310,    81,   325,   326,
      86,    87,    80,    81,    66,   189,    84,    91,    82,   193,
      84,    89,   196,    81,    82,   432,    80,     2,    80,    81,
      82,    89,   354,    80,    80,    82,    80,    81,    81,    91,
     362,    82,    83,    90,    81,    89,    89,    22,   370,   371,
     354,   373,    89,   375,     6,   377,   132,   133,    54,    55,
     382,    31,    32,    89,     3,     4,   388,     6,     7,   373,
       6,   375,   148,   377,    81,   151,    67,    81,    17,    18,
     254,   403,    89,    22,   388,    89,    84,    80,   410,    64,
      65,     3,     4,   415,   416,    70,   432,    81,    68,    69,
      70,   254,    66,    89,     3,    89,   428,     6,   430,   431,
     432,   415,   416,    88,   431,    66,   290,    81,    82,   441,
      84,    80,   444,    82,    83,   100,    81,    91,   432,    80,
      81,    82,     6,   455,    89,    74,    80,   290,    81,    82,
     444,    84,   464,    17,    18,   467,    89,   464,    22,   471,
     472,   325,   326,     6,     2,   288,    90,   132,   133,     6,
      31,    32,   137,    80,   139,    82,    83,    17,    18,    80,
     303,    82,    67,   148,    22,    66,   151,   152,    12,    13,
      14,    15,    75,    76,    77,   359,   360,    37,   362,    80,
      81,     6,   366,    84,   368,   328,   370,    68,    69,    70,
      91,    80,    82,    82,    23,   338,   359,   360,   382,    84,
      80,    16,     6,   366,   189,   368,    64,    65,   193,     6,
      81,   196,    70,    73,    74,    75,    76,    77,    90,   403,
      66,    81,   406,    90,    84,     6,   410,    71,    72,    89,
      88,   317,   318,   319,   320,   321,   322,   323,   324,    17,
      18,   327,   100,   406,   132,   133,   430,   431,   432,    73,
      74,    75,    76,    77,    82,   398,    83,   441,     3,    37,
     148,     6,     7,   151,     3,   449,    83,     6,     7,   254,
     413,   455,    90,     3,   132,   133,     6,     7,    89,   137,
     464,   139,    90,   467,     6,    81,   449,   471,   472,    67,
     148,    90,   435,   151,   152,    73,    74,    75,    76,    77,
       6,    81,    90,    81,    83,   290,    84,    83,    83,    22,
      80,    89,    80,    80,   457,     3,     4,     5,     6,     7,
      81,    83,    26,   466,    83,    83,   469,    81,    80,    17,
      18,   189,    89,    84,    22,   193,    84,    83,   196,    83,
     325,   326,   317,   318,   319,   320,   321,   322,    22,    17,
      18,    64,    73,    74,    75,    76,    77,     3,     4,     5,
       6,     7,    81,    31,    32,    83,    80,     6,    36,    37,
      58,    17,    18,    16,   359,   360,    22,   362,    90,    81,
      90,   366,    90,   368,    97,   370,    74,   100,    80,    10,
      64,    79,    80,    47,    90,    81,   254,   382,    81,    81,
      68,    69,    70,    81,    80,    90,    94,    22,    81,    93,
      81,    81,    58,    93,    81,    61,    84,    34,   403,   132,
     133,   406,   154,   432,   137,   410,   100,   190,    74,   439,
     139,   100,   290,    79,    80,   148,   290,    -1,   151,   152,
      -1,    -1,    -1,    -1,    90,   430,   431,   432,    -1,    64,
      73,    74,    75,    76,    77,    -1,   441,    -1,   132,   133,
      -1,    -1,    -1,   137,   449,    -1,    -1,   325,   326,    -1,
     455,    86,    87,    -1,   148,    -1,    -1,   151,   152,   464,
      -1,    -1,   467,    -1,    99,   100,   471,   472,    -1,    22,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,   359,   360,    -1,   362,    -1,    17,    18,   366,    -1,
     368,    22,   370,    -1,    -1,    -1,    -1,   132,   133,    -1,
      -1,    -1,   137,    -1,   382,    -1,   141,   142,   143,   144,
     145,    64,    -1,   148,    -1,    -1,   151,   152,    -1,    -1,
      -1,   254,    -1,    -1,    -1,   403,    -1,    58,   406,    -1,
      61,    -1,   410,   246,   247,   248,   249,   250,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,   100,    79,    80,
      -1,    -1,   430,   431,   432,    17,    18,   290,    -1,    -1,
     254,    -1,   197,   441,    -1,    22,    -1,    -1,    -1,    31,
      32,   449,    -1,    -1,    -1,    37,    -1,   455,    -1,   132,
     133,    -1,    -1,    -1,   137,    -1,   464,    -1,    -1,   467,
      -1,    -1,   227,   471,   472,   148,   290,    -1,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,    -1,
      -1,   246,   247,   248,   249,   250,    -1,    -1,    -1,   254,
      -1,    -1,    84,    -1,    -1,    -1,   359,   360,    -1,    86,
      87,    -1,    -1,   366,    -1,   368,    -1,     3,     4,     5,
       6,     7,    99,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    17,    18,    -1,    -1,   290,    22,    -1,    17,    18,
      -1,    -1,    -1,    22,    -1,   359,   360,    -1,    -1,    -1,
      -1,    -1,   366,   406,   368,   132,   133,    -1,    -1,    -1,
      -1,    -1,   317,   318,   319,   320,   321,   322,   323,   324,
      -1,   148,   327,    -1,   151,    61,    -1,    -1,    -1,    -1,
      -1,   254,    61,    -1,   437,    -1,    -1,    -1,    74,    -1,
      -1,    -1,   406,    79,    80,    74,   449,    -1,    -1,    78,
      79,    80,    -1,    -1,   359,   360,    -1,    -1,    -1,    -1,
      -1,   366,    -1,   368,    -1,    -1,    -1,   290,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,     6,     7,    -1,    -1,   449,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,   250,    17,    18,    -1,    -1,    -1,    22,
      -1,    -1,     6,    -1,     8,    -1,   359,   360,    -1,    -1,
      -1,    -1,    -1,   366,   449,   368,    -1,    21,    22,    74,
      -1,    25,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    74,    -1,   406,    58,    -1,    79,    80,    62,    -1,
     317,   318,   319,   320,   321,   322,   323,   324,    -1,    -1,
     327,    -1,    -1,    -1,     6,    79,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    -1,    91,    92,    21,
      22,    -1,    -1,    25,    -1,    -1,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    -1,    -1,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    79,    21,    22,
      -1,    -1,    25,    27,    28,    29,    30,    89,    90,    33,
      92,    -1,    35,    37,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,     6,    62,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    -1,    79,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    35,    91,    92,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      -1,    79,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,    35,    91,    92,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    27,    28,    29,    30,    58,    -1,    33,    -1,    62,
      -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,    97,     0,     6,     8,    21,    22,    25,    35,
      39,    40,    41,    42,    43,    44,    45,    46,    48,    49,
      50,    51,    52,    53,    58,    62,    79,    89,    92,    98,
      99,   100,   102,   103,   104,   105,   106,   107,   108,   110,
     115,   116,   117,   118,   119,   125,   126,   127,   130,   132,
     133,   134,   135,   136,   137,   147,   148,   161,   162,   163,
     164,   165,    16,    23,    80,    82,   111,    16,     5,   149,
      84,    90,    34,     7,   152,   152,     6,   109,     6,   125,
     148,     6,    92,   110,   125,     6,    80,    80,    80,     6,
       3,     4,     6,    17,    18,    22,    61,    74,    79,    80,
      90,   114,   116,   118,   120,   121,   135,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   158,   159,   160,
     163,    80,     6,   148,   152,     6,     6,   110,     6,    45,
     105,    89,    67,    67,    82,    84,    84,    80,    89,    68,
      82,    27,    28,    29,    30,    33,    37,    66,    67,    84,
      89,    67,    80,    84,    80,   122,     6,     6,    94,   114,
     116,   118,   120,   135,   138,   139,   140,   144,   147,   148,
     149,   150,   151,   152,   158,   163,     3,     6,     7,   116,
     135,   148,   163,    90,   122,     6,   116,   135,   148,   124,
      67,    84,    89,    82,     6,   111,    78,    80,   116,   118,
     135,   144,   148,   149,   150,   151,   152,   153,   155,   156,
     157,   160,   163,   156,     6,   125,   131,   148,   158,   165,
      16,    66,    82,   148,   148,    84,     3,    80,   142,   143,
     148,   150,     3,   145,   148,     6,   123,   144,   139,    16,
      66,    31,    32,    68,    69,    70,    73,    74,    75,    76,
      77,    17,    18,   148,    80,    16,   111,     6,   159,   159,
       3,     6,     7,   148,   148,   138,   135,   137,     3,     6,
       7,   148,   160,   160,   160,   160,   160,   148,   125,   148,
     159,   161,   148,   159,   138,   148,     6,   123,    90,    81,
      66,    83,    83,    83,    83,     6,    91,   112,   113,   119,
     125,   148,   161,    90,    91,    98,   109,     6,     3,     6,
      90,   114,   116,   135,   148,   154,    36,    12,    13,    14,
      15,    71,    72,    10,    11,    81,    81,    89,    90,     6,
       3,     6,   148,   160,    66,    81,    81,    91,    90,     6,
     145,   145,   145,   145,   145,   144,   146,   146,   146,   146,
     146,    81,   138,   122,    90,   111,    83,    83,    83,    80,
      80,    81,    68,    83,    83,    83,    80,    81,    80,    81,
     124,    84,   140,    66,    89,    66,    89,    66,    89,    91,
     113,    89,   124,    26,   101,    83,    83,    91,   112,   148,
     155,   155,   155,   155,   155,   155,   156,   156,    90,    98,
     141,   141,   156,   124,    83,    83,    80,    81,     6,    16,
     124,    90,    81,    90,    91,   112,    90,   138,   138,   135,
     138,   138,    91,   148,   125,   125,   125,    91,    80,    91,
     124,    47,    89,    91,   138,    90,    91,    54,    55,   128,
     129,   124,    91,    91,   112,    81,    81,    81,    81,    80,
     148,    91,   141,   131,    81,   124,   150,    93,    91,   129,
      91,    91,   138,    81,    81,    91,    93,   124,    81,    90,
     141,   124,   124,    91
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
    { (yyval.node) = opr(DELETE, 1 ,(yyvsp[(2) - (2)].sValue) ); }
    break;

  case 106:
#line 314 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
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
    { (yyval.node) = opr(XCONTINUE , 0 ); }
    break;

  case 110:
#line 318 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 111:
#line 323 "a.y"
    { (yyval.node) = opr(RESTRICT,0);}
    break;

  case 112:
#line 324 "a.y"
    { (yyval.node) = opr(RESTRICT,1,(yyvsp[(2) - (2)].node)); }
    break;

  case 113:
#line 328 "a.y"
    { (yyval.node) = opr(BREAK, 0); }
    break;

  case 114:
#line 329 "a.y"
    { (yyval.node) = opr(RETURN , 0); }
    break;

  case 115:
#line 330 "a.y"
    { (yyval.node) = opr(RETURN , 1 ,(yyvsp[(2) - (2)].node));}
    break;

  case 116:
#line 331 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 117:
#line 336 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, (yyvsp[(1) - (4)].node), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 118:
#line 337 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, var((yyvsp[(1) - (4)].sValue)), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 119:
#line 338 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 120:
#line 339 "a.y"
    { (yyval.node) = opr(SCOPE_FUNC_CALL,2,(yyvsp[(1) - (4)].node),argsNode((yyvsp[(3) - (4)].args))); }
    break;

  case 121:
#line 343 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 122:
#line 344 "a.y"
    { (yyval.node) = NULL ;}
    break;

  case 123:
#line 348 "a.y"
    { (yyval.node) = NULL ;}
    break;

  case 124:
#line 352 "a.y"
    { (yyval.args) = NULL; }
    break;

  case 125:
#line 353 "a.y"
    { (yyval.args) = (yyvsp[(1) - (1)].args); }
    break;

  case 126:
#line 357 "a.y"
    { (yyval.args) = xArgs(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 127:
#line 358 "a.y"
    { (yyval.args) = xArgs((yyvsp[(1) - (3)].args), (yyvsp[(3) - (3)].node)); }
    break;

  case 128:
#line 362 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 129:
#line 363 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 130:
#line 364 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 131:
#line 365 "a.y"
    { /*printf("IDENTIFIER $1= %s\n" , $1);*/ (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 132:
#line 366 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 133:
#line 367 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 134:
#line 368 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 135:
#line 369 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 136:
#line 370 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 137:
#line 371 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 138:
#line 372 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 139:
#line 373 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 140:
#line 374 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 141:
#line 378 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 142:
#line 379 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 143:
#line 385 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 144:
#line 386 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 145:
#line 391 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 146:
#line 397 "a.y"
    { (yyval.node) = opr('+',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 147:
#line 398 "a.y"
    { (yyval.node) = opr('-',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 148:
#line 399 "a.y"
    { (yyval.node) = opr('*',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 149:
#line 400 "a.y"
    { (yyval.node) = opr('/',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 150:
#line 401 "a.y"
    { (yyval.node) = opr('%',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 151:
#line 402 "a.y"
    { (yyval.node) = opr('&',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 152:
#line 403 "a.y"
    { (yyval.node) = opr('|',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 153:
#line 404 "a.y"
    { (yyval.node) = opr('^',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 154:
#line 405 "a.y"
    { /* printf("get a ~ opr.\n"); */ (yyval.node) = opr('~',1,(yyvsp[(2) - (2)].node)); }
    break;

  case 155:
#line 406 "a.y"
    { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 156:
#line 407 "a.y"
    { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 157:
#line 412 "a.y"
    { (yyval.node) = xint((yyvsp[(1) - (1)].intValue)); }
    break;

  case 158:
#line 413 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 159:
#line 418 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 160:
#line 420 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 161:
#line 421 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node) ; }
    break;

  case 162:
#line 426 "a.y"
    { (yyval.node) = opr(NEW ,2, (yyvsp[(2) - (5)].node) , argsNode((yyvsp[(4) - (5)].args)) ); }
    break;

  case 163:
#line 430 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 164:
#line 434 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 165:
#line 438 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 166:
#line 439 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].intValue)); }
    break;

  case 167:
#line 443 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 168:
#line 444 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 169:
#line 448 "a.y"
    { (yyval.node) = string((yyvsp[(1) - (1)].sValue)); }
    break;

  case 170:
#line 452 "a.y"
    { (yyval.node) = xnull();}
    break;

  case 171:
#line 456 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 172:
#line 457 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 173:
#line 458 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 174:
#line 459 "a.y"
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
#line 466 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 178:
#line 467 "a.y"
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
#line 474 "a.y"
    { (yyval.node) = opr('!', 1, (yyvsp[(2) - (2)].node));}
    break;

  case 182:
#line 475 "a.y"
    { (yyval.node) = opr('>',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 183:
#line 476 "a.y"
    { (yyval.node) = opr('<',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 184:
#line 477 "a.y"
    { (yyval.node) = opr( LE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 185:
#line 478 "a.y"
    { (yyval.node) = opr( GE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 186:
#line 479 "a.y"
    { (yyval.node) = opr( EQ_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 187:
#line 480 "a.y"
    { (yyval.node) = opr( NE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 188:
#line 481 "a.y"
    { (yyval.node) = opr(AND_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 189:
#line 482 "a.y"
    { (yyval.node) = opr(OR_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 190:
#line 487 "a.y"
    { (yyval.node) = opr(XIS ,2 , (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 191:
#line 492 "a.y"
    { (yyval.node) = opr(INC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 192:
#line 493 "a.y"
    { (yyval.node) = opr(DEC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 193:
#line 494 "a.y"
    { (yyval.node) = sopr(INC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 194:
#line 495 "a.y"
    { (yyval.node) = sopr(DEC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 195:
#line 500 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 196:
#line 501 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 197:
#line 502 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:
#line 503 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 199:
#line 504 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 200:
#line 505 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:
#line 506 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:
#line 507 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:
#line 508 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:
#line 509 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 205:
#line 510 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 206:
#line 511 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:
#line 512 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 208:
#line 513 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 209:
#line 514 "a.y"
    { (yyval.node) =(yyvsp[(1) - (1)].node) ;}
    break;

  case 210:
#line 519 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 211:
#line 520 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 212:
#line 521 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 213:
#line 522 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 214:
#line 523 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 215:
#line 524 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 216:
#line 525 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 217:
#line 526 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 218:
#line 527 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 219:
#line 528 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 220:
#line 533 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 221:
#line 534 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node) ); }
    break;

  case 222:
#line 538 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 223:
#line 539 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 224:
#line 544 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), (yyvsp[(3) - (4)].intValue), NULL); }
    break;

  case 225:
#line 545 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 226:
#line 546 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 227:
#line 547 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].intValue), NULL) ; }
    break;

  case 228:
#line 548 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 229:
#line 549 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 230:
#line 550 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node),  (yyvsp[(3) - (4)].intValue), NULL ) ; }
    break;

  case 231:
#line 551 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 232:
#line 552 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 233:
#line 558 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 234:
#line 563 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 235:
#line 564 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 236:
#line 565 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 237:
#line 566 "a.y"
    { (yyval.node) = opr(ADD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 238:
#line 567 "a.y"
    { (yyval.node) = opr(SUB_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 239:
#line 568 "a.y"
    { (yyval.node) = opr(MUL_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 240:
#line 569 "a.y"
    { (yyval.node) = opr(DIV_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 241:
#line 570 "a.y"
    { (yyval.node) = opr(MOD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;


/* Line 1267 of yacc.c.  */
#line 3394 "y.tab.c"
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


#line 573 "a.y"


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

