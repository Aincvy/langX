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
};

%token <iValue> TDOUBLE TBOOL
%token <sValue> VARIABLE TSTRING
%token OP_CALC AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP FUNC_OP
%token AUTO IF ELSE WHILE FOR

%type <iValue> TDOUBLE 
%type <node> expr statement block expr_list
%type <sValue> TSTRING

%nonassoc IFX
%nonassoc ELSE

%left ','
%right '='
%left AND_OP OR_OP
%left LE_OP GE_OP EQ_OP NE_OP '>' '<'
%left '+' '-'
%left '*' '/'

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
	| IF '(' expr ')' block %prec IFX { $$ = opr(IF ,2,$3,$5) ; }
	| IF '(' expr ')' block ELSE block { $$ = opr(IF ,3,$3,$5,$7) ; }
	| WHILE '(' expr ')' block { $$ = opr(WHILE , 2, $3, $5 ); }
	| FOR '(' expr ';' expr ';' expr ')' block { $$ = opr(FOR,4,$3,$5,$7,$9); }
	| VARIABLE FUNC_OP '{' expr_list '}' { $$ = func($1,$4);}
	;

block
	: '{' expr_list '}'  { $$ = $2;}
	| statement { $$ = $1; }
	;

expr_list
	: expr_list statement { $$ = opr(';',2,$1, $2); }
	| statement { $$ = $1; }
	;
	
//  表达式， 单条语句 
expr
	: TBOOL   { $$ = number($1); }
	| TDOUBLE { $$ = number($1); }
	| VARIABLE { /*printf("VARIABLE $1= %s\n" , $1);*/ $$ = var($1); }
	| TSTRING  { printf("get a string: %s\n" , $1); $$ = string($1); }
	| expr '+' expr { $$ = opr('+',2,$1,$3);}
	| expr '-' expr { $$ = opr('-',2,$1,$3);}
	| expr '*' expr { $$ = opr('*',2,$1,$3);}
	| expr '/' expr { $$ = opr('/',2,$1,$3);}
	| expr '>' expr { $$ = opr('>',2,$1,$3);}
	| expr '<' expr { $$ = opr('<',2,$1,$3);}
	| expr LE_OP expr { $$ = opr( LE_OP,2,$1,$3);}
	| expr GE_OP expr { $$ = opr( GE_OP,2,$1,$3);}
	| expr EQ_OP expr { $$ = opr( EQ_OP,2,$1,$3);}
	| expr NE_OP expr { $$ = opr( NE_OP,2,$1,$3);}
	| expr ',' expr { $$ = opr(',',2,$1,$3);}
	| expr AND_OP expr { $$ = opr(AND_OP,2,$1,$3);}
	| expr OR_OP expr  { $$ = opr(OR_OP,2,$1,$3); }
	| '(' expr ')'  { $$ = $2; }
	| VARIABLE '=' expr { $$ = opr('=',2,var($1),$3 ); }
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