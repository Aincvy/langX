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
#define XTRY 278
#define XCATCH 279
#define ADD_EQ 280
#define SUB_EQ 281
#define MUL_EQ 282
#define DIV_EQ 283
#define LEFT_SHIFT 284
#define RIGHT_SHIFT 285
#define AUTO 286
#define IF 287
#define ELSE 288
#define WHILE 289
#define FOR 290
#define DELETE 291
#define BREAK 292
#define RETURN 293
#define SWITCH 294
#define CASE 295
#define DEFAULT 296
#define CASE_LIST 297
#define CLAXX_BODY 298
#define NEW 299
#define CLAXX_MEMBER 300
#define CLAXX_FUNC_CALL 301
#define XNULL 302
#define NONASSOC 303
#define IFX 304
#define UMINUS 305
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   55,   55,    1,    1,    1,    1,    1,   26,   26,
   27,    2,    2,    2,   36,   36,   54,   54,   37,   37,
   38,   38,   38,   45,   45,   45,   46,   46,   39,   39,
   39,   39,   41,   41,   41,   41,   42,   42,   42,    5,
   50,   50,   51,   51,   51,    7,    7,    6,    6,    6,
    6,    6,    6,    3,    3,    8,    8,    8,   34,   34,
   35,   35,    9,    9,   12,   12,   12,   12,    4,    4,
    4,    4,    4,    4,    4,   44,   44,   24,   24,   24,
   16,   16,   52,   52,   53,   53,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   49,   49,
   33,   33,   33,   33,   33,   33,   25,   28,   29,   30,
   30,   31,   32,   43,   23,   23,   23,   23,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   15,   15,   15,
   15,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   20,   20,   20,   20,   20,   22,
   22,   40,   40,   47,   47,   48,   13,   13,   13,   13,
   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    4,    5,
    7,    1,    1,    1,    4,    5,    0,    2,    1,    2,
    1,    2,    1,    1,    3,    6,    3,    3,    3,    3,
    6,    3,    6,    9,    6,    6,    8,   10,    5,    6,
    0,    3,    1,    3,    0,    2,    0,    2,    3,    5,
    6,    5,    6,    1,    1,    5,    7,    7,    1,    2,
    4,    3,    5,    9,    0,    1,    1,    1,    1,    1,
    3,    1,    1,    1,    1,    1,    2,    1,    1,    2,
    4,    1,    0,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    3,    3,    1,    1,
    1,    1,    1,    1,    1,    3,    5,    1,    1,    1,
    1,    2,    1,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    2,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    3,    4,    4,    3,    1,    1,    1,    3,
    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   78,    0,    0,    0,    4,    2,    5,    6,    0,   12,
   13,   54,   55,   69,   70,  167,   72,   73,    8,    0,
   14,    0,  168,    0,    0,   75,    0,    0,  169,    0,
    0,    0,    0,    0,  119,   77,    0,   47,    0,    0,
    0,    0,    0,  120,    0,  123,    0,    0,    0,  124,
    0,    0,    0,    0,    0,    0,  111,   80,  150,    0,
  144,    0,    0,    0,    0,    0,  152,  153,    0,    0,
    0,  118,    0,    7,    0,    0,    0,    0,    0,    0,
   48,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   18,    0,  159,    0,   85,    0,   87,    0,    0,    0,
    0,  115,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  157,    0,    0,    0,  127,  155,
  156,    0,    0,    0,   67,    0,   66,   68,    0,   71,
    0,    0,  138,  139,    0,  121,    0,  122,   97,   96,
    0,  112,  109,  110,  106,  140,  141,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  170,    0,    0,  171,  172,  173,    0,   49,    0,  160,
  161,    0,    0,  162,    0,    0,    0,  163,  166,   43,
    0,   47,    0,    0,    0,    0,    0,   15,   23,   21,
    0,    0,    0,   19,    0,    0,   46,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  116,    0,  113,    0,    0,  101,  102,
  107,  108,  103,  104,  105,    0,    0,    0,    0,    0,
    0,    0,    0,   42,    0,    0,    0,   86,    0,   50,
    0,   52,   22,   16,   20,    0,    0,   10,  136,  137,
   47,   95,    0,  132,  133,  134,  135,  130,  131,   63,
    0,    0,  164,  165,    0,   98,    0,    0,  117,    0,
    0,    0,    0,    0,   39,   44,   40,    0,    0,   51,
   53,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   59,    0,    0,    0,   35,   36,    0,    0,    0,
   94,   57,    0,   26,   33,    0,   47,   58,   60,    0,
   37,    0,    0,    0,   47,    0,    0,   34,   47,   64,
    0,    0,    0,   38,   11,
};
static const short yydgoto[] = {                          1,
  207,   17,   18,   19,   20,   21,  122,   22,   23,  123,
  263,  136,   24,  102,  103,  125,  105,  148,  149,   67,
   68,   26,  127,   27,   28,   29,  258,  128,  107,  130,
  131,  110,   75,  301,  302,   31,  203,  204,  111,   33,
   34,   35,   77,   36,   78,   37,  112,   39,   80,  100,
  191,  113,  114,   44,    2,
};
static const short yysindex[] = {                         0,
    0,  618,  -23, -228,  -11,  -82,   11,   17,   36, -207,
    0,  135,   63, -153,    0,    0,    0,    0,   64,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  365,
    0,  -18,    0,   95, -101,    0,  108,  115,    0,  150,
  -74,  261, -187,   88,    0,    0,  -56,    0,  261,  261,
 -193,  154,    0,    0,  -25,    0, -153, -153,  187,    0,
   23,  157, -144,    0,    0,    0,    0,    0,    0,  -35,
    0,    0,    0,    0,  482,  196,    0,    0,    0,  -30,
 -153,    0,  219,    0,  226,  226,  226,  226,    8,  135,
    0, -153,  135, -153, -153,  232,  135,  135,   28,  181,
    0,    0,    0,    0,    0,  -35,    0,    0,    0,    0,
  196,    0,  268,  269,  221,  222, -112,  290,  287,  196,
   95,  377,  -32,    0,    0,    0,  112,  -35,    0,    0,
    0,    0,   -7,  -10,    0,  276,    0,    0,  496,    0,
  261,  -40,    0,    0, -153,    0,  226,    0,    0,    0,
  296,    0,    0,    0,    0,    0,    0, -153,  157,  157,
  157,  157, -144, -144, -144, -144, -144,  297,  261,  307,
    0,  -35,  196,    0,    0,    0,  258,    0,   30,    0,
    0,  -43,  313,    0,  314,  320,  261,    0,    0,    0,
  116,    0,  -42,  261,   85,   92,  -75,    0,    0,    0,
  302,   74, -111,    0,  261,   83,    0,  261,  261,  449,
  261,  261,  261,  261,  261,  261,  449,  261,  326,  277,
  281,  329,  335,    0,  342,    0,  131,  131,    0,    0,
    0,    0,    0,    0,    0,  262,  345,   22,  261,  261,
  261,  348,  137,    0,  471,  351, -153,    0,    8,    0,
    8,    0,    0,    0,    0,  358,  368,    0,    0,    0,
    0,    0,  125,    0,    0,    0,    0,    0,    0,    0,
  -57,  366,    0,    0,  261,    0,  261, -114,    0,  330,
  332,  378,  388,  391,    0,    0,    0,  261,  393,    0,
    0,  366, -153,  528,  449, -193,  397,  398,  -58,  382,
 -100,    0,   85,   92,  183,    0,    0,  413,  261,  414,
    0,    0,  415,    0,    0,  400,    0,    0,    0,  421,
    0,  422,  349,  449,    0,  618,  261,    0,    0,    0,
  618,  440,  582,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  485,  -17,  423,    0,    0,    0,    0,    0,    0,
    0,  428,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  754,  429,    0,    0,    0,    0,  367,
    0,  448,    0,    0,    0,    0,    0,    0,    0,    0,
  436,    0,  526,    0,  432,    0,    0,    0,  -21,    0,
    0,    0,    0,  299,  492,  536,    0,    0,    0,  146,
    0,  616,  709,  993,    0, 1001,    0,    0, 1020,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  282,    0,
    0,  637,    0, 1027,    0,  404,    0, 1043, 1050, 1091,
  906,    0,    0,  458,    0,    0,    0,   91,  439,  442,
    0,    0,    0,  935,    0,  942,   21,  580,    0,    0,
    0,  964,    0,  501,    0,    0,    0,    0,    0,    0,
  448,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  683,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  448,    6,
    0,   -9,    0,    0,    0,    0,  124,    0,    0,    0,
    0,  146,  249,    0,  790,  841,  448,    0,    0,    0,
    0,    0,  445,    0,  450,  451,   81,    0,    0,    0,
    0,    0,    0,    0,  448,  316,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   13,    0,    0,  877,    0,  764,  854,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  448,  448,
  448,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  339,    0,    0,    0,    0,    0,    0,    0,
    0,  913,    0,    0,  448,    0,  448,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  448,  884,    0,
    0,    0,    0,    0,    0,  460,    0,    0,    0,    0,
    0,    0,    0,    0,  -22,    0,    0,    0,  448,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -86,  448,    0,    0,    0,
   -6,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    4,    0,    0,    0,  -95,    9, -159,    0,    0,  103,
 -194,  213,  -44, 1063,    7,   57,  319,    0,    0, 1204,
  132,  -69,  499,    0,   34,    0,    0,   -2, 1033,  266,
  275, 1171,  306,    0,  209,    0,    0,  333,   24,    0,
  -46,    0,    0,    0,    0,    0,  126,    0,  237,    0,
    0, 1047,    0,    0,    0,
};
#define YYTABLESIZE 1422
static const short yytable[] = {                         30,
  121,  296,  158,  247,  121,   16,  137,  165,  210,   70,
  158,   83,  198,  254,  141,  238,   42,   90,   65,   24,
  181,  199,  270,   33,  318,   32,  118,   94,  118,  205,
   45,  158,  245,  217,   47,   76,   33,   24,   62,  106,
   48,  118,   93,  118,  119,   69,  118,  201,  139,  158,
   49,  118,   52,   25,  143,  144,   50,  138,   25,  135,
  154,  129,  147,  167,  118,  142,  134,   43,   66,  115,
  120,   25,  116,   89,   32,   51,   57,   58,  168,  129,
   43,    5,  172,  172,  172,  172,  179,  182,   91,  183,
   70,  185,  186,  166,   70,   70,   65,  178,  104,   65,
  312,  294,   81,   65,   65,   17,   82,  199,  173,  173,
  173,  173,  153,   76,  202,   82,   76,   89,   61,   30,
   76,   76,   84,   69,  118,  200,   69,   38,  249,  330,
   69,   69,   91,  201,   90,  251,  118,   79,  106,  118,
   95,  118,  222,  250,  172,   32,   66,  197,  197,   66,
  252,  118,  133,   66,   66,  225,  244,  326,   96,  243,
  154,  154,  154,  154,  154,  331,  106,  118,   97,  333,
  173,  216,  161,  215,   62,   98,   38,  162,   25,   61,
  299,  300,  118,  110,  106,  101,  147,  158,  158,   99,
  158,  106,  158,   40,  299,  300,   62,  104,  146,   54,
  202,   61,  106,  118,  147,  208,  209,   30,   62,   62,
  117,  200,  140,  262,   30,   79,  220,  246,   79,  221,
  262,  180,   79,   79,  184,  104,  156,  157,  188,  189,
  208,  209,  145,   32,  156,  157,  106,  106,  106,  110,
   32,   94,   30,  104,  289,   40,  179,   38,  179,  121,
  104,  137,   41,  163,  164,  208,  209,  290,  169,  291,
   63,  104,  118,  118,  118,  118,   25,  177,   32,  110,
   61,  187,  106,   25,  106,  118,  118,   72,  280,  146,
   54,  281,   63,  129,  129,  106,   73,  190,   61,   61,
  310,   30,   30,  139,   29,  104,  104,  104,  262,  155,
   62,   25,  138,  192,  135,   61,  106,  108,  193,   29,
  259,  260,  194,  195,  196,    9,  109,   32,   32,   32,
  271,   30,   45,   30,  106,   45,  150,  262,   30,  205,
   30,  104,  158,  104,  218,   38,  224,  236,   56,  145,
  113,  113,   38,  113,  104,  113,  141,   32,  238,   32,
   25,   25,  239,  240,   32,   72,   32,  145,   72,  241,
  253,  257,   72,   72,   73,  104,  272,   73,  275,  273,
   38,   73,   73,  274,    9,  276,  211,  212,  213,  214,
   25,  277,   25,  104,  278,  279,   63,   25,  285,   25,
  288,   53,   54,   45,   55,   56,  286,   56,  292,  231,
  232,  233,  234,  235,   57,   58,  108,  293,   89,   59,
   92,  247,  295,   53,   54,  109,   55,   56,  305,   38,
   38,   38,  303,   91,  304,   90,   57,   58,  306,  110,
  110,  307,  309,   14,  108,   15,   60,  314,  315,  317,
    9,  110,  320,  109,   89,  158,  158,   89,  158,   38,
  158,   38,  108,  321,  323,  324,   38,  325,   38,  108,
  327,  109,  328,   56,  227,  228,  229,  230,  109,  118,
  108,  329,  118,  118,  118,  118,  118,  118,  118,  109,
  334,   76,  146,   54,    1,  170,   79,   74,   83,   41,
  118,  118,  118,  118,   65,   57,   58,  110,   84,   27,
   65,  206,   28,   81,  108,  108,  108,   15,  313,  319,
  164,  165,  248,  109,  109,  109,    0,   53,   54,   45,
   55,   56,    0,  161,  159,  118,  160,  110,  162,   15,
   57,   58,  149,  159,  159,  255,  159,    0,  159,   89,
  108,  158,  108,    0,  118,    0,  118,    0,    0,  109,
  149,  109,    0,  108,   91,  118,   90,    0,    0,  118,
    0,  118,  109,  109,  316,    0,  121,  121,  121,  121,
  121,  261,  121,    0,  108,    9,  146,  157,  157,    0,
  157,    0,  157,  109,  121,  121,   15,  121,    0,    9,
    9,    0,  108,    9,  146,  287,    0,    0,   56,    0,
    0,  109,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,   56,   56,    9,    0,   56,  110,    0,  109,
  158,  158,  158,  158,  158,   56,  158,   56,   56,   56,
   56,   56,   56,   56,   56,    0,    3,   56,  158,  158,
   15,  158,    0,    0,   85,   86,   87,   88,    0,  109,
    4,    5,  311,    0,    6,    0,  142,  155,  155,    0,
  155,    0,  155,    7,    0,    8,    9,   10,   11,   12,
   13,    0,    0,  110,  142,   14,   15,   93,  113,  113,
   93,  113,    0,  113,    0,    0,    0,  110,  110,    0,
    0,    0,    0,    0,  118,  118,  118,  118,  118,  118,
    0,  118,  118,  110,    0,    0,  335,    0,    3,  264,
  265,  266,  267,  268,  269,  118,  118,    0,    0,    0,
    0,    0,    4,    5,  113,  113,    6,  113,    0,  113,
    3,    0,    0,    0,    0,    7,    0,    8,    9,   10,
   11,   12,   13,    0,    4,    5,    0,   14,    6,  143,
  156,  156,    0,  156,    0,  156,    0,    7,    0,    8,
    9,   10,   11,   12,   13,  156,  157,  143,    0,   14,
  118,  118,    0,    0,    0,   85,   86,   87,   88,    0,
  118,  118,  118,  118,    0,    0,    0,    3,  121,  121,
  121,  121,  121,  121,   82,   82,   82,   82,   82,    0,
   82,    4,    5,    0,   99,    6,   99,   99,   99,  109,
  109,    0,   82,   82,    7,   82,    8,    9,   10,   11,
   12,   13,   99,   99,    0,   99,   14,    0,    0,    0,
   32,   32,   32,   32,   32,   32,   32,    0,    0,    0,
    0,    3,  158,  158,  158,  158,  158,  158,   32,   32,
   32,   32,    0,    0,    0,    4,    5,    0,    0,    6,
    0,    0,    0,  110,  110,    0,    0,    0,    7,    0,
    8,    9,   10,   11,   12,   13,    0,    3,    0,    0,
   14,   30,   30,   30,   30,   30,   30,   30,    0,    0,
    0,    4,    5,    0,  100,    6,  100,  100,  100,   30,
   30,   30,   30,    0,    7,    0,    8,    9,   10,   11,
   12,   13,  100,  100,    0,  100,   14,   29,   29,   29,
   29,   29,   29,   29,   31,   31,   31,   31,   31,   31,
   31,    0,    0,    0,    0,   29,   29,   29,   29,    0,
    0,    0,   31,   31,   31,   31,  114,  114,  114,  114,
  114,    0,  114,   81,   81,   81,   81,   81,    0,   81,
    0,    0,    0,    0,  114,  114,    0,  114,    0,    0,
    0,   81,   81,    0,   81,  126,  113,  113,    0,  113,
    0,  113,  125,  111,  111,    0,  111,    0,  111,    0,
    0,    0,    0,  126,  126,    0,  126,    0,    0,    0,
  125,  125,    0,  125,  128,  112,  112,    0,  112,    0,
  112,    0,    0,    0,    0,    0,   82,   82,   82,   82,
   82,   82,  128,  128,    0,  128,   99,   99,   99,   99,
   99,   99,    0,  148,  112,  112,   46,  112,    0,  112,
    0,  151,  114,  114,   71,  114,    0,  114,    0,    0,
    0,  148,   32,   32,   32,   32,   32,   32,    0,  151,
  154,  115,  115,    0,  115,    0,  115,   92,  157,  157,
   92,  157,    0,  157,   64,    0,    0,    0,  154,    0,
    0,  129,  129,   88,  155,  155,   88,  155,    0,  155,
   91,  156,  156,   91,  156,    0,  156,    0,    0,    0,
    0,    0,    0,   30,   30,   30,   30,   30,   30,    0,
    0,  124,  124,    0,    0,    0,  100,  100,  100,  100,
  100,  100,   71,    0,  151,   71,    0,    0,    0,   71,
   71,   90,  112,  112,   90,  112,    0,  112,    0,   29,
   29,   29,   29,   29,   29,    0,   31,   31,   31,   31,
   31,   31,   64,    0,    0,   64,    0,    0,    0,   64,
   64,    0,    0,    0,    0,    0,    0,    0,  114,  114,
  114,  114,  114,  114,    0,   81,   81,   81,   81,   81,
   81,    0,   74,    0,    0,    0,    0,  219,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  126,  126,  126,
  126,  126,  126,    0,  125,  125,  125,  125,  125,  125,
    0,    0,    0,    0,    0,  237,    0,    0,    0,  132,
  132,  226,  226,  226,  226,    0,  128,  128,  128,  128,
  128,  128,  152,  242,    0,    0,    0,    0,    0,    0,
  129,  129,    0,  129,  129,  129,  129,  129,  129,    0,
  129,  256,  126,  126,    0,    0,    0,    0,    0,    0,
   74,    0,    0,   74,    0,    0,    0,   74,   74,    0,
  124,  124,    0,  124,  124,  124,  124,  124,  124,    0,
  124,    0,    0,    0,    0,  282,  283,  284,  171,  174,
  175,  176,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  297,    0,  298,    0,    0,    0,    0,    0,  152,
  152,  152,  152,    0,  308,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  223,    0,    0,    0,    0,  322,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  332,    0,    0,    0,    0,  132,  132,
    0,  132,  132,  132,  132,  132,  132,    0,  132,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  126,  126,    0,  126,  126,  126,  126,  126,  126,
    0,  126,
};
static const short yycheck[] = {                          2,
   47,   59,   46,   46,   51,    2,   51,   38,   41,   12,
   46,   14,  125,  125,   40,   91,   40,   61,   12,   41,
   90,  117,  217,   46,  125,    2,   44,   46,   46,   40,
  259,   41,  192,   41,   46,   12,   59,   59,  125,   42,
  123,   59,   61,   61,   47,   12,   41,  117,   51,   59,
   40,   46,  260,   41,   57,   58,   40,   51,    2,   51,
   63,   41,   40,   94,   59,   91,  260,   91,   12,  257,
   47,   59,  260,   44,   51,   40,  270,  271,   81,   59,
   91,  275,   85,   86,   87,   88,   89,   90,   59,   92,
   93,   94,   95,  124,   97,   98,   90,   89,   42,   93,
  295,  261,   40,   97,   98,  123,  260,  203,   85,   86,
   87,   88,  257,   90,  117,  260,   93,   44,  125,  122,
   97,   98,   59,   90,   44,  117,   93,    2,   44,  324,
   97,   98,   59,  203,   61,   44,   46,   12,  141,   59,
   46,   61,  145,   59,  147,  122,   90,  260,  260,   93,
   59,   61,   50,   97,   98,  158,   41,  317,  260,   44,
  163,  164,  165,  166,  167,  325,  169,   44,   61,  329,
  147,   60,   42,   62,   40,   61,   51,   47,  122,   45,
  295,  296,   59,   38,  187,  260,   41,   42,   43,   40,
   45,  194,   47,  269,  295,  296,   40,  141,  257,  258,
  203,   45,  205,  260,   59,  263,  264,  210,  295,  296,
  123,  203,   59,  210,  217,   90,  257,  260,   93,  260,
  217,   90,   97,   98,   93,  169,  270,  271,   97,   98,
  263,  264,   46,  210,  270,  271,  239,  240,  241,   94,
  217,   46,  245,  187,  247,  269,  249,  122,  251,  296,
  194,  296,  276,  284,  285,  263,  264,  249,   40,  251,
  126,  205,  280,  281,  282,  283,  210,  260,  245,  124,
   45,   40,  275,  217,  277,  270,  271,   12,  257,  257,
  258,  260,  126,  263,  264,  288,   12,  260,  295,  296,
  293,  294,  295,  296,   46,  239,  240,  241,  295,   63,
   40,  245,  296,  123,  296,   45,  309,   42,   41,   61,
  208,  209,   44,   93,   93,    0,   42,  294,  295,  296,
  218,  324,   41,  326,  327,   44,   61,  324,  331,   40,
  333,  275,   46,  277,   59,  210,   41,   41,    0,   41,
   42,   43,  217,   45,  288,   47,   40,  324,   91,  326,
  294,  295,   40,   40,  331,   90,  333,   59,   93,   40,
   59,  279,   97,   98,   90,  309,   41,   93,   40,   93,
  245,   97,   98,   93,   59,   41,  265,  266,  267,  268,
  324,   40,  326,  327,  123,   41,  126,  331,   41,  333,
   40,  257,  258,  259,  260,  261,  260,   59,   41,  163,
  164,  165,  166,  167,  270,  271,  141,   40,   44,  275,
   46,   46,  288,  257,  258,  141,  260,  261,   41,  294,
  295,  296,   93,   59,   93,   61,  270,  271,   41,  284,
  285,   41,   40,  299,  169,   59,  302,   41,   41,   58,
  125,   38,  260,  169,   41,   42,   43,   44,   45,  324,
   47,  326,  187,   41,   41,   41,  331,   58,  333,  194,
   40,  187,   41,  125,  159,  160,  161,  162,  194,   38,
  205,  123,   41,   42,   43,   44,   45,   46,   47,  205,
   41,   59,  257,  258,    0,  260,   59,   59,   41,  123,
   59,   60,   61,   62,   59,  270,  271,   94,   41,   61,
   41,  125,   61,   59,  239,  240,  241,   59,  296,  301,
   61,   61,  194,  239,  240,  241,   -1,  257,  258,  259,
  260,  261,   -1,   42,   43,   94,   45,  124,   47,   59,
  270,  271,   41,   42,   43,  203,   45,   -1,   47,   44,
  275,   46,  277,   -1,   44,   -1,   46,   -1,   -1,  275,
   59,  277,   -1,  288,   59,  124,   61,   -1,   -1,   59,
   -1,   61,  288,   38,  299,   -1,   41,   42,   43,   44,
   45,  123,   47,   -1,  309,  260,   41,   42,   43,   -1,
   45,   -1,   47,  309,   59,   60,   59,   62,   -1,  274,
  275,   -1,  327,  278,   59,  125,   -1,   -1,  260,   -1,
   -1,  327,  287,  288,  289,  290,  291,  292,  293,  294,
  295,  296,  274,  275,  299,   -1,  278,   38,   -1,   94,
   41,   42,   43,   44,   45,  287,   47,  289,  290,  291,
  292,  293,  294,  295,  296,   -1,  260,  299,   59,   60,
   59,   62,   -1,   -1,  280,  281,  282,  283,   -1,  124,
  274,  275,  125,   -1,  278,   -1,   41,   42,   43,   -1,
   45,   -1,   47,  287,   -1,  289,  290,  291,  292,  293,
  294,   -1,   -1,   94,   59,  299,   59,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,  284,  285,   -1,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   -1,  270,  271,  124,   -1,   -1,  125,   -1,  260,  211,
  212,  213,  214,  215,  216,  284,  285,   -1,   -1,   -1,
   -1,   -1,  274,  275,   42,   43,  278,   45,   -1,   47,
  260,   -1,   -1,   -1,   -1,  287,   -1,  289,  290,  291,
  292,  293,  294,   -1,  274,  275,   -1,  299,  278,   41,
   42,   43,   -1,   45,   -1,   47,   -1,  287,   -1,  289,
  290,  291,  292,  293,  294,  270,  271,   59,   -1,  299,
  270,  271,   -1,   -1,   -1,  280,  281,  282,  283,   -1,
  280,  281,  282,  283,   -1,   -1,   -1,  260,  263,  264,
  265,  266,  267,  268,   41,   42,   43,   44,   45,   -1,
   47,  274,  275,   -1,   41,  278,   43,   44,   45,  284,
  285,   -1,   59,   60,  287,   62,  289,  290,  291,  292,
  293,  294,   59,   60,   -1,   62,  299,   -1,   -1,   -1,
   41,   42,   43,   44,   45,   46,   47,   -1,   -1,   -1,
   -1,  260,  263,  264,  265,  266,  267,  268,   59,   60,
   61,   62,   -1,   -1,   -1,  274,  275,   -1,   -1,  278,
   -1,   -1,   -1,  284,  285,   -1,   -1,   -1,  287,   -1,
  289,  290,  291,  292,  293,  294,   -1,  260,   -1,   -1,
  299,   41,   42,   43,   44,   45,   46,   47,   -1,   -1,
   -1,  274,  275,   -1,   41,  278,   43,   44,   45,   59,
   60,   61,   62,   -1,  287,   -1,  289,  290,  291,  292,
  293,  294,   59,   60,   -1,   62,  299,   41,   42,   43,
   44,   45,   46,   47,   41,   42,   43,   44,   45,   46,
   47,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   59,   60,   61,   62,   41,   42,   43,   44,
   45,   -1,   47,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,   59,   60,   -1,   62,   41,   42,   43,   -1,   45,
   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   59,   60,   -1,   62,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,  263,  264,  265,  266,
  267,  268,   59,   60,   -1,   62,  263,  264,  265,  266,
  267,  268,   -1,   41,   42,   43,    4,   45,   -1,   47,
   -1,   41,   42,   43,   12,   45,   -1,   47,   -1,   -1,
   -1,   59,  263,  264,  265,  266,  267,  268,   -1,   59,
   41,   42,   43,   -1,   45,   -1,   47,   41,   42,   43,
   44,   45,   -1,   47,   12,   -1,   -1,   -1,   59,   -1,
   -1,   49,   50,   41,   42,   43,   44,   45,   -1,   47,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   -1,
   -1,   49,   50,   -1,   -1,   -1,  263,  264,  265,  266,
  267,  268,   90,   -1,   62,   93,   -1,   -1,   -1,   97,
   98,   41,   42,   43,   44,   45,   -1,   47,   -1,  263,
  264,  265,  266,  267,  268,   -1,  263,  264,  265,  266,
  267,  268,   90,   -1,   -1,   93,   -1,   -1,   -1,   97,
   98,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,
  265,  266,  267,  268,   -1,  263,  264,  265,  266,  267,
  268,   -1,   12,   -1,   -1,   -1,   -1,  141,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,  265,
  266,  267,  268,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,   -1,  169,   -1,   -1,   -1,   49,
   50,  159,  160,  161,  162,   -1,  263,  264,  265,  266,
  267,  268,   62,  187,   -1,   -1,   -1,   -1,   -1,   -1,
  208,  209,   -1,  211,  212,  213,  214,  215,  216,   -1,
  218,  205,   49,   50,   -1,   -1,   -1,   -1,   -1,   -1,
   90,   -1,   -1,   93,   -1,   -1,   -1,   97,   98,   -1,
  208,  209,   -1,  211,  212,  213,  214,  215,  216,   -1,
  218,   -1,   -1,   -1,   -1,  239,  240,  241,   85,   86,
   87,   88,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  275,   -1,  277,   -1,   -1,   -1,   -1,   -1,  159,
  160,  161,  162,   -1,  288,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  147,   -1,   -1,   -1,   -1,  309,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  327,   -1,   -1,   -1,   -1,  208,  209,
   -1,  211,  212,  213,  214,  215,  216,   -1,  218,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  208,  209,   -1,  211,  212,  213,  214,  215,  216,
   -1,  218,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,
0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"XINTEGER","TDOUBLE","TBOOL",
"IDENTIFIER","TSTRING","OP_CALC","AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP",
"NE_OP","FUNC_OP","INC_OP","DEC_OP","FUNC_CALL","VAR_DECLAR","RESTRICT","THIS",
"EXTENDS","ARRAY_ELE","XTRY","XCATCH","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ",
"LEFT_SHIFT","RIGHT_SHIFT","AUTO","IF","ELSE","WHILE","FOR","DELETE","BREAK",
"RETURN","SWITCH","CASE","DEFAULT","CASE_LIST","CLAXX_BODY","NEW",
"CLAXX_MEMBER","CLAXX_FUNC_CALL","XNULL","NONASSOC","IFX","UMINUS",
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
"statement : try_stmt",
"try_stmt : XTRY '{' expr_list '}'",
"try_stmt : XTRY '{' expr_list '}' catch_block_stmt",
"catch_block_stmt : XCATCH '(' id_expr ')' '{' expr_list '}'",
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
"arithmetic_stmt : bit_opr_factor '&' bit_opr_factor",
"arithmetic_stmt : bit_opr_factor '|' bit_opr_factor",
"arithmetic_stmt : bit_opr_factor '^' bit_opr_factor",
"arithmetic_stmt : '~' bit_opr_factor",
"arithmetic_stmt : bit_opr_factor LEFT_SHIFT bit_opr_factor",
"arithmetic_stmt : bit_opr_factor RIGHT_SHIFT bit_opr_factor",
"bit_opr_factor : XINTEGER",
"bit_opr_factor : id_expr",
"arithmetic_stmt_factor : assign_stmt_value_eq",
"arithmetic_stmt_factor : string_expr",
"arithmetic_stmt_factor : arithmetic_stmt",
"arithmetic_stmt_factor : class_member_stmt",
"arithmetic_stmt_factor : array_ele_stmt",
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
#line 443 "a.y"


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
#line 858 "y.tab.c"

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
#line 78 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 83 "a.y"
	{ yyval.node = opr(XTRY, 2,yystack.l_mark[-1].node,NULL); }
break;
case 10:
#line 84 "a.y"
	{ yyval.node = opr(XTRY, 2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 11:
#line 88 "a.y"
	{ yyval.node = opr(XCATCH, 2, yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 12:
#line 93 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 13:
#line 94 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 14:
#line 95 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 15:
#line 100 "a.y"
	{ /*if($2 != NULL) printf("parentName: %s\n",$2);*/ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-2].sValue, NULL); }
break;
case 16:
#line 101 "a.y"
	{ /*if($2 != NULL) printf("parentName: %s\n",$2);*/ yyval.node = claxx(yystack.l_mark[-4].sValue , yystack.l_mark[-3].sValue, yystack.l_mark[-1].node); }
break;
case 17:
#line 106 "a.y"
	{ yyval.sValue = NULL; }
break;
case 18:
#line 107 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue; }
break;
case 19:
#line 112 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 20:
#line 113 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 21:
#line 117 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 22:
#line 118 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 23:
#line 119 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 24:
#line 124 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 25:
#line 125 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 26:
#line 127 "a.y"
	{ yyval.node = opr(THIS, 1 , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 27:
#line 132 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 28:
#line 133 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 29:
#line 138 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 30:
#line 139 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 31:
#line 140 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 32:
#line 141 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 33:
#line 146 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 34:
#line 147 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 35:
#line 148 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 36:
#line 149 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 37:
#line 154 "a.y"
	{  yyval.node = NULL; }
break;
case 38:
#line 155 "a.y"
	{ yyval.node = NULL; }
break;
case 39:
#line 156 "a.y"
	{ yyval.node = NULL; }
break;
case 40:
#line 161 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 41:
#line 165 "a.y"
	{ yyval.params = NULL; }
break;
case 42:
#line 166 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 43:
#line 170 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 44:
#line 171 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 45:
#line 172 "a.y"
	{ yyval.params = NULL; }
break;
case 46:
#line 176 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 47:
#line 177 "a.y"
	{ yyval.node = NULL; }
break;
case 48:
#line 182 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 49:
#line 183 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 50:
#line 184 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,yystack.l_mark[-2].intValue,NULL) ); }
break;
case 51:
#line 185 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,yystack.l_mark[-3].intValue,NULL),yystack.l_mark[0].node); }
break;
case 52:
#line 186 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,-1,var(yystack.l_mark[-2].sValue)) ); }
break;
case 53:
#line 187 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,-1,var(yystack.l_mark[-3].sValue)),yystack.l_mark[0].node); }
break;
case 54:
#line 192 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 55:
#line 193 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 198 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 57:
#line 199 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 58:
#line 200 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 59:
#line 204 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 60:
#line 205 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 61:
#line 209 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 62:
#line 210 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 63:
#line 214 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 64:
#line 215 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 65:
#line 220 "a.y"
	{ yyval.node = NULL ; }
break;
case 66:
#line 221 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 67:
#line 222 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 223 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 69:
#line 228 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 70:
#line 229 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 71:
#line 230 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 72:
#line 231 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 232 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 233 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 234 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 76:
#line 240 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 77:
#line 241 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 78:
#line 245 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 79:
#line 246 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 80:
#line 247 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 81:
#line 252 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 82:
#line 253 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 257 "a.y"
	{ yyval.args = NULL; }
break;
case 84:
#line 258 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 85:
#line 262 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 86:
#line 263 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 87:
#line 267 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 268 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 269 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 270 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 271 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 272 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 273 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 94:
#line 277 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 95:
#line 278 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 96:
#line 284 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 97:
#line 285 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 98:
#line 290 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 99:
#line 296 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 100:
#line 297 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 101:
#line 298 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 102:
#line 299 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 103:
#line 300 "a.y"
	{ yyval.node = opr('&',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 104:
#line 301 "a.y"
	{ yyval.node = opr('|',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 105:
#line 302 "a.y"
	{ yyval.node = opr('^',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 106:
#line 303 "a.y"
	{ yyval.node = opr('~',1,yystack.l_mark[0].node); }
break;
case 107:
#line 304 "a.y"
	{ yyval.node = opr(LEFT_SHIFT,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 108:
#line 305 "a.y"
	{ yyval.node = opr(RIGHT_SHIFT,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 109:
#line 310 "a.y"
	{ yyval.node = xint(yystack.l_mark[0].intValue); }
break;
case 110:
#line 311 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 111:
#line 316 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 112:
#line 317 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 113:
#line 318 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 114:
#line 319 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 115:
#line 320 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 116:
#line 321 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 117:
#line 326 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 118:
#line 330 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 119:
#line 334 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 120:
#line 338 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 121:
#line 339 "a.y"
	{ yyval.node = number(yystack.l_mark[0].intValue); }
break;
case 122:
#line 343 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 123:
#line 347 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 124:
#line 351 "a.y"
	{ yyval.node = xnull();}
break;
case 125:
#line 356 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 357 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 358 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 359 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 364 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 365 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 131:
#line 366 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 132:
#line 367 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 133:
#line 368 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 134:
#line 369 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 135:
#line 370 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 136:
#line 371 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 137:
#line 372 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 138:
#line 377 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 139:
#line 378 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 140:
#line 379 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 141:
#line 380 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 142:
#line 385 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 143:
#line 386 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 144:
#line 387 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 145:
#line 388 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 146:
#line 389 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 147:
#line 390 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 148:
#line 391 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 149:
#line 392 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 150:
#line 393 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 151:
#line 394 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 152:
#line 395 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 153:
#line 396 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 154:
#line 397 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 155:
#line 402 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 156:
#line 403 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 157:
#line 404 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 158:
#line 405 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 159:
#line 406 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 160:
#line 411 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 161:
#line 412 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 162:
#line 416 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 163:
#line 417 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 164:
#line 422 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, yystack.l_mark[-1].intValue, NULL); }
break;
case 165:
#line 423 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, -1, var(yystack.l_mark[-1].sValue)) ; }
break;
case 166:
#line 429 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 167:
#line 434 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 168:
#line 435 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 169:
#line 436 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 170:
#line 437 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 171:
#line 438 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 172:
#line 439 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 173:
#line 440 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1748 "y.tab.c"
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
