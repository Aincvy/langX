%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "../include/NodeCreator.h"
#include "y.tab.h"

extern "C"{
int yylex(void);
}

extern YYSTYPE yylval;

void comment(void);
int column = 0;
void count(void);

#define MAX_INCLUDE_DEPTH 45
YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
int line_stack[MAX_INCLUDE_DEPTH] ;       // 记录行的栈
int now_line = 1 ;     // 当前行
//  这个数值永远指向栈顶
int include_stack_ptr = -1;
//  文件深度 默认是0 ，解析文件1 ，将会变成1
//           如果文件1包含文件2， 那么解析文件2的时候，文件深度就为2
//           退回到文件1的时候， 文件深度就会变成1
int fileDeep = 0 ;

// 切换缓冲区到 文件指针
void pushBuffer(FILE *fp);

// 获得当前是在解析第几行
int getParseLineNo();

// lex 中的 文件结束的内容
void lexEOFWork();

%}

%%
"/*"			{ comment(); }
"//"[^\n]*      { /* consume //-comment */  }

"attr"  {count();  return KEY_SET; }
"using"  {count();  return KEY_REF ;}

"auto" {count(); return KEY_AUTO;}
"if" {count(); return KEY_IF;}
"else" {count(); return KEY_ELSE;}
"while" {count(); return KEY_WHILE;}
"for" {count(); return KEY_FOR;}
"delete" {count(); return KEY_DELETE;}
"false" {count();  yylval.iValue = 0; return TBOOL;}
"true" {count();  yylval.iValue = 1; return TBOOL;}
"break" {count(); return KEY_BREAK;}
"return" {count(); return KEY_RETURN; }
"switch" { count(); return KEY_SWITCH;}
"case"  { count(); return KEY_CASE;}
"default" { count(); return KEY_DEFAULT; }
"new"  { count();  return KEY_NEW; }
"null" { count(); return KEY_NULL; }
"restrict" { count(); return KEY_RESTRICT;}
"this" {count();  return KEY_THIS; }
"extends"  { count(); return KEY_EXTENDS; }
"try"  {count();  return KEY_TRY; }
"catch" {count();  return KEY_CATCH; }
"public" {count(); return KEY_PUBLIC;}
"is"   {count();  return KEY_IS; }
"continue" { count(); return KEY_CONTINUE; }
"const" { count(); return KEY_CONST; }
"local" { count(); return KEY_LOCAL; }

"=>"   {count();  return FUNC_OP; }
"/>" {count(); return PIPELINE_OP; }
"++"   {count();  return INC_OP;}
"--"   {count();  return DEC_OP;}


\"(\\.|[^\\"\n])*\"   {count();  yylval.sValue = strdup(yytext); return TSTRING;}
[$_a-zA-Z][$_a-zA-Z0-9]*  {count(); yylval.sValue=strdup(yytext); return IDENTIFIER;}
$[\?#]+              {count(); yylval.sValue=strdup(yytext); return IDENTIFIER;}

operator([\+\-\*\/\.\=]|<<|>>|\+\+|\-\-|\[\])  {count();  yylval.sValue=strdup(yytext); return OPERATOR_X__;  }

0|([1-9][0-9]*)           {count();  yylval.iValue = atoi(yytext);  return TINTEGER; }
(0|[1-9][0-9]*)\.[0-9]+ { count(); yylval.dValue = atof(yytext); return TDOUBLE;}

"<=" {count(); return LE_OP;}
">=" {count(); return GE_OP;}
"==" {count(); return EQ_OP;}
"!=" {count(); return NE_OP;}
"+=" {count(); return ADD_EQ; }
"-=" {count(); return SUB_EQ; }
"*=" {count(); return MUL_EQ; }
"/=" {count(); return DIV_EQ; }
"%=" {count(); return MOD_EQ; }
"::" {count(); return SCOPE;}
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
"!" {count(); return '!'; }
"^" {count(); return '^'; }
"~" {count(); return '~'; }
"%" {count(); return '%'; }
"<<" {count(); return LEFT_SHIFT;}
">>" {count(); return RIGHT_SHIFT; }
"&&" {count(); return AND_OP;}
"||" {count(); return OR_OP;}
[+-/*()] {count(); return *yytext;}

[ \t]  {count(); }
[\n]   {count(); now_line++; }

<<EOF>> {
	// 这里只标记一下文件结束了， 在下一个节点执行结束的时候才会真正的结束文件
	endOfFileFlag();

	// 通知yacc 文件已经结束
	// return YY_NULL;

	//printf("read one file over! stack_ptr: %d\n" , include_stack_ptr);
	bool flag = false;

	if(fileDeep-- > 1){
	  // 包含文件栈 存在其他缓冲区
	  yy_delete_buffer( YY_CURRENT_BUFFER );
	  yy_switch_to_buffer(
		include_stack[include_stack_ptr] );

	  // 删除栈顶元素
	  include_stack[include_stack_ptr] = NULL ;
	  // 调整行信息
	  now_line = line_stack[ include_stack_ptr ] ;
	  line_stack[ include_stack_ptr ] = 0 ;
	  //
	  include_stack_ptr-- ;
	  //printf("remove stack top buffer to current.\n");
	}else{
		flag = true;
	}

	if(flag){
		yyParseStopped();

		// yyterminate() 是一个宏。。  不是一个方法。。 会执行return 语句
		yyterminate();
	}

}

%%

void lexEOFWork(){

	popStateFrame();
	fileEOF();

}


int getParseLineNo(){
	return now_line ;
}

void pushBuffer(FILE *fp){

	//printf("pushBuffer %d\n" , include_stack_ptr);

    if(fp == NULL )
	  return ;

	if(++fileDeep > 1) {
		if ( include_stack_ptr >= MAX_INCLUDE_DEPTH )
		{
			fprintf( stderr, "Includes nested too deeply" );
			exit( 1 );
		}
		include_stack[++include_stack_ptr] = YY_CURRENT_BUFFER;
		line_stack[include_stack_ptr] = now_line ;
		//printf("add current buffer to stack.\n");
	}

	now_line = 1;
	column = 0;
	yyin = fp;
	yy_switch_to_buffer( yy_create_buffer( yyin, YY_BUF_SIZE ) );
	BEGIN(INITIAL);
}


void comment(void)
{
	char c, prev = 0;

	while ((c = yyinput()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '\n') {
			now_line++ ;
			column = 0;
		}
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	//error("unterminated comment");
}

void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++) {
		if (yytext[i] == '\n'){
			column = 0;
		} else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else {
			column++;
		}
	}

	// printf("after count %s, column: %d\n", yytext, column);
}
