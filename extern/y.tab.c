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

#line 19 "a.y"
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
#line 51 "y.tab.c"

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
   14,   14,   14,   14,   31,   31,   31,   31,   25,   26,
   27,   28,   29,   30,   41,   23,   23,   23,   23,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   15,   15,
   15,   15,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   20,   20,   20,   20,   20,   22,
   22,   38,   38,   13,   13,   13,   13,   13,   13,
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
    3,    3,    3,    3,    1,    1,    1,    3,    5,    1,
    1,    1,    2,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    2,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    3,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   70,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   46,   47,   61,   62,  144,   64,   65,    0,   10,    0,
  145,    0,    0,   67,    0,    0,    0,    0,    0,  101,
   69,    0,    0,    0,    0,    0,  102,    0,  104,    0,
    0,    0,  105,    0,    0,    0,    0,    0,   95,   72,
  131,    0,  125,    0,    0,    0,    0,    0,  133,  134,
    0,  100,    0,    7,    0,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    0,  139,    0,   77,    0,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  137,
    0,    0,    0,  108,  135,  136,    0,    0,   59,    0,
   58,   60,    0,   63,    0,  119,  120,    0,    0,  103,
   89,   88,    0,   96,  121,  122,    0,    0,    0,    0,
    0,    0,    0,  146,  147,  148,  149,   45,    0,  140,
  141,    0,    0,  142,    0,    0,    0,  143,   39,    0,
   43,    0,    0,    0,   11,   19,   17,    0,    0,    0,
   15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   98,    0,   97,    0,
    0,   93,   94,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0,    0,   78,   18,   12,   16,    0,  117,
  118,   43,   87,    0,  113,  114,  115,  116,  111,  112,
   55,    0,    0,    0,   90,    0,    0,   99,    0,    0,
    0,   35,   40,   36,   42,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   51,    0,   31,   32,
    0,    0,   86,   49,    0,   22,   29,    0,   43,   50,
   52,    0,   33,    0,    0,   43,    0,    0,   30,   56,
    0,    0,   34,
};
static const short yydgoto[] = {                          1,
  213,   16,   17,   18,   19,   20,  202,   21,   22,  108,
  214,  120,   23,   91,   92,  110,   94,  130,  131,   59,
   60,   25,  112,   26,   27,  113,   96,  115,  116,   99,
   67,  246,  247,   29,  170,  171,  100,   31,   32,   33,
   69,   34,   70,   35,   89,  160,  101,  102,   39,    2,
};
static const short yysindex[] = {                         0,
    0,  282,  -38, -230,    4,   -2,   32,   76, -211,    0,
   57,   78, -201,    0,    0,    0,    0,   61,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  144,    0,   29,
    0,   83, -137,    0,   63,   91, -123,  253,   34,    0,
    0, -104,  253,  253, -107,   99,    0,  120,    0, -201,
 -201,  115,    0,  -37,  -24,    0,    0,    0,    0,    0,
    0,  -46,    0,    0,    0,    0,  386,  127,    0,    0,
 -201,    0,  135,    0,  220,  220,  220,  220, -201,   57,
    0, -201,   57, -201, -201,  139,   57,  -78,   59,    0,
    0,    0,    0,    0,  -46,    0,    0,    0,    0,  127,
  142,  141, -116,  149,  147,  127,   83,   -6,    0,    0,
    0,  118,  -46,    0,    0,    0,    0,   60,    0,  153,
    0,    0,   89,    0,  253,    0,    0, -201,  220,    0,
    0,    0,  160,    0,    0,    0, -201,  -24,  -24,  -24,
  -24,  174,  253,    0,    0,    0,    0,    0,  -22,    0,
    0,  -20,  182,    0,  187,  191,  253,    0,    0,   47,
    0,    9,  253,   -9,    0,    0,    0,  189,   62, -115,
    0,  253,  253,  253,  188,  253,  253,  253,  253,  253,
  253,  188,  253,  223,  231,  237,    0,  252,    0,  -13,
  -13,    0,    0,  176,  256,  253,  253,  253,  261,   44,
    0,  245,  265, -201,    0,    0,    0,    0,  267,    0,
    0,    0,    0,   24,    0,    0,    0,    0,    0,    0,
    0,  -54,  263,  253,    0,  253, -148,    0,  271,  278,
  280,    0,    0,    0,    0,  253,  284,  263,  266,  188,
 -107,  287,  288,   80,  272,  -98,    0,   74,    0,    0,
  298,  253,    0,    0,  304,    0,    0,  293,    0,    0,
    0,  314,    0,  316,  188,    0,  282,  253,    0,    0,
  282,  320,    0,
};
static const short yyrindex[] = {                         0,
    0,  363,  173,  296,    0,    0,    0,    0,    0,    0,
  310,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  395,  317,    0,    0,  258,    0,  334,    0,    0,
    0,    0,    0,    0,  333,    0,    0,  441,    0,    0,
    0,   -8,    0,    0,    0,   21,  301,  501,    0,    0,
    0,  628,    0,  650,  678,  687,    0,    8,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52,    0,    0,
  706,    0,  716,    0,  723,    0,  748,  848,  855,    0,
    0,  352,    0,  110,  343,  346,    0,    0,  355,    0,
  564,  -23,  535,    0,    0,    0,  586,    0,    0,    0,
    0,    0,    0,    0,  334,    0,    0,    0,    0,    0,
    0,    0,  449,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  334,    0,    0,    0,    0,    0,    0,    0,
    0,  628,   37,    0,  -16,   15,  334,    0,    0,    0,
    0,  336,    0,  109,    0,    0,    0,    0,    0,    0,
    0,  334,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   18,    0,    0,   73,    0,  593,
  606,    0,    0,    0,    0,  334,  334,  334,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,
    0,    0,  542,  334,    0,  334,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  334,  105,    0,    0,    0,
  367,    0,    0,    0,    0,    0,    0,   66,    0,    0,
    0,  334,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -93,  334,    0,    0,
  -79,    0,    0,
};
static const short yygindex[] = {                         0,
    5,    0,    0,    0,  -91,   25, -188,    0,    0,  -36,
 -171,  169,  -39,  701,   20,  138,  250,    0,    0,  640,
   30,  -61,  562,    0,   28,    2,  599,  175,  269,  821,
  368,    0,  170,    0,    0,  248,   12,    0,  -25,    0,
    0,    0,    0,    0,    0,    0,  690,    0,    0,    0,
};
#define YYTABLESIZE 1004
static const short yytable[] = {                        137,
   48,   38,  129,   28,  241,  121,   15,  118,  165,  207,
  221,  166,   62,   30,   73,   55,  107,  110,  151,  107,
   54,   79,   68,  239,   28,  137,  260,   40,  140,   28,
   57,   54,   20,  141,  175,  110,   81,   43,   61,   95,
   80,  168,   28,  105,   28,   53,  123,   46,  132,   42,
   20,  126,  127,  106,  204,   26,   30,   72,   21,   48,
   26,  126,   97,   97,  122,   97,  132,   97,  254,  119,
  267,   44,  142,   26,   84,   26,   21,  271,  166,  126,
  149,  152,   25,  153,   62,  155,  156,  201,   62,   83,
  200,   68,   41,  270,   68,   41,   55,   25,   68,   57,
  182,   54,   57,  148,  169,   79,   57,   61,  168,  150,
   61,   29,  154,   25,   61,   45,  158,   71,   25,   74,
   81,   86,   80,   87,   29,   48,   95,  167,   85,  185,
   88,   25,   79,   25,  137,   90,  210,  211,  188,   24,
  244,  245,  164,  164,   95,   27,  222,   81,   58,   80,
   27,  104,  100,  100,  104,  100,  103,  124,   95,  125,
  128,   50,   51,   27,   95,   27,    5,  100,  100,  100,
  100,  169,   84,   95,  143,   93,   28,  181,  157,  180,
  159,  161,  162,   28,  163,   64,   30,   79,  172,   82,
  244,  245,  137,   30,  167,   54,   54,   95,   95,   95,
  187,  121,   81,   28,   80,  237,  235,  173,  174,   53,
   53,  183,   97,   30,  194,  107,  100,   58,  100,   47,
   58,  196,  135,  136,   58,   95,  197,   95,  132,   36,
  198,  100,   47,  100,   48,   49,   37,   95,  110,  110,
   28,   28,  123,  235,   50,   51,   14,  206,  135,  136,
   30,   30,   30,   95,   64,  173,  174,   64,   36,   48,
  122,   64,   93,  223,   54,  119,   28,  203,   28,   95,
  224,  235,   28,   48,   48,  235,   30,  225,   30,   65,
   93,   48,   30,   48,   48,   48,   48,   48,   48,   48,
   48,  226,   55,   48,   93,   13,  228,   54,  227,   97,
   93,  232,  233,   14,  236,  240,   98,  238,  204,   93,
  212,  248,   24,   47,   40,   48,   49,   97,  249,   24,
  250,  173,  174,  252,   14,   50,   51,  256,  257,  259,
   52,   97,  262,   93,   93,   93,   47,   97,  263,   24,
   14,  130,  139,  139,  265,  139,   97,  139,   65,   13,
  266,   65,   53,  268,   68,   65,  269,  135,  136,  130,
  273,   93,    1,   93,   75,   76,   77,   78,   71,  234,
   97,   97,   97,   93,   75,   66,   24,   24,  100,  100,
   37,  176,  177,  178,  179,  100,  100,  100,  100,   93,
  253,   57,   76,   98,   73,  107,   97,   97,   97,   97,
   97,   97,   24,   23,   24,   93,   24,   57,   24,  255,
   97,   98,  205,  107,  107,  261,  107,  208,  258,   75,
   76,   77,   78,    0,    0,   98,   97,  140,  138,    0,
  139,   98,  141,    0,    0,   74,   74,   74,   74,   74,
   98,   74,   97,    0,    0,    0,    3,    0,  100,  100,
  100,  100,    0,   74,   74,    0,   74,    0,    0,    0,
    4,    5,    0,    0,   98,   98,   98,    0,    6,    0,
    7,    8,    9,   10,   11,   12,   47,    0,   48,    0,
   13,  100,  100,  100,  100,  100,  100,  100,   50,   51,
   97,   97,   98,   97,   98,   97,    0,    0,    0,  100,
  100,  100,  100,    3,   98,  190,  191,  192,  193,   47,
   40,   48,   49,    0,    0,    0,    0,    4,    5,    0,
   98,   50,   51,    0,    3,    6,    0,    7,    8,    9,
   10,   11,   12,    0,    0,    0,   98,   13,    4,    5,
    3,  127,  137,  137,    0,  137,    6,  137,    7,    8,
    9,   10,   11,   12,    4,    5,    0,    0,   13,  127,
    0,    0,    6,    0,    7,    8,    9,   10,   11,   12,
    0,    0,    0,    0,   13,  138,  138,  138,  138,  138,
    0,  138,   73,   73,   73,   73,   73,    0,   73,    0,
    0,    0,    0,  138,  138,    0,  138,    0,    0,    0,
   73,   73,   41,   73,  106,   95,   95,    0,   95,   63,
   95,    0,    0,    0,    0,    0,  107,  107,  107,  107,
  107,  107,  106,  106,    0,  106,  109,   96,   96,    0,
   96,    0,   96,   91,    0,   91,   91,   91,    0,    0,
    0,  114,  114,    0,  109,  109,   92,  109,   92,   92,
   92,   91,   91,    0,   91,    0,   74,   74,   74,   74,
   74,   74,    0,    0,   92,   92,    0,   92,  128,  138,
  138,    0,  138,    0,  138,    0,    0,    0,   63,    0,
    0,   63,  111,  111,    0,   63,  128,    0,    0,    0,
  123,  135,  135,    0,  135,    0,  135,    0,    0,    0,
    0,    0,  100,  100,  100,  100,  100,  100,  123,  100,
  100,   56,    0,    0,  144,  145,  146,  147,  124,  136,
  136,    0,  136,    0,  136,    0,    0,  129,   96,   96,
    0,   96,    0,   96,    0,    0,  124,  215,  216,  217,
  218,  219,  220,  109,  109,  129,   85,   97,   97,   85,
   97,    0,   97,    0,    0,  133,   84,  137,  137,   84,
  137,    0,  137,   81,  138,  138,   81,  138,  186,  138,
    0,  114,  114,    0,  114,  114,  114,  114,  114,  114,
   56,  114,    0,   56,    0,    0,    0,   56,   80,  135,
  135,   80,  135,    0,  135,    0,  138,  138,  138,  138,
  138,  138,    0,   73,   73,   73,   73,   73,   73,    0,
    0,    0,  111,  111,  184,  111,  111,  111,  111,  111,
  111,    0,  111,    0,    0,  106,  106,  106,  106,  106,
  106,   66,  195,    0,    0,    0,    0,    0,  189,  189,
  189,  189,    0,    0,    0,    0,  199,  109,  109,  109,
  109,  109,  109,    0,   91,   91,   91,   91,   91,   91,
    0,  209,    0,  117,  117,    0,    0,   92,   92,   92,
   92,   92,   92,  109,  109,  134,  109,  109,  109,  109,
  109,  109,    0,  109,    0,  229,  230,  231,   83,  136,
  136,   83,  136,    0,  136,   82,   96,   96,   82,   96,
   66,   96,    0,   66,    0,    0,    0,   66,    0,    0,
    0,    0,    0,  242,    0,  243,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  251,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  264,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  272,  134,  134,
  134,  134,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  117,  117,    0,  117,  117,  117,  117,
  117,  117,    0,  117,
};
static const short yycheck[] = {                         46,
    0,   40,   40,    2,   59,   45,    2,   44,  125,  125,
  182,  103,   11,    2,   13,   40,   42,   41,   80,   45,
   45,   44,   11,  212,   41,   46,  125,  258,   42,   46,
   11,  125,   41,   47,   41,   59,   59,   40,   11,   38,
   61,  103,   59,   42,   61,  125,   45,  259,   41,   46,
   59,   50,   51,   42,   46,   41,   45,  259,   41,   59,
   46,   41,   42,   43,   45,   45,   59,   47,  240,   45,
  259,   40,   71,   59,   46,   61,   59,  266,  170,   59,
   79,   80,   46,   82,   83,   84,   85,   41,   87,   61,
   44,   80,   41,  265,   83,   44,   40,   61,   87,   80,
   41,   45,   83,   79,  103,   44,   87,   80,  170,   80,
   83,   46,   83,   41,   87,   40,   87,   40,   46,   59,
   59,  259,   61,   61,   59,  125,  125,  103,   46,  128,
   40,   59,   44,   61,   46,  259,  173,  174,  137,    2,
  289,  290,  259,  259,  143,   41,  183,   59,   11,   61,
   46,  259,   44,   44,  259,   46,  123,   59,  157,   40,
   46,  269,  270,   59,  163,   61,  274,   59,   59,   61,
   61,  170,   46,  172,   40,   38,  175,   60,   40,   62,
  259,  123,   41,  182,   44,   11,  175,   44,   40,   46,
  289,  290,   46,  182,  170,  289,  290,  196,  197,  198,
   41,  241,   59,  202,   61,  204,  202,  262,  263,  289,
  290,   59,   38,  202,   41,  241,   44,   80,   46,  257,
   83,   40,  269,  270,   87,  224,   40,  226,   54,  268,
   40,   59,  257,   61,  259,  260,  275,  236,  262,  263,
  239,  240,  241,  239,  269,  270,   59,   59,  269,  270,
  239,  240,  241,  252,   80,  262,  263,   83,  268,  259,
  241,   87,  125,   41,   45,  241,  265,  259,  267,  268,
   40,  267,  271,  273,  274,  271,  265,   41,  267,   11,
  143,  281,  271,  283,  284,  285,  286,  287,  288,  289,
  290,   40,   40,  293,  157,  123,   41,   45,  123,  125,
  163,   41,  259,   59,   40,  282,   38,   41,   46,  172,
  123,   41,  175,  257,  258,  259,  260,  143,   41,  182,
   41,  262,  263,   40,   59,  269,  270,   41,   41,   58,
  274,  157,  259,  196,  197,  198,  257,  163,   41,  202,
   59,   41,   42,   43,   41,   45,  172,   47,   80,  293,
   58,   83,  296,   40,   59,   87,   41,  269,  270,   59,
   41,  224,    0,  226,  276,  277,  278,  279,   59,  125,
  196,  197,  198,  236,   41,   59,  239,  240,  269,  270,
  123,  264,  265,  266,  267,  276,  277,  278,  279,  252,
  125,   59,   41,  125,   59,   41,   42,   43,  224,   45,
  226,   47,  265,   61,  267,  268,   61,   41,  271,  241,
  236,  143,  163,   59,   60,  246,   62,  170,  244,  276,
  277,  278,  279,   -1,   -1,  157,  252,   42,   43,   -1,
   45,  163,   47,   -1,   -1,   41,   42,   43,   44,   45,
  172,   47,  268,   -1,   -1,   -1,  259,   -1,  276,  277,
  278,  279,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
  273,  274,   -1,   -1,  196,  197,  198,   -1,  281,   -1,
  283,  284,  285,  286,  287,  288,  257,   -1,  259,   -1,
  293,   41,   42,   43,   44,   45,   46,   47,  269,  270,
   42,   43,  224,   45,  226,   47,   -1,   -1,   -1,   59,
   60,   61,   62,  259,  236,  138,  139,  140,  141,  257,
  258,  259,  260,   -1,   -1,   -1,   -1,  273,  274,   -1,
  252,  269,  270,   -1,  259,  281,   -1,  283,  284,  285,
  286,  287,  288,   -1,   -1,   -1,  268,  293,  273,  274,
  259,   41,   42,   43,   -1,   45,  281,   47,  283,  284,
  285,  286,  287,  288,  273,  274,   -1,   -1,  293,   59,
   -1,   -1,  281,   -1,  283,  284,  285,  286,  287,  288,
   -1,   -1,   -1,   -1,  293,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   59,   60,    4,   62,   41,   42,   43,   -1,   45,   11,
   47,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,   59,   60,   -1,   62,   41,   42,   43,   -1,
   45,   -1,   47,   41,   -1,   43,   44,   45,   -1,   -1,
   -1,   43,   44,   -1,   59,   60,   41,   62,   43,   44,
   45,   59,   60,   -1,   62,   -1,  262,  263,  264,  265,
  266,  267,   -1,   -1,   59,   60,   -1,   62,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   80,   -1,
   -1,   83,   43,   44,   -1,   87,   59,   -1,   -1,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,  266,  267,   59,  269,
  270,   11,   -1,   -1,   75,   76,   77,   78,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   59,  176,  177,  178,
  179,  180,  181,   43,   44,   59,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   55,   41,   42,   43,   44,
   45,   -1,   47,   41,   42,   43,   44,   45,  129,   47,
   -1,  173,  174,   -1,  176,  177,  178,  179,  180,  181,
   80,  183,   -1,   83,   -1,   -1,   -1,   87,   41,   42,
   43,   44,   45,   -1,   47,   -1,  262,  263,  264,  265,
  266,  267,   -1,  262,  263,  264,  265,  266,  267,   -1,
   -1,   -1,  173,  174,  125,  176,  177,  178,  179,  180,
  181,   -1,  183,   -1,   -1,  262,  263,  264,  265,  266,
  267,   11,  143,   -1,   -1,   -1,   -1,   -1,  138,  139,
  140,  141,   -1,   -1,   -1,   -1,  157,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
   -1,  172,   -1,   43,   44,   -1,   -1,  262,  263,  264,
  265,  266,  267,  173,  174,   55,  176,  177,  178,  179,
  180,  181,   -1,  183,   -1,  196,  197,  198,   41,   42,
   43,   44,   45,   -1,   47,   41,   42,   43,   44,   45,
   80,   47,   -1,   83,   -1,   -1,   -1,   87,   -1,   -1,
   -1,   -1,   -1,  224,   -1,  226,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  236,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  252,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  138,  139,
  140,  141,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  173,  174,   -1,  176,  177,  178,  179,
  180,  181,   -1,  183,
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
#line 396 "a.y"


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
	
	extern FILE* yyin; 
	yyin=fp;
	initLangX();
    yyparse();
	closeLangX();
	fclose(fp);
	
	printf("parse over!\n");
	return 0;
}
#line 712 "y.tab.c"

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
#line 65 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 69 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 70 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 71 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 72 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 77 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 78 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 79 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 11:
#line 84 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-2].sValue, NULL); }
break;
case 12:
#line 85 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-4].sValue , yystack.l_mark[-3].sValue, yystack.l_mark[-1].node); }
break;
case 13:
#line 90 "a.y"
	{ yyval.sValue = NULL; }
break;
case 14:
#line 91 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue; }
break;
case 15:
#line 96 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 16:
#line 97 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 17:
#line 101 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 18:
#line 102 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 19:
#line 103 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 20:
#line 108 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 21:
#line 109 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 22:
#line 111 "a.y"
	{ yyval.node = opr(THIS, 1 , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 23:
#line 118 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 24:
#line 119 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 25:
#line 124 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 26:
#line 125 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 27:
#line 126 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 28:
#line 127 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 29:
#line 132 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 30:
#line 133 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 31:
#line 134 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 32:
#line 135 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 33:
#line 140 "a.y"
	{  yyval.node = NULL; }
break;
case 34:
#line 141 "a.y"
	{ yyval.node = NULL; }
break;
case 35:
#line 142 "a.y"
	{ yyval.node = NULL; }
break;
case 36:
#line 147 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 37:
#line 151 "a.y"
	{ yyval.params = NULL; }
break;
case 38:
#line 152 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 39:
#line 156 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 40:
#line 157 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 41:
#line 158 "a.y"
	{ yyval.params = NULL; }
break;
case 42:
#line 162 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 43:
#line 163 "a.y"
	{ yyval.node = NULL; }
break;
case 44:
#line 168 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 45:
#line 169 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 46:
#line 174 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 47:
#line 175 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 180 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 49:
#line 181 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 50:
#line 182 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 51:
#line 186 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 52:
#line 187 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 53:
#line 191 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 54:
#line 192 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 55:
#line 196 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 56:
#line 197 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 57:
#line 202 "a.y"
	{ yyval.node = NULL ; }
break;
case 58:
#line 203 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 204 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 205 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 210 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 62:
#line 211 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 212 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 64:
#line 213 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 214 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 215 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 67:
#line 216 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 222 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 69:
#line 223 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 70:
#line 227 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 71:
#line 228 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 72:
#line 229 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 73:
#line 234 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 74:
#line 235 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 239 "a.y"
	{ yyval.args = NULL; }
break;
case 76:
#line 240 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 77:
#line 244 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 78:
#line 245 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 79:
#line 249 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 250 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 251 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 252 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 253 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 254 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 85:
#line 255 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 86:
#line 259 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 87:
#line 260 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 266 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 267 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 272 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 91:
#line 278 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 92:
#line 279 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 93:
#line 280 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 94:
#line 281 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 95:
#line 286 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 96:
#line 287 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 97:
#line 288 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 98:
#line 289 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 99:
#line 294 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 100:
#line 298 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 101:
#line 302 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 102:
#line 306 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 103:
#line 310 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 104:
#line 314 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 105:
#line 318 "a.y"
	{ yyval.node = xnull();}
break;
case 106:
#line 323 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 107:
#line 324 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 325 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 109:
#line 326 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 110:
#line 331 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 111:
#line 332 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 112:
#line 333 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 113:
#line 334 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 335 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 115:
#line 336 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 116:
#line 337 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 117:
#line 338 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 118:
#line 339 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 119:
#line 344 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 120:
#line 345 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 121:
#line 346 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 122:
#line 347 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 123:
#line 352 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 124:
#line 353 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 125:
#line 354 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 355 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 356 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 357 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 358 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 359 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 131:
#line 360 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 132:
#line 361 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 133:
#line 362 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 363 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 135:
#line 368 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 136:
#line 369 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 370 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 138:
#line 371 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 139:
#line 372 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 140:
#line 377 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 141:
#line 378 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 142:
#line 382 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 143:
#line 383 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 144:
#line 388 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 145:
#line 389 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 146:
#line 390 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 147:
#line 391 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 148:
#line 392 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 149:
#line 393 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1506 "y.tab.c"
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
