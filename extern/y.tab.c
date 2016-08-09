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
    0,   35,   35,    1,    1,    1,    1,    2,    2,    5,
   31,   31,   32,   32,   32,    7,    7,    6,    6,    3,
    3,    8,    8,    9,    9,   12,   12,   12,   12,    4,
    4,    4,    4,   24,   24,   24,   16,   33,   33,   34,
   34,   17,   17,   17,   17,   17,   17,   17,   11,   11,
   18,   18,   19,   14,   14,   14,   14,   30,   30,   30,
   30,   25,   26,   27,   28,   29,   23,   23,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   15,   15,   15,
   15,   21,   21,   21,   21,   21,   21,   21,   21,   20,
   20,   20,   20,   20,   22,   22,   13,   13,   13,   13,
   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    6,
    0,    3,    1,    3,    0,    2,    0,    2,    3,    1,
    1,    5,    7,    5,    9,    0,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    2,    4,    0,    1,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    3,    1,
    1,    1,    3,    3,    3,    3,    3,    1,    1,    1,
    3,    1,    1,    1,    2,    1,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    2,    2,
    2,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    3,    1,    3,    3,    3,
    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,   34,    0,    4,
    2,    5,    6,    0,    8,    9,   20,   21,   30,   31,
   97,   33,    0,    0,    0,    0,    0,    0,    0,   64,
   63,    0,   66,    0,    0,    0,    0,    0,    0,    0,
   58,   36,    0,   84,    0,    0,    0,    0,    7,    0,
    0,    0,    0,    0,    0,   18,    0,    0,    0,   94,
    0,   40,    0,   42,    0,    0,    0,    0,    0,    0,
    0,   92,    0,    0,    0,   90,   91,   59,    0,   62,
   28,    0,   27,   29,    0,   32,   78,   79,    0,   65,
   52,   51,    0,   80,   81,    0,    0,    0,    0,   98,
   99,  100,  101,   19,    0,   95,   96,    0,   13,    0,
   17,   37,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   61,   60,    0,    0,   56,
   57,    0,   12,    0,   41,   76,   77,   17,   50,    0,
   72,   73,   74,   75,   70,   71,   24,    0,   53,   14,
   10,   16,    0,    0,    0,   49,   23,    0,    0,   25,
};
static const short yydgoto[] = {                          1,
  139,   12,   13,   14,   15,   16,  134,   17,   18,   70,
  140,   82,   19,   71,   60,   72,   62,   90,   91,   73,
   42,   21,   74,   22,   75,   44,   76,   77,   78,   48,
   58,  110,   68,   69,    2,
};
static const short yysindex[] = {                         0,
    0,   82,  -28,  -24,  -22,  -14, -227,    0,  -16,    0,
    0,    0,    0,  -23,    0,    0,    0,    0,    0,    0,
    0,    0,  -40,   -2,  -16,  -12,  -12, -229,   -1,    0,
    0,   57,    0, -160, -160,  -37,  -12,    0,    0,    0,
    0,    0, -189,    0,    0,    0,    0,  335,    0,   -8,
   -8,   -8,   -8, -160,  -16,    0, -150,   -4,    0,    0,
    0,    0, -189,    0,    0,    0,    0,   84,   77,   -7,
    0,    0,    0,  -49, -189,    0,    0,    0,   11,    0,
    0,   69,    0,    0,  -44,    0,    0,    0,   -8,    0,
    0,    0,   88,    0,    0,  -12,  -12,  -12,  -12,    0,
    0,    0,    0,    0,  -17,    0,    0,  -56,    0,    7,
    0,    0,  -16,  -12,  -12,   46,  -12,  -12,  -12,  -12,
  -12,  -12,   46,  -12,   89,    0,    0,   80,   80,    0,
    0, -119,    0,   65,    0,    0,    0,    0,    0, -136,
    0,    0,    0,    0,    0,    0,    0,  -53,    0,    0,
    0,    0,   72,   46, -229,    0,    0,  114,   46,    0,
};
static const short yyrindex[] = {                         0,
    0,  157,  -36,    0,    0,    0,    0,    0,  100,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   37,  122,    0,    0,  106,    0,    0,
    0,    2,    0,    0,    0,    0,    0,  102,  109,  129,
    0,    0,  160,    0,  142,  344,  363,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   38,    0,   12,    0,
  382,    0,  406,    0,  425,  435,  442,    0,  125,    0,
   31,    0,   53,  -39,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  388,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  373,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   44,   73,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  126,    0,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    5,    0,    0,    0,    0,  -19,   35,    0,    0,  -13,
  -84,   20,  -18,   83,   22,  358,   78,    0,    0,  347,
  123,  131,  182,    0,  341,   -3,   98,  137,  139,  342,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 517
static const short yytable[] = {                         54,
   22,   69,   89,   54,   55,  155,   11,   62,   81,   83,
  122,   25,  121,   79,   56,   26,   55,   27,   56,   69,
   55,   64,   62,   37,   62,   28,   54,   37,   36,   80,
   39,   29,   36,  116,  104,   49,   36,   57,  147,   34,
   35,   56,   62,   62,   62,   62,   62,  133,   62,   84,
  132,  123,   48,   60,   60,   48,   60,   86,   60,   22,
   62,   62,   62,   62,   93,   93,   93,   93,   93,  157,
   93,   68,   60,   60,  160,   60,   39,   60,   15,   94,
   95,   15,   93,   93,   54,   93,   54,   54,   54,   68,
   68,   38,   68,   67,   58,   58,   25,   58,   80,   58,
  136,  137,   54,   54,   10,   54,   45,   59,  109,   64,
  148,   67,   67,   55,   67,   55,   55,   55,  111,   93,
  113,   98,   65,   10,  112,   22,   99,  124,  126,  149,
   10,   55,   55,   92,   55,   81,   83,   38,  152,  150,
   10,  154,   85,   60,   60,   46,   60,   47,   60,   89,
   94,   94,   45,   94,  159,   94,    1,  152,   35,   11,
   85,   66,   38,   67,   26,   39,   26,   89,  138,   86,
   92,   92,  153,   92,  158,   92,   84,  106,  127,  127,
  127,  127,   82,   90,   90,  107,   90,   86,   90,  151,
  135,   46,    0,   47,    0,   59,  156,    0,    0,    0,
   82,   93,   93,    0,   93,    0,   93,    0,  114,  115,
   65,    0,   94,   95,  117,  118,  119,  120,   87,   30,
    0,    0,   69,   69,   94,   95,    0,   50,   51,   52,
   53,   50,   51,   52,   53,   62,   62,   62,   62,   24,
   30,   31,   32,   33,   30,    0,   32,   33,   30,   66,
   32,   67,   34,   35,  114,  115,   34,   35,    0,   22,
   34,   35,    0,   62,   62,   62,   62,   62,   62,    0,
   62,   62,  114,  115,    0,    0,    0,   22,    0,   22,
   22,   22,   22,   22,    0,   93,   93,   93,   93,   93,
   93,    0,   68,   68,   68,   68,   68,   68,  141,  142,
  143,  144,  145,  146,    3,   54,   54,   54,   54,   54,
   54,    0,    0,    0,   67,   67,   67,   67,   67,   67,
    0,    0,    4,    3,    5,    6,    7,    8,    9,    0,
    3,    0,    0,    0,   55,   55,   55,   55,   55,   55,
    3,    4,   23,    5,    6,    7,    8,    9,    4,   43,
    5,    6,    7,    8,    9,   41,    0,    0,    4,   20,
    5,    6,    7,    8,    9,   63,   40,    0,   85,    0,
    0,   41,    0,    0,   87,   88,   98,   96,    0,   97,
    0,   99,   61,   41,   83,   91,   91,    0,   91,    0,
   91,    0,    0,    0,  105,  108,  100,  101,  102,  103,
    0,   41,   83,   88,   59,   59,    0,   59,    0,   59,
    0,    0,   40,   87,   93,   93,    0,   93,    0,   93,
    0,   88,   47,   92,   92,   47,   92,    0,   92,   60,
   60,   87,   60,    0,   60,  125,    0,  128,  129,  130,
  131,    0,   41,   41,   41,   41,   44,   93,   93,   44,
   93,    0,   93,   63,    0,    0,   23,    0,    0,   41,
    0,    0,    0,   23,    0,   43,   90,   90,   43,   90,
   61,   90,    0,   20,   23,   46,   91,   91,   46,   91,
   20,   91,   45,   59,   59,   45,   59,    0,   59,    0,
    0,   20,    0,   23,   23,   85,    0,    0,    0,   23,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   20,   20,    0,    0,    0,    0,   20,
};
static const short yycheck[] = {                         44,
    0,   41,   40,   44,   61,   59,    2,   44,   28,   28,
   60,   40,   62,   27,   59,   40,   61,   40,   59,   59,
   61,   25,   59,   40,   61,   40,   44,   40,   45,  259,
    9,  259,   45,   41,   54,   59,   45,   40,  123,  269,
  270,   59,   41,   42,   43,   44,   45,   41,   47,   28,
   44,   41,   41,   42,   43,   44,   45,   59,   47,   59,
   59,   60,   61,   62,   41,   42,   43,   44,   45,  154,
   47,   41,   42,   43,  159,   45,   55,   47,   41,  269,
  270,   44,   59,   60,   41,   62,   43,   44,   45,   59,
   60,    9,   62,   41,   42,   43,   40,   45,  259,   47,
  114,  115,   59,   60,   59,   62,    9,   25,  259,  113,
  124,   59,   60,   41,   62,   43,   44,   45,  123,   37,
   44,   42,   25,   59,   41,  125,   47,   59,   41,   41,
   59,   59,   60,   36,   62,  155,  155,   55,  134,  259,
   59,  278,   41,   42,   43,    9,   45,    9,   47,   41,
   42,   43,   55,   45,   41,   47,    0,  153,   59,  123,
   59,   25,   41,   25,   59,   41,   41,   59,  123,   41,
   42,   43,  138,   45,  155,   47,  155,   55,   96,   97,
   98,   99,   41,   42,   43,   55,   45,   59,   47,  125,
  113,   55,   -1,   55,   -1,  113,  125,   -1,   -1,   -1,
   59,   42,   43,   -1,   45,   -1,   47,   -1,  262,  263,
  113,   -1,  269,  270,  264,  265,  266,  267,   59,  257,
   -1,   -1,  262,  263,  269,  270,   -1,  272,  273,  274,
  275,  272,  273,  274,  275,  272,  273,  274,  275,  268,
  257,  258,  259,  260,  257,   -1,  259,  260,  257,  113,
  259,  113,  269,  270,  262,  263,  269,  270,   -1,  259,
  269,  270,   -1,  262,  263,  264,  265,  266,  267,   -1,
  269,  270,  262,  263,   -1,   -1,   -1,  277,   -1,  279,
  280,  281,  282,  283,   -1,  262,  263,  264,  265,  266,
  267,   -1,  262,  263,  264,  265,  266,  267,  117,  118,
  119,  120,  121,  122,  259,  262,  263,  264,  265,  266,
  267,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,  277,  259,  279,  280,  281,  282,  283,   -1,
  259,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
  259,  277,    2,  279,  280,  281,  282,  283,  277,    9,
  279,  280,  281,  282,  283,    9,   -1,   -1,  277,    2,
  279,  280,  281,  282,  283,   25,    9,   -1,   28,   -1,
   -1,   25,   -1,   -1,   34,   35,   42,   43,   -1,   45,
   -1,   47,   25,   37,   41,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   54,   55,   50,   51,   52,   53,
   -1,   55,   59,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   55,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   59,   41,   42,   43,   44,   45,   -1,   47,   42,
   43,   59,   45,   -1,   47,   89,   -1,   96,   97,   98,
   99,   -1,   96,   97,   98,   99,   41,   42,   43,   44,
   45,   -1,   47,  113,   -1,   -1,  116,   -1,   -1,  113,
   -1,   -1,   -1,  123,   -1,   41,   42,   43,   44,   45,
  113,   47,   -1,  116,  134,   41,   42,   43,   44,   45,
  123,   47,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,  134,   -1,  153,  154,  155,   -1,   -1,   -1,  159,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  153,  154,   -1,   -1,   -1,   -1,  159,
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
"var_declar_stmt : id_expr ',' var_declar_stmt",
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
"simple_stmt : interrupt_stmt",
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
#line 291 "a.y"


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
#line 503 "y.tab.c"

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
#line 100 "a.y"
	{ yyval.node = opr(',' , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 20:
#line 105 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 21:
#line 106 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 22:
#line 111 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 23:
#line 112 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 24:
#line 116 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 25:
#line 117 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 26:
#line 122 "a.y"
	{ yyval.node = NULL ; }
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
#line 125 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 30:
#line 130 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 31:
#line 131 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 32:
#line 132 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 33:
#line 133 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 34:
#line 137 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 35:
#line 138 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 36:
#line 139 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 37:
#line 144 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 38:
#line 148 "a.y"
	{ yyval.args = NULL; }
break;
case 39:
#line 149 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 40:
#line 153 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 41:
#line 154 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 42:
#line 158 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 43:
#line 159 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 44:
#line 160 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 45:
#line 161 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 46:
#line 162 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 47:
#line 163 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 164 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 49:
#line 168 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 50:
#line 169 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 51:
#line 175 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 52:
#line 176 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 53:
#line 181 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 54:
#line 187 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 55:
#line 188 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 56:
#line 189 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 57:
#line 190 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 58:
#line 195 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 59:
#line 196 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 60:
#line 197 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 61:
#line 198 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 62:
#line 202 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 63:
#line 206 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 64:
#line 210 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 65:
#line 214 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 66:
#line 218 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 67:
#line 223 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 224 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 69:
#line 229 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 70:
#line 230 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 71:
#line 231 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 72:
#line 232 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 73:
#line 233 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 74:
#line 234 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 75:
#line 235 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 76:
#line 236 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 77:
#line 237 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 78:
#line 242 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 79:
#line 243 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 80:
#line 244 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 81:
#line 245 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 82:
#line 250 "a.y"
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
#line 256 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 257 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 263 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 264 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 265 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 94:
#line 266 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 95:
#line 271 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 96:
#line 272 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 97:
#line 284 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 98:
#line 285 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 99:
#line 286 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 100:
#line 287 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 101:
#line 288 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1105 "y.tab.c"
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
