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
 bool bValue; /* bool value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
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
#define VARIABLE 258
#define TSTRING 259
#define TBOOL 260
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
    0,    5,    5,    2,    2,    2,    2,    2,    2,    3,
    3,    4,    4,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    2,    5,    7,    5,    9,    3,
    1,    2,    1,    1,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,   15,    0,   17,   14,    0,    0,    0,    4,
    0,    0,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    5,    0,    0,    0,    0,   31,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,   21,
    0,    0,    0,    0,   11,    0,    8,    0,   13,    0,
    0,    0,   10,   12,    7,    0,    0,    9,
};
static const short yydgoto[] = {                          1,
   12,   55,   56,   60,    2,
};
static const short yysindex[] = {                         0,
    0,  -32,    0,  -58,    0,    0,  -34,  -29,  -28,    0,
    5,  124,    0,    5,    5,    5,    5,   14,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    0,  248,   22,   49,  130,    0,  338,  338,   28,
   28,   28,   28,  248,   28,   28,  -33,  -33,    0,    0,
  -40,  -40,    5,  -32,    0, -258,    0,  151,    0,  -36,
  -40,    5,    0,    0,    0,   56,  -40,    0,
};
static const short yyrindex[] = {                         0,
    0,   17,    0,  -13,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -39,    0,    0,    0,    0,   -6,   36,  -20,
   76,   83,   89,  -26,   96,  103,   63,   69,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  408,    8,  -45,    0,    0,
};
#define YYTABLESIZE 605
static const short yytable[] = {                         11,
    6,   32,   14,   11,   32,   15,   57,   11,   30,   13,
   16,   17,   61,   31,   28,   65,    1,   28,   10,   32,
   24,   68,   10,   24,    0,    0,   10,   16,   16,   16,
   16,   16,   28,   16,   29,    0,    0,   29,   24,   24,
    6,   24,    0,    0,   11,   16,   16,    0,   16,    0,
    0,    0,   29,    0,   37,   30,   28,   25,   29,    6,
   31,   59,   51,   30,   28,   25,   29,   64,   31,   30,
   28,    0,   29,   27,   31,   26,   30,    0,    0,   30,
    0,   27,   54,   26,    0,    0,    0,    0,   63,   52,
   30,   28,   25,   29,   30,   31,   67,   30,   28,   25,
   29,    0,   31,   18,    0,   18,   18,   18,   27,   19,
   26,   19,   19,   19,    0,   27,   25,   26,    0,   25,
    0,   18,   18,   26,   18,    6,   26,   19,   19,   27,
   19,    0,   27,    0,   25,   25,   22,   25,    0,   22,
    0,   26,   26,   23,   26,    0,   23,   27,   27,    0,
   27,    0,    0,    0,   22,   22,    0,   22,    0,    0,
    0,   23,   23,    0,   23,   30,   28,   25,   29,    0,
   31,   30,   28,   25,   29,    0,   31,    0,    0,    0,
    0,    0,   32,   27,    0,   26,    0,    0,   53,   27,
    0,   26,   30,   28,   25,   29,    0,   31,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   62,
   27,    0,   26,    0,    0,    0,    3,    4,    5,    6,
    3,    4,    5,    6,    3,    4,    5,    6,    0,    7,
    0,    8,    9,    7,    0,    8,    9,    7,    0,    8,
    9,   24,   24,   24,   24,   24,   24,    0,   16,   16,
   16,   16,   16,   16,    0,   29,   29,    6,    6,    6,
    6,    3,    4,    5,    6,    0,    0,    0,    0,    0,
    6,    0,    6,    6,    0,   19,   20,   21,   22,   23,
   24,    0,    0,   19,   20,   21,   22,   23,   24,   30,
   28,    0,   29,    0,   31,    0,    0,   30,   30,    0,
    0,    0,    0,    0,    0,    0,    0,   27,    0,   26,
   19,   20,   21,   22,   23,   24,    0,   19,   20,   21,
   22,   23,   24,    0,   18,   18,   18,   18,   18,   18,
   19,   19,   19,   19,   19,   19,    0,   25,   25,   25,
   25,   25,   25,    0,   26,   26,   26,   26,   26,   26,
   27,   27,   27,   27,   27,   27,    0,   22,   22,   22,
   22,   22,   22,    0,   23,   23,   23,   23,   23,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
   28,    0,   29,    0,   31,   19,   20,   21,   22,   23,
   24,   19,   20,   21,   22,   23,   24,   27,    0,   26,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   19,   20,   21,   22,   23,   24,   18,    0,
    0,   33,   34,   35,   36,    0,   38,   39,   40,   41,
   42,   43,   44,   45,   46,   47,   48,   49,   50,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   58,    0,    0,    0,    0,    0,    0,    0,    0,   66,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   19,
   20,   21,   22,   23,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,   22,   23,   24,
};
static const short yycheck[] = {                         40,
    0,   41,   61,   40,   44,   40,   52,   40,   42,    2,
   40,   40,  271,   47,   41,   61,    0,   44,   59,   59,
   41,   67,   59,   44,   -1,   -1,   59,   41,   42,   43,
   44,   45,   59,   47,   41,   -1,   -1,   44,   59,   60,
   40,   62,   -1,   -1,   40,   59,   60,   -1,   62,   -1,
   -1,   -1,   59,   -1,   41,   42,   43,   44,   45,   59,
   47,   54,   41,   42,   43,   44,   45,   60,   47,   42,
   43,   -1,   45,   60,   47,   62,   41,   -1,   -1,   44,
   -1,   60,  123,   62,   -1,   -1,   -1,   -1,  125,   41,
   42,   43,   44,   45,   59,   47,   41,   42,   43,   44,
   45,   -1,   47,   41,   -1,   43,   44,   45,   60,   41,
   62,   43,   44,   45,   -1,   60,   41,   62,   -1,   44,
   -1,   59,   60,   41,   62,  125,   44,   59,   60,   41,
   62,   -1,   44,   -1,   59,   60,   41,   62,   -1,   44,
   -1,   59,   60,   41,   62,   -1,   44,   59,   60,   -1,
   62,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,   59,   60,   -1,   62,   42,   43,   44,   45,   -1,
   47,   42,   43,   44,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   59,   60,
   -1,   62,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,  257,  258,  259,  260,
  257,  258,  259,  260,  257,  258,  259,  260,   -1,  270,
   -1,  272,  273,  270,   -1,  272,  273,  270,   -1,  272,
  273,  262,  263,  264,  265,  266,  267,   -1,  262,  263,
  264,  265,  266,  267,   -1,  262,  263,  257,  258,  259,
  260,  257,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
  270,   -1,  272,  273,   -1,  262,  263,  264,  265,  266,
  267,   -1,   -1,  262,  263,  264,  265,  266,  267,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   -1,   62,
  262,  263,  264,  265,  266,  267,   -1,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
  262,  263,  264,  265,  266,  267,   -1,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
  262,  263,  264,  265,  266,  267,   -1,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,  262,  263,  264,  265,  266,
  267,  262,  263,  264,  265,  266,  267,   60,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,  266,  267,   11,   -1,
   -1,   14,   15,   16,   17,   -1,   19,   20,   21,   22,
   23,   24,   25,   26,   27,   28,   29,   30,   31,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   53,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,  266,  267,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  264,  265,  266,  267,
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
0,0,0,0,0,0,0,0,0,0,"TDOUBLE","VARIABLE","TSTRING","TBOOL","OP_CALC","AND_OP",
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
#line 388 "y.tab.c"

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
#line 49 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 53 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 54 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 55 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 7:
#line 56 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 8:
#line 57 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 9:
#line 58 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 10:
#line 62 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 11:
#line 63 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 12:
#line 67 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 13:
#line 68 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 14:
#line 73 "a.y"
	{ yyval.node = number(yystack.l_mark[0].bValue ? 1 : 0);}
break;
case 15:
#line 74 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 16:
#line 75 "a.y"
	{ /*printf("VARIABLE $1= %s\n" , $1);*/ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 17:
#line 76 "a.y"
	{ printf("get a string: %s\n" , yystack.l_mark[0].sValue); yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 18:
#line 77 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 19:
#line 78 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 20:
#line 79 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 21:
#line 80 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 22:
#line 81 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 23:
#line 82 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 24:
#line 83 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 25:
#line 84 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 26:
#line 85 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 27:
#line 86 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 28:
#line 87 "a.y"
	{ yyval.node = opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 29:
#line 88 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 30:
#line 89 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 31:
#line 90 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 32:
#line 91 "a.y"
	{ yyval.node = opr('=',2,var(yystack.l_mark[-2].sValue),yystack.l_mark[0].node ); }
break;
#line 714 "y.tab.c"
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
