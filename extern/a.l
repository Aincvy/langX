%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "../include/YLlangX.h"
#include "y.tab.h"

extern "C"{
int yylex(void);
}

extern YYSTYPE yylval;

void comment(void);
int column = 0; 
void count(void);

%}

%%
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-comment */ }

"auto" {count(); return AUTO;}
"if" {count(); return IF;}
"else" {count(); return ELSE;}
"while" {count(); return WHILE;}
"for" {count(); return FOR;}
"delete" {count(); count(); return DELETE;}
"false" {count();  yylval.iValue = 0.0; return TBOOL;}
"true" {count();  yylval.iValue = 1.0; return TBOOL;}
"break" {count(); return BREAK;}
"return" {count(); return RETURN; }
"switch" { count(); return SWITCH;}
"case"  { count(); return CASE;}
"default" { count(); return DEFAULT; }
"new"  { count();  return NEW; }
"null" { count(); return XNULL; }
"restrict" { count(); return RESTRICT;}
"this" {count();  return THIS; }
"extends"  { count(); return EXTENDS; }
"try"  {count();  return XTRY; }
"catch" {count();  return XCATCH; }
"public" {count(); return XPUBLIC;}
"set"  {count();  return XSET; }
"=>"   {count();  return FUNC_OP; }
"++"   {count();  return INC_OP;}
"--"   {count();  return DEC_OP;}

\"(\\.|[^\\"\n])*\"   {count();  yylval.sValue = strdup(yytext); return TSTRING;}
[a-zA-Z][a-zA-Z0-9]*  {count();  yylval.sValue=strdup(yytext); return IDENTIFIER;}

0|([1-9][0-9]*)           {count();  yylval.intValue = atoi(yytext);  return XINTEGER; }
(0|[1-9][0-9]*)\.[0-9]+ { count(); yylval.iValue = atof(yytext); return TDOUBLE;}

"<=" {count(); return LE_OP;}
">=" {count(); return GE_OP;}
"==" {count(); return EQ_OP;}
"!=" {count(); return NE_OP;}
"+=" {count(); return ADD_EQ; }
"-=" {count(); return SUB_EQ; }
"*=" {count(); return MUL_EQ; }
"/=" {count(); return DIV_EQ; }
"%=" {count(); return MOD_EQ; }
">" {count(); return '>'; }
"<" {count(); return '<'; }
"{" {count(); return '{'; }
"}" {count(); return '}'; }
":" {count(); return ':'; }
"@" {count(); return '@'; }
";" {count(); return ';'; }
"=" {count(); return '='; }
"," {count(); return ','; }
"." {count(); return '.'; }
"[" {count(); return '['; }
"]" {count(); return ']'; }
"&" {count(); return '&'; }
"|" {count(); return '|'; }
"^" {count(); return '^'; }
"~" {count(); return '~'; }
"%" {count(); return '%'; }
"<<" {count(); return LEFT_SHIFT;}
">>" {count(); return RIGHT_SHIFT; }
"&&" {count(); return AND_OP;}
"||" {count(); return OR_OP;}
[+-/*()] {count(); return *yytext;}

[ \t]  {count(); }
[\n]   {count(); yylineno++; }

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

void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	/*ECHO; */
}
