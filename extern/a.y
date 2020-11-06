%{

#include "../include/YLlangX.h"
#include "../include/Program.h"

%}

%union {
 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
};

%token <iValue> XINTEGER TBOOL
%token <dValue> TDOUBLE
%token <sValue> IDENTIFIER TSTRING OPERATOR_X__
%token OP_CALC AND_OP OR_OP FUNC_OP FUNC_CALL VAR_DECLAR RESTRICT THIS EXTENDS ARRAY_ELE XTRY XCATCH
%token LEFT_SHIFT RIGHT_SHIFT  XPUBLIC XSET XIS SCOPE SCOPE_FUNC_CALL  REF XCONTINUE
%token IF ELSE WHILE FOR DELETE BREAK RETURN SWITCH CASE DEFAULT CASE_LIST CLAXX_BODY NEW CLAXX_MEMBER CLAXX_FUNC_CALL XNULL
%token <iValue> REQUIRE REQUIRE_ONCE XINCLUDE AUTO XCONST XLOCAL
%token <iValue> ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ LE_OP GE_OP EQ_OP NE_OP '>' '<' INC_OP DEC_OP

%type <node> statement _extra_nothing con_ctl_stmt simple_stmt simple_stmt_types require_stmt interrupt_stmt new_expr null_expr delete_expr
%type <node> func_declar_stmt out_declar_stmt var_declar_stmt element_var_declar_stmt _elements_var_declar_stmt class_declar_stmt namespace_declar_stmt
%type <node> call_statement assign_stmt_value_eq single_assign_stmt bool_param_expr try_stmt catch_block_stmt
%type <node> id_expr bool_expr double_expr uminus_expr uminus_expr_values string_expr number_expr positive_number_expr int_expr
%type <node> this_stmt array_ele_stmt static_member_stmt class_member_stmt
%type <node> selection_stmt loop_stmt code_block block_item_list block_item
%type <node> case_stmt_list case_stmt logic_stmt
%type <node> common_types_expr common_others_values_expr common_values_expr common_result_of_call_expr common_assignable_expr common_number_expr
%type <node> common_object_expr common_string_expr common_expr number_parentheses_stmt string_plus_stmt lambda_stmt
%type <node> func_param_list func_name_types multiple_id_expr args_list_with_parentheses

%type <params> lambda_args_stmt
%type <args> args_list
%type <sValue> namespace_name_stmt
%type <iValue> require_operators class_name_prefix var_prefix _symbol_compare symbol_change_assign self_inc_dec_operators _symbol_equals_not

%type <node> class_name_suffix class_body class_body_items class_body_item
%type <node> namespace_ref_stmt single_assign_stmt_value string_plus_stmt_value
%type <node> if_stmt single_if_stmt else_stmt single_else_stmt else_if_stmt else_if_stmts
%type <node> for_1_stmt for_1_stmt_list for_logic_stmt for_3_stmt for_3_stmt_list
%type <node> compare_expr number_compare_expr object_compare_expr not_bool_param_expr type_judge_stmt
%type <node> restrict_stmt assign_stmt number_change_assign_stmt arithmetic_stmt self_inc_dec_stmt



/* 优先级是从低到高 */
%nonassoc IFX
%nonassoc ELSE

%left ',' PIPELINE_OP
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
%right '!' '~' INC_OP_BACK
%left '(' ')' '[' ']' '.' INC_OP DEC_OP
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
	: _extra_nothing     { $$ = $1; }
	| out_declar_stmt    { $$ = $1; }
	| con_ctl_stmt   { $$ = $1; }
	| simple_stmt    { $$ = $1; }
	| try_stmt       { $$ = $1; }
	;

_extra_nothing
  : ';'         { $$ = NULL; }
  ;

out_declar_stmt
  : func_declar_stmt          { $$ = $1; }
  | class_declar_stmt         { $$ = $1; }
  | namespace_declar_stmt     { $$ = $1; }
  | namespace_ref_stmt        { $$ = $1; }
  ;

// 需求语句
require_stmt
	: require_operators string_expr         { $$ = opr($1 , 1 , $2); }
	;

require_operators
    : REQUIRE             { $$ = $1; }
    | REQUIRE_ONCE        { $$ = $1; }
    | XINCLUDE            { $$ = $1; }
    ;

// try 语句
try_stmt
	: XTRY code_block   { $$ = opr(XTRY, 2,$2,NULL); }
	| XTRY code_block catch_block_stmt  { $$ = opr(XTRY, 2,$2,$3); }
	;

catch_block_stmt
	: XCATCH '(' id_expr ')' code_block  { $$ = opr(XCATCH, 2, $3,$5); }
	;


// 命名空间的声明语句
namespace_declar_stmt
	: XSET XPUBLIC '=' namespace_name_stmt { $$ = changeNameSpace($4); }
	;

// 引用命名空间
namespace_ref_stmt
    : REF namespace_name_stmt       { $$ = opr(REF, 1, $2); }
    ;

namespace_name_stmt
	: id_expr  { $$ = $1 ; }
	| namespace_name_stmt '.' id_expr { $$ = namespaceNameCat($1,$3) ; }
	;


////////////////////////////////////////////////////////////////////////
//    类声明语句
////////////////////////////////////////////////////////////////////////

//  类声明语句
class_declar_stmt
	: class_name_prefix id_expr class_name_suffix class_body     {  $$ = NULL; }
	;

class_name_prefix
    :        { $$ = NULL; }
    | AUTO   { $$ = $1; }
    ;

//  类继承语句
class_name_suffix
	:                     { $$ = NULL; }
	| EXTENDS multiple_id_expr  { $$ = NULL; }
	;

class_body
    : '{' '}'           { $$ = NULL; }
    | '{' class_body_items '}'  { $$ = $2; }
    ;

class_body_items
    : class_body_item           { $$ = $1; }
    | class_body_items class_body_item  { $$ = NULL; }
    ;

class_body_item
    : var_declar_stmt ';'       { $$ = $1; }
    | single_assign_stmt ';'    { $$ = $1; }
    | func_declar_stmt          { $$ = $1; }
    | _extra_nothing            { $$ = $1; }
    ;

//  this 语句， 暂只支持1级调用
this_stmt
	: THIS    { $$ = opr(THIS , 0 ); }
	;


//  类成员。  比如 a.x  a.y  这样 a.y.x
class_member_stmt
	: common_object_expr '.' id_expr       { $$ = NULL; }
	;

//  静态成员
static_member_stmt
	: id_expr SCOPE id_expr   { $$ = opr(SCOPE, 2 ,$1,$3) ; }
	;


  ////////////////////////////////////////////////////////////////////////
  //    函数声明语句
  ////////////////////////////////////////////////////////////////////////

// 函数声明语句
func_declar_stmt
	: func_name_types FUNC_OP code_block            { $$ = NULL; }
    | func_name_types FUNC_OP func_param_list code_block            { $$ = NULL; }
	;

func_name_types
    : id_expr  { $$ = $1; }
    | '~' id_expr   { $$ = NULL; }
    | OPERATOR_X__  { $$ = NULL; }
    ;

func_param_list
    : '(' ')'           { $$ = NULL; }
    | '(' multiple_id_expr ')'  { $$ = $2; }
    ;

// lambda 表达式
lambda_stmt
	: lambda_args_stmt FUNC_OP code_block   { $$ = lambda($1,$3) ; }
	;

lambda_args_stmt
	: '(' ')'          { $$ = NULL; }
    | '(' multiple_id_expr ')'  { $$ = $2; }
    | multiple_id_expr          { $$ = $1; }
	;

// 变量声明语句
var_declar_stmt
	: _elements_var_declar_stmt  { $$ = opr(VAR_DECLAR , 1, $1 ); }
	| var_prefix _elements_var_declar_stmt { $$ = NULL; }
	;

var_prefix
    : XCONST    { $$ = $1; }
    | XLOCAL    { $$ = $1; }
    ;

_elements_var_declar_stmt
    : element_var_declar_stmt       { $$ = $1; }
    | _elements_var_declar_stmt ',' element_var_declar_stmt  { $$ = NULL; }
    ;

element_var_declar_stmt
	: id_expr							{ $$ = $1; }
	| id_expr '[' common_number_expr ']'		{ $$ = NULL; }
	;

//  条件控制语句
con_ctl_stmt
	: selection_stmt    { $$ = $1; }
	| loop_stmt         { $$ = $1; }
	;

//  选择语句
selection_stmt
	: if_stmt        { $$ = $1; }
	| SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  { $$ = opr(SWITCH, 2 , $3,$6); pretreatSwitch( $$ ) ; }
	;

if_stmt
  : single_if_stmt        { $$ = $1; }
  | single_if_stmt else_stmt { $$ = NULL; }
  ;

single_if_stmt
  : IF '(' logic_stmt ')' code_block { $$ = opr(IF ,2,$3,$5) ; }
  ;

else_stmt
  : else_if_stmts single_else_stmt    { $$ =  NULL; }
  | single_else_stmt        { $$ = $1; }
  ;

else_if_stmts
  : else_if_stmt        { $$ = $1; }
  | else_if_stmts else_if_stmt    { $$ =  NULL; }
  ;

else_if_stmt
  : ELSE single_if_stmt   { $$ = $2; }
  ;

single_else_stmt
  : ELSE code_block     { $$ = NULL; }
  ;

case_stmt_list
	: case_stmt            { $$ = opr(CASE_LIST , 1 ,$1 ); }
	| case_stmt_list case_stmt { $$ = opr(CASE_LIST , 2 ,$1, $2 ); }
	;

case_stmt
	: CASE int_expr ':' code_block        { $$ = opr(CASE, 2 , $2, $4); }
	| DEFAULT ':' code_block                 { $$ = opr(DEFAULT , 1, $3); }
	;

loop_stmt
	: WHILE '(' logic_stmt ')' code_block { $$ = opr(WHILE , 2, $3, $5 ); }
	| FOR '(' for_1_stmt_list ';' for_logic_stmt ';' for_3_stmt_list ')' code_block { $$ = opr(FOR,4,$3,$5,$7,$9); }
	;

for_logic_stmt
  :       { $$ = NULL;  }    // true
  | logic_stmt    { $$ = $1; }
  ;

for_1_stmt_list
  :      { $$ = NULL ; }
  | for_1_stmt    { $$ = $1; }
  | for_1_stmt_list ',' for_1_stmt    { $$ = NULL; }
  ;

//  for 括号内的东西
for_1_stmt
	: assign_stmt  { $$ = $1; }
//	| var_declar_stmt { $$ = $1; }
//	| self_inc_dec_stmt { $$ = $1; }
	;

for_3_stmt_list
  :      { $$ = NULL ; }
  | for_3_stmt    { $$ = $1; }
  | for_3_stmt_list ',' for_3_stmt    { $$ = NULL; }
  ;

//  for 括号里面的第三段
for_3_stmt
  : assign_stmt         { $$ = $1; }
  | self_inc_dec_stmt   { $$ = $1; }
  ;

//  简单语句
simple_stmt
  : simple_stmt_types ';'   { $$ = $1; }
  ;

simple_stmt_types
	: self_inc_dec_stmt { $$ = $1; }
	| assign_stmt   { $$ = $1; }
	| call_statement  %prec PRIORITY1 { $$ = $1; }
	| delete_expr    { $$ = $1; }
	| interrupt_stmt { $$ = $1; }
	| new_expr       { $$ = $1; }
	| restrict_stmt  { $$ = $1; }
  | require_stmt      { $$ = $1; }
  | var_declar_stmt   { $$ = $1; }
	;

//  限定语句， 限定环境
restrict_stmt
	: RESTRICT       { $$ = opr(RESTRICT,0);}
	| RESTRICT bool_expr  { $$ = opr(RESTRICT,1,$2); }
	;

interrupt_stmt
	: BREAK { $$ = opr(BREAK, 0); }
	| RETURN { $$ = opr(RETURN , 0); }
	| RETURN common_expr { $$ = opr(RETURN , 1 ,$2);}
  | XCONTINUE { $$ = opr(XCONTINUE); }
	;

//  函数调用
call_statement
	: common_values_expr args_list_with_parentheses %prec PRIORITY3 { $$ = NULL; }
  | call_statement '.' id_expr args_list_with_parentheses  %prec PRIORITY2 { $$ = NULL; }
	;

//  运算语句
arithmetic_stmt
	: common_number_expr '+' common_number_expr { $$ = opr('+',2,$1,$3); }
	| common_number_expr '-' common_number_expr { $$ = opr('-',2,$1,$3); }
	| common_number_expr '*' common_number_expr { $$ = opr('*',2,$1,$3); }
	| common_number_expr '/' common_number_expr { $$ = opr('/',2,$1,$3); }
	| common_number_expr '%' common_number_expr { $$ = opr('%',2,$1,$3); }
	| common_number_expr '&' common_number_expr  { $$ = opr('&',2,$1,$3); }
	| common_number_expr '|' common_number_expr  { $$ = opr('|',2,$1,$3); }
	| common_number_expr '^' common_number_expr  { $$ = opr('^',2,$1,$3); }
	| common_number_expr LEFT_SHIFT common_number_expr  { $$ = opr(LEFT_SHIFT,2,$1,$3); }
	| common_number_expr RIGHT_SHIFT common_number_expr  { $$ = opr(RIGHT_SHIFT,2,$1,$3); }
  | '~' common_number_expr  { $$ = opr('~',1,$2); }
	;

//   new 表达式
new_expr
	: NEW id_expr args_list_with_parentheses { $$ = NULL; }
	;

args_list_with_parentheses
  : '(' ')'       { $$ = NULL; }
  | '(' args_list ')'   { $$ = $2; }
  ;

args_list
  : common_expr     { $$ = $1; }
  | args_list ',' common_expr  { $$ = NULL; }
  ;

delete_expr
  : DELETE multiple_id_expr   { $$ = NULL; }
  ;


//  逻辑语句
logic_stmt
	: bool_param_expr { $$ = $1; }
  | not_bool_param_expr     { $$ = $1; }
	| type_judge_stmt         { $$ = $1; }
  | compare_expr            { $$ = $1; }
  | logic_stmt _symbol_logic_connection logic_stmt      { $$ = NULL; }
	;

_symbol_logic_connection
  : AND_OP
  | OR_OP
  ;

//  bool 比较的值
bool_param_expr
	: assign_stmt_value_eq { $$ = $1; }
	| bool_expr         { $$ = $1; }
	;

// 类型判断语句
type_judge_stmt
	: common_object_expr XIS id_expr  { $$ = opr(XIS ,2 , $1,$3); }
	;

not_bool_param_expr
  : '!' bool_param_expr   { $$ = NULL; }
  ;

// 比较表达式
compare_expr
  : number_compare_expr     { $$ = $1; }
  | object_compare_expr     { $$ = $1; }
  ;

number_compare_expr
  : common_number_expr _symbol_compare common_number_expr { $$ = NULL; }
  ;

object_compare_expr
  : common_object_expr _symbol_equals_not common_types_expr  { $$ = NULL; }
  ;

_symbol_compare
  : '>'       { $$ = $1; }
  | '<'       { $$ = $1; }
  | GE_OP     { $$ = $1; }
  | LE_OP     { $$ = $1; }
  | NE_OP     { $$ = $1; }
  | EQ_OP     { $$ = $1; }
  ;

_symbol_equals_not
  : NE_OP     { $$ = $1; }
  | EQ_OP     { $$ = $1; }
  ;

//  自增 OR 自减
self_inc_dec_stmt
	: self_inc_dec_operators common_values_expr { $$ = opr($1,1, $2 ); }
	| common_values_expr self_inc_dec_operators  %prec INC_OP_BACK { $$ = sopr($1,1, $1 ); }
	;

self_inc_dec_operators
  : INC_OP        { $$ = $1; }
  | DEC_OP        { $$ = $1; }
  ;


//  += -= *= /=  的值
assign_stmt_value_eq
	: number_expr          { $$ = $1; }
  | common_values_expr    { $$ = $1; }
  | common_result_of_call_expr      { $$ = $1; }
	;

// 赋值

// ARRAY_ELE 意思是获得数组元素
// 数组元素获取语句
array_ele_stmt
	: common_object_expr '[' common_number_expr ']'  { $$ = NULL; }
	;

//  赋值语句
assign_stmt
	: single_assign_stmt   { $$ = $1; }
	| number_change_assign_stmt { $$ = $1 ;}
  ;

single_assign_stmt
	: common_assignable_expr '=' single_assign_stmt_value { $$ = opr('=',2, $1,$3 ); }
	;

single_assign_stmt_value
  : common_expr         { $$ = $1; }
  | single_assign_stmt    { $$ = $1; }
  ;

number_change_assign_stmt
  : common_assignable_expr symbol_change_assign common_number_expr  { $$ = NULL; }
  ;

symbol_change_assign
  : ADD_EQ      { $$ = $1; }
  | SUB_EQ      { $$ = $1; }
  | MUL_EQ      { $$ = $1; }
  | DIV_EQ      { $$ = $1; }
  | MOD_EQ      { $$ = $1; }
  ;

// code block
code_block
    : '{' '}'       { $$ = NULL; }
    | '{' block_item_list '}'    { $$ = $2; }
    ;

block_item_list
    : block_item                    { $$ = $1; }
    | block_item_list block_item    { $$ = $1; }
    ;

block_item
    : try_stmt          { $$ = $1; }
    | simple_stmt       { $$ = $1; }
    | con_ctl_stmt      { $$ = $1; }
    | _extra_nothing    { $$ = $1; }
    ;

// string plus string  and some others
string_plus_stmt
  : string_expr '+' string_plus_stmt_value    { $$ = NULL; }
  | string_plus_stmt_value '+' string_expr    { $$ = NULL; }
  ;

string_plus_stmt_value
  : common_object_expr      { $$ = $1; }
  | common_types_expr       { $$ = $1; }
  | string_plus_stmt        { $$ = $1; }
  | self_inc_dec_stmt       { $$ = $1; }
  | number_parentheses_stmt     { $$ = $1; }
  ;

number_parentheses_stmt
  : '(' common_number_expr ')'     { $$ = NULL; }
  ;


//  base element statement ..
id_expr
	: IDENTIFIER { $$ = var($1); }
	;

multiple_id_expr
    : id_expr       { $$ = $1;}
    | multiple_id_expr ',' id_expr { $$ = NULL; }
    ;

bool_expr
	: TBOOL   { $$ = number($1); }
	;

number_expr
  : positive_number_expr    { $$ = $1; }
  | uminus_expr             { $$ = $1; }
  ;

positive_number_expr
  : double_expr     { $$ = $1; }
  | int_expr        { $$ = $1; }
  ;

int_expr
  : XINTEGER { $$ = number($1); }
  ;

double_expr
	: TDOUBLE { $$ = number($1); }
	;

uminus_expr
	: '-' uminus_expr_values %prec UMINUS { $$ = opr(UMINUS, 1, $2 ); }
	;

uminus_expr_values
  : positive_number_expr        { $$ = $1; }
  | common_others_values_expr   { $$ = $1; }
  | call_statement              { $$ = $1; }
  | number_parentheses_stmt     { $$ = $1; }
  ;

string_expr
	: TSTRING  { $$ = string($1); }
	;

null_expr
	: XNULL   { $$ = xnull(); }
	;


//   common_xxx_expr 注释可见 grammar.js 文件

common_types_expr
  : number_expr       { $$ = $1; }
  | string_expr       { $$ = $1; }
  | null_expr         { $$ = $1; }
  | lambda_stmt       { $$ = $1; }
  | bool_expr         { $$ = $1; }
  ;

common_others_values_expr
  : id_expr           { $$ = $1; }
  | array_ele_stmt    { $$ = $1; }
  | class_member_stmt { $$ = $1; }
  | static_member_stmt { $$ = $1; }
  ;

common_values_expr
  : common_others_values_expr { $$ = $1; }
  | this_stmt                 { $$ = $1; }
  | new_expr                  { $$ = $1; }
  ;

common_result_of_call_expr
  : self_inc_dec_stmt         { $$ = $1; }
  | call_statement            { $$ = $1; }
  | arithmetic_stmt           { $$ = $1; }
  | number_parentheses_stmt   { $$ = $1; }
  ;

common_assignable_expr
  : common_others_values_expr { $$ = $1; }
  ;

common_number_expr
  : number_expr                 { $$ = $1; }
  | common_values_expr          { $$ = $1; }
  | common_result_of_call_expr  { $$ = $1; }
  ;

common_object_expr
  : common_values_expr        { $$ = $1; }
  | call_statement            { $$ = $1; }
  ;

common_string_expr
  : string_expr               { $$ = $1; }
  | common_object_expr        { $$ = $1; }
  ;

common_expr
  : common_types_expr       { $$ = $1; }
  | common_values_expr      { $$ = $1; }
  | common_result_of_call_expr  { $$ = $1; }
  | string_plus_stmt        { $$ = $1; }
  ;

%%


int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
