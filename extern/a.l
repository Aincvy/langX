%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include "../include/NodeCreator.h"
#include "../include/LogManager.h"
#include "y.tab.h"

extern "C"{
int yylex(void);
}

extern YYSTYPE yylval;

// 。。
typedef struct {
	// Yacc 得 buffer
	YY_BUFFER_STATE state;
	// 上面得 buffer 对应得文件名， 这个指针是需要释放得
	char *parsingFile;
	// 解析到得行数
	int line;
} includeLayer;

void comment(void);
int column = 0;
void count(void);

#define MAX_INCLUDE_DEPTH 45
includeLayer include_stack[MAX_INCLUDE_DEPTH];

// 当前行
int now_line = 1 ;
//  这个数值永远指向栈顶
int include_stack_ptr = -1;
//  文件深度 默认是0 ，解析文件1 ，将会变成1
//           如果文件1包含文件2， 那么解析文件2的时候，文件深度就为2
//           退回到文件1的时候， 文件深度就会变成1
int fileDeep = 0 ;

// 正在解析中得文件得名字
char *parsingFile = nullptr;

// 切换缓冲区到 文件指针
void pushBuffer(FILE *fp, const char* fileName);

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
"delete_var" {count(); return KEY_DELETE;}
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
	auto p = getParsingFilename();

	// 如果没有当前正在解析得文件， 或者正在解析得文件和当前文件不一致， 则终止解析？
	if( !p || !parsingFile) {

		// yyterminate() 是一个宏。。  不是一个方法。。 会执行return 语句
		yyterminate();
	}

	return TOKEN_END_OF_FILE;
}

%%


void lexEOFWork(){

	langX::logger->debug("on end of file.. %s", parsingFile);

	popStateFrame();
	fileEOF();

	// 释放 文件名占用得内存
	free(parsingFile);
	parsingFile = nullptr;

	// 判断一下 是否还有其他得文件需要解析
	if(fileDeep-- > 1){
	  // 包含文件栈 存在其他缓冲区
	  auto & stack = include_stack[include_stack_ptr--];

	  // 切换 yacc 解析得缓冲区
	  yy_delete_buffer( YY_CURRENT_BUFFER );
	  yy_switch_to_buffer( stack.state );

	  // 调整行信息
	  now_line = stack.line ;

	  // 恢复解析得文件信息
	  parsingFile = stack.parsingFile;

	  // 重置元素得属性
	  stack.state = nullptr;
	  stack.line = 0;
	  stack.parsingFile = nullptr;


	}else{
		yyParseStopped();
	}

}


int getParseLineNo(){
	return now_line ;
}

void pushBuffer(FILE *fp, const char* fileName){
	if(fp == NULL )
	  return ;

	if(++fileDeep > 1) {
		if ( include_stack_ptr >= MAX_INCLUDE_DEPTH )
		{
			fprintf( stderr, "Includes nested too deeply" );
			exit( 1 );
		}

		auto & stack = include_stack[++include_stack_ptr];
		stack.state = YY_CURRENT_BUFFER;
		stack.parsingFile = parsingFile;
		stack.line = now_line;
		// line_stack[include_stack_ptr] = now_line ;
	}

	// copy fileName;
	// todo 释放指针
	parsingFile = strdup(fileName);
	langX::logger->debug("pushBuffer file.. %s", parsingFile);

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
