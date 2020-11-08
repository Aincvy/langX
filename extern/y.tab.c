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


#include <string.h>
#include "../include/NodeCreator.h"
#include "../include/Program.h"


#line 79 "y.tab.c"

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
    FUNC_OP = 265,                 /* FUNC_OP  */
    FUNC_CALL = 266,               /* FUNC_CALL  */
    VAR_DECLAR = 267,              /* VAR_DECLAR  */
    ARRAY_ELE = 268,               /* ARRAY_ELE  */
    KEY_TRY = 269,                 /* KEY_TRY  */
    KEY_PUBLIC = 270,              /* KEY_PUBLIC  */
    KEY_SET = 271,                 /* KEY_SET  */
    KEY_IS = 272,                  /* KEY_IS  */
    KEY_REF = 273,                 /* KEY_REF  */
    KEY_CONTINUE = 274,            /* KEY_CONTINUE  */
    KEY_NEW = 275,                 /* KEY_NEW  */
    KEY_CATCH = 276,               /* KEY_CATCH  */
    KEY_THIS = 277,                /* KEY_THIS  */
    KEY_EXTENDS = 278,             /* KEY_EXTENDS  */
    KEY_RESTRICT = 279,            /* KEY_RESTRICT  */
    KEY_IF = 280,                  /* KEY_IF  */
    KEY_ELSE = 281,                /* KEY_ELSE  */
    KEY_WHILE = 282,               /* KEY_WHILE  */
    KEY_FOR = 283,                 /* KEY_FOR  */
    KEY_DELETE = 284,              /* KEY_DELETE  */
    KEY_BREAK = 285,               /* KEY_BREAK  */
    KEY_RETURN = 286,              /* KEY_RETURN  */
    KEY_SWITCH = 287,              /* KEY_SWITCH  */
    KEY_CASE = 288,                /* KEY_CASE  */
    KEY_DEFAULT = 289,             /* KEY_DEFAULT  */
    KEY_NULL = 290,                /* KEY_NULL  */
    CASE_LIST = 291,               /* CASE_LIST  */
    CLAXX_BODY = 292,              /* CLAXX_BODY  */
    CLAXX_MEMBER = 293,            /* CLAXX_MEMBER  */
    CLAXX_FUNC_CALL = 294,         /* CLAXX_FUNC_CALL  */
    SCOPE_FUNC_CALL = 295,         /* SCOPE_FUNC_CALL  */
    SCOPE = 296,                   /* SCOPE  */
    LEFT_SHIFT = 297,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 298,             /* RIGHT_SHIFT  */
    OPR_NODE_LIST = 299,           /* OPR_NODE_LIST  */
    OPR_CHANGE_NAME_SPACE = 300,   /* OPR_CHANGE_NAME_SPACE  */
    OPR_CAT_NS_NAME = 301,         /* OPR_CAT_NS_NAME  */
    OPR_CLASS_DECLARE = 302,       /* OPR_CLASS_DECLARE  */
    OPR_INC_DEC = 303,             /* OPR_INC_DEC  */
    OPR_IF_ELSE = 304,             /* OPR_IF_ELSE  */
    OPR_MULTIPLE_ID = 305,         /* OPR_MULTIPLE_ID  */
    KEY_REQUIRE = 306,             /* KEY_REQUIRE  */
    KEY_REQUIRE_ONCE = 307,        /* KEY_REQUIRE_ONCE  */
    KEY_INCLUDE = 308,             /* KEY_INCLUDE  */
    KEY_AUTO = 309,                /* KEY_AUTO  */
    KEY_CONST = 310,               /* KEY_CONST  */
    KEY_LOCAL = 311,               /* KEY_LOCAL  */
    ADD_EQ = 312,                  /* ADD_EQ  */
    SUB_EQ = 313,                  /* SUB_EQ  */
    MUL_EQ = 314,                  /* MUL_EQ  */
    DIV_EQ = 315,                  /* DIV_EQ  */
    MOD_EQ = 316,                  /* MOD_EQ  */
    LE_OP = 317,                   /* LE_OP  */
    GE_OP = 318,                   /* GE_OP  */
    EQ_OP = 319,                   /* EQ_OP  */
    NE_OP = 320,                   /* NE_OP  */
    INC_OP = 321,                  /* INC_OP  */
    DEC_OP = 322,                  /* DEC_OP  */
    AND_OP = 323,                  /* AND_OP  */
    OR_OP = 324,                   /* OR_OP  */
    IFX = 325,                     /* IFX  */
    ELSE = 326,                    /* ELSE  */
    PIPELINE_OP = 327,             /* PIPELINE_OP  */
    INC_OP_BACK = 328,             /* INC_OP_BACK  */
    PRIORITY3 = 329,               /* PRIORITY3  */
    PRIORITY2 = 330,               /* PRIORITY2  */
    PRIORITY1 = 331,               /* PRIORITY1  */
    UMINUS = 332                   /* UMINUS  */
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
#define FUNC_OP 265
#define FUNC_CALL 266
#define VAR_DECLAR 267
#define ARRAY_ELE 268
#define KEY_TRY 269
#define KEY_PUBLIC 270
#define KEY_SET 271
#define KEY_IS 272
#define KEY_REF 273
#define KEY_CONTINUE 274
#define KEY_NEW 275
#define KEY_CATCH 276
#define KEY_THIS 277
#define KEY_EXTENDS 278
#define KEY_RESTRICT 279
#define KEY_IF 280
#define KEY_ELSE 281
#define KEY_WHILE 282
#define KEY_FOR 283
#define KEY_DELETE 284
#define KEY_BREAK 285
#define KEY_RETURN 286
#define KEY_SWITCH 287
#define KEY_CASE 288
#define KEY_DEFAULT 289
#define KEY_NULL 290
#define CASE_LIST 291
#define CLAXX_BODY 292
#define CLAXX_MEMBER 293
#define CLAXX_FUNC_CALL 294
#define SCOPE_FUNC_CALL 295
#define SCOPE 296
#define LEFT_SHIFT 297
#define RIGHT_SHIFT 298
#define OPR_NODE_LIST 299
#define OPR_CHANGE_NAME_SPACE 300
#define OPR_CAT_NS_NAME 301
#define OPR_CLASS_DECLARE 302
#define OPR_INC_DEC 303
#define OPR_IF_ELSE 304
#define OPR_MULTIPLE_ID 305
#define KEY_REQUIRE 306
#define KEY_REQUIRE_ONCE 307
#define KEY_INCLUDE 308
#define KEY_AUTO 309
#define KEY_CONST 310
#define KEY_LOCAL 311
#define ADD_EQ 312
#define SUB_EQ 313
#define MUL_EQ 314
#define DIV_EQ 315
#define MOD_EQ 316
#define LE_OP 317
#define GE_OP 318
#define EQ_OP 319
#define NE_OP 320
#define INC_OP 321
#define DEC_OP 322
#define AND_OP 323
#define OR_OP 324
#define IFX 325
#define ELSE 326
#define PIPELINE_OP 327
#define INC_OP_BACK 328
#define PRIORITY3 329
#define PRIORITY2 330
#define PRIORITY1 331
#define UMINUS 332

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 9 "a.y"

 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */

#line 294 "y.tab.c"

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
  YYSYMBOL_FUNC_OP = 10,                   /* FUNC_OP  */
  YYSYMBOL_FUNC_CALL = 11,                 /* FUNC_CALL  */
  YYSYMBOL_VAR_DECLAR = 12,                /* VAR_DECLAR  */
  YYSYMBOL_ARRAY_ELE = 13,                 /* ARRAY_ELE  */
  YYSYMBOL_KEY_TRY = 14,                   /* KEY_TRY  */
  YYSYMBOL_KEY_PUBLIC = 15,                /* KEY_PUBLIC  */
  YYSYMBOL_KEY_SET = 16,                   /* KEY_SET  */
  YYSYMBOL_KEY_IS = 17,                    /* KEY_IS  */
  YYSYMBOL_KEY_REF = 18,                   /* KEY_REF  */
  YYSYMBOL_KEY_CONTINUE = 19,              /* KEY_CONTINUE  */
  YYSYMBOL_KEY_NEW = 20,                   /* KEY_NEW  */
  YYSYMBOL_KEY_CATCH = 21,                 /* KEY_CATCH  */
  YYSYMBOL_KEY_THIS = 22,                  /* KEY_THIS  */
  YYSYMBOL_KEY_EXTENDS = 23,               /* KEY_EXTENDS  */
  YYSYMBOL_KEY_RESTRICT = 24,              /* KEY_RESTRICT  */
  YYSYMBOL_KEY_IF = 25,                    /* KEY_IF  */
  YYSYMBOL_KEY_ELSE = 26,                  /* KEY_ELSE  */
  YYSYMBOL_KEY_WHILE = 27,                 /* KEY_WHILE  */
  YYSYMBOL_KEY_FOR = 28,                   /* KEY_FOR  */
  YYSYMBOL_KEY_DELETE = 29,                /* KEY_DELETE  */
  YYSYMBOL_KEY_BREAK = 30,                 /* KEY_BREAK  */
  YYSYMBOL_KEY_RETURN = 31,                /* KEY_RETURN  */
  YYSYMBOL_KEY_SWITCH = 32,                /* KEY_SWITCH  */
  YYSYMBOL_KEY_CASE = 33,                  /* KEY_CASE  */
  YYSYMBOL_KEY_DEFAULT = 34,               /* KEY_DEFAULT  */
  YYSYMBOL_KEY_NULL = 35,                  /* KEY_NULL  */
  YYSYMBOL_CASE_LIST = 36,                 /* CASE_LIST  */
  YYSYMBOL_CLAXX_BODY = 37,                /* CLAXX_BODY  */
  YYSYMBOL_CLAXX_MEMBER = 38,              /* CLAXX_MEMBER  */
  YYSYMBOL_CLAXX_FUNC_CALL = 39,           /* CLAXX_FUNC_CALL  */
  YYSYMBOL_SCOPE_FUNC_CALL = 40,           /* SCOPE_FUNC_CALL  */
  YYSYMBOL_SCOPE = 41,                     /* SCOPE  */
  YYSYMBOL_LEFT_SHIFT = 42,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 43,               /* RIGHT_SHIFT  */
  YYSYMBOL_OPR_NODE_LIST = 44,             /* OPR_NODE_LIST  */
  YYSYMBOL_OPR_CHANGE_NAME_SPACE = 45,     /* OPR_CHANGE_NAME_SPACE  */
  YYSYMBOL_OPR_CAT_NS_NAME = 46,           /* OPR_CAT_NS_NAME  */
  YYSYMBOL_OPR_CLASS_DECLARE = 47,         /* OPR_CLASS_DECLARE  */
  YYSYMBOL_OPR_INC_DEC = 48,               /* OPR_INC_DEC  */
  YYSYMBOL_OPR_IF_ELSE = 49,               /* OPR_IF_ELSE  */
  YYSYMBOL_OPR_MULTIPLE_ID = 50,           /* OPR_MULTIPLE_ID  */
  YYSYMBOL_KEY_REQUIRE = 51,               /* KEY_REQUIRE  */
  YYSYMBOL_KEY_REQUIRE_ONCE = 52,          /* KEY_REQUIRE_ONCE  */
  YYSYMBOL_KEY_INCLUDE = 53,               /* KEY_INCLUDE  */
  YYSYMBOL_KEY_AUTO = 54,                  /* KEY_AUTO  */
  YYSYMBOL_KEY_CONST = 55,                 /* KEY_CONST  */
  YYSYMBOL_KEY_LOCAL = 56,                 /* KEY_LOCAL  */
  YYSYMBOL_ADD_EQ = 57,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 58,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 59,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 60,                    /* DIV_EQ  */
  YYSYMBOL_MOD_EQ = 61,                    /* MOD_EQ  */
  YYSYMBOL_LE_OP = 62,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 63,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 64,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 65,                     /* NE_OP  */
  YYSYMBOL_66_ = 66,                       /* '>'  */
  YYSYMBOL_67_ = 67,                       /* '<'  */
  YYSYMBOL_INC_OP = 68,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 69,                    /* DEC_OP  */
  YYSYMBOL_AND_OP = 70,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 71,                     /* OR_OP  */
  YYSYMBOL_IFX = 72,                       /* IFX  */
  YYSYMBOL_ELSE = 73,                      /* ELSE  */
  YYSYMBOL_74_ = 74,                       /* ','  */
  YYSYMBOL_PIPELINE_OP = 75,               /* PIPELINE_OP  */
  YYSYMBOL_76_ = 76,                       /* '='  */
  YYSYMBOL_77_ = 77,                       /* '|'  */
  YYSYMBOL_78_ = 78,                       /* '^'  */
  YYSYMBOL_79_ = 79,                       /* '&'  */
  YYSYMBOL_80_ = 80,                       /* '+'  */
  YYSYMBOL_81_ = 81,                       /* '-'  */
  YYSYMBOL_82_ = 82,                       /* '*'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_84_ = 84,                       /* '%'  */
  YYSYMBOL_85_ = 85,                       /* '!'  */
  YYSYMBOL_86_ = 86,                       /* '~'  */
  YYSYMBOL_INC_OP_BACK = 87,               /* INC_OP_BACK  */
  YYSYMBOL_88_ = 88,                       /* '('  */
  YYSYMBOL_89_ = 89,                       /* ')'  */
  YYSYMBOL_90_ = 90,                       /* '['  */
  YYSYMBOL_91_ = 91,                       /* ']'  */
  YYSYMBOL_92_ = 92,                       /* '.'  */
  YYSYMBOL_PRIORITY3 = 93,                 /* PRIORITY3  */
  YYSYMBOL_PRIORITY2 = 94,                 /* PRIORITY2  */
  YYSYMBOL_PRIORITY1 = 95,                 /* PRIORITY1  */
  YYSYMBOL_UMINUS = 96,                    /* UMINUS  */
  YYSYMBOL_97_ = 97,                       /* ';'  */
  YYSYMBOL_98_ = 98,                       /* '{'  */
  YYSYMBOL_99_ = 99,                       /* '}'  */
  YYSYMBOL_100_ = 100,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 101,                 /* $accept  */
  YYSYMBOL_program = 102,                  /* program  */
  YYSYMBOL_statement_list = 103,           /* statement_list  */
  YYSYMBOL_statement = 104,                /* statement  */
  YYSYMBOL__extra_nothing = 105,           /* _extra_nothing  */
  YYSYMBOL_out_declare_stmt = 106,         /* out_declare_stmt  */
  YYSYMBOL_require_stmt = 107,             /* require_stmt  */
  YYSYMBOL_require_operators = 108,        /* require_operators  */
  YYSYMBOL_try_stmt = 109,                 /* try_stmt  */
  YYSYMBOL_catch_block_stmt = 110,         /* catch_block_stmt  */
  YYSYMBOL_namespace_declare_stmt = 111,   /* namespace_declare_stmt  */
  YYSYMBOL_namespace_ref_stmt = 112,       /* namespace_ref_stmt  */
  YYSYMBOL_namespace_name_stmt = 113,      /* namespace_name_stmt  */
  YYSYMBOL_class_declare_stmt = 114,       /* class_declare_stmt  */
  YYSYMBOL_class_name_prefix = 115,        /* class_name_prefix  */
  YYSYMBOL_class_name_suffix = 116,        /* class_name_suffix  */
  YYSYMBOL_class_body = 117,               /* class_body  */
  YYSYMBOL_class_body_items = 118,         /* class_body_items  */
  YYSYMBOL_class_body_item = 119,          /* class_body_item  */
  YYSYMBOL_this_stmt = 120,                /* this_stmt  */
  YYSYMBOL_class_member_stmt = 121,        /* class_member_stmt  */
  YYSYMBOL_static_member_stmt = 122,       /* static_member_stmt  */
  YYSYMBOL_func_declare_stmt = 123,        /* func_declare_stmt  */
  YYSYMBOL_func_name_types = 124,          /* func_name_types  */
  YYSYMBOL_func_param_list = 125,          /* func_param_list  */
  YYSYMBOL_lambda_stmt = 126,              /* lambda_stmt  */
  YYSYMBOL_lambda_args_stmt = 127,         /* lambda_args_stmt  */
  YYSYMBOL_var_declare_stmt = 128,         /* var_declare_stmt  */
  YYSYMBOL_var_prefix = 129,               /* var_prefix  */
  YYSYMBOL__elements_var_declare_stmt = 130, /* _elements_var_declare_stmt  */
  YYSYMBOL_element_var_declare_stmt = 131, /* element_var_declare_stmt  */
  YYSYMBOL_con_ctl_stmt = 132,             /* con_ctl_stmt  */
  YYSYMBOL_selection_stmt = 133,           /* selection_stmt  */
  YYSYMBOL_if_stmt = 134,                  /* if_stmt  */
  YYSYMBOL_single_if_stmt = 135,           /* single_if_stmt  */
  YYSYMBOL_else_stmt = 136,                /* else_stmt  */
  YYSYMBOL_else_if_stmts = 137,            /* else_if_stmts  */
  YYSYMBOL_else_if_stmt = 138,             /* else_if_stmt  */
  YYSYMBOL_single_else_stmt = 139,         /* single_else_stmt  */
  YYSYMBOL_case_stmt_list = 140,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 141,                /* case_stmt  */
  YYSYMBOL_loop_stmt = 142,                /* loop_stmt  */
  YYSYMBOL_for_logic_stmt = 143,           /* for_logic_stmt  */
  YYSYMBOL_for_1_stmt_list = 144,          /* for_1_stmt_list  */
  YYSYMBOL_for_1_stmt = 145,               /* for_1_stmt  */
  YYSYMBOL_for_3_stmt_list = 146,          /* for_3_stmt_list  */
  YYSYMBOL_for_3_stmt = 147,               /* for_3_stmt  */
  YYSYMBOL_simple_stmt = 148,              /* simple_stmt  */
  YYSYMBOL_simple_stmt_types = 149,        /* simple_stmt_types  */
  YYSYMBOL_restrict_stmt = 150,            /* restrict_stmt  */
  YYSYMBOL_interrupt_stmt = 151,           /* interrupt_stmt  */
  YYSYMBOL_call_statement = 152,           /* call_statement  */
  YYSYMBOL_arithmetic_stmt = 153,          /* arithmetic_stmt  */
  YYSYMBOL_new_expr = 154,                 /* new_expr  */
  YYSYMBOL_args_list_with_parentheses = 155, /* args_list_with_parentheses  */
  YYSYMBOL_args_list = 156,                /* args_list  */
  YYSYMBOL_delete_expr = 157,              /* delete_expr  */
  YYSYMBOL_logic_stmt = 158,               /* logic_stmt  */
  YYSYMBOL__symbol_logic_connection = 159, /* _symbol_logic_connection  */
  YYSYMBOL_bool_param_expr = 160,          /* bool_param_expr  */
  YYSYMBOL_type_judge_stmt = 161,          /* type_judge_stmt  */
  YYSYMBOL_not_bool_param_expr = 162,      /* not_bool_param_expr  */
  YYSYMBOL_compare_expr = 163,             /* compare_expr  */
  YYSYMBOL_number_compare_expr = 164,      /* number_compare_expr  */
  YYSYMBOL_object_compare_expr = 165,      /* object_compare_expr  */
  YYSYMBOL__symbol_compare = 166,          /* _symbol_compare  */
  YYSYMBOL__symbol_equals_not = 167,       /* _symbol_equals_not  */
  YYSYMBOL_self_inc_dec_stmt = 168,        /* self_inc_dec_stmt  */
  YYSYMBOL_self_inc_dec_operators = 169,   /* self_inc_dec_operators  */
  YYSYMBOL_assign_stmt_value_eq = 170,     /* assign_stmt_value_eq  */
  YYSYMBOL_array_ele_stmt = 171,           /* array_ele_stmt  */
  YYSYMBOL_assign_stmt = 172,              /* assign_stmt  */
  YYSYMBOL_single_assign_stmt = 173,       /* single_assign_stmt  */
  YYSYMBOL_single_assign_stmt_value = 174, /* single_assign_stmt_value  */
  YYSYMBOL_number_change_assign_stmt = 175, /* number_change_assign_stmt  */
  YYSYMBOL_symbol_change_assign = 176,     /* symbol_change_assign  */
  YYSYMBOL_code_block = 177,               /* code_block  */
  YYSYMBOL_block_item_list = 178,          /* block_item_list  */
  YYSYMBOL_block_item = 179,               /* block_item  */
  YYSYMBOL_string_plus_stmt = 180,         /* string_plus_stmt  */
  YYSYMBOL_string_plus_stmt_value = 181,   /* string_plus_stmt_value  */
  YYSYMBOL_number_parentheses_stmt = 182,  /* number_parentheses_stmt  */
  YYSYMBOL_id_expr = 183,                  /* id_expr  */
  YYSYMBOL_multiple_id_expr = 184,         /* multiple_id_expr  */
  YYSYMBOL_bool_expr = 185,                /* bool_expr  */
  YYSYMBOL_number_expr = 186,              /* number_expr  */
  YYSYMBOL_positive_number_expr = 187,     /* positive_number_expr  */
  YYSYMBOL_int_expr = 188,                 /* int_expr  */
  YYSYMBOL_double_expr = 189,              /* double_expr  */
  YYSYMBOL_uminus_expr = 190,              /* uminus_expr  */
  YYSYMBOL_uminus_expr_values = 191,       /* uminus_expr_values  */
  YYSYMBOL_string_expr = 192,              /* string_expr  */
  YYSYMBOL_null_expr = 193,                /* null_expr  */
  YYSYMBOL_common_types_expr = 194,        /* common_types_expr  */
  YYSYMBOL_common_others_values_expr = 195, /* common_others_values_expr  */
  YYSYMBOL_common_values_expr = 196,       /* common_values_expr  */
  YYSYMBOL_common_result_of_call_expr = 197, /* common_result_of_call_expr  */
  YYSYMBOL_common_assignable_expr = 198,   /* common_assignable_expr  */
  YYSYMBOL_common_number_expr = 199,       /* common_number_expr  */
  YYSYMBOL_common_object_expr = 200,       /* common_object_expr  */
  YYSYMBOL_common_expr = 201               /* common_expr  */
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
#define YYLAST   812

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  341

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
       2,     2,     2,    85,     2,     2,     2,    84,    79,     2,
      88,    89,    82,    80,    74,    81,    92,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   100,    97,
      67,    76,    66,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    90,     2,    91,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    98,    77,    99,    86,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    68,    69,    70,    71,    72,    73,    75,    87,    93,
      94,    95,    96
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    85,    86,    89,    90,    91,    92,    93,
      97,   101,   102,   103,   104,   109,   113,   114,   115,   120,
     121,   125,   131,   136,   140,   141,   151,   155,   156,   161,
     162,   166,   167,   171,   172,   176,   177,   178,   179,   184,
     190,   195,   205,   206,   210,   211,   212,   216,   217,   222,
     226,   227,   228,   233,   234,   238,   239,   243,   244,   248,
     249,   254,   255,   260,   261,   265,   266,   270,   274,   275,
     279,   280,   284,   288,   292,   293,   297,   298,   302,   303,
     307,   308,   312,   313,   314,   319,   325,   326,   327,   332,
     333,   338,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   355,   356,   360,   361,   362,   363,   368,   369,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     389,   393,   394,   398,   399,   403,   409,   410,   411,   412,
     413,   417,   418,   423,   424,   429,   433,   438,   439,   443,
     447,   451,   452,   453,   454,   455,   456,   460,   461,   466,
     467,   471,   472,   478,   479,   480,   488,   493,   494,   498,
     502,   503,   507,   511,   512,   513,   514,   515,   520,   521,
     525,   526,   530,   531,   532,   533,   538,   539,   543,   544,
     545,   546,   547,   551,   557,   561,   562,   566,   570,   571,
     575,   576,   580,   584,   588,   592,   593,   594,   595,   599,
     603,   610,   611,   612,   613,   614,   618,   619,   620,   621,
     625,   626,   627,   631,   632,   633,   634,   638,   642,   643,
     644,   648,   649,   658,   659,   660,   661
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
  "TDOUBLE", "IDENTIFIER", "TSTRING", "OPERATOR_X__", "OP_CALC", "FUNC_OP",
  "FUNC_CALL", "VAR_DECLAR", "ARRAY_ELE", "KEY_TRY", "KEY_PUBLIC",
  "KEY_SET", "KEY_IS", "KEY_REF", "KEY_CONTINUE", "KEY_NEW", "KEY_CATCH",
  "KEY_THIS", "KEY_EXTENDS", "KEY_RESTRICT", "KEY_IF", "KEY_ELSE",
  "KEY_WHILE", "KEY_FOR", "KEY_DELETE", "KEY_BREAK", "KEY_RETURN",
  "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT", "KEY_NULL", "CASE_LIST",
  "CLAXX_BODY", "CLAXX_MEMBER", "CLAXX_FUNC_CALL", "SCOPE_FUNC_CALL",
  "SCOPE", "LEFT_SHIFT", "RIGHT_SHIFT", "OPR_NODE_LIST",
  "OPR_CHANGE_NAME_SPACE", "OPR_CAT_NS_NAME", "OPR_CLASS_DECLARE",
  "OPR_INC_DEC", "OPR_IF_ELSE", "OPR_MULTIPLE_ID", "KEY_REQUIRE",
  "KEY_REQUIRE_ONCE", "KEY_INCLUDE", "KEY_AUTO", "KEY_CONST", "KEY_LOCAL",
  "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "'>'", "'<'", "INC_OP", "DEC_OP", "AND_OP", "OR_OP",
  "IFX", "ELSE", "','", "PIPELINE_OP", "'='", "'|'", "'^'", "'&'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "INC_OP_BACK", "'('", "')'",
  "'['", "']'", "'.'", "PRIORITY3", "PRIORITY2", "PRIORITY1", "UMINUS",
  "';'", "'{'", "'}'", "':'", "$accept", "program", "statement_list",
  "statement", "_extra_nothing", "out_declare_stmt", "require_stmt",
  "require_operators", "try_stmt", "catch_block_stmt",
  "namespace_declare_stmt", "namespace_ref_stmt", "namespace_name_stmt",
  "class_declare_stmt", "class_name_prefix", "class_name_suffix",
  "class_body", "class_body_items", "class_body_item", "this_stmt",
  "class_member_stmt", "static_member_stmt", "func_declare_stmt",
  "func_name_types", "func_param_list", "lambda_stmt", "lambda_args_stmt",
  "var_declare_stmt", "var_prefix", "_elements_var_declare_stmt",
  "element_var_declare_stmt", "con_ctl_stmt", "selection_stmt", "if_stmt",
  "single_if_stmt", "else_stmt", "else_if_stmts", "else_if_stmt",
  "single_else_stmt", "case_stmt_list", "case_stmt", "loop_stmt",
  "for_logic_stmt", "for_1_stmt_list", "for_1_stmt", "for_3_stmt_list",
  "for_3_stmt", "simple_stmt", "simple_stmt_types", "restrict_stmt",
  "interrupt_stmt", "call_statement", "arithmetic_stmt", "new_expr",
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
     315,   316,   317,   318,   319,   320,    62,    60,   321,   322,
     323,   324,   325,   326,    44,   327,    61,   124,    94,    38,
      43,    45,    42,    47,    37,    33,   126,   328,    40,    41,
      91,    93,    46,   329,   330,   331,   332,    59,   123,   125,
      58
};
#endif

#define YYPACT_NINF (-255)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-226)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -255,     8,   520,  -255,  -255,  -255,   -72,    49,    26,  -255,
      26,  -255,    36,   -20,    11,    14,    26,  -255,   587,    35,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,    26,  -255,
    -255,  -255,  -255,  -255,    67,  -255,  -255,  -255,  -255,    26,
    -255,  -255,  -255,  -255,   100,  -255,    26,    77,  -255,  -255,
    -255,  -255,   107,  -255,  -255,    60,  -255,  -255,    25,    63,
    -255,  -255,   121,  -255,  -255,  -255,  -255,    17,   373,   156,
     429,   180,   372,   147,    98,    89,  -255,   103,  -255,  -255,
     593,   593,   121,  -255,   124,  -255,  -255,  -255,  -255,    28,
     688,   557,  -255,   195,     6,  -255,  -255,   131,   136,   140,
     150,    51,   124,  -255,   -50,  -255,  -255,  -255,  -255,   167,
    -255,   171,  -255,   513,    31,   328,   180,  -255,   688,  -255,
    -255,   238,   -42,    77,   176,    26,    -4,  -255,   107,  -255,
    -255,  -255,    26,   177,   234,    92,    26,   688,   497,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,   587,   688,   688,    26,
    -255,  -255,  -255,  -255,  -255,   423,  -255,   -21,   189,  -255,
      26,    26,  -255,   666,   688,    59,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,    42,   254,   143,   700,
     105,   152,   -38,  -255,  -255,   103,    26,    25,  -255,  -255,
    -255,   127,  -255,   292,  -255,  -255,  -255,   -37,   622,   -72,
      67,   628,   688,   688,   688,   688,   688,   688,   688,   688,
     688,   688,   640,    26,   182,    19,   -72,  -255,  -255,  -255,
    -255,  -255,  -255,   103,  -255,   285,  -255,    32,  -255,  -255,
    -255,   214,  -255,   328,   430,  -255,  -255,  -255,    26,    89,
    -255,  -255,  -255,  -255,   -72,   593,  -255,  -255,  -255,  -255,
    -255,  -255,   688,    26,  -255,  -255,   232,   -72,   121,   593,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,   415,   415,   707,   716,   728,   144,   144,  -255,  -255,
    -255,   200,   124,   438,  -255,  -255,   120,  -255,  -255,  -255,
     587,  -255,  -255,   198,  -255,   203,   328,  -255,    22,  -255,
    -255,  -255,  -255,   196,   203,   263,  -255,  -255,   460,  -255,
    -255,   202,   207,  -255,  -255,   -72,   184,   302,   212,    10,
    -255,  -255,  -255,  -255,  -255,  -255,   129,  -255,  -255,  -255,
     218,   -72,  -255,  -255,   184,   -72,   -72,  -255,  -255,  -255,
    -255
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
    -255,  -255,  -255,  -255,     3,  -255,  -255,  -255,   305,  -255,
    -255,  -255,   159,  -255,  -255,  -255,  -255,  -255,    13,  -255,
    -255,  -255,   324,  -255,  -255,  -255,  -255,  -254,  -255,   290,
     206,   336,  -255,  -255,   213,  -255,  -255,   219,   221,  -255,
      21,  -255,  -255,  -255,    83,  -255,    16,   350,  -255,  -255,
    -255,     0,  -255,     9,   -58,  -255,  -255,   -67,  -255,   190,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,    -1,   -18,  -255,
    -255,   -70,  -137,  -255,  -255,  -255,   -81,  -255,   199,   155,
     172,   -12,    47,    -3,    23,   -14,   268,    55,  -255,  -255,
    -255,   -27,  -255,  -159,     1,    -2,     4,  -131,   211,    20,
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
     136,    13,   114,  -222,  -201,     4,    72,   -44,     4,   311,
    -201,    85,     4,    86,     4,    79,   258,   186,   116,  -201,
      78,   217,   270,   317,   318,   220,   215,  -201,    10,    67,
      11,   140,   261,   -59,   311,    76,    72,    77,   136,   259,
     135,  -185,   133,    83,    74,   101,   176,   176,    80,   137,
      69,    61,    58,    68,    87,   119,   -59,   188,   177,   177,
     185,    59,   133,    68,   178,   178,   121,   185,   197,   187,
     191,   -59,   136,   124,    72,   140,  -222,   300,   132,    81,
     180,   180,    82,   175,   175,  -225,   290,   137,   285,   332,
     122,   196,  -153,  -153,   -59,  -222,   164,   132,   263,   157,
    -225,   291,   253,   118,   104,  -185,   100,     4,  -225,   242,
     243,  -153,   104,   126,   100,   287,   113,    97,   101,  -153,
    -185,    10,   114,    11,   113,    97,   312,    68,   244,   176,
     114,   125,   231,    69,    61,    58,    68,   131,   116,   140,
     -97,   177,   314,   294,    59,   288,   116,   178,   158,   254,
     255,   312,   124,   264,   160,   140,   301,   231,   295,   223,
     138,   161,  -221,   224,  -221,   101,   175,   269,   184,   268,
       4,   138,   304,   101,   186,   148,   235,   149,   186,    69,
     265,   133,   157,   334,    10,   199,    11,    76,   240,   313,
     282,  -181,   286,  -155,  -155,  -210,  -180,  -210,   335,  -210,
     200,   116,   242,   243,    26,    27,   209,   210,   211,   299,
    -182,   176,  -155,   260,   325,    85,    78,    86,     4,    87,
    -155,   257,   269,   177,   138,   176,   329,   201,   101,   178,
     337,  -179,    26,    27,   339,   340,   185,   177,   133,    68,
      83,   213,    83,   178,   329,   180,   137,    88,   175,   132,
     148,  -221,   149,   242,   243,   136,   104,   238,   100,   180,
     283,   185,   175,   133,    68,   293,   307,   315,   113,    97,
     146,   179,   179,   316,   114,   197,   317,   318,   305,   323,
     297,   195,   198,    83,   324,    85,   185,    35,   133,    68,
     116,   307,   331,    89,    69,   328,   133,    68,   336,   239,
     298,   322,    26,    27,  -154,  -154,    43,   202,   203,   212,
      67,   218,    69,   328,   133,    68,   123,   101,    49,   219,
     333,   302,   138,  -154,  -221,    83,  -221,   221,   225,   222,
     338,  -154,    54,   241,   237,    67,   266,   189,   233,   234,
      26,    27,   204,   205,   206,   207,   208,   209,   210,   211,
     202,   203,   330,   267,     0,   198,   289,     0,     4,     0,
     138,     0,  -221,     0,  -221,     0,     6,     0,     0,     0,
       0,     9,    10,     0,    11,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,   204,   205,   206,   207,   208,
     209,   210,   211,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,    20,    21,    22,     0,    24,    25,     4,
    -217,  -217,  -217,  -217,  -217,     0,     0,     6,     0,     0,
      26,    27,     9,    10,     4,    11,     5,    12,    13,  -217,
      14,    15,    16,    17,    18,    19,   179,     0,    10,     0,
      11,     0,     0,   296,     0,     0,     4,     0,     5,    29,
     179,   150,   202,   203,    20,    21,    22,     0,    24,    25,
      10,     0,    11,     0,     0,     0,   141,   142,   143,   144,
     145,    26,    27,    24,    25,   207,   208,   209,   210,   211,
      85,    78,    86,     4,    87,   146,     0,   204,   205,   206,
     207,   208,   209,   210,   211,    24,    25,    10,     0,    11,
      29,   292,   236,     0,    28,     0,     4,     0,     5,     0,
       0,     0,    88,     0,     6,    29,     7,   306,     8,     9,
      10,     0,    11,     0,    12,    13,    28,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,    29,     0,   321,
      85,     0,    86,     4,     0,    26,    27,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    10,    89,    11,
       0,    26,    27,    90,     0,    91,   226,  -224,    26,    27,
      85,    78,    86,     4,    87,     0,    85,    78,    86,     4,
       0,   138,  -224,  -221,     0,  -221,    28,    10,     0,    11,
    -224,     0,     0,    10,     0,    11,     0,    29,     0,     0,
       0,     0,    88,     0,     0,    26,    27,     0,     0,     0,
       0,    85,    78,    86,     4,    87,     0,     0,    89,     0,
       0,     0,     0,    90,     0,   164,   196,     0,    10,     0,
      11,     0,     0,     0,     0,    26,    27,     0,     0,     0,
       0,    26,    27,    88,   202,   203,     0,     0,    89,    85,
      78,    86,     4,    90,    89,    91,     0,     0,   163,    90,
       0,   164,   202,   203,     0,     0,    10,     0,    11,     0,
       0,    85,     0,    86,     4,     0,    26,    27,     0,   204,
     205,   206,   207,   208,   209,   210,   211,     0,    10,    89,
      11,   262,     0,     0,     0,     0,    91,   204,   205,   206,
     207,   208,   209,   210,   211,     0,     0,     0,     0,   281,
       0,     0,     0,     0,    26,    27,     0,     0,     0,     0,
       0,     0,   202,   203,     0,     0,     0,    89,     0,   202,
     203,     0,    90,     0,   164,     0,    26,    27,   202,   203,
       0,     0,   246,   247,   248,   249,   250,   251,     0,    89,
     202,   203,     0,     0,    90,     0,   164,   204,   205,   206,
     207,   208,   209,   210,   211,   205,   206,   207,   208,   209,
     210,   211,     0,     0,     0,   206,   207,   208,   209,   210,
     211,     0,     0,     0,     0,     0,     0,     0,   207,   208,
     209,   210,   211
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,    18,     2,    18,    34,     0,   146,
     138,     2,    82,    16,    81,   146,    18,    18,   146,    77,
      41,    25,    18,    17,    74,     6,    98,    10,     6,   283,
      80,     3,     6,     5,     6,    12,    74,    74,    18,    89,
       4,   122,   201,    33,    34,   126,    88,    97,    20,     2,
      22,    69,    89,    74,   308,     8,    98,    10,    41,    97,
      62,    10,    62,    16,    15,    18,    80,    81,    88,    90,
      72,    72,    72,    72,     7,    28,    97,    89,    80,    81,
      82,    72,    82,    82,    80,    81,    39,    89,    91,    89,
      89,    74,    41,    46,    98,   113,    90,   256,    92,    88,
      80,    81,    88,    80,    81,    74,    74,    90,    89,    99,
      10,    89,    70,    71,    97,    90,    88,    92,   199,    72,
      89,    89,    17,    88,   138,    74,   138,     6,    97,    70,
      71,    89,   146,    26,   146,   216,   138,   138,    91,    97,
      89,    20,   138,    22,   146,   146,   283,   146,    89,   163,
     146,    74,   283,   155,   155,   155,   155,    97,   138,   177,
      97,   163,   290,   244,   155,   223,   146,   163,    21,    64,
      65,   308,   125,   200,    76,   193,   257,   308,   245,   132,
      88,    92,    90,   136,    92,   138,   163,   201,   258,   201,
       6,    88,   259,   146,    74,    90,   149,    92,    74,   201,
     201,   201,   155,    74,    20,    10,    22,   160,   161,    89,
     213,    80,   215,    70,    71,    88,    80,    90,    89,    92,
      80,   201,    70,    71,    68,    69,    82,    83,    84,   256,
      80,   245,    89,   186,   315,     3,     4,     5,     6,     7,
      97,    89,   256,   245,    88,   259,   316,    80,   201,   245,
     331,    80,    68,    69,   335,   336,   258,   259,   258,   258,
     213,    23,   215,   259,   334,   245,    90,    35,   245,    92,
      90,    17,    92,    70,    71,    41,   290,    88,   290,   259,
      98,   283,   259,   283,   283,   238,   283,    89,   290,   290,
      76,    80,    81,    97,   290,   298,    33,    34,    98,    97,
     253,    90,    91,   256,    97,     3,   308,     2,   308,   308,
     290,   308,   100,    81,   316,   316,   316,   316,   100,   160,
      88,   308,    68,    69,    70,    71,     2,    42,    43,   118,
     283,   125,   334,   334,   334,   334,    46,   290,     2,   126,
     319,   258,    88,    89,    90,   298,    92,   128,   137,   128,
     334,    97,     2,   163,   155,   308,   201,    89,   147,   148,
      68,    69,    77,    78,    79,    80,    81,    82,    83,    84,
      42,    43,   317,   201,    -1,   164,    91,    -1,     6,    -1,
      88,    -1,    90,    -1,    92,    -1,    14,    -1,    -1,    -1,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    77,    78,    79,    80,    81,
      82,    83,    84,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    51,    52,    53,    -1,    55,    56,     6,
      57,    58,    59,    60,    61,    -1,    -1,    14,    -1,    -1,
      68,    69,    19,    20,     6,    22,     8,    24,    25,    76,
      27,    28,    29,    30,    31,    32,   245,    -1,    20,    -1,
      22,    -1,    -1,   252,    -1,    -1,     6,    -1,     8,    97,
     259,    99,    42,    43,    51,    52,    53,    -1,    55,    56,
      20,    -1,    22,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    68,    69,    55,    56,    80,    81,    82,    83,    84,
       3,     4,     5,     6,     7,    76,    -1,    77,    78,    79,
      80,    81,    82,    83,    84,    55,    56,    20,    -1,    22,
      97,    91,    99,    -1,    86,    -1,     6,    -1,     8,    -1,
      -1,    -1,    35,    -1,    14,    97,    16,    99,    18,    19,
      20,    -1,    22,    -1,    24,    25,    86,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    97,    -1,    99,
       3,    -1,     5,     6,    -1,    68,    69,    -1,    -1,    -1,
      -1,    51,    52,    53,    54,    55,    56,    20,    81,    22,
      -1,    68,    69,    86,    -1,    88,    89,    74,    68,    69,
       3,     4,     5,     6,     7,    -1,     3,     4,     5,     6,
      -1,    88,    89,    90,    -1,    92,    86,    20,    -1,    22,
      97,    -1,    -1,    20,    -1,    22,    -1,    97,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    68,    69,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    86,    -1,    88,    89,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,
      -1,    68,    69,    35,    42,    43,    -1,    -1,    81,     3,
       4,     5,     6,    86,    81,    88,    -1,    -1,    85,    86,
      -1,    88,    42,    43,    -1,    -1,    20,    -1,    22,    -1,
      -1,     3,    -1,     5,     6,    -1,    68,    69,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    20,    81,
      22,    89,    -1,    -1,    -1,    -1,    88,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    81,    -1,    42,
      43,    -1,    86,    -1,    88,    -1,    68,    69,    42,    43,
      -1,    -1,    62,    63,    64,    65,    66,    67,    -1,    81,
      42,    43,    -1,    -1,    86,    -1,    88,    77,    78,    79,
      80,    81,    82,    83,    84,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    79,    80,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      82,    83,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   102,   103,     0,     6,     8,    14,    16,    18,    19,
      20,    22,    24,    25,    27,    28,    29,    30,    31,    32,
      51,    52,    53,    54,    55,    56,    68,    69,    86,    97,
     104,   105,   106,   107,   108,   109,   111,   112,   114,   115,
     120,   121,   122,   123,   124,   128,   129,   130,   131,   132,
     133,   134,   135,   142,   148,   149,   150,   151,   152,   154,
     157,   168,   169,   171,   172,   173,   175,   183,   195,   196,
     198,   200,    98,   177,    15,   113,   183,   183,     4,   185,
      88,    88,    88,   183,   184,     3,     5,     7,    35,    81,
      86,    88,   126,   127,   152,   153,   154,   168,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   192,
     193,   194,   195,   196,   197,   199,   200,   201,    88,   183,
     192,   183,    10,   130,   183,    74,    26,   136,   137,   138,
     139,    97,    92,   152,   183,   196,    41,    90,    88,   155,
     169,    57,    58,    59,    60,    61,    76,   176,    90,    92,
      99,   105,   109,   132,   148,   178,   179,   183,    21,   110,
      76,    92,   155,    85,    88,   158,   160,   161,   162,   163,
     164,   165,   168,   170,   182,   185,   186,   196,   197,   199,
     200,   158,   144,   145,   172,   196,    74,   152,   182,   187,
     191,   195,   186,   196,   197,   199,    89,   184,   199,    10,
      80,    80,    42,    43,    77,    78,    79,    80,    81,    82,
      83,    84,   199,    23,   116,    88,   125,   177,   131,   135,
     177,   138,   139,   183,   183,   199,    89,   156,   201,   173,
     174,   198,   201,   199,   199,   183,    99,   179,    88,   113,
     183,   160,    70,    71,    89,   159,    62,    63,    64,    65,
      66,    67,   166,    17,    64,    65,   167,    89,    74,    97,
     183,    89,    89,   177,   192,   168,   180,   181,   182,   186,
     194,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,    89,   184,    98,   117,    89,   184,   177,   155,    91,
      74,    89,    91,   183,   177,   158,   199,   183,    88,   192,
     194,   177,   145,   143,   158,    98,    99,   105,   118,   119,
     123,   128,   173,    89,   201,    89,    97,    33,    34,   140,
     141,    99,   119,    97,    97,   177,   146,   147,   168,   172,
     188,   100,    99,   141,    74,    89,   100,   177,   147,   177,
     177
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   103,   104,   104,   104,   104,   104,
     105,   106,   106,   106,   106,   107,   108,   108,   108,   109,
     109,   110,   111,   112,   113,   113,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   120,
     121,   122,   123,   123,   124,   124,   124,   125,   125,   126,
     127,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   136,   136,
     137,   137,   138,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   144,   144,   144,   145,   146,   146,   146,   147,
     147,   148,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   150,   150,   151,   151,   151,   151,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     154,   155,   155,   156,   156,   157,   158,   158,   158,   158,
     158,   159,   159,   160,   160,   161,   162,   163,   163,   164,
     165,   166,   166,   166,   166,   166,   166,   167,   167,   168,
     168,   169,   169,   170,   170,   170,   171,   172,   172,   173,
     174,   174,   175,   176,   176,   176,   176,   176,   177,   177,
     178,   178,   179,   179,   179,   179,   180,   180,   181,   181,
     181,   181,   181,   182,   183,   184,   184,   185,   186,   186,
     187,   187,   188,   189,   190,   191,   191,   191,   191,   192,
     193,   194,   194,   194,   194,   194,   195,   195,   195,   195,
     196,   196,   196,   197,   197,   197,   197,   198,   199,   199,
     199,   200,   200,   201,   201,   201,   201
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
#line 85 "a.y"
                                   { execAndFreeNode((yyvsp[0].node));}
#line 1866 "y.tab.c"
    break;

  case 5: /* statement: _extra_nothing  */
#line 89 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1872 "y.tab.c"
    break;

  case 6: /* statement: out_declare_stmt  */
#line 90 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1878 "y.tab.c"
    break;

  case 7: /* statement: con_ctl_stmt  */
#line 91 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1884 "y.tab.c"
    break;

  case 8: /* statement: simple_stmt  */
#line 92 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1890 "y.tab.c"
    break;

  case 9: /* statement: try_stmt  */
#line 93 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1896 "y.tab.c"
    break;

  case 10: /* _extra_nothing: ';'  */
#line 97 "a.y"
                { (yyval.node) = NULL; }
#line 1902 "y.tab.c"
    break;

  case 11: /* out_declare_stmt: func_declare_stmt  */
#line 101 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1908 "y.tab.c"
    break;

  case 12: /* out_declare_stmt: class_declare_stmt  */
#line 102 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1914 "y.tab.c"
    break;

  case 13: /* out_declare_stmt: namespace_declare_stmt  */
#line 103 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 1920 "y.tab.c"
    break;

  case 14: /* out_declare_stmt: namespace_ref_stmt  */
#line 104 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1926 "y.tab.c"
    break;

  case 15: /* require_stmt: require_operators string_expr  */
#line 109 "a.y"
                                                { (yyval.node) = opr((yyvsp[-1].iValue) , 1 , (yyvsp[0].node)); }
#line 1932 "y.tab.c"
    break;

  case 16: /* require_operators: KEY_REQUIRE  */
#line 113 "a.y"
                              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1938 "y.tab.c"
    break;

  case 17: /* require_operators: KEY_REQUIRE_ONCE  */
#line 114 "a.y"
                              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1944 "y.tab.c"
    break;

  case 18: /* require_operators: KEY_INCLUDE  */
#line 115 "a.y"
                             { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1950 "y.tab.c"
    break;

  case 19: /* try_stmt: KEY_TRY code_block  */
#line 120 "a.y"
                               { (yyval.node) = opr(KEY_TRY, 2,(yyvsp[0].node),NULL); }
#line 1956 "y.tab.c"
    break;

  case 20: /* try_stmt: KEY_TRY code_block catch_block_stmt  */
#line 121 "a.y"
                                               { (yyval.node) = opr(KEY_TRY, 2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1962 "y.tab.c"
    break;

  case 21: /* catch_block_stmt: KEY_CATCH '(' id_expr ')' code_block  */
#line 125 "a.y"
                                                { (yyval.node) = opr(KEY_CATCH, 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1968 "y.tab.c"
    break;

  case 22: /* namespace_declare_stmt: KEY_SET KEY_PUBLIC '=' namespace_name_stmt  */
#line 131 "a.y"
                                                     { (yyval.node) = opr(OPR_CHANGE_NAME_SPACE, 1, (yyvsp[0].node)); }
#line 1974 "y.tab.c"
    break;

  case 23: /* namespace_ref_stmt: KEY_REF namespace_name_stmt  */
#line 136 "a.y"
                                        { (yyval.node) = opr(KEY_REF, 1, (yyvsp[0].node)); }
#line 1980 "y.tab.c"
    break;

  case 24: /* namespace_name_stmt: id_expr  */
#line 140 "a.y"
                   { (yyval.node) = opr(OPR_CAT_NS_NAME, 1, (yyvsp[0].node)); }
#line 1986 "y.tab.c"
    break;

  case 25: /* namespace_name_stmt: namespace_name_stmt '.' id_expr  */
#line 141 "a.y"
                                          { (yyval.node) = opr(OPR_CAT_NS_NAME, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1992 "y.tab.c"
    break;

  case 26: /* class_declare_stmt: class_name_prefix id_expr class_name_suffix class_body  */
#line 151 "a.y"
                                                                     {  (yyval.node) = opr(OPR_CLASS_DECLARE, 4, intNode((yyvsp[-3].iValue)), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1998 "y.tab.c"
    break;

  case 27: /* class_name_prefix: %empty  */
#line 155 "a.y"
             { (yyval.iValue) = -1; }
#line 2004 "y.tab.c"
    break;

  case 28: /* class_name_prefix: KEY_AUTO  */
#line 156 "a.y"
                 { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2010 "y.tab.c"
    break;

  case 29: /* class_name_suffix: %empty  */
#line 161 "a.y"
                              { (yyval.node) = NULL; }
#line 2016 "y.tab.c"
    break;

  case 30: /* class_name_suffix: KEY_EXTENDS multiple_id_expr  */
#line 162 "a.y"
                                        { (yyval.node) = opr(KEY_EXTENDS, 1, (yyvsp[0].node)); }
#line 2022 "y.tab.c"
    break;

  case 31: /* class_body: '{' '}'  */
#line 166 "a.y"
                        { (yyval.node) = NULL; }
#line 2028 "y.tab.c"
    break;

  case 32: /* class_body: '{' class_body_items '}'  */
#line 167 "a.y"
                                { (yyval.node) = opr(CLAXX_BODY, 1, (yyvsp[-1].node)); }
#line 2034 "y.tab.c"
    break;

  case 33: /* class_body_items: class_body_item  */
#line 171 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2040 "y.tab.c"
    break;

  case 34: /* class_body_items: class_body_items class_body_item  */
#line 172 "a.y"
                                        { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[-1].node) ,(yyvsp[0].node)); }
#line 2046 "y.tab.c"
    break;

  case 35: /* class_body_item: var_declare_stmt ';'  */
#line 176 "a.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2052 "y.tab.c"
    break;

  case 36: /* class_body_item: single_assign_stmt ';'  */
#line 177 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2058 "y.tab.c"
    break;

  case 37: /* class_body_item: func_declare_stmt  */
#line 178 "a.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2064 "y.tab.c"
    break;

  case 38: /* class_body_item: _extra_nothing  */
#line 179 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2070 "y.tab.c"
    break;

  case 39: /* this_stmt: KEY_THIS  */
#line 184 "a.y"
                      { (yyval.node) = opr(KEY_THIS , 0 ); }
#line 2076 "y.tab.c"
    break;

  case 40: /* class_member_stmt: common_object_expr '.' id_expr  */
#line 190 "a.y"
                                               { (yyval.node) = opr(CLAXX_MEMBER, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2082 "y.tab.c"
    break;

  case 41: /* static_member_stmt: id_expr SCOPE id_expr  */
#line 195 "a.y"
                                  { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2088 "y.tab.c"
    break;

  case 42: /* func_declare_stmt: func_name_types FUNC_OP code_block  */
#line 205 "a.y"
                                                        { (yyval.node) = opr(FUNC_OP,3, (yyvsp[-2].node), NULL, (yyvsp[0].node)); }
#line 2094 "y.tab.c"
    break;

  case 43: /* func_declare_stmt: func_name_types FUNC_OP func_param_list code_block  */
#line 206 "a.y"
                                                                  { (yyval.node) = opr(FUNC_OP, 3, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2100 "y.tab.c"
    break;

  case 44: /* func_name_types: id_expr  */
#line 210 "a.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2106 "y.tab.c"
    break;

  case 45: /* func_name_types: '~' id_expr  */
#line 211 "a.y"
                    { char buf[1024] = "~"; strcat(buf, (yyvsp[0].node)->var_obj->name);  (yyval.node) = varWithNameNeedFree(strdup(buf)); }
#line 2112 "y.tab.c"
    break;

  case 46: /* func_name_types: OPERATOR_X__  */
#line 212 "a.y"
                    { (yyval.node) = var((yyvsp[0].sValue)); }
#line 2118 "y.tab.c"
    break;

  case 47: /* func_param_list: '(' ')'  */
#line 216 "a.y"
                        { (yyval.node) = NULL; }
#line 2124 "y.tab.c"
    break;

  case 48: /* func_param_list: '(' multiple_id_expr ')'  */
#line 217 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2130 "y.tab.c"
    break;

  case 49: /* lambda_stmt: lambda_args_stmt FUNC_OP code_block  */
#line 222 "a.y"
                                                { (yyval.node) = opr(FUNC_OP, 3, NULL, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2136 "y.tab.c"
    break;

  case 50: /* lambda_args_stmt: '(' ')'  */
#line 226 "a.y"
                     { (yyval.node) = NULL; }
#line 2142 "y.tab.c"
    break;

  case 51: /* lambda_args_stmt: '(' multiple_id_expr ')'  */
#line 227 "a.y"
                              { (yyval.node) = (yyvsp[-1].node); }
#line 2148 "y.tab.c"
    break;

  case 52: /* lambda_args_stmt: multiple_id_expr  */
#line 228 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2154 "y.tab.c"
    break;

  case 53: /* var_declare_stmt: _elements_var_declare_stmt  */
#line 233 "a.y"
                                      { (yyval.node) = opr(VAR_DECLAR , 2, NULL, (yyvsp[0].node) ); }
#line 2160 "y.tab.c"
    break;

  case 54: /* var_declare_stmt: var_prefix _elements_var_declare_stmt  */
#line 234 "a.y"
                                                { (yyval.node) = opr(VAR_DECLAR, 2, intNode((yyvsp[-1].iValue)), (yyvsp[0].node) ); }
#line 2166 "y.tab.c"
    break;

  case 55: /* var_prefix: KEY_CONST  */
#line 238 "a.y"
                 { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2172 "y.tab.c"
    break;

  case 56: /* var_prefix: KEY_LOCAL  */
#line 239 "a.y"
                 { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2178 "y.tab.c"
    break;

  case 57: /* _elements_var_declare_stmt: element_var_declare_stmt  */
#line 243 "a.y"
                                   { (yyval.node) = (yyvsp[0].node); }
#line 2184 "y.tab.c"
    break;

  case 58: /* _elements_var_declare_stmt: _elements_var_declare_stmt ',' element_var_declare_stmt  */
#line 244 "a.y"
                                                             { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2190 "y.tab.c"
    break;

  case 59: /* element_var_declare_stmt: id_expr  */
#line 248 "a.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2196 "y.tab.c"
    break;

  case 60: /* element_var_declare_stmt: id_expr '[' common_number_expr ']'  */
#line 249 "a.y"
                                                        { (yyval.node) = arrayNode((yyvsp[-3].node)->var_obj->name, -1, (yyvsp[-1].node)); }
#line 2202 "y.tab.c"
    break;

  case 61: /* con_ctl_stmt: selection_stmt  */
#line 254 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2208 "y.tab.c"
    break;

  case 62: /* con_ctl_stmt: loop_stmt  */
#line 255 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2214 "y.tab.c"
    break;

  case 63: /* selection_stmt: if_stmt  */
#line 260 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2220 "y.tab.c"
    break;

  case 64: /* selection_stmt: KEY_SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  */
#line 261 "a.y"
                                                                        { (yyval.node) = opr(KEY_SWITCH, 2 , (yyvsp[-4].node),(yyvsp[-1].node)); pretreatSwitch( (yyval.node) ) ; }
#line 2226 "y.tab.c"
    break;

  case 65: /* if_stmt: single_if_stmt  */
#line 265 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2232 "y.tab.c"
    break;

  case 66: /* if_stmt: single_if_stmt else_stmt  */
#line 266 "a.y"
                             { (yyval.node) = opr(OPR_IF_ELSE, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2238 "y.tab.c"
    break;

  case 67: /* single_if_stmt: KEY_IF '(' logic_stmt ')' code_block  */
#line 270 "a.y"
                                         { (yyval.node) = opr(KEY_IF ,2,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2244 "y.tab.c"
    break;

  case 68: /* else_stmt: else_if_stmts single_else_stmt  */
#line 274 "a.y"
                                      { (yyval.node) =  opr(OPR_NODE_LIST, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2250 "y.tab.c"
    break;

  case 69: /* else_stmt: single_else_stmt  */
#line 275 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2256 "y.tab.c"
    break;

  case 70: /* else_if_stmts: else_if_stmt  */
#line 279 "a.y"
                        { (yyval.node) = opr(OPR_NODE_LIST, 1, (yyvsp[0].node)); }
#line 2262 "y.tab.c"
    break;

  case 71: /* else_if_stmts: else_if_stmts else_if_stmt  */
#line 280 "a.y"
                                  { (yyval.node) =  opr(OPR_NODE_LIST, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2268 "y.tab.c"
    break;

  case 72: /* else_if_stmt: KEY_ELSE single_if_stmt  */
#line 284 "a.y"
                              { (yyval.node) = opr(KEY_ELSE, 2, (yyvsp[0].node), NULL); }
#line 2274 "y.tab.c"
    break;

  case 73: /* single_else_stmt: KEY_ELSE code_block  */
#line 288 "a.y"
                            { (yyval.node) = opr( KEY_ELSE, 1, (yyvsp[0].node)); }
#line 2280 "y.tab.c"
    break;

  case 74: /* case_stmt_list: case_stmt  */
#line 292 "a.y"
                               { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[0].node) ); }
#line 2286 "y.tab.c"
    break;

  case 75: /* case_stmt_list: case_stmt_list case_stmt  */
#line 293 "a.y"
                                   { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[-1].node), (yyvsp[0].node) ); }
#line 2292 "y.tab.c"
    break;

  case 76: /* case_stmt: KEY_CASE int_expr ':' code_block  */
#line 297 "a.y"
                                                  { (yyval.node) = opr(KEY_CASE, 2 , (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2298 "y.tab.c"
    break;

  case 77: /* case_stmt: KEY_DEFAULT ':' code_block  */
#line 298 "a.y"
                                                     { (yyval.node) = opr(KEY_DEFAULT , 1, (yyvsp[0].node)); }
#line 2304 "y.tab.c"
    break;

  case 78: /* loop_stmt: KEY_WHILE '(' logic_stmt ')' code_block  */
#line 302 "a.y"
                                                  { (yyval.node) = opr(KEY_WHILE , 2, (yyvsp[-2].node), (yyvsp[0].node) ); }
#line 2310 "y.tab.c"
    break;

  case 79: /* loop_stmt: KEY_FOR '(' for_1_stmt_list ';' for_logic_stmt ';' for_3_stmt_list ')' code_block  */
#line 303 "a.y"
                                                                                            { (yyval.node) = opr(KEY_FOR,4,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2316 "y.tab.c"
    break;

  case 80: /* for_logic_stmt: %empty  */
#line 307 "a.y"
          { (yyval.node) = intNode(1);  }
#line 2322 "y.tab.c"
    break;

  case 81: /* for_logic_stmt: logic_stmt  */
#line 308 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2328 "y.tab.c"
    break;

  case 82: /* for_1_stmt_list: %empty  */
#line 312 "a.y"
         { (yyval.node) = NULL ; }
#line 2334 "y.tab.c"
    break;

  case 83: /* for_1_stmt_list: for_1_stmt  */
#line 313 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2340 "y.tab.c"
    break;

  case 84: /* for_1_stmt_list: for_1_stmt_list ',' for_1_stmt  */
#line 314 "a.y"
                                      { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2346 "y.tab.c"
    break;

  case 85: /* for_1_stmt: assign_stmt  */
#line 319 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2352 "y.tab.c"
    break;

  case 86: /* for_3_stmt_list: %empty  */
#line 325 "a.y"
         { (yyval.node) = NULL ; }
#line 2358 "y.tab.c"
    break;

  case 87: /* for_3_stmt_list: for_3_stmt  */
#line 326 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2364 "y.tab.c"
    break;

  case 88: /* for_3_stmt_list: for_3_stmt_list ',' for_3_stmt  */
#line 327 "a.y"
                                      { (yyval.node) = opr(OPR_NODE_LIST, 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2370 "y.tab.c"
    break;

  case 89: /* for_3_stmt: assign_stmt  */
#line 332 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2376 "y.tab.c"
    break;

  case 90: /* for_3_stmt: self_inc_dec_stmt  */
#line 333 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2382 "y.tab.c"
    break;

  case 91: /* simple_stmt: simple_stmt_types ';'  */
#line 338 "a.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 2388 "y.tab.c"
    break;

  case 92: /* simple_stmt_types: self_inc_dec_stmt  */
#line 342 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2394 "y.tab.c"
    break;

  case 93: /* simple_stmt_types: assign_stmt  */
#line 343 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2400 "y.tab.c"
    break;

  case 94: /* simple_stmt_types: call_statement  */
#line 344 "a.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 2406 "y.tab.c"
    break;

  case 95: /* simple_stmt_types: delete_expr  */
#line 345 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2412 "y.tab.c"
    break;

  case 96: /* simple_stmt_types: interrupt_stmt  */
#line 346 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2418 "y.tab.c"
    break;

  case 97: /* simple_stmt_types: new_expr  */
#line 347 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2424 "y.tab.c"
    break;

  case 98: /* simple_stmt_types: restrict_stmt  */
#line 348 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2430 "y.tab.c"
    break;

  case 99: /* simple_stmt_types: require_stmt  */
#line 349 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2436 "y.tab.c"
    break;

  case 100: /* simple_stmt_types: var_declare_stmt  */
#line 350 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2442 "y.tab.c"
    break;

  case 101: /* restrict_stmt: KEY_RESTRICT  */
#line 355 "a.y"
                             { (yyval.node) = opr(KEY_RESTRICT,0);}
#line 2448 "y.tab.c"
    break;

  case 102: /* restrict_stmt: KEY_RESTRICT bool_expr  */
#line 356 "a.y"
                                  { (yyval.node) = opr(KEY_RESTRICT,1,(yyvsp[0].node)); }
#line 2454 "y.tab.c"
    break;

  case 103: /* interrupt_stmt: KEY_BREAK  */
#line 360 "a.y"
                    { (yyval.node) = opr(KEY_BREAK, 0); }
#line 2460 "y.tab.c"
    break;

  case 104: /* interrupt_stmt: KEY_RETURN  */
#line 361 "a.y"
                     { (yyval.node) = opr(KEY_RETURN , 0); }
#line 2466 "y.tab.c"
    break;

  case 105: /* interrupt_stmt: KEY_RETURN common_expr  */
#line 362 "a.y"
                                 { (yyval.node) = opr(KEY_RETURN , 1 ,(yyvsp[0].node));}
#line 2472 "y.tab.c"
    break;

  case 106: /* interrupt_stmt: KEY_CONTINUE  */
#line 363 "a.y"
                 { (yyval.node) = opr(KEY_CONTINUE,0); }
#line 2478 "y.tab.c"
    break;

  case 107: /* call_statement: common_values_expr args_list_with_parentheses  */
#line 368 "a.y"
                                                                        { (yyval.node) = opr(FUNC_CALL, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2484 "y.tab.c"
    break;

  case 108: /* call_statement: call_statement '.' id_expr args_list_with_parentheses  */
#line 369 "a.y"
                                                                           { (yyval.node) = opr(CLAXX_FUNC_CALL, 3, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2490 "y.tab.c"
    break;

  case 109: /* arithmetic_stmt: common_number_expr '+' common_number_expr  */
#line 374 "a.y"
                                                    { (yyval.node) = opr('+',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2496 "y.tab.c"
    break;

  case 110: /* arithmetic_stmt: common_number_expr '-' common_number_expr  */
#line 375 "a.y"
                                                    { (yyval.node) = opr('-',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2502 "y.tab.c"
    break;

  case 111: /* arithmetic_stmt: common_number_expr '*' common_number_expr  */
#line 376 "a.y"
                                                    { (yyval.node) = opr('*',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2508 "y.tab.c"
    break;

  case 112: /* arithmetic_stmt: common_number_expr '/' common_number_expr  */
#line 377 "a.y"
                                                    { (yyval.node) = opr('/',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2514 "y.tab.c"
    break;

  case 113: /* arithmetic_stmt: common_number_expr '%' common_number_expr  */
#line 378 "a.y"
                                                    { (yyval.node) = opr('%',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2520 "y.tab.c"
    break;

  case 114: /* arithmetic_stmt: common_number_expr '&' common_number_expr  */
#line 379 "a.y"
                                                     { (yyval.node) = opr('&',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2526 "y.tab.c"
    break;

  case 115: /* arithmetic_stmt: common_number_expr '|' common_number_expr  */
#line 380 "a.y"
                                                     { (yyval.node) = opr('|',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2532 "y.tab.c"
    break;

  case 116: /* arithmetic_stmt: common_number_expr '^' common_number_expr  */
#line 381 "a.y"
                                                     { (yyval.node) = opr('^',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2538 "y.tab.c"
    break;

  case 117: /* arithmetic_stmt: common_number_expr LEFT_SHIFT common_number_expr  */
#line 382 "a.y"
                                                            { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2544 "y.tab.c"
    break;

  case 118: /* arithmetic_stmt: common_number_expr RIGHT_SHIFT common_number_expr  */
#line 383 "a.y"
                                                             { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2550 "y.tab.c"
    break;

  case 119: /* arithmetic_stmt: '~' common_number_expr  */
#line 384 "a.y"
                            { (yyval.node) = opr('~',1,(yyvsp[0].node)); }
#line 2556 "y.tab.c"
    break;

  case 120: /* new_expr: KEY_NEW id_expr args_list_with_parentheses  */
#line 389 "a.y"
                                                     { (yyval.node) = opr(KEY_NEW, 2 , (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2562 "y.tab.c"
    break;

  case 121: /* args_list_with_parentheses: '(' ')'  */
#line 393 "a.y"
                  { (yyval.node) = NULL; }
#line 2568 "y.tab.c"
    break;

  case 122: /* args_list_with_parentheses: '(' args_list ')'  */
#line 394 "a.y"
                        { (yyval.node) = (yyvsp[-1].node); }
#line 2574 "y.tab.c"
    break;

  case 123: /* args_list: common_expr  */
#line 398 "a.y"
                    { (yyval.node) = opr(OPR_NODE_LIST, 1, (yyvsp[0].node)); }
#line 2580 "y.tab.c"
    break;

  case 124: /* args_list: args_list ',' common_expr  */
#line 399 "a.y"
                               { (yyval.node) = opr(OPR_NODE_LIST, 2 , (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2586 "y.tab.c"
    break;

  case 125: /* delete_expr: KEY_DELETE multiple_id_expr  */
#line 403 "a.y"
                                  { (yyval.node) = opr(KEY_DELETE, 1, (yyvsp[0].node)); }
#line 2592 "y.tab.c"
    break;

  case 126: /* logic_stmt: bool_param_expr  */
#line 409 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2598 "y.tab.c"
    break;

  case 127: /* logic_stmt: not_bool_param_expr  */
#line 410 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2604 "y.tab.c"
    break;

  case 128: /* logic_stmt: type_judge_stmt  */
#line 411 "a.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 2610 "y.tab.c"
    break;

  case 129: /* logic_stmt: compare_expr  */
#line 412 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2616 "y.tab.c"
    break;

  case 130: /* logic_stmt: logic_stmt _symbol_logic_connection logic_stmt  */
#line 413 "a.y"
                                                        { (yyval.node) = opr((yyvsp[-1].iValue), 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2622 "y.tab.c"
    break;

  case 131: /* _symbol_logic_connection: AND_OP  */
#line 417 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2628 "y.tab.c"
    break;

  case 132: /* _symbol_logic_connection: OR_OP  */
#line 418 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2634 "y.tab.c"
    break;

  case 133: /* bool_param_expr: assign_stmt_value_eq  */
#line 423 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2640 "y.tab.c"
    break;

  case 134: /* bool_param_expr: bool_expr  */
#line 424 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2646 "y.tab.c"
    break;

  case 135: /* type_judge_stmt: common_object_expr KEY_IS id_expr  */
#line 429 "a.y"
                                             { (yyval.node) = opr(KEY_IS ,2 , (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2652 "y.tab.c"
    break;

  case 136: /* not_bool_param_expr: '!' bool_param_expr  */
#line 433 "a.y"
                          { (yyval.node) = opr('!', 1, (yyvsp[0].node)); }
#line 2658 "y.tab.c"
    break;

  case 137: /* compare_expr: number_compare_expr  */
#line 438 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2664 "y.tab.c"
    break;

  case 138: /* compare_expr: object_compare_expr  */
#line 439 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2670 "y.tab.c"
    break;

  case 139: /* number_compare_expr: common_number_expr _symbol_compare common_number_expr  */
#line 443 "a.y"
                                                          { (yyval.node) = opr((yyvsp[-1].iValue), 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2676 "y.tab.c"
    break;

  case 140: /* object_compare_expr: common_object_expr _symbol_equals_not common_types_expr  */
#line 447 "a.y"
                                                             { (yyval.node) = opr((yyvsp[-1].iValue), 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2682 "y.tab.c"
    break;

  case 141: /* _symbol_compare: '>'  */
#line 451 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2688 "y.tab.c"
    break;

  case 142: /* _symbol_compare: '<'  */
#line 452 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2694 "y.tab.c"
    break;

  case 143: /* _symbol_compare: GE_OP  */
#line 453 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2700 "y.tab.c"
    break;

  case 144: /* _symbol_compare: LE_OP  */
#line 454 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2706 "y.tab.c"
    break;

  case 145: /* _symbol_compare: NE_OP  */
#line 455 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2712 "y.tab.c"
    break;

  case 146: /* _symbol_compare: EQ_OP  */
#line 456 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2718 "y.tab.c"
    break;

  case 147: /* _symbol_equals_not: NE_OP  */
#line 460 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2724 "y.tab.c"
    break;

  case 148: /* _symbol_equals_not: EQ_OP  */
#line 461 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2730 "y.tab.c"
    break;

  case 149: /* self_inc_dec_stmt: self_inc_dec_operators common_values_expr  */
#line 466 "a.y"
                                                    { (yyval.node) = opr(OPR_INC_DEC,2, intNode((yyvsp[-1].iValue)), (yyvsp[0].node) ); }
#line 2736 "y.tab.c"
    break;

  case 150: /* self_inc_dec_stmt: common_values_expr self_inc_dec_operators  */
#line 467 "a.y"
                                                                       { (yyval.node) = opr(OPR_INC_DEC, 2, (yyvsp[-1].node), intNode((yyvsp[0].iValue))); }
#line 2742 "y.tab.c"
    break;

  case 151: /* self_inc_dec_operators: INC_OP  */
#line 471 "a.y"
                  { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2748 "y.tab.c"
    break;

  case 152: /* self_inc_dec_operators: DEC_OP  */
#line 472 "a.y"
                  { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2754 "y.tab.c"
    break;

  case 153: /* assign_stmt_value_eq: number_expr  */
#line 478 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2760 "y.tab.c"
    break;

  case 154: /* assign_stmt_value_eq: common_values_expr  */
#line 479 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2766 "y.tab.c"
    break;

  case 155: /* assign_stmt_value_eq: common_result_of_call_expr  */
#line 480 "a.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2772 "y.tab.c"
    break;

  case 156: /* array_ele_stmt: common_object_expr '[' common_number_expr ']'  */
#line 488 "a.y"
                                                         { (yyval.node) = objectArrayElementNode((yyvsp[-3].node), -1, (yyvsp[-1].node)); }
#line 2778 "y.tab.c"
    break;

  case 157: /* assign_stmt: single_assign_stmt  */
#line 493 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2784 "y.tab.c"
    break;

  case 158: /* assign_stmt: number_change_assign_stmt  */
#line 494 "a.y"
                                    { (yyval.node) = (yyvsp[0].node) ;}
#line 2790 "y.tab.c"
    break;

  case 159: /* single_assign_stmt: common_assignable_expr '=' single_assign_stmt_value  */
#line 498 "a.y"
                                                              { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 2796 "y.tab.c"
    break;

  case 160: /* single_assign_stmt_value: common_expr  */
#line 502 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2802 "y.tab.c"
    break;

  case 161: /* single_assign_stmt_value: single_assign_stmt  */
#line 503 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2808 "y.tab.c"
    break;

  case 162: /* number_change_assign_stmt: common_assignable_expr symbol_change_assign common_number_expr  */
#line 507 "a.y"
                                                                    { (yyval.node) = opr((yyvsp[-1].iValue), 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2814 "y.tab.c"
    break;

  case 163: /* symbol_change_assign: ADD_EQ  */
#line 511 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2820 "y.tab.c"
    break;

  case 164: /* symbol_change_assign: SUB_EQ  */
#line 512 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2826 "y.tab.c"
    break;

  case 165: /* symbol_change_assign: MUL_EQ  */
#line 513 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2832 "y.tab.c"
    break;

  case 166: /* symbol_change_assign: DIV_EQ  */
#line 514 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2838 "y.tab.c"
    break;

  case 167: /* symbol_change_assign: MOD_EQ  */
#line 515 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2844 "y.tab.c"
    break;

  case 168: /* code_block: '{' '}'  */
#line 520 "a.y"
                    { (yyval.node) = NULL; }
#line 2850 "y.tab.c"
    break;

  case 169: /* code_block: '{' block_item_list '}'  */
#line 521 "a.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2856 "y.tab.c"
    break;

  case 170: /* block_item_list: block_item  */
#line 525 "a.y"
                                    { (yyval.node) = opr(OPR_NODE_LIST, 1, (yyvsp[0].node)); }
#line 2862 "y.tab.c"
    break;

  case 171: /* block_item_list: block_item_list block_item  */
#line 526 "a.y"
                                    { (yyval.node) = opr(OPR_NODE_LIST, 2 , (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2868 "y.tab.c"
    break;

  case 172: /* block_item: try_stmt  */
#line 530 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2874 "y.tab.c"
    break;

  case 173: /* block_item: simple_stmt  */
#line 531 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2880 "y.tab.c"
    break;

  case 174: /* block_item: con_ctl_stmt  */
#line 532 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2886 "y.tab.c"
    break;

  case 175: /* block_item: _extra_nothing  */
#line 533 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2892 "y.tab.c"
    break;

  case 176: /* string_plus_stmt: string_expr '+' string_plus_stmt_value  */
#line 538 "a.y"
                                              { (yyval.node) = opr('+', 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2898 "y.tab.c"
    break;

  case 177: /* string_plus_stmt: string_plus_stmt_value '+' string_expr  */
#line 539 "a.y"
                                              { (yyval.node) = opr('+', 2, (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2904 "y.tab.c"
    break;

  case 178: /* string_plus_stmt_value: common_object_expr  */
#line 543 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2910 "y.tab.c"
    break;

  case 179: /* string_plus_stmt_value: common_types_expr  */
#line 544 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2916 "y.tab.c"
    break;

  case 180: /* string_plus_stmt_value: string_plus_stmt  */
#line 545 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2922 "y.tab.c"
    break;

  case 181: /* string_plus_stmt_value: self_inc_dec_stmt  */
#line 546 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2928 "y.tab.c"
    break;

  case 182: /* string_plus_stmt_value: number_parentheses_stmt  */
#line 547 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2934 "y.tab.c"
    break;

  case 183: /* number_parentheses_stmt: '(' common_number_expr ')'  */
#line 551 "a.y"
                                   { (yyval.node) = (yyvsp[-1].node); }
#line 2940 "y.tab.c"
    break;

  case 184: /* id_expr: IDENTIFIER  */
#line 557 "a.y"
                     { (yyval.node) = var((yyvsp[0].sValue)); }
#line 2946 "y.tab.c"
    break;

  case 185: /* multiple_id_expr: id_expr  */
#line 561 "a.y"
                    { (yyval.node) = (yyvsp[0].node);}
#line 2952 "y.tab.c"
    break;

  case 186: /* multiple_id_expr: multiple_id_expr ',' id_expr  */
#line 562 "a.y"
                                   { (yyval.node) = opr(OPR_MULTIPLE_ID , 2 , (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2958 "y.tab.c"
    break;

  case 187: /* bool_expr: TBOOL  */
#line 566 "a.y"
                  { (yyval.node) = intNode((yyvsp[0].iValue)); }
#line 2964 "y.tab.c"
    break;

  case 188: /* number_expr: positive_number_expr  */
#line 570 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2970 "y.tab.c"
    break;

  case 189: /* number_expr: uminus_expr  */
#line 571 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2976 "y.tab.c"
    break;

  case 190: /* positive_number_expr: double_expr  */
#line 575 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2982 "y.tab.c"
    break;

  case 191: /* positive_number_expr: int_expr  */
#line 576 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2988 "y.tab.c"
    break;

  case 192: /* int_expr: TINTEGER  */
#line 580 "a.y"
             { (yyval.node) = intNode((yyvsp[0].iValue)); }
#line 2994 "y.tab.c"
    break;

  case 193: /* double_expr: TDOUBLE  */
#line 584 "a.y"
                  { (yyval.node) = number((yyvsp[0].dValue)); }
#line 3000 "y.tab.c"
    break;

  case 194: /* uminus_expr: '-' uminus_expr_values  */
#line 588 "a.y"
                                              { (yyval.node) = opr(UMINUS, 1, (yyvsp[0].node) ); }
#line 3006 "y.tab.c"
    break;

  case 195: /* uminus_expr_values: positive_number_expr  */
#line 592 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3012 "y.tab.c"
    break;

  case 196: /* uminus_expr_values: common_others_values_expr  */
#line 593 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3018 "y.tab.c"
    break;

  case 197: /* uminus_expr_values: call_statement  */
#line 594 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3024 "y.tab.c"
    break;

  case 198: /* uminus_expr_values: number_parentheses_stmt  */
#line 595 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3030 "y.tab.c"
    break;

  case 199: /* string_expr: TSTRING  */
#line 599 "a.y"
                   { (yyval.node) = string((yyvsp[0].sValue)); }
#line 3036 "y.tab.c"
    break;

  case 200: /* null_expr: KEY_NULL  */
#line 603 "a.y"
                     { (yyval.node) = xnull(); }
#line 3042 "y.tab.c"
    break;

  case 201: /* common_types_expr: number_expr  */
#line 610 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3048 "y.tab.c"
    break;

  case 202: /* common_types_expr: string_expr  */
#line 611 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3054 "y.tab.c"
    break;

  case 203: /* common_types_expr: null_expr  */
#line 612 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3060 "y.tab.c"
    break;

  case 204: /* common_types_expr: lambda_stmt  */
#line 613 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3066 "y.tab.c"
    break;

  case 205: /* common_types_expr: bool_expr  */
#line 614 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3072 "y.tab.c"
    break;

  case 206: /* common_others_values_expr: id_expr  */
#line 618 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3078 "y.tab.c"
    break;

  case 207: /* common_others_values_expr: array_ele_stmt  */
#line 619 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3084 "y.tab.c"
    break;

  case 208: /* common_others_values_expr: class_member_stmt  */
#line 620 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3090 "y.tab.c"
    break;

  case 209: /* common_others_values_expr: static_member_stmt  */
#line 621 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 3096 "y.tab.c"
    break;

  case 210: /* common_values_expr: common_others_values_expr  */
#line 625 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3102 "y.tab.c"
    break;

  case 211: /* common_values_expr: this_stmt  */
#line 626 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3108 "y.tab.c"
    break;

  case 212: /* common_values_expr: new_expr  */
#line 627 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3114 "y.tab.c"
    break;

  case 213: /* common_result_of_call_expr: self_inc_dec_stmt  */
#line 631 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3120 "y.tab.c"
    break;

  case 214: /* common_result_of_call_expr: call_statement  */
#line 632 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3126 "y.tab.c"
    break;

  case 215: /* common_result_of_call_expr: arithmetic_stmt  */
#line 633 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3132 "y.tab.c"
    break;

  case 216: /* common_result_of_call_expr: number_parentheses_stmt  */
#line 634 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3138 "y.tab.c"
    break;

  case 217: /* common_assignable_expr: common_others_values_expr  */
#line 638 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3144 "y.tab.c"
    break;

  case 218: /* common_number_expr: number_expr  */
#line 642 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3150 "y.tab.c"
    break;

  case 219: /* common_number_expr: common_values_expr  */
#line 643 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3156 "y.tab.c"
    break;

  case 220: /* common_number_expr: common_result_of_call_expr  */
#line 644 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3162 "y.tab.c"
    break;

  case 221: /* common_object_expr: common_values_expr  */
#line 648 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3168 "y.tab.c"
    break;

  case 222: /* common_object_expr: call_statement  */
#line 649 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3174 "y.tab.c"
    break;

  case 223: /* common_expr: common_types_expr  */
#line 658 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3180 "y.tab.c"
    break;

  case 224: /* common_expr: common_values_expr  */
#line 659 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3186 "y.tab.c"
    break;

  case 225: /* common_expr: common_result_of_call_expr  */
#line 660 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3192 "y.tab.c"
    break;

  case 226: /* common_expr: string_plus_stmt  */
#line 661 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3198 "y.tab.c"
    break;


#line 3202 "y.tab.c"

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

#line 664 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
