/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0






#include "y.tab.h"

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

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template,
   here we set the default value of $$ to a zeroed-out value.
   Since the default value is undefined, this behavior is
   technically correct.  */
static YYSTYPE yyval_default;

/* Copy the second part of user declarations.  */


/* Line 234 of glr.c.  */
#line 89 "y.tab.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX ((size_t) -1)

#ifdef __cplusplus
   typedef bool yybool;
#else
   typedef unsigned char yybool;
#endif
#define yytrue 1
#define yyfalse 0

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(env) setjmp (env)
# define YYLONGJMP(env, val) longjmp (env, val)
#endif

/*-----------------.
| GCC extensions.  |
`-----------------*/

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__)
#  define __attribute__(Spec) /* empty */
# endif
#endif


#ifdef __cplusplus
# define YYOPTIONAL_LOC(Name) /* empty */
#else
# define YYOPTIONAL_LOC(Name) Name __attribute__ ((__unused__))
#endif

#ifndef YYASSERT
# define YYASSERT(condition) ((void) ((condition) || (abort (), 0)))
#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   816

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNRULES -- Number of states.  */
#define YYNSTATES  341
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)						\
  ((YYX <= 0) ? YYEOF :							\
   (unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,     2,     2,     2,    86,    81,     2,
      90,    91,    84,    82,    76,    83,    94,    85,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,    99,
      71,    78,    69,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,     2,    93,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    79,   101,    88,     2,     2,     2,
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
      65,    66,    67,    68,    70,    72,    73,    74,    75,    77,
      89,    95,    96,    97,    98
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
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
static const short int yyrhs[] =
{
     104,     0,    -1,   105,    -1,   105,   106,    -1,    -1,   107,
      -1,   108,    -1,   134,    -1,   150,    -1,   111,    -1,    99,
      -1,   125,    -1,   116,    -1,   113,    -1,   114,    -1,   110,
     194,    -1,    58,    -1,    59,    -1,    60,    -1,    14,   179,
      -1,    14,   179,   112,    -1,    21,    90,   185,    91,   179,
      -1,    16,    15,    78,   115,    -1,    18,   115,    -1,   185,
      -1,   115,    94,   185,    -1,   117,   185,   118,   119,    -1,
      -1,    25,    -1,    -1,    23,   186,    -1,   100,   101,    -1,
     100,   120,   101,    -1,   121,    -1,   120,   121,    -1,   130,
      99,    -1,   175,    99,    -1,   125,    -1,   107,    -1,    22,
      -1,   202,    94,   185,    -1,   185,    44,   185,    -1,   126,
      10,   179,    -1,   126,    10,   127,   179,    -1,   185,    -1,
      88,   185,    -1,     8,    -1,    90,    91,    -1,    90,   186,
      91,    -1,   129,    10,   179,    -1,    90,    91,    -1,    90,
     186,    91,    -1,   186,    -1,   132,    -1,   131,   132,    -1,
      26,    -1,    27,    -1,   133,    -1,   132,    76,   133,    -1,
     185,    -1,   185,    92,   201,    93,    -1,   135,    -1,   144,
      -1,   136,    -1,    35,    90,   201,    91,   100,   142,   101,
      -1,   137,    -1,   137,   138,    -1,    28,    90,   160,    91,
     179,    -1,   139,   141,    -1,   141,    -1,   140,    -1,   139,
     140,    -1,    29,   137,    -1,    29,   179,    -1,   143,    -1,
     142,   143,    -1,    36,   190,   102,   179,    -1,    37,   102,
     179,    -1,    30,    90,   160,    91,   179,    -1,    31,    90,
     146,    99,   145,    99,   148,    91,   179,    -1,    -1,   160,
      -1,    -1,   147,    -1,   146,    76,   147,    -1,   174,    -1,
      -1,   149,    -1,   148,    76,   149,    -1,   174,    -1,   170,
      -1,   151,    99,    -1,   170,    -1,   174,    -1,   154,    -1,
     159,    -1,   153,    -1,   156,    -1,   152,    -1,   109,    -1,
     130,    -1,    24,    -1,    24,   187,    -1,    33,    -1,    34,
      -1,    34,   203,    -1,    19,    -1,   198,   157,    -1,   154,
      94,   185,   157,    -1,   201,    82,   201,    -1,   201,    83,
     201,    -1,   201,    84,   201,    -1,   201,    85,   201,    -1,
     201,    86,   201,    -1,   201,    81,   201,    -1,   201,    79,
     201,    -1,   201,    80,   201,    -1,   201,    45,   201,    -1,
     201,    46,   201,    -1,    88,   201,    -1,    20,   185,   157,
      -1,    90,    91,    -1,    90,   158,    91,    -1,   203,    -1,
     158,    76,   203,    -1,    32,   186,    -1,   162,    -1,   164,
      -1,   163,    -1,   165,    -1,   160,   161,   160,    -1,    72,
      -1,    73,    -1,   172,    -1,   187,    -1,   202,    17,   185,
      -1,    87,   162,    -1,   166,    -1,   167,    -1,   201,   168,
     201,    -1,   202,   169,   196,    -1,    69,    -1,    71,    -1,
      67,    -1,    66,    -1,    70,    -1,    68,    -1,    70,    -1,
      68,    -1,   171,   198,    -1,   198,   171,    -1,    47,    -1,
      48,    -1,   188,    -1,   198,    -1,   199,    -1,   202,    92,
     201,    93,    -1,   175,    -1,   177,    -1,   200,    78,   176,
      -1,   203,    -1,   175,    -1,   200,   178,   201,    -1,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,   100,
     101,    -1,   100,   180,   101,    -1,   181,    -1,   180,   181,
      -1,   111,    -1,   150,    -1,   134,    -1,   107,    -1,   194,
      82,   183,    -1,   183,    82,   194,    -1,   202,    -1,   196,
      -1,   182,    -1,   170,    -1,   184,    -1,    90,   201,    91,
      -1,     6,    -1,   185,    -1,   186,    76,   185,    -1,     4,
      -1,   189,    -1,   192,    -1,   191,    -1,   190,    -1,     3,
      -1,     5,    -1,    83,   193,    -1,   189,    -1,   197,    -1,
     154,    -1,   184,    -1,     7,    -1,    38,    -1,   188,    -1,
     194,    -1,   195,    -1,   128,    -1,   187,    -1,   185,    -1,
     173,    -1,   123,    -1,   124,    -1,   197,    -1,   122,    -1,
     156,    -1,   170,    -1,   154,    -1,   155,    -1,   184,    -1,
     197,    -1,   188,    -1,   198,    -1,   199,    -1,   198,    -1,
     154,    -1,   196,    -1,   198,    -1,   199,    -1,   182,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    85,    85,    89,    90,    93,    94,    95,    96,    97,
     101,   105,   106,   107,   108,   113,   117,   118,   119,   124,
     125,   129,   135,   140,   144,   145,   155,   159,   160,   165,
     166,   170,   171,   175,   176,   180,   181,   182,   183,   188,
     194,   199,   209,   210,   214,   215,   216,   220,   221,   226,
     230,   231,   232,   237,   238,   242,   243,   247,   248,   252,
     253,   258,   259,   264,   265,   269,   270,   274,   278,   279,
     283,   284,   288,   292,   296,   297,   301,   302,   306,   307,
     311,   312,   316,   317,   318,   323,   329,   330,   331,   336,
     337,   342,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   359,   360,   364,   365,   366,   367,   372,   373,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     393,   397,   398,   402,   403,   407,   413,   414,   415,   416,
     417,   421,   422,   427,   428,   433,   437,   442,   443,   447,
     451,   455,   456,   457,   458,   459,   460,   464,   465,   470,
     471,   475,   476,   482,   483,   484,   492,   497,   498,   502,
     506,   507,   511,   515,   516,   517,   518,   519,   524,   525,
     529,   530,   534,   535,   536,   537,   542,   543,   547,   548,
     549,   550,   551,   555,   561,   565,   566,   570,   574,   575,
     579,   580,   584,   588,   592,   596,   597,   598,   599,   603,
     607,   614,   615,   616,   617,   618,   622,   623,   624,   625,
     629,   630,   631,   635,   636,   637,   638,   642,   646,   647,
     648,   652,   653,   662,   663,   664,   665
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
  "KEY_THIS", "KEY_EXTENDS", "KEY_RESTRICT", "KEY_AUTO", "KEY_CONST",
  "KEY_LOCAL", "KEY_IF", "KEY_ELSE", "KEY_WHILE", "KEY_FOR", "KEY_DELETE",
  "KEY_BREAK", "KEY_RETURN", "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT",
  "KEY_NULL", "CASE_LIST", "CLAXX_BODY", "CLAXX_MEMBER", "CLAXX_FUNC_CALL",
  "SCOPE_FUNC_CALL", "SCOPE", "LEFT_SHIFT", "RIGHT_SHIFT", "INC_OP",
  "DEC_OP", "OPR_NODE_LIST", "OPR_CHANGE_NAME_SPACE", "OPR_GET_NAME_SPACE",
  "OPR_CLASS_DECLARE", "OPR_INC_DEC", "OPR_IF_ELSE", "OPR_MULTIPLE_ID",
  "OPR_START_IF", "OPR_ARGS_LIST", "KEY_REQUIRE", "KEY_REQUIRE_ONCE",
  "KEY_INCLUDE", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ", "LE_OP",
  "GE_OP", "EQ_OP", "'>'", "NE_OP", "'<'", "AND_OP", "OR_OP", "IFX",
  "ELSE", "','", "PIPELINE_OP", "'='", "'|'", "'^'", "'&'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "'~'", "INC_OP_BACK", "'('", "')'", "'['",
  "']'", "'.'", "PRIORITY3", "PRIORITY2", "PRIORITY1", "UMINUS", "';'",
  "'{'", "'}'", "':'", "$accept", "program", "statement_list", "statement",
  "_extra_nothing", "out_declare_stmt", "require_stmt",
  "require_operators", "try_stmt", "catch_block_stmt",
  "namespace_declare_stmt", "namespace_ref_stmt", "namespace_name_stmt",
  "class_declare_stmt", "class_name_prefix", "class_name_suffix",
  "class_body", "class_body_items", "class_body_item", "this_stmt",
  "class_member_stmt", "static_member_stmt", "func_declare_stmt",
  "func_name_types", "func_param_list", "lambda_stmt", "lambda_args_stmt",
  "var_declare_stmt", "var_prefix", "_elements_var_declare_stmt",
  "element_var_declare_stmt", "con_ctl_stmt", "selection_stmt", "if_stmt",
  "single_if_stmt", "else_stmt", "else_if_stmts", "else_if_stmt",
  "single_else_stmt", "case_stmt_list", "case_stmt", "loop_stmt",
  "for_logic_stmt", "for_1_stmt_list", "for_1_stmt", "for_3_stmt_list",
  "for_3_stmt", "simple_stmt", "simple_stmt_types", "restrict_stmt",
  "interrupt_stmt", "call_statement", "arithmetic_stmt", "new_expr",
  "args_list_with_parentheses", "args_list", "delete_expr", "logic_stmt",
  "_symbol_logic_connection", "bool_param_expr", "type_judge_stmt",
  "not_bool_param_expr", "compare_expr", "number_compare_expr",
  "object_compare_expr", "_symbol_compare", "_symbol_equals_not",
  "self_inc_dec_stmt", "self_inc_dec_operators", "assign_stmt_value_eq",
  "array_ele_stmt", "assign_stmt", "single_assign_stmt",
  "single_assign_stmt_value", "number_change_assign_stmt",
  "symbol_change_assign", "code_block", "block_item_list", "block_item",
  "string_plus_stmt", "string_plus_stmt_value", "number_parentheses_stmt",
  "id_expr", "multiple_id_expr", "bool_expr", "number_expr",
  "positive_number_expr", "int_expr", "double_expr", "uminus_expr",
  "uminus_expr_values", "string_expr", "null_expr", "common_types_expr",
  "common_others_values_expr", "common_values_expr",
  "common_result_of_call_expr", "common_assignable_expr",
  "common_number_expr", "common_object_expr", "common_expr", 0
};
#endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   103,   104,   105,   105,   106,   106,   106,   106,   106,
     107,   108,   108,   108,   108,   109,   110,   110,   110,   111,
     111,   112,   113,   114,   115,   115,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   121,   122,
     123,   124,   125,   125,   126,   126,   126,   127,   127,   128,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   138,   138,
     139,   139,   140,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   146,   147,   148,   148,   148,   149,
     149,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   152,   152,   153,   153,   153,   153,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   157,   157,   158,   158,   159,   160,   160,   160,   160,
     160,   161,   161,   162,   162,   163,   164,   165,   165,   166,
     167,   168,   168,   168,   168,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   172,   173,   174,   174,   175,
     176,   176,   177,   178,   178,   178,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   181,   182,   182,   183,   183,
     183,   183,   183,   184,   185,   186,   186,   187,   188,   188,
     189,   189,   190,   191,   192,   193,   193,   193,   193,   194,
     195,   196,   196,   196,   196,   196,   197,   197,   197,   197,
     198,   198,   198,   199,   199,   199,   199,   200,   201,   201,
     201,   202,   202,   203,   203,   203,   203
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
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

/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const unsigned char yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const unsigned char yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
   doesn't specify something else to do.  Zero means the default is an
   error.  */
static const unsigned char yydefact[] =
{
       4,     0,     2,     1,   184,    46,     0,     0,     0,   106,
       0,    39,   101,    28,    55,    56,     0,     0,     0,     0,
     103,   104,     0,   151,   152,    16,    17,    18,     0,    10,
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

/* YYPDEFGOTO[NTERM-NUM].  */
static const short int yydefgoto[] =
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
#define YYPACT_NINF -275
static const short int yypact[] =
{
    -275,    32,   492,  -275,  -275,  -275,   -85,    33,    50,  -275,
      50,  -275,    22,  -275,  -275,  -275,   -29,   -23,    12,    50,
    -275,   554,    37,  -275,  -275,  -275,  -275,  -275,    50,  -275,
    -275,  -275,  -275,  -275,   115,  -275,  -275,  -275,  -275,    50,
    -275,  -275,  -275,  -275,    81,  -275,    50,    54,  -275,  -275,
    -275,  -275,   114,  -275,  -275,    53,  -275,  -275,    11,    58,
    -275,  -275,   112,  -275,  -275,  -275,  -275,   138,   563,     6,
     626,    86,   346,   153,   109,   101,  -275,   108,  -275,  -275,
     562,   562,   112,  -275,   140,  -275,  -275,  -275,  -275,    24,
     592,   341,  -275,   212,   366,  -275,  -275,   142,   156,   158,
     170,    84,   140,  -275,   237,  -275,  -275,  -275,  -275,   172,
    -275,   192,  -275,   392,   221,   724,    86,  -275,   592,  -275,
    -275,   257,   -31,    54,   190,    50,     7,  -275,   114,  -275,
    -275,  -275,    50,   193,   246,   248,    50,   592,   525,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,   554,   592,   592,    50,
    -275,  -275,  -275,  -275,  -275,   445,  -275,   105,   208,  -275,
      50,    50,  -275,   583,   592,   205,  -275,  -275,  -275,  -275,
    -275,  -275,  -275,  -275,  -275,  -275,   145,   587,   154,   711,
      41,   250,    21,  -275,  -275,   108,    50,   100,  -275,  -275,
    -275,   259,  -275,   121,  -275,  -275,  -275,   -26,   669,   -85,
     115,   405,   592,   592,   592,   592,   592,   592,   592,   592,
     592,   592,   682,    50,   199,    15,   -85,  -275,  -275,  -275,
    -275,  -275,  -275,   108,  -275,   638,  -275,    34,  -275,  -275,
    -275,   215,  -275,   724,   654,  -275,  -275,  -275,    50,   101,
    -275,  -275,  -275,  -275,   -85,   562,  -275,  -275,  -275,  -275,
    -275,  -275,   592,    50,  -275,  -275,   615,   -85,   112,   562,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,  -275,
    -275,   313,   313,   186,   730,   451,   300,   300,  -275,  -275,
    -275,   204,   140,    16,  -275,  -275,   144,  -275,  -275,  -275,
     554,  -275,  -275,   216,  -275,   -33,   724,  -275,    17,  -275,
    -275,  -275,  -275,   219,    98,    62,  -275,  -275,    25,  -275,
    -275,   225,   228,  -275,  -275,   -85,   203,   328,   241,   104,
    -275,  -275,  -275,  -275,  -275,  -275,   185,  -275,  -275,  -275,
     252,   -85,  -275,  -275,   203,   -85,   -85,  -275,  -275,  -275,
    -275
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -275,  -275,  -275,  -275,     3,  -275,  -275,  -275,   337,  -275,
    -275,  -275,   196,  -275,  -275,  -275,  -275,  -275,    42,  -275,
    -275,  -275,   355,  -275,  -275,  -275,  -275,  -274,  -275,   316,
     239,   365,  -275,  -275,   243,  -275,  -275,   254,   262,  -275,
      52,  -275,  -275,  -275,   129,  -275,    57,   390,  -275,  -275,
    -275,     0,  -275,     9,   -60,  -275,  -275,   -68,  -275,   238,
    -275,  -275,  -275,  -275,  -275,  -275,  -275,    -1,    26,  -275,
    -275,   -70,  -132,  -275,  -275,  -275,   -10,  -275,   245,   201,
     202,   -15,    47,    -3,    -4,   -17,   318,   106,  -275,  -275,
    -275,   -27,  -275,  -164,     1,    -2,     4,  -118,   211,    20,
    -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -226
static const short int yytable[] =
{
      69,    61,    58,    68,   104,    31,   100,   120,    79,   311,
     228,    59,   184,   181,   229,    72,    84,   162,   232,   113,
      97,     4,     4,     4,     5,   114,    78,    85,   231,    86,
       4,     4,     3,     5,   311,    16,    10,   270,    11,   242,
     243,   116,    14,    15,    10,    10,    11,    11,    74,    67,
     186,    14,    15,    23,    24,    76,     4,    77,   253,   215,
     135,    80,   133,   176,   176,   261,    83,    81,   101,    72,
      69,    61,    58,    68,   188,   119,   175,   175,   177,   177,
     185,    59,   133,    68,   178,   178,   121,   185,   197,   187,
     191,   122,   300,   124,  -185,   140,   138,   258,   317,   318,
     180,   180,    82,  -222,    28,   132,   285,    72,   196,   254,
     290,   255,   217,    28,   164,    29,   220,   306,     4,   157,
     259,   104,    87,   100,    29,   291,   321,   118,   136,   104,
     125,   100,    10,   148,    11,   149,   113,    97,   101,   140,
     317,   318,   114,   126,   113,    97,   176,    68,   -44,   136,
     114,   312,   131,    69,    61,    58,    68,   -97,   116,   175,
    -185,   177,   314,   288,    59,   231,   116,   178,    23,    24,
     242,   243,   124,   264,   158,  -185,   312,   295,   148,   223,
     149,   -59,   136,   224,   269,   101,   268,   160,   184,   263,
     231,   304,  -222,   101,   132,   161,   235,   137,   138,    69,
     265,   133,   157,   140,   -59,   332,   287,    76,   240,     4,
     282,   138,   286,  -221,   -59,  -221,   186,  -153,  -153,   140,
     186,   116,   199,    10,  -181,    11,  -155,  -155,   176,   299,
     137,   202,   203,   260,   294,   313,  -153,   -59,  -180,   269,
     200,   175,   176,   177,  -153,  -155,   329,   301,   101,   178,
      23,    24,  -182,  -155,   201,   175,   185,   177,   133,    68,
      83,   334,    83,   178,   329,   180,   205,   206,   207,   208,
     209,   210,   211,   104,  -179,   100,   335,   242,   243,   180,
     213,   185,   137,   133,    68,   293,   307,   132,   113,    97,
     136,   179,   179,   146,   114,   197,   244,  -225,   238,   283,
     297,   195,   198,    83,   305,   325,   185,   315,   133,    68,
     116,   307,  -225,  -201,    69,   328,   133,    68,   316,  -201,
    -225,   337,   242,   243,   323,   339,   340,   324,  -201,   212,
      67,    85,    69,   328,   133,    68,  -201,   101,   138,    35,
    -221,   257,  -221,   331,    85,    83,    86,     4,   225,  -210,
     322,  -210,     4,  -210,   336,    67,   239,    43,   233,   234,
       6,    10,   123,    11,   218,     9,    10,    49,    11,   219,
      12,   333,    14,    15,    16,   198,    17,    18,    19,    20,
      21,    22,   221,  -222,   209,   210,   211,   302,    23,    24,
     222,   338,    54,    23,    24,   207,   208,   209,   210,   211,
     237,   241,   266,   267,    25,    26,    27,   189,    85,    78,
      86,     4,    87,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   330,    89,    10,     0,    11,     0,    90,
       0,   164,   196,     0,  -214,     0,  -214,     0,     0,    23,
      24,     0,     0,    88,     0,    29,     0,   150,  -214,     0,
       0,     4,    23,    24,     0,     0,   179,     0,  -222,     6,
     132,     0,     0,   296,     9,    10,     0,    11,  -224,    12,
     179,    14,    15,    16,  -219,    17,    18,    19,    20,    21,
      22,     0,   138,  -224,  -221,     0,  -221,     0,    89,     0,
       0,  -224,    23,    24,     0,    91,   202,   203,     4,     0,
       5,     0,     0,    25,    26,    27,     6,     0,     7,     0,
       8,     9,    10,     0,    11,     0,    12,    13,    14,    15,
      16,     0,    17,    18,    19,    20,    21,    22,    85,    78,
      86,     4,    87,   207,   208,   209,   210,   211,     0,    23,
      24,     0,     0,     0,    29,    10,   236,    11,     0,     0,
      25,    26,    27,     0,     0,     0,     0,    85,    78,    86,
       4,    87,     0,    88,     0,    85,    78,    86,     4,     0,
       0,     0,    23,    24,    10,     0,    11,     0,     0,     0,
      28,     0,    10,     0,    11,     0,    85,    78,    86,     4,
       0,    29,    88,     0,     0,    85,     0,    86,     4,     0,
       0,    23,    24,    10,  -221,    11,     0,     0,    89,    23,
      24,     0,    10,    90,    11,    91,   226,     0,    85,    78,
      86,     4,    87,     0,  -217,  -217,  -217,  -217,  -217,     0,
      23,    24,     0,     0,    23,    24,     0,    89,     0,    23,
      24,  -217,    90,     0,    91,    89,     0,     0,     0,   163,
      90,     0,   164,    88,     0,  -219,     0,  -219,     0,  -154,
    -154,     0,     0,     0,     0,     0,    89,     0,     0,     0,
       0,    90,     0,   164,     0,    89,     0,   138,  -154,  -221,
      90,  -221,   164,   202,   203,     0,  -154,   141,   142,   143,
     144,   145,     0,     0,     0,     0,     0,     0,    89,   202,
     203,     0,     0,     0,   146,   298,     0,     0,     0,     0,
       0,     0,     0,     0,   202,   203,     0,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,   202,   203,     0,
       0,   289,     0,   204,   205,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     0,     0,     0,   292,   204,   205,
     206,   207,   208,   209,   210,   211,   202,   203,     0,     0,
     262,   204,   205,   206,   207,   208,   209,   210,   211,   202,
     203,     0,     0,   281,     0,   202,   203,   246,   247,   248,
     249,   250,   251,     0,     0,     0,     0,     0,     0,     0,
     204,   205,   206,   207,   208,   209,   210,   211,     0,     0,
       0,     0,     0,   204,   205,   206,   207,   208,   209,   210,
     211,   206,   207,   208,   209,   210,   211
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const unsigned char yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short int yyconfl[] =
{
       0,    27,     0,   222,     0,   206,     0,   222,     0,   222,
       0,   222,     0,   222,     0,   213,     0,   216,     0,   206,
       0,   206,     0,   218,     0,   202,     0,   221,     0,   222,
       0,   206,     0,   221,     0,   221,     0,   222,     0,   130,
       0,   130,     0
};

static const short int yycheck[] =
{
       2,     2,     2,     2,    21,     2,    21,    34,    12,   283,
     138,     2,    82,    81,   146,   100,    19,    77,   146,    21,
      21,     6,     6,     6,     8,    21,     4,     3,   146,     5,
       6,     6,     0,     8,   308,    28,    20,   201,    22,    72,
      73,    21,    26,    27,    20,    20,    22,    22,    15,     2,
      76,    26,    27,    47,    48,     8,     6,    10,    17,    90,
      62,    90,    62,    80,    81,    91,    19,    90,    21,   100,
      72,    72,    72,    72,    89,    28,    80,    81,    80,    81,
      82,    72,    82,    82,    80,    81,    39,    89,    91,    89,
      89,    10,   256,    46,    10,    69,    90,    76,    36,    37,
      80,    81,    90,    92,    88,    94,    91,   100,    91,    68,
      76,    70,   122,    88,    90,    99,   126,   101,     6,    72,
      99,   138,     7,   138,    99,    91,   101,    90,    44,   146,
      76,   146,    20,    92,    22,    94,   138,   138,    91,   113,
      36,    37,   138,    29,   146,   146,   163,   146,    10,    44,
     146,   283,    99,   155,   155,   155,   155,    99,   138,   163,
      76,   163,   290,   223,   155,   283,   146,   163,    47,    48,
      72,    73,   125,   200,    21,    91,   308,   245,    92,   132,
      94,    76,    44,   136,   201,   138,   201,    78,   258,   199,
     308,   259,    92,   146,    94,    94,   149,    92,    90,   201,
     201,   201,   155,   177,    99,   101,   216,   160,   161,     6,
     213,    90,   215,    92,    76,    94,    76,    72,    73,   193,
      76,   201,    10,    20,    82,    22,    72,    73,   245,   256,
      92,    45,    46,   186,   244,    91,    91,    99,    82,   256,
      82,   245,   259,   245,    99,    91,   316,   257,   201,   245,
      47,    48,    82,    99,    82,   259,   258,   259,   258,   258,
     213,    76,   215,   259,   334,   245,    80,    81,    82,    83,
      84,    85,    86,   290,    82,   290,    91,    72,    73,   259,
      23,   283,    92,   283,   283,   238,   283,    94,   290,   290,
      44,    80,    81,    78,   290,   298,    91,    76,    90,   100,
     253,    90,    91,   256,   100,   315,   308,    91,   308,   308,
     290,   308,    91,    76,   316,   316,   316,   316,    99,    82,
      99,   331,    72,    73,    99,   335,   336,    99,    91,   118,
     283,     3,   334,   334,   334,   334,    99,   290,    90,     2,
      92,    91,    94,   102,     3,   298,     5,     6,   137,    90,
     308,    92,     6,    94,   102,   308,   160,     2,   147,   148,
      14,    20,    46,    22,   125,    19,    20,     2,    22,   126,
      24,   319,    26,    27,    28,   164,    30,    31,    32,    33,
      34,    35,   128,    17,    84,    85,    86,   258,    47,    48,
     128,   334,     2,    47,    48,    82,    83,    84,    85,    86,
     155,   163,   201,   201,    58,    59,    60,    89,     3,     4,
       5,     6,     7,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   317,    83,    20,    -1,    22,    -1,    88,
      -1,    90,    91,    -1,    68,    -1,    70,    -1,    -1,    47,
      48,    -1,    -1,    38,    -1,    99,    -1,   101,    82,    -1,
      -1,     6,    47,    48,    -1,    -1,   245,    -1,    92,    14,
      94,    -1,    -1,   252,    19,    20,    -1,    22,    76,    24,
     259,    26,    27,    28,    82,    30,    31,    32,    33,    34,
      35,    -1,    90,    91,    92,    -1,    94,    -1,    83,    -1,
      -1,    99,    47,    48,    -1,    90,    45,    46,     6,    -1,
       8,    -1,    -1,    58,    59,    60,    14,    -1,    16,    -1,
      18,    19,    20,    -1,    22,    -1,    24,    25,    26,    27,
      28,    -1,    30,    31,    32,    33,    34,    35,     3,     4,
       5,     6,     7,    82,    83,    84,    85,    86,    -1,    47,
      48,    -1,    -1,    -1,    99,    20,   101,    22,    -1,    -1,
      58,    59,    60,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    38,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    47,    48,    20,    -1,    22,    -1,    -1,    -1,
      88,    -1,    20,    -1,    22,    -1,     3,     4,     5,     6,
      -1,    99,    38,    -1,    -1,     3,    -1,     5,     6,    -1,
      -1,    47,    48,    20,    17,    22,    -1,    -1,    83,    47,
      48,    -1,    20,    88,    22,    90,    91,    -1,     3,     4,
       5,     6,     7,    -1,    61,    62,    63,    64,    65,    -1,
      47,    48,    -1,    -1,    47,    48,    -1,    83,    -1,    47,
      48,    78,    88,    -1,    90,    83,    -1,    -1,    -1,    87,
      88,    -1,    90,    38,    -1,    68,    -1,    70,    -1,    72,
      73,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,
      -1,    88,    -1,    90,    -1,    83,    -1,    90,    91,    92,
      88,    94,    90,    45,    46,    -1,    99,    61,    62,    63,
      64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    83,    45,
      46,    -1,    -1,    -1,    78,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,    45,    46,    -1,
      -1,    93,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    79,    80,
      81,    82,    83,    84,    85,    86,    45,    46,    -1,    -1,
      91,    79,    80,    81,    82,    83,    84,    85,    86,    45,
      46,    -1,    -1,    91,    -1,    45,    46,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    84,    85,
      86,    81,    82,    83,    84,    85,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,   104,   105,     0,     6,     8,    14,    16,    18,    19,
      20,    22,    24,    25,    26,    27,    28,    30,    31,    32,
      33,    34,    35,    47,    48,    58,    59,    60,    88,    99,
     106,   107,   108,   109,   110,   111,   113,   114,   116,   117,
     122,   123,   124,   125,   126,   130,   131,   132,   133,   134,
     135,   136,   137,   144,   150,   151,   152,   153,   154,   156,
     159,   170,   171,   173,   174,   175,   177,   185,   197,   198,
     200,   202,   100,   179,    15,   115,   185,   185,     4,   187,
      90,    90,    90,   185,   186,     3,     5,     7,    38,    83,
      88,    90,   128,   129,   154,   155,   156,   170,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   194,
     195,   196,   197,   198,   199,   201,   202,   203,    90,   185,
     194,   185,    10,   132,   185,    76,    29,   138,   139,   140,
     141,    99,    94,   154,   185,   198,    44,    92,    90,   157,
     171,    61,    62,    63,    64,    65,    78,   178,    92,    94,
     101,   107,   111,   134,   150,   180,   181,   185,    21,   112,
      78,    94,   157,    87,    90,   160,   162,   163,   164,   165,
     166,   167,   170,   172,   184,   187,   188,   198,   199,   201,
     202,   160,   146,   147,   174,   198,    76,   154,   184,   189,
     193,   197,   188,   198,   199,   201,    91,   186,   201,    10,
      82,    82,    45,    46,    79,    80,    81,    82,    83,    84,
      85,    86,   201,    23,   118,    90,   127,   179,   133,   137,
     179,   140,   141,   185,   185,   201,    91,   158,   203,   175,
     176,   200,   203,   201,   201,   185,   101,   181,    90,   115,
     185,   162,    72,    73,    91,   161,    66,    67,    68,    69,
      70,    71,   168,    17,    68,    70,   169,    91,    76,    99,
     185,    91,    91,   179,   194,   170,   182,   183,   184,   188,
     196,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,    91,   186,   100,   119,    91,   186,   179,   157,    93,
      76,    91,    93,   185,   179,   160,   201,   185,    90,   194,
     196,   179,   147,   145,   160,   100,   101,   107,   120,   121,
     125,   130,   175,    91,   203,    91,    99,    36,    37,   142,
     143,   101,   121,    99,    99,   179,   148,   149,   170,   174,
     190,   102,   101,   143,    76,    91,   102,   179,   149,   179,
     179
};


/* Prevent warning if -Wmissing-prototypes.  */
int yyparse (void);

/* Error token number */
#define YYTERROR 1

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */


#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N) ((void) 0)
#endif


#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#define YYLEX yylex ()

YYSTYPE yylval;

YYLTYPE yylloc;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)							     \
   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
   while (YYID (0))

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
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

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			    \
do {									    \
  if (yydebug)								    \
    {									    \
      YYFPRINTF (stderr, "%s ", Title);					    \
      yy_symbol_print (stderr, Type,					    \
		       Value);  \
      YYFPRINTF (stderr, "\n");						    \
    }									    \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

#else /* !YYDEBUG */

# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
# if (! defined __cplusplus \
      || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
#  define YYSTACKEXPANDABLE 1
# else
#  define YYSTACKEXPANDABLE 0
# endif
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyexpandGLRStack (Yystack);			\
  } while (YYID (0))
#else
# define YY_RESERVE_GLRSTACK(Yystack)			\
  do {							\
    if (Yystack->yyspaceLeft < YYHEADROOM)		\
      yyMemoryExhausted (Yystack);			\
  } while (YYID (0))
#endif


#if YYERROR_VERBOSE

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
static size_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
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
    return strlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers, as in LALR(1) machine */
typedef int yyStateNum;

/** Rule numbers, as in LALR(1) machine */
typedef int yyRuleNum;

/** Grammar symbol */
typedef short int yySymbol;

/** Item references, as in LALR(1) machine */
typedef short int yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the first token produced by my symbol */
  size_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  non-terminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  size_t yysize, yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  size_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

static void yyFail (yyGLRStack* yystackp, const char* yymsg)
  __attribute__ ((__noreturn__));
static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != NULL)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

static void yyMemoryExhausted (yyGLRStack* yystackp)
  __attribute__ ((__noreturn__));
static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  if (yytoken == YYEMPTY)
    return "";

  return yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) __attribute__ ((__unused__));
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  yyGLRState* s;
  int i;
  s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
      YYASSERT (s->yyresolved);
      yyvsp[i].yystate.yyresolved = yytrue;
      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     __attribute__ ((__unused__));
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
/*ARGSUSED*/ static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
	      YYSTYPE* yyvalp,
	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
	      yyGLRStack* yystackp
	      )
{
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  int yylow;
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)						     \
  return yyerror (YY_("syntax error: cannot back up")),     \
	 yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);

  switch (yyn)
    {
        case 3:
#line 89 "a.y"
    { execAndFreeNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 5:
#line 93 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 6:
#line 94 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 7:
#line 95 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 8:
#line 96 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 9:
#line 97 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 10:
#line 101 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 11:
#line 105 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 12:
#line 106 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 13:
#line 107 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 14:
#line 108 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 15:
#line 113 "a.y"
    { ((*yyvalp).node) = opr((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.iValue) , 1 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 16:
#line 117 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 17:
#line 118 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 18:
#line 119 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 19:
#line 124 "a.y"
    { ((*yyvalp).node) = opr(KEY_TRY, 2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node),NULL); }
    break;

  case 20:
#line 125 "a.y"
    { ((*yyvalp).node) = opr(KEY_TRY, 2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 21:
#line 129 "a.y"
    { ((*yyvalp).node) = opr(KEY_CATCH, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.node)); }
    break;

  case 22:
#line 135 "a.y"
    { ((*yyvalp).node) = opr(OPR_CHANGE_NAME_SPACE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 23:
#line 140 "a.y"
    { ((*yyvalp).node) = opr(KEY_REF, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 24:
#line 144 "a.y"
    { ((*yyvalp).node) = opr(OPR_GET_NAME_SPACE, 2, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node)); }
    break;

  case 25:
#line 145 "a.y"
    { ((*yyvalp).node) = opr(OPR_GET_NAME_SPACE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 26:
#line 155 "a.y"
    {  ((*yyvalp).node) = opr(OPR_CLASS_DECLARE, 4, intNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.iValue)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 27:
#line 159 "a.y"
    { ((*yyvalp).iValue) = -1; }
    break;

  case 28:
#line 160 "a.y"
    { ((*yyvalp).iValue) = yytokentype::KEY_AUTO; }
    break;

  case 29:
#line 165 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 30:
#line 166 "a.y"
    { ((*yyvalp).node) = opr(KEY_EXTENDS, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 31:
#line 170 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 32:
#line 171 "a.y"
    { ((*yyvalp).node) = opr(CLAXX_BODY, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 33:
#line 175 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 34:
#line 176 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node) ,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 35:
#line 180 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node); }
    break;

  case 36:
#line 181 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node); }
    break;

  case 37:
#line 182 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 38:
#line 183 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 39:
#line 188 "a.y"
    { ((*yyvalp).node) = opr(KEY_THIS , 0 ); }
    break;

  case 40:
#line 194 "a.y"
    { ((*yyvalp).node) = opr(CLAXX_MEMBER, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 41:
#line 199 "a.y"
    { ((*yyvalp).node) = opr(SCOPE, 2 ,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)) ; }
    break;

  case 42:
#line 209 "a.y"
    { ((*yyvalp).node) = opr(FUNC_OP,3, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 43:
#line 210 "a.y"
    { ((*yyvalp).node) = opr(FUNC_OP, 3, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 44:
#line 214 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 45:
#line 215 "a.y"
    { char buf[1024] = "~"; strcat(buf, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)->var_obj->name);  ((*yyvalp).node) = varWithNameNeedFree(strdup(buf)); }
    break;

  case 46:
#line 216 "a.y"
    { ((*yyvalp).node) = var((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.sValue)); }
    break;

  case 47:
#line 220 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 48:
#line 221 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node); }
    break;

  case 49:
#line 226 "a.y"
    { ((*yyvalp).node) = opr(FUNC_OP, 3, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 50:
#line 230 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 51:
#line 231 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node); }
    break;

  case 52:
#line 232 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 53:
#line 237 "a.y"
    { ((*yyvalp).node) = opr(VAR_DECLAR , 2, NULL, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node) ); }
    break;

  case 54:
#line 238 "a.y"
    { ((*yyvalp).node) = opr(VAR_DECLAR, 2, intNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.iValue)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node) ); }
    break;

  case 55:
#line 242 "a.y"
    { ((*yyvalp).iValue) = yytokentype::KEY_CONST; }
    break;

  case 56:
#line 243 "a.y"
    { ((*yyvalp).iValue) = yytokentype::KEY_LOCAL; }
    break;

  case 57:
#line 247 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node)); }
    break;

  case 58:
#line 248 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 59:
#line 252 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 60:
#line 253 "a.y"
    { ((*yyvalp).node) = arrayNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.node)->var_obj->name, -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 61:
#line 258 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 62:
#line 259 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 63:
#line 264 "a.y"
    { ((*yyvalp).node) = opr(OPR_START_IF, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node)); }
    break;

  case 64:
#line 265 "a.y"
    { ((*yyvalp).node) = opr(KEY_SWITCH, 2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (7))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((6) - (7))].yystate.yysemantics.yysval.node)); pretreatSwitch( ((*yyvalp).node) ) ; }
    break;

  case 65:
#line 269 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 66:
#line 270 "a.y"
    { ((*yyvalp).node) = opr(OPR_IF_ELSE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 67:
#line 274 "a.y"
    { ((*yyvalp).node) = opr(KEY_IF ,2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.node)) ; }
    break;

  case 68:
#line 278 "a.y"
    { ((*yyvalp).node) =  opr(OPR_IF_ELSE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 69:
#line 279 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 70:
#line 283 "a.y"
    { ((*yyvalp).node) = opr(OPR_IF_ELSE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node), NULL); }
    break;

  case 71:
#line 284 "a.y"
    { ((*yyvalp).node) =  opr(OPR_IF_ELSE, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 72:
#line 288 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node); }
    break;

  case 73:
#line 292 "a.y"
    { ((*yyvalp).node) = opr( KEY_ELSE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 74:
#line 296 "a.y"
    { ((*yyvalp).node) = opr(CASE_LIST , 1 ,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node) ); }
    break;

  case 75:
#line 297 "a.y"
    { ((*yyvalp).node) = opr(CASE_LIST , 2 ,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node) ); }
    break;

  case 76:
#line 301 "a.y"
    { ((*yyvalp).node) = opr(KEY_CASE, 2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 77:
#line 302 "a.y"
    { ((*yyvalp).node) = opr(KEY_DEFAULT , 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 78:
#line 306 "a.y"
    { ((*yyvalp).node) = opr(KEY_WHILE , 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (5))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (5))].yystate.yysemantics.yysval.node) ); }
    break;

  case 79:
#line 307 "a.y"
    { ((*yyvalp).node) = opr(KEY_FOR,4,(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (9))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((5) - (9))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((7) - (9))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((9) - (9))].yystate.yysemantics.yysval.node)); }
    break;

  case 80:
#line 311 "a.y"
    { ((*yyvalp).node) = intNode(1);  }
    break;

  case 81:
#line 312 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 82:
#line 316 "a.y"
    { ((*yyvalp).node) = NULL ; }
    break;

  case 83:
#line 317 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 84:
#line 318 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 85:
#line 323 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 86:
#line 329 "a.y"
    { ((*yyvalp).node) = NULL ; }
    break;

  case 87:
#line 330 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 88:
#line 331 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 89:
#line 336 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 90:
#line 337 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 91:
#line 342 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node); }
    break;

  case 92:
#line 346 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 93:
#line 347 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 94:
#line 348 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 95:
#line 349 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 96:
#line 350 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 97:
#line 351 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 98:
#line 352 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 99:
#line 353 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 100:
#line 354 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 101:
#line 359 "a.y"
    { ((*yyvalp).node) = opr(KEY_RESTRICT,0);}
    break;

  case 102:
#line 360 "a.y"
    { ((*yyvalp).node) = opr(KEY_RESTRICT,1,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 103:
#line 364 "a.y"
    { ((*yyvalp).node) = opr(KEY_BREAK, 0); }
    break;

  case 104:
#line 365 "a.y"
    { ((*yyvalp).node) = opr(KEY_RETURN , 0); }
    break;

  case 105:
#line 366 "a.y"
    { ((*yyvalp).node) = opr(KEY_RETURN , 1 ,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node));}
    break;

  case 106:
#line 367 "a.y"
    { ((*yyvalp).node) = opr(KEY_CONTINUE,0); }
    break;

  case 107:
#line 372 "a.y"
    { ((*yyvalp).node) = opr(FUNC_CALL, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 108:
#line 373 "a.y"
    { ((*yyvalp).node) = opr(CLAXX_FUNC_CALL, 3, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((4) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 109:
#line 378 "a.y"
    { ((*yyvalp).node) = opr('+',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 110:
#line 379 "a.y"
    { ((*yyvalp).node) = opr('-',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 111:
#line 380 "a.y"
    { ((*yyvalp).node) = opr('*',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 112:
#line 381 "a.y"
    { ((*yyvalp).node) = opr('/',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 113:
#line 382 "a.y"
    { ((*yyvalp).node) = opr('%',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 114:
#line 383 "a.y"
    { ((*yyvalp).node) = opr('&',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 115:
#line 384 "a.y"
    { ((*yyvalp).node) = opr('|',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 116:
#line 385 "a.y"
    { ((*yyvalp).node) = opr('^',2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 117:
#line 386 "a.y"
    { ((*yyvalp).node) = opr(LEFT_SHIFT,2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 118:
#line 387 "a.y"
    { ((*yyvalp).node) = opr(RIGHT_SHIFT,2,(((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 119:
#line 388 "a.y"
    { ((*yyvalp).node) = opr('~',1,(((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 120:
#line 393 "a.y"
    { ((*yyvalp).node) = opr(KEY_NEW, 2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 121:
#line 397 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 122:
#line 398 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node); }
    break;

  case 123:
#line 402 "a.y"
    { ((*yyvalp).node) = opr(OPR_ARGS_LIST, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node)); }
    break;

  case 124:
#line 403 "a.y"
    { ((*yyvalp).node) = opr(OPR_ARGS_LIST, 2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 125:
#line 407 "a.y"
    { ((*yyvalp).node) = opr(KEY_DELETE, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 126:
#line 413 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 127:
#line 414 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 128:
#line 415 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 129:
#line 416 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 130:
#line 417 "a.y"
    { ((*yyvalp).node) = opr((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.iValue), 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 131:
#line 421 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 132:
#line 422 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 133:
#line 427 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 134:
#line 428 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 135:
#line 433 "a.y"
    { ((*yyvalp).node) = opr(KEY_IS ,2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 136:
#line 437 "a.y"
    { ((*yyvalp).node) = opr('!', 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 137:
#line 442 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 138:
#line 443 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 139:
#line 447 "a.y"
    { ((*yyvalp).node) = opr((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.iValue), 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 140:
#line 451 "a.y"
    { ((*yyvalp).node) = opr((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.iValue), 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 141:
#line 455 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 142:
#line 456 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 143:
#line 457 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 144:
#line 458 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 145:
#line 459 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 146:
#line 460 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 147:
#line 464 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 148:
#line 465 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 149:
#line 470 "a.y"
    { ((*yyvalp).node) = opr(OPR_INC_DEC,2, intNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.iValue)), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node) ); }
    break;

  case 150:
#line 471 "a.y"
    { ((*yyvalp).node) = opr(OPR_INC_DEC, 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), intNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.iValue))); }
    break;

  case 151:
#line 475 "a.y"
    { ((*yyvalp).iValue) = yytokentype::INC_OP; }
    break;

  case 152:
#line 476 "a.y"
    { ((*yyvalp).iValue) = yytokentype::DEC_OP; }
    break;

  case 153:
#line 482 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 154:
#line 483 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 155:
#line 484 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 156:
#line 492 "a.y"
    { ((*yyvalp).node) = objectArrayElementNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (4))].yystate.yysemantics.yysval.node), -1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (4))].yystate.yysemantics.yysval.node)); }
    break;

  case 157:
#line 497 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 158:
#line 498 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node) ;}
    break;

  case 159:
#line 502 "a.y"
    { ((*yyvalp).node) = opr('=',2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node),(((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node) ); }
    break;

  case 160:
#line 506 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 161:
#line 507 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 162:
#line 511 "a.y"
    { ((*yyvalp).node) = opr((((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.iValue), 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 163:
#line 515 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 164:
#line 516 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 165:
#line 517 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 166:
#line 518 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 167:
#line 519 "a.y"
    { ((*yyvalp).iValue) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue); }
    break;

  case 168:
#line 524 "a.y"
    { ((*yyvalp).node) = NULL; }
    break;

  case 169:
#line 525 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node); }
    break;

  case 170:
#line 529 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node)); }
    break;

  case 171:
#line 530 "a.y"
    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (2))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node)); }
    break;

  case 172:
#line 534 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 173:
#line 535 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 174:
#line 536 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 175:
#line 537 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 176:
#line 542 "a.y"
    { ((*yyvalp).node) = opr('+', 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 177:
#line 543 "a.y"
    { ((*yyvalp).node) = opr('+', 2, (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 178:
#line 547 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 179:
#line 548 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 180:
#line 549 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 181:
#line 550 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 182:
#line 551 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 183:
#line 555 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (3))].yystate.yysemantics.yysval.node); }
    break;

  case 184:
#line 561 "a.y"
    { ((*yyvalp).node) = var((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.sValue)); }
    break;

  case 185:
#line 565 "a.y"
    { ((*yyvalp).node) = opr(OPR_MULTIPLE_ID , 1 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node) );}
    break;

  case 186:
#line 566 "a.y"
    { ((*yyvalp).node) = opr(OPR_MULTIPLE_ID , 2 , (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (3))].yystate.yysemantics.yysval.node), (((yyGLRStackItem const *)yyvsp)[YYFILL ((3) - (3))].yystate.yysemantics.yysval.node)); }
    break;

  case 187:
#line 570 "a.y"
    { ((*yyvalp).node) = intNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue)); }
    break;

  case 188:
#line 574 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 189:
#line 575 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 190:
#line 579 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 191:
#line 580 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 192:
#line 584 "a.y"
    { ((*yyvalp).node) = intNode((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.iValue)); }
    break;

  case 193:
#line 588 "a.y"
    { ((*yyvalp).node) = number((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.dValue)); }
    break;

  case 194:
#line 592 "a.y"
    { ((*yyvalp).node) = opr(UMINUS, 1, (((yyGLRStackItem const *)yyvsp)[YYFILL ((2) - (2))].yystate.yysemantics.yysval.node) ); }
    break;

  case 195:
#line 596 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 196:
#line 597 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 197:
#line 598 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 198:
#line 599 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 199:
#line 603 "a.y"
    { ((*yyvalp).node) = string((((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.sValue)); }
    break;

  case 200:
#line 607 "a.y"
    { ((*yyvalp).node) = xnull(); }
    break;

  case 201:
#line 614 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 202:
#line 615 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 203:
#line 616 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 204:
#line 617 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 205:
#line 618 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 206:
#line 622 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 207:
#line 623 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 208:
#line 624 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 209:
#line 625 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 210:
#line 629 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 211:
#line 630 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 212:
#line 631 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 213:
#line 635 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 214:
#line 636 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 215:
#line 637 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 216:
#line 638 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 217:
#line 642 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 218:
#line 646 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 219:
#line 647 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 220:
#line 648 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 221:
#line 652 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 222:
#line 653 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 223:
#line 662 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 224:
#line 663 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 225:
#line 664 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;

  case 226:
#line 665 "a.y"
    { ((*yyvalp).node) = (((yyGLRStackItem const *)yyvsp)[YYFILL ((1) - (1))].yystate.yysemantics.yysval.node); }
    break;


/* Line 930 of glr.c.  */
#line 2528 "y.tab.c"
      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


/*ARGSUSED*/ static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {
      
      default: break;
    }
}

			      /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
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

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
		&yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
	{
	  if (yys->yysemantics.yyfirstVal)
	    YYFPRINTF (stderr, "%s unresolved ", yymsg);
	  else
	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
	  yy_symbol_print (stderr, yystos[yys->yylrState],
			   NULL);
	  YYFPRINTF (stderr, "\n");
	}
#endif

      if (yys->yysemantics.yyfirstVal)
	{
	  yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
	  yyGLRState *yyrh;
	  int yyn;
	  for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
	       yyn > 0;
	       yyrh = yyrh->yypred, yyn -= 1)
	    yydestroyGLRState (yymsg, yyrh);
	}
    }
}

/** Left-hand-side symbol for rule #RULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yyis_pact_ninf(yystate) \
  ((yystate) == YYPACT_NINF)

/** True iff LR state STATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yyis_pact_ninf (yypact[yystate]);
}

/** The default reduction for STATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yyis_table_ninf(yytable_value) \
  YYID (0)

/** Set *YYACTION to the action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
 *  conflicting reductions.
 */
static inline void
yygetLRActions (yyStateNum yystate, int yytoken,
		int* yyaction, const short int** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyaction = -yydefact[yystate];
      *yyconflicts = yyconfl;
    }
  else if (! yyis_table_ninf (yytable[yyindex]))
    {
      *yyaction = yytable[yyindex];
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
  else
    {
      *yyaction = 0;
      *yyconflicts = yyconfl + yyconflp[yyindex];
    }
}

static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
{
  int yyr;
  yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yylhs - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

				/* GLRStates */

/** Return a fresh GLRStackItem.  Callers should call
 * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 * headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  RULENUM on the semantic values in RHS to the list of
 *  alternative actions for STATE.  Assumes that RHS comes from
 *  stack #K of *STACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
		     yyGLRState* rhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  yynewOption->yystate = rhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

				/* GLRStacks */

/** Initialize SET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = NULL;
  yyset->yylookaheadNeeds =
    (yybool*) YYMALLOC (16 * sizeof yyset->yylookaheadNeeds[0]);
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize STACK to a single empty stack, with total maximum
 *  capacity for all stacks of SIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, size_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems =
    (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystackp->yynextFree[0]);
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
  &((YYTOITEMS) - ((YYFROMITEMS) - (yyGLRStackItem*) (YYX)))->YYTYPE

/** If STACK is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  size_t yysize, yynewSize;
  size_t yyn;
  yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*(yybool *) yyp0)
	{
	  yyGLRState* yys0 = &yyp0->yystate;
	  yyGLRState* yys1 = &yyp1->yystate;
	  if (yys0->yypred != NULL)
	    yys1->yypred =
	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != NULL)
	    yys1->yysemantics.yyfirstVal =
	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
	}
      else
	{
	  yySemanticOption* yyv0 = &yyp0->yyoption;
	  yySemanticOption* yyv1 = &yyp1->yyoption;
	  if (yyv0->yystate != NULL)
	    yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
	  if (yyv0->yynext != NULL)
	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
	}
    }
  if (yystackp->yysplitPoint != NULL)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
				 yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != NULL)
      yystackp->yytops.yystates[yyn] =
	YYRELOC (yystackp->yyitems, yynewItems,
		 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that S is a GLRState somewhere on STACK, update the
 *  splitpoint of STACK, if needed, so that it is at least as deep as
 *  S.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != NULL && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #K in STACK.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != NULL)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = NULL;
}

/** Undelete the last stack that was marked as deleted.  Can only be
    done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == NULL || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = NULL;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  size_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == NULL)
	{
	  if (yyi == yyj)
	    {
	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
	    }
	  yystackp->yytops.yysize -= 1;
	}
      else
	{
	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
	  /* In the current implementation, it's unnecessary to copy
	     yystackp->yytops.yylookaheadNeeds[yyi] since, after
	     yyremoveDeletes returns, the parser immediately either enters
	     deterministic operation or shifts a token.  However, it doesn't
	     hurt, and the code might evolve to need it.  */
	  yystackp->yytops.yylookaheadNeeds[yyj] =
	    yystackp->yytops.yylookaheadNeeds[yyi];
	  if (yyj != yyi)
	    {
	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
			  (unsigned long int) yyi, (unsigned long int) yyj));
	    }
	  yyj += 1;
	}
      yyi += 1;
    }
}

/** Shift to a new state on stack #K of STACK, corresponding to LR state
 * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
static inline void
yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
	    size_t yyposn,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #K of YYSTACK, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = NULL;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, rhs, yyrule);
}

/** Pop the symbols consumed by reduction #RULE from the top of stack
 *  #K of STACK, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *VALP to the resulting value,
 *  and *LOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	    YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == NULL)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* rhs = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
      YYASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, rhs,
			   yyvalp, yylocp, yystackp);
    }
  else
    {
      /* At present, doAction is never called in nondeterministic
       * mode, so this branch is never taken.  It is here in
       * anticipation of a future feature that will allow immediate
       * evaluation of selected actions in nondeterministic mode.  */
      int yyi;
      yyGLRState* yys;
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
	= yystackp->yytops.yystates[yyk];
      for (yyi = 0; yyi < yynrhs; yyi += 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
    }
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)		\
do {					\
  if (yydebug)				\
    yy_reduce_print Args;		\
} while (YYID (0))

/*----------------------------------------------------------.
| Report that the RULE is going to be reduced on stack #K.  |
`----------------------------------------------------------*/

/*ARGSUSED*/ static inline void
yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  int yynrhs = yyrhsLength (yyrule);
  yybool yynormal __attribute__ ((__unused__)) =
    (yystackp->yysplitPoint == NULL);
  yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystackp->yytops.yystates[yyk];
  int yylow = 1;
  int yyi;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
	     (unsigned long int) yyk, yyrule - 1,
	     (unsigned long int) yyrline[yyrule]);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(((yyGLRStackItem const *)yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yysemantics.yysval)
		       		       );
      fprintf (stderr, "\n");
    }
}
#endif

/** Pop items off stack #K of STACK according to grammar rule RULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with RULE and store its value with the
 *  newly pushed state, if FORCEEVAL or if STACK is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #K from
 *  the STACK.  In this case, the (necessarily deferred) semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
	     yybool yyforceEval)
{
  size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == NULL)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YY_REDUCE_PRINT ((yystackp, yyk, yyrule, &yysval, &yyloc));
      YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval,
			 &yyloc));
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
				 yylhsNonterm (yyrule)),
		  yyposn, &yysval, &yyloc);
    }
  else
    {
      size_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
	   0 < yyn; yyn -= 1)
	{
	  yys = yys->yypred;
	  YYASSERT (yys);
	}
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YYDPRINTF ((stderr,
		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
	if (yyi != yyk && yystackp->yytops.yystates[yyi] != NULL)
	  {
	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
	    yyp = yystackp->yytops.yystates[yyi];
	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
	      {
		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
		  {
		    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
		    yymarkStackDeleted (yystackp, yyk);
		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
				(unsigned long int) yyk,
				(unsigned long int) yyi));
		    return yyok;
		  }
		yyp = yyp->yypred;
	      }
	  }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static size_t
yysplitStack (yyGLRStack* yystackp, size_t yyk)
{
  if (yystackp->yysplitPoint == NULL)
    {
      YYASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yysize >= yystackp->yytops.yycapacity)
    {
      yyGLRState** yynewStates;
      yybool* yynewLookaheadNeeds;

      yynewStates = NULL;

      if (yystackp->yytops.yycapacity
	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      yynewStates =
	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
				  (yystackp->yytops.yycapacity
				   * sizeof yynewStates[0]));
      if (yynewStates == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yystates = yynewStates;

      yynewLookaheadNeeds =
	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
			     (yystackp->yytops.yycapacity
			      * sizeof yynewLookaheadNeeds[0]));
      if (yynewLookaheadNeeds == NULL)
	yyMemoryExhausted (yystackp);
      yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize-1;
}

/** True iff Y0 and Y1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
	   yyn = yyrhsLength (yyy0->yyrule);
	   yyn > 0;
	   yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
	if (yys0->yyposn != yys1->yyposn)
	  return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (Y0,Y1), destructively merge the
 *  alternative semantic values for the RHS-symbols of Y1 and Y0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       yyn > 0;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
	break;
      else if (yys0->yyresolved)
	{
	  yys1->yyresolved = yytrue;
	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
	}
      else if (yys1->yyresolved)
	{
	  yys0->yyresolved = yytrue;
	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
	}
      else
	{
	  yySemanticOption** yyz0p;
	  yySemanticOption* yyz1;
	  yyz0p = &yys0->yysemantics.yyfirstVal;
	  yyz1 = yys1->yysemantics.yyfirstVal;
	  while (YYID (yytrue))
	    {
	      if (yyz1 == *yyz0p || yyz1 == NULL)
		break;
	      else if (*yyz0p == NULL)
		{
		  *yyz0p = yyz1;
		  break;
		}
	      else if (*yyz0p < yyz1)
		{
		  yySemanticOption* yyz = *yyz0p;
		  *yyz0p = yyz1;
		  yyz1 = yyz1->yynext;
		  (*yyz0p)->yynext = yyz;
		}
	      yyz0p = &(*yyz0p)->yynext;
	    }
	  yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
	}
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
	return 0;
      else
	return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
				   yyGLRStack* yystackp);


/** Resolve the previous N states starting at and including state S.  If result
 *  != yyok, some states may have been left unresolved possibly with empty
 *  semantic option chains.  Regardless of whether result = yyok, each state
 *  has been left with consistent data so that yydestroyGLRState can be invoked
 *  if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
		 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YYASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
	YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of OPT, perform its user action, and return
 *  the semantic value and location.  Regardless of whether result = yyok, all
 *  RHS states have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
		 YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs;
  int yychar_current;
  YYSTYPE yylval_current;
  YYLTYPE yylloc_current;
  YYRESULTTAG yyflag;

  yynrhs = yyrhsLength (yyopt->yyrule);
  yyflag = yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
	yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  yychar_current = yychar;
  yylval_current = yylval;
  yylloc_current = yylloc;
  yychar = yyopt->yyrawchar;
  yylval = yyopt->yyval;
  yylloc = yyopt->yyloc;
  yyflag = yyuserAction (yyopt->yyrule, yynrhs,
			   yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
			   yyvalp, yylocp, yystackp);
  yychar = yychar_current;
  yylval = yylval_current;
  yylloc = yylloc_current;
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == NULL)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1);
  else
    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
	       yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
	       (unsigned long int) yyx->yystate->yyposn);
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
	{
	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
	  else
	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
		       (unsigned long int) yystates[yyi]->yyposn);
	}
      else
	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

/*ARGSUSED*/ static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
		   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YYFPRINTF (stderr, "Ambiguity detected.\n");
  YYFPRINTF (stderr, "Option 1,\n");
  yyreportTree (yyx0, 2);
  YYFPRINTF (stderr, "\nOption 2,\n");
  yyreportTree (yyx1, 2);
  YYFPRINTF (stderr, "\n");
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Starting at and including state S1, resolve the location for each of the
 *  previous N1 states that is unresolved.  The first semantic option of a state
 *  is always chosen.  */
static void
yyresolveLocations (yyGLRState* yys1, int yyn1,
		    yyGLRStack *yystackp)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp);
      if (!yys1->yyresolved)
	{
	  yySemanticOption *yyoption;
	  yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
	  int yynrhs;
	  int yychar_current;
	  YYSTYPE yylval_current;
	  YYLTYPE yylloc_current;
	  yyoption = yys1->yysemantics.yyfirstVal;
	  YYASSERT (yyoption != NULL);
	  yynrhs = yyrhsLength (yyoption->yyrule);
	  if (yynrhs > 0)
	    {
	      yyGLRState *yys;
	      int yyn;
	      yyresolveLocations (yyoption->yystate, yynrhs,
				  yystackp);
	      for (yys = yyoption->yystate, yyn = yynrhs;
		   yyn > 0;
		   yys = yys->yypred, yyn -= 1)
		yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
	    }
	  else
	    {
	      /* Both yyresolveAction and yyresolveLocations traverse the GSS
		 in reverse rightmost order.  It is only necessary to invoke
		 yyresolveLocations on a subforest for which yyresolveAction
		 would have been invoked next had an ambiguity not been
		 detected.  Thus the location of the previous state (but not
		 necessarily the previous state itself) is guaranteed to be
		 resolved already.  */
	      yyGLRState *yyprevious = yyoption->yystate;
	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
	    }
	  yychar_current = yychar;
	  yylval_current = yylval;
	  yylloc_current = yylloc;
	  yychar = yyoption->yyrawchar;
	  yylval = yyoption->yyval;
	  yylloc = yyoption->yyloc;
	  YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
	  yychar = yychar_current;
	  yylval = yylval_current;
	  yylloc = yylloc_current;
	}
    }
}

/** Resolve the ambiguity represented in state S, perform the indicated
 *  actions, and set the semantic value of S.  If result != yyok, the chain of
 *  semantic options in S has been cleared instead or it has been left
 *  unmodified except that redundant options may have been removed.  Regardless
 *  of whether result = yyok, S has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest;
  yySemanticOption** yypp;
  yybool yymerge;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  yybest = yyoptionList;
  yymerge = yyfalse;
  for (yypp = &yyoptionList->yynext; *yypp != NULL; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
	{
	  yymergeOptionSets (yybest, yyp);
	  *yypp = yyp->yynext;
	}
      else
	{
	  switch (yypreference (yybest, yyp))
	    {
	    case 0:
	      yyresolveLocations (yys, 1, yystackp);
	      return yyreportAmbiguity (yybest, yyp);
	      break;
	    case 1:
	      yymerge = yytrue;
	      break;
	    case 2:
	      break;
	    case 3:
	      yybest = yyp;
	      yymerge = yyfalse;
	      break;
	    default:
	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
		 but some compilers complain if the default case is
		 omitted.  */
	      break;
	    }
	  yypp = &yyp->yynext;
	}
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval,
				yylocp);
      if (yyflag == yyok)
	for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
	  {
	    if (yyprec == yydprec[yyp->yyrule])
	      {
		YYSTYPE yysval_other;
		YYLTYPE yydummy;
		yyflag = yyresolveAction (yyp, yystackp, &yysval_other,
					  &yydummy);
		if (yyflag != yyok)
		  {
		    yydestruct ("Cleanup: discarding incompletely merged value for",
				yystos[yys->yylrState],
				&yysval);
		    break;
		  }
		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
	      }
	  }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = NULL;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != NULL)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
	   yys != yystackp->yysplitPoint;
	   yys = yys->yypred, yyn += 1)
	continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
			     ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == NULL)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = ((yyGLRStackItem*) yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = NULL;
  yystackp->yylastDeleted = NULL;

  while (yyr != NULL)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
		   size_t yyposn)
{
  int yyaction;
  const short int* yyconflicts;
  yyRuleNum yyrule;

  while (yystackp->yytops.yystates[yyk] != NULL)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
		  (unsigned long int) yyk, yystate));

      YYASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
	{
	  yyrule = yydefaultAction (yystate);
	  if (yyrule == 0)
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      return yyok;
	    }
	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse));
	}
      else
	{
	  yySymbol yytoken;
	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
	  if (yychar == YYEMPTY)
	    {
	      YYDPRINTF ((stderr, "Reading a token: "));
	      yychar = YYLEX;
	      yytoken = YYTRANSLATE (yychar);
	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	    }
	  else
	    yytoken = YYTRANSLATE (yychar);
	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);

	  while (*yyconflicts != 0)
	    {
	      size_t yynewStack = yysplitStack (yystackp, yyk);
	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
			  (unsigned long int) yynewStack,
			  (unsigned long int) yyk));
	      YYCHK (yyglrReduce (yystackp, yynewStack,
				  *yyconflicts, yyfalse));
	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
					yyposn));
	      yyconflicts += 1;
	    }

	  if (yyisShiftAction (yyaction))
	    break;
	  else if (yyisErrorAction (yyaction))
	    {
	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
			  (unsigned long int) yyk));
	      yymarkStackDeleted (yystackp, yyk);
	      break;
	    }
	  else
	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
				yyfalse));
	}
    }
  return yyok;
}

/*ARGSUSED*/ static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 0)
    {
#if YYERROR_VERBOSE
      int yyn;
      yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      if (YYPACT_NINF < yyn && yyn <= YYLAST)
	{
	  yySymbol yytoken = YYTRANSLATE (yychar);
	  size_t yysize0 = yytnamerr (NULL, yytokenName (yytoken));
	  size_t yysize = yysize0;
	  size_t yysize1;
	  yybool yysize_overflow = yyfalse;
	  char* yymsg = NULL;
	  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;
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

	  yyarg[0] = yytokenName (yytoken);
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
		yyarg[yycount++] = yytokenName (yyx);
		yysize1 = yysize + yytnamerr (NULL, yytokenName (yyx));
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + strlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow)
	    yymsg = (char *) YYMALLOC (yysize);

	  if (yymsg)
	    {
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYFREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      yyMemoryExhausted (yystackp);
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
      yynerrs += 1;
    }
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the look-ahead.  */
/*ARGSUSED*/ static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  size_t yyk;
  int yyj;

  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (YYID (yytrue))
      {
	yySymbol yytoken;
	if (yychar == YYEOF)
	  yyFail (yystackp, NULL);
	if (yychar != YYEMPTY)
	  {
	    yytoken = YYTRANSLATE (yychar);
	    yydestruct ("Error: discarding",
			yytoken, &yylval);
	  }
	YYDPRINTF ((stderr, "Reading a token: "));
	yychar = YYLEX;
	yytoken = YYTRANSLATE (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
	if (yyis_pact_ninf (yyj))
	  return;
	yyj += yytoken;
	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
	  {
	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
	      return;
	  }
	else if (yytable[yyj] != 0 && ! yyis_table_ninf (yytable[yyj]))
	  return;
      }

  /* Reduce to one stack.  */
  for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
    if (yystackp->yytops.yystates[yyk] != NULL)
      break;
  if (yyk >= yystackp->yytops.yysize)
    yyFail (yystackp, NULL);
  for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
    yymarkStackDeleted (yystackp, yyk);
  yyremoveDeletes (yystackp);
  yycompressStack (yystackp);

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != NULL)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      yyj = yypact[yys->yylrState];
      if (! yyis_pact_ninf (yyj))
	{
	  yyj += YYTERROR;
	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
	      && yyisShiftAction (yytable[yyj]))
	    {
	      /* Shift the error token having adjusted its location.  */
	      YYLTYPE yyerrloc;
	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
			       &yylval, &yyerrloc);
	      yyglrShift (yystackp, 0, yytable[yyj],
			  yys->yyposn, &yylval, &yyerrloc);
	      yys = yystackp->yytops.yystates[0];
	      break;
	    }
	}

      yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == NULL)
    yyFail (yystackp, NULL);
}

#define YYCHK1(YYE)							     \
  do {									     \
    switch (YYE) {							     \
    case yyok:								     \
      break;								     \
    case yyabort:							     \
      goto yyabortlab;							     \
    case yyaccept:							     \
      goto yyacceptlab;							     \
    case yyerr:								     \
      goto yyuser_error;						     \
    default:								     \
      goto yybuglab;							     \
    }									     \
  } while (YYID (0))


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  size_t yyposn;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (YYID (yytrue))
    {
      /* For efficiency, we have two loops, the first of which is
	 specialized to deterministic operation (single stack, no
	 potential ambiguity).  */
      /* Standard mode */
      while (YYID (yytrue))
	{
	  yyRuleNum yyrule;
	  int yyaction;
	  const short int* yyconflicts;

	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
	  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
	  if (yystate == YYFINAL)
	    goto yyacceptlab;
	  if (yyisDefaultedState (yystate))
	    {
	      yyrule = yydefaultAction (yystate);
	      if (yyrule == 0)
		{

		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
	    }
	  else
	    {
	      yySymbol yytoken;
	      if (yychar == YYEMPTY)
		{
		  YYDPRINTF ((stderr, "Reading a token: "));
		  yychar = YYLEX;
		  yytoken = YYTRANSLATE (yychar);
		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
		}
	      else
		yytoken = YYTRANSLATE (yychar);
	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
	      if (*yyconflicts != 0)
		break;
	      if (yyisShiftAction (yyaction))
		{
		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
		  if (yychar != YYEOF)
		    yychar = YYEMPTY;
		  yyposn += 1;
		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
		  if (0 < yystack.yyerrState)
		    yystack.yyerrState -= 1;
		}
	      else if (yyisErrorAction (yyaction))
		{

		  yyreportSyntaxError (&yystack);
		  goto yyuser_error;
		}
	      else
		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
	    }
	}

      while (YYID (yytrue))
	{
	  yySymbol yytoken_to_shift;
	  size_t yys;

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

	  /* yyprocessOneStack returns one of three things:

	      - An error flag.  If the caller is yyprocessOneStack, it
		immediately returns as well.  When the caller is finally
		yyparse, it jumps to an error label via YYCHK1.

	      - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
		(&yystack, yys), which sets the top state of yys to NULL.  Thus,
		yyparse's following invocation of yyremoveDeletes will remove
		the stack.

	      - yyok, when ready to shift a token.

	     Except in the first case, yyparse will invoke yyremoveDeletes and
	     then shift the next token onto all remaining stacks.  This
	     synchronization of the shift (that is, after all preceding
	     reductions on all stacks) helps prevent double destructor calls
	     on yylval in the event of memory exhaustion.  */

	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
	  yyremoveDeletes (&yystack);
	  if (yystack.yytops.yysize == 0)
	    {
	      yyundeleteLastStack (&yystack);
	      if (yystack.yytops.yysize == 0)
		yyFail (&yystack, YY_("syntax error"));
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));

	      yyreportSyntaxError (&yystack);
	      goto yyuser_error;
	    }

	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
	     a copy of yylval will already be on stack 0 in the event of a
	     failure in the following loop.  Thus, yychar is set to YYEMPTY
	     before the loop to make sure the user destructor for yylval isn't
	     called twice.  */
	  yytoken_to_shift = YYTRANSLATE (yychar);
	  yychar = YYEMPTY;
	  yyposn += 1;
	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
	    {
	      int yyaction;
	      const short int* yyconflicts;
	      yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
	      yygetLRActions (yystate, yytoken_to_shift, &yyaction,
			      &yyconflicts);
	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
	      yyglrShift (&yystack, yys, yyaction, yyposn,
			  &yylval, &yylloc);
	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
			  (unsigned long int) yys,
			  yystack.yytops.yystates[yys]->yylrState));
	    }

	  if (yystack.yytops.yysize == 1)
	    {
	      YYCHK1 (yyresolveStack (&yystack));
	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
	      yycompressStack (&yystack);
	      break;
	    }
	}
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YYASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
		YYTRANSLATE (yychar),
		&yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
	{
	  size_t yysize = yystack.yytops.yysize;
	  size_t yyk;
	  for (yyk = 0; yyk < yysize; yyk += 1)
	    if (yystates[yyk])
	      {
		while (yystates[yyk])
		  {
		    yyGLRState *yys = yystates[yyk];
		    yydestroyGLRState ("Cleanup: popping", yys);
		    yystates[yyk] = yys->yypred;
		    yystack.yynextFree -= 1;
		    yystack.yyspaceLeft += 1;
		  }
		break;
	      }
	}
      yyfreeGLRStack (&yystack);
    }

  /* Make sure YYID is used.  */
  return YYID (yyresult);
}

/* DEBUGGING ONLY */
#ifdef YYDEBUG
static void yypstack (yyGLRStack* yystackp, size_t yyk)
  __attribute__ ((__unused__));
static void yypdumpstack (yyGLRStack* yystackp) __attribute__ ((__unused__));

static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      fprintf (stderr, " -> ");
    }
  fprintf (stderr, "%d@%lu", yys->yylrState, (unsigned long int) yys->yyposn);
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == NULL)
    fprintf (stderr, "<null>");
  else
    yy_yypstack (yyst);
  fprintf (stderr, "\n");
}

static void
yypstack (yyGLRStack* yystackp, size_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

#define YYINDEX(YYX)							     \
    ((YYX) == NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)


static void
yypdumpstack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yyp;
  size_t yyi;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystackp->yyitems));
      if (*(yybool *) yyp)
	{
	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
		   (unsigned long int) yyp->yystate.yyposn,
		   (long int) YYINDEX (yyp->yystate.yypred));
	  if (! yyp->yystate.yyresolved)
	    fprintf (stderr, ", firstVal: %ld",
		     (long int) YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
	}
      else
	{
	  fprintf (stderr, "Option. rule: %d, state: %ld, next: %ld",
		   yyp->yyoption.yyrule - 1,
		   (long int) YYINDEX (yyp->yyoption.yystate),
		   (long int) YYINDEX (yyp->yyoption.yynext));
	}
      fprintf (stderr, "\n");
    }
  fprintf (stderr, "Tops:");
  for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
    fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
	     (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
  fprintf (stderr, "\n");
}
#endif


#line 668 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}

