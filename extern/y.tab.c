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

#line 14 "a.y"
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
 XArgsList* args;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 45 "y.tab.c"

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
#define VARIABLE 259
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
#define ADD_EQ 271
#define SUB_EQ 272
#define MUL_EQ 273
#define DIV_EQ 274
#define AUTO 275
#define IF 276
#define ELSE 277
#define WHILE 278
#define FOR 279
#define DELETE 280
#define IFX 281
#define UMINUS 282
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   12,   12,    2,    2,    2,    2,    2,    2,    2,
    2,   11,   11,    5,    5,    5,    3,    3,    4,    4,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,   10,   10,    9,    8,    8,    8,    8,
    6,    6,    6,    6,    6,    6,    7,    7,    7,    7,
    7,    7,    7,    7,    7,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    2,    5,    7,    5,    9,    6,
    4,    0,    2,    1,    3,    0,    3,    1,    2,    1,
    1,    1,    1,    1,    2,    1,    3,    3,    3,    1,
    2,    1,    1,    1,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    2,    2,
    3,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,   22,   21,    0,   24,    0,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    2,   32,   33,   26,
   30,    0,   49,   50,    0,    0,    0,    0,    0,    0,
   47,   48,    0,    0,    0,   31,   34,   35,   25,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   39,   40,
   13,    0,   11,    0,    0,    0,   20,    0,    0,   18,
    0,    8,    0,   10,   19,    0,    0,    0,   17,    7,
    0,    0,    9,
};
static const short yydgoto[] = {                          1,
   16,   90,   91,   88,    0,   18,   19,   20,   21,   39,
   57,    2,
};
static const short yysindex[] = {                         0,
    0,   31,    0,    0,   49,    0, -257, -243,   -9,   -4,
    3, -230,  -36,    0,   46,  396,    0,    0,    0,    0,
    0,   10,    0,    0,   46,   46,   46,   46,   46,   11,
    0,    0,   46,   46,   46,    0,    0,    0,    0,  -58,
   77,   46,   46,   46,   46,   46,   46,   46,   46,   46,
   46,   46,   46,   46,    0,   17,  -72,    2,    2,    2,
    2,    2,    4,  101,  108,  417,    0,  450,  450,   12,
   12,   12,   12,    2,   12,   12,   -5,   -5,    0,    0,
    0,   31,    0,  -40,  -40,   46,    0,  -25,   31,    0,
 -212,    0,  423,    0,    0,   16,  -40,   46,    0,    0,
  115,  -40,    0,
};
static const short yyrindex[] = {                         0,
    0,   66,    0,    0,  444,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -56,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -33,  -32,  -31,
  -27,  -19,    0,    0,    0,    0,    0,  -20,   -6,  141,
  148,  165,  187,  -11,  286,  375,  128,  135,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const short yygindex[] = {                         0,
  490,    5,  -79,  -21,    0,    0,    0,    0,   56,    0,
    0,    0,
};
#define YYTABLESIZE 717
static const short yytable[] = {                         15,
    6,   31,   29,   15,   13,   92,   17,   52,   53,   54,
   52,   53,   54,   55,   15,   32,   55,  100,   14,   13,
   28,   51,  103,   28,   51,   52,   53,   54,   36,   27,
   33,   55,   27,   14,   29,   34,   53,   29,   28,   51,
    6,   54,   35,   53,   51,    6,   52,   27,   54,   56,
   82,   63,   29,   53,   51,   15,   52,   81,   54,    6,
   13,   50,   83,   49,   97,    1,   12,   96,   38,    0,
   15,    0,    0,    0,   14,   13,    0,    0,    0,    0,
    0,    0,   89,    0,    0,   15,   87,    0,   30,   14,
   13,    0,   95,   87,    0,    0,    0,    0,    0,   94,
   95,    0,    0,    0,    0,    0,    0,    0,    0,   29,
   23,   23,   23,   23,   23,    0,   23,   67,   53,   51,
   48,   52,    0,   54,    0,    6,    0,    0,   23,   23,
    0,   23,    0,    0,    0,    0,   50,    0,   49,    0,
   99,   84,   53,   51,   48,   52,    0,   54,   85,   53,
   51,   48,   52,    0,   54,  102,   53,   51,   48,   52,
   50,   54,   49,    0,    0,    0,    0,   50,   37,   49,
   37,   37,   37,    0,   50,   38,   49,   38,   38,   38,
    0,   43,    0,    0,   43,    0,   37,   37,   44,   37,
    0,   44,    0,   38,   38,    0,   38,    0,    0,   43,
   43,    0,   43,    0,    0,   45,   44,   44,   45,   44,
   23,   24,   25,   26,   27,   28,    3,    4,    5,    6,
   37,    0,    0,   45,   45,    0,   45,   46,    7,    8,
   46,    3,    4,    5,    6,    9,    0,   10,   11,   12,
    0,   28,   28,    7,    8,   46,   46,    0,   46,    0,
    9,    0,   10,   11,   12,   29,   29,    6,    6,    6,
    6,    0,    0,   42,   43,   44,   45,   46,   47,    6,
    6,    0,    3,    4,    5,    6,    6,    0,    6,    6,
    6,    0,    0,    0,    7,    8,    0,    3,    4,    5,
    6,    9,    0,   10,   11,   12,    0,    0,    0,    7,
    8,    0,    3,    4,   40,    6,    9,    0,   10,   11,
   12,    0,    0,    0,    7,    8,   22,   23,   24,   25,
   26,   27,   28,    0,    0,   12,   41,    0,    0,   41,
    0,   23,   23,   23,   23,   23,   23,    0,   42,   43,
   44,   45,   46,   47,   41,   41,    0,   41,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   42,   43,   44,   45,   46,   47,    0,   42,
   43,   44,   45,   46,   47,    0,   42,   43,   44,   45,
   46,   47,    0,    0,    0,    0,    0,    0,    0,   37,
   37,   37,   37,   37,   37,    0,   38,   38,   38,   38,
   38,   38,   43,   43,   43,   43,   43,   43,    0,   44,
   44,   44,   44,   44,   44,   42,    0,    0,   42,    0,
    0,    0,    0,    0,    0,    0,   45,   45,   45,   45,
   45,   45,    0,   42,   42,    0,   42,   53,   51,   48,
   52,    0,   54,    0,    0,    0,    0,    0,   46,   46,
   46,   46,   46,   46,   55,   50,    0,   49,   53,   51,
   48,   52,    0,   54,   53,   51,   48,   52,    0,   54,
    0,    0,    0,    0,    0,   86,   50,    0,   49,    0,
    0,   98,   50,    0,   49,   23,   23,   23,   23,    0,
   23,   53,   51,    0,   52,    0,   54,    0,    0,    0,
    0,    0,   23,   23,   41,   23,    0,    0,    0,   50,
    0,   49,    0,    0,   58,   59,   60,   61,   62,    0,
    0,    0,   64,   65,   66,    0,    0,    0,    0,    0,
    0,   68,   69,   70,   71,   72,   73,   74,   75,   76,
   77,   78,   79,   80,    0,    0,    0,   41,   41,   41,
   41,   41,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   93,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  101,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   42,   42,   42,   42,
   42,   42,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   43,   44,
   45,   46,   47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   42,   43,
   44,   45,   46,   47,   42,   43,   44,   45,   46,   47,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,   23,   23,   23,   23,
   23,    0,    0,   44,   45,   46,   47,
};
static const short yycheck[] = {                         40,
    0,  259,   61,   40,   45,   85,    2,   41,   41,   41,
   44,   44,   44,   41,   40,  259,   44,   97,   59,   45,
   41,   41,  102,   44,   44,   59,   59,   59,  259,   41,
   40,   59,   44,   59,   41,   40,   42,   44,   59,   59,
   40,   47,   40,   42,   43,   45,   45,   59,   47,   40,
  123,   41,   59,   42,   43,   40,   45,   41,   47,   59,
   45,   60,   59,   62,  277,    0,  123,   89,   13,   -1,
   40,   -1,   -1,   -1,   59,   45,   -1,   -1,   -1,   -1,
   -1,   -1,  123,   -1,   -1,   40,   82,   -1,   40,   59,
   45,   -1,   88,   89,   -1,   -1,   -1,   -1,   -1,  125,
   96,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   61,
   41,   42,   43,   44,   45,   -1,   47,   41,   42,   43,
   44,   45,   -1,   47,   -1,  125,   -1,   -1,   59,   60,
   -1,   62,   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,
  125,   41,   42,   43,   44,   45,   -1,   47,   41,   42,
   43,   44,   45,   -1,   47,   41,   42,   43,   44,   45,
   60,   47,   62,   -1,   -1,   -1,   -1,   60,   41,   62,
   43,   44,   45,   -1,   60,   41,   62,   43,   44,   45,
   -1,   41,   -1,   -1,   44,   -1,   59,   60,   41,   62,
   -1,   44,   -1,   59,   60,   -1,   62,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   41,   59,   60,   44,   62,
  269,  270,  271,  272,  273,  274,  257,  258,  259,  260,
  257,   -1,   -1,   59,   60,   -1,   62,   41,  269,  270,
   44,  257,  258,  259,  260,  276,   -1,  278,  279,  280,
   -1,  262,  263,  269,  270,   59,   60,   -1,   62,   -1,
  276,   -1,  278,  279,  280,  262,  263,  257,  258,  259,
  260,   -1,   -1,  262,  263,  264,  265,  266,  267,  269,
  270,   -1,  257,  258,  259,  260,  276,   -1,  278,  279,
  280,   -1,   -1,   -1,  269,  270,   -1,  257,  258,  259,
  260,  276,   -1,  278,  279,  280,   -1,   -1,   -1,  269,
  270,   -1,  257,  258,  259,  260,  276,   -1,  278,  279,
  280,   -1,   -1,   -1,  269,  270,  268,  269,  270,  271,
  272,  273,  274,   -1,   -1,  280,   41,   -1,   -1,   44,
   -1,  262,  263,  264,  265,  266,  267,   -1,  262,  263,
  264,  265,  266,  267,   59,   60,   -1,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,  262,
  263,  264,  265,  266,  267,   -1,  262,  263,  264,  265,
  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,  266,  267,   -1,  262,  263,  264,  265,
  266,  267,  262,  263,  264,  265,  266,  267,   -1,  262,
  263,  264,  265,  266,  267,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,   -1,   59,   60,   -1,   62,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,   59,   60,   -1,   62,   42,   43,
   44,   45,   -1,   47,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   59,   60,   -1,   62,   42,   43,   44,   45,   -1,
   47,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   59,   60,   15,   62,   -1,   -1,   -1,   60,
   -1,   62,   -1,   -1,   25,   26,   27,   28,   29,   -1,
   -1,   -1,   33,   34,   35,   -1,   -1,   -1,   -1,   -1,
   -1,   42,   43,   44,   45,   46,   47,   48,   49,   50,
   51,   52,   53,   54,   -1,   -1,   -1,  262,  263,  264,
  265,  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   86,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   98,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,
  265,  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,  262,  263,  264,  265,  266,  267,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,  264,  265,  266,  267,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"TDOUBLE","TBOOL","VARIABLE","TSTRING","OP_CALC","AND_OP",
"OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP","ADD_EQ",
"SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE","FOR","DELETE","IFX",
"UMINUS",
};
static const char *yyrule[] = {
"$accept : program",
"program : statement_list",
"statement_list : statement_list statement",
"statement_list :",
"statement : ';'",
"statement : expr ';'",
"statement : IF '(' expr ')' block",
"statement : IF '(' expr ')' block ELSE block",
"statement : WHILE '(' expr ')' block",
"statement : FOR '(' expr ';' expr ';' expr ')' block",
"statement : VARIABLE FUNC_OP param_list '{' expr_list '}'",
"statement : VARIABLE '(' ')' ';'",
"param_list :",
"param_list : '(' ')'",
"args_list : expr",
"args_list : expr ',' expr",
"args_list :",
"block : '{' expr_list '}'",
"block : statement",
"expr_list : expr_list statement",
"expr_list : statement",
"expr : TBOOL",
"expr : TDOUBLE",
"expr : VARIABLE",
"expr : TSTRING",
"expr : '-' double_or_ps_expr",
"expr : arithmetic_expr",
"expr : expr ',' expr",
"expr : expr AND_OP expr",
"expr : expr OR_OP expr",
"expr : parentheses_expr",
"expr : DELETE VARIABLE",
"expr : bool_expr",
"expr : assign_expr",
"double_or_ps_expr : TDOUBLE",
"double_or_ps_expr : parentheses_expr",
"parentheses_expr : '(' expr ')'",
"arithmetic_expr : expr '+' expr",
"arithmetic_expr : expr '-' expr",
"arithmetic_expr : expr '*' expr",
"arithmetic_expr : expr '/' expr",
"bool_expr : expr '>' expr",
"bool_expr : expr '<' expr",
"bool_expr : expr LE_OP expr",
"bool_expr : expr GE_OP expr",
"bool_expr : expr EQ_OP expr",
"bool_expr : expr NE_OP expr",
"assign_expr : INC_OP VARIABLE",
"assign_expr : DEC_OP VARIABLE",
"assign_expr : VARIABLE INC_OP",
"assign_expr : VARIABLE DEC_OP",
"assign_expr : VARIABLE '=' expr",
"assign_expr : VARIABLE ADD_EQ expr",
"assign_expr : VARIABLE SUB_EQ expr",
"assign_expr : VARIABLE MUL_EQ expr",
"assign_expr : VARIABLE DIV_EQ expr",

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
#line 143 "a.y"


void yyerror(char *s) {
 fprintf(stderr, "%s\n", s);
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
#line 460 "y.tab.c"

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
#line 52 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 56 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 57 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 58 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 7:
#line 59 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 8:
#line 60 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 9:
#line 61 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 10:
#line 62 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].args,yystack.l_mark[-1].node);}
break;
case 11:
#line 63 "a.y"
	{ yyval.node = call(yystack.l_mark[-3].sValue ); }
break;
case 12:
#line 67 "a.y"
	{ yyval.args = NULL; }
break;
case 13:
#line 68 "a.y"
	{ yyval.args = NULL; }
break;
case 14:
#line 72 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 15:
#line 73 "a.y"
	{ opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 16:
#line 74 "a.y"
	{ yyval.node = NULL; }
break;
case 17:
#line 78 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 18:
#line 79 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 19:
#line 83 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 20:
#line 84 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 21:
#line 89 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 22:
#line 90 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 23:
#line 91 "a.y"
	{ /*printf("VARIABLE $1= %s\n" , $1);*/ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 24:
#line 92 "a.y"
	{ printf("get a string: %s\n" , yystack.l_mark[0].sValue); yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 25:
#line 93 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 26:
#line 94 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 27:
#line 95 "a.y"
	{ yyval.node = opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 28:
#line 96 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 29:
#line 97 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 30:
#line 98 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 31:
#line 99 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[0].sValue ); }
break;
case 32:
#line 100 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 33:
#line 101 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 34:
#line 106 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 35:
#line 107 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 36:
#line 111 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 37:
#line 116 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 38:
#line 117 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 39:
#line 118 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 40:
#line 119 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 41:
#line 123 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 42:
#line 124 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 43:
#line 125 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 44:
#line 126 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 45:
#line 127 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 46:
#line 128 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 47:
#line 132 "a.y"
	{ yyval.node = opr(INC_OP,1, var(yystack.l_mark[0].sValue) ); }
break;
case 48:
#line 133 "a.y"
	{ yyval.node = opr(DEC_OP,1, var(yystack.l_mark[0].sValue) ); }
break;
case 49:
#line 134 "a.y"
	{ yyval.node = opr(INC_OP,1, var(yystack.l_mark[-1].sValue) ); }
break;
case 50:
#line 135 "a.y"
	{ yyval.node = opr(DEC_OP,1, var(yystack.l_mark[-1].sValue) ); }
break;
case 51:
#line 136 "a.y"
	{ yyval.node = opr('=',2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node ); }
break;
case 52:
#line 137 "a.y"
	{ yyval.node = opr(ADD_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 53:
#line 138 "a.y"
	{ yyval.node = opr(SUB_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 54:
#line 139 "a.y"
	{ yyval.node = opr(MUL_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 55:
#line 140 "a.y"
	{ yyval.node = opr(DIV_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
#line 878 "y.tab.c"
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
