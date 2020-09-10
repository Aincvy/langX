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
     PIPELINE_OP = 318,
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
#define PIPELINE_OP 318
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
#define YYLAST   1776

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNRULES -- Number of states.  */
#define YYNSTATES  443

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
       2,     2,     2,    78,     2,     2,    93,    77,    70,     2,
      80,    81,    75,    73,    66,    74,    84,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    92,    89,
      72,    67,    71,     2,     2,     2,     2,     2,     2,     2,
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
      58,    60,    63,    65,    67,    70,    73,    76,    81,    83,
      87,    92,    98,   104,   111,   112,   115,   117,   120,   122,
     125,   127,   129,   133,   140,   144,   148,   152,   156,   163,
     167,   174,   181,   191,   198,   205,   209,   217,   224,   231,
     239,   245,   251,   255,   259,   260,   264,   266,   270,   271,
     274,   275,   277,   282,   287,   292,   295,   299,   301,   303,
     309,   317,   325,   327,   330,   335,   339,   345,   355,   356,
     358,   360,   362,   364,   366,   368,   371,   373,   375,   377,
     379,   381,   383,   385,   388,   390,   392,   395,   400,   405,
     410,   412,   417,   422,   423,   425,   427,   431,   433,   435,
     437,   439,   441,   443,   445,   447,   449,   451,   453,   455,
     457,   459,   463,   465,   467,   469,   473,   477,   481,   485,
     489,   493,   497,   501,   505,   508,   512,   516,   518,   520,
     522,   524,   528,   534,   536,   538,   540,   542,   545,   548,
     550,   552,   554,   556,   558,   560,   562,   564,   566,   568,
     570,   572,   575,   579,   583,   587,   591,   595,   599,   603,
     607,   611,   614,   617,   620,   623,   625,   627,   629,   631,
     633,   635,   637,   639,   641,   643,   645,   647,   649,   651,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   677,   681,   685,   689,   694,   699,   704,   709,   714,
     719,   724,   729,   734,   738,   740,   742,   744,   748,   752,
     756,   760
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      95,     0,    -1,    96,    -1,    96,    97,    -1,    -1,    89,
      -1,   101,    -1,   123,    -1,   129,    89,    -1,    98,    -1,
      99,    -1,    39,   149,    -1,    40,   149,    -1,    62,   149,
      -1,    41,   105,    89,    -1,    25,    90,   120,    91,    -1,
      25,    90,   120,    91,   100,    -1,    26,    80,   145,    81,
      90,   120,    91,    -1,   115,    -1,   122,    -1,   106,    -1,
     104,    89,    -1,   102,    -1,   103,    -1,    43,   122,    -1,
      44,   122,    -1,    44,   106,    -1,    35,    34,    67,   105,
      -1,     6,    -1,   105,    84,     6,    -1,     6,   107,    90,
      91,    -1,     6,   107,    90,   108,    91,    -1,    45,     6,
     107,    90,    91,    -1,    45,     6,   107,    90,   108,    91,
      -1,    -1,    23,     6,    -1,   109,    -1,   108,   109,    -1,
     122,    -1,   158,    89,    -1,   115,    -1,    22,    -1,    22,
      84,   145,    -1,    22,    84,   145,    80,   135,    81,    -1,
      22,    84,   145,    -1,    22,    84,   112,    -1,   145,    84,
     145,    -1,   113,    84,   145,    -1,     6,    80,   135,    81,
      84,   145,    -1,   112,    84,   145,    -1,   145,    84,   145,
      80,   135,    81,    -1,   160,    84,   145,    80,   135,    81,
      -1,     6,    80,   135,    81,    84,   145,    80,   135,    81,
      -1,   112,    84,   145,    80,   135,    81,    -1,   113,    84,
     145,    80,   135,    81,    -1,   145,    37,   145,    -1,    79,
       6,    16,   118,    90,   120,    91,    -1,     6,    16,   118,
      90,   120,    91,    -1,     8,    16,   118,    90,   120,    91,
      -1,    80,   119,    81,    16,    90,   120,    91,    -1,     6,
      16,    90,   120,    91,    -1,   117,    16,    90,   120,    91,
      -1,     6,    66,     6,    -1,   117,    66,     6,    -1,    -1,
      80,   119,    81,    -1,     6,    -1,   119,    66,     6,    -1,
      -1,   120,    97,    -1,    -1,   145,    -1,     6,    82,     3,
      83,    -1,     6,    82,     6,    83,    -1,     6,    82,   133,
      83,    -1,   121,    89,    -1,   121,    66,   122,    -1,   124,
      -1,   127,    -1,    46,    80,   153,    81,   138,    -1,    46,
      80,   153,    81,   138,    47,   138,    -1,    53,    80,   145,
      81,    90,   125,    91,    -1,   126,    -1,   125,   126,    -1,
      54,   147,    92,   120,    -1,    55,    92,   120,    -1,    48,
      80,   153,    81,   138,    -1,    49,    80,   128,    89,   153,
      89,   128,    81,   138,    -1,    -1,   162,    -1,   122,    -1,
     155,    -1,   130,    -1,   162,    -1,   133,    -1,    50,     6,
      -1,   132,    -1,   144,    -1,   131,    -1,    42,    -1,   134,
      -1,   155,    -1,    21,    -1,    21,   146,    -1,    51,    -1,
      52,    -1,    52,   156,    -1,    52,    90,   136,    91,    -1,
     160,    80,   135,    81,    -1,     6,    80,   135,    81,    -1,
     113,    -1,   114,    80,   135,    81,    -1,   133,    63,   133,
      89,    -1,    -1,   136,    -1,   137,    -1,   136,    66,   137,
      -1,   116,    -1,   146,    -1,   147,    -1,     6,    -1,   149,
      -1,   148,    -1,   133,    -1,   141,    -1,   160,    -1,   112,
      -1,   114,    -1,   144,    -1,    93,    -1,   150,    -1,    90,
     120,    91,    -1,    97,    -1,   147,    -1,   140,    -1,    80,
     157,    81,    -1,   143,    73,   143,    -1,   143,    74,   143,
      -1,   143,    75,   143,    -1,   143,    76,   143,    -1,   143,
      77,   143,    -1,   142,    70,   142,    -1,   142,    68,   142,
      -1,   142,    69,   142,    -1,    79,   142,    -1,   142,    31,
     142,    -1,   142,    32,   142,    -1,     3,    -1,   145,    -1,
     157,    -1,   141,    -1,    80,   141,    81,    -1,    58,   145,
      80,   135,    81,    -1,     6,    -1,     5,    -1,     4,    -1,
       3,    -1,    74,   139,    -1,    74,   145,    -1,     7,    -1,
      61,    -1,   145,    -1,   133,    -1,   112,    -1,   110,    -1,
     157,    -1,   141,    -1,   146,    -1,   150,    -1,   152,    -1,
     154,    -1,    78,   151,    -1,   152,    71,   152,    -1,   152,
      72,   152,    -1,   152,    12,   152,    -1,   152,    13,   152,
      -1,   152,    14,   152,    -1,   152,    15,   152,    -1,   153,
      10,   153,    -1,   153,    11,   153,    -1,   145,    36,   145,
      -1,    17,   145,    -1,    18,   145,    -1,   145,    17,    -1,
     145,    18,    -1,   147,    -1,   148,    -1,   146,    -1,   141,
      -1,   133,    -1,   116,    -1,   145,    -1,   149,    -1,   155,
      -1,   144,    -1,   112,    -1,   150,    -1,   110,    -1,   160,
      -1,   114,    -1,   147,    -1,   148,    -1,   149,    -1,   133,
      -1,   145,    -1,   155,    -1,   112,    -1,   114,    -1,   110,
      -1,   160,    -1,   145,    67,   156,    -1,   145,    67,   158,
      -1,   112,    67,   156,    -1,   111,    67,   156,    -1,     6,
      82,     3,    83,    -1,     6,    82,     6,    83,    -1,     6,
      82,     7,    83,    -1,   112,    82,     3,    83,    -1,   112,
      82,     6,    83,    -1,   112,    82,     7,    83,    -1,   133,
      82,     3,    83,    -1,   133,    82,     6,    83,    -1,   133,
      82,     7,    83,    -1,   160,    67,   156,    -1,   158,    -1,
     159,    -1,   161,    -1,   145,    27,   157,    -1,   145,    28,
     157,    -1,   145,    29,   157,    -1,   145,    30,   157,    -1,
     145,    33,   157,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    80,    80,    84,    85,    88,    89,    90,    91,    92,
      93,    98,    99,   100,   101,   106,   107,   111,   116,   117,
     118,   119,   120,   121,   127,   132,   133,   138,   142,   143,
     148,   149,   150,   151,   156,   157,   162,   163,   167,   168,
     169,   174,   175,   177,   182,   183,   188,   189,   190,   191,
     196,   197,   198,   199,   200,   205,   211,   212,   213,   218,
     219,   220,   224,   225,   229,   230,   234,   235,   236,   240,
     241,   245,   246,   247,   248,   253,   254,   259,   260,   265,
     266,   267,   271,   272,   276,   277,   281,   282,   287,   288,
     289,   290,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   308,   313,   314,   318,   319,   320,   321,   326,   327,
     328,   329,   333,   339,   340,   344,   345,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   366,   367,   373,   374,   379,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   400,   401,   406,
     408,   409,   414,   418,   422,   426,   427,   431,   432,   436,
     440,   444,   445,   446,   447,   452,   453,   454,   455,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     475,   480,   481,   482,   483,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     521,   522,   526,   527,   532,   533,   534,   535,   536,   537,
     538,   539,   540,   546,   551,   552,   553,   554,   555,   556,
     557,   558
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
  "XINCLUDE", "PIPELINE_OP", "NONASSOC", "IFX", "','", "'='", "'|'", "'^'",
  "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "'('", "')'", "'['", "']'", "'.'", "PRIORITY3", "PRIORITY2", "PRIORITY1",
  "UMINUS", "';'", "'{'", "'}'", "':'", "'$'", "$accept", "program",
  "statement_list", "statement", "require_stmt", "try_stmt",
  "catch_block_stmt", "declar_stmt", "const_declar_stmt",
  "local_declar_stmt", "namespace_declar_stmt", "namespace_name_stmt",
  "class_declar_stmt", "extends_stmt", "class_body", "class_body_stmt",
  "this_stmt", "this_member_stmt", "class_member_stmt",
  "class_member_func_stmt", "static_member_stmt", "func_declar_stmt",
  "lambda_stmt", "lambda_args_stmt", "param_list", "parameter",
  "expr_list", "element_var_declar_stmt", "var_declar_stmt",
  "con_ctl_stmt", "selection_stmt", "case_stmt_list", "case_stmt",
  "loop_stmt", "for_1_stmt", "simple_stmt", "self_compute_stmt",
  "restrict_stmt", "interrupt_stmt", "call_statement",
  "call_statement_pipeline", "args_list", "args_expr",
  "args_expr_collection", "block", "double_or_ps_expr", "parentheses_stmt",
  "arithmetic_stmt", "bit_opr_factor", "arithmetic_stmt_factor",
  "new_expr", "id_expr", "t_bool_expr", "double_expr", "uminus_expr",
  "string_expr", "null_expr", "not_expr_value", "bool_param_expr",
  "logic_stmt", "type_judge_stmt", "self_inc_dec_stmt",
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
      38,    62,    60,    43,    45,    42,    47,    37,    33,   126,
      40,    41,    91,    93,    46,   321,   322,   323,   324,    59,
     123,   125,    58,    36
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    98,    99,    99,   100,   101,   101,
     101,   101,   101,   101,   102,   103,   103,   104,   105,   105,
     106,   106,   106,   106,   107,   107,   108,   108,   109,   109,
     109,   110,   110,   110,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   115,   115,   115,   116,
     116,   116,   117,   117,   118,   118,   119,   119,   119,   120,
     120,   121,   121,   121,   121,   122,   122,   123,   123,   124,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     128,   128,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   131,   131,   132,   132,   132,   132,   133,   133,
     133,   133,   134,   135,   135,   136,   136,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   142,   142,   143,
     143,   143,   144,   145,   146,   147,   147,   148,   148,   149,
     150,   151,   151,   151,   151,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     154,   155,   155,   155,   155,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   161,   162,   162,   162,   162,   162,   162,
     162,   162
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       1,     2,     2,     2,     3,     4,     5,     7,     1,     1,
       1,     2,     1,     1,     2,     2,     2,     4,     1,     3,
       4,     5,     5,     6,     0,     2,     1,     2,     1,     2,
       1,     1,     3,     6,     3,     3,     3,     3,     6,     3,
       6,     6,     9,     6,     6,     3,     7,     6,     6,     7,
       5,     5,     3,     3,     0,     3,     1,     3,     0,     2,
       0,     1,     4,     4,     4,     2,     3,     1,     1,     5,
       7,     7,     1,     2,     4,     3,     5,     9,     0,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     4,     4,     4,
       1,     4,     4,     0,     1,     1,     3,     1,     1,     1,
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
       4,     0,     2,     1,   153,     0,     0,     0,   102,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   104,   105,     0,     0,     0,     0,     5,
       3,     9,    10,     6,    22,    23,     0,    20,     0,     0,
     110,     0,    18,     0,    19,     7,    77,    78,     0,    92,
      98,    96,    94,   100,    97,    71,   101,   224,   225,     0,
     226,    93,    64,     0,   113,     0,     0,    64,   153,   181,
     182,   154,   103,     0,    70,     0,   159,    11,    12,    28,
       0,   153,    24,    71,   153,    26,    25,    34,     0,     0,
      88,    95,   156,   155,   153,    41,   160,     0,     0,    68,
       0,   208,   206,   207,   190,     0,   203,   150,     0,     0,
     194,   148,   187,   200,   201,   202,   196,   205,   106,   149,
     209,     0,     0,    13,     0,    21,     0,     0,     0,     0,
       0,   113,     0,    75,     8,     0,     0,   183,   184,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
      68,     0,    35,   153,   129,   208,   206,   207,   117,   203,
       0,   114,   115,   150,   128,   204,   118,   200,   201,   202,
     130,   205,   209,     0,   153,     0,     0,     0,     0,     0,
       0,     0,   153,    45,     0,    44,     0,     0,     0,    14,
       0,     0,     0,     0,   206,   207,   203,   166,   204,   167,
     200,   201,   202,   168,   169,     0,   170,   165,   209,     0,
     153,    90,     0,    91,    89,     0,     0,     0,     0,   156,
       0,   157,   134,   158,   133,   147,   144,   148,   153,     0,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,    64,   213,   212,     0,
       0,     0,    49,    47,     0,    76,     0,     0,     0,     0,
     204,   227,   228,   229,   230,   231,    55,   148,   210,   211,
      46,   223,     0,     0,    66,     0,    70,   109,     0,   214,
     215,   216,    74,   153,    30,     0,    36,    40,    38,    71,
       0,    70,    15,    69,    27,    29,     0,   153,     0,   164,
     163,   162,   161,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    62,     0,     0,
      42,     0,     0,     0,   151,   107,    70,    63,   145,   146,
     142,   143,   141,   150,   136,   137,   138,   139,   140,     0,
       0,     0,   217,   218,   219,   113,   113,   111,   112,   220,
     221,   222,   113,   108,   113,    65,     0,     0,   116,    31,
      37,    39,     0,     0,    16,    72,    73,    32,     0,   180,
     174,   175,   176,   177,   172,   173,   178,   179,    70,   132,
      79,    86,     0,     0,   214,   215,   113,   135,    67,     0,
       0,     0,   152,    70,     0,     0,     0,     0,    57,    48,
      58,     0,    33,     0,     0,    88,    60,     0,    70,    61,
       0,     0,     0,    82,     0,    53,    54,    50,    51,   113,
       0,   131,    80,     0,    43,     0,     0,    70,    81,    83,
      56,     0,     0,     0,    59,    70,    85,    52,    70,    87,
      84,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   293,    31,    32,   364,    33,    34,    35,
      36,    80,    37,    66,   285,   286,   155,    38,   194,    40,
     195,    42,   158,   105,   151,   229,   186,    43,    44,    45,
      46,   412,   413,    47,   212,    48,    49,    50,    51,   196,
      53,   160,   161,   162,   380,   221,   222,   163,   108,   109,
      54,   165,   166,   200,   201,   202,   170,   303,   204,   205,
     206,   171,   118,   119,    57,    58,   208,    60,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -303
static const yytype_int16 yypact[] =
{
    -303,    25,  1687,  -303,   256,    67,    68,    68,   110,    37,
      44,    75,   141,   141,   170,  -303,   208,    21,   233,    82,
     211,   215,   265,  -303,   263,   234,    68,   141,   322,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,    93,  -303,   252,   133,
     250,   264,  -303,    11,  -303,  -303,  -303,  -303,   262,  -303,
    -303,  -303,    40,  -303,  -303,  1038,  -303,  -303,  -303,   272,
    -303,  -303,   305,   394,    33,   457,   338,   305,  -303,  -303,
    -303,  -303,  -303,   423,  -303,   366,  -303,  -303,  -303,  -303,
     -11,   364,  -303,  -303,    83,  -303,  -303,   433,   669,   669,
     365,  -303,   143,  -303,   176,   381,  -303,    38,   251,   620,
      33,   104,   391,   295,  -303,    -7,   156,   317,   229,   419,
    -303,   288,  -303,   324,   341,   351,  -303,   370,  -303,  -303,
     373,    68,   386,  -303,   460,  -303,   766,   766,   478,    68,
      68,    33,   208,  -303,  -303,   423,   501,  -303,  -303,    58,
      58,    58,    58,    58,    68,   766,    68,   766,    33,    68,
     477,   399,  -303,   212,  -303,  -303,   193,   -23,  -303,   128,
     422,   439,  -303,   -21,  -303,  1206,  -303,   241,   242,   249,
    -303,  -303,   313,   437,   429,   445,   296,   125,   -17,    30,
      10,   440,   309,   296,   451,   -17,  1157,   170,   529,  -303,
     298,   463,    63,   965,   296,   264,   451,   474,  1102,  -303,
    -303,  -303,  -303,  -303,   191,    24,  -303,   497,    30,    36,
     367,  -303,   466,  -303,  -303,   486,   534,   535,    68,  -303,
      58,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   345,   106,
     500,   -43,   492,   581,   251,   251,   251,   251,   251,   965,
     965,   965,   965,   965,   508,    33,   305,  -303,  -303,   509,
     511,   512,   516,   517,   510,  -303,   -10,   518,   519,   523,
     146,  -303,  -303,  -303,  -303,  -303,  -303,   450,  -303,  -303,
     527,  -303,   528,   531,  -303,   114,  -303,   515,    33,   100,
     102,  -303,  -303,    15,  -303,    13,  -303,  -303,  -303,   541,
     524,  -303,   586,  -303,   538,  -303,   532,   495,    20,  -303,
     296,   451,   -17,  -303,    68,  1030,  1030,  1030,  1030,  1030,
    1030,   669,   669,  1634,  1634,   669,  -303,  -303,   545,   547,
     551,   553,   629,   627,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,   483,   483,  -303,  -303,  -303,   554,
     564,   558,  -303,  -303,  -303,    33,    33,  -303,  -303,  -303,
    -303,  -303,    33,  -303,    33,  -303,  1210,    68,  -303,  -303,
    -303,  -303,  1263,   570,  -303,  -303,  -303,  -303,    76,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,   642,  -303,  -303,
     606,  -303,    19,  1316,  -303,  -303,    33,  -303,  -303,   571,
    1369,   166,  -303,  -303,   573,   582,   583,   585,  -303,   590,
    -303,    68,  -303,  1422,  1634,   365,  -303,   596,  -303,  -303,
     354,   579,    -1,  -303,  1475,  -303,  -303,  -303,  -303,    33,
     597,  -303,  -303,   599,  -303,  1528,   589,  -303,  -303,  -303,
    -303,   601,   572,  1634,  -303,  -303,  1687,  -303,  -303,  -303,
    1687,  1581,  -303
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,  -303,     4,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,   496,   673,   609,   395,  -275,     9,  -303,    96,  -303,
     200,  -169,    32,  -303,   -65,   542,   588,  -303,    -9,  -303,
    -303,  -303,   286,  -303,   297,  -303,  -303,  -303,  -303,   371,
    -303,   -99,   603,   426,  -302,  -303,  -303,   820,   -85,   417,
     343,    -2,   771,   754,   655,   605,   847,  -303,   259,   -86,
    -303,   453,   223,   109,  -128,  -303,   520,  -303,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -205
static const yytype_int16 yytable[] =
{
      55,   214,   181,   209,    69,    70,    30,    82,    86,   232,
     360,   287,   381,   226,    83,    83,   283,   269,     5,   283,
     144,     5,   111,   278,   122,     3,   283,    84,     5,   311,
     312,    62,   254,   101,   311,   312,    92,    93,    71,   153,
      76,   219,    93,  -127,    68,  -124,   311,   312,   325,   272,
       6,     7,   290,   410,   411,    95,   104,   131,  -127,   233,
    -124,   219,    93,   178,   182,    76,    18,   146,  -127,   182,
    -124,   185,   136,   188,    68,     6,     7,   132,   189,   348,
      95,   211,   283,    67,     5,    95,   198,   198,    55,    28,
     428,    26,    28,   360,    96,   223,   227,   190,    39,    28,
     133,   284,   422,   135,   359,   313,    63,    97,   405,    75,
     148,   367,    98,    99,   149,    71,   287,   314,   220,   244,
     102,    73,   136,   255,   111,   111,   154,   252,   253,   287,
      83,   439,    97,   178,    74,   101,   101,   260,   260,   260,
     260,   260,   266,   267,   270,   111,   340,   273,    76,   328,
     329,   330,   331,   332,   101,    28,   101,   290,   104,   104,
     156,   176,    88,   137,   138,   190,   -72,   402,   -73,   183,
     290,   288,   322,   -34,  -147,  -147,    79,   104,   289,   104,
     322,   341,   125,   144,    55,  -197,    39,   323,   178,   -72,
     302,   -73,   215,  -197,  -123,   355,   156,   207,   207,   287,
     127,   299,    41,   305,   306,   307,   308,   136,   282,  -123,
     136,  -147,  -147,  -147,    81,   128,   320,   129,   260,  -123,
     410,   411,   102,   102,   103,   376,   377,   156,   215,   382,
     146,   176,   227,   227,   227,   227,   227,  -189,   136,    87,
     290,   102,   216,   102,   156,  -189,   394,   395,   261,   262,
     263,   264,   265,   396,   225,   397,    64,    68,   217,  -126,
     234,   235,   309,   310,   157,    41,    92,    93,    71,    94,
      76,    91,    62,    41,  -126,   128,   288,   129,  -120,    63,
       6,     7,    39,   289,  -126,    95,   176,   407,   300,   288,
      41,    89,    64,  -120,   217,    90,   289,   236,   237,   238,
     157,   296,   369,  -120,   297,   137,   138,  -119,  -122,   198,
     198,    55,    55,   198,   121,  -121,   214,   379,   379,   126,
     431,    26,  -119,  -122,    96,   144,   103,   103,   124,   321,
    -121,   157,  -119,  -122,   130,    41,    64,    97,    65,   147,
    -121,   156,    98,    99,   131,   103,   -34,   103,   157,   247,
     248,   134,   148,   100,    55,   399,   149,   219,    93,   288,
      55,  -204,  -204,  -204,  -204,  -204,   289,   110,   268,  -191,
     271,   210,   146,    52,   156,   131,  -199,  -191,   128,  -125,
     129,    55,     6,     7,  -199,   150,    41,     9,    55,    64,
      41,   217,    41,   148,  -125,   106,   211,   149,  -188,   420,
     152,    55,    55,    55,  -125,  -185,  -188,   164,   379,    39,
      39,   -66,    55,  -185,   207,   207,   207,   207,   207,   207,
     207,   207,  -186,    55,   207,    64,   -66,   217,   180,   182,
    -186,    55,  -192,   187,    55,   159,   177,   379,    55,    55,
    -192,   156,   156,   164,   184,   157,   190,    64,   156,    65,
     156,  -193,    39,   148,  -198,    56,    63,   149,    39,  -193,
     173,   184,  -198,   174,   175,   218,   245,   137,   138,   110,
     110,   159,  -195,   128,   164,   129,   246,   117,   157,    39,
    -195,   249,   156,   274,   250,   251,    39,   144,   110,   276,
     110,   164,   239,   240,   241,   242,   243,   106,   106,    39,
      39,    39,   159,   277,   257,   278,   256,   258,   259,    64,
      39,   217,   280,    41,    41,   156,   106,   145,   106,   159,
     279,    39,    59,  -204,  -204,  -204,  -204,  -204,   281,    39,
     291,  -191,    39,   136,   146,   295,    39,    39,   318,  -191,
     317,   319,   175,   213,   120,   157,   157,  -150,  -150,  -150,
    -150,  -150,   157,   298,   157,   315,    41,    52,   241,   242,
     243,   177,    41,   301,   370,   371,   372,   373,   374,   375,
    -149,  -149,  -149,  -149,  -149,    64,   316,   217,   366,   117,
     117,   324,   326,    41,   172,   179,   157,   327,   164,   339,
      41,   347,   342,   179,   343,   344,   345,   346,   117,   357,
     117,   349,   350,    41,    41,    41,   351,   352,   145,   353,
      59,   354,   363,   361,    41,   365,   159,    77,    78,   157,
     172,   164,   188,    92,    93,    41,   228,    76,   384,   115,
     385,   386,   123,    41,   387,   388,    41,     6,     7,    56,
      41,    41,    95,   389,   391,   392,   120,   120,   393,   159,
     401,   172,   311,   404,   415,   179,   334,   335,   336,   337,
     338,   408,   438,   416,   417,   120,   418,   120,   172,   169,
     419,   427,    92,    93,    71,   182,    76,   424,   432,   114,
     433,   435,   437,   294,    52,    52,     6,     7,   164,   164,
      85,    95,   275,   368,    97,   164,   191,   164,   429,    98,
     193,     0,   423,   231,   358,   169,    59,     0,     0,     0,
     179,     0,   179,     0,     0,     0,   159,   159,     0,   168,
       0,     0,     0,   159,     0,   159,     0,    52,     0,   164,
      96,   115,   115,    52,     0,     0,   169,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,   192,    98,   193,
     115,     0,   115,   169,    52,   168,     0,   159,     0,     0,
       0,    52,   164,     0,     0,   172,    56,    56,     0,    92,
      93,    71,    94,    76,    52,    52,   184,     0,   113,    72,
       0,   114,   114,     6,     7,    52,   168,     0,    95,     0,
     159,     0,     0,     0,     0,   112,    52,     0,   172,     0,
     114,     0,   114,   168,    52,     0,     0,    52,     0,    56,
       0,    52,    52,     0,     0,    56,     0,     0,   167,     0,
       0,     0,     0,     0,    26,     0,     0,    96,     0,     0,
       0,     0,     0,    59,    59,     0,    56,     0,     0,     0,
      97,     0,     0,    56,   107,    98,    99,     0,     0,     0,
     169,   224,     0,     0,   167,     0,    56,    56,   213,   199,
     199,     0,     0,     0,   356,   172,   172,    56,     0,     0,
       0,   116,   172,     0,   172,     0,    59,     0,    56,   362,
     113,   113,    59,   169,     0,   167,    56,     0,     0,    56,
       0,     0,     0,    56,    56,     0,     0,   112,   112,   113,
     168,   113,   167,    59,   383,     0,   172,     0,   197,   197,
      59,     0,     0,     0,   390,     0,   112,     0,   112,   230,
       0,     0,     0,    59,    59,    59,     0,     0,     0,     0,
       0,     0,     0,   168,    59,   203,   203,     0,     0,   172,
       0,     0,     0,     0,     0,    59,   107,   107,     0,     0,
     169,   169,     0,    59,     0,     0,    59,   169,     0,   169,
      59,    59,     0,     0,     0,   107,   403,   107,    92,    93,
       0,   182,    76,   116,   116,     0,     0,     0,     0,     0,
       0,   414,     6,     7,     0,     0,     0,    95,     0,     0,
       0,   169,   116,     0,   116,     0,   425,     0,     0,   167,
     168,   168,     0,     0,     0,     0,     0,   168,     0,   168,
       0,     0,     0,   230,     0,   436,     0,     0,     0,     0,
       0,     0,     0,   440,   169,     0,   441,     0,     0,     0,
       0,     0,   167,    92,    93,    71,   182,    76,     0,    97,
       0,   168,     0,     0,    98,   193,     0,     6,     7,     0,
       0,     0,    95,     0,     0,   137,   138,     0,     0,   333,
     333,   333,   333,   333,     0,   139,   140,   141,   142,     0,
       0,   143,     0,     0,   168,   144,   199,   199,   199,   199,
     199,   199,   199,   199,     0,     0,   199,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,   167,
     167,     0,     0,     0,    97,   145,   167,     0,   167,    98,
     193,     0,     0,     0,     0,     0,     0,     0,     0,   137,
     138,     0,   146,     0,     0,   197,   197,   197,   197,   197,
     197,   197,   197,  -148,  -148,   197,     0,     0,   304,   144,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,   203,   203,   203,   203,   203,   203,   203,
       0,     0,   203,     4,   426,     5,     0,     0,     0,     0,
    -148,  -148,  -148,   167,     6,     7,     0,     0,     8,     9,
       0,     0,    10,     0,     0,     0,   146,     0,     0,     0,
       0,     0,    11,     0,     0,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     4,     0,     5,    27,
       0,     0,     0,   137,   138,     0,     0,     6,     7,     0,
       0,     8,     9,     0,     0,    10,    28,  -148,  -148,     0,
       0,     0,     0,   144,     0,    11,    29,     0,   292,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    26,     4,
       0,     5,    27,     0,  -148,  -148,  -148,     0,     0,     0,
       6,     7,     0,     0,     8,     9,     0,     0,    10,    28,
     146,     0,     0,     0,     0,     0,     0,     0,    11,    29,
       0,   398,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     4,     0,     5,    27,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,     0,     8,     9,     0,
       0,    10,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    29,     0,   400,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     4,     0,     5,    27,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
       8,     9,     0,     0,    10,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    29,     0,   406,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,    26,     4,     0,
       5,    27,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,     0,     8,     9,     0,     0,    10,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    29,     0,
     409,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     4,     0,     5,    27,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     0,     0,     8,     9,     0,     0,
      10,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    29,     0,   421,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     4,     0,     5,    27,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     8,
       9,     0,     0,    10,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    29,     0,   430,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     4,     0,     5,
      27,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,     8,     9,     0,     0,    10,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    29,     0,   434,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       4,     0,     5,    27,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,     8,     9,     0,     0,    10,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      29,     0,   442,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     4,     0,     5,    27,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,     0,    10,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    29,   378,     0,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     0,     0,     0,    27,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
       2,    90,    67,    89,     6,     7,     2,    16,    17,    16,
     285,   180,   314,    98,    16,    17,     6,   145,     8,     6,
      37,     8,    24,    66,    26,     0,     6,     6,     8,    10,
      11,    16,   131,    24,    10,    11,     3,     4,     5,     6,
       7,     3,     4,    66,     6,    66,    10,    11,    91,   148,
      17,    18,   180,    54,    55,    22,    24,    80,    81,    66,
      81,     3,     4,    65,     6,     7,    45,    84,    91,     6,
      91,    73,    82,    84,     6,    17,    18,    66,    89,    89,
      22,    90,     6,    16,     8,    22,    88,    89,    90,    79,
      91,    58,    79,   368,    61,    97,    98,    82,     2,    79,
      89,    91,   404,    63,    91,    81,    23,    74,    89,    34,
      80,    91,    79,    80,    84,     5,   285,    81,    80,   121,
      24,    84,    82,   132,   126,   127,    93,   129,   130,   298,
     132,   433,    74,   135,    90,   126,   127,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   245,   149,     7,   234,
     235,   236,   237,   238,   145,    79,   147,   285,   126,   127,
      64,    65,    80,    17,    18,    82,    66,    91,    66,    73,
     298,   180,    66,    90,    31,    32,     6,   145,   180,   147,
      66,   246,    89,    37,   186,    81,    90,    81,   190,    89,
     192,    89,    16,    89,    66,    81,   100,    88,    89,   368,
      67,   192,     2,    12,    13,    14,    15,    82,    83,    81,
      82,    68,    69,    70,     6,    82,   218,    84,   220,    91,
      54,    55,   126,   127,    24,   311,   312,   131,    16,   315,
      84,   135,   234,   235,   236,   237,   238,    81,    82,     6,
     368,   145,    66,   147,   148,    89,   345,   346,   139,   140,
     141,   142,   143,   352,     3,   354,    80,     6,    82,    66,
      31,    32,    71,    72,    64,    65,     3,     4,     5,     6,
       7,     6,    16,    73,    81,    82,   285,    84,    66,    23,
      17,    18,   186,   285,    91,    22,   190,   386,   192,   298,
      90,    80,    80,    81,    82,    80,   298,    68,    69,    70,
     100,     3,   304,    91,     6,    17,    18,    66,    66,   311,
     312,   313,   314,   315,    80,    66,   405,   313,   314,    67,
     419,    58,    81,    81,    61,    37,   126,   127,     6,   220,
      81,   131,    91,    91,    84,   135,    80,    74,    82,    67,
      91,   245,    79,    80,    80,   145,    90,   147,   148,   126,
     127,    89,    80,    90,   356,   357,    84,     3,     4,   368,
     362,    73,    74,    75,    76,    77,   368,    24,   145,    81,
     147,     6,    84,     2,   278,    80,    81,    89,    82,    66,
      84,   383,    17,    18,    89,    80,   186,    22,   390,    80,
     190,    82,   192,    80,    81,    24,   405,    84,    81,   401,
       6,   403,   404,   405,    91,    81,    89,    64,   404,   313,
     314,    66,   414,    89,   305,   306,   307,   308,   309,   310,
     311,   312,    81,   425,   315,    80,    81,    82,    90,     6,
      89,   433,    81,    67,   436,    64,    65,   433,   440,   441,
      89,   345,   346,   100,    73,   245,    82,    80,   352,    82,
     354,    81,   356,    80,    81,     2,    23,    84,   362,    89,
       3,    90,    89,     6,     7,    84,    80,    17,    18,   126,
     127,   100,    81,    82,   131,    84,    16,    24,   278,   383,
      89,     3,   386,     6,     6,     7,   390,    37,   145,    90,
     147,   148,    73,    74,    75,    76,    77,   126,   127,   403,
     404,   405,   131,    81,     3,    66,   135,     6,     7,    80,
     414,    82,    83,   313,   314,   419,   145,    67,   147,   148,
      83,   425,     2,    73,    74,    75,    76,    77,    83,   433,
      90,    81,   436,    82,    84,     6,   440,   441,     3,    89,
       6,     6,     7,    90,    24,   345,   346,    73,    74,    75,
      76,    77,   352,    90,   354,    89,   356,   186,    75,    76,
      77,   190,   362,   192,   305,   306,   307,   308,   309,   310,
      73,    74,    75,    76,    77,    80,    90,    82,    83,   126,
     127,    81,    90,   383,    64,    65,   386,     6,   245,    81,
     390,    81,    83,    73,    83,    83,    80,    80,   145,    84,
     147,    83,    83,   403,   404,   405,    83,    80,    67,    81,
      90,    80,    26,    89,   414,    83,   245,    12,    13,   419,
     100,   278,    84,     3,     4,   425,     6,     7,    83,    24,
      83,    80,    27,   433,    81,     6,   436,    17,    18,   186,
     440,   441,    22,    16,    90,    81,   126,   127,    90,   278,
      80,   131,    10,    47,    81,   135,   239,   240,   241,   242,
     243,    90,    90,    81,    81,   145,    81,   147,   148,    64,
      80,    92,     3,     4,     5,     6,     7,    81,    81,    24,
      81,    92,    81,   187,   313,   314,    17,    18,   345,   346,
      17,    22,   150,   298,    74,   352,    87,   354,   412,    79,
      80,    -1,   405,   100,   278,   100,   186,    -1,    -1,    -1,
     190,    -1,   192,    -1,    -1,    -1,   345,   346,    -1,    64,
      -1,    -1,    -1,   352,    -1,   354,    -1,   356,    -1,   386,
      61,   126,   127,   362,    -1,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    -1,    78,    79,    80,
     145,    -1,   147,   148,   383,   100,    -1,   386,    -1,    -1,
      -1,   390,   419,    -1,    -1,   245,   313,   314,    -1,     3,
       4,     5,     6,     7,   403,   404,   405,    -1,    24,     8,
      -1,   126,   127,    17,    18,   414,   131,    -1,    22,    -1,
     419,    -1,    -1,    -1,    -1,    24,   425,    -1,   278,    -1,
     145,    -1,   147,   148,   433,    -1,    -1,   436,    -1,   356,
      -1,   440,   441,    -1,    -1,   362,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,   313,   314,    -1,   383,    -1,    -1,    -1,
      74,    -1,    -1,   390,    24,    79,    80,    -1,    -1,    -1,
     245,    97,    -1,    -1,   100,    -1,   403,   404,   405,    88,
      89,    -1,    -1,    -1,   276,   345,   346,   414,    -1,    -1,
      -1,    24,   352,    -1,   354,    -1,   356,    -1,   425,   291,
     126,   127,   362,   278,    -1,   131,   433,    -1,    -1,   436,
      -1,    -1,    -1,   440,   441,    -1,    -1,   126,   127,   145,
     245,   147,   148,   383,   316,    -1,   386,    -1,    88,    89,
     390,    -1,    -1,    -1,   326,    -1,   145,    -1,   147,    99,
      -1,    -1,    -1,   403,   404,   405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   278,   414,    88,    89,    -1,    -1,   419,
      -1,    -1,    -1,    -1,    -1,   425,   126,   127,    -1,    -1,
     345,   346,    -1,   433,    -1,    -1,   436,   352,    -1,   354,
     440,   441,    -1,    -1,    -1,   145,   378,   147,     3,     4,
      -1,     6,     7,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,   393,    17,    18,    -1,    -1,    -1,    22,    -1,    -1,
      -1,   386,   145,    -1,   147,    -1,   408,    -1,    -1,   245,
     345,   346,    -1,    -1,    -1,    -1,    -1,   352,    -1,   354,
      -1,    -1,    -1,   193,    -1,   427,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   435,   419,    -1,   438,    -1,    -1,    -1,
      -1,    -1,   278,     3,     4,     5,     6,     7,    -1,    74,
      -1,   386,    -1,    -1,    79,    80,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,    17,    18,    -1,    -1,   239,
     240,   241,   242,   243,    -1,    27,    28,    29,    30,    -1,
      -1,    33,    -1,    -1,   419,    37,   305,   306,   307,   308,
     309,   310,   311,   312,    -1,    -1,   315,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,
     346,    -1,    -1,    -1,    74,    67,   352,    -1,   354,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    84,    -1,    -1,   305,   306,   307,   308,   309,
     310,   311,   312,    31,    32,   315,    -1,    -1,    36,    37,
     386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,    -1,   315,     6,   410,     8,    -1,    -1,    -1,    -1,
      68,    69,    70,   419,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,     6,    -1,     8,    62,
      -1,    -1,    -1,    17,    18,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    25,    79,    31,    32,    -1,
      -1,    -1,    -1,    37,    -1,    35,    89,    -1,    91,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,     6,
      -1,     8,    62,    -1,    68,    69,    70,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    79,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    89,
      -1,    91,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,     6,    -1,     8,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    89,    -1,    91,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    58,     6,    -1,     8,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    89,    -1,    91,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    58,     6,    -1,
       8,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    25,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    89,    -1,
      91,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,     6,    -1,     8,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    89,    -1,    91,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,     6,    -1,     8,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    25,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    89,    -1,    91,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    58,     6,    -1,     8,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    25,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    89,    -1,    91,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,
       6,    -1,     8,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      89,    -1,    91,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,     6,    -1,     8,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    89,    90,    -1,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    95,    96,     0,     6,     8,    17,    18,    21,    22,
      25,    35,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    58,    62,    79,    89,
      97,    98,    99,   101,   102,   103,   104,   106,   111,   112,
     113,   114,   115,   121,   122,   123,   124,   127,   129,   130,
     131,   132,   133,   134,   144,   145,   155,   158,   159,   160,
     161,   162,    16,    23,    80,    82,   107,    16,     6,   145,
     145,     5,   146,    84,    90,    34,     7,   149,   149,     6,
     105,     6,   122,   145,     6,   106,   122,     6,    80,    80,
      80,     6,     3,     4,     6,    22,    61,    74,    79,    80,
      90,   110,   112,   114,   116,   117,   133,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   155,   156,   157,
     160,    80,   145,   149,     6,    89,    67,    67,    82,    84,
      84,    80,    66,    89,    89,    63,    82,    17,    18,    27,
      28,    29,    30,    33,    37,    67,    84,    67,    80,    84,
      80,   118,     6,     6,    93,   110,   112,   114,   116,   133,
     135,   136,   137,   141,   144,   145,   146,   147,   148,   149,
     150,   155,   160,     3,     6,     7,   112,   133,   145,   160,
      90,   118,     6,   112,   133,   145,   120,    67,    84,    89,
      82,   107,    78,    80,   112,   114,   133,   141,   145,   146,
     147,   148,   149,   150,   152,   153,   154,   157,   160,   153,
       6,   122,   128,   155,   162,    16,    66,    82,    84,     3,
      80,   139,   140,   145,   147,     3,   142,   145,     6,   119,
     141,   136,    16,    66,    31,    32,    68,    69,    70,    73,
      74,    75,    76,    77,   145,    80,    16,   156,   156,     3,
       6,     7,   145,   145,   135,   122,   133,     3,     6,     7,
     145,   157,   157,   157,   157,   157,   145,   145,   156,   158,
     145,   156,   135,   145,     6,   119,    90,    81,    66,    83,
      83,    83,    83,     6,    91,   108,   109,   115,   122,   145,
     158,    90,    91,    97,   105,     6,     3,     6,    90,   110,
     112,   133,   145,   151,    36,    12,    13,    14,    15,    71,
      72,    10,    11,    81,    81,    89,    90,     6,     3,     6,
     145,   157,    66,    81,    81,    91,    90,     6,   142,   142,
     142,   142,   142,   141,   143,   143,   143,   143,   143,    81,
     135,   118,    83,    83,    83,    80,    80,    81,    89,    83,
      83,    83,    80,    81,    80,    81,   120,    84,   137,    91,
     109,    89,   120,    26,   100,    83,    83,    91,   108,   145,
     152,   152,   152,   152,   152,   152,   153,   153,    90,    97,
     138,   138,   153,   120,    83,    83,    80,    81,     6,    16,
     120,    90,    81,    90,   135,   135,   135,   135,    91,   145,
      91,    80,    91,   120,    47,    89,    91,   135,    90,    91,
      54,    55,   125,   126,   120,    81,    81,    81,    81,    80,
     145,    91,   138,   128,    81,   120,   147,    92,    91,   126,
      91,   135,    81,    81,    91,    92,   120,    81,    90,   138,
     120,   120,    91
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
#line 84 "a.y"
    { execAndFreeNode((yyvsp[(2) - (2)].node));}
    break;

  case 5:
#line 88 "a.y"
    { (yyval.node) = opr(';' , 0 ); }
    break;

  case 6:
#line 89 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 90 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:
#line 91 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 9:
#line 92 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
#line 93 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
#line 98 "a.y"
    { (yyval.node) = opr(REQUIRE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 12:
#line 99 "a.y"
    { (yyval.node) = opr(REQUIRE_ONCE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 13:
#line 100 "a.y"
    { (yyval.node) = opr(XINCLUDE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 14:
#line 101 "a.y"
    { (yyval.node) = opr(REF , 1, string((yyvsp[(2) - (3)].sValue))); }
    break;

  case 15:
#line 106 "a.y"
    { (yyval.node) = opr(XTRY, 2,(yyvsp[(3) - (4)].node),NULL); }
    break;

  case 16:
#line 107 "a.y"
    { (yyval.node) = opr(XTRY, 2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); }
    break;

  case 17:
#line 111 "a.y"
    { (yyval.node) = opr(XCATCH, 2, (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); }
    break;

  case 18:
#line 116 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 117 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 20:
#line 118 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:
#line 119 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 22:
#line 120 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 23:
#line 121 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:
#line 127 "a.y"
    { (yyval.node) = opr(XCONST , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 25:
#line 132 "a.y"
    { (yyval.node) = opr(XLOCAL , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 26:
#line 133 "a.y"
    { (yyval.node) = opr(XLOCAL , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 27:
#line 138 "a.y"
    { (yyval.node) = changeNameSpace((yyvsp[(4) - (4)].sValue)); }
    break;

  case 28:
#line 142 "a.y"
    { (yyval.sValue) = (yyvsp[(1) - (1)].sValue) ; }
    break;

  case 29:
#line 143 "a.y"
    { (yyval.sValue) = namespaceNameCat((yyvsp[(1) - (3)].sValue),(yyvsp[(3) - (3)].sValue)) ; }
    break;

  case 30:
#line 148 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(1) - (4)].sValue) , (yyvsp[(2) - (4)].sValue), NULL,false); }
    break;

  case 31:
#line 149 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(1) - (5)].sValue) , (yyvsp[(2) - (5)].sValue), (yyvsp[(4) - (5)].node),false); }
    break;

  case 32:
#line 150 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(2) - (5)].sValue) , (yyvsp[(3) - (5)].sValue), NULL,true); }
    break;

  case 33:
#line 151 "a.y"
    { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ (yyval.node) = claxx((yyvsp[(2) - (6)].sValue) , (yyvsp[(3) - (6)].sValue), (yyvsp[(5) - (6)].node), true); }
    break;

  case 34:
#line 156 "a.y"
    { (yyval.sValue) = NULL; }
    break;

  case 35:
#line 157 "a.y"
    { (yyval.sValue) = (yyvsp[(2) - (2)].sValue); }
    break;

  case 36:
#line 162 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 37:
#line 163 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 38:
#line 167 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:
#line 168 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 40:
#line 169 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 41:
#line 174 "a.y"
    { (yyval.node) = opr(THIS , 0 ); }
    break;

  case 42:
#line 175 "a.y"
    {  (yyval.node) = opr(THIS,1,(yyvsp[(3) - (3)].node)); }
    break;

  case 43:
#line 177 "a.y"
    { (yyval.node) = opr(THIS, 1 , opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 44:
#line 182 "a.y"
    {  (yyval.node) = opr(THIS,1,(yyvsp[(3) - (3)].node)); }
    break;

  case 45:
#line 183 "a.y"
    {  (yyval.node) = opr(THIS, 1, (yyvsp[(3) - (3)].node) ); }
    break;

  case 46:
#line 188 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 47:
#line 189 "a.y"
    { (yyval.node) =  opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 48:
#line 190 "a.y"
    { (yyval.node) = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var((yyvsp[(1) - (6)].sValue)), argsNode((yyvsp[(3) - (6)].args)) ) , (yyvsp[(6) - (6)].node)); }
    break;

  case 49:
#line 191 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 50:
#line 196 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[(1) - (6)].node), opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) );}
    break;

  case 51:
#line 197 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[(1) - (6)].node), opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) );}
    break;

  case 52:
#line 198 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var((yyvsp[(1) - (9)].sValue)), argsNode((yyvsp[(3) - (9)].args)) ) , opr(FUNC_CALL,2, (yyvsp[(6) - (9)].node), argsNode((yyvsp[(8) - (9)].args)) )); }
    break;

  case 53:
#line 199 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[(1) - (6)].node),opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 54:
#line 200 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[(1) - (6)].node),opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 55:
#line 205 "a.y"
    { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)) ; }
    break;

  case 56:
#line 211 "a.y"
    { (yyval.node) = dtrt((yyvsp[(2) - (7)].sValue),(yyvsp[(4) - (7)].params),(yyvsp[(6) - (7)].node));}
    break;

  case 57:
#line 212 "a.y"
    { (yyval.node) = func((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].params),(yyvsp[(5) - (6)].node));}
    break;

  case 58:
#line 213 "a.y"
    { (yyval.node) = func((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].params),(yyvsp[(5) - (6)].node));}
    break;

  case 59:
#line 218 "a.y"
    { (yyval.node) = lambda((yyvsp[(2) - (7)].params),(yyvsp[(6) - (7)].node)) ;}
    break;

  case 60:
#line 219 "a.y"
    { (yyval.node) = lambda(params(NULL, (yyvsp[(1) - (5)].sValue)),(yyvsp[(4) - (5)].node)) ; }
    break;

  case 61:
#line 220 "a.y"
    { (yyval.node) = lambda((yyvsp[(1) - (5)].params),(yyvsp[(4) - (5)].node)) ; }
    break;

  case 62:
#line 224 "a.y"
    { (yyval.params) = params2((yyvsp[(1) - (3)].sValue),(yyvsp[(3) - (3)].sValue));  }
    break;

  case 63:
#line 225 "a.y"
    { (yyval.params) = params((yyvsp[(1) - (3)].params),(yyvsp[(3) - (3)].sValue));  }
    break;

  case 64:
#line 229 "a.y"
    { (yyval.params) = NULL; }
    break;

  case 65:
#line 230 "a.y"
    { (yyval.params) = (yyvsp[(2) - (3)].params); }
    break;

  case 66:
#line 234 "a.y"
    { (yyval.params) = params(NULL, (yyvsp[(1) - (1)].sValue)); }
    break;

  case 67:
#line 235 "a.y"
    { (yyval.params) = params((yyvsp[(1) - (3)].params),(yyvsp[(3) - (3)].sValue)); }
    break;

  case 68:
#line 236 "a.y"
    { (yyval.params) = NULL; }
    break;

  case 69:
#line 240 "a.y"
    { (yyval.node) = opr(';',2,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 70:
#line 241 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 71:
#line 245 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 72:
#line 246 "a.y"
    { (yyval.node) = arrayNode((yyvsp[(1) - (4)].sValue),(yyvsp[(3) - (4)].intValue),NULL); }
    break;

  case 73:
#line 247 "a.y"
    {  (yyval.node) = arrayNode((yyvsp[(1) - (4)].sValue),-1,var((yyvsp[(3) - (4)].sValue))); }
    break;

  case 74:
#line 248 "a.y"
    { (yyval.node) = arrayNode((yyvsp[(1) - (4)].sValue),-1,(yyvsp[(3) - (4)].node)); }
    break;

  case 75:
#line 253 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 76:
#line 254 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 77:
#line 259 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 78:
#line 260 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 79:
#line 265 "a.y"
    { (yyval.node) = opr(IF ,2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)) ; }
    break;

  case 80:
#line 266 "a.y"
    { (yyval.node) = opr(IF ,3,(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(7) - (7)].node)) ; }
    break;

  case 81:
#line 267 "a.y"
    { (yyval.node) = opr(SWITCH, 2 , (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); pretreatSwitch( (yyval.node) ) ; }
    break;

  case 82:
#line 271 "a.y"
    { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[(1) - (1)].node) ); }
    break;

  case 83:
#line 272 "a.y"
    { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node) ); }
    break;

  case 84:
#line 276 "a.y"
    { (yyval.node) = opr(CASE, 2 , (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 85:
#line 277 "a.y"
    { (yyval.node) = opr(DEFAULT , 1, (yyvsp[(3) - (3)].node)); }
    break;

  case 86:
#line 281 "a.y"
    { (yyval.node) = opr(WHILE , 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node) ); }
    break;

  case 87:
#line 282 "a.y"
    { (yyval.node) = opr(FOR,4,(yyvsp[(3) - (9)].node),(yyvsp[(5) - (9)].node),(yyvsp[(7) - (9)].node),(yyvsp[(9) - (9)].node)); }
    break;

  case 88:
#line 287 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 89:
#line 288 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 90:
#line 289 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 91:
#line 290 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 92:
#line 295 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 93:
#line 296 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 94:
#line 297 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:
#line 298 "a.y"
    { (yyval.node) = opr(DELETE, 1 ,(yyvsp[(2) - (2)].sValue) ); }
    break;

  case 96:
#line 299 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 97:
#line 300 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 98:
#line 301 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 99:
#line 302 "a.y"
    { (yyval.node) = opr(XCONTINUE , 0 ); }
    break;

  case 100:
#line 303 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 101:
#line 308 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 102:
#line 313 "a.y"
    { (yyval.node) = opr(RESTRICT,0);}
    break;

  case 103:
#line 314 "a.y"
    { (yyval.node) = opr(RESTRICT,1,(yyvsp[(2) - (2)].node)); }
    break;

  case 104:
#line 318 "a.y"
    { (yyval.node) = opr(BREAK, 0); }
    break;

  case 105:
#line 319 "a.y"
    { (yyval.node) = opr(RETURN , 0); }
    break;

  case 106:
#line 320 "a.y"
    { (yyval.node) = opr(RETURN , 1 ,(yyvsp[(2) - (2)].node));}
    break;

  case 107:
#line 321 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 108:
#line 326 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, (yyvsp[(1) - (4)].node), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 109:
#line 327 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, var((yyvsp[(1) - (4)].sValue)), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 110:
#line 328 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 111:
#line 329 "a.y"
    { (yyval.node) = opr(SCOPE_FUNC_CALL,2,(yyvsp[(1) - (4)].node),argsNode((yyvsp[(3) - (4)].args))); }
    break;

  case 112:
#line 333 "a.y"
    { (yyval.node) = opr(PIPELINE_OP,2, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 113:
#line 339 "a.y"
    { (yyval.args) = NULL; }
    break;

  case 114:
#line 340 "a.y"
    { (yyval.args) = (yyvsp[(1) - (1)].args); }
    break;

  case 115:
#line 344 "a.y"
    { (yyval.args) = xArgs(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 116:
#line 345 "a.y"
    { (yyval.args) = xArgs((yyvsp[(1) - (3)].args), (yyvsp[(3) - (3)].node)); }
    break;

  case 117:
#line 349 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 118:
#line 350 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 119:
#line 351 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 120:
#line 352 "a.y"
    { /*printf("IDENTIFIER $1= %s\n" , $1);*/ (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 121:
#line 353 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 122:
#line 354 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 123:
#line 355 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 124:
#line 356 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 125:
#line 357 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 126:
#line 358 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 127:
#line 359 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 128:
#line 360 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 129:
#line 361 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 130:
#line 362 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 131:
#line 366 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 132:
#line 367 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 133:
#line 373 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 134:
#line 374 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 135:
#line 379 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 136:
#line 385 "a.y"
    { (yyval.node) = opr('+',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 137:
#line 386 "a.y"
    { (yyval.node) = opr('-',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 138:
#line 387 "a.y"
    { (yyval.node) = opr('*',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 139:
#line 388 "a.y"
    { (yyval.node) = opr('/',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 140:
#line 389 "a.y"
    { (yyval.node) = opr('%',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 141:
#line 390 "a.y"
    { (yyval.node) = opr('&',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 142:
#line 391 "a.y"
    { (yyval.node) = opr('|',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 143:
#line 392 "a.y"
    { (yyval.node) = opr('^',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 144:
#line 393 "a.y"
    { /* printf("get a ~ opr.\n"); */ (yyval.node) = opr('~',1,(yyvsp[(2) - (2)].node)); }
    break;

  case 145:
#line 394 "a.y"
    { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 146:
#line 395 "a.y"
    { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 147:
#line 400 "a.y"
    { (yyval.node) = xint((yyvsp[(1) - (1)].intValue)); }
    break;

  case 148:
#line 401 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 149:
#line 406 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 150:
#line 408 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 151:
#line 409 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node) ; }
    break;

  case 152:
#line 414 "a.y"
    { (yyval.node) = opr(NEW ,2, (yyvsp[(2) - (5)].node) , argsNode((yyvsp[(4) - (5)].args)) ); }
    break;

  case 153:
#line 418 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 154:
#line 422 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 155:
#line 426 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 156:
#line 427 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].intValue)); }
    break;

  case 157:
#line 431 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 158:
#line 432 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 159:
#line 436 "a.y"
    { (yyval.node) = string((yyvsp[(1) - (1)].sValue)); }
    break;

  case 160:
#line 440 "a.y"
    { (yyval.node) = xnull();}
    break;

  case 161:
#line 444 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 162:
#line 445 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 163:
#line 446 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 164:
#line 447 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 165:
#line 452 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 166:
#line 453 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 167:
#line 454 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 168:
#line 455 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 169:
#line 460 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 170:
#line 461 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 171:
#line 462 "a.y"
    { (yyval.node) = opr('!', 1, (yyvsp[(2) - (2)].node));}
    break;

  case 172:
#line 463 "a.y"
    { (yyval.node) = opr('>',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 173:
#line 464 "a.y"
    { (yyval.node) = opr('<',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 174:
#line 465 "a.y"
    { (yyval.node) = opr( LE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 175:
#line 466 "a.y"
    { (yyval.node) = opr( GE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 176:
#line 467 "a.y"
    { (yyval.node) = opr( EQ_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 177:
#line 468 "a.y"
    { (yyval.node) = opr( NE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 178:
#line 469 "a.y"
    { (yyval.node) = opr(AND_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 179:
#line 470 "a.y"
    { (yyval.node) = opr(OR_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 180:
#line 475 "a.y"
    { (yyval.node) = opr(XIS ,2 , (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 181:
#line 480 "a.y"
    { (yyval.node) = opr(INC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 182:
#line 481 "a.y"
    { (yyval.node) = opr(DEC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 183:
#line 482 "a.y"
    { (yyval.node) = sopr(INC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 184:
#line 483 "a.y"
    { (yyval.node) = sopr(DEC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 185:
#line 488 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 186:
#line 489 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 187:
#line 490 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 188:
#line 491 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 189:
#line 492 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
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
    { (yyval.node) =(yyvsp[(1) - (1)].node) ;}
    break;

  case 200:
#line 507 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:
#line 508 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:
#line 509 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:
#line 510 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:
#line 511 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
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
#line 521 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 211:
#line 522 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node) ); }
    break;

  case 212:
#line 526 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 213:
#line 527 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 214:
#line 532 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), (yyvsp[(3) - (4)].intValue), NULL); }
    break;

  case 215:
#line 533 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 216:
#line 534 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 217:
#line 535 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].intValue), NULL) ; }
    break;

  case 218:
#line 536 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 219:
#line 537 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 220:
#line 538 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node),  (yyvsp[(3) - (4)].intValue), NULL ) ; }
    break;

  case 221:
#line 539 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 222:
#line 540 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 223:
#line 546 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 224:
#line 551 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 225:
#line 552 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 226:
#line 553 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 227:
#line 554 "a.y"
    { (yyval.node) = opr(ADD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 228:
#line 555 "a.y"
    { (yyval.node) = opr(SUB_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 229:
#line 556 "a.y"
    { (yyval.node) = opr(MUL_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 230:
#line 557 "a.y"
    { (yyval.node) = opr(DIV_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 231:
#line 558 "a.y"
    { (yyval.node) = opr(MOD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;


/* Line 1267 of yacc.c.  */
#line 3311 "y.tab.c"
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


#line 561 "a.y"


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

	initLangX(argc, argv);

	doFile(argv[1]);
	//for(int i = 1; i < argc; i++)
	//	doFile(argv[i]);

	closeLangX();

	//printf("parse over!\n");
	return 0;
}

