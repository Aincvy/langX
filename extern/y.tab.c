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
   21,   21,   21,   21,   21,   21,   20,   20,   20,   20,
   20,   22,   22,   38,   13,   13,   13,   13,   13,   13,
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
    1,    3,    3,    3,    1,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,   49,    0,    0,
    0,    4,    2,    5,    6,    0,    8,    9,   29,   30,
   44,   45,  115,   47,   48,    0,   10,    0,  116,    0,
    0,    0,    0,    0,    0,    0,   80,   79,    0,   82,
    0,    0,    0,    0,    0,    0,    0,   73,   51,  106,
    0,  100,    0,    0,    0,    0,    0,   78,    0,    7,
    0,    0,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,   11,   18,   16,    0,    0,    0,   13,    0,
  111,    0,   55,    0,   57,    0,    0,    0,    0,    0,
    0,    0,  109,    0,    0,    0,  107,  108,   74,    0,
   42,    0,   41,   43,    0,   46,   94,   95,    0,   81,
   67,   66,    0,   96,   97,    0,    0,    0,    0,    0,
    0,  117,  118,  119,  120,   28,    0,  112,  113,    0,
   15,  114,   22,    0,   26,   17,   12,   14,   52,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   76,   75,    0,    0,   71,   72,    0,    0,
    0,   21,    0,   56,   92,   93,   26,   65,    0,   88,
   89,   90,   91,   86,   87,   38,    0,   68,    0,   77,
   23,   19,   25,    0,    0,    0,    0,    0,    0,   34,
   64,   32,    0,    0,   26,   33,   35,    0,   26,    0,
   39,    0,
};
static const short yydgoto[] = {                          1,
  168,   14,   15,   16,   17,   18,  163,   19,   20,   91,
  169,  102,   21,   92,   81,   93,   83,  110,  111,   48,
   49,   23,   95,   24,   25,   96,   52,   97,   98,   99,
   56,  189,  190,   27,   78,   79,   28,   29,   71,  134,
   89,   90,    2,
};
static const short yysindex[] = {                         0,
    0,   29,  -20,  -14,   31,   41, -194,    0,  -40,   47,
 -182,    0,    0,    0,    0,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -34,    0,   44,    0,   69,
 -118,   -7,   45,   45, -162,   55,    0,    0,   82,    0,
 -182, -182,  -10,   45,    0,    0,    0,    0,    0,    0,
 -219,    0,    0,    0,    0,   68, -182,    0,   83,    0,
   75,   75,   75,   75, -182,  -40,    0, -182,  -40, -127,
   19, -131,    0,    0,    0,   84,  -16,  -83,    0,    0,
    0,    0,    0, -219,    0,    0,    0,    0,  113,  117,
   -4,    0,    0,    0,  -51, -219,    0,    0,    0,   37,
    0,  100,    0,    0,  -38,    0,    0,    0,   75,    0,
    0,    0,  131,    0,    0,   45,   45,   45,   45,  132,
   -7,    0,    0,    0,    0,    0,   15,    0,    0,  -59,
    0,    0,    0,   52,    0,    0,    0,    0,    0,   -7,
   45,   45,  -56,   45,   45,   45,   45,   45,   45,  -56,
   45,  139,    0,    0,    7,    7,    0,    0,   58,  148,
  -66,    0,  -13,    0,    0,    0,    0,    0,  -77,    0,
    0,    0,    0,    0,    0,    0,  -55,    0, -228,    0,
    0,    0,    0,   14,  -56, -162,  -53,  147, -107,    0,
    0,    0,  165,  151,    0,    0,    0,  -56,    0,   29,
    0,   29,
};
static const short yyrindex[] = {                         0,
    0,  212,  -30,    0,    0,    0,    0,    0,  195,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  138,
    0,  214,    0,    0,  206,    0,    0,    0,   57,    0,
    0,    0,    0,    0,   21,  368,  397,    0,    0,    0,
  417,    0,  440,  493,  512,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   80,
    0,   25,    0,    0,    0,    0,    0,    0,    0,  155,
    0,  545,    0,  552,    0,  559,  566,  573,    0,  231,
    0,   93,    0,  115,   -6,   86,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  232,    0,    0,    0,    0,    0,    0,    0,
  214,    0,    0,    0,    0,    0,    0,    0,    0,  417,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  106,  126,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  248,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -103,
    0,  -91,
};
static const short yygindex[] = {                         0,
  162,    0,    0,    0,   13,    5, -143,    0,    0,  188,
 -137,  121,    4,  405,    6,  329,  152,    0,    0,  434,
  118,   16,  477,    0,   10,  365,  -15,  385,   23,  354,
  224,    0,  112,    0,    0,  238,    0,    0,    0,    0,
  196,    0,    0,
};
#define YYTABLESIZE 626
static const short yytable[] = {                         44,
   31,   66,   12,  186,   43,   65,   73,   68,  149,   65,
  148,   68,  176,   78,   46,   78,   85,  196,   50,   32,
   67,   37,   66,  184,   67,   33,   66,   65,   78,  109,
   78,   54,   44,   36,   85,   75,  143,   43,  103,  101,
  104,  137,   67,   74,   66,   12,   76,  192,  118,  114,
  115,  200,   85,  119,   87,  202,  187,  188,   65,   31,
  201,  101,   75,   75,   36,   75,  167,   75,   78,  126,
   34,   46,   12,   67,   46,   50,   58,  150,   50,  101,
   35,  129,   75,   78,   44,   78,   57,   12,   54,   43,
   74,   54,  162,   76,   60,  161,   58,   78,   78,   78,
   78,   78,   31,   78,   69,   85,   41,   42,   70,  118,
  116,  182,  117,  106,  119,   78,   78,   78,   78,   43,
   24,   32,  121,   24,   85,   31,  110,  110,  110,  110,
  110,  133,  110,   84,   75,   75,   30,   75,  191,   75,
   72,  135,  136,   87,  110,  110,   69,  110,   69,   69,
   69,   84,   84,  139,   84,   83,   73,   73,  151,   73,
  140,   73,   87,   13,   69,   69,   70,   69,   70,   70,
   70,  153,  159,   83,   83,   72,   83,  187,  188,  178,
  179,   37,   37,  128,   70,   70,  132,   70,  180,  103,
  101,  104,  181,   36,   36,   63,   75,   75,   63,   75,
  185,   75,    3,   37,  195,  198,  141,  142,  199,  114,
  115,    1,  144,  145,  146,  147,   37,   38,   39,   40,
    4,  100,    5,    6,    7,    8,    9,   10,   41,   42,
  114,  115,   11,   61,   62,   63,   64,   61,   62,   63,
   64,   78,   78,   78,   78,    3,   37,   30,   11,   37,
   38,   39,   40,   50,   53,   85,   85,  141,  142,   31,
   20,   41,   42,    4,   40,    5,    6,    7,    8,    9,
   10,   54,    3,   75,   75,   11,   75,   31,   75,   31,
   31,   31,   31,   31,   31,   31,   31,    3,   40,   31,
    4,  164,    5,    6,    7,    8,    9,   10,  141,  142,
  197,   37,   11,   39,   40,    4,  193,    5,    6,    7,
    8,    9,   10,   41,   42,  138,  160,   11,   78,   78,
   78,   78,   78,   78,  183,   78,   78,    0,  165,  166,
   22,   37,    0,   39,    0,    0,    0,   47,  177,  155,
  156,  157,  158,   41,   42,  183,    0,  110,  110,  110,
  110,  110,  110,    0,   84,   84,   84,   84,   84,   84,
   82,  183,   55,  183,    0,    0,   26,   69,   69,   69,
   69,   69,   69,   51,    0,   59,   83,   83,   83,   83,
   83,   83,    0,    0,    0,   88,    0,   70,   70,   70,
   70,   70,   70,   53,   47,   77,   84,   47,    0,  105,
    0,    0,    0,    0,    0,  107,  108,    0,  105,  111,
  111,    0,  111,   45,  111,    0,   86,    0,    0,   55,
    0,  120,   55,    0,    0,    0,  105,  112,    0,  127,
  130,    0,  131,   51,    0,    0,   80,  102,  109,  109,
    0,  109,   77,  109,    0,    0,    0,    0,  113,   82,
   53,    0,    0,   53,    0,  102,    0,  103,  110,  110,
    0,  110,    0,  110,    0,    0,   94,   94,   82,    0,
   45,   22,    0,   45,   88,  103,    0,    0,   22,    0,
   98,  107,  107,    0,  107,   84,  107,    0,    0,    0,
    0,   22,    0,   88,  122,  123,  124,  125,   98,    0,
    0,    0,    0,    0,   84,   86,    0,   26,    0,    0,
    0,    0,   22,   22,   26,    0,    0,    0,    0,    0,
  154,  154,  154,  154,   86,   80,   22,   26,   22,    0,
   22,    0,    0,   99,  108,  108,    0,  108,    0,  108,
    0,    0,  152,    0,   80,    0,    0,    0,   26,   26,
  105,   99,  104,   74,   74,    0,   74,    0,   74,    0,
    0,    0,   26,    0,   26,    0,   26,    0,    0,    0,
  104,  194,    0,    0,   94,   94,    0,   94,   94,   94,
   94,   94,   94,    0,   94,   62,  109,  109,   62,  109,
    0,  109,   59,  110,  110,   59,  110,    0,  110,   58,
  107,  107,   58,  107,    0,  107,   61,  108,  108,   61,
  108,    0,  108,   60,   74,   74,   60,   74,    0,   74,
  170,  171,  172,  173,  174,  175,
};
static const short yycheck[] = {                         40,
    0,   61,   59,   59,   45,   44,  125,   46,   60,   44,
   62,   46,  150,   44,    9,   46,   32,  125,    9,   40,
   59,  125,   61,  167,   59,   40,   61,   44,   59,   40,
   61,    9,   40,  125,   41,   31,   41,   45,   35,   35,
   35,  125,   59,   31,   61,   59,   31,  185,   42,  269,
  270,  195,   59,   47,   32,  199,  285,  286,   44,   59,
  198,   41,   42,   43,  259,   45,  123,   47,   44,   65,
   40,   66,   59,   59,   69,   66,  259,   41,   69,   59,
   40,   66,   78,   59,   40,   61,   40,   59,   66,   45,
   78,   69,   41,   78,   59,   44,  259,   41,   42,   43,
   44,   45,  123,   47,   61,  121,  269,  270,   40,   42,
   43,  125,   45,   59,   47,   59,   60,   61,   62,   45,
   41,   40,   40,   44,  140,  125,   41,   42,   43,   44,
   45,  259,   47,   41,   42,   43,  268,   45,  125,   47,
  259,  123,   59,  121,   59,   60,   41,   62,   43,   44,
   45,   59,   60,   41,   62,   41,   42,   43,   59,   45,
   44,   47,  140,    2,   59,   60,   41,   62,   43,   44,
   45,   41,   41,   59,   60,  259,   62,  285,  286,   41,
  123,  285,  286,   66,   59,   60,   69,   62,   41,  186,
  186,  186,  259,  285,  286,   41,   42,   43,   44,   45,
  278,   47,  259,  257,   58,   41,  262,  263,   58,  269,
  270,    0,  264,  265,  266,  267,  257,  258,  259,  260,
  277,   34,  279,  280,  281,  282,  283,  284,  269,  270,
  269,  270,  289,  272,  273,  274,  275,  272,  273,  274,
  275,  272,  273,  274,  275,  259,  257,  268,  289,  257,
  258,  259,  260,   59,   41,  262,  263,  262,  263,  259,
  123,  269,  270,  277,   59,  279,  280,  281,  282,  283,
  284,   41,  259,   42,   43,  289,   45,  277,   47,  279,
  280,  281,  282,  283,  284,  285,  286,  259,   41,  289,
  277,  140,  279,  280,  281,  282,  283,  284,  262,  263,
  189,  257,  289,  259,  260,  277,  186,  279,  280,  281,
  282,  283,  284,  269,  270,   78,  121,  289,  262,  263,
  264,  265,  266,  267,  163,  269,  270,   -1,  141,  142,
    2,  257,   -1,  259,   -1,   -1,   -1,    9,  151,  116,
  117,  118,  119,  269,  270,  184,   -1,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
   32,  200,    9,  202,   -1,   -1,    2,  262,  263,  264,
  265,  266,  267,    9,   -1,   11,  262,  263,  264,  265,
  266,  267,   -1,   -1,   -1,   32,   -1,  262,  263,  264,
  265,  266,  267,    9,   66,   31,   32,   69,   -1,   35,
   -1,   -1,   -1,   -1,   -1,   41,   42,   -1,   41,   42,
   43,   -1,   45,    9,   47,   -1,   32,   -1,   -1,   66,
   -1,   57,   69,   -1,   -1,   -1,   59,   43,   -1,   65,
   66,   -1,   68,   69,   -1,   -1,   32,   41,   42,   43,
   -1,   45,   78,   47,   -1,   -1,   -1,   -1,   44,  121,
   66,   -1,   -1,   69,   -1,   59,   -1,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   33,   34,  140,   -1,
   66,  143,   -1,   69,  121,   59,   -1,   -1,  150,   -1,
   41,   42,   43,   -1,   45,  121,   47,   -1,   -1,   -1,
   -1,  163,   -1,  140,   61,   62,   63,   64,   59,   -1,
   -1,   -1,   -1,   -1,  140,  121,   -1,  143,   -1,   -1,
   -1,   -1,  184,  185,  150,   -1,   -1,   -1,   -1,   -1,
  116,  117,  118,  119,  140,  121,  198,  163,  200,   -1,
  202,   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,  109,   -1,  140,   -1,   -1,   -1,  184,  185,
  186,   59,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,  198,   -1,  200,   -1,  202,   -1,   -1,   -1,
   59,  187,   -1,   -1,  141,  142,   -1,  144,  145,  146,
  147,  148,  149,   -1,  151,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,   41,   42,   43,   44,
   45,   -1,   47,   41,   42,   43,   44,   45,   -1,   47,
  144,  145,  146,  147,  148,  149,
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
#line 335 "a.y"


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
#line 573 "y.tab.c"

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
#line 308 "a.y"
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
#line 317 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 113:
#line 318 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 114:
#line 322 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 115:
#line 327 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 116:
#line 328 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 117:
#line 329 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 118:
#line 330 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 119:
#line 331 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 120:
#line 332 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1251 "y.tab.c"
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
