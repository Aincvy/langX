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

void comment(void);

%}

%%
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-comment */ }

"auto" {return AUTO;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"delete" {return DELETE;}
"false" { yylval.iValue = 0.0; return TBOOL;}
"true" { yylval.iValue = 1.0; return TBOOL;}
"=>"   { return FUNC_OP; }
"++"   { return INC_OP;}
"--"   { return DEC_OP;}

\"(.)*\"   { yylval.sValue = strdup(yytext); return TSTRING;}
[a-zA-Z][a-zA-Z0-9]* { /*printf("get var: %s, length: %d\n" , yytext,yyleng); */ yylval.sValue=strdup(yytext); return VARIABLE;}
([1-9][0-9]*)|0|((0|[1-9][0-9]*)\.[0-9]+) { yylval.iValue = atof(yytext); /*printf("get a double value: %f\n",yylval.iValue );*/ return TDOUBLE;}

"<=" { return LE_OP;}
">=" { return GE_OP;}
"==" { return EQ_OP;}
"!=" { return NE_OP;}
"+=" { return ADD_EQ; }
"-=" { return SUB_EQ; }
"*=" { return MUL_EQ; }
"/=" { return DIV_EQ; }
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

%%

void comment(void)
{
	char c, prev = 0;
  
	while ((c = yyinput()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	//error("unterminated comment");
}
