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
 int intValue;
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 55 "y.tab.c"

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

#define XINTEGER 257
#define TDOUBLE 258
#define TBOOL 259
#define IDENTIFIER 260
#define TSTRING 261
#define OP_CALC 262
#define AND_OP 263
#define OR_OP 264
#define LE_OP 265
#define GE_OP 266
#define EQ_OP 267
#define NE_OP 268
#define FUNC_OP 269
#define INC_OP 270
#define DEC_OP 271
#define FUNC_CALL 272
#define VAR_DECLAR 273
#define RESTRICT 274
#define THIS 275
#define EXTENDS 276
#define ARRAY_ELE 277
#define ADD_EQ 278
#define SUB_EQ 279
#define MUL_EQ 280
#define DIV_EQ 281
#define AUTO 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define FOR 286
#define DELETE 287
#define BREAK 288
#define RETURN 289
#define SWITCH 290
#define CASE 291
#define DEFAULT 292
#define CASE_LIST 293
#define CLAXX_BODY 294
#define NEW 295
#define CLAXX_MEMBER 296
#define CLAXX_FUNC_CALL 297
#define XNULL 298
#define NONASSOC 299
#define IFX 300
#define UMINUS 301
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   52,   52,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   51,   51,   35,   35,   36,   36,   36,   43,
   43,   43,   44,   44,   37,   37,   37,   37,   39,   39,
   39,   39,   40,   40,   40,    5,   47,   47,   48,   48,
   48,    7,    7,    6,    6,    6,    6,    3,    3,    8,
    8,    8,   32,   32,   33,   33,    9,    9,   12,   12,
   12,   12,    4,    4,    4,    4,    4,    4,    4,   42,
   42,   24,   24,   24,   16,   16,   49,   49,   50,   50,
   17,   17,   17,   17,   17,   17,   17,   11,   11,   18,
   18,   19,   14,   14,   14,   14,   31,   31,   31,   31,
   31,   25,   26,   27,   28,   28,   29,   30,   41,   23,
   23,   23,   23,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   15,   15,   15,   15,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   20,
   20,   20,   20,   20,   22,   22,   38,   38,   45,   46,
   13,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    4,    5,    0,    2,    1,    2,    1,    2,    1,    1,
    3,    6,    3,    3,    3,    3,    6,    3,    6,    9,
    6,    6,    8,   10,    5,    6,    0,    3,    1,    3,
    0,    2,    0,    2,    3,    5,    6,    1,    1,    5,
    7,    7,    1,    2,    4,    3,    5,    9,    0,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    1,    1,
    2,    1,    1,    2,    4,    1,    0,    1,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    3,    1,    1,
    1,    3,    3,    3,    3,    3,    1,    1,    1,    1,
    3,    5,    1,    1,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    4,    3,
    1,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   72,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   48,   49,   63,   64,  151,   66,   67,    0,   10,    0,
  152,    0,    0,   69,    0,    0,  153,    0,    0,    0,
    0,    0,  104,   71,    0,    0,    0,    0,    0,  106,
  105,    0,  108,    0,    0,    0,  109,    0,    0,    0,
    0,    0,   97,   74,  135,    0,  129,    0,    0,    0,
    0,    0,  137,  138,  139,    0,  103,    0,    7,    0,
    0,    0,    0,    0,    0,   44,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,    0,    0,  144,    0,
   79,    0,   81,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  142,    0,    0,
    0,  112,  140,  141,    0,    0,    0,   61,    0,   60,
   62,    0,   65,    0,    0,  123,  124,    0,    0,  107,
   91,   90,    0,   98,  125,  126,    0,    0,    0,    0,
    0,    0,    0,  154,    0,  155,  156,  157,    0,   45,
    0,  145,  146,    0,    0,  147,    0,    0,    0,  148,
  150,   39,    0,   43,    0,    0,    0,    0,   11,   19,
   17,    0,    0,    0,   15,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  101,    0,   99,    0,    0,   95,   96,    0,    0,
    0,    0,    0,    0,    0,    0,   38,    0,    0,    0,
   80,    0,   46,   18,   12,   16,    0,  121,  122,   43,
   89,    0,  117,  118,  119,  120,  115,  116,   57,    0,
    0,  149,    0,   92,    0,    0,  102,    0,    0,    0,
    0,   35,   40,   36,   42,    0,    0,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   53,    0,    0,
   31,   32,    0,    0,   88,   51,    0,   22,   29,    0,
   43,   52,   54,    0,   33,    0,    0,   43,    0,    0,
   30,   58,    0,    0,   34,
};
static const short yydgoto[] = {                          1,
  231,   16,   17,   18,   19,   20,  218,   21,   22,  116,
  232,  129,   23,   98,   99,  118,  101,  140,  141,   63,
   64,   25,  120,   26,   27,  121,  103,  123,  124,  106,
   71,  267,  268,   29,  184,  185,  107,   31,   32,   33,
   73,   34,   74,   35,   36,   37,   95,  173,  108,  109,
   42,    2,
};
static const short yysindex[] = {                         0,
    0,  333,  -36, -231,  -10,   17,   41,   73, -228,    0,
  113,   87, -221,    0,    0,    0,    0,   40,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   88,    0,   -9,
    0,   63, -193,    0,   70,   78,    0,  101, -110,  192,
 -114,   36,    0,    0,  -89,  192,  192, -229,  117,    0,
    0,  -20,    0, -221, -221,  127,    0,   21,  155,    0,
    0,    0,    0,    0,    0,  -29,    0,    0,    0,    0,
  109,  133,    0,    0,    0, -221,    0,  153,    0,  221,
  221,  221,  221,  -64,  113,    0, -221,  113, -221, -221,
  158,  113,  113,  -59,   80,    0,  165,    0,    0,    0,
    0,  -29,    0,    0,    0,    0,  133,  169,  170,  123,
 -100,  178,  177,  133,   63,    9,    0,    0,    0,  378,
  -29,    0,    0,    0,    0,   44,  -13,    0,  206,    0,
    0,  -35,    0,  192,   10,    0,    0, -221,  221,    0,
    0,    0,  233,    0,    0,    0, -221,  155,  155,  155,
  155,  236,  192,    0,  133,    0,    0,    0,  190,    0,
   15,    0,    0,  -46,  243,    0,  254,  262,  192,    0,
    0,    0,   -6,    0,   -2,  192,   31,  -84,    0,    0,
    0,  246,  -14,  -96,    0,  192,  192,  192,  253,  192,
  192,  192,  192,  192,  192,  253,  192,  270,  225,  274,
  279,    0,  288,    0,   82,   82,    0,    0,  198,  293,
   72,  192,  192,  192,  295,   81,    0,  272,  303, -221,
    0,  -64,    0,    0,    0,    0,  305,    0,    0,    0,
    0,   65,    0,    0,    0,    0,    0,    0,    0,   46,
  301,    0,  192,    0,  192, -126,    0,  257,  310,  320,
  321,    0,    0,    0,    0,  192,  317,    0,  301,  316,
  253, -229,  336,  337,   59,  322, -117,    0,   31,  121,
    0,    0,  341,  192,    0,    0,  345,    0,    0,  346,
    0,    0,    0,  359,    0,  362,  253,    0,  333,  192,
    0,    0,  333,  368,    0,
};
static const short yyrindex[] = {                         0,
    0,  410,   45,  358,    0,    0,    0,    0,    0,    0,
  360,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  455,  363,    0,    0,    0,    0,  300,    0,  377,
    0,    0,    0,    0,    0,    0,    0,  365,    0,    0,
    0,   69,    0,    0,    0,   -8,    0,    0,    0,   23,
  536,  624,    0,    0,    0,  665,    0,  766,  777,  785,
    0,  827,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  126,    0,    0,  423,  798,    0,  857,
    0,  950,    0,  983, 1024, 1038,  464,    0,  389,    0,
    0,   33,  371,  373,    0,    0,  699,    0,  721,   -1,
  654,    0,    0,    0,  755,    0,   74,    0,    0,    0,
    0,    0,    0,  377,    0,    0,    0,    0,    0,    0,
    0,    0,  166,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  377,    0,    0,    0,    0,    0,   58,    0,
    0,    0,    0,  665,   62,    0,  527,  588,  377,    0,
    0,    0,    0,    0,  384,    0,  376,   77,    0,    0,
    0,    0,    0,    0,    0,  377,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   13,
    0,    0,  595,    0,  712,  744,    0,    0,    0,    0,
    0,  377,  377,  377,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
  692,    0,  377,    0,  377,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  377,  617,    0,    0,    0,
    0,  403,    0,    0,    0,    0,    0,    0,    0,   27,
    0,    0,    0,  377,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -111,  377,
    0,    0, -109,    0,    0,
};
static const short yygindex[] = {                         0,
   11,    0,    0,    0,  -77,  143, -212,    0,    0,  -25,
 -184,  183,  -45,  957,   -5,  146,  271,    0,    0,  866,
   52,  -62,  281,    0,  114,    8,  846,  245,  308,  985,
   39,    0,  179,    0,    0,  264,  167,    0,  -43,    0,
    0,    0,    0,    0,  302,    0,    0,    0,  652,    0,
    0,    0,
};
#define YYTABLESIZE 1182
static const short yytable[] = {                        147,
   50,  115,  130,   40,  115,   61,  211,  282,   84,   28,
  147,  239,   15,   56,   85,   55,  147,  260,   66,  134,
   78,  126,  163,   86,  179,   85,  186,   43,  225,   84,
  127,   49,   20,  180,  217,   45,   89,  216,   77,  114,
   54,   55,  131,  220,   86,    5,   85,  102,  182,  189,
   20,   88,  113,   21,   41,  132,   46,  114,   84,   50,
  139,  136,  137,  130,   99,   99,   91,   99,  289,   99,
  135,   21,   29,   86,  222,  293,  276,   41,  103,   61,
   47,  130,   61,  152,  196,   29,   61,   61,  103,  223,
  103,  161,  164,  103,  165,   66,  167,  168,   79,   66,
   66,  103,  292,  103,  262,  103,  180,   25,   90,  103,
  103,  103,   48,  103,  103,  103,  103,  103,  183,  103,
  103,  182,   25,  150,   65,   50,   76,  103,  151,  103,
   92,   84,  103,   87,  103,  103,  162,  103,   93,  166,
   94,  102,  110,  170,  171,  200,   86,   24,   85,   96,
  150,  148,   59,  149,  203,  151,   62,   58,  111,  178,
  102,  228,  229,  178,  265,  266,   41,   13,   30,   41,
  112,  240,  138,  265,  266,  133,  102,   72,   89,   56,
   56,   55,   55,  102,   38,  100,  205,  206,  207,  208,
  128,  183,  153,  102,   59,  159,   28,  169,   65,   58,
  172,   65,  174,   28,  134,   65,   65,   99,   99,  175,
   99,  114,   99,  176,   30,  177,  130,  186,  115,  102,
  102,  102,  147,  145,  146,   28,  160,  257,  255,  161,
   62,   59,   38,   62,  145,  146,   58,   62,   62,   39,
  145,  146,   80,   81,   82,   83,  155,  155,  155,  155,
  102,   72,  102,  181,   72,   68,  131,  219,   72,   72,
   50,  114,  114,  102,  197,   58,  199,   28,   28,  132,
  255,  187,  188,  202,   50,   50,  209,   50,   51,  100,
  211,  102,  212,   50,  104,   50,   50,   50,   50,   50,
   50,   50,   50,  213,   28,   50,   28,  102,  100,  255,
   28,  214,  142,  255,  224,  155,  187,  188,  187,  188,
  241,   14,   75,  243,  100,   50,   51,  242,   69,  244,
  246,  100,  103,  103,  103,  103,  181,  245,  248,   68,
   14,  100,   68,  247,   24,  252,   68,   68,  103,  103,
  253,   24,  256,  103,  103,  259,  220,  105,  261,  269,
  270,  103,  103,  103,  103,   30,  274,  100,  100,  100,
  271,  272,   30,   24,  258,   80,   81,   82,   83,   50,
   51,   43,   52,   53,   14,  230,  278,  279,  104,  281,
  284,  285,   54,   55,   30,  287,   75,   56,  100,   75,
  100,   14,   69,   75,   75,   69,  254,  104,  290,   69,
   69,  100,  291,  288,  128,   24,   24,   13,  295,    1,
   57,   50,   51,  104,   97,   53,   70,   77,   73,  100,
  104,   68,   37,   59,   54,   55,   30,   30,   30,   78,
  104,   23,   24,   24,   24,  100,  149,  195,   24,  194,
  275,  105,   75,   59,  277,  283,  221,  226,   50,   51,
   43,   97,   53,   30,    0,   30,  104,  104,  104,   30,
  105,   54,   55,  103,  103,  103,  103,  103,  103,  103,
  233,  234,  235,  236,  237,  238,  105,   50,   51,    0,
   97,  103,  103,  105,  103,    0,    0,  104,    0,  104,
   54,   55,    0,  105,    0,   76,   76,   76,   76,   76,
  104,   76,    0,    0,  100,  100,  100,  100,  100,  280,
  100,    0,    3,   76,   76,    0,   76,    0,  104,  105,
  105,  105,  100,  100,    0,  100,    4,    5,    0,    0,
    0,    3,    0,    0,  104,    6,    0,    7,    8,    9,
   10,   11,   12,    0,    0,    4,    5,   13,    0,    0,
  105,    0,  105,    0,    6,    0,    7,    8,    9,   10,
   11,   12,    0,  105,    0,    0,   13,   28,   28,   28,
   28,   28,   28,   28,    0,    3,  134,  144,  144,    0,
  144,  105,  144,    0,    0,   28,   28,   28,   28,    4,
    5,    0,    3,    0,  134,    0,    0,  105,    6,    0,
    7,    8,    9,   10,   11,   12,    4,    5,    0,    0,
   13,    0,    0,    0,    0,    6,    0,    7,    8,    9,
   10,   11,   12,    0,    0,    0,    0,   13,   26,   26,
   26,   26,   26,   26,   26,   25,   25,   25,   25,   25,
   25,   25,  190,  191,  192,  193,   26,   26,   26,   26,
    0,    0,    0,   25,   25,   25,   25,   27,   27,   27,
   27,   27,   27,   27,  131,  142,  142,    0,  142,    0,
  142,    0,    0,    0,    0,   27,   27,   27,   27,    0,
    0,    0,  131,    0,    0,  103,  103,  103,  103,  103,
  103,    0,  103,  103,  143,  143,  143,  143,  143,    0,
  143,    0,    0,    0,    0,  132,  143,  143,    0,  143,
    0,  143,  143,  143,    0,  143,    0,   76,   76,   76,
   76,   76,   76,  132,    0,    0,  100,  100,  100,  100,
  100,  100,   75,   75,   75,   75,   75,    0,   75,  111,
   99,   99,    0,   99,    0,   99,    0,    0,    0,    0,
   75,   75,   93,   75,   93,   93,   93,  111,  111,    0,
  111,  110,   97,   97,    0,   97,    0,   97,    0,    0,
   93,   93,    0,   93,    0,    0,    0,    0,    0,  110,
  110,    0,  110,    0,   94,  198,   94,   94,   94,   28,
   28,   28,   28,   28,   28,  113,   98,   98,    0,   98,
    0,   98,   94,   94,  210,   94,  127,  140,  140,    0,
  140,    0,  140,  113,  113,    0,  113,  128,  141,  141,
  215,  141,    0,  141,  127,  133,   98,   98,    0,   98,
    0,   98,    0,    0,    0,  128,    0,  227,   87,   99,
   99,   87,   99,  133,   99,    0,    0,    0,    0,   44,
   26,   26,   26,   26,   26,   26,   67,   25,   25,   25,
   25,   25,   25,  249,  250,  251,    0,  136,  100,  100,
    0,  100,    0,  100,    0,    0,    0,    0,    0,   27,
   27,   27,   27,   27,   27,  136,    0,    0,    0,    0,
    0,  122,  122,    0,  263,    0,  264,   86,  142,  142,
   86,  142,    0,  142,    0,    0,    0,  273,    0,    0,
    0,  119,  119,    0,    0,    0,  143,  143,  143,  143,
  143,  143,    0,    0,    0,  286,    0,    0,    0,    0,
   67,    0,    0,   67,    0,    0,    0,   67,   67,    0,
    0,  294,    0,    0,    0,  154,  156,  157,  158,    0,
    0,    0,    0,    0,   75,   75,   75,   75,   75,   75,
    0,  111,  111,  111,  111,  111,  111,   60,    0,    0,
    0,    0,    0,    0,   93,   93,   93,   93,   93,   93,
    0,    0,    0,  110,  110,  110,  110,  110,  110,    0,
   83,  143,  143,   83,  143,   70,  143,    0,    0,    0,
    0,    0,  117,  117,  201,    0,   94,   94,   94,   94,
   94,   94,    0,    0,    0,  143,    0,  113,  113,  113,
  113,  113,  113,   82,  140,  140,   82,  140,    0,  140,
  125,  125,  122,  122,    0,  122,  122,  122,  122,  122,
  122,   60,  122,  144,   60,    0,    0,    0,   60,   60,
    0,    0,  119,  119,    0,  119,  119,  119,  119,  119,
  119,    0,  119,    0,   85,  141,  141,   85,  141,   70,
  141,    0,   70,    0,    0,    0,   70,   70,   84,   98,
   98,   84,   98,    0,   98,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  204,  204,  204,  204,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  144,  144,  144,  144,    0,    0,    0,    0,
    0,    0,    0,  117,  117,    0,  117,  117,  117,  117,
  117,  117,    0,  117,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  125,  125,    0,  125,  125,  125,  125,  125,  125,
    0,  125,
};
static const short yycheck[] = {                         46,
    0,   45,   48,   40,   48,   11,   91,  125,   44,    2,
   46,  196,    2,  125,   61,  125,   46,  230,   11,   40,
   13,   47,   85,   59,  125,   61,   40,  259,  125,   44,
  260,  260,   41,  111,   41,   46,   46,   44,  260,   41,
  270,  271,   48,   46,   59,  275,   61,   40,  111,   41,
   59,   61,   45,   41,   91,   48,   40,   59,   44,   59,
   40,   54,   55,   41,   42,   43,  260,   45,  281,   47,
   91,   59,   46,   59,   44,  288,  261,   91,   46,   85,
   40,   59,   88,   76,   41,   59,   92,   93,   44,   59,
   46,   84,   85,   61,   87,   88,   89,   90,   59,   92,
   93,   44,  287,   59,   59,   61,  184,   46,   46,   41,
   42,   43,   40,   45,   46,   47,   59,   44,  111,   46,
   44,  184,   61,   42,   11,  125,   40,   59,   47,   61,
   61,   44,   59,   46,   61,   59,   85,   61,   61,   88,
   40,  134,  257,   92,   93,  138,   59,    2,   61,  260,
   42,   43,   40,   45,  147,   47,   11,   45,  123,  260,
  153,  187,  188,  260,  291,  292,   41,  123,    2,   44,
  260,  197,   46,  291,  292,   59,  169,   11,   46,  291,
  292,  291,  292,  176,  269,   40,  148,  149,  150,  151,
   48,  184,   40,  186,   40,  260,  189,   40,   85,   45,
  260,   88,  123,  196,   40,   92,   93,   42,   43,   41,
   45,   45,   47,   44,   48,   93,  262,   40,  262,  212,
  213,  214,   46,  270,  271,  218,   84,  220,  218,  222,
   85,   40,  269,   88,  270,  271,   45,   92,   93,  276,
  270,  271,  278,  279,  280,  281,   80,   81,   82,   83,
  243,   85,  245,  111,   88,   11,  262,  260,   92,   93,
  260,  263,  264,  256,   59,   45,  257,  260,  261,  262,
  260,  263,  264,   41,  274,  275,   41,  257,  258,  134,
   91,  274,   40,  283,   40,  285,  286,  287,  288,  289,
  290,  291,  292,   40,  287,  295,  289,  290,  153,  289,
  293,   40,   58,  293,   59,  139,  263,  264,  263,  264,
   41,   59,   11,   40,  169,  257,  258,   93,   11,   41,
  123,  176,  278,  279,  280,  281,  184,   40,  257,   85,
   59,  186,   88,   41,  189,   41,   92,   93,  270,  271,
  260,  196,   40,  270,  271,   41,   46,   40,  284,   93,
   41,  278,  279,  280,  281,  189,   40,  212,  213,  214,
   41,   41,  196,  218,  222,  278,  279,  280,  281,  257,
  258,  259,  260,  261,   59,  123,   41,   41,  134,   58,
  260,   41,  270,  271,  218,   41,   85,  275,  243,   88,
  245,   59,   85,   92,   93,   88,  125,  153,   40,   92,
   93,  256,   41,   58,  262,  260,  261,  295,   41,    0,
  298,  257,  258,  169,  260,  261,   59,   41,   59,  274,
  176,   59,  123,   59,  270,  271,  260,  261,  262,   41,
  186,   61,  287,   61,  289,  290,   61,   60,  293,   62,
  125,  134,   59,   41,  262,  267,  176,  184,  257,  258,
  259,  260,  261,  287,   -1,  289,  212,  213,  214,  293,
  153,  270,  271,   41,   42,   43,   44,   45,   46,   47,
  190,  191,  192,  193,  194,  195,  169,  257,  258,   -1,
  260,   59,   60,  176,   62,   -1,   -1,  243,   -1,  245,
  270,  271,   -1,  186,   -1,   41,   42,   43,   44,   45,
  256,   47,   -1,   -1,   41,   42,   43,   44,   45,  265,
   47,   -1,  260,   59,   60,   -1,   62,   -1,  274,  212,
  213,  214,   59,   60,   -1,   62,  274,  275,   -1,   -1,
   -1,  260,   -1,   -1,  290,  283,   -1,  285,  286,  287,
  288,  289,  290,   -1,   -1,  274,  275,  295,   -1,   -1,
  243,   -1,  245,   -1,  283,   -1,  285,  286,  287,  288,
  289,  290,   -1,  256,   -1,   -1,  295,   41,   42,   43,
   44,   45,   46,   47,   -1,  260,   41,   42,   43,   -1,
   45,  274,   47,   -1,   -1,   59,   60,   61,   62,  274,
  275,   -1,  260,   -1,   59,   -1,   -1,  290,  283,   -1,
  285,  286,  287,  288,  289,  290,  274,  275,   -1,   -1,
  295,   -1,   -1,   -1,   -1,  283,   -1,  285,  286,  287,
  288,  289,  290,   -1,   -1,   -1,   -1,  295,   41,   42,
   43,   44,   45,   46,   47,   41,   42,   43,   44,   45,
   46,   47,  265,  266,  267,  268,   59,   60,   61,   62,
   -1,   -1,   -1,   59,   60,   61,   62,   41,   42,   43,
   44,   45,   46,   47,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   59,   -1,   -1,  263,  264,  265,  266,  267,
  268,   -1,  270,  271,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   59,   60,   -1,   62,   -1,  263,  264,  265,
  266,  267,  268,   59,   -1,   -1,  263,  264,  265,  266,
  267,  268,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   59,   60,   41,   62,   43,   44,   45,   59,   60,   -1,
   62,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   41,  134,   43,   44,   45,  263,
  264,  265,  266,  267,  268,   41,   42,   43,   -1,   45,
   -1,   47,   59,   60,  153,   62,   41,   42,   43,   -1,
   45,   -1,   47,   59,   60,   -1,   62,   41,   42,   43,
  169,   45,   -1,   47,   59,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   59,   -1,  186,   41,   42,
   43,   44,   45,   59,   47,   -1,   -1,   -1,   -1,    4,
  263,  264,  265,  266,  267,  268,   11,  263,  264,  265,
  266,  267,  268,  212,  213,  214,   -1,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  263,
  264,  265,  266,  267,  268,   59,   -1,   -1,   -1,   -1,
   -1,   46,   47,   -1,  243,   -1,  245,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,  256,   -1,   -1,
   -1,   46,   47,   -1,   -1,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,   -1,  274,   -1,   -1,   -1,   -1,
   85,   -1,   -1,   88,   -1,   -1,   -1,   92,   93,   -1,
   -1,  290,   -1,   -1,   -1,   80,   81,   82,   83,   -1,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   -1,  263,  264,  265,  266,  267,  268,   11,   -1,   -1,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   -1,
   41,   42,   43,   44,   45,   11,   47,   -1,   -1,   -1,
   -1,   -1,   46,   47,  139,   -1,  263,  264,  265,  266,
  267,  268,   -1,   -1,   -1,   59,   -1,  263,  264,  265,
  266,  267,  268,   41,   42,   43,   44,   45,   -1,   47,
   46,   47,  187,  188,   -1,  190,  191,  192,  193,  194,
  195,   85,  197,   59,   88,   -1,   -1,   -1,   92,   93,
   -1,   -1,  187,  188,   -1,  190,  191,  192,  193,  194,
  195,   -1,  197,   -1,   41,   42,   43,   44,   45,   85,
   47,   -1,   88,   -1,   -1,   -1,   92,   93,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  148,  149,  150,  151,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  148,  149,  150,  151,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  187,  188,   -1,  190,  191,  192,  193,
  194,  195,   -1,  197,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  187,  188,   -1,  190,  191,  192,  193,  194,  195,
   -1,  197,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"XINTEGER","TDOUBLE","TBOOL","IDENTIFIER",
"TSTRING","OP_CALC","AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP",
"INC_OP","DEC_OP","FUNC_CALL","VAR_DECLAR","RESTRICT","THIS","EXTENDS",
"ARRAY_ELE","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE",
"FOR","DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT","CASE_LIST",
"CLAXX_BODY","NEW","CLAXX_MEMBER","CLAXX_FUNC_CALL","XNULL","NONASSOC","IFX",
"UMINUS",
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
"var_declar_stmt : IDENTIFIER '[' XINTEGER ']' ';'",
"var_declar_stmt : IDENTIFIER '[' XINTEGER ']' ',' var_declar_stmt",
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
"double_expr : XINTEGER",
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
"assign_stmt_value : array_ele_stmt",
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
"single_assign_stmt : id_expr '=' single_assign_stmt",
"class_member_assign_stmt : class_member_stmt '=' assign_stmt_value",
"class_member_assign_stmt : this_member_stmt '=' assign_stmt_value",
"array_ele_stmt : IDENTIFIER '[' XINTEGER ']'",
"array_ele_assign_stmt : array_ele_stmt '=' assign_stmt_value",
"assign_stmt : single_assign_stmt",
"assign_stmt : class_member_assign_stmt",
"assign_stmt : array_ele_assign_stmt",
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
#line 416 "a.y"


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
#line 774 "y.tab.c"

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
#line 70 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 74 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 75 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 76 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 77 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 82 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 83 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 84 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 11:
#line 89 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-2].sValue, NULL); }
break;
case 12:
#line 90 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-4].sValue , yystack.l_mark[-3].sValue, yystack.l_mark[-1].node); }
break;
case 13:
#line 95 "a.y"
	{ yyval.sValue = NULL; }
break;
case 14:
#line 96 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue; }
break;
case 15:
#line 101 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 16:
#line 102 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 17:
#line 106 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 18:
#line 107 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 19:
#line 108 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 20:
#line 113 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 21:
#line 114 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 22:
#line 116 "a.y"
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
#line 173 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,yystack.l_mark[-2].intValue) ); }
break;
case 47:
#line 174 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,yystack.l_mark[-3].intValue),yystack.l_mark[0].node); }
break;
case 48:
#line 179 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 49:
#line 180 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 50:
#line 185 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 51:
#line 186 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 52:
#line 187 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 53:
#line 191 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 54:
#line 192 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 55:
#line 196 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 56:
#line 197 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 57:
#line 201 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 58:
#line 202 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 59:
#line 207 "a.y"
	{ yyval.node = NULL ; }
break;
case 60:
#line 208 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 209 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 62:
#line 210 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 215 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 216 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 217 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
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
#line 220 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 69:
#line 221 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 70:
#line 227 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 71:
#line 228 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 72:
#line 232 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 73:
#line 233 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 74:
#line 234 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 75:
#line 239 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 76:
#line 240 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 77:
#line 244 "a.y"
	{ yyval.args = NULL; }
break;
case 78:
#line 245 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 79:
#line 249 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 80:
#line 250 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 81:
#line 254 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 255 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 256 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 257 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 85:
#line 258 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 86:
#line 259 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 260 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 88:
#line 264 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 89:
#line 265 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 271 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 272 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 277 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 93:
#line 283 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 94:
#line 284 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 95:
#line 285 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 96:
#line 286 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
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
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 100:
#line 294 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 101:
#line 295 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 102:
#line 300 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 103:
#line 304 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 104:
#line 308 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 105:
#line 312 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 106:
#line 313 "a.y"
	{ yyval.node = number(yystack.l_mark[0].intValue); }
break;
case 107:
#line 317 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 108:
#line 321 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 109:
#line 325 "a.y"
	{ yyval.node = xnull();}
break;
case 110:
#line 330 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 111:
#line 331 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 112:
#line 332 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 113:
#line 333 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 114:
#line 338 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 115:
#line 339 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 116:
#line 340 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 117:
#line 341 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 118:
#line 342 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 119:
#line 343 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 120:
#line 344 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 121:
#line 345 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 122:
#line 346 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 123:
#line 351 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 124:
#line 352 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 125:
#line 353 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 126:
#line 354 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
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
#line 368 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 369 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 138:
#line 370 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 139:
#line 371 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 140:
#line 376 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 377 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 142:
#line 378 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 143:
#line 379 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 144:
#line 380 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 145:
#line 385 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 146:
#line 386 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 147:
#line 390 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 148:
#line 391 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 149:
#line 396 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, yystack.l_mark[-1].intValue); }
break;
case 150:
#line 402 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 151:
#line 407 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 152:
#line 408 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 153:
#line 409 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 154:
#line 410 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 155:
#line 411 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 156:
#line 412 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 157:
#line 413 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1600 "y.tab.c"
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
