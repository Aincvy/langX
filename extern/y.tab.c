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
#define YYLAST   1824

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  236
/* YYNRULES -- Number of states.  */
#define YYNSTATES  468

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
       2,     2,     2,     2,     2,     2,    93,    77,    70,     2,
      80,    81,    75,    73,    66,    74,    79,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    92,    88,
      72,    67,    71,     2,    91,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,    68,    90,    78,     2,     2,     2,
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
      65,    84,    85,    86,    87
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
     612,   614,   616,   618,   620,   622,   624,   626,   630,   634,
     638,   642,   646,   650,   654,   658,   662,   665,   668,   671,
     674,   676,   678,   680,   682,   684,   686,   688,   690,   692,
     694,   696,   698,   700,   702,   704,   706,   708,   710,   712,
     714,   716,   718,   720,   722,   724,   728,   732,   736,   740,
     745,   750,   755,   760,   765,   770,   775,   780,   785,   789,
     791,   793,   795,   799,   803,   807,   811
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      95,     0,    -1,    96,    -1,    96,    97,    -1,    -1,    88,
      -1,   101,    -1,   125,    -1,   131,    88,    -1,    98,    -1,
      99,    -1,    39,   151,    -1,    40,   151,    -1,    62,   151,
      -1,    41,   108,    88,    -1,    25,    89,   123,    90,    -1,
      25,    89,   123,    90,   100,    -1,    26,    80,   147,    81,
      89,   123,    90,    -1,   118,    -1,   124,    -1,   109,    -1,
     107,    88,    -1,   105,    -1,   106,    -1,   102,    -1,    91,
     109,    -1,   104,    -1,   103,   104,    -1,    91,     6,    -1,
      43,   124,    -1,    44,   124,    -1,    44,   109,    -1,    35,
      34,    67,   108,    -1,     6,    -1,   108,    79,     6,    -1,
       6,   110,    89,    90,    -1,     6,   110,    89,   111,    90,
      -1,    45,     6,   110,    89,    90,    -1,    45,     6,   110,
      89,   111,    90,    -1,   103,     6,   110,    89,    90,    -1,
     103,     6,   110,    89,   111,    90,    -1,   103,    45,     6,
     110,    89,    90,    -1,   103,    45,     6,   110,    89,   111,
      90,    -1,    -1,    23,     6,    -1,   112,    -1,   111,   112,
      -1,   124,    -1,   159,    88,    -1,   118,    -1,    22,    -1,
      22,    79,   147,    -1,    22,    79,   147,    80,   137,    81,
      -1,    22,    79,   147,    -1,    22,    79,   115,    -1,   147,
      79,   147,    -1,   116,    79,   147,    -1,     6,    80,   137,
      81,    79,   147,    -1,   115,    79,   147,    -1,   147,    79,
     147,    80,   137,    81,    -1,   161,    79,   147,    80,   137,
      81,    -1,     6,    80,   137,    81,    79,   147,    80,   137,
      81,    -1,   115,    79,   147,    80,   137,    81,    -1,   116,
      79,   147,    80,   137,    81,    -1,   147,    37,   147,    -1,
      78,     6,    16,   121,    89,   123,    90,    -1,     6,    16,
     121,    89,   123,    90,    -1,     8,    16,   121,    89,   123,
      90,    -1,    80,   122,    81,    16,    89,   123,    90,    -1,
       6,    16,    89,   123,    90,    -1,   120,    16,    89,   123,
      90,    -1,     6,    66,     6,    -1,   120,    66,     6,    -1,
      -1,    80,   122,    81,    -1,     6,    -1,   122,    66,     6,
      -1,    -1,   123,    97,    -1,    -1,   147,    88,    -1,   147,
      66,   124,    -1,     6,    82,     3,    83,    88,    -1,     6,
      82,     3,    83,    66,   124,    -1,     6,    82,     6,    83,
      88,    -1,     6,    82,     6,    83,    66,   124,    -1,     6,
      82,   134,    83,    88,    -1,     6,    82,   134,    83,    66,
     124,    -1,   126,    -1,   129,    -1,    46,    80,   154,    81,
     140,    -1,    46,    80,   154,    81,   140,    47,   140,    -1,
      53,    80,   147,    81,    89,   127,    90,    -1,   128,    -1,
     127,   128,    -1,    54,   149,    92,   123,    -1,    55,    92,
     123,    -1,    48,    80,   154,    81,   140,    -1,    49,    80,
     130,    88,   154,    88,   130,    81,   140,    -1,    -1,   163,
      -1,   124,    -1,   156,    -1,   163,    -1,   134,    -1,    50,
       6,    -1,   133,    -1,   146,    -1,   132,    -1,    42,    -1,
     135,    -1,    21,    -1,    21,   148,    -1,    51,    -1,    52,
      -1,    52,   157,    -1,    52,    89,   138,    90,    -1,   161,
      80,   137,    81,    -1,     6,    80,   137,    81,    -1,   116,
      -1,   117,    80,   137,    81,    -1,   136,    -1,   134,    68,
     136,    -1,   134,    68,   134,    -1,    -1,   138,    -1,   139,
      -1,   138,    66,   139,    -1,   119,    -1,   148,    -1,   149,
      -1,     6,    -1,   151,    -1,   150,    -1,   134,    -1,   143,
      -1,   161,    -1,   115,    -1,   117,    -1,   146,    -1,    93,
      -1,    89,   123,    90,    -1,    97,    -1,   149,    -1,   142,
      -1,    80,   158,    81,    -1,   145,    73,   145,    -1,   145,
      74,   145,    -1,   145,    75,   145,    -1,   145,    76,   145,
      -1,   145,    77,   145,    -1,   144,    70,   144,    -1,   144,
      68,   144,    -1,   144,    69,   144,    -1,    78,   144,    -1,
     144,    31,   144,    -1,   144,    32,   144,    -1,     3,    -1,
     147,    -1,   158,    -1,   143,    -1,    80,   143,    81,    -1,
      58,   147,    80,   137,    81,    -1,     6,    -1,     5,    -1,
       4,    -1,     3,    -1,    74,   141,    -1,    74,   147,    -1,
       7,    -1,    61,    -1,   158,    -1,   143,    -1,   148,    -1,
     152,    -1,   153,    -1,   155,    -1,   153,    71,   153,    -1,
     153,    72,   153,    -1,   153,    12,   153,    -1,   153,    13,
     153,    -1,   153,    14,   153,    -1,   153,    15,   153,    -1,
     154,    10,   154,    -1,   154,    11,   154,    -1,   147,    36,
     147,    -1,    17,   147,    -1,    18,   147,    -1,   147,    17,
      -1,   147,    18,    -1,   149,    -1,   150,    -1,   148,    -1,
     143,    -1,   134,    -1,   119,    -1,   147,    -1,   151,    -1,
     156,    -1,   146,    -1,   115,    -1,   152,    -1,   113,    -1,
     161,    -1,   117,    -1,   149,    -1,   150,    -1,   151,    -1,
     134,    -1,   147,    -1,   156,    -1,   115,    -1,   117,    -1,
     113,    -1,   161,    -1,   147,    67,   157,    -1,   147,    67,
     159,    -1,   115,    67,   157,    -1,   114,    67,   157,    -1,
       6,    82,     3,    83,    -1,     6,    82,     6,    83,    -1,
       6,    82,     7,    83,    -1,   115,    82,     3,    83,    -1,
     115,    82,     6,    83,    -1,   115,    82,     7,    83,    -1,
     134,    82,     3,    83,    -1,   134,    82,     6,    83,    -1,
     134,    82,     7,    83,    -1,   161,    67,   157,    -1,   159,
      -1,   160,    -1,   162,    -1,   147,    27,   158,    -1,   147,
      28,   158,    -1,   147,    29,   158,    -1,   147,    30,   158,
      -1,   147,    33,   158,    -1
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
     452,   457,   458,   459,   461,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   480,   485,   486,   487,   488,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   526,   527,   531,   532,   537,
     538,   539,   540,   541,   542,   543,   544,   545,   551,   556,
     557,   558,   559,   560,   561,   562,   563
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
  "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'~'", "'.'",
  "'('", "')'", "'['", "']'", "PRIORITY3", "PRIORITY2", "PRIORITY1",
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
  "bool_param_expr", "logic_stmt", "type_judge_stmt", "self_inc_dec_stmt",
  "assign_stmt_value", "assign_stmt_value_eq", "single_assign_stmt",
  "class_member_assign_stmt", "array_ele_stmt", "array_ele_assign_stmt",
  "assign_stmt", 0
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
      38,    62,    60,    43,    45,    42,    47,    37,   126,    46,
      40,    41,    91,    93,   321,   322,   323,   324,    59,   123,
     125,    64,    58,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    98,    99,    99,   100,   101,   101,
     101,   101,   101,   101,   101,   102,   103,   103,   104,   105,
     106,   106,   107,   108,   108,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     113,   113,   113,   114,   114,   115,   115,   115,   115,   116,
     116,   116,   116,   116,   117,   118,   118,   118,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   137,   137,   138,   138,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   140,   140,   141,   141,   142,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   144,   144,   145,
     145,   145,   146,   147,   148,   149,   149,   150,   150,   151,
     152,   153,   153,   153,   153,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   155,   156,   156,   156,   156,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   159,   160,   160,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   162,   163,
     163,   163,   163,   163,   163,   163,   163
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
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     1,
       1,     1,     3,     3,     3,     3,     3
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
     108,   106,   104,   110,   121,   107,     0,   229,   230,     0,
     231,   103,    73,     0,   124,     0,     0,    73,   164,   112,
       0,    79,     0,   169,    11,    12,    33,     0,   163,    29,
       0,   163,     0,    31,    30,    43,     0,     0,    99,   105,
     166,   165,   163,     0,     0,    50,   170,     0,     0,    77,
       0,   213,   211,   212,   195,     0,   208,   160,     0,     0,
     199,   158,   192,   205,   206,   207,   201,   210,   115,   159,
     214,     0,   163,     0,    13,     0,    28,    25,    43,     0,
      27,    21,     0,     0,     0,     0,     0,   124,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      80,     0,     0,   124,    77,     0,    44,   163,   140,   213,
     211,   212,   128,   208,     0,   125,   126,   160,   139,   209,
     129,   205,   206,   207,   210,   214,     0,   163,     0,     0,
       0,     0,     0,     0,     0,   163,    54,     0,    53,     0,
       0,     0,    14,     0,    28,     0,     0,   211,   212,   208,
     172,   209,   173,   205,   206,   207,   174,   175,     0,   176,
     171,   214,     0,   163,   101,     0,     0,   102,   100,     0,
       0,     0,   186,   187,     0,   166,     0,   167,   144,   168,
     143,   157,   154,   158,   163,     0,   160,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     188,   189,     0,   124,    73,     0,    43,   218,   217,    58,
       0,     0,     0,    56,     0,   123,   122,     0,     0,     0,
     209,   232,   233,   234,   235,   236,    64,    81,   158,   215,
     216,    55,   228,     0,     0,    75,     0,    79,   118,     0,
     219,   220,   221,     0,   163,    35,     0,    45,    49,    47,
       0,     0,    79,    15,    78,    32,    34,     0,   163,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    71,     0,     0,    51,     0,     0,     0,
     161,   116,    79,    72,   155,   156,   152,   153,   151,   160,
     146,   147,   148,   149,   150,     0,     0,     0,     0,     0,
     124,   222,   223,   224,   124,   120,     0,   225,   226,   227,
     124,   124,   117,    74,     0,     0,   127,     0,    82,     0,
      84,     0,    86,    36,    46,    48,     0,     0,    16,     0,
       0,    37,     0,   185,   179,   180,   181,   182,   177,   178,
     183,   184,    79,   142,    90,    97,     0,     0,   219,   220,
     124,   145,    76,     0,     0,     0,   162,    79,    39,     0,
       0,     0,     0,   123,     0,     0,    66,    57,    83,    85,
      87,    67,     0,    38,     0,     0,    99,    69,     0,    79,
      70,     0,     0,     0,    93,     0,    40,    41,     0,    62,
      63,    59,    60,   124,     0,   141,    91,     0,    52,     0,
       0,    79,    92,    94,    65,    42,     0,     0,     0,    68,
      79,    96,    61,    79,    98,    95,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   304,    30,    31,   378,    32,    33,    34,
      35,    36,    37,    38,    77,    39,    66,   296,   297,   159,
      40,   197,    42,   198,    44,   162,   105,   155,   235,   189,
      45,    46,    47,   433,   434,    48,   215,    49,    50,    51,
     199,    53,    54,   164,   165,   166,   394,   227,   228,   167,
     108,   109,    55,   169,   170,   203,   204,   205,   206,   207,
     208,   209,   174,   118,   119,    57,    58,   211,    60,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -309
static const yytype_int16 yypact[] =
{
    -309,    65,  1671,  -309,   270,    17,   109,    -9,    49,    86,
     152,   152,   159,  -309,   180,    -1,   200,    74,   146,   157,
     249,  -309,  1052,   184,   264,   152,   274,  -309,    12,  -309,
    -309,  -309,  -309,  -309,    13,  -309,  -309,  -309,   225,  -309,
     265,    81,   255,   273,  -309,  -309,  -309,  -309,  -309,   276,
    -309,  -309,    31,  -309,  -309,  -309,  1736,  -309,  -309,   230,
    -309,  -309,   275,   355,   498,   506,   281,   275,  -309,  -309,
     366,  -309,   309,  -309,  -309,  -309,  -309,   -53,   296,  -309,
     -35,    87,   384,  -309,  -309,   373,   970,   970,   462,  -309,
     231,  -309,   185,   264,   264,   325,  -309,   123,   167,   720,
     498,   131,   472,   250,  -309,    -6,   407,   142,   430,   636,
    -309,  1201,  -309,   168,   178,   224,  -309,   351,  -309,  -309,
     444,   264,  -309,   320,  -309,   390,   -14,  -309,   373,   408,
    -309,  -309,  1677,  1677,   264,   556,   264,   498,  -309,   366,
     587,   523,   523,   523,   523,   523,   264,   180,  1677,   264,
    -309,  1677,   264,   498,   429,   349,  -309,   267,  -309,  -309,
     347,   307,  -309,   465,   329,   382,  -309,    -7,  -309,   819,
    -309,   191,   245,   285,  -309,   313,   369,   360,   372,   213,
     -45,    -8,     1,    15,   368,     7,   213,   388,    -8,  1094,
     159,   467,  -309,   339,  -309,   389,   864,   213,   273,   388,
     699,   413,  -309,  -309,  -309,  -309,  -309,   404,    35,  -309,
     728,     1,    44,   242,  -309,   397,  1713,  -309,  -309,   398,
     487,   592,  -309,  -309,   264,  -309,   523,  -309,  -309,  -309,
    -309,  -309,  -309,  -309,   302,   -17,   440,   -23,   422,   522,
     167,   167,   167,   167,   167,   864,   864,   864,   864,   864,
    -309,  -309,   454,   498,   275,   448,   373,  -309,  -309,   463,
     475,   478,   490,   470,   494,    39,  -309,   497,   513,   517,
     217,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  1088,  -309,
    -309,   509,  -309,   525,   526,  -309,   148,  -309,   524,   498,
     -19,     0,  -309,     6,    16,  -309,    19,  -309,  -309,  -309,
     194,   521,  -309,   585,  -309,   536,  -309,   533,   488,    22,
     264,   970,   970,   970,   970,   970,   970,   970,   970,  1152,
    1152,   970,  -309,  -309,   535,   538,   554,   557,   629,   620,
    -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
     442,   442,  -309,  -309,  -309,   550,   561,   558,    28,   567,
     498,  -309,  -309,  -309,   498,  -309,   366,  -309,  -309,  -309,
     498,   498,  -309,  -309,  1207,   264,  -309,   180,  -309,   180,
    -309,   180,  -309,  -309,  -309,  -309,  1265,   563,  -309,   -19,
       0,  -309,    33,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,   634,  -309,  -309,   598,  -309,    68,  1323,  -309,  -309,
     498,  -309,  -309,   568,  1381,   411,  -309,  -309,  -309,   127,
     201,   569,   580,   388,   582,   583,  -309,   588,  -309,  -309,
    -309,  -309,   264,  -309,  1439,  1152,   462,  -309,   584,  -309,
    -309,   579,   577,   125,  -309,  1497,  -309,  -309,   212,  -309,
    -309,  -309,  -309,   498,   589,  -309,  -309,   593,  -309,  1555,
     581,  -309,  -309,  -309,  -309,  -309,   595,   570,  1152,  -309,
    -309,  1671,  -309,  -309,  -309,  1671,  1613,  -309
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,  -309,     9,  -309,  -309,  -309,  -309,  -309,  -309,
     626,  -309,  -309,  -309,   489,   147,   -78,  -308,  -281,    34,
    -309,   188,  -309,   321,  -135,    60,  -309,   -65,   529,   578,
     -11,  -309,  -309,  -309,   247,  -309,   252,  -309,  -309,  -309,
     469,  -309,   545,  -129,   586,   400,  -303,  -309,  -309,   775,
     -46,   700,   555,    -2,   500,   136,   630,    51,    95,   314,
     -73,  -309,    20,   433,   698,  -132,  -309,   602,  -309,   -82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -210
static const yytype_int16 yytable[] =
{
      56,   382,   184,    79,    84,    81,   218,   195,   264,    63,
     238,    29,    80,    80,   212,   374,   280,   395,   126,   128,
     111,   294,   123,     5,   284,   294,   191,     5,   294,   146,
       5,   147,    62,    67,   294,   192,     5,   140,   293,   294,
     409,     5,   117,   289,    16,   317,   318,   367,   298,   328,
     255,   301,   232,   150,   317,   318,   101,    16,   129,  -135,
     239,    74,    75,   181,   329,     3,   369,   331,   188,   368,
      70,   149,   371,   115,  -135,   -43,   124,   214,   317,   318,
     152,   153,   104,  -135,   201,   201,   216,    64,   370,   221,
      82,   222,   223,    26,   372,   229,   233,    26,   193,   139,
      26,   374,   438,    82,    82,   295,    26,   356,   217,   373,
      63,    26,   381,   140,    68,   173,   319,   116,   408,   252,
      72,   140,   446,   423,   346,   320,   225,    91,   374,   122,
     111,   111,   259,   294,   263,     5,   277,   181,    71,   270,
     270,   270,   270,   270,   276,    80,   278,   281,   133,   111,
     283,   173,   117,   117,    86,   464,   426,   374,   113,    73,
     134,   298,    83,   135,   301,    76,   101,   101,   117,   193,
     231,   117,   299,   122,   298,   127,   -43,   301,   349,   431,
     432,   300,   101,   115,   115,   101,    78,    56,   173,   347,
      41,   181,   104,   104,   334,   335,   336,   337,   338,   115,
     171,   219,   115,   226,   173,    26,    85,   294,   104,     5,
     102,   104,  -202,   298,   328,   452,   301,   436,   294,  -202,
       5,   411,   326,  -193,   270,   412,    87,   116,   116,   363,
    -193,   414,   415,   230,   250,   251,   171,    88,   233,   233,
     233,   233,   233,   116,   390,   391,   116,   298,   396,  -190,
     301,   220,   160,   179,   146,    89,  -190,  -130,   186,  -191,
     147,   148,  -157,  -157,   121,    64,  -191,   221,   113,   113,
     122,   428,  -130,   171,   298,   298,    41,   301,   301,    26,
     125,  -130,   150,   219,   113,   299,    62,   113,   160,   171,
      26,   437,   134,    63,   300,   135,   149,   151,   299,  -157,
    -157,  -157,   455,   298,   173,  -197,   301,   300,   383,   152,
     153,  -133,  -197,   131,   456,   201,   201,    56,    56,   201,
     102,   102,    64,    43,    65,   160,  -133,   179,   393,   393,
     137,  -204,   132,  -131,   136,  -133,   102,   299,  -204,   102,
     173,   160,   307,   103,   218,   308,   300,    64,  -131,   221,
      64,  -132,    65,   137,   181,   154,   418,  -131,   419,   -43,
     420,   156,    56,   417,   138,    80,  -132,    80,   -75,    80,
     183,   299,   185,  -138,    56,  -132,   190,    41,   193,  -136,
     300,   179,    64,   -75,   221,   161,    43,   137,  -138,   171,
     194,    43,   152,   153,  -136,    56,    63,  -138,   299,   299,
     253,   173,    56,  -136,   224,   173,   254,   300,   300,    43,
     288,   173,   173,  -137,   256,   214,   311,   312,   313,   314,
     444,   161,    56,    56,   216,   171,   134,   299,  -137,   135,
     250,   251,  -198,    56,   393,   285,   300,  -137,   287,  -198,
      64,   160,   221,   291,  -158,  -158,   217,    56,   289,   310,
     146,   173,   290,   103,   103,   292,    56,   302,   161,    56,
      43,   240,   241,    56,    56,   431,   432,   393,   213,   103,
     140,    52,   103,   306,   161,   315,   316,   160,   309,    93,
      94,  -158,  -158,  -158,     7,   321,   171,   322,  -194,   140,
     171,   106,   149,   323,   173,  -194,   171,   171,   242,   243,
     244,    90,    91,    68,   157,    73,    69,    41,    41,   176,
      43,   332,   177,   178,    43,    93,    94,   247,   248,   249,
      95,   330,   112,   152,   153,  -203,   225,    91,   333,   185,
      73,  -134,  -203,   163,   180,   345,   171,   348,   160,   187,
      93,    94,   160,   350,   179,    95,  -134,   140,   160,   160,
     354,   134,    41,  -200,   135,  -134,    24,   187,   351,   260,
    -200,   352,   261,   262,    41,   257,   258,   450,    64,   163,
     221,   380,    97,   353,   161,   355,    98,   110,    99,   171,
     357,   279,   225,    91,   282,    41,   202,   202,   160,   360,
     267,   158,    41,   268,   269,   324,   358,    97,   325,   178,
     359,   106,   106,   365,    59,   361,   163,   362,   265,   375,
     161,   377,    41,    41,    41,   191,   379,   106,   398,   168,
     106,   399,   163,    41,   120,   384,   385,   386,   387,   388,
     389,   160,   112,   112,   400,   402,   403,    41,   401,   405,
      43,    43,   406,   422,   317,   425,    41,   407,   112,    41,
     439,   112,   114,    41,    41,   168,   410,   429,    52,   463,
     130,   440,   180,   441,   442,   448,   175,   182,   443,   451,
     457,   161,   182,   460,   458,   161,   462,    43,   447,   305,
     453,   161,   161,   286,   266,    43,   237,   110,   110,   366,
      59,     0,   168,     0,   172,     0,     0,    43,     0,     0,
       0,     0,   175,   110,     0,     0,   110,     0,   168,   245,
     246,   247,   248,   249,     0,     0,     0,     0,    43,     0,
       0,   161,   163,    90,    91,    43,   234,    73,     0,     0,
     172,     0,     0,     0,   120,   120,     0,    93,    94,   175,
       0,   182,    95,     0,     0,    43,    43,    43,     0,     0,
     120,     0,     0,   120,     0,   175,    43,     0,   163,     0,
       0,     0,   114,   114,   161,     0,     0,   172,     0,     0,
      43,     0,  -160,  -160,  -160,  -160,  -160,     0,   114,    43,
       0,   114,    43,   172,   210,   210,    43,    43,    52,    52,
       0,    59,     0,     0,    97,   182,     0,   107,    98,     0,
     196,  -159,  -159,  -159,  -159,  -159,     0,     0,   168,     0,
       0,   202,   202,   202,   202,   202,   202,   202,   202,   163,
       0,   202,     0,   163,     0,   413,     0,     0,     0,   163,
     163,     0,     0,    52,     0,     0,   250,   251,     0,   271,
     272,   273,   274,   275,   168,    52,     0,     0,     0,     0,
    -158,  -158,     0,     0,     0,   175,   146,     0,     0,     0,
       0,   200,   200,     0,     0,   364,    52,    90,    91,   163,
     185,    73,     0,    52,   236,     0,     0,     0,     0,     0,
     376,    93,    94,   172,     0,     0,    95,  -158,  -158,  -158,
       0,   175,     0,    52,    52,   187,     0,     0,   149,     0,
     397,     0,     0,     0,    52,   168,     0,   107,   107,   168,
     404,     0,   163,     0,     0,   168,   168,     0,    52,   172,
       0,    59,    59,   107,   327,     0,   107,    52,     0,     0,
      52,     0,     0,     0,    52,    52,     0,     0,    97,     0,
       0,     0,    98,     0,   196,   340,   341,   342,   343,   344,
       0,     0,   175,     0,     0,   168,   175,     0,   182,     0,
       0,     0,   175,   175,     0,     0,    59,     0,     0,     0,
     424,   236,     0,    90,    91,    68,   185,    73,    59,     0,
     172,     0,     0,     0,   172,   435,     0,    93,    94,     0,
     172,   172,    95,     0,     0,     0,     0,     0,   168,    59,
       0,     0,   175,     0,     0,     0,    59,   449,     0,   210,
     210,   210,   210,   210,   210,   210,   210,     0,     0,   210,
     339,   339,   339,   339,   339,     0,    59,    59,    59,   461,
     172,    96,     0,     0,     0,     0,     0,    59,   465,     0,
       0,   466,     0,     0,    97,   175,     0,     0,    98,     0,
     196,    59,     0,     0,     0,    90,    91,    68,    92,    73,
      59,     0,     0,    59,     0,     0,     0,    59,    59,    93,
      94,     0,     0,   172,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,   200,   200,   200,
     200,   200,   200,   200,     0,     0,   200,     0,     0,     0,
       4,     0,     5,     0,     0,   250,   251,     0,     0,     0,
      24,     0,     0,    96,     0,     6,     7,     0,     0,     8,
       0,     0,     0,     0,     0,   146,    97,     0,     0,     9,
      98,     0,    99,    10,    11,    12,    13,    14,    15,    16,
      17,   100,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,    24,     0,     0,   148,    25,     0,     4,     0,
       5,  -209,  -209,  -209,  -209,  -209,     0,   149,     0,  -196,
       0,     0,    26,     6,     7,     0,  -196,     8,     0,     0,
       0,     0,    27,     0,   303,    28,     0,     9,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,    17,     0,
      18,    19,    20,    21,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     4,    25,     5,     0,     0,   250,   251,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
      26,     0,     8,     0,     0,     0,     0,     0,   146,     0,
      27,   392,     9,    28,     0,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     0,     0,    25,
       0,     4,     0,     5,  -209,  -209,  -209,  -209,  -209,     0,
     149,     0,  -196,     0,     0,    26,     6,     7,     0,  -196,
       8,     0,     0,     0,     0,    27,     0,   416,    28,     0,
       9,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,     0,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,    24,     0,     0,     0,    25,     0,     4,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     6,     7,     0,     0,     8,     0,
       0,     0,     0,    27,     0,   421,    28,     0,     9,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,    24,     0,     0,     0,    25,     0,     4,     0,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     6,     7,     0,     0,     8,     0,     0,     0,
       0,    27,     0,   427,    28,     0,     9,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,     0,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,    24,
       0,     0,     0,    25,     0,     4,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       6,     7,     0,     0,     8,     0,     0,     0,     0,    27,
       0,   430,    28,     0,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,    17,     0,    18,    19,    20,
      21,    22,    23,     0,     0,     0,     0,    24,     0,     0,
       0,    25,     0,     4,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,     6,     7,
       0,     0,     8,     0,     0,     0,     0,    27,     0,   445,
      28,     0,     9,     0,     0,     0,    10,    11,    12,    13,
      14,    15,    16,    17,     0,    18,    19,    20,    21,    22,
      23,     0,     0,     0,     0,    24,     0,     0,     0,    25,
       0,     4,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     6,     7,     0,     0,
       8,     0,     0,     0,     0,    27,     0,   454,    28,     0,
       9,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      16,    17,     0,    18,    19,    20,    21,    22,    23,     0,
       0,     0,     0,    24,     0,     0,     0,    25,     0,     4,
       0,     5,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     6,     7,     0,     0,     8,     0,
       0,     0,     0,    27,     0,   459,    28,     0,     9,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
       0,    18,    19,    20,    21,    22,    23,     0,     0,     0,
       0,    24,     0,     0,     0,    25,     0,     4,     0,     5,
      90,    91,    68,    92,    73,     0,     0,     0,     0,     0,
       0,    26,     6,     7,    93,    94,     8,     0,     0,    95,
       0,    27,     0,   467,    28,     0,     9,     0,     0,     0,
      10,    11,    12,    13,    14,    15,    16,    17,     0,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,    24,
     250,   251,     0,    25,     0,    24,     0,     0,    96,     0,
     141,   142,   143,   144,     0,     0,   145,     0,     0,    26,
     146,    97,     0,     0,     0,    98,     0,    99,     0,    27,
       0,     0,    28,   141,   142,   143,   144,     0,     0,   145,
       0,     0,     0,   146,     0,     0,     0,     0,     0,   147,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,   150
};

static const yytype_int16 yycheck[] =
{
       2,   309,    67,    14,    15,     6,    88,    85,   137,    23,
      16,     2,    14,    15,    87,   296,   148,   320,     6,     6,
      22,     6,    24,     8,   153,     6,    79,     8,     6,    37,
       8,    66,    16,    16,     6,    88,     8,    82,    83,     6,
     348,     8,    22,    66,    45,    10,    11,    66,   183,    66,
     128,   183,    98,    88,    10,    11,    22,    45,    45,    66,
      66,    10,    11,    65,    81,     0,    66,    90,    70,    88,
      79,    79,    66,    22,    81,    89,    25,    88,    10,    11,
      79,    80,    22,    90,    86,    87,    88,    80,    88,    82,
      91,    93,    94,    78,    88,    97,    98,    78,    82,    68,
      78,   382,   410,    91,    91,    90,    78,    68,    88,    90,
      23,    78,    90,    82,     5,    64,    81,    22,    90,   121,
      34,    82,   425,    90,   253,    81,     3,     4,   409,     6,
     132,   133,   134,     6,   136,     8,   147,   139,    89,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    67,   151,
     152,   100,   132,   133,    80,   458,    88,   438,    22,     7,
      79,   296,    15,    82,   296,     6,   132,   133,   148,    82,
       3,   151,   183,     6,   309,    28,    89,   309,   256,    54,
      55,   183,   148,   132,   133,   151,     6,   189,   137,   254,
       2,   193,   132,   133,   240,   241,   242,   243,   244,   148,
      64,    16,   151,    80,   153,    78,     6,     6,   148,     8,
      22,   151,    81,   348,    66,    90,   348,    90,     6,    88,
       8,   350,   224,    81,   226,   354,    80,   132,   133,    81,
      88,   360,   361,    97,    17,    18,   100,    80,   240,   241,
     242,   243,   244,   148,   317,   318,   151,   382,   321,    81,
     382,    66,    64,    65,    37,     6,    88,    66,    70,    81,
      66,    67,    31,    32,    80,    80,    88,    82,   132,   133,
       6,   400,    81,   137,   409,   410,    88,   409,   410,    78,
       6,    90,    88,    16,   148,   296,    16,   151,   100,   153,
      78,    90,    79,    23,   296,    82,    79,    67,   309,    68,
      69,    70,    90,   438,   253,    81,   438,   309,   310,    79,
      80,    66,    88,    88,   443,   317,   318,   319,   320,   321,
     132,   133,    80,     2,    82,   137,    81,   139,   319,   320,
      80,    81,    67,    66,    79,    90,   148,   348,    88,   151,
     289,   153,     3,    22,   426,     6,   348,    80,    81,    82,
      80,    66,    82,    80,   356,    80,   367,    90,   369,    89,
     371,     6,   364,   365,    88,   367,    81,   369,    66,   371,
      89,   382,     6,    66,   376,    90,    67,   189,    82,    66,
     382,   193,    80,    81,    82,    64,    65,    80,    81,   253,
       6,    70,    79,    80,    81,   397,    23,    90,   409,   410,
      80,   350,   404,    90,    79,   354,    16,   409,   410,    88,
      81,   360,   361,    66,     6,   426,    12,    13,    14,    15,
     422,   100,   424,   425,   426,   289,    79,   438,    81,    82,
      17,    18,    81,   435,   425,     6,   438,    90,    89,    88,
      80,   253,    82,    83,    31,    32,   426,   449,    66,    36,
      37,   400,    83,   132,   133,    83,   458,    89,   137,   461,
     139,    31,    32,   465,   466,    54,    55,   458,     6,   148,
      82,     2,   151,     6,   153,    71,    72,   289,    89,    17,
      18,    68,    69,    70,    22,    88,   350,    89,    81,    82,
     354,    22,    79,     6,   443,    88,   360,   361,    68,    69,
      70,     3,     4,     5,     6,     7,     6,   319,   320,     3,
     189,    89,     6,     7,   193,    17,    18,    75,    76,    77,
      22,    81,    22,    79,    80,    81,     3,     4,     6,     6,
       7,    66,    88,    64,    65,    81,   400,    89,   350,    70,
      17,    18,   354,    80,   356,    22,    81,    82,   360,   361,
      80,    79,   364,    81,    82,    90,    58,    88,    83,     3,
      88,    83,     6,     7,   376,   132,   133,   431,    80,   100,
      82,    83,    74,    83,   253,    81,    78,    22,    80,   443,
      83,   148,     3,     4,   151,   397,    86,    87,   400,    80,
       3,    93,   404,     6,     7,     3,    83,    74,     6,     7,
      83,   132,   133,    79,     2,    80,   137,    81,   139,    88,
     289,    26,   424,   425,   426,    79,    83,   148,    83,    64,
     151,    83,   153,   435,    22,   311,   312,   313,   314,   315,
     316,   443,   132,   133,    80,     6,    16,   449,    81,    89,
     319,   320,    81,    80,    10,    47,   458,    89,   148,   461,
      81,   151,    22,   465,   466,   100,    89,    89,   189,    89,
      34,    81,   193,    81,    81,    81,    64,    65,    80,    92,
      81,   350,    70,    92,    81,   354,    81,   356,   426,   190,
     433,   360,   361,   154,   139,   364,   100,   132,   133,   289,
      88,    -1,   137,    -1,    64,    -1,    -1,   376,    -1,    -1,
      -1,    -1,   100,   148,    -1,    -1,   151,    -1,   153,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   397,    -1,
      -1,   400,   253,     3,     4,   404,     6,     7,    -1,    -1,
     100,    -1,    -1,    -1,   132,   133,    -1,    17,    18,   137,
      -1,   139,    22,    -1,    -1,   424,   425,   426,    -1,    -1,
     148,    -1,    -1,   151,    -1,   153,   435,    -1,   289,    -1,
      -1,    -1,   132,   133,   443,    -1,    -1,   137,    -1,    -1,
     449,    -1,    73,    74,    75,    76,    77,    -1,   148,   458,
      -1,   151,   461,   153,    86,    87,   465,   466,   319,   320,
      -1,   189,    -1,    -1,    74,   193,    -1,    22,    78,    -1,
      80,    73,    74,    75,    76,    77,    -1,    -1,   253,    -1,
      -1,   311,   312,   313,   314,   315,   316,   317,   318,   350,
      -1,   321,    -1,   354,    -1,   356,    -1,    -1,    -1,   360,
     361,    -1,    -1,   364,    -1,    -1,    17,    18,    -1,   141,
     142,   143,   144,   145,   289,   376,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,   253,    37,    -1,    -1,    -1,
      -1,    86,    87,    -1,    -1,   287,   397,     3,     4,   400,
       6,     7,    -1,   404,    99,    -1,    -1,    -1,    -1,    -1,
     302,    17,    18,   253,    -1,    -1,    22,    68,    69,    70,
      -1,   289,    -1,   424,   425,   426,    -1,    -1,    79,    -1,
     322,    -1,    -1,    -1,   435,   350,    -1,   132,   133,   354,
     332,    -1,   443,    -1,    -1,   360,   361,    -1,   449,   289,
      -1,   319,   320,   148,   226,    -1,   151,   458,    -1,    -1,
     461,    -1,    -1,    -1,   465,   466,    -1,    -1,    74,    -1,
      -1,    -1,    78,    -1,    80,   245,   246,   247,   248,   249,
      -1,    -1,   350,    -1,    -1,   400,   354,    -1,   356,    -1,
      -1,    -1,   360,   361,    -1,    -1,   364,    -1,    -1,    -1,
     392,   196,    -1,     3,     4,     5,     6,     7,   376,    -1,
     350,    -1,    -1,    -1,   354,   407,    -1,    17,    18,    -1,
     360,   361,    22,    -1,    -1,    -1,    -1,    -1,   443,   397,
      -1,    -1,   400,    -1,    -1,    -1,   404,   429,    -1,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,    -1,   321,
     245,   246,   247,   248,   249,    -1,   424,   425,   426,   451,
     400,    61,    -1,    -1,    -1,    -1,    -1,   435,   460,    -1,
      -1,   463,    -1,    -1,    74,   443,    -1,    -1,    78,    -1,
      80,   449,    -1,    -1,    -1,     3,     4,     5,     6,     7,
     458,    -1,    -1,   461,    -1,    -1,    -1,   465,   466,    17,
      18,    -1,    -1,   443,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,   314,
     315,   316,   317,   318,    -1,    -1,   321,    -1,    -1,    -1,
       6,    -1,     8,    -1,    -1,    17,    18,    -1,    -1,    -1,
      58,    -1,    -1,    61,    -1,    21,    22,    -1,    -1,    25,
      -1,    -1,    -1,    -1,    -1,    37,    74,    -1,    -1,    35,
      78,    -1,    80,    39,    40,    41,    42,    43,    44,    45,
      46,    89,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    67,    62,    -1,     6,    -1,
       8,    73,    74,    75,    76,    77,    -1,    79,    -1,    81,
      -1,    -1,    78,    21,    22,    -1,    88,    25,    -1,    -1,
      -1,    -1,    88,    -1,    90,    91,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,    -1,    -1,     6,    62,     8,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      78,    -1,    25,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      88,    89,    35,    91,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      -1,     6,    -1,     8,    73,    74,    75,    76,    77,    -1,
      79,    -1,    81,    -1,    -1,    78,    21,    22,    -1,    88,
      25,    -1,    -1,    -1,    -1,    88,    -1,    90,    91,    -1,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    -1,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    21,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    88,    -1,    90,    91,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    -1,     6,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    88,    -1,    90,    91,    -1,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    -1,     6,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    88,
      -1,    90,    91,    -1,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    -1,     6,    -1,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    88,    -1,    90,
      91,    -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      -1,     6,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    21,    22,    -1,    -1,
      25,    -1,    -1,    -1,    -1,    88,    -1,    90,    91,    -1,
      35,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    -1,     6,
      -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    21,    22,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    88,    -1,    90,    91,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    -1,     6,    -1,     8,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    21,    22,    17,    18,    25,    -1,    -1,    22,
      -1,    88,    -1,    90,    91,    -1,    35,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,
      17,    18,    -1,    62,    -1,    58,    -1,    -1,    61,    -1,
      27,    28,    29,    30,    -1,    -1,    33,    -1,    -1,    78,
      37,    74,    -1,    -1,    -1,    78,    -1,    80,    -1,    88,
      -1,    -1,    91,    27,    28,    29,    30,    -1,    -1,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    95,    96,     0,     6,     8,    21,    22,    25,    35,
      39,    40,    41,    42,    43,    44,    45,    46,    48,    49,
      50,    51,    52,    53,    58,    62,    78,    88,    91,    97,
      98,    99,   101,   102,   103,   104,   105,   106,   107,   109,
     114,   115,   116,   117,   118,   124,   125,   126,   129,   131,
     132,   133,   134,   135,   136,   146,   147,   159,   160,   161,
     162,   163,    16,    23,    80,    82,   110,    16,     5,   148,
      79,    89,    34,     7,   151,   151,     6,   108,     6,   124,
     147,     6,    91,   109,   124,     6,    80,    80,    80,     6,
       3,     4,     6,    17,    18,    22,    61,    74,    78,    80,
      89,   113,   115,   117,   119,   120,   134,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   156,   157,   158,
     161,    80,     6,   147,   151,     6,     6,   109,     6,    45,
     104,    88,    67,    67,    79,    82,    79,    80,    88,    68,
      82,    27,    28,    29,    30,    33,    37,    66,    67,    79,
      88,    67,    79,    80,    80,   121,     6,     6,    93,   113,
     115,   117,   119,   134,   137,   138,   139,   143,   146,   147,
     148,   149,   150,   151,   156,   161,     3,     6,     7,   115,
     134,   147,   161,    89,   121,     6,   115,   134,   147,   123,
      67,    79,    88,    82,     6,   110,    80,   115,   117,   134,
     143,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     158,   161,   154,     6,   124,   130,   147,   156,   163,    16,
      66,    82,   147,   147,    79,     3,    80,   141,   142,   147,
     149,     3,   144,   147,     6,   122,   143,   138,    16,    66,
      31,    32,    68,    69,    70,    73,    74,    75,    76,    77,
      17,    18,   147,    80,    16,   110,     6,   157,   157,   147,
       3,     6,     7,   147,   137,   134,   136,     3,     6,     7,
     147,   158,   158,   158,   158,   158,   147,   124,   147,   157,
     159,   147,   157,   147,   137,     6,   122,    89,    81,    66,
      83,    83,    83,    83,     6,    90,   111,   112,   118,   124,
     147,   159,    89,    90,    97,   108,     6,     3,     6,    89,
      36,    12,    13,    14,    15,    71,    72,    10,    11,    81,
      81,    88,    89,     6,     3,     6,   147,   158,    66,    81,
      81,    90,    89,     6,   144,   144,   144,   144,   144,   143,
     145,   145,   145,   145,   145,    81,   137,   121,    89,   110,
      80,    83,    83,    83,    80,    81,    68,    83,    83,    83,
      80,    80,    81,    81,   123,    79,   139,    66,    88,    66,
      88,    66,    88,    90,   112,    88,   123,    26,   100,    83,
      83,    90,   111,   147,   153,   153,   153,   153,   153,   153,
     154,   154,    89,    97,   140,   140,   154,   123,    83,    83,
      80,    81,     6,    16,   123,    89,    81,    89,    90,   111,
      89,   137,   137,   134,   137,   137,    90,   147,   124,   124,
     124,    90,    80,    90,   123,    47,    88,    90,   137,    89,
      90,    54,    55,   127,   128,   123,    90,    90,   111,    81,
      81,    81,    81,    80,   147,    90,   140,   130,    81,   123,
     149,    92,    90,   128,    90,    90,   137,    81,    81,    90,
      92,   123,    81,    89,   140,   123,   123,    90
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
#line 457 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 172:
#line 458 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 173:
#line 459 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 174:
#line 461 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 175:
#line 466 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 176:
#line 467 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 177:
#line 468 "a.y"
    { (yyval.node) = opr('>',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 178:
#line 469 "a.y"
    { (yyval.node) = opr('<',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 179:
#line 470 "a.y"
    { (yyval.node) = opr( LE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 180:
#line 471 "a.y"
    { (yyval.node) = opr( GE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 181:
#line 472 "a.y"
    { (yyval.node) = opr( EQ_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 182:
#line 473 "a.y"
    { (yyval.node) = opr( NE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 183:
#line 474 "a.y"
    { (yyval.node) = opr(AND_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 184:
#line 475 "a.y"
    { (yyval.node) = opr(OR_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 185:
#line 480 "a.y"
    { (yyval.node) = opr(XIS ,2 , (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 186:
#line 485 "a.y"
    { (yyval.node) = opr(INC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 187:
#line 486 "a.y"
    { (yyval.node) = opr(DEC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 188:
#line 487 "a.y"
    { (yyval.node) = sopr(INC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 189:
#line 488 "a.y"
    { (yyval.node) = sopr(DEC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 190:
#line 493 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 191:
#line 494 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 192:
#line 495 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 193:
#line 496 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 194:
#line 497 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 195:
#line 498 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 196:
#line 499 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 197:
#line 500 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:
#line 501 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 199:
#line 502 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 200:
#line 503 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:
#line 504 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:
#line 505 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:
#line 506 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:
#line 507 "a.y"
    { (yyval.node) =(yyvsp[(1) - (1)].node) ;}
    break;

  case 205:
#line 512 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 206:
#line 513 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:
#line 514 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 208:
#line 515 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 209:
#line 516 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 210:
#line 517 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 211:
#line 518 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 212:
#line 519 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 213:
#line 520 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 214:
#line 521 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 215:
#line 526 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 216:
#line 527 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node) ); }
    break;

  case 217:
#line 531 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 218:
#line 532 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 219:
#line 537 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), (yyvsp[(3) - (4)].intValue), NULL); }
    break;

  case 220:
#line 538 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 221:
#line 539 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 222:
#line 540 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].intValue), NULL) ; }
    break;

  case 223:
#line 541 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 224:
#line 542 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 225:
#line 543 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node),  (yyvsp[(3) - (4)].intValue), NULL ) ; }
    break;

  case 226:
#line 544 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 227:
#line 545 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 228:
#line 551 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 229:
#line 556 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 230:
#line 557 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 231:
#line 558 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 232:
#line 559 "a.y"
    { (yyval.node) = opr(ADD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 233:
#line 560 "a.y"
    { (yyval.node) = opr(SUB_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 234:
#line 561 "a.y"
    { (yyval.node) = opr(MUL_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 235:
#line 562 "a.y"
    { (yyval.node) = opr(DIV_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 236:
#line 563 "a.y"
    { (yyval.node) = opr(MOD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;


/* Line 1267 of yacc.c.  */
#line 3357 "y.tab.c"
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


#line 566 "a.y"


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

