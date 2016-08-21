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
   14,   14,   31,   31,   31,   31,   25,   26,   27,   28,
   29,   30,   41,   23,   23,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   15,   15,   15,   15,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   20,   20,   20,   20,   20,   22,   22,   38,   38,   13,
   13,   13,   13,   13,   13,
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
    3,    3,    1,    1,    1,    3,    5,    1,    1,    1,
    2,    1,    1,    1,    1,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    2,    2,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    3,    3,    3,    1,
    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   68,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   44,   45,   59,   60,  140,   62,   63,    0,   10,    0,
  141,    0,    0,   65,    0,    0,    0,    0,   99,   67,
    0,    0,    0,    0,    0,  100,    0,  102,    0,    0,
    0,  103,    0,    0,    0,    0,    0,   93,   70,  127,
    0,  121,    0,    0,    0,    0,    0,  129,  130,    0,
   98,    0,    7,    0,    0,    0,    0,    0,    0,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   11,
   17,   15,    0,    0,    0,   13,    0,  135,    0,   75,
    0,   77,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  133,    0,    0,    0,  131,  132,
   94,    0,   57,    0,   56,   58,    0,   61,    0,  115,
  116,    0,    0,  101,   87,   86,    0,  117,  118,    0,
    0,    0,    0,    0,    0,    0,  142,  143,  144,  145,
   43,    0,  136,  137,    0,    0,  138,    0,    0,    0,
  139,   37,    0,   41,   16,   12,   14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   96,    0,   95,    0,    0,   91,
   92,    0,    0,    0,    0,    0,    0,    0,   36,    0,
    0,    0,   76,    0,  113,  114,   41,   85,    0,  109,
  110,  111,  112,  107,  108,   53,    0,    0,    0,   88,
    0,    0,   97,    0,    0,    0,   33,   38,   34,   40,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   49,    0,   29,   30,    0,    0,   84,   47,    0,
   20,   27,    0,   41,   48,   50,    0,   31,    0,    0,
   41,    0,    0,   28,   54,    0,    0,   32,
};
static const short yydgoto[] = {                          1,
  208,   16,   17,   18,   19,   20,  200,   21,   22,  113,
  209,  124,   23,   97,   98,  115,  100,  134,  135,   58,
   59,   25,  117,   26,   27,  118,  102,  119,  120,  121,
   66,  241,  242,   29,   95,   96,  106,   31,   32,   33,
   68,   34,   69,   35,   88,  163,  107,  108,    2,
};
static const short yysindex[] = {                         0,
    0,  297,  -33, -236,   -8,   14,   25,   39, -215,    0,
   65,   47, -211,    0,    0,    0,    0,   11,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   86,    0,   12,
    0,   15, -166,    0,   34,  103,  -99,  165,    0,    0,
 -104,  161,  161,   36,   98,    0,  118,    0, -211, -211,
  131,    0,  -37,  161,    0,    0,    0,    0,    0,    0,
  -38,    0,    0,    0,    0,  351,  137,    0,    0, -211,
    0,  124,    0,  251,  251,  251,  251, -211,   65,    0,
 -211,   65, -211, -211,  145,   65,  -69,   72,  -68,    0,
    0,    0,  140,   -2,  -96,    0,    0,    0,    0,    0,
  -38,    0,    0,    0,    0,  137,  162,  167,  169,  166,
  137,   15,   -4,    0,    0,    0,  -48,  -38,    0,    0,
    0,    9,    0,  180,    0,    0,  -25,    0,  165,    0,
    0, -211,  251,    0,    0,    0,  183,    0,    0, -211,
  161,  161,  161,  161,  185,  165,    0,    0,    0,    0,
    0,   30,    0,    0,  -41,  203,    0,  206,  215,  165,
    0,    0,   75,    0,    0,    0,    0,  -44,  165,  165,
  161,  161,  252,  161,  161,  161,  161,  161,  161,  252,
  161,  220,  223,  225,    0,  236,    0,  142,  142,    0,
    0,  155,  238,  165,  165,  165,  239,   32,    0,  117,
  242, -211,    0,  257,    0,    0,    0,    0,   26,    0,
    0,    0,    0,    0,    0,    0,  -49,  246,  165,    0,
  165, -171,    0,  258,  263,  272,    0,    0,    0,    0,
  165,  260,  246,  189,  252,   36,  274,  275,   62,  262,
 -119,    0,   71,    0,    0,  285,  165,    0,    0,  290,
    0,    0,  279,    0,    0,    0,  292,    0,  299,  252,
    0,  297,  165,    0,    0,  297,  308,    0,
};
static const short yyrindex[] = {                         0,
    0,  350,   95,  300,    0,    0,    0,    0,    0,    0,
  307,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  571,  309,    0,    0,  228,    0,  317,    0,    0,
    0,    0,    0,  315,    0,    0,  549,    0,    0,    0,
    4,    0,    0,    0,  400,  454,  510,    0,    0,    0,
  517,    0,  670,  683,  693,    0,    8,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   84,    0,   68,    0,
    0,    0,    0,    0,    0,    0,  702,    0,  712,    0,
  725,    0,  732,  739,  746,    0,    0,  337,   77,  320,
  324,    0,    0,  607,    0,  629,   -6,  578,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  317,    0,
    0,    0,    0,    0,    0,    0,  370,    0,    0,    0,
    0,    0,    0,    0,    0,  317,    0,    0,    0,    0,
    0,    0,    0,    0,  517,   31,    0,   63,   74,  317,
    0,    0,    0,    0,    0,    0,    0,  327,    0,  317,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   23,    0,    0,  132,    0,  443,  620,    0,
    0,    0,    0,  317,  317,  317,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,    0,    0,  600,  317,    0,
  317,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  317,  133,    0,    0,    0,  346,    0,    0,    0,    0,
    0,    0,  -18,    0,    0,    0,  317,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -108,  317,    0,    0, -101,    0,    0,
};
static const short yygindex[] = {                         0,
    7,    0,    0,    0,  -19,   18, -160,    0,    0,  -20,
 -169,  153,  -28,  679,  -11,  148,  237,    0,    0,  523,
   58,   19,  428,    0,   20,    2,   21,  259,  298,  354,
   24,    0,  175,    0,    0,  312,   67,    0,  -14,    0,
    0,    0,    0,    0,    0,    0,  730,    0,    0,
};
#define YYTABLESIZE 993
static const short yytable[] = {                         56,
   46,  202,  133,   28,  140,  255,   38,  140,   15,  236,
  216,  179,   61,  178,   72,  125,   52,   91,   78,   79,
  140,   39,  122,   51,   40,   90,  112,   27,  166,  112,
   60,   62,  126,   80,  106,   79,  173,   41,   94,  101,
   27,   78,  110,   45,   18,  127,  234,   71,  128,  180,
  130,  131,  106,   42,   92,   93,   80,   83,   79,   46,
   84,  123,   18,   19,   43,  249,  128,   56,   30,   73,
   56,  145,   82,   78,   56,   91,   23,   67,   44,  152,
  155,   19,  156,   61,  158,  159,   70,   61,   80,   37,
  265,   23,   85,  262,   86,  151,   94,  154,   60,   62,
  266,   60,   62,   26,   54,   60,   62,  111,   26,   53,
   30,   98,   92,   93,   24,  199,  239,  240,  198,   24,
   98,   26,   98,   26,   39,   46,   98,   39,   98,   78,
  101,   81,   24,  183,   24,   98,  153,   98,   98,  157,
   98,  186,   87,  161,   80,   67,   79,  101,   67,   24,
  205,  206,   67,   98,  109,   98,  128,  129,   57,   89,
  217,  101,   89,  146,  188,  189,  190,  191,  239,  240,
  101,  101,   23,   25,   28,   14,  132,   23,   25,   52,
   52,   28,   83,  143,  160,   99,   51,   51,  144,  162,
   23,   25,   23,   25,  164,  101,  101,  101,  165,   36,
   54,   28,  168,  232,   54,   53,  230,  125,  170,   53,
  169,  140,  171,  172,  201,  174,  175,  176,  177,   46,
  101,  112,  101,  185,  126,  192,   57,  138,  139,   57,
  138,  139,  101,   57,   36,   28,   28,  127,  181,   30,
  230,  229,  194,  138,  139,  195,   30,   14,  101,   74,
   75,   76,   77,  123,  196,  106,  106,  171,  172,   46,
  218,   28,  219,   28,  101,  220,   30,   28,  230,   63,
  171,  172,  230,   46,   46,  221,   99,  222,  223,  227,
   46,  231,   46,   46,   46,   46,   46,   46,   46,   46,
  228,  202,   46,   99,  109,   53,  103,  233,  243,  247,
   30,   30,   30,  244,   49,   50,  235,   99,   64,    5,
   14,  136,  245,  248,  251,  252,   99,   99,   46,  254,
   24,   46,   39,   47,   48,  258,   30,   24,   30,  257,
  260,  263,   30,   49,   50,  104,  261,   63,   51,  264,
   63,   99,   99,   99,   63,   98,   98,   24,  268,    1,
   35,   98,   98,   98,   98,   14,   13,   73,   66,   52,
   74,   75,   76,   77,   65,   69,   99,   64,   99,   98,
   98,   98,   98,   55,  207,    3,   64,   74,   99,   64,
   21,   24,   24,   64,   22,   71,   55,  103,  250,    4,
    5,  105,  143,  141,   99,  142,    6,  144,    7,    8,
    9,   10,   11,   12,  103,  203,  167,   24,   13,   24,
   99,   95,   95,   24,   95,  256,   95,   46,  103,   47,
   48,   46,   39,   47,   48,    0,  104,  103,  103,   49,
   50,    0,   65,   49,   50,   65,    0,    0,    0,   65,
  122,   95,   95,  104,   95,    0,   95,    3,    0,    0,
    0,    0,  103,  103,  103,    0,    0,  104,  122,    0,
    0,    4,    5,    0,    0,    0,  104,  104,    6,    0,
    7,    8,    9,   10,   11,   12,    0,  103,    0,  103,
   13,    0,  105,   89,    0,   89,   89,   89,    0,  103,
    0,  104,  104,  104,  126,  135,  135,  253,  135,  105,
  135,   89,   89,    0,   89,  103,    0,   46,    0,   47,
    3,    0,  126,  105,    0,    0,  104,    0,  104,   49,
   50,  103,  105,  105,    4,    5,    0,    0,  104,    0,
    0,    6,    0,    7,    8,    9,   10,   11,   12,    0,
    0,    0,    0,   13,  104,    0,    0,  105,  105,  105,
  123,  133,  133,    0,  133,    3,  133,  124,  134,  134,
  104,  134,    0,  134,  116,  116,    0,    0,  123,    4,
    5,    0,  105,    0,  105,  124,    6,    0,    7,    8,
    9,   10,   11,   12,  105,    0,    0,    0,   13,   98,
   98,   98,   98,   98,   98,   98,  147,  148,  149,  150,
  105,  210,  211,  212,  213,  214,  215,   98,   98,   98,
   98,   72,   72,   72,   72,   72,  105,   72,  134,  134,
  134,  134,  134,    0,  134,    0,    0,    0,    0,   72,
   72,    0,   72,    0,    0,    0,  134,  134,    0,  134,
   71,   71,   71,   71,   71,    0,   71,  105,   95,   95,
    0,   95,    0,   95,    0,  184,    0,    0,   71,   71,
   90,   71,   90,   90,   90,  105,  105,    0,  105,  104,
   93,   93,    0,   93,    0,   93,    0,    0,   90,   90,
    0,   90,    0,    0,    0,    0,    0,  104,  104,   55,
  104,    0,    0,  116,  116,    0,  116,  116,  116,  116,
  116,  116,    0,  116,   89,   89,   89,   89,   89,   89,
  119,  131,  131,    0,  131,    0,  131,    0,    0,    0,
  114,  114,    0,  120,  132,  132,    0,  132,  119,  132,
    0,    0,  137,  125,   94,   94,    0,   94,    0,   94,
    0,  120,   83,   95,   95,   83,   95,    0,   95,    0,
    0,  125,   82,  133,  133,   82,  133,   55,  133,    0,
   55,    0,    0,    0,   55,   79,  134,  134,   79,  134,
    0,  134,   78,  131,  131,   78,  131,    0,  131,   81,
  132,  132,   81,  132,    0,  132,   80,   94,   94,   80,
   94,    0,   94,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   98,   98,   98,   98,   98,   98,    0,   98,   98,  187,
  187,  187,  187,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   72,   72,   72,   72,   72,   72,    0,  134,
  134,  134,  134,  134,  134,    0,    0,    0,    0,  114,
  114,    0,  114,  114,  114,  114,  114,  114,  182,  114,
    0,   71,   71,   71,   71,   71,   71,    0,  105,  105,
  105,  105,  105,  105,    0,  193,    0,    0,    0,    0,
    0,   90,   90,   90,   90,   90,   90,    0,    0,  197,
  104,  104,  104,  104,  104,  104,    0,    0,    0,  204,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  224,  225,  226,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  237,    0,
  238,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  246,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  259,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  267,
};
static const short yycheck[] = {                         11,
    0,   46,   40,    2,   46,  125,   40,   46,    2,   59,
  180,   60,   11,   62,   13,   44,  125,   37,   44,   61,
   46,  258,   43,  125,    4,  125,   41,   46,  125,   44,
   11,   11,   44,   59,   41,   61,   41,   46,   37,   38,
   59,   44,   41,  259,   41,   44,  207,  259,   41,   41,
   49,   50,   59,   40,   37,   37,   59,   46,   61,   59,
   46,   44,   59,   41,   40,  235,   59,   79,    2,   59,
   82,   70,   61,   44,   86,   95,   46,   11,   40,   78,
   79,   59,   81,   82,   83,   84,   40,   86,   59,  123,
  260,   61,  259,  254,   61,   78,   95,   79,   79,   79,
  261,   82,   82,   41,   40,   86,   86,   41,   46,   45,
   44,   44,   95,   95,   41,   41,  288,  289,   44,   46,
   44,   59,   46,   61,   41,  125,   59,   44,   61,   44,
  129,   46,   59,  132,   61,   59,   79,   61,   44,   82,
   46,  140,   40,   86,   59,   79,   61,  146,   82,    2,
  171,  172,   86,   59,  259,   61,   59,   40,   11,  259,
  181,  160,  259,   40,  141,  142,  143,  144,  288,  289,
  169,  170,   41,   41,  173,   59,   46,   46,   46,  288,
  289,  180,   46,   42,   40,   38,  288,  289,   47,  259,
   59,   59,   61,   61,  123,  194,  195,  196,   59,  268,
   40,  200,   41,  202,   40,   45,  200,  236,   40,   45,
   44,   46,  262,  263,  259,  264,  265,  266,  267,  257,
  219,  236,  221,   41,  236,   41,   79,  269,  270,   82,
  269,  270,  231,   86,  268,  234,  235,  236,   59,  173,
  234,  125,   40,  269,  270,   40,  180,   59,  247,  275,
  276,  277,  278,  236,   40,  262,  263,  262,  263,  259,
   41,  260,   40,  262,  263,   41,  200,  266,  262,   11,
  262,  263,  266,  273,  274,   40,  129,  123,   41,   41,
  280,   40,  282,  283,  284,  285,  286,  287,  288,  289,
  259,   46,  292,  146,  259,   45,   38,   41,   41,   40,
  234,  235,  236,   41,  269,  270,  281,  160,   11,  274,
   59,   53,   41,  125,   41,   41,  169,  170,  257,   58,
  173,  257,  258,  259,  260,   41,  260,  180,  262,  259,
   41,   40,  266,  269,  270,   38,   58,   79,  274,   41,
   82,  194,  195,  196,   86,  269,  270,  200,   41,    0,
  123,  275,  276,  277,  278,   59,  292,   41,   59,  295,
  275,  276,  277,  278,   11,   59,  219,   59,  221,  275,
  276,  277,  278,   59,  123,  259,   79,   41,  231,   82,
   61,  234,  235,   86,   61,   59,   41,  129,  236,  273,
  274,   38,   42,   43,  247,   45,  280,   47,  282,  283,
  284,  285,  286,  287,  146,  169,   95,  260,  292,  262,
  263,   42,   43,  266,   45,  241,   47,  257,  160,  259,
  260,  257,  258,  259,  260,   -1,  129,  169,  170,  269,
  270,   -1,   79,  269,  270,   82,   -1,   -1,   -1,   86,
   41,   42,   43,  146,   45,   -1,   47,  259,   -1,   -1,
   -1,   -1,  194,  195,  196,   -1,   -1,  160,   59,   -1,
   -1,  273,  274,   -1,   -1,   -1,  169,  170,  280,   -1,
  282,  283,  284,  285,  286,  287,   -1,  219,   -1,  221,
  292,   -1,  129,   41,   -1,   43,   44,   45,   -1,  231,
   -1,  194,  195,  196,   41,   42,   43,  239,   45,  146,
   47,   59,   60,   -1,   62,  247,   -1,  257,   -1,  259,
  259,   -1,   59,  160,   -1,   -1,  219,   -1,  221,  269,
  270,  263,  169,  170,  273,  274,   -1,   -1,  231,   -1,
   -1,  280,   -1,  282,  283,  284,  285,  286,  287,   -1,
   -1,   -1,   -1,  292,  247,   -1,   -1,  194,  195,  196,
   41,   42,   43,   -1,   45,  259,   47,   41,   42,   43,
  263,   45,   -1,   47,   42,   43,   -1,   -1,   59,  273,
  274,   -1,  219,   -1,  221,   59,  280,   -1,  282,  283,
  284,  285,  286,  287,  231,   -1,   -1,   -1,  292,   41,
   42,   43,   44,   45,   46,   47,   74,   75,   76,   77,
  247,  174,  175,  176,  177,  178,  179,   59,   60,   61,
   62,   41,   42,   43,   44,   45,  263,   47,   41,   42,
   43,   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   59,   60,   -1,   62,
   41,   42,   43,   44,   45,   -1,   47,   41,   42,   43,
   -1,   45,   -1,   47,   -1,  133,   -1,   -1,   59,   60,
   41,   62,   43,   44,   45,   59,   60,   -1,   62,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   59,   60,
   -1,   62,   -1,   -1,   -1,   -1,   -1,   59,   60,   11,
   62,   -1,   -1,  171,  172,   -1,  174,  175,  176,  177,
  178,  179,   -1,  181,  262,  263,  264,  265,  266,  267,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   42,   43,   -1,   41,   42,   43,   -1,   45,   59,   47,
   -1,   -1,   54,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   59,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   59,   41,   42,   43,   44,   45,   79,   47,   -1,
   82,   -1,   -1,   -1,   86,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,  266,  267,   -1,  269,  270,  141,
  142,  143,  144,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,  262,
  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,  171,
  172,   -1,  174,  175,  176,  177,  178,  179,  129,  181,
   -1,  262,  263,  264,  265,  266,  267,   -1,  262,  263,
  264,  265,  266,  267,   -1,  146,   -1,   -1,   -1,   -1,
   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,  160,
  262,  263,  264,  265,  266,  267,   -1,   -1,   -1,  170,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  194,  195,  196,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  219,   -1,
  221,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  231,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  247,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  263,
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
#line 384 "a.y"


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
#line 702 "y.tab.c"

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
#line 109 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 22:
#line 110 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 23:
#line 115 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 24:
#line 116 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 25:
#line 117 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 26:
#line 118 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 27:
#line 123 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 28:
#line 124 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 29:
#line 125 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 30:
#line 126 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 31:
#line 131 "a.y"
	{  yyval.node = NULL; }
break;
case 32:
#line 132 "a.y"
	{ yyval.node = NULL; }
break;
case 33:
#line 133 "a.y"
	{ yyval.node = NULL; }
break;
case 34:
#line 138 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 35:
#line 142 "a.y"
	{ yyval.params = NULL; }
break;
case 36:
#line 143 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 37:
#line 147 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 38:
#line 148 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 39:
#line 149 "a.y"
	{ yyval.params = NULL; }
break;
case 40:
#line 153 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 41:
#line 154 "a.y"
	{ yyval.node = NULL; }
break;
case 42:
#line 159 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 43:
#line 160 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 44:
#line 165 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 45:
#line 166 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 171 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 47:
#line 172 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 48:
#line 173 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 49:
#line 177 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 50:
#line 178 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 51:
#line 182 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 52:
#line 183 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 53:
#line 187 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 54:
#line 188 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 55:
#line 193 "a.y"
	{ yyval.node = NULL ; }
break;
case 56:
#line 194 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 195 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 196 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 201 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 202 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 203 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 62:
#line 204 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 205 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 206 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 207 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 212 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 67:
#line 213 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 68:
#line 217 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 69:
#line 218 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 70:
#line 219 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 71:
#line 224 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 72:
#line 225 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 229 "a.y"
	{ yyval.args = NULL; }
break;
case 74:
#line 230 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 75:
#line 234 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 76:
#line 235 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 77:
#line 239 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 78:
#line 240 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 241 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 243 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 244 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 245 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 84:
#line 249 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 85:
#line 250 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 86:
#line 256 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 257 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 89:
#line 268 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 90:
#line 269 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 91:
#line 270 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 92:
#line 271 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 93:
#line 276 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 94:
#line 277 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 95:
#line 278 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 96:
#line 279 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 97:
#line 284 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 98:
#line 288 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 99:
#line 292 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 100:
#line 296 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 101:
#line 300 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 102:
#line 304 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 103:
#line 308 "a.y"
	{ yyval.node = xnull();}
break;
case 104:
#line 313 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 105:
#line 314 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 106:
#line 319 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 107:
#line 320 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 108:
#line 321 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 109:
#line 322 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 110:
#line 323 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 111:
#line 324 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 112:
#line 325 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 113:
#line 326 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 327 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 115:
#line 332 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 116:
#line 333 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 117:
#line 334 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 118:
#line 335 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 119:
#line 340 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 120:
#line 341 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 342 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 343 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 123:
#line 344 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 124:
#line 345 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 125:
#line 346 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 347 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 348 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 349 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 350 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 351 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 131:
#line 356 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 132:
#line 357 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 133:
#line 358 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 359 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 135:
#line 360 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 136:
#line 365 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 137:
#line 366 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 138:
#line 370 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 139:
#line 371 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 140:
#line 376 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 141:
#line 377 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 142:
#line 378 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 143:
#line 379 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 144:
#line 380 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 145:
#line 381 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1480 "y.tab.c"
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
