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
    0,   50,   50,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   35,   35,   36,   36,   36,   43,   43,   44,
   44,   45,   45,   37,   37,   37,   37,   39,   39,   39,
   39,   40,   40,   40,    5,   46,   46,   47,   47,   47,
    7,    7,    6,    6,    3,    3,    8,    8,    8,   32,
   32,   33,   33,    9,    9,   12,   12,   12,   12,    4,
    4,    4,    4,    4,    4,    4,   42,   42,   24,   24,
   24,   16,   16,   48,   48,   49,   49,   17,   17,   17,
   17,   17,   17,   17,   11,   11,   18,   18,   19,   14,
   14,   14,   14,   31,   31,   31,   31,   25,   26,   27,
   28,   29,   30,   41,   23,   23,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   15,   15,   15,   15,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   20,   20,   20,   20,   20,   22,   22,   38,   38,   13,
   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    1,    2,    1,    2,    1,    1,    1,    3,
    3,    6,    3,    3,    3,    6,    3,    6,    9,    6,
    6,    8,   10,    5,    6,    0,    3,    1,    3,    0,
    2,    0,    2,    3,    1,    1,    5,    7,    7,    1,
    2,    4,    3,    5,    9,    0,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    1,    1,    2,    1,    1,
    2,    4,    1,    0,    1,    1,    3,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    3,    3,
    3,    3,    3,    1,    1,    1,    3,    5,    1,    1,
    1,    2,    1,    1,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    2,    2,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    3,    3,    3,    3,    1,
    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   69,
    0,    0,    0,    4,    2,    5,    6,    0,    8,    9,
   45,   46,   60,   61,  140,   63,   64,    0,   10,    0,
  141,    0,    0,   66,    0,    0,    0,    0,  100,   68,
    0,    0,    0,    0,    0,  101,    0,  103,    0,    0,
  104,    0,    0,    0,    0,    0,   94,   71,  128,    0,
  122,    0,    0,    0,    0,    0,  130,    0,   99,    0,
    7,    0,    0,    0,    0,    0,    0,   43,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   11,   17,   15,
    0,    0,    0,   13,    0,  135,    0,   76,    0,   78,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  133,    0,    0,    0,  131,  132,   95,    0,
   58,    0,   57,   59,    0,   62,    0,  116,  117,    0,
  102,   88,   87,    0,  118,  119,    0,    0,    0,    0,
    0,    0,    0,  142,  143,  144,  145,   44,    0,  136,
  137,    0,    0,  138,    0,    0,    0,  139,   38,    0,
   42,   16,   12,   14,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   97,    0,   96,    0,    0,   92,   93,    0,    0,    0,
    0,    0,    0,    0,   37,    0,    0,    0,   77,    0,
  114,  115,   42,   86,    0,  110,  111,  112,  113,  108,
  109,   54,    0,    0,   89,    0,    0,   98,    0,    0,
    0,   34,   39,   35,   41,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   50,    0,   30,   31,    0,
    0,   85,   48,    0,   28,    0,   42,   49,   51,    0,
   32,    0,    0,   42,    0,    0,   29,   55,    0,    0,
   33,
};
static const short yydgoto[] = {                          1,
  204,   16,   17,   18,   19,   20,  196,   21,   22,  111,
  205,  122,   23,   95,   96,  113,   98,  131,  132,   57,
   58,   25,  115,   26,   27,  116,  100,  117,  118,  119,
   65,  235,  236,   29,   93,   94,  104,   31,   32,   33,
   67,   34,    0,   35,    0,   86,  160,  105,  106,    2,
};
static const short yysindex[] = {                         0,
    0,  334,  -38, -237,   11,   -3,   21,   25, -192,    0,
   50,   36, -165,    0,    0,    0,    0,   43,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   84,    0,   -5,
    0,   51, -150,    0,   49,   80, -107,  141,    0,    0,
 -138,  210,  210,  120,   81,    0,   82,    0, -165, -165,
    0,  -23,  210,    0,    0,    0,    0,    0,    0,  -24,
    0,    0,    0,    0,  469,   83,    0, -165,    0,  106,
    0,    8,    8,    8,    8, -165,   50,    0, -165,   50,
 -165, -165,  111,   50,  -98,   56, -102,    0,    0,    0,
  126,  156,  -99,    0,    0,    0,    0,    0,  -24,    0,
    0,    0,    0,   83,  146,  149,  155,  158,   83,   51,
  -37,    0,    0,    0,  -54,  -24,    0,    0,    0,   17,
    0,  142,    0,    0,  -34,    0,  141,    0,    0,    8,
    0,    0,    0,  167,    0,    0, -165,  210,  210,  210,
  210,  179,  141,    0,    0,    0,    0,    0,   27,    0,
    0,  -32,  181,    0,  182,  183,  141,    0,    0,   18,
    0,    0,    0,    0,  -43,  141,  141,  210,  210,  148,
  210,  210,  210,  210,  210,  210,  148,  210,  190,  192,
    0,  208,    0,   -9,   -9,    0,    0,  133,  218,  141,
  141,  141,  220,    4,    0,  289,  209, -165,    0,  223,
    0,    0,    0,    0,  -12,    0,    0,    0,    0,    0,
    0,    0,  -44,  230,    0,  141, -245,    0,  255,  257,
  262,    0,    0,    0,    0,  141,  264,  230,  318,  148,
  120,  265,   48,  254, -105,    0,   55,    0,    0,  277,
  141,    0,    0,  290,    0,  279,    0,    0,    0,  298,
    0,  303,  148,    0,  334,  141,    0,    0,  334,  305,
    0,
};
static const short yyrindex[] = {                         0,
    0,  347,   98,  291,    0,    0,    0,    0,    0,    0,
  293,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  487,  294,    0,    0,  233,    0,  316,    0,    0,
    0,    0,    0,  299,    0,    0,  463,    0,    0,    0,
    0,    0,    0,  615,  628,  643,    0,    0,    0,  653,
    0,  662,  724,  746,    0,  -10,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   52,    0,  269,    0,    0,    0,
    0,    0,    0,    0,  446,    0,  778,    0,  785,    0,
  792,  799,  820,    0,    0,  322,   57,  307,  308,    0,
    0,  537,    0,  593,   10,  497,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  316,    0,    0,    0,
    0,    0,    0,  668,    0,    0,    0,    0,    0,    0,
    0,    0,  316,    0,    0,    0,    0,    0,    0,    0,
    0,  653,   38,    0,    9,  121,  316,    0,    0,    0,
    0,    0,    0,    0,  312,    0,  316,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  324,    0,  401,  414,    0,    0,    0,    0,  316,
  316,  316,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,  586,    0,  316,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  316,  378,    0,    0,    0,
  323,    0,    0,    0,    0,    0,  -14,    0,    0,    0,
  316,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -97,  316,    0,    0,  -91,    0,
    0,
};
static const short yygindex[] = {                         0,
    3,    0,    0,    0,  -30,   63, -130,    0,    0,  -20,
 -147,  151,  -25,  640,   93,  125,  206,    0,    0,  569,
   92,   15,  601,    0,   35,   -2,   94,  259,  311,  329,
   -7,    0,  152,    0,    0,  304,   70,    0,  -28,    0,
    0,    0,    0,    0,    0,    0,    0, -103,    0,    0,
};
#define YYTABLESIZE 867
static const short yytable[] = {                         28,
   47,   38,  198,  170,   15,  176,   89,  175,   60,   76,
   70,  137,  110,  137,  231,  110,  130,   88,  123,  248,
   39,  137,  120,  179,   78,  163,   77,   53,   77,  212,
  129,   28,  140,   52,   92,   99,   42,  141,  108,  189,
   81,  125,  233,  234,   28,   59,  128,  129,  129,   27,
  107,   91,   52,  193,   27,   80,   41,  177,  195,   47,
   43,  194,   89,  200,   44,  142,   45,   27,  107,   27,
   76,   30,  229,  149,  152,   68,  153,   60,  155,  156,
   66,   60,  243,   24,   37,   78,  219,  220,  221,   53,
   92,  151,   40,   69,   52,   40,   82,   40,   24,   90,
   99,   71,   99,   55,   61,  258,  121,   91,   83,   84,
  109,   59,  232,   30,   59,   99,  255,   99,   59,   85,
  107,  127,  240,  259,   99,   47,   24,   76,   81,   79,
  184,  185,  186,  187,  182,   56,  124,  252,  148,  126,
   99,   99,   78,   99,   77,  143,   66,  201,  202,   66,
  157,   87,  260,   66,   99,   90,   99,  213,   99,   87,
  159,   25,   97,   99,   99,   36,   25,   28,  150,   55,
   61,  154,   55,   61,   28,  158,   55,   61,  161,   25,
   53,   25,  233,  234,  162,   52,  165,   99,   99,   99,
   53,   53,  166,   28,  167,  227,   52,   52,  225,   76,
  178,   56,  110,  137,   56,  123,   14,  181,   56,  171,
  172,  173,  174,   99,   78,  197,   77,  168,  169,  188,
  190,  191,  192,   99,  168,  169,   28,   28,  125,   36,
  214,  225,  215,   46,  135,  136,  135,  136,   99,   30,
   72,   73,   74,   75,  135,  136,   30,  216,  226,   53,
   28,   97,   28,   99,   52,  217,   28,  225,  218,   47,
  222,  225,  223,  228,   46,   30,   47,   97,  230,   62,
  203,  107,  107,   47,   47,  198,   49,   50,  168,  169,
   47,   97,   47,   47,   47,   47,   47,   47,   47,   47,
   97,   97,   47,  121,   24,  237,  101,  238,   30,   30,
   30,   24,  239,  241,   46,  245,   46,   39,   47,   48,
  133,  247,   99,  250,   97,   97,   97,  251,   49,   50,
   24,   63,   30,  124,   30,   99,   99,   99,   30,   99,
  253,   99,   99,   99,   99,   62,  254,  256,   62,   64,
   97,   13,   62,  257,   51,  261,    1,   14,  102,   67,
   97,   70,   65,   24,   24,   36,   74,   56,   72,   73,
   74,   75,   75,   56,   24,   97,  103,   20,   21,   24,
   72,  199,   99,   99,   99,   99,   14,   24,  107,   24,
   97,  244,   24,   24,   24,  101,  249,   63,   49,   50,
   63,    0,   14,    5,   63,    0,  164,   46,   39,   47,
   48,  101,    0,    0,    0,   64,    3,    0,   64,   49,
   50,    0,   64,  224,    0,  101,    0,    0,   26,    0,
    4,    5,    0,   26,  101,  101,    0,    6,    0,    7,
    8,    9,   10,   11,   12,    0,   26,  102,   26,   13,
    0,   90,  242,   90,   90,   90,    0,    0,  101,  101,
  101,    0,    0,  102,   91,  103,   91,   91,   91,   90,
   90,    0,   90,    0,    0,    0,   46,  102,   47,   48,
    0,  103,   91,   91,  101,   91,  102,  102,   49,   50,
    0,    0,    0,    0,  101,  103,   84,   96,   96,   84,
   96,  246,   96,    0,  103,  103,    0,    0,    0,  101,
  102,  102,  102,   99,   99,   99,   99,   99,   99,   99,
  140,  138,    0,  139,  101,  141,    0,    0,  103,  103,
  103,   99,   99,   99,   99,    0,  102,   73,   73,   73,
   73,   73,    0,   73,    0,    0,  102,  134,  134,  134,
  134,  134,    0,  134,  103,   73,   73,    3,   73,    0,
    0,  102,    0,    0,  103,  134,  134,    0,  134,    0,
    0,    4,    5,    0,    0,    0,  102,    0,    6,  103,
    7,    8,    9,   10,   11,   12,    3,  106,   96,   96,
   13,   96,    0,   96,  103,    0,    0,    0,    0,    0,
    4,    5,    3,    0,    0,  106,  106,    6,  106,    7,
    8,    9,   10,   11,   12,    0,    4,    5,    0,   13,
  114,  114,    0,    6,    0,    7,    8,    9,   10,   11,
   12,    0,    0,    0,    0,   13,   72,   72,   72,   72,
   72,    0,   72,  105,   94,   94,    0,   94,    0,   94,
  144,  145,  146,  147,   72,   72,    0,   72,    0,    0,
   54,  105,  105,    0,  105,  123,   96,   96,    0,   96,
    0,   96,   90,   90,   90,   90,   90,   90,  127,  135,
  135,    0,  135,  123,  135,   91,   91,   91,   91,   91,
   91,  112,  112,  124,  133,  133,  127,  133,    0,  133,
    0,    0,  134,  125,  134,  134,    0,  134,  180,  134,
    0,  124,  120,  131,  131,    0,  131,    0,  131,   96,
   96,  125,   96,    0,   96,    0,   54,    0,    0,   54,
  120,    0,    0,   54,   99,   99,   99,   99,   99,   99,
    0,   99,   99,    0,    0,    0,  114,  114,    0,  114,
  114,  114,  114,  114,  114,    0,  114,    0,   73,   73,
   73,   73,   73,   73,    0,    0,    0,    0,  134,  134,
  134,  134,  134,  134,  121,  132,  132,    0,  132,    0,
  132,  206,  207,  208,  209,  210,  211,  183,  183,  183,
  183,    0,  121,    0,    0,    0,  126,   95,   95,    0,
   95,    0,   95,    0,    0,    0,    0,    0,  106,  106,
  106,  106,  106,  106,  126,    0,    0,  112,  112,    0,
  112,  112,  112,  112,  112,  112,    0,  112,   83,  133,
  133,   83,  133,    0,  133,   80,  134,  134,   80,  134,
    0,  134,   79,  131,  131,   79,  131,    0,  131,   82,
  132,  132,   82,  132,    0,  132,    0,   72,   72,   72,
   72,   72,   72,    0,  105,  105,  105,  105,  105,  105,
   81,   95,   95,   81,   95,    0,   95,
};
static const short yycheck[] = {                          2,
    0,   40,   46,   41,    2,   60,   37,   62,   11,   44,
   13,   46,   41,   46,   59,   44,   40,  125,   44,  125,
  258,   46,   43,  127,   59,  125,   61,  125,   61,  177,
   41,   46,   42,  125,   37,   38,   40,   47,   41,  143,
   46,   44,  288,  289,   59,   11,   49,   50,   59,   41,
   41,   37,   45,  157,   46,   61,   46,   41,   41,   59,
   40,   44,   93,  167,   40,   68,  259,   59,   59,   61,
   44,    2,  203,   76,   77,   40,   79,   80,   81,   82,
   11,   84,  230,   46,  123,   59,  190,  191,  192,   40,
   93,   77,   41,  259,   45,   44,   46,    4,   61,   37,
   44,   59,   46,   11,   11,  253,   44,   93,  259,   61,
   41,   77,  216,   44,   80,   59,  247,   61,   84,   40,
  259,   40,  226,  254,  127,  125,    2,   44,   46,   46,
  138,  139,  140,  141,  137,   11,   44,  241,   76,   59,
  143,   44,   59,   46,   61,   40,   77,  168,  169,   80,
   40,  259,  256,   84,  157,   93,   59,  178,   61,  259,
  259,   41,   38,  166,  167,  268,   46,  170,   77,   77,
   77,   80,   80,   80,  177,   84,   84,   84,  123,   59,
   40,   61,  288,  289,   59,   45,   41,  190,  191,  192,
  288,  289,   44,  196,   40,  198,  288,  289,  196,   44,
   59,   77,  231,   46,   80,  231,   59,   41,   84,  264,
  265,  266,  267,  216,   59,  259,   61,  262,  263,   41,
   40,   40,   40,  226,  262,  263,  229,  230,  231,  268,
   41,  229,   41,  257,  269,  270,  269,  270,  241,  170,
  275,  276,  277,  278,  269,  270,  177,   40,   40,   40,
  253,  127,  255,  256,   45,  123,  259,  255,   41,  259,
   41,  259,  259,   41,  257,  196,  259,  143,  281,   11,
  123,  262,  263,  273,  274,   46,  269,  270,  262,  263,
  280,  157,  282,  283,  284,  285,  286,  287,  288,  289,
  166,  167,  292,  231,  170,   41,   38,   41,  229,  230,
  231,  177,   41,   40,  257,   41,  257,  258,  259,  260,
   52,   58,   44,  259,  190,  191,  192,   41,  269,  270,
  196,   11,  253,  231,  255,  269,  270,   59,  259,   61,
   41,  275,  276,  277,  278,   77,   58,   40,   80,   11,
  216,  292,   84,   41,  295,   41,    0,   59,   38,   59,
  226,   59,   59,  229,  230,  123,   41,   59,  275,  276,
  277,  278,   41,   41,   41,  241,   38,   61,   61,   46,
   59,  166,  275,  276,  277,  278,   59,  253,  259,  255,
  256,  231,   59,  259,   61,  127,  235,   77,  269,  270,
   80,   -1,   59,  274,   84,   -1,   93,  257,  258,  259,
  260,  143,   -1,   -1,   -1,   77,  259,   -1,   80,  269,
  270,   -1,   84,  125,   -1,  157,   -1,   -1,   41,   -1,
  273,  274,   -1,   46,  166,  167,   -1,  280,   -1,  282,
  283,  284,  285,  286,  287,   -1,   59,  127,   61,  292,
   -1,   41,  125,   43,   44,   45,   -1,   -1,  190,  191,
  192,   -1,   -1,  143,   41,  127,   43,   44,   45,   59,
   60,   -1,   62,   -1,   -1,   -1,  257,  157,  259,  260,
   -1,  143,   59,   60,  216,   62,  166,  167,  269,  270,
   -1,   -1,   -1,   -1,  226,  157,   41,   42,   43,   44,
   45,  233,   47,   -1,  166,  167,   -1,   -1,   -1,  241,
  190,  191,  192,   41,   42,   43,   44,   45,   46,   47,
   42,   43,   -1,   45,  256,   47,   -1,   -1,  190,  191,
  192,   59,   60,   61,   62,   -1,  216,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,  226,   41,   42,   43,
   44,   45,   -1,   47,  216,   59,   60,  259,   62,   -1,
   -1,  241,   -1,   -1,  226,   59,   60,   -1,   62,   -1,
   -1,  273,  274,   -1,   -1,   -1,  256,   -1,  280,  241,
  282,  283,  284,  285,  286,  287,  259,   41,   42,   43,
  292,   45,   -1,   47,  256,   -1,   -1,   -1,   -1,   -1,
  273,  274,  259,   -1,   -1,   59,   60,  280,   62,  282,
  283,  284,  285,  286,  287,   -1,  273,  274,   -1,  292,
   42,   43,   -1,  280,   -1,  282,  283,  284,  285,  286,
  287,   -1,   -1,   -1,   -1,  292,   41,   42,   43,   44,
   45,   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,
   72,   73,   74,   75,   59,   60,   -1,   62,   -1,   -1,
   11,   59,   60,   -1,   62,   41,   42,   43,   -1,   45,
   -1,   47,  262,  263,  264,  265,  266,  267,   41,   42,
   43,   -1,   45,   59,   47,  262,  263,  264,  265,  266,
  267,   42,   43,   41,   42,   43,   59,   45,   -1,   47,
   -1,   -1,   53,   41,   42,   43,   -1,   45,  130,   47,
   -1,   59,   41,   42,   43,   -1,   45,   -1,   47,   42,
   43,   59,   45,   -1,   47,   -1,   77,   -1,   -1,   80,
   59,   -1,   -1,   84,  262,  263,  264,  265,  266,  267,
   -1,  269,  270,   -1,   -1,   -1,  168,  169,   -1,  171,
  172,  173,  174,  175,  176,   -1,  178,   -1,  262,  263,
  264,  265,  266,  267,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,   41,   42,   43,   -1,   45,   -1,
   47,  171,  172,  173,  174,  175,  176,  138,  139,  140,
  141,   -1,   59,   -1,   -1,   -1,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,   59,   -1,   -1,  168,  169,   -1,
  171,  172,  173,  174,  175,  176,   -1,  178,   41,   42,
   43,   44,   45,   -1,   47,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,   -1,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
   41,   42,   43,   44,   45,   -1,   47,
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
"this_stmt : this_member_stmt",
"this_stmt : this_func_stmt",
"this_member_stmt : THIS '.' id_expr",
"this_member_stmt : THIS '.' class_member_stmt",
"this_func_stmt : THIS '.' id_expr '(' args_list ')'",
"this_func_stmt : THIS '.' class_member_func_stmt",
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
#line 676 "y.tab.c"

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
#line 100 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 19:
#line 101 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 20:
#line 105 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 21:
#line 106 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 22:
#line 110 "a.y"
	{}
break;
case 23:
#line 111 "a.y"
	{}
break;
case 24:
#line 116 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 25:
#line 117 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 26:
#line 118 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 27:
#line 119 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 28:
#line 123 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 29:
#line 124 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 30:
#line 125 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 31:
#line 126 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 32:
#line 131 "a.y"
	{  yyval.node = NULL; }
break;
case 33:
#line 132 "a.y"
	{ yyval.node = NULL; }
break;
case 34:
#line 133 "a.y"
	{ yyval.node = NULL; }
break;
case 35:
#line 138 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 36:
#line 142 "a.y"
	{ yyval.params = NULL; }
break;
case 37:
#line 143 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 38:
#line 147 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 39:
#line 148 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 40:
#line 149 "a.y"
	{ yyval.params = NULL; }
break;
case 41:
#line 153 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 42:
#line 154 "a.y"
	{ yyval.node = NULL; }
break;
case 43:
#line 159 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 44:
#line 160 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 45:
#line 165 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 166 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 47:
#line 171 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 48:
#line 172 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 49:
#line 173 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 50:
#line 177 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 51:
#line 178 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 52:
#line 182 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 53:
#line 183 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 54:
#line 187 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 55:
#line 188 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 56:
#line 193 "a.y"
	{ yyval.node = NULL ; }
break;
case 57:
#line 194 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 195 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 196 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 201 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 202 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 62:
#line 203 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 63:
#line 204 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 205 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 206 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 207 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 67:
#line 212 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 68:
#line 213 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 69:
#line 217 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 70:
#line 218 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 71:
#line 219 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 72:
#line 224 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 73:
#line 225 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 229 "a.y"
	{ yyval.args = NULL; }
break;
case 75:
#line 230 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 76:
#line 234 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 77:
#line 235 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 78:
#line 239 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 240 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 241 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 243 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 244 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 245 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 85:
#line 249 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 86:
#line 250 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 256 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 257 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 90:
#line 268 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 91:
#line 269 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 92:
#line 270 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 93:
#line 271 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 94:
#line 276 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 95:
#line 277 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 96:
#line 278 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 97:
#line 279 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 98:
#line 284 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 99:
#line 288 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 100:
#line 292 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 101:
#line 296 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 102:
#line 300 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 103:
#line 304 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 104:
#line 308 "a.y"
	{ yyval.node = xnull();}
break;
case 105:
#line 313 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 106:
#line 314 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 107:
#line 319 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 320 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 109:
#line 321 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 110:
#line 322 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 111:
#line 323 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 112:
#line 324 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 113:
#line 325 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 326 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 115:
#line 327 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 116:
#line 332 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 117:
#line 333 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 118:
#line 334 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 119:
#line 335 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 120:
#line 340 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 341 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 122:
#line 342 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 123:
#line 343 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 124:
#line 344 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 125:
#line 345 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 126:
#line 346 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 347 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 348 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 349 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 350 "a.y"
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
#line 1454 "y.tab.c"
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
