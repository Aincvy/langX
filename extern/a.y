%{

#include <string.h>
#include "../include/NodeCreator.h"
#include "../include/Program.h"

extern void lexEOFWork();

%}

%union {
 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
};

%token <iValue> TINTEGER TBOOL
%token <dValue> TDOUBLE
%token <sValue> IDENTIFIER TSTRING OPERATOR_X__
%token FUNC_OP FUNC_CALL VAR_DECLARE ARRAY_ELE KEY_TRY
%token KEY_PUBLIC KEY_SET KEY_IS KEY_REF KEY_CONTINUE KEY_NEW KEY_CATCH KEY_THIS KEY_EXTENDS KEY_RESTRICT KEY_AUTO KEY_CONST KEY_LOCAL
%token KEY_IF KEY_ELSE KEY_WHILE KEY_FOR KEY_DELETE KEY_BREAK KEY_RETURN KEY_SWITCH KEY_CASE KEY_DEFAULT KEY_NULL
%token CASE_LIST CLAXX_BODY CLAXX_MEMBER CLAXX_FUNC_CALL SCOPE LEFT_SHIFT RIGHT_SHIFT
%token INC_OP DEC_OP
%token OPR_NODE_LIST OPR_CHANGE_NAME_SPACE OPR_GET_NAME_SPACE OPR_CLASS_DECLARE OPR_INC_DEC OPR_IF_ELSE OPR_MULTIPLE_ID OPR_START_IF
%token OPR_ARGS_LIST
%token KEY_REQUIRE KEY_REQUIRE_ONCE KEY_INCLUDE
%token ADD_EQ SUB_EQ MUL_EQ DIV_EQ MOD_EQ LE_OP GE_OP EQ_OP NE_OP '>' '<'  AND_OP OR_OP
%token TOKEN_END_OF_FILE

%type <node> statement _extra_nothing con_ctl_stmt simple_stmt simple_stmt_types interrupt_stmt new_expr null_expr delete_expr
%type <node> func_declare_stmt out_declare_stmt var_declare_stmt element_var_declare_stmt _elements_var_declare_stmt class_declare_stmt namespace_declare_stmt
%type <node> _var_declare_stmt_with_assign _var_declare_stmt_with_assign_list
%type <node> call_statement assign_stmt_value_eq single_assign_stmt bool_param_expr try_stmt catch_block_stmt
%type <node> id_expr bool_expr double_expr uminus_expr uminus_expr_values string_expr number_expr positive_number_expr int_expr
%type <node> this_stmt array_ele_stmt static_member_stmt class_member_stmt
%type <node> selection_stmt loop_stmt code_block block_item_list block_item
%type <node> case_stmt_list case_stmt case_block logic_stmt
%type <node> common_types_expr common_others_values_expr common_values_expr common_result_of_call_expr common_assignable_expr common_number_expr
%type <node> common_object_expr common_string_expr common_expr number_parentheses_stmt string_plus_stmt lambda_stmt
%type <node> func_param_list func_name_types multiple_id_expr args_list args_list_with_parentheses lambda_args_stmt


%type <iValue> class_name_prefix var_prefix _symbol_compare symbol_change_assign self_inc_dec_operators _symbol_equals_not


%type <node> class_name_suffix class_body class_body_items class_body_item namespace_name_stmt
%type <node> namespace_ref_stmt single_assign_stmt_value string_plus_stmt_value
%type <node> if_stmt single_if_stmt else_stmt single_else_stmt else_if_stmt else_if_stmts
%type <node> for_1_stmt for_1_stmt_list for_3_stmt for_3_stmt_list
%type <node> compare_expr number_compare_expr object_compare_expr not_bool_param_expr type_judge_stmt
%type <node> restrict_stmt assign_stmt number_change_assign_stmt arithmetic_stmt self_inc_dec_stmt


/* 优先级是从低到高 */
%nonassoc KEY_IF
%nonassoc KEY_ELSE

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
%nonassoc UMINUS

%glr-parser

%start program
%%

program
	: statement_list
	;

statement_list
    : statement_list statement      { execAndFreeNode($2); }
    |
	;

statement
	: _extra_nothing     { $$ = $1; }
	| out_declare_stmt    { $$ = $1; }
	| con_ctl_stmt   { $$ = $1; }
	| simple_stmt    { $$ = $1; }
	| try_stmt       { $$ = $1; }
    | TOKEN_END_OF_FILE { lexEOFWork();  $$ = nullptr; }
	;

_extra_nothing
    : ';'         { $$ = NULL; }
    ;

out_declare_stmt
    : func_declare_stmt          { $$ = $1; }
    | class_declare_stmt         { $$ = $1; }
    | namespace_declare_stmt     { $$ = $1; }
    | namespace_ref_stmt        { $$ = $1; }
    ;


// try 语句
try_stmt
	: KEY_TRY code_block   { $$ = opr(KEY_TRY, 2,$2,NULL); }
	| KEY_TRY code_block catch_block_stmt  { $$ = opr(KEY_TRY, 2,$2,$3); }
	;

catch_block_stmt
	: KEY_CATCH '(' id_expr ')' code_block  { $$ = opr(KEY_CATCH, 2, $3,$5); }
	;


// 命名空间的声明语句
namespace_declare_stmt
	: KEY_SET KEY_PUBLIC '=' namespace_name_stmt { $$ = opr(OPR_CHANGE_NAME_SPACE, 1, $4); }
	;

// 引用命名空间
namespace_ref_stmt
    : KEY_REF namespace_name_stmt       { $$ = opr(KEY_REF, 1, $2); }
    ;

namespace_name_stmt
	: id_expr  { $$ = opr(OPR_GET_NAME_SPACE, 2, NULL, $1); }
	| namespace_name_stmt '.' id_expr { $$ = opr(OPR_GET_NAME_SPACE, 2, $1, $3); }
	;


////////////////////////////////////////////////////////////////////////
//    类声明语句
////////////////////////////////////////////////////////////////////////

//  类声明语句
class_declare_stmt
	: class_name_prefix id_expr class_name_suffix class_body     {  $$ = opr(OPR_CLASS_DECLARE, 4, intNode($1), $2, $3, $4); }
	;

class_name_prefix
    :        { $$ = -1; }
    | KEY_AUTO   { $$ = yytokentype::KEY_AUTO; }
    ;

//  类继承语句
class_name_suffix
	:                     { $$ = NULL; }
	| KEY_EXTENDS multiple_id_expr  { $$ = opr(KEY_EXTENDS, 1, $2); }
	;

class_body
    : '{' '}'           { $$ = NULL; }
    | '{' class_body_items '}'  { $$ = opr(CLAXX_BODY, 1, $2); }
    ;

class_body_items
    : class_body_item           { $$ = $1; }
    | class_body_items class_body_item  { $$ = opr(OPR_NODE_LIST, 2, $1 ,$2); }
    ;

class_body_item
    : var_declare_stmt ';'       { $$ = $1; }
    | single_assign_stmt ';'    { $$ = $1; }
    | func_declare_stmt          { $$ = $1; }
    | _extra_nothing            { $$ = $1; }
    ;

//  this 语句， 用于获取当前对象
this_stmt
	: KEY_THIS    { $$ = opr(KEY_THIS , 0 ); }
	;


//  类成员。  比如 a.x  a.y  这样 a.y.x
class_member_stmt
	: common_object_expr '.' id_expr       { $$ = opr(CLAXX_MEMBER, 2, $1, $3); }
	;

//  静态成员
static_member_stmt
	: id_expr SCOPE id_expr   { $$ = opr(SCOPE, 2 ,$1,$3) ; }
	;


  ////////////////////////////////////////////////////////////////////////
  //    函数声明语句
  ////////////////////////////////////////////////////////////////////////

// 函数声明语句
func_declare_stmt
	: func_name_types FUNC_OP code_block            { $$ = opr(FUNC_OP,3, $1, NULL, $3); }     // 和下面的节点保持对齐
    | func_name_types FUNC_OP func_param_list code_block            { $$ = opr(FUNC_OP, 3, $1, $3, $4); }
	;

func_name_types
    : id_expr  { $$ = $1; }
    | '~' id_expr   { char buf[1024] = "~"; strcat(buf, $2->var_obj->name);  $$ = var(strdup(buf)); }
    | OPERATOR_X__  { $$ = var($1); }
    ;

func_param_list
    : '(' ')'           { $$ = NULL; }
    | '(' multiple_id_expr ')'  { $$ = $2; }
    ;

// lambda 表达式
lambda_stmt
	: lambda_args_stmt FUNC_OP code_block   { $$ = opr(FUNC_OP, 3, NULL, $1, $3); }
	;

lambda_args_stmt
    : '(' ')'          { $$ = NULL; }
    | '(' multiple_id_expr ')'  { $$ = $2; }
    | multiple_id_expr          { $$ = $1; }
	;

// 变量声明语句
var_declare_stmt
	: _elements_var_declare_stmt  { $$ = opr(VAR_DECLARE , 2, NULL, $1 ); }
	| var_prefix _var_declare_stmt_with_assign_list { $$ = opr(VAR_DECLARE, 2, intNode($1), $2 ); }
	;

var_prefix
    : KEY_CONST    { $$ = yytokentype::KEY_CONST; }
    | KEY_LOCAL    { $$ = yytokentype::KEY_LOCAL; }
    ;

_elements_var_declare_stmt
    : element_var_declare_stmt         { $$ = opr(OPR_NODE_LIST, 1 , $1); }
    | _elements_var_declare_stmt ',' element_var_declare_stmt  { $$ = opr(OPR_NODE_LIST, 2, $1, $3); }
    ;

element_var_declare_stmt
	: id_expr							{ $$ = $1; }
	| id_expr '[' common_number_expr ']'		{ $$ = arrayElementNode($1->var_obj->name, $3); }
	;

_var_declare_stmt_with_assign_list
    : _var_declare_stmt_with_assign         { $$ = opr(OPR_NODE_LIST, 1 , $1); }
    | _var_declare_stmt_with_assign_list ',' _var_declare_stmt_with_assign       { $$ = opr(OPR_NODE_LIST, 2, $1, $3); }
    ;

_var_declare_stmt_with_assign
    : element_var_declare_stmt			{ $$ = $1; }
    | single_assign_stmt                { $$ = $1; }
    ;


//  条件控制语句
con_ctl_stmt
	: selection_stmt    { $$ = $1; }
	| loop_stmt         { $$ = $1; }
	;

//  选择语句
selection_stmt
	: if_stmt        { $$ = opr(OPR_START_IF, 1, $1); }
	| KEY_SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  { $$ = opr(KEY_SWITCH, 2 , $3,$6); pretreatSwitch( $$ ) ; }
	;

if_stmt
    : single_if_stmt        { $$ = $1; }
    | single_if_stmt else_stmt { $$ = opr(OPR_IF_ELSE, 2, $1, $2); }   // IF-ELSE
    ;

single_if_stmt
    : KEY_IF '(' logic_stmt ')' code_block { $$ = opr(KEY_IF ,2,$3,$5) ; }
    ;

else_stmt
    : else_if_stmts                     { $$ =  $1; }
    | else_if_stmts single_else_stmt    { $$ =  opr(OPR_IF_ELSE, 2, $1, $2); }
    | single_else_stmt        { $$ = $1; }
    ;

else_if_stmts
    : else_if_stmt        { $$ = opr(OPR_IF_ELSE, 2, $1, NULL); }
    | else_if_stmts else_if_stmt    { $$ =  opr(OPR_IF_ELSE, 2, $1, $2); }
    ;

else_if_stmt
    : KEY_ELSE single_if_stmt   { $$ = $2; }   // 使用2个长度的子节点表示 else if  和下面的单个else 区分
    ;

single_else_stmt
    : KEY_ELSE code_block     { $$ = opr( KEY_ELSE, 1, $2); }
    ;

case_stmt_list
	: case_stmt            { $$ = opr(CASE_LIST , 1 ,$1 ); }
	| case_stmt_list case_stmt { $$ = opr(CASE_LIST , 2 ,$1, $2 ); }
	;

case_stmt
	: KEY_CASE int_expr ':' case_block        { $$ = opr(KEY_CASE, 2 , $2, $4); }
	| KEY_DEFAULT ':' case_block                 { $$ = opr(KEY_DEFAULT , 1, $3); }
	;

case_block
    : code_block        %dprec 2 { $$ = $1; }
    | block_item_list   %dprec 1 { $$ = $1; }
    |       { $$ = NULL; }
    ;

loop_stmt
	: KEY_WHILE '(' logic_stmt ')' code_block { $$ = opr(KEY_WHILE , 2, $3, $5 ); }
	| KEY_FOR '(' for_1_stmt_list ';' logic_stmt ';' for_3_stmt_list ')' code_block { $$ = opr(KEY_FOR,4,$3,$5,$7,$9); }
	;

for_1_stmt_list
    :      { $$ = NULL ; }
    | for_1_stmt    { $$ = $1; }
    | for_1_stmt_list ',' for_1_stmt    { $$ = opr(OPR_NODE_LIST, 2, $1, $3); }
    ;

//  for 括号内的东西
for_1_stmt
	: assign_stmt  { $$ = $1; }
//	| var_declare_stmt { $$ = $1; }
//	| self_inc_dec_stmt { $$ = $1; }
	;

for_3_stmt_list
    :      { $$ = NULL ; }
    | for_3_stmt    { $$ = $1; }
    | for_3_stmt_list ',' for_3_stmt    { $$ = opr(OPR_NODE_LIST, 2, $1, $3); }
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
	| call_statement { $$ = $1; }
	| delete_expr    { $$ = $1; }
	| interrupt_stmt { $$ = $1; }
	| new_expr       { $$ = $1; }
	| restrict_stmt  { $$ = $1; }
    | var_declare_stmt   { $$ = $1; }
	;

//  限定语句， 限定环境
restrict_stmt
	: KEY_RESTRICT       { $$ = opr(KEY_RESTRICT,0);}
	| KEY_RESTRICT bool_expr  { $$ = opr(KEY_RESTRICT,1,$2); }
	;

interrupt_stmt
	: KEY_BREAK { $$ = opr(KEY_BREAK, 0); }
	| KEY_RETURN { $$ = opr(KEY_RETURN , 0); }
	| KEY_RETURN common_expr { $$ = opr(KEY_RETURN , 1 ,$2); }
    | KEY_CONTINUE { $$ = opr(KEY_CONTINUE,0); }
	;

//  函数调用
call_statement
	: common_values_expr args_list_with_parentheses { $$ = opr(FUNC_CALL, 2, $1, $2); }
//    | call_statement '.' id_expr args_list_with_parentheses  { $$ = opr(CLAXX_FUNC_CALL, 3, $1, $3, $4); }
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
	: KEY_NEW id_expr args_list_with_parentheses { $$ = opr(KEY_NEW, 2 , $2, $3); }
	;

args_list_with_parentheses
  : '(' ')'       { $$ = NULL; }
  | '(' args_list ')'   { $$ = $2; }
  ;

args_list
  : common_expr     { $$ = opr(OPR_ARGS_LIST, 1, $1); }         // 和下面部分的语法节点 保持统一
  | args_list ',' common_expr  { $$ = opr(OPR_ARGS_LIST, 2 , $1, $3); }
  ;

delete_expr
  : KEY_DELETE multiple_id_expr   { $$ = opr(KEY_DELETE, 1, $2); }
  ;


//  逻辑语句
logic_stmt
	: bool_param_expr { $$ = $1; }
    | not_bool_param_expr     { $$ = $1; }
	| type_judge_stmt         { $$ = $1; }
    | compare_expr            { $$ = $1; }
    | logic_stmt AND_OP logic_stmt   { $$ = opr(AND_OP, 2, $1, $3); }
    | logic_stmt OR_OP logic_stmt   { $$ = opr(OR_OP, 2, $1, $3); }
	;

//  bool 比较的值
bool_param_expr
	: assign_stmt_value_eq { $$ = $1; }
	| bool_expr         { $$ = $1; }
	;

// 类型判断语句
type_judge_stmt
	: common_object_expr KEY_IS id_expr  { $$ = opr(KEY_IS ,2 , $1,$3); }
	;

not_bool_param_expr
    : '!' bool_param_expr   { $$ = opr('!', 1, $2); }
    ;

// 比较表达式
compare_expr
    : number_compare_expr   %dprec 2  { $$ = $1; }
    | object_compare_expr   %dprec 1 { $$ = $1; }
    ;

number_compare_expr
    : common_number_expr _symbol_compare common_number_expr  { $$ = opr($2, 2, $1, $3); }
    ;

object_compare_expr
    : common_object_expr _symbol_equals_not common_types_expr  { $$ = opr($2, 2, $1, $3); }
    ;

_symbol_compare
    : '>'       { $$ = '>'; }
    | '<'       { $$ = '<'; }
    | GE_OP     { $$ = yytokentype::GE_OP; }
    | LE_OP     { $$ = yytokentype::LE_OP; }
    | NE_OP     { $$ = yytokentype::NE_OP; }
    | EQ_OP     { $$ = yytokentype::EQ_OP; }
    ;

_symbol_equals_not
    : NE_OP     { $$ = yytokentype::NE_OP; }
    | EQ_OP     { $$ = yytokentype::EQ_OP; }
    ;

//  自增 OR 自减
self_inc_dec_stmt
	: self_inc_dec_operators common_values_expr { $$ = opr(OPR_INC_DEC,2, intNode($1), $2 ); }
	| common_values_expr self_inc_dec_operators  %prec INC_OP_BACK { $$ = opr(OPR_INC_DEC, 2, $1, intNode($2)); }
	;

self_inc_dec_operators
    : INC_OP        { $$ = yytokentype::INC_OP; }
    | DEC_OP        { $$ = yytokentype::DEC_OP; }
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
	: common_object_expr '[' common_number_expr ']'  { $$ = objectArrayElementNode($1, $3); }
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
  : common_assignable_expr symbol_change_assign common_number_expr  { $$ = opr($2, 2, $1, $3); }
  ;

symbol_change_assign
  : ADD_EQ      { $$ = yytokentype::ADD_EQ; }
  | SUB_EQ      { $$ = yytokentype::SUB_EQ; }
  | MUL_EQ      { $$ = yytokentype::MUL_EQ; }
  | DIV_EQ      { $$ = yytokentype::DIV_EQ; }
  | MOD_EQ      { $$ = yytokentype::MOD_EQ; }
  ;

// code block
code_block
    : '{' '}'       { $$ = opr(OPR_NODE_LIST,0 ); }
    | '{' block_item_list '}'    { $$ = $2; }
    ;

block_item_list
    : block_item                    { $$ = opr(OPR_NODE_LIST, 1, $1); }
    | block_item_list block_item    { $$ = opr(OPR_NODE_LIST, 2 , $1, $2); }
    ;

block_item
    : try_stmt          { $$ = $1; }
    | simple_stmt       { $$ = $1; }
    | con_ctl_stmt      { $$ = $1; }
    | _extra_nothing    { $$ = $1; }
    ;

// string plus string  and some others
string_plus_stmt
    : string_expr '+' string_plus_stmt_value   %dprec 1  { $$ = opr('+', 2, $1, $3); }
    | string_plus_stmt_value '+' string_expr   %dprec 2 { $$ = opr('+', 2, $1, $3); }
    | string_plus_stmt_value '+' string_plus_stmt  %dprec 3   { $$ = opr('+', 2, $1, $3); }
    | string_plus_stmt '+' string_plus_stmt_value  %dprec 4   { $$ = opr('+', 2, $1, $3); }
    ;

string_plus_stmt_value
    : common_object_expr      { $$ = $1; }
    | common_types_expr       { $$ = $1; }
    | self_inc_dec_stmt       { $$ = $1; }
    | number_parentheses_stmt     { $$ = $1; }
    ;

number_parentheses_stmt
    : '(' common_number_expr ')'     { $$ = $2; }
    ;


//  base element statement ..
id_expr
	: IDENTIFIER { $$ = var($1); }
	;

multiple_id_expr
    : id_expr       { $$ = opr(OPR_MULTIPLE_ID , 1 , $1 );}
    | multiple_id_expr ',' id_expr { $$ = opr(OPR_MULTIPLE_ID , 2 , $1, $3); }
    ;

bool_expr
	: TBOOL   { $$ = boolNode($1); }
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
    : TINTEGER { $$ = intNode($1); }
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
	: KEY_NULL   { $$ = xnull(); }
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
  : common_types_expr       %dprec 5 { $$ = $1; }
  | common_values_expr      %dprec 5 { $$ = $1; }
  | common_result_of_call_expr  %dprec 5 { $$ = $1; }
  | string_plus_stmt        %dprec 5 { $$ = $1; }
  | logic_stmt              %dprec 1 { $$ = $1; }
  ;

%%


int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
