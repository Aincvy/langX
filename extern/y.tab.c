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
#define ADD_EQ 275
#define SUB_EQ 276
#define MUL_EQ 277
#define DIV_EQ 278
#define AUTO 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define FOR 283
#define DELETE 284
#define BREAK 285
#define RETURN 286
#define SWITCH 287
#define CASE 288
#define DEFAULT 289
#define CASE_LIST 290
#define CLAXX_BODY 291
#define NEW 292
#define CLAXX_MEMBER 293
#define CLAXX_FUNC_CALL 294
#define XNULL 295
#define NONASSOC 296
#define IFX 297
#define UMINUS 298
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   49,   49,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   35,   35,   36,   36,   36,   43,   43,   43,
   44,   44,   37,   37,   37,   37,   39,   39,   39,   39,
   40,   40,   40,    5,   45,   45,   46,   46,   46,    7,
    7,    6,    6,    3,    3,    8,    8,    8,   32,   32,
   33,   33,    9,    9,   12,   12,   12,   12,    4,    4,
    4,    4,    4,    4,    4,   42,   42,   24,   24,   24,
   16,   16,   47,   47,   48,   48,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   31,   31,   31,   31,   31,   25,   26,   27,
   28,   29,   30,   41,   23,   23,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   15,   15,   15,   15,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   20,   20,   20,   20,   20,   22,   22,   38,   38,
   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    1,    2,    1,    2,    1,    1,    3,    6,
    3,    3,    3,    3,    6,    3,    6,    9,    6,    6,
    8,   10,    5,    6,    0,    3,    1,    3,    0,    2,
    0,    2,    3,    1,    1,    5,    7,    7,    1,    2,
    4,    3,    5,    9,    0,    1,    1,    1,    1,    1,
    3,    1,    1,    1,    1,    1,    2,    1,    1,    2,
    4,    1,    0,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    3,    3,
    3,    3,    1,    1,    1,    1,    3,    5,    1,    1,
    1,    2,    1,    1,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    2,    2,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    3,    3,    3,    3,
    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   68,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   44,   45,   59,   60,  141,   62,   63,    0,   10,    0,
  142,    0,    0,   65,    0,    0,    0,    0,  100,   67,
    0,    0,    0,    0,    0,  101,    0,  103,    0,    0,
    0,  104,    0,    0,    0,    0,    0,   93,   70,  128,
    0,  122,    0,    0,    0,    0,    0,  130,  131,    0,
   99,    0,    7,    0,    0,    0,    0,    0,    0,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   11,
   17,   15,    0,    0,    0,   13,    0,  136,    0,   75,
    0,   77,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  134,    0,    0,    0,  132,  133,
   94,    0,   57,    0,   56,   58,    0,   61,    0,  116,
  117,    0,    0,  102,   87,   86,    0,  118,  119,    0,
    0,    0,    0,    0,    0,    0,  143,    0,  144,  145,
  146,   43,    0,  137,  138,    0,    0,  139,    0,    0,
    0,  140,   37,    0,   41,   16,   12,   14,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   97,    0,   95,    0,    0,
   91,   92,    0,    0,    0,    0,    0,    0,    0,   36,
    0,    0,    0,   76,    0,  114,  115,   41,   85,    0,
  110,  111,  112,  113,  108,  109,   53,    0,    0,    0,
   88,    0,    0,   98,    0,    0,    0,   33,   38,   34,
   40,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   49,    0,   29,   30,    0,    0,   84,   47,
    0,   20,   27,    0,   41,   48,   50,    0,   31,    0,
    0,   41,    0,    0,   28,   54,    0,    0,   32,
};
static const short yydgoto[] = {                          1,
  209,   16,   17,   18,   19,   20,  201,   21,   22,  113,
  210,  124,   23,   97,   98,  115,  100,  134,  135,   58,
   59,   25,  117,   26,   27,  118,  102,  119,  120,  121,
   66,  242,  243,   29,   95,   96,  106,   31,   32,   33,
   68,   34,   69,   35,   88,  164,  107,  108,    2,
};
static const short yysindex[] = {                         0,
    0,  309,  -37, -229,   -5,   -7,   17,   24, -209,    0,
   43,   34, -181,    0,    0,    0,    0,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52,    0,  -16,
    0,   49, -145,    0,   61,   88, -103,  146,    0,    0,
 -120,  223,  223,  -99,   82,    0,  107,    0, -181, -181,
  103,    0,  -34,  223,    0,    0,    0,    0,    0,    0,
  -44,    0,    0,    0,    0,  322,  116,    0,    0, -181,
    0,  124,    0,  122,  122,  122,  122, -181,   43,    0,
 -181,   43, -181, -181,  126,   43,  -69,   69,  -68,    0,
    0,    0,  143,   11, -101,    0,    0,    0,    0,    0,
  -44,    0,    0,    0,    0,  116,  162,  161,  166,  163,
  116,   49,  -23,    0,    0,    0,  155,  -44,    0,    0,
    0,  -20,    0,  153,    0,    0,  -21,    0,  146,    0,
    0, -181,  122,    0,    0,    0,  173,    0,    0, -181,
  223,  223,  223,  223,  178,  146,    0,  116,    0,    0,
    0,    0,    8,    0,    0,  -42,  182,    0,  184,  197,
  146,    0,    0,   99,    0,    0,    0,    0,  -38,  146,
  146,  223,  223,  186,  223,  223,  223,  223,  223,  223,
  186,  223,  200,  204,  206,    0,  213,    0,   95,   95,
    0,    0,  141,  226,  146,  146,  146,  228,   12,    0,
  277,  237, -181,    0,  239,    0,    0,    0,    0,   16,
    0,    0,    0,    0,    0,    0,    0,  -52,  246,  146,
    0,  146, -112,    0,  257,  258,  263,    0,    0,    0,
    0,  146,  266,  246,  293,  186,  -99,  267,  269,   50,
  256, -115,    0,   56,    0,    0,  275,  146,    0,    0,
  278,    0,    0,  264,    0,    0,    0,  283,    0,  284,
  186,    0,  309,  146,    0,    0,  309,  285,    0,
};
static const short yyrindex[] = {                         0,
    0,  334,   64,  289,    0,    0,    0,    0,    0,    0,
  290,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  641,  291,    0,    0,  214,    0,  302,    0,    0,
    0,    0,    0,  301,    0,    0,  561,    0,    0,    0,
  -13,    0,    0,    0,  462,  496,  741,    0,    0,    0,
  748,    0,  756,  763,  879,    0,  960,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  113,    0,   14,    0,
    0,    0,    0,    0,    0,    0,  140,    0,  488,    0,
  568,    0,  795,  853,  909,  648,    0,  303,  119,  300,
  310,    0,    0,  699,    0,  706,   10,  670,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  302,    0,
    0,    0,    0,    0,    0,    0,  365,    0,    0,    0,
    0,    0,    0,    0,    0,  302,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  748,   72,    0,  583,  590,
  302,    0,    0,    0,    0,    0,    0,    0,  315,    0,
  302,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    0,    0,  612,    0,   91,  719,
    0,    0,    0,    0,  302,  302,  302,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,    0,    0,    0,  677,  302,
    0,  302,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  302,  619,    0,    0,    0,  336,    0,    0,    0,
    0,    0,    0,    7,    0,    0,    0,  302,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -91,  302,    0,    0,    6,    0,    0,
};
static const short yygindex[] = {                         0,
    3,    0,    0,    0,  -10,  -24, -146,    0,    0,  -27,
 -132,  138,  -30,  691,   21,  150,  208,    0,    0,  816,
   38,   26,  833,    0,   20,   -2,   33,  280,  294,  352,
  286,    0,  142,    0,    0,  288,   15,    0,  -29,    0,
    0,    0,    0,    0,    0,    0,  829,    0,    0,
};
#define YYTABLESIZE 1093
static const short yytable[] = {                         28,
   46,  140,   38,  140,   15,  133,  237,  203,   61,  256,
   72,  112,   92,  125,  112,  122,   30,  174,   79,  123,
  181,   90,   78,  167,  140,   67,   91,   18,   39,   83,
   60,   56,   42,   52,   94,  101,   40,   80,  110,   79,
   41,  127,   19,   62,   82,   18,  130,  131,  217,   45,
  107,   78,   27,  152,   78,  111,   43,   99,   30,   46,
   19,  235,   93,   44,  126,   27,   80,  145,  107,   80,
   92,   79,   99,   70,   99,  153,  156,   71,  157,   61,
  159,  160,   54,   61,   91,   37,   73,   53,  148,  148,
  148,  148,   94,   67,   84,   78,   67,   81,   60,   56,
   67,   60,   56,  250,  155,   60,   56,   99,  263,   99,
   80,   62,   79,   85,   62,  267,  154,   23,   62,  158,
   93,   86,   99,  162,   99,   46,  101,   87,  266,  184,
   51,   89,   23,   89,   89,   89,  143,  187,  109,  200,
  128,  144,  199,  101,  206,  207,  129,  148,  132,   89,
   89,   24,   89,   39,  218,   89,   39,   89,  101,  109,
   57,   83,   99,  146,   99,  161,   53,  101,  101,   49,
   50,   28,  240,  241,    5,  240,  241,   99,   28,   99,
   83,   95,   95,   83,   95,   54,   95,   99,   30,  163,
   53,  165,  101,  101,  101,   30,   52,   52,   28,   36,
  233,  166,  169,  231,  170,  171,  125,  112,  140,  172,
  173,  182,  123,  186,  180,   30,  179,  101,  193,  101,
  202,  195,   46,  196,  138,  139,  138,  139,   57,  101,
   36,   57,   28,   28,  127,   57,  197,  231,  172,  173,
  219,  172,  173,  220,   14,  101,  221,  138,  139,   30,
   30,   30,  222,   74,   75,   76,   77,  126,   28,   46,
   28,  101,   54,  223,   28,  231,  224,   53,  228,  231,
  229,  107,  107,   46,   46,   30,  232,   30,   99,  234,
   46,   30,   46,   46,   46,   46,   46,   46,   46,   46,
   63,  203,   46,   51,   51,   99,  236,  244,  245,   46,
   39,   47,   48,  246,   64,  248,   46,  252,  208,  253,
   99,   49,   50,  255,  258,  259,   51,  103,  261,   99,
   99,  262,  264,   24,  265,  269,   74,   75,   76,   77,
   24,  104,  136,    1,   13,   14,   35,   52,   99,   99,
   99,   99,   73,   74,   99,   99,   99,   66,   69,   64,
   24,   14,   89,   89,   89,   89,   89,   89,   63,   55,
   21,   63,   65,  143,  141,   63,  142,   14,  144,   99,
   22,   99,   64,   71,  251,   64,   55,  204,   46,   64,
   47,   99,  168,  257,   24,   24,    0,   99,   99,  105,
   49,   50,    0,   99,   99,   99,   99,   99,    0,    0,
    0,  230,   46,   39,   47,   48,   95,   95,  103,   95,
   24,   95,   24,   99,   49,   50,   24,  249,  175,  176,
  177,  178,  104,    0,    0,  103,  189,  190,  191,  192,
   65,    0,    0,   65,    0,    0,    0,   65,    0,  104,
  103,    0,    0,    0,    3,    0,    0,    0,    0,  103,
  103,    0,    0,    0,  104,    0,    0,    0,    4,    5,
    0,    0,    0,  104,  104,    6,    0,    7,    8,    9,
   10,   11,   12,    0,  103,  103,  103,   13,    0,   46,
  105,   47,   48,    0,    0,    0,    0,    0,  104,  104,
  104,   49,   50,    0,    0,    0,    0,  105,    0,  103,
    0,  103,  123,   95,   95,    0,   95,    0,   95,    0,
    0,  103,  105,  104,    0,  104,    0,    0,    0,  254,
  123,  105,  105,    0,    0,  104,    0,  103,   82,  134,
  134,   82,  134,    0,  134,    3,  127,  136,  136,    0,
  136,  104,  136,  103,    0,    0,  105,  105,  105,    4,
    5,    3,    0,    0,  127,    0,    6,  104,    7,    8,
    9,   10,   11,   12,    0,    4,    5,    3,   13,    0,
    0,  105,    6,  105,    7,    8,    9,   10,   11,   12,
    0,    4,    5,  105,   13,    0,    0,    0,    6,    0,
    7,    8,    9,   10,   11,   12,    0,    0,    0,  105,
   13,   99,   99,   99,   99,   99,   99,   99,   79,  135,
  135,   79,  135,    0,  135,  105,    0,    0,    0,   99,
   99,   99,   99,   26,   26,   26,   26,   26,   26,   26,
   24,   24,   24,   24,   24,   24,   24,    0,    0,    0,
    0,   26,   26,   26,   26,    0,    0,    0,   24,   24,
   24,   24,   23,   23,   23,   23,   23,   23,   23,   25,
   25,   25,   25,   25,   25,   25,    0,    0,    0,    0,
   23,   23,   23,   23,    0,    0,    0,   25,   25,   25,
   25,   72,   72,   72,   72,   72,    0,   72,   96,   96,
   96,   96,   96,    0,   96,    0,    0,    0,    0,   72,
   72,   55,   72,    0,    0,    0,   96,   96,    0,   96,
  135,  135,  135,  135,  135,    0,  135,   71,   71,   71,
   71,   71,    0,   71,    0,    0,    0,    0,  135,  135,
    0,  135,  114,  114,    0,   71,   71,    0,   71,  106,
   95,   95,    0,   95,  137,   95,  105,   93,   93,    0,
   93,    0,   93,    0,    0,    0,    0,  106,  106,   90,
  106,   90,   90,   90,  105,  105,    0,  105,    0,   55,
    0,    0,   55,    0,    0,    0,   55,   90,   90,    0,
   90,  124,  134,  134,    0,  134,    0,  134,  125,  135,
  135,    0,  135,    0,  135,    0,  120,  132,  132,  124,
  132,    0,  132,  121,  133,  133,  125,  133,    0,  133,
    0,    0,    0,    0,  120,    0,    0,    0,    0,    0,
    0,  121,   99,   99,   99,   99,   99,   99,    0,   99,
   99,  188,  188,  188,  188,   78,  132,  132,   78,  132,
    0,  132,    0,    0,   26,   26,   26,   26,   26,   26,
    0,   24,   24,   24,   24,   24,   24,  116,  116,    0,
    0,    0,  114,  114,    0,  114,  114,  114,  114,  114,
  114,    0,  114,   23,   23,   23,   23,   23,   23,    0,
   25,   25,   25,   25,   25,   25,    0,    0,    0,  147,
  149,  150,  151,   81,  133,  133,   81,  133,    0,  133,
    0,    0,   72,   72,   72,   72,   72,   72,    0,   96,
   96,   96,   96,   96,   96,    0,    0,    0,    0,  126,
   94,   94,    0,   94,    0,   94,    0,    0,    0,    0,
    0,  135,  135,  135,  135,  135,  135,  126,   71,   71,
   71,   71,   71,   71,    0,    0,    0,    0,  185,   80,
   94,   94,   80,   94,    0,   94,    0,  183,    0,    0,
  106,  106,  106,  106,  106,  106,    0,  105,  105,  105,
  105,  105,  105,    0,  194,    0,    0,    0,    0,    0,
   90,   90,   90,   90,   90,   90,    0,  116,  116,  198,
  116,  116,  116,  116,  116,  116,    0,  116,    0,  205,
  129,   96,   96,    0,   96,    0,   96,  211,  212,  213,
  214,  215,  216,    0,    0,    0,    0,    0,  129,    0,
    0,    0,    0,  225,  226,  227,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  238,    0,
  239,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  247,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  260,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  268,
};
static const short yycheck[] = {                          2,
    0,   46,   40,   46,    2,   40,   59,   46,   11,  125,
   13,   41,   37,   44,   44,   43,    2,   41,   61,   44,
   41,  125,   44,  125,   46,   11,   37,   41,  258,   46,
   11,   11,   40,  125,   37,   38,    4,   59,   41,   61,
   46,   44,   41,   11,   61,   59,   49,   50,  181,  259,
   41,   44,   46,   78,   44,   41,   40,   44,   44,   59,
   59,  208,   37,   40,   44,   59,   59,   70,   59,   59,
   95,   61,   59,   40,   61,   78,   79,  259,   81,   82,
   83,   84,   40,   86,   95,  123,   59,   45,   74,   75,
   76,   77,   95,   79,   46,   44,   82,   46,   79,   79,
   86,   82,   82,  236,   79,   86,   86,   44,  255,   46,
   59,   79,   61,  259,   82,  262,   79,   46,   86,   82,
   95,   61,   59,   86,   61,  125,  129,   40,  261,  132,
  125,   41,   61,   43,   44,   45,   42,  140,  259,   41,
   59,   47,   44,  146,  172,  173,   40,  133,   46,   59,
   60,    2,   62,   41,  182,  259,   44,  259,  161,  259,
   11,   46,   44,   40,   46,   40,   45,  170,  171,  269,
  270,  174,  288,  289,  274,  288,  289,   59,  181,   61,
   41,   42,   43,   44,   45,   40,   47,   38,  174,  259,
   45,  123,  195,  196,  197,  181,  288,  289,  201,  268,
  203,   59,   41,  201,   44,   40,  237,  237,   46,  262,
  263,   59,  237,   41,   60,  201,   62,  220,   41,  222,
  259,   40,  257,   40,  269,  270,  269,  270,   79,  232,
  268,   82,  235,  236,  237,   86,   40,  235,  262,  263,
   41,  262,  263,   40,   59,  248,   41,  269,  270,  235,
  236,  237,   40,  275,  276,  277,  278,  237,  261,  259,
  263,  264,   40,  123,  267,  263,   41,   45,   41,  267,
  259,  262,  263,  273,  274,  261,   40,  263,  129,   41,
  280,  267,  282,  283,  284,  285,  286,  287,  288,  289,
   11,   46,  292,  288,  289,  146,  281,   41,   41,  257,
  258,  259,  260,   41,   11,   40,  257,   41,  123,   41,
  161,  269,  270,   58,  259,   41,  274,   38,   41,  170,
  171,   58,   40,  174,   41,   41,  275,  276,  277,  278,
  181,   38,   53,    0,  292,   59,  123,  295,  275,  276,
  277,  278,   41,   41,  195,  196,  197,   59,   59,   59,
  201,   59,  262,  263,  264,  265,  266,  267,   79,   59,
   61,   82,   11,   42,   43,   86,   45,   59,   47,  220,
   61,  222,   79,   59,  237,   82,   41,  170,  257,   86,
  259,  232,   95,  242,  235,  236,   -1,  269,  270,   38,
  269,  270,   -1,  275,  276,  277,  278,  248,   -1,   -1,
   -1,  125,  257,  258,  259,  260,   42,   43,  129,   45,
  261,   47,  263,  264,  269,  270,  267,  125,  264,  265,
  266,  267,  129,   -1,   -1,  146,  141,  142,  143,  144,
   79,   -1,   -1,   82,   -1,   -1,   -1,   86,   -1,  146,
  161,   -1,   -1,   -1,  259,   -1,   -1,   -1,   -1,  170,
  171,   -1,   -1,   -1,  161,   -1,   -1,   -1,  273,  274,
   -1,   -1,   -1,  170,  171,  280,   -1,  282,  283,  284,
  285,  286,  287,   -1,  195,  196,  197,  292,   -1,  257,
  129,  259,  260,   -1,   -1,   -1,   -1,   -1,  195,  196,
  197,  269,  270,   -1,   -1,   -1,   -1,  146,   -1,  220,
   -1,  222,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,  232,  161,  220,   -1,  222,   -1,   -1,   -1,  240,
   59,  170,  171,   -1,   -1,  232,   -1,  248,   41,   42,
   43,   44,   45,   -1,   47,  259,   41,   42,   43,   -1,
   45,  248,   47,  264,   -1,   -1,  195,  196,  197,  273,
  274,  259,   -1,   -1,   59,   -1,  280,  264,  282,  283,
  284,  285,  286,  287,   -1,  273,  274,  259,  292,   -1,
   -1,  220,  280,  222,  282,  283,  284,  285,  286,  287,
   -1,  273,  274,  232,  292,   -1,   -1,   -1,  280,   -1,
  282,  283,  284,  285,  286,  287,   -1,   -1,   -1,  248,
  292,   41,   42,   43,   44,   45,   46,   47,   41,   42,
   43,   44,   45,   -1,   47,  264,   -1,   -1,   -1,   59,
   60,   61,   62,   41,   42,   43,   44,   45,   46,   47,
   41,   42,   43,   44,   45,   46,   47,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   59,   60,
   61,   62,   41,   42,   43,   44,   45,   46,   47,   41,
   42,   43,   44,   45,   46,   47,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   59,   60,   61,
   62,   41,   42,   43,   44,   45,   -1,   47,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,
   60,   11,   62,   -1,   -1,   -1,   59,   60,   -1,   62,
   41,   42,   43,   44,   45,   -1,   47,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,   60,
   -1,   62,   42,   43,   -1,   59,   60,   -1,   62,   41,
   42,   43,   -1,   45,   54,   47,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   59,   60,   41,
   62,   43,   44,   45,   59,   60,   -1,   62,   -1,   79,
   -1,   -1,   82,   -1,   -1,   -1,   86,   59,   60,   -1,
   62,   41,   42,   43,   -1,   45,   -1,   47,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   41,   42,   43,   59,
   45,   -1,   47,   41,   42,   43,   59,   45,   -1,   47,
   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,   -1,
   -1,   59,  262,  263,  264,  265,  266,  267,   -1,  269,
  270,  141,  142,  143,  144,   41,   42,   43,   44,   45,
   -1,   47,   -1,   -1,  262,  263,  264,  265,  266,  267,
   -1,  262,  263,  264,  265,  266,  267,   42,   43,   -1,
   -1,   -1,  172,  173,   -1,  175,  176,  177,  178,  179,
  180,   -1,  182,  262,  263,  264,  265,  266,  267,   -1,
  262,  263,  264,  265,  266,  267,   -1,   -1,   -1,   74,
   75,   76,   77,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,  262,
  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,  262,  263,  264,  265,  266,  267,   59,  262,  263,
  264,  265,  266,  267,   -1,   -1,   -1,   -1,  133,   41,
   42,   43,   44,   45,   -1,   47,   -1,  129,   -1,   -1,
  262,  263,  264,  265,  266,  267,   -1,  262,  263,  264,
  265,  266,  267,   -1,  146,   -1,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,  266,  267,   -1,  172,  173,  161,
  175,  176,  177,  178,  179,  180,   -1,  182,   -1,  171,
   41,   42,   43,   -1,   45,   -1,   47,  175,  176,  177,
  178,  179,  180,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   -1,   -1,   -1,  195,  196,  197,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  220,   -1,
  222,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  232,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  248,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  264,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 298
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
"FUNC_CALL","VAR_DECLAR","RESTRICT","THIS","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ",
"AUTO","IF","ELSE","WHILE","FOR","DELETE","BREAK","RETURN","SWITCH","CASE",
"DEFAULT","CASE_LIST","CLAXX_BODY","NEW","CLAXX_MEMBER","CLAXX_FUNC_CALL",
"XNULL","NONASSOC","IFX","UMINUS",
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
"class_declar_stmt : IDENTIFIER '{' '}'",
"class_declar_stmt : IDENTIFIER '{' class_body '}'",
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
#line 388 "a.y"


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
#line 723 "y.tab.c"

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
#line 64 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 68 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 69 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 70 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 71 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 76 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 77 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 78 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 11:
#line 83 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-2].sValue , NULL); }
break;
case 12:
#line 84 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-1].node); }
break;
case 13:
#line 89 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 14:
#line 90 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 15:
#line 94 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 16:
#line 95 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 17:
#line 96 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 18:
#line 101 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 19:
#line 102 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 20:
#line 104 "a.y"
	{ yyval.node = opr(THIS, 1 , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 21:
#line 111 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 22:
#line 112 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 23:
#line 117 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 24:
#line 118 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 25:
#line 119 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 26:
#line 120 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 27:
#line 125 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 28:
#line 126 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 29:
#line 127 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 30:
#line 128 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 31:
#line 133 "a.y"
	{  yyval.node = NULL; }
break;
case 32:
#line 134 "a.y"
	{ yyval.node = NULL; }
break;
case 33:
#line 135 "a.y"
	{ yyval.node = NULL; }
break;
case 34:
#line 140 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 35:
#line 144 "a.y"
	{ yyval.params = NULL; }
break;
case 36:
#line 145 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 37:
#line 149 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 38:
#line 150 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 39:
#line 151 "a.y"
	{ yyval.params = NULL; }
break;
case 40:
#line 155 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 41:
#line 156 "a.y"
	{ yyval.node = NULL; }
break;
case 42:
#line 161 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 43:
#line 162 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 44:
#line 167 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 45:
#line 168 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 173 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 47:
#line 174 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 48:
#line 175 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 49:
#line 179 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 50:
#line 180 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 51:
#line 184 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 52:
#line 185 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 53:
#line 189 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 54:
#line 190 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 55:
#line 195 "a.y"
	{ yyval.node = NULL ; }
break;
case 56:
#line 196 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 197 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 198 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 203 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 204 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 205 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 62:
#line 206 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 207 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 208 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 209 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 215 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 67:
#line 216 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 68:
#line 220 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 69:
#line 221 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 70:
#line 222 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 71:
#line 227 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 72:
#line 228 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 232 "a.y"
	{ yyval.args = NULL; }
break;
case 74:
#line 233 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 75:
#line 237 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 76:
#line 238 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 77:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 78:
#line 243 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 244 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 245 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 246 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 247 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 248 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 84:
#line 252 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 85:
#line 253 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
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
#line 265 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 89:
#line 271 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 90:
#line 272 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 91:
#line 273 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 92:
#line 274 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 93:
#line 279 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 94:
#line 280 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 95:
#line 281 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 96:
#line 282 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 97:
#line 283 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 98:
#line 288 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 99:
#line 292 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 100:
#line 296 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 101:
#line 300 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 102:
#line 304 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 103:
#line 308 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 104:
#line 312 "a.y"
	{ yyval.node = xnull();}
break;
case 105:
#line 317 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 106:
#line 318 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 107:
#line 323 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 324 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 109:
#line 325 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 110:
#line 326 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 111:
#line 327 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 112:
#line 328 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 113:
#line 329 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 330 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 115:
#line 331 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 116:
#line 336 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 117:
#line 337 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 118:
#line 338 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 119:
#line 339 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 120:
#line 344 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 345 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 346 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 123:
#line 347 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 124:
#line 348 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 125:
#line 349 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 350 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 351 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 352 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 353 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 354 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 131:
#line 355 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 132:
#line 360 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 133:
#line 361 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 362 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 135:
#line 363 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 136:
#line 364 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 137:
#line 369 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 138:
#line 370 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 139:
#line 374 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 140:
#line 375 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 141:
#line 380 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 142:
#line 381 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 143:
#line 382 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 144:
#line 383 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 145:
#line 384 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 146:
#line 385 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1505 "y.tab.c"
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
