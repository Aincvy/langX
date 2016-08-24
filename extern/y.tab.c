#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "a.y"

#include <stdio.h>
#include <string>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

extern int yyget_lineno(void);
extern int column; 
extern char * yytext;

/* 正在解析的文件 的文件名*/
const char * parseFileName=NULL;

#line 22 "a.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 54 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define TDOUBLE 257
#define TBOOL 258
#define IDENTIFIER 259
#define TSTRING 260
#define OP_CALC 261
#define AND_OP 262
#define OR_OP 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define FUNC_OP 268
#define INC_OP 269
#define DEC_OP 270
#define FUNC_CALL 271
#define VAR_DECLAR 272
#define RESTRICT 273
#define THIS 274
#define EXTENDS 275
#define ADD_EQ 276
#define SUB_EQ 277
#define MUL_EQ 278
#define DIV_EQ 279
#define AUTO 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define FOR 284
#define DELETE 285
#define BREAK 286
#define RETURN 287
#define SWITCH 288
#define CASE 289
#define DEFAULT 290
#define CASE_LIST 291
#define CLAXX_BODY 292
#define NEW 293
#define CLAXX_MEMBER 294
#define CLAXX_FUNC_CALL 295
#define XNULL 296
#define NONASSOC 297
#define IFX 298
#define UMINUS 299
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   50,   50,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   49,   49,   35,   35,   36,   36,   36,   43,
   43,   43,   44,   44,   37,   37,   37,   37,   39,   39,
   39,   39,   40,   40,   40,    5,   45,   45,   46,   46,
   46,    7,    7,    6,    6,    3,    3,    8,    8,    8,
   32,   32,   33,   33,    9,    9,   12,   12,   12,   12,
    4,    4,    4,    4,    4,    4,    4,   42,   42,   24,
   24,   24,   16,   16,   47,   47,   48,   48,   17,   17,
   17,   17,   17,   17,   17,   11,   11,   18,   18,   19,
   14,   14,   14,   14,   31,   31,   31,   31,   31,   25,
   26,   27,   28,   29,   30,   41,   23,   23,   23,   23,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   15,
   15,   15,   15,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   20,   20,   20,   20,   20,
   22,   22,   38,   38,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    4,    5,    0,    2,    1,    2,    1,    2,    1,    1,
    3,    6,    3,    3,    3,    3,    6,    3,    6,    9,
    6,    6,    8,   10,    5,    6,    0,    3,    1,    3,
    0,    2,    0,    2,    3,    1,    1,    5,    7,    7,
    1,    2,    4,    3,    5,    9,    0,    1,    1,    1,
    1,    1,    3,    1,    1,    1,    1,    1,    2,    1,
    1,    2,    4,    1,    0,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    3,    1,    1,    1,    3,
    3,    3,    3,    3,    1,    1,    1,    1,    3,    5,
    1,    1,    1,    2,    1,    1,    1,    1,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   70,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   46,   47,   61,   62,  145,   64,   65,    0,   10,    0,
  146,    0,    0,   67,    0,    0,    0,    0,    0,  102,
   69,    0,    0,    0,    0,    0,  103,    0,  105,    0,
    0,    0,  106,    0,    0,    0,    0,    0,   95,   72,
  132,    0,  126,    0,    0,    0,    0,    0,  134,  135,
    0,  101,    0,    7,    0,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    0,  140,    0,   77,    0,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  138,
    0,    0,    0,  109,  136,  137,    0,    0,   59,    0,
   58,   60,    0,   63,    0,  120,  121,    0,    0,  104,
   89,   88,    0,   96,  122,  123,    0,    0,    0,    0,
    0,    0,    0,  147,    0,  148,  149,  150,   45,    0,
  141,  142,    0,    0,  143,    0,    0,    0,  144,   39,
    0,   43,    0,    0,    0,   11,   19,   17,    0,    0,
    0,   15,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   99,    0,   97,
    0,    0,   93,   94,    0,    0,    0,    0,    0,    0,
    0,   38,    0,    0,    0,   78,   18,   12,   16,    0,
  118,  119,   43,   87,    0,  114,  115,  116,  117,  112,
  113,   55,    0,    0,    0,   90,    0,    0,  100,    0,
    0,    0,   35,   40,   36,   42,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   51,    0,   31,
   32,    0,    0,   86,   49,    0,   22,   29,    0,   43,
   50,   52,    0,   33,    0,    0,   43,    0,    0,   30,
   56,    0,    0,   34,
};
static const short yydgoto[] = {                          1,
  214,   16,   17,   18,   19,   20,  203,   21,   22,  108,
  215,  120,   23,   91,   92,  110,   94,  130,  131,   59,
   60,   25,  112,   26,   27,  113,   96,  115,  116,   99,
   67,  247,  248,   29,  171,  172,  100,   31,   32,   33,
   69,   34,   70,   35,   89,  161,  101,  102,   39,    2,
};
static const short yysindex[] = {                         0,
    0,  159,  -38, -248,   11,   34,   50,   54, -183,    0,
   70,   56, -159,    0,    0,    0,    0,   12,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  112,    0,  -16,
    0,   62, -148,    0,   51,   81, -145,  168,    2,    0,
    0, -132,  168,  168, -207,   69,    0,   94,    0, -159,
 -159,   96,    0,  -18,  125,    0,    0,    0,    0,    0,
    0,  -35,    0,    0,    0,    0,  110,   97,    0,    0,
 -159,    0,  108,    0,  -37,  -37,  -37,  -37, -159,   70,
    0, -159,   70, -159, -159,  109,   70, -109,   40,    0,
    0,    0,    0,    0,  -35,    0,    0,    0,    0,   97,
  119,  120, -121,  126,  121,   97,   62,  -13,    0,    0,
    0,   37,  -35,    0,    0,    0,    0,   -8,    0,  115,
    0,    0,   78,    0,  168,    0,    0, -159,  -37,    0,
    0,    0,  135,    0,    0,    0, -159,  125,  125,  125,
  125,  140,  168,    0,   97,    0,    0,    0,    0,    7,
    0,    0,  -43,  142,    0,  143,  146,  168,    0,    0,
  -10,    0,  -11,  168,  -77,    0,    0,    0,  133,  -21,
 -105,    0,  168,  168,  168,  177,  168,  168,  168,  168,
  168,  168,  177,  168,  163,  165,  171,    0,  166,    0,
    6,    6,    0,    0,   92,  178,  168,  168,  168,  211,
    3,    0,  247,  221, -159,    0,    0,    0,    0,  223,
    0,    0,    0,    0,  -14,    0,    0,    0,    0,    0,
    0,    0,  -52,  220,  168,    0,  168, -187,    0,  226,
  239,  242,    0,    0,    0,    0,  168,  259,  220,  283,
  177, -207,  264,  267,   52,  257, -111,    0,   59,    0,
    0,  279,  168,    0,    0,  280,    0,    0,  266,    0,
    0,    0,  282,    0,  284,  177,    0,  159,  168,    0,
    0,  159,  285,    0,
};
static const short yyrindex[] = {                         0,
    0,  334,   74,  276,    0,    0,    0,    0,    0,    0,
  277,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  456,  287,    0,    0,  235,    0,  302,    0,    0,
    0,    0,    0,    0,  290,    0,    0,  536,    0,    0,
    0,  -15,    0,    0,    0,  446,  496,  713,    0,    0,
    0,  732,    0,  745,  776,  805,    0,  863,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   24,    0,    0,
  933,    0,  949,    0,  956,    0,  983, 1005, 1033,  503,
    0,  319,    0,  100,  301,  303,    0,    0,  632,    0,
  654,  -20,  603,    0,    0,    0,  665,    0,    0,    0,
    0,    0,    0,    0,  302,    0,    0,    0,    0,    0,
    0,    0,  153,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  302,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  732,   31,    0,  545,  567,  302,    0,    0,
    0,    0,  308,    0,   -3,    0,    0,    0,    0,    0,
    0,    0,  302,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -9,    0,    0,  574,    0,
  685,  691,    0,    0,    0,    0,  302,  302,  302,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,  625,  302,    0,  302,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  302,  596,    0,    0,
    0,  327,    0,    0,    0,    0,    0,    0,   23,    0,
    0,    0,  302,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -101,  302,    0,
    0,  -96,    0,    0,
};
static const short yygindex[] = {                         0,
   25,    0,    0,    0,  -98,   14, -188,    0,    0,  -44,
 -171,  131,   16,  882,   -2,  134,  216,    0,    0,  858,
   18,  -67,  764,    0,   36,    4,  698,   26,  258,  929,
  328,    0,  139,    0,    0,  210,  236,    0,  -26,    0,
    0,    0,    0,    0,    0,    0,  846,    0,    0,    0,
};
#define YYTABLESIZE 1115
static const short yytable[] = {                        118,
   48,   38,  137,  166,  167,   28,  242,   54,   57,   40,
  137,  222,  152,  261,   62,  107,   73,   80,  107,  208,
  111,  129,   79,   54,  240,   20,   15,  176,   53,   84,
  202,   21,  183,  201,  205,  169,   64,   81,  111,   80,
  101,   95,  122,   20,   83,  105,   61,  140,  123,   21,
   79,  104,  141,  126,  127,  101,   42,  101,  119,   48,
  121,   50,   51,   97,   41,   81,    5,   41,   29,  255,
   74,  268,  167,   43,  142,   46,   25,   57,  272,  132,
   57,   29,  150,  153,   57,  154,   62,  156,  157,   44,
   62,   25,  149,   45,  271,   71,  182,  151,  181,   72,
  155,  245,  246,  169,  159,   64,  170,   85,   64,   55,
   86,   87,   64,   90,   54,   61,  168,  101,   61,  101,
   88,   79,   61,  137,  103,   48,  104,  124,   95,  211,
  212,  186,  101,  125,  101,   24,   81,  165,   80,  223,
  189,  128,   84,  101,   58,  101,   95,  143,  158,  160,
   97,  140,  138,  165,  139,   79,  141,   82,  101,  163,
  101,   95,  162,  164,   55,  173,  137,   95,   97,   54,
   81,   93,   80,  184,  170,  188,   95,  245,  246,   28,
  195,  197,  198,   97,  168,  199,   28,   54,   54,   97,
   36,  207,   53,   53,   97,   97,   13,   97,   97,   97,
   95,   95,   95,  224,  225,  227,   28,   55,  238,  174,
  175,  226,   54,   58,  228,  107,   58,   14,  229,   47,
   58,   48,   97,   97,   97,  135,  136,  236,   95,   36,
   95,   50,   51,  135,  136,   14,   37,   30,   47,  122,
   95,  111,  111,   28,   28,  123,   68,  204,  174,  175,
   97,  233,   97,  174,  175,  119,   95,  121,   93,   48,
  237,  234,   97,  239,  236,  205,  249,  241,   65,   28,
  259,   28,   95,   48,   48,   28,   93,  106,   97,  250,
   30,   48,  251,   48,   48,   48,   48,   48,   48,   48,
   48,   93,  236,   48,   97,   98,  236,   93,  253,  213,
  177,  178,  179,  180,  257,   14,   93,  258,   47,   24,
  145,  145,  145,  145,  260,   68,   24,  263,   68,  264,
  266,  269,   68,  267,  270,  274,   47,   40,   48,   49,
   93,   93,   93,    1,   68,   71,   24,   65,   50,   51,
   65,   14,   75,   52,   65,   66,  135,  136,   57,  101,
  101,  101,  101,   75,   76,   77,   78,   37,   93,   76,
   93,   23,   13,   24,  145,   53,   73,   57,  101,  101,
   93,  235,  256,   24,   24,  101,  101,  101,  101,  206,
  209,   47,   98,   48,   49,  262,   93,   75,   76,   77,
   78,    0,    0,   50,   51,    0,    0,    0,    0,   24,
   98,   24,   93,    0,    0,   24,    0,  254,    0,    0,
    0,   30,    0,    0,    0,   98,    0,    3,   30,    0,
    0,   98,    0,    0,   47,   40,   48,   49,    0,    0,
   98,    4,    5,    0,    0,    3,   50,   51,   30,    6,
    0,    7,    8,    9,   10,   11,   12,    0,    0,    4,
    5,   13,    0,    0,   98,   98,   98,    6,    0,    7,
    8,    9,   10,   11,   12,  191,  192,  193,  194,   13,
    0,    0,    0,    0,    0,   30,   30,   30,    0,    0,
    0,    0,   98,    0,   98,    0,  127,   97,   97,    0,
   97,    0,   97,    0,   98,    0,   74,   74,   74,   74,
   74,   30,   74,   30,  127,    3,    0,   30,    0,    0,
   98,    0,    0,    0,   74,   74,    0,   74,    0,    4,
    5,    0,    0,    0,    0,    0,   98,    6,    0,    7,
    8,    9,   10,   11,   12,    0,  131,  140,  140,   13,
  140,    3,  140,   98,   98,   98,   98,   98,    0,   98,
    0,    0,    0,    0,  131,    4,    5,    0,    0,    0,
    0,   98,   98,    6,   98,    7,    8,    9,   10,   11,
   12,    0,    0,    0,    0,   13,  101,  101,  101,  101,
  101,  101,  101,    0,    0,   28,   28,   28,   28,   28,
   28,   28,    0,    0,  101,  101,  101,  101,    0,    0,
    0,    0,    0,   28,   28,   28,   28,   26,   26,   26,
   26,   26,   26,   26,   25,   25,   25,   25,   25,   25,
   25,    0,    0,    0,    0,   26,   26,   26,   26,    0,
    0,    0,   25,   25,   25,   25,   27,   27,   27,   27,
   27,   27,   27,  139,  139,  139,  139,  139,    0,  139,
    0,    0,    0,    0,   27,   27,   27,   27,    0,    0,
    0,  139,  139,    0,  139,   73,   73,   73,   73,   73,
    0,   73,  108,   97,   97,    0,   97,    0,   97,    0,
    0,    0,    0,   73,   73,    0,   73,    0,    0,    0,
  108,  108,    0,  108,  107,   95,   95,    0,   95,    0,
   95,   41,    0,    0,    0,  110,   96,   96,   63,   96,
    0,   96,  107,  107,    0,  107,    0,   74,   74,   74,
   74,   74,   74,  110,  110,   91,  110,   91,   91,   91,
    0,   92,    0,   92,   92,   92,    0,    0,    0,    0,
  114,  114,    0,   91,   91,    0,   91,    0,    0,   92,
   92,    0,   92,  128,  138,  138,    0,  138,    0,  138,
    0,    0,    0,    0,   98,   98,   98,   98,   98,   98,
    0,  128,  129,  139,  139,    0,  139,   63,  139,    0,
   63,    0,    0,    0,   63,  124,  136,  136,    0,  136,
  129,  136,    0,    0,    0,    0,    0,  101,  101,  101,
  101,  101,  101,  124,  101,  101,   28,   28,   28,   28,
   28,   28,    0,    0,    0,    0,  125,  137,  137,    0,
  137,    0,  137,    0,    0,    0,    0,    0,   26,   26,
   26,   26,   26,   26,  125,   25,   25,   25,   25,   25,
   25,    0,    0,    0,    0,  130,   96,   96,    0,   96,
    0,   96,    0,    0,    0,    0,    0,   27,   27,   27,
   27,   27,   27,  130,  139,  139,  139,  139,  139,  139,
    0,  114,  114,    0,  114,  114,  114,  114,  114,  114,
    0,  114,    0,    0,    0,    0,   73,   73,   73,   73,
   73,   73,   56,  108,  108,  108,  108,  108,  108,    0,
  111,  111,    0,  133,   98,   98,    0,   98,    0,   98,
    0,    0,    0,    0,    0,  107,  107,  107,  107,  107,
  107,  133,    0,    0,  109,  109,  110,  110,  110,  110,
  110,  110,  144,  146,  147,  148,  133,    0,    0,   66,
  216,  217,  218,  219,  220,  221,   91,   91,   91,   91,
   91,   91,   92,   92,   92,   92,   92,   92,    0,    0,
    0,   56,    0,    0,   56,    0,    0,    0,   56,    0,
  185,  117,  117,   85,   97,   97,   85,   97,    0,   97,
    0,    0,    0,  134,    0,    0,  187,    0,  196,   84,
  138,  138,   84,  138,    0,  138,   81,  139,  139,   81,
  139,    0,  139,  200,    0,    0,    0,    0,   66,    0,
    0,   66,    0,    0,    0,   66,    0,    0,  210,  190,
  190,  190,  190,   80,  136,  136,   80,  136,    0,  136,
    0,  111,  111,    0,  111,  111,  111,  111,  111,  111,
    0,  111,  230,  231,  232,   83,  137,  137,   83,  137,
    0,  137,    0,    0,    0,  109,  109,    0,  109,  109,
  109,  109,  109,  109,    0,  109,  134,  134,  134,  134,
  243,    0,  244,   82,   96,   96,   82,   96,    0,   96,
    0,    0,  252,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  265,    0,
    0,    0,  117,  117,    0,  117,  117,  117,  117,  117,
  117,    0,  117,    0,  273,
};
static const short yycheck[] = {                         44,
    0,   40,   46,  125,  103,    2,   59,   45,   11,  258,
   46,  183,   80,  125,   11,   42,   13,   61,   45,  125,
   41,   40,   44,  125,  213,   41,    2,   41,  125,   46,
   41,   41,   41,   44,   46,  103,   11,   59,   59,   61,
   44,   38,   45,   59,   61,   42,   11,   42,   45,   59,
   44,  259,   47,   50,   51,   59,   46,   61,   45,   59,
   45,  269,  270,   38,   41,   59,  274,   44,   46,  241,
   59,  260,  171,   40,   71,  259,   46,   80,  267,   54,
   83,   59,   79,   80,   87,   82,   83,   84,   85,   40,
   87,   61,   79,   40,  266,   40,   60,   80,   62,  259,
   83,  289,  290,  171,   87,   80,  103,   46,   83,   40,
  259,   61,   87,  259,   45,   80,  103,   44,   83,   46,
   40,   44,   87,   46,  123,  125,  259,   59,  125,  174,
  175,  128,   59,   40,   61,    2,   59,  259,   61,  184,
  137,   46,   46,   44,   11,   46,  143,   40,   40,  259,
  125,   42,   43,  259,   45,   44,   47,   46,   59,   41,
   61,  158,  123,   44,   40,   40,   46,  164,  143,   45,
   59,   38,   61,   59,  171,   41,  173,  289,  290,  176,
   41,   40,   40,  158,  171,   40,  183,  289,  290,  164,
  268,   59,  289,  290,   42,   43,  123,   45,  173,   47,
  197,  198,  199,   41,   40,   40,  203,   40,  205,  262,
  263,   41,   45,   80,  123,  242,   83,   59,   41,  257,
   87,  259,  197,  198,  199,  269,  270,  203,  225,  268,
  227,  269,  270,  269,  270,   59,  275,    2,  257,  242,
  237,  262,  263,  240,  241,  242,   11,  259,  262,  263,
  225,   41,  227,  262,  263,  242,  253,  242,  125,  259,
   40,  259,  237,   41,  240,   46,   41,  282,   11,  266,
  245,  268,  269,  273,  274,  272,  143,   42,  253,   41,
   45,  281,   41,  283,  284,  285,  286,  287,  288,  289,
  290,  158,  268,  293,  269,   38,  272,  164,   40,  123,
  264,  265,  266,  267,   41,   59,  173,   41,  257,  176,
   75,   76,   77,   78,   58,   80,  183,  259,   83,   41,
   41,   40,   87,   58,   41,   41,  257,  258,  259,  260,
  197,  198,  199,    0,   59,   59,  203,   80,  269,  270,
   83,   59,   41,  274,   87,   59,  269,  270,   59,  276,
  277,  278,  279,  276,  277,  278,  279,  123,  225,   41,
  227,   61,  293,   61,  129,  296,   59,   41,  269,  270,
  237,  125,  242,  240,  241,  276,  277,  278,  279,  164,
  171,  257,  125,  259,  260,  247,  253,  276,  277,  278,
  279,   -1,   -1,  269,  270,   -1,   -1,   -1,   -1,  266,
  143,  268,  269,   -1,   -1,  272,   -1,  125,   -1,   -1,
   -1,  176,   -1,   -1,   -1,  158,   -1,  259,  183,   -1,
   -1,  164,   -1,   -1,  257,  258,  259,  260,   -1,   -1,
  173,  273,  274,   -1,   -1,  259,  269,  270,  203,  281,
   -1,  283,  284,  285,  286,  287,  288,   -1,   -1,  273,
  274,  293,   -1,   -1,  197,  198,  199,  281,   -1,  283,
  284,  285,  286,  287,  288,  138,  139,  140,  141,  293,
   -1,   -1,   -1,   -1,   -1,  240,  241,  242,   -1,   -1,
   -1,   -1,  225,   -1,  227,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,  237,   -1,   41,   42,   43,   44,
   45,  266,   47,  268,   59,  259,   -1,  272,   -1,   -1,
  253,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,  273,
  274,   -1,   -1,   -1,   -1,   -1,  269,  281,   -1,  283,
  284,  285,  286,  287,  288,   -1,   41,   42,   43,  293,
   45,  259,   47,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   59,  273,  274,   -1,   -1,   -1,
   -1,   59,   60,  281,   62,  283,  284,  285,  286,  287,
  288,   -1,   -1,   -1,   -1,  293,   41,   42,   43,   44,
   45,   46,   47,   -1,   -1,   41,   42,   43,   44,   45,
   46,   47,   -1,   -1,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   59,   60,   61,   62,   41,   42,   43,
   44,   45,   46,   47,   41,   42,   43,   44,   45,   46,
   47,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   59,   60,   61,   62,   41,   42,   43,   44,
   45,   46,   47,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,   -1,
   -1,   59,   60,   -1,   62,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   59,   60,   -1,   62,   41,   42,   43,   -1,   45,   -1,
   47,    4,   -1,   -1,   -1,   41,   42,   43,   11,   45,
   -1,   47,   59,   60,   -1,   62,   -1,  262,  263,  264,
  265,  266,  267,   59,   60,   41,   62,   43,   44,   45,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   43,   44,   -1,   59,   60,   -1,   62,   -1,   -1,   59,
   60,   -1,   62,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
   -1,   59,   41,   42,   43,   -1,   45,   80,   47,   -1,
   83,   -1,   -1,   -1,   87,   41,   42,   43,   -1,   45,
   59,   47,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,
  265,  266,  267,   59,  269,  270,  262,  263,  264,  265,
  266,  267,   -1,   -1,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,   59,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,
  265,  266,  267,   59,  262,  263,  264,  265,  266,  267,
   -1,  174,  175,   -1,  177,  178,  179,  180,  181,  182,
   -1,  184,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,   11,  262,  263,  264,  265,  266,  267,   -1,
   43,   44,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   59,   -1,   -1,   43,   44,  262,  263,  264,  265,
  266,  267,   75,   76,   77,   78,   55,   -1,   -1,   11,
  177,  178,  179,  180,  181,  182,  262,  263,  264,  265,
  266,  267,  262,  263,  264,  265,  266,  267,   -1,   -1,
   -1,   80,   -1,   -1,   83,   -1,   -1,   -1,   87,   -1,
  125,   43,   44,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   55,   -1,   -1,  129,   -1,  143,   41,
   42,   43,   44,   45,   -1,   47,   41,   42,   43,   44,
   45,   -1,   47,  158,   -1,   -1,   -1,   -1,   80,   -1,
   -1,   83,   -1,   -1,   -1,   87,   -1,   -1,  173,  138,
  139,  140,  141,   41,   42,   43,   44,   45,   -1,   47,
   -1,  174,  175,   -1,  177,  178,  179,  180,  181,  182,
   -1,  184,  197,  198,  199,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,  174,  175,   -1,  177,  178,
  179,  180,  181,  182,   -1,  184,  138,  139,  140,  141,
  225,   -1,  227,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,  237,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  253,   -1,
   -1,   -1,  174,  175,   -1,  177,  178,  179,  180,  181,
  182,   -1,  184,   -1,  269,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 299
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TDOUBLE","TBOOL","IDENTIFIER","TSTRING","OP_CALC",
"AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP",
"FUNC_CALL","VAR_DECLAR","RESTRICT","THIS","EXTENDS","ADD_EQ","SUB_EQ","MUL_EQ",
"DIV_EQ","AUTO","IF","ELSE","WHILE","FOR","DELETE","BREAK","RETURN","SWITCH",
"CASE","DEFAULT","CASE_LIST","CLAXX_BODY","NEW","CLAXX_MEMBER",
"CLAXX_FUNC_CALL","XNULL","NONASSOC","IFX","UMINUS",
};
static const char *yyrule[] = {
"$accept : program",
"program : statement_list",
"statement_list : statement_list statement",
"statement_list :",
"statement : ';'",
"statement : declar_stmt",
"statement : con_ctl_stmt",
"statement : simple_stmt ';'",
"declar_stmt : func_declar_stmt",
"declar_stmt : var_declar_stmt",
"declar_stmt : class_declar_stmt",
"class_declar_stmt : IDENTIFIER extends_stmt '{' '}'",
"class_declar_stmt : IDENTIFIER extends_stmt '{' class_body '}'",
"extends_stmt :",
"extends_stmt : EXTENDS IDENTIFIER",
"class_body : class_body_stmt",
"class_body : class_body class_body_stmt",
"class_body_stmt : var_declar_stmt",
"class_body_stmt : single_assign_stmt ';'",
"class_body_stmt : func_declar_stmt",
"this_stmt : THIS",
"this_stmt : THIS '.' id_expr",
"this_stmt : THIS '.' id_expr '(' args_list ')'",
"this_member_stmt : THIS '.' id_expr",
"this_member_stmt : THIS '.' class_member_stmt",
"class_member_stmt : id_expr '.' id_expr",
"class_member_stmt : class_member_func_stmt '.' id_expr",
"class_member_stmt : IDENTIFIER '(' args_list ')' '.' id_expr",
"class_member_stmt : class_member_stmt '.' id_expr",
"class_member_func_stmt : id_expr '.' id_expr '(' args_list ')'",
"class_member_func_stmt : IDENTIFIER '(' args_list ')' '.' id_expr '(' args_list ')'",
"class_member_func_stmt : class_member_stmt '.' id_expr '(' args_list ')'",
"class_member_func_stmt : class_member_func_stmt '.' id_expr '(' args_list ')'",
"class_func_serial_stmt : IDENTIFIER '(' args_list ')' IDENTIFIER '(' args_list ')'",
"class_func_serial_stmt : id_expr '.' id_expr '(' args_list ')' IDENTIFIER '(' args_list ')'",
"class_func_serial_stmt : class_func_serial_stmt IDENTIFIER '(' args_list ')'",
"func_declar_stmt : IDENTIFIER FUNC_OP param_list '{' expr_list '}'",
"param_list :",
"param_list : '(' parameter ')'",
"parameter : IDENTIFIER",
"parameter : parameter ',' IDENTIFIER",
"parameter :",
"expr_list : expr_list statement",
"expr_list :",
"var_declar_stmt : id_expr ';'",
"var_declar_stmt : id_expr ',' var_declar_stmt",
"con_ctl_stmt : selection_stmt",
"con_ctl_stmt : loop_stmt",
"selection_stmt : IF '(' logic_stmt ')' block",
"selection_stmt : IF '(' logic_stmt ')' block ELSE block",
"selection_stmt : SWITCH '(' id_expr ')' '{' case_stmt_list '}'",
"case_stmt_list : case_stmt",
"case_stmt_list : case_stmt_list case_stmt",
"case_stmt : CASE double_expr ':' expr_list",
"case_stmt : DEFAULT ':' expr_list",
"loop_stmt : WHILE '(' logic_stmt ')' block",
"loop_stmt : FOR '(' for_1_stmt ';' logic_stmt ';' for_1_stmt ')' block",
"for_1_stmt :",
"for_1_stmt : assign_stmt",
"for_1_stmt : var_declar_stmt",
"for_1_stmt : self_inc_dec_stmt",
"simple_stmt : assign_stmt",
"simple_stmt : call_statement",
"simple_stmt : DELETE IDENTIFIER ';'",
"simple_stmt : interrupt_stmt",
"simple_stmt : new_expr",
"simple_stmt : class_func_serial_stmt",
"simple_stmt : restrict_stmt",
"restrict_stmt : RESTRICT",
"restrict_stmt : RESTRICT t_bool_expr",
"interrupt_stmt : BREAK",
"interrupt_stmt : RETURN",
"interrupt_stmt : RETURN assign_stmt_value",
"call_statement : IDENTIFIER '(' args_list ')'",
"call_statement : class_member_func_stmt",
"args_list :",
"args_list : args_expr",
"args_expr : args_expr_collection",
"args_expr : args_expr ',' args_expr_collection",
"args_expr_collection : t_bool_expr",
"args_expr_collection : double_expr",
"args_expr_collection : id_expr",
"args_expr_collection : string_expr",
"args_expr_collection : uminus_expr",
"args_expr_collection : call_statement",
"args_expr_collection : arithmetic_stmt",
"block : '{' expr_list '}'",
"block : statement",
"double_or_ps_expr : double_expr",
"double_or_ps_expr : parentheses_stmt",
"parentheses_stmt : '(' assign_stmt_value_eq ')'",
"arithmetic_stmt : arithmetic_stmt_factor '+' arithmetic_stmt_factor",
"arithmetic_stmt : arithmetic_stmt_factor '-' arithmetic_stmt_factor",
"arithmetic_stmt : arithmetic_stmt_factor '*' arithmetic_stmt_factor",
"arithmetic_stmt : arithmetic_stmt_factor '/' arithmetic_stmt_factor",
"arithmetic_stmt_factor : assign_stmt_value_eq",
"arithmetic_stmt_factor : string_expr",
"arithmetic_stmt_factor : arithmetic_stmt",
"arithmetic_stmt_factor : class_member_stmt",
"arithmetic_stmt_factor : '(' arithmetic_stmt ')'",
"new_expr : NEW id_expr '(' args_list ')'",
"id_expr : IDENTIFIER",
"t_bool_expr : TBOOL",
"double_expr : TDOUBLE",
"uminus_expr : '-' double_or_ps_expr",
"string_expr : TSTRING",
"null_expr : XNULL",
"bool_param_expr : assign_stmt_value_eq",
"bool_param_expr : arithmetic_stmt",
"bool_param_expr : t_bool_expr",
"bool_param_expr : string_expr",
"logic_stmt : bool_param_expr",
"logic_stmt : bool_param_expr '>' bool_param_expr",
"logic_stmt : bool_param_expr '<' bool_param_expr",
"logic_stmt : bool_param_expr LE_OP bool_param_expr",
"logic_stmt : bool_param_expr GE_OP bool_param_expr",
"logic_stmt : bool_param_expr EQ_OP bool_param_expr",
"logic_stmt : bool_param_expr NE_OP bool_param_expr",
"logic_stmt : logic_stmt AND_OP logic_stmt",
"logic_stmt : logic_stmt OR_OP logic_stmt",
"self_inc_dec_stmt : INC_OP id_expr",
"self_inc_dec_stmt : DEC_OP id_expr",
"self_inc_dec_stmt : id_expr INC_OP",
"self_inc_dec_stmt : id_expr DEC_OP",
"assign_stmt_value : double_expr",
"assign_stmt_value : uminus_expr",
"assign_stmt_value : t_bool_expr",
"assign_stmt_value : arithmetic_stmt",
"assign_stmt_value : call_statement",
"assign_stmt_value : id_expr",
"assign_stmt_value : string_expr",
"assign_stmt_value : self_inc_dec_stmt",
"assign_stmt_value : new_expr",
"assign_stmt_value : class_member_stmt",
"assign_stmt_value : null_expr",
"assign_stmt_value : this_stmt",
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
"single_assign_stmt : id_expr '=' single_assign_stmt",
"class_member_assign_stmt : class_member_stmt '=' assign_stmt_value",
"class_member_assign_stmt : this_member_stmt '=' assign_stmt_value",
"assign_stmt : single_assign_stmt",
"assign_stmt : class_member_assign_stmt",
"assign_stmt : id_expr ADD_EQ assign_stmt_value_eq",
"assign_stmt : id_expr SUB_EQ assign_stmt_value_eq",
"assign_stmt : id_expr MUL_EQ assign_stmt_value_eq",
"assign_stmt : id_expr DIV_EQ assign_stmt_value_eq",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 400 "a.y"


void yyerror(char *s) {
 fprintf(stderr, "%s on line %d,column %d. near by '%s' \n", s ,yyget_lineno(),column , yytext  );
}

int main(int argc, char *argv[]){
	if(argc <= 1){
		printf("no input file.\n");
		return 1;
	}
	
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("file %s not found.\n" , argv[1]);
		return 1;
	}
	
	parseFileName = argv[1];
	extern FILE* yyin; 
	yyin=fp;
	initLangX();
    yyparse();
	closeLangX();
	fclose(fp);
	
	printf("parse over!\n");
	return 0;
}
#line 739 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 68 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 72 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 73 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 74 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 75 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 80 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 81 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 82 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 11:
#line 87 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-2].sValue, NULL); }
break;
case 12:
#line 88 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-4].sValue , yystack.l_mark[-3].sValue, yystack.l_mark[-1].node); }
break;
case 13:
#line 93 "a.y"
	{ yyval.sValue = NULL; }
break;
case 14:
#line 94 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue; }
break;
case 15:
#line 99 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 16:
#line 100 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 17:
#line 104 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 18:
#line 105 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 19:
#line 106 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 20:
#line 111 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 21:
#line 112 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 22:
#line 114 "a.y"
	{ yyval.node = opr(THIS, 1 , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 23:
#line 121 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 24:
#line 122 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 25:
#line 127 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 26:
#line 128 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 27:
#line 129 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 28:
#line 130 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 29:
#line 135 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 30:
#line 136 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 31:
#line 137 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 32:
#line 138 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 33:
#line 143 "a.y"
	{  yyval.node = NULL; }
break;
case 34:
#line 144 "a.y"
	{ yyval.node = NULL; }
break;
case 35:
#line 145 "a.y"
	{ yyval.node = NULL; }
break;
case 36:
#line 150 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 37:
#line 154 "a.y"
	{ yyval.params = NULL; }
break;
case 38:
#line 155 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 39:
#line 159 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 40:
#line 160 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 41:
#line 161 "a.y"
	{ yyval.params = NULL; }
break;
case 42:
#line 165 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 43:
#line 166 "a.y"
	{ yyval.node = NULL; }
break;
case 44:
#line 171 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 45:
#line 172 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 46:
#line 177 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 47:
#line 178 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 183 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 49:
#line 184 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 50:
#line 185 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 51:
#line 189 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 52:
#line 190 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 53:
#line 194 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 54:
#line 195 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 55:
#line 199 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 56:
#line 200 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 57:
#line 205 "a.y"
	{ yyval.node = NULL ; }
break;
case 58:
#line 206 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 207 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 208 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 213 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 62:
#line 214 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 215 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 64:
#line 216 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 217 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 218 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 67:
#line 219 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 225 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 69:
#line 226 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 70:
#line 230 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 71:
#line 231 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 72:
#line 232 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 73:
#line 237 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 74:
#line 238 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 242 "a.y"
	{ yyval.args = NULL; }
break;
case 76:
#line 243 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 77:
#line 247 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 78:
#line 248 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 79:
#line 252 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 253 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 254 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 255 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 256 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 257 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 85:
#line 258 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 86:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 87:
#line 263 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 269 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 270 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 275 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 91:
#line 281 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 92:
#line 282 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 93:
#line 283 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 94:
#line 284 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 95:
#line 289 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 96:
#line 290 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 97:
#line 291 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 98:
#line 292 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 99:
#line 293 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 100:
#line 298 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 101:
#line 302 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 102:
#line 306 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 103:
#line 310 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 104:
#line 314 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 105:
#line 318 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 106:
#line 322 "a.y"
	{ yyval.node = xnull();}
break;
case 107:
#line 327 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 328 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 109:
#line 329 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 110:
#line 330 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 111:
#line 335 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 112:
#line 336 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 113:
#line 337 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 338 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 115:
#line 339 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 116:
#line 340 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 117:
#line 341 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 118:
#line 342 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 119:
#line 343 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 120:
#line 348 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 121:
#line 349 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 122:
#line 350 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 123:
#line 351 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 124:
#line 356 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 125:
#line 357 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 358 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 359 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 360 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 361 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 362 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 131:
#line 363 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 132:
#line 364 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 133:
#line 365 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 366 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 135:
#line 367 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 136:
#line 372 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 373 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 138:
#line 374 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 139:
#line 375 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 140:
#line 376 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 381 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 142:
#line 382 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 143:
#line 386 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 144:
#line 387 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 145:
#line 392 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 146:
#line 393 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 147:
#line 394 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 148:
#line 395 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 149:
#line 396 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 150:
#line 397 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1537 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
