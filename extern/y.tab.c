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
#define AUTO 284
#define IF 285
#define ELSE 286
#define WHILE 287
#define FOR 288
#define DELETE 289
#define BREAK 290
#define RETURN 291
#define SWITCH 292
#define CASE 293
#define DEFAULT 294
#define CASE_LIST 295
#define CLAXX_BODY 296
#define NEW 297
#define CLAXX_MEMBER 298
#define CLAXX_FUNC_CALL 299
#define XNULL 300
#define NONASSOC 301
#define IFX 302
#define UMINUS 303
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   54,   54,    1,    1,    1,    1,    1,   26,   26,
   27,    2,    2,    2,   36,   36,   53,   53,   37,   37,
   38,   38,   38,   45,   45,   45,   46,   46,   39,   39,
   39,   39,   41,   41,   41,   41,   42,   42,   42,    5,
   49,   49,   50,   50,   50,    7,    7,    6,    6,    6,
    6,    6,    6,    3,    3,    8,    8,    8,   34,   34,
   35,   35,    9,    9,   12,   12,   12,   12,    4,    4,
    4,    4,    4,    4,    4,   44,   44,   24,   24,   24,
   16,   16,   51,   51,   52,   52,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   33,   33,   33,   33,   33,   33,   25,   28,
   29,   30,   30,   31,   32,   43,   23,   23,   23,   23,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   15,
   15,   15,   15,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   20,   20,   20,   20,
   20,   22,   22,   40,   40,   47,   47,   48,   13,   13,
   13,   13,   13,   13,   13,
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
    3,    3,    1,    1,    1,    1,    1,    3,    5,    1,
    1,    1,    1,    2,    1,    1,    1,    1,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    3,    3,    3,    3,    4,    4,    3,    1,    1,
    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   78,    0,    0,    0,    4,    2,    5,    6,    0,   12,
   13,   54,   55,   69,   70,  159,   72,   73,    8,    0,
   14,    0,  160,    0,    0,   75,    0,    0,  161,    0,
    0,    0,    0,    0,  111,   77,    0,   47,    0,    0,
    0,    0,  113,  112,    0,  115,    0,    0,    0,  116,
    0,    0,    0,    0,    0,  103,   80,  142,    0,  136,
    0,    0,    0,    0,    0,  144,  145,    0,    0,  110,
    0,    7,    0,    0,    0,    0,    0,    0,   48,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   18,    0,
  151,    0,   85,    0,   87,    0,    0,    0,    0,  107,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  149,    0,    0,    0,  119,  147,  148,    0,
    0,    0,   67,    0,   66,   68,    0,   71,    0,    0,
  130,  131,    0,    0,  114,   97,   96,    0,  104,  132,
  133,    0,    0,    0,    0,    0,    0,    0,    0,  162,
    0,  163,  164,  165,    0,   49,    0,  152,  153,    0,
    0,  154,    0,    0,    0,  155,  158,   43,    0,   47,
    0,    0,    0,    0,    0,   15,   23,   21,    0,    0,
    0,   19,    0,    0,   46,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  108,    0,  105,    0,    0,  101,  102,    0,    0,
    0,    0,    0,    0,    0,    0,   42,    0,    0,    0,
   86,    0,   50,    0,   52,   22,   16,   20,    0,    0,
   10,  128,  129,   47,   95,    0,  124,  125,  126,  127,
  122,  123,   63,    0,    0,  156,  157,    0,   98,    0,
    0,  109,    0,    0,    0,    0,    0,   39,   44,   40,
    0,    0,   51,   53,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   59,    0,    0,    0,   35,   36,
    0,    0,    0,   94,   57,    0,   26,   33,    0,   47,
   58,   60,    0,   37,    0,    0,    0,   47,    0,    0,
   34,   47,   64,    0,    0,    0,   38,   11,
};
static const short yydgoto[] = {                          1,
  195,   17,   18,   19,   20,   21,  120,   22,   23,  121,
  246,  134,   24,  100,  101,  123,  103,  145,  146,   66,
   67,   26,  125,   27,   28,   29,  241,  126,  105,  128,
  129,  108,   74,  284,  285,   31,  191,  192,  109,   33,
   34,   35,   76,   36,   77,   37,  110,   39,   98,  179,
  111,  112,   44,    2,
};
static const short yysindex[] = {                         0,
    0,  446,  -29, -234,  -19,  -73,   33,   59,   63, -203,
    0,  145,   68, -189,    0,    0,    0,    0,   28,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  373,
    0,   -3,    0,   79, -131,    0,   70,   75,    0,  107,
  -86,  217, -191,   30,    0,    0,  -81,    0,  217,  217,
  -93,  124,    0,    0,  -17,    0, -189, -189,  142,    0,
   52,   67,    0,    0,    0,    0,    0,    0,    8,    0,
    0,    0,    0,  468,  156,    0,    0,    0, -189,    0,
  153,    0,  284,  284,  284,  284,  -35,  145,    0, -189,
  145, -189, -189,  175,  145,  145,  -21,  122,    0,    0,
    0,    0,    0,    8,    0,    0,    0,    0,  156,    0,
  219,  222,  187,  192, -121,  228,  243,  156,   79,  315,
   31,    0,    0,    0,  291,    8,    0,    0,    0,    0,
   37,  -16,    0,  233,    0,    0,  200,    0,  217, -177,
    0,    0, -189,  284,    0,    0,    0,  255,    0,    0,
    0, -189,   67,   67,   67,   67,  258,  217,  262,    0,
  156,    0,    0,    0,  215,    0,   17,    0,    0,    2,
  273,    0,  276,  281,  217,    0,    0,    0,  125,    0,
  -33,  217,   23,   56,  -88,    0,    0,    0,  256,   -8,
 -109,    0,  217,   43,    0,  217,  217,  350,  217,  217,
  217,  217,  217,  217,  350,  217,  282,  238,  239,  294,
  298,    0,  301,    0,   -1,   -1,    0,    0,  220,  306,
  -63,  217,  217,  217,  307,   90,    0,  384,  316, -189,
    0,  -35,    0,  -35,    0,    0,    0,    0,  314,  322,
    0,    0,    0,    0,    0,   81,    0,    0,    0,    0,
    0,    0,    0,  -50,  323,    0,    0,  217,    0,  217,
  -23,    0,  285,  287,  327,  336,  341,    0,    0,    0,
  217,  353,    0,    0,  323, -189,  405,  350,  -93,  356,
  360,   25,  349, -123,    0,   23,   56,  150,    0,    0,
  370,  217,  371,    0,    0,  372,    0,    0,  363,    0,
    0,    0,  378,    0,  381,  308,  350,    0,  446,  217,
    0,    0,    0,  446,  382,  425,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  429,  335,  377,    0,    0,    0,    0,    0,    0,
    0,  379,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  589,  380,    0,    0,    0,    0,  318,
    0,  406,    0,    0,    0,    0,    0,    0,    0,    0,
  387,    0,    0,    0,  703,    0,    0,    0,  -22,    0,
    0,    0,  -12,   85,  554,    0,    0,    0,  792,    0,
  902,  944,  998,    0, 1108,    0,    0, 1115,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  211,    0,    0,  521,
    0,  685,    0,  909,    0, 1005, 1085, 1128,  770,    0,
    0,  407,    0,    0,    0,   50,  388,  391,    0,    0,
    0,  828,    0,  850,  -27,  799,    0,    0,    0,  857,
    0,  300,    0,    0,    0,    0,    0,    0,  406,    0,
    0,    0,    0,    0,    0,    0,    0,  489,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  406,   -7,    0,
    0,    0,    0,    0,   57,    0,    0,    0,    0,  792,
   58,    0,  712,  734,  406,    0,    0,    0,    0,    0,
  394,    0,  398,  399,   20,    0,    0,    0,    0,    0,
    0,    0,  406,   98,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,  741,    0,  870,  877,    0,    0,    0,    0,
    0,  406,  406,  406,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  229,    0,    0,    0,    0,
    0,    0,    0,    0,  821,    0,    0,  406,    0,  406,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  406,  763,    0,    0,    0,    0,    0,    0,  414,    0,
    0,    0,    0,    0,    0,    0,    0,   99,    0,    0,
    0,  406,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -118,  406,
    0,    0,    0, -107,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   13,    0,    0,    0,  -94,   19, -160,    0,    0,  -42,
 -183,  186,  -45, 1097,   14,   26,  290,    0,    0,  874,
  104,  -71,  977,    0,   47,    0,    0,   -2, 1009,  269,
  275, 1152,    7,    0,  182,    0,    0,  278,  121,    0,
  -46,    0,    0,    0,    0,    0,  147,    0,    0,    0,
  973,    0,    0,    0,
};
#define YYTABLESIZE 1358
static const short yytable[] = {                         30,
  119,  301,  221,  186,  119,  135,   62,  131,  279,   69,
   42,   81,  230,  121,   16,  237,  169,   61,   24,  228,
  187,  253,  139,  193,   45,   64,   47,   25,  137,  105,
  105,  121,  105,  110,  105,   87,   24,   65,  110,  104,
  155,   25,   92,  189,  117,  156,  137,  152,  137,   48,
   89,  110,   88,  152,  141,  142,   52,   91,   68,   25,
   87,   43,   88,  110,  136,  113,  232,  102,  114,  133,
   80,  198,   49,  140,   43,   89,  157,  205,  110,  208,
  110,  233,  209,  277,  167,  170,   82,  171,   69,  173,
  174,  144,   69,   69,  295,  110,  187,    9,   50,  234,
  110,   64,   51,   29,   64,  166,   62,   79,   64,   64,
  110,   61,  190,   65,  235,  110,   65,   30,   29,  189,
   65,   65,   32,  313,   93,  141,  151,  151,   94,  151,
   95,  151,   75,  188,   68,   96,  104,   68,  185,  309,
  210,   68,   68,  141,   33,   25,   97,  314,   38,  213,
  185,  316,  115,  242,  243,  104,    9,   33,   78,  215,
  216,  217,  218,  254,  102,  227,  132,  118,  226,  282,
  283,   32,  104,   99,   62,   62,   57,   58,  116,  104,
   40,    5,  138,  102,   62,   61,   61,  143,  190,   61,
  104,  168,  158,  263,  172,   30,  264,   38,  176,  177,
  102,   92,   30,  161,  161,  161,  161,  102,   75,  188,
  245,   75,  196,  197,  175,   75,   75,  245,  102,  104,
  104,  104,    9,   25,  165,   30,  229,  272,   56,  167,
   25,  167,  119,  135,   78,  121,  121,   78,  178,   40,
   32,   78,   78,   87,  180,  152,   41,  102,  102,  102,
  273,   45,  274,   25,   45,  104,   62,  104,   89,  181,
   88,   61,  110,  110,  161,  182,   38,  193,  104,  282,
  283,  150,  151,  293,   30,   30,  137,  150,  151,  183,
   71,   53,   54,  102,  184,  102,   72,   56,  152,  104,
  245,  206,  136,  196,  197,  212,  102,  133,  219,  196,
  197,  139,   25,   25,   30,  221,   30,  104,   53,   54,
  106,   30,  222,   30,  236,  223,  107,  102,   32,  245,
  224,  240,  255,   53,   54,   32,   55,   56,   61,  147,
  256,  257,   25,  258,   25,  102,   57,   58,  259,   25,
  260,   25,  261,  110,   38,  110,  262,  268,   32,  269,
  204,   38,  203,   56,  275,  271,   71,    9,  110,   71,
  110,  276,   72,   71,   71,   72,  278,  288,  230,   72,
   72,    9,    9,   15,   38,    9,  289,  286,  110,  287,
  110,  290,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,  292,  110,    9,  110,  297,   32,   32,   32,
  298,   53,   54,   45,   55,   56,  300,  106,   15,  303,
  304,  306,  307,  107,   57,   58,   87,  310,   90,   59,
  308,  311,  317,   38,   38,   38,  106,   32,    1,   32,
  312,   89,  107,   88,   32,   76,   32,   79,   74,  194,
   41,   14,   15,  106,   60,   65,   83,   84,   27,  107,
  106,   28,   81,   38,   65,   38,  107,   17,  156,  157,
   38,  106,   38,   15,  296,  302,    0,  107,  238,  150,
  151,  231,  244,   53,   54,   45,   55,   56,    0,   83,
   84,   85,   86,   15,    0,    0,   57,   58,   56,    0,
  106,  106,  106,    0,    0,    0,  107,  107,  107,    0,
    0,    0,   56,   56,   15,    0,   56,    0,  270,  155,
  153,    0,  154,   56,  156,   56,   56,   56,   56,   56,
   56,   56,   56,    0,    0,   56,  106,    0,  106,  294,
  105,  105,  107,  105,  107,  105,    0,    0,    0,  106,
   53,   54,    0,  159,    0,  107,    0,    0,    0,  318,
  299,    0,    0,   57,   58,  199,  200,  201,  202,    0,
  106,   93,  105,  105,   93,  105,  107,  105,    0,  110,
  110,    0,    0,    0,    3,    0,    0,    0,  106,  110,
  110,  110,  110,    0,  107,    0,    0,    0,    4,    5,
    0,    0,    6,    0,  138,  149,  149,    0,  149,    7,
  149,    8,    9,   10,   11,   12,   13,    0,    0,    3,
    0,   14,  138,    0,  110,  110,  110,  110,    0,    0,
    0,    0,    0,    4,    5,    0,    0,    6,    0,   82,
   82,   82,   82,   82,    7,   82,    8,    9,   10,   11,
   12,   13,    0,    3,    0,    0,   14,   82,   82,    0,
   82,    0,   83,   84,   85,   86,    0,    4,    5,    0,
    0,    6,    0,    0,    3,    0,    0,    0,    7,    0,
    8,    9,   10,   11,   12,   13,    0,    0,    4,    5,
   14,    0,    6,    0,    3,    0,    0,    0,    0,    7,
    0,    8,    9,   10,   11,   12,   13,    0,    4,    5,
    0,   14,    6,    0,    0,    3,    0,    0,    0,    7,
    0,    8,    9,   10,   11,   12,   13,    0,    0,    4,
    5,   14,    0,    6,    0,   92,  149,  149,   92,  149,
    7,  149,    8,    9,   10,   11,   12,   13,    0,    0,
    0,    0,   14,  110,  110,  110,  110,  110,  110,  110,
    0,    0,   32,   32,   32,   32,   32,   32,   32,    0,
    0,  110,  110,  110,  110,    0,    0,    0,    0,    0,
   32,   32,   32,   32,   30,   30,   30,   30,   30,   30,
   30,   29,   29,   29,   29,   29,   29,   29,    0,    0,
    0,    0,   30,   30,   30,   30,    0,    0,    0,   29,
   29,   29,   29,   31,   31,   31,   31,   31,   31,   31,
  106,  106,  106,  106,  106,    0,  106,    0,    0,    0,
    0,   31,   31,   31,   31,    0,    0,    0,  106,  106,
    0,  106,  139,  150,  150,    0,  150,    0,  150,  150,
  150,  150,  150,  150,    0,  150,    0,    0,    0,    0,
  139,   82,   82,   82,   82,   82,   82,  150,  150,    0,
  150,   81,   81,   81,   81,   81,    0,   81,  118,  105,
  105,    0,  105,    0,  105,    0,    0,    0,    0,   81,
   81,    0,   81,    0,    0,    0,  118,  118,    0,  118,
  117,  103,  103,    0,  103,    0,  103,  120,  104,  104,
    0,  104,    0,  104,    0,    0,    0,    0,  117,  117,
   99,  117,   99,   99,   99,  120,  120,  100,  120,  100,
  100,  100,  124,  124,    0,    0,    0,    0,   99,   99,
    0,   99,    0,    0,    0,  100,  100,    0,  100,    0,
    0,    0,  134,  147,  147,    0,  147,    0,  147,   89,
  150,  150,   89,  150,    0,  150,  160,  162,  163,  164,
  134,    0,    0,    0,    0,  110,  110,  110,  110,  110,
  110,    0,  110,  110,   32,   32,   32,   32,   32,   32,
    0,    0,    0,    0,  135,  148,  148,    0,  148,    0,
  148,    0,    0,    0,    0,    0,   30,   30,   30,   30,
   30,   30,  135,   29,   29,   29,   29,   29,   29,    0,
    0,    0,   46,    0,    0,    0,    0,  211,    0,    0,
   70,    0,    0,    0,    0,   31,   31,   31,   31,   31,
   31,    0,  106,  106,  106,  106,  106,  106,  140,  104,
  104,    0,  104,    0,  104,   88,  147,  147,   88,  147,
    0,  147,    0,    0,    0,    0,  140,  127,  127,    0,
    0,  150,  150,  150,  150,  150,  150,    0,    0,  124,
  124,    0,  124,  124,  124,  124,  124,  124,    0,  124,
    0,    0,    0,   81,   81,   81,   81,   81,   81,    0,
  118,  118,  118,  118,  118,  118,   70,    0,    0,   70,
    0,    0,    0,   70,   70,    0,    0,    0,   63,    0,
    0,  207,  117,  117,  117,  117,  117,  117,    0,  120,
  120,  120,  120,  120,  120,   91,  148,  148,   91,  148,
  220,  148,   99,   99,   99,   99,   99,   99,    0,  100,
  100,  100,  100,  100,  100,  122,  122,  225,  143,  106,
  106,    0,  106,    0,  106,  146,  107,  107,  148,  107,
    0,  107,    0,   73,    0,  239,  143,    0,   90,  104,
  104,   90,  104,  146,  104,  247,  248,  249,  250,  251,
  252,    0,    0,    0,   63,    0,    0,   63,    0,    0,
    0,   63,   63,    0,  265,  266,  267,    0,    0,    0,
  130,  130,    0,    0,  127,  127,    0,  127,  127,  127,
  127,  127,  127,  149,  127,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  280,    0,  281,    0,    0,    0,    0,    0,    0,   73,
    0,    0,   73,  291,    0,    0,   73,   73,    0,  214,
  214,  214,  214,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  305,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  315,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  122,  122,    0,  122,  122,  122,  122,  122,
  122,    0,  122,    0,  149,  149,  149,  149,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  130,  130,    0,
  130,  130,  130,  130,  130,  130,    0,  130,
};
static const short yycheck[] = {                          2,
   47,  125,   91,  125,   51,   51,  125,   50,   59,   12,
   40,   14,   46,   41,    2,  125,   88,  125,   41,  180,
  115,  205,   40,   40,  259,   12,   46,    2,   41,   42,
   43,   59,   45,   41,   47,   44,   59,   12,   46,   42,
   42,   41,   46,  115,   47,   47,   59,   46,   51,  123,
   59,   59,   61,   46,   57,   58,  260,   61,   12,   59,
   44,   91,   61,   44,   51,  257,   44,   42,  260,   51,
  260,   41,   40,   91,   91,   59,   79,   41,   59,  257,
   61,   59,  260,  244,   87,   88,   59,   90,   91,   92,
   93,   40,   95,   96,  278,   46,  191,    0,   40,   44,
   44,   88,   40,   46,   91,   87,   40,   40,   95,   96,
   61,   45,  115,   88,   59,   59,   91,  120,   61,  191,
   95,   96,    2,  307,   46,   41,   42,   43,  260,   45,
   61,   47,   12,  115,   88,   61,  139,   91,  260,  300,
  143,   95,   96,   59,   46,  120,   40,  308,    2,  152,
  260,  312,  123,  196,  197,  158,   59,   59,   12,  153,
  154,  155,  156,  206,  139,   41,  260,   47,   44,  293,
  294,   51,  175,  260,  293,  294,  270,  271,  260,  182,
  269,  275,   59,  158,   40,  293,  294,   46,  191,   45,
  193,   88,   40,  257,   91,  198,  260,   51,   95,   96,
  175,   46,  205,   83,   84,   85,   86,  182,   88,  191,
  198,   91,  263,  264,   40,   95,   96,  205,  193,  222,
  223,  224,  125,  198,  260,  228,  260,  230,    0,  232,
  205,  234,  279,  279,   88,  263,  264,   91,  260,  269,
  120,   95,   96,   44,  123,   46,  276,  222,  223,  224,
  232,   41,  234,  228,   44,  258,   40,  260,   59,   41,
   61,   45,  270,  271,  144,   44,  120,   40,  271,  293,
  294,  270,  271,  276,  277,  278,  279,  270,  271,   93,
   12,  257,  258,  258,   93,  260,   12,   59,   46,  292,
  278,   59,  279,  263,  264,   41,  271,  279,   41,  263,
  264,   40,  277,  278,  307,   91,  309,  310,  257,  258,
   42,  314,   40,  316,   59,   40,   42,  292,  198,  307,
   40,  279,   41,  257,  258,  205,  260,  261,   45,   61,
   93,   93,  307,   40,  309,  310,  270,  271,   41,  314,
   40,  316,  123,   44,  198,   46,   41,   41,  228,  260,
   60,  205,   62,  125,   41,   40,   88,  260,   59,   91,
   61,   40,   88,   95,   96,   91,  286,   41,   46,   95,
   96,  274,  275,   59,  228,  278,   41,   93,   44,   93,
   46,   41,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,   40,   59,  297,   61,   41,  277,  278,  279,
   41,  257,  258,  259,  260,  261,   58,  139,   59,  260,
   41,   41,   41,  139,  270,  271,   44,   40,   46,  275,
   58,   41,   41,  277,  278,  279,  158,  307,    0,  309,
  123,   59,  158,   61,  314,   59,  316,   59,   59,  125,
  123,  297,   59,  175,  300,   59,   41,   41,   61,  175,
  182,   61,   59,  307,   41,  309,  182,  123,   61,   61,
  314,  193,  316,   59,  279,  284,   -1,  193,  191,  270,
  271,  182,  123,  257,  258,  259,  260,  261,   -1,  280,
  281,  282,  283,   59,   -1,   -1,  270,  271,  260,   -1,
  222,  223,  224,   -1,   -1,   -1,  222,  223,  224,   -1,
   -1,   -1,  274,  275,   59,   -1,  278,   -1,  125,   42,
   43,   -1,   45,  285,   47,  287,  288,  289,  290,  291,
  292,  293,  294,   -1,   -1,  297,  258,   -1,  260,  125,
   42,   43,  258,   45,  260,   47,   -1,   -1,   -1,  271,
  257,  258,   -1,  260,   -1,  271,   -1,   -1,   -1,  125,
  282,   -1,   -1,  270,  271,  265,  266,  267,  268,   -1,
  292,   41,   42,   43,   44,   45,  292,   47,   -1,  270,
  271,   -1,   -1,   -1,  260,   -1,   -1,   -1,  310,  280,
  281,  282,  283,   -1,  310,   -1,   -1,   -1,  274,  275,
   -1,   -1,  278,   -1,   41,   42,   43,   -1,   45,  285,
   47,  287,  288,  289,  290,  291,  292,   -1,   -1,  260,
   -1,  297,   59,   -1,  280,  281,  282,  283,   -1,   -1,
   -1,   -1,   -1,  274,  275,   -1,   -1,  278,   -1,   41,
   42,   43,   44,   45,  285,   47,  287,  288,  289,  290,
  291,  292,   -1,  260,   -1,   -1,  297,   59,   60,   -1,
   62,   -1,  280,  281,  282,  283,   -1,  274,  275,   -1,
   -1,  278,   -1,   -1,  260,   -1,   -1,   -1,  285,   -1,
  287,  288,  289,  290,  291,  292,   -1,   -1,  274,  275,
  297,   -1,  278,   -1,  260,   -1,   -1,   -1,   -1,  285,
   -1,  287,  288,  289,  290,  291,  292,   -1,  274,  275,
   -1,  297,  278,   -1,   -1,  260,   -1,   -1,   -1,  285,
   -1,  287,  288,  289,  290,  291,  292,   -1,   -1,  274,
  275,  297,   -1,  278,   -1,   41,   42,   43,   44,   45,
  285,   47,  287,  288,  289,  290,  291,  292,   -1,   -1,
   -1,   -1,  297,   41,   42,   43,   44,   45,   46,   47,
   -1,   -1,   41,   42,   43,   44,   45,   46,   47,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   41,   42,   43,   44,   45,   46,
   47,   41,   42,   43,   44,   45,   46,   47,   -1,   -1,
   -1,   -1,   59,   60,   61,   62,   -1,   -1,   -1,   59,
   60,   61,   62,   41,   42,   43,   44,   45,   46,   47,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   59,   60,
   -1,   62,   41,   42,   43,   -1,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,
   59,  263,  264,  265,  266,  267,  268,   59,   60,   -1,
   62,   41,   42,   43,   44,   45,   -1,   47,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   59,   60,   -1,   62,
   41,   42,   43,   -1,   45,   -1,   47,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,   60,
   41,   62,   43,   44,   45,   59,   60,   41,   62,   43,
   44,   45,   49,   50,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,   83,   84,   85,   86,
   59,   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,
  268,   -1,  270,  271,  263,  264,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,  263,  264,  265,  266,
  267,  268,   59,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,    4,   -1,   -1,   -1,   -1,  144,   -1,   -1,
   12,   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,
  268,   -1,  263,  264,  265,  266,  267,  268,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,   -1,   -1,   59,   49,   50,   -1,
   -1,  263,  264,  265,  266,  267,  268,   -1,   -1,  196,
  197,   -1,  199,  200,  201,  202,  203,  204,   -1,  206,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   -1,
  263,  264,  265,  266,  267,  268,   88,   -1,   -1,   91,
   -1,   -1,   -1,   95,   96,   -1,   -1,   -1,   12,   -1,
   -1,  139,  263,  264,  265,  266,  267,  268,   -1,  263,
  264,  265,  266,  267,  268,   41,   42,   43,   44,   45,
  158,   47,  263,  264,  265,  266,  267,  268,   -1,  263,
  264,  265,  266,  267,  268,   49,   50,  175,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   62,   45,
   -1,   47,   -1,   12,   -1,  193,   59,   -1,   41,   42,
   43,   44,   45,   59,   47,  199,  200,  201,  202,  203,
  204,   -1,   -1,   -1,   88,   -1,   -1,   91,   -1,   -1,
   -1,   95,   96,   -1,  222,  223,  224,   -1,   -1,   -1,
   49,   50,   -1,   -1,  196,  197,   -1,  199,  200,  201,
  202,  203,  204,   62,  206,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  258,   -1,  260,   -1,   -1,   -1,   -1,   -1,   -1,   88,
   -1,   -1,   91,  271,   -1,   -1,   95,   96,   -1,  153,
  154,  155,  156,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  292,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  310,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  196,  197,   -1,  199,  200,  201,  202,  203,
  204,   -1,  206,   -1,  153,  154,  155,  156,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  196,  197,   -1,
  199,  200,  201,  202,  203,  204,   -1,  206,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
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
"ARRAY_ELE","XTRY","XCATCH","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF",
"ELSE","WHILE","FOR","DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT",
"CASE_LIST","CLAXX_BODY","NEW","CLAXX_MEMBER","CLAXX_FUNC_CALL","XNULL",
"NONASSOC","IFX","UMINUS",
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
#line 431 "a.y"


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
#line 826 "y.tab.c"

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
#line 304 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 104:
#line 305 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 105:
#line 306 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 106:
#line 307 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 107:
#line 308 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 309 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 109:
#line 314 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 110:
#line 318 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 111:
#line 322 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 112:
#line 326 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 113:
#line 327 "a.y"
	{ yyval.node = number(yystack.l_mark[0].intValue); }
break;
case 114:
#line 331 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 115:
#line 335 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 116:
#line 339 "a.y"
	{ yyval.node = xnull();}
break;
case 117:
#line 344 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 118:
#line 345 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 119:
#line 346 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 120:
#line 347 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 352 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 353 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 123:
#line 354 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 124:
#line 355 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 125:
#line 356 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 126:
#line 357 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 127:
#line 358 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 128:
#line 359 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 129:
#line 360 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 130:
#line 365 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 131:
#line 366 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 132:
#line 367 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 133:
#line 368 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 134:
#line 373 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 135:
#line 374 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 136:
#line 375 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 376 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 138:
#line 377 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 139:
#line 378 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 140:
#line 379 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 380 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 142:
#line 381 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 143:
#line 382 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 144:
#line 383 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 145:
#line 384 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 146:
#line 385 "a.y"
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
#line 399 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 153:
#line 400 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 154:
#line 404 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 155:
#line 405 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 156:
#line 410 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, yystack.l_mark[-1].intValue, NULL); }
break;
case 157:
#line 411 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, -1, var(yystack.l_mark[-1].sValue)) ; }
break;
case 158:
#line 417 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 159:
#line 422 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 160:
#line 423 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 161:
#line 424 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 162:
#line 425 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 163:
#line 426 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 164:
#line 427 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 165:
#line 428 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1684 "y.tab.c"
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
