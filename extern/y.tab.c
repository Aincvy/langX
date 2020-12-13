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
  YYSYMBOL_FUNC_OP = 9,                    /* FUNC_OP  */
  YYSYMBOL_FUNC_CALL = 10,                 /* FUNC_CALL  */
  YYSYMBOL_VAR_DECLARE = 11,               /* VAR_DECLARE  */
  YYSYMBOL_ARRAY_ELE = 12,                 /* ARRAY_ELE  */
  YYSYMBOL_KEY_TRY = 13,                   /* KEY_TRY  */
  YYSYMBOL_KEY_PUBLIC = 14,                /* KEY_PUBLIC  */
  YYSYMBOL_KEY_SET = 15,                   /* KEY_SET  */
  YYSYMBOL_KEY_IS = 16,                    /* KEY_IS  */
  YYSYMBOL_KEY_REF = 17,                   /* KEY_REF  */
  YYSYMBOL_KEY_CONTINUE = 18,              /* KEY_CONTINUE  */
  YYSYMBOL_KEY_NEW = 19,                   /* KEY_NEW  */
  YYSYMBOL_KEY_CATCH = 20,                 /* KEY_CATCH  */
  YYSYMBOL_KEY_THIS = 21,                  /* KEY_THIS  */
  YYSYMBOL_KEY_EXTENDS = 22,               /* KEY_EXTENDS  */
  YYSYMBOL_KEY_RESTRICT = 23,              /* KEY_RESTRICT  */
  YYSYMBOL_KEY_AUTO = 24,                  /* KEY_AUTO  */
  YYSYMBOL_KEY_CONST = 25,                 /* KEY_CONST  */
  YYSYMBOL_KEY_LOCAL = 26,                 /* KEY_LOCAL  */
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
  YYSYMBOL_ADD_EQ = 59,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 60,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 61,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 62,                    /* DIV_EQ  */
  YYSYMBOL_MOD_EQ = 63,                    /* MOD_EQ  */
  YYSYMBOL_LE_OP = 64,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 65,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 66,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 67,                     /* NE_OP  */
  YYSYMBOL_68_ = 68,                       /* '>'  */
  YYSYMBOL_69_ = 69,                       /* '<'  */
  YYSYMBOL_AND_OP = 70,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 71,                     /* OR_OP  */
  YYSYMBOL_72_ = 72,                       /* ','  */
  YYSYMBOL_PIPELINE_OP = 73,               /* PIPELINE_OP  */
  YYSYMBOL_74_ = 74,                       /* '='  */
  YYSYMBOL_75_ = 75,                       /* '|'  */
  YYSYMBOL_76_ = 76,                       /* '^'  */
  YYSYMBOL_77_ = 77,                       /* '&'  */
  YYSYMBOL_78_ = 78,                       /* '+'  */
  YYSYMBOL_79_ = 79,                       /* '-'  */
  YYSYMBOL_80_ = 80,                       /* '*'  */
  YYSYMBOL_81_ = 81,                       /* '/'  */
  YYSYMBOL_82_ = 82,                       /* '%'  */
  YYSYMBOL_83_ = 83,                       /* '!'  */
  YYSYMBOL_84_ = 84,                       /* '~'  */
  YYSYMBOL_INC_OP_BACK = 85,               /* INC_OP_BACK  */
  YYSYMBOL_86_ = 86,                       /* '('  */
  YYSYMBOL_87_ = 87,                       /* ')'  */
  YYSYMBOL_88_ = 88,                       /* '['  */
  YYSYMBOL_89_ = 89,                       /* ']'  */
  YYSYMBOL_90_ = 90,                       /* '.'  */
  YYSYMBOL_UMINUS = 91,                    /* UMINUS  */
  YYSYMBOL_92_ = 92,                       /* ';'  */
  YYSYMBOL_93_ = 93,                       /* '{'  */
  YYSYMBOL_94_ = 94,                       /* '}'  */
  YYSYMBOL_95_ = 95,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 96,                  /* $accept  */
  YYSYMBOL_program = 97,                   /* program  */
  YYSYMBOL_statement_list = 98,            /* statement_list  */
  YYSYMBOL_statement = 99,                 /* statement  */
  YYSYMBOL__extra_nothing = 100,           /* _extra_nothing  */
  YYSYMBOL_out_declare_stmt = 101,         /* out_declare_stmt  */
  YYSYMBOL_try_stmt = 102,                 /* try_stmt  */
  YYSYMBOL_catch_block_stmt = 103,         /* catch_block_stmt  */
  YYSYMBOL_namespace_declare_stmt = 104,   /* namespace_declare_stmt  */
  YYSYMBOL_namespace_ref_stmt = 105,       /* namespace_ref_stmt  */
  YYSYMBOL_namespace_name_stmt = 106,      /* namespace_name_stmt  */
  YYSYMBOL_class_declare_stmt = 107,       /* class_declare_stmt  */
  YYSYMBOL_class_name_prefix = 108,        /* class_name_prefix  */
  YYSYMBOL_class_name_suffix = 109,        /* class_name_suffix  */
  YYSYMBOL_class_body = 110,               /* class_body  */
  YYSYMBOL_class_body_items = 111,         /* class_body_items  */
  YYSYMBOL_class_body_item = 112,          /* class_body_item  */
  YYSYMBOL_this_stmt = 113,                /* this_stmt  */
  YYSYMBOL_class_member_stmt = 114,        /* class_member_stmt  */
  YYSYMBOL_static_member_stmt = 115,       /* static_member_stmt  */
  YYSYMBOL_func_declare_stmt = 116,        /* func_declare_stmt  */
  YYSYMBOL_func_name_types = 117,          /* func_name_types  */
  YYSYMBOL_func_param_list = 118,          /* func_param_list  */
  YYSYMBOL_lambda_stmt = 119,              /* lambda_stmt  */
  YYSYMBOL_lambda_args_stmt = 120,         /* lambda_args_stmt  */
  YYSYMBOL_var_declare_stmt = 121,         /* var_declare_stmt  */
  YYSYMBOL_var_prefix = 122,               /* var_prefix  */
  YYSYMBOL__elements_var_declare_stmt = 123, /* _elements_var_declare_stmt  */
  YYSYMBOL_element_var_declare_stmt = 124, /* element_var_declare_stmt  */
  YYSYMBOL__var_declare_stmt_with_assign_list = 125, /* _var_declare_stmt_with_assign_list  */
  YYSYMBOL__var_declare_stmt_with_assign = 126, /* _var_declare_stmt_with_assign  */
  YYSYMBOL_con_ctl_stmt = 127,             /* con_ctl_stmt  */
  YYSYMBOL_selection_stmt = 128,           /* selection_stmt  */
  YYSYMBOL_if_stmt = 129,                  /* if_stmt  */
  YYSYMBOL_single_if_stmt = 130,           /* single_if_stmt  */
  YYSYMBOL_else_stmt = 131,                /* else_stmt  */
  YYSYMBOL_else_if_stmts = 132,            /* else_if_stmts  */
  YYSYMBOL_else_if_stmt = 133,             /* else_if_stmt  */
  YYSYMBOL_single_else_stmt = 134,         /* single_else_stmt  */
  YYSYMBOL_case_stmt_list = 135,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 136,                /* case_stmt  */
  YYSYMBOL_loop_stmt = 137,                /* loop_stmt  */
  YYSYMBOL_for_logic_stmt = 138,           /* for_logic_stmt  */
  YYSYMBOL_for_1_stmt_list = 139,          /* for_1_stmt_list  */
  YYSYMBOL_for_1_stmt = 140,               /* for_1_stmt  */
  YYSYMBOL_for_3_stmt_list = 141,          /* for_3_stmt_list  */
  YYSYMBOL_for_3_stmt = 142,               /* for_3_stmt  */
  YYSYMBOL_simple_stmt = 143,              /* simple_stmt  */
  YYSYMBOL_simple_stmt_types = 144,        /* simple_stmt_types  */
  YYSYMBOL_restrict_stmt = 145,            /* restrict_stmt  */
  YYSYMBOL_interrupt_stmt = 146,           /* interrupt_stmt  */
  YYSYMBOL_call_statement = 147,           /* call_statement  */
  YYSYMBOL_arithmetic_stmt = 148,          /* arithmetic_stmt  */
  YYSYMBOL_new_expr = 149,                 /* new_expr  */
  YYSYMBOL_args_list_with_parentheses = 150, /* args_list_with_parentheses  */
  YYSYMBOL_args_list = 151,                /* args_list  */
  YYSYMBOL_delete_expr = 152,              /* delete_expr  */
  YYSYMBOL_logic_stmt = 153,               /* logic_stmt  */
  YYSYMBOL_bool_param_expr = 154,          /* bool_param_expr  */
  YYSYMBOL_type_judge_stmt = 155,          /* type_judge_stmt  */
  YYSYMBOL_not_bool_param_expr = 156,      /* not_bool_param_expr  */
  YYSYMBOL_compare_expr = 157,             /* compare_expr  */
  YYSYMBOL_number_compare_expr = 158,      /* number_compare_expr  */
  YYSYMBOL_object_compare_expr = 159,      /* object_compare_expr  */
  YYSYMBOL__symbol_compare = 160,          /* _symbol_compare  */
  YYSYMBOL__symbol_equals_not = 161,       /* _symbol_equals_not  */
  YYSYMBOL_self_inc_dec_stmt = 162,        /* self_inc_dec_stmt  */
  YYSYMBOL_self_inc_dec_operators = 163,   /* self_inc_dec_operators  */
  YYSYMBOL_assign_stmt_value_eq = 164,     /* assign_stmt_value_eq  */
  YYSYMBOL_array_ele_stmt = 165,           /* array_ele_stmt  */
  YYSYMBOL_assign_stmt = 166,              /* assign_stmt  */
  YYSYMBOL_single_assign_stmt = 167,       /* single_assign_stmt  */
  YYSYMBOL_single_assign_stmt_value = 168, /* single_assign_stmt_value  */
  YYSYMBOL_number_change_assign_stmt = 169, /* number_change_assign_stmt  */
  YYSYMBOL_symbol_change_assign = 170,     /* symbol_change_assign  */
  YYSYMBOL_code_block = 171,               /* code_block  */
  YYSYMBOL_block_item_list = 172,          /* block_item_list  */
  YYSYMBOL_block_item = 173,               /* block_item  */
  YYSYMBOL_string_plus_stmt = 174,         /* string_plus_stmt  */
  YYSYMBOL_string_plus_stmt_value = 175,   /* string_plus_stmt_value  */
  YYSYMBOL_number_parentheses_stmt = 176,  /* number_parentheses_stmt  */
  YYSYMBOL_id_expr = 177,                  /* id_expr  */
  YYSYMBOL_multiple_id_expr = 178,         /* multiple_id_expr  */
  YYSYMBOL_bool_expr = 179,                /* bool_expr  */
  YYSYMBOL_number_expr = 180,              /* number_expr  */
  YYSYMBOL_positive_number_expr = 181,     /* positive_number_expr  */
  YYSYMBOL_int_expr = 182,                 /* int_expr  */
  YYSYMBOL_double_expr = 183,              /* double_expr  */
  YYSYMBOL_uminus_expr = 184,              /* uminus_expr  */
  YYSYMBOL_uminus_expr_values = 185,       /* uminus_expr_values  */
  YYSYMBOL_string_expr = 186,              /* string_expr  */
  YYSYMBOL_null_expr = 187,                /* null_expr  */
  YYSYMBOL_common_types_expr = 188,        /* common_types_expr  */
  YYSYMBOL_common_others_values_expr = 189, /* common_others_values_expr  */
  YYSYMBOL_common_values_expr = 190,       /* common_values_expr  */
  YYSYMBOL_common_result_of_call_expr = 191, /* common_result_of_call_expr  */
  YYSYMBOL_common_assignable_expr = 192,   /* common_assignable_expr  */
  YYSYMBOL_common_number_expr = 193,       /* common_number_expr  */
  YYSYMBOL_common_object_expr = 194,       /* common_object_expr  */
  YYSYMBOL_common_expr = 195               /* common_expr  */
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
#define YYLAST   866

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  96
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  100
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  342
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 9
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327

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
       2,     2,     2,    83,     2,     2,     2,    82,    77,     2,
      86,    87,    80,    78,    72,    79,    90,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    95,    92,
      69,    74,    68,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    88,     2,    89,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    93,    75,    94,    84,     2,     2,     2,
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
      65,    66,    67,    70,    71,    73,    85,    91
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    82,    82,    86,    87,    90,    91,    92,    93,    94,
      98,   102,   103,   104,   105,   111,   112,   116,   122,   127,
     131,   132,   142,   146,   147,   152,   153,   157,   158,   162,
     163,   167,   168,   169,   170,   175,   181,   186,   196,   197,
     201,   202,   203,   207,   208,   213,   217,   218,   219,   224,
     225,   229,   230,   234,   235,   239,   240,   244,   245,   249,
     250,   256,   257,   262,   263,   267,   268,   272,   276,   277,
     281,   282,   286,   290,   294,   295,   299,   300,   304,   305,
     309,   310,   314,   315,   316,   321,   327,   328,   329,   334,
     335,   340,   344,   345,   346,   347,   348,   349,   350,   351,
     356,   357,   361,   362,   363,   364,   369,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   390,   394,
     395,   399,   400,   404,   410,   411,   412,   413,   414,   415,
     420,   421,   426,   430,   435,   436,   440,   444,   448,   449,
     450,   451,   452,   453,   457,   458,   463,   464,   468,   469,
     475,   476,   477,   485,   490,   491,   495,   499,   500,   504,
     508,   509,   510,   511,   512,   517,   518,   522,   523,   527,
     528,   529,   530,   535,   536,   537,   538,   542,   543,   544,
     545,   549,   555,   559,   560,   564,   568,   569,   573,   574,
     578,   582,   586,   590,   591,   592,   593,   597,   601,   608,
     609,   610,   611,   612,   616,   617,   618,   619,   623,   624,
     625,   629,   630,   631,   632,   636,   640,   641,   642,   646,
     647,   656,   657,   658,   659,   660
};
#endif

#define YYPACT_NINF (-273)
#define YYTABLE_NINF (-221)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -273,    61,   477,  -273,  -273,  -273,   -83,    42,    87,  -273,
      87,  -273,    95,  -273,  -273,  -273,    47,    50,    72,    87,
    -273,   531,    79,  -273,  -273,    87,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,    87,  -273,  -273,  -273,  -273,   119,
    -273,    92,    96,  -273,  -273,  -273,  -273,   152,  -273,  -273,
      81,  -273,  -273,   102,   117,  -273,  -273,    92,  -273,  -273,
    -273,  -273,    15,   787,     6,   792,   -67,   366,   164,   148,
     142,  -273,   153,  -273,  -273,   541,   541,    92,  -273,   168,
    -273,  -273,  -273,  -273,    10,   630,   634,   521,  -273,   237,
      64,  -273,  -273,   106,  -273,  -273,  -273,  -273,  -273,  -273,
     173,  -273,   180,   183,   184,    18,   168,   103,   493,  -273,
    -273,  -273,  -273,   186,  -273,   187,  -273,   656,   286,   736,
      60,  -273,   634,  -273,   245,   -27,  -273,   201,  -273,  -273,
    -273,    49,   153,   205,    87,    -7,  -273,   152,  -273,  -273,
    -273,   232,   240,    87,   634,   512,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,   531,   634,   634,    87,  -273,  -273,  -273,
    -273,  -273,   420,  -273,   194,  -273,    87,    87,  -273,   634,
     -23,  -273,  -273,  -273,   397,   597,   483,    60,   198,   -39,
    -273,  -273,    87,    56,  -273,  -273,  -273,   262,  -273,   749,
    -273,   162,  -273,  -273,  -273,   -65,   696,   -83,   541,   541,
     625,   625,   625,   634,   634,  -273,  -273,  -273,  -273,  -273,
    -273,   634,   634,   634,   634,   634,   634,   634,   634,   634,
      87,  -273,  -273,   337,   709,    87,   189,    28,   -83,  -273,
      92,  -273,   195,  -273,  -273,  -273,  -273,  -273,   616,  -273,
     -18,  -273,  -273,  -273,  -273,   749,   681,  -273,  -273,  -273,
      87,   142,  -273,   -83,   -83,    92,   541,  -273,  -273,  -273,
    -273,  -273,   217,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
     -67,  -273,   216,  -273,   340,   340,   763,   687,   754,   145,
     145,  -273,  -273,  -273,   749,  -273,    32,  -273,   203,   168,
      24,  -273,  -273,    30,  -273,  -273,  -273,   531,  -273,  -273,
     213,  -273,  -273,  -273,   210,   106,   200,  -273,  -273,   343,
    -273,  -273,   221,   222,  -273,  -273,   -83,   411,   317,   228,
      53,  -273,  -273,  -273,  -273,  -273,  -273,    37,  -273,  -273,
    -273,   230,   -83,  -273,  -273,   411,   -83,   -83,  -273,  -273,
    -273,  -273
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   182,    42,     0,     0,     0,   105,
       0,    35,   100,    24,    51,    52,     0,     0,     0,     0,
     102,   103,     0,   148,   149,     0,    10,     3,     5,     6,
       9,    13,    14,    12,     0,   209,   206,   207,    11,     0,
      99,     0,    49,    53,     7,    61,    63,    65,    62,     8,
       0,    98,    96,   220,   210,    95,    92,     0,   205,    93,
     154,   155,   204,   208,   219,     0,     0,     0,    15,     0,
      19,    20,     0,   185,   101,     0,     0,    82,   183,   123,
     190,   191,   197,   198,     0,     0,     0,     0,   202,     0,
     212,   213,   210,   225,   124,   126,   125,   127,   134,   135,
     211,   130,   224,     0,   214,   204,    48,   131,   216,   186,
     189,   188,   187,   200,   201,   221,   208,   217,   218,     0,
     177,   104,     0,    41,    25,     0,    59,    50,    57,   220,
      60,   204,   219,     0,     0,     0,    66,     0,    70,    69,
      91,   204,   146,     0,     0,     0,   106,   147,   160,   161,
     162,   163,   164,     0,     0,     0,     0,   165,   172,   169,
     171,   170,     0,   167,     0,    16,     0,     0,   118,     0,
       0,   211,   214,   131,   216,   217,   218,     0,     0,     0,
      83,    85,     0,   195,   196,   193,   192,   194,   133,     0,
     216,   217,   218,   117,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   140,   143,   142,   138,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   144,     0,     0,     0,     0,     0,     0,    38,
       0,    54,    55,    72,    73,    71,    68,    37,     0,   119,
       0,   121,   158,   156,   157,   159,     0,    36,   166,   168,
       0,    18,    21,     0,     0,     0,    80,   184,    47,   181,
      45,   128,   129,   179,   176,   180,   203,   199,   200,   178,
     177,   175,   174,   173,   115,   116,   113,   114,   112,   107,
     108,   109,   110,   111,   136,   132,     0,   137,     0,    26,
       0,    22,    43,     0,    39,    58,    56,     0,   120,   153,
       0,    67,    78,    84,     0,    81,     0,    27,    34,     0,
      29,    33,     0,     0,    44,   122,     0,    86,     0,     0,
       0,    74,    28,    30,    31,    32,    17,     0,    87,    90,
      89,     0,     0,    64,    75,     0,     0,     0,    77,    88,
      79,    76
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,  -273,  -273,    -1,  -273,   330,  -273,  -273,  -273,
     171,  -273,  -273,  -273,  -273,  -273,    46,  -273,  -273,  -273,
     357,  -273,  -273,  -273,  -273,  -272,  -273,  -273,   -37,  -273,
     133,   363,  -273,  -273,   231,  -273,  -273,   233,   234,  -273,
      55,  -273,  -273,  -273,   112,  -273,    48,   375,  -273,  -273,
    -273,     1,  -273,    12,   314,  -273,  -273,   -64,   303,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,     4,   -36,  -273,  -273,
     -72,     3,  -273,  -273,  -273,    44,  -273,   241,   204,   -80,
     208,   104,    17,    14,   -13,   318,    88,  -273,  -273,  -273,
      11,  -273,    76,     0,    -2,    25,    29,   260,    19,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    27,   158,    29,   159,   165,    31,    32,
      70,    33,    34,   226,   291,   309,   310,    35,    36,    37,
     311,    39,   228,    88,    89,    40,    41,    42,    43,   127,
     128,   160,    45,    46,    47,   136,   137,   138,   139,   320,
     321,    48,   304,   179,   180,   327,   328,   161,    50,    51,
      52,    90,    91,    92,   146,   240,    55,    93,    94,    95,
      96,    97,    98,    99,   219,   223,   171,    57,   101,    58,
      59,    60,   243,    61,   154,    68,   162,   163,   102,   103,
     172,   141,   106,   173,   190,   109,   110,   111,   112,   186,
     113,   114,   115,   116,   191,   192,    65,   119,    66,   121
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    28,    63,    53,   126,   181,    56,   182,   108,   241,
      67,   170,   178,    80,    54,    81,     4,   244,   312,   117,
      16,   155,   258,   156,   -40,   100,    74,  -183,   147,    10,
       4,    11,     5,   255,     4,   107,    79,   312,     4,   132,
     120,    63,   129,    10,   130,    11,   118,   198,   199,    14,
      15,    23,    24,   256,   297,   142,    69,   143,   129,   227,
     143,     3,   174,   174,   253,    64,    67,    63,    53,   298,
     133,    56,   174,   175,   175,   132,   220,    63,   129,    54,
    -220,   147,   132,   175,   187,   183,    67,   -55,   318,   319,
    -183,   143,   145,     4,   177,   177,   169,   231,     4,    73,
     176,   176,   182,   144,   195,  -183,    62,   -55,    25,   335,
     176,    10,    71,    11,    72,   292,    26,   314,   307,   194,
     264,   -55,   273,    78,   336,   105,   221,   222,   125,   123,
    -212,  -212,   108,    75,   261,   262,    76,   144,   124,   147,
     108,   -55,  -212,   117,  -220,   131,  -220,   333,   155,   100,
     156,   117,  -220,    63,  -220,   147,   242,   100,    77,   107,
      64,   315,    63,    53,   120,   122,    56,   107,   134,   229,
     118,   131,   120,   140,    54,  -131,   198,   199,   118,   234,
     135,  -203,   133,   181,   164,   174,   174,   267,   267,   267,
    -131,   105,   305,   126,   -94,  -131,   175,   175,    64,    64,
      64,   129,   129,   129,   263,   263,   263,    23,    24,   -97,
     267,   268,   272,   268,   266,   266,   266,   177,   177,   270,
     270,   270,   166,   176,   176,   216,   217,   218,   132,   104,
      63,   129,   167,   130,   268,   318,   319,   266,   232,   145,
     182,   260,   289,   174,   293,   330,   197,   237,   145,   105,
    -219,  -179,  -219,   132,   175,    63,   129,   105,   200,   133,
     247,   201,  -180,   330,   202,  -178,   131,   225,   198,   199,
      71,   252,   294,   230,   143,   177,   269,   269,   269,   153,
     250,   176,   290,   144,   108,   254,   257,   198,   132,   308,
      63,   129,   184,   313,  -174,   117,   306,   301,   302,   287,
     316,   100,   317,   195,   105,   105,   105,   132,   308,    63,
     129,   107,   313,   324,   325,    64,   120,    63,   129,   133,
      80,   329,   118,   332,   285,   337,   145,    78,  -219,    78,
    -219,    78,    30,    64,   131,    63,   129,   251,   133,   329,
      80,    73,    81,     4,    82,   189,   193,   196,  -208,     4,
    -208,     5,  -208,   104,   300,   323,  -152,  -152,  -152,    38,
     326,   104,    10,   295,    11,    44,   233,   303,    14,    15,
     235,   236,     4,  -152,    83,   334,   338,    49,  -152,     6,
     340,   341,   224,   339,     9,    10,   168,    11,   188,    12,
      78,    14,    15,    16,    62,    17,    18,    19,    20,    21,
      22,   105,   185,   249,   238,   271,   331,     0,   265,   265,
     265,    23,    24,    62,   245,   246,    84,     4,   214,   215,
     216,   217,   218,   286,     0,     0,     4,    25,     0,   196,
      10,     0,    11,     6,     0,    26,     0,   322,     9,    10,
       0,    11,     0,    12,     0,    14,    15,    16,     0,    17,
      18,    19,    20,    21,    22,     0,    23,    24,    26,     0,
     157,     0,     0,   274,   275,    23,    24,  -150,  -150,  -150,
       0,   276,   277,   278,   279,   280,   281,   282,   283,   284,
       0,     0,     0,     4,  -150,     5,     0,     0,     0,  -150,
       6,     0,     7,     0,     8,     9,    10,     0,    11,     0,
      12,    13,    14,    15,    16,   104,    17,    18,    19,    20,
      21,    22,    26,     0,   248,    80,    73,    81,     4,    82,
       0,     0,    23,    24,    80,     0,    81,     4,     0,     0,
       0,    10,     0,    11,    80,    73,    81,     4,    82,     0,
      10,     0,    11,     0,    80,    73,    81,     4,     0,    83,
      10,     0,    11,  -152,  -152,  -152,     0,    23,    24,     0,
      10,    25,    11,  -150,  -150,  -150,    23,    24,    83,    26,
    -152,  -199,     0,     0,     0,  -152,    23,    24,     0,     0,
    -150,     0,     0,     0,     0,  -150,    23,    24,     0,     0,
       0,    84,     0,     0,     0,    85,    86,     0,    87,   239,
      84,     0,     0,     0,     0,    86,     0,   169,   194,     0,
      84,     0,     0,  -219,    85,    86,     0,    87,     0,     0,
      84,     0,     0,     0,    85,    86,     0,   169,    80,    73,
      81,     4,    82,    80,    73,    81,     4,    80,     0,    81,
       4,     0,    23,    24,    10,     0,    11,     0,     0,    10,
       0,    11,     0,    10,     0,    11,     0,     0,     0,   203,
     204,     0,    83,  -217,  -217,     0,     0,  -151,  -151,  -151,
      23,    24,  -219,     0,     0,    23,    24,     0,     0,    23,
      24,     0,     0,   145,  -151,  -219,     0,  -219,     0,  -151,
       0,   211,   212,   213,   214,   215,   216,   217,   218,     0,
       0,    23,    24,     0,    84,   296,     0,     0,     0,    84,
       0,    87,     0,    84,    86,     0,   169,     0,    86,     0,
     169,     0,  -217,  -217,   203,   204,  -151,  -151,  -151,     0,
     203,   204,     0,     0,  -217,     0,     0,     0,     0,   203,
     204,     0,   145,  -151,  -219,     0,  -219,     0,  -151,     0,
       0,     0,   203,   204,     0,     0,   211,   212,   213,   214,
     215,   216,   217,   218,   213,   214,   215,   216,   217,   218,
     299,   211,   212,   213,   214,   215,   216,   217,   218,   203,
     204,     0,     0,   259,   211,   212,   213,   214,   215,   216,
     217,   218,   203,   204,     0,     0,   288,   203,   204,     0,
     205,   206,   207,   208,   209,   210,   203,   204,     0,     0,
       0,   211,   212,   213,   214,   215,   216,   217,   218,     0,
       0,     0,     0,     0,   211,   212,   213,   214,   215,   216,
     217,   218,   214,   215,   216,   217,   218,     0,     0,   212,
     213,   214,   215,   216,   217,   218,  -215,  -215,  -215,  -215,
    -215,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,  -215,     0,     0,     0,     0,   153
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,    41,    77,     2,    72,    21,   145,
      93,    75,    76,     3,     2,     5,     6,   153,   290,    21,
      27,    88,    87,    90,     9,    21,    12,     9,    64,    19,
       6,    21,     8,    72,     6,    21,    19,   309,     6,    41,
      21,    41,    41,    19,    41,    21,    21,    70,    71,    25,
      26,    45,    46,    92,    72,    57,    14,    42,    57,    86,
      42,     0,    75,    76,    87,    67,    93,    67,    67,    87,
      41,    67,    85,    75,    76,    77,    16,    77,    77,    67,
      16,   117,    84,    85,    84,    84,    93,    72,    35,    36,
      72,    42,    86,     6,    75,    76,    86,   134,     6,     4,
      75,    76,    72,    88,    87,    87,     2,    92,    84,    72,
      85,    19,     8,    21,    10,    87,    92,    87,    94,    87,
     200,    72,   202,    19,    87,    21,    66,    67,     9,    25,
      66,    67,   145,    86,   198,   199,    86,    88,    34,   175,
     153,    92,    78,   145,    88,    41,    90,    94,    88,   145,
      90,   153,    88,   153,    90,   191,   153,   153,    86,   145,
     162,   297,   162,   162,   145,    86,   162,   153,    72,   125,
     145,    67,   153,    92,   162,    72,    70,    71,   153,   135,
      28,    78,   153,   255,    20,   198,   199,   200,   201,   202,
      87,    87,   256,   230,    92,    92,   198,   199,   200,   201,
     202,   200,   201,   202,   200,   201,   202,    45,    46,    92,
     223,   200,   201,   202,   200,   201,   202,   198,   199,   200,
     201,   202,    74,   198,   199,    80,    81,    82,   230,    21,
     230,   230,    90,   230,   223,    35,    36,   223,   134,    86,
      72,   197,   225,   256,   227,   317,     9,   143,    86,   145,
      88,    78,    90,   255,   256,   255,   255,   153,    78,   230,
     156,    78,    78,   335,    78,    78,   162,    22,    70,    71,
     166,   167,   228,    72,    42,   256,   200,   201,   202,    74,
      86,   256,    93,    88,   297,    87,   182,    70,   290,   290,
     290,   290,    84,   290,    78,   297,    93,   253,   254,   223,
      87,   297,    92,   286,   200,   201,   202,   309,   309,   309,
     309,   297,   309,    92,    92,   317,   297,   317,   317,   290,
       3,   317,   297,    95,   220,    95,    86,   223,    88,   225,
      90,   227,     2,   335,   230,   335,   335,   166,   309,   335,
       3,     4,     5,     6,     7,    85,    86,    87,    86,     6,
      88,     8,    90,   145,   250,   309,    70,    71,    72,     2,
     316,   153,    19,   230,    21,     2,   135,   255,    25,    26,
     137,   137,     6,    87,    37,   320,   332,     2,    92,    13,
     336,   337,   122,   335,    18,    19,    72,    21,    85,    23,
     286,    25,    26,    27,   290,    29,    30,    31,    32,    33,
      34,   297,    84,   162,   144,   201,   318,    -1,   200,   201,
     202,    45,    46,   309,   154,   155,    79,     6,    78,    79,
      80,    81,    82,    86,    -1,    -1,     6,    84,    -1,   169,
      19,    -1,    21,    13,    -1,    92,    -1,    94,    18,    19,
      -1,    21,    -1,    23,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    -1,    45,    46,    92,    -1,
      94,    -1,    -1,   203,   204,    45,    46,    70,    71,    72,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
      -1,    -1,    -1,     6,    87,     8,    -1,    -1,    -1,    92,
      13,    -1,    15,    -1,    17,    18,    19,    -1,    21,    -1,
      23,    24,    25,    26,    27,   297,    29,    30,    31,    32,
      33,    34,    92,    -1,    94,     3,     4,     5,     6,     7,
      -1,    -1,    45,    46,     3,    -1,     5,     6,    -1,    -1,
      -1,    19,    -1,    21,     3,     4,     5,     6,     7,    -1,
      19,    -1,    21,    -1,     3,     4,     5,     6,    -1,    37,
      19,    -1,    21,    70,    71,    72,    -1,    45,    46,    -1,
      19,    84,    21,    70,    71,    72,    45,    46,    37,    92,
      87,    78,    -1,    -1,    -1,    92,    45,    46,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    92,    45,    46,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    83,    84,    -1,    86,    87,
      79,    -1,    -1,    -1,    -1,    84,    -1,    86,    87,    -1,
      79,    -1,    -1,    16,    83,    84,    -1,    86,    -1,    -1,
      79,    -1,    -1,    -1,    83,    84,    -1,    86,     3,     4,
       5,     6,     7,     3,     4,     5,     6,     3,    -1,     5,
       6,    -1,    45,    46,    19,    -1,    21,    -1,    -1,    19,
      -1,    21,    -1,    19,    -1,    21,    -1,    -1,    -1,    43,
      44,    -1,    37,    66,    67,    -1,    -1,    70,    71,    72,
      45,    46,    16,    -1,    -1,    45,    46,    -1,    -1,    45,
      46,    -1,    -1,    86,    87,    88,    -1,    90,    -1,    92,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    45,    46,    -1,    79,    89,    -1,    -1,    -1,    79,
      -1,    86,    -1,    79,    84,    -1,    86,    -1,    84,    -1,
      86,    -1,    66,    67,    43,    44,    70,    71,    72,    -1,
      43,    44,    -1,    -1,    78,    -1,    -1,    -1,    -1,    43,
      44,    -1,    86,    87,    88,    -1,    90,    -1,    92,    -1,
      -1,    -1,    43,    44,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    77,    78,    79,    80,    81,    82,
      89,    75,    76,    77,    78,    79,    80,    81,    82,    43,
      44,    -1,    -1,    87,    75,    76,    77,    78,    79,    80,
      81,    82,    43,    44,    -1,    -1,    87,    43,    44,    -1,
      64,    65,    66,    67,    68,    69,    43,    44,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    78,    79,    80,    81,    82,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    59,    60,    61,    62,
      63,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    -1,    -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    97,    98,     0,     6,     8,    13,    15,    17,    18,
      19,    21,    23,    24,    25,    26,    27,    29,    30,    31,
      32,    33,    34,    45,    46,    84,    92,    99,   100,   101,
     102,   104,   105,   107,   108,   113,   114,   115,   116,   117,
     121,   122,   123,   124,   127,   128,   129,   130,   137,   143,
     144,   145,   146,   147,   149,   152,   162,   163,   165,   166,
     167,   169,   177,   189,   190,   192,   194,    93,   171,    14,
     106,   177,   177,     4,   179,    86,    86,    86,   177,   178,
       3,     5,     7,    37,    79,    83,    84,    86,   119,   120,
     147,   148,   149,   153,   154,   155,   156,   157,   158,   159,
     162,   164,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   186,   187,   188,   189,   190,   191,   193,
     194,   195,    86,   177,   177,     9,   124,   125,   126,   147,
     167,   177,   190,   192,    72,    28,   131,   132,   133,   134,
      92,   177,   190,    42,    88,    86,   150,   163,    59,    60,
      61,    62,    63,    74,   170,    88,    90,    94,   100,   102,
     127,   143,   172,   173,    20,   103,    74,    90,   150,    86,
     153,   162,   176,   179,   180,   190,   191,   194,   153,   139,
     140,   166,    72,   147,   176,   181,   185,   189,   154,   193,
     180,   190,   191,   193,    87,   178,   193,     9,    70,    71,
      78,    78,    78,    43,    44,    64,    65,    66,    67,    68,
      69,    75,    76,    77,    78,    79,    80,    81,    82,   160,
      16,    66,    67,   161,   193,    22,   109,    86,   118,   171,
      72,   124,   177,   130,   171,   133,   134,   177,   193,    87,
     151,   195,   167,   168,   195,   193,   193,   177,    94,   173,
      86,   106,   177,    87,    87,    72,    92,   177,    87,    87,
     171,   153,   153,   162,   175,   176,   179,   180,   186,   188,
     194,   174,   186,   175,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   177,    86,   188,    87,   178,
      93,   110,    87,   178,   171,   126,    89,    72,    87,    89,
     177,   171,   171,   140,   138,   153,    93,    94,   100,   111,
     112,   116,   121,   167,    87,   195,    87,    92,    35,    36,
     135,   136,    94,   112,    92,    92,   171,   141,   142,   162,
     166,   182,    95,    94,   136,    72,    87,    95,   171,   142,
     171,   171
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    96,    97,    98,    98,    99,    99,    99,    99,    99,
     100,   101,   101,   101,   101,   102,   102,   103,   104,   105,
     106,   106,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   112,   112,   113,   114,   115,   116,   116,
     117,   117,   117,   118,   118,   119,   120,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   131,   131,
     132,   132,   133,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   139,   140,   141,   141,   141,   142,
     142,   143,   144,   144,   144,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   146,   146,   147,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   149,   150,
     150,   151,   151,   152,   153,   153,   153,   153,   153,   153,
     154,   154,   155,   156,   157,   157,   158,   159,   160,   160,
     160,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     164,   164,   164,   165,   166,   166,   167,   168,   168,   169,
     170,   170,   170,   170,   170,   171,   171,   172,   172,   173,
     173,   173,   173,   174,   174,   174,   174,   175,   175,   175,
     175,   176,   177,   178,   178,   179,   180,   180,   181,   181,
     182,   183,   184,   185,   185,   185,   185,   186,   187,   188,
     188,   188,   188,   188,   189,   189,   189,   189,   190,   190,
     190,   191,   191,   191,   191,   192,   193,   193,   193,   194,
     194,   195,   195,   195,   195,   195
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     5,     4,     2,
       1,     3,     4,     0,     1,     0,     2,     2,     3,     1,
       2,     2,     2,     1,     1,     1,     3,     3,     3,     4,
       1,     2,     1,     2,     3,     3,     2,     3,     1,     1,
       2,     1,     1,     1,     3,     1,     4,     1,     3,     1,
       1,     1,     1,     1,     7,     1,     2,     5,     2,     1,
       1,     2,     2,     2,     1,     2,     4,     3,     5,     9,
       0,     1,     0,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     2,
       3,     1,     3,     2,     1,     1,     1,     1,     3,     3,
       1,     1,     3,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     4,     1,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     3,     1,     2,     1,
       1,     1,     1,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
       0,     0,     0,     0,     2,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     5,     5,     5,     1
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
       0,     0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0
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
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     7,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    13,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,     0,     0,    51,     0,
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
       0,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    37,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,    45,     0,
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

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    23,     0,   204,     0,   220,     0,   220,     0,   220,
       0,   211,     0,   214,     0,   204,     0,   204,     0,   203,
       0,   203,     0,   203,     0,   199,     0,   216,     0,   199,
       0,   199,     0,   200,     0,   219,     0,   219,     0,   222,
       0,   219,     0,   222,     0,   222,     0,   223,     0,   223,
       0,   223,     0,   204,     0,   219,     0,   219,     0,   200,
       0
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
  "TDOUBLE", "IDENTIFIER", "TSTRING", "OPERATOR_X__", "FUNC_OP",
  "FUNC_CALL", "VAR_DECLARE", "ARRAY_ELE", "KEY_TRY", "KEY_PUBLIC",
  "KEY_SET", "KEY_IS", "KEY_REF", "KEY_CONTINUE", "KEY_NEW", "KEY_CATCH",
  "KEY_THIS", "KEY_EXTENDS", "KEY_RESTRICT", "KEY_AUTO", "KEY_CONST",
  "KEY_LOCAL", "KEY_IF", "KEY_ELSE", "KEY_WHILE", "KEY_FOR", "KEY_DELETE",
  "KEY_BREAK", "KEY_RETURN", "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT",
  "KEY_NULL", "CASE_LIST", "CLAXX_BODY", "CLAXX_MEMBER", "CLAXX_FUNC_CALL",
  "SCOPE", "LEFT_SHIFT", "RIGHT_SHIFT", "INC_OP", "DEC_OP",
  "OPR_NODE_LIST", "OPR_CHANGE_NAME_SPACE", "OPR_GET_NAME_SPACE",
  "OPR_CLASS_DECLARE", "OPR_INC_DEC", "OPR_IF_ELSE", "OPR_MULTIPLE_ID",
  "OPR_START_IF", "OPR_ARGS_LIST", "KEY_REQUIRE", "KEY_REQUIRE_ONCE",
  "KEY_INCLUDE", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ", "MOD_EQ", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "'>'", "'<'", "AND_OP", "OR_OP", "','",
  "PIPELINE_OP", "'='", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "INC_OP_BACK", "'('", "')'", "'['", "']'", "'.'",
  "UMINUS", "';'", "'{'", "'}'", "':'", "$accept", "program",
  "statement_list", "statement", "_extra_nothing", "out_declare_stmt",
  "try_stmt", "catch_block_stmt", "namespace_declare_stmt",
  "namespace_ref_stmt", "namespace_name_stmt", "class_declare_stmt",
  "class_name_prefix", "class_name_suffix", "class_body",
  "class_body_items", "class_body_item", "this_stmt", "class_member_stmt",
  "static_member_stmt", "func_declare_stmt", "func_name_types",
  "func_param_list", "lambda_stmt", "lambda_args_stmt", "var_declare_stmt",
  "var_prefix", "_elements_var_declare_stmt", "element_var_declare_stmt",
  "_var_declare_stmt_with_assign_list", "_var_declare_stmt_with_assign",
  "con_ctl_stmt", "selection_stmt", "if_stmt", "single_if_stmt",
  "else_stmt", "else_if_stmts", "else_if_stmt", "single_else_stmt",
  "case_stmt_list", "case_stmt", "loop_stmt", "for_logic_stmt",
  "for_1_stmt_list", "for_1_stmt", "for_3_stmt_list", "for_3_stmt",
  "simple_stmt", "simple_stmt_types", "restrict_stmt", "interrupt_stmt",
  "call_statement", "arithmetic_stmt", "new_expr",
  "args_list_with_parentheses", "args_list", "delete_expr", "logic_stmt",
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
#line 86 "a.y"
                                    { execAndFreeNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1654 "y.tab.c"
    break;

  case 5: /* statement: _extra_nothing  */
#line 90 "a.y"
                             { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1660 "y.tab.c"
    break;

  case 6: /* statement: out_declare_stmt  */
#line 91 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1666 "y.tab.c"
    break;

  case 7: /* statement: con_ctl_stmt  */
#line 92 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1672 "y.tab.c"
    break;

  case 8: /* statement: simple_stmt  */
#line 93 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1678 "y.tab.c"
    break;

  case 9: /* statement: try_stmt  */
#line 94 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1684 "y.tab.c"
    break;

  case 10: /* _extra_nothing: ';'  */
#line 98 "a.y"
                  { ((*yyvalp).node) = NULL; }
#line 1690 "y.tab.c"
    break;

  case 11: /* out_declare_stmt: func_declare_stmt  */
#line 102 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1696 "y.tab.c"
    break;

  case 12: /* out_declare_stmt: class_declare_stmt  */
#line 103 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1702 "y.tab.c"
    break;

  case 13: /* out_declare_stmt: namespace_declare_stmt  */
#line 104 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1708 "y.tab.c"
    break;

  case 14: /* out_declare_stmt: namespace_ref_stmt  */
#line 105 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1714 "y.tab.c"
    break;

  case 15: /* try_stmt: KEY_TRY code_block  */
#line 111 "a.y"
                               { ((*yyvalp).node) = opr(KEY_TRY, 2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node),NULL); }
#line 1720 "y.tab.c"
    break;

  case 16: /* try_stmt: KEY_TRY code_block catch_block_stmt  */
#line 112 "a.y"
                                               { ((*yyvalp).node) = opr(KEY_TRY, 2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1726 "y.tab.c"
    break;

  case 17: /* catch_block_stmt: KEY_CATCH '(' id_expr ')' code_block  */
#line 116 "a.y"
                                                { ((*yyvalp).node) = opr(KEY_CATCH, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1732 "y.tab.c"
    break;

  case 18: /* namespace_declare_stmt: KEY_SET KEY_PUBLIC '=' namespace_name_stmt  */
#line 122 "a.y"
                                                     { ((*yyvalp).node) = opr(OPR_CHANGE_NAME_SPACE, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1738 "y.tab.c"
    break;

  case 19: /* namespace_ref_stmt: KEY_REF namespace_name_stmt  */
#line 127 "a.y"
                                        { ((*yyvalp).node) = opr(KEY_REF, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1744 "y.tab.c"
    break;

  case 20: /* namespace_name_stmt: id_expr  */
#line 131 "a.y"
                   { ((*yyvalp).node) = opr(OPR_GET_NAME_SPACE, 2, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1750 "y.tab.c"
    break;

  case 21: /* namespace_name_stmt: namespace_name_stmt '.' id_expr  */
#line 132 "a.y"
                                          { ((*yyvalp).node) = opr(OPR_GET_NAME_SPACE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1756 "y.tab.c"
    break;

  case 22: /* class_declare_stmt: class_name_prefix id_expr class_name_suffix class_body  */
#line 142 "a.y"
                                                                     {  ((*yyvalp).node) = opr(OPR_CLASS_DECLARE, 4, intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.iValue)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1762 "y.tab.c"
    break;

  case 23: /* class_name_prefix: %empty  */
#line 146 "a.y"
             { ((*yyvalp).iValue) = -1; }
#line 1768 "y.tab.c"
    break;

  case 24: /* class_name_prefix: KEY_AUTO  */
#line 147 "a.y"
                 { ((*yyvalp).iValue) = yytokentype::KEY_AUTO; }
#line 1774 "y.tab.c"
    break;

  case 25: /* class_name_suffix: %empty  */
#line 152 "a.y"
                              { ((*yyvalp).node) = NULL; }
#line 1780 "y.tab.c"
    break;

  case 26: /* class_name_suffix: KEY_EXTENDS multiple_id_expr  */
#line 153 "a.y"
                                        { ((*yyvalp).node) = opr(KEY_EXTENDS, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1786 "y.tab.c"
    break;

  case 27: /* class_body: '{' '}'  */
#line 157 "a.y"
                        { ((*yyvalp).node) = NULL; }
#line 1792 "y.tab.c"
    break;

  case 28: /* class_body: '{' class_body_items '}'  */
#line 158 "a.y"
                                { ((*yyvalp).node) = opr(CLAXX_BODY, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 1798 "y.tab.c"
    break;

  case 29: /* class_body_items: class_body_item  */
#line 162 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1804 "y.tab.c"
    break;

  case 30: /* class_body_items: class_body_items class_body_item  */
#line 163 "a.y"
                                        { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node) ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1810 "y.tab.c"
    break;

  case 31: /* class_body_item: var_declare_stmt ';'  */
#line 167 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1816 "y.tab.c"
    break;

  case 32: /* class_body_item: single_assign_stmt ';'  */
#line 168 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1822 "y.tab.c"
    break;

  case 33: /* class_body_item: func_declare_stmt  */
#line 169 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1828 "y.tab.c"
    break;

  case 34: /* class_body_item: _extra_nothing  */
#line 170 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1834 "y.tab.c"
    break;

  case 35: /* this_stmt: KEY_THIS  */
#line 175 "a.y"
                      { ((*yyvalp).node) = opr(KEY_THIS , 0 ); }
#line 1840 "y.tab.c"
    break;

  case 36: /* class_member_stmt: common_object_expr '.' id_expr  */
#line 181 "a.y"
                                               { ((*yyvalp).node) = opr(CLAXX_MEMBER, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1846 "y.tab.c"
    break;

  case 37: /* static_member_stmt: id_expr SCOPE id_expr  */
#line 186 "a.y"
                                  { ((*yyvalp).node) = opr(SCOPE, 2 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)) ; }
#line 1852 "y.tab.c"
    break;

  case 38: /* func_declare_stmt: func_name_types FUNC_OP code_block  */
#line 196 "a.y"
                                                        { ((*yyvalp).node) = opr(FUNC_OP,3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1858 "y.tab.c"
    break;

  case 39: /* func_declare_stmt: func_name_types FUNC_OP func_param_list code_block  */
#line 197 "a.y"
                                                                    { ((*yyvalp).node) = opr(FUNC_OP, 3, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1864 "y.tab.c"
    break;

  case 40: /* func_name_types: id_expr  */
#line 201 "a.y"
               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1870 "y.tab.c"
    break;

  case 41: /* func_name_types: '~' id_expr  */
#line 202 "a.y"
                    { char buf[1024] = "~"; strcat(buf, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->var_obj->name);  ((*yyvalp).node) = var(strdup(buf)); }
#line 1876 "y.tab.c"
    break;

  case 42: /* func_name_types: OPERATOR_X__  */
#line 203 "a.y"
                    { ((*yyvalp).node) = var((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sValue)); }
#line 1882 "y.tab.c"
    break;

  case 43: /* func_param_list: '(' ')'  */
#line 207 "a.y"
                        { ((*yyvalp).node) = NULL; }
#line 1888 "y.tab.c"
    break;

  case 44: /* func_param_list: '(' multiple_id_expr ')'  */
#line 208 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1894 "y.tab.c"
    break;

  case 45: /* lambda_stmt: lambda_args_stmt FUNC_OP code_block  */
#line 213 "a.y"
                                                { ((*yyvalp).node) = opr(FUNC_OP, 3, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1900 "y.tab.c"
    break;

  case 46: /* lambda_args_stmt: '(' ')'  */
#line 217 "a.y"
                       { ((*yyvalp).node) = NULL; }
#line 1906 "y.tab.c"
    break;

  case 47: /* lambda_args_stmt: '(' multiple_id_expr ')'  */
#line 218 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 1912 "y.tab.c"
    break;

  case 48: /* lambda_args_stmt: multiple_id_expr  */
#line 219 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1918 "y.tab.c"
    break;

  case 49: /* var_declare_stmt: _elements_var_declare_stmt  */
#line 224 "a.y"
                                      { ((*yyvalp).node) = opr(VAR_DECLARE , 2, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 1924 "y.tab.c"
    break;

  case 50: /* var_declare_stmt: var_prefix _var_declare_stmt_with_assign_list  */
#line 225 "a.y"
                                                        { ((*yyvalp).node) = opr(VAR_DECLARE, 2, intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 1930 "y.tab.c"
    break;

  case 51: /* var_prefix: KEY_CONST  */
#line 229 "a.y"
                   { ((*yyvalp).iValue) = yytokentype::KEY_CONST; }
#line 1936 "y.tab.c"
    break;

  case 52: /* var_prefix: KEY_LOCAL  */
#line 230 "a.y"
                   { ((*yyvalp).iValue) = yytokentype::KEY_LOCAL; }
#line 1942 "y.tab.c"
    break;

  case 53: /* _elements_var_declare_stmt: element_var_declare_stmt  */
#line 234 "a.y"
                                       { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1948 "y.tab.c"
    break;

  case 54: /* _elements_var_declare_stmt: _elements_var_declare_stmt ',' element_var_declare_stmt  */
#line 235 "a.y"
                                                               { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1954 "y.tab.c"
    break;

  case 55: /* element_var_declare_stmt: id_expr  */
#line 239 "a.y"
                                                                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1960 "y.tab.c"
    break;

  case 56: /* element_var_declare_stmt: id_expr '[' common_number_expr ']'  */
#line 240 "a.y"
                                                        { ((*yyvalp).node) = arrayElementNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node)->var_obj->name, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 1966 "y.tab.c"
    break;

  case 57: /* _var_declare_stmt_with_assign_list: _var_declare_stmt_with_assign  */
#line 244 "a.y"
                                            { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1972 "y.tab.c"
    break;

  case 58: /* _var_declare_stmt_with_assign_list: _var_declare_stmt_with_assign_list ',' _var_declare_stmt_with_assign  */
#line 245 "a.y"
                                                                                 { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 1978 "y.tab.c"
    break;

  case 59: /* _var_declare_stmt_with_assign: element_var_declare_stmt  */
#line 249 "a.y"
                                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1984 "y.tab.c"
    break;

  case 60: /* _var_declare_stmt_with_assign: single_assign_stmt  */
#line 250 "a.y"
                                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1990 "y.tab.c"
    break;

  case 61: /* con_ctl_stmt: selection_stmt  */
#line 256 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 1996 "y.tab.c"
    break;

  case 62: /* con_ctl_stmt: loop_stmt  */
#line 257 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2002 "y.tab.c"
    break;

  case 63: /* selection_stmt: if_stmt  */
#line 262 "a.y"
                         { ((*yyvalp).node) = opr(OPR_START_IF, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2008 "y.tab.c"
    break;

  case 64: /* selection_stmt: KEY_SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  */
#line 263 "a.y"
                                                                        { ((*yyvalp).node) = opr(KEY_SWITCH, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); pretreatSwitch( ((*yyvalp).node) ) ; }
#line 2014 "y.tab.c"
    break;

  case 65: /* if_stmt: single_if_stmt  */
#line 267 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2020 "y.tab.c"
    break;

  case 66: /* if_stmt: single_if_stmt else_stmt  */
#line 268 "a.y"
                               { ((*yyvalp).node) = opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2026 "y.tab.c"
    break;

  case 67: /* single_if_stmt: KEY_IF '(' logic_stmt ')' code_block  */
#line 272 "a.y"
                                           { ((*yyvalp).node) = opr(KEY_IF ,2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)) ; }
#line 2032 "y.tab.c"
    break;

  case 68: /* else_stmt: else_if_stmts single_else_stmt  */
#line 276 "a.y"
                                        { ((*yyvalp).node) =  opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2038 "y.tab.c"
    break;

  case 69: /* else_stmt: single_else_stmt  */
#line 277 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2044 "y.tab.c"
    break;

  case 70: /* else_if_stmts: else_if_stmt  */
#line 281 "a.y"
                          { ((*yyvalp).node) = opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 2050 "y.tab.c"
    break;

  case 71: /* else_if_stmts: else_if_stmts else_if_stmt  */
#line 282 "a.y"
                                    { ((*yyvalp).node) =  opr(OPR_IF_ELSE, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2056 "y.tab.c"
    break;

  case 72: /* else_if_stmt: KEY_ELSE single_if_stmt  */
#line 286 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2062 "y.tab.c"
    break;

  case 73: /* single_else_stmt: KEY_ELSE code_block  */
#line 290 "a.y"
                              { ((*yyvalp).node) = opr( KEY_ELSE, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2068 "y.tab.c"
    break;

  case 74: /* case_stmt_list: case_stmt  */
#line 294 "a.y"
                               { ((*yyvalp).node) = opr(CASE_LIST , 1 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2074 "y.tab.c"
    break;

  case 75: /* case_stmt_list: case_stmt_list case_stmt  */
#line 295 "a.y"
                                   { ((*yyvalp).node) = opr(CASE_LIST , 2 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2080 "y.tab.c"
    break;

  case 76: /* case_stmt: KEY_CASE int_expr ':' code_block  */
#line 299 "a.y"
                                                  { ((*yyvalp).node) = opr(KEY_CASE, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2086 "y.tab.c"
    break;

  case 77: /* case_stmt: KEY_DEFAULT ':' code_block  */
#line 300 "a.y"
                                                     { ((*yyvalp).node) = opr(KEY_DEFAULT , 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2092 "y.tab.c"
    break;

  case 78: /* loop_stmt: KEY_WHILE '(' logic_stmt ')' code_block  */
#line 304 "a.y"
                                                  { ((*yyvalp).node) = opr(KEY_WHILE , 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2098 "y.tab.c"
    break;

  case 79: /* loop_stmt: KEY_FOR '(' for_1_stmt_list ';' for_logic_stmt ';' for_3_stmt_list ')' code_block  */
#line 305 "a.y"
                                                                                            { ((*yyvalp).node) = opr(KEY_FOR,4,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2104 "y.tab.c"
    break;

  case 80: /* for_logic_stmt: %empty  */
#line 309 "a.y"
            { ((*yyvalp).node) = intNode(1);  }
#line 2110 "y.tab.c"
    break;

  case 81: /* for_logic_stmt: logic_stmt  */
#line 310 "a.y"
                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2116 "y.tab.c"
    break;

  case 82: /* for_1_stmt_list: %empty  */
#line 314 "a.y"
           { ((*yyvalp).node) = NULL ; }
#line 2122 "y.tab.c"
    break;

  case 83: /* for_1_stmt_list: for_1_stmt  */
#line 315 "a.y"
                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2128 "y.tab.c"
    break;

  case 84: /* for_1_stmt_list: for_1_stmt_list ',' for_1_stmt  */
#line 316 "a.y"
                                        { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2134 "y.tab.c"
    break;

  case 85: /* for_1_stmt: assign_stmt  */
#line 321 "a.y"
                       { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2140 "y.tab.c"
    break;

  case 86: /* for_3_stmt_list: %empty  */
#line 327 "a.y"
           { ((*yyvalp).node) = NULL ; }
#line 2146 "y.tab.c"
    break;

  case 87: /* for_3_stmt_list: for_3_stmt  */
#line 328 "a.y"
                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2152 "y.tab.c"
    break;

  case 88: /* for_3_stmt_list: for_3_stmt_list ',' for_3_stmt  */
#line 329 "a.y"
                                        { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2158 "y.tab.c"
    break;

  case 89: /* for_3_stmt: assign_stmt  */
#line 334 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2164 "y.tab.c"
    break;

  case 90: /* for_3_stmt: self_inc_dec_stmt  */
#line 335 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2170 "y.tab.c"
    break;

  case 91: /* simple_stmt: simple_stmt_types ';'  */
#line 340 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2176 "y.tab.c"
    break;

  case 92: /* simple_stmt_types: self_inc_dec_stmt  */
#line 344 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2182 "y.tab.c"
    break;

  case 93: /* simple_stmt_types: assign_stmt  */
#line 345 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2188 "y.tab.c"
    break;

  case 94: /* simple_stmt_types: call_statement  */
#line 346 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2194 "y.tab.c"
    break;

  case 95: /* simple_stmt_types: delete_expr  */
#line 347 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2200 "y.tab.c"
    break;

  case 96: /* simple_stmt_types: interrupt_stmt  */
#line 348 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2206 "y.tab.c"
    break;

  case 97: /* simple_stmt_types: new_expr  */
#line 349 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2212 "y.tab.c"
    break;

  case 98: /* simple_stmt_types: restrict_stmt  */
#line 350 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2218 "y.tab.c"
    break;

  case 99: /* simple_stmt_types: var_declare_stmt  */
#line 351 "a.y"
                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2224 "y.tab.c"
    break;

  case 100: /* restrict_stmt: KEY_RESTRICT  */
#line 356 "a.y"
                             { ((*yyvalp).node) = opr(KEY_RESTRICT,0);}
#line 2230 "y.tab.c"
    break;

  case 101: /* restrict_stmt: KEY_RESTRICT bool_expr  */
#line 357 "a.y"
                                  { ((*yyvalp).node) = opr(KEY_RESTRICT,1,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2236 "y.tab.c"
    break;

  case 102: /* interrupt_stmt: KEY_BREAK  */
#line 361 "a.y"
                    { ((*yyvalp).node) = opr(KEY_BREAK, 0); }
#line 2242 "y.tab.c"
    break;

  case 103: /* interrupt_stmt: KEY_RETURN  */
#line 362 "a.y"
                     { ((*yyvalp).node) = opr(KEY_RETURN , 0); }
#line 2248 "y.tab.c"
    break;

  case 104: /* interrupt_stmt: KEY_RETURN common_expr  */
#line 363 "a.y"
                                 { ((*yyvalp).node) = opr(KEY_RETURN , 1 ,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2254 "y.tab.c"
    break;

  case 105: /* interrupt_stmt: KEY_CONTINUE  */
#line 364 "a.y"
                   { ((*yyvalp).node) = opr(KEY_CONTINUE,0); }
#line 2260 "y.tab.c"
    break;

  case 106: /* call_statement: common_values_expr args_list_with_parentheses  */
#line 369 "a.y"
                                                        { ((*yyvalp).node) = opr(FUNC_CALL, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2266 "y.tab.c"
    break;

  case 107: /* arithmetic_stmt: common_number_expr '+' common_number_expr  */
#line 375 "a.y"
                                                    { ((*yyvalp).node) = opr('+',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2272 "y.tab.c"
    break;

  case 108: /* arithmetic_stmt: common_number_expr '-' common_number_expr  */
#line 376 "a.y"
                                                    { ((*yyvalp).node) = opr('-',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2278 "y.tab.c"
    break;

  case 109: /* arithmetic_stmt: common_number_expr '*' common_number_expr  */
#line 377 "a.y"
                                                    { ((*yyvalp).node) = opr('*',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2284 "y.tab.c"
    break;

  case 110: /* arithmetic_stmt: common_number_expr '/' common_number_expr  */
#line 378 "a.y"
                                                    { ((*yyvalp).node) = opr('/',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2290 "y.tab.c"
    break;

  case 111: /* arithmetic_stmt: common_number_expr '%' common_number_expr  */
#line 379 "a.y"
                                                    { ((*yyvalp).node) = opr('%',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2296 "y.tab.c"
    break;

  case 112: /* arithmetic_stmt: common_number_expr '&' common_number_expr  */
#line 380 "a.y"
                                                     { ((*yyvalp).node) = opr('&',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2302 "y.tab.c"
    break;

  case 113: /* arithmetic_stmt: common_number_expr '|' common_number_expr  */
#line 381 "a.y"
                                                     { ((*yyvalp).node) = opr('|',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2308 "y.tab.c"
    break;

  case 114: /* arithmetic_stmt: common_number_expr '^' common_number_expr  */
#line 382 "a.y"
                                                     { ((*yyvalp).node) = opr('^',2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2314 "y.tab.c"
    break;

  case 115: /* arithmetic_stmt: common_number_expr LEFT_SHIFT common_number_expr  */
#line 383 "a.y"
                                                            { ((*yyvalp).node) = opr(LEFT_SHIFT,2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2320 "y.tab.c"
    break;

  case 116: /* arithmetic_stmt: common_number_expr RIGHT_SHIFT common_number_expr  */
#line 384 "a.y"
                                                             { ((*yyvalp).node) = opr(RIGHT_SHIFT,2,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2326 "y.tab.c"
    break;

  case 117: /* arithmetic_stmt: '~' common_number_expr  */
#line 385 "a.y"
                              { ((*yyvalp).node) = opr('~',1,(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2332 "y.tab.c"
    break;

  case 118: /* new_expr: KEY_NEW id_expr args_list_with_parentheses  */
#line 390 "a.y"
                                                     { ((*yyvalp).node) = opr(KEY_NEW, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2338 "y.tab.c"
    break;

  case 119: /* args_list_with_parentheses: '(' ')'  */
#line 394 "a.y"
                  { ((*yyvalp).node) = NULL; }
#line 2344 "y.tab.c"
    break;

  case 120: /* args_list_with_parentheses: '(' args_list ')'  */
#line 395 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2350 "y.tab.c"
    break;

  case 121: /* args_list: common_expr  */
#line 399 "a.y"
                    { ((*yyvalp).node) = opr(OPR_ARGS_LIST, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2356 "y.tab.c"
    break;

  case 122: /* args_list: args_list ',' common_expr  */
#line 400 "a.y"
                               { ((*yyvalp).node) = opr(OPR_ARGS_LIST, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2362 "y.tab.c"
    break;

  case 123: /* delete_expr: KEY_DELETE multiple_id_expr  */
#line 404 "a.y"
                                  { ((*yyvalp).node) = opr(KEY_DELETE, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2368 "y.tab.c"
    break;

  case 124: /* logic_stmt: bool_param_expr  */
#line 410 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2374 "y.tab.c"
    break;

  case 125: /* logic_stmt: not_bool_param_expr  */
#line 411 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2380 "y.tab.c"
    break;

  case 126: /* logic_stmt: type_judge_stmt  */
#line 412 "a.y"
                                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2386 "y.tab.c"
    break;

  case 127: /* logic_stmt: compare_expr  */
#line 413 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2392 "y.tab.c"
    break;

  case 128: /* logic_stmt: logic_stmt AND_OP logic_stmt  */
#line 414 "a.y"
                                     { ((*yyvalp).node) = opr(AND_OP, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2398 "y.tab.c"
    break;

  case 129: /* logic_stmt: logic_stmt OR_OP logic_stmt  */
#line 415 "a.y"
                                    { ((*yyvalp).node) = opr(OR_OP, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2404 "y.tab.c"
    break;

  case 130: /* bool_param_expr: assign_stmt_value_eq  */
#line 420 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2410 "y.tab.c"
    break;

  case 131: /* bool_param_expr: bool_expr  */
#line 421 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2416 "y.tab.c"
    break;

  case 132: /* type_judge_stmt: common_object_expr KEY_IS id_expr  */
#line 426 "a.y"
                                             { ((*yyvalp).node) = opr(KEY_IS ,2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2422 "y.tab.c"
    break;

  case 133: /* not_bool_param_expr: '!' bool_param_expr  */
#line 430 "a.y"
                            { ((*yyvalp).node) = opr('!', 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2428 "y.tab.c"
    break;

  case 134: /* compare_expr: number_compare_expr  */
#line 435 "a.y"
                                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2434 "y.tab.c"
    break;

  case 135: /* compare_expr: object_compare_expr  */
#line 436 "a.y"
                                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2440 "y.tab.c"
    break;

  case 136: /* number_compare_expr: common_number_expr _symbol_compare common_number_expr  */
#line 440 "a.y"
                                                             { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2446 "y.tab.c"
    break;

  case 137: /* object_compare_expr: common_object_expr _symbol_equals_not common_types_expr  */
#line 444 "a.y"
                                                               { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2452 "y.tab.c"
    break;

  case 138: /* _symbol_compare: '>'  */
#line 448 "a.y"
                { ((*yyvalp).iValue) = '>'; }
#line 2458 "y.tab.c"
    break;

  case 139: /* _symbol_compare: '<'  */
#line 449 "a.y"
                { ((*yyvalp).iValue) = '<'; }
#line 2464 "y.tab.c"
    break;

  case 140: /* _symbol_compare: GE_OP  */
#line 450 "a.y"
                { ((*yyvalp).iValue) = yytokentype::GE_OP; }
#line 2470 "y.tab.c"
    break;

  case 141: /* _symbol_compare: LE_OP  */
#line 451 "a.y"
                { ((*yyvalp).iValue) = yytokentype::LE_OP; }
#line 2476 "y.tab.c"
    break;

  case 142: /* _symbol_compare: NE_OP  */
#line 452 "a.y"
                { ((*yyvalp).iValue) = yytokentype::NE_OP; }
#line 2482 "y.tab.c"
    break;

  case 143: /* _symbol_compare: EQ_OP  */
#line 453 "a.y"
                { ((*yyvalp).iValue) = yytokentype::EQ_OP; }
#line 2488 "y.tab.c"
    break;

  case 144: /* _symbol_equals_not: NE_OP  */
#line 457 "a.y"
                { ((*yyvalp).iValue) = yytokentype::NE_OP; }
#line 2494 "y.tab.c"
    break;

  case 145: /* _symbol_equals_not: EQ_OP  */
#line 458 "a.y"
                { ((*yyvalp).iValue) = yytokentype::EQ_OP; }
#line 2500 "y.tab.c"
    break;

  case 146: /* self_inc_dec_stmt: self_inc_dec_operators common_values_expr  */
#line 463 "a.y"
                                                    { ((*yyvalp).node) = opr(OPR_INC_DEC,2, intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2506 "y.tab.c"
    break;

  case 147: /* self_inc_dec_stmt: common_values_expr self_inc_dec_operators  */
#line 464 "a.y"
                                                                       { ((*yyvalp).node) = opr(OPR_INC_DEC, 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue))); }
#line 2512 "y.tab.c"
    break;

  case 148: /* self_inc_dec_operators: INC_OP  */
#line 468 "a.y"
                    { ((*yyvalp).iValue) = yytokentype::INC_OP; }
#line 2518 "y.tab.c"
    break;

  case 149: /* self_inc_dec_operators: DEC_OP  */
#line 469 "a.y"
                    { ((*yyvalp).iValue) = yytokentype::DEC_OP; }
#line 2524 "y.tab.c"
    break;

  case 150: /* assign_stmt_value_eq: number_expr  */
#line 475 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2530 "y.tab.c"
    break;

  case 151: /* assign_stmt_value_eq: common_values_expr  */
#line 476 "a.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2536 "y.tab.c"
    break;

  case 152: /* assign_stmt_value_eq: common_result_of_call_expr  */
#line 477 "a.y"
                                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2542 "y.tab.c"
    break;

  case 153: /* array_ele_stmt: common_object_expr '[' common_number_expr ']'  */
#line 485 "a.y"
                                                         { ((*yyvalp).node) = objectArrayElementNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 2548 "y.tab.c"
    break;

  case 154: /* assign_stmt: single_assign_stmt  */
#line 490 "a.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2554 "y.tab.c"
    break;

  case 155: /* assign_stmt: number_change_assign_stmt  */
#line 491 "a.y"
                                    { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ;}
#line 2560 "y.tab.c"
    break;

  case 156: /* single_assign_stmt: common_assignable_expr '=' single_assign_stmt_value  */
#line 495 "a.y"
                                                              { ((*yyvalp).node) = opr('=',2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node),(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2566 "y.tab.c"
    break;

  case 157: /* single_assign_stmt_value: common_expr  */
#line 499 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2572 "y.tab.c"
    break;

  case 158: /* single_assign_stmt_value: single_assign_stmt  */
#line 500 "a.y"
                          { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2578 "y.tab.c"
    break;

  case 159: /* number_change_assign_stmt: common_assignable_expr symbol_change_assign common_number_expr  */
#line 504 "a.y"
                                                                    { ((*yyvalp).node) = opr((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.iValue), 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2584 "y.tab.c"
    break;

  case 160: /* symbol_change_assign: ADD_EQ  */
#line 508 "a.y"
                { ((*yyvalp).iValue) = yytokentype::ADD_EQ; }
#line 2590 "y.tab.c"
    break;

  case 161: /* symbol_change_assign: SUB_EQ  */
#line 509 "a.y"
                { ((*yyvalp).iValue) = yytokentype::SUB_EQ; }
#line 2596 "y.tab.c"
    break;

  case 162: /* symbol_change_assign: MUL_EQ  */
#line 510 "a.y"
                { ((*yyvalp).iValue) = yytokentype::MUL_EQ; }
#line 2602 "y.tab.c"
    break;

  case 163: /* symbol_change_assign: DIV_EQ  */
#line 511 "a.y"
                { ((*yyvalp).iValue) = yytokentype::DIV_EQ; }
#line 2608 "y.tab.c"
    break;

  case 164: /* symbol_change_assign: MOD_EQ  */
#line 512 "a.y"
                { ((*yyvalp).iValue) = yytokentype::MOD_EQ; }
#line 2614 "y.tab.c"
    break;

  case 165: /* code_block: '{' '}'  */
#line 517 "a.y"
                    { ((*yyvalp).node) = opr(OPR_NODE_LIST,0 ); }
#line 2620 "y.tab.c"
    break;

  case 166: /* code_block: '{' block_item_list '}'  */
#line 518 "a.y"
                                 { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2626 "y.tab.c"
    break;

  case 167: /* block_item_list: block_item  */
#line 522 "a.y"
                                    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2632 "y.tab.c"
    break;

  case 168: /* block_item_list: block_item_list block_item  */
#line 523 "a.y"
                                    { ((*yyvalp).node) = opr(OPR_NODE_LIST, 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2638 "y.tab.c"
    break;

  case 169: /* block_item: try_stmt  */
#line 527 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2644 "y.tab.c"
    break;

  case 170: /* block_item: simple_stmt  */
#line 528 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2650 "y.tab.c"
    break;

  case 171: /* block_item: con_ctl_stmt  */
#line 529 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2656 "y.tab.c"
    break;

  case 172: /* block_item: _extra_nothing  */
#line 530 "a.y"
                        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2662 "y.tab.c"
    break;

  case 173: /* string_plus_stmt: string_expr '+' string_plus_stmt_value  */
#line 535 "a.y"
                                                         { ((*yyvalp).node) = opr('+', 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2668 "y.tab.c"
    break;

  case 174: /* string_plus_stmt: string_plus_stmt_value '+' string_expr  */
#line 536 "a.y"
                                                        { ((*yyvalp).node) = opr('+', 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2674 "y.tab.c"
    break;

  case 175: /* string_plus_stmt: string_plus_stmt_value '+' string_plus_stmt  */
#line 537 "a.y"
                                                              { ((*yyvalp).node) = opr('+', 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2680 "y.tab.c"
    break;

  case 176: /* string_plus_stmt: string_plus_stmt '+' string_plus_stmt_value  */
#line 538 "a.y"
                                                              { ((*yyvalp).node) = opr('+', 2, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2686 "y.tab.c"
    break;

  case 177: /* string_plus_stmt_value: common_object_expr  */
#line 542 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2692 "y.tab.c"
    break;

  case 178: /* string_plus_stmt_value: common_types_expr  */
#line 543 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2698 "y.tab.c"
    break;

  case 179: /* string_plus_stmt_value: self_inc_dec_stmt  */
#line 544 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2704 "y.tab.c"
    break;

  case 180: /* string_plus_stmt_value: number_parentheses_stmt  */
#line 545 "a.y"
                                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2710 "y.tab.c"
    break;

  case 181: /* number_parentheses_stmt: '(' common_number_expr ')'  */
#line 549 "a.y"
                                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 2716 "y.tab.c"
    break;

  case 182: /* id_expr: IDENTIFIER  */
#line 555 "a.y"
                     { ((*yyvalp).node) = var((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sValue)); }
#line 2722 "y.tab.c"
    break;

  case 183: /* multiple_id_expr: id_expr  */
#line 559 "a.y"
                    { ((*yyvalp).node) = opr(OPR_MULTIPLE_ID , 1 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) );}
#line 2728 "y.tab.c"
    break;

  case 184: /* multiple_id_expr: multiple_id_expr ',' id_expr  */
#line 560 "a.y"
                                   { ((*yyvalp).node) = opr(OPR_MULTIPLE_ID , 2 , (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2734 "y.tab.c"
    break;

  case 185: /* bool_expr: TBOOL  */
#line 564 "a.y"
                  { ((*yyvalp).node) = intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue)); }
#line 2740 "y.tab.c"
    break;

  case 186: /* number_expr: positive_number_expr  */
#line 568 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2746 "y.tab.c"
    break;

  case 187: /* number_expr: uminus_expr  */
#line 569 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2752 "y.tab.c"
    break;

  case 188: /* positive_number_expr: double_expr  */
#line 573 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2758 "y.tab.c"
    break;

  case 189: /* positive_number_expr: int_expr  */
#line 574 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2764 "y.tab.c"
    break;

  case 190: /* int_expr: TINTEGER  */
#line 578 "a.y"
               { ((*yyvalp).node) = intNode((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.iValue)); }
#line 2770 "y.tab.c"
    break;

  case 191: /* double_expr: TDOUBLE  */
#line 582 "a.y"
                  { ((*yyvalp).node) = number((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.dValue)); }
#line 2776 "y.tab.c"
    break;

  case 192: /* uminus_expr: '-' uminus_expr_values  */
#line 586 "a.y"
                                              { ((*yyvalp).node) = opr(UMINUS, 1, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node) ); }
#line 2782 "y.tab.c"
    break;

  case 193: /* uminus_expr_values: positive_number_expr  */
#line 590 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2788 "y.tab.c"
    break;

  case 194: /* uminus_expr_values: common_others_values_expr  */
#line 591 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2794 "y.tab.c"
    break;

  case 195: /* uminus_expr_values: call_statement  */
#line 592 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2800 "y.tab.c"
    break;

  case 196: /* uminus_expr_values: number_parentheses_stmt  */
#line 593 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2806 "y.tab.c"
    break;

  case 197: /* string_expr: TSTRING  */
#line 597 "a.y"
                   { ((*yyvalp).node) = string((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sValue)); }
#line 2812 "y.tab.c"
    break;

  case 198: /* null_expr: KEY_NULL  */
#line 601 "a.y"
                     { ((*yyvalp).node) = xnull(); }
#line 2818 "y.tab.c"
    break;

  case 199: /* common_types_expr: number_expr  */
#line 608 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2824 "y.tab.c"
    break;

  case 200: /* common_types_expr: string_expr  */
#line 609 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2830 "y.tab.c"
    break;

  case 201: /* common_types_expr: null_expr  */
#line 610 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2836 "y.tab.c"
    break;

  case 202: /* common_types_expr: lambda_stmt  */
#line 611 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2842 "y.tab.c"
    break;

  case 203: /* common_types_expr: bool_expr  */
#line 612 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2848 "y.tab.c"
    break;

  case 204: /* common_others_values_expr: id_expr  */
#line 616 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2854 "y.tab.c"
    break;

  case 205: /* common_others_values_expr: array_ele_stmt  */
#line 617 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2860 "y.tab.c"
    break;

  case 206: /* common_others_values_expr: class_member_stmt  */
#line 618 "a.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2866 "y.tab.c"
    break;

  case 207: /* common_others_values_expr: static_member_stmt  */
#line 619 "a.y"
                       { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2872 "y.tab.c"
    break;

  case 208: /* common_values_expr: common_others_values_expr  */
#line 623 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2878 "y.tab.c"
    break;

  case 209: /* common_values_expr: this_stmt  */
#line 624 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2884 "y.tab.c"
    break;

  case 210: /* common_values_expr: new_expr  */
#line 625 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2890 "y.tab.c"
    break;

  case 211: /* common_result_of_call_expr: self_inc_dec_stmt  */
#line 629 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2896 "y.tab.c"
    break;

  case 212: /* common_result_of_call_expr: call_statement  */
#line 630 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2902 "y.tab.c"
    break;

  case 213: /* common_result_of_call_expr: arithmetic_stmt  */
#line 631 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2908 "y.tab.c"
    break;

  case 214: /* common_result_of_call_expr: number_parentheses_stmt  */
#line 632 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2914 "y.tab.c"
    break;

  case 215: /* common_assignable_expr: common_others_values_expr  */
#line 636 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2920 "y.tab.c"
    break;

  case 216: /* common_number_expr: number_expr  */
#line 640 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2926 "y.tab.c"
    break;

  case 217: /* common_number_expr: common_values_expr  */
#line 641 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2932 "y.tab.c"
    break;

  case 218: /* common_number_expr: common_result_of_call_expr  */
#line 642 "a.y"
                                { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2938 "y.tab.c"
    break;

  case 219: /* common_object_expr: common_values_expr  */
#line 646 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2944 "y.tab.c"
    break;

  case 220: /* common_object_expr: call_statement  */
#line 647 "a.y"
                              { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2950 "y.tab.c"
    break;

  case 221: /* common_expr: common_types_expr  */
#line 656 "a.y"
                                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2956 "y.tab.c"
    break;

  case 222: /* common_expr: common_values_expr  */
#line 657 "a.y"
                                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2962 "y.tab.c"
    break;

  case 223: /* common_expr: common_result_of_call_expr  */
#line 658 "a.y"
                                         { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2968 "y.tab.c"
    break;

  case 224: /* common_expr: string_plus_stmt  */
#line 659 "a.y"
                                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2974 "y.tab.c"
    break;

  case 225: /* common_expr: logic_stmt  */
#line 660 "a.y"
                                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2980 "y.tab.c"
    break;


#line 2984 "y.tab.c"

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




#line 663 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
