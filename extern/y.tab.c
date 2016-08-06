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
#define IFX 284
#define UMINUS 285
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   34,   34,    1,    1,    1,    1,    2,    2,    5,
   30,   30,   31,   31,   31,    7,    7,    6,    3,    3,
    8,    8,    9,    9,   12,   12,   12,   12,    4,    4,
    4,   16,   32,   32,   33,   33,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   29,   29,   24,   25,   26,   27,   28,   23,
   23,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   15,   15,   15,   15,   21,   21,   21,   21,   21,   21,
   21,   21,   20,   20,   20,   20,   20,   22,   13,   13,
   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    6,
    0,    3,    1,    3,    0,    2,    0,    2,    1,    1,
    5,    7,    5,    9,    0,    1,    1,    1,    1,    1,
    3,    4,    0,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    3,    3,
    3,    3,    1,    1,    1,    1,    1,    2,    1,    1,
    1,    1,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    2,    2,    2,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    3,    1,    3,
    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    4,    2,    5,
    6,    0,    8,    9,   19,   20,   29,   30,   89,    0,
    0,    0,    0,    0,    0,    0,    7,    0,    0,    0,
    0,    0,   18,    0,    0,   57,   56,    0,   59,    0,
    0,    0,   43,   87,    0,   35,    0,    0,   37,    0,
    0,    0,    0,    0,    0,    0,   61,   85,    0,    0,
    0,   83,   84,   54,    0,   55,   27,    0,   26,   28,
    0,   31,   90,   91,   92,   93,   78,    0,    0,   88,
    0,   77,    0,    0,    0,   13,    0,   17,   71,   72,
    0,   58,   47,   46,    0,    0,    0,   73,   74,    0,
   32,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   12,    0,    0,   50,   51,   52,
   53,   49,   36,   69,   70,   17,   45,    0,   65,   66,
   67,   68,   63,   64,   23,    0,   14,   10,   16,   48,
    0,    0,    0,   44,   22,    0,    0,   24,
};
static const short yydgoto[] = {                          1,
  127,   10,   11,   12,   13,   14,  116,   15,   16,   56,
  128,   68,   17,   57,   44,   58,   46,   92,   93,   59,
   80,   19,   60,   61,   49,   62,   63,   64,   53,   35,
   87,   54,   55,    2,
};
static const short yysindex[] = {                         0,
    0,   18,  -33,    6,   34,   53, -249,    0,    0,    0,
    0,  -45,    0,    0,    0,    0,    0,    0,    0,   35,
   55,   -6,   -1,   -1, -189,   -7,    0,   14,   14,   14,
   14,   -6,    0, -201,  -61,    0,    0,   57,    0, -177,
 -177,  -28,    0,    0,    0,    0,   70, -181,    0,    0,
    0,    0,   48,   60,   58,  -19,    0,    0,   70,   51,
 -181,    0,    0,    0,   12,    0,    0,   45,    0,    0,
   31,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -181,    0,    0,    0,    0,    0,  -25,    0,    0,    0,
   14,    0,    0,    0,   14,   14,   14,    0,    0,   -1,
    0,   -6,   -1,   -1,  -59,   -1,   -1,   -1,   -1,   -1,
   -1,  -59,   -1, -156,    0,    8,   69,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -164,    0,    0,
    0,    0,    0,    0,    0,  -50,    0,    0,    0,    0,
   13,  -59, -189,    0,    0,   75,  -59,    0,
};
static const short yyrindex[] = {                         0,
    0,  120,   39,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2,   78,    0,    0,   63,    0,    0,    0,    0,    0,
    0,    0,    0,   -4,    0,    0,    0,  -39,    0,    0,
    0,    0,    0,    0,  298,    0,   80,  305,    0,  312,
  319,   42,    0,    0,   83,    0,    0,    0,  -26,  -30,
  -17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  119,  139,    0,
  146,    0,  278,  285,   28,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   95,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
   11,    0,    0,    0,    0,    7,   21,    0,    0,   26,
  -63,   -3,   10,   41,   22,   29,   40,    0,    0,   77,
    0,    0,  100,   16,  105,   33,   44,   46,   49,    0,
    0,    0,    0,    0,
};
#define YYTABLESIZE 366
static const short yytable[] = {                          8,
   21,   55,   55,   55,   55,   55,   22,   55,  143,   26,
   62,   91,    9,   27,   60,  115,   53,   20,  114,   55,
   55,  105,   55,   86,   86,   86,   86,   86,   62,   86,
   18,   67,   60,   60,   69,   60,   15,   48,   42,   15,
   71,   86,   86,   42,   86,   23,   70,   81,  135,   65,
   45,   72,  112,   78,   50,   89,   90,   86,   42,   21,
   79,   88,   43,  126,   83,   51,    8,   52,   81,   66,
   54,    8,   77,   24,   94,   84,    8,   85,  145,   40,
   41,   66,   40,  148,   54,   40,   81,   98,   99,   33,
  100,   32,   25,   33,   34,   32,   22,   55,   47,   55,
  101,  102,  137,  113,   73,   74,   75,   76,   47,  140,
  111,   96,  110,  142,   95,  147,   97,   48,   33,    1,
   20,   25,   53,   34,   11,   21,  139,   20,  124,  125,
   45,   20,  138,   18,   50,   25,   82,  144,  136,  146,
   18,  123,   43,    0,   18,   51,  141,   52,  122,   67,
    0,  139,   69,    0,    0,    0,   20,   20,   71,   82,
   87,   87,   20,   87,   70,   87,    0,  117,    0,   18,
   18,  118,  119,  120,    0,   18,  121,   82,   47,   79,
   85,   85,    0,   85,    0,   85,   80,   86,   86,    0,
   86,    0,   86,    0,    0,    0,    0,   79,    0,    3,
    0,    0,    0,    0,   80,  129,  130,  131,  132,  133,
  134,  103,  104,    0,    0,    0,    0,    4,    0,    5,
    6,    7,   55,   55,   55,   55,   55,   55,   36,   55,
   55,   62,   62,    0,   21,   60,   60,   60,   60,   60,
   60,    0,  103,  104,   86,   86,   86,   86,   86,   86,
   36,   37,   38,   39,    0,   36,    0,   38,   39,   21,
    0,    0,   40,   41,    0,    0,    3,   40,   41,    0,
   36,    3,   38,  103,  104,    0,    3,   21,    0,   21,
   21,   21,   40,   41,    4,    0,    5,    6,    7,    4,
    0,    5,    6,    7,    4,    0,    5,    6,    7,   98,
   99,    0,   28,   29,   30,   31,   28,   29,   30,   31,
   55,   55,   55,   55,  106,  107,  108,  109,   75,   83,
   83,    0,   83,    0,   83,   76,   84,   84,    0,   84,
    0,   84,    0,    0,    0,    0,   75,    0,   42,   85,
   85,   42,   85,   76,   85,   39,   86,   86,   39,   86,
    0,   86,   38,   83,   83,   38,   83,    0,   83,   41,
   84,   84,   41,   84,    0,   84,
};
static const short yycheck[] = {                         59,
    0,   41,   42,   43,   44,   45,   40,   47,   59,  259,
   41,   40,    2,   59,   41,   41,   43,    2,   44,   59,
   60,   41,   62,   41,   42,   43,   44,   45,   59,   47,
    2,   25,   59,   60,   25,   62,   41,   22,   45,   44,
   25,   59,   60,   45,   62,   40,   25,   32,  112,   24,
   22,   59,   41,   32,   22,   40,   41,  259,   45,   59,
   32,  123,   22,  123,   32,   22,   59,   22,   41,  259,
   43,   59,   32,   40,   42,   32,   59,   32,  142,  269,
  270,  259,   41,  147,   43,   44,   59,  269,  270,   59,
   43,   61,   40,   59,   40,   61,   40,   59,   22,   61,
   41,   44,  259,   59,   28,   29,   30,   31,   32,   41,
   60,   42,   62,  278,   45,   41,   47,  102,   41,    0,
  105,   59,   43,   41,  123,  125,  116,  112,  103,  104,
  102,  116,  125,  105,  102,   41,   32,  125,  113,  143,
  112,  102,  102,   -1,  116,  102,  126,  102,  100,  143,
   -1,  141,  143,   -1,   -1,   -1,  141,  142,  143,   41,
   42,   43,  147,   45,  143,   47,   -1,   91,   -1,  141,
  142,   95,   96,   97,   -1,  147,  100,   59,  102,   41,
   42,   43,   -1,   45,   -1,   47,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   59,   -1,  259,
   -1,   -1,   -1,   -1,   59,  106,  107,  108,  109,  110,
  111,  262,  263,   -1,   -1,   -1,   -1,  277,   -1,  279,
  280,  281,  262,  263,  264,  265,  266,  267,  257,  269,
  270,  262,  263,   -1,  268,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  262,  263,  264,  265,  266,  267,
  257,  258,  259,  260,   -1,  257,   -1,  259,  260,  259,
   -1,   -1,  269,  270,   -1,   -1,  259,  269,  270,   -1,
  257,  259,  259,  262,  263,   -1,  259,  277,   -1,  279,
  280,  281,  269,  270,  277,   -1,  279,  280,  281,  277,
   -1,  279,  280,  281,  277,   -1,  279,  280,  281,  269,
  270,   -1,  272,  273,  274,  275,  272,  273,  274,  275,
  272,  273,  274,  275,  264,  265,  266,  267,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   59,   -1,   41,   42,
   43,   44,   45,   59,   47,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,   41,
   42,   43,   44,   45,   -1,   47,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 285
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
"BREAK","RETURN","IFX","UMINUS",
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
"func_declar_stmt : IDENTIFIER FUNC_OP param_list '{' expr_list '}'",
"param_list :",
"param_list : '(' parameter ')'",
"parameter : IDENTIFIER",
"parameter : parameter ',' IDENTIFIER",
"parameter :",
"expr_list : expr_list statement",
"expr_list :",
"var_declar_stmt : id_expr ';'",
"con_ctl_stmt : selection_stmt",
"con_ctl_stmt : loop_stmt",
"selection_stmt : IF '(' logic_stmt ')' block",
"selection_stmt : IF '(' logic_stmt ')' block ELSE block",
"loop_stmt : WHILE '(' logic_stmt ')' block",
"loop_stmt : FOR '(' for_1_stmt ';' logic_stmt ';' for_1_stmt ')' block",
"for_1_stmt :",
"for_1_stmt : assign_stmt",
"for_1_stmt : var_declar_stmt",
"for_1_stmt : self_inc_dec_stmt",
"simple_stmt : assign_stmt",
"simple_stmt : call_statement",
"simple_stmt : DELETE IDENTIFIER ';'",
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
"arithmetic_stmt : add_arithmetic_stmt_value '+' add_arithmetic_stmt_value",
"arithmetic_stmt : assign_stmt_value_eq '-' assign_stmt_value_eq",
"arithmetic_stmt : assign_stmt_value_eq '*' assign_stmt_value_eq",
"arithmetic_stmt : assign_stmt_value_eq '/' assign_stmt_value_eq",
"add_arithmetic_stmt_value : assign_stmt_value_eq",
"add_arithmetic_stmt_value : string_expr",
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
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
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
#line 272 "a.y"


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
#line 60 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 64 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 65 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 66 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 67 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 72 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 73 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 78 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 11:
#line 82 "a.y"
	{ yyval.params = NULL; }
break;
case 12:
#line 83 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 13:
#line 87 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 14:
#line 88 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 15:
#line 89 "a.y"
	{ yyval.params = NULL; }
break;
case 16:
#line 93 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 17:
#line 94 "a.y"
	{ yyval.node = NULL; }
break;
case 18:
#line 99 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 19:
#line 104 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 20:
#line 105 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 21:
#line 110 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 22:
#line 111 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 23:
#line 115 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 24:
#line 116 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 25:
#line 121 "a.y"
	{ yyval.node = NULL ; }
break;
case 26:
#line 122 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 27:
#line 123 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 28:
#line 124 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 29:
#line 129 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 30:
#line 130 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 31:
#line 131 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 32:
#line 136 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 33:
#line 140 "a.y"
	{ yyval.args = NULL; }
break;
case 34:
#line 141 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 35:
#line 145 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 36:
#line 146 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 37:
#line 150 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 38:
#line 151 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 39:
#line 152 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 40:
#line 153 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 41:
#line 154 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 42:
#line 155 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 43:
#line 156 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 44:
#line 160 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 45:
#line 161 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 167 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 47:
#line 168 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 173 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 49:
#line 179 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 50:
#line 180 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 51:
#line 181 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 52:
#line 182 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 53:
#line 186 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 54:
#line 187 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 55:
#line 191 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 56:
#line 195 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 57:
#line 199 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 58:
#line 203 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 59:
#line 207 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 60:
#line 212 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 61:
#line 213 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 62:
#line 218 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 219 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 64:
#line 220 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 65:
#line 221 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 66:
#line 222 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 67:
#line 223 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 68:
#line 224 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 69:
#line 225 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 70:
#line 226 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 71:
#line 231 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 72:
#line 232 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 73:
#line 233 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 74:
#line 234 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 75:
#line 239 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 76:
#line 240 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 77:
#line 241 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 78:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 243 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 244 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 81:
#line 245 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 82:
#line 246 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 251 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 84:
#line 252 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 85:
#line 253 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 86:
#line 254 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 255 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 260 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 89:
#line 265 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 266 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 91:
#line 267 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 92:
#line 268 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 93:
#line 269 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1030 "y.tab.c"
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
