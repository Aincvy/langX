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
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

extern int yyget_lineno(void);
extern int column; 
extern char * yytext;

#line 18 "a.y"
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
#line 50 "y.tab.c"

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
#define ADD_EQ 272
#define SUB_EQ 273
#define MUL_EQ 274
#define DIV_EQ 275
#define AUTO 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define FOR 280
#define DELETE 281
#define BREAK 282
#define RETURN 283
#define SWITCH 284
#define CASE 285
#define DEFAULT 286
#define CASE_LIST 287
#define CLAXX_BODY 288
#define NEW 289
#define NONASSOC 290
#define IFX 291
#define UMINUS 292
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   41,   41,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   35,   35,   36,   36,    5,   37,   37,   38,
   38,   38,    7,    7,    6,    6,    3,    3,    8,    8,
    8,   32,   32,   33,   33,    9,    9,   12,   12,   12,
   12,    4,    4,    4,    4,    4,   24,   24,   24,   16,
   39,   39,   40,   40,   17,   17,   17,   17,   17,   17,
   17,   11,   11,   18,   18,   19,   14,   14,   14,   14,
   31,   31,   31,   31,   25,   26,   27,   28,   29,   30,
   23,   23,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   15,   15,   15,   15,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   20,   20,   20,   20,   20,   22,
   22,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    1,    2,    1,    1,    6,    0,    3,    1,
    3,    0,    2,    0,    2,    3,    1,    1,    5,    7,
    7,    1,    2,    4,    3,    5,    9,    0,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    1,    2,    4,
    0,    1,    1,    3,    1,    1,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    3,    3,    3,    3,    3,
    1,    1,    1,    3,    5,    1,    1,    1,    2,    1,
    1,    1,    1,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    2,    2,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    3,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,   47,    0,    0,
    0,    4,    2,    5,    6,    0,    8,    9,   27,   28,
   42,   43,  112,   45,   46,    0,   10,    0,    0,    0,
    0,    0,    0,    0,   78,   77,    0,   80,    0,    0,
    0,    0,    0,    0,    0,   71,   49,  104,    0,   98,
    0,    0,    0,    0,    0,   76,    0,    7,    0,    0,
    0,    0,    0,    0,   25,    0,    0,    0,   11,   16,
   15,    0,    0,   13,    0,  109,    0,   53,    0,   55,
    0,    0,    0,    0,    0,    0,    0,  107,    0,    0,
    0,  105,  106,   72,    0,   40,    0,   39,   41,    0,
   44,   92,   93,    0,   79,   65,   64,    0,   94,   95,
    0,    0,    0,    0,    0,    0,  113,  114,  115,  116,
   26,  110,  111,    0,   20,    0,   24,   12,   14,   50,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   74,   73,    0,    0,   69,   70,    0,
    0,    0,   19,    0,   54,   90,   91,   24,   63,    0,
   86,   87,   88,   89,   84,   85,   36,    0,   66,    0,
   75,   21,   17,   23,    0,    0,    0,    0,    0,    0,
   32,   62,   30,    0,    0,   24,   31,   33,    0,   24,
    0,   37,    0,
};
static const short yydgoto[] = {                          1,
  159,   14,   15,   16,   17,   18,  154,   19,   20,   86,
  160,   97,   21,   87,   76,   88,   78,  105,  106,   89,
   47,   23,   90,   24,   25,   91,   80,   92,   93,   94,
   54,  180,  181,   27,   73,   74,   67,  126,   84,   85,
    2,
};
static const short yysindex[] = {                         0,
    0,   29,  -20,  -12,    8,   24, -209,    0,  -40,   28,
 -184,    0,    0,    0,    0,   18,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -34,    0,   46,  -70,   -7,
   45,   45, -218,   35,    0,    0,   56,    0, -184, -184,
  -10,   45,    0,    0,    0,    0,    0,    0, -226,    0,
    0,    0,    0,  157, -184,    0,   67,    0,   75,   75,
   75,   75, -184,  -40,    0, -149,    2, -157,    0,    0,
    0,   -2,  -69,    0,    0,    0,    0,    0, -226,    0,
    0,    0,    0,   74,   77,   -4,    0,    0,    0,  -51,
 -226,    0,    0,    0,   37,    0,   65,    0,    0,  -38,
    0,    0,    0,   75,    0,    0,    0,   91,    0,    0,
   45,   45,   45,   45,  100,   -7,    0,    0,    0,    0,
    0,    0,    0,  -59,    0,   21,    0,    0,    0,    0,
   -7,   45,   45,  -56,   45,   45,   45,   45,   45,   45,
  -56,   45,  102,    0,    0,   -8,   -8,    0,    0,   31,
  103,  -96,    0,  -13,    0,    0,    0,    0,    0, -114,
    0,    0,    0,    0,    0,    0,    0,  -55,    0, -180,
    0,    0,    0,    0,   14,  -56, -218,  -76,  129, -113,
    0,    0,    0,  150,  134,    0,    0,    0,  -56,    0,
   29,    0,   29,
};
static const short yyrindex[] = {                         0,
    0,  195,  -30,    0,    0,    0,    0,    0,  138,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   82,    0,  160,
    0,    0,  147,    0,    0,    0,   57,    0,    0,    0,
    0,    0,   50,  368,  392,    0,    0,    0,  458,    0,
  400,  413,  469,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,    0,   17,    0,    0,
    0,    0,    0,    0,  296,    0,  508,    0,  518,    0,
  525,  532,  539,    0,  171,    0,   93,    0,  115,   -6,
   86,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  232,    0,    0,
    0,    0,    0,    0,    0,  160,    0,    0,    0,    0,
    0,    0,    0,  488,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  106,  126,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  181,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -107,    0, -103,
};
static const short yygindex[] = {                         0,
    5,    0,    0,    0,   11,   16, -132,    0,    0,  -19,
 -117,   84,  -16,  366,   -1,  333,  123,    0,    0,  357,
  191,  201,  452,    0,    7,  365,   10,    6,   78,  376,
  -31,    0,   92,    0,    0,  216,    0,    0,  176,    0,
    0,
};
#define YYTABLESIZE 592
static const short yytable[] = {                         42,
   29,   64,   12,  177,   41,   63,   13,   44,  140,   63,
  139,  187,   95,   76,   51,   48,   98,   35,   50,   30,
   65,   34,   64,  167,   65,  175,   64,   31,   76,  104,
   76,   99,   42,  113,   83,   81,  134,   41,  114,   70,
   56,   63,  109,  110,   71,   12,  107,   32,   96,   34,
   39,   40,   83,  191,   69,  128,   65,  193,  183,   29,
   76,  153,   44,   33,  152,   22,  158,   55,   22,   51,
   48,  192,   12,   50,   56,   76,   58,  141,  121,  146,
  147,  148,  149,   70,   42,   66,   52,   12,   71,   41,
   99,   73,   73,  101,   73,   30,   73,   76,   76,   76,
   76,   76,   29,   76,  178,  179,  116,   82,   99,  125,
   28,  173,  156,  157,  130,   76,   76,   76,   76,   41,
  131,   81,  168,  142,  127,   29,  108,  108,  108,  108,
  108,  144,  108,   82,   73,   73,   81,   73,  182,   73,
  150,   52,  169,  171,  108,  108,   67,  108,   67,   67,
   67,   82,   82,  170,   82,   81,   71,   71,  174,   71,
   98,   71,  172,  176,   67,   67,   68,   67,   68,   68,
   68,  178,  179,   81,   81,   99,   81,   35,   35,  174,
   35,   34,   34,  185,   68,   68,  186,   68,   68,   68,
  189,  190,   96,   82,    1,  174,   48,  174,  113,  111,
   51,  112,    3,  114,   18,   38,  132,  133,   82,  109,
  110,   52,  135,  136,  137,  138,   35,   36,   37,   38,
    4,   38,    5,    6,    7,    8,    9,   10,   39,   40,
  109,  110,   11,   59,   60,   61,   62,   59,   60,   61,
   62,   76,   76,   76,   76,    3,   35,   28,   11,   35,
   36,   37,   38,  155,  122,   83,   83,  132,  133,   29,
  184,   39,   40,    4,  123,    5,    6,    7,    8,    9,
   10,  188,    3,   73,   73,   11,   73,   29,   73,   29,
   29,   29,   29,   29,   29,   29,   29,    3,  129,   29,
    4,  151,    5,    6,    7,    8,    9,   10,  132,  133,
    0,   35,   11,   37,   38,    4,    0,    5,    6,    7,
    8,    9,   10,   39,   40,    0,    0,   11,   76,   76,
   76,   76,   76,   76,    0,   76,   76,    0,    0,    0,
    0,   35,    0,   37,   22,    0,   61,   73,   73,   61,
   73,   45,   73,   39,   40,    0,    0,  108,  108,  108,
  108,  108,  108,    0,   82,   82,   82,   82,   82,   82,
    0,    0,   77,    0,    0,   46,   26,   67,   67,   67,
   67,   67,   67,   49,   43,   57,   81,   81,   81,   81,
   81,   81,    0,    0,   53,    0,   46,   68,   68,   68,
   68,   68,   68,   72,   79,   75,   45,  100,   46,    0,
    0,    0,    0,  102,  103,   83,    0,  108,  103,  109,
  109,    0,  109,    0,  109,  117,  118,  119,  120,  115,
   46,    0,    0,    0,    0,    0,  103,   72,  124,   43,
    0,    0,  100,  107,  107,    0,  107,   72,  107,   53,
   96,  105,  105,    0,  105,    0,  105,    0,   77,    0,
  100,    0,    0,   97,  106,  106,    0,  106,   96,  106,
  143,    0,    0,   77,    0,    0,   22,   46,   46,   46,
   46,   97,   46,   22,    0,    0,  145,  145,  145,  145,
   79,   75,    0,    0,    0,    0,   22,   46,    0,    0,
    0,   83,    0,    0,    0,   79,   75,    0,   26,  108,
  108,    0,  108,    0,  108,   26,   83,   22,   22,  102,
   72,   72,    0,   72,    0,   72,  101,    0,   26,    0,
    0,   22,    0,   22,    0,   22,    0,  102,  101,  108,
  108,    0,  108,    0,  108,    0,    0,    0,    0,   26,
   26,  100,    0,    0,    0,    0,  101,    0,   60,  107,
  107,   60,  107,   26,  107,   26,    0,   26,   57,  108,
  108,   57,  108,    0,  108,   56,  105,  105,   56,  105,
    0,  105,   59,  106,  106,   59,  106,    0,  106,   58,
   72,   72,   58,   72,    0,   72,  161,  162,  163,  164,
  165,  166,
};
static const short yycheck[] = {                         40,
    0,   61,   59,   59,   45,   44,    2,    9,   60,   44,
   62,  125,   32,   44,    9,    9,   33,  125,    9,   40,
   59,  125,   61,  141,   59,  158,   61,   40,   59,   40,
   61,   33,   40,   42,   41,   30,   41,   45,   47,   29,
  259,   44,  269,  270,   29,   59,   41,   40,   33,  259,
  269,  270,   59,  186,  125,  125,   59,  190,  176,   59,
   44,   41,   64,   40,   44,   41,  123,   40,   44,   64,
   64,  189,   59,   64,  259,   59,   59,   41,   63,  111,
  112,  113,  114,   73,   40,   40,    9,   59,   73,   45,
   41,   42,   43,   59,   45,   40,   47,   41,   42,   43,
   44,   45,  123,   47,  285,  286,   40,   30,   59,  259,
  268,  125,  132,  133,   41,   59,   60,   61,   62,   45,
   44,  116,  142,   59,  123,  125,   41,   42,   43,   44,
   45,   41,   47,   41,   42,   43,  131,   45,  125,   47,
   41,   64,   41,   41,   59,   60,   41,   62,   43,   44,
   45,   59,   60,  123,   62,   41,   42,   43,  154,   45,
  177,   47,  259,  278,   59,   60,   41,   62,   43,   44,
   45,  285,  286,   59,   60,  177,   62,  285,  286,  175,
  257,  285,  286,  178,   59,   60,   58,   62,  259,  259,
   41,   58,  177,  116,    0,  191,   59,  193,   42,   43,
   41,   45,  259,   47,  123,   59,  262,  263,  131,  269,
  270,   41,  264,  265,  266,  267,  257,  258,  259,  260,
  277,   41,  279,  280,  281,  282,  283,  284,  269,  270,
  269,  270,  289,  272,  273,  274,  275,  272,  273,  274,
  275,  272,  273,  274,  275,  259,  257,  268,  289,  257,
  258,  259,  260,  131,   64,  262,  263,  262,  263,  259,
  177,  269,  270,  277,   64,  279,  280,  281,  282,  283,
  284,  180,  259,   42,   43,  289,   45,  277,   47,  279,
  280,  281,  282,  283,  284,  285,  286,  259,   73,  289,
  277,  116,  279,  280,  281,  282,  283,  284,  262,  263,
   -1,  257,  289,  259,  260,  277,   -1,  279,  280,  281,
  282,  283,  284,  269,  270,   -1,   -1,  289,  262,  263,
  264,  265,  266,  267,   -1,  269,  270,   -1,   -1,   -1,
   -1,  257,   -1,  259,    2,   -1,   41,   42,   43,   44,
   45,    9,   47,  269,  270,   -1,   -1,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,   30,   -1,   -1,    9,    2,  262,  263,  264,
  265,  266,  267,    9,    9,   11,  262,  263,  264,  265,
  266,  267,   -1,   -1,    9,   -1,   30,  262,  263,  264,
  265,  266,  267,   29,   30,   30,   64,   33,   42,   -1,
   -1,   -1,   -1,   39,   40,   30,   -1,   42,   41,   42,
   43,   -1,   45,   -1,   47,   59,   60,   61,   62,   55,
   64,   -1,   -1,   -1,   -1,   -1,   59,   63,   64,   64,
   -1,   -1,   41,   42,   43,   -1,   45,   73,   47,   64,
   41,   42,   43,   -1,   45,   -1,   47,   -1,  116,   -1,
   59,   -1,   -1,   41,   42,   43,   -1,   45,   59,   47,
  104,   -1,   -1,  131,   -1,   -1,  134,  111,  112,  113,
  114,   59,  116,  141,   -1,   -1,  111,  112,  113,  114,
  116,  116,   -1,   -1,   -1,   -1,  154,  131,   -1,   -1,
   -1,  116,   -1,   -1,   -1,  131,  131,   -1,  134,   42,
   43,   -1,   45,   -1,   47,  141,  131,  175,  176,   41,
   42,   43,   -1,   45,   -1,   47,   59,   -1,  154,   -1,
   -1,  189,   -1,  191,   -1,  193,   -1,   59,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  175,
  176,  177,   -1,   -1,   -1,   -1,   59,   -1,   41,   42,
   43,   44,   45,  189,   47,  191,   -1,  193,   41,   42,
   43,   44,   45,   -1,   47,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,  135,  136,  137,  138,
  139,  140,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TDOUBLE","TBOOL","IDENTIFIER","TSTRING","OP_CALC",
"AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP",
"FUNC_CALL","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE",
"FOR","DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT","CASE_LIST",
"CLAXX_BODY","NEW","NONASSOC","IFX","UMINUS",
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
"interrupt_stmt : BREAK",
"interrupt_stmt : RETURN",
"interrupt_stmt : RETURN assign_stmt_value",
"call_statement : IDENTIFIER '(' args_list ')'",
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
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
"single_assign_stmt : id_expr '=' single_assign_stmt",
"assign_stmt : single_assign_stmt",
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
#line 322 "a.y"


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
#line 558 "y.tab.c"

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
#line 62 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 66 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 67 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 68 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 69 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 74 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 75 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 76 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 11:
#line 81 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-2].sValue , NULL); }
break;
case 12:
#line 82 "a.y"
	{ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-1].node); }
break;
case 13:
#line 87 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 14:
#line 88 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 15:
#line 92 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 16:
#line 93 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 17:
#line 98 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 18:
#line 102 "a.y"
	{ yyval.params = NULL; }
break;
case 19:
#line 103 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 20:
#line 107 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 21:
#line 108 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 22:
#line 109 "a.y"
	{ yyval.params = NULL; }
break;
case 23:
#line 113 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 24:
#line 114 "a.y"
	{ yyval.node = NULL; }
break;
case 25:
#line 119 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 26:
#line 120 "a.y"
	{ yyval.node = opr(',' , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 27:
#line 125 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 28:
#line 126 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 29:
#line 131 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 30:
#line 132 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 31:
#line 133 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 32:
#line 137 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 33:
#line 138 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 34:
#line 142 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 35:
#line 143 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 36:
#line 147 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 37:
#line 148 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 38:
#line 153 "a.y"
	{ yyval.node = NULL ; }
break;
case 39:
#line 154 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 40:
#line 155 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 41:
#line 156 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 42:
#line 161 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 43:
#line 162 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 44:
#line 163 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 45:
#line 164 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 165 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 47:
#line 169 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 48:
#line 170 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 49:
#line 171 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 50:
#line 176 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 51:
#line 180 "a.y"
	{ yyval.args = NULL; }
break;
case 52:
#line 181 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 53:
#line 185 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 54:
#line 186 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 55:
#line 190 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 191 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 192 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 193 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 194 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 195 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 196 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 62:
#line 200 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 63:
#line 201 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 207 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 65:
#line 208 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 66:
#line 213 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 67:
#line 219 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 68:
#line 220 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 69:
#line 221 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 70:
#line 222 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 71:
#line 227 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 72:
#line 228 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 73:
#line 229 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 74:
#line 230 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 75:
#line 235 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 76:
#line 239 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 77:
#line 243 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 78:
#line 247 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 79:
#line 251 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 80:
#line 255 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 81:
#line 260 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 261 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 266 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 267 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 85:
#line 268 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 86:
#line 269 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 87:
#line 270 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 88:
#line 271 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 89:
#line 272 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 90:
#line 273 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 91:
#line 274 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 92:
#line 279 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 93:
#line 280 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 94:
#line 281 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 95:
#line 282 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 96:
#line 287 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 97:
#line 288 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 98:
#line 289 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 99:
#line 290 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 100:
#line 291 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 101:
#line 292 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 102:
#line 293 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 103:
#line 294 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 104:
#line 295 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 105:
#line 300 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 106:
#line 301 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 107:
#line 302 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 303 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 109:
#line 304 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 110:
#line 309 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 111:
#line 310 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 112:
#line 315 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 113:
#line 316 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 114:
#line 317 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 115:
#line 318 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 116:
#line 319 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1220 "y.tab.c"
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
