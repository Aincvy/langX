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
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    7,    7,    2,    2,    2,    2,    2,    2,    2,
    2,    6,    6,    5,    5,    5,    3,    3,    4,    4,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    2,    5,    7,    5,    9,    6,
    4,    0,    2,    1,    3,    0,    3,    1,    2,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    3,
    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,   22,   21,    0,   24,    0,    0,    0,    0,
    4,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   39,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   38,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   27,   28,   13,    0,   11,    0,
    0,    0,   20,    0,    0,   18,    0,    8,    0,   10,
   19,    0,    0,    0,   17,    7,    0,    0,    9,
};
static const short yydgoto[] = {                          1,
   13,   76,   77,   74,    0,   43,    2,
};
static const short yysindex[] = {                         0,
    0,  -25,    0,    0,   -2,    0,  -17,  -12,   -7, -223,
    0,    5,  361,    0,    3,    5,    5,    5,    5,    5,
   -4,    5,    5,    5,    0,  -59,   32,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    0,    6,  -77,  415,  415,  415,  415,  415,  -11,   55,
   62,  367,    0,  421,  421,   -3,   -3,   -3,   -3,  415,
   -3,   -3,  -22,  -22,    0,    0,    0,  -25,    0,  -40,
  -40,    5,    0,  -35,  -25,    0, -228,    0,  388,    0,
    0,  -30,  -40,    5,    0,    0,   69,  -40,    0,
};
static const short yyrindex[] = {                         0,
    0,   50,    0,    0,  394,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -72,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -38,  -37,  -33,  -32,  -28,    0,    0,
    0,    0,    0,   12,   21,  101,  109,  115,  121,  -27,
  129,  135,   89,   95,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  468,   53,  -53,  -23,    0,    0,    0,
};
#define YYTABLESIZE 688
static const short yytable[] = {                         12,
    6,   20,   40,   41,   12,   40,   41,   42,   43,   12,
   42,   43,   44,   35,   12,   44,   35,   78,   11,   39,
   40,   41,   22,   11,   40,   42,   43,   23,   11,   86,
   44,   35,   24,   11,   89,   25,   49,   21,   39,   37,
    6,   38,   42,   40,   12,   68,   67,   69,   83,    1,
   12,   82,   36,    0,   14,   36,    0,    0,   20,    6,
    0,   37,    0,    0,   37,   23,   23,   23,   23,   23,
   36,   23,   53,   39,   37,   34,   38,    0,   40,   37,
    0,    0,   75,   23,   23,    0,   23,    0,    0,   80,
    0,   36,    0,   35,   85,   70,   39,   37,   34,   38,
    0,   40,   71,   39,   37,   34,   38,    0,   40,   88,
   39,   37,   34,   38,   36,   40,   35,    0,    0,    0,
   73,   36,    0,   35,    0,    6,   81,   73,   36,   25,
   35,   25,   25,   25,   81,   26,    0,   26,   26,   26,
    0,   31,    0,    0,   31,    0,    0,   25,   25,   32,
   25,    0,   32,   26,   26,   33,   26,    0,   33,   31,
   31,   34,   31,    0,   34,    0,    0,   32,   32,   29,
   32,    0,   29,   33,   33,   30,   33,    0,   30,   34,
   34,    0,   34,    0,    0,    0,    0,   29,   29,    0,
   29,    0,    0,   30,   30,    0,   30,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   16,   17,   18,   19,    0,    3,    4,    5,    6,
    0,    3,    4,    5,    6,    0,    3,    4,    5,    6,
    0,    3,    4,    5,    6,    7,    0,    8,    9,   10,
    7,    0,    8,    9,   10,    7,    0,    8,    9,   10,
    7,    0,    8,    9,   10,    0,    0,    6,    6,    6,
    6,    3,    4,   26,    6,   15,    0,    0,   16,   17,
   18,   19,    0,   36,   36,    0,    6,    0,    6,    6,
    6,    0,   37,   37,   10,    0,   23,   23,   23,   23,
   23,   23,    0,   28,   29,   30,   31,   32,   33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   28,   29,   30,   31,
   32,   33,    0,   28,   29,   30,   31,   32,   33,    0,
   28,   29,   30,   31,   32,   33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   25,   25,   25,   25,   25,   25,   26,   26,   26,   26,
   26,   26,   31,   31,   31,   31,   31,   31,    0,    0,
   32,   32,   32,   32,   32,   32,   33,   33,   33,   33,
   33,   33,   34,   34,   34,   34,   34,   34,    0,    0,
   29,   29,   29,   29,   29,   29,   30,   30,   30,   30,
   30,   30,   39,   37,   34,   38,    0,   40,   39,   37,
   34,   38,    0,   40,    0,    0,    0,    0,    0,   41,
   36,    0,   35,    0,    0,   72,   36,    0,   35,   39,
   37,   34,   38,    0,   40,   23,   23,   23,   23,    0,
   23,    0,    0,    0,    0,    0,   84,   36,    0,   35,
    0,    0,   23,   23,    0,   23,   39,   37,    0,   38,
    0,   40,   39,   37,    0,   38,    0,   40,    0,    0,
    0,    0,    0,    0,   36,    0,   35,    0,    0,   27,
   36,    0,   35,   44,   45,   46,   47,   48,    0,   50,
   51,   52,    0,    0,    0,   54,   55,   56,   57,   58,
   59,   60,   61,   62,   63,   64,   65,   66,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,   29,   30,   31,   32,   33,   28,   29,
   30,   31,   32,   33,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   28,
   29,   30,   31,   32,   33,   23,   23,   23,   23,   23,
   23,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   28,   29,   30,   31,
   32,   33,    0,    0,   30,   31,   32,   33,
};
static const short yycheck[] = {                         40,
    0,   61,   41,   41,   40,   44,   44,   41,   41,   40,
   44,   44,   41,   41,   40,   44,   44,   71,   59,   42,
   59,   59,   40,   59,   47,   59,   59,   40,   59,   83,
   59,   59,   40,   59,   88,  259,   41,   40,   42,   43,
   40,   45,   40,   47,   40,  123,   41,   59,  277,    0,
  123,   75,   41,   -1,    2,   44,   -1,   -1,   61,   59,
   -1,   41,   -1,   -1,   44,   41,   42,   43,   44,   45,
   59,   47,   41,   42,   43,   44,   45,   -1,   47,   59,
   -1,   -1,  123,   59,   60,   -1,   62,   -1,   -1,  125,
   -1,   60,   -1,   62,  125,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   60,   47,   62,   -1,   -1,   -1,
   68,   60,   -1,   62,   -1,  125,   74,   75,   60,   41,
   62,   43,   44,   45,   82,   41,   -1,   43,   44,   45,
   -1,   41,   -1,   -1,   44,   -1,   -1,   59,   60,   41,
   62,   -1,   44,   59,   60,   41,   62,   -1,   44,   59,
   60,   41,   62,   -1,   44,   -1,   -1,   59,   60,   41,
   62,   -1,   44,   59,   60,   41,   62,   -1,   44,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,  272,  273,  274,   -1,  257,  258,  259,  260,
   -1,  257,  258,  259,  260,   -1,  257,  258,  259,  260,
   -1,  257,  258,  259,  260,  276,   -1,  278,  279,  280,
  276,   -1,  278,  279,  280,  276,   -1,  278,  279,  280,
  276,   -1,  278,  279,  280,   -1,   -1,  257,  258,  259,
  260,  257,  258,  259,  260,  268,   -1,   -1,  271,  272,
  273,  274,   -1,  262,  263,   -1,  276,   -1,  278,  279,
  280,   -1,  262,  263,  280,   -1,  262,  263,  264,  265,
  266,  267,   -1,  262,  263,  264,  265,  266,  267,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,   -1,  262,  263,  264,  265,  266,  267,   -1,
  262,  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,  266,  267,  262,  263,  264,  265,
  266,  267,  262,  263,  264,  265,  266,  267,   -1,   -1,
  262,  263,  264,  265,  266,  267,  262,  263,  264,  265,
  266,  267,  262,  263,  264,  265,  266,  267,   -1,   -1,
  262,  263,  264,  265,  266,  267,  262,  263,  264,  265,
  266,  267,   42,   43,   44,   45,   -1,   47,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   59,   60,   -1,   62,   42,
   43,   44,   45,   -1,   47,   42,   43,   44,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,
   -1,   -1,   59,   60,   -1,   62,   42,   43,   -1,   45,
   -1,   47,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,   12,
   60,   -1,   62,   16,   17,   18,   19,   20,   -1,   22,
   23,   24,   -1,   -1,   -1,   28,   29,   30,   31,   32,
   33,   34,   35,   36,   37,   38,   39,   40,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   72,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   84,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,  266,  267,  262,  263,
  264,  265,  266,  267,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,  266,  267,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,   -1,   -1,  264,  265,  266,  267,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 281
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
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '>' expr",
"expr : expr '<' expr",
"expr : expr LE_OP expr",
"expr : expr GE_OP expr",
"expr : expr EQ_OP expr",
"expr : expr NE_OP expr",
"expr : expr ',' expr",
"expr : expr AND_OP expr",
"expr : expr OR_OP expr",
"expr : '(' expr ')'",
"expr : DELETE VARIABLE",
"expr : VARIABLE ADD_EQ expr",
"expr : VARIABLE SUB_EQ expr",
"expr : VARIABLE MUL_EQ expr",
"expr : VARIABLE DIV_EQ expr",
"expr : VARIABLE '=' expr",

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
#line 114 "a.y"


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
		printf("file %s not found.\n" , argv[0]);
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
#line 431 "y.tab.c"

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
#line 51 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 55 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 56 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 57 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 7:
#line 58 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 8:
#line 59 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 9:
#line 60 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 10:
#line 61 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].args,yystack.l_mark[-1].node);}
break;
case 11:
#line 62 "a.y"
	{ yyval.node = call(yystack.l_mark[-3].sValue ); }
break;
case 12:
#line 66 "a.y"
	{ yyval.args = NULL; }
break;
case 13:
#line 67 "a.y"
	{ yyval.args = NULL; }
break;
case 14:
#line 71 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 15:
#line 72 "a.y"
	{ opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 16:
#line 73 "a.y"
	{ yyval.node = NULL; }
break;
case 17:
#line 77 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 18:
#line 78 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 19:
#line 82 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 20:
#line 83 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 21:
#line 88 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 22:
#line 89 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 23:
#line 90 "a.y"
	{ /*printf("VARIABLE $1= %s\n" , $1);*/ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 24:
#line 91 "a.y"
	{ printf("get a string: %s\n" , yystack.l_mark[0].sValue); yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 25:
#line 92 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 26:
#line 93 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 27:
#line 94 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 28:
#line 95 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 29:
#line 96 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 30:
#line 97 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 31:
#line 98 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 32:
#line 99 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 33:
#line 100 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 34:
#line 101 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 35:
#line 102 "a.y"
	{ yyval.node = opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 36:
#line 103 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 37:
#line 104 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 38:
#line 105 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 39:
#line 106 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[0].sValue ); }
break;
case 40:
#line 107 "a.y"
	{ yyval.node = opr(ADD_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 41:
#line 108 "a.y"
	{ yyval.node = opr(SUB_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 42:
#line 109 "a.y"
	{ yyval.node = opr(MUL_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 43:
#line 110 "a.y"
	{ yyval.node = opr(DIV_EQ,2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node);}
break;
case 44:
#line 111 "a.y"
	{ yyval.node = opr('=',2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node ); }
break;
#line 805 "y.tab.c"
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
