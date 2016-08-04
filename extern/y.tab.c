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
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

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
#define IFX 282
#define UMINUS 283
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   21,   21,    2,    2,    2,    2,    2,    2,    2,
    2,    2,   17,   17,   18,   18,   18,   19,   19,   20,
   20,   10,   10,   10,   10,   10,    3,    3,    4,    4,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    9,    9,    8,    7,    7,    7,    7,   11,   11,   11,
   12,   13,   14,   15,   16,    5,    5,    5,    5,    5,
    5,    5,    5,    6,    6,    6,    6,    6,    6,    6,
    6,    6,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    2,    2,    5,    7,    5,    9,
    6,    5,    0,    3,    1,    3,    0,    0,    1,    1,
    3,    1,    1,    1,    1,    1,    3,    1,    2,    0,
    1,    1,    1,    1,    1,    1,    3,    1,    1,    1,
    1,    1,    3,    3,    3,    3,    3,    1,    1,    1,
    1,    1,    1,    2,    1,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    2,    2,    2,    3,    3,    3,
    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,   53,   52,    0,   34,    0,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    2,   39,   40,   36,
   38,    0,    0,   31,    0,    0,    0,    0,   51,   64,
   65,    0,    0,    0,    6,   42,   54,   41,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    5,    0,
    0,    0,    0,   66,   67,    0,    0,    0,    0,    0,
    0,    0,   55,   20,   24,   22,   23,   26,   25,    0,
    0,    0,    0,    0,   43,    0,    0,   58,   59,   60,
   61,    0,   56,   57,   44,   48,   49,   50,   45,   46,
   47,    0,    0,    0,    0,    0,   15,    0,   30,    0,
    0,    0,    0,    0,    0,   14,    0,   12,   21,   30,
   28,    0,    9,    0,   16,   11,   29,    0,    0,    0,
   27,    8,    0,    0,   10,
};
static const short yydgoto[] = {                          1,
   16,  111,  112,  107,   18,   19,   20,   21,   37,   64,
   22,   23,   24,   25,   26,   69,   62,   98,   70,   71,
    2,
};
static const short yysindex[] = {                         0,
    0,   26,    0,    0,  -37,    0, -251, -251,  -31,  -30,
  -26, -243,  -36,    0,   30,  128,    0,    0,    0,    0,
    0,   20,  -59,    0,    0,    0,  -20,   34,    0,    0,
    0,   30,   30,   30,    0,    0,    0,    0,   92,   30,
   30,   30,   30,   30,   30,   30,   30,   30,    0,   10,
   10,   10,   10,    0,    0,   30,   30,   30,   30,   30,
 -237, -100,    0,    0,    0,    0,    0,    0,    0,    4,
    9,  109,  115,  134,    0,   44,   44,    0,    0,    0,
    0,  147,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  147,  147,  147,  147,  147,    0,  -13,    0,   14,
   34,  -40,  -40,   30, -220,    0,  -34,    0,    0,    0,
    0, -221,    0,  141,    0,    0,    0,   -5,  -40,   30,
    0,    0,  122,  -40,    0,
};
static const short yyrindex[] = {                         0,
    0,   68,    0,    0,   50,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   72,    0,   80,  102,  -46,   41,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   28,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   43,    0,    0,    0,    0,  -29,  -12,    0,    0,    0,
    0,  -23,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -17,   -7,   15,   17,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
  387,   11,  -86,  -10,    0,    0,    0,   77,    0,   -3,
  276,   36,  -21,  409,   -2,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 510
static const short yytable[] = {                         15,
    7,   60,   28,   15,   13,   15,   66,   29,   32,   33,
   13,   62,   17,   34,   62,   35,  113,   37,   14,   61,
   37,   97,   99,   69,   14,   68,   69,  106,   63,   62,
  105,   63,  122,   70,   15,   37,   70,  125,  115,   13,
    7,   69,   30,   31,  100,    7,   63,   88,   88,   88,
   88,   70,  101,   14,   13,   71,  119,   72,   71,    7,
   72,   52,   50,   65,   51,   15,   53,    1,   17,   15,
   13,   17,  108,   71,   13,   72,   13,   68,   13,   66,
   68,   18,  110,   19,   14,   86,   86,   86,   86,   36,
  116,   51,   51,   51,   51,   68,   51,  109,   68,  118,
    0,    0,    0,   48,    0,   47,    0,    0,   51,   51,
   51,   51,   33,   48,   48,   33,   48,  117,   48,  121,
   32,   49,   49,   32,   49,    7,   49,    0,  117,    0,
   33,   33,   75,   33,    0,   46,   65,    0,   32,   32,
    0,   32,   35,   50,   50,   35,   50,    0,   50,  102,
    0,   48,   46,   47,    0,  103,    0,    0,   46,    0,
   35,   35,  124,   35,    0,   46,    0,    0,   48,    0,
   47,   46,    0,    0,   48,    0,   47,   46,    0,    0,
    0,   48,    0,   47,   46,    0,   49,   48,    0,   47,
    0,    0,  104,   48,    0,   47,    0,    0,    0,  120,
   48,    0,   47,    0,    0,    0,   48,    0,   47,   54,
   55,    0,   56,   57,   58,   59,    3,    4,    5,    6,
    3,    0,    3,    4,    5,    6,    0,    0,    7,    8,
   27,    0,   62,   62,    7,    8,    9,    0,   10,   11,
   12,    0,    9,    0,   10,   11,   12,    0,    0,   63,
   63,    3,    4,    5,    6,    0,    0,    7,    7,    7,
    7,    0,    0,    7,    8,    0,    3,    0,   29,    7,
    7,    9,    0,   10,   11,   12,    0,    7,    0,    7,
    7,    7,    3,    4,    5,    6,    3,    4,   29,    6,
    3,    4,   29,   63,    7,    8,    0,    0,    7,    8,
    0,    0,    9,    0,   10,   11,   12,   42,   43,   44,
   45,   51,   51,   51,   51,   51,   51,    0,   51,   51,
    0,   51,   51,   51,   51,   85,   89,   90,   91,    0,
    0,    0,    0,   33,   33,   33,   33,   33,   33,    0,
    0,   32,   32,   32,   32,   32,   32,    0,    0,    0,
    0,    0,    0,   40,   41,   42,   43,   44,   45,    0,
    0,    0,    0,   35,   35,   35,   35,   35,   35,    0,
   40,   41,   42,   43,   44,   45,   40,   41,   42,   43,
   44,   45,    0,   40,   41,   42,   43,   44,   45,   40,
   41,   42,   43,   44,   45,   40,   41,   42,   43,   44,
   45,   39,   40,   41,   42,   43,   44,   45,   40,   41,
   42,   43,   44,   45,    0,    0,    0,    0,   72,   73,
   74,   38,    0,    0,    0,    0,   76,   77,   78,   79,
   80,   81,   82,   83,   84,    0,   67,    0,    0,    0,
    0,    0,   92,   93,   94,   95,   96,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   87,   87,
   87,   87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  114,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  123,    0,    0,   67,
};
static const short yycheck[] = {                         40,
    0,   61,   40,   40,   45,   40,   28,  259,   40,   40,
   45,   41,    2,   40,   44,  259,  103,   41,   59,   40,
   44,  259,  123,   41,   59,   28,   44,   41,   41,   59,
   44,   44,  119,   41,   40,   59,   44,  124,  259,   45,
   40,   59,    7,    8,   41,   45,   59,   50,   51,   52,
   53,   59,   44,   59,   45,   41,  278,   41,   44,   59,
   44,   42,   43,   28,   45,   40,   47,    0,   41,   40,
   45,   44,   59,   59,   45,   59,  123,   41,   45,  101,
   44,   41,  123,   41,   59,   50,   51,   52,   53,   13,
  125,   42,   43,   44,   45,   59,   47,  101,  101,  110,
   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,   59,   60,
   61,   62,   41,   42,   43,   44,   45,  107,   47,  125,
   41,   42,   43,   44,   45,  125,   47,   -1,  118,   -1,
   59,   60,   41,   62,   -1,   44,  101,   -1,   59,   60,
   -1,   62,   41,   42,   43,   44,   45,   -1,   47,   41,
   -1,   60,   44,   62,   -1,   41,   -1,   -1,   44,   -1,
   59,   60,   41,   62,   -1,   44,   -1,   -1,   60,   -1,
   62,   44,   -1,   -1,   60,   -1,   62,   44,   -1,   -1,
   -1,   60,   -1,   62,   44,   -1,   59,   60,   -1,   62,
   -1,   -1,   59,   60,   -1,   62,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   60,   -1,   62,  269,
  270,   -1,  272,  273,  274,  275,  257,  258,  259,  260,
  257,   -1,  257,  258,  259,  260,   -1,   -1,  269,  270,
  268,   -1,  262,  263,  269,  270,  277,   -1,  279,  280,
  281,   -1,  277,   -1,  279,  280,  281,   -1,   -1,  262,
  263,  257,  258,  259,  260,   -1,   -1,  257,  258,  259,
  260,   -1,   -1,  269,  270,   -1,  257,   -1,  259,  269,
  270,  277,   -1,  279,  280,  281,   -1,  277,   -1,  279,
  280,  281,  257,  258,  259,  260,  257,  258,  259,  260,
  257,  258,  259,  260,  269,  270,   -1,   -1,  269,  270,
   -1,   -1,  277,   -1,  279,  280,  281,  264,  265,  266,
  267,  262,  263,  264,  265,  266,  267,   -1,  269,  270,
   -1,  272,  273,  274,  275,   50,   51,   52,   53,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,
   -1,  262,  263,  264,  265,  266,  267,   -1,   -1,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,   -1,
  262,  263,  264,  265,  266,  267,  262,  263,  264,  265,
  266,  267,   -1,  262,  263,  264,  265,  266,  267,  262,
  263,  264,  265,  266,  267,  262,  263,  264,  265,  266,
  267,   15,  262,  263,  264,  265,  266,  267,  262,  263,
  264,  265,  266,  267,   -1,   -1,   -1,   -1,   32,   33,
   34,   13,   -1,   -1,   -1,   -1,   40,   41,   42,   43,
   44,   45,   46,   47,   48,   -1,   28,   -1,   -1,   -1,
   -1,   -1,   56,   57,   58,   59,   60,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   50,   51,
   52,   53,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  104,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  120,   -1,   -1,  101,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 283
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,
"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"TDOUBLE","TBOOL","IDENTIFIER","TSTRING","OP_CALC","AND_OP",
"OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP","FUNC_CALL",
"ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE","FOR","DELETE",
"IFX","UMINUS",
};
static const char *yyrule[] = {
"$accept : program",
"program : statement_list",
"statement_list : statement_list statement",
"statement_list :",
"statement : ';'",
"statement : expr ';'",
"statement : DELETE IDENTIFIER",
"statement : IF '(' expr ')' block",
"statement : IF '(' expr ')' block ELSE block",
"statement : WHILE '(' expr ')' block",
"statement : FOR '(' expr ';' expr ';' expr ')' block",
"statement : IDENTIFIER FUNC_OP param_list '{' expr_list '}'",
"statement : IDENTIFIER '(' args_list ')' ';'",
"param_list :",
"param_list : '(' parameter ')'",
"parameter : IDENTIFIER",
"parameter : parameter ',' IDENTIFIER",
"parameter :",
"args_list :",
"args_list : args_expr",
"args_expr : args_expr_collection",
"args_expr : args_expr ',' args_expr_collection",
"args_expr_collection : t_bool_expr",
"args_expr_collection : double_expr",
"args_expr_collection : id_expr",
"args_expr_collection : string_expr",
"args_expr_collection : uminus_expr",
"block : '{' expr_list '}'",
"block : statement",
"expr_list : expr_list statement",
"expr_list :",
"expr : t_bool_expr",
"expr : double_expr",
"expr : id_expr",
"expr : TSTRING",
"expr : uminus_expr",
"expr : arithmetic_expr",
"expr : expr ',' expr",
"expr : parentheses_expr",
"expr : bool_expr",
"expr : assign_expr",
"double_or_ps_expr : double_expr",
"double_or_ps_expr : parentheses_expr",
"parentheses_expr : '(' expr ')'",
"arithmetic_expr : number_value_expr '+' number_value_expr",
"arithmetic_expr : number_value_expr '-' number_value_expr",
"arithmetic_expr : number_value_expr '*' number_value_expr",
"arithmetic_expr : number_value_expr '/' number_value_expr",
"number_value_expr : id_expr",
"number_value_expr : double_expr",
"number_value_expr : uminus_expr",
"id_expr : IDENTIFIER",
"t_bool_expr : TBOOL",
"double_expr : TDOUBLE",
"uminus_expr : '-' double_or_ps_expr",
"string_expr : TSTRING",
"bool_expr : expr '>' expr",
"bool_expr : expr '<' expr",
"bool_expr : expr LE_OP expr",
"bool_expr : expr GE_OP expr",
"bool_expr : expr EQ_OP expr",
"bool_expr : expr NE_OP expr",
"bool_expr : expr AND_OP expr",
"bool_expr : expr OR_OP expr",
"assign_expr : INC_OP id_expr",
"assign_expr : DEC_OP id_expr",
"assign_expr : id_expr INC_OP",
"assign_expr : id_expr DEC_OP",
"assign_expr : id_expr '=' expr",
"assign_expr : id_expr ADD_EQ expr",
"assign_expr : id_expr SUB_EQ expr",
"assign_expr : id_expr MUL_EQ expr",
"assign_expr : id_expr DIV_EQ expr",

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
#line 190 "a.y"


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
#line 449 "y.tab.c"

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
#line 54 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 58 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 59 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 60 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[0].sValue ); }
break;
case 7:
#line 61 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 8:
#line 62 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 9:
#line 63 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 10:
#line 64 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 11:
#line 65 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 12:
#line 66 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-4].sValue), argsNode(yystack.l_mark[-2].args) ); }
break;
case 13:
#line 70 "a.y"
	{ yyval.params = NULL; }
break;
case 14:
#line 71 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 15:
#line 75 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 16:
#line 76 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 17:
#line 77 "a.y"
	{ yyval.params = NULL; }
break;
case 18:
#line 81 "a.y"
	{ yyval.args = NULL; }
break;
case 19:
#line 82 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 20:
#line 86 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 21:
#line 87 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 22:
#line 91 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 23:
#line 92 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 24:
#line 93 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 25:
#line 94 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 26:
#line 95 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 27:
#line 99 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 28:
#line 100 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 29:
#line 104 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 30:
#line 105 "a.y"
	{ yyval.node = NULL; }
break;
case 31:
#line 110 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 32:
#line 111 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 33:
#line 112 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 34:
#line 113 "a.y"
	{ printf("get a string: %s\n" , yystack.l_mark[0].sValue); yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 35:
#line 114 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 36:
#line 115 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 37:
#line 116 "a.y"
	{ yyval.node = opr(',',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 38:
#line 117 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 39:
#line 118 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 40:
#line 119 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 41:
#line 124 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 42:
#line 125 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 43:
#line 129 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 44:
#line 134 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 45:
#line 135 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 46:
#line 136 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 47:
#line 137 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 48:
#line 142 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 49:
#line 143 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 50:
#line 144 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 51:
#line 148 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 52:
#line 152 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 53:
#line 156 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 54:
#line 160 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 55:
#line 164 "a.y"
	{ printf("get a string: %s\n" , yystack.l_mark[0].sValue); yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 56:
#line 168 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 57:
#line 169 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 58:
#line 170 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 59:
#line 171 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 60:
#line 172 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 61:
#line 173 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 62:
#line 174 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 63:
#line 175 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 64:
#line 179 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 65:
#line 180 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 66:
#line 181 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 67:
#line 182 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 68:
#line 183 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 69:
#line 184 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 70:
#line 185 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 71:
#line 186 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 72:
#line 187 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 935 "y.tab.c"
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
