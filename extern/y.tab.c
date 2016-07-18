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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 44 "y.tab.c"

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
#define AUTO 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define FOR 273
#define IFX 274
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    5,    5,    2,    2,    2,    2,    2,    2,    2,
    2,    3,    3,    4,    4,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    2,    5,    7,    5,    9,    5,
    4,    3,    1,    2,    1,    1,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,   17,   16,    0,   19,    0,    0,    0,    4,
    0,    0,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,    0,    0,    0,
    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   22,   23,   15,    0,   11,    0,    0,
    0,   10,   14,    0,   13,    0,    8,    0,    0,    0,
    0,   12,    7,    0,    0,    9,
};
static const short yydgoto[] = {                          1,
   12,   65,   66,   57,    2,
};
static const short yysindex[] = {                         0,
    0,   -8,    0,    0,  -37,    0,  -29,  -26,  -23,    0,
   -4,  145,    0, -114,   -4,   -7,   -4,   -4,   -4,  -43,
   21,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,   -4,
   -4,   -4,   -4,   -4,    0,   -8,  404,  -22,   47,   54,
  151,    0,  410,  410,  -12,  -12,  -12,  -12,  404,  -12,
  -12,  -35,  -35,    0,    0,    0,  -40,    0,  -36,  -36,
   -4,    0,    0,   -8,    0, -233,    0,  377,  -32,  -36,
   -4,    0,    0,   61,  -36,    0,
};
static const short yyrindex[] = {                         0,
    0,   39,    0,    0,  383,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   14,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -39,    0,    0,    0,
    0,    0,  -19,  -15,   91,   97,  104,  111,  -31,  117,
  124,   74,   84,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  456,   13,  -54,  -21,    0,
};
#define YYTABLESIZE 677
static const short yytable[] = {                         11,
    6,   34,   16,   11,   34,   67,   33,   11,   36,   30,
   17,   34,   30,   18,   13,   73,   19,   15,   10,   34,
   76,   31,   10,   15,   31,   32,   10,   30,   32,   33,
   31,   11,   32,   38,   34,   11,   58,   70,    1,   31,
    6,    0,   69,   32,    0,    0,    0,    0,   56,    0,
   10,    0,    0,    0,   18,   18,   18,   18,   18,    6,
   18,   42,   33,   31,   28,   32,    0,   34,    0,   63,
    0,    0,   18,   18,    0,   18,   56,    0,    0,    0,
   30,   63,   29,    0,   62,    0,   64,   59,   33,   31,
   28,   32,   72,   34,   60,   33,   31,   28,   32,    0,
   34,   75,   33,   31,   28,   32,   30,   34,   29,    0,
    0,    0,    0,   30,   20,   29,   20,   20,   20,    0,
   30,    0,   29,    0,   21,    6,   21,   21,   21,    0,
    0,   26,   20,   20,   26,   20,    0,   27,    0,    0,
   27,    0,   21,   21,   28,   21,    0,   28,    0,   26,
   26,   29,   26,    0,   29,   27,   27,   24,   27,    0,
   24,    0,   28,   28,   25,   28,    0,   25,    0,   29,
   29,    0,   29,    0,    0,   24,   24,    0,   24,    0,
    0,    0,   25,   25,    0,   25,   33,   31,   28,   32,
    0,   34,   33,   31,   28,   32,    0,   34,    0,    0,
    0,    0,    0,   35,   30,    0,   29,    0,    0,   61,
   30,    0,   29,    0,    0,    0,    3,    4,    5,    6,
    3,    4,    5,    6,    3,    4,    5,    6,    0,    7,
   14,    8,    9,    7,    0,    8,    9,    7,    0,    8,
    9,    0,   31,   31,    0,    0,   32,   32,    3,    4,
    5,    6,    3,    4,   20,    6,    0,    6,    6,    6,
    6,    7,    0,    8,    9,    0,    0,    0,    0,    0,
    6,    0,    6,    6,    0,   18,   18,   18,   18,   18,
   18,    0,   22,   23,   24,   25,   26,   27,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   22,   23,
   24,   25,   26,   27,    0,   22,   23,   24,   25,   26,
   27,    0,   22,   23,   24,   25,   26,   27,    0,    0,
    0,    0,    0,    0,    0,   20,   20,   20,   20,   20,
   20,    0,    0,    0,    0,   21,   21,   21,   21,   21,
   21,    0,   26,   26,   26,   26,   26,   26,   27,   27,
   27,   27,   27,   27,    0,   28,   28,   28,   28,   28,
   28,    0,   29,   29,   29,   29,   29,   29,   24,   24,
   24,   24,   24,   24,    0,   25,   25,   25,   25,   25,
   25,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   22,   23,   24,   25,
   26,   27,   22,   23,   24,   25,   26,   27,   33,   31,
   28,   32,    0,   34,   18,   18,   18,   18,    0,   18,
    0,    0,    0,    0,    0,   71,   30,    0,   29,    0,
    0,   18,   18,    0,   18,   33,   31,    0,   32,    0,
   34,   33,   31,    0,   32,    0,   34,    0,    0,    0,
    0,    0,    0,   30,    0,   29,   21,    0,    0,   30,
   37,   29,   39,   40,   41,    0,    0,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   68,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   74,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   22,   23,
   24,   25,   26,   27,   18,   18,   18,   18,   18,   18,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   22,   23,   24,   25,   26,
   27,    0,    0,   24,   25,   26,   27,
};
static const short yycheck[] = {                         40,
    0,   41,   40,   40,   44,   60,   42,   40,  123,   41,
   40,   47,   44,   40,    2,   70,   40,   61,   59,   59,
   75,   41,   59,   61,   44,   41,   59,   59,   44,   42,
   43,   40,   45,   41,   47,   40,   59,  271,    0,   59,
   40,   -1,   64,   59,   -1,   -1,   -1,   -1,   36,   -1,
   59,   -1,   -1,   -1,   41,   42,   43,   44,   45,   59,
   47,   41,   42,   43,   44,   45,   -1,   47,   -1,   57,
   -1,   -1,   59,   60,   -1,   62,   64,   -1,   -1,   -1,
   60,   69,   62,   -1,  125,   -1,  123,   41,   42,   43,
   44,   45,  125,   47,   41,   42,   43,   44,   45,   -1,
   47,   41,   42,   43,   44,   45,   60,   47,   62,   -1,
   -1,   -1,   -1,   60,   41,   62,   43,   44,   45,   -1,
   60,   -1,   62,   -1,   41,  125,   43,   44,   45,   -1,
   -1,   41,   59,   60,   44,   62,   -1,   41,   -1,   -1,
   44,   -1,   59,   60,   41,   62,   -1,   44,   -1,   59,
   60,   41,   62,   -1,   44,   59,   60,   41,   62,   -1,
   44,   -1,   59,   60,   41,   62,   -1,   44,   -1,   59,
   60,   -1,   62,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   59,   60,   -1,   62,   42,   43,   44,   45,
   -1,   47,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,  257,  258,  259,  260,
  257,  258,  259,  260,  257,  258,  259,  260,   -1,  270,
  268,  272,  273,  270,   -1,  272,  273,  270,   -1,  272,
  273,   -1,  262,  263,   -1,   -1,  262,  263,  257,  258,
  259,  260,  257,  258,  259,  260,   -1,  257,  258,  259,
  260,  270,   -1,  272,  273,   -1,   -1,   -1,   -1,   -1,
  270,   -1,  272,  273,   -1,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,   -1,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  264,  265,  266,  267,  262,  263,
  264,  265,  266,  267,   -1,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  264,  265,  266,  267,  262,  263,
  264,  265,  266,  267,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,  262,  263,  264,  265,  266,  267,   42,   43,
   44,   45,   -1,   47,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   59,   60,   -1,   62,   42,   43,   -1,   45,   -1,
   47,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   60,   -1,   62,   11,   -1,   -1,   60,
   15,   62,   17,   18,   19,   -1,   -1,   22,   23,   24,
   25,   26,   27,   28,   29,   30,   31,   32,   33,   34,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   61,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   71,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
#define YYMAXTOKEN 274
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
"OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","AUTO","IF","ELSE","WHILE",
"FOR","IFX",
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
"statement : VARIABLE FUNC_OP '{' expr_list '}'",
"statement : VARIABLE '(' ')' ';'",
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
#line 94 "a.y"


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
#line 406 "y.tab.c"

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
#line 47 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 51 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 52 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 53 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 7:
#line 54 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 8:
#line 55 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 9:
#line 56 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 10:
#line 57 "a.y"
	{ yyval.node = func(yystack.l_mark[-4].sValue,yystack.l_mark[-1].node);}
break;
case 11:
#line 58 "a.y"
	{ yyval.node = call(yystack.l_mark[-3].sValue); }
break;
case 12:
#line 62 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 13:
#line 63 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 14:
#line 67 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 15:
#line 68 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 16:
#line 73 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 17:
#line 74 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 18:
#line 75 "a.y"
	{ /*printf("VARIABLE $1= %s\n" , $1);*/ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 19:
#line 76 "a.y"
	{ printf("get a string: %s\n" , yystack.l_mark[0].sValue); yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 20:
#line 77 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 21:
#line 78 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 22:
#line 79 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 23:
#line 80 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 24:
#line 81 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 25:
#line 82 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 26:
#line 83 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 27:
#line 84 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 28:
#line 85 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 29:
#line 86 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 30:
#line 87 "a.y"
	{ yyval.node = opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 31:
#line 88 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 32:
#line 89 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 33:
#line 90 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 34:
#line 91 "a.y"
	{ yyval.node = opr('=',2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node ); }
break;
#line 740 "y.tab.c"
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
