%{
#include <stdio.h>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

%}

%union {
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
};

%token <iValue> TDOUBLE TBOOL
%token <sValue> IDENTIFIER TSTRING
%token OP_CALC AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP FUNC_OP INC_OP DEC_OP FUNC_CALL
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ
%token AUTO IF ELSE WHILE FOR DELETE

%type <iValue> TDOUBLE 
%type <node> expr statement block expr_list bool_expr assign_expr arithmetic_expr parentheses_expr double_or_ps_expr args_expr_collection number_value_expr id_expr t_bool_expr double_expr uminus_expr string_expr self_assign_expr call_statement
%type <node> bool_param_expr 
%type <sValue> TSTRING
%type <params> param_list parameter
%type <args> args_list args_expr

%nonassoc IFX
%nonassoc ELSE

%left FUNC_OP
%left ','
%right '=' ADD_EQ SUB_EQ MUL_EQ DIV_EQ
%left AND_OP OR_OP
%left LE_OP GE_OP EQ_OP NE_OP '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%start program
%%

program
	: statement_list
	;

statement_list
	: statement_list statement { execAndFreeNode($2);}
	| 
	;
statement
	: ';'      { $$ = opr(';' , 0 ); }
	| expr ';' { $$ = $1; }
	| DELETE IDENTIFIER { $$ = opr(DELETE, 1 ,$2 ); }
	| IF '(' bool_expr ')' block %prec IFX { $$ = opr(IF ,2,$3,$5) ; }
	| IF '(' bool_expr ')' block ELSE block { $$ = opr(IF ,3,$3,$5,$7) ; }
	| WHILE '(' bool_expr ')' block { $$ = opr(WHILE , 2, $3, $5 ); }
	| FOR '(' expr ';' bool_expr ';' expr ')' block { $$ = opr(FOR,4,$3,$5,$7,$9); }
	| IDENTIFIER FUNC_OP param_list '{' expr_list '}' { $$ = func($1,$3,$5);}
	| call_statement    { $$ = $1; }
	;

//  函数调用
call_statement
	: IDENTIFIER '(' args_list ')' ';' { /*$$ = call($1,$3 );*/  $$ = opr(FUNC_CALL,2, var($1), argsNode($3) ); }
	;

param_list
	:           { $$ = NULL; }
	| '(' parameter ')'   { $$ = $2; }
	;

parameter
	: IDENTIFIER { $$ = params(NULL, $1); }
	| parameter ',' IDENTIFIER { params($1,$3); }
	|        { $$ = NULL; }
	;

args_list
	:      { $$ = NULL; }
	| args_expr  { $$ = $1; }
	;

args_expr
	: args_expr_collection   { $$ = xArgs(NULL, $1); }
	| args_expr ',' args_expr_collection   { $$ = xArgs($1, $3); }
	;

args_expr_collection
	: t_bool_expr   { $$ = $1; }
	| double_expr   { $$ = $1; }
	| id_expr       { /*printf("IDENTIFIER $1= %s\n" , $1);*/ $$ = $1; }
	| string_expr   { $$ = $1; }
	| uminus_expr   { $$ = $1; }
	| call_statement { $$ = $1; }
	| bool_expr     { $$ = $1; }
	;

block
	: '{' expr_list '}'  { $$ = $2;}
	| statement { $$ = $1; }
	;

expr_list
	: expr_list statement { $$ = opr(';',2,$1, $2); }
	|   { $$ = NULL; }
	;
	
//  表达式， 单条语句 
expr
	: t_bool_expr   { $$ = $1; }
	| double_expr   { $$ = $1; }
	| id_expr { /*printf("IDENTIFIER $1= %s\n" , $1);*/ $$ = $1; }
	| TSTRING  { printf("get a string: %s\n" , $1); $$ = string($1); }
	| uminus_expr     { $$ = $1; }
	| arithmetic_expr { $$ = $1; }
	| expr ',' expr { $$ = opr(',',2,$1,$3);}
	| parentheses_expr { $$ = $1; }
	| assign_expr   { $$ = $1; }
	;

// 数字或者 小括号表达式
double_or_ps_expr
	: double_expr        { $$ = $1; }
	| parentheses_expr   { $$ = $1; }
	;

parentheses_expr
	: '(' expr ')'  { $$ = $2; }
	;

//  运算表达式
arithmetic_expr
	: number_value_expr '+' number_value_expr { $$ = opr('+',2,$1,$3);}
	| number_value_expr '-' number_value_expr { $$ = opr('-',2,$1,$3);}
	| number_value_expr '*' number_value_expr { $$ = opr('*',2,$1,$3);}
	| number_value_expr '/' number_value_expr { $$ = opr('/',2,$1,$3);}
	;

// 数值， 可能产生 数值值得 表达式都算
number_value_expr
	: id_expr        { $$ = $1 ;}
	| double_expr    { $$ = $1 ;}
	| uminus_expr    { $$ = $1 ;}
	| self_assign_expr { $$ = $1; }
	;

id_expr
	: IDENTIFIER     { $$ = var($1); }
	;

t_bool_expr
	: TBOOL   { $$ = number($1); }
	;

double_expr
	: TDOUBLE { $$ = number($1); }
	;

uminus_expr
	: '-' double_or_ps_expr %prec UMINUS { $$ = opr(UMINUS, 1, $2 ); }
	;

string_expr
	: TSTRING  { printf("get a string: %s\n" , $1); $$ = string($1); }
	;

//  bool 比较的值
bool_param_expr
	: number_value_expr { $$ = $1; }
	| call_statement    { $$ = $1; }
	;

//  可以获得布尔结果的表达式
bool_expr
	: bool_param_expr { $$ = $1; }
	| bool_param_expr '>' bool_param_expr { $$ = opr('>',2,$1,$3);}
	| bool_param_expr '<' bool_param_expr { $$ = opr('<',2,$1,$3);}
	| bool_param_expr LE_OP bool_param_expr { $$ = opr( LE_OP,2,$1,$3);}
	| bool_param_expr GE_OP bool_param_expr { $$ = opr( GE_OP,2,$1,$3);}
	| bool_param_expr EQ_OP bool_param_expr { $$ = opr( EQ_OP,2,$1,$3);}
	| bool_param_expr NE_OP bool_param_expr { $$ = opr( NE_OP,2,$1,$3);}
	| bool_expr AND_OP bool_expr { $$ = opr(AND_OP,2,$1,$3);}
	| bool_expr OR_OP bool_expr  { $$ = opr(OR_OP,2,$1,$3); }
	;

//  自增 OR 自减
self_assign_expr
	: INC_OP id_expr { $$ = opr(INC_OP,1, $2 ); }
	| DEC_OP id_expr { $$ = opr(DEC_OP,1, $2 ); }
	| id_expr INC_OP { $$ = opr(INC_OP,1, $1 ); }
	| id_expr DEC_OP { $$ = opr(DEC_OP,1, $1 ); }
	;

assign_expr
	: self_assign_expr { $$ = $1;}
	| id_expr '=' args_expr_collection { $$ = opr('=',2, $1,$3 ); }
	| id_expr ADD_EQ args_expr_collection { $$ = opr(ADD_EQ,2,$1,$3);}
	| id_expr SUB_EQ args_expr_collection { $$ = opr(SUB_EQ,2,$1,$3);}
	| id_expr MUL_EQ args_expr_collection { $$ = opr(MUL_EQ,2,$1,$3);}
	| id_expr DIV_EQ args_expr_collection { $$ = opr(DIV_EQ,2,$1,$3);}
	;
	
%%

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