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
 double iValue; /* integer value */
 bool bValue; /* bool value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
};

%token <iValue> NUMBER 
%token <sValue> VARIABLE
%token OP_CALC AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP FUNC_OP
%token AUTO IF ELSE WHILE FOR
%type <iValue> NUMBER 
%type <node> expr statement block expr_list

%nonassoc ELSE

%right '='
%left GE LE EQ NE '>' '<'
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
	| VARIABLE '=' expr ';' { $$ = opr('=',2,var($1),$3 ); }
	| IF '(' expr ')' block { $$ = opr(IF ,2,$3,$5) ; }
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
	: NUMBER { $$ = number($1); }
	| VARIABLE { /*printf("VARIABLE $1= %s\n" , $1);*/ $$ = var($1); }
	| expr '+' expr { $$ = opr('+',2,$1,$3);}
	| expr '-' expr { $$ = opr('-',2,$1,$3);}
	| expr '*' expr { $$ = opr('*',2,$1,$3);}
	| expr '/' expr { $$ = opr('/',2,$1,$3);}
	| '(' expr ')'  { $$ = $2; }
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