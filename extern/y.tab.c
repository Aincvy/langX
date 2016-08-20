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
    0,   47,   47,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   35,   35,   37,   37,   37,   37,   39,   39,
   39,   39,   40,   40,   40,   36,   36,   36,    5,   43,
   43,   44,   44,   44,    7,    7,    6,    6,    3,    3,
    8,    8,    8,   32,   32,   33,   33,    9,    9,   12,
   12,   12,   12,    4,    4,    4,    4,    4,    4,    4,
   42,   42,   24,   24,   24,   16,   16,   45,   45,   46,
   46,   17,   17,   17,   17,   17,   17,   17,   11,   11,
   18,   18,   19,   14,   14,   14,   14,   31,   31,   31,
   31,   25,   26,   27,   28,   29,   30,   41,   23,   23,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   15,
   15,   15,   15,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   20,   20,   20,   20,   20,   22,
   22,   38,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    1,    2,    3,    3,    6,    3,    6,    9,
    6,    6,    8,   10,    5,    1,    2,    1,    6,    0,
    3,    1,    3,    0,    2,    0,    2,    3,    1,    1,
    5,    7,    7,    1,    2,    4,    3,    5,    9,    0,
    1,    1,    1,    1,    1,    3,    1,    1,    1,    1,
    1,    2,    1,    1,    2,    4,    1,    0,    1,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    3,    1,
    1,    1,    3,    3,    3,    3,    3,    1,    1,    1,
    3,    5,    1,    1,    1,    2,    1,    1,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    2,    2,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    3,    3,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,   63,    0,
    0,    0,    4,    2,    5,    6,    0,    8,    9,   39,
   40,   54,   55,  133,   57,   58,    0,   10,    0,  134,
    0,    0,   60,    0,    0,    0,   94,   62,    0,    0,
    0,    0,   95,    0,   97,    0,    0,   98,    0,    0,
    0,    0,    0,   88,   65,  122,    0,  116,    0,    0,
    0,    0,    0,  124,    0,   93,    0,    7,    0,    0,
    0,    0,    0,    0,   37,    0,    0,    0,    0,    0,
    0,    0,    0,   11,   28,   26,    0,    0,    0,   13,
    0,  129,    0,   70,    0,   72,    0,    0,    0,    0,
    0,    0,    0,    0,  127,    0,    0,    0,  125,  126,
   89,    0,    0,   52,    0,   51,   53,    0,    0,   56,
    0,  110,  111,    0,   96,   82,   81,    0,  112,  113,
    0,    0,    0,    0,    0,    0,    0,  135,  136,  137,
  138,   38,    0,  130,  131,    0,    0,  132,    0,    0,
    0,   32,    0,   36,   27,   12,   14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   91,    0,   90,    0,    0,   86,   87,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
    0,   71,  108,  109,   36,   80,    0,  104,  105,  106,
  107,  102,  103,   48,    0,    0,    0,   83,    0,    0,
   92,    0,    0,    0,   25,   33,   29,   35,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   44,    0,
   21,   22,    0,    0,   79,   42,    0,   19,    0,   36,
   43,   45,    0,   23,    0,    0,   36,    0,    0,   20,
   49,    0,    0,   24,
};
static const short yydgoto[] = {                          1,
  196,   15,   16,   17,   18,   19,  189,   20,   21,  103,
  197,  115,   22,   91,   92,  105,   94,  125,  126,   54,
   55,   24,  107,   25,   26,  108,   96,  109,  110,  111,
   62,  228,  229,   28,   89,   90,  100,   30,   31,   32,
   64,   33,   82,  153,  101,  102,    2,
};
static const short yysindex[] = {                         0,
    0,  263,  -34, -233,   22,   23,   24, -189,    0,  -40,
   32, -176,    0,    0,    0,    0,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,    0,  -19,    0,
   44, -149,    0,   71, -118,   92,    0,    0,  114,  114,
 -101,   61,    0,   82,    0, -176, -176,    0,  -32,  114,
    0,    0,    0,    0,    0,    0,  -24,    0,    0,    0,
    0,  487,   78,    0, -176,    0,   94,    0,  130,  130,
  130,  130, -176,  -40,    0, -176,  -40, -176, -176,   96,
 -121,   40, -103,    0,    0,    0,  107,   48, -108,    0,
    0,    0,    0,    0,  -24,    0,    0,    0,    0,   78,
  126,  132,   16,    0,    0,    0,  303,  -24,    0,    0,
    0,   46,  139,    0,  125,    0,    0,   42,   44,    0,
   92,    0,    0,  130,    0,    0,    0,  149,    0,    0,
 -176,  114,  114,  114,  114,  151,   92,    0,    0,    0,
    0,    0,   69,    0,    0,    7,  156,    0,  161,  165,
   92,    0,  -18,    0,    0,    0,    0,  -37,   92,  114,
  114,  180,  114,  114,  114,  114,  114,  114,  180,   92,
  114,  172,  174,    0,  187,    0,   14,   14,    0,    0,
  112,  202,   92,   92,   92,  206,   -3,    0,  223,  226,
 -176,    0,    0,    0,    0,    0,  -12,    0,    0,    0,
    0,    0,    0,    0,  232,  -56,  246,    0,   92, -257,
    0,  253,  260,  261,    0,    0,    0,    0,   92,  267,
  241,  180,  246, -101,  269,   57,  257, -115,    0,   65,
    0,    0,  287,   92,    0,    0,  288,    0,  281,    0,
    0,    0,  301,    0,  306,  180,    0,  263,   92,    0,
    0,  263,  312,    0,
};
static const short yyrindex[] = {                         0,
    0,  354,   68,  297,    0,    0,    0,    0,    0,  298,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  433,  300,    0,  244,    0,  323,    0,    0,    0,    0,
  309,    0,    0,  372,    0,    0,    0,    0,    0,    0,
  530,  543,  563,    0,    0,    0,  570,    0,  618,  685,
  749,    0,    6,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  102,    0,  153,    0,    0,    0,    0,    0,    0,    0,
  637,    0,  692,    0,  724,    0,  756,  773,  783,    0,
    0,  328,    0,  409,    0,  519,   -1,  442,    0,    0,
    0,    0,   56,    0,    0,    0,    0,    0,    0,    0,
  323,    0,    0,    0,    0,    0,    0,  576,    0,    0,
    0,    0,    0,    0,    0,    0,  323,    0,    0,    0,
    0,    0,    0,    0,    0,  570,  -10,    0,   -7,   89,
  323,    0,    0,    0,    0,    0,    0,  322,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  323,
    0,    0,    0,    0,  101,    0,  334,  384,    0,    0,
    0,    0,  323,  323,  323,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  497,    0,  323,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  323,  351,
    0,    0,    0,  341,    0,    0,    0,    0,    0,  -31,
    0,    0,    0,  323,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -106,  323,    0,
    0,  -79,    0,    0,
};
static const short yygindex[] = {                         0,
   11,    0,    0,    0,   10,    9, -122,    0,    0,  -16,
 -151,  162,  -30,  553,   -8,   19,  229,    0,    0,  586,
  103,  -15,  526,    0,   20,    2,   31,  221,  121,  239,
  385,    0,  157,    0,    0,  313,   75,    0,  -25,    0,
    0,    0,    0,    0,  604,    0,    0,
};
#define YYTABLESIZE 853
static const short yytable[] = {                         50,
   41,   52,  224,   27,   49,   36,   84,  124,  191,  241,
  116,   57,   14,   67,   19,  119,  156,  204,   47,   87,
   23,  131,  188,  112,   37,  187,   78,   19,   53,   56,
  226,  227,  117,   18,   38,   15,   88,   95,   18,  101,
   58,   77,  118,   86,   85,   46,  123,  122,  123,  114,
   15,   18,  131,   18,   93,  134,  162,  101,  145,   41,
  135,   39,   40,   41,  123,   52,  136,   74,   52,   42,
  236,   65,  221,   87,  143,  146,   29,  147,   57,  149,
  150,  142,   66,   68,   63,   73,  169,  131,   35,   79,
   88,   73,   53,   56,  251,   53,   56,   86,   85,   93,
   75,   93,   74,   73,   58,   76,   75,   58,   74,   80,
   81,   93,   73,   93,   93,   29,   93,  248,   75,  120,
   74,  121,   95,   78,  252,   41,   93,   75,   93,   16,
   60,   50,  175,  137,   16,  151,   49,  152,   95,   93,
   83,   15,   34,  193,  194,   34,   15,   16,   63,   16,
   83,   63,   95,   50,  206,   93,   98,  113,   49,   15,
   95,   15,  154,   27,   34,  155,  158,   46,   47,   93,
   27,   95,  226,  227,   49,  159,  144,   93,  170,  148,
   23,   47,   47,  171,   95,   95,   95,   23,   93,  174,
   27,  181,  220,  116,   60,  183,   93,   60,  119,  218,
  184,   93,   93,   93,  185,  160,  161,   23,   46,   46,
   95,   93,  207,   93,  208,  117,   43,   37,   44,   45,
   95,  190,   27,   27,   43,  118,  209,   93,   46,   47,
   59,  218,  114,   34,  210,   95,   29,   93,   13,   23,
   23,   98,  211,   29,  129,  130,  215,   27,   61,   27,
   95,   12,   93,   27,   48,  216,   97,   98,  218,   41,
  101,  101,  218,   29,   23,  219,   23,   93,  222,  127,
   23,   98,  223,   41,   99,  129,  130,  160,  161,   98,
   41,   13,   41,   41,   41,   41,   41,   41,   41,   41,
   98,  191,   41,  230,   59,   29,   29,   59,   29,   13,
  231,  232,  195,   98,   98,   98,  234,  160,  161,  238,
  129,  130,   61,   43,  240,   61,   69,   70,   71,   72,
   29,   13,   29,  243,   93,   93,   29,  244,  246,   98,
   93,   93,   93,   93,   69,   70,   71,   72,  247,   98,
  249,   97,   93,   93,   93,   93,  250,  217,   43,   37,
   44,   45,  254,    1,   98,   61,   64,   97,   59,   99,
   46,   47,  168,   68,  167,  235,   30,   50,   69,   98,
   43,   97,   44,   45,   84,   99,   84,   84,   84,   97,
   66,   50,   46,   47,  242,  237,   43,  192,   44,   99,
   97,   17,   84,   84,    0,   84,   17,   99,   46,   47,
    0,  157,    0,   97,   97,   97,    0,    0,   99,   17,
    0,   17,   93,   93,   93,   93,   93,   93,   93,    0,
    0,   99,   99,   99,   85,    0,   85,   85,   85,   97,
   93,   93,   93,   93,    0,    0,    0,    0,    3,   97,
    0,    0,   85,   85,    0,   85,  239,   99,    0,  100,
   90,   90,    4,   90,   97,   90,    0,   99,    0,    5,
    0,    6,    7,    8,    9,   10,   11,  100,  100,   97,
  100,   12,   99,   67,   67,   67,   67,   67,    0,   67,
    0,    3,  128,  128,  128,  128,  128,   99,  128,    0,
    0,   67,   67,    0,   67,    4,    0,    0,    0,    3,
  128,  128,    5,  128,    6,    7,    8,    9,   10,   11,
    0,    0,    0,    4,   12,    0,  177,  178,  179,  180,
    5,    3,    6,    7,    8,    9,   10,   11,  134,  132,
    0,  133,   12,  135,    0,    4,    0,   66,   66,   66,
   66,   66,    5,   66,    6,    7,    8,    9,   10,   11,
    0,    0,    0,    0,   12,   66,   66,    0,   66,   99,
   88,   88,   51,   88,    0,   88,  163,  164,  165,  166,
  117,   90,   90,    0,   90,    0,   90,   99,   99,    0,
   99,    0,    0,  121,  129,  129,    0,  129,  117,  129,
    0,  104,  104,    0,    0,   84,   84,   84,   84,   84,
   84,  121,  128,  118,  127,  127,    0,  127,    0,  127,
  119,  128,  128,    0,  128,    0,  128,   90,   90,    0,
   90,  118,   90,    0,  106,  106,   51,    0,  119,   51,
    0,    0,    0,   93,   93,   93,   93,   93,   93,    0,
   93,   93,    0,    0,    0,   85,   85,   85,   85,   85,
   85,    0,    0,    0,  138,  139,  140,  141,  114,  125,
  125,    0,  125,    0,  125,    0,    0,    0,    0,    0,
  100,  100,  100,  100,  100,  100,  114,   78,   90,   90,
   78,   90,    0,   90,  176,  176,  176,  176,  198,  199,
  200,  201,  202,  203,   67,   67,   67,   67,   67,   67,
    0,    0,    0,  128,  128,  128,  128,  128,  128,  173,
    0,    0,  104,  104,    0,  104,  104,  104,  104,  104,
  104,    0,    0,  104,  172,  115,  126,  126,    0,  126,
    0,  126,   77,  127,  127,   77,  127,    0,  127,    0,
  182,    0,    0,  115,    0,  106,  106,    0,  106,  106,
  106,  106,  106,  106,  186,    0,  106,    0,   66,   66,
   66,   66,   66,   66,   74,  128,  128,   74,  128,    0,
  128,    0,    0,  205,    0,    0,    0,    0,    0,    0,
   99,   99,   99,   99,   99,   99,  212,  213,  214,  120,
   89,   89,    0,   89,    0,   89,   73,  125,  125,   73,
  125,    0,  125,    0,    0,    0,    0,  120,    0,    0,
    0,    0,  225,   76,  126,  126,   76,  126,    0,  126,
    0,    0,  233,   75,   89,   89,   75,   89,    0,   89,
    0,    0,    0,    0,    0,    0,    0,  245,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  253,
};
static const short yycheck[] = {                         40,
    0,   10,   59,    2,   45,   40,  125,   40,   46,  125,
   41,   10,    2,   12,   46,   41,  125,  169,  125,   35,
    2,   46,   41,   40,  258,   44,   46,   59,   10,   10,
  288,  289,   41,   41,    4,   46,   35,   36,   46,   41,
   10,   61,   41,   35,   35,  125,   41,   46,   47,   41,
   61,   59,   46,   61,   36,   42,   41,   59,   74,   59,
   47,   40,   40,   40,   59,   74,   65,   61,   77,  259,
  222,   40,  195,   89,   73,   74,    2,   76,   77,   78,
   79,   73,  259,   59,   10,   44,   41,   46,  123,   46,
   89,   44,   74,   74,  246,   77,   77,   89,   89,   44,
   59,   46,   61,   44,   74,   46,   59,   77,   61,  259,
   40,   44,   44,   46,   59,   41,   61,  240,   59,   59,
   61,   40,  121,   46,  247,  125,   59,   59,   61,   41,
   10,   40,  131,   40,   46,   40,   45,  259,  137,  121,
  259,   41,   41,  160,  161,   44,   46,   59,   74,   61,
  259,   77,  151,   40,  171,  137,   36,  259,   45,   59,
  159,   61,  123,  162,  268,   59,   41,  269,  270,  151,
  169,  170,  288,  289,   45,   44,   74,  159,   40,   77,
  162,  288,  289,   59,  183,  184,  185,  169,  170,   41,
  189,   41,  191,  224,   74,   40,   44,   77,  224,  189,
   40,  183,  184,  185,   40,  262,  263,  189,  288,  289,
  209,   59,   41,   61,   41,  224,  257,  258,  259,  260,
  219,  259,  221,  222,  257,  224,   40,  209,  269,  270,
   10,  221,  224,  268,  123,  234,  162,  219,   59,  221,
  222,  121,   41,  169,  269,  270,   41,  246,   10,  248,
  249,  292,  234,  252,  295,  259,   36,  137,  248,  259,
  262,  263,  252,  189,  246,   40,  248,  249,  281,   49,
  252,  151,   41,  273,   36,  269,  270,  262,  263,  159,
  280,   59,  282,  283,  284,  285,  286,  287,  288,  289,
  170,   46,  292,   41,   74,  221,  222,   77,  224,   59,
   41,   41,  123,  183,  184,  185,   40,  262,  263,   41,
  269,  270,   74,  257,   58,   77,  275,  276,  277,  278,
  246,   59,  248,  259,  269,  270,  252,   41,   41,  209,
  275,  276,  277,  278,  275,  276,  277,  278,   58,  219,
   40,  121,  275,  276,  277,  278,   41,  125,  257,  258,
  259,  260,   41,    0,  234,   59,   59,  137,   59,  121,
  269,  270,   60,   41,   62,  125,  123,   59,   41,  249,
  257,  151,  259,  260,   41,  137,   43,   44,   45,  159,
   59,   41,  269,  270,  228,  224,  257,  159,  259,  151,
  170,   41,   59,   60,   -1,   62,   46,  159,  269,  270,
   -1,   89,   -1,  183,  184,  185,   -1,   -1,  170,   59,
   -1,   61,   41,   42,   43,   44,   45,   46,   47,   -1,
   -1,  183,  184,  185,   41,   -1,   43,   44,   45,  209,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,  259,  219,
   -1,   -1,   59,   60,   -1,   62,  226,  209,   -1,   41,
   42,   43,  273,   45,  234,   47,   -1,  219,   -1,  280,
   -1,  282,  283,  284,  285,  286,  287,   59,   60,  249,
   62,  292,  234,   41,   42,   43,   44,   45,   -1,   47,
   -1,  259,   41,   42,   43,   44,   45,  249,   47,   -1,
   -1,   59,   60,   -1,   62,  273,   -1,   -1,   -1,  259,
   59,   60,  280,   62,  282,  283,  284,  285,  286,  287,
   -1,   -1,   -1,  273,  292,   -1,  132,  133,  134,  135,
  280,  259,  282,  283,  284,  285,  286,  287,   42,   43,
   -1,   45,  292,   47,   -1,  273,   -1,   41,   42,   43,
   44,   45,  280,   47,  282,  283,  284,  285,  286,  287,
   -1,   -1,   -1,   -1,  292,   59,   60,   -1,   62,   41,
   42,   43,   10,   45,   -1,   47,  264,  265,  266,  267,
   41,   42,   43,   -1,   45,   -1,   47,   59,   60,   -1,
   62,   -1,   -1,   41,   42,   43,   -1,   45,   59,   47,
   -1,   39,   40,   -1,   -1,  262,  263,  264,  265,  266,
  267,   59,   50,   41,   42,   43,   -1,   45,   -1,   47,
   41,   42,   43,   -1,   45,   -1,   47,   42,   43,   -1,
   45,   59,   47,   -1,   39,   40,   74,   -1,   59,   77,
   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,
  269,  270,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,   69,   70,   71,   72,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,  266,  267,   59,   41,   42,   43,
   44,   45,   -1,   47,  132,  133,  134,  135,  163,  164,
  165,  166,  167,  168,  262,  263,  264,  265,  266,  267,
   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,  124,
   -1,   -1,  160,  161,   -1,  163,  164,  165,  166,  167,
  168,   -1,   -1,  171,  121,   41,   42,   43,   -1,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   -1,
  137,   -1,   -1,   59,   -1,  160,  161,   -1,  163,  164,
  165,  166,  167,  168,  151,   -1,  171,   -1,  262,  263,
  264,  265,  266,  267,   41,   42,   43,   44,   45,   -1,
   47,   -1,   -1,  170,   -1,   -1,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,  266,  267,  183,  184,  185,   41,
   42,   43,   -1,   45,   -1,   47,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   59,   -1,   -1,
   -1,   -1,  209,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,  219,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  234,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  249,
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
"class_body_stmt : var_declar_stmt",
"class_body_stmt : single_assign_stmt ';'",
"class_body_stmt : func_declar_stmt",
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
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
"single_assign_stmt : id_expr '=' single_assign_stmt",
"class_member_assign_stmt : class_member_stmt '=' assign_stmt_value",
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
#line 367 "a.y"


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
#line 662 "y.tab.c"

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
#line 95 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 16:
#line 96 "a.y"
	{ yyval.node = NULL;  }
break;
case 17:
#line 97 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 18:
#line 98 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 19:
#line 102 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 20:
#line 103 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 21:
#line 104 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 22:
#line 105 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 23:
#line 110 "a.y"
	{  yyval.node = NULL; }
break;
case 24:
#line 111 "a.y"
	{ yyval.node = NULL; }
break;
case 25:
#line 112 "a.y"
	{ yyval.node = NULL; }
break;
case 26:
#line 116 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 27:
#line 117 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 28:
#line 118 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 29:
#line 123 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 30:
#line 127 "a.y"
	{ yyval.params = NULL; }
break;
case 31:
#line 128 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 32:
#line 132 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 33:
#line 133 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 34:
#line 134 "a.y"
	{ yyval.params = NULL; }
break;
case 35:
#line 138 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 36:
#line 139 "a.y"
	{ yyval.node = NULL; }
break;
case 37:
#line 144 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 38:
#line 145 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 39:
#line 150 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 40:
#line 151 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 41:
#line 156 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 42:
#line 157 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 43:
#line 158 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 44:
#line 162 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 45:
#line 163 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 46:
#line 167 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 47:
#line 168 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 48:
#line 172 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 49:
#line 173 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 50:
#line 178 "a.y"
	{ yyval.node = NULL ; }
break;
case 51:
#line 179 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 52:
#line 180 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 53:
#line 181 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 54:
#line 186 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 55:
#line 187 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 188 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 57:
#line 189 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 190 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 191 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 192 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 197 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 62:
#line 198 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 63:
#line 202 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 64:
#line 203 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 65:
#line 204 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 66:
#line 209 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 67:
#line 210 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 214 "a.y"
	{ yyval.args = NULL; }
break;
case 69:
#line 215 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 70:
#line 219 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 71:
#line 220 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 72:
#line 224 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 225 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 226 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 227 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 76:
#line 228 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 77:
#line 229 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 78:
#line 230 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 79:
#line 234 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 80:
#line 235 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 241 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 247 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 84:
#line 253 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 85:
#line 254 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 86:
#line 255 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 87:
#line 256 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 88:
#line 261 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 89:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 90:
#line 263 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 91:
#line 264 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 92:
#line 269 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 93:
#line 273 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 94:
#line 277 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 95:
#line 281 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 96:
#line 285 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 97:
#line 289 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 98:
#line 293 "a.y"
	{ yyval.node = xnull();}
break;
case 99:
#line 298 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 100:
#line 299 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 101:
#line 304 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 102:
#line 305 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 103:
#line 306 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 104:
#line 307 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 105:
#line 308 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 106:
#line 309 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 107:
#line 310 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 108:
#line 311 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 109:
#line 312 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 110:
#line 317 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 111:
#line 318 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 112:
#line 319 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 113:
#line 320 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 114:
#line 325 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 115:
#line 326 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 116:
#line 327 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 117:
#line 328 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 118:
#line 329 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 119:
#line 330 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 120:
#line 331 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 332 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 333 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 123:
#line 334 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 124:
#line 335 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 125:
#line 340 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 341 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 342 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 343 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 344 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 349 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 131:
#line 350 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 132:
#line 354 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 133:
#line 359 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 360 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 135:
#line 361 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 136:
#line 362 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 137:
#line 363 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 138:
#line 364 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1412 "y.tab.c"
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
