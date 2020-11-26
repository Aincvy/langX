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
     TINTEGER = 258,
     TBOOL = 259,
     TDOUBLE = 260,
     IDENTIFIER = 261,
     TSTRING = 262,
     OPERATOR_X__ = 263,
     OP_CALC = 264,
     FUNC_OP = 265,
     FUNC_CALL = 266,
     VAR_DECLAR = 267,
     ARRAY_ELE = 268,
     KEY_TRY = 269,
     KEY_PUBLIC = 270,
     KEY_SET = 271,
     KEY_IS = 272,
     KEY_REF = 273,
     KEY_CONTINUE = 274,
     KEY_NEW = 275,
     KEY_CATCH = 276,
     KEY_THIS = 277,
     KEY_EXTENDS = 278,
     KEY_RESTRICT = 279,
     KEY_IF = 280,
     KEY_ELSE = 281,
     KEY_WHILE = 282,
     KEY_FOR = 283,
     KEY_DELETE = 284,
     KEY_BREAK = 285,
     KEY_RETURN = 286,
     KEY_SWITCH = 287,
     KEY_CASE = 288,
     KEY_DEFAULT = 289,
     KEY_NULL = 290,
     CASE_LIST = 291,
     CLAXX_BODY = 292,
     CLAXX_MEMBER = 293,
     CLAXX_FUNC_CALL = 294,
     SCOPE_FUNC_CALL = 295,
     SCOPE = 296,
     LEFT_SHIFT = 297,
     RIGHT_SHIFT = 298,
     OPR_NODE_LIST = 299,
     OPR_CHANGE_NAME_SPACE = 300,
     OPR_GET_NAME_SPACE = 301,
     OPR_CLASS_DECLARE = 302,
     OPR_INC_DEC = 303,
     OPR_IF_ELSE = 304,
     OPR_MULTIPLE_ID = 305,
     OPR_START_IF = 306,
     KEY_REQUIRE = 307,
     KEY_REQUIRE_ONCE = 308,
     KEY_INCLUDE = 309,
     KEY_AUTO = 310,
     KEY_CONST = 311,
     KEY_LOCAL = 312,
     ADD_EQ = 313,
     SUB_EQ = 314,
     MUL_EQ = 315,
     DIV_EQ = 316,
     MOD_EQ = 317,
     LE_OP = 318,
     GE_OP = 319,
     EQ_OP = 320,
     NE_OP = 321,
     INC_OP = 322,
     DEC_OP = 323,
     AND_OP = 324,
     OR_OP = 325,
     IFX = 326,
     ELSE = 327,
     PIPELINE_OP = 328,
     INC_OP_BACK = 329,
     PRIORITY3 = 330,
     PRIORITY2 = 331,
     PRIORITY1 = 332,
     UMINUS = 333
   };
#endif
/* Tokens.  */
#define TINTEGER 258
#define TBOOL 259
#define TDOUBLE 260
#define IDENTIFIER 261
#define TSTRING 262
#define OPERATOR_X__ 263
#define OP_CALC 264
#define FUNC_OP 265
#define FUNC_CALL 266
#define VAR_DECLAR 267
#define ARRAY_ELE 268
#define KEY_TRY 269
#define KEY_PUBLIC 270
#define KEY_SET 271
#define KEY_IS 272
#define KEY_REF 273
#define KEY_CONTINUE 274
#define KEY_NEW 275
#define KEY_CATCH 276
#define KEY_THIS 277
#define KEY_EXTENDS 278
#define KEY_RESTRICT 279
#define KEY_IF 280
#define KEY_ELSE 281
#define KEY_WHILE 282
#define KEY_FOR 283
#define KEY_DELETE 284
#define KEY_BREAK 285
#define KEY_RETURN 286
#define KEY_SWITCH 287
#define KEY_CASE 288
#define KEY_DEFAULT 289
#define KEY_NULL 290
#define CASE_LIST 291
#define CLAXX_BODY 292
#define CLAXX_MEMBER 293
#define CLAXX_FUNC_CALL 294
#define SCOPE_FUNC_CALL 295
#define SCOPE 296
#define LEFT_SHIFT 297
#define RIGHT_SHIFT 298
#define OPR_NODE_LIST 299
#define OPR_CHANGE_NAME_SPACE 300
#define OPR_GET_NAME_SPACE 301
#define OPR_CLASS_DECLARE 302
#define OPR_INC_DEC 303
#define OPR_IF_ELSE 304
#define OPR_MULTIPLE_ID 305
#define OPR_START_IF 306
#define KEY_REQUIRE 307
#define KEY_REQUIRE_ONCE 308
#define KEY_INCLUDE 309
#define KEY_AUTO 310
#define KEY_CONST 311
#define KEY_LOCAL 312
#define ADD_EQ 313
#define SUB_EQ 314
#define MUL_EQ 315
#define DIV_EQ 316
#define MOD_EQ 317
#define LE_OP 318
#define GE_OP 319
#define EQ_OP 320
#define NE_OP 321
#define INC_OP 322
#define DEC_OP 323
#define AND_OP 324
#define OR_OP 325
#define IFX 326
#define ELSE 327
#define PIPELINE_OP 328
#define INC_OP_BACK 329
#define PRIORITY3 330
#define PRIORITY2 331
#define PRIORITY1 332
#define UMINUS 333




/* Copy the first part of user declarations.  */
#line 1 "a.y"


#include <string.h>
#include "../include/NodeCreator.h"
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
#line 9 "a.y"
{
 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
}
/* Line 193 of yacc.c.  */
#line 269 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 282 "y.tab.c"

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
#define YYLAST   826

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNRULES -- Number of states.  */
#define YYNSTATES  341

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   333

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,     2,     2,     2,    85,    80,     2,
      89,    90,    83,    81,    75,    82,    93,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   101,    98,
      68,    77,    66,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    91,     2,    92,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    99,    78,   100,    87,     2,     2,     2,
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
      65,    67,    69,    70,    71,    72,    73,    74,    76,    88,
      94,    95,    96,    97
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    32,    34,    36,    38,
      41,    45,    51,    56,    59,    61,    65,    70,    71,    73,
      74,    77,    80,    84,    86,    89,    92,    95,    97,    99,
     101,   105,   109,   113,   118,   120,   123,   125,   128,   132,
     136,   139,   143,   145,   147,   150,   152,   154,   156,   160,
     162,   167,   169,   171,   173,   181,   183,   186,   192,   195,
     197,   199,   202,   205,   208,   210,   213,   218,   222,   228,
     238,   239,   241,   242,   244,   248,   250,   251,   253,   257,
     259,   261,   264,   266,   268,   270,   272,   274,   276,   278,
     280,   282,   284,   287,   289,   291,   294,   296,   299,   304,
     308,   312,   316,   320,   324,   328,   332,   336,   340,   344,
     347,   351,   354,   358,   360,   364,   367,   369,   371,   373,
     375,   379,   381,   383,   385,   387,   391,   394,   396,   398,
     402,   406,   408,   410,   412,   414,   416,   418,   420,   422,
     425,   428,   430,   432,   434,   436,   438,   443,   445,   447,
     451,   453,   455,   459,   461,   463,   465,   467,   469,   472,
     476,   478,   481,   483,   485,   487,   489,   493,   497,   499,
     501,   503,   505,   507,   511,   513,   515,   519,   521,   523,
     525,   527,   529,   531,   533,   536,   538,   540,   542,   544,
     546,   548,   550,   552,   554,   556,   558,   560,   562,   564,
     566,   568,   570,   572,   574,   576,   578,   580,   582,   584,
     586,   588,   590,   592,   594,   596,   598
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     103,     0,    -1,   104,    -1,   104,   105,    -1,    -1,   106,
      -1,   107,    -1,   133,    -1,   149,    -1,   110,    -1,    98,
      -1,   124,    -1,   115,    -1,   112,    -1,   113,    -1,   109,
     193,    -1,    52,    -1,    53,    -1,    54,    -1,    14,   178,
      -1,    14,   178,   111,    -1,    21,    89,   184,    90,   178,
      -1,    16,    15,    77,   114,    -1,    18,   114,    -1,   184,
      -1,   114,    93,   184,    -1,   116,   184,   117,   118,    -1,
      -1,    55,    -1,    -1,    23,   185,    -1,    99,   100,    -1,
      99,   119,   100,    -1,   120,    -1,   119,   120,    -1,   129,
      98,    -1,   174,    98,    -1,   124,    -1,   106,    -1,    22,
      -1,   201,    93,   184,    -1,   184,    41,   184,    -1,   125,
      10,   178,    -1,   125,    10,   126,   178,    -1,   184,    -1,
      87,   184,    -1,     8,    -1,    89,    90,    -1,    89,   185,
      90,    -1,   128,    10,   178,    -1,    89,    90,    -1,    89,
     185,    90,    -1,   185,    -1,   131,    -1,   130,   131,    -1,
      56,    -1,    57,    -1,   132,    -1,   131,    75,   132,    -1,
     184,    -1,   184,    91,   200,    92,    -1,   134,    -1,   143,
      -1,   135,    -1,    32,    89,   200,    90,    99,   141,   100,
      -1,   136,    -1,   136,   137,    -1,    25,    89,   159,    90,
     178,    -1,   138,   140,    -1,   140,    -1,   139,    -1,   138,
     139,    -1,    26,   136,    -1,    26,   178,    -1,   142,    -1,
     141,   142,    -1,    33,   189,   101,   178,    -1,    34,   101,
     178,    -1,    27,    89,   159,    90,   178,    -1,    28,    89,
     145,    98,   144,    98,   147,    90,   178,    -1,    -1,   159,
      -1,    -1,   146,    -1,   145,    75,   146,    -1,   173,    -1,
      -1,   148,    -1,   147,    75,   148,    -1,   173,    -1,   169,
      -1,   150,    98,    -1,   169,    -1,   173,    -1,   153,    -1,
     158,    -1,   152,    -1,   155,    -1,   151,    -1,   108,    -1,
     129,    -1,    24,    -1,    24,   186,    -1,    30,    -1,    31,
      -1,    31,   202,    -1,    19,    -1,   197,   156,    -1,   153,
      93,   184,   156,    -1,   200,    81,   200,    -1,   200,    82,
     200,    -1,   200,    83,   200,    -1,   200,    84,   200,    -1,
     200,    85,   200,    -1,   200,    80,   200,    -1,   200,    78,
     200,    -1,   200,    79,   200,    -1,   200,    42,   200,    -1,
     200,    43,   200,    -1,    87,   200,    -1,    20,   184,   156,
      -1,    89,    90,    -1,    89,   157,    90,    -1,   202,    -1,
     157,    75,   202,    -1,    29,   185,    -1,   161,    -1,   163,
      -1,   162,    -1,   164,    -1,   159,   160,   159,    -1,    71,
      -1,    72,    -1,   171,    -1,   186,    -1,   201,    17,   184,
      -1,    86,   161,    -1,   165,    -1,   166,    -1,   200,   167,
     200,    -1,   201,   168,   195,    -1,    66,    -1,    68,    -1,
      64,    -1,    63,    -1,    67,    -1,    65,    -1,    67,    -1,
      65,    -1,   170,   197,    -1,   197,   170,    -1,    69,    -1,
      70,    -1,   187,    -1,   197,    -1,   198,    -1,   201,    91,
     200,    92,    -1,   174,    -1,   176,    -1,   199,    77,   175,
      -1,   202,    -1,   174,    -1,   199,   177,   200,    -1,    58,
      -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,    99,
     100,    -1,    99,   179,   100,    -1,   180,    -1,   179,   180,
      -1,   110,    -1,   149,    -1,   133,    -1,   106,    -1,   193,
      81,   182,    -1,   182,    81,   193,    -1,   201,    -1,   195,
      -1,   181,    -1,   169,    -1,   183,    -1,    89,   200,    90,
      -1,     6,    -1,   184,    -1,   185,    75,   184,    -1,     4,
      -1,   188,    -1,   191,    -1,   190,    -1,   189,    -1,     3,
      -1,     5,    -1,    82,   192,    -1,   188,    -1,   196,    -1,
     153,    -1,   183,    -1,     7,    -1,    35,    -1,   187,    -1,
     193,    -1,   194,    -1,   127,    -1,   186,    -1,   184,    -1,
     172,    -1,   122,    -1,   123,    -1,   196,    -1,   121,    -1,
     155,    -1,   169,    -1,   153,    -1,   154,    -1,   183,    -1,
     196,    -1,   187,    -1,   197,    -1,   198,    -1,   197,    -1,
     153,    -1,   195,    -1,   197,    -1,   198,    -1,   181,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    85,    86,    89,    90,    91,    92,    93,
      97,   101,   102,   103,   104,   109,   113,   114,   115,   120,
     121,   125,   131,   136,   140,   141,   151,   155,   156,   161,
     162,   166,   167,   171,   172,   176,   177,   178,   179,   184,
     190,   195,   205,   206,   210,   211,   212,   216,   217,   222,
     226,   227,   228,   233,   234,   238,   239,   243,   244,   248,
     249,   254,   255,   260,   261,   265,   266,   270,   274,   275,
     279,   280,   284,   288,   292,   293,   297,   298,   302,   303,
     307,   308,   312,   313,   314,   319,   325,   326,   327,   332,
     333,   338,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   355,   356,   360,   361,   362,   363,   368,   369,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     389,   393,   394,   398,   399,   403,   409,   410,   411,   412,
     413,   417,   418,   423,   424,   429,   433,   438,   439,   443,
     447,   451,   452,   453,   454,   455,   456,   460,   461,   466,
     467,   471,   472,   478,   479,   480,   488,   493,   494,   498,
     502,   503,   507,   511,   512,   513,   514,   515,   520,   521,
     525,   526,   530,   531,   532,   533,   538,   539,   543,   544,
     545,   546,   547,   551,   557,   561,   562,   566,   570,   571,
     575,   576,   580,   584,   588,   592,   593,   594,   595,   599,
     603,   610,   611,   612,   613,   614,   618,   619,   620,   621,
     625,   626,   627,   631,   632,   633,   634,   638,   642,   643,
     644,   648,   649,   658,   659,   660,   661
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TINTEGER", "TBOOL", "TDOUBLE",
  "IDENTIFIER", "TSTRING", "OPERATOR_X__", "OP_CALC", "FUNC_OP",
  "FUNC_CALL", "VAR_DECLAR", "ARRAY_ELE", "KEY_TRY", "KEY_PUBLIC",
  "KEY_SET", "KEY_IS", "KEY_REF", "KEY_CONTINUE", "KEY_NEW", "KEY_CATCH",
  "KEY_THIS", "KEY_EXTENDS", "KEY_RESTRICT", "KEY_IF", "KEY_ELSE",
  "KEY_WHILE", "KEY_FOR", "KEY_DELETE", "KEY_BREAK", "KEY_RETURN",
  "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT", "KEY_NULL", "CASE_LIST",
  "CLAXX_BODY", "CLAXX_MEMBER", "CLAXX_FUNC_CALL", "SCOPE_FUNC_CALL",
  "SCOPE", "LEFT_SHIFT", "RIGHT_SHIFT", "OPR_NODE_LIST",
  "OPR_CHANGE_NAME_SPACE", "OPR_GET_NAME_SPACE", "OPR_CLASS_DECLARE",
  "OPR_INC_DEC", "OPR_IF_ELSE", "OPR_MULTIPLE_ID", "OPR_START_IF",
  "KEY_REQUIRE", "KEY_REQUIRE_ONCE", "KEY_INCLUDE", "KEY_AUTO",
  "KEY_CONST", "KEY_LOCAL", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ",
  "MOD_EQ", "LE_OP", "GE_OP", "EQ_OP", "'>'", "NE_OP", "'<'", "INC_OP",
  "DEC_OP", "AND_OP", "OR_OP", "IFX", "ELSE", "','", "PIPELINE_OP", "'='",
  "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "INC_OP_BACK", "'('", "')'", "'['", "']'", "'.'", "PRIORITY3",
  "PRIORITY2", "PRIORITY1", "UMINUS", "';'", "'{'", "'}'", "':'",
  "$accept", "program", "statement_list", "statement", "_extra_nothing",
  "out_declare_stmt", "require_stmt", "require_operators", "try_stmt",
  "catch_block_stmt", "namespace_declare_stmt", "namespace_ref_stmt",
  "namespace_name_stmt", "class_declare_stmt", "class_name_prefix",
  "class_name_suffix", "class_body", "class_body_items", "class_body_item",
  "this_stmt", "class_member_stmt", "static_member_stmt",
  "func_declare_stmt", "func_name_types", "func_param_list", "lambda_stmt",
  "lambda_args_stmt", "var_declare_stmt", "var_prefix",
  "_elements_var_declare_stmt", "element_var_declare_stmt", "con_ctl_stmt",
  "selection_stmt", "if_stmt", "single_if_stmt", "else_stmt",
  "else_if_stmts", "else_if_stmt", "single_else_stmt", "case_stmt_list",
  "case_stmt", "loop_stmt", "for_logic_stmt", "for_1_stmt_list",
  "for_1_stmt", "for_3_stmt_list", "for_3_stmt", "simple_stmt",
  "simple_stmt_types", "restrict_stmt", "interrupt_stmt", "call_statement",
  "arithmetic_stmt", "new_expr", "args_list_with_parentheses", "args_list",
  "delete_expr", "logic_stmt", "_symbol_logic_connection",
  "bool_param_expr", "type_judge_stmt", "not_bool_param_expr",
  "compare_expr", "number_compare_expr", "object_compare_expr",
  "_symbol_compare", "_symbol_equals_not", "self_inc_dec_stmt",
  "self_inc_dec_operators", "assign_stmt_value_eq", "array_ele_stmt",
  "assign_stmt", "single_assign_stmt", "single_assign_stmt_value",
  "number_change_assign_stmt", "symbol_change_assign", "code_block",
  "block_item_list", "block_item", "string_plus_stmt",
  "string_plus_stmt_value", "number_parentheses_stmt", "id_expr",
  "multiple_id_expr", "bool_expr", "number_expr", "positive_number_expr",
  "int_expr", "double_expr", "uminus_expr", "uminus_expr_values",
  "string_expr", "null_expr", "common_types_expr",
  "common_others_values_expr", "common_values_expr",
  "common_result_of_call_expr", "common_assignable_expr",
  "common_number_expr", "common_object_expr", "common_expr", 0
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
     315,   316,   317,   318,   319,   320,    62,   321,    60,   322,
     323,   324,   325,   326,   327,    44,   328,    61,   124,    94,
      38,    43,    45,    42,    47,    37,    33,   126,   329,    40,
      41,    91,    93,    46,   330,   331,   332,   333,    59,   123,
     125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   104,   104,   105,   105,   105,   105,   105,
     106,   107,   107,   107,   107,   108,   109,   109,   109,   110,
     110,   111,   112,   113,   114,   114,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   121,
     122,   123,   124,   124,   125,   125,   125,   126,   126,   127,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   137,   137,
     138,   138,   139,   140,   141,   141,   142,   142,   143,   143,
     144,   144,   145,   145,   145,   146,   147,   147,   147,   148,
     148,   149,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   152,   152,   153,   153,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     155,   156,   156,   157,   157,   158,   159,   159,   159,   159,
     159,   160,   160,   161,   161,   162,   163,   164,   164,   165,
     166,   167,   167,   167,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   171,   171,   171,   172,   173,   173,   174,
     175,   175,   176,   177,   177,   177,   177,   177,   178,   178,
     179,   179,   180,   180,   180,   180,   181,   181,   182,   182,
     182,   182,   182,   183,   184,   185,   185,   186,   187,   187,
     188,   188,   189,   190,   191,   192,   192,   192,   192,   193,
     194,   195,   195,   195,   195,   195,   196,   196,   196,   196,
     197,   197,   197,   198,   198,   198,   198,   199,   200,   200,
     200,   201,   201,   202,   202,   202,   202
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     5,     4,     2,     1,     3,     4,     0,     1,     0,
       2,     2,     3,     1,     2,     2,     2,     1,     1,     1,
       3,     3,     3,     4,     1,     2,     1,     2,     3,     3,
       2,     3,     1,     1,     2,     1,     1,     1,     3,     1,
       4,     1,     1,     1,     7,     1,     2,     5,     2,     1,
       1,     2,     2,     2,     1,     2,     4,     3,     5,     9,
       0,     1,     0,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     2,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     1,     3,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     4,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     3,
       1,     2,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   184,    46,     0,     0,     0,   106,
       0,    39,   101,     0,     0,     0,     0,   103,   104,     0,
      16,    17,    18,    28,    55,    56,   151,   152,     0,    10,
       3,     5,     6,    99,     0,     9,    13,    14,    12,     0,
     211,   208,   209,    11,     0,   100,     0,    53,    57,     7,
      61,    63,    65,    62,     8,     0,    98,    96,    94,   212,
      95,    92,     0,   207,    93,   157,   158,   206,   210,   221,
       0,     0,     0,    19,     0,    23,    24,     0,   187,   102,
       0,     0,    82,   185,   125,   192,   193,   199,   200,     0,
       0,     0,   204,     0,   214,   215,   212,   213,   226,     0,
     216,   206,    52,   205,   218,   188,   191,   190,   189,   202,
     203,   223,   210,   219,   220,     0,   178,   105,     0,    45,
      15,    29,     0,    54,    59,     0,     0,    66,     0,    70,
      69,    91,     0,   222,   206,   149,     0,     0,     0,   107,
     150,   163,   164,   165,   166,   167,     0,     0,     0,     0,
     168,   175,   172,   174,   173,     0,   170,   206,     0,    20,
       0,     0,   120,     0,     0,     0,   126,   128,   127,   129,
     137,   138,   213,   133,   216,   134,   218,   219,   220,     0,
       0,     0,     0,    83,    85,   221,     0,   197,   198,   195,
     194,   196,   218,   219,   220,   119,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    58,    72,
      73,    71,    68,     0,    41,     0,   121,     0,   123,   161,
     159,     0,   160,   162,     0,    40,   169,   171,     0,    22,
      25,   136,   131,   132,     0,     0,   144,   143,   146,   141,
     145,   142,     0,     0,   148,   147,     0,     0,     0,    80,
     186,    51,   183,    49,   177,   181,   180,   176,   182,   201,
     179,   117,   118,   115,   116,   114,   109,   110,   111,   112,
     113,     0,    30,     0,    26,    47,     0,    43,   108,    60,
       0,   122,   156,     0,    67,   130,   139,   135,     0,   202,
     140,    78,    84,     0,    81,     0,    31,    38,     0,    33,
      37,     0,     0,    48,   124,     0,    86,     0,     0,     0,
      74,    32,    34,    35,    36,    21,     0,    87,    90,    89,
       0,     0,    64,    75,     0,     0,     0,    77,    88,    79,
      76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    30,   151,    32,    33,    34,   152,   159,
      36,    37,    75,    38,    39,   214,   284,   308,   309,    40,
      41,    42,   310,    44,   216,    92,    93,    45,    46,    47,
      48,   153,    50,    51,    52,   127,   128,   129,   130,   319,
     320,    53,   303,   182,   183,   326,   327,   154,    55,    56,
      57,    94,    95,    96,   139,   227,    60,   165,   245,   166,
     167,   168,   169,   170,   171,   252,   256,   172,    62,   173,
      63,    64,    65,   230,    66,   147,    73,   155,   156,    98,
      99,   174,   134,   102,   103,   192,   105,   106,   107,   108,
     190,   109,   110,   111,   112,   193,   194,    70,   115,    71,
     117
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -256
static const yytype_int16 yypact[] =
{
    -256,     8,   524,  -256,  -256,  -256,   -73,    22,    55,  -256,
      55,  -256,    52,   -25,    13,    18,    55,  -256,   601,    40,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,    55,  -256,
    -256,  -256,  -256,  -256,   104,  -256,  -256,  -256,  -256,    55,
    -256,  -256,  -256,  -256,   147,  -256,    55,    85,  -256,  -256,
    -256,  -256,   148,  -256,  -256,    83,  -256,  -256,   -17,   100,
    -256,  -256,   108,  -256,  -256,  -256,  -256,    17,   280,   -30,
     368,    77,   354,   194,   145,   133,  -256,   127,  -256,  -256,
     612,   612,   108,  -256,   153,  -256,  -256,  -256,  -256,    28,
     640,   569,  -256,   225,    30,  -256,  -256,   166,   185,   188,
     196,    58,   153,  -256,   215,  -256,  -256,  -256,  -256,   199,
    -256,   206,  -256,   728,   163,   711,    77,  -256,   640,  -256,
    -256,   244,   -69,    85,   202,    55,     7,  -256,   148,  -256,
    -256,  -256,    55,   204,   257,   120,    55,   640,   579,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,   601,   640,   640,    55,
    -256,  -256,  -256,  -256,  -256,   419,  -256,   139,   210,  -256,
      55,    55,  -256,   673,   640,   -48,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,    41,   134,   146,   703,
      29,    26,   -46,  -256,  -256,   127,    55,   -17,  -256,  -256,
    -256,   181,  -256,   182,  -256,  -256,  -256,   -21,   483,   -73,
     104,   622,   640,   640,   640,   640,   640,   640,   640,   640,
     640,   640,   654,    55,   205,    15,   -73,  -256,  -256,  -256,
    -256,  -256,  -256,   127,  -256,   309,  -256,    50,  -256,  -256,
    -256,   230,  -256,   711,   416,  -256,  -256,  -256,    55,   133,
    -256,  -256,  -256,  -256,   -73,   612,  -256,  -256,  -256,  -256,
    -256,  -256,   640,    55,  -256,  -256,   315,   -73,   108,   612,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,   402,   402,   282,   632,   439,   156,   156,  -256,  -256,
    -256,   213,   153,   447,  -256,  -256,    94,  -256,  -256,  -256,
     601,  -256,  -256,   233,  -256,   123,   711,  -256,    19,  -256,
    -256,  -256,  -256,   228,   123,   186,  -256,  -256,   471,  -256,
    -256,   229,   238,  -256,  -256,   -73,   121,   325,   242,    10,
    -256,  -256,  -256,  -256,  -256,  -256,   107,  -256,  -256,  -256,
     243,   -73,  -256,  -256,   121,   -73,   -73,  -256,  -256,  -256,
    -256
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,  -256,  -256,     3,  -256,  -256,  -256,   329,  -256,
    -256,  -256,   187,  -256,  -256,  -256,  -256,  -256,    38,  -256,
    -256,  -256,   347,  -256,  -256,  -256,  -256,  -255,  -256,   307,
     231,   352,  -256,  -256,   245,  -256,  -256,   241,   249,  -256,
      51,  -256,  -256,  -256,   114,  -256,    46,   393,  -256,  -256,
    -256,     0,  -256,     9,   -58,  -256,  -256,   -67,  -256,   235,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,    -1,   -18,  -256,
    -256,   -70,  -137,  -256,  -256,  -256,   -81,  -256,   247,   195,
     198,   -12,    47,    -3,    23,   -14,   311,    86,  -256,  -256,
    -256,   -27,  -256,  -165,     1,    -2,     4,  -131,   211,    20,
    -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -226
static const yytype_int16 yytable[] =
{
      69,    61,    58,    68,   104,    31,   100,   120,     3,   229,
     228,    59,   184,    84,   181,   231,   113,    97,   232,   162,
     215,     4,   114,   242,   243,     4,    72,   -44,   311,   258,
      72,    85,    13,    86,     4,    79,   270,    74,   116,    26,
      27,   217,   244,   317,   318,   220,   253,  -222,    10,    67,
      11,   140,   259,   311,   186,    76,    78,    77,   136,   138,
     135,     4,   133,    83,    80,   101,   176,   176,  -185,   261,
      69,    61,    58,    68,  -222,   119,   132,   188,   177,   177,
     185,    59,   133,    68,   178,   178,   121,   185,   197,   187,
     191,   300,   -59,   124,   254,   140,   255,   242,   243,   136,
     180,   180,    81,   175,   175,   285,    72,    82,   137,   196,
     332,    87,  -153,  -153,     4,   -59,   257,   164,   263,   157,
     148,  -222,   149,   132,   104,   290,   100,     4,    10,   118,
      11,  -153,   104,  -185,   100,   287,   113,    97,   101,  -153,
     291,    10,   114,    11,   113,    97,   312,    68,  -185,   176,
     114,  -221,   231,    69,    61,    58,    68,   122,   116,   140,
     125,   177,   314,   294,    59,   288,   116,   178,   148,   186,
     149,   312,   124,   264,   126,   140,   301,   231,   295,   223,
     136,   131,   334,   224,   313,   101,   175,   269,   184,   268,
      26,    27,   304,   101,   242,   243,   235,   335,   -97,    69,
     265,   133,   157,    26,    27,  -154,  -154,    76,   240,   138,
     282,  -221,   286,  -221,   -59,   158,   138,  -155,  -155,   317,
     318,   116,   160,   138,  -154,  -221,   161,  -221,   186,   299,
     137,   176,  -154,   260,   325,   199,  -155,   -59,  -225,   209,
     210,   211,   269,   177,  -155,   176,   329,  -181,   101,   178,
     337,    26,    27,  -225,   339,   340,   185,   177,   133,    68,
      83,  -225,    83,   178,   329,   180,  -180,   213,   175,   200,
    -210,   138,  -210,  -221,  -210,  -221,   104,  -182,   100,   180,
     201,   185,   175,   133,    68,   293,   307,  -179,   113,    97,
    -201,   179,   179,   137,   114,   197,  -201,   132,   136,   238,
     297,   195,   198,    83,   283,  -201,   185,   146,   133,    68,
     116,   307,   305,  -201,    69,   328,   133,    68,    85,    78,
      86,     4,    87,   315,   202,   203,   316,   323,    85,   212,
      67,    35,    69,   328,   133,    68,   324,   101,  -217,  -217,
    -217,  -217,  -217,   331,   336,    83,   322,   239,   225,    43,
      88,   202,   203,   123,    49,    67,   218,  -217,   233,   234,
       4,   205,   206,   207,   208,   209,   210,   211,     6,   221,
     333,   219,   302,     9,    10,   198,    11,   222,    12,    13,
     338,    14,    15,    16,    17,    18,    19,   204,   205,   206,
     207,   208,   209,   210,   211,    54,   266,    89,   241,   267,
     189,   289,   237,   330,   298,     0,    20,    21,    22,     0,
      24,    25,     0,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,    26,    27,     4,   141,   142,   143,   144,
     145,     0,     0,     6,     0,     0,     0,     0,     9,    10,
       0,    11,     0,    12,    13,   146,    14,    15,    16,    17,
      18,    19,    29,     4,   150,     5,   179,     0,   202,   203,
       0,     0,     0,   296,     0,     0,     0,    10,     0,    11,
     179,    20,    21,    22,     0,    24,    25,     4,     0,     5,
       0,   202,   203,   207,   208,   209,   210,   211,    26,    27,
       0,    10,     0,    11,   204,   205,   206,   207,   208,   209,
     210,   211,     0,    24,    25,     0,     0,     0,   292,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,   236,
     207,   208,   209,   210,   211,   202,   203,    24,    25,     0,
       4,     0,     5,     0,    28,     0,     0,     0,     6,     0,
       7,     0,     8,     9,    10,    29,    11,   306,    12,    13,
       0,    14,    15,    16,    17,    18,    19,     0,    28,     0,
       0,   204,   205,   206,   207,   208,   209,   210,   211,    29,
       0,   321,    85,   262,    86,     4,    20,    21,    22,    23,
      24,    25,    85,    78,    86,     4,    87,     0,     0,    10,
       0,    11,     0,    26,    27,     0,     0,     0,     0,    10,
       0,    11,     0,     0,    85,    78,    86,     4,    87,     0,
       0,    28,     0,     0,    88,    85,    78,    86,     4,     0,
       0,    10,    29,    11,     0,    85,    78,    86,     4,    87,
       0,     0,    10,     0,    11,     0,    88,     0,    26,    27,
       0,     0,    10,    85,    11,    86,     4,     0,    26,    27,
       0,    89,     0,     0,     0,     0,    90,    88,   164,   196,
      10,    89,    11,     0,     0,     0,    90,     0,    91,   226,
      26,    27,     0,     0,   202,   203,    85,    78,    86,     4,
       0,    26,    27,    89,     0,     0,     0,     0,    90,     0,
      91,    26,    27,    10,    89,    11,   202,   203,   163,    90,
       0,   164,     0,     0,    89,     0,     0,     0,     0,    26,
      27,    91,   206,   207,   208,   209,   210,   211,     0,     0,
       0,     0,    89,     0,     0,     0,     0,    90,     0,   164,
       0,     0,   204,   205,   206,   207,   208,   209,   210,   211,
       0,     0,    26,    27,   281,   202,   203,     0,     0,     0,
       0,     0,     0,   202,   203,    89,     0,     0,     0,     0,
      90,     0,   164,     0,     0,     0,   246,   247,   248,   249,
     250,   251,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   205,   206,   207,   208,   209,   210,   211,   204,
     205,   206,   207,   208,   209,   210,   211,    26,    27,     0,
       0,     0,     0,  -224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,  -224,  -221,
       0,  -221,     0,     0,     0,     0,  -224
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,    18,     2,    18,    34,     0,   146,
     138,     2,    82,    16,    81,   146,    18,    18,   146,    77,
      89,     6,    18,    71,    72,     6,    99,    10,   283,    75,
      99,     3,    25,     5,     6,    12,   201,    15,    18,    69,
      70,   122,    90,    33,    34,   126,    17,    17,    20,     2,
      22,    69,    98,   308,    75,     8,     4,    10,    41,    89,
      62,     6,    62,    16,    89,    18,    80,    81,    10,    90,
      72,    72,    72,    72,    91,    28,    93,    89,    80,    81,
      82,    72,    82,    82,    80,    81,    39,    89,    91,    89,
      89,   256,    75,    46,    65,   113,    67,    71,    72,    41,
      80,    81,    89,    80,    81,    90,    99,    89,    91,    90,
     100,     7,    71,    72,     6,    98,    90,    89,   199,    72,
      91,    91,    93,    93,   138,    75,   138,     6,    20,    89,
      22,    90,   146,    75,   146,   216,   138,   138,    91,    98,
      90,    20,   138,    22,   146,   146,   283,   146,    90,   163,
     146,    17,   283,   155,   155,   155,   155,    10,   138,   177,
      75,   163,   290,   244,   155,   223,   146,   163,    91,    75,
      93,   308,   125,   200,    26,   193,   257,   308,   245,   132,
      41,    98,    75,   136,    90,   138,   163,   201,   258,   201,
      69,    70,   259,   146,    71,    72,   149,    90,    98,   201,
     201,   201,   155,    69,    70,    71,    72,   160,   161,    89,
     213,    91,   215,    93,    75,    21,    89,    71,    72,    33,
      34,   201,    77,    89,    90,    91,    93,    93,    75,   256,
      91,   245,    98,   186,   315,    10,    90,    98,    75,    83,
      84,    85,   256,   245,    98,   259,   316,    81,   201,   245,
     331,    69,    70,    90,   335,   336,   258,   259,   258,   258,
     213,    98,   215,   259,   334,   245,    81,    23,   245,    81,
      89,    89,    91,    91,    93,    93,   290,    81,   290,   259,
      81,   283,   259,   283,   283,   238,   283,    81,   290,   290,
      75,    80,    81,    91,   290,   298,    81,    93,    41,    89,
     253,    90,    91,   256,    99,    90,   308,    77,   308,   308,
     290,   308,    99,    98,   316,   316,   316,   316,     3,     4,
       5,     6,     7,    90,    42,    43,    98,    98,     3,   118,
     283,     2,   334,   334,   334,   334,    98,   290,    58,    59,
      60,    61,    62,   101,   101,   298,   308,   160,   137,     2,
      35,    42,    43,    46,     2,   308,   125,    77,   147,   148,
       6,    79,    80,    81,    82,    83,    84,    85,    14,   128,
     319,   126,   258,    19,    20,   164,    22,   128,    24,    25,
     334,    27,    28,    29,    30,    31,    32,    78,    79,    80,
      81,    82,    83,    84,    85,     2,   201,    82,   163,   201,
      89,    92,   155,   317,    89,    -1,    52,    53,    54,    -1,
      56,    57,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    69,    70,     6,    58,    59,    60,    61,
      62,    -1,    -1,    14,    -1,    -1,    -1,    -1,    19,    20,
      -1,    22,    -1,    24,    25,    77,    27,    28,    29,    30,
      31,    32,    98,     6,   100,     8,   245,    -1,    42,    43,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    20,    -1,    22,
     259,    52,    53,    54,    -1,    56,    57,     6,    -1,     8,
      -1,    42,    43,    81,    82,    83,    84,    85,    69,    70,
      -1,    20,    -1,    22,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    56,    57,    -1,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,   100,
      81,    82,    83,    84,    85,    42,    43,    56,    57,    -1,
       6,    -1,     8,    -1,    87,    -1,    -1,    -1,    14,    -1,
      16,    -1,    18,    19,    20,    98,    22,   100,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    -1,    87,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    98,
      -1,   100,     3,    90,     5,     6,    52,    53,    54,    55,
      56,    57,     3,     4,     5,     6,     7,    -1,    -1,    20,
      -1,    22,    -1,    69,    70,    -1,    -1,    -1,    -1,    20,
      -1,    22,    -1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    87,    -1,    -1,    35,     3,     4,     5,     6,    -1,
      -1,    20,    98,    22,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    20,    -1,    22,    -1,    35,    -1,    69,    70,
      -1,    -1,    20,     3,    22,     5,     6,    -1,    69,    70,
      -1,    82,    -1,    -1,    -1,    -1,    87,    35,    89,    90,
      20,    82,    22,    -1,    -1,    -1,    87,    -1,    89,    90,
      69,    70,    -1,    -1,    42,    43,     3,     4,     5,     6,
      -1,    69,    70,    82,    -1,    -1,    -1,    -1,    87,    -1,
      89,    69,    70,    20,    82,    22,    42,    43,    86,    87,
      -1,    89,    -1,    -1,    82,    -1,    -1,    -1,    -1,    69,
      70,    89,    80,    81,    82,    83,    84,    85,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    87,    -1,    89,
      -1,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    69,    70,    90,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    82,    -1,    -1,    -1,    -1,
      87,    -1,    89,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,    85,    78,
      79,    80,    81,    82,    83,    84,    85,    69,    70,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      -1,    93,    -1,    -1,    -1,    -1,    98
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   103,   104,     0,     6,     8,    14,    16,    18,    19,
      20,    22,    24,    25,    27,    28,    29,    30,    31,    32,
      52,    53,    54,    55,    56,    57,    69,    70,    87,    98,
     105,   106,   107,   108,   109,   110,   112,   113,   115,   116,
     121,   122,   123,   124,   125,   129,   130,   131,   132,   133,
     134,   135,   136,   143,   149,   150,   151,   152,   153,   155,
     158,   169,   170,   172,   173,   174,   176,   184,   196,   197,
     199,   201,    99,   178,    15,   114,   184,   184,     4,   186,
      89,    89,    89,   184,   185,     3,     5,     7,    35,    82,
      87,    89,   127,   128,   153,   154,   155,   169,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   193,
     194,   195,   196,   197,   198,   200,   201,   202,    89,   184,
     193,   184,    10,   131,   184,    75,    26,   137,   138,   139,
     140,    98,    93,   153,   184,   197,    41,    91,    89,   156,
     170,    58,    59,    60,    61,    62,    77,   177,    91,    93,
     100,   106,   110,   133,   149,   179,   180,   184,    21,   111,
      77,    93,   156,    86,    89,   159,   161,   162,   163,   164,
     165,   166,   169,   171,   183,   186,   187,   197,   198,   200,
     201,   159,   145,   146,   173,   197,    75,   153,   183,   188,
     192,   196,   187,   197,   198,   200,    90,   185,   200,    10,
      81,    81,    42,    43,    78,    79,    80,    81,    82,    83,
      84,    85,   200,    23,   117,    89,   126,   178,   132,   136,
     178,   139,   140,   184,   184,   200,    90,   157,   202,   174,
     175,   199,   202,   200,   200,   184,   100,   180,    89,   114,
     184,   161,    71,    72,    90,   160,    63,    64,    65,    66,
      67,    68,   167,    17,    65,    67,   168,    90,    75,    98,
     184,    90,    90,   178,   193,   169,   181,   182,   183,   187,
     195,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,    90,   185,    99,   118,    90,   185,   178,   156,    92,
      75,    90,    92,   184,   178,   159,   200,   184,    89,   193,
     195,   178,   146,   144,   159,    99,   100,   106,   119,   120,
     124,   129,   174,    90,   202,    90,    98,    33,    34,   141,
     142,   100,   120,    98,    98,   178,   147,   148,   169,   173,
     189,   101,   100,   142,    75,    90,   101,   178,   148,   178,
     178
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
#line 85 "a.y"
    {   /* execAndFreeNode($2); */ }
    break;

  case 5:
#line 89 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 90 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 91 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 8:
#line 92 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 9:
#line 93 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 10:
#line 97 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 11:
#line 101 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 12:
#line 102 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 13:
#line 103 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 14:
#line 104 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
#line 109 "a.y"
    { (yyval.node) = opr((yyvsp[(1) - (2)].iValue) , 1 , (yyvsp[(2) - (2)].node)); }
    break;

  case 16:
#line 113 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 17:
#line 114 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 18:
#line 115 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 19:
#line 120 "a.y"
    { (yyval.node) = opr(KEY_TRY, 2,(yyvsp[(2) - (2)].node),NULL); }
    break;

  case 20:
#line 121 "a.y"
    { (yyval.node) = opr(KEY_TRY, 2,(yyvsp[(2) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 21:
#line 125 "a.y"
    { (yyval.node) = opr(KEY_CATCH, 2, (yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)); }
    break;

  case 22:
#line 131 "a.y"
    { (yyval.node) = opr(OPR_CHANGE_NAME_SPACE, 1, (yyvsp[(4) - (4)].node)); }
    break;

  case 23:
#line 136 "a.y"
    { (yyval.node) = opr(KEY_REF, 1, (yyvsp[(2) - (2)].node)); }
    break;

  case 24:
#line 140 "a.y"
    { (yyval.node) = opr(OPR_GET_NAME_SPACE, 2, NULL, (yyvsp[(1) - (1)].node)); }
    break;

  case 25:
#line 141 "a.y"
    { (yyval.node) = opr(OPR_GET_NAME_SPACE, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 26:
#line 151 "a.y"
    {  (yyval.node) = opr(OPR_CLASS_DECLARE, 4, intNode((yyvsp[(1) - (4)].iValue)), (yyvsp[(2) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 27:
#line 155 "a.y"
    { (yyval.iValue) = -1; }
    break;

  case 28:
#line 156 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 29:
#line 161 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 30:
#line 162 "a.y"
    { (yyval.node) = opr(KEY_EXTENDS, 1, (yyvsp[(2) - (2)].node)); }
    break;

  case 31:
#line 166 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 32:
#line 167 "a.y"
    { (yyval.node) = opr(CLAXX_BODY, 1, (yyvsp[(2) - (3)].node)); }
    break;

  case 33:
#line 171 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 34:
#line 172 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[(1) - (2)].node) ,(yyvsp[(2) - (2)].node)); }
    break;

  case 35:
#line 176 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 36:
#line 177 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 37:
#line 178 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 38:
#line 179 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 39:
#line 184 "a.y"
    { (yyval.node) = opr(KEY_THIS , 0 ); }
    break;

  case 40:
#line 190 "a.y"
    { (yyval.node) = opr(CLAXX_MEMBER, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 41:
#line 195 "a.y"
    { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)) ; }
    break;

  case 42:
#line 205 "a.y"
    { (yyval.node) = opr(FUNC_OP,3, (yyvsp[(1) - (3)].node), NULL, (yyvsp[(3) - (3)].node)); }
    break;

  case 43:
#line 206 "a.y"
    { (yyval.node) = opr(FUNC_OP, 3, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 44:
#line 210 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 45:
#line 211 "a.y"
    { char buf[1024] = "~"; strcat(buf, (yyvsp[(2) - (2)].node)->var_obj->name);  (yyval.node) = varWithNameNeedFree(strdup(buf)); }
    break;

  case 46:
#line 212 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 47:
#line 216 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 48:
#line 217 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 49:
#line 222 "a.y"
    { (yyval.node) = opr(FUNC_OP, 3, NULL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 50:
#line 226 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 51:
#line 227 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 52:
#line 228 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 53:
#line 233 "a.y"
    { (yyval.node) = opr(VAR_DECLAR , 2, NULL, (yyvsp[(1) - (1)].node) ); }
    break;

  case 54:
#line 234 "a.y"
    { (yyval.node) = opr(VAR_DECLAR, 2, intNode((yyvsp[(1) - (2)].iValue)), (yyvsp[(2) - (2)].node) ); }
    break;

  case 55:
#line 238 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 56:
#line 239 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 57:
#line 243 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 58:
#line 244 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 59:
#line 248 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 60:
#line 249 "a.y"
    { (yyval.node) = arrayNode((yyvsp[(1) - (4)].node)->var_obj->name, -1, (yyvsp[(3) - (4)].node)); }
    break;

  case 61:
#line 254 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 62:
#line 255 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 63:
#line 260 "a.y"
    { (yyval.node) = opr(OPR_START_IF, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 64:
#line 261 "a.y"
    { (yyval.node) = opr(KEY_SWITCH, 2 , (yyvsp[(3) - (7)].node),(yyvsp[(6) - (7)].node)); pretreatSwitch( (yyval.node) ) ; }
    break;

  case 65:
#line 265 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 66:
#line 266 "a.y"
    { (yyval.node) = opr(OPR_IF_ELSE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 67:
#line 270 "a.y"
    { (yyval.node) = opr(KEY_IF ,2,(yyvsp[(3) - (5)].node),(yyvsp[(5) - (5)].node)) ; }
    break;

  case 68:
#line 274 "a.y"
    { (yyval.node) =  opr(OPR_IF_ELSE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 69:
#line 275 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:
#line 279 "a.y"
    { (yyval.node) = opr(OPR_IF_ELSE, 2, (yyvsp[(1) - (1)].node), NULL); }
    break;

  case 71:
#line 280 "a.y"
    { (yyval.node) =  opr(OPR_IF_ELSE, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 72:
#line 284 "a.y"
    { (yyval.node) = (yyvsp[(2) - (2)].node); }
    break;

  case 73:
#line 288 "a.y"
    { (yyval.node) = opr( KEY_ELSE, 1, (yyvsp[(2) - (2)].node)); }
    break;

  case 74:
#line 292 "a.y"
    { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[(1) - (1)].node) ); }
    break;

  case 75:
#line 293 "a.y"
    { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node) ); }
    break;

  case 76:
#line 297 "a.y"
    { (yyval.node) = opr(KEY_CASE, 2 , (yyvsp[(2) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 77:
#line 298 "a.y"
    { (yyval.node) = opr(KEY_DEFAULT , 1, (yyvsp[(3) - (3)].node)); }
    break;

  case 78:
#line 302 "a.y"
    { (yyval.node) = opr(KEY_WHILE , 2, (yyvsp[(3) - (5)].node), (yyvsp[(5) - (5)].node) ); }
    break;

  case 79:
#line 303 "a.y"
    { (yyval.node) = opr(KEY_FOR,4,(yyvsp[(3) - (9)].node),(yyvsp[(5) - (9)].node),(yyvsp[(7) - (9)].node),(yyvsp[(9) - (9)].node)); }
    break;

  case 80:
#line 307 "a.y"
    { (yyval.node) = intNode(1);  }
    break;

  case 81:
#line 308 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 82:
#line 312 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 83:
#line 313 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 84:
#line 314 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 85:
#line 319 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 86:
#line 325 "a.y"
    { (yyval.node) = NULL ; }
    break;

  case 87:
#line 326 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 88:
#line 327 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 89:
#line 332 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 90:
#line 333 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 91:
#line 338 "a.y"
    { (yyval.node) = (yyvsp[(1) - (2)].node); }
    break;

  case 92:
#line 342 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 93:
#line 343 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 94:
#line 344 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 95:
#line 345 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 96:
#line 346 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 97:
#line 347 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 98:
#line 348 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 99:
#line 349 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 100:
#line 350 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 101:
#line 355 "a.y"
    { (yyval.node) = opr(KEY_RESTRICT,0);}
    break;

  case 102:
#line 356 "a.y"
    { (yyval.node) = opr(KEY_RESTRICT,1,(yyvsp[(2) - (2)].node)); }
    break;

  case 103:
#line 360 "a.y"
    { (yyval.node) = opr(KEY_BREAK, 0); }
    break;

  case 104:
#line 361 "a.y"
    { (yyval.node) = opr(KEY_RETURN , 0); }
    break;

  case 105:
#line 362 "a.y"
    { (yyval.node) = opr(KEY_RETURN , 1 ,(yyvsp[(2) - (2)].node));}
    break;

  case 106:
#line 363 "a.y"
    { (yyval.node) = opr(KEY_CONTINUE,0); }
    break;

  case 107:
#line 368 "a.y"
    { (yyval.node) = opr(FUNC_CALL, 2, (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 108:
#line 369 "a.y"
    { (yyval.node) = opr(CLAXX_FUNC_CALL, 3, (yyvsp[(1) - (4)].node), (yyvsp[(3) - (4)].node), (yyvsp[(4) - (4)].node)); }
    break;

  case 109:
#line 374 "a.y"
    { (yyval.node) = opr('+',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 110:
#line 375 "a.y"
    { (yyval.node) = opr('-',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 111:
#line 376 "a.y"
    { (yyval.node) = opr('*',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 112:
#line 377 "a.y"
    { (yyval.node) = opr('/',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 113:
#line 378 "a.y"
    { (yyval.node) = opr('%',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 114:
#line 379 "a.y"
    { (yyval.node) = opr('&',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 115:
#line 380 "a.y"
    { (yyval.node) = opr('|',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 116:
#line 381 "a.y"
    { (yyval.node) = opr('^',2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 117:
#line 382 "a.y"
    { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 118:
#line 383 "a.y"
    { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 119:
#line 384 "a.y"
    { (yyval.node) = opr('~',1,(yyvsp[(2) - (2)].node)); }
    break;

  case 120:
#line 389 "a.y"
    { (yyval.node) = opr(KEY_NEW, 2 , (yyvsp[(2) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 121:
#line 393 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 122:
#line 394 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 123:
#line 398 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 124:
#line 399 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 2 , (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 125:
#line 403 "a.y"
    { (yyval.node) = opr(KEY_DELETE, 1, (yyvsp[(2) - (2)].node)); }
    break;

  case 126:
#line 409 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 127:
#line 410 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 128:
#line 411 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 129:
#line 412 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 130:
#line 413 "a.y"
    { (yyval.node) = opr((yyvsp[(2) - (3)].iValue), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 131:
#line 417 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 132:
#line 418 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 133:
#line 423 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 134:
#line 424 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 135:
#line 429 "a.y"
    { (yyval.node) = opr(KEY_IS ,2 , (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node)); }
    break;

  case 136:
#line 433 "a.y"
    { (yyval.node) = opr('!', 1, (yyvsp[(2) - (2)].node)); }
    break;

  case 137:
#line 438 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 138:
#line 439 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 139:
#line 443 "a.y"
    { (yyval.node) = opr((yyvsp[(2) - (3)].iValue), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 140:
#line 447 "a.y"
    { (yyval.node) = opr((yyvsp[(2) - (3)].iValue), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 141:
#line 451 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 142:
#line 452 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 143:
#line 453 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 144:
#line 454 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 145:
#line 455 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 146:
#line 456 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 147:
#line 460 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 148:
#line 461 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 149:
#line 466 "a.y"
    { (yyval.node) = opr(OPR_INC_DEC,2, intNode((yyvsp[(1) - (2)].iValue)), (yyvsp[(2) - (2)].node) ); }
    break;

  case 150:
#line 467 "a.y"
    { (yyval.node) = opr(OPR_INC_DEC, 2, (yyvsp[(1) - (2)].node), intNode((yyvsp[(2) - (2)].iValue))); }
    break;

  case 151:
#line 471 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 152:
#line 472 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 153:
#line 478 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 154:
#line 479 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 155:
#line 480 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 156:
#line 488 "a.y"
    { (yyval.node) = objectArrayElementNode((yyvsp[(1) - (4)].node), -1, (yyvsp[(3) - (4)].node)); }
    break;

  case 157:
#line 493 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 158:
#line 494 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node) ;}
    break;

  case 159:
#line 498 "a.y"
    { (yyval.node) = opr('=',2, (yyvsp[(1) - (3)].node),(yyvsp[(3) - (3)].node) ); }
    break;

  case 160:
#line 502 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 161:
#line 503 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 162:
#line 507 "a.y"
    { (yyval.node) = opr((yyvsp[(2) - (3)].iValue), 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 163:
#line 511 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 164:
#line 512 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 165:
#line 513 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 166:
#line 514 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 167:
#line 515 "a.y"
    { (yyval.iValue) = (yyvsp[(1) - (1)].iValue); }
    break;

  case 168:
#line 520 "a.y"
    { (yyval.node) = NULL; }
    break;

  case 169:
#line 521 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 170:
#line 525 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 1, (yyvsp[(1) - (1)].node)); }
    break;

  case 171:
#line 526 "a.y"
    { (yyval.node) = opr(OPR_NODE_LIST, 2 , (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node)); }
    break;

  case 172:
#line 530 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 173:
#line 531 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 174:
#line 532 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 175:
#line 533 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 176:
#line 538 "a.y"
    { (yyval.node) = opr('+', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 177:
#line 539 "a.y"
    { (yyval.node) = opr('+', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 178:
#line 543 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 179:
#line 544 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 180:
#line 545 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 181:
#line 546 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 182:
#line 547 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 183:
#line 551 "a.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 184:
#line 557 "a.y"
    { (yyval.node) = var((yyvsp[(1) - (1)].sValue)); }
    break;

  case 185:
#line 561 "a.y"
    { (yyval.node) = opr(OPR_MULTIPLE_ID , 1 , (yyvsp[(1) - (1)].node) );}
    break;

  case 186:
#line 562 "a.y"
    { (yyval.node) = opr(OPR_MULTIPLE_ID , 2 , (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node)); }
    break;

  case 187:
#line 566 "a.y"
    { (yyval.node) = intNode((yyvsp[(1) - (1)].iValue)); }
    break;

  case 188:
#line 570 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 189:
#line 571 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 190:
#line 575 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 191:
#line 576 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 192:
#line 580 "a.y"
    { (yyval.node) = intNode((yyvsp[(1) - (1)].iValue)); }
    break;

  case 193:
#line 584 "a.y"
    { (yyval.node) = number((yyvsp[(1) - (1)].dValue)); }
    break;

  case 194:
#line 588 "a.y"
    { (yyval.node) = opr(UMINUS, 1, (yyvsp[(2) - (2)].node) ); }
    break;

  case 195:
#line 592 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 196:
#line 593 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 197:
#line 594 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 198:
#line 595 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 199:
#line 599 "a.y"
    { (yyval.node) = string((yyvsp[(1) - (1)].sValue)); }
    break;

  case 200:
#line 603 "a.y"
    { (yyval.node) = xnull(); }
    break;

  case 201:
#line 610 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 202:
#line 611 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 203:
#line 612 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 204:
#line 613 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 205:
#line 614 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 206:
#line 618 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 207:
#line 619 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 208:
#line 620 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 209:
#line 621 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 210:
#line 625 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 211:
#line 626 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 212:
#line 627 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 213:
#line 631 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 214:
#line 632 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 215:
#line 633 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 216:
#line 634 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 217:
#line 638 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 218:
#line 642 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 219:
#line 643 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 220:
#line 644 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 221:
#line 648 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 222:
#line 649 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 223:
#line 658 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 224:
#line 659 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 225:
#line 660 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 226:
#line 661 "a.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;


/* Line 1267 of yacc.c.  */
#line 3073 "y.tab.c"
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


#line 664 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}

