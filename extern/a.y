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
%token <sValue> VARIABLE TSTRING
%token OP_CALC AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP FUNC_OP INC_OP DEC_OP 
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ
%token AUTO IF ELSE WHILE FOR DELETE

%type <iValue> TDOUBLE 
%type <node> expr statement block expr_list bool_expr assign_expr arithmetic_expr parentheses_expr double_or_ps_expr args_expr_collection
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
	| DELETE VARIABLE { $$ = opr(DELETE, 1 ,$2 ); }
	| IF '(' expr ')' block %prec IFX { $$ = opr(IF ,2,$3,$5) ; }
	| IF '(' expr ')' block ELSE block { $$ = opr(IF ,3,$3,$5,$7) ; }
	| WHILE '(' expr ')' block { $$ = opr(WHILE , 2, $3, $5 ); }
	| FOR '(' expr ';' expr ';' expr ')' block { $$ = opr(FOR,4,$3,$5,$7,$9); }
	| VARIABLE FUNC_OP param_list '{' expr_list '}' { $$ = func($1,$3,$5);}
	| VARIABLE '(' args_list ')' ';' { $$ = call($1,$3 ); }
	;

param_list
	:           { $$ = NULL; }
	| '(' parameter ')'   { $$ = $2; }
	;

parameter
	: VARIABLE { $$ = params(NULL, $1); }
	| parameter ',' VARIABLE { params($1,$3); }
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
	: TBOOL   { $$ = number($1); }
	| TDOUBLE { $$ = number($1); }
	| VARIABLE { /*printf("VARIABLE $1= %s\n" , $1);*/ $$ = var($1); }
	| TSTRING  { printf("get a string: %s\n" , $1); $$ = string($1); }
	| '-' double_or_ps_expr %prec UMINUS { $$ = opr(UMINUS, 1, $2 ); }
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
	: TBOOL   { $$ = number($1); }
	| TDOUBLE { $$ = number($1); }
	| VARIABLE { /*printf("VARIABLE $1= %s\n" , $1);*/ $$ = var($1); }
	| TSTRING  { printf("get a string: %s\n" , $1); $$ = string($1); }
	| '-' double_or_ps_expr %prec UMINUS { $$ = opr(UMINUS, 1, $2 ); }
	| arithmetic_expr { $$ = $1; }
	| expr ',' expr { $$ = opr(',',2,$1,$3);}
	| parentheses_expr { $$ = $1; }
	| bool_expr     { $$ = $1; }
	| assign_expr   { $$ = $1; }
	;

// 数字或者 小括号表达式
double_or_ps_expr
	: TDOUBLE            { $$ = number($1); }
	| parentheses_expr   { $$ = $1; }
	;

parentheses_expr
	: '(' expr ')'  { $$ = $2; }
	;

//  运算表达式
arithmetic_expr
	: expr '+' expr { $$ = opr('+',2,$1,$3);}
	| expr '-' expr { $$ = opr('-',2,$1,$3);}
	| expr '*' expr { $$ = opr('*',2,$1,$3);}
	| expr '/' expr { $$ = opr('/',2,$1,$3);}
	;

bool_expr
	: expr '>' expr { $$ = opr('>',2,$1,$3);}
	| expr '<' expr { $$ = opr('<',2,$1,$3);}
	| expr LE_OP expr { $$ = opr( LE_OP,2,$1,$3);}
	| expr GE_OP expr { $$ = opr( GE_OP,2,$1,$3);}
	| expr EQ_OP expr { $$ = opr( EQ_OP,2,$1,$3);}
	| expr NE_OP expr { $$ = opr( NE_OP,2,$1,$3);}
	| expr AND_OP expr { $$ = opr(AND_OP,2,$1,$3);}
	| expr OR_OP expr  { $$ = opr(OR_OP,2,$1,$3); }
	;

assign_expr
	: INC_OP VARIABLE { $$ = opr(INC_OP,1, var($2) ); }
	| DEC_OP VARIABLE { $$ = opr(DEC_OP,1, var($2) ); }
	| VARIABLE INC_OP { $$ = opr(INC_OP,1, var($1) ); }
	| VARIABLE DEC_OP { $$ = opr(DEC_OP,1, var($1) ); }
	| VARIABLE '=' expr { $$ = opr('=',2,var($1),$3 ); }
	| VARIABLE ADD_EQ expr { $$ = opr(ADD_EQ,2,var($1),$3);}
	| VARIABLE SUB_EQ expr { $$ = opr(SUB_EQ,2,var($1),$3);}
	| VARIABLE MUL_EQ expr { $$ = opr(MUL_EQ,2,var($1),$3);}
	| VARIABLE DIV_EQ expr { $$ = opr(DIV_EQ,2,var($1),$3);}
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