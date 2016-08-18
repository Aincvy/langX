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
#define CLAXX_MEMBER 290
#define NONASSOC 291
#define IFX 292
#define UMINUS 293
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   43,   43,    1,    1,    1,    1,    2,    2,    2,
   34,   34,   35,   35,   37,   36,   36,   36,    5,   39,
   39,   40,   40,   40,    7,    7,    6,    6,    3,    3,
    8,    8,    8,   32,   32,   33,   33,    9,    9,   12,
   12,   12,   12,    4,    4,    4,    4,    4,   24,   24,
   24,   16,   41,   41,   42,   42,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   31,   31,   31,   31,   25,   26,   27,   28,
   29,   30,   23,   23,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   15,   15,   15,   15,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   20,   20,   20,
   20,   20,   22,   22,   38,   13,   13,   13,   13,   13,
   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    1,    2,    3,    1,    2,    1,    6,    0,
    3,    1,    3,    0,    2,    0,    2,    3,    1,    1,
    5,    7,    7,    1,    2,    4,    3,    5,    9,    0,
    1,    1,    1,    1,    1,    3,    1,    1,    1,    1,
    2,    4,    0,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    3,    3,
    3,    3,    1,    1,    1,    3,    5,    1,    1,    1,
    2,    1,    1,    1,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    2,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    3,    3,    1,    1,    3,    3,    3,
    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,   49,    0,    0,
    0,    4,    2,    5,    6,    0,    8,    9,   29,   30,
   44,   45,  116,   47,   48,    0,   10,    0,  117,    0,
    0,    0,    0,    0,    0,    0,   80,   79,    0,   82,
    0,    0,    0,    0,    0,    0,    0,   73,   51,  106,
    0,  100,    0,    0,    0,    0,  107,    0,   78,    0,
    7,    0,    0,    0,    0,    0,    0,   27,    0,    0,
    0,    0,    0,   11,   18,   16,    0,    0,    0,   13,
    0,  112,    0,   55,    0,   57,    0,    0,    0,    0,
    0,    0,    0,  110,    0,    0,    0,  108,  109,   74,
    0,   42,    0,   41,   43,    0,   46,   94,   95,    0,
   81,   67,   66,    0,   96,   97,    0,    0,    0,    0,
    0,    0,  118,  119,  120,  121,   28,    0,  113,  114,
    0,   15,  115,   22,    0,   26,   17,   12,   14,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,   75,    0,    0,   71,   72,    0,
    0,    0,   21,    0,   56,   92,   93,   26,   65,    0,
   88,   89,   90,   91,   86,   87,   38,    0,   68,    0,
   77,   23,   19,   25,    0,    0,    0,    0,    0,    0,
   34,   64,   32,    0,    0,   26,   33,   35,    0,   26,
    0,   39,    0,
};
static const short yydgoto[] = {                          1,
  169,   14,   15,   16,   17,   18,  164,   19,   20,   92,
  170,  103,   21,   93,   82,   94,   84,  111,  112,   48,
   49,   23,   96,   24,   25,   97,   52,   98,   99,  100,
   56,  190,  191,   27,   79,   80,   28,   29,   72,  135,
   90,   91,    2,
};
static const short yysindex[] = {                         0,
    0,   29,  -14,   -5,   16,   30, -218,    0,  -40,   42,
 -216,    0,    0,    0,    0,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -34,    0,   46,    0,   74,
 -105,   -7,   45,   45, -178,   73,    0,    0,   97,    0,
 -216, -216,    2,   45,    0,    0,    0,    0,    0,    0,
  -12,    0,    0,    0,    0,   68,    0, -216,    0,  119,
    0,   75,   75,   75,   75, -216,  -40,    0, -216,  -40,
  -83,   41,  -90,    0,    0,    0,  125,   -4,  -78,    0,
    0,    0,    0,    0, -148,    0,    0,    0,    0,  146,
  145,   37,    0,    0,    0,  -58, -148,    0,    0,    0,
   54,    0,  139,    0,    0,  -38,    0,    0,    0,   75,
    0,    0,    0,  159,    0,    0,   45,   45,   45,   45,
  160,   -7,    0,    0,    0,    0,    0,  -27,    0,    0,
  -22,    0,    0,    0,   10,    0,    0,    0,    0,    0,
   -7,   45,   45,  -56,   45,   45,   45,   45,   45,   45,
  -56,   45,  164,    0,    0,    3,    3,    0,    0,   89,
  172,  -45,    0,  -13,    0,    0,    0,    0,    0,  -63,
    0,    0,    0,    0,    0,    0,    0,  -52,    0, -113,
    0,    0,    0,    0,   14,  -56, -178,  -41,  197, -106,
    0,    0,    0,  181,  198,    0,    0,    0,  -56,    0,
   29,    0,   29,
};
static const short yyrindex[] = {                         0,
    0,  261,  -30,    0,    0,    0,    0,    0,  206,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  149,
    0,  236,    0,    0,  220,    0,    0,    0,   57,    0,
    0,    0,    0,    0,   21,  288,  367,    0,    0,    0,
  395,    0,  406,  425,  449,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,   64,    0,    0,    0,    0,    0,    0,    0,
  480,    0,  500,    0,  512,    0,  528,  535,  542,    0,
  248,    0,   93,    0,  115,   12,   86,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  152,    0,    0,    0,    0,    0,    0,
    0,  236,    0,    0,    0,    0,    0,    0,    0,    0,
  395,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  106,  126,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  251,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -103,    0,  -95,
};
static const short yygindex[] = {                         0,
  161,    0,    0,    0,  -20,   17, -131,    0,    0,   50,
  -93,  114,  -26,  385,    9,  334,  166,    0,    0,  448,
    7,  -18,  192,    0,   19,  365,  -17,  352,  354,  393,
   24,    0,  138,    0,    0,  275,   27,    0,    0,    0,
  243,    0,    0,
};
#define YYTABLESIZE 600
static const short yytable[] = {                         44,
   31,  150,   12,  149,   43,   66,  187,   69,  104,   66,
   75,   69,   77,   78,   86,   78,   66,   46,  197,   74,
   68,   37,   67,   69,   68,   32,   67,   50,   78,   36,
   78,   68,   44,   69,   33,   57,  185,   43,   67,   66,
   36,  110,   59,  105,  119,   12,  138,   76,  130,  120,
  163,  102,   85,  162,   68,   34,   67,  177,   75,   31,
   77,  101,   75,   75,  201,   75,  168,   75,  203,   35,
   85,   24,   12,  129,   24,   46,  133,  144,   46,  101,
   59,   58,  127,  101,   44,   50,   61,   12,   50,   43,
   41,   42,  193,   57,  151,   76,   57,   78,   78,   78,
   78,   78,   78,   78,   86,  202,   70,   78,   31,  119,
  117,  183,  118,   71,  120,   78,   78,   78,   78,   43,
  115,  116,   78,   86,   78,   31,  111,  111,  111,  111,
  111,  107,  111,   84,   75,   75,   32,   75,  192,   75,
  156,  157,  158,  159,  111,  111,   69,  111,   69,   69,
   69,   84,   84,   73,   84,   83,   73,   73,  122,   73,
  104,   73,   13,  136,   69,   69,   70,   69,   70,   70,
   70,  188,  189,   83,   83,  134,   83,   30,  188,  189,
   73,   37,   37,  137,   70,   70,  140,   70,  141,   36,
   36,  166,  167,   75,   75,  105,   75,  152,   75,  154,
  160,  178,    3,  102,  179,  145,  146,  147,  148,  142,
  143,  180,  181,  182,  186,   37,   37,   38,   39,   40,
    4,  199,    5,    6,    7,    8,    9,   10,   41,   42,
  115,  116,   11,   62,   63,   64,   65,   62,   63,   64,
   65,   78,   78,   78,   78,    3,  115,  116,   11,   37,
   38,   39,   40,   30,  196,  200,  115,  116,   37,   31,
    1,   41,   42,    4,   50,    5,    6,    7,    8,    9,
   10,   20,    3,   85,   85,   11,   53,   31,   40,   31,
   31,   31,   31,   31,   31,   31,   31,    3,   54,   31,
    4,   40,    5,    6,    7,    8,    9,   10,  142,  143,
  194,   37,   11,   39,   40,    4,  165,    5,    6,    7,
    8,    9,   10,   41,   42,  142,  143,   11,   78,   78,
   78,   78,   78,   78,  184,   78,   78,  198,  105,  112,
  112,   37,  112,   39,  112,   22,  171,  172,  173,  174,
  175,  176,   47,   41,   42,  184,  105,  111,  111,  111,
  111,  111,  111,  139,   84,   84,   84,   84,   84,   84,
   53,  184,   54,  184,  161,   83,   26,   69,   69,   69,
   69,   69,   69,   51,    0,   60,   83,   83,   83,   83,
   83,   83,    0,   87,    0,   88,    0,   70,   70,   70,
   70,   70,   70,   45,  113,   78,   85,    0,    0,  106,
   47,   55,    0,   47,    0,  108,  109,  102,  110,  110,
    0,  110,    0,  110,    0,    0,   81,    0,   53,    0,
   54,   53,  121,   54,   89,  102,    0,    0,  114,    0,
  128,  131,    0,  132,   51,  103,  111,  111,    0,  111,
    0,  111,    0,   78,    0,    0,   98,  108,  108,    0,
  108,   45,  108,  103,   45,   83,    0,    0,    0,   55,
    0,    0,   55,    0,   98,   99,  109,  109,    0,  109,
    0,  109,    0,   87,   83,   88,    0,   22,    0,    0,
   95,   95,    0,   99,   22,    0,   85,    0,    0,  104,
   74,   74,   87,   74,   88,   74,    0,   22,    0,    0,
    0,  155,  155,  155,  155,   85,   81,  104,   26,  123,
  124,  125,  126,    0,   89,   26,    0,    0,   22,   22,
   63,   75,   75,   63,   75,   81,   75,    0,   26,    0,
    0,    0,   22,   89,   22,    0,   22,    0,    0,  195,
   62,  110,  110,   62,  110,    0,  110,    0,    0,   26,
   26,  106,   59,  111,  111,   59,  111,  153,  111,    0,
    0,    0,    0,   26,    0,   26,    0,   26,   58,  108,
  108,   58,  108,    0,  108,   61,  109,  109,   61,  109,
    0,  109,   60,   74,   74,   60,   74,    0,   74,   95,
   95,    0,   95,   95,   95,   95,   95,   95,    0,   95,
};
static const short yycheck[] = {                         40,
    0,   60,   59,   62,   45,   44,   59,   46,   35,   44,
   31,   46,   31,   44,   32,   46,   44,    9,  125,  125,
   59,  125,   61,   46,   59,   40,   61,    9,   59,  125,
   61,   59,   40,   46,   40,    9,  168,   45,   61,   44,
  259,   40,  259,   35,   42,   59,  125,   31,   67,   47,
   41,   35,   41,   44,   59,   40,   61,  151,   79,   59,
   79,   41,   42,   43,  196,   45,  123,   47,  200,   40,
   59,   41,   59,   67,   44,   67,   70,   41,   70,   59,
  259,   40,   66,   34,   40,   67,   59,   59,   70,   45,
  269,  270,  186,   67,   41,   79,   70,   41,   42,   43,
   44,   45,   46,   47,  122,  199,   61,   44,  123,   42,
   43,  125,   45,   40,   47,   59,   60,   61,   62,   45,
  269,  270,   59,  141,   61,  125,   41,   42,   43,   44,
   45,   59,   47,   41,   42,   43,   40,   45,  125,   47,
  117,  118,  119,  120,   59,   60,   41,   62,   43,   44,
   45,   59,   60,  259,   62,   41,   42,   43,   40,   45,
  187,   47,    2,  123,   59,   60,   41,   62,   43,   44,
   45,  285,  286,   59,   60,  259,   62,  268,  285,  286,
  259,  285,  286,   59,   59,   60,   41,   62,   44,  285,
  286,  142,  143,   42,   43,  187,   45,   59,   47,   41,
   41,  152,  259,  187,   41,  264,  265,  266,  267,  262,
  263,  123,   41,  259,  278,  257,  257,  258,  259,  260,
  277,   41,  279,  280,  281,  282,  283,  284,  269,  270,
  269,  270,  289,  272,  273,  274,  275,  272,  273,  274,
  275,  272,  273,  274,  275,  259,  269,  270,  289,  257,
  258,  259,  260,  268,   58,   58,  269,  270,  257,  259,
    0,  269,  270,  277,   59,  279,  280,  281,  282,  283,
  284,  123,  259,  262,  263,  289,   41,  277,   59,  279,
  280,  281,  282,  283,  284,  285,  286,  259,   41,  289,
  277,   41,  279,  280,  281,  282,  283,  284,  262,  263,
  187,  257,  289,  259,  260,  277,  141,  279,  280,  281,
  282,  283,  284,  269,  270,  262,  263,  289,  262,  263,
  264,  265,  266,  267,  164,  269,  270,  190,   41,   42,
   43,  257,   45,  259,   47,    2,  145,  146,  147,  148,
  149,  150,    9,  269,  270,  185,   59,  262,  263,  264,
  265,  266,  267,   79,  262,  263,  264,  265,  266,  267,
    9,  201,    9,  203,  122,   32,    2,  262,  263,  264,
  265,  266,  267,    9,   -1,   11,  262,  263,  264,  265,
  266,  267,   -1,   32,   -1,   32,   -1,  262,  263,  264,
  265,  266,  267,    9,   43,   31,   32,   -1,   -1,   35,
   67,    9,   -1,   70,   -1,   41,   42,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   32,   -1,   67,   -1,
   67,   70,   58,   70,   32,   59,   -1,   -1,   44,   -1,
   66,   67,   -1,   69,   70,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   79,   -1,   -1,   41,   42,   43,   -1,
   45,   67,   47,   59,   70,  122,   -1,   -1,   -1,   67,
   -1,   -1,   70,   -1,   59,   41,   42,   43,   -1,   45,
   -1,   47,   -1,  122,  141,  122,   -1,  144,   -1,   -1,
   33,   34,   -1,   59,  151,   -1,  122,   -1,   -1,   41,
   42,   43,  141,   45,  141,   47,   -1,  164,   -1,   -1,
   -1,  117,  118,  119,  120,  141,  122,   59,  144,   62,
   63,   64,   65,   -1,  122,  151,   -1,   -1,  185,  186,
   41,   42,   43,   44,   45,  141,   47,   -1,  164,   -1,
   -1,   -1,  199,  141,  201,   -1,  203,   -1,   -1,  188,
   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,  185,
  186,  187,   41,   42,   43,   44,   45,  110,   47,   -1,
   -1,   -1,   -1,  199,   -1,  201,   -1,  203,   41,   42,
   43,   44,   45,   -1,   47,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,  142,
  143,   -1,  145,  146,  147,  148,  149,  150,   -1,  152,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 293
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
"FUNC_CALL","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE",
"FOR","DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT","CASE_LIST",
"CLAXX_BODY","NEW","CLAXX_MEMBER","NONASSOC","IFX","UMINUS",
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
"assign_stmt_value : class_member_stmt",
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
#line 336 "a.y"


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
#line 570 "y.tab.c"

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
#line 99 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 17:
#line 100 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 18:
#line 101 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 19:
#line 106 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 20:
#line 110 "a.y"
	{ yyval.params = NULL; }
break;
case 21:
#line 111 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 22:
#line 115 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 23:
#line 116 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 24:
#line 117 "a.y"
	{ yyval.params = NULL; }
break;
case 25:
#line 121 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 26:
#line 122 "a.y"
	{ yyval.node = NULL; }
break;
case 27:
#line 127 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 28:
#line 128 "a.y"
	{ yyval.node = opr(',' , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 29:
#line 133 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 30:
#line 134 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 31:
#line 139 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 32:
#line 140 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 33:
#line 141 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 34:
#line 145 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 35:
#line 146 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 36:
#line 150 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 37:
#line 151 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 38:
#line 155 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 39:
#line 156 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 40:
#line 161 "a.y"
	{ yyval.node = NULL ; }
break;
case 41:
#line 162 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 42:
#line 163 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 43:
#line 164 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 44:
#line 169 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 45:
#line 170 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 171 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 47:
#line 172 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 173 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 49:
#line 177 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 50:
#line 178 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 51:
#line 179 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 52:
#line 184 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 53:
#line 188 "a.y"
	{ yyval.args = NULL; }
break;
case 54:
#line 189 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 55:
#line 193 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 56:
#line 194 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 57:
#line 198 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 199 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 200 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
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
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 204 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 64:
#line 208 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 65:
#line 209 "a.y"
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
#line 221 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 69:
#line 227 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 70:
#line 228 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 71:
#line 229 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 72:
#line 230 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 73:
#line 235 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 74:
#line 236 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 75:
#line 237 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 76:
#line 238 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 77:
#line 243 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 78:
#line 247 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 79:
#line 251 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 80:
#line 255 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 81:
#line 259 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 82:
#line 263 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 83:
#line 268 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 269 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 85:
#line 274 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 86:
#line 275 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 87:
#line 276 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 88:
#line 277 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 89:
#line 278 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 90:
#line 279 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 91:
#line 280 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 92:
#line 281 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 93:
#line 282 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 94:
#line 287 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 95:
#line 288 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 96:
#line 289 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 97:
#line 290 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 98:
#line 295 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 99:
#line 296 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 100:
#line 297 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 101:
#line 298 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 102:
#line 299 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 103:
#line 300 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 104:
#line 301 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 105:
#line 302 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 106:
#line 303 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 107:
#line 304 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 108:
#line 309 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 109:
#line 310 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 110:
#line 311 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 111:
#line 312 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 112:
#line 313 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 113:
#line 318 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 114:
#line 319 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 115:
#line 323 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 116:
#line 328 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 117:
#line 329 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 118:
#line 330 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 119:
#line 331 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 120:
#line 332 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 121:
#line 333 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1252 "y.tab.c"
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
