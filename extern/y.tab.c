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
     TBOOL = 259,
     TDOUBLE = 260,
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
#define TBOOL 259
#define TDOUBLE 260
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


#include "../include/YLlangX.h"
#include "../include/Program.h"



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
#line 8 "a.y"
{
 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
}
/* Line 193 of yacc.c.  */
#line 250 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 263 "y.tab.c"

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
#define YYLAST   1753

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNRULES -- Number of states.  */
#define YYNSTATES  438

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
       2,     2,     2,    78,     2,     2,     2,    77,    70,     2,
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
     379,   381,   383,   386,   388,   390,   393,   398,   403,   405,
     410,   415,   416,   418,   420,   424,   426,   428,   430,   432,
     434,   436,   438,   440,   442,   444,   446,   448,   450,   454,
     456,   458,   460,   464,   468,   472,   476,   480,   484,   488,
     492,   496,   499,   503,   507,   509,   511,   513,   515,   519,
     525,   527,   529,   531,   533,   536,   539,   541,   543,   545,
     547,   549,   551,   553,   555,   557,   559,   561,   563,   566,
     570,   574,   578,   582,   586,   590,   594,   598,   602,   605,
     608,   611,   614,   616,   618,   620,   622,   624,   626,   628,
     630,   632,   634,   636,   638,   640,   642,   644,   646,   648,
     650,   652,   654,   656,   658,   660,   662,   664,   668,   672,
     676,   680,   685,   690,   695,   700,   705,   710,   715,   720,
     725,   729,   731,   733,   735,   739,   743,   747,   751
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      94,     0,    -1,    95,    -1,    95,    96,    -1,    -1,    89,
      -1,   100,    -1,   122,    -1,   128,    89,    -1,    97,    -1,
      98,    -1,    39,   147,    -1,    40,   147,    -1,    62,   147,
      -1,    41,   104,    89,    -1,    25,    90,   119,    91,    -1,
      25,    90,   119,    91,    99,    -1,    26,    80,   143,    81,
      90,   119,    91,    -1,   114,    -1,   121,    -1,   105,    -1,
     103,    89,    -1,   101,    -1,   102,    -1,    43,   121,    -1,
      44,   121,    -1,    44,   105,    -1,    35,    34,    67,   104,
      -1,     6,    -1,   104,    84,     6,    -1,     6,   106,    90,
      91,    -1,     6,   106,    90,   107,    91,    -1,    45,     6,
     106,    90,    91,    -1,    45,     6,   106,    90,   107,    91,
      -1,    -1,    23,     6,    -1,   108,    -1,   107,   108,    -1,
     121,    -1,   156,    89,    -1,   114,    -1,    22,    -1,    22,
      84,   143,    -1,    22,    84,   143,    80,   133,    81,    -1,
      22,    84,   143,    -1,    22,    84,   111,    -1,   143,    84,
     143,    -1,   112,    84,   143,    -1,     6,    80,   133,    81,
      84,   143,    -1,   111,    84,   143,    -1,   143,    84,   143,
      80,   133,    81,    -1,   158,    84,   143,    80,   133,    81,
      -1,     6,    80,   133,    81,    84,   143,    80,   133,    81,
      -1,   111,    84,   143,    80,   133,    81,    -1,   112,    84,
     143,    80,   133,    81,    -1,   143,    37,   143,    -1,    79,
       6,    16,   117,    90,   119,    91,    -1,     6,    16,   117,
      90,   119,    91,    -1,     8,    16,   117,    90,   119,    91,
      -1,    80,   118,    81,    16,    90,   119,    91,    -1,     6,
      16,    90,   119,    91,    -1,   116,    16,    90,   119,    91,
      -1,     6,    66,     6,    -1,   116,    66,     6,    -1,    -1,
      80,   118,    81,    -1,     6,    -1,   118,    66,     6,    -1,
      -1,   119,    96,    -1,    -1,   143,    -1,     6,    82,     3,
      83,    -1,     6,    82,     6,    83,    -1,     6,    82,   131,
      83,    -1,   120,    89,    -1,   120,    66,   121,    -1,   123,
      -1,   126,    -1,    46,    80,   151,    81,   136,    -1,    46,
      80,   151,    81,   136,    47,   136,    -1,    53,    80,   143,
      81,    90,   124,    91,    -1,   125,    -1,   124,   125,    -1,
      54,   145,    92,   119,    -1,    55,    92,   119,    -1,    48,
      80,   151,    81,   136,    -1,    49,    80,   127,    89,   151,
      89,   127,    81,   136,    -1,    -1,   160,    -1,   121,    -1,
     153,    -1,   153,    -1,   160,    -1,   131,    -1,    50,     6,
      -1,   130,    -1,   142,    -1,   129,    -1,    42,    -1,   132,
      -1,    21,    -1,    21,   144,    -1,    51,    -1,    52,    -1,
      52,   154,    -1,   158,    80,   133,    81,    -1,     6,    80,
     133,    81,    -1,   112,    -1,   113,    80,   133,    81,    -1,
     131,    63,   131,    89,    -1,    -1,   134,    -1,   135,    -1,
     134,    66,   135,    -1,   115,    -1,   144,    -1,   145,    -1,
       6,    -1,   147,    -1,   146,    -1,   131,    -1,   139,    -1,
     158,    -1,   111,    -1,   113,    -1,   142,    -1,   148,    -1,
      90,   119,    91,    -1,    96,    -1,   145,    -1,   138,    -1,
      80,   155,    81,    -1,   141,    73,   141,    -1,   141,    74,
     141,    -1,   141,    75,   141,    -1,   141,    76,   141,    -1,
     141,    77,   141,    -1,   140,    70,   140,    -1,   140,    68,
     140,    -1,   140,    69,   140,    -1,    79,   140,    -1,   140,
      31,   140,    -1,   140,    32,   140,    -1,     3,    -1,   143,
      -1,   155,    -1,   139,    -1,    80,   139,    81,    -1,    58,
     143,    80,   133,    81,    -1,     6,    -1,     4,    -1,     5,
      -1,     3,    -1,    74,   137,    -1,    74,   143,    -1,     7,
      -1,    61,    -1,   143,    -1,   131,    -1,   111,    -1,   109,
      -1,   155,    -1,   139,    -1,   144,    -1,   148,    -1,   150,
      -1,   152,    -1,    78,   149,    -1,   150,    71,   150,    -1,
     150,    72,   150,    -1,   150,    12,   150,    -1,   150,    13,
     150,    -1,   150,    14,   150,    -1,   150,    15,   150,    -1,
     151,    10,   151,    -1,   151,    11,   151,    -1,   143,    36,
     143,    -1,    17,   143,    -1,    18,   143,    -1,   143,    17,
      -1,   143,    18,    -1,   145,    -1,   146,    -1,   144,    -1,
     139,    -1,   131,    -1,   115,    -1,   143,    -1,   147,    -1,
     153,    -1,   142,    -1,   111,    -1,   148,    -1,   109,    -1,
     158,    -1,   113,    -1,   145,    -1,   146,    -1,   147,    -1,
     131,    -1,   143,    -1,   153,    -1,   111,    -1,   113,    -1,
     109,    -1,   158,    -1,   143,    67,   154,    -1,   143,    67,
     156,    -1,   111,    67,   154,    -1,   110,    67,   154,    -1,
       6,    82,     3,    83,    -1,     6,    82,     6,    83,    -1,
       6,    82,     7,    83,    -1,   111,    82,     3,    83,    -1,
     111,    82,     6,    83,    -1,   111,    82,     7,    83,    -1,
     131,    82,     3,    83,    -1,   131,    82,     6,    83,    -1,
     131,    82,     7,    83,    -1,   158,    67,   154,    -1,   156,
      -1,   157,    -1,   159,    -1,   143,    27,   155,    -1,   143,
      28,   155,    -1,   143,    29,   155,    -1,   143,    30,   155,
      -1,   143,    33,   155,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    65,    65,    69,    70,    73,    74,    75,    76,    77,
      78,    83,    84,    85,    86,    91,    92,    96,   101,   102,
     103,   104,   105,   106,   112,   117,   118,   123,   127,   128,
     133,   134,   135,   136,   141,   142,   147,   148,   152,   153,
     154,   159,   160,   162,   167,   168,   173,   174,   175,   176,
     181,   182,   183,   184,   185,   190,   196,   197,   198,   203,
     204,   205,   209,   210,   214,   215,   219,   220,   221,   225,
     226,   230,   231,   232,   233,   238,   239,   244,   245,   250,
     251,   252,   256,   257,   261,   262,   266,   267,   272,   273,
     274,   275,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   293,   294,   298,   299,   300,   305,   306,   307,   308,
     312,   318,   319,   323,   324,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   344,   345,
     351,   352,   357,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   378,   379,   384,   385,   386,   391,
     395,   399,   403,   404,   408,   409,   413,   417,   421,   422,
     423,   424,   429,   430,   431,   432,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   452,   457,   458,
     459,   460,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   498,   499,   503,
     504,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     523,   528,   529,   530,   531,   532,   533,   534,   535
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "XINTEGER", "TBOOL", "TDOUBLE",
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
  "UMINUS", "';'", "'{'", "'}'", "':'", "$accept", "program",
  "statement_list", "statement", "require_stmt", "try_stmt",
  "catch_block_stmt", "declar_stmt", "const_declar_stmt",
  "local_declar_stmt", "namespace_declar_stmt", "namespace_name_stmt",
  "class_declar_stmt", "extends_stmt", "class_body", "class_body_stmt",
  "this_stmt", "this_member_stmt", "class_member_stmt",
  "class_member_func_stmt", "static_member_stmt", "func_declar_stmt",
  "lambda_stmt", "lambda_args_stmt", "param_list", "parameter",
  "expr_list", "element_var_declar_stmt", "var_declar_stmt",
  "con_ctl_stmt", "selection_stmt", "case_stmt_list", "case_stmt",
  "loop_stmt", "for_1_stmt", "simple_stmt", "restrict_stmt",
  "interrupt_stmt", "call_statement", "call_statement_pipeline",
  "args_list", "args_expr", "args_expr_collection", "block",
  "double_or_ps_expr", "parentheses_stmt", "arithmetic_stmt",
  "bit_opr_factor", "arithmetic_stmt_factor", "new_expr", "id_expr",
  "t_bool_expr", "double_expr", "uminus_expr", "string_expr", "null_expr",
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
     123,   125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    98,    98,    99,   100,   100,
     100,   100,   100,   100,   101,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   109,   109,   109,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   113,   114,   114,   114,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   119,
     119,   120,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     132,   133,   133,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     137,   137,   138,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   141,   142,
     143,   144,   145,   145,   146,   146,   147,   148,   149,   149,
     149,   149,   150,   150,   150,   150,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   152,   153,   153,
     153,   153,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   156,   156,   157,
     157,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   160,   160,   160,   160,   160,   160,   160,   160
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
       1,     1,     2,     1,     1,     2,     4,     4,     1,     4,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     1,     1,     1,     1,     3,     5,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     1,     1,     1,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   150,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,     0,     0,     0,     5,
       3,     9,    10,     6,    22,    23,     0,    20,     0,     0,
     108,     0,    18,     0,    19,     7,    77,    78,     0,    98,
      96,    94,   100,    97,    71,    92,   221,   222,     0,   223,
      93,    64,     0,   111,     0,     0,    64,   150,   178,   179,
     151,   102,     0,    70,     0,   156,    11,    12,    28,     0,
     150,    24,    71,   150,    26,    25,    34,     0,     0,    88,
      95,   153,   152,   150,    41,   157,     0,     0,    68,   205,
     203,   204,   187,     0,   200,   147,     0,     0,   191,   145,
     184,   197,   198,   199,   193,   202,   105,   146,   206,     0,
       0,    13,     0,    21,     0,     0,     0,     0,     0,   111,
       0,    75,     8,     0,     0,   180,   181,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,    68,     0,
      35,   150,   205,   203,   204,   115,   200,     0,   112,   113,
     147,   126,   201,   116,   197,   198,   199,   127,   202,   206,
       0,   150,     0,     0,     0,     0,     0,     0,     0,   150,
      45,     0,    44,     0,     0,     0,    14,     0,     0,     0,
       0,   203,   204,   200,   163,   201,   164,   197,   198,   199,
     165,   166,     0,   167,   162,   206,     0,   150,    90,     0,
      91,    89,     0,     0,     0,     0,   153,     0,   154,   131,
     155,   130,   144,   141,   145,   150,     0,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,    64,   210,   209,     0,     0,     0,    49,    47,
       0,    76,     0,     0,     0,     0,   201,   224,   225,   226,
     227,   228,    55,   145,   207,   208,    46,   220,     0,     0,
      66,     0,    70,   107,     0,   211,   212,   213,    74,   150,
      30,     0,    36,    40,    38,    71,     0,    70,    15,    69,
      27,    29,     0,   150,     0,   161,   160,   159,   158,   168,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    62,     0,     0,    42,     0,     0,     0,
     148,    70,    63,   142,   143,   139,   140,   138,   147,   133,
     134,   135,   136,   137,     0,     0,     0,   214,   215,   216,
     111,   111,   109,   110,   217,   218,   219,   111,   106,   111,
      65,     0,     0,   114,    31,    37,    39,     0,     0,    16,
      72,    73,    32,     0,   177,   171,   172,   173,   174,   169,
     170,   175,   176,    70,   129,    79,    86,     0,     0,   211,
     212,   111,   132,    67,     0,     0,     0,   149,    70,     0,
       0,     0,     0,    57,    48,    58,     0,    33,     0,     0,
      88,    60,     0,    70,    61,     0,     0,     0,    82,     0,
      53,    54,    50,    51,   111,     0,   128,    80,     0,    43,
       0,     0,    70,    81,    83,    56,     0,     0,     0,    59,
      70,    85,    52,    70,    87,    84,     0,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   289,    31,    32,   359,    33,    34,    35,
      36,    79,    37,    65,   281,   282,   152,    38,   191,    40,
     192,    42,   155,   103,   149,   226,   183,    43,    44,    45,
      46,   407,   408,    47,   209,    48,    49,    50,   193,    52,
     157,   158,   159,   375,   218,   219,   160,   106,   107,    53,
     162,   163,   197,   198,   199,   167,   299,   201,   202,   203,
     168,   116,   117,    56,    57,   205,    59,    60
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -285
static const yytype_int16 yypact[] =
{
    -285,    41,  1664,  -285,   134,    50,    32,    32,    93,    19,
      31,    99,   160,   160,   166,  -285,   172,    37,   212,   188,
     203,   235,   330,  -285,   405,   260,    32,   160,   340,  -285,
    -285,  -285,  -285,  -285,  -285,  -285,   275,  -285,   306,    16,
     309,   315,  -285,   -39,  -285,  -285,  -285,  -285,   346,  -285,
    -285,   -40,  -285,  -285,   173,  -285,  -285,  -285,   236,  -285,
    -285,   333,   434,   919,   351,   366,   333,  -285,  -285,  -285,
    -285,  -285,   441,  -285,   393,  -285,  -285,  -285,  -285,    18,
     380,  -285,  -285,   -13,  -285,  -285,   445,   643,   643,   267,
    -285,   269,  -285,   167,   381,  -285,    34,   371,   764,   -21,
     355,   263,  -285,    39,   155,   -10,   347,   430,  -285,   778,
    -285,    95,   116,   189,  -285,   207,  -285,  -285,   244,    32,
     384,  -285,   453,  -285,   405,   405,   418,    32,    32,   919,
     172,  -285,  -285,   441,   435,  -285,  -285,    58,    58,    58,
      58,    58,    32,   405,    32,   405,   919,    32,   464,   383,
    -285,    83,  -285,   114,   161,  -285,   182,   399,   417,  -285,
     -37,  -285,   875,  -285,    89,   142,   201,  -285,  -285,   196,
     388,   319,   403,   135,    71,   -17,   250,     5,   397,   112,
     135,   407,   -17,  1134,   166,   484,  -285,   449,   402,    68,
    1033,   135,   315,   407,   452,   589,  -285,  -285,  -285,  -285,
    -285,   246,    35,  -285,   481,   250,    38,   280,  -285,   404,
    -285,  -285,   406,   488,   442,    32,  -285,    58,  -285,  -285,
    -285,  -285,  -285,  -285,  -285,   324,   209,   416,   408,   493,
     371,   371,   371,   371,   371,  1033,  1033,  1033,  1033,  1033,
     432,   919,   333,  -285,  -285,   433,   437,   438,   451,   454,
     455,  -285,   222,   439,   456,   461,    36,  -285,  -285,  -285,
    -285,  -285,  -285,   500,  -285,  -285,   467,  -285,   469,   468,
    -285,   229,  -285,   448,   919,   -30,    -8,  -285,  -285,    -4,
    -285,    13,  -285,  -285,  -285,   485,   471,  -285,   535,  -285,
     480,  -285,   482,   348,    22,  -285,   135,   407,   -17,  -285,
      32,  1070,  1070,  1070,  1070,  1070,  1070,   643,   643,  1611,
    1611,   643,  -285,  -285,   483,   486,   492,   487,   572,   563,
    -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,  -285,   311,
     311,  -285,  -285,  -285,   495,   501,   496,  -285,  -285,  -285,
     919,   919,  -285,  -285,  -285,  -285,  -285,   919,  -285,   919,
    -285,  1187,    32,  -285,  -285,  -285,  -285,  1240,   510,  -285,
    -285,  -285,  -285,    27,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,  -285,   581,  -285,  -285,   545,  -285,    21,  1293,  -285,
    -285,   919,  -285,  -285,   514,  1346,   268,  -285,  -285,   524,
     527,   528,   529,  -285,   532,  -285,    32,  -285,  1399,  1611,
     267,  -285,   533,  -285,  -285,   377,   521,     2,  -285,  1452,
    -285,  -285,  -285,  -285,   919,   536,  -285,  -285,   537,  -285,
    1505,   539,  -285,  -285,  -285,  -285,   538,   544,  1611,  -285,
    -285,  1664,  -285,  -285,  -285,  1664,  1558,  -285
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -285,  -285,  -285,     4,  -285,  -285,  -285,  -285,  -285,  -285,
    -285,   443,   612,   549,   342,  -272,    23,  -285,   110,  -285,
     202,  -170,   -16,  -285,   -63,   491,  -101,  -285,     0,  -285,
    -285,  -285,   233,  -285,   241,  -285,  -285,  -285,   499,  -285,
     -95,  -285,   369,  -284,  -285,  -285,   859,   -72,   490,   688,
      -2,    64,   676,   744,   329,   390,  -285,   293,   -86,  -285,
     357,   126,   815,  -125,  -285,   591,  -285,   -88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -202
static const yytype_int16 yytable[] =
{
      54,   211,   206,   178,    68,    69,    30,   283,   102,   355,
      62,   279,    61,     5,    82,    82,    81,    85,   265,   279,
     142,     5,   109,   133,   120,   223,   376,   130,   279,  -122,
       5,   307,   308,   279,   250,     5,   -72,   216,    67,    92,
      67,     3,   134,    83,  -122,   307,   308,    99,   307,   308,
     131,   268,   286,   135,   136,   228,   405,   406,   -73,   -72,
    -194,   216,   175,    92,   179,    75,    66,   144,  -194,   187,
     182,  -185,    71,   142,   179,     6,     7,   -34,   187,  -185,
      94,   -73,    18,   125,    28,   195,   195,    54,   110,   208,
      94,   355,    28,   423,   220,   224,   280,    70,   126,   212,
     127,    28,   185,    72,   354,   229,    28,   186,   102,   102,
     400,   283,    39,   362,   217,   417,   309,   240,   397,   310,
     144,    73,   109,   109,   283,   248,   249,   102,    82,   102,
     251,   175,    96,    74,   100,   256,   256,   256,   256,   256,
     262,   263,   266,   109,   434,   269,   335,    99,    99,  -118,
      61,   196,   196,   134,   278,  -117,   286,    62,   323,   324,
     325,   326,   327,    63,  -118,   214,    99,    75,    99,   286,
    -117,   351,    78,   153,   173,   285,  -182,   284,    80,   336,
    -124,    54,   180,   212,  -182,   175,   357,   298,   110,   110,
     135,   136,    63,   283,   214,  -124,   126,  -183,   127,    39,
     137,   138,   139,   140,    41,  -183,   141,   110,  -120,   110,
     142,   378,   295,   316,    63,   256,    64,   126,    86,   127,
     385,   371,   372,  -120,   -34,   377,   101,  -125,   224,   224,
     224,   224,   224,   213,   100,   100,  -186,   134,   286,   153,
     143,   129,  -125,   173,  -186,   389,   390,    63,  -121,   214,
     243,   244,   391,   100,   392,   100,   153,   144,   301,   302,
     303,   304,  -123,  -121,   134,   154,    41,  -119,    87,   264,
    -189,   267,   398,   207,    41,   318,   146,  -123,  -189,   285,
     147,   284,  -119,    88,     6,     7,   402,   409,  -190,     9,
     319,    41,   285,    39,   284,   318,  -190,   173,   364,   296,
    -144,  -144,   420,   145,   134,   195,   195,    54,    54,   195,
     350,   343,   211,   374,   374,    89,   146,   305,   306,   426,
     147,   431,   405,   406,   146,  -195,   101,   101,   147,   435,
     146,   154,   436,  -195,   147,    41,    90,  -144,  -144,  -144,
     119,    76,    77,   129,  -196,   101,   122,   101,   154,    54,
     394,   153,  -196,   113,   170,    54,   121,   171,   172,    55,
      63,   285,    64,   284,   123,   196,   196,   196,   196,   196,
     196,   196,   196,   124,   222,   196,    54,    67,   230,   231,
     216,   115,    92,    54,   153,    41,   237,   238,   239,    41,
     -66,    41,   166,   128,   415,   129,    54,    54,    54,    63,
     208,   214,   276,   374,    63,   -66,   214,    54,    91,    70,
      92,    93,    75,   148,   114,   232,   233,   234,    54,    39,
      39,   245,     6,     7,   246,   247,    54,    94,    63,    54,
     214,   361,   374,    54,    54,   132,  -192,   126,   253,   127,
     150,   254,   255,   154,  -192,   314,   210,   179,   315,   172,
     153,   153,   292,   113,   113,   293,   177,   153,   166,   153,
     184,    39,   187,    26,   241,   215,    95,    39,    62,   242,
     270,   275,   113,   272,   113,   166,   154,   200,   200,    96,
     273,   115,   115,   274,    97,    98,   277,   287,    39,   134,
     291,   153,   294,   311,   313,    39,   312,   320,   321,   322,
     115,    51,   115,   235,   236,   237,   238,   239,    39,    39,
      39,    41,    41,   334,   114,   114,   337,   135,   136,    39,
     338,   339,   344,   104,   153,  -147,  -147,  -147,  -147,  -147,
      39,   340,   352,   114,   341,   114,   342,   142,    39,   345,
      55,    39,   154,   154,   346,    39,    39,   347,   349,   154,
     348,   154,   143,    41,  -146,  -146,  -146,  -146,  -146,    41,
     356,   358,   156,   174,   185,   360,   379,   143,   382,   380,
     166,   181,   381,  -201,  -201,  -201,  -201,  -201,   383,   384,
      41,  -188,   387,   154,   144,   386,   388,    41,   181,  -188,
     396,   307,   399,    58,   365,   366,   367,   368,   369,   370,
      41,    41,    41,   166,   403,   410,   135,   136,   411,   412,
     413,    41,   414,   422,   419,   118,   154,   427,   428,   432,
    -145,  -145,    41,   104,   104,   300,   142,   290,   156,    84,
      41,   430,   252,    41,   433,   188,   363,    41,    41,   271,
     424,   418,   104,   353,   104,   156,    91,    70,    92,   179,
      75,     0,     0,     0,   169,   176,     0,  -145,  -145,  -145,
       6,     7,     0,   176,     0,    94,    55,    55,     0,   166,
     166,     0,     0,   144,     0,     0,   166,     0,   166,     0,
      58,     0,    51,     0,     0,     0,   174,     0,   297,     0,
       0,   200,   200,   200,   200,   200,   200,   200,   200,     0,
     111,   200,     0,     0,    95,     0,     0,     0,    55,     0,
     166,     0,   108,     0,    55,   118,   118,    96,     0,     0,
     169,   189,    97,   190,   176,   329,   330,   331,   332,   333,
       0,     0,     0,     0,   118,    55,   118,   169,     0,   164,
     156,     0,    55,   166,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,     0,    55,    55,   210,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    91,   112,    92,
     225,    75,   221,   156,    58,     0,     0,    55,   176,     0,
     176,     6,     7,     0,     0,    55,    94,     0,    55,     0,
       0,     0,    55,    55,     0,   135,   136,     0,     0,     0,
     111,   111,     0,     0,     0,   164,     0,   165,    51,    51,
       0,     0,   108,   108,     0,   142,     0,   161,     0,   111,
       0,   111,   164,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   169,   108,   161,     0,     0,     0,    96,   156,
     156,     0,     0,    97,   190,     0,   156,     0,   156,     0,
      51,  -201,  -201,  -201,  -201,  -201,    51,     0,     0,  -188,
       0,     0,   144,     0,     0,   169,     0,  -188,   112,   112,
       0,     0,     0,   165,     0,     0,     0,    51,     0,     0,
     156,     0,     0,   105,    51,     0,     0,   112,     0,   112,
     165,     0,   135,   136,     0,     0,     0,    51,    51,   181,
      58,    58,   204,   204,     0,     0,  -145,  -145,    51,     0,
       0,     0,   142,   156,     0,     0,     0,   164,     0,    51,
       0,     0,    91,    70,    92,   151,    75,    51,     0,   161,
      51,   169,   169,     0,    51,    51,     6,     7,   169,     0,
     169,    94,    58,  -145,  -145,  -145,   194,   194,    58,     0,
     164,     0,   257,   258,   259,   260,   261,   227,     0,   144,
       0,     0,   161,     0,     0,     0,     0,     0,     0,    58,
       0,     0,   169,     0,     0,     0,    58,    26,     0,     0,
      95,     0,     0,   105,   105,   165,     0,     0,     0,    58,
      58,    58,     0,    96,     0,     0,     0,     0,    97,    98,
      58,     0,   105,     0,   105,   169,     0,     0,     0,     0,
       0,    58,     0,     0,     0,     0,   164,   164,   165,    58,
       0,     0,    58,   164,     0,   164,    58,    58,   161,   161,
       0,     0,   317,     0,     0,   161,    91,   161,    92,   179,
      75,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       6,     7,     0,     0,     0,    94,     0,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,     0,    91,    70,    92,   179,    75,     0,     0,
       0,   421,     0,     0,   165,   165,     0,     6,     7,     0,
     164,   165,    94,   165,   328,   328,   328,   328,   328,     0,
       0,     0,   161,     0,     0,     0,     0,    96,     0,     0,
       0,     0,    97,   190,     0,     0,   204,   204,   204,   204,
     204,   204,   204,   204,     0,   165,   204,     0,     0,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     5,     0,    96,     0,     0,     0,     0,    97,
     190,     6,     7,     0,     0,     8,     9,     0,   165,    10,
     194,   194,   194,   194,   194,   194,   194,   194,     0,    11,
     194,     0,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     4,     0,     5,    27,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,     0,    10,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    29,     0,   288,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     4,     0,     5,    27,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     0,
       0,     8,     9,     0,     0,    10,    28,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    29,     0,   393,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    26,     4,
       0,     5,    27,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     0,     0,     8,     9,     0,     0,    10,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    29,
       0,   395,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     4,     0,     5,    27,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,     0,     8,     9,     0,
       0,    10,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    29,     0,   401,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     4,     0,     5,    27,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
       8,     9,     0,     0,    10,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    29,     0,   404,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,    26,     4,     0,
       5,    27,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,     0,     8,     9,     0,     0,    10,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    29,     0,
     416,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     4,     0,     5,    27,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     0,     0,     8,     9,     0,     0,
      10,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    29,     0,   425,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     4,     0,     5,    27,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     8,
       9,     0,     0,    10,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    29,     0,   429,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     4,     0,     5,
      27,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,     8,     9,     0,     0,    10,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    29,     0,   437,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       4,     0,     5,    27,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,     8,     9,     0,     0,    10,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      29,   373,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
       2,    89,    88,    66,     6,     7,     2,   177,    24,   281,
      23,     6,    16,     8,    16,    17,    16,    17,   143,     6,
      37,     8,    24,    63,    26,    97,   310,    66,     6,    66,
       8,    10,    11,     6,   129,     8,    66,     3,     6,     5,
       6,     0,    82,     6,    81,    10,    11,    24,    10,    11,
      89,   146,   177,    17,    18,    16,    54,    55,    66,    89,
      81,     3,    64,     5,     6,     7,    16,    84,    89,    82,
      72,    81,     8,    37,     6,    17,    18,    90,    82,    89,
      22,    89,    45,    67,    79,    87,    88,    89,    24,    89,
      22,   363,    79,    91,    96,    97,    91,     4,    82,    16,
      84,    79,    84,    84,    91,    66,    79,    89,   124,   125,
      89,   281,     2,    91,    80,   399,    81,   119,    91,    81,
      84,    90,   124,   125,   294,   127,   128,   143,   130,   145,
     130,   133,    74,    34,    24,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   428,   147,   241,   124,   125,    66,
      16,    87,    88,    82,    83,    66,   281,    23,   230,   231,
     232,   233,   234,    80,    81,    82,   143,     7,   145,   294,
      81,   272,     6,    63,    64,   177,    81,   177,     6,   242,
      66,   183,    72,    16,    89,   187,   287,   189,   124,   125,
      17,    18,    80,   363,    82,    81,    82,    81,    84,    89,
      27,    28,    29,    30,     2,    89,    33,   143,    66,   145,
      37,   312,   189,   215,    80,   217,    82,    82,     6,    84,
     321,   307,   308,    81,    90,   311,    24,    66,   230,   231,
     232,   233,   234,    66,   124,   125,    81,    82,   363,   129,
      67,    80,    81,   133,    89,   340,   341,    80,    66,    82,
     124,   125,   347,   143,   349,   145,   146,    84,    12,    13,
      14,    15,    66,    81,    82,    63,    64,    66,    80,   143,
      81,   145,   373,     6,    72,    66,    80,    81,    89,   281,
      84,   281,    81,    80,    17,    18,   381,   388,    81,    22,
      81,    89,   294,   183,   294,    66,    89,   187,   300,   189,
      31,    32,   403,    67,    82,   307,   308,   309,   310,   311,
      81,    89,   400,   309,   310,    80,    80,    71,    72,   414,
      84,   422,    54,    55,    80,    81,   124,   125,    84,   430,
      80,   129,   433,    89,    84,   133,     6,    68,    69,    70,
      80,    12,    13,    80,    81,   143,     6,   145,   146,   351,
     352,   241,    89,    24,     3,   357,    27,     6,     7,     2,
      80,   363,    82,   363,    89,   301,   302,   303,   304,   305,
     306,   307,   308,    67,     3,   311,   378,     6,    31,    32,
       3,    24,     5,   385,   274,   183,    75,    76,    77,   187,
      66,   189,    63,    84,   396,    80,   398,   399,   400,    80,
     400,    82,    83,   399,    80,    81,    82,   409,     3,     4,
       5,     6,     7,    80,    24,    68,    69,    70,   420,   309,
     310,     3,    17,    18,     6,     7,   428,    22,    80,   431,
      82,    83,   428,   435,   436,    89,    81,    82,     3,    84,
       6,     6,     7,   241,    89,     3,    89,     6,     6,     7,
     340,   341,     3,   124,   125,     6,    90,   347,   129,   349,
      67,   351,    82,    58,    80,    84,    61,   357,    23,    16,
       6,    83,   143,    90,   145,   146,   274,    87,    88,    74,
      81,   124,   125,    66,    79,    80,    83,    90,   378,    82,
       6,   381,    90,    89,     6,   385,    90,    81,    90,     6,
     143,     2,   145,    73,    74,    75,    76,    77,   398,   399,
     400,   309,   310,    81,   124,   125,    83,    17,    18,   409,
      83,    83,    83,    24,   414,    73,    74,    75,    76,    77,
     420,    80,    84,   143,    80,   145,    81,    37,   428,    83,
     183,   431,   340,   341,    83,   435,   436,    80,    80,   347,
      81,   349,    67,   351,    73,    74,    75,    76,    77,   357,
      89,    26,    63,    64,    84,    83,    83,    67,    81,    83,
     241,    72,    80,    73,    74,    75,    76,    77,     6,    16,
     378,    81,    81,   381,    84,    90,    90,   385,    89,    89,
      80,    10,    47,     2,   301,   302,   303,   304,   305,   306,
     398,   399,   400,   274,    90,    81,    17,    18,    81,    81,
      81,   409,    80,    92,    81,    24,   414,    81,    81,    81,
      31,    32,   420,   124,   125,    36,    37,   184,   129,    17,
     428,    92,   133,   431,    90,    86,   294,   435,   436,   148,
     407,   400,   143,   274,   145,   146,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    63,    64,    -1,    68,    69,    70,
      17,    18,    -1,    72,    -1,    22,   309,   310,    -1,   340,
     341,    -1,    -1,    84,    -1,    -1,   347,    -1,   349,    -1,
      89,    -1,   183,    -1,    -1,    -1,   187,    -1,   189,    -1,
      -1,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      24,   311,    -1,    -1,    61,    -1,    -1,    -1,   351,    -1,
     381,    -1,    24,    -1,   357,   124,   125,    74,    -1,    -1,
     129,    78,    79,    80,   133,   235,   236,   237,   238,   239,
      -1,    -1,    -1,    -1,   143,   378,   145,   146,    -1,    63,
     241,    -1,   385,   414,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    -1,    -1,   398,   399,   400,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   409,     3,    24,     5,
       6,     7,    96,   274,   183,    -1,    -1,   420,   187,    -1,
     189,    17,    18,    -1,    -1,   428,    22,    -1,   431,    -1,
      -1,    -1,   435,   436,    -1,    17,    18,    -1,    -1,    -1,
     124,   125,    -1,    -1,    -1,   129,    -1,    63,   309,   310,
      -1,    -1,   124,   125,    -1,    37,    -1,   129,    -1,   143,
      -1,   145,   146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,   241,   145,   146,    -1,    -1,    -1,    74,   340,
     341,    -1,    -1,    79,    80,    -1,   347,    -1,   349,    -1,
     351,    73,    74,    75,    76,    77,   357,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,   274,    -1,    89,   124,   125,
      -1,    -1,    -1,   129,    -1,    -1,    -1,   378,    -1,    -1,
     381,    -1,    -1,    24,   385,    -1,    -1,   143,    -1,   145,
     146,    -1,    17,    18,    -1,    -1,    -1,   398,   399,   400,
     309,   310,    87,    88,    -1,    -1,    31,    32,   409,    -1,
      -1,    -1,    37,   414,    -1,    -1,    -1,   241,    -1,   420,
      -1,    -1,     3,     4,     5,     6,     7,   428,    -1,   241,
     431,   340,   341,    -1,   435,   436,    17,    18,   347,    -1,
     349,    22,   351,    68,    69,    70,    87,    88,   357,    -1,
     274,    -1,   137,   138,   139,   140,   141,    98,    -1,    84,
      -1,    -1,   274,    -1,    -1,    -1,    -1,    -1,    -1,   378,
      -1,    -1,   381,    -1,    -1,    -1,   385,    58,    -1,    -1,
      61,    -1,    -1,   124,   125,   241,    -1,    -1,    -1,   398,
     399,   400,    -1,    74,    -1,    -1,    -1,    -1,    79,    80,
     409,    -1,   143,    -1,   145,   414,    -1,    -1,    -1,    -1,
      -1,   420,    -1,    -1,    -1,    -1,   340,   341,   274,   428,
      -1,    -1,   431,   347,    -1,   349,   435,   436,   340,   341,
      -1,    -1,   217,    -1,    -1,   347,     3,   349,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      17,    18,    -1,    -1,    -1,    22,    -1,   381,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   381,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,   405,    -1,    -1,   340,   341,    -1,    17,    18,    -1,
     414,   347,    22,   349,   235,   236,   237,   238,   239,    -1,
      -1,    -1,   414,    -1,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    -1,    79,    80,    -1,    -1,   301,   302,   303,   304,
     305,   306,   307,   308,    -1,   381,   311,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,     8,    -1,    74,    -1,    -1,    -1,    -1,    79,
      80,    17,    18,    -1,    -1,    21,    22,    -1,   414,    25,
     301,   302,   303,   304,   305,   306,   307,   308,    -1,    35,
     311,    -1,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,     6,    -1,     8,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    89,    -1,    91,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,     6,    -1,     8,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    25,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    89,    -1,    91,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,     6,
      -1,     8,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    89,
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
      89,    90,    -1,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    94,    95,     0,     6,     8,    17,    18,    21,    22,
      25,    35,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    58,    62,    79,    89,
      96,    97,    98,   100,   101,   102,   103,   105,   110,   111,
     112,   113,   114,   120,   121,   122,   123,   126,   128,   129,
     130,   131,   132,   142,   143,   153,   156,   157,   158,   159,
     160,    16,    23,    80,    82,   106,    16,     6,   143,   143,
       4,   144,    84,    90,    34,     7,   147,   147,     6,   104,
       6,   121,   143,     6,   105,   121,     6,    80,    80,    80,
       6,     3,     5,     6,    22,    61,    74,    79,    80,   109,
     111,   113,   115,   116,   131,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   153,   154,   155,   158,    80,
     143,   147,     6,    89,    67,    67,    82,    84,    84,    80,
      66,    89,    89,    63,    82,    17,    18,    27,    28,    29,
      30,    33,    37,    67,    84,    67,    80,    84,    80,   117,
       6,     6,   109,   111,   113,   115,   131,   133,   134,   135,
     139,   142,   143,   144,   145,   146,   147,   148,   153,   158,
       3,     6,     7,   111,   131,   143,   158,    90,   117,     6,
     111,   131,   143,   119,    67,    84,    89,    82,   106,    78,
      80,   111,   113,   131,   139,   143,   144,   145,   146,   147,
     148,   150,   151,   152,   155,   158,   151,     6,   121,   127,
     153,   160,    16,    66,    82,    84,     3,    80,   137,   138,
     143,   145,     3,   140,   143,     6,   118,   139,    16,    66,
      31,    32,    68,    69,    70,    73,    74,    75,    76,    77,
     143,    80,    16,   154,   154,     3,     6,     7,   143,   143,
     133,   121,   131,     3,     6,     7,   143,   155,   155,   155,
     155,   155,   143,   143,   154,   156,   143,   154,   133,   143,
       6,   118,    90,    81,    66,    83,    83,    83,    83,     6,
      91,   107,   108,   114,   121,   143,   156,    90,    91,    96,
     104,     6,     3,     6,    90,   109,   111,   131,   143,   149,
      36,    12,    13,    14,    15,    71,    72,    10,    11,    81,
      81,    89,    90,     6,     3,     6,   143,   155,    66,    81,
      81,    90,     6,   140,   140,   140,   140,   140,   139,   141,
     141,   141,   141,   141,    81,   133,   117,    83,    83,    83,
      80,    80,    81,    89,    83,    83,    83,    80,    81,    80,
      81,   119,    84,   135,    91,   108,    89,   119,    26,    99,
      83,    83,    91,   107,   143,   150,   150,   150,   150,   150,
     150,   151,   151,    90,    96,   136,   136,   151,   119,    83,
      83,    80,    81,     6,    16,   119,    90,    81,    90,   133,
     133,   133,   133,    91,   143,    91,    80,    91,   119,    47,
      89,    91,   133,    90,    91,    54,    55,   124,   125,   119,
      81,    81,    81,    81,    80,   143,    91,   136,   127,    81,
     119,   145,    92,    91,   125,    91,   133,    81,    81,    91,
      92,   119,    81,    90,   136,   119,   119,    91
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
#line 69 "a.y"
    { execAndFreeNode((yyvsp[(2) - (2)].node));}
    break;

  case 5:
#line 73 "a.y"
    { (yyval.node) = opr(';' , 0 ); }
    break;

  case 6:
#line 74 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 75 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:
#line 76 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 9:
#line 77 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
#line 78 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 11:
#line 83 "a.y"
    { (yyval.node) = opr(REQUIRE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 12:
#line 84 "a.y"
    { (yyval.node) = opr(REQUIRE_ONCE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 13:
#line 85 "a.y"
    { (yyval.node) = opr(XINCLUDE , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 14:
#line 86 "a.y"
    { (yyval.node) = opr(REF , 1, string((yyvsp[(2) - (3)].sValue))); }
    break;

  case 15:
#line 91 "a.y"
    { (yyval.node) = opr(XTRY, 2,(yyvsp[(3) - (4)].node),NULL); }
    break;

  case 16:
#line 92 "a.y"
    { (yyval.node) = opr(XTRY, 2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); }
    break;

  case 17:
#line 96 "a.y"
    { (yyval.node) = opr(XCATCH, 2, (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); }
    break;

  case 18:
#line 101 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 102 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 20:
#line 103 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 21:
#line 104 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 22:
#line 105 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 23:
#line 106 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 24:
#line 112 "a.y"
    { (yyval.node) = opr(XCONST , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 25:
#line 117 "a.y"
    { (yyval.node) = opr(XLOCAL , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 26:
#line 118 "a.y"
    { (yyval.node) = opr(XLOCAL , 1,(yyvsp[(2) - (2)].node)); }
    break;

  case 27:
#line 123 "a.y"
    { (yyval.node) = changeNameSpace((yyvsp[(4) - (4)].sValue)); }
    break;

  case 28:
#line 127 "a.y"
    { (yyval.sValue) = (yyvsp[(1) - (1)].sValue) ; }
    break;

  case 29:
#line 128 "a.y"
    { (yyval.sValue) = namespaceNameCat((yyvsp[(1) - (3)].sValue),(yyvsp[(3) - (3)].sValue)) ; }
    break;

  case 30:
#line 133 "a.y"
    {  (yyval.node) = claxx((yyvsp[(1) - (4)].sValue) , (yyvsp[(2) - (4)].sValue), NULL,false); }
    break;

  case 31:
#line 134 "a.y"
    { (yyval.node) = claxx((yyvsp[(1) - (5)].sValue) , (yyvsp[(2) - (5)].sValue), (yyvsp[(4) - (5)].node),false); }
    break;

  case 32:
#line 135 "a.y"
    {  (yyval.node) = claxx((yyvsp[(2) - (5)].sValue) , (yyvsp[(3) - (5)].sValue), NULL,true); }
    break;

  case 33:
#line 136 "a.y"
    {  (yyval.node) = claxx((yyvsp[(2) - (6)].sValue) , (yyvsp[(3) - (6)].sValue), (yyvsp[(5) - (6)].node), true); }
    break;

  case 34:
#line 141 "a.y"
    { (yyval.sValue) = NULL; }
    break;

  case 35:
#line 142 "a.y"
    { (yyval.sValue) = (yyvsp[(2) - (2)].sValue); }
    break;

  case 36:
#line 147 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 37:
#line 148 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 38:
#line 152 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:
#line 153 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 40:
#line 154 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 41:
#line 159 "a.y"
    { (yyval.node) = opr(THIS , 0 ); }
    break;

  case 42:
#line 160 "a.y"
    {  (yyval.node) = opr(THIS,1,(yyvsp[(3) - (3)].node)); }
    break;

  case 43:
#line 162 "a.y"
    { (yyval.node) = opr(THIS, 1 , opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 44:
#line 167 "a.y"
    {  (yyval.node) = opr(THIS,1,(yyvsp[(3) - (3)].node)); }
    break;

  case 45:
#line 168 "a.y"
    {  (yyval.node) = opr(THIS, 1, (yyvsp[(3) - (3)].node) ); }
    break;

  case 46:
#line 173 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 47:
#line 174 "a.y"
    { (yyval.node) =  opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 48:
#line 175 "a.y"
    { (yyval.node) = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var((yyvsp[(1) - (6)].sValue)), argsNode((yyvsp[(3) - (6)].args)) ) , (yyvsp[(6) - (6)].node)); }
    break;

  case 49:
#line 176 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 50:
#line 181 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[(1) - (6)].node), opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) );}
    break;

  case 51:
#line 182 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[(1) - (6)].node), opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) );}
    break;

  case 52:
#line 183 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var((yyvsp[(1) - (9)].sValue)), argsNode((yyvsp[(3) - (9)].args)) ) , opr(FUNC_CALL,2, (yyvsp[(6) - (9)].node), argsNode((yyvsp[(8) - (9)].args)) )); }
    break;

  case 53:
#line 184 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[(1) - (6)].node),opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 54:
#line 185 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[(1) - (6)].node),opr(FUNC_CALL,2, (yyvsp[(3) - (6)].node), argsNode((yyvsp[(5) - (6)].args)) ) ); }
    break;

  case 55:
#line 190 "a.y"
    { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)) ; }
    break;

  case 56:
#line 196 "a.y"
    { (yyval.node) = dtrt((yyvsp[(2) - (7)].sValue),(yyvsp[(4) - (7)].params),(yyvsp[(6) - (7)].node));}
    break;

  case 57:
#line 197 "a.y"
    { (yyval.node) = func((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].params),(yyvsp[(5) - (6)].node));}
    break;

  case 58:
#line 198 "a.y"
    { (yyval.node) = func((yyvsp[(1) - (6)].sValue),(yyvsp[(3) - (6)].params),(yyvsp[(5) - (6)].node));}
    break;

  case 59:
#line 203 "a.y"
    { (yyval.node) = lambda((yyvsp[(2) - (7)].params),(yyvsp[(6) - (7)].node)) ;}
    break;

  case 60:
#line 204 "a.y"
    { (yyval.node) = lambda(params(NULL, (yyvsp[(1) - (5)].sValue)),(yyvsp[(4) - (5)].node)) ; }
    break;

  case 61:
#line 205 "a.y"
    { (yyval.node) = lambda((yyvsp[(1) - (5)].params),(yyvsp[(4) - (5)].node)) ; }
    break;

  case 62:
#line 209 "a.y"
    { (yyval.params) = params2((yyvsp[(1) - (3)].sValue),(yyvsp[(3) - (3)].sValue));  }
    break;

  case 63:
#line 210 "a.y"
    { (yyval.params) = params((yyvsp[(1) - (3)].params),(yyvsp[(3) - (3)].sValue));  }
    break;

  case 64:
#line 214 "a.y"
    { (yyval.params) = NULL; }
    break;

  case 65:
#line 215 "a.y"
    { (yyval.params) = (yyvsp[(2) - (3)].params); }
    break;

  case 66:
#line 219 "a.y"
    { (yyval.params) = params(NULL, (yyvsp[(1) - (1)].sValue)); }
    break;

  case 67:
#line 220 "a.y"
    { (yyval.params) = params((yyvsp[(1) - (3)].params),(yyvsp[(3) - (3)].sValue)); }
    break;

  case 68:
#line 221 "a.y"
    { (yyval.params) = NULL; }
    break;

  case 69:
#line 225 "a.y"
    { (yyval.node) = opr(';',2,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 70:
#line 226 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 71:
#line 230 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 72:
#line 231 "a.y"
    { (yyval.node) = arrayNode((yyvsp[(1) - (4)].sValue),(yyvsp[(3) - (4)].iValue),NULL); }
    break;

  case 73:
#line 232 "a.y"
    {  (yyval.node) = arrayNode((yyvsp[(1) - (4)].sValue),-1,var((yyvsp[(3) - (4)].sValue))); }
    break;

  case 74:
#line 233 "a.y"
    { (yyval.node) = arrayNode((yyvsp[(1) - (4)].sValue),-1,(yyvsp[(3) - (4)].node)); }
    break;

  case 75:
#line 238 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 76:
#line 239 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 77:
#line 244 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 78:
#line 245 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 79:
#line 250 "a.y"
    { (yyval.node) = opr(IF ,2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)) ; }
    break;

  case 80:
#line 251 "a.y"
    { (yyval.node) = opr(IF ,3,(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node),(yyvsp[(7) - (7)].node)) ; }
    break;

  case 81:
#line 252 "a.y"
    { (yyval.node) = opr(SWITCH, 2 , (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); pretreatSwitch( (yyval.node) ) ; }
    break;

  case 82:
#line 256 "a.y"
    { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[(1) - (1)].node) ); }
    break;

  case 83:
#line 257 "a.y"
    { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node) ); }
    break;

  case 84:
#line 261 "a.y"
    { (yyval.node) = opr(CASE, 2 , (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 85:
#line 262 "a.y"
    { (yyval.node) = opr(DEFAULT , 1, (yyvsp[(3) - (3)].node)); }
    break;

  case 86:
#line 266 "a.y"
    { (yyval.node) = opr(WHILE , 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node) ); }
    break;

  case 87:
#line 267 "a.y"
    { (yyval.node) = opr(FOR,4,(yyvsp[(3) - (9)].node),(yyvsp[(5) - (9)].node),(yyvsp[(7) - (9)].node),(yyvsp[(9) - (9)].node)); }
    break;

  case 88:
#line 272 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 89:
#line 273 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 90:
#line 274 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 91:
#line 275 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 92:
#line 280 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 93:
#line 281 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 94:
#line 282 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:
#line 283 "a.y"
    { (yyval.node) = opr(DELETE, 1 ,(yyvsp[(2) - (2)].sValue) ); }
    break;

  case 96:
#line 284 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 97:
#line 285 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 98:
#line 286 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 99:
#line 287 "a.y"
    { (yyval.node) = opr(XCONTINUE , 0 ); }
    break;

  case 100:
#line 288 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 101:
#line 293 "a.y"
    { (yyval.node) = opr(RESTRICT,0);}
    break;

  case 102:
#line 294 "a.y"
    { (yyval.node) = opr(RESTRICT,1,(yyvsp[(2) - (2)].node)); }
    break;

  case 103:
#line 298 "a.y"
    { (yyval.node) = opr(BREAK, 0); }
    break;

  case 104:
#line 299 "a.y"
    { (yyval.node) = opr(RETURN , 0); }
    break;

  case 105:
#line 300 "a.y"
    { (yyval.node) = opr(RETURN , 1 ,(yyvsp[(2) - (2)].node));}
    break;

  case 106:
#line 305 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, (yyvsp[(1) - (4)].node), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 107:
#line 306 "a.y"
    { (yyval.node) = opr(FUNC_CALL,2, var((yyvsp[(1) - (4)].sValue)), argsNode((yyvsp[(3) - (4)].args)) ); }
    break;

  case 108:
#line 307 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 109:
#line 308 "a.y"
    { (yyval.node) = opr(SCOPE_FUNC_CALL,2,(yyvsp[(1) - (4)].node),argsNode((yyvsp[(3) - (4)].args))); }
    break;

  case 110:
#line 312 "a.y"
    { (yyval.node) = opr(PIPELINE_OP,2, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node)); }
    break;

  case 111:
#line 318 "a.y"
    { (yyval.args) = NULL; }
    break;

  case 112:
#line 319 "a.y"
    { (yyval.args) = (yyvsp[(1) - (1)].args); }
    break;

  case 113:
#line 323 "a.y"
    { (yyval.args) = xArgs(NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 114:
#line 324 "a.y"
    { (yyval.args) = xArgs((yyvsp[(1) - (3)].args), (yyvsp[(3) - (3)].node)); }
    break;

  case 115:
#line 328 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 116:
#line 329 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 117:
#line 330 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 118:
#line 331 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 119:
#line 332 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 120:
#line 333 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 121:
#line 334 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 122:
#line 335 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 123:
#line 336 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 124:
#line 337 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 125:
#line 338 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 126:
#line 339 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 127:
#line 340 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 128:
#line 344 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 129:
#line 345 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 130:
#line 351 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 131:
#line 352 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 132:
#line 357 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 133:
#line 363 "a.y"
    { (yyval.node) = opr('+',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 134:
#line 364 "a.y"
    { (yyval.node) = opr('-',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 135:
#line 365 "a.y"
    { (yyval.node) = opr('*',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 136:
#line 366 "a.y"
    { (yyval.node) = opr('/',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 137:
#line 367 "a.y"
    { (yyval.node) = opr('%',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 138:
#line 368 "a.y"
    { (yyval.node) = opr('&',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 139:
#line 369 "a.y"
    { (yyval.node) = opr('|',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 140:
#line 370 "a.y"
    { (yyval.node) = opr('^',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 141:
#line 371 "a.y"
    { (yyval.node) = opr('~',1,(yyvsp[(2) - (2)].node)); }
    break;

  case 142:
#line 372 "a.y"
    { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 143:
#line 373 "a.y"
    { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 144:
#line 378 "a.y"
    { (yyval.node) = xint((yyvsp[(1) - (1)].iValue)); }
    break;

  case 145:
#line 379 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 146:
#line 384 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 147:
#line 385 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ; }
    break;

  case 148:
#line 386 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node) ; }
    break;

  case 149:
#line 391 "a.y"
    { (yyval.node) = opr(NEW ,2, (yyvsp[(2) - (5)].node) , argsNode((yyvsp[(4) - (5)].args)) ); }
    break;

  case 150:
#line 395 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 151:
#line 399 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 152:
#line 403 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].dValue)); }
    break;

  case 153:
#line 404 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].iValue)); }
    break;

  case 154:
#line 408 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 155:
#line 409 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 156:
#line 413 "a.y"
    { (yyval.node) = string((yyvsp[(1) - (1)].sValue)); }
    break;

  case 157:
#line 417 "a.y"
    { (yyval.node) = xnull();}
    break;

  case 158:
#line 421 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 159:
#line 422 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 160:
#line 423 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 161:
#line 424 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 162:
#line 429 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 163:
#line 430 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 164:
#line 431 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 165:
#line 432 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 166:
#line 437 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 167:
#line 438 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 168:
#line 439 "a.y"
    { (yyval.node) = opr('!', 1, (yyvsp[(2) - (2)].node));}
    break;

  case 169:
#line 440 "a.y"
    { (yyval.node) = opr('>',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 170:
#line 441 "a.y"
    { (yyval.node) = opr('<',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 171:
#line 442 "a.y"
    { (yyval.node) = opr( LE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 172:
#line 443 "a.y"
    { (yyval.node) = opr( GE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 173:
#line 444 "a.y"
    { (yyval.node) = opr( EQ_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 174:
#line 445 "a.y"
    { (yyval.node) = opr( NE_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 175:
#line 446 "a.y"
    { (yyval.node) = opr(AND_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 176:
#line 447 "a.y"
    { (yyval.node) = opr(OR_OP,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 177:
#line 452 "a.y"
    { (yyval.node) = opr(XIS ,2 , (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 178:
#line 457 "a.y"
    { (yyval.node) = opr(INC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 179:
#line 458 "a.y"
    { (yyval.node) = opr(DEC_OP,1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 180:
#line 459 "a.y"
    { (yyval.node) = sopr(INC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 181:
#line 460 "a.y"
    { (yyval.node) = sopr(DEC_OP,1, (yyvsp[(1) - (2)].node) ); }
    break;

  case 182:
#line 465 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 183:
#line 466 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 184:
#line 467 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 185:
#line 468 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 186:
#line 469 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 187:
#line 470 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 188:
#line 471 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 189:
#line 472 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 190:
#line 473 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 191:
#line 474 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 192:
#line 475 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 193:
#line 476 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 194:
#line 477 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 195:
#line 478 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 196:
#line 479 "a.y"
    { (yyval.node) =(yyvsp[(1) - (1)].node) ;}
    break;

  case 197:
#line 484 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:
#line 485 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 199:
#line 486 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 200:
#line 487 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 201:
#line 488 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:
#line 489 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:
#line 490 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:
#line 491 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 205:
#line 492 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 206:
#line 493 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:
#line 498 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 208:
#line 499 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node) ); }
    break;

  case 209:
#line 503 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 210:
#line 504 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 211:
#line 509 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), (yyvsp[(3) - (4)].iValue), NULL); }
    break;

  case 212:
#line 510 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 213:
#line 511 "a.y"
    { (yyval.node) = arr((yyvsp[(1) - (4)].sValue), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 214:
#line 512 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].iValue), NULL) ; }
    break;

  case 215:
#line 513 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 216:
#line 514 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 217:
#line 515 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node),  (yyvsp[(3) - (4)].iValue), NULL ) ; }
    break;

  case 218:
#line 516 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, var((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 219:
#line 517 "a.y"
    {  (yyval.node) = arr2((yyvsp[(1) - (4)].node), -1, string((yyvsp[(3) - (4)].sValue))) ; }
    break;

  case 220:
#line 523 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) );  }
    break;

  case 221:
#line 528 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 222:
#line 529 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 223:
#line 530 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 224:
#line 531 "a.y"
    { (yyval.node) = opr(ADD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 225:
#line 532 "a.y"
    { (yyval.node) = opr(SUB_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 226:
#line 533 "a.y"
    { (yyval.node) = opr(MUL_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 227:
#line 534 "a.y"
    { (yyval.node) = opr(DIV_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;

  case 228:
#line 535 "a.y"
    { (yyval.node) = opr(MOD_EQ,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node));}
    break;


/* Line 1267 of yacc.c.  */
#line 3268 "y.tab.c"
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


#line 538 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}

