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
   27,   28,   29,   30,   41,   23,   23,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   15,   15,   15,   15,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   20,   20,   20,   20,   20,   22,   22,   38,
   38,   13,   13,   13,   13,   13,   13,
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
    1,    1,    2,    1,    1,    1,    1,    1,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    3,    3,
    3,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   70,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   46,   47,   61,   62,  142,   64,   65,    0,   10,    0,
  143,    0,    0,   67,    0,    0,    0,    0,    0,  101,
   69,    0,    0,    0,    0,    0,  102,    0,  104,    0,
    0,    0,  105,    0,    0,    0,    0,    0,   95,   72,
  129,    0,  123,    0,    0,    0,    0,    0,  131,  132,
    0,  100,    0,    7,    0,    0,    0,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    0,  137,    0,   77,    0,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  135,
    0,    0,    0,  133,  134,   96,    0,   59,    0,   58,
   60,    0,   63,    0,  117,  118,    0,    0,  103,   89,
   88,    0,  119,  120,    0,    0,    0,    0,    0,    0,
    0,  144,  145,  146,  147,   45,    0,  138,  139,    0,
    0,  140,    0,    0,    0,  141,   39,    0,   43,    0,
    0,    0,   11,   19,   17,    0,    0,    0,   15,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   98,    0,   97,    0,    0,   93,
   94,    0,    0,    0,    0,    0,    0,    0,   38,    0,
    0,    0,   78,   18,   12,   16,    0,  115,  116,   43,
   87,    0,  111,  112,  113,  114,  109,  110,   55,    0,
    0,    0,   90,    0,    0,   99,    0,    0,    0,   35,
   40,   36,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,    0,   31,   32,    0,    0,
   86,   49,    0,   22,   29,    0,   43,   50,   52,    0,
   33,    0,    0,   43,    0,    0,   30,   56,    0,    0,
   34,
};
static const short yydgoto[] = {                          1,
  211,   16,   17,   18,   19,   20,  200,   21,   22,  108,
  212,  119,   23,   91,   92,  110,   94,  129,  130,   59,
   60,   25,  112,   26,   27,  113,   96,  114,  115,  116,
   67,  244,  245,   29,  168,  169,  100,   31,   32,   33,
   69,   34,   70,   35,   89,  158,  101,  102,   39,    2,
};
static const short yysindex[] = {                         0,
    0,  321,  -37, -235,   -9,  -10,   24,   30, -203,    0,
   47,   32, -159,    0,    0,    0,    0,   70,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   71,    0,   52,
    0,   95, -116,    0,  100,  116,  -85,  188,   54,    0,
    0,  -80,  122,  122, -151,  121,    0,  143,    0, -159,
 -159,  139,    0,  -33,  122,    0,    0,    0,    0,    0,
    0,  -40,    0,    0,    0,    0,  342,  145,    0,    0,
 -159,    0,  155,    0,  -43,  -43,  -43,  -43, -159,   47,
    0, -159,   47, -159, -159,  161,   47,  -55,   82,    0,
    0,    0,    0,    0,  -40,    0,    0,    0,    0,  145,
  172,  171, -111,  179,  193,  145,   95,   18,    0,    0,
    0,  103,  -40,    0,    0,    0,   33,    0,  175,    0,
    0,  -26,    0,  188,    0,    0, -159,  -43,    0,    0,
    0,  200,    0,    0, -159,  122,  122,  122,  122,  201,
  188,    0,    0,    0,    0,    0,   83,    0,    0,  -15,
  225,    0,  226,  229,  188,    0,    0,   45,    0,  -42,
  188,   35,    0,    0,    0,  219,  -17, -109,    0,  188,
  122,  122,  243,  122,  122,  122,  122,  122,  122,  243,
  122,  251,  258,  260,    0,  269,    0,   26,   26,    0,
    0,  177,  271,  188,  188,  188,  273,   56,    0,  151,
  282, -159,    0,    0,    0,    0,  284,    0,    0,    0,
    0,   49,    0,    0,    0,    0,    0,    0,    0,  -51,
  289,  188,    0,  188, -184,    0,  296,  303,  304,    0,
    0,    0,    0,  188,  311,  289,  305,  243, -151,  312,
  317,  104,  307, -103,    0,  112,    0,    0,  322,  188,
    0,    0,  332,    0,    0,  316,    0,    0,    0,  337,
    0,  345,  243,    0,  321,  188,    0,    0,  321,  349,
    0,
};
static const short yyrindex[] = {                         0,
    0,  394,  -20,  338,    0,    0,    0,    0,    0,    0,
  339,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  428,  346,    0,    0,  285,    0,  368,    0,    0,
    0,    0,    0,    0,  352,    0,    0,  513,    0,    0,
    0,   16,    0,    0,    0,   20,  492,  662,    0,    0,
    0,  669,    0,  682,  701,  712,    0,   17,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   94,    0,    0,
  374,    0,  636,    0,  764,    0,  772,  850,  857,    0,
    0,  371,    0,   50,  361,  362,    0,    0,  581,    0,
  603,   61,  503,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  368,    0,    0,    0,    0,    0,    0,
    0,  465,    0,    0,    0,    0,    0,    0,    0,    0,
  368,    0,    0,    0,    0,    0,    0,    0,    0,  669,
   85,    0,  111,  114,  368,    0,    0,    0,    0,  367,
    0,  334,    0,    0,    0,    0,    0,    0,    0,  368,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   25,    0,    0,  123,    0,  594,  614,    0,
    0,    0,    0,  368,  368,  368,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
  574,  368,    0,  368,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  368,  295,    0,    0,    0,  387,    0,
    0,    0,    0,    0,    0,   88,    0,    0,    0,  368,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -100,  368,    0,    0,  -93,    0,
    0,
};
static const short yygindex[] = {                         0,
    3,    0,    0,    0,  -69,  -32, -106,    0,    0,  -27,
 -126,  192,  -16,  653,   10,  138,  279,    0,    0,  623,
  119,  -52,  510,    0,   27,   -2,   41,  259,  272,  319,
  313,    0,  197,    0,    0,  288,    8,    0,  -30,    0,
    0,    0,    0,    0,    0,    0,  694,    0,    0,    0,
};
#define YYTABLESIZE 960
static const short yytable[] = {                         28,
   48,   54,   38,  202,   15,  135,  128,  239,   62,   30,
   73,  107,  118,  163,  107,  205,  117,   79,   68,  135,
   57,  258,   40,  100,   54,  100,   79,  149,  120,   43,
  135,   53,   81,  164,   80,   95,   42,   61,  100,  105,
  100,   81,  122,   80,   41,   80,  146,  125,  126,  106,
  166,   63,   30,  219,  121,   46,   20,  130,  173,   48,
  124,   97,   97,   44,   97,   21,   97,  138,  140,   45,
  165,   71,  139,  180,   20,  130,  147,  150,  124,  151,
   62,  153,  154,   21,   62,  199,   55,   68,  198,   57,
   68,   54,   57,  100,   68,  100,   57,   84,  164,   72,
  167,  108,   13,  237,  242,  243,   61,  104,  100,   61,
  100,  252,   83,   61,   79,  166,   82,   50,   51,  108,
   63,   95,    5,   63,  183,   48,   79,   63,   74,   81,
   25,   80,  186,   29,   41,  165,  268,   41,   95,   24,
   85,   81,   86,  208,  209,   25,   29,  162,   58,  162,
  265,   28,   95,  220,   26,   88,   28,  269,   95,   26,
   87,   55,  179,   25,  178,  167,   54,   95,   25,   28,
   28,   28,   26,   90,   26,   93,  103,   28,  104,  123,
   30,   25,  124,   25,  127,  242,  243,   30,   54,   54,
   84,   95,   95,   95,  141,   53,   53,   28,  148,  235,
  155,  152,  233,  157,  159,  156,  118,   30,  107,   14,
  171,  172,  160,   47,  161,   48,  201,   58,  170,   95,
   58,   95,  120,   47,   58,   50,   51,   55,  133,  134,
   36,   95,   54,  181,   28,   28,  122,   37,  135,  233,
  185,  192,  133,  134,   30,   30,   30,   95,  121,   75,
   76,   77,   78,  133,  134,  100,  100,  100,  100,   48,
   28,   93,   28,   95,  194,  195,   28,  233,  196,   64,
   30,  233,   30,   48,   48,  232,   30,  204,   93,  171,
  172,   48,   65,   48,   48,   48,   48,   48,   48,   48,
   48,  221,   93,   48,  171,  172,   97,  222,   93,  225,
  223,   14,   36,   47,   40,   48,   49,   93,  224,   98,
   24,  226,  131,  230,  231,   50,   51,   24,  100,  100,
   52,  234,  108,  108,  236,  100,  100,  100,  100,   66,
  238,   93,   93,   93,  202,   27,  246,   24,   64,   13,
   27,   64,   53,  247,  248,   64,   75,   76,   77,   78,
  250,   65,  254,   27,   65,   27,   99,  255,   65,   93,
   47,   93,  261,   14,  257,  210,  174,  175,  176,  177,
  260,   93,  263,  264,   24,   24,  266,  100,   47,   14,
   48,   49,   97,  138,  136,  267,  137,   93,  139,  271,
   50,   51,  100,    1,  100,   98,   68,   71,   66,   97,
   24,   66,   24,   93,   66,   66,   24,   37,   75,    3,
   57,   76,   98,   97,   85,   97,   97,   85,   97,   97,
   97,   23,   24,    4,    5,   73,   98,   57,   97,  251,
  253,    6,   98,    7,    8,    9,   10,   11,   12,  203,
  259,   98,   99,   13,   47,   40,   48,   49,  188,  189,
  190,  191,   97,   97,   97,  206,   50,   51,    0,   99,
    0,    0,    0,    0,    0,   98,   98,   98,   74,   74,
   74,   74,   74,   99,   74,    0,    0,    0,    0,   99,
   97,    0,   97,    0,    0,    0,   74,   74,   99,   74,
    0,    0,   97,   98,    0,   98,    0,    0,    0,    0,
  256,    3,    0,    0,    0,   98,   97,   97,   97,   97,
    0,   97,   99,   99,   99,    4,    5,    0,    0,    0,
    0,   98,    0,    6,   97,    7,    8,    9,   10,   11,
   12,    0,  128,  137,  137,   13,  137,   98,  137,    0,
   99,    0,   99,  136,  136,  136,  136,  136,    0,  136,
  128,    0,   99,  100,  100,  100,  100,  100,  100,  100,
    0,  136,  136,    3,  136,    0,    0,    0,   99,    0,
    0,  100,  100,  100,  100,    0,    0,    4,    5,    3,
    0,    0,    0,    0,   99,    6,    0,    7,    8,    9,
   10,   11,   12,    4,    5,    0,    0,   13,    0,    0,
    0,    6,    0,    7,    8,    9,   10,   11,   12,    0,
    0,    0,    0,   13,   73,   73,   73,   73,   73,    0,
   73,  107,   97,   97,    0,   97,    0,   97,    0,    0,
    0,    0,   73,   73,   91,   73,   91,   91,   91,  107,
  107,    0,  107,  106,   95,   95,    0,   95,    0,   95,
    0,    0,   91,   91,   92,   91,   92,   92,   92,    0,
    0,  106,  106,   56,  106,  111,  111,    0,    0,    0,
    0,    0,   92,   92,    0,   92,   84,  135,  135,   84,
  135,    0,  135,  213,  214,  215,  216,  217,  218,   74,
   74,   74,   74,   74,   74,  109,  109,  142,  143,  144,
  145,    0,  125,  135,  135,    0,  135,  132,  135,  126,
  136,  136,    0,  136,    0,  136,    0,    0,    0,    0,
  125,    0,  121,  133,  133,    0,  133,  126,  133,    0,
    0,    0,   56,    0,    0,   56,    0,    0,    0,   56,
  121,  122,  134,  134,    0,  134,    0,  134,    0,    0,
  184,    0,  127,   96,   96,    0,   96,    0,   96,  122,
    0,    0,    0,    0,  136,  136,  136,  136,  136,  136,
  127,    0,    0,    0,  100,  100,  100,  100,  100,  100,
    0,  100,  100,    0,    0,    0,    0,    0,  187,  187,
  187,  187,    0,  111,  111,    0,  111,  111,  111,  111,
  111,  111,    0,  111,   81,  136,  136,   81,  136,    0,
  136,    0,   80,  133,  133,   80,  133,  182,  133,    0,
    0,    0,    0,  109,  109,    0,  109,  109,  109,  109,
  109,  109,    0,  109,  193,   73,   73,   73,   73,   73,
   73,    0,  107,  107,  107,  107,  107,  107,  197,    0,
    0,    0,    0,    0,    0,   91,   91,   91,   91,   91,
   91,    0,    0,  207,  106,  106,  106,  106,  106,  106,
    0,    0,    0,    0,    0,   92,   92,   92,   92,   92,
   92,    0,    0,    0,    0,    0,    0,  227,  228,  229,
   83,  134,  134,   83,  134,    0,  134,   82,   96,   96,
   82,   96,    0,   96,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  240,    0,  241,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  249,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  262,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  270,
};
static const short yycheck[] = {                          2,
    0,   45,   40,   46,    2,   46,   40,   59,   11,    2,
   13,   42,   45,  125,   45,  125,   44,   44,   11,   46,
   11,  125,  258,   44,  125,   46,   44,   80,   45,   40,
   46,  125,   59,  103,   61,   38,   46,   11,   59,   42,
   61,   59,   45,   61,    4,   61,   79,   50,   51,   42,
  103,   11,   45,  180,   45,  259,   41,   41,   41,   59,
   41,   42,   43,   40,   45,   41,   47,   42,   71,   40,
  103,   40,   47,   41,   59,   59,   79,   80,   59,   82,
   83,   84,   85,   59,   87,   41,   40,   80,   44,   80,
   83,   45,   83,   44,   87,   46,   87,   46,  168,  259,
  103,   41,  123,  210,  289,  290,   80,  259,   59,   83,
   61,  238,   61,   87,   44,  168,   46,  269,  270,   59,
   80,  124,  274,   83,  127,  125,   44,   87,   59,   59,
   46,   61,  135,   46,   41,  168,  263,   44,  141,    2,
   46,   59,  259,  171,  172,   61,   59,  259,   11,  259,
  257,   41,  155,  181,   41,   40,   46,  264,  161,   46,
   61,   40,   60,   41,   62,  168,   45,  170,   46,   59,
  173,   61,   59,  259,   61,   38,  123,  180,  259,   59,
  173,   59,   40,   61,   46,  289,  290,  180,  289,  290,
   46,  194,  195,  196,   40,  289,  290,  200,   80,  202,
   40,   83,  200,  259,  123,   87,  239,  200,  239,   59,
  262,  263,   41,  257,   44,  259,  259,   80,   40,  222,
   83,  224,  239,  257,   87,  269,  270,   40,  269,  270,
  268,  234,   45,   59,  237,  238,  239,  275,   46,  237,
   41,   41,  269,  270,  237,  238,  239,  250,  239,  276,
  277,  278,  279,  269,  270,  276,  277,  278,  279,  259,
  263,  124,  265,  266,   40,   40,  269,  265,   40,   11,
  263,  269,  265,  273,  274,  125,  269,   59,  141,  262,
  263,  281,   11,  283,  284,  285,  286,  287,  288,  289,
  290,   41,  155,  293,  262,  263,   38,   40,  161,  123,
   41,   59,  268,  257,  258,  259,  260,  170,   40,   38,
  173,   41,   54,   41,  259,  269,  270,  180,  269,  270,
  274,   40,  262,  263,   41,  276,  277,  278,  279,   11,
  282,  194,  195,  196,   46,   41,   41,  200,   80,  293,
   46,   83,  296,   41,   41,   87,  276,  277,  278,  279,
   40,   80,   41,   59,   83,   61,   38,   41,   87,  222,
  257,  224,   41,   59,   58,  123,  264,  265,  266,  267,
  259,  234,   41,   58,  237,  238,   40,   44,  257,   59,
  259,  260,  124,   42,   43,   41,   45,  250,   47,   41,
  269,  270,   59,    0,   61,  124,   59,   59,   80,  141,
  263,   83,  265,  266,   59,   87,  269,  123,   41,  259,
   59,   41,  141,  155,   41,   42,   43,   44,   45,  161,
   47,   61,   61,  273,  274,   59,  155,   41,  170,  125,
  239,  281,  161,  283,  284,  285,  286,  287,  288,  161,
  244,  170,  124,  293,  257,  258,  259,  260,  136,  137,
  138,  139,  194,  195,  196,  168,  269,  270,   -1,  141,
   -1,   -1,   -1,   -1,   -1,  194,  195,  196,   41,   42,
   43,   44,   45,  155,   47,   -1,   -1,   -1,   -1,  161,
  222,   -1,  224,   -1,   -1,   -1,   59,   60,  170,   62,
   -1,   -1,  234,  222,   -1,  224,   -1,   -1,   -1,   -1,
  242,  259,   -1,   -1,   -1,  234,   42,   43,  250,   45,
   -1,   47,  194,  195,  196,  273,  274,   -1,   -1,   -1,
   -1,  250,   -1,  281,  266,  283,  284,  285,  286,  287,
  288,   -1,   41,   42,   43,  293,   45,  266,   47,   -1,
  222,   -1,  224,   41,   42,   43,   44,   45,   -1,   47,
   59,   -1,  234,   41,   42,   43,   44,   45,   46,   47,
   -1,   59,   60,  259,   62,   -1,   -1,   -1,  250,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,  273,  274,  259,
   -1,   -1,   -1,   -1,  266,  281,   -1,  283,  284,  285,
  286,  287,  288,  273,  274,   -1,   -1,  293,   -1,   -1,
   -1,  281,   -1,  283,  284,  285,  286,  287,  288,   -1,
   -1,   -1,   -1,  293,   41,   42,   43,   44,   45,   -1,
   47,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   59,   60,   41,   62,   43,   44,   45,   59,
   60,   -1,   62,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   59,   60,   41,   62,   43,   44,   45,   -1,
   -1,   59,   60,   11,   62,   43,   44,   -1,   -1,   -1,
   -1,   -1,   59,   60,   -1,   62,   41,   42,   43,   44,
   45,   -1,   47,  174,  175,  176,  177,  178,  179,  262,
  263,  264,  265,  266,  267,   43,   44,   75,   76,   77,
   78,   -1,   41,   42,   43,   -1,   45,   55,   47,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   59,   -1,   41,   42,   43,   -1,   45,   59,   47,   -1,
   -1,   -1,   80,   -1,   -1,   83,   -1,   -1,   -1,   87,
   59,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
  128,   -1,   41,   42,   43,   -1,   45,   -1,   47,   59,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
   59,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
   -1,  269,  270,   -1,   -1,   -1,   -1,   -1,  136,  137,
  138,  139,   -1,  171,  172,   -1,  174,  175,  176,  177,
  178,  179,   -1,  181,   41,   42,   43,   44,   45,   -1,
   47,   -1,   41,   42,   43,   44,   45,  124,   47,   -1,
   -1,   -1,   -1,  171,  172,   -1,  174,  175,  176,  177,
  178,  179,   -1,  181,  141,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  264,  265,  266,  267,  155,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,  170,  262,  263,  264,  265,  266,  267,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,   -1,   -1,   -1,  194,  195,  196,
   41,   42,   43,   44,   45,   -1,   47,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  222,   -1,  224,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  234,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  250,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  266,
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
#line 394 "a.y"


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
#line 700 "y.tab.c"

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
#line 329 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 109:
#line 330 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 110:
#line 331 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 111:
#line 332 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 112:
#line 333 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 113:
#line 334 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 335 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 115:
#line 336 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 116:
#line 337 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 117:
#line 342 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 118:
#line 343 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 119:
#line 344 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 120:
#line 345 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 121:
#line 350 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 351 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
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
#line 366 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 367 "a.y"
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
#line 375 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 139:
#line 376 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 140:
#line 380 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 141:
#line 381 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 142:
#line 386 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 143:
#line 387 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 144:
#line 388 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 145:
#line 389 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 146:
#line 390 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 147:
#line 391 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1486 "y.tab.c"
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
