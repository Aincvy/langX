#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 1 "a.y"

#include <stdio.h>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

#line 14 "a.y"
typedef union {
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XArgsList* args;
} YYSTYPE;
#line 42 "y.tab.c"
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
#define IFX 280
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    7,    7,    2,    2,    2,    2,    2,    2,    2,
    2,    6,    6,    5,    5,    5,    3,    3,    4,    4,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,
};
short yylen[] = {                                         2,
    1,    2,    0,    1,    2,    5,    7,    5,    9,    6,
    4,    0,    2,    1,    3,    0,    3,    1,    2,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,
};
short yydefred[] = {                                      3,
    0,    0,   22,   21,    0,   24,    0,    0,    0,    4,
    0,    0,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    5,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   38,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   27,   28,   13,    0,   11,    0,    0,    0,
   20,    0,    0,   18,    0,    8,    0,   10,   19,    0,
    0,    0,   17,    7,    0,    0,    9,
};
short yydgoto[] = {                                       1,
   12,   74,   75,   72,    0,   41,    2,
};
short yysindex[] = {                                      0,
    0,  -28,    0,    0,  -19,    0,  -37,  -27,  -14,    0,
  127,  135,    0,  -12,  127,  127,  127,  127,  127,  -25,
  127,  127,  127,  -59,    9,  127,  127,  127,  127,  127,
  127,  127,  127,  127,  127,  127,  127,  127,    0,  -11,
 -118,  373,  373,  373,  373,  373,  -23,   32,   43,  141,
    0,  389,  389,   23,   23,   23,   23,  373,   23,   23,
   16,   16,    0,    0,    0,  -28,    0,  -40,  -40,  127,
    0,  -36,  -28,    0, -245,    0,  241,    0,    0,  -32,
  -40,  127,    0,    0,   54,  -40,    0,
};
short yyrindex[] = {                                      0,
    0,   38,    0,    0,  367,    0,    0,    0,    0,    0,
    0,    0,    0,  -75,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -35,  -34,  -30,  -26,  -24,    0,    0,    0,    0,
    0,   69,  128,   80,   86,   94,  100,   -4,  106,  114,
   63,   74,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  439,  190,  -47,  -16,    0,    0,    0,
};
#define YYTABLESIZE 656
short yytable[] = {                                      11,
    6,   19,   21,   11,   66,   39,   40,   11,   39,   40,
   41,   11,   22,   41,   42,   47,   43,   42,   10,   43,
   20,   76,   10,   39,   40,   23,   10,   40,   41,   65,
   10,   81,   42,   84,   43,   67,   35,    1,   87,   35,
    6,   19,   23,   23,   23,   23,   23,   12,   23,   51,
   37,   35,   32,   36,   35,   38,   80,   37,    0,    6,
   23,   23,   38,   23,   37,   35,    0,   36,   34,   38,
   33,    0,   68,   37,   35,   32,   36,    0,   38,    0,
    0,    0,   73,   69,   37,   35,   32,   36,   78,   38,
    0,   34,   83,   33,   86,   37,   35,   32,   36,    0,
   38,    0,   34,   25,   33,   25,   25,   25,    0,   36,
    0,    0,   36,   34,   26,   33,   26,   26,   26,    0,
   31,   25,   25,   31,   25,    6,   32,   36,    0,   32,
    0,    0,   26,   26,   33,   26,    0,   33,   31,   31,
   34,   31,    0,   34,   32,   32,   29,   32,    0,   29,
    0,    0,   33,   33,   30,   33,    0,   30,   34,   34,
    0,   34,    0,    0,   29,   29,   11,   29,   37,    0,
    0,   37,   30,   30,    0,   30,   37,   35,   32,   36,
    0,   38,   37,   35,   32,   36,   37,   38,    0,    0,
    0,   13,    0,   39,   34,    0,   33,    0,    0,   70,
   34,    0,   33,    0,    0,    0,    0,    0,    0,    0,
    0,   15,   16,   17,   18,    0,    3,    4,    5,    6,
    3,    4,    5,    6,    3,    4,    5,    6,    3,    4,
    5,    6,    0,    0,    0,    7,    0,    8,    9,    7,
    0,    8,    9,    7,    0,    8,    9,    7,   14,    8,
    9,   15,   16,   17,   18,   71,    0,    6,    6,    6,
    6,   79,   71,   23,   23,   23,   23,   23,   23,   79,
   26,   27,   28,   29,   30,   31,    6,    0,    6,    6,
    0,    0,   37,   35,   32,   36,    0,   38,    0,    0,
    0,    0,    0,   26,   27,   28,   29,   30,   31,   82,
   34,    0,   33,    0,   26,   27,   28,   29,   30,   31,
    0,    0,    0,    0,    0,   26,   27,   28,   29,   30,
   31,    0,    0,    0,   25,   25,   25,   25,   25,   25,
   36,   36,    0,    0,    0,   26,   26,   26,   26,   26,
   26,   31,   31,   31,   31,   31,   31,   32,   32,   32,
   32,   32,   32,    0,    0,   33,   33,   33,   33,   33,
   33,   34,   34,   34,   34,   34,   34,   29,   29,   29,
   29,   29,   29,    0,    0,   30,   30,   30,   30,   30,
   30,    0,    0,    3,    4,   24,    6,    0,    0,   37,
   37,    0,    0,    0,    0,    0,   26,   27,   28,   29,
   30,   31,   26,   27,   28,   29,   30,   31,   23,   23,
   23,   23,    0,   23,   37,   35,    0,   36,    0,   38,
    0,    0,    0,    0,    0,   23,   23,    0,   23,    0,
   37,   35,   34,   36,   33,   38,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   34,   25,
   33,    0,    0,   42,   43,   44,   45,   46,    0,   48,
   49,   50,    0,    0,   52,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   64,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   26,   27,   28,   29,   30,   31,   77,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   85,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   23,   23,
   23,   23,   23,   23,   26,   27,   28,   29,   30,   31,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,   29,   30,   31,
};
short yycheck[] = {                                      40,
    0,   61,   40,   40,  123,   41,   41,   40,   44,   44,
   41,   40,   40,   44,   41,   41,   41,   44,   59,   44,
   40,   69,   59,   59,   59,   40,   59,   40,   59,   41,
   59,  277,   59,   81,   59,   59,   41,    0,   86,   44,
   40,   61,   41,   42,   43,   44,   45,  123,   47,   41,
   42,   43,   44,   45,   59,   47,   73,   42,   -1,   59,
   59,   60,   47,   62,   42,   43,   -1,   45,   60,   47,
   62,   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   -1,  123,   41,   42,   43,   44,   45,  125,   47,
   -1,   60,  125,   62,   41,   42,   43,   44,   45,   -1,
   47,   -1,   60,   41,   62,   43,   44,   45,   -1,   41,
   -1,   -1,   44,   60,   41,   62,   43,   44,   45,   -1,
   41,   59,   60,   44,   62,  125,   41,   59,   -1,   44,
   -1,   -1,   59,   60,   41,   62,   -1,   44,   59,   60,
   41,   62,   -1,   44,   59,   60,   41,   62,   -1,   44,
   -1,   -1,   59,   60,   41,   62,   -1,   44,   59,   60,
   -1,   62,   -1,   -1,   59,   60,   40,   62,   41,   -1,
   -1,   44,   59,   60,   -1,   62,   42,   43,   44,   45,
   -1,   47,   42,   43,   44,   45,   59,   47,   -1,   -1,
   -1,    2,   -1,   59,   60,   -1,   62,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  271,  272,  273,  274,   -1,  257,  258,  259,  260,
  257,  258,  259,  260,  257,  258,  259,  260,  257,  258,
  259,  260,   -1,   -1,   -1,  276,   -1,  278,  279,  276,
   -1,  278,  279,  276,   -1,  278,  279,  276,  268,  278,
  279,  271,  272,  273,  274,   66,   -1,  257,  258,  259,
  260,   72,   73,  262,  263,  264,  265,  266,  267,   80,
  262,  263,  264,  265,  266,  267,  276,   -1,  278,  279,
   -1,   -1,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,   59,
   60,   -1,   62,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
  262,  263,   -1,   -1,   -1,  262,  263,  264,  265,  266,
  267,  262,  263,  264,  265,  266,  267,  262,  263,  264,
  265,  266,  267,   -1,   -1,  262,  263,  264,  265,  266,
  267,  262,  263,  264,  265,  266,  267,  262,  263,  264,
  265,  266,  267,   -1,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,  257,  258,  259,  260,   -1,   -1,  262,
  263,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,  262,  263,  264,  265,  266,  267,   42,   43,
   44,   45,   -1,   47,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   42,   43,   60,   45,   62,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   11,
   62,   -1,   -1,   15,   16,   17,   18,   19,   -1,   21,
   22,   23,   -1,   -1,   26,   27,   28,   29,   30,   31,
   32,   33,   34,   35,   36,   37,   38,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,  266,  267,   70,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   82,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
   -1,   -1,  264,  265,  266,  267,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"TDOUBLE","TBOOL","VARIABLE","TSTRING","OP_CALC","AND_OP",
"OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP","ADD_EQ",
"SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE","FOR","IFX",
};
char *yyrule[] = {
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
"expr : VARIABLE ADD_EQ expr",
"expr : VARIABLE SUB_EQ expr",
"expr : VARIABLE MUL_EQ expr",
"expr : VARIABLE DIV_EQ expr",
"expr : VARIABLE '=' expr",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 113 "a.y"


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
#line 385 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

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

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
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
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
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

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
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
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 51 "a.y"
{ execAndFreeNode(yyvsp[0].node);}
break;
case 4:
#line 55 "a.y"
{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 56 "a.y"
{ yyval.node = yyvsp[-1].node; }
break;
case 6:
#line 57 "a.y"
{ yyval.node = opr(IF ,2,yyvsp[-2].node,yyvsp[0].node) ; }
break;
case 7:
#line 58 "a.y"
{ yyval.node = opr(IF ,3,yyvsp[-4].node,yyvsp[-2].node,yyvsp[0].node) ; }
break;
case 8:
#line 59 "a.y"
{ yyval.node = opr(WHILE , 2, yyvsp[-2].node, yyvsp[0].node ); }
break;
case 9:
#line 60 "a.y"
{ yyval.node = opr(FOR,4,yyvsp[-6].node,yyvsp[-4].node,yyvsp[-2].node,yyvsp[0].node); }
break;
case 10:
#line 61 "a.y"
{ yyval.node = func(yyvsp[-5].sValue,yyvsp[-3].args,yyvsp[-1].node);}
break;
case 11:
#line 62 "a.y"
{ yyval.node = call(yyvsp[-3].sValue ); }
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
{ yyval.node = yyvsp[0].node; }
break;
case 15:
#line 72 "a.y"
{ opr(',',2,yyvsp[-2].node,yyvsp[0].node); }
break;
case 16:
#line 73 "a.y"
{ yyval.node = NULL; }
break;
case 17:
#line 77 "a.y"
{ yyval.node = yyvsp[-1].node;}
break;
case 18:
#line 78 "a.y"
{ yyval.node = yyvsp[0].node; }
break;
case 19:
#line 82 "a.y"
{ yyval.node = opr(';',2,yyvsp[-1].node, yyvsp[0].node); }
break;
case 20:
#line 83 "a.y"
{ yyval.node = yyvsp[0].node; }
break;
case 21:
#line 88 "a.y"
{ yyval.node = number(yyvsp[0].iValue); }
break;
case 22:
#line 89 "a.y"
{ yyval.node = number(yyvsp[0].iValue); }
break;
case 23:
#line 90 "a.y"
{ /*printf("VARIABLE $1= %s\n" , $1);*/ yyval.node = var(yyvsp[0].sValue); }
break;
case 24:
#line 91 "a.y"
{ printf("get a string: %s\n" , yyvsp[0].sValue); yyval.node = string(yyvsp[0].sValue); }
break;
case 25:
#line 92 "a.y"
{ yyval.node = opr('+',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 26:
#line 93 "a.y"
{ yyval.node = opr('-',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 27:
#line 94 "a.y"
{ yyval.node = opr('*',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 28:
#line 95 "a.y"
{ yyval.node = opr('/',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 29:
#line 96 "a.y"
{ yyval.node = opr('>',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 30:
#line 97 "a.y"
{ yyval.node = opr('<',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 31:
#line 98 "a.y"
{ yyval.node = opr( LE_OP,2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 32:
#line 99 "a.y"
{ yyval.node = opr( GE_OP,2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 33:
#line 100 "a.y"
{ yyval.node = opr( EQ_OP,2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 34:
#line 101 "a.y"
{ yyval.node = opr( NE_OP,2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 35:
#line 102 "a.y"
{ yyval.node = opr(',',2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 36:
#line 103 "a.y"
{ yyval.node = opr(AND_OP,2,yyvsp[-2].node,yyvsp[0].node);}
break;
case 37:
#line 104 "a.y"
{ yyval.node = opr(OR_OP,2,yyvsp[-2].node,yyvsp[0].node); }
break;
case 38:
#line 105 "a.y"
{ yyval.node = yyvsp[-1].node; }
break;
case 39:
#line 106 "a.y"
{ yyval.node = opr(ADD_EQ,2,yyvsp[-2].sValue,yyvsp[0].node);}
break;
case 40:
#line 107 "a.y"
{ yyval.node = opr(SUB_EQ,2,yyvsp[-2].sValue,yyvsp[0].node);}
break;
case 41:
#line 108 "a.y"
{ yyval.node = opr(MUL_EQ,2,yyvsp[-2].sValue,yyvsp[0].node);}
break;
case 42:
#line 109 "a.y"
{ yyval.node = opr(DIV_EQ,2,yyvsp[-2].sValue,yyvsp[0].node);}
break;
case 43:
#line 110 "a.y"
{ yyval.node = opr('=',2,var(yyvsp[-2].sValue),yyvsp[0].node ); }
break;
#line 730 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
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
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
