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


#include "../include/YLlangX.h"
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
    XINTEGER = 258,                /* XINTEGER  */
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
    RESTRICT = 270,                /* RESTRICT  */
    THIS = 271,                    /* THIS  */
    EXTENDS = 272,                 /* EXTENDS  */
    ARRAY_ELE = 273,               /* ARRAY_ELE  */
    XTRY = 274,                    /* XTRY  */
    XCATCH = 275,                  /* XCATCH  */
    LEFT_SHIFT = 276,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 277,             /* RIGHT_SHIFT  */
    XPUBLIC = 278,                 /* XPUBLIC  */
    XSET = 279,                    /* XSET  */
    XIS = 280,                     /* XIS  */
    SCOPE = 281,                   /* SCOPE  */
    SCOPE_FUNC_CALL = 282,         /* SCOPE_FUNC_CALL  */
    REF = 283,                     /* REF  */
    XCONTINUE = 284,               /* XCONTINUE  */
    IF = 285,                      /* IF  */
    ELSE = 286,                    /* ELSE  */
    WHILE = 287,                   /* WHILE  */
    FOR = 288,                     /* FOR  */
    DELETE = 289,                  /* DELETE  */
    BREAK = 290,                   /* BREAK  */
    RETURN = 291,                  /* RETURN  */
    SWITCH = 292,                  /* SWITCH  */
    CASE = 293,                    /* CASE  */
    DEFAULT = 294,                 /* DEFAULT  */
    CASE_LIST = 295,               /* CASE_LIST  */
    CLAXX_BODY = 296,              /* CLAXX_BODY  */
    NEW = 297,                     /* NEW  */
    CLAXX_MEMBER = 298,            /* CLAXX_MEMBER  */
    CLAXX_FUNC_CALL = 299,         /* CLAXX_FUNC_CALL  */
    XNULL = 300,                   /* XNULL  */
    REQUIRE = 301,                 /* REQUIRE  */
    REQUIRE_ONCE = 302,            /* REQUIRE_ONCE  */
    XINCLUDE = 303,                /* XINCLUDE  */
    AUTO = 304,                    /* AUTO  */
    XCONST = 305,                  /* XCONST  */
    XLOCAL = 306,                  /* XLOCAL  */
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
    NONASSOC = 318,                /* NONASSOC  */
    IFX = 319,                     /* IFX  */
    PIPELINE_OP = 320,             /* PIPELINE_OP  */
    PRIORITY3 = 321,               /* PRIORITY3  */
    PRIORITY2 = 322,               /* PRIORITY2  */
    PRIORITY1 = 323,               /* PRIORITY1  */
    UMINUS = 324                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define XINTEGER 258
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
#define RESTRICT 270
#define THIS 271
#define EXTENDS 272
#define ARRAY_ELE 273
#define XTRY 274
#define XCATCH 275
#define LEFT_SHIFT 276
#define RIGHT_SHIFT 277
#define XPUBLIC 278
#define XSET 279
#define XIS 280
#define SCOPE 281
#define SCOPE_FUNC_CALL 282
#define REF 283
#define XCONTINUE 284
#define IF 285
#define ELSE 286
#define WHILE 287
#define FOR 288
#define DELETE 289
#define BREAK 290
#define RETURN 291
#define SWITCH 292
#define CASE 293
#define DEFAULT 294
#define CASE_LIST 295
#define CLAXX_BODY 296
#define NEW 297
#define CLAXX_MEMBER 298
#define CLAXX_FUNC_CALL 299
#define XNULL 300
#define REQUIRE 301
#define REQUIRE_ONCE 302
#define XINCLUDE 303
#define AUTO 304
#define XCONST 305
#define XLOCAL 306
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
#define NONASSOC 318
#define IFX 319
#define PIPELINE_OP 320
#define PRIORITY3 321
#define PRIORITY2 322
#define PRIORITY1 323
#define UMINUS 324

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

#line 277 "y.tab.c"

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
  YYSYMBOL_XINTEGER = 3,                   /* XINTEGER  */
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
  YYSYMBOL_RESTRICT = 15,                  /* RESTRICT  */
  YYSYMBOL_THIS = 16,                      /* THIS  */
  YYSYMBOL_EXTENDS = 17,                   /* EXTENDS  */
  YYSYMBOL_ARRAY_ELE = 18,                 /* ARRAY_ELE  */
  YYSYMBOL_XTRY = 19,                      /* XTRY  */
  YYSYMBOL_XCATCH = 20,                    /* XCATCH  */
  YYSYMBOL_LEFT_SHIFT = 21,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 22,               /* RIGHT_SHIFT  */
  YYSYMBOL_XPUBLIC = 23,                   /* XPUBLIC  */
  YYSYMBOL_XSET = 24,                      /* XSET  */
  YYSYMBOL_XIS = 25,                       /* XIS  */
  YYSYMBOL_SCOPE = 26,                     /* SCOPE  */
  YYSYMBOL_SCOPE_FUNC_CALL = 27,           /* SCOPE_FUNC_CALL  */
  YYSYMBOL_REF = 28,                       /* REF  */
  YYSYMBOL_XCONTINUE = 29,                 /* XCONTINUE  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_WHILE = 32,                     /* WHILE  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_DELETE = 34,                    /* DELETE  */
  YYSYMBOL_BREAK = 35,                     /* BREAK  */
  YYSYMBOL_RETURN = 36,                    /* RETURN  */
  YYSYMBOL_SWITCH = 37,                    /* SWITCH  */
  YYSYMBOL_CASE = 38,                      /* CASE  */
  YYSYMBOL_DEFAULT = 39,                   /* DEFAULT  */
  YYSYMBOL_CASE_LIST = 40,                 /* CASE_LIST  */
  YYSYMBOL_CLAXX_BODY = 41,                /* CLAXX_BODY  */
  YYSYMBOL_NEW = 42,                       /* NEW  */
  YYSYMBOL_CLAXX_MEMBER = 43,              /* CLAXX_MEMBER  */
  YYSYMBOL_CLAXX_FUNC_CALL = 44,           /* CLAXX_FUNC_CALL  */
  YYSYMBOL_XNULL = 45,                     /* XNULL  */
  YYSYMBOL_REQUIRE = 46,                   /* REQUIRE  */
  YYSYMBOL_REQUIRE_ONCE = 47,              /* REQUIRE_ONCE  */
  YYSYMBOL_XINCLUDE = 48,                  /* XINCLUDE  */
  YYSYMBOL_AUTO = 49,                      /* AUTO  */
  YYSYMBOL_XCONST = 50,                    /* XCONST  */
  YYSYMBOL_XLOCAL = 51,                    /* XLOCAL  */
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
  YYSYMBOL_NONASSOC = 65,                  /* NONASSOC  */
  YYSYMBOL_IFX = 66,                       /* IFX  */
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
  YYSYMBOL_80_ = 80,                       /* '('  */
  YYSYMBOL_81_ = 81,                       /* ')'  */
  YYSYMBOL_82_ = 82,                       /* '['  */
  YYSYMBOL_83_ = 83,                       /* ']'  */
  YYSYMBOL_84_ = 84,                       /* '.'  */
  YYSYMBOL_PRIORITY3 = 85,                 /* PRIORITY3  */
  YYSYMBOL_PRIORITY2 = 86,                 /* PRIORITY2  */
  YYSYMBOL_PRIORITY1 = 87,                 /* PRIORITY1  */
  YYSYMBOL_UMINUS = 88,                    /* UMINUS  */
  YYSYMBOL_89_ = 89,                       /* ';'  */
  YYSYMBOL_90_ = 90,                       /* '{'  */
  YYSYMBOL_91_ = 91,                       /* '}'  */
  YYSYMBOL_92_ = 92,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_program = 94,                   /* program  */
  YYSYMBOL_statement_list = 95,            /* statement_list  */
  YYSYMBOL_statement = 96,                 /* statement  */
  YYSYMBOL__extra_nothing = 97,            /* _extra_nothing  */
  YYSYMBOL_out_declar_stmt = 98,           /* out_declar_stmt  */
  YYSYMBOL_require_stmt = 99,              /* require_stmt  */
  YYSYMBOL_require_operators = 100,        /* require_operators  */
  YYSYMBOL_try_stmt = 101,                 /* try_stmt  */
  YYSYMBOL_catch_block_stmt = 102,         /* catch_block_stmt  */
  YYSYMBOL_namespace_declar_stmt = 103,    /* namespace_declar_stmt  */
  YYSYMBOL_namespace_ref_stmt = 104,       /* namespace_ref_stmt  */
  YYSYMBOL_namespace_name_stmt = 105,      /* namespace_name_stmt  */
  YYSYMBOL_class_declar_stmt = 106,        /* class_declar_stmt  */
  YYSYMBOL_class_name_prefix = 107,        /* class_name_prefix  */
  YYSYMBOL_class_name_suffix = 108,        /* class_name_suffix  */
  YYSYMBOL_class_body = 109,               /* class_body  */
  YYSYMBOL_class_body_items = 110,         /* class_body_items  */
  YYSYMBOL_class_body_item = 111,          /* class_body_item  */
  YYSYMBOL_this_stmt = 112,                /* this_stmt  */
  YYSYMBOL_class_member_stmt = 113,        /* class_member_stmt  */
  YYSYMBOL_static_member_stmt = 114,       /* static_member_stmt  */
  YYSYMBOL_func_declar_stmt = 115,         /* func_declar_stmt  */
  YYSYMBOL_func_name_types = 116,          /* func_name_types  */
  YYSYMBOL_func_param_list = 117,          /* func_param_list  */
  YYSYMBOL_lambda_stmt = 118,              /* lambda_stmt  */
  YYSYMBOL_lambda_args_stmt = 119,         /* lambda_args_stmt  */
  YYSYMBOL_var_declar_stmt = 120,          /* var_declar_stmt  */
  YYSYMBOL_var_prefix = 121,               /* var_prefix  */
  YYSYMBOL__elements_var_declar_stmt = 122, /* _elements_var_declar_stmt  */
  YYSYMBOL_element_var_declar_stmt = 123,  /* element_var_declar_stmt  */
  YYSYMBOL_con_ctl_stmt = 124,             /* con_ctl_stmt  */
  YYSYMBOL_selection_stmt = 125,           /* selection_stmt  */
  YYSYMBOL_if_stmt = 126,                  /* if_stmt  */
  YYSYMBOL_single_if_stmt = 127,           /* single_if_stmt  */
  YYSYMBOL_else_stmt = 128,                /* else_stmt  */
  YYSYMBOL_else_if_stmts = 129,            /* else_if_stmts  */
  YYSYMBOL_else_if_stmt = 130,             /* else_if_stmt  */
  YYSYMBOL_single_else_stmt = 131,         /* single_else_stmt  */
  YYSYMBOL_case_stmt_list = 132,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 133,                /* case_stmt  */
  YYSYMBOL_loop_stmt = 134,                /* loop_stmt  */
  YYSYMBOL_for_logic_stmt = 135,           /* for_logic_stmt  */
  YYSYMBOL_for_1_stmt_list = 136,          /* for_1_stmt_list  */
  YYSYMBOL_for_1_stmt = 137,               /* for_1_stmt  */
  YYSYMBOL_for_3_stmt_list = 138,          /* for_3_stmt_list  */
  YYSYMBOL_for_3_stmt = 139,               /* for_3_stmt  */
  YYSYMBOL_simple_stmt = 140,              /* simple_stmt  */
  YYSYMBOL_simple_stmt_types = 141,        /* simple_stmt_types  */
  YYSYMBOL_restrict_stmt = 142,            /* restrict_stmt  */
  YYSYMBOL_interrupt_stmt = 143,           /* interrupt_stmt  */
  YYSYMBOL_call_statement = 144,           /* call_statement  */
  YYSYMBOL_arithmetic_stmt = 145,          /* arithmetic_stmt  */
  YYSYMBOL_new_expr = 146,                 /* new_expr  */
  YYSYMBOL_args_list_with_parentheses = 147, /* args_list_with_parentheses  */
  YYSYMBOL_args_list = 148,                /* args_list  */
  YYSYMBOL_delete_expr = 149,              /* delete_expr  */
  YYSYMBOL_logic_stmt = 150,               /* logic_stmt  */
  YYSYMBOL__symbol_logic_connection = 151, /* _symbol_logic_connection  */
  YYSYMBOL_bool_param_expr = 152,          /* bool_param_expr  */
  YYSYMBOL_type_judge_stmt = 153,          /* type_judge_stmt  */
  YYSYMBOL_not_bool_param_expr = 154,      /* not_bool_param_expr  */
  YYSYMBOL_compare_expr = 155,             /* compare_expr  */
  YYSYMBOL_number_compare_expr = 156,      /* number_compare_expr  */
  YYSYMBOL_object_compare_expr = 157,      /* object_compare_expr  */
  YYSYMBOL__symbol_compare = 158,          /* _symbol_compare  */
  YYSYMBOL__symbol_equals_not = 159,       /* _symbol_equals_not  */
  YYSYMBOL_self_inc_dec_stmt = 160,        /* self_inc_dec_stmt  */
  YYSYMBOL_self_inc_dec_operators = 161,   /* self_inc_dec_operators  */
  YYSYMBOL_assign_stmt_value_eq = 162,     /* assign_stmt_value_eq  */
  YYSYMBOL_array_ele_stmt = 163,           /* array_ele_stmt  */
  YYSYMBOL_assign_stmt = 164,              /* assign_stmt  */
  YYSYMBOL_single_assign_stmt = 165,       /* single_assign_stmt  */
  YYSYMBOL_single_assign_stmt_value = 166, /* single_assign_stmt_value  */
  YYSYMBOL_number_change_assign_stmt = 167, /* number_change_assign_stmt  */
  YYSYMBOL_symbol_change_assign = 168,     /* symbol_change_assign  */
  YYSYMBOL_code_block = 169,               /* code_block  */
  YYSYMBOL_block_item_list = 170,          /* block_item_list  */
  YYSYMBOL_block_item = 171,               /* block_item  */
  YYSYMBOL_string_plus_stmt = 172,         /* string_plus_stmt  */
  YYSYMBOL_string_plus_stmt_value = 173,   /* string_plus_stmt_value  */
  YYSYMBOL_number_parentheses_stmt = 174,  /* number_parentheses_stmt  */
  YYSYMBOL_id_expr = 175,                  /* id_expr  */
  YYSYMBOL_multiple_id_expr = 176,         /* multiple_id_expr  */
  YYSYMBOL_bool_expr = 177,                /* bool_expr  */
  YYSYMBOL_number_expr = 178,              /* number_expr  */
  YYSYMBOL_positive_number_expr = 179,     /* positive_number_expr  */
  YYSYMBOL_int_expr = 180,                 /* int_expr  */
  YYSYMBOL_double_expr = 181,              /* double_expr  */
  YYSYMBOL_uminus_expr = 182,              /* uminus_expr  */
  YYSYMBOL_uminus_expr_values = 183,       /* uminus_expr_values  */
  YYSYMBOL_string_expr = 184,              /* string_expr  */
  YYSYMBOL_null_expr = 185,                /* null_expr  */
  YYSYMBOL_common_types_expr = 186,        /* common_types_expr  */
  YYSYMBOL_common_others_values_expr = 187, /* common_others_values_expr  */
  YYSYMBOL_common_values_expr = 188,       /* common_values_expr  */
  YYSYMBOL_common_result_of_call_expr = 189, /* common_result_of_call_expr  */
  YYSYMBOL_common_assignable_expr = 190,   /* common_assignable_expr  */
  YYSYMBOL_common_number_expr = 191,       /* common_number_expr  */
  YYSYMBOL_common_object_expr = 192,       /* common_object_expr  */
  YYSYMBOL_common_expr = 193               /* common_expr  */
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
#define YYLAST   836

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  341

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   324


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
      80,    81,    75,    73,    67,    74,    84,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    92,    89,
      62,    69,    61,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    71,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,    70,    91,    79,     2,     2,     2,
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
      68,    85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    76,    76,    80,    81,    84,    85,    86,    87,    88,
      92,    96,    97,    98,    99,   104,   108,   109,   110,   115,
     116,   120,   126,   131,   135,   136,   146,   150,   151,   156,
     157,   161,   162,   166,   167,   171,   172,   173,   174,   179,
     185,   190,   200,   201,   205,   206,   207,   211,   212,   217,
     221,   222,   223,   228,   229,   233,   234,   238,   239,   243,
     244,   249,   250,   255,   256,   260,   261,   265,   269,   270,
     274,   275,   279,   283,   287,   288,   292,   293,   297,   298,
     302,   303,   307,   308,   309,   314,   320,   321,   322,   327,
     328,   333,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   350,   351,   355,   356,   357,   358,   363,   364,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     384,   388,   389,   393,   394,   398,   404,   405,   406,   407,
     408,   412,   413,   418,   419,   424,   428,   433,   434,   438,
     442,   446,   447,   448,   449,   450,   451,   455,   456,   461,
     462,   466,   467,   473,   474,   475,   483,   488,   489,   493,
     497,   498,   502,   506,   507,   508,   509,   510,   515,   516,
     520,   521,   525,   526,   527,   528,   533,   534,   538,   539,
     540,   541,   542,   546,   552,   556,   557,   561,   565,   566,
     570,   571,   575,   579,   583,   587,   588,   589,   590,   594,
     598,   605,   606,   607,   608,   609,   613,   614,   615,   616,
     620,   621,   622,   626,   627,   628,   629,   633,   637,   638,
     639,   643,   644,   653,   654,   655,   656
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
  "\"end of file\"", "error", "\"invalid token\"", "XINTEGER", "TBOOL",
  "TDOUBLE", "IDENTIFIER", "TSTRING", "OPERATOR_X__", "OP_CALC", "AND_OP",
  "OR_OP", "FUNC_OP", "FUNC_CALL", "VAR_DECLAR", "RESTRICT", "THIS",
  "EXTENDS", "ARRAY_ELE", "XTRY", "XCATCH", "LEFT_SHIFT", "RIGHT_SHIFT",
  "XPUBLIC", "XSET", "XIS", "SCOPE", "SCOPE_FUNC_CALL", "REF", "XCONTINUE",
  "IF", "ELSE", "WHILE", "FOR", "DELETE", "BREAK", "RETURN", "SWITCH",
  "CASE", "DEFAULT", "CASE_LIST", "CLAXX_BODY", "NEW", "CLAXX_MEMBER",
  "CLAXX_FUNC_CALL", "XNULL", "REQUIRE", "REQUIRE_ONCE", "XINCLUDE",
  "AUTO", "XCONST", "XLOCAL", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ",
  "MOD_EQ", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "'>'", "'<'", "INC_OP",
  "DEC_OP", "NONASSOC", "IFX", "','", "PIPELINE_OP", "'='", "'|'", "'^'",
  "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "'('", "')'",
  "'['", "']'", "'.'", "PRIORITY3", "PRIORITY2", "PRIORITY1", "UMINUS",
  "';'", "'{'", "'}'", "':'", "$accept", "program", "statement_list",
  "statement", "_extra_nothing", "out_declar_stmt", "require_stmt",
  "require_operators", "try_stmt", "catch_block_stmt",
  "namespace_declar_stmt", "namespace_ref_stmt", "namespace_name_stmt",
  "class_declar_stmt", "class_name_prefix", "class_name_suffix",
  "class_body", "class_body_items", "class_body_item", "this_stmt",
  "class_member_stmt", "static_member_stmt", "func_declar_stmt",
  "func_name_types", "func_param_list", "lambda_stmt", "lambda_args_stmt",
  "var_declar_stmt", "var_prefix", "_elements_var_declar_stmt",
  "element_var_declar_stmt", "con_ctl_stmt", "selection_stmt", "if_stmt",
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
     315,    62,    60,   316,   317,   318,   319,    44,   320,    61,
     124,    94,    38,    43,    45,    42,    47,    37,    33,   126,
      40,    41,    91,    93,    46,   321,   322,   323,   324,    59,
     123,   125,    58
};
#endif

#define YYPACT_NINF (-267)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-226)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -267,    59,   546,  -267,  -267,  -267,    15,  -267,   -46,    45,
     107,  -267,    40,    49,    68,   107,  -267,   623,    72,   107,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,   107,  -267,
    -267,  -267,  -267,  -267,   121,  -267,  -267,  -267,  -267,   107,
    -267,  -267,  -267,  -267,   139,  -267,   107,    96,  -267,  -267,
    -267,  -267,   141,  -267,  -267,    87,  -267,  -267,    57,   100,
    -267,  -267,   213,  -267,  -267,  -267,  -267,    44,   272,    -9,
     382,   129,  -267,  -267,   334,   182,   138,   126,  -267,   637,
     637,   213,  -267,   163,  -267,  -267,  -267,  -267,    19,   689,
     595,  -267,   214,   132,  -267,  -267,   176,   180,   181,   202,
      54,   163,  -267,   158,  -267,  -267,  -267,  -267,   205,  -267,
     206,  -267,   437,    51,   749,   129,  -267,   689,   152,  -267,
    -267,   243,   -54,    96,   208,   107,    34,  -267,   141,  -267,
    -267,  -267,   107,   207,   266,   190,   107,   689,   542,  -267,
    -267,  -267,  -267,  -267,  -267,  -267,   623,   689,   689,   107,
    -267,  -267,  -267,  -267,  -267,   447,  -267,   123,   222,  -267,
     107,   107,   646,   689,     3,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -267,    36,   311,    38,   739,   133,
      42,    16,  -267,  -267,   152,   107,    57,  -267,  -267,  -267,
     342,  -267,   187,  -267,  -267,  -267,   -24,   702,   -46,   121,
     677,   689,   689,   689,   689,   689,   689,   689,   689,   689,
     689,   714,  -267,   107,   203,    33,   -46,  -267,  -267,  -267,
    -267,  -267,  -267,   152,  -267,   337,  -267,    97,  -267,  -267,
    -267,   236,  -267,   749,   384,  -267,  -267,  -267,   107,   126,
    -267,  -267,  -267,  -267,   -46,   637,  -267,  -267,  -267,  -267,
    -267,  -267,   689,   107,  -267,  -267,    24,   -46,   213,   637,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,   161,   161,   759,   223,   395,   165,   165,  -267,  -267,
    -267,   217,   163,   423,  -267,  -267,   114,  -267,  -267,  -267,
     623,  -267,  -267,   231,  -267,    80,   749,  -267,    35,  -267,
    -267,  -267,  -267,   248,    80,    71,  -267,  -267,   480,  -267,
    -267,   253,   256,  -267,  -267,   -46,   159,   344,   259,    -6,
    -267,  -267,  -267,  -267,  -267,  -267,   115,  -267,  -267,  -267,
     260,   -46,  -267,  -267,   159,   -46,   -46,  -267,  -267,  -267,
    -267
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   184,    46,   101,    39,     0,     0,
       0,   106,     0,     0,     0,     0,   103,   104,     0,     0,
      16,    17,    18,    28,    55,    56,   151,   152,     0,    10,
       3,     5,     6,    99,     0,     9,    13,    14,    12,     0,
     211,   208,   209,    11,     0,   100,     0,    53,    57,     7,
      61,    63,    65,    62,     8,     0,    98,    96,    94,   212,
      95,    92,     0,   207,    93,   157,   158,   206,   210,   221,
       0,     0,   187,   102,     0,    19,     0,    23,    24,     0,
       0,    82,   185,   125,   192,   193,   199,   200,     0,     0,
       0,   204,     0,   214,   215,   212,   213,   226,     0,   216,
     206,    52,   205,   218,   188,   191,   190,   189,   202,   203,
     223,   210,   219,   220,     0,   178,   105,     0,     0,    45,
      15,    29,     0,    54,    59,     0,     0,    66,     0,    70,
      69,    91,     0,   222,   206,   149,     0,     0,     0,   107,
     150,   163,   164,   165,   166,   167,     0,     0,     0,     0,
     168,   175,   172,   174,   173,     0,   170,   206,     0,    20,
       0,     0,     0,     0,     0,   126,   128,   127,   129,   137,
     138,   213,   133,   216,   134,   218,   219,   220,     0,     0,
       0,     0,    83,    85,   221,     0,   197,   198,   195,   194,
     196,   218,   219,   220,   119,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   120,     0,     0,     0,     0,    42,    58,    72,
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
    -267,  -267,  -267,  -267,     2,  -267,  -267,  -267,   346,  -267,
    -267,  -267,   194,  -267,  -267,  -267,  -267,  -267,    47,  -267,
    -267,  -267,   358,  -267,  -267,  -267,  -267,  -266,  -267,   315,
     237,   363,  -267,  -267,   246,  -267,  -267,   245,   250,  -267,
      60,  -267,  -267,  -267,   125,  -267,    52,   387,  -267,  -267,
    -267,     0,  -267,    32,  -111,  -267,  -267,   -68,  -267,   228,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,    -1,   -61,  -267,
    -267,   -70,  -140,  -267,  -267,  -267,     8,  -267,   239,   196,
     199,     4,    48,     5,    17,    21,   313,    85,  -267,  -267,
    -267,   -29,  -267,  -163,     1,    -2,    23,  -137,   240,    28,
    -128
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    30,   151,    32,    33,    34,   152,   159,
      36,    37,    77,    38,    39,   214,   284,   308,   309,    40,
      41,    42,   310,    44,   216,    91,    92,    45,    46,    47,
      48,   153,    50,    51,    52,   127,   128,   129,   130,   319,
     320,    53,   303,   181,   182,   326,   327,   154,    55,    56,
      57,    93,    94,    95,   139,   227,    60,   164,   245,   165,
     166,   167,   168,   169,   170,   252,   256,   171,    62,   172,
      63,    64,    65,   230,    66,   147,    75,   155,   156,    97,
      98,   173,   134,   101,   102,   191,   104,   105,   106,   107,
     189,   108,   109,   110,   111,   192,   193,    70,   114,    71,
     116
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    61,    58,    68,    31,   120,   229,   212,   140,   231,
     228,   183,   180,   242,   243,   112,    96,   311,   232,    72,
      83,    99,    84,    73,    85,     4,   215,    84,    72,    85,
       4,    86,   317,   318,    59,     7,    74,   270,   103,     4,
     113,     4,   311,   185,    74,   115,  -153,  -153,  -155,  -155,
      67,   140,   242,   243,    26,    27,   -44,   261,    78,     3,
     135,    19,   133,    82,    12,   100,  -185,   118,    76,    87,
     136,   138,    69,    61,    58,    68,   119,   176,   176,   184,
     136,   133,    68,   258,   244,   332,   184,   121,   186,   190,
     242,   243,   187,   300,   124,   196,   174,   174,    88,   163,
     175,   175,   177,   177,   298,   259,    59,   179,   179,   317,
     318,   -59,   288,     4,   285,   140,   195,  -153,  -225,  -155,
      79,  -185,   157,   257,    74,  -153,   137,  -155,    86,    80,
     217,   140,  -225,   -59,   220,  -185,   112,    96,   100,  -222,
    -225,   132,    99,   312,   112,    96,   231,    68,    81,   136,
      99,   122,   117,    69,    61,    58,    68,  -222,   253,   103,
     176,   113,   314,   125,   290,     4,   115,   103,   312,   113,
     264,   231,   126,   124,   115,     7,   131,   295,   291,   174,
     223,   185,   334,   175,   224,   177,   100,    59,   183,   -97,
     -59,   304,   254,   255,   100,   313,   335,   235,    69,   265,
     133,    19,   158,   157,   268,   137,   263,   160,    78,   240,
     161,   148,   -59,   149,  -222,   148,   132,   149,   282,     4,
     286,   269,    26,    27,   287,  -201,   198,   299,   115,     7,
     185,  -201,   138,   260,   206,   207,   208,   209,   210,  -201,
     208,   209,   210,   176,   201,   202,   329,  -201,   100,  -181,
      26,    27,   294,  -180,   199,    19,   184,   176,   133,    68,
     213,    82,   174,    82,   329,   301,   175,   138,   177,  -221,
     138,  -221,  -221,   179,  -221,  -182,   174,   269,   200,  -179,
     175,   184,   177,   133,    68,   307,   293,   179,   112,    96,
     137,   132,   136,   283,    99,   205,   206,   207,   208,   209,
     210,   297,   238,   196,    82,   146,   184,   305,   133,    68,
     307,   103,   315,   113,    69,   328,   133,    68,   115,   178,
     178,  -154,  -154,   325,  -217,  -217,  -217,  -217,  -217,   194,
     197,    67,    69,   328,   133,    68,  -221,   316,   100,   337,
       4,  -217,   323,   339,   340,   324,    82,    84,    35,     6,
       7,   331,   336,     8,   239,   322,    67,   211,   201,   202,
      43,   123,   218,    11,    12,    49,    13,    14,    15,    16,
      17,    18,   219,   221,    26,    27,    19,   225,   222,   333,
      20,    21,    22,   302,    24,    25,   338,   233,   234,    54,
     241,   138,  -154,  -221,   237,  -221,   266,    26,    27,   267,
    -154,   188,   330,   197,     0,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,   201,   202,     0,     0,
     289,     0,  -210,    29,  -210,   150,  -210,     0,     0,     4,
       0,     5,     0,     0,   141,   142,   143,   144,   145,     7,
       0,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   146,     0,     4,   203,   204,   205,   206,   207,   208,
     209,   210,     6,     7,     0,    19,     8,   292,   206,   207,
     208,   209,   210,    24,    25,     0,    11,    12,     0,    13,
      14,    15,    16,    17,    18,   178,     4,     0,     5,    19,
       0,     0,   296,    20,    21,    22,     7,    24,    25,   178,
      26,    27,    28,     0,  -224,     0,     0,     0,     0,     0,
      26,    27,    29,     0,   306,     0,     0,   138,  -224,  -221,
       0,  -221,    19,     0,     0,     0,  -224,     0,     0,     0,
      24,    25,     0,     0,     0,     0,    29,     0,   236,     0,
       0,     0,     0,     0,     0,    84,    72,    85,     4,    86,
       0,     0,     4,     0,     5,     0,     0,     0,     7,    28,
       0,     6,     7,     0,     0,     8,     0,     0,     0,    29,
       9,   321,     0,     0,    10,    11,    12,     0,    13,    14,
      15,    16,    17,    18,    19,     0,     0,    87,    19,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    84,     0,
      85,     4,     0,     0,     0,    26,    27,     0,     0,    26,
      27,     7,     0,     0,     0,     0,    88,     0,     0,     0,
       0,    89,    90,   226,     0,    28,    84,    72,    85,     4,
      86,     0,     0,     0,     0,    29,     0,    19,     0,     7,
      84,    72,    85,     4,     0,     0,     0,     0,     0,    84,
      72,    85,     4,     7,     0,     0,     0,     0,    26,    27,
       0,     0,     7,     0,     0,    19,     0,     0,    87,    88,
       0,     0,     0,     0,    89,   163,   195,     0,     0,    19,
      84,    72,    85,     4,    86,     0,    26,    27,    19,     0,
       0,     0,    84,     7,    85,     4,     0,    88,     0,     0,
      26,    27,    89,    90,     0,     7,     0,     0,     0,    26,
      27,    88,     0,     0,     0,   162,    89,   163,     0,    19,
      88,     0,    87,   201,   202,    89,   163,     0,     0,     0,
       0,    19,     0,     0,     0,   201,   202,     0,     0,     0,
      26,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    26,    27,     0,     0,     0,    90,     0,     0,
     201,   202,     0,    88,     0,     0,     0,     0,    89,   163,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     201,   202,     0,   262,   203,   204,   205,   206,   207,   208,
     209,   210,     0,     0,     0,   281,   246,   247,   248,   249,
     250,   251,     0,     0,     0,     0,     0,     0,     0,   203,
     204,   205,   206,   207,   208,   209,   210,     0,     0,   203,
     204,   205,   206,   207,   208,   209,   210,     0,     0,     0,
     204,   205,   206,   207,   208,   209,   210
};

static const yytype_int16 yycheck[] =
{
       2,     2,     2,     2,     2,    34,   146,   118,    69,   146,
     138,    81,    80,    10,    11,    17,    17,   283,   146,     4,
      15,    17,     3,     6,     5,     6,    80,     3,     4,     5,
       6,     7,    38,    39,     2,    16,    90,   200,    17,     6,
      17,     6,   308,    67,    90,    17,    10,    11,    10,    11,
       2,   112,    10,    11,    63,    64,    12,    81,    10,     0,
      62,    42,    62,    15,    30,    17,    12,    19,    23,    45,
      26,    80,    74,    74,    74,    74,    28,    79,    80,    81,
      26,    81,    81,    67,    81,    91,    88,    39,    88,    88,
      10,    11,    88,   256,    46,    90,    79,    80,    74,    80,
      79,    80,    79,    80,    80,    89,    74,    79,    80,    38,
      39,    67,   223,     6,    81,   176,    81,    81,    67,    81,
      80,    67,    74,    81,    90,    89,    82,    89,     7,    80,
     122,   192,    81,    89,   126,    81,   138,   138,    90,    82,
      89,    84,   138,   283,   146,   146,   283,   146,    80,    26,
     146,    12,    80,   155,   155,   155,   155,    25,    25,   138,
     162,   138,   290,    67,    67,     6,   138,   146,   308,   146,
     199,   308,    31,   125,   146,    16,    89,   245,    81,   162,
     132,    67,    67,   162,   136,   162,   138,   155,   258,    89,
      67,   259,    59,    60,   146,    81,    81,   149,   200,   200,
     200,    42,    20,   155,   200,    82,   198,    69,   160,   161,
      84,    82,    89,    84,    82,    82,    84,    84,   213,     6,
     215,   200,    63,    64,   216,    67,    12,   256,   200,    16,
      67,    73,    80,   185,    73,    74,    75,    76,    77,    81,
      75,    76,    77,   245,    21,    22,   316,    89,   200,    73,
      63,    64,   244,    73,    73,    42,   258,   259,   258,   258,
      17,   213,   245,   215,   334,   257,   245,    80,   245,    82,
      80,    84,    82,   245,    84,    73,   259,   256,    73,    73,
     259,   283,   259,   283,   283,   283,   238,   259,   290,   290,
      82,    84,    26,    90,   290,    72,    73,    74,    75,    76,
      77,   253,    80,   298,   256,    69,   308,    90,   308,   308,
     308,   290,    81,   290,   316,   316,   316,   316,   290,    79,
      80,    10,    11,   315,    52,    53,    54,    55,    56,    89,
      90,   283,   334,   334,   334,   334,    25,    89,   290,   331,
       6,    69,    89,   335,   336,    89,   298,     3,     2,    15,
      16,    92,    92,    19,   160,   308,   308,   117,    21,    22,
       2,    46,   125,    29,    30,     2,    32,    33,    34,    35,
      36,    37,   126,   128,    63,    64,    42,   137,   128,   319,
      46,    47,    48,   258,    50,    51,   334,   147,   148,     2,
     162,    80,    81,    82,   155,    84,   200,    63,    64,   200,
      89,    88,   317,   163,    -1,    21,    22,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    21,    22,    -1,    -1,
      83,    -1,    80,    89,    82,    91,    84,    -1,    -1,     6,
      -1,     8,    -1,    -1,    52,    53,    54,    55,    56,    16,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    69,    -1,     6,    70,    71,    72,    73,    74,    75,
      76,    77,    15,    16,    -1,    42,    19,    83,    73,    74,
      75,    76,    77,    50,    51,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,   245,     6,    -1,     8,    42,
      -1,    -1,   252,    46,    47,    48,    16,    50,    51,   259,
      63,    64,    79,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      63,    64,    89,    -1,    91,    -1,    -1,    80,    81,    82,
      -1,    84,    42,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      50,    51,    -1,    -1,    -1,    -1,    89,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,     6,    -1,     8,    -1,    -1,    -1,    16,    79,
      -1,    15,    16,    -1,    -1,    19,    -1,    -1,    -1,    89,
      24,    91,    -1,    -1,    28,    29,    30,    -1,    32,    33,
      34,    35,    36,    37,    42,    -1,    -1,    45,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,     3,    -1,
       5,     6,    -1,    -1,    -1,    63,    64,    -1,    -1,    63,
      64,    16,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    79,    80,    81,    -1,    79,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    89,    -1,    42,    -1,    16,
       3,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    16,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    16,    -1,    -1,    42,    -1,    -1,    45,    74,
      -1,    -1,    -1,    -1,    79,    80,    81,    -1,    -1,    42,
       3,     4,     5,     6,     7,    -1,    63,    64,    42,    -1,
      -1,    -1,     3,    16,     5,     6,    -1,    74,    -1,    -1,
      63,    64,    79,    80,    -1,    16,    -1,    -1,    -1,    63,
      64,    74,    -1,    -1,    -1,    78,    79,    80,    -1,    42,
      74,    -1,    45,    21,    22,    79,    80,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    21,    22,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    63,    64,    -1,    -1,    -1,    80,    -1,    -1,
      21,    22,    -1,    74,    -1,    -1,    -1,    -1,    79,    80,
      21,    22,    70,    71,    72,    73,    74,    75,    76,    77,
      21,    22,    -1,    81,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    81,    57,    58,    59,    60,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    94,    95,     0,     6,     8,    15,    16,    19,    24,
      28,    29,    30,    32,    33,    34,    35,    36,    37,    42,
      46,    47,    48,    49,    50,    51,    63,    64,    79,    89,
      96,    97,    98,    99,   100,   101,   103,   104,   106,   107,
     112,   113,   114,   115,   116,   120,   121,   122,   123,   124,
     125,   126,   127,   134,   140,   141,   142,   143,   144,   146,
     149,   160,   161,   163,   164,   165,   167,   175,   187,   188,
     190,   192,     4,   177,    90,   169,    23,   105,   175,    80,
      80,    80,   175,   176,     3,     5,     7,    45,    74,    79,
      80,   118,   119,   144,   145,   146,   160,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   184,   185,
     186,   187,   188,   189,   191,   192,   193,    80,   175,   175,
     184,   175,    12,   122,   175,    67,    31,   128,   129,   130,
     131,    89,    84,   144,   175,   188,    26,    82,    80,   147,
     161,    52,    53,    54,    55,    56,    69,   168,    82,    84,
      91,    97,   101,   124,   140,   170,   171,   175,    20,   102,
      69,    84,    78,    80,   150,   152,   153,   154,   155,   156,
     157,   160,   162,   174,   177,   178,   188,   189,   191,   192,
     150,   136,   137,   164,   188,    67,   144,   174,   179,   183,
     187,   178,   188,   189,   191,    81,   176,   191,    12,    73,
      73,    21,    22,    70,    71,    72,    73,    74,    75,    76,
      77,   191,   147,    17,   108,    80,   117,   169,   123,   127,
     169,   130,   131,   175,   175,   191,    81,   148,   193,   165,
     166,   190,   193,   191,   191,   175,    91,   171,    80,   105,
     175,   152,    10,    11,    81,   151,    57,    58,    59,    60,
      61,    62,   158,    25,    59,    60,   159,    81,    67,    89,
     175,    81,    81,   169,   184,   160,   172,   173,   174,   178,
     186,   191,   191,   191,   191,   191,   191,   191,   191,   191,
     191,    81,   176,    90,   109,    81,   176,   169,   147,    83,
      67,    81,    83,   175,   169,   150,   191,   175,    80,   184,
     186,   169,   137,   135,   150,    90,    91,    97,   110,   111,
     115,   120,   165,    81,   193,    81,    89,    38,    39,   132,
     133,    91,   111,    89,    89,   169,   138,   139,   160,   164,
     180,    92,    91,   133,    67,    81,    92,   169,   139,   169,
     169
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    96,    96,    96,    96,    96,
      97,    98,    98,    98,    98,    99,   100,   100,   100,   101,
     101,   102,   103,   104,   105,   105,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   111,   111,   112,
     113,   114,   115,   115,   116,   116,   116,   117,   117,   118,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   127,   128,   128,
     129,   129,   130,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   136,   136,   137,   138,   138,   138,   139,
     139,   140,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   143,   143,   143,   143,   144,   144,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     146,   147,   147,   148,   148,   149,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   153,   154,   155,   155,   156,
     157,   158,   158,   158,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   162,   163,   164,   164,   165,
     166,   166,   167,   168,   168,   168,   168,   168,   169,   169,
     170,   170,   171,   171,   171,   171,   172,   172,   173,   173,
     173,   173,   173,   174,   175,   176,   176,   177,   178,   178,
     179,   179,   180,   181,   182,   183,   183,   183,   183,   184,
     185,   186,   186,   186,   186,   186,   187,   187,   187,   187,
     188,   188,   188,   189,   189,   189,   189,   190,   191,   191,
     191,   192,   192,   193,   193,   193,   193
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
#line 80 "a.y"
                                   { execAndFreeNode((yyvsp[0].node));}
#line 1839 "y.tab.c"
    break;

  case 5: /* statement: _extra_nothing  */
#line 84 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1845 "y.tab.c"
    break;

  case 6: /* statement: out_declar_stmt  */
#line 85 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 1851 "y.tab.c"
    break;

  case 7: /* statement: con_ctl_stmt  */
#line 86 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1857 "y.tab.c"
    break;

  case 8: /* statement: simple_stmt  */
#line 87 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1863 "y.tab.c"
    break;

  case 9: /* statement: try_stmt  */
#line 88 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 1869 "y.tab.c"
    break;

  case 10: /* _extra_nothing: ';'  */
#line 92 "a.y"
                { (yyval.node) = NULL; }
#line 1875 "y.tab.c"
    break;

  case 11: /* out_declar_stmt: func_declar_stmt  */
#line 96 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1881 "y.tab.c"
    break;

  case 12: /* out_declar_stmt: class_declar_stmt  */
#line 97 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1887 "y.tab.c"
    break;

  case 13: /* out_declar_stmt: namespace_declar_stmt  */
#line 98 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1893 "y.tab.c"
    break;

  case 14: /* out_declar_stmt: namespace_ref_stmt  */
#line 99 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 1899 "y.tab.c"
    break;

  case 15: /* require_stmt: require_operators string_expr  */
#line 104 "a.y"
                                                { (yyval.node) = opr((yyvsp[-1].iValue) , 1 , (yyvsp[0].node)); }
#line 1905 "y.tab.c"
    break;

  case 16: /* require_operators: REQUIRE  */
#line 108 "a.y"
                          { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1911 "y.tab.c"
    break;

  case 17: /* require_operators: REQUIRE_ONCE  */
#line 109 "a.y"
                          { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1917 "y.tab.c"
    break;

  case 18: /* require_operators: XINCLUDE  */
#line 110 "a.y"
                          { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1923 "y.tab.c"
    break;

  case 19: /* try_stmt: XTRY code_block  */
#line 115 "a.y"
                            { (yyval.node) = opr(XTRY, 2,(yyvsp[0].node),NULL); }
#line 1929 "y.tab.c"
    break;

  case 20: /* try_stmt: XTRY code_block catch_block_stmt  */
#line 116 "a.y"
                                            { (yyval.node) = opr(XTRY, 2,(yyvsp[-1].node),(yyvsp[0].node)); }
#line 1935 "y.tab.c"
    break;

  case 21: /* catch_block_stmt: XCATCH '(' id_expr ')' code_block  */
#line 120 "a.y"
                                             { (yyval.node) = opr(XCATCH, 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1941 "y.tab.c"
    break;

  case 22: /* namespace_declar_stmt: XSET XPUBLIC '=' namespace_name_stmt  */
#line 126 "a.y"
                                               { (yyval.node) = changeNameSpace((yyvsp[0].sValue)); }
#line 1947 "y.tab.c"
    break;

  case 23: /* namespace_ref_stmt: REF namespace_name_stmt  */
#line 131 "a.y"
                                    { (yyval.node) = opr(REF, 1, (yyvsp[0].sValue)); }
#line 1953 "y.tab.c"
    break;

  case 24: /* namespace_name_stmt: id_expr  */
#line 135 "a.y"
                   { (yyval.sValue) = (yyvsp[0].node) ; }
#line 1959 "y.tab.c"
    break;

  case 25: /* namespace_name_stmt: namespace_name_stmt '.' id_expr  */
#line 136 "a.y"
                                          { (yyval.sValue) = namespaceNameCat((yyvsp[-2].sValue),(yyvsp[0].node)) ; }
#line 1965 "y.tab.c"
    break;

  case 26: /* class_declar_stmt: class_name_prefix id_expr class_name_suffix class_body  */
#line 146 "a.y"
                                                                     {  (yyval.node) = NULL; }
#line 1971 "y.tab.c"
    break;

  case 27: /* class_name_prefix: %empty  */
#line 150 "a.y"
             { (yyval.iValue) = NULL; }
#line 1977 "y.tab.c"
    break;

  case 28: /* class_name_prefix: AUTO  */
#line 151 "a.y"
             { (yyval.iValue) = (yyvsp[0].iValue); }
#line 1983 "y.tab.c"
    break;

  case 29: /* class_name_suffix: %empty  */
#line 156 "a.y"
                              { (yyval.node) = NULL; }
#line 1989 "y.tab.c"
    break;

  case 30: /* class_name_suffix: EXTENDS multiple_id_expr  */
#line 157 "a.y"
                                    { (yyval.node) = NULL; }
#line 1995 "y.tab.c"
    break;

  case 31: /* class_body: '{' '}'  */
#line 161 "a.y"
                        { (yyval.node) = NULL; }
#line 2001 "y.tab.c"
    break;

  case 32: /* class_body: '{' class_body_items '}'  */
#line 162 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2007 "y.tab.c"
    break;

  case 33: /* class_body_items: class_body_item  */
#line 166 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2013 "y.tab.c"
    break;

  case 34: /* class_body_items: class_body_items class_body_item  */
#line 167 "a.y"
                                        { (yyval.node) = NULL; }
#line 2019 "y.tab.c"
    break;

  case 35: /* class_body_item: var_declar_stmt ';'  */
#line 171 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2025 "y.tab.c"
    break;

  case 36: /* class_body_item: single_assign_stmt ';'  */
#line 172 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2031 "y.tab.c"
    break;

  case 37: /* class_body_item: func_declar_stmt  */
#line 173 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2037 "y.tab.c"
    break;

  case 38: /* class_body_item: _extra_nothing  */
#line 174 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2043 "y.tab.c"
    break;

  case 39: /* this_stmt: THIS  */
#line 179 "a.y"
                  { (yyval.node) = opr(THIS , 0 ); }
#line 2049 "y.tab.c"
    break;

  case 40: /* class_member_stmt: common_object_expr '.' id_expr  */
#line 185 "a.y"
                                               { (yyval.node) = NULL; }
#line 2055 "y.tab.c"
    break;

  case 41: /* static_member_stmt: id_expr SCOPE id_expr  */
#line 190 "a.y"
                                  { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2061 "y.tab.c"
    break;

  case 42: /* func_declar_stmt: func_name_types FUNC_OP code_block  */
#line 200 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2067 "y.tab.c"
    break;

  case 43: /* func_declar_stmt: func_name_types FUNC_OP func_param_list code_block  */
#line 201 "a.y"
                                                                    { (yyval.node) = NULL; }
#line 2073 "y.tab.c"
    break;

  case 44: /* func_name_types: id_expr  */
#line 205 "a.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2079 "y.tab.c"
    break;

  case 45: /* func_name_types: '~' id_expr  */
#line 206 "a.y"
                    { (yyval.node) = NULL; }
#line 2085 "y.tab.c"
    break;

  case 46: /* func_name_types: OPERATOR_X__  */
#line 207 "a.y"
                    { (yyval.node) = NULL; }
#line 2091 "y.tab.c"
    break;

  case 47: /* func_param_list: '(' ')'  */
#line 211 "a.y"
                        { (yyval.node) = NULL; }
#line 2097 "y.tab.c"
    break;

  case 48: /* func_param_list: '(' multiple_id_expr ')'  */
#line 212 "a.y"
                                { (yyval.node) = (yyvsp[-1].node); }
#line 2103 "y.tab.c"
    break;

  case 49: /* lambda_stmt: lambda_args_stmt FUNC_OP code_block  */
#line 217 "a.y"
                                                { (yyval.node) = lambda((yyvsp[-2].params),(yyvsp[0].node)) ; }
#line 2109 "y.tab.c"
    break;

  case 50: /* lambda_args_stmt: '(' ')'  */
#line 221 "a.y"
                           { (yyval.params) = NULL; }
#line 2115 "y.tab.c"
    break;

  case 51: /* lambda_args_stmt: '(' multiple_id_expr ')'  */
#line 222 "a.y"
                                { (yyval.params) = (yyvsp[-1].node); }
#line 2121 "y.tab.c"
    break;

  case 52: /* lambda_args_stmt: multiple_id_expr  */
#line 223 "a.y"
                                { (yyval.params) = (yyvsp[0].node); }
#line 2127 "y.tab.c"
    break;

  case 53: /* var_declar_stmt: _elements_var_declar_stmt  */
#line 228 "a.y"
                                     { (yyval.node) = opr(VAR_DECLAR , 1, (yyvsp[0].node) ); }
#line 2133 "y.tab.c"
    break;

  case 54: /* var_declar_stmt: var_prefix _elements_var_declar_stmt  */
#line 229 "a.y"
                                               { (yyval.node) = NULL; }
#line 2139 "y.tab.c"
    break;

  case 55: /* var_prefix: XCONST  */
#line 233 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2145 "y.tab.c"
    break;

  case 56: /* var_prefix: XLOCAL  */
#line 234 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2151 "y.tab.c"
    break;

  case 57: /* _elements_var_declar_stmt: element_var_declar_stmt  */
#line 238 "a.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2157 "y.tab.c"
    break;

  case 58: /* _elements_var_declar_stmt: _elements_var_declar_stmt ',' element_var_declar_stmt  */
#line 239 "a.y"
                                                             { (yyval.node) = NULL; }
#line 2163 "y.tab.c"
    break;

  case 59: /* element_var_declar_stmt: id_expr  */
#line 243 "a.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2169 "y.tab.c"
    break;

  case 60: /* element_var_declar_stmt: id_expr '[' common_number_expr ']'  */
#line 244 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2175 "y.tab.c"
    break;

  case 61: /* con_ctl_stmt: selection_stmt  */
#line 249 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2181 "y.tab.c"
    break;

  case 62: /* con_ctl_stmt: loop_stmt  */
#line 250 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2187 "y.tab.c"
    break;

  case 63: /* selection_stmt: if_stmt  */
#line 255 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2193 "y.tab.c"
    break;

  case 64: /* selection_stmt: SWITCH '(' common_number_expr ')' '{' case_stmt_list '}'  */
#line 256 "a.y"
                                                                    { (yyval.node) = opr(SWITCH, 2 , (yyvsp[-4].node),(yyvsp[-1].node)); pretreatSwitch( (yyval.node) ) ; }
#line 2199 "y.tab.c"
    break;

  case 65: /* if_stmt: single_if_stmt  */
#line 260 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2205 "y.tab.c"
    break;

  case 66: /* if_stmt: single_if_stmt else_stmt  */
#line 261 "a.y"
                             { (yyval.node) = NULL; }
#line 2211 "y.tab.c"
    break;

  case 67: /* single_if_stmt: IF '(' logic_stmt ')' code_block  */
#line 265 "a.y"
                                     { (yyval.node) = opr(IF ,2,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2217 "y.tab.c"
    break;

  case 68: /* else_stmt: else_if_stmts single_else_stmt  */
#line 269 "a.y"
                                      { (yyval.node) =  NULL; }
#line 2223 "y.tab.c"
    break;

  case 69: /* else_stmt: single_else_stmt  */
#line 270 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2229 "y.tab.c"
    break;

  case 70: /* else_if_stmts: else_if_stmt  */
#line 274 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2235 "y.tab.c"
    break;

  case 71: /* else_if_stmts: else_if_stmts else_if_stmt  */
#line 275 "a.y"
                                  { (yyval.node) =  NULL; }
#line 2241 "y.tab.c"
    break;

  case 72: /* else_if_stmt: ELSE single_if_stmt  */
#line 279 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2247 "y.tab.c"
    break;

  case 73: /* single_else_stmt: ELSE code_block  */
#line 283 "a.y"
                        { (yyval.node) = NULL; }
#line 2253 "y.tab.c"
    break;

  case 74: /* case_stmt_list: case_stmt  */
#line 287 "a.y"
                               { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[0].node) ); }
#line 2259 "y.tab.c"
    break;

  case 75: /* case_stmt_list: case_stmt_list case_stmt  */
#line 288 "a.y"
                                   { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[-1].node), (yyvsp[0].node) ); }
#line 2265 "y.tab.c"
    break;

  case 76: /* case_stmt: CASE int_expr ':' code_block  */
#line 292 "a.y"
                                              { (yyval.node) = opr(CASE, 2 , (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2271 "y.tab.c"
    break;

  case 77: /* case_stmt: DEFAULT ':' code_block  */
#line 293 "a.y"
                                                 { (yyval.node) = opr(DEFAULT , 1, (yyvsp[0].node)); }
#line 2277 "y.tab.c"
    break;

  case 78: /* loop_stmt: WHILE '(' logic_stmt ')' code_block  */
#line 297 "a.y"
                                              { (yyval.node) = opr(WHILE , 2, (yyvsp[-2].node), (yyvsp[0].node) ); }
#line 2283 "y.tab.c"
    break;

  case 79: /* loop_stmt: FOR '(' for_1_stmt_list ';' for_logic_stmt ';' for_3_stmt_list ')' code_block  */
#line 298 "a.y"
                                                                                        { (yyval.node) = opr(FOR,4,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2289 "y.tab.c"
    break;

  case 80: /* for_logic_stmt: %empty  */
#line 302 "a.y"
          { (yyval.node) = NULL;  }
#line 2295 "y.tab.c"
    break;

  case 81: /* for_logic_stmt: logic_stmt  */
#line 303 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2301 "y.tab.c"
    break;

  case 82: /* for_1_stmt_list: %empty  */
#line 307 "a.y"
         { (yyval.node) = NULL ; }
#line 2307 "y.tab.c"
    break;

  case 83: /* for_1_stmt_list: for_1_stmt  */
#line 308 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2313 "y.tab.c"
    break;

  case 84: /* for_1_stmt_list: for_1_stmt_list ',' for_1_stmt  */
#line 309 "a.y"
                                      { (yyval.node) = NULL; }
#line 2319 "y.tab.c"
    break;

  case 85: /* for_1_stmt: assign_stmt  */
#line 314 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2325 "y.tab.c"
    break;

  case 86: /* for_3_stmt_list: %empty  */
#line 320 "a.y"
         { (yyval.node) = NULL ; }
#line 2331 "y.tab.c"
    break;

  case 87: /* for_3_stmt_list: for_3_stmt  */
#line 321 "a.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2337 "y.tab.c"
    break;

  case 88: /* for_3_stmt_list: for_3_stmt_list ',' for_3_stmt  */
#line 322 "a.y"
                                      { (yyval.node) = NULL; }
#line 2343 "y.tab.c"
    break;

  case 89: /* for_3_stmt: assign_stmt  */
#line 327 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2349 "y.tab.c"
    break;

  case 90: /* for_3_stmt: self_inc_dec_stmt  */
#line 328 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2355 "y.tab.c"
    break;

  case 91: /* simple_stmt: simple_stmt_types ';'  */
#line 333 "a.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 2361 "y.tab.c"
    break;

  case 92: /* simple_stmt_types: self_inc_dec_stmt  */
#line 337 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2367 "y.tab.c"
    break;

  case 93: /* simple_stmt_types: assign_stmt  */
#line 338 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2373 "y.tab.c"
    break;

  case 94: /* simple_stmt_types: call_statement  */
#line 339 "a.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 2379 "y.tab.c"
    break;

  case 95: /* simple_stmt_types: delete_expr  */
#line 340 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2385 "y.tab.c"
    break;

  case 96: /* simple_stmt_types: interrupt_stmt  */
#line 341 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2391 "y.tab.c"
    break;

  case 97: /* simple_stmt_types: new_expr  */
#line 342 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2397 "y.tab.c"
    break;

  case 98: /* simple_stmt_types: restrict_stmt  */
#line 343 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2403 "y.tab.c"
    break;

  case 99: /* simple_stmt_types: require_stmt  */
#line 344 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2409 "y.tab.c"
    break;

  case 100: /* simple_stmt_types: var_declar_stmt  */
#line 345 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2415 "y.tab.c"
    break;

  case 101: /* restrict_stmt: RESTRICT  */
#line 350 "a.y"
                         { (yyval.node) = opr(RESTRICT,0);}
#line 2421 "y.tab.c"
    break;

  case 102: /* restrict_stmt: RESTRICT bool_expr  */
#line 351 "a.y"
                              { (yyval.node) = opr(RESTRICT,1,(yyvsp[0].node)); }
#line 2427 "y.tab.c"
    break;

  case 103: /* interrupt_stmt: BREAK  */
#line 355 "a.y"
                { (yyval.node) = opr(BREAK, 0); }
#line 2433 "y.tab.c"
    break;

  case 104: /* interrupt_stmt: RETURN  */
#line 356 "a.y"
                 { (yyval.node) = opr(RETURN , 0); }
#line 2439 "y.tab.c"
    break;

  case 105: /* interrupt_stmt: RETURN common_expr  */
#line 357 "a.y"
                             { (yyval.node) = opr(RETURN , 1 ,(yyvsp[0].node));}
#line 2445 "y.tab.c"
    break;

  case 106: /* interrupt_stmt: XCONTINUE  */
#line 358 "a.y"
              { (yyval.node) = opr(XCONTINUE); }
#line 2451 "y.tab.c"
    break;

  case 107: /* call_statement: common_values_expr args_list_with_parentheses  */
#line 363 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2457 "y.tab.c"
    break;

  case 108: /* call_statement: call_statement '.' id_expr args_list_with_parentheses  */
#line 364 "a.y"
                                                          { (yyval.node) = NULL; }
#line 2463 "y.tab.c"
    break;

  case 109: /* arithmetic_stmt: common_number_expr '+' common_number_expr  */
#line 369 "a.y"
                                                    { (yyval.node) = opr('+',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2469 "y.tab.c"
    break;

  case 110: /* arithmetic_stmt: common_number_expr '-' common_number_expr  */
#line 370 "a.y"
                                                    { (yyval.node) = opr('-',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2475 "y.tab.c"
    break;

  case 111: /* arithmetic_stmt: common_number_expr '*' common_number_expr  */
#line 371 "a.y"
                                                    { (yyval.node) = opr('*',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2481 "y.tab.c"
    break;

  case 112: /* arithmetic_stmt: common_number_expr '/' common_number_expr  */
#line 372 "a.y"
                                                    { (yyval.node) = opr('/',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2487 "y.tab.c"
    break;

  case 113: /* arithmetic_stmt: common_number_expr '%' common_number_expr  */
#line 373 "a.y"
                                                    { (yyval.node) = opr('%',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2493 "y.tab.c"
    break;

  case 114: /* arithmetic_stmt: common_number_expr '&' common_number_expr  */
#line 374 "a.y"
                                                     { (yyval.node) = opr('&',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2499 "y.tab.c"
    break;

  case 115: /* arithmetic_stmt: common_number_expr '|' common_number_expr  */
#line 375 "a.y"
                                                     { (yyval.node) = opr('|',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2505 "y.tab.c"
    break;

  case 116: /* arithmetic_stmt: common_number_expr '^' common_number_expr  */
#line 376 "a.y"
                                                     { (yyval.node) = opr('^',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2511 "y.tab.c"
    break;

  case 117: /* arithmetic_stmt: common_number_expr LEFT_SHIFT common_number_expr  */
#line 377 "a.y"
                                                            { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2517 "y.tab.c"
    break;

  case 118: /* arithmetic_stmt: common_number_expr RIGHT_SHIFT common_number_expr  */
#line 378 "a.y"
                                                             { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2523 "y.tab.c"
    break;

  case 119: /* arithmetic_stmt: '~' common_number_expr  */
#line 379 "a.y"
                            { (yyval.node) = opr('~',1,(yyvsp[0].node)); }
#line 2529 "y.tab.c"
    break;

  case 120: /* new_expr: NEW id_expr args_list_with_parentheses  */
#line 384 "a.y"
                                                 { (yyval.node) = NULL; }
#line 2535 "y.tab.c"
    break;

  case 121: /* args_list_with_parentheses: '(' ')'  */
#line 388 "a.y"
                  { (yyval.node) = NULL; }
#line 2541 "y.tab.c"
    break;

  case 122: /* args_list_with_parentheses: '(' args_list ')'  */
#line 389 "a.y"
                        { (yyval.node) = (yyvsp[-1].args); }
#line 2547 "y.tab.c"
    break;

  case 123: /* args_list: common_expr  */
#line 393 "a.y"
                    { (yyval.args) = (yyvsp[0].node); }
#line 2553 "y.tab.c"
    break;

  case 124: /* args_list: args_list ',' common_expr  */
#line 394 "a.y"
                               { (yyval.args) = NULL; }
#line 2559 "y.tab.c"
    break;

  case 125: /* delete_expr: DELETE multiple_id_expr  */
#line 398 "a.y"
                              { (yyval.node) = NULL; }
#line 2565 "y.tab.c"
    break;

  case 126: /* logic_stmt: bool_param_expr  */
#line 404 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2571 "y.tab.c"
    break;

  case 127: /* logic_stmt: not_bool_param_expr  */
#line 405 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2577 "y.tab.c"
    break;

  case 128: /* logic_stmt: type_judge_stmt  */
#line 406 "a.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 2583 "y.tab.c"
    break;

  case 129: /* logic_stmt: compare_expr  */
#line 407 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2589 "y.tab.c"
    break;

  case 130: /* logic_stmt: logic_stmt _symbol_logic_connection logic_stmt  */
#line 408 "a.y"
                                                        { (yyval.node) = NULL; }
#line 2595 "y.tab.c"
    break;

  case 133: /* bool_param_expr: assign_stmt_value_eq  */
#line 418 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2601 "y.tab.c"
    break;

  case 134: /* bool_param_expr: bool_expr  */
#line 419 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2607 "y.tab.c"
    break;

  case 135: /* type_judge_stmt: common_object_expr XIS id_expr  */
#line 424 "a.y"
                                          { (yyval.node) = opr(XIS ,2 , (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2613 "y.tab.c"
    break;

  case 136: /* not_bool_param_expr: '!' bool_param_expr  */
#line 428 "a.y"
                          { (yyval.node) = NULL; }
#line 2619 "y.tab.c"
    break;

  case 137: /* compare_expr: number_compare_expr  */
#line 433 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2625 "y.tab.c"
    break;

  case 138: /* compare_expr: object_compare_expr  */
#line 434 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2631 "y.tab.c"
    break;

  case 139: /* number_compare_expr: common_number_expr _symbol_compare common_number_expr  */
#line 438 "a.y"
                                                          { (yyval.node) = NULL; }
#line 2637 "y.tab.c"
    break;

  case 140: /* object_compare_expr: common_object_expr _symbol_equals_not common_types_expr  */
#line 442 "a.y"
                                                             { (yyval.node) = NULL; }
#line 2643 "y.tab.c"
    break;

  case 141: /* _symbol_compare: '>'  */
#line 446 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2649 "y.tab.c"
    break;

  case 142: /* _symbol_compare: '<'  */
#line 447 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2655 "y.tab.c"
    break;

  case 143: /* _symbol_compare: GE_OP  */
#line 448 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2661 "y.tab.c"
    break;

  case 144: /* _symbol_compare: LE_OP  */
#line 449 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2667 "y.tab.c"
    break;

  case 145: /* _symbol_compare: NE_OP  */
#line 450 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2673 "y.tab.c"
    break;

  case 146: /* _symbol_compare: EQ_OP  */
#line 451 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2679 "y.tab.c"
    break;

  case 147: /* _symbol_equals_not: NE_OP  */
#line 455 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2685 "y.tab.c"
    break;

  case 148: /* _symbol_equals_not: EQ_OP  */
#line 456 "a.y"
              { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2691 "y.tab.c"
    break;

  case 149: /* self_inc_dec_stmt: self_inc_dec_operators common_values_expr  */
#line 461 "a.y"
                                                    { (yyval.node) = opr((yyvsp[-1].iValue),1, (yyvsp[0].node) ); }
#line 2697 "y.tab.c"
    break;

  case 150: /* self_inc_dec_stmt: common_values_expr self_inc_dec_operators  */
#line 462 "a.y"
                                                    { (yyval.node) = sopr((yyvsp[-1].node),1, (yyvsp[-1].node) ); }
#line 2703 "y.tab.c"
    break;

  case 151: /* self_inc_dec_operators: INC_OP  */
#line 466 "a.y"
                  { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2709 "y.tab.c"
    break;

  case 152: /* self_inc_dec_operators: DEC_OP  */
#line 467 "a.y"
                  { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2715 "y.tab.c"
    break;

  case 153: /* assign_stmt_value_eq: number_expr  */
#line 473 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2721 "y.tab.c"
    break;

  case 154: /* assign_stmt_value_eq: common_values_expr  */
#line 474 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2727 "y.tab.c"
    break;

  case 155: /* assign_stmt_value_eq: common_result_of_call_expr  */
#line 475 "a.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2733 "y.tab.c"
    break;

  case 156: /* array_ele_stmt: common_object_expr '[' common_number_expr ']'  */
#line 483 "a.y"
                                                         { (yyval.node) = NULL; }
#line 2739 "y.tab.c"
    break;

  case 157: /* assign_stmt: single_assign_stmt  */
#line 488 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2745 "y.tab.c"
    break;

  case 158: /* assign_stmt: number_change_assign_stmt  */
#line 489 "a.y"
                                    { (yyval.node) = (yyvsp[0].node) ;}
#line 2751 "y.tab.c"
    break;

  case 159: /* single_assign_stmt: common_assignable_expr '=' single_assign_stmt_value  */
#line 493 "a.y"
                                                              { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 2757 "y.tab.c"
    break;

  case 160: /* single_assign_stmt_value: common_expr  */
#line 497 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2763 "y.tab.c"
    break;

  case 161: /* single_assign_stmt_value: single_assign_stmt  */
#line 498 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2769 "y.tab.c"
    break;

  case 162: /* number_change_assign_stmt: common_assignable_expr symbol_change_assign common_number_expr  */
#line 502 "a.y"
                                                                    { (yyval.node) = NULL; }
#line 2775 "y.tab.c"
    break;

  case 163: /* symbol_change_assign: ADD_EQ  */
#line 506 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2781 "y.tab.c"
    break;

  case 164: /* symbol_change_assign: SUB_EQ  */
#line 507 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2787 "y.tab.c"
    break;

  case 165: /* symbol_change_assign: MUL_EQ  */
#line 508 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2793 "y.tab.c"
    break;

  case 166: /* symbol_change_assign: DIV_EQ  */
#line 509 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2799 "y.tab.c"
    break;

  case 167: /* symbol_change_assign: MOD_EQ  */
#line 510 "a.y"
                { (yyval.iValue) = (yyvsp[0].iValue); }
#line 2805 "y.tab.c"
    break;

  case 168: /* code_block: '{' '}'  */
#line 515 "a.y"
                    { (yyval.node) = NULL; }
#line 2811 "y.tab.c"
    break;

  case 169: /* code_block: '{' block_item_list '}'  */
#line 516 "a.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2817 "y.tab.c"
    break;

  case 170: /* block_item_list: block_item  */
#line 520 "a.y"
                                    { (yyval.node) = (yyvsp[0].node); }
#line 2823 "y.tab.c"
    break;

  case 171: /* block_item_list: block_item_list block_item  */
#line 521 "a.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2829 "y.tab.c"
    break;

  case 172: /* block_item: try_stmt  */
#line 525 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2835 "y.tab.c"
    break;

  case 173: /* block_item: simple_stmt  */
#line 526 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2841 "y.tab.c"
    break;

  case 174: /* block_item: con_ctl_stmt  */
#line 527 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2847 "y.tab.c"
    break;

  case 175: /* block_item: _extra_nothing  */
#line 528 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2853 "y.tab.c"
    break;

  case 176: /* string_plus_stmt: string_expr '+' string_plus_stmt_value  */
#line 533 "a.y"
                                              { (yyval.node) = NULL; }
#line 2859 "y.tab.c"
    break;

  case 177: /* string_plus_stmt: string_plus_stmt_value '+' string_expr  */
#line 534 "a.y"
                                              { (yyval.node) = NULL; }
#line 2865 "y.tab.c"
    break;

  case 178: /* string_plus_stmt_value: common_object_expr  */
#line 538 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2871 "y.tab.c"
    break;

  case 179: /* string_plus_stmt_value: common_types_expr  */
#line 539 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2877 "y.tab.c"
    break;

  case 180: /* string_plus_stmt_value: string_plus_stmt  */
#line 540 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2883 "y.tab.c"
    break;

  case 181: /* string_plus_stmt_value: self_inc_dec_stmt  */
#line 541 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2889 "y.tab.c"
    break;

  case 182: /* string_plus_stmt_value: number_parentheses_stmt  */
#line 542 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2895 "y.tab.c"
    break;

  case 183: /* number_parentheses_stmt: '(' common_number_expr ')'  */
#line 546 "a.y"
                                   { (yyval.node) = NULL; }
#line 2901 "y.tab.c"
    break;

  case 184: /* id_expr: IDENTIFIER  */
#line 552 "a.y"
                     { (yyval.node) = var((yyvsp[0].sValue)); }
#line 2907 "y.tab.c"
    break;

  case 185: /* multiple_id_expr: id_expr  */
#line 556 "a.y"
                    { (yyval.node) = (yyvsp[0].node);}
#line 2913 "y.tab.c"
    break;

  case 186: /* multiple_id_expr: multiple_id_expr ',' id_expr  */
#line 557 "a.y"
                                   { (yyval.node) = NULL; }
#line 2919 "y.tab.c"
    break;

  case 187: /* bool_expr: TBOOL  */
#line 561 "a.y"
                  { (yyval.node) = number((yyvsp[0].iValue)); }
#line 2925 "y.tab.c"
    break;

  case 188: /* number_expr: positive_number_expr  */
#line 565 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2931 "y.tab.c"
    break;

  case 189: /* number_expr: uminus_expr  */
#line 566 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2937 "y.tab.c"
    break;

  case 190: /* positive_number_expr: double_expr  */
#line 570 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2943 "y.tab.c"
    break;

  case 191: /* positive_number_expr: int_expr  */
#line 571 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2949 "y.tab.c"
    break;

  case 192: /* int_expr: XINTEGER  */
#line 575 "a.y"
             { (yyval.node) = number((yyvsp[0].iValue)); }
#line 2955 "y.tab.c"
    break;

  case 193: /* double_expr: TDOUBLE  */
#line 579 "a.y"
                  { (yyval.node) = number((yyvsp[0].dValue)); }
#line 2961 "y.tab.c"
    break;

  case 194: /* uminus_expr: '-' uminus_expr_values  */
#line 583 "a.y"
                                              { (yyval.node) = opr(UMINUS, 1, (yyvsp[0].node) ); }
#line 2967 "y.tab.c"
    break;

  case 195: /* uminus_expr_values: positive_number_expr  */
#line 587 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2973 "y.tab.c"
    break;

  case 196: /* uminus_expr_values: common_others_values_expr  */
#line 588 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2979 "y.tab.c"
    break;

  case 197: /* uminus_expr_values: call_statement  */
#line 589 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2985 "y.tab.c"
    break;

  case 198: /* uminus_expr_values: number_parentheses_stmt  */
#line 590 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2991 "y.tab.c"
    break;

  case 199: /* string_expr: TSTRING  */
#line 594 "a.y"
                   { (yyval.node) = string((yyvsp[0].sValue)); }
#line 2997 "y.tab.c"
    break;

  case 200: /* null_expr: XNULL  */
#line 598 "a.y"
                  { (yyval.node) = xnull(); }
#line 3003 "y.tab.c"
    break;

  case 201: /* common_types_expr: number_expr  */
#line 605 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3009 "y.tab.c"
    break;

  case 202: /* common_types_expr: string_expr  */
#line 606 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3015 "y.tab.c"
    break;

  case 203: /* common_types_expr: null_expr  */
#line 607 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3021 "y.tab.c"
    break;

  case 204: /* common_types_expr: lambda_stmt  */
#line 608 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3027 "y.tab.c"
    break;

  case 205: /* common_types_expr: bool_expr  */
#line 609 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3033 "y.tab.c"
    break;

  case 206: /* common_others_values_expr: id_expr  */
#line 613 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3039 "y.tab.c"
    break;

  case 207: /* common_others_values_expr: array_ele_stmt  */
#line 614 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3045 "y.tab.c"
    break;

  case 208: /* common_others_values_expr: class_member_stmt  */
#line 615 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3051 "y.tab.c"
    break;

  case 209: /* common_others_values_expr: static_member_stmt  */
#line 616 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 3057 "y.tab.c"
    break;

  case 210: /* common_values_expr: common_others_values_expr  */
#line 620 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3063 "y.tab.c"
    break;

  case 211: /* common_values_expr: this_stmt  */
#line 621 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3069 "y.tab.c"
    break;

  case 212: /* common_values_expr: new_expr  */
#line 622 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3075 "y.tab.c"
    break;

  case 213: /* common_result_of_call_expr: self_inc_dec_stmt  */
#line 626 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3081 "y.tab.c"
    break;

  case 214: /* common_result_of_call_expr: call_statement  */
#line 627 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3087 "y.tab.c"
    break;

  case 215: /* common_result_of_call_expr: arithmetic_stmt  */
#line 628 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3093 "y.tab.c"
    break;

  case 216: /* common_result_of_call_expr: number_parentheses_stmt  */
#line 629 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3099 "y.tab.c"
    break;

  case 217: /* common_assignable_expr: common_others_values_expr  */
#line 633 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3105 "y.tab.c"
    break;

  case 218: /* common_number_expr: number_expr  */
#line 637 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3111 "y.tab.c"
    break;

  case 219: /* common_number_expr: common_values_expr  */
#line 638 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3117 "y.tab.c"
    break;

  case 220: /* common_number_expr: common_result_of_call_expr  */
#line 639 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3123 "y.tab.c"
    break;

  case 221: /* common_object_expr: common_values_expr  */
#line 643 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3129 "y.tab.c"
    break;

  case 222: /* common_object_expr: call_statement  */
#line 644 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 3135 "y.tab.c"
    break;

  case 223: /* common_expr: common_types_expr  */
#line 653 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3141 "y.tab.c"
    break;

  case 224: /* common_expr: common_values_expr  */
#line 654 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3147 "y.tab.c"
    break;

  case 225: /* common_expr: common_result_of_call_expr  */
#line 655 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 3153 "y.tab.c"
    break;

  case 226: /* common_expr: string_plus_stmt  */
#line 656 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3159 "y.tab.c"
    break;


#line 3163 "y.tab.c"

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

#line 659 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
