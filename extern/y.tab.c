/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "a.y"


#include "../include/NodeCreator.h"
#include "../include/Program.h"


#line 78 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TINTEGER = 258,                /* TINTEGER  */
    TBOOL = 259,                   /* TBOOL  */
    TDOUBLE = 260,                 /* TDOUBLE  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    TSTRING = 262,                 /* TSTRING  */
    OPERATOR_X__ = 263,            /* OPERATOR_X__  */
    OP_CALC = 264,                 /* OP_CALC  */
    AND_OP = 265,                  /* AND_OP  */
    OR_OP = 266,                   /* OR_OP  */
    FUNC_OP = 267,                 /* FUNC_OP  */
    FUNC_CALL = 268,               /* FUNC_CALL  */
    VAR_DECLAR = 269,              /* VAR_DECLAR  */
    ARRAY_ELE = 270,               /* ARRAY_ELE  */
    KEY_TRY = 271,                 /* KEY_TRY  */
    KEY_PUBLIC = 272,              /* KEY_PUBLIC  */
    KEY_SET = 273,                 /* KEY_SET  */
    KEY_IS = 274,                  /* KEY_IS  */
    KEY_REF = 275,                 /* KEY_REF  */
    KEY_CONTINUE = 276,            /* KEY_CONTINUE  */
    KEY_NEW = 277,                 /* KEY_NEW  */
    KEY_CATCH = 278,               /* KEY_CATCH  */
    KEY_THIS = 279,                /* KEY_THIS  */
    KEY_EXTENDS = 280,             /* KEY_EXTENDS  */
    KEY_RESTRICT = 281,            /* KEY_RESTRICT  */
    KEY_IF = 282,                  /* KEY_IF  */
    KEY_ELSE = 283,                /* KEY_ELSE  */
    KEY_WHILE = 284,               /* KEY_WHILE  */
    KEY_FOR = 285,                 /* KEY_FOR  */
    KEY_DELETE = 286,              /* KEY_DELETE  */
    KEY_BREAK = 287,               /* KEY_BREAK  */
    KEY_RETURN = 288,              /* KEY_RETURN  */
    KEY_SWITCH = 289,              /* KEY_SWITCH  */
    KEY_CASE = 290,                /* KEY_CASE  */
    KEY_DEFAULT = 291,             /* KEY_DEFAULT  */
    KEY_NULL = 292,                /* KEY_NULL  */
    CASE_LIST = 293,               /* CASE_LIST  */
    CLAXX_BODY = 294,              /* CLAXX_BODY  */
    CLAXX_MEMBER = 295,            /* CLAXX_MEMBER  */
    CLAXX_FUNC_CALL = 296,         /* CLAXX_FUNC_CALL  */
    SCOPE_FUNC_CALL = 297,         /* SCOPE_FUNC_CALL  */
    SCOPE = 298,                   /* SCOPE  */
    LEFT_SHIFT = 299,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 300,             /* RIGHT_SHIFT  */
    KEY_REQUIRE = 301,             /* KEY_REQUIRE  */
    KEY_REQUIRE_ONCE = 302,        /* KEY_REQUIRE_ONCE  */
    KEY_INCLUDE = 303,             /* KEY_INCLUDE  */
    KEY_AUTO = 304,                /* KEY_AUTO  */
    KEY_CONST = 305,               /* KEY_CONST  */
    KEY_LOCAL = 306,               /* KEY_LOCAL  */
    ADD_EQ = 307,                  /* ADD_EQ  */
    SUB_EQ = 308,                  /* SUB_EQ  */
    MUL_EQ = 309,                  /* MUL_EQ  */
    DIV_EQ = 310,                  /* DIV_EQ  */
    MOD_EQ = 311,                  /* MOD_EQ  */
    LE_OP = 312,                   /* LE_OP  */
    GE_OP = 313,                   /* GE_OP  */
    EQ_OP = 314,                   /* EQ_OP  */
    NE_OP = 315,                   /* NE_OP  */
    INC_OP = 316,                  /* INC_OP  */
    DEC_OP = 317,                  /* DEC_OP  */
    IFX = 318,                     /* IFX  */
    ELSE = 319,                    /* ELSE  */
    PIPELINE_OP = 320,             /* PIPELINE_OP  */
    INC_OP_BACK = 321,             /* INC_OP_BACK  */
    PRIORITY3 = 322,               /* PRIORITY3  */
    PRIORITY2 = 323,               /* PRIORITY2  */
    PRIORITY1 = 324,               /* PRIORITY1  */
    UMINUS = 325                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TINTEGER 258
#define TBOOL 259
#define TDOUBLE 260
#define IDENTIFIER 261
#define TSTRING 262
#define OPERATOR_X__ 263
#define OP_CALC 264
#define AND_OP 265
#define OR_OP 266
#define FUNC_OP 267
#define FUNC_CALL 268
#define VAR_DECLAR 269
#define ARRAY_ELE 270
#define KEY_TRY 271
#define KEY_PUBLIC 272
#define KEY_SET 273
#define KEY_IS 274
#define KEY_REF 275
#define KEY_CONTINUE 276
#define KEY_NEW 277
#define KEY_CATCH 278
#define KEY_THIS 279
#define KEY_EXTENDS 280
#define KEY_RESTRICT 281
#define KEY_IF 282
#define KEY_ELSE 283
#define KEY_WHILE 284
#define KEY_FOR 285
#define KEY_DELETE 286
#define KEY_BREAK 287
#define KEY_RETURN 288
#define KEY_SWITCH 289
#define KEY_CASE 290
#define KEY_DEFAULT 291
#define KEY_NULL 292
#define CASE_LIST 293
#define CLAXX_BODY 294
#define CLAXX_MEMBER 295
#define CLAXX_FUNC_CALL 296
#define SCOPE_FUNC_CALL 297
#define SCOPE 298
#define LEFT_SHIFT 299
#define RIGHT_SHIFT 300
#define KEY_REQUIRE 301
#define KEY_REQUIRE_ONCE 302
#define KEY_INCLUDE 303
#define KEY_AUTO 304
#define KEY_CONST 305
#define KEY_LOCAL 306
#define ADD_EQ 307
#define SUB_EQ 308
#define MUL_EQ 309
#define DIV_EQ 310
#define MOD_EQ 311
#define LE_OP 312
#define GE_OP 313
#define EQ_OP 314
#define NE_OP 315
#define INC_OP 316
#define DEC_OP 317
#define IFX 318
#define ELSE 319
#define PIPELINE_OP 320
#define INC_OP_BACK 321
#define PRIORITY3 322
#define PRIORITY2 323
#define PRIORITY1 324
#define UMINUS 325

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 8 "a.y"

 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */

#line 279 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TINTEGER = 3,                   /* TINTEGER  */
  YYSYMBOL_TBOOL = 4,                      /* TBOOL  */
  YYSYMBOL_TDOUBLE = 5,                    /* TDOUBLE  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_TSTRING = 7,                    /* TSTRING  */
  YYSYMBOL_OPERATOR_X__ = 8,               /* OPERATOR_X__  */
  YYSYMBOL_OP_CALC = 9,                    /* OP_CALC  */
  YYSYMBOL_AND_OP = 10,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 11,                     /* OR_OP  */
  YYSYMBOL_FUNC_OP = 12,                   /* FUNC_OP  */
  YYSYMBOL_FUNC_CALL = 13,                 /* FUNC_CALL  */
  YYSYMBOL_VAR_DECLAR = 14,                /* VAR_DECLAR  */
  YYSYMBOL_ARRAY_ELE = 15,                 /* ARRAY_ELE  */
  YYSYMBOL_KEY_TRY = 16,                   /* KEY_TRY  */
  YYSYMBOL_KEY_PUBLIC = 17,                /* KEY_PUBLIC  */
  YYSYMBOL_KEY_SET = 18,                   /* KEY_SET  */
  YYSYMBOL_KEY_IS = 19,                    /* KEY_IS  */
  YYSYMBOL_KEY_REF = 20,                   /* KEY_REF  */
  YYSYMBOL_KEY_CONTINUE = 21,              /* KEY_CONTINUE  */
  YYSYMBOL_KEY_NEW = 22,                   /* KEY_NEW  */
  YYSYMBOL_KEY_CATCH = 23,                 /* KEY_CATCH  */
  YYSYMBOL_KEY_THIS = 24,                  /* KEY_THIS  */
  YYSYMBOL_KEY_EXTENDS = 25,               /* KEY_EXTENDS  */
  YYSYMBOL_KEY_RESTRICT = 26,              /* KEY_RESTRICT  */
  YYSYMBOL_KEY_IF = 27,                    /* KEY_IF  */
  YYSYMBOL_KEY_ELSE = 28,                  /* KEY_ELSE  */
  YYSYMBOL_KEY_WHILE = 29,                 /* KEY_WHILE  */
  YYSYMBOL_KEY_FOR = 30,                   /* KEY_FOR  */
  YYSYMBOL_KEY_DELETE = 31,                /* KEY_DELETE  */
  YYSYMBOL_KEY_BREAK = 32,                 /* KEY_BREAK  */
  YYSYMBOL_KEY_RETURN = 33,                /* KEY_RETURN  */
  YYSYMBOL_KEY_SWITCH = 34,                /* KEY_SWITCH  */
  YYSYMBOL_KEY_CASE = 35,                  /* KEY_CASE  */
  YYSYMBOL_KEY_DEFAULT = 36,               /* KEY_DEFAULT  */
  YYSYMBOL_KEY_NULL = 37,                  /* KEY_NULL  */
  YYSYMBOL_CASE_LIST = 38,                 /* CASE_LIST  */
  YYSYMBOL_CLAXX_BODY = 39,                /* CLAXX_BODY  */
  YYSYMBOL_CLAXX_MEMBER = 40,              /* CLAXX_MEMBER  */
  YYSYMBOL_CLAXX_FUNC_CALL = 41,           /* CLAXX_FUNC_CALL  */
  YYSYMBOL_SCOPE_FUNC_CALL = 42,           /* SCOPE_FUNC_CALL  */
  YYSYMBOL_SCOPE = 43,                     /* SCOPE  */
  YYSYMBOL_LEFT_SHIFT = 44,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 45,               /* RIGHT_SHIFT  */
  YYSYMBOL_KEY_REQUIRE = 46,               /* KEY_REQUIRE  */
  YYSYMBOL_KEY_REQUIRE_ONCE = 47,          /* KEY_REQUIRE_ONCE  */
  YYSYMBOL_KEY_INCLUDE = 48,               /* KEY_INCLUDE  */
  YYSYMBOL_KEY_AUTO = 49,                  /* KEY_AUTO  */
  YYSYMBOL_KEY_CONST = 50,                 /* KEY_CONST  */
  YYSYMBOL_KEY_LOCAL = 51,                 /* KEY_LOCAL  */
  YYSYMBOL_ADD_EQ = 52,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 53,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 54,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 55,                    /* DIV_EQ  */
  YYSYMBOL_MOD_EQ = 56,                    /* MOD_EQ  */
  YYSYMBOL_LE_OP = 57,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 58,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 59,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 60,                     /* NE_OP  */
  YYSYMBOL_61_ = 61,                       /* '>'  */
  YYSYMBOL_62_ = 62,                       /* '<'  */
  YYSYMBOL_INC_OP = 63,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 64,                    /* DEC_OP  */
  YYSYMBOL_IFX = 65,                       /* IFX  */
  YYSYMBOL_ELSE = 66,                      /* ELSE  */
  YYSYMBOL_67_ = 67,                       /* ','  */
  YYSYMBOL_PIPELINE_OP = 68,               /* PIPELINE_OP  */
  YYSYMBOL_69_ = 69,                       /* '='  */
  YYSYMBOL_70_ = 70,                       /* '|'  */
  YYSYMBOL_71_ = 71,                       /* '^'  */
  YYSYMBOL_72_ = 72,                       /* '&'  */
  YYSYMBOL_73_ = 73,                       /* '+'  */
  YYSYMBOL_74_ = 74,                       /* '-'  */
  YYSYMBOL_75_ = 75,                       /* '*'  */
  YYSYMBOL_76_ = 76,                       /* '/'  */
  YYSYMBOL_77_ = 77,                       /* '%'  */
  YYSYMBOL_78_ = 78,                       /* '!'  */
  YYSYMBOL_79_ = 79,                       /* '~'  */
  YYSYMBOL_INC_OP_BACK = 80,               /* INC_OP_BACK  */
  YYSYMBOL_81_ = 81,                       /* '('  */
  YYSYMBOL_82_ = 82,                       /* ')'  */
  YYSYMBOL_83_ = 83,                       /* '['  */
  YYSYMBOL_84_ = 84,                       /* ']'  */
  YYSYMBOL_85_ = 85,                       /* '.'  */
  YYSYMBOL_PRIORITY3 = 86,                 /* PRIORITY3  */
  YYSYMBOL_PRIORITY2 = 87,                 /* PRIORITY2  */
  YYSYMBOL_PRIORITY1 = 88,                 /* PRIORITY1  */
  YYSYMBOL_UMINUS = 89,                    /* UMINUS  */
  YYSYMBOL_90_ = 90,                       /* ';'  */
  YYSYMBOL_91_ = 91,                       /* '{'  */
  YYSYMBOL_92_ = 92,                       /* '}'  */
  YYSYMBOL_93_ = 93,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 94,                  /* $accept  */
  YYSYMBOL_program = 95,                   /* program  */
  YYSYMBOL_statement_list = 96,            /* statement_list  */
  YYSYMBOL_statement = 97,                 /* statement  */
  YYSYMBOL__extra_nothing = 98,            /* _extra_nothing  */
  YYSYMBOL_out_declar_stmt = 99,           /* out_declar_stmt  */
  YYSYMBOL_require_stmt = 100,             /* require_stmt  */
  YYSYMBOL_require_operators = 101,        /* require_operators  */
  YYSYMBOL_try_stmt = 102,                 /* try_stmt  */
  YYSYMBOL_catch_block_stmt = 103,         /* catch_block_stmt  */
  YYSYMBOL_namespace_declar_stmt = 104,    /* namespace_declar_stmt  */
  YYSYMBOL_namespace_ref_stmt = 105,       /* namespace_ref_stmt  */
  YYSYMBOL_namespace_name_stmt = 106,      /* namespace_name_stmt  */
  YYSYMBOL_class_declar_stmt = 107,        /* class_declar_stmt  */
  YYSYMBOL_class_name_prefix = 108,        /* class_name_prefix  */
  YYSYMBOL_class_name_suffix = 109,        /* class_name_suffix  */
  YYSYMBOL_class_body = 110,               /* class_body  */
  YYSYMBOL_class_body_items = 111,         /* class_body_items  */
  YYSYMBOL_class_body_item = 112,          /* class_body_item  */
  YYSYMBOL_this_stmt = 113,                /* this_stmt  */
  YYSYMBOL_class_member_stmt = 114,        /* class_member_stmt  */
  YYSYMBOL_static_member_stmt = 115,       /* static_member_stmt  */
  YYSYMBOL_func_declar_stmt = 116,         /* func_declar_stmt  */
  YYSYMBOL_func_name_types = 117,          /* func_name_types  */
  YYSYMBOL_func_param_list = 118,          /* func_param_list  */
  YYSYMBOL_lambda_stmt = 119,              /* lambda_stmt  */
  YYSYMBOL_lambda_args_stmt = 120,         /* lambda_args_stmt  */
  YYSYMBOL_var_declar_stmt = 121,          /* var_declar_stmt  */
  YYSYMBOL_var_prefix = 122,               /* var_prefix  */
  YYSYMBOL__elements_var_declar_stmt = 123, /* _elements_var_declar_stmt  */
  YYSYMBOL_element_var_declar_stmt = 124,  /* element_var_declar_stmt  */
  YYSYMBOL_con_ctl_stmt = 125,             /* con_ctl_stmt  */
  YYSYMBOL_selection_stmt = 126,           /* selection_stmt  */
  YYSYMBOL_if_stmt = 127,                  /* if_stmt  */
  YYSYMBOL_single_if_stmt = 128,           /* single_if_stmt  */
  YYSYMBOL_else_stmt = 129,                /* else_stmt  */
  YYSYMBOL_else_if_stmts = 130,            /* else_if_stmts  */
  YYSYMBOL_else_if_stmt = 131,             /* else_if_stmt  */
  YYSYMBOL_single_else_stmt = 132,         /* single_else_stmt  */
  YYSYMBOL_case_stmt_list = 133,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 134,                /* case_stmt  */
  YYSYMBOL_loop_stmt = 135,                /* loop_stmt  */
  YYSYMBOL_for_logic_stmt = 136,           /* for_logic_stmt  */
  YYSYMBOL_for_1_stmt_list = 137,          /* for_1_stmt_list  */
  YYSYMBOL_for_1_stmt = 138,               /* for_1_stmt  */
  YYSYMBOL_for_3_stmt_list = 139,          /* for_3_stmt_list  */
  YYSYMBOL_for_3_stmt = 140,               /* for_3_stmt  */
  YYSYMBOL_simple_stmt = 141,              /* simple_stmt  */
  YYSYMBOL_simple_stmt_types = 142,        /* simple_stmt_types  */
  YYSYMBOL_restrict_stmt = 143,            /* restrict_stmt  */
  YYSYMBOL_interrupt_stmt = 144,           /* interrupt_stmt  */
  YYSYMBOL_call_statement = 145,           /* call_statement  */
  YYSYMBOL_arithmetic_stmt = 146,          /* arithmetic_stmt  */
  YYSYMBOL_new_expr = 147,                 /* new_expr  */
  YYSYMBOL_args_list_with_parentheses = 148, /* args_list_with_parentheses  */
  YYSYMBOL_args_list = 149,                /* args_list  */
  YYSYMBOL_delete_expr = 150,              /* delete_expr  */
  YYSYMBOL_logic_stmt = 151,               /* logic_stmt  */
  YYSYMBOL__symbol_logic_connection = 152, /* _symbol_logic_connection  */
  YYSYMBOL_bool_param_expr = 153,          /* bool_param_expr  */
  YYSYMBOL_type_judge_stmt = 154,          /* type_judge_stmt  */
  YYSYMBOL_not_bool_param_expr = 155,      /* not_bool_param_expr  */
  YYSYMBOL_compare_expr = 156,             /* compare_expr  */
  YYSYMBOL_number_compare_expr = 157,      /* number_compare_expr  */
  YYSYMBOL_object_compare_expr = 158,      /* object_compare_expr  */
  YYSYMBOL__symbol_compare = 159,          /* _symbol_compare  */
  YYSYMBOL__symbol_equals_not = 160,       /* _symbol_equals_not  */
  YYSYMBOL_self_inc_dec_stmt = 161,        /* self_inc_dec_stmt  */
  YYSYMBOL_self_inc_dec_operators = 162,   /* self_inc_dec_operators  */
  YYSYMBOL_assign_stmt_value_eq = 163,     /* assign_stmt_value_eq  */
  YYSYMBOL_array_ele_stmt = 164,           /* array_ele_stmt  */
  YYSYMBOL_assign_stmt = 165,              /* assign_stmt  */
  YYSYMBOL_single_assign_stmt = 166,       /* single_assign_stmt  */
  YYSYMBOL_single_assign_stmt_value = 167, /* single_assign_stmt_value  */
  YYSYMBOL_number_change_assign_stmt = 168, /* number_change_assign_stmt  */
  YYSYMBOL_symbol_change_assign = 169,     /* symbol_change_assign  */
  YYSYMBOL_code_block = 170,               /* code_block  */
  YYSYMBOL_block_item_list = 171,          /* block_item_list  */
  YYSYMBOL_block_item = 172,               /* block_item  */
  YYSYMBOL_string_plus_stmt = 173,         /* string_plus_stmt  */
  YYSYMBOL_string_plus_stmt_value = 174,   /* string_plus_stmt_value  */
  YYSYMBOL_number_parentheses_stmt = 175,  /* number_parentheses_stmt  */
  YYSYMBOL_id_expr = 176,                  /* id_expr  */
  YYSYMBOL_multiple_id_expr = 177,         /* multiple_id_expr  */
  YYSYMBOL_bool_expr = 178,                /* bool_expr  */
  YYSYMBOL_number_expr = 179,              /* number_expr  */
  YYSYMBOL_positive_number_expr = 180,     /* positive_number_expr  */
  YYSYMBOL_int_expr = 181,                 /* int_expr  */
  YYSYMBOL_double_expr = 182,              /* double_expr  */
  YYSYMBOL_uminus_expr = 183,              /* uminus_expr  */
  YYSYMBOL_uminus_expr_values = 184,       /* uminus_expr_values  */
  YYSYMBOL_string_expr = 185,              /* string_expr  */
  YYSYMBOL_null_expr = 186,                /* null_expr  */
  YYSYMBOL_common_types_expr = 187,        /* common_types_expr  */
  YYSYMBOL_common_others_values_expr = 188, /* common_others_values_expr  */
  YYSYMBOL_common_values_expr = 189,       /* common_values_expr  */
  YYSYMBOL_common_result_of_call_expr = 190, /* common_result_of_call_expr  */
  YYSYMBOL_common_assignable_expr = 191,   /* common_assignable_expr  */
  YYSYMBOL_common_number_expr = 192,       /* common_number_expr  */
  YYSYMBOL_common_object_expr = 193,       /* common_object_expr  */
  YYSYMBOL_common_expr = 194               /* common_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  341

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   325


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    77,    72,     2,
      81,    82,    75,    73,    67,    74,    85,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    93,    90,
      62,    69,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    83,     2,    84,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,    70,    92,    79,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    63,    64,    65,    66,
      68,    80,    86,    87,    88,    89
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    84,    85,    88,    89,    90,    91,    92,
      96,   100,   101,   102,   103,   108,   112,   113,   114,   119,
     120,   124,   130,   135,   139,   140,   150,   154,   155,   160,
     161,   165,   166,   170,   171,   175,   176,   177,   178,   183,
     189,   194,   204,   205,   209,   210,   211,   215,   216,   221,
     225,   226,   227,   232,   233,   237,   238,   242,   243,   247,
     248,   253,   254,   259,   260,   264,   265,   269,   273,   274,
     278,   279,   283,   287,   291,   292,   296,   297,   301,   302,
     306,   307,   311,   312,   313,   318,   324,   325,   326,   331,
     332,   337,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   354,   355,   359,   360,   361,   362,   367,   368,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     388,   392,   393,   397,   398,   402,   408,   409,   410,   411,
     412,   416,   417,   422,   423,   428,   432,   437,   438,   442,
     446,   450,   451,   452,   453,   454,   455,   459,   460,   465,
     466,   470,   471,   477,   478,   479,   487,   492,   493,   497,
     501,   502,   506,   510,   511,   512,   513,   514,   519,   520,
     524,   525,   529,   530,   531,   532,   537,   538,   542,   543,
     544,   545,   546,   550,   556,   560,   561,   565,   569,   570,
     574,   575,   579,   583,   587,   591,   592,   593,   594,   598,
     602,   609,   610,   611,   612,   613,   617,   618,   619,   620,
     624,   625,   626,   630,   631,   632,   633,   637,   641,   642,
     643,   647,   648,   657,   658,   659,   660
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TINTEGER", "TBOOL",
  "TDOUBLE", "IDENTIFIER", "TSTRING", "OPERATOR_X__", "OP_CALC", "AND_OP",
  "OR_OP", "FUNC_OP", "FUNC_CALL", "VAR_DECLAR", "ARRAY_ELE", "KEY_TRY",
  "KEY_PUBLIC", "KEY_SET", "KEY_IS", "KEY_REF", "KEY_CONTINUE", "KEY_NEW",
  "KEY_CATCH", "KEY_THIS", "KEY_EXTENDS", "KEY_RESTRICT", "KEY_IF",
  "KEY_ELSE", "KEY_WHILE", "KEY_FOR", "KEY_DELETE", "KEY_BREAK",
  "KEY_RETURN", "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT", "KEY_NULL",
  "CASE_LIST", "CLAXX_BODY", "CLAXX_MEMBER", "CLAXX_FUNC_CALL",
  "SCOPE_FUNC_CALL", "SCOPE", "LEFT_SHIFT", "RIGHT_SHIFT", "KEY_REQUIRE",
  "KEY_REQUIRE_ONCE", "KEY_INCLUDE", "KEY_AUTO", "KEY_CONST", "KEY_LOCAL",
  "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "'>'", "'<'", "INC_OP", "DEC_OP", "IFX", "ELSE", "','",
  "PIPELINE_OP", "'='", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "INC_OP_BACK", "'('", "')'", "'['", "']'", "'.'",
  "PRIORITY3", "PRIORITY2", "PRIORITY1", "UMINUS", "';'", "'{'", "'}'",
  "':'", "$accept", "program", "statement_list", "statement",
  "_extra_nothing", "out_declar_stmt", "require_stmt", "require_operators",
  "try_stmt", "catch_block_stmt", "namespace_declar_stmt",
  "namespace_ref_stmt", "namespace_name_stmt", "class_declar_stmt",
  "class_name_prefix", "class_name_suffix", "class_body",
  "class_body_items", "class_body_item", "this_stmt", "class_member_stmt",
  "static_member_stmt", "func_declar_stmt", "func_name_types",
  "func_param_list", "lambda_stmt", "lambda_args_stmt", "var_declar_stmt",
  "var_prefix", "_elements_var_declar_stmt", "element_var_declar_stmt",
  "con_ctl_stmt", "selection_stmt", "if_stmt", "single_if_stmt",
  "else_stmt", "else_if_stmts", "else_if_stmt", "single_else_stmt",
  "case_stmt_list", "case_stmt", "loop_stmt", "for_logic_stmt",
  "for_1_stmt_list", "for_1_stmt", "for_3_stmt_list", "for_3_stmt",
  "simple_stmt", "simple_stmt_types", "restrict_stmt", "interrupt_stmt",
  "call_statement", "arithmetic_stmt", "new_expr",
  "args_list_with_parentheses", "args_list", "delete_expr", "logic_stmt",
  "_symbol_logic_connection", "bool_param_expr", "type_judge_stmt",
  "not_bool_param_expr", "compare_expr", "number_compare_expr",
  "object_compare_expr", "_symbol_compare", "_symbol_equals_not",
  "self_inc_dec_stmt", "self_inc_dec_operators", "assign_stmt_value_eq",
  "array_ele_stmt", "assign_stmt", "single_assign_stmt",
  "single_assign_stmt_value", "number_change_assign_stmt",
  "symbol_change_assign", "code_block", "block_item_list", "block_item",
  "string_plus_stmt", "string_plus_stmt_value", "number_parentheses_stmt",
  "id_expr", "multiple_id_expr", "bool_expr", "number_expr",
  "positive_number_expr", "int_expr", "double_expr", "uminus_expr",
  "uminus_expr_values", "string_expr", "null_expr", "common_types_expr",
  "common_others_values_expr", "common_values_expr",
  "common_result_of_call_expr", "common_assignable_expr",
  "common_number_expr", "common_object_expr", "common_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    62,    60,   316,   317,   318,   319,    44,   320,    61,
     124,    94,    38,    43,    45,    42,    47,    37,    33,   126,
     321,    40,    41,    91,    93,    46,   322,   323,   324,   325,
      59,   123,   125,    58
};
#endif

#define YYPACT_NINF (-261)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-226)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -261,     8,   467,  -261,  -261,  -261,   -66,    15,    96,  -261,
      96,  -261,   101,    30,    40,    76,    96,  -261,   547,    79,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,    96,  -261,
    -261,  -261,  -261,  -261,   161,  -261,  -261,  -261,  -261,    96,
    -261,  -261,  -261,  -261,   172,  -261,    96,   114,  -261,  -261,
    -261,  -261,   178,  -261,  -261,   126,  -261,  -261,   -24,   129,
    -261,  -261,    52,  -261,  -261,  -261,  -261,   295,   587,   -17,
     748,   137,   320,   167,   154,   140,  -261,   145,  -261,  -261,
     555,   555,    52,  -261,   174,  -261,  -261,  -261,  -261,    28,
     603,   519,  -261,   216,    37,  -261,  -261,   171,   193,   202,
     204,   127,   174,  -261,   157,  -261,  -261,  -261,  -261,   207,
    -261,   214,  -261,   568,    61,   706,   137,  -261,   603,  -261,
    -261,   265,   -52,   114,   210,    96,   100,  -261,   178,  -261,
    -261,  -261,    96,   212,   253,   240,    96,   603,   499,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,   547,   603,   603,    96,
    -261,  -261,  -261,  -261,  -261,   418,  -261,   184,   217,  -261,
      96,    96,  -261,   591,   603,    10,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,    17,   309,    33,   698,
     155,    43,    27,  -261,  -261,   145,    96,   -24,  -261,  -261,
    -261,   280,  -261,   374,  -261,  -261,  -261,    49,   649,   -66,
     161,   583,   603,   603,   603,   603,   603,   603,   603,   603,
     603,   603,   664,    96,   208,    24,   -66,  -261,  -261,  -261,
    -261,  -261,  -261,   145,  -261,   615,  -261,    66,  -261,  -261,
    -261,   235,  -261,   706,   630,  -261,  -261,  -261,    96,   140,
    -261,  -261,  -261,  -261,   -66,   555,  -261,  -261,  -261,  -261,
    -261,  -261,   603,    96,  -261,  -261,   398,   -66,    52,   555,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,   196,   196,   717,   353,   722,   160,   160,  -261,  -261,
    -261,   221,   174,    18,  -261,  -261,   136,  -261,  -261,  -261,
     547,  -261,  -261,   223,  -261,   119,   706,  -261,    31,  -261,
    -261,  -261,  -261,   228,   119,   162,  -261,  -261,    90,  -261,
    -261,   232,   234,  -261,  -261,   -66,   189,   310,   238,   169,
    -261,  -261,  -261,  -261,  -261,  -261,   150,  -261,  -261,  -261,
     246,   -66,  -261,  -261,   189,   -66,   -66,  -261,  -261,  -261,
    -261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   184,    46,     0,     0,     0,   106,
       0,    39,   101,     0,     0,     0,     0,   103,   104,     0,
      16,    17,    18,    28,    55,    56,   151,   152,     0,    10,
       3,     5,     6,    99,     0,     9,    13,    14,    12,     0,
     211,   208,   209,    11,     0,   100,     0,    53,    57,     7,
      61,    63,    65,    62,     8,     0,    98,    96,    94,   212,
      95,    92,     0,   207,    93,   157,   158,   206,   210,   221,
       0,     0,     0,    19,     0,    23,    24,     0,   187,   102,
       0,     0,    82,   185,   125,   192,   193,   199,   200,     0,
       0,     0,   204,     0,   214,   215,   212,   213,   226,     0,
     216,   206,    52,   205,   218,   188,   191,   190,   189,   202,
     203,   223,   210,   219,   220,     0,   178,   105,     0,    45,
      15,    29,     0,    54,    59,     0,     0,    66,     0,    70,
      69,    91,     0,   222,   206,   149,     0,     0,     0,   107,
     150,   163,   164,   165,   166,   167,     0,     0,     0,     0,
     168,   175,   172,   174,   173,     0,   170,   206,     0,    20,
       0,     0,   120,     0,     0,     0,   126,   128,   127,   129,
     137,   138,   213,   133,   216,   134,   218,   219,   220,     0,
       0,     0,     0,    83,    85,   221,     0,   197,   198,   195,
     194,   196,   218,   219,   220,   119,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    58,    72,
      73,    71,    68,     0,    41,     0,   121,     0,   123,   161,
     159,     0,   160,   162,     0,    40,   169,   171,     0,    22,
      25,   136,   131,   132,     0,     0,   144,   143,   146,   145,
     141,   142,     0,     0,   148,   147,     0,     0,     0,    80,
     186,    51,   183,    49,   177,   181,   180,   176,   182,   201,
     179,   117,   118,   115,   116,   114,   109,   110,   111,   112,
     113,     0,    30,     0,    26,    47,     0,    43,   108,    60,
       0,   122,   156,     0,    67,   130,   139,   135,     0,   202,
     140,    78,    84,     0,    81,     0,    31,    38,     0,    33,
      37,     0,     0,    48,   124,     0,    86,     0,     0,     0,
      74,    32,    34,    35,    36,    21,     0,    87,    90,    89,
       0,     0,    64,    75,     0,     0,     0,    77,    88,    79,
      76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,  -261,  -261,  -261,     3,  -261,  -261,  -261,   325,  -261,
    -261,  -261,   180,  -261,  -261,  -261,  -261,  -261,    35,  -261,
    -261,  -261,   354,  -261,  -261,  -261,  -261,  -260,  -261,   311,
     239,   358,  -261,  -261,   243,  -261,  -261,   248,   249,  -261,
      55,  -261,  -261,  -261,   121,  -261,    46,   379,  -261,  -261,
    -261,     0,  -261,     9,   -58,  -261,  -261,   -67,  -261,   219,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,    -1,   -18,  -261,
    -261,   -70,  -137,  -261,  -261,  -261,   -81,  -261,   231,   186,
     187,   -12,    47,    -3,    23,   -14,   300,    78,  -261,  -261,
    -261,   -27,  -261,  -165,     1,    -2,     4,  -131,   211,    20,
    -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    30,   151,    32,    33,    34,   152,   159,
      36,    37,    75,    38,    39,   214,   284,   308,   309,    40,
      41,    42,   310,    44,   216,    92,    93,    45,    46,    47,
      48,   153,    50,    51,    52,   127,   128,   129,   130,   319,
     320,    53,   303,   182,   183,   326,   327,   154,    55,    56,
      57,    94,    95,    96,   139,   227,    60,   165,   245,   166,
     167,   168,   169,   170,   171,   252,   256,   172,    62,   173,
      63,    64,    65,   230,    66,   147,    73,   155,   156,    98,
      99,   174,   134,   102,   103,   192,   105,   106,   107,   108,
     190,   109,   110,   111,   112,   193,   194,    70,   115,    71,
     117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    61,    58,    68,   104,    31,   100,   120,     3,   229,
     228,    59,   184,    84,   181,   231,   113,    97,   232,   162,
     242,   243,   114,   311,     4,    72,     5,  -153,  -153,   215,
       4,    85,    74,    86,     4,    79,   270,     4,   116,    72,
      10,   217,    11,  -155,  -155,   220,    26,    27,   311,    67,
      10,   140,    11,   242,   243,    76,  -222,    77,     4,  -222,
     135,   132,   133,    83,   138,   101,   176,   176,    24,    25,
      69,    61,    58,    68,    10,   119,    11,   188,   177,   177,
     185,    59,   133,    68,   178,   178,   121,   185,   197,   187,
     191,   300,   244,   124,   258,   140,     4,    28,     5,  -153,
     180,   180,     4,   175,   175,    78,   285,  -153,    29,   164,
     306,    80,    10,   196,    11,  -155,   186,   259,   263,   157,
    -222,    81,   132,  -155,   104,   257,   100,    13,  -225,   242,
     243,   261,   104,   290,   100,   287,   113,    97,   101,  -185,
      24,    25,   114,  -225,   113,    97,   312,    68,   291,   176,
     114,  -225,   231,    69,    61,    58,    68,    82,   116,   140,
     118,   177,   314,   294,    59,   288,   116,   178,    87,    28,
     136,   312,   124,   264,   253,   140,   301,   231,   295,   223,
      29,   125,   321,   224,   122,   101,   175,   269,   184,   268,
     158,    72,   304,   101,  -185,     4,   235,   317,   318,    69,
     265,   133,   157,   186,   317,   318,   126,    76,   240,  -185,
     282,    10,   286,    11,   254,   255,   131,   334,   313,   -97,
     148,   116,   149,   160,  -201,   161,   138,   136,   199,   299,
    -201,   176,   335,   260,   325,   209,   210,   211,   148,  -201,
     149,   186,   269,   177,  -181,   176,   329,  -201,   101,   178,
     337,   -59,    26,    27,   339,   340,   185,   177,   133,    68,
      83,   332,    83,   178,   329,   180,  -180,   137,   175,   207,
     208,   209,   210,   211,   -59,   200,   104,  -182,   100,   180,
     201,   185,   175,   133,    68,   293,   307,  -179,   113,    97,
     213,   179,   179,   137,   114,   197,   136,   132,   238,   283,
     297,   195,   198,    83,   146,   315,   185,   -44,   133,    68,
     116,   307,   305,    85,    69,   328,   133,    68,   316,  -154,
    -154,   138,   323,  -221,   324,  -221,     4,    35,  -221,   212,
      67,   331,    69,   328,   133,    68,     6,   101,   136,   336,
     239,     9,    10,   322,    11,    83,    12,    13,   225,    14,
      15,    16,    17,    18,    19,    67,    43,   123,   233,   234,
      49,  -210,   -59,  -210,   218,  -210,    20,    21,    22,   219,
      24,    25,    26,    27,   333,   198,   221,   222,   137,   302,
     338,    54,   241,    26,    27,   -59,   237,   266,   267,   189,
     138,  -154,  -221,     0,  -221,   330,     0,   202,   203,  -154,
       0,    85,    78,    86,     4,    87,     0,     0,     0,     0,
      29,     0,   150,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,     0,     4,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     6,    88,     0,    26,    27,     9,
      10,     0,    11,     0,    12,    13,     0,    14,    15,    16,
      17,    18,    19,     0,     0,   138,   179,  -221,     0,  -221,
       0,     0,     0,   296,    20,    21,    22,     0,    24,    25,
     179,     0,    89,     4,     0,     5,     0,     0,     0,   298,
       0,    26,    27,     6,     0,     7,     0,     8,     9,    10,
       0,    11,     0,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    85,    78,    86,     4,    87,     0,    29,     0,
     236,     0,     0,    20,    21,    22,    23,    24,    25,     0,
       0,    10,    85,    11,    86,     4,     0,     0,     0,     0,
      26,    27,     0,     0,     0,     0,    88,     0,     0,     0,
       0,    10,     0,    11,     0,     0,    28,     0,     0,     0,
      85,    78,    86,     4,    87,     0,     0,    29,    85,    78,
      86,     4,    26,    27,     0,     0,     0,     0,     0,    10,
       0,    11,     0,    89,     0,     0,     0,    10,    90,    11,
      91,   226,    26,    27,    88,     0,    85,    78,    86,     4,
      87,     0,     0,    89,    85,    78,    86,     4,    90,     0,
     164,   196,     0,     0,     0,    10,    85,    11,    86,     4,
      26,    27,     0,    10,     0,    11,     0,     0,    26,    27,
      88,    89,     0,     0,     0,    10,    90,    11,    91,    89,
       0,    26,    27,   163,    90,  -224,   164,     0,     0,  -217,
    -217,  -217,  -217,  -217,     0,     0,    26,    27,     0,   138,
    -224,  -221,     0,  -221,    26,    27,  -217,    89,  -224,   202,
     203,     0,     0,     0,    91,    89,    26,    27,     0,     0,
      90,     0,   164,     0,   202,   203,     0,    89,     0,     0,
       0,     0,    90,     0,   164,   204,   205,   206,   207,   208,
     209,   210,   211,   202,   203,     0,     0,     0,     0,   289,
     204,   205,   206,   207,   208,   209,   210,   211,   202,   203,
       0,     0,     0,     0,   292,     0,     0,     0,     0,   204,
     205,   206,   207,   208,   209,   210,   211,     0,     0,     0,
       0,   262,     0,     0,   204,   205,   206,   207,   208,   209,
     210,   211,   202,   203,     0,     0,   281,     0,     0,     0,
     202,   203,     0,     0,     0,   246,   247,   248,   249,   250,
     251,   202,   203,     0,     0,     0,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   204,   205,   206,   207,
     208,   209,   210,   211,     0,     0,     0,     0,   205,   206,
     207,   208,   209,   210,   211,   207,   208,   209,   210,   211,
     141,   142,   143,   144,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,    18,     2,    18,    34,     0,   146,
     138,     2,    82,    16,    81,   146,    18,    18,   146,    77,
      10,    11,    18,   283,     6,    91,     8,    10,    11,    81,
       6,     3,    17,     5,     6,    12,   201,     6,    18,    91,
      22,   122,    24,    10,    11,   126,    63,    64,   308,     2,
      22,    69,    24,    10,    11,     8,    19,    10,     6,    83,
      62,    85,    62,    16,    81,    18,    80,    81,    50,    51,
      72,    72,    72,    72,    22,    28,    24,    89,    80,    81,
      82,    72,    82,    82,    80,    81,    39,    89,    91,    89,
      89,   256,    82,    46,    67,   113,     6,    79,     8,    82,
      80,    81,     6,    80,    81,     4,    82,    90,    90,    81,
      92,    81,    22,    82,    24,    82,    67,    90,   199,    72,
      83,    81,    85,    90,   138,    82,   138,    27,    67,    10,
      11,    82,   146,    67,   146,   216,   138,   138,    91,    12,
      50,    51,   138,    82,   146,   146,   283,   146,    82,   163,
     146,    90,   283,   155,   155,   155,   155,    81,   138,   177,
      81,   163,   290,   244,   155,   223,   146,   163,     7,    79,
      43,   308,   125,   200,    19,   193,   257,   308,   245,   132,
      90,    67,    92,   136,    12,   138,   163,   201,   258,   201,
      23,    91,   259,   146,    67,     6,   149,    35,    36,   201,
     201,   201,   155,    67,    35,    36,    28,   160,   161,    82,
     213,    22,   215,    24,    59,    60,    90,    67,    82,    90,
      83,   201,    85,    69,    67,    85,    81,    43,    12,   256,
      73,   245,    82,   186,   315,    75,    76,    77,    83,    82,
      85,    67,   256,   245,    73,   259,   316,    90,   201,   245,
     331,    67,    63,    64,   335,   336,   258,   259,   258,   258,
     213,    92,   215,   259,   334,   245,    73,    83,   245,    73,
      74,    75,    76,    77,    90,    73,   290,    73,   290,   259,
      73,   283,   259,   283,   283,   238,   283,    73,   290,   290,
      25,    80,    81,    83,   290,   298,    43,    85,    81,    91,
     253,    90,    91,   256,    69,    82,   308,    12,   308,   308,
     290,   308,    91,     3,   316,   316,   316,   316,    90,    10,
      11,    81,    90,    83,    90,    85,     6,     2,    19,   118,
     283,    93,   334,   334,   334,   334,    16,   290,    43,    93,
     160,    21,    22,   308,    24,   298,    26,    27,   137,    29,
      30,    31,    32,    33,    34,   308,     2,    46,   147,   148,
       2,    81,    67,    83,   125,    85,    46,    47,    48,   126,
      50,    51,    63,    64,   319,   164,   128,   128,    83,   258,
     334,     2,   163,    63,    64,    90,   155,   201,   201,    89,
      81,    82,    83,    -1,    85,   317,    -1,    44,    45,    90,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      90,    -1,    92,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,     6,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    16,    37,    -1,    63,    64,    21,
      22,    -1,    24,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    -1,    81,   245,    83,    -1,    85,
      -1,    -1,    -1,   252,    46,    47,    48,    -1,    50,    51,
     259,    -1,    74,     6,    -1,     8,    -1,    -1,    -1,    81,
      -1,    63,    64,    16,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    -1,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,     3,     4,     5,     6,     7,    -1,    90,    -1,
      92,    -1,    -1,    46,    47,    48,    49,    50,    51,    -1,
      -1,    22,     3,    24,     5,     6,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    22,    -1,    24,    -1,    -1,    79,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    90,     3,     4,
       5,     6,    63,    64,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    24,    -1,    74,    -1,    -1,    -1,    22,    79,    24,
      81,    82,    63,    64,    37,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    74,     3,     4,     5,     6,    79,    -1,
      81,    82,    -1,    -1,    -1,    22,     3,    24,     5,     6,
      63,    64,    -1,    22,    -1,    24,    -1,    -1,    63,    64,
      37,    74,    -1,    -1,    -1,    22,    79,    24,    81,    74,
      -1,    63,    64,    78,    79,    67,    81,    -1,    -1,    52,
      53,    54,    55,    56,    -1,    -1,    63,    64,    -1,    81,
      82,    83,    -1,    85,    63,    64,    69,    74,    90,    44,
      45,    -1,    -1,    -1,    81,    74,    63,    64,    -1,    -1,
      79,    -1,    81,    -1,    44,    45,    -1,    74,    -1,    -1,
      -1,    -1,    79,    -1,    81,    70,    71,    72,    73,    74,
      75,    76,    77,    44,    45,    -1,    -1,    -1,    -1,    84,
      70,    71,    72,    73,    74,    75,    76,    77,    44,    45,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    44,    45,    -1,    -1,    82,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    57,    58,    59,    60,    61,
      62,    44,    45,    -1,    -1,    -1,    44,    45,    70,    71,
      72,    73,    74,    75,    76,    77,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    73,    74,    75,    76,    77,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    95,    96,     0,     6,     8,    16,    18,    20,    21,
      22,    24,    26,    27,    29,    30,    31,    32,    33,    34,
      46,    47,    48,    49,    50,    51,    63,    64,    79,    90,
      97,    98,    99,   100,   101,   102,   104,   105,   107,   108,
     113,   114,   115,   116,   117,   121,   122,   123,   124,   125,
     126,   127,   128,   135,   141,   142,   143,   144,   145,   147,
     150,   161,   162,   164,   165,   166,   168,   176,   188,   189,
     191,   193,    91,   170,    17,   106,   176,   176,     4,   178,
      81,    81,    81,   176,   177,     3,     5,     7,    37,    74,
      79,    81,   119,   120,   145,   146,   147,   161,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   185,
     186,   187,   188,   189,   190,   192,   193,   194,    81,   176,
     185,   176,    12,   123,   176,    67,    28,   129,   130,   131,
     132,    90,    85,   145,   176,   189,    43,    83,    81,   148,
     162,    52,    53,    54,    55,    56,    69,   169,    83,    85,
      92,    98,   102,   125,   141,   171,   172,   176,    23,   103,
      69,    85,   148,    78,    81,   151,   153,   154,   155,   156,
     157,   158,   161,   163,   175,   178,   179,   189,   190,   192,
     193,   151,   137,   138,   165,   189,    67,   145,   175,   180,
     184,   188,   179,   189,   190,   192,    82,   177,   192,    12,
      73,    73,    44,    45,    70,    71,    72,    73,    74,    75,
      76,    77,   192,    25,   109,    81,   118,   170,   124,   128,
     170,   131,   132,   176,   176,   192,    82,   149,   194,   166,
     167,   191,   194,   192,   192,   176,    92,   172,    81,   106,
     176,   153,    10,    11,    82,   152,    57,    58,    59,    60,
      61,    62,   159,    19,    59,    60,   160,    82,    67,    90,
     176,    82,    82,   170,   185,   161,   173,   174,   175,   179,
     187,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,    82,   177,    91,   110,    82,   177,   170,   148,    84,
      67,    82,    84,   176,   170,   151,   192,   176,    81,   185,
     187,   170,   138,   136,   151,    91,    92,    98,   111,   112,
     116,   121,   166,    82,   194,    82,    90,    35,    36,   133,
     134,    92,   112,    90,    90,   170,   139,   140,   161,   165,
     181,    93,    92,   134,    67,    82,    93,   170,   140,   170,
     170
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    96,    96,    97,    97,    97,    97,    97,
      98,    99,    99,    99,    99,   100,   101,   101,   101,   102,
     102,   103,   104,   105,   106,   106,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   112,   112,   113,
     114,   115,   116,   116,   117,   117,   117,   118,   118,   119,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   129,   129,
     130,   130,   131,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   137,   138,   139,   139,   139,   140,
     140,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   143,   143,   144,   144,   144,   144,   145,   145,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   148,   148,   149,   149,   150,   151,   151,   151,   151,
     151,   152,   152,   153,   153,   154,   155,   156,   156,   157,
     158,   159,   159,   159,   159,   159,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   163,   164,   165,   165,   166,
     167,   167,   168,   169,   169,   169,   169,   169,   170,   170,
     171,   171,   172,   172,   172,   172,   173,   173,   174,   174,
     174,   174,   174,   175,   176,   177,   177,   178,   179,   179,
     180,   180,   181,   182,   183,   184,   184,   184,   184,   185,
     186,   187,   187,   187,   187,   187,   188,   188,   188,   188,
     189,   189,   189,   190,   190,   190,   190,   191,   192,   192,
     192,   193,   193,   194,   194,   194,   194
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     5,     4,     2,     1,     3,     4,     0,     1,     0,
       2,     2,     3,     1,     2,     2,     2,     1,     1,     1,
       3,     3,     3,     4,     1,     2,     1,     2,     3,     3,
       2,     3,     1,     1,     2,     1,     1,     1,     3,     1,
       4,     1,     1,     1,     7,     1,     2,     5,     2,     1,
       1,     2,     2,     2,     1,     2,     4,     3,     5,     9,
       0,     1,     0,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     2,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     2,     3,     1,     3,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     2,     1,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     4,     1,     1,     3,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     3,
       1,     2,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* statement_list: statement_list statement  */
#line 84 "a.y"
                                   { execAndFreeNode((yyvsp[0].node));}
#line 1840 "y.tab.c"
    break;

  case 5: /* statement: _extra_nothing  */
#line 88 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1846 "y.tab.c"
    break;

  case 6: /* statement: out_declar_stmt  */
#line 89 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1852 "y.tab.c"
    break;

  case 7: /* statement: con_ctl_stmt  */
#line 90 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1858 "y.tab.c"
    break;

  case 8: /* statement: simple_stmt  */
#line 91 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1864 "y.tab.c"
    break;

  case 9: /* statement: try_stmt  */
#line 92 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1870 "y.tab.c"
    break;

  case 10: /* _extra_nothing: ';'  */
#line 96 "a.y"
                { (yyval.node) = NULL; }
#line 1876 "y.tab.c"
    break;

  case 11: /* out_declar_stmt: func_declar_stmt  */
#line 100 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1882 "y.tab.c"
    break;

  case 12: /* out_declar_stmt: class_declar_stmt  */
#line 101 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1888 "y.tab.c"
    break;

  case 13: /* out_declar_stmt: namespace_declar_stmt  */
#line 102 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1894 "y.tab.c"
    break;

  case 14: /* out_declar_stmt: namespace_ref_stmt  */
#line 103 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1900 "y.tab.c"
    break;

  case 15: /* require_stmt: require_operators string_expr  */
#line 108 "a.y"
                                                { (yyval.node) = opr((yyvsp[-1].iValue) , 1 , (yyvsp[0].node)); }
#line 1906 "y.tab.c"
    break;

  case 16: /* require_operators: KEY_REQUIRE  */
#line 112 "a.y"
                              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1912 "y.tab.c"
    break;

  case 17: /* require_operators: KEY_REQUIRE_ONCE  */
#line 113 "a.y"
                              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1918 "y.tab.c"
    break;

  case 18: /* require_operators: KEY_INCLUDE  */
#line 114 "a.y"
                             { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1924 "y.tab.c"
    break;

  case 19: /* try_stmt: KEY_TRY code_block  */
#line 119 "a.y"
                               { (yyval.node) = opr(KEY_TRY, 2,(yyvsp[0].node),NULL); }
#line 1930 "y.tab.c"
    break;

  case 20: /* try_stmt: KEY_TRY code_block catch_block_stmt  */
#line 120 "a.y"
                                               { (yyval.node) = opr(KEY_TRY, 2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1936 "y.tab.c"
    break;

  case 21: /* catch_block_stmt: KEY_CATCH '(' id_expr ')' code_block  */
#line 124 "a.y"
                                                { (yyval.node) = opr(KEY_CATCH, 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1942 "y.tab.c"
    break;

  case 22: /* namespace_declar_stmt: KEY_SET KEY_PUBLIC '=' namespace_name_stmt  */
#line 130 "a.y"
                                                     { (yyval.node) = NULL; }
#line 1948 "y.tab.c"
    break;

  case 23: /* namespace_ref_stmt: KEY_REF namespace_name_stmt  */
#line 135 "a.y"
                                        { (yyval.node) = opr(KEY_REF, 1, (yyvsp[0].node)); }
#line 1954 "y.tab.c"
    break;

  case 24: /* namespace_name_stmt: id_expr  */
#line 139 "a.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1960 "y.tab.c"
    break;

  case 25: /* namespace_name_stmt: namespace_name_stmt '.' id_expr  */
#line 140 "a.y"
                                          { (yyval.node) = NULL; }
#line 1966 "y.tab.c"
    break;

  case 26: /* class_declar_stmt: class_name_prefix id_expr class_name_suffix class_body  */
#line 150 "a.y"
                                                                     {  (yyval.node) = NULL; }
#line 1972 "y.tab.c"
    break;

  case 27: /* class_name_prefix: %empty  */
#line 154 "a.y"
             { (yyval.iValue) = -1; }
#line 1978 "y.tab.c"
    break;

  case 28: /* class_name_prefix: KEY_AUTO  */
#line 155 "a.y"
                 { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1984 "y.tab.c"
    break;

  case 29: /* class_name_suffix: %empty  */
#line 160 "a.y"
                              { (yyval.node) = NULL; }
#line 1990 "y.tab.c"
    break;

  case 30: /* class_name_suffix: KEY_EXTENDS multiple_id_expr  */
#line 161 "a.y"
                                        { (yyval.node) = NULL; }
#line 1996 "y.tab.c"
    break;

  case 31: /* class_body: '{' '}'  */
#line 165 "a.y"
                        { (yyval.node) = NULL; }
#line 2002 "y.tab.c"
    break;

  case 32: /* class_body: '{' class_body_items '}'  */
#line 166 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2008 "y.tab.c"
    break;

  case 33: /* class_body_items: class_body_item  */
#line 170 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2014 "y.tab.c"
    break;

  case 34: /* class_body_items: class_body_items class_body_item  */
#line 171 "a.y"
                                        { (yyval.node) = NULL; }
#line 2020 "y.tab.c"
    break;

  case 35: /* class_body_item: var_declar_stmt ';'  */
#line 175 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2026 "y.tab.c"
    break;

  case 36: /* class_body_item: single_assign_stmt ';'  */
#line 176 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2032 "y.tab.c"
    break;

  case 37: /* class_body_item: func_declar_stmt  */
#line 177 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2038 "y.tab.c"
    break;

  case 38: /* class_body_item: _extra_nothing  */
#line 178 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2044 "y.tab.c"
    break;

  case 39: /* this_stmt: KEY_THIS  */
#line 183 "a.y"
                      { (yyval.node) = opr(KEY_THIS , 0 ); }
#line 2050 "y.tab.c"
    break;

  case 40: /* class_member_stmt: common_object_expr '.' id_expr  */
#line 189 "a.y"
                                               { (yyval.node) = NULL; }
#line 2056 "y.tab.c"
    break;

  case 41: /* static_member_stmt: id_expr SCOPE id_expr  */
#line 194 "a.y"
                                  { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2062 "y.tab.c"
    break;

  case 42: /* func_declar_stmt: func_name_types FUNC_OP code_block  */
#line 204 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2068 "y.tab.c"
    break;

  case 43: /* func_declar_stmt: func_name_types FUNC_OP func_param_list code_block  */
#line 205 "a.y"
                                                                    { (yyval.node) = NULL; }
#line 2074 "y.tab.c"
    break;

  case 44: /* func_name_types: id_expr  */
#line 209 "a.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2080 "y.tab.c"
    break;

  case 45: /* func_name_types: '~' id_expr  */
#line 210 "a.y"
                    { (yyval.node) = NULL; }
#line 2086 "y.tab.c"
    break;

  case 46: /* func_name_types: OPERATOR_X__  */
#line 211 "a.y"
                    { (yyval.node) = NULL; }
#line 2092 "y.tab.c"
    break;

  case 47: /* func_param_list: '(' ')'  */
#line 215 "a.y"
                        { (yyval.node) = NULL; }
#line 2098 "y.tab.c"
    break;

  case 48: /* func_param_list: '(' multiple_id_expr ')'  */
#line 216 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2104 "y.tab.c"
    break;

  case 49: /* lambda_stmt: lambda_args_stmt FUNC_OP code_block  */
#line 221 "a.y"
                                                { (yyval.node) = lambda((yyvsp[-2].params),(yyvsp[0].node)) ; }
#line 2110 "y.tab.c"
    break;

  case 50: /* lambda_args_stmt: '(' ')'  */
#line 225 "a.y"
                     { (yyval.params) = NULL; }
#line 2116 "y.tab.c"
    break;

  case 51: /* lambda_args_stmt: '(' multiple_id_expr ')'  */
#line 226 "a.y"
                              { (yyval.params) = NULL; }
#line 2122 "y.tab.c"
    break;

  case 52: /* lambda_args_stmt: multiple_id_expr  */
#line 227 "a.y"
                              { (yyval.params) = NULL; }
#line 2128 "y.tab.c"
    break;

  case 53: /* var_declar_stmt: _elements_var_declar_stmt  */
#line 232 "a.y"
                                     { (yyval.node) = opr(VAR_DECLAR , 1, (yyvsp[0].node) ); }
#line 2134 "y.tab.c"
    break;

  case 54: /* var_declar_stmt: var_prefix _elements_var_declar_stmt  */
#line 233 "a.y"
                                               { (yyval.node) = NULL; }
#line 2140 "y.tab.c"
    break;

  case 55: /* var_prefix: KEY_CONST  */
#line 237 "a.y"
                 { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2146 "y.tab.c"
    break;

  case 56: /* var_prefix: KEY_LOCAL  */
#line 238 "a.y"
                 { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2152 "y.tab.c"
    break;

  case 57: /* _elements_var_declar_stmt: element_var_declar_stmt  */
#line 242 "a.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 2158 "y.tab.c"
    break;

  case 58: /* _elements_var_declar_stmt: _elements_var_declar_stmt ',' element_var_declar_stmt  */
#line 243 "a.y"
                                                           { (yyval.node) = NULL; }
#line 2164 "y.tab.c"
    break;

  case 59: /* element_var_declar_stmt: id_expr  */
#line 247 "a.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2170 "y.tab.c"
    break;

  case 60: /* element_var_declar_stmt: id_expr '[' common_number_expr ']'  */
#line 248 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2176 "y.tab.c"
    break;

  case 61: /* con_ctl_stmt: selection_stmt  */
#line 253 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2182 "y.tab.c"
    break;

  case 62: /* con_ctl_stmt: loop_stmt  */
#line 254 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2188 "y.tab.c"
    break;

  case 63: /* selection_stmt: if_stmt  */
#line 259 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2194 "y.tab.c"
    break;

  case 64: /* selection_stmt: KEY_SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  */
#line 260 "a.y"
                                                                        { (yyval.node) = opr(KEY_SWITCH, 2 , (yyvsp[-4].node),(yyvsp[-1].node)); pretreatSwitch( (yyval.node) ) ; }
#line 2200 "y.tab.c"
    break;

  case 65: /* if_stmt: single_if_stmt  */
#line 264 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2206 "y.tab.c"
    break;

  case 66: /* if_stmt: single_if_stmt else_stmt  */
#line 265 "a.y"
                             { (yyval.node) = NULL; }
#line 2212 "y.tab.c"
    break;

  case 67: /* single_if_stmt: KEY_IF '(' logic_stmt ')' code_block  */
#line 269 "a.y"
                                         { (yyval.node) = opr(KEY_IF ,2,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2218 "y.tab.c"
    break;

  case 68: /* else_stmt: else_if_stmts single_else_stmt  */
#line 273 "a.y"
                                      { (yyval.node) =  NULL; }
#line 2224 "y.tab.c"
    break;

  case 69: /* else_stmt: single_else_stmt  */
#line 274 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2230 "y.tab.c"
    break;

  case 70: /* else_if_stmts: else_if_stmt  */
#line 278 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2236 "y.tab.c"
    break;

  case 71: /* else_if_stmts: else_if_stmts else_if_stmt  */
#line 279 "a.y"
                                  { (yyval.node) =  NULL; }
#line 2242 "y.tab.c"
    break;

  case 72: /* else_if_stmt: KEY_ELSE single_if_stmt  */
#line 283 "a.y"
                              { (yyval.node) = NULL; }
#line 2248 "y.tab.c"
    break;

  case 73: /* single_else_stmt: KEY_ELSE code_block  */
#line 287 "a.y"
                            { (yyval.node) = NULL; }
#line 2254 "y.tab.c"
    break;

  case 74: /* case_stmt_list: case_stmt  */
#line 291 "a.y"
                               { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[0].node) ); }
#line 2260 "y.tab.c"
    break;

  case 75: /* case_stmt_list: case_stmt_list case_stmt  */
#line 292 "a.y"
                                   { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[-1].node), (yyvsp[0].node) ); }
#line 2266 "y.tab.c"
    break;

  case 76: /* case_stmt: KEY_CASE int_expr ':' code_block  */
#line 296 "a.y"
                                                  { (yyval.node) = opr(KEY_CASE, 2 , (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2272 "y.tab.c"
    break;

  case 77: /* case_stmt: KEY_DEFAULT ':' code_block  */
#line 297 "a.y"
                                                     { (yyval.node) = opr(KEY_DEFAULT , 1, (yyvsp[0].node)); }
#line 2278 "y.tab.c"
    break;

  case 78: /* loop_stmt: KEY_WHILE '(' logic_stmt ')' code_block  */
#line 301 "a.y"
                                                  { (yyval.node) = opr(KEY_WHILE , 2, (yyvsp[-2].node), (yyvsp[0].node) ); }
#line 2284 "y.tab.c"
    break;

  case 79: /* loop_stmt: KEY_FOR '(' for_1_stmt_list ';' for_logic_stmt ';' for_3_stmt_list ')' code_block  */
#line 302 "a.y"
                                                                                            { (yyval.node) = opr(KEY_FOR,4,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2290 "y.tab.c"
    break;

  case 80: /* for_logic_stmt: %empty  */
#line 306 "a.y"
          { (yyval.node) = NULL;  }
#line 2296 "y.tab.c"
    break;

  case 81: /* for_logic_stmt: logic_stmt  */
#line 307 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2302 "y.tab.c"
    break;

  case 82: /* for_1_stmt_list: %empty  */
#line 311 "a.y"
         { (yyval.node) = NULL ; }
#line 2308 "y.tab.c"
    break;

  case 83: /* for_1_stmt_list: for_1_stmt  */
#line 312 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2314 "y.tab.c"
    break;

  case 84: /* for_1_stmt_list: for_1_stmt_list ',' for_1_stmt  */
#line 313 "a.y"
                                      { (yyval.node) = NULL; }
#line 2320 "y.tab.c"
    break;

  case 85: /* for_1_stmt: assign_stmt  */
#line 318 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2326 "y.tab.c"
    break;

  case 86: /* for_3_stmt_list: %empty  */
#line 324 "a.y"
         { (yyval.node) = NULL ; }
#line 2332 "y.tab.c"
    break;

  case 87: /* for_3_stmt_list: for_3_stmt  */
#line 325 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2338 "y.tab.c"
    break;

  case 88: /* for_3_stmt_list: for_3_stmt_list ',' for_3_stmt  */
#line 326 "a.y"
                                      { (yyval.node) = NULL; }
#line 2344 "y.tab.c"
    break;

  case 89: /* for_3_stmt: assign_stmt  */
#line 331 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2350 "y.tab.c"
    break;

  case 90: /* for_3_stmt: self_inc_dec_stmt  */
#line 332 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2356 "y.tab.c"
    break;

  case 91: /* simple_stmt: simple_stmt_types ';'  */
#line 337 "a.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 2362 "y.tab.c"
    break;

  case 92: /* simple_stmt_types: self_inc_dec_stmt  */
#line 341 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2368 "y.tab.c"
    break;

  case 93: /* simple_stmt_types: assign_stmt  */
#line 342 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2374 "y.tab.c"
    break;

  case 94: /* simple_stmt_types: call_statement  */
#line 343 "a.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 2380 "y.tab.c"
    break;

  case 95: /* simple_stmt_types: delete_expr  */
#line 344 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2386 "y.tab.c"
    break;

  case 96: /* simple_stmt_types: interrupt_stmt  */
#line 345 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2392 "y.tab.c"
    break;

  case 97: /* simple_stmt_types: new_expr  */
#line 346 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2398 "y.tab.c"
    break;

  case 98: /* simple_stmt_types: restrict_stmt  */
#line 347 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2404 "y.tab.c"
    break;

  case 99: /* simple_stmt_types: require_stmt  */
#line 348 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2410 "y.tab.c"
    break;

  case 100: /* simple_stmt_types: var_declar_stmt  */
#line 349 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2416 "y.tab.c"
    break;

  case 101: /* restrict_stmt: KEY_RESTRICT  */
#line 354 "a.y"
                             { (yyval.node) = opr(KEY_RESTRICT,0);}
#line 2422 "y.tab.c"
    break;

  case 102: /* restrict_stmt: KEY_RESTRICT bool_expr  */
#line 355 "a.y"
                                  { (yyval.node) = opr(KEY_RESTRICT,1,(yyvsp[0].node)); }
#line 2428 "y.tab.c"
    break;

  case 103: /* interrupt_stmt: KEY_BREAK  */
#line 359 "a.y"
                    { (yyval.node) = opr(KEY_BREAK, 0); }
#line 2434 "y.tab.c"
    break;

  case 104: /* interrupt_stmt: KEY_RETURN  */
#line 360 "a.y"
                     { (yyval.node) = opr(KEY_RETURN , 0); }
#line 2440 "y.tab.c"
    break;

  case 105: /* interrupt_stmt: KEY_RETURN common_expr  */
#line 361 "a.y"
                                 { (yyval.node) = opr(KEY_RETURN , 1 ,(yyvsp[0].node));}
#line 2446 "y.tab.c"
    break;

  case 106: /* interrupt_stmt: KEY_CONTINUE  */
#line 362 "a.y"
                 { (yyval.node) = opr(KEY_CONTINUE,0); }
#line 2452 "y.tab.c"
    break;

  case 107: /* call_statement: common_values_expr args_list_with_parentheses  */
#line 367 "a.y"
                                                                        { (yyval.node) = NULL; }
#line 2458 "y.tab.c"
    break;

  case 108: /* call_statement: call_statement '.' id_expr args_list_with_parentheses  */
#line 368 "a.y"
                                                                           { (yyval.node) = NULL; }
#line 2464 "y.tab.c"
    break;

  case 109: /* arithmetic_stmt: common_number_expr '+' common_number_expr  */
#line 373 "a.y"
                                                    { (yyval.node) = opr('+',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2470 "y.tab.c"
    break;

  case 110: /* arithmetic_stmt: common_number_expr '-' common_number_expr  */
#line 374 "a.y"
                                                    { (yyval.node) = opr('-',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2476 "y.tab.c"
    break;

  case 111: /* arithmetic_stmt: common_number_expr '*' common_number_expr  */
#line 375 "a.y"
                                                    { (yyval.node) = opr('*',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2482 "y.tab.c"
    break;

  case 112: /* arithmetic_stmt: common_number_expr '/' common_number_expr  */
#line 376 "a.y"
                                                    { (yyval.node) = opr('/',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2488 "y.tab.c"
    break;

  case 113: /* arithmetic_stmt: common_number_expr '%' common_number_expr  */
#line 377 "a.y"
                                                    { (yyval.node) = opr('%',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2494 "y.tab.c"
    break;

  case 114: /* arithmetic_stmt: common_number_expr '&' common_number_expr  */
#line 378 "a.y"
                                                     { (yyval.node) = opr('&',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2500 "y.tab.c"
    break;

  case 115: /* arithmetic_stmt: common_number_expr '|' common_number_expr  */
#line 379 "a.y"
                                                     { (yyval.node) = opr('|',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2506 "y.tab.c"
    break;

  case 116: /* arithmetic_stmt: common_number_expr '^' common_number_expr  */
#line 380 "a.y"
                                                     { (yyval.node) = opr('^',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2512 "y.tab.c"
    break;

  case 117: /* arithmetic_stmt: common_number_expr LEFT_SHIFT common_number_expr  */
#line 381 "a.y"
                                                            { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2518 "y.tab.c"
    break;

  case 118: /* arithmetic_stmt: common_number_expr RIGHT_SHIFT common_number_expr  */
#line 382 "a.y"
                                                             { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2524 "y.tab.c"
    break;

  case 119: /* arithmetic_stmt: '~' common_number_expr  */
#line 383 "a.y"
                            { (yyval.node) = opr('~',1,(yyvsp[0].node)); }
#line 2530 "y.tab.c"
    break;

  case 120: /* new_expr: KEY_NEW id_expr args_list_with_parentheses  */
#line 388 "a.y"
                                                     { (yyval.node) = NULL; }
#line 2536 "y.tab.c"
    break;

  case 121: /* args_list_with_parentheses: '(' ')'  */
#line 392 "a.y"
                  { (yyval.node) = NULL; }
#line 2542 "y.tab.c"
    break;

  case 122: /* args_list_with_parentheses: '(' args_list ')'  */
#line 393 "a.y"
                        { (yyval.node) = NULL; }
#line 2548 "y.tab.c"
    break;

  case 123: /* args_list: common_expr  */
#line 397 "a.y"
                    { (yyval.args) = NULL; }
#line 2554 "y.tab.c"
    break;

  case 124: /* args_list: args_list ',' common_expr  */
#line 398 "a.y"
                               { (yyval.args) = NULL; }
#line 2560 "y.tab.c"
    break;

  case 125: /* delete_expr: KEY_DELETE multiple_id_expr  */
#line 402 "a.y"
                                  { (yyval.node) = NULL; }
#line 2566 "y.tab.c"
    break;

  case 126: /* logic_stmt: bool_param_expr  */
#line 408 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2572 "y.tab.c"
    break;

  case 127: /* logic_stmt: not_bool_param_expr  */
#line 409 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2578 "y.tab.c"
    break;

  case 128: /* logic_stmt: type_judge_stmt  */
#line 410 "a.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 2584 "y.tab.c"
    break;

  case 129: /* logic_stmt: compare_expr  */
#line 411 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2590 "y.tab.c"
    break;

  case 130: /* logic_stmt: logic_stmt _symbol_logic_connection logic_stmt  */
#line 412 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2596 "y.tab.c"
    break;

  case 133: /* bool_param_expr: assign_stmt_value_eq  */
#line 422 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2602 "y.tab.c"
    break;

  case 134: /* bool_param_expr: bool_expr  */
#line 423 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2608 "y.tab.c"
    break;

  case 135: /* type_judge_stmt: common_object_expr KEY_IS id_expr  */
#line 428 "a.y"
                                             { (yyval.node) = opr(KEY_IS ,2 , (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2614 "y.tab.c"
    break;

  case 136: /* not_bool_param_expr: '!' bool_param_expr  */
#line 432 "a.y"
                          { (yyval.node) = NULL; }
#line 2620 "y.tab.c"
    break;

  case 137: /* compare_expr: number_compare_expr  */
#line 437 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2626 "y.tab.c"
    break;

  case 138: /* compare_expr: object_compare_expr  */
#line 438 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2632 "y.tab.c"
    break;

  case 139: /* number_compare_expr: common_number_expr _symbol_compare common_number_expr  */
#line 442 "a.y"
                                                          { (yyval.node) = NULL; }
#line 2638 "y.tab.c"
    break;

  case 140: /* object_compare_expr: common_object_expr _symbol_equals_not common_types_expr  */
#line 446 "a.y"
                                                             { (yyval.node) = NULL; }
#line 2644 "y.tab.c"
    break;

  case 141: /* _symbol_compare: '>'  */
#line 450 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2650 "y.tab.c"
    break;

  case 142: /* _symbol_compare: '<'  */
#line 451 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2656 "y.tab.c"
    break;

  case 143: /* _symbol_compare: GE_OP  */
#line 452 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2662 "y.tab.c"
    break;

  case 144: /* _symbol_compare: LE_OP  */
#line 453 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2668 "y.tab.c"
    break;

  case 145: /* _symbol_compare: NE_OP  */
#line 454 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2674 "y.tab.c"
    break;

  case 146: /* _symbol_compare: EQ_OP  */
#line 455 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2680 "y.tab.c"
    break;

  case 147: /* _symbol_equals_not: NE_OP  */
#line 459 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2686 "y.tab.c"
    break;

  case 148: /* _symbol_equals_not: EQ_OP  */
#line 460 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2692 "y.tab.c"
    break;

  case 149: /* self_inc_dec_stmt: self_inc_dec_operators common_values_expr  */
#line 465 "a.y"
                                                    { (yyval.node) = opr((yyvsp[-1].iValue),1, (yyvsp[0].node) ); }
#line 2698 "y.tab.c"
    break;

  case 150: /* self_inc_dec_stmt: common_values_expr self_inc_dec_operators  */
#line 466 "a.y"
                                                                       { (yyval.node) = NULL; }
#line 2704 "y.tab.c"
    break;

  case 151: /* self_inc_dec_operators: INC_OP  */
#line 470 "a.y"
                  { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2710 "y.tab.c"
    break;

  case 152: /* self_inc_dec_operators: DEC_OP  */
#line 471 "a.y"
                  { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2716 "y.tab.c"
    break;

  case 153: /* assign_stmt_value_eq: number_expr  */
#line 477 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2722 "y.tab.c"
    break;

  case 154: /* assign_stmt_value_eq: common_values_expr  */
#line 478 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2728 "y.tab.c"
    break;

  case 155: /* assign_stmt_value_eq: common_result_of_call_expr  */
#line 479 "a.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2734 "y.tab.c"
    break;

  case 156: /* array_ele_stmt: common_object_expr '[' common_number_expr ']'  */
#line 487 "a.y"
                                                         { (yyval.node) = NULL; }
#line 2740 "y.tab.c"
    break;

  case 157: /* assign_stmt: single_assign_stmt  */
#line 492 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2746 "y.tab.c"
    break;

  case 158: /* assign_stmt: number_change_assign_stmt  */
#line 493 "a.y"
                                    { (yyval.node) = (yyvsp[0].node) ;}
#line 2752 "y.tab.c"
    break;

  case 159: /* single_assign_stmt: common_assignable_expr '=' single_assign_stmt_value  */
#line 497 "a.y"
                                                              { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 2758 "y.tab.c"
    break;

  case 160: /* single_assign_stmt_value: common_expr  */
#line 501 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2764 "y.tab.c"
    break;

  case 161: /* single_assign_stmt_value: single_assign_stmt  */
#line 502 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2770 "y.tab.c"
    break;

  case 162: /* number_change_assign_stmt: common_assignable_expr symbol_change_assign common_number_expr  */
#line 506 "a.y"
                                                                    { (yyval.node) = NULL; }
#line 2776 "y.tab.c"
    break;

  case 163: /* symbol_change_assign: ADD_EQ  */
#line 510 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2782 "y.tab.c"
    break;

  case 164: /* symbol_change_assign: SUB_EQ  */
#line 511 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2788 "y.tab.c"
    break;

  case 165: /* symbol_change_assign: MUL_EQ  */
#line 512 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2794 "y.tab.c"
    break;

  case 166: /* symbol_change_assign: DIV_EQ  */
#line 513 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2800 "y.tab.c"
    break;

  case 167: /* symbol_change_assign: MOD_EQ  */
#line 514 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2806 "y.tab.c"
    break;

  case 168: /* code_block: '{' '}'  */
#line 519 "a.y"
                    { (yyval.node) = NULL; }
#line 2812 "y.tab.c"
    break;

  case 169: /* code_block: '{' block_item_list '}'  */
#line 520 "a.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2818 "y.tab.c"
    break;

  case 170: /* block_item_list: block_item  */
#line 524 "a.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2824 "y.tab.c"
    break;

  case 171: /* block_item_list: block_item_list block_item  */
#line 525 "a.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2830 "y.tab.c"
    break;

  case 172: /* block_item: try_stmt  */
#line 529 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2836 "y.tab.c"
    break;

  case 173: /* block_item: simple_stmt  */
#line 530 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2842 "y.tab.c"
    break;

  case 174: /* block_item: con_ctl_stmt  */
#line 531 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2848 "y.tab.c"
    break;

  case 175: /* block_item: _extra_nothing  */
#line 532 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2854 "y.tab.c"
    break;

  case 176: /* string_plus_stmt: string_expr '+' string_plus_stmt_value  */
#line 537 "a.y"
                                              { (yyval.node) = NULL; }
#line 2860 "y.tab.c"
    break;

  case 177: /* string_plus_stmt: string_plus_stmt_value '+' string_expr  */
#line 538 "a.y"
                                              { (yyval.node) = NULL; }
#line 2866 "y.tab.c"
    break;

  case 178: /* string_plus_stmt_value: common_object_expr  */
#line 542 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2872 "y.tab.c"
    break;

  case 179: /* string_plus_stmt_value: common_types_expr  */
#line 543 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2878 "y.tab.c"
    break;

  case 180: /* string_plus_stmt_value: string_plus_stmt  */
#line 544 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2884 "y.tab.c"
    break;

  case 181: /* string_plus_stmt_value: self_inc_dec_stmt  */
#line 545 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2890 "y.tab.c"
    break;

  case 182: /* string_plus_stmt_value: number_parentheses_stmt  */
#line 546 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2896 "y.tab.c"
    break;

  case 183: /* number_parentheses_stmt: '(' common_number_expr ')'  */
#line 550 "a.y"
                                   { (yyval.node) = NULL; }
#line 2902 "y.tab.c"
    break;

  case 184: /* id_expr: IDENTIFIER  */
#line 556 "a.y"
                     { (yyval.node) = var((yyvsp[0].sValue)); }
#line 2908 "y.tab.c"
    break;

  case 185: /* multiple_id_expr: id_expr  */
#line 560 "a.y"
                    { (yyval.node) = (yyvsp[0].node);}
#line 2914 "y.tab.c"
    break;

  case 186: /* multiple_id_expr: multiple_id_expr ',' id_expr  */
#line 561 "a.y"
                                   { (yyval.node) = NULL; }
#line 2920 "y.tab.c"
    break;

  case 187: /* bool_expr: TBOOL  */
#line 565 "a.y"
                  { (yyval.node) = number((yyvsp[0].iValue)); }
#line 2926 "y.tab.c"
    break;

  case 188: /* number_expr: positive_number_expr  */
#line 569 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2932 "y.tab.c"
    break;

  case 189: /* number_expr: uminus_expr  */
#line 570 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2938 "y.tab.c"
    break;

  case 190: /* positive_number_expr: double_expr  */
#line 574 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2944 "y.tab.c"
    break;

  case 191: /* positive_number_expr: int_expr  */
#line 575 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2950 "y.tab.c"
    break;

  case 192: /* int_expr: TINTEGER  */
#line 579 "a.y"
             { (yyval.node) = number((yyvsp[0].iValue)); }
#line 2956 "y.tab.c"
    break;

  case 193: /* double_expr: TDOUBLE  */
#line 583 "a.y"
                  { (yyval.node) = number((yyvsp[0].dValue)); }
#line 2962 "y.tab.c"
    break;

  case 194: /* uminus_expr: '-' uminus_expr_values  */
#line 587 "a.y"
                                              { (yyval.node) = opr(UMINUS, 1, (yyvsp[0].node) ); }
#line 2968 "y.tab.c"
    break;

  case 195: /* uminus_expr_values: positive_number_expr  */
#line 591 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2974 "y.tab.c"
    break;

  case 196: /* uminus_expr_values: common_others_values_expr  */
#line 592 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2980 "y.tab.c"
    break;

  case 197: /* uminus_expr_values: call_statement  */
#line 593 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2986 "y.tab.c"
    break;

  case 198: /* uminus_expr_values: number_parentheses_stmt  */
#line 594 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2992 "y.tab.c"
    break;

  case 199: /* string_expr: TSTRING  */
#line 598 "a.y"
                   { (yyval.node) = string((yyvsp[0].sValue)); }
#line 2998 "y.tab.c"
    break;

  case 200: /* null_expr: KEY_NULL  */
#line 602 "a.y"
                     { (yyval.node) = xnull(); }
#line 3004 "y.tab.c"
    break;

  case 201: /* common_types_expr: number_expr  */
#line 609 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3010 "y.tab.c"
    break;

  case 202: /* common_types_expr: string_expr  */
#line 610 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3016 "y.tab.c"
    break;

  case 203: /* common_types_expr: null_expr  */
#line 611 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3022 "y.tab.c"
    break;

  case 204: /* common_types_expr: lambda_stmt  */
#line 612 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3028 "y.tab.c"
    break;

  case 205: /* common_types_expr: bool_expr  */
#line 613 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3034 "y.tab.c"
    break;

  case 206: /* common_others_values_expr: id_expr  */
#line 617 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3040 "y.tab.c"
    break;

  case 207: /* common_others_values_expr: array_ele_stmt  */
#line 618 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3046 "y.tab.c"
    break;

  case 208: /* common_others_values_expr: class_member_stmt  */
#line 619 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3052 "y.tab.c"
    break;

  case 209: /* common_others_values_expr: static_member_stmt  */
#line 620 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 3058 "y.tab.c"
    break;

  case 210: /* common_values_expr: common_others_values_expr  */
#line 624 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3064 "y.tab.c"
    break;

  case 211: /* common_values_expr: this_stmt  */
#line 625 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3070 "y.tab.c"
    break;

  case 212: /* common_values_expr: new_expr  */
#line 626 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3076 "y.tab.c"
    break;

  case 213: /* common_result_of_call_expr: self_inc_dec_stmt  */
#line 630 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3082 "y.tab.c"
    break;

  case 214: /* common_result_of_call_expr: call_statement  */
#line 631 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3088 "y.tab.c"
    break;

  case 215: /* common_result_of_call_expr: arithmetic_stmt  */
#line 632 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3094 "y.tab.c"
    break;

  case 216: /* common_result_of_call_expr: number_parentheses_stmt  */
#line 633 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3100 "y.tab.c"
    break;

  case 217: /* common_assignable_expr: common_others_values_expr  */
#line 637 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3106 "y.tab.c"
    break;

  case 218: /* common_number_expr: number_expr  */
#line 641 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3112 "y.tab.c"
    break;

  case 219: /* common_number_expr: common_values_expr  */
#line 642 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3118 "y.tab.c"
    break;

  case 220: /* common_number_expr: common_result_of_call_expr  */
#line 643 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3124 "y.tab.c"
    break;

  case 221: /* common_object_expr: common_values_expr  */
#line 647 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3130 "y.tab.c"
    break;

  case 222: /* common_object_expr: call_statement  */
#line 648 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3136 "y.tab.c"
    break;

  case 223: /* common_expr: common_types_expr  */
#line 657 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3142 "y.tab.c"
    break;

  case 224: /* common_expr: common_values_expr  */
#line 658 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3148 "y.tab.c"
    break;

  case 225: /* common_expr: common_result_of_call_expr  */
#line 659 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3154 "y.tab.c"
    break;

  case 226: /* common_expr: string_plus_stmt  */
#line 660 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3160 "y.tab.c"
    break;


#line 3164 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 663 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
