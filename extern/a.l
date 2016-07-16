%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/YLlangX.h"
#include "y.tab.h"

extern "C"{
int yylex(void);
}

extern YYSTYPE yylval;

%}

%%
"auto" {return AUTO;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"false" { yylval.bValue = false; return TBOOL;}
"true" { yylval.bValue = false; return TBOOL;}

\"(.)*\"   { yylval.sValue = strdup(yytext); return TSTRING;}
[a-zA-Z][a-zA-Z0-9]* { /*printf("get var: %s, length: %d\n" , yytext,yyleng); */ yylval.sValue=strdup(yytext); return VARIABLE;}
([1-9][0-9]*)|0|((0|[1-9][0-9]*)\.[0-9]+) { yylval.iValue = atof(yytext); return TDOUBLE;}

">" { return '>'; }
"<" { return '<'; }
"{" { return '{'; }
"}" { return '}'; }
";" { return ';'; }
"=" { return '='; }
"," { return ','; }
[+-/*()] {return *yytext;}
[ \t\n] ;
"&&" { return AND_OP;}
"||" { return OR_OP;}
"<=" { return LE_OP;}
">=" { return GE_OP;}
"==" { return EQ_OP;}
"!=" { return NE_OP;}

%%