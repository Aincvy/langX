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
   48,    7,    7,    6,    6,    6,    6,    6,    6,    3,
    3,    8,    8,    8,   32,   32,   33,   33,    9,    9,
   12,   12,   12,   12,    4,    4,    4,    4,    4,    4,
    4,   42,   42,   24,   24,   24,   16,   16,   49,   49,
   50,   50,   17,   17,   17,   17,   17,   17,   17,   11,
   11,   18,   18,   19,   14,   14,   14,   14,   31,   31,
   31,   31,   31,   25,   26,   27,   28,   28,   29,   30,
   41,   23,   23,   23,   23,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   15,   15,   15,   15,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   20,   20,   20,   20,   20,   22,   22,   38,   38,
   45,   45,   46,   13,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    4,    5,    0,    2,    1,    2,    1,    2,    1,    1,
    3,    6,    3,    3,    3,    3,    6,    3,    6,    9,
    6,    6,    8,   10,    5,    6,    0,    3,    1,    3,
    0,    2,    0,    2,    3,    5,    6,    5,    6,    1,
    1,    5,    7,    7,    1,    2,    4,    3,    5,    9,
    0,    1,    1,    1,    1,    1,    3,    1,    1,    1,
    1,    1,    2,    1,    1,    2,    4,    1,    0,    1,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    3,
    1,    1,    1,    3,    3,    3,    3,    3,    1,    1,
    1,    1,    3,    5,    1,    1,    1,    1,    2,    1,
    1,    1,    1,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    2,    2,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    3,    3,    3,
    4,    4,    3,    1,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   74,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   50,   51,   65,   66,  154,   68,   69,    0,   10,    0,
  155,    0,    0,   71,    0,    0,  156,    0,    0,    0,
    0,    0,  106,   73,    0,    0,    0,    0,    0,  108,
  107,    0,  110,    0,    0,    0,  111,    0,    0,    0,
    0,    0,   99,   76,  137,    0,  131,    0,    0,    0,
    0,    0,  139,  140,  141,    0,  105,    0,    7,    0,
    0,    0,    0,    0,    0,   44,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,    0,    0,  146,    0,
   81,    0,   83,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  144,    0,
    0,    0,  114,  142,  143,    0,    0,    0,   63,    0,
   62,   64,    0,   67,    0,    0,  125,  126,    0,    0,
  109,   93,   92,    0,  100,  127,  128,    0,    0,    0,
    0,    0,    0,    0,  157,    0,  158,  159,  160,    0,
   45,    0,  147,  148,    0,    0,  149,    0,    0,    0,
  150,  153,   39,    0,   43,    0,    0,    0,    0,    0,
   11,   19,   17,    0,    0,    0,   15,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  103,    0,  101,    0,    0,   97,
   98,    0,    0,    0,    0,    0,    0,    0,    0,   38,
    0,    0,    0,   82,    0,   46,    0,   48,   18,   12,
   16,    0,  123,  124,   43,   91,    0,  119,  120,  121,
  122,  117,  118,   59,    0,    0,  151,  152,    0,   94,
    0,    0,  104,    0,    0,    0,    0,    0,   35,   40,
   36,   42,    0,    0,   47,   49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   55,    0,    0,    0,   31,
   32,    0,    0,   90,   53,    0,   22,   29,    0,   43,
   54,   56,    0,   33,    0,    0,   43,    0,    0,   30,
   60,    0,    0,   34,
};
static const short yydgoto[] = {                          1,
  236,   16,   17,   18,   19,   20,  221,   21,   22,  117,
  237,  130,   23,   98,   99,  119,  101,  141,  142,   63,
   64,   25,  121,   26,   27,  122,  103,  124,  125,  106,
   71,  275,  276,   29,  186,  187,  107,   31,   32,   33,
   73,   34,   74,   35,   36,   37,   95,  174,  108,  109,
   42,    2,
};
static const short yysindex[] = {                         0,
    0,  286,  -37, -222,   11,   19,   23,   27, -191,    0,
  177,   67, -124,    0,    0,    0,    0,   94,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   98,    0,  -11,
    0,  141,  -95,    0,  134,  148,    0,  172,  -34,  159,
 -221,  108,    0,    0,  -26,  159,  159, -144,  189,    0,
    0,  -23,    0, -124, -124,  206,    0,   18,  193,    0,
    0,    0,    0,    0,    0,    2,    0,    0,    0,    0,
   51,  209,    0,    0,    0, -124,    0,  218,    0,  185,
  185,  185,  185,    4,  177,    0, -124,  177, -124, -124,
  220,  177,  177,   10,  139,    0,  239,    0,    0,    0,
    0,    2,    0,    0,    0,    0,  209,  241,  240,  194,
  197, -120,  252,  249,  209,  141,   43,    0,    0,    0,
  420,    2,    0,    0,    0,    0,   68,  -19,    0,  254,
    0,    0,  112,    0,  159, -110,    0,    0, -124,  185,
    0,    0,    0,  258,    0,    0,    0, -124,  193,  193,
  193,  193,  270,  159,    0,  209,    0,    0,    0,  226,
    0,    5,    0,    0,  -42,  280,    0,  285,  287,  159,
    0,    0,    0,  110,    0,  -40,  159,   21,   45,  -75,
    0,    0,    0,  275,   12, -111,    0,  159,  159,  159,
  227,  159,  159,  159,  159,  159,  159,  227,  159,  288,
  266,  267,  307,  331,    0,  341,    0,   59,   59,    0,
    0,  271,  354,  -90,  159,  159,  159,  356,  140,    0,
  246,  361, -124,    0,    4,    0,    4,    0,    0,    0,
    0,  362,    0,    0,    0,    0,  120,    0,    0,    0,
    0,    0,    0,    0,  -58,  359,    0,    0,  159,    0,
  159,  -89,    0,  313,  315,  369,  370,  372,    0,    0,
    0,    0,  159,  374,    0,    0,  359,  264,  227, -144,
  382,  383,   52,  367, -115,    0,   21,   45,  167,    0,
    0,  385,  159,    0,    0,  387,    0,    0,  381,    0,
    0,    0,  392,    0,  399,  227,    0,  286,  159,    0,
    0,  286,  403,    0,
};
static const short yyrindex[] = {                         0,
    0,  446,  219,  390,    0,    0,    0,    0,    0,    0,
  400,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  608,  406,    0,    0,    0,    0,  335,    0,  425,
    0,    0,    0,    0,    0,    0,    0,  408,    0,    0,
    0,  -17,    0,    0,    0,  -14,    0,    0,    0,  448,
  521,  737,    0,    0,    0,  744,    0,  811,  840,  869,
    0,  962,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  166,    0,    0,  541,  119,    0,  778,
    0,  981,    0,  992, 1006, 1026,  630,    0,  429,    0,
    0,    0,   71,  410,  412,    0,    0,  666,    0,  688,
   38,  637,    0,    0,    0,  695,    0,  198,    0,    0,
    0,    0,    0,    0,  425,    0,    0,    0,    0,    0,
    0,    0,    0,   96,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  425,    0,    0,    0,    0,    0,   75,
    0,    0,    0,    0,  744,   74,    0,  550,  572,  425,
    0,    0,    0,    0,    0,  415,    0,  422,  423,   17,
    0,    0,    0,    0,    0,    0,    0,  425,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -8,    0,    0,  579,    0,  708,  715,    0,
    0,    0,    0,    0,  425,  425,  425,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   66,    0,    0,    0,
    0,    0,    0,    0,    0,  659,    0,    0,  425,    0,
  425,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  425,  601,    0,    0,    0,    0,    0,  440,
    0,    0,    0,    0,    0,    0,    0,    0,   16,    0,
    0,    0,  425,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -113,  425,    0,
    0,  -91,    0,    0,
};
static const short yygindex[] = {                         0,
    6,    0,    0,    0, -105,  300, -220,    0,    0,  125,
 -166,  215,  -46,  953,    7,   20,  311,    0,    0,  746,
  251,  -72,  170,    0,   30,   -2,  902,  158,  245,  973,
  236,    0,  217,    0,    0,  317,  100,    0,  -25,    0,
    0,    0,    0,    0,   36,    0,    0,    0,  939,    0,
    0,    0,
};
#define YYTABLESIZE 1238
static const short yytable[] = {                         28,
  270,  131,   40,  148,  181,  223,  182,   15,   66,  291,
   78,   58,  164,  230,  268,  214,  135,   61,   85,  116,
  188,   24,  116,  105,  105,  105,   20,  105,  105,  105,
   62,  244,   21,   57,   89,  110,   43,  102,  111,  184,
   65,  105,  114,  105,   20,  133,   75,  148,   84,   88,
   21,  137,  138,   41,  132,   84,   45,  140,   46,  100,
  105,   29,   47,   86,  225,   52,   48,  136,   49,  298,
   86,   41,   85,  153,   29,  105,  302,  105,  116,  226,
  182,  162,  165,  191,  166,   66,  168,  169,  227,   66,
   66,   61,  151,  149,   61,  150,  116,  152,   61,   61,
  151,   30,  285,  228,   62,  152,   76,   62,  198,  185,
   72,   62,   62,  184,   65,  128,  105,   65,  105,   25,
   75,   65,   65,   75,   52,   54,   55,   75,   75,  301,
    5,  105,  102,  105,   25,   77,  203,  101,  101,  180,
  101,   84,  101,   87,  115,  206,  201,   30,  180,  202,
  220,  102,   79,  219,  100,   84,   86,  148,   85,   89,
  101,  101,   89,  101,   91,  101,  254,  102,   68,  255,
   86,  127,   85,  100,  102,  273,  274,   58,   58,  156,
  156,  156,  156,  185,   72,  102,   90,   72,   28,  100,
   52,   72,   72,   38,   92,   28,  100,  104,   59,   57,
   57,  273,  274,   58,  189,  190,   41,  100,   93,   41,
   24,   94,  102,  102,  102,  143,   59,   24,   28,  222,
  264,   58,  162,  131,  162,   96,  262,  146,  147,   58,
  112,   38,   59,  113,  100,  100,  100,   58,   39,  156,
   24,  105,   68,  105,  116,   68,  102,  134,  102,   68,
   68,  139,  105,  105,   89,   69,  105,  154,  105,  170,
  102,  175,  105,  160,  105,   28,   28,  133,  100,  173,
  100,  146,  147,  262,   50,   51,  132,  105,  135,  105,
  102,  176,  100,  177,  105,   14,  178,   24,   24,  179,
   30,  188,  104,   28,  148,   28,  102,   30,  205,   28,
  116,  116,  100,  262,   14,  189,  190,  262,   50,   51,
  212,  104,  199,  233,  234,   24,  214,   24,  100,  215,
   30,   24,   14,  245,  216,   52,  217,  104,  246,   69,
  189,  190,   69,  229,  104,  163,   69,   69,  167,   52,
   52,   13,  171,  172,   14,  104,  249,  129,   52,  235,
   52,   52,   52,   52,   52,   52,   52,   52,  247,  248,
   52,  238,  239,  240,  241,  242,  243,   30,   30,   30,
  261,  250,  104,  104,  104,   80,   81,   82,   83,  105,
  251,  146,  147,  161,  208,  209,  210,  211,  284,   80,
   81,   82,   83,  252,  253,   30,  259,   30,  105,  260,
  263,   30,  267,  269,  223,  277,  104,  278,  104,  279,
  280,  183,  281,  283,  105,   50,   51,   43,   97,   53,
  104,  105,  287,  288,  290,  294,  293,  296,   54,   55,
  289,  299,  105,   50,   51,   43,   52,   53,  297,  300,
  104,   50,   51,  304,   97,    1,   54,   55,   72,   50,
   51,   56,   97,   53,   54,   55,  104,   37,   75,  105,
  105,  105,   54,   55,   70,   79,   61,  105,  105,   80,
   23,   13,   24,   77,   57,  105,  105,  105,  105,  197,
   61,  196,  151,  152,  286,  183,    3,  224,  132,  101,
  101,  292,  101,  105,  101,  105,  105,  105,  105,  105,
    4,    5,  231,    0,    0,    3,  132,  105,    0,    6,
    0,    7,    8,    9,   10,   11,   12,    0,    0,    4,
    5,   13,    0,    3,  265,    0,  266,  105,    6,    0,
    7,    8,    9,   10,   11,   12,    0,    4,    5,    0,
   13,    0,    0,  105,    0,    3,    6,    0,    7,    8,
    9,   10,   11,   12,    0,    0,    0,    0,   13,    4,
    5,  136,  146,  146,    0,  146,    0,  146,    6,  129,
    7,    8,    9,   10,   11,   12,    0,    0,    0,  136,
   13,  105,  105,  105,  105,  105,  105,  105,    0,    0,
   28,   28,   28,   28,   28,   28,   28,    0,    0,  105,
  105,    0,  105,    0,    0,    0,    0,    0,   28,   28,
   28,   28,   26,   26,   26,   26,   26,   26,   26,   25,
   25,   25,   25,   25,   25,   25,    0,    0,    0,    0,
   26,   26,   26,   26,    0,    0,    0,   25,   25,   25,
   25,   27,   27,   27,   27,   27,   27,   27,   78,   78,
   78,   78,   78,    0,   78,    0,    0,    0,    0,   27,
   27,   27,   27,    0,    0,    0,   78,   78,    0,   78,
  102,  102,  102,  102,  102,    0,  102,  145,  145,  145,
  145,  145,    0,  145,  192,  193,  194,  195,  102,  102,
    0,  102,    0,    0,    0,  145,  145,    0,  145,   77,
   77,   77,   77,   77,    0,   77,  113,  101,  101,    0,
  101,    0,  101,    0,    0,    0,    0,   77,   77,    0,
   77,    0,    0,    0,  113,  113,    0,  113,  112,   99,
   99,    0,   99,    0,   99,  115,  100,  100,    0,  100,
    0,  100,    0,    0,    0,    0,  112,  112,   95,  112,
   95,   95,   95,  115,  115,   96,  115,   96,   96,   96,
    0,    0,    0,    0,    0,    0,   95,   95,    0,   95,
    0,    0,    0,   96,   96,    0,   96,  133,  144,  144,
    0,  144,    0,  144,  134,  145,  145,    0,  145,    0,
  145,  120,  120,    0,    0,  133,    0,    0,    0,    0,
    0,    0,  134,  105,  105,  105,  105,  105,  105,    0,
  105,  105,   28,   28,   28,   28,   28,   28,   88,  144,
  144,   88,  144,    0,  144,  155,  157,  158,  159,    0,
    0,    0,    0,    0,   26,   26,   26,   26,   26,   26,
    0,   25,   25,   25,   25,   25,   25,    0,    0,    0,
    0,  129,  142,  142,    0,  142,    0,  142,    0,    0,
    0,    0,    0,   27,   27,   27,   27,   27,   27,  129,
   78,   78,   78,   78,   78,   78,    0,    0,    0,    0,
  130,  143,  143,    0,  143,  204,  143,    0,    0,    0,
    0,    0,  102,  102,  102,  102,  102,  102,  130,  145,
  145,  145,  145,  145,  145,   44,    0,    0,    0,  135,
  100,  100,   67,  100,    0,  100,    0,    0,    0,    0,
    0,   77,   77,   77,   77,   77,   77,  135,  113,  113,
  113,  113,  113,  113,  120,  120,    0,  120,  120,  120,
  120,  120,  120,    0,  120,    0,    0,  123,  123,    0,
  112,  112,  112,  112,  112,  112,    0,  115,  115,  115,
  115,  115,  115,   60,    0,    0,    0,    0,    0,    0,
   95,   95,   95,   95,   95,   95,    0,   96,   96,   96,
   96,   96,   96,   70,    0,    0,   67,    0,    0,   67,
    0,    0,    0,   67,   67,    0,    0,    0,  118,  118,
    0,    0,  138,  102,  102,    0,  102,    0,  102,    0,
    0,  144,    0,    0,    0,    0,    0,    0,  126,  126,
  138,   85,  145,  145,   85,  145,    0,  145,    0,    0,
    0,  145,   84,  142,  142,   84,  142,   60,  142,    0,
   60,    0,    0,    0,   60,   60,   87,  143,  143,   87,
  143,    0,  143,    0,    0,    0,    0,   70,    0,    0,
   70,    0,    0,    0,   70,   70,   86,  100,  100,   86,
  100,    0,  100,  200,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  123,  123,  213,  123,  123,  123,  123,  123,  123,    0,
  123,  207,  207,  207,  207,    0,    0,    0,  218,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  145,  145,  145,  145,    0,  232,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  118,  118,    0,  118,  118,  118,  118,  118,  118,
    0,  118,    0,  256,  257,  258,    0,    0,    0,    0,
    0,  126,  126,    0,  126,  126,  126,  126,  126,  126,
    0,  126,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  271,    0,  272,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  282,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  295,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  303,
};
static const short yycheck[] = {                          2,
   59,   48,   40,   46,  125,   46,  112,    2,   11,  125,
   13,  125,   85,  125,  235,   91,   40,   11,   61,   45,
   40,    2,   48,   41,   42,   43,   41,   45,   46,   47,
   11,  198,   41,  125,   46,  257,  259,   40,  260,  112,
   11,   59,   45,   61,   59,   48,   11,   46,   44,   61,
   59,   54,   55,   91,   48,   44,   46,   40,   40,   40,
   44,   46,   40,   59,   44,    0,   40,   91,  260,  290,
   59,   91,   61,   76,   59,   59,  297,   61,   41,   59,
  186,   84,   85,   41,   87,   88,   89,   90,   44,   92,
   93,   85,   42,   43,   88,   45,   59,   47,   92,   93,
   42,    2,  269,   59,   85,   47,   40,   88,   41,  112,
   11,   92,   93,  186,   85,  260,   46,   88,   44,   46,
   85,   92,   93,   88,   59,  270,  271,   92,   93,  296,
  275,   61,  135,   59,   61,  260,  139,   42,   43,  260,
   45,   44,   47,   46,   45,  148,  257,   48,  260,  260,
   41,  154,   59,   44,  135,   44,   59,   46,   61,   41,
   42,   43,   44,   45,  260,   47,  257,  170,   11,  260,
   59,   47,   61,  154,  177,  291,  292,  291,  292,   80,
   81,   82,   83,  186,   85,  188,   46,   88,  191,  170,
  125,   92,   93,  269,   61,  198,  177,   40,   40,  291,
  292,  291,  292,   45,  263,  264,   41,  188,   61,   44,
  191,   40,  215,  216,  217,   58,   40,  198,  221,  260,
  223,   45,  225,  270,  227,  260,  221,  270,  271,   45,
  123,  269,   40,  260,  215,  216,  217,   45,  276,  140,
  221,   44,   85,   46,  270,   88,  249,   59,  251,   92,
   93,   46,  270,  271,   46,   11,   59,   40,   61,   40,
  263,  123,   44,  260,   46,  268,  269,  270,  249,  260,
  251,  270,  271,  268,  257,  258,  270,   59,   40,   61,
  283,   41,  263,   44,   40,   59,   93,  268,  269,   93,
  191,   40,  135,  296,   46,  298,  299,  198,   41,  302,
  263,  264,  283,  298,   59,  263,  264,  302,  257,  258,
   41,  154,   59,  189,  190,  296,   91,  298,  299,   40,
  221,  302,   59,  199,   40,  260,   40,  170,   41,   85,
  263,  264,   88,   59,  177,   85,   92,   93,   88,  274,
  275,  123,   92,   93,   59,  188,   40,   48,  283,  123,
  285,  286,  287,  288,  289,  290,  291,  292,   93,   93,
  295,  192,  193,  194,  195,  196,  197,  268,  269,  270,
  125,   41,  215,  216,  217,  278,  279,  280,  281,  135,
   40,  270,  271,   84,  149,  150,  151,  152,  125,  278,
  279,  280,  281,  123,   41,  296,   41,  298,  154,  260,
   40,  302,   41,  284,   46,   93,  249,   93,  251,   41,
   41,  112,   41,   40,  170,  257,  258,  259,  260,  261,
  263,  177,   41,   41,   58,   41,  260,   41,  270,  271,
  273,   40,  188,  257,  258,  259,  260,  261,   58,   41,
  283,  257,  258,   41,  260,    0,  270,  271,   59,  257,
  258,  275,  260,  261,  270,  271,  299,  123,   59,  215,
  216,  217,  270,  271,   59,   41,   59,  270,  271,   41,
   61,  295,   61,   59,  298,  278,  279,  280,  281,   60,
   41,   62,   61,   61,  270,  186,  260,  177,   41,   42,
   43,  275,   45,  249,   47,  251,  278,  279,  280,  281,
  274,  275,  186,   -1,   -1,  260,   59,  263,   -1,  283,
   -1,  285,  286,  287,  288,  289,  290,   -1,   -1,  274,
  275,  295,   -1,  260,  225,   -1,  227,  283,  283,   -1,
  285,  286,  287,  288,  289,  290,   -1,  274,  275,   -1,
  295,   -1,   -1,  299,   -1,  260,  283,   -1,  285,  286,
  287,  288,  289,  290,   -1,   -1,   -1,   -1,  295,  274,
  275,   41,   42,   43,   -1,   45,   -1,   47,  283,  270,
  285,  286,  287,  288,  289,  290,   -1,   -1,   -1,   59,
  295,   41,   42,   43,   44,   45,   46,   47,   -1,   -1,
   41,   42,   43,   44,   45,   46,   47,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   59,   60,
   61,   62,   41,   42,   43,   44,   45,   46,   47,   41,
   42,   43,   44,   45,   46,   47,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   59,   60,   61,
   62,   41,   42,   43,   44,   45,   46,   47,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   -1,   -1,   -1,   59,   60,   -1,   62,
   41,   42,   43,   44,   45,   -1,   47,   41,   42,   43,
   44,   45,   -1,   47,  265,  266,  267,  268,   59,   60,
   -1,   62,   -1,   -1,   -1,   59,   60,   -1,   62,   41,
   42,   43,   44,   45,   -1,   47,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   -1,   59,   60,   -1,   62,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   59,   60,   41,   62,
   43,   44,   45,   59,   60,   41,   62,   43,   44,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,
   -1,   -1,   -1,   59,   60,   -1,   62,   41,   42,   43,
   -1,   45,   -1,   47,   41,   42,   43,   -1,   45,   -1,
   47,   46,   47,   -1,   -1,   59,   -1,   -1,   -1,   -1,
   -1,   -1,   59,  263,  264,  265,  266,  267,  268,   -1,
  270,  271,  263,  264,  265,  266,  267,  268,   41,   42,
   43,   44,   45,   -1,   47,   80,   81,   82,   83,   -1,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   -1,  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   59,
  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,   -1,
   41,   42,   43,   -1,   45,  140,   47,   -1,   -1,   -1,
   -1,   -1,  263,  264,  265,  266,  267,  268,   59,  263,
  264,  265,  266,  267,  268,    4,   -1,   -1,   -1,   41,
   42,   43,   11,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,  263,  264,  265,  266,  267,  268,   59,  263,  264,
  265,  266,  267,  268,  189,  190,   -1,  192,  193,  194,
  195,  196,  197,   -1,  199,   -1,   -1,   46,   47,   -1,
  263,  264,  265,  266,  267,  268,   -1,  263,  264,  265,
  266,  267,  268,   11,   -1,   -1,   -1,   -1,   -1,   -1,
  263,  264,  265,  266,  267,  268,   -1,  263,  264,  265,
  266,  267,  268,   11,   -1,   -1,   85,   -1,   -1,   88,
   -1,   -1,   -1,   92,   93,   -1,   -1,   -1,   46,   47,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   46,   47,
   59,   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   59,   41,   42,   43,   44,   45,   85,   47,   -1,
   88,   -1,   -1,   -1,   92,   93,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   85,   -1,   -1,
   88,   -1,   -1,   -1,   92,   93,   41,   42,   43,   44,
   45,   -1,   47,  135,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  189,  190,  154,  192,  193,  194,  195,  196,  197,   -1,
  199,  149,  150,  151,  152,   -1,   -1,   -1,  170,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  149,  150,  151,  152,   -1,  188,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  189,  190,   -1,  192,  193,  194,  195,  196,  197,
   -1,  199,   -1,  215,  216,  217,   -1,   -1,   -1,   -1,
   -1,  189,  190,   -1,  192,  193,  194,  195,  196,  197,
   -1,  199,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  249,   -1,  251,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  299,
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
"var_declar_stmt : IDENTIFIER '[' IDENTIFIER ']' ';'",
"var_declar_stmt : IDENTIFIER '[' IDENTIFIER ']' ',' var_declar_stmt",
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
"array_ele_stmt : IDENTIFIER '[' IDENTIFIER ']'",
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
#line 419 "a.y"


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
#line 790 "y.tab.c"

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
	{ yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,yystack.l_mark[-2].intValue,NULL) ); }
break;
case 47:
#line 174 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,yystack.l_mark[-3].intValue,NULL),yystack.l_mark[0].node); }
break;
case 48:
#line 175 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,-1,var(yystack.l_mark[-2].sValue)) ); }
break;
case 49:
#line 176 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,-1,var(yystack.l_mark[-3].sValue)),yystack.l_mark[0].node); }
break;
case 50:
#line 181 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 51:
#line 182 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 52:
#line 187 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 53:
#line 188 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 54:
#line 189 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 55:
#line 193 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 56:
#line 194 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 57:
#line 198 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 58:
#line 199 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 59:
#line 203 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 60:
#line 204 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 61:
#line 209 "a.y"
	{ yyval.node = NULL ; }
break;
case 62:
#line 210 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 211 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 212 "a.y"
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
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
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
#line 222 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 71:
#line 223 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 72:
#line 229 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 73:
#line 230 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 74:
#line 234 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 75:
#line 235 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 76:
#line 236 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 77:
#line 241 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 78:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 246 "a.y"
	{ yyval.args = NULL; }
break;
case 80:
#line 247 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 81:
#line 251 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 82:
#line 252 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
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
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 86:
#line 259 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 260 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 261 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 90:
#line 266 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 91:
#line 267 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 273 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 274 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 94:
#line 279 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 95:
#line 285 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 96:
#line 286 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 97:
#line 287 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 98:
#line 288 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
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
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 102:
#line 296 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 103:
#line 297 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 104:
#line 302 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 105:
#line 306 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 106:
#line 310 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 107:
#line 314 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 108:
#line 315 "a.y"
	{ yyval.node = number(yystack.l_mark[0].intValue); }
break;
case 109:
#line 319 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 110:
#line 323 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 111:
#line 327 "a.y"
	{ yyval.node = xnull();}
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
#line 334 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 115:
#line 335 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 116:
#line 340 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 117:
#line 341 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 118:
#line 342 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 119:
#line 343 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 120:
#line 344 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 121:
#line 345 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 122:
#line 346 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 123:
#line 347 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 124:
#line 348 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 125:
#line 353 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 126:
#line 354 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 127:
#line 355 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 128:
#line 356 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
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
#line 372 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 373 "a.y"
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
#line 381 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 146:
#line 382 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 147:
#line 387 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 148:
#line 388 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 149:
#line 392 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 150:
#line 393 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 151:
#line 398 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, yystack.l_mark[-1].intValue, NULL); }
break;
case 152:
#line 399 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, -1, var(yystack.l_mark[-1].sValue)) ; }
break;
case 153:
#line 405 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 154:
#line 410 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 155:
#line 411 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 156:
#line 412 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 157:
#line 413 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 158:
#line 414 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 159:
#line 415 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 160:
#line 416 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1628 "y.tab.c"
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
