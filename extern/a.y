%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

extern int getParseLineNo();
extern int column; 
extern char * yytext;

char *namespaceNameCat(char *,char *);

%}

%union {
 int intValue;
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
};

%token <intValue> XINTEGER 
%token <iValue> TDOUBLE TBOOL
%token <sValue> IDENTIFIER TSTRING OPERATOR_X__
%token OP_CALC AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP FUNC_OP INC_OP DEC_OP FUNC_CALL VAR_DECLAR RESTRICT THIS EXTENDS ARRAY_ELE XTRY XCATCH
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ LEFT_SHIFT RIGHT_SHIFT MOD_EQ XPUBLIC XSET XIS SCOPE SCOPE_FUNC_CALL REQUIRE REQUIRE_ONCE REF XCONTINUE XCONST XLOCAL 
%token AUTO IF ELSE WHILE FOR DELETE BREAK RETURN SWITCH CASE DEFAULT CASE_LIST CLAXX_BODY NEW CLAXX_MEMBER CLAXX_FUNC_CALL XNULL XINCLUDE

%type <node> statement declar_stmt con_ctl_stmt simple_stmt func_declar_stmt var_declar_stmt expr_list  selection_stmt loop_stmt logic_stmt block for_1_stmt assign_stmt arithmetic_stmt self_inc_dec_stmt
%type <node> call_statement args_expr_collection double_or_ps_expr parentheses_stmt assign_stmt_value_eq assign_stmt_value single_assign_stmt bool_param_expr interrupt_stmt new_expr try_stmt catch_block_stmt
%type <node> id_expr t_bool_expr double_expr uminus_expr string_expr arithmetic_stmt_factor case_stmt_list case_stmt class_declar_stmt class_body class_body_stmt namespace_declar_stmt
%type <node> class_member_stmt class_member_assign_stmt class_member_func_stmt null_expr restrict_stmt this_stmt this_member_stmt array_ele_stmt array_ele_assign_stmt bit_opr_factor local_declar_stmt
%type <node> type_judge_stmt lambda_stmt static_member_stmt require_stmt const_declar_stmt
%type <params> param_list parameter lambda_args_stmt
%type <args> args_list args_expr
%type <sValue> extends_stmt namespace_name_stmt

/* 优先级是从低到高 */

%nonassoc NONASSOC

%nonassoc IFX
%nonassoc ELSE

%left ','
%right '=' ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ 
%left OR_OP
%left AND_OP
%left '|' 
%left '^'
%left '&' 
%left EQ_OP NE_OP
%left LE_OP GE_OP '>' '<'
%left LEFT_SHIFT RIGHT_SHIFT
%left '+' '-'
%left '*' '/' '%'
%right '~' 
%left '.' '(' ')' '[' ']'
%left FUNC_OP
%nonassoc PRIORITY3
%nonassoc PRIORITY2
%nonassoc PRIORITY1
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
	| declar_stmt    { $$ = $1; }
	| con_ctl_stmt   { $$ = $1; }
	| simple_stmt ';'   { $$ = $1; }
	| require_stmt   { $$ = $1; }
	| try_stmt       { $$ = $1; }
	;

// 需求语句 / ref 语句
require_stmt
	: REQUIRE string_expr         { $$ = opr(REQUIRE , 1 , $2); }
	| REQUIRE_ONCE string_expr    { $$ = opr(REQUIRE_ONCE , 1 , $2); }
	| XINCLUDE string_expr        { $$ = opr(XINCLUDE , 1 , $2); }
	| REF namespace_name_stmt ';' { $$ = opr(REF , 1, string($2)); }
	;

// try 语句
try_stmt
	: XTRY '{' expr_list '}'   { $$ = opr(XTRY, 2,$3,NULL); }
	| XTRY '{' expr_list '}' catch_block_stmt  { $$ = opr(XTRY, 2,$3,$5); }
	;

catch_block_stmt
	: XCATCH '(' id_expr ')' '{' expr_list '}'  { $$ = opr(XCATCH, 2, $3,$6); }
	;

//  声明语句
declar_stmt
	: func_declar_stmt   { $$ = $1; }
	| var_declar_stmt    { $$ = $1; }
	| class_declar_stmt  %prec PRIORITY1 { $$ = $1; }
	| namespace_declar_stmt ';' { $$ = $1; }
	| const_declar_stmt { $$ = $1; }   
	| local_declar_stmt  %prec PRIORITY3 { $$ = $1; }
	;

//  带修饰的 变量声明语句
const_declar_stmt
	: XCONST var_declar_stmt { $$ = opr(XCONST , 1,$2); }
	;

//  带 local 关键字修饰的 语句
local_declar_stmt
	: XLOCAL var_declar_stmt   { $$ = opr(XLOCAL , 1,$2); }
	| XLOCAL class_declar_stmt { $$ = opr(XLOCAL , 1,$2); } 
	;

// 命名空间的声明语句
namespace_declar_stmt
	: XSET XPUBLIC '=' namespace_name_stmt { $$ = changeNameSpace($4); }
	;

namespace_name_stmt
	: IDENTIFIER  { $$ = $1 ; }
	| namespace_name_stmt '.' IDENTIFIER { $$ = namespaceNameCat($1,$3) ; }
	;

//  类声明语句
class_declar_stmt
	: IDENTIFIER extends_stmt '{' '}'            { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ $$ = claxx($1 , $2, NULL,false); }
	| IDENTIFIER extends_stmt '{' class_body '}' { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ $$ = claxx($1 , $2, $4,false); }
	| AUTO IDENTIFIER extends_stmt '{' '}'            { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ $$ = claxx($2 , $3, NULL,true); }
	| AUTO IDENTIFIER extends_stmt '{' class_body '}' { /*if($2 != NULL) printf("parentName: %s\n",$2);*/ $$ = claxx($2 , $3, $5, true); }
	;

//  类继承语句
extends_stmt
	:                     { $$ = NULL; }
	| EXTENDS IDENTIFIER  { $$ = $2; }
	;

//  类主体
class_body
	: class_body_stmt            { $$ = opr(CLAXX_BODY, 1, $1); }
	| class_body class_body_stmt { $$ = opr(CLAXX_BODY, 2, $1, $2); }
	;

class_body_stmt
	: var_declar_stmt        { $$ = $1; }
	| single_assign_stmt ';' { $$ = $1; }
	| func_declar_stmt       { $$ = $1; }
	;

//  this 语句， 暂只支持1级调用
this_stmt
	: THIS    { $$ = opr(THIS , 0 ); }
	| THIS '.' id_expr   {  $$ = opr(THIS,1,$3); }
//	| THIS '.' class_member_stmt {  $$ = opr(THIS, 1, $3 ); }
	| THIS '.' id_expr '(' args_list ')' { $$ = opr(THIS, 1 , opr(FUNC_CALL,2, $3, argsNode($5) ) ); } 
//	| THIS '.' class_member_func_stmt  {}
	;

this_member_stmt
	: THIS '.' id_expr    {  $$ = opr(THIS,1,$3); }
	| THIS '.' class_member_stmt  {  $$ = opr(THIS, 1, $3 ); }
	;

//  类成员。  比如 a.x  a.y  这样 a.y.x
class_member_stmt
	: id_expr '.' id_expr   { $$ = opr(CLAXX_MEMBER,2, $1,$3 ); }
	| class_member_func_stmt '.' id_expr %prec UMINUS { $$ =  opr(CLAXX_MEMBER,2, $1,$3 );  }
	| IDENTIFIER '(' args_list ')' '.' id_expr { $$ = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var($1), argsNode($3) ) , $6); }
	| class_member_stmt '.' id_expr  { $$ = opr(CLAXX_MEMBER,2, $1,$3 ); }
	;

//  类的成员函数调用 
class_member_func_stmt
	: id_expr '.' id_expr '(' args_list ')'  { $$ = opr(CLAXX_FUNC_CALL , 2, $1, opr(FUNC_CALL,2, $3, argsNode($5) ) );}
	| IDENTIFIER '(' args_list ')' '.' id_expr '(' args_list ')' { $$ = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var($1), argsNode($3) ) , opr(FUNC_CALL,2, $6, argsNode($8) )); }
	| class_member_stmt '.' id_expr '(' args_list ')'         { $$ = opr(CLAXX_FUNC_CALL,2,$1,opr(FUNC_CALL,2, $3, argsNode($5) ) ); }
	| class_member_func_stmt '.' id_expr '(' args_list ')'    { $$ = opr(CLAXX_FUNC_CALL,2,$1,opr(FUNC_CALL,2, $3, argsNode($5) ) ); }
	;

//  静态成员
static_member_stmt
	: id_expr SCOPE id_expr   { $$ = opr(SCOPE, 2 ,$1,$3) ; }
	;


// 函数声明语句
func_declar_stmt
	: '~' IDENTIFIER FUNC_OP param_list '{' expr_list '}' { $$ = dtrt($2,$4,$6);}
	| IDENTIFIER FUNC_OP param_list '{' expr_list '}' { $$ = func($1,$3,$5);}
	| OPERATOR_X__ FUNC_OP param_list '{' expr_list '}' { $$ = func($1,$3,$5);}
	;

// lambda 表达式
lambda_stmt
	: '(' parameter ')' FUNC_OP '{' expr_list '}' { $$ = lambda($2,$6) ;}
	| IDENTIFIER FUNC_OP '{' expr_list '}'   { $$ = lambda(params(NULL, $1),$4) ; }
	| lambda_args_stmt FUNC_OP '{' expr_list '}'   { $$ = lambda($1,$4) ; }
	;

lambda_args_stmt
	: IDENTIFIER ',' IDENTIFIER { $$ = params2($1,$3);  }
	| lambda_args_stmt ',' IDENTIFIER  { $$ = params($1,$3);  }
	;

param_list
	:           { $$ = NULL; }
	| '(' parameter ')'   { $$ = $2; }
	;

parameter
	: IDENTIFIER { $$ = params(NULL, $1); }
	| parameter ',' IDENTIFIER { $$ = params($1,$3); }
	|        { $$ = NULL; }
	;

expr_list
	: expr_list statement { $$ = opr(';',2,$1, $2); }
	|   { $$ = NULL; }
	;	

// 变量声明语句  
var_declar_stmt
	: id_expr ';'  { $$ = opr(VAR_DECLAR , 1, $1 ); }
	| id_expr ',' var_declar_stmt { $$ = opr(VAR_DECLAR , 2, $1,$3);}
	| IDENTIFIER '[' XINTEGER ']' ';' { $$ = opr(VAR_DECLAR , 1, arrayNode($1,$3,NULL) ); }
	| IDENTIFIER '[' XINTEGER ']' ',' var_declar_stmt  { $$ = opr(VAR_DECLAR , 2, arrayNode($1,$3,NULL),$6); }
	| IDENTIFIER '[' IDENTIFIER ']' ';' %prec UMINUS {  $$ = opr(VAR_DECLAR , 1, arrayNode($1,-1,var($3)) ); }
	| IDENTIFIER '[' IDENTIFIER ']' ',' var_declar_stmt {  $$ = opr(VAR_DECLAR , 2, arrayNode($1,-1,var($3)),$6); }
	| IDENTIFIER '[' call_statement ']' ';' { $$ = opr(VAR_DECLAR , 1, arrayNode($1,-1, $3) ); } 
	| IDENTIFIER '[' call_statement ']' ',' var_declar_stmt { $$ = opr(VAR_DECLAR , 2, arrayNode($1,-1, $3),$6 ); } 
	;
	
//  条件控制语句
con_ctl_stmt
	: selection_stmt    { $$ = $1; }
	| loop_stmt         { $$ = $1; }
	;

//  选择语句
selection_stmt
	: IF '(' logic_stmt ')' block %prec IFX { $$ = opr(IF ,2,$3,$5) ; }
	| IF '(' logic_stmt ')' block ELSE block { $$ = opr(IF ,3,$3,$5,$7) ; }
	| SWITCH '(' id_expr ')' '{' case_stmt_list '}'  { $$ = opr(SWITCH, 2 , $3,$6); pretreatSwitch( $$ ) ; }
	;

case_stmt_list
	: case_stmt            { $$ = opr(CASE_LIST , 1 ,$1 ); }
	| case_stmt_list case_stmt { $$ = opr(CASE_LIST , 2 ,$1, $2 ); }
	;

case_stmt
	: CASE double_expr ':' expr_list        { $$ = opr(CASE, 2 , $2, $4); }
	| DEFAULT ':' expr_list                 { $$ = opr(DEFAULT , 1, $3); }
	;
	
loop_stmt
	: WHILE '(' logic_stmt ')' block { $$ = opr(WHILE , 2, $3, $5 ); }
	| FOR '(' for_1_stmt ';' logic_stmt ';' for_1_stmt ')' block { $$ = opr(FOR,4,$3,$5,$7,$9); }
	;

//  for 括号内的东西
for_1_stmt
	:     { $$ = NULL ; }
	| assign_stmt  { $$ = $1; }
	| var_declar_stmt { $$ = $1; }
	| self_inc_dec_stmt { $$ = $1; }
	;
	
//  简单语句
simple_stmt
	: assign_stmt   { $$ = $1; }
	| call_statement { $$ = $1; }
	| DELETE IDENTIFIER { $$ = opr(DELETE, 1 ,$2 ); }
	| interrupt_stmt { $$ = $1; }
	| new_expr       { $$ = $1; }
	| restrict_stmt  { $$ = $1; }
	| XCONTINUE { $$ = opr(XCONTINUE , 0 ); }
	;

//  限定语句， 限定环境
restrict_stmt
	: RESTRICT       { $$ = opr(RESTRICT,0);}
	| RESTRICT t_bool_expr  { $$ = opr(RESTRICT,1,$2); }
	;
	
interrupt_stmt
	: BREAK { $$ = opr(BREAK, 0); }
	| RETURN { $$ = opr(RETURN , 0); }
	| RETURN assign_stmt_value { $$ = opr(RETURN , 1 ,$2);} 
	;

//  函数调用
call_statement
	: IDENTIFIER '(' args_list ')' { /*$$ = call($1,$3 );*/  $$ = opr(FUNC_CALL,2, var($1), argsNode($3) ); }
	| class_member_func_stmt  { $$ = $1; }
	| static_member_stmt '(' args_list ')' { $$ = opr(SCOPE_FUNC_CALL,2,$1,argsNode($3)); }
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
	: lambda_stmt   %prec PRIORITY1 { $$ = $1; }
	| t_bool_expr   { $$ = $1; }
	| double_expr   { $$ = $1; }
	| IDENTIFIER    %prec PRIORITY3 { /*printf("IDENTIFIER $1= %s\n" , $1);*/ $$ = var($1); }
	| string_expr   { $$ = $1; }
	| uminus_expr   { $$ = $1; }
	| call_statement { $$ = $1; }
	| arithmetic_stmt { $$ = $1;}
	| array_ele_stmt  { $$ = $1;}
	| class_member_stmt  { $$ = $1; }
	| static_member_stmt { $$ = $1; }
	| new_expr        { $$ = $1;}
	;

block
	: '{' expr_list '}'  { $$ = $2;}
	| statement { $$ = $1; }
	;
	

// 数字或者 小括号表达式
double_or_ps_expr
	: double_expr        { $$ = $1; }
	| parentheses_stmt   { $$ = $1; }
	;

//  小括号表达式
parentheses_stmt
	: '(' assign_stmt_value_eq ')'  { $$ = $2; }
	;


//  运算语句
arithmetic_stmt
	: arithmetic_stmt_factor '+' arithmetic_stmt_factor { $$ = opr('+',2,$1,$3); }
	| arithmetic_stmt_factor '-' arithmetic_stmt_factor { $$ = opr('-',2,$1,$3); }
	| arithmetic_stmt_factor '*' arithmetic_stmt_factor { $$ = opr('*',2,$1,$3); }
	| arithmetic_stmt_factor '/' arithmetic_stmt_factor { $$ = opr('/',2,$1,$3); }
	| arithmetic_stmt_factor '%' arithmetic_stmt_factor { $$ = opr('%',2,$1,$3); }
	| bit_opr_factor '&' bit_opr_factor  { $$ = opr('&',2,$1,$3); }
	| bit_opr_factor '|' bit_opr_factor  { $$ = opr('|',2,$1,$3); }
	| bit_opr_factor '^' bit_opr_factor  { $$ = opr('^',2,$1,$3); }
	| '~' bit_opr_factor  { /* printf("get a ~ opr.\n"); */ $$ = opr('~',1,$2); }
	| bit_opr_factor LEFT_SHIFT bit_opr_factor  { $$ = opr(LEFT_SHIFT,2,$1,$3); }
	| bit_opr_factor RIGHT_SHIFT bit_opr_factor  { $$ = opr(RIGHT_SHIFT,2,$1,$3); }
	;

// 位运算的  因子
bit_opr_factor
	: XINTEGER { $$ = xint($1); }
	| id_expr  { $$ = $1; }
	;

//  运算语句的分子
arithmetic_stmt_factor
	: assign_stmt_value_eq    { $$ = $1 ; }
	| string_expr             { $$ = $1 ; }
	| arithmetic_stmt         { $$ = $1 ; }
	| '(' arithmetic_stmt ')' { $$ = $2 ; }
	;

//   new 表达式
new_expr
	: NEW id_expr '(' args_list ')' { $$ = opr(NEW ,2, $2 , argsNode($4) ); }
	;

id_expr
	: IDENTIFIER { $$ = var($1); }
	;

t_bool_expr
	: TBOOL   { $$ = number($1); }
	;

double_expr
	: TDOUBLE { $$ = number($1); }
	| XINTEGER { $$ = number($1); }
	;

uminus_expr
	: '-' double_or_ps_expr %prec UMINUS { $$ = opr(UMINUS, 1, $2 ); }
	| '-' id_expr %prec UMINUS           { $$ = opr(UMINUS, 1, $2 ); }
	;

string_expr
	: TSTRING  { $$ = string($1); }
	;

null_expr
	: XNULL   { $$ = xnull();}
	;

//  bool 比较的值
bool_param_expr
	: assign_stmt_value_eq { $$ = $1; }
	| arithmetic_stmt     { $$ = $1; }
	| t_bool_expr         { $$ = $1; }
	| string_expr         { $$ = $1; }
	| null_expr           { $$ = $1; }
	;

//  逻辑语句 
logic_stmt
	: bool_param_expr { $$ = $1; }
	| type_judge_stmt { $$ = $1; }
	| bool_param_expr '>' bool_param_expr { $$ = opr('>',2,$1,$3);}
	| bool_param_expr '<' bool_param_expr { $$ = opr('<',2,$1,$3);}
	| bool_param_expr LE_OP bool_param_expr { $$ = opr( LE_OP,2,$1,$3);}
	| bool_param_expr GE_OP bool_param_expr { $$ = opr( GE_OP,2,$1,$3);}
	| bool_param_expr EQ_OP bool_param_expr { $$ = opr( EQ_OP,2,$1,$3);}
	| bool_param_expr NE_OP bool_param_expr { $$ = opr( NE_OP,2,$1,$3);}
	| logic_stmt AND_OP logic_stmt { $$ = opr(AND_OP,2,$1,$3);}
	| logic_stmt OR_OP logic_stmt  { $$ = opr(OR_OP,2,$1,$3); }
	;

// 类型判断语句
type_judge_stmt
	: id_expr XIS id_expr  { $$ = opr(XIS ,2 , $1,$3); }
	;

//  自增 OR 自减
self_inc_dec_stmt
	: INC_OP id_expr { $$ = opr(INC_OP,1, $2 ); }
	| DEC_OP id_expr { $$ = opr(DEC_OP,1, $2 ); }
	| id_expr INC_OP { $$ = sopr(INC_OP,1, $1 ); }
	| id_expr DEC_OP { $$ = sopr(DEC_OP,1, $1 ); }
	;

//  赋值语句的值
assign_stmt_value
	: double_expr   { $$ = $1; }
	| uminus_expr   { $$ = $1; }
	| t_bool_expr   { $$ = $1; }
	| arithmetic_stmt { $$ = $1; }
	| call_statement  { $$ = $1; }
	| lambda_stmt   { $$ = $1; }
	| id_expr       { $$ = $1; }
	| string_expr   { $$ = $1; }
	| self_inc_dec_stmt { $$ = $1; }
	| new_expr       { $$ = $1; }
	| class_member_stmt  %prec NONASSOC { $$ = $1; }
	| null_expr      { $$ = $1; }
	| this_stmt    %prec UMINUS  { $$ = $1; }
	| array_ele_stmt  { $$ = $1; }
	| static_member_stmt { $$ =$1 ;}
	;

//  += -= *= /=  的值
assign_stmt_value_eq
	: double_expr   { $$ = $1; }
	| uminus_expr   { $$ = $1; }
	| call_statement    { $$ = $1; }
	| id_expr       { $$ = $1; }
	| self_inc_dec_stmt { $$ = $1; }
	| class_member_stmt { $$ = $1; }
	| static_member_stmt { $$ = $1; }
	| this_stmt          { $$ = $1; }
	| array_ele_stmt     { $$ = $1; }
	;

// 赋值
single_assign_stmt
	: id_expr '=' assign_stmt_value { $$ = opr('=',2, $1,$3 ); }
	| id_expr '=' single_assign_stmt { $$ = opr('=',2, $1, $3 ); }
	;

class_member_assign_stmt
	: class_member_stmt '=' assign_stmt_value  { $$ = opr('=',2, $1,$3 ); }
	| this_member_stmt '=' assign_stmt_value   { $$ = opr('=',2, $1,$3 ); }
	;

// 数组元素获取语句
array_ele_stmt
	: IDENTIFIER '[' XINTEGER ']'    { $$ = arr($1, $3, NULL); }
	| IDENTIFIER '[' IDENTIFIER ']'  { $$ = arr($1, -1, var($3)) ; }
	| class_member_stmt '[' XINTEGER ']'  {  $$ = arr2($1, $3, NULL) ; }
	| class_member_stmt '[' IDENTIFIER ']'  {  $$ = arr2($1, -1, var($3)) ; }
	| call_statement '[' XINTEGER ']'  {  $$ = arr2($1,  $3, NULL ) ; }
	| call_statement '[' IDENTIFIER ']'  {  $$ = arr2($1, -1, var($3)) ; }
	;

// ARRAY_ELE 意思是获得数组元素
// 数组元素 赋值语句
array_ele_assign_stmt
	: array_ele_stmt '=' assign_stmt_value  { $$ = opr('=',2, $1,$3 );  }
	;

//  赋值语句
assign_stmt
	: single_assign_stmt   { $$ = $1; }
	| class_member_assign_stmt { $$ = $1 ;}
	| array_ele_assign_stmt  { $$ = $1; }
	| id_expr ADD_EQ assign_stmt_value_eq { $$ = opr(ADD_EQ,2,$1,$3);}
	| id_expr SUB_EQ assign_stmt_value_eq { $$ = opr(SUB_EQ,2,$1,$3);}
	| id_expr MUL_EQ assign_stmt_value_eq { $$ = opr(MUL_EQ,2,$1,$3);}
	| id_expr DIV_EQ assign_stmt_value_eq { $$ = opr(DIV_EQ,2,$1,$3);}
	| id_expr MOD_EQ assign_stmt_value_eq { $$ = opr(MOD_EQ,2,$1,$3);}
	;
	
%%

void yyerror(char *s) {
	fprintf(stderr, "%s on file %s line %d,column %d. near by '%s' \n", s , getParsingFilename() , getParseLineNo(),column , yytext  );
}

char *namespaceNameCat(char *arg1,char *arg2){
	int len = strlen(arg1) + strlen(arg2) + 1;
	char *p = (char*)calloc(1, len + 1);
	strcat(p,arg1);
	strcat(p,".");
	strcat(p,arg2);
	p[len] = '\0' ;
	
	free(arg1);
	free(arg2);
	return p;
}

int main(int argc, char *argv[]){
	if(argc <= 1){
		printf("no input file.\n");
		return 1;
	}
	
	initLangX();
	
	for(int i = 1; i < argc; i++)
		doFile(argv[i]);
	
	closeLangX();
	
	printf("parse over!\n");
	return 0;
}