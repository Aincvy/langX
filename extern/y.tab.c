/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "a.y"


#include <string.h>
#include "../include/NodeCreator.h"
#include "../include/Program.h"


#line 66 "y.tab.c"

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

#include "y.tab.h"

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
  YYSYMBOL_KEY_AUTO = 25,                  /* KEY_AUTO  */
  YYSYMBOL_KEY_IF = 26,                    /* KEY_IF  */
  YYSYMBOL_KEY_ELSE = 27,                  /* KEY_ELSE  */
  YYSYMBOL_KEY_WHILE = 28,                 /* KEY_WHILE  */
  YYSYMBOL_KEY_FOR = 29,                   /* KEY_FOR  */
  YYSYMBOL_KEY_DELETE = 30,                /* KEY_DELETE  */
  YYSYMBOL_KEY_BREAK = 31,                 /* KEY_BREAK  */
  YYSYMBOL_KEY_RETURN = 32,                /* KEY_RETURN  */
  YYSYMBOL_KEY_SWITCH = 33,                /* KEY_SWITCH  */
  YYSYMBOL_KEY_CASE = 34,                  /* KEY_CASE  */
  YYSYMBOL_KEY_DEFAULT = 35,               /* KEY_DEFAULT  */
  YYSYMBOL_KEY_NULL = 36,                  /* KEY_NULL  */
  YYSYMBOL_CASE_LIST = 37,                 /* CASE_LIST  */
  YYSYMBOL_CLAXX_BODY = 38,                /* CLAXX_BODY  */
  YYSYMBOL_CLAXX_MEMBER = 39,              /* CLAXX_MEMBER  */
  YYSYMBOL_CLAXX_FUNC_CALL = 40,           /* CLAXX_FUNC_CALL  */
  YYSYMBOL_SCOPE_FUNC_CALL = 41,           /* SCOPE_FUNC_CALL  */
  YYSYMBOL_SCOPE = 42,                     /* SCOPE  */
  YYSYMBOL_LEFT_SHIFT = 43,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 44,               /* RIGHT_SHIFT  */
  YYSYMBOL_INC_OP = 45,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 46,                    /* DEC_OP  */
  YYSYMBOL_OPR_NODE_LIST = 47,             /* OPR_NODE_LIST  */
  YYSYMBOL_OPR_CHANGE_NAME_SPACE = 48,     /* OPR_CHANGE_NAME_SPACE  */
  YYSYMBOL_OPR_GET_NAME_SPACE = 49,        /* OPR_GET_NAME_SPACE  */
  YYSYMBOL_OPR_CLASS_DECLARE = 50,         /* OPR_CLASS_DECLARE  */
  YYSYMBOL_OPR_INC_DEC = 51,               /* OPR_INC_DEC  */
  YYSYMBOL_OPR_IF_ELSE = 52,               /* OPR_IF_ELSE  */
  YYSYMBOL_OPR_MULTIPLE_ID = 53,           /* OPR_MULTIPLE_ID  */
  YYSYMBOL_OPR_START_IF = 54,              /* OPR_START_IF  */
  YYSYMBOL_OPR_ARGS_LIST = 55,             /* OPR_ARGS_LIST  */
  YYSYMBOL_KEY_REQUIRE = 56,               /* KEY_REQUIRE  */
  YYSYMBOL_KEY_REQUIRE_ONCE = 57,          /* KEY_REQUIRE_ONCE  */
  YYSYMBOL_KEY_INCLUDE = 58,               /* KEY_INCLUDE  */
  YYSYMBOL_KEY_CONST = 59,                 /* KEY_CONST  */
  YYSYMBOL_KEY_LOCAL = 60,                 /* KEY_LOCAL  */
  YYSYMBOL_ADD_EQ = 61,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 62,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 63,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 64,                    /* DIV_EQ  */
  YYSYMBOL_MOD_EQ = 65,                    /* MOD_EQ  */
  YYSYMBOL_LE_OP = 66,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 67,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 68,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 69,                     /* NE_OP  */
  YYSYMBOL_70_ = 70,                       /* '>'  */
  YYSYMBOL_71_ = 71,                       /* '<'  */
  YYSYMBOL_AND_OP = 72,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 73,                     /* OR_OP  */
  YYSYMBOL_IFX = 74,                       /* IFX  */
  YYSYMBOL_ELSE = 75,                      /* ELSE  */
  YYSYMBOL_76_ = 76,                       /* ','  */
  YYSYMBOL_PIPELINE_OP = 77,               /* PIPELINE_OP  */
  YYSYMBOL_78_ = 78,                       /* '='  */
  YYSYMBOL_79_ = 79,                       /* '|'  */
  YYSYMBOL_80_ = 80,                       /* '^'  */
  YYSYMBOL_81_ = 81,                       /* '&'  */
  YYSYMBOL_82_ = 82,                       /* '+'  */
  YYSYMBOL_83_ = 83,                       /* '-'  */
  YYSYMBOL_84_ = 84,                       /* '*'  */
  YYSYMBOL_85_ = 85,                       /* '/'  */
  YYSYMBOL_86_ = 86,                       /* '%'  */
  YYSYMBOL_87_ = 87,                       /* '!'  */
  YYSYMBOL_88_ = 88,                       /* '~'  */
  YYSYMBOL_INC_OP_BACK = 89,               /* INC_OP_BACK  */
  YYSYMBOL_90_ = 90,                       /* '('  */
  YYSYMBOL_91_ = 91,                       /* ')'  */
  YYSYMBOL_92_ = 92,                       /* '['  */
  YYSYMBOL_93_ = 93,                       /* ']'  */
  YYSYMBOL_94_ = 94,                       /* '.'  */
  YYSYMBOL_PRIORITY3 = 95,                 /* PRIORITY3  */
  YYSYMBOL_PRIORITY2 = 96,                 /* PRIORITY2  */
  YYSYMBOL_PRIORITY1 = 97,                 /* PRIORITY1  */
  YYSYMBOL_UMINUS = 98,                    /* UMINUS  */
  YYSYMBOL_99_ = 99,                       /* ';'  */
  YYSYMBOL_100_ = 100,                     /* '{'  */
  YYSYMBOL_101_ = 101,                     /* '}'  */
  YYSYMBOL_102_ = 102,                     /* ':'  */
  YYSYMBOL_YYACCEPT = 103,                 /* $accept  */
  YYSYMBOL_program = 104,                  /* program  */
  YYSYMBOL_statement_list = 105,           /* statement_list  */
  YYSYMBOL_statement = 106,                /* statement  */
  YYSYMBOL__extra_nothing = 107,           /* _extra_nothing  */
  YYSYMBOL_out_declare_stmt = 108,         /* out_declare_stmt  */
  YYSYMBOL_require_stmt = 109,             /* require_stmt  */
  YYSYMBOL_require_operators = 110,        /* require_operators  */
  YYSYMBOL_try_stmt = 111,                 /* try_stmt  */
  YYSYMBOL_catch_block_stmt = 112,         /* catch_block_stmt  */
  YYSYMBOL_namespace_declare_stmt = 113,   /* namespace_declare_stmt  */
  YYSYMBOL_namespace_ref_stmt = 114,       /* namespace_ref_stmt  */
  YYSYMBOL_namespace_name_stmt = 115,      /* namespace_name_stmt  */
  YYSYMBOL_class_declare_stmt = 116,       /* class_declare_stmt  */
  YYSYMBOL_class_name_prefix = 117,        /* class_name_prefix  */
  YYSYMBOL_class_name_suffix = 118,        /* class_name_suffix  */
  YYSYMBOL_class_body = 119,               /* class_body  */
  YYSYMBOL_class_body_items = 120,         /* class_body_items  */
  YYSYMBOL_class_body_item = 121,          /* class_body_item  */
  YYSYMBOL_this_stmt = 122,                /* this_stmt  */
  YYSYMBOL_class_member_stmt = 123,        /* class_member_stmt  */
  YYSYMBOL_static_member_stmt = 124,       /* static_member_stmt  */
  YYSYMBOL_func_declare_stmt = 125,        /* func_declare_stmt  */
  YYSYMBOL_func_name_types = 126,          /* func_name_types  */
  YYSYMBOL_func_param_list = 127,          /* func_param_list  */
  YYSYMBOL_lambda_stmt = 128,              /* lambda_stmt  */
  YYSYMBOL_lambda_args_stmt = 129,         /* lambda_args_stmt  */
  YYSYMBOL_var_declare_stmt = 130,         /* var_declare_stmt  */
  YYSYMBOL_var_prefix = 131,               /* var_prefix  */
  YYSYMBOL__elements_var_declare_stmt = 132, /* _elements_var_declare_stmt  */
  YYSYMBOL_element_var_declare_stmt = 133, /* element_var_declare_stmt  */
  YYSYMBOL_con_ctl_stmt = 134,             /* con_ctl_stmt  */
  YYSYMBOL_selection_stmt = 135,           /* selection_stmt  */
  YYSYMBOL_if_stmt = 136,                  /* if_stmt  */
  YYSYMBOL_single_if_stmt = 137,           /* single_if_stmt  */
  YYSYMBOL_else_stmt = 138,                /* else_stmt  */
  YYSYMBOL_else_if_stmts = 139,            /* else_if_stmts  */
  YYSYMBOL_else_if_stmt = 140,             /* else_if_stmt  */
  YYSYMBOL_single_else_stmt = 141,         /* single_else_stmt  */
  YYSYMBOL_case_stmt_list = 142,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 143,                /* case_stmt  */
  YYSYMBOL_loop_stmt = 144,                /* loop_stmt  */
  YYSYMBOL_for_logic_stmt = 145,           /* for_logic_stmt  */
  YYSYMBOL_for_1_stmt_list = 146,          /* for_1_stmt_list  */
  YYSYMBOL_for_1_stmt = 147,               /* for_1_stmt  */
  YYSYMBOL_for_3_stmt_list = 148,          /* for_3_stmt_list  */
  YYSYMBOL_for_3_stmt = 149,               /* for_3_stmt  */
  YYSYMBOL_simple_stmt = 150,              /* simple_stmt  */
  YYSYMBOL_simple_stmt_types = 151,        /* simple_stmt_types  */
  YYSYMBOL_restrict_stmt = 152,            /* restrict_stmt  */
  YYSYMBOL_interrupt_stmt = 153,           /* interrupt_stmt  */
  YYSYMBOL_call_statement = 154,           /* call_statement  */
  YYSYMBOL_arithmetic_stmt = 155,          /* arithmetic_stmt  */
  YYSYMBOL_new_expr = 156,                 /* new_expr  */
  YYSYMBOL_args_list_with_parentheses = 157, /* args_list_with_parentheses  */
  YYSYMBOL_args_list = 158,                /* args_list  */
  YYSYMBOL_delete_expr = 159,              /* delete_expr  */
  YYSYMBOL_logic_stmt = 160,               /* logic_stmt  */
  YYSYMBOL__symbol_logic_connection = 161, /* _symbol_logic_connection  */
  YYSYMBOL_bool_param_expr = 162,          /* bool_param_expr  */
  YYSYMBOL_type_judge_stmt = 163,          /* type_judge_stmt  */
  YYSYMBOL_not_bool_param_expr = 164,      /* not_bool_param_expr  */
  YYSYMBOL_compare_expr = 165,             /* compare_expr  */
  YYSYMBOL_number_compare_expr = 166,      /* number_compare_expr  */
  YYSYMBOL_object_compare_expr = 167,      /* object_compare_expr  */
  YYSYMBOL__symbol_compare = 168,          /* _symbol_compare  */
  YYSYMBOL__symbol_equals_not = 169,       /* _symbol_equals_not  */
  YYSYMBOL_self_inc_dec_stmt = 170,        /* self_inc_dec_stmt  */
  YYSYMBOL_self_inc_dec_operators = 171,   /* self_inc_dec_operators  */
  YYSYMBOL_assign_stmt_value_eq = 172,     /* assign_stmt_value_eq  */
  YYSYMBOL_array_ele_stmt = 173,           /* array_ele_stmt  */
  YYSYMBOL_assign_stmt = 174,              /* assign_stmt  */
  YYSYMBOL_single_assign_stmt = 175,       /* single_assign_stmt  */
  YYSYMBOL_single_assign_stmt_value = 176, /* single_assign_stmt_value  */
  YYSYMBOL_number_change_assign_stmt = 177, /* number_change_assign_stmt  */
  YYSYMBOL_symbol_change_assign = 178,     /* symbol_change_assign  */
  YYSYMBOL_code_block = 179,               /* code_block  */
  YYSYMBOL_block_item_list = 180,          /* block_item_list  */
  YYSYMBOL_block_item = 181,               /* block_item  */
  YYSYMBOL_string_plus_stmt = 182,         /* string_plus_stmt  */
  YYSYMBOL_string_plus_stmt_value = 183,   /* string_plus_stmt_value  */
  YYSYMBOL_number_parentheses_stmt = 184,  /* number_parentheses_stmt  */
  YYSYMBOL_id_expr = 185,                  /* id_expr  */
  YYSYMBOL_multiple_id_expr = 186,         /* multiple_id_expr  */
  YYSYMBOL_bool_expr = 187,                /* bool_expr  */
  YYSYMBOL_number_expr = 188,              /* number_expr  */
  YYSYMBOL_positive_number_expr = 189,     /* positive_number_expr  */
  YYSYMBOL_int_expr = 190,                 /* int_expr  */
  YYSYMBOL_double_expr = 191,              /* double_expr  */
  YYSYMBOL_uminus_expr = 192,              /* uminus_expr  */
  YYSYMBOL_uminus_expr_values = 193,       /* uminus_expr_values  */
  YYSYMBOL_string_expr = 194,              /* string_expr  */
  YYSYMBOL_null_expr = 195,                /* null_expr  */
  YYSYMBOL_common_types_expr = 196,        /* common_types_expr  */
  YYSYMBOL_common_others_values_expr = 197, /* common_others_values_expr  */
  YYSYMBOL_common_values_expr = 198,       /* common_values_expr  */
  YYSYMBOL_common_result_of_call_expr = 199, /* common_result_of_call_expr  */
  YYSYMBOL_common_assignable_expr = 200,   /* common_assignable_expr  */
  YYSYMBOL_common_number_expr = 201,       /* common_number_expr  */
  YYSYMBOL_common_object_expr = 202,       /* common_object_expr  */
  YYSYMBOL_common_expr = 203               /* common_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif (!defined __cplusplus                     \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || 4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
            || (defined __apple_build_version__ \
                ? 6000000 <= __apple_build_version__ \
                : 3 < __clang_major__ + (5 <= __clang_minor__))))
   /* _Noreturn works as-is.  */
# elif 2 < __GNUC__ + (8 <= __GNUC_MINOR__) || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   875

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  341
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   334

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
       2,     2,     2,    87,     2,     2,     2,    86,    81,     2,
      90,    91,    84,    82,    76,    83,    94,    85,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,    99,
      71,    78,    70,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    92,     2,    93,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    79,   101,    88,     2,     2,     2,
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
      65,    66,    67,    68,    69,    72,    73,    74,    75,    77,
      89,    95,    96,    97,    98
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    89,    90,    93,    94,    95,    96,    97,
     101,   105,   106,   107,   108,   113,   117,   118,   119,   124,
     125,   129,   135,   140,   144,   145,   155,   159,   160,   165,
     166,   170,   171,   175,   176,   180,   181,   182,   183,   188,
     194,   199,   209,   210,   214,   215,   216,   220,   221,   226,
     230,   231,   232,   237,   238,   242,   243,   247,   248,   252,
     253,   258,   259,   264,   265,   269,   270,   274,   278,   279,
     283,   284,   288,   292,   296,   297,   301,   302,   306,   307,
     311,   312,   316,   317,   318,   323,   329,   330,   331,   336,
     337,   342,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   359,   360,   364,   365,   366,   367,   372,   373,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     393,   397,   398,   402,   403,   407,   413,   414,   415,   416,
     417,   421,   422,   427,   428,   433,   437,   442,   443,   447,
     451,   455,   456,   457,   458,   459,   460,   464,   465,   470,
     471,   475,   476,   482,   483,   484,   492,   497,   498,   502,
     506,   507,   511,   515,   516,   517,   518,   519,   524,   525,
     529,   530,   534,   535,   536,   537,   542,   543,   547,   548,
     549,   550,   551,   555,   561,   565,   566,   570,   574,   575,
     579,   580,   584,   588,   592,   596,   597,   598,   599,   603,
     607,   614,   615,   616,   617,   618,   622,   623,   624,   625,
     629,   630,   631,   635,   636,   637,   638,   642,   646,   647,
     648,   652,   653,   662,   663,   664,   665
};
#endif

#define YYPACT_NINF (-262)
#define YYTABLE_NINF (-226)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -262,    15,   514,  -262,  -262,  -262,   -71,    26,    29,  -262,
      29,  -262,    42,  -262,   -47,   -25,   -22,    29,  -262,   572,
     -21,  -262,  -262,  -262,  -262,  -262,  -262,  -262,    29,  -262,
    -262,  -262,  -262,  -262,   100,  -262,  -262,  -262,  -262,    29,
    -262,  -262,  -262,  -262,   112,  -262,    29,    51,  -262,  -262,
    -262,  -262,   114,  -262,  -262,    44,  -262,  -262,    84,    53,
    -262,  -262,   205,  -262,  -262,  -262,  -262,    16,   261,     7,
     288,   134,   364,   139,    90,    87,  -262,    97,  -262,  -262,
     581,   581,   205,  -262,   116,  -262,  -262,  -262,  -262,    39,
     670,   478,  -262,   188,    34,  -262,  -262,   124,   133,   137,
     149,    57,   116,  -262,   148,  -262,  -262,  -262,  -262,   155,
    -262,   158,  -262,   649,    22,   779,   134,  -262,   670,  -262,
    -262,   180,    30,    51,   150,    29,    14,  -262,   114,  -262,
    -262,  -262,    29,   156,   219,   252,    29,   670,   545,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,   572,   670,   670,    29,
    -262,  -262,  -262,  -262,  -262,   411,  -262,   121,   164,  -262,
      29,    29,  -262,   601,   670,   -35,  -262,  -262,  -262,  -262,
    -262,  -262,  -262,  -262,  -262,  -262,    33,   613,   179,   771,
     122,   145,   -51,  -262,  -262,    97,    29,   174,  -262,  -262,
    -262,   287,  -262,   177,  -262,  -262,  -262,    49,   727,   -71,
     100,   634,   670,   670,   670,   670,   670,   670,   670,   670,
     670,   670,   745,    29,   204,    13,   -71,  -262,  -262,  -262,
    -262,  -262,  -262,    97,  -262,   683,  -262,   104,  -262,  -262,
    -262,   199,  -262,   779,   701,  -262,  -262,  -262,    29,    87,
    -262,  -262,  -262,  -262,   -71,   581,  -262,  -262,  -262,  -262,
    -262,  -262,   670,    29,  -262,  -262,    27,   -71,   205,   581,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,  -262,
    -262,   289,   289,   789,   410,   472,   212,   212,  -262,  -262,
    -262,   207,   116,   426,  -262,  -262,   113,  -262,  -262,  -262,
     572,  -262,  -262,   189,  -262,    23,   779,  -262,    18,  -262,
    -262,  -262,  -262,   206,   201,   258,  -262,  -262,   430,  -262,
    -262,   213,   214,  -262,  -262,   -71,   129,   316,   218,    -7,
    -262,  -262,  -262,  -262,  -262,  -262,   162,  -262,  -262,  -262,
     226,   -71,  -262,  -262,   129,   -71,   -71,  -262,  -262,  -262,
    -262
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   184,    46,     0,     0,     0,   106,
       0,    39,   101,    28,     0,     0,     0,     0,   103,   104,
       0,   151,   152,    16,    17,    18,    55,    56,     0,    10,
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
    -262,  -262,  -262,  -262,     3,  -262,  -262,  -262,   327,  -262,
    -262,  -262,   171,  -262,  -262,  -262,  -262,  -262,    28,  -262,
    -262,  -262,   336,  -262,  -262,  -262,  -262,  -261,  -262,   295,
     222,   341,  -262,  -262,   228,  -262,  -262,   220,   239,  -262,
      50,  -262,  -262,  -262,   110,  -262,    46,   374,  -262,  -262,
    -262,     0,  -262,     9,   -61,  -262,  -262,   -75,  -262,   224,
    -262,  -262,  -262,  -262,  -262,  -262,  -262,    -1,   -59,  -262,
    -262,   -70,  -137,  -262,  -262,  -262,    83,  -262,   227,   184,
     190,   -15,    47,    -3,    -4,    31,   300,    85,  -262,  -262,
    -262,   -27,  -262,  -165,     1,    -2,     4,  -126,   154,    20,
    -125
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
      69,    61,    58,    68,   100,    31,   181,   120,    79,   229,
     140,    59,   184,   228,    84,     3,   162,   113,    97,     4,
     231,   232,   311,   114,     4,   258,   -44,   317,   318,    72,
      85,    78,    86,     4,    87,     4,   270,   242,   243,   116,
      14,    74,    85,    80,    86,     4,    78,   311,   259,    67,
     104,  -222,    21,    22,   140,    76,   244,    77,   136,    10,
     135,    11,   133,    88,    83,    81,   101,  -185,    82,   118,
      69,    61,    58,    68,   188,   119,   175,   175,   177,   177,
     185,    59,   133,    68,   178,   178,   121,   185,   197,   187,
     191,   300,   -59,   124,   332,   242,   243,   138,  -225,   136,
     180,   180,  -214,  -214,   285,  -153,  -153,    87,   137,   196,
      89,   176,   176,  -225,    72,   -59,  -214,   298,   140,   157,
     215,  -225,   122,   100,  -153,   186,  -222,   125,   132,   164,
      72,   100,  -153,  -185,   140,     4,   113,    97,   101,   253,
     261,   126,   114,   131,   113,    97,   312,    68,  -185,    10,
     114,    11,   -97,    69,    61,    58,    68,   231,   116,   175,
     158,   177,   288,   136,    59,   314,   116,   178,   160,   104,
     295,   312,   124,   264,    21,    22,  -222,   104,   132,   223,
     290,   161,   231,   224,   304,   101,   268,   138,   184,   186,
     254,   255,   186,   101,   176,   291,   235,   -59,   199,    69,
     265,   133,   157,   213,   313,   217,  -181,    76,   240,   220,
     282,     4,   286,   137,   148,  -180,   149,   242,   243,   200,
     -59,   116,    21,    22,  -201,    10,   148,    11,   149,   299,
    -201,  -182,   269,   260,   179,   179,   257,   201,   334,  -201,
    -179,   175,   137,   177,   195,   198,   329,  -201,   101,   178,
     132,  -155,  -155,   335,   238,   175,   185,   177,   133,    68,
      83,   136,    83,   178,   329,   180,  -222,   138,   132,  -221,
    -155,  -221,   212,   242,   243,   100,   176,   146,  -155,   180,
     315,   185,   263,   133,    68,   293,   307,   269,   113,    97,
     176,   225,   317,   318,   114,   197,   209,   210,   211,   287,
     297,   233,   234,    83,   283,   316,   185,   305,   133,    68,
     116,   307,   323,   324,    69,   328,   133,    68,   198,    85,
     331,   104,  -217,  -217,  -217,  -217,  -217,   294,   336,    35,
      67,   239,    69,   328,   133,    68,   322,   101,    43,  -217,
     301,   123,   138,    49,  -221,    83,  -221,   218,   221,   141,
     142,   143,   144,   145,   219,    67,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   146,   222,   302,   333,
       4,   207,   208,   209,   210,   211,    54,  -210,     6,  -210,
     338,  -210,   237,     9,    10,   266,    11,   241,    12,   189,
      14,   267,    15,    16,    17,    18,    19,    20,   325,   179,
       0,     0,   330,     0,     0,     0,   296,     0,     0,    21,
      22,     0,     0,   179,   337,     0,     0,     4,   339,   340,
      23,    24,    25,    26,    27,     6,     0,     0,     0,     0,
       9,    10,     4,    11,     5,    12,     4,    14,     5,    15,
      16,    17,    18,    19,    20,     0,    10,     0,    11,     0,
      10,     0,    11,   202,   203,     0,    21,    22,     0,     0,
       0,     0,     0,    29,     0,   150,     0,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,    86,     4,    26,    27,     0,     0,    26,
      27,   206,   207,   208,   209,   210,   211,     0,    10,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,   236,     0,    28,   202,   203,     0,    28,     0,
       4,     0,     5,    21,    22,    29,     0,   306,     6,    29,
       7,   321,     8,     9,    10,     0,    11,     0,    12,    13,
      14,     0,    15,    16,    17,    18,    19,    20,    85,    78,
      86,     4,    87,     0,   207,   208,   209,   210,   211,    21,
      22,    89,     0,     0,     0,    10,    90,    11,   164,   196,
      23,    24,    25,    26,    27,    85,    78,    86,     4,    87,
       0,    88,     0,     0,    85,    78,    86,     4,     0,     0,
      21,    22,    10,     0,    11,     0,     0,     0,     0,     0,
       0,    10,    28,    11,    85,    78,    86,     4,    88,     0,
       0,     0,     0,    29,     0,     0,     0,    21,    22,     0,
       0,    10,     0,    11,     0,     0,    21,    22,    89,     0,
    -221,     0,     0,    90,     0,    91,   226,    85,    78,    86,
       4,    87,     0,     0,     0,     0,    21,    22,     0,     0,
       0,     0,     0,     0,    10,    89,    11,     0,    21,    22,
      90,     0,    91,     0,    89,     0,     0,     0,   163,    90,
      88,   164,     0,    85,     0,    86,     4,     0,     0,    21,
      22,  -219,  -219,     0,    89,  -154,  -154,     0,     0,    90,
      10,   164,    11,     0,    21,    22,     0,     0,     0,     0,
       0,     0,     0,   138,  -154,  -221,     0,  -221,     0,     0,
       0,     0,  -154,     0,     0,    21,    22,    89,     0,     0,
       0,     0,     0,     0,    91,  -224,   202,   203,     0,     0,
       0,  -219,     0,     0,     0,     0,     0,     0,     0,   138,
    -224,  -221,     0,  -221,   202,   203,     0,     0,  -224,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    90,     0,
     164,     0,   204,   205,   206,   207,   208,   209,   210,   211,
     202,   203,     0,     0,     0,     0,   289,     0,     0,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   202,   203,
       0,     0,     0,     0,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,   206,   207,
     208,   209,   210,   211,   202,   203,     0,     0,   262,     0,
       0,     0,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   202,   203,     0,     0,   281,   246,   247,   248,
     249,   250,   251,     0,     0,     0,     0,     0,     0,     0,
     204,   205,   206,   207,   208,   209,   210,   211,   204,   205,
     206,   207,   208,   209,   210,   211,     0,     0,     0,   205,
     206,   207,   208,   209,   210,   211
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,    19,     2,    81,    34,    12,   146,
      69,     2,    82,   138,    17,     0,    77,    19,    19,     6,
     146,   146,   283,    19,     6,    76,    10,    34,    35,   100,
       3,     4,     5,     6,     7,     6,   201,    72,    73,    19,
      26,    15,     3,    90,     5,     6,     4,   308,    99,     2,
      19,    17,    45,    46,   113,     8,    91,    10,    42,    20,
      62,    22,    62,    36,    17,    90,    19,    10,    90,    90,
      72,    72,    72,    72,    89,    28,    80,    81,    80,    81,
      82,    72,    82,    82,    80,    81,    39,    89,    91,    89,
      89,   256,    76,    46,   101,    72,    73,    90,    76,    42,
      80,    81,    68,    69,    91,    72,    73,     7,    92,    91,
      83,    80,    81,    91,   100,    99,    82,    90,   177,    72,
      90,    99,    10,   138,    91,    76,    92,    76,    94,    90,
     100,   146,    99,    76,   193,     6,   138,   138,    91,    17,
      91,    27,   138,    99,   146,   146,   283,   146,    91,    20,
     146,    22,    99,   155,   155,   155,   155,   283,   138,   163,
      21,   163,   223,    42,   155,   290,   146,   163,    78,   138,
     245,   308,   125,   200,    45,    46,    92,   146,    94,   132,
      76,    94,   308,   136,   259,   138,   201,    90,   258,    76,
      68,    69,    76,   146,   163,    91,   149,    76,    10,   201,
     201,   201,   155,    23,    91,   122,    82,   160,   161,   126,
     213,     6,   215,    92,    92,    82,    94,    72,    73,    82,
      99,   201,    45,    46,    76,    20,    92,    22,    94,   256,
      82,    82,   201,   186,    80,    81,    91,    82,    76,    91,
      82,   245,    92,   245,    90,    91,   316,    99,   201,   245,
      94,    72,    73,    91,    90,   259,   258,   259,   258,   258,
     213,    42,   215,   259,   334,   245,    92,    90,    94,    92,
      91,    94,   118,    72,    73,   290,   245,    78,    99,   259,
      91,   283,   199,   283,   283,   238,   283,   256,   290,   290,
     259,   137,    34,    35,   290,   298,    84,    85,    86,   216,
     253,   147,   148,   256,   100,    99,   308,   100,   308,   308,
     290,   308,    99,    99,   316,   316,   316,   316,   164,     3,
     102,   290,    61,    62,    63,    64,    65,   244,   102,     2,
     283,   160,   334,   334,   334,   334,   308,   290,     2,    78,
     257,    46,    90,     2,    92,   298,    94,   125,   128,    61,
      62,    63,    64,    65,   126,   308,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    78,   128,   258,   319,
       6,    82,    83,    84,    85,    86,     2,    90,    14,    92,
     334,    94,   155,    19,    20,   201,    22,   163,    24,    89,
      26,   201,    28,    29,    30,    31,    32,    33,   315,   245,
      -1,    -1,   317,    -1,    -1,    -1,   252,    -1,    -1,    45,
      46,    -1,    -1,   259,   331,    -1,    -1,     6,   335,   336,
      56,    57,    58,    59,    60,    14,    -1,    -1,    -1,    -1,
      19,    20,     6,    22,     8,    24,     6,    26,     8,    28,
      29,    30,    31,    32,    33,    -1,    20,    -1,    22,    -1,
      20,    -1,    22,    43,    44,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    99,    -1,   101,    -1,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,     6,    59,    60,    -1,    -1,    59,
      60,    81,    82,    83,    84,    85,    86,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,   101,    -1,    88,    43,    44,    -1,    88,    -1,
       6,    -1,     8,    45,    46,    99,    -1,   101,    14,    99,
      16,   101,    18,    19,    20,    -1,    22,    -1,    24,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,     3,     4,
       5,     6,     7,    -1,    82,    83,    84,    85,    86,    45,
      46,    83,    -1,    -1,    -1,    20,    88,    22,    90,    91,
      56,    57,    58,    59,    60,     3,     4,     5,     6,     7,
      -1,    36,    -1,    -1,     3,     4,     5,     6,    -1,    -1,
      45,    46,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    88,    22,     3,     4,     5,     6,    36,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    45,    46,    -1,
      -1,    20,    -1,    22,    -1,    -1,    45,    46,    83,    -1,
      17,    -1,    -1,    88,    -1,    90,    91,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    83,    22,    -1,    45,    46,
      88,    -1,    90,    -1,    83,    -1,    -1,    -1,    87,    88,
      36,    90,    -1,     3,    -1,     5,     6,    -1,    -1,    45,
      46,    68,    69,    -1,    83,    72,    73,    -1,    -1,    88,
      20,    90,    22,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    -1,    94,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    45,    46,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    76,    43,    44,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    -1,    94,    43,    44,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,    -1,
      90,    -1,    79,    80,    81,    82,    83,    84,    85,    86,
      43,    44,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    43,    44,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    43,    44,    -1,    -1,    91,    -1,
      -1,    -1,    43,    44,    79,    80,    81,    82,    83,    84,
      85,    86,    43,    44,    -1,    -1,    91,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    80,    81,    82,    83,    84,    85,    86,    79,    80,
      81,    82,    83,    84,    85,    86,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   104,   105,     0,     6,     8,    14,    16,    18,    19,
      20,    22,    24,    25,    26,    28,    29,    30,    31,    32,
      33,    45,    46,    56,    57,    58,    59,    60,    88,    99,
     106,   107,   108,   109,   110,   111,   113,   114,   116,   117,
     122,   123,   124,   125,   126,   130,   131,   132,   133,   134,
     135,   136,   137,   144,   150,   151,   152,   153,   154,   156,
     159,   170,   171,   173,   174,   175,   177,   185,   197,   198,
     200,   202,   100,   179,    15,   115,   185,   185,     4,   187,
      90,    90,    90,   185,   186,     3,     5,     7,    36,    83,
      88,    90,   128,   129,   154,   155,   156,   170,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   194,
     195,   196,   197,   198,   199,   201,   202,   203,    90,   185,
     194,   185,    10,   132,   185,    76,    27,   138,   139,   140,
     141,    99,    94,   154,   185,   198,    42,    92,    90,   157,
     171,    61,    62,    63,    64,    65,    78,   178,    92,    94,
     101,   107,   111,   134,   150,   180,   181,   185,    21,   112,
      78,    94,   157,    87,    90,   160,   162,   163,   164,   165,
     166,   167,   170,   172,   184,   187,   188,   198,   199,   201,
     202,   160,   146,   147,   174,   198,    76,   154,   184,   189,
     193,   197,   188,   198,   199,   201,    91,   186,   201,    10,
      82,    82,    43,    44,    79,    80,    81,    82,    83,    84,
      85,    86,   201,    23,   118,    90,   127,   179,   133,   137,
     179,   140,   141,   185,   185,   201,    91,   158,   203,   175,
     176,   200,   203,   201,   201,   185,   101,   181,    90,   115,
     185,   162,    72,    73,    91,   161,    66,    67,    68,    69,
      70,    71,   168,    17,    68,    69,   169,    91,    76,    99,
     185,    91,    91,   179,   194,   170,   182,   183,   184,   188,
     196,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,    91,   186,   100,   119,    91,   186,   179,   157,    93,
      76,    91,    93,   185,   179,   160,   201,   185,    90,   194,
     196,   179,   147,   145,   160,   100,   101,   107,   120,   121,
     125,   130,   175,    91,   203,    91,    99,    34,    35,   142,
     143,   101,   121,    99,    99,   179,   148,   149,   170,   174,
     190,   102,   101,   143,    76,    91,   102,   179,   149,   179,
     179
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   105,   105,   106,   106,   106,   106,   106,
     107,   108,   108,   108,   108,   109,   110,   110,   110,   111,
     111,   112,   113,   114,   115,   115,   116,   117,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   121,   122,
     123,   124,   125,   125,   126,   126,   126,   127,   127,   128,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   134,   134,   135,   135,   136,   136,   137,   138,   138,
     139,   139,   140,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   146,   147,   148,   148,   148,   149,
     149,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   152,   152,   153,   153,   153,   153,   154,   154,   155,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     156,   157,   157,   158,   158,   159,   160,   160,   160,   160,
     160,   161,   161,   162,   162,   163,   164,   165,   165,   166,
     167,   168,   168,   168,   168,   168,   168,   169,   169,   170,
     170,   171,   171,   172,   172,   172,   173,   174,   174,   175,
     176,   176,   177,   178,   178,   178,   178,   178,   179,   179,
     180,   180,   181,   181,   181,   181,   182,   182,   183,   183,
     183,   183,   183,   184,   185,   186,   186,   187,   188,   188,
     189,   189,   190,   191,   192,   193,   193,   193,   193,   194,
     195,   196,   196,   196,   196,   196,   197,   197,   197,   197,
     198,   198,   198,   199,   199,   199,   199,   200,   201,   201,
     201,   202,   202,   203,   203,   203,   203
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


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    41,     0,     0,     0,
       0,     0,     7,     9,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    17,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    27,     0,   222,     0,   206,     0,   222,     0,   222,
       0,   222,     0,   222,     0,   213,     0,   216,     0,   206,
       0,   206,     0,   218,     0,   202,     0,   221,     0,   222,
       0,   206,     0,   221,     0,   221,     0,   222,     0,   130,
       0,   130,     0
};



YYSTYPE yylval;

int yynerrs;
int yychar;

enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;


  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

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
  "KEY_THIS", "KEY_EXTENDS", "KEY_RESTRICT", "KEY_AUTO", "KEY_IF",
  "KEY_ELSE", "KEY_WHILE", "KEY_FOR", "KEY_DELETE", "KEY_BREAK",
  "KEY_RETURN", "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT", "KEY_NULL",
  "CASE_LIST", "CLAXX_BODY", "CLAXX_MEMBER", "CLAXX_FUNC_CALL",
  "SCOPE_FUNC_CALL", "SCOPE", "LEFT_SHIFT", "RIGHT_SHIFT", "INC_OP",
  "DEC_OP", "OPR_NODE_LIST", "OPR_CHANGE_NAME_SPACE", "OPR_GET_NAME_SPACE",
  "OPR_CLASS_DECLARE", "OPR_INC_DEC", "OPR_IF_ELSE", "OPR_MULTIPLE_ID",
  "OPR_START_IF", "OPR_ARGS_LIST", "KEY_REQUIRE", "KEY_REQUIRE_ONCE",
  "KEY_INCLUDE", "KEY_CONST", "KEY_LOCAL", "ADD_EQ", "SUB_EQ", "MUL_EQ",
  "DIV_EQ", "MOD_EQ", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "'>'", "'<'",
  "AND_OP", "OR_OP", "IFX", "ELSE", "','", "PIPELINE_OP", "'='", "'|'",
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "INC_OP_BACK", "'('", "')'", "'['", "']'", "'.'", "PRIORITY3",
  "PRIORITY2", "PRIORITY1", "UMINUS", "';'", "'{'", "'}'", "':'",
  "$accept", "program", "statement_list", "statement", "_extra_nothing",
  "out_declare_stmt", "require_stmt", "require_operators", "try_stmt",
  "catch_block_stmt", "namespace_declare_stmt", "namespace_ref_stmt",
  "namespace_name_stmt", "class_declare_stmt", "class_name_prefix",
  "class_name_suffix", "class_body", "class_body_items", "class_body_item",
  "this_stmt", "class_member_stmt", "static_member_stmt",
  "func_declare_stmt", "func_name_types", "func_param_list", "lambda_stmt",
  "lambda_args_stmt", "var_declare_stmt", "var_prefix",
  "_elements_var_declare_stmt", "element_var_declare_stmt", "con_ctl_stmt",
  "selection_stmt", "if_stmt", "single_if_stmt", "else_stmt",
  "else_if_stmts", "else_if_stmt", "single_else_stmt", "case_stmt_list",
  "case_stmt", "loop_stmt", "for_logic_stmt", "for_1_stmt_list",
  "for_1_stmt", "for_3_stmt_list", "for_3_stmt", "simple_stmt",
  "simple_stmt_types", "restrict_stmt", "interrupt_stmt", "call_statement",
  "arithmetic_stmt", "new_expr", "args_list_with_parentheses", "args_list",
  "delete_expr", "logic_stmt", "_symbol_logic_connection",
  "bool_param_expr", "type_judge_stmt", "not_bool_param_expr",
  "compare_expr", "number_compare_expr", "object_compare_expr",
  "_symbol_compare", "_symbol_equals_not", "self_inc_dec_stmt",
  "self_inc_dec_operators", "assign_stmt_value_eq", "array_ele_stmt",
  "assign_stmt", "single_assign_stmt", "single_assign_stmt_value",
  "number_change_assign_stmt", "symbol_change_assign", "code_block",
  "block_item_list", "block_item", "string_plus_stmt",
  "string_plus_stmt_value", "number_parentheses_stmt", "id_expr",
  "multiple_id_expr", "bool_expr", "number_expr", "positive_number_expr",
  "int_expr", "double_expr", "uminus_expr", "uminus_expr_values",
  "string_expr", "null_expr", "common_types_expr",
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

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif



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

# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)

#endif /* !YYDEBUG */



/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp)
{
  yysymbol_kind_t yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  switch (yyn)
    {
  case 3: /* statement_list: statement_list statement  */
#line 89 "a.y"
                                  { execAndFreeNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1667 "y.tab.c"
    break;

  case 5: /* statement: _extra_nothing  */
#line 93 "a.y"
                             { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1673 "y.tab.c"
    break;

  case 6: /* statement: out_declare_stmt  */
#line 94 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1679 "y.tab.c"
    break;

  case 7: /* statement: con_ctl_stmt  */
#line 95 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1685 "y.tab.c"
    break;

  case 8: /* statement: simple_stmt  */
#line 96 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1691 "y.tab.c"
    break;

  case 9: /* statement: try_stmt  */
#line 97 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1697 "y.tab.c"
    break;

  case 10: /* _extra_nothing: ';'  */
#line 101 "a.y"
                { ((*yyvalp).node) = NULL; }
#line 1703 "y.tab.c"
    break;

  case 11: /* out_declare_stmt: func_declare_stmt  */
#line 105 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1709 "y.tab.c"
    break;

  case 12: /* out_declare_stmt: class_declare_stmt  */
#line 106 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1715 "y.tab.c"
    break;

  case 13: /* out_declare_stmt: namespace_declare_stmt  */
#line 107 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1721 "y.tab.c"
    break;

  case 14: /* out_declare_stmt: namespace_ref_stmt  */
#line 108 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1727 "y.tab.c"
    break;

  case 15: /* require_stmt: require_operators string_expr  */
#line 113 "a.y"
                                                { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue) , 1 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1733 "y.tab.c"
    break;

  case 16: /* require_operators: KEY_REQUIRE  */
#line 117 "a.y"
                              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 1739 "y.tab.c"
    break;

  case 17: /* require_operators: KEY_REQUIRE_ONCE  */
#line 118 "a.y"
                              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 1745 "y.tab.c"
    break;

  case 18: /* require_operators: KEY_INCLUDE  */
#line 119 "a.y"
                             { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 1751 "y.tab.c"
    break;

  case 19: /* try_stmt: KEY_TRY code_block  */
#line 124 "a.y"
                               { ((*yyvalp).node) = opr(KEY_TRY, 2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node),NULL); }
#line 1757 "y.tab.c"
    break;

  case 20: /* try_stmt: KEY_TRY code_block catch_block_stmt  */
#line 125 "a.y"
                                               { ((*yyvalp).node) = opr(KEY_TRY, 2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1763 "y.tab.c"
    break;

  case 21: /* catch_block_stmt: KEY_CATCH '(' id_expr ')' code_block  */
#line 129 "a.y"
                                                { ((*yyvalp).node) = opr(KEY_CATCH, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1769 "y.tab.c"
    break;

  case 22: /* namespace_declare_stmt: KEY_SET KEY_PUBLIC '=' namespace_name_stmt  */
#line 135 "a.y"
                                                     { ((*yyvalp).node) = opr(OPR_CHANGE_NAME_SPACE, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1775 "y.tab.c"
    break;

  case 23: /* namespace_ref_stmt: KEY_REF namespace_name_stmt  */
#line 140 "a.y"
                                        { ((*yyvalp).node) = opr(KEY_REF, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1781 "y.tab.c"
    break;

  case 24: /* namespace_name_stmt: id_expr  */
#line 144 "a.y"
                   { ((*yyvalp).node) = opr(OPR_GET_NAME_SPACE, 2, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1787 "y.tab.c"
    break;

  case 25: /* namespace_name_stmt: namespace_name_stmt '.' id_expr  */
#line 145 "a.y"
                                          { ((*yyvalp).node) = opr(OPR_GET_NAME_SPACE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1793 "y.tab.c"
    break;

  case 26: /* class_declare_stmt: class_name_prefix id_expr class_name_suffix class_body  */
#line 155 "a.y"
                                                                     {  ((*yyvalp).node) = opr(OPR_CLASS_DECLARE, 4, intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.iValue)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1799 "y.tab.c"
    break;

  case 27: /* class_name_prefix: %empty  */
#line 159 "a.y"
             { ((*yyvalp).iValue) = -1; }
#line 1805 "y.tab.c"
    break;

  case 28: /* class_name_prefix: KEY_AUTO  */
#line 160 "a.y"
                 { ((*yyvalp).iValue) = yytokentype::KEY_AUTO; }
#line 1811 "y.tab.c"
    break;

  case 29: /* class_name_suffix: %empty  */
#line 165 "a.y"
                              { ((*yyvalp).node) = NULL; }
#line 1817 "y.tab.c"
    break;

  case 30: /* class_name_suffix: KEY_EXTENDS multiple_id_expr  */
#line 166 "a.y"
                                        { ((*yyvalp).node) = opr(KEY_EXTENDS, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1823 "y.tab.c"
    break;

  case 31: /* class_body: '{' '}'  */
#line 170 "a.y"
                        { ((*yyvalp).node) = NULL; }
#line 1829 "y.tab.c"
    break;

  case 32: /* class_body: '{' class_body_items '}'  */
#line 171 "a.y"
                                { ((*yyvalp).node) = opr(CLAXX_BODY, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 1835 "y.tab.c"
    break;

  case 33: /* class_body_items: class_body_item  */
#line 175 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1841 "y.tab.c"
    break;

  case 34: /* class_body_items: class_body_items class_body_item  */
#line 176 "a.y"
                                        { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node) ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1847 "y.tab.c"
    break;

  case 35: /* class_body_item: var_declare_stmt ';'  */
#line 180 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1853 "y.tab.c"
    break;

  case 36: /* class_body_item: single_assign_stmt ';'  */
#line 181 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1859 "y.tab.c"
    break;

  case 37: /* class_body_item: func_declare_stmt  */
#line 182 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1865 "y.tab.c"
    break;

  case 38: /* class_body_item: _extra_nothing  */
#line 183 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1871 "y.tab.c"
    break;

  case 39: /* this_stmt: KEY_THIS  */
#line 188 "a.y"
                      { ((*yyvalp).node) = opr(KEY_THIS , 0 ); }
#line 1877 "y.tab.c"
    break;

  case 40: /* class_member_stmt: common_object_expr '.' id_expr  */
#line 194 "a.y"
                                               { ((*yyvalp).node) = opr(CLAXX_MEMBER, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1883 "y.tab.c"
    break;

  case 41: /* static_member_stmt: id_expr SCOPE id_expr  */
#line 199 "a.y"
                                  { ((*yyvalp).node) = opr(SCOPE, 2 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)) ; }
#line 1889 "y.tab.c"
    break;

  case 42: /* func_declare_stmt: func_name_types FUNC_OP code_block  */
#line 209 "a.y"
                                                        { ((*yyvalp).node) = opr(FUNC_OP,3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1895 "y.tab.c"
    break;

  case 43: /* func_declare_stmt: func_name_types FUNC_OP func_param_list code_block  */
#line 210 "a.y"
                                                                  { ((*yyvalp).node) = opr(FUNC_OP, 3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1901 "y.tab.c"
    break;

  case 44: /* func_name_types: id_expr  */
#line 214 "a.y"
               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1907 "y.tab.c"
    break;

  case 45: /* func_name_types: '~' id_expr  */
#line 215 "a.y"
                    { char buf[1024] = "~"; strcat(buf, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->var_obj->name);  ((*yyvalp).node) = varWithNameNeedFree(strdup(buf)); }
#line 1913 "y.tab.c"
    break;

  case 46: /* func_name_types: OPERATOR_X__  */
#line 216 "a.y"
                    { ((*yyvalp).node) = var((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sValue)); }
#line 1919 "y.tab.c"
    break;

  case 47: /* func_param_list: '(' ')'  */
#line 220 "a.y"
                        { ((*yyvalp).node) = NULL; }
#line 1925 "y.tab.c"
    break;

  case 48: /* func_param_list: '(' multiple_id_expr ')'  */
#line 221 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1931 "y.tab.c"
    break;

  case 49: /* lambda_stmt: lambda_args_stmt FUNC_OP code_block  */
#line 226 "a.y"
                                                { ((*yyvalp).node) = opr(FUNC_OP, 3, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1937 "y.tab.c"
    break;

  case 50: /* lambda_args_stmt: '(' ')'  */
#line 230 "a.y"
                     { ((*yyvalp).node) = NULL; }
#line 1943 "y.tab.c"
    break;

  case 51: /* lambda_args_stmt: '(' multiple_id_expr ')'  */
#line 231 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1949 "y.tab.c"
    break;

  case 52: /* lambda_args_stmt: multiple_id_expr  */
#line 232 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1955 "y.tab.c"
    break;

  case 53: /* var_declare_stmt: _elements_var_declare_stmt  */
#line 237 "a.y"
                                      { ((*yyvalp).node) = opr(VAR_DECLAR , 2, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 1961 "y.tab.c"
    break;

  case 54: /* var_declare_stmt: var_prefix _elements_var_declare_stmt  */
#line 238 "a.y"
                                                { ((*yyvalp).node) = opr(VAR_DECLAR, 2, intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 1967 "y.tab.c"
    break;

  case 55: /* var_prefix: KEY_CONST  */
#line 242 "a.y"
                 { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 1973 "y.tab.c"
    break;

  case 56: /* var_prefix: KEY_LOCAL  */
#line 243 "a.y"
                 { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 1979 "y.tab.c"
    break;

  case 57: /* _elements_var_declare_stmt: element_var_declare_stmt  */
#line 247 "a.y"
                                     { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1985 "y.tab.c"
    break;

  case 58: /* _elements_var_declare_stmt: _elements_var_declare_stmt ',' element_var_declare_stmt  */
#line 248 "a.y"
                                                             { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1991 "y.tab.c"
    break;

  case 59: /* element_var_declare_stmt: id_expr  */
#line 252 "a.y"
                                                                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1997 "y.tab.c"
    break;

  case 60: /* element_var_declare_stmt: id_expr '[' common_number_expr ']'  */
#line 253 "a.y"
                                                        { ((*yyvalp).node) = arrayNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)->var_obj->name, -1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 2003 "y.tab.c"
    break;

  case 61: /* con_ctl_stmt: selection_stmt  */
#line 258 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2009 "y.tab.c"
    break;

  case 62: /* con_ctl_stmt: loop_stmt  */
#line 259 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2015 "y.tab.c"
    break;

  case 63: /* selection_stmt: if_stmt  */
#line 264 "a.y"
                         { ((*yyvalp).node) = opr(OPR_START_IF, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2021 "y.tab.c"
    break;

  case 64: /* selection_stmt: KEY_SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  */
#line 265 "a.y"
                                                                        { ((*yyvalp).node) = opr(KEY_SWITCH, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); pretreatSwitch( ((*yyvalp).node) ) ; }
#line 2027 "y.tab.c"
    break;

  case 65: /* if_stmt: single_if_stmt  */
#line 269 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2033 "y.tab.c"
    break;

  case 66: /* if_stmt: single_if_stmt else_stmt  */
#line 270 "a.y"
                             { ((*yyvalp).node) = opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2039 "y.tab.c"
    break;

  case 67: /* single_if_stmt: KEY_IF '(' logic_stmt ')' code_block  */
#line 274 "a.y"
                                         { ((*yyvalp).node) = opr(KEY_IF ,2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)) ; }
#line 2045 "y.tab.c"
    break;

  case 68: /* else_stmt: else_if_stmts single_else_stmt  */
#line 278 "a.y"
                                      { ((*yyvalp).node) =  opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2051 "y.tab.c"
    break;

  case 69: /* else_stmt: single_else_stmt  */
#line 279 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2057 "y.tab.c"
    break;

  case 70: /* else_if_stmts: else_if_stmt  */
#line 283 "a.y"
                        { ((*yyvalp).node) = opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 2063 "y.tab.c"
    break;

  case 71: /* else_if_stmts: else_if_stmts else_if_stmt  */
#line 284 "a.y"
                                  { ((*yyvalp).node) =  opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2069 "y.tab.c"
    break;

  case 72: /* else_if_stmt: KEY_ELSE single_if_stmt  */
#line 288 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2075 "y.tab.c"
    break;

  case 73: /* single_else_stmt: KEY_ELSE code_block  */
#line 292 "a.y"
                            { ((*yyvalp).node) = opr( KEY_ELSE, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2081 "y.tab.c"
    break;

  case 74: /* case_stmt_list: case_stmt  */
#line 296 "a.y"
                               { ((*yyvalp).node) = opr(CASE_LIST , 1 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2087 "y.tab.c"
    break;

  case 75: /* case_stmt_list: case_stmt_list case_stmt  */
#line 297 "a.y"
                                   { ((*yyvalp).node) = opr(CASE_LIST , 2 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2093 "y.tab.c"
    break;

  case 76: /* case_stmt: KEY_CASE int_expr ':' code_block  */
#line 301 "a.y"
                                                  { ((*yyvalp).node) = opr(KEY_CASE, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2099 "y.tab.c"
    break;

  case 77: /* case_stmt: KEY_DEFAULT ':' code_block  */
#line 302 "a.y"
                                                     { ((*yyvalp).node) = opr(KEY_DEFAULT , 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2105 "y.tab.c"
    break;

  case 78: /* loop_stmt: KEY_WHILE '(' logic_stmt ')' code_block  */
#line 306 "a.y"
                                                  { ((*yyvalp).node) = opr(KEY_WHILE , 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2111 "y.tab.c"
    break;

  case 79: /* loop_stmt: KEY_FOR '(' for_1_stmt_list ';' for_logic_stmt ';' for_3_stmt_list ')' code_block  */
#line 307 "a.y"
                                                                                            { ((*yyvalp).node) = opr(KEY_FOR,4,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2117 "y.tab.c"
    break;

  case 80: /* for_logic_stmt: %empty  */
#line 311 "a.y"
          { ((*yyvalp).node) = intNode(1);  }
#line 2123 "y.tab.c"
    break;

  case 81: /* for_logic_stmt: logic_stmt  */
#line 312 "a.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2129 "y.tab.c"
    break;

  case 82: /* for_1_stmt_list: %empty  */
#line 316 "a.y"
         { ((*yyvalp).node) = NULL ; }
#line 2135 "y.tab.c"
    break;

  case 83: /* for_1_stmt_list: for_1_stmt  */
#line 317 "a.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2141 "y.tab.c"
    break;

  case 84: /* for_1_stmt_list: for_1_stmt_list ',' for_1_stmt  */
#line 318 "a.y"
                                      { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2147 "y.tab.c"
    break;

  case 85: /* for_1_stmt: assign_stmt  */
#line 323 "a.y"
                       { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2153 "y.tab.c"
    break;

  case 86: /* for_3_stmt_list: %empty  */
#line 329 "a.y"
         { ((*yyvalp).node) = NULL ; }
#line 2159 "y.tab.c"
    break;

  case 87: /* for_3_stmt_list: for_3_stmt  */
#line 330 "a.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2165 "y.tab.c"
    break;

  case 88: /* for_3_stmt_list: for_3_stmt_list ',' for_3_stmt  */
#line 331 "a.y"
                                      { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2171 "y.tab.c"
    break;

  case 89: /* for_3_stmt: assign_stmt  */
#line 336 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2177 "y.tab.c"
    break;

  case 90: /* for_3_stmt: self_inc_dec_stmt  */
#line 337 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2183 "y.tab.c"
    break;

  case 91: /* simple_stmt: simple_stmt_types ';'  */
#line 342 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2189 "y.tab.c"
    break;

  case 92: /* simple_stmt_types: self_inc_dec_stmt  */
#line 346 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2195 "y.tab.c"
    break;

  case 93: /* simple_stmt_types: assign_stmt  */
#line 347 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2201 "y.tab.c"
    break;

  case 94: /* simple_stmt_types: call_statement  */
#line 348 "a.y"
                                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2207 "y.tab.c"
    break;

  case 95: /* simple_stmt_types: delete_expr  */
#line 349 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2213 "y.tab.c"
    break;

  case 96: /* simple_stmt_types: interrupt_stmt  */
#line 350 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2219 "y.tab.c"
    break;

  case 97: /* simple_stmt_types: new_expr  */
#line 351 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2225 "y.tab.c"
    break;

  case 98: /* simple_stmt_types: restrict_stmt  */
#line 352 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2231 "y.tab.c"
    break;

  case 99: /* simple_stmt_types: require_stmt  */
#line 353 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2237 "y.tab.c"
    break;

  case 100: /* simple_stmt_types: var_declare_stmt  */
#line 354 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2243 "y.tab.c"
    break;

  case 101: /* restrict_stmt: KEY_RESTRICT  */
#line 359 "a.y"
                             { ((*yyvalp).node) = opr(KEY_RESTRICT,0);}
#line 2249 "y.tab.c"
    break;

  case 102: /* restrict_stmt: KEY_RESTRICT bool_expr  */
#line 360 "a.y"
                                  { ((*yyvalp).node) = opr(KEY_RESTRICT,1,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2255 "y.tab.c"
    break;

  case 103: /* interrupt_stmt: KEY_BREAK  */
#line 364 "a.y"
                    { ((*yyvalp).node) = opr(KEY_BREAK, 0); }
#line 2261 "y.tab.c"
    break;

  case 104: /* interrupt_stmt: KEY_RETURN  */
#line 365 "a.y"
                     { ((*yyvalp).node) = opr(KEY_RETURN , 0); }
#line 2267 "y.tab.c"
    break;

  case 105: /* interrupt_stmt: KEY_RETURN common_expr  */
#line 366 "a.y"
                                 { ((*yyvalp).node) = opr(KEY_RETURN , 1 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));}
#line 2273 "y.tab.c"
    break;

  case 106: /* interrupt_stmt: KEY_CONTINUE  */
#line 367 "a.y"
                   { ((*yyvalp).node) = opr(KEY_CONTINUE,0); }
#line 2279 "y.tab.c"
    break;

  case 107: /* call_statement: common_values_expr args_list_with_parentheses  */
#line 372 "a.y"
                                                                        { ((*yyvalp).node) = opr(FUNC_CALL, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2285 "y.tab.c"
    break;

  case 108: /* call_statement: call_statement '.' id_expr args_list_with_parentheses  */
#line 373 "a.y"
                                                                             { ((*yyvalp).node) = opr(CLAXX_FUNC_CALL, 3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2291 "y.tab.c"
    break;

  case 109: /* arithmetic_stmt: common_number_expr '+' common_number_expr  */
#line 378 "a.y"
                                                    { ((*yyvalp).node) = opr('+',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2297 "y.tab.c"
    break;

  case 110: /* arithmetic_stmt: common_number_expr '-' common_number_expr  */
#line 379 "a.y"
                                                    { ((*yyvalp).node) = opr('-',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2303 "y.tab.c"
    break;

  case 111: /* arithmetic_stmt: common_number_expr '*' common_number_expr  */
#line 380 "a.y"
                                                    { ((*yyvalp).node) = opr('*',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2309 "y.tab.c"
    break;

  case 112: /* arithmetic_stmt: common_number_expr '/' common_number_expr  */
#line 381 "a.y"
                                                    { ((*yyvalp).node) = opr('/',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2315 "y.tab.c"
    break;

  case 113: /* arithmetic_stmt: common_number_expr '%' common_number_expr  */
#line 382 "a.y"
                                                    { ((*yyvalp).node) = opr('%',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2321 "y.tab.c"
    break;

  case 114: /* arithmetic_stmt: common_number_expr '&' common_number_expr  */
#line 383 "a.y"
                                                     { ((*yyvalp).node) = opr('&',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2327 "y.tab.c"
    break;

  case 115: /* arithmetic_stmt: common_number_expr '|' common_number_expr  */
#line 384 "a.y"
                                                     { ((*yyvalp).node) = opr('|',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2333 "y.tab.c"
    break;

  case 116: /* arithmetic_stmt: common_number_expr '^' common_number_expr  */
#line 385 "a.y"
                                                     { ((*yyvalp).node) = opr('^',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2339 "y.tab.c"
    break;

  case 117: /* arithmetic_stmt: common_number_expr LEFT_SHIFT common_number_expr  */
#line 386 "a.y"
                                                            { ((*yyvalp).node) = opr(LEFT_SHIFT,2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2345 "y.tab.c"
    break;

  case 118: /* arithmetic_stmt: common_number_expr RIGHT_SHIFT common_number_expr  */
#line 387 "a.y"
                                                             { ((*yyvalp).node) = opr(RIGHT_SHIFT,2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2351 "y.tab.c"
    break;

  case 119: /* arithmetic_stmt: '~' common_number_expr  */
#line 388 "a.y"
                              { ((*yyvalp).node) = opr('~',1,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2357 "y.tab.c"
    break;

  case 120: /* new_expr: KEY_NEW id_expr args_list_with_parentheses  */
#line 393 "a.y"
                                                     { ((*yyvalp).node) = opr(KEY_NEW, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2363 "y.tab.c"
    break;

  case 121: /* args_list_with_parentheses: '(' ')'  */
#line 397 "a.y"
                  { ((*yyvalp).node) = NULL; }
#line 2369 "y.tab.c"
    break;

  case 122: /* args_list_with_parentheses: '(' args_list ')'  */
#line 398 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2375 "y.tab.c"
    break;

  case 123: /* args_list: common_expr  */
#line 402 "a.y"
                    { ((*yyvalp).node) = opr(OPR_ARGS_LIST, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2381 "y.tab.c"
    break;

  case 124: /* args_list: args_list ',' common_expr  */
#line 403 "a.y"
                               { ((*yyvalp).node) = opr(OPR_ARGS_LIST, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2387 "y.tab.c"
    break;

  case 125: /* delete_expr: KEY_DELETE multiple_id_expr  */
#line 407 "a.y"
                                  { ((*yyvalp).node) = opr(KEY_DELETE, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2393 "y.tab.c"
    break;

  case 126: /* logic_stmt: bool_param_expr  */
#line 413 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2399 "y.tab.c"
    break;

  case 127: /* logic_stmt: not_bool_param_expr  */
#line 414 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2405 "y.tab.c"
    break;

  case 128: /* logic_stmt: type_judge_stmt  */
#line 415 "a.y"
                                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2411 "y.tab.c"
    break;

  case 129: /* logic_stmt: compare_expr  */
#line 416 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2417 "y.tab.c"
    break;

  case 130: /* logic_stmt: logic_stmt _symbol_logic_connection logic_stmt  */
#line 417 "a.y"
                                                        { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2423 "y.tab.c"
    break;

  case 131: /* _symbol_logic_connection: AND_OP  */
#line 421 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2429 "y.tab.c"
    break;

  case 132: /* _symbol_logic_connection: OR_OP  */
#line 422 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2435 "y.tab.c"
    break;

  case 133: /* bool_param_expr: assign_stmt_value_eq  */
#line 427 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2441 "y.tab.c"
    break;

  case 134: /* bool_param_expr: bool_expr  */
#line 428 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2447 "y.tab.c"
    break;

  case 135: /* type_judge_stmt: common_object_expr KEY_IS id_expr  */
#line 433 "a.y"
                                             { ((*yyvalp).node) = opr(KEY_IS ,2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2453 "y.tab.c"
    break;

  case 136: /* not_bool_param_expr: '!' bool_param_expr  */
#line 437 "a.y"
                          { ((*yyvalp).node) = opr('!', 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2459 "y.tab.c"
    break;

  case 137: /* compare_expr: number_compare_expr  */
#line 442 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2465 "y.tab.c"
    break;

  case 138: /* compare_expr: object_compare_expr  */
#line 443 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2471 "y.tab.c"
    break;

  case 139: /* number_compare_expr: common_number_expr _symbol_compare common_number_expr  */
#line 447 "a.y"
                                                          { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2477 "y.tab.c"
    break;

  case 140: /* object_compare_expr: common_object_expr _symbol_equals_not common_types_expr  */
#line 451 "a.y"
                                                             { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2483 "y.tab.c"
    break;

  case 141: /* _symbol_compare: '>'  */
#line 455 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2489 "y.tab.c"
    break;

  case 142: /* _symbol_compare: '<'  */
#line 456 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2495 "y.tab.c"
    break;

  case 143: /* _symbol_compare: GE_OP  */
#line 457 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2501 "y.tab.c"
    break;

  case 144: /* _symbol_compare: LE_OP  */
#line 458 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2507 "y.tab.c"
    break;

  case 145: /* _symbol_compare: NE_OP  */
#line 459 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2513 "y.tab.c"
    break;

  case 146: /* _symbol_compare: EQ_OP  */
#line 460 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2519 "y.tab.c"
    break;

  case 147: /* _symbol_equals_not: NE_OP  */
#line 464 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2525 "y.tab.c"
    break;

  case 148: /* _symbol_equals_not: EQ_OP  */
#line 465 "a.y"
              { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2531 "y.tab.c"
    break;

  case 149: /* self_inc_dec_stmt: self_inc_dec_operators common_values_expr  */
#line 470 "a.y"
                                                    { ((*yyvalp).node) = opr(OPR_INC_DEC,2, intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2537 "y.tab.c"
    break;

  case 150: /* self_inc_dec_stmt: common_values_expr self_inc_dec_operators  */
#line 471 "a.y"
                                                                       { ((*yyvalp).node) = opr(OPR_INC_DEC, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue))); }
#line 2543 "y.tab.c"
    break;

  case 151: /* self_inc_dec_operators: INC_OP  */
#line 475 "a.y"
                  { ((*yyvalp).iValue) = yytokentype::INC_OP; }
#line 2549 "y.tab.c"
    break;

  case 152: /* self_inc_dec_operators: DEC_OP  */
#line 476 "a.y"
                  { ((*yyvalp).iValue) = yytokentype::DEC_OP; }
#line 2555 "y.tab.c"
    break;

  case 153: /* assign_stmt_value_eq: number_expr  */
#line 482 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2561 "y.tab.c"
    break;

  case 154: /* assign_stmt_value_eq: common_values_expr  */
#line 483 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2567 "y.tab.c"
    break;

  case 155: /* assign_stmt_value_eq: common_result_of_call_expr  */
#line 484 "a.y"
                                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2573 "y.tab.c"
    break;

  case 156: /* array_ele_stmt: common_object_expr '[' common_number_expr ']'  */
#line 492 "a.y"
                                                         { ((*yyvalp).node) = objectArrayElementNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), -1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 2579 "y.tab.c"
    break;

  case 157: /* assign_stmt: single_assign_stmt  */
#line 497 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2585 "y.tab.c"
    break;

  case 158: /* assign_stmt: number_change_assign_stmt  */
#line 498 "a.y"
                                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ;}
#line 2591 "y.tab.c"
    break;

  case 159: /* single_assign_stmt: common_assignable_expr '=' single_assign_stmt_value  */
#line 502 "a.y"
                                                              { ((*yyvalp).node) = opr('=',2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2597 "y.tab.c"
    break;

  case 160: /* single_assign_stmt_value: common_expr  */
#line 506 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2603 "y.tab.c"
    break;

  case 161: /* single_assign_stmt_value: single_assign_stmt  */
#line 507 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2609 "y.tab.c"
    break;

  case 162: /* number_change_assign_stmt: common_assignable_expr symbol_change_assign common_number_expr  */
#line 511 "a.y"
                                                                    { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2615 "y.tab.c"
    break;

  case 163: /* symbol_change_assign: ADD_EQ  */
#line 515 "a.y"
                { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2621 "y.tab.c"
    break;

  case 164: /* symbol_change_assign: SUB_EQ  */
#line 516 "a.y"
                { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2627 "y.tab.c"
    break;

  case 165: /* symbol_change_assign: MUL_EQ  */
#line 517 "a.y"
                { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2633 "y.tab.c"
    break;

  case 166: /* symbol_change_assign: DIV_EQ  */
#line 518 "a.y"
                { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2639 "y.tab.c"
    break;

  case 167: /* symbol_change_assign: MOD_EQ  */
#line 519 "a.y"
                { ((*yyvalp).iValue) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue); }
#line 2645 "y.tab.c"
    break;

  case 168: /* code_block: '{' '}'  */
#line 524 "a.y"
                    { ((*yyvalp).node) = NULL; }
#line 2651 "y.tab.c"
    break;

  case 169: /* code_block: '{' block_item_list '}'  */
#line 525 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2657 "y.tab.c"
    break;

  case 170: /* block_item_list: block_item  */
#line 529 "a.y"
                                    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2663 "y.tab.c"
    break;

  case 171: /* block_item_list: block_item_list block_item  */
#line 530 "a.y"
                                    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2669 "y.tab.c"
    break;

  case 172: /* block_item: try_stmt  */
#line 534 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2675 "y.tab.c"
    break;

  case 173: /* block_item: simple_stmt  */
#line 535 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2681 "y.tab.c"
    break;

  case 174: /* block_item: con_ctl_stmt  */
#line 536 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2687 "y.tab.c"
    break;

  case 175: /* block_item: _extra_nothing  */
#line 537 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2693 "y.tab.c"
    break;

  case 176: /* string_plus_stmt: string_expr '+' string_plus_stmt_value  */
#line 542 "a.y"
                                              { ((*yyvalp).node) = opr('+', 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2699 "y.tab.c"
    break;

  case 177: /* string_plus_stmt: string_plus_stmt_value '+' string_expr  */
#line 543 "a.y"
                                              { ((*yyvalp).node) = opr('+', 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2705 "y.tab.c"
    break;

  case 178: /* string_plus_stmt_value: common_object_expr  */
#line 547 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2711 "y.tab.c"
    break;

  case 179: /* string_plus_stmt_value: common_types_expr  */
#line 548 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2717 "y.tab.c"
    break;

  case 180: /* string_plus_stmt_value: string_plus_stmt  */
#line 549 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2723 "y.tab.c"
    break;

  case 181: /* string_plus_stmt_value: self_inc_dec_stmt  */
#line 550 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2729 "y.tab.c"
    break;

  case 182: /* string_plus_stmt_value: number_parentheses_stmt  */
#line 551 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2735 "y.tab.c"
    break;

  case 183: /* number_parentheses_stmt: '(' common_number_expr ')'  */
#line 555 "a.y"
                                   { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2741 "y.tab.c"
    break;

  case 184: /* id_expr: IDENTIFIER  */
#line 561 "a.y"
                     { ((*yyvalp).node) = var((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sValue)); }
#line 2747 "y.tab.c"
    break;

  case 185: /* multiple_id_expr: id_expr  */
#line 565 "a.y"
                    { ((*yyvalp).node) = opr(OPR_MULTIPLE_ID , 1 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) );}
#line 2753 "y.tab.c"
    break;

  case 186: /* multiple_id_expr: multiple_id_expr ',' id_expr  */
#line 566 "a.y"
                                   { ((*yyvalp).node) = opr(OPR_MULTIPLE_ID , 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2759 "y.tab.c"
    break;

  case 187: /* bool_expr: TBOOL  */
#line 570 "a.y"
                  { ((*yyvalp).node) = intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue)); }
#line 2765 "y.tab.c"
    break;

  case 188: /* number_expr: positive_number_expr  */
#line 574 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2771 "y.tab.c"
    break;

  case 189: /* number_expr: uminus_expr  */
#line 575 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2777 "y.tab.c"
    break;

  case 190: /* positive_number_expr: double_expr  */
#line 579 "a.y"
                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2783 "y.tab.c"
    break;

  case 191: /* positive_number_expr: int_expr  */
#line 580 "a.y"
                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2789 "y.tab.c"
    break;

  case 192: /* int_expr: TINTEGER  */
#line 584 "a.y"
             { ((*yyvalp).node) = intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue)); }
#line 2795 "y.tab.c"
    break;

  case 193: /* double_expr: TDOUBLE  */
#line 588 "a.y"
                  { ((*yyvalp).node) = number((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.dValue)); }
#line 2801 "y.tab.c"
    break;

  case 194: /* uminus_expr: '-' uminus_expr_values  */
#line 592 "a.y"
                                              { ((*yyvalp).node) = opr(UMINUS, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2807 "y.tab.c"
    break;

  case 195: /* uminus_expr_values: positive_number_expr  */
#line 596 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2813 "y.tab.c"
    break;

  case 196: /* uminus_expr_values: common_others_values_expr  */
#line 597 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2819 "y.tab.c"
    break;

  case 197: /* uminus_expr_values: call_statement  */
#line 598 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2825 "y.tab.c"
    break;

  case 198: /* uminus_expr_values: number_parentheses_stmt  */
#line 599 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2831 "y.tab.c"
    break;

  case 199: /* string_expr: TSTRING  */
#line 603 "a.y"
                   { ((*yyvalp).node) = string((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sValue)); }
#line 2837 "y.tab.c"
    break;

  case 200: /* null_expr: KEY_NULL  */
#line 607 "a.y"
                     { ((*yyvalp).node) = xnull(); }
#line 2843 "y.tab.c"
    break;

  case 201: /* common_types_expr: number_expr  */
#line 614 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2849 "y.tab.c"
    break;

  case 202: /* common_types_expr: string_expr  */
#line 615 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2855 "y.tab.c"
    break;

  case 203: /* common_types_expr: null_expr  */
#line 616 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2861 "y.tab.c"
    break;

  case 204: /* common_types_expr: lambda_stmt  */
#line 617 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2867 "y.tab.c"
    break;

  case 205: /* common_types_expr: bool_expr  */
#line 618 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2873 "y.tab.c"
    break;

  case 206: /* common_others_values_expr: id_expr  */
#line 622 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2879 "y.tab.c"
    break;

  case 207: /* common_others_values_expr: array_ele_stmt  */
#line 623 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2885 "y.tab.c"
    break;

  case 208: /* common_others_values_expr: class_member_stmt  */
#line 624 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2891 "y.tab.c"
    break;

  case 209: /* common_others_values_expr: static_member_stmt  */
#line 625 "a.y"
                       { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2897 "y.tab.c"
    break;

  case 210: /* common_values_expr: common_others_values_expr  */
#line 629 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2903 "y.tab.c"
    break;

  case 211: /* common_values_expr: this_stmt  */
#line 630 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2909 "y.tab.c"
    break;

  case 212: /* common_values_expr: new_expr  */
#line 631 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2915 "y.tab.c"
    break;

  case 213: /* common_result_of_call_expr: self_inc_dec_stmt  */
#line 635 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2921 "y.tab.c"
    break;

  case 214: /* common_result_of_call_expr: call_statement  */
#line 636 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2927 "y.tab.c"
    break;

  case 215: /* common_result_of_call_expr: arithmetic_stmt  */
#line 637 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2933 "y.tab.c"
    break;

  case 216: /* common_result_of_call_expr: number_parentheses_stmt  */
#line 638 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2939 "y.tab.c"
    break;

  case 217: /* common_assignable_expr: common_others_values_expr  */
#line 642 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2945 "y.tab.c"
    break;

  case 218: /* common_number_expr: number_expr  */
#line 646 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2951 "y.tab.c"
    break;

  case 219: /* common_number_expr: common_values_expr  */
#line 647 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2957 "y.tab.c"
    break;

  case 220: /* common_number_expr: common_result_of_call_expr  */
#line 648 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2963 "y.tab.c"
    break;

  case 221: /* common_object_expr: common_values_expr  */
#line 652 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2969 "y.tab.c"
    break;

  case 222: /* common_object_expr: call_statement  */
#line 653 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2975 "y.tab.c"
    break;

  case 223: /* common_expr: common_types_expr  */
#line 662 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2981 "y.tab.c"
    break;

  case 224: /* common_expr: common_values_expr  */
#line 663 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2987 "y.tab.c"
    break;

  case 225: /* common_expr: common_result_of_call_expr  */
#line 664 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2993 "y.tab.c"
    break;

  case 226: /* common_expr: string_plus_stmt  */
#line 665 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2999 "y.tab.c"
    break;


#line 3003 "y.tab.c"

      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

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

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yysval);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == YYSYMBOL_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp);
    yychar = yychar_current;
    yylval = yylval_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yysval);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}






static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
  yyerror (YY_("syntax error"));
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYSYMBOL_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYSYMBOL_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval);
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs




#line 668 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
