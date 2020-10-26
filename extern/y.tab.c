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
    LE_OP = 267,                   /* LE_OP  */
    GE_OP = 268,                   /* GE_OP  */
    EQ_OP = 269,                   /* EQ_OP  */
    NE_OP = 270,                   /* NE_OP  */
    FUNC_OP = 271,                 /* FUNC_OP  */
    INC_OP = 272,                  /* INC_OP  */
    DEC_OP = 273,                  /* DEC_OP  */
    FUNC_CALL = 274,               /* FUNC_CALL  */
    VAR_DECLAR = 275,              /* VAR_DECLAR  */
    RESTRICT = 276,                /* RESTRICT  */
    THIS = 277,                    /* THIS  */
    EXTENDS = 278,                 /* EXTENDS  */
    ARRAY_ELE = 279,               /* ARRAY_ELE  */
    XTRY = 280,                    /* XTRY  */
    XCATCH = 281,                  /* XCATCH  */
    ADD_EQ = 282,                  /* ADD_EQ  */
    SUB_EQ = 283,                  /* SUB_EQ  */
    MUL_EQ = 284,                  /* MUL_EQ  */
    DIV_EQ = 285,                  /* DIV_EQ  */
    LEFT_SHIFT = 286,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 287,             /* RIGHT_SHIFT  */
    MOD_EQ = 288,                  /* MOD_EQ  */
    XPUBLIC = 289,                 /* XPUBLIC  */
    XSET = 290,                    /* XSET  */
    XIS = 291,                     /* XIS  */
    SCOPE = 292,                   /* SCOPE  */
    SCOPE_FUNC_CALL = 293,         /* SCOPE_FUNC_CALL  */
    REQUIRE = 294,                 /* REQUIRE  */
    REQUIRE_ONCE = 295,            /* REQUIRE_ONCE  */
    REF = 296,                     /* REF  */
    XCONTINUE = 297,               /* XCONTINUE  */
    XCONST = 298,                  /* XCONST  */
    XLOCAL = 299,                  /* XLOCAL  */
    AUTO = 300,                    /* AUTO  */
    IF = 301,                      /* IF  */
    ELSE = 302,                    /* ELSE  */
    WHILE = 303,                   /* WHILE  */
    FOR = 304,                     /* FOR  */
    DELETE = 305,                  /* DELETE  */
    BREAK = 306,                   /* BREAK  */
    RETURN = 307,                  /* RETURN  */
    SWITCH = 308,                  /* SWITCH  */
    CASE = 309,                    /* CASE  */
    DEFAULT = 310,                 /* DEFAULT  */
    CASE_LIST = 311,               /* CASE_LIST  */
    CLAXX_BODY = 312,              /* CLAXX_BODY  */
    NEW = 313,                     /* NEW  */
    CLAXX_MEMBER = 314,            /* CLAXX_MEMBER  */
    CLAXX_FUNC_CALL = 315,         /* CLAXX_FUNC_CALL  */
    XNULL = 316,                   /* XNULL  */
    XINCLUDE = 317,                /* XINCLUDE  */
    PIPELINE_OP = 318,             /* PIPELINE_OP  */
    NONASSOC = 319,                /* NONASSOC  */
    IFX = 320,                     /* IFX  */
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
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define FUNC_OP 271
#define INC_OP 272
#define DEC_OP 273
#define FUNC_CALL 274
#define VAR_DECLAR 275
#define RESTRICT 276
#define THIS 277
#define EXTENDS 278
#define ARRAY_ELE 279
#define XTRY 280
#define XCATCH 281
#define ADD_EQ 282
#define SUB_EQ 283
#define MUL_EQ 284
#define DIV_EQ 285
#define LEFT_SHIFT 286
#define RIGHT_SHIFT 287
#define MOD_EQ 288
#define XPUBLIC 289
#define XSET 290
#define XIS 291
#define SCOPE 292
#define SCOPE_FUNC_CALL 293
#define REQUIRE 294
#define REQUIRE_ONCE 295
#define REF 296
#define XCONTINUE 297
#define XCONST 298
#define XLOCAL 299
#define AUTO 300
#define IF 301
#define ELSE 302
#define WHILE 303
#define FOR 304
#define DELETE 305
#define BREAK 306
#define RETURN 307
#define SWITCH 308
#define CASE 309
#define DEFAULT 310
#define CASE_LIST 311
#define CLAXX_BODY 312
#define NEW 313
#define CLAXX_MEMBER 314
#define CLAXX_FUNC_CALL 315
#define XNULL 316
#define XINCLUDE 317
#define PIPELINE_OP 318
#define NONASSOC 319
#define IFX 320
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
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_FUNC_OP = 16,                   /* FUNC_OP  */
  YYSYMBOL_INC_OP = 17,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 18,                    /* DEC_OP  */
  YYSYMBOL_FUNC_CALL = 19,                 /* FUNC_CALL  */
  YYSYMBOL_VAR_DECLAR = 20,                /* VAR_DECLAR  */
  YYSYMBOL_RESTRICT = 21,                  /* RESTRICT  */
  YYSYMBOL_THIS = 22,                      /* THIS  */
  YYSYMBOL_EXTENDS = 23,                   /* EXTENDS  */
  YYSYMBOL_ARRAY_ELE = 24,                 /* ARRAY_ELE  */
  YYSYMBOL_XTRY = 25,                      /* XTRY  */
  YYSYMBOL_XCATCH = 26,                    /* XCATCH  */
  YYSYMBOL_ADD_EQ = 27,                    /* ADD_EQ  */
  YYSYMBOL_SUB_EQ = 28,                    /* SUB_EQ  */
  YYSYMBOL_MUL_EQ = 29,                    /* MUL_EQ  */
  YYSYMBOL_DIV_EQ = 30,                    /* DIV_EQ  */
  YYSYMBOL_LEFT_SHIFT = 31,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 32,               /* RIGHT_SHIFT  */
  YYSYMBOL_MOD_EQ = 33,                    /* MOD_EQ  */
  YYSYMBOL_XPUBLIC = 34,                   /* XPUBLIC  */
  YYSYMBOL_XSET = 35,                      /* XSET  */
  YYSYMBOL_XIS = 36,                       /* XIS  */
  YYSYMBOL_SCOPE = 37,                     /* SCOPE  */
  YYSYMBOL_SCOPE_FUNC_CALL = 38,           /* SCOPE_FUNC_CALL  */
  YYSYMBOL_REQUIRE = 39,                   /* REQUIRE  */
  YYSYMBOL_REQUIRE_ONCE = 40,              /* REQUIRE_ONCE  */
  YYSYMBOL_REF = 41,                       /* REF  */
  YYSYMBOL_XCONTINUE = 42,                 /* XCONTINUE  */
  YYSYMBOL_XCONST = 43,                    /* XCONST  */
  YYSYMBOL_XLOCAL = 44,                    /* XLOCAL  */
  YYSYMBOL_AUTO = 45,                      /* AUTO  */
  YYSYMBOL_IF = 46,                        /* IF  */
  YYSYMBOL_ELSE = 47,                      /* ELSE  */
  YYSYMBOL_WHILE = 48,                     /* WHILE  */
  YYSYMBOL_FOR = 49,                       /* FOR  */
  YYSYMBOL_DELETE = 50,                    /* DELETE  */
  YYSYMBOL_BREAK = 51,                     /* BREAK  */
  YYSYMBOL_RETURN = 52,                    /* RETURN  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_CASE = 54,                      /* CASE  */
  YYSYMBOL_DEFAULT = 55,                   /* DEFAULT  */
  YYSYMBOL_CASE_LIST = 56,                 /* CASE_LIST  */
  YYSYMBOL_CLAXX_BODY = 57,                /* CLAXX_BODY  */
  YYSYMBOL_NEW = 58,                       /* NEW  */
  YYSYMBOL_CLAXX_MEMBER = 59,              /* CLAXX_MEMBER  */
  YYSYMBOL_CLAXX_FUNC_CALL = 60,           /* CLAXX_FUNC_CALL  */
  YYSYMBOL_XNULL = 61,                     /* XNULL  */
  YYSYMBOL_XINCLUDE = 62,                  /* XINCLUDE  */
  YYSYMBOL_PIPELINE_OP = 63,               /* PIPELINE_OP  */
  YYSYMBOL_NONASSOC = 64,                  /* NONASSOC  */
  YYSYMBOL_IFX = 65,                       /* IFX  */
  YYSYMBOL_66_ = 66,                       /* ','  */
  YYSYMBOL_67_ = 67,                       /* '='  */
  YYSYMBOL_68_ = 68,                       /* '|'  */
  YYSYMBOL_69_ = 69,                       /* '^'  */
  YYSYMBOL_70_ = 70,                       /* '&'  */
  YYSYMBOL_71_ = 71,                       /* '>'  */
  YYSYMBOL_72_ = 72,                       /* '<'  */
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
  YYSYMBOL_require_stmt = 97,              /* require_stmt  */
  YYSYMBOL_try_stmt = 98,                  /* try_stmt  */
  YYSYMBOL_catch_block_stmt = 99,          /* catch_block_stmt  */
  YYSYMBOL_declar_stmt = 100,              /* declar_stmt  */
  YYSYMBOL_const_declar_stmt = 101,        /* const_declar_stmt  */
  YYSYMBOL_local_declar_stmt = 102,        /* local_declar_stmt  */
  YYSYMBOL_namespace_declar_stmt = 103,    /* namespace_declar_stmt  */
  YYSYMBOL_namespace_name_stmt = 104,      /* namespace_name_stmt  */
  YYSYMBOL_class_declar_stmt = 105,        /* class_declar_stmt  */
  YYSYMBOL_extends_stmt = 106,             /* extends_stmt  */
  YYSYMBOL_class_body = 107,               /* class_body  */
  YYSYMBOL_class_body_stmt = 108,          /* class_body_stmt  */
  YYSYMBOL_this_stmt = 109,                /* this_stmt  */
  YYSYMBOL_this_member_stmt = 110,         /* this_member_stmt  */
  YYSYMBOL_class_member_stmt = 111,        /* class_member_stmt  */
  YYSYMBOL_class_member_func_stmt = 112,   /* class_member_func_stmt  */
  YYSYMBOL_static_member_stmt = 113,       /* static_member_stmt  */
  YYSYMBOL_func_declar_stmt = 114,         /* func_declar_stmt  */
  YYSYMBOL_lambda_stmt = 115,              /* lambda_stmt  */
  YYSYMBOL_lambda_args_stmt = 116,         /* lambda_args_stmt  */
  YYSYMBOL_param_list = 117,               /* param_list  */
  YYSYMBOL_parameter = 118,                /* parameter  */
  YYSYMBOL_expr_list = 119,                /* expr_list  */
  YYSYMBOL_element_var_declar_stmt = 120,  /* element_var_declar_stmt  */
  YYSYMBOL_var_declar_stmt = 121,          /* var_declar_stmt  */
  YYSYMBOL_con_ctl_stmt = 122,             /* con_ctl_stmt  */
  YYSYMBOL_selection_stmt = 123,           /* selection_stmt  */
  YYSYMBOL_case_stmt_list = 124,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 125,                /* case_stmt  */
  YYSYMBOL_loop_stmt = 126,                /* loop_stmt  */
  YYSYMBOL_for_1_stmt = 127,               /* for_1_stmt  */
  YYSYMBOL_simple_stmt = 128,              /* simple_stmt  */
  YYSYMBOL_restrict_stmt = 129,            /* restrict_stmt  */
  YYSYMBOL_interrupt_stmt = 130,           /* interrupt_stmt  */
  YYSYMBOL_call_statement = 131,           /* call_statement  */
  YYSYMBOL_call_statement_pipeline = 132,  /* call_statement_pipeline  */
  YYSYMBOL_args_list = 133,                /* args_list  */
  YYSYMBOL_args_expr = 134,                /* args_expr  */
  YYSYMBOL_args_expr_collection = 135,     /* args_expr_collection  */
  YYSYMBOL_block = 136,                    /* block  */
  YYSYMBOL_double_or_ps_expr = 137,        /* double_or_ps_expr  */
  YYSYMBOL_parentheses_stmt = 138,         /* parentheses_stmt  */
  YYSYMBOL_arithmetic_stmt = 139,          /* arithmetic_stmt  */
  YYSYMBOL_bit_opr_factor = 140,           /* bit_opr_factor  */
  YYSYMBOL_arithmetic_stmt_factor = 141,   /* arithmetic_stmt_factor  */
  YYSYMBOL_new_expr = 142,                 /* new_expr  */
  YYSYMBOL_not_expr_value = 143,           /* not_expr_value  */
  YYSYMBOL_bool_param_expr = 144,          /* bool_param_expr  */
  YYSYMBOL_logic_stmt = 145,               /* logic_stmt  */
  YYSYMBOL_type_judge_stmt = 146,          /* type_judge_stmt  */
  YYSYMBOL_self_inc_dec_stmt = 147,        /* self_inc_dec_stmt  */
  YYSYMBOL_assign_stmt_value = 148,        /* assign_stmt_value  */
  YYSYMBOL_assign_stmt_value_eq = 149,     /* assign_stmt_value_eq  */
  YYSYMBOL_single_assign_stmt = 150,       /* single_assign_stmt  */
  YYSYMBOL_class_member_assign_stmt = 151, /* class_member_assign_stmt  */
  YYSYMBOL_array_ele_stmt = 152,           /* array_ele_stmt  */
  YYSYMBOL_array_ele_assign_stmt = 153,    /* array_ele_assign_stmt  */
  YYSYMBOL_assign_stmt = 154,              /* assign_stmt  */
  YYSYMBOL_id_expr = 155,                  /* id_expr  */
  YYSYMBOL_bool_expr = 156,                /* bool_expr  */
  YYSYMBOL_double_expr = 157,              /* double_expr  */
  YYSYMBOL_uminus_expr = 158,              /* uminus_expr  */
  YYSYMBOL_string_expr = 159,              /* string_expr  */
  YYSYMBOL_null_expr = 160                 /* null_expr  */
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
#define YYLAST   1790

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  227
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  436

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
       2,     2,     2,    78,     2,     2,     2,    77,    70,     2,
      80,    81,    75,    73,    66,    74,    84,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    92,    89,
      72,    67,    71,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    82,     2,    83,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    90,    68,    91,    79,     2,     2,     2,
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
      65,    85,    86,    87,    88
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    71,    72,    75,    76,    77,    78,    79,
      80,    85,    86,    87,    88,    93,    94,    98,   103,   104,
     105,   106,   107,   108,   114,   119,   120,   125,   129,   130,
     135,   136,   137,   138,   143,   144,   149,   150,   154,   155,
     156,   161,   162,   164,   169,   170,   175,   176,   177,   178,
     183,   184,   185,   186,   187,   192,   198,   199,   200,   205,
     206,   207,   211,   212,   216,   217,   221,   222,   223,   227,
     228,   232,   233,   234,   235,   240,   241,   246,   247,   252,
     253,   254,   258,   259,   263,   264,   268,   269,   274,   275,
     276,   277,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   295,   296,   300,   301,   302,   307,   308,   309,   310,
     314,   320,   321,   325,   326,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   346,   347,
     353,   354,   359,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   380,   381,   386,   387,   388,   393,
     397,   398,   399,   400,   405,   406,   407,   408,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   428,
     433,   434,   435,   436,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   474,
     475,   479,   480,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   499,   504,   505,   506,   507,   508,   509,   510,
     511,   526,   530,   548,   552,   553,   557,   561
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
  "OR_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "FUNC_OP", "INC_OP",
  "DEC_OP", "FUNC_CALL", "VAR_DECLAR", "RESTRICT", "THIS", "EXTENDS",
  "ARRAY_ELE", "XTRY", "XCATCH", "ADD_EQ", "SUB_EQ", "MUL_EQ", "DIV_EQ",
  "LEFT_SHIFT", "RIGHT_SHIFT", "MOD_EQ", "XPUBLIC", "XSET", "XIS", "SCOPE",
  "SCOPE_FUNC_CALL", "REQUIRE", "REQUIRE_ONCE", "REF", "XCONTINUE",
  "XCONST", "XLOCAL", "AUTO", "IF", "ELSE", "WHILE", "FOR", "DELETE",
  "BREAK", "RETURN", "SWITCH", "CASE", "DEFAULT", "CASE_LIST",
  "CLAXX_BODY", "NEW", "CLAXX_MEMBER", "CLAXX_FUNC_CALL", "XNULL",
  "XINCLUDE", "PIPELINE_OP", "NONASSOC", "IFX", "','", "'='", "'|'", "'^'",
  "'&'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "'('", "')'", "'['", "']'", "'.'", "PRIORITY3", "PRIORITY2", "PRIORITY1",
  "UMINUS", "';'", "'{'", "'}'", "':'", "$accept", "program",
  "statement_list", "statement", "require_stmt", "try_stmt",
  "catch_block_stmt", "declar_stmt", "const_declar_stmt",
  "local_declar_stmt", "namespace_declar_stmt", "namespace_name_stmt",
  "class_declar_stmt", "extends_stmt", "class_body", "class_body_stmt",
  "this_stmt", "this_member_stmt", "class_member_stmt",
  "class_member_func_stmt", "static_member_stmt", "func_declar_stmt",
  "lambda_stmt", "lambda_args_stmt", "param_list", "parameter",
  "expr_list", "element_var_declar_stmt", "var_declar_stmt",
  "con_ctl_stmt", "selection_stmt", "case_stmt_list", "case_stmt",
  "loop_stmt", "for_1_stmt", "simple_stmt", "restrict_stmt",
  "interrupt_stmt", "call_statement", "call_statement_pipeline",
  "args_list", "args_expr", "args_expr_collection", "block",
  "double_or_ps_expr", "parentheses_stmt", "arithmetic_stmt",
  "bit_opr_factor", "arithmetic_stmt_factor", "new_expr", "not_expr_value",
  "bool_param_expr", "logic_stmt", "type_judge_stmt", "self_inc_dec_stmt",
  "assign_stmt_value", "assign_stmt_value_eq", "single_assign_stmt",
  "class_member_assign_stmt", "array_ele_stmt", "array_ele_assign_stmt",
  "assign_stmt", "id_expr", "bool_expr", "double_expr", "uminus_expr",
  "string_expr", "null_expr", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,    44,    61,   124,    94,
      38,    62,    60,    43,    45,    42,    47,    37,    33,   126,
      40,    41,    91,    93,    46,   321,   322,   323,   324,    59,
     123,   125,    58
};
#endif

#define YYPACT_NINF (-279)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-194)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -279,    90,  1622,  -279,   104,     7,    41,    41,   109,    53,
      70,   181,   234,   234,   242,  -279,   248,    43,   269,   186,
     239,   259,   329,  -279,   890,   272,    41,   234,   336,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,   289,  -279,   321,    15,
     309,   323,  -279,   -32,  -279,  -279,  -279,  -279,   325,  -279,
    -279,   -24,  -279,  -279,  -279,  -279,  -279,   128,  -279,  -279,
     540,   330,   409,  1682,   215,   327,   330,  -279,  -279,  -279,
    -279,  -279,   414,  -279,   354,  -279,  -279,  -279,  -279,   158,
     348,  -279,  -279,   -11,  -279,  -279,   402,  1690,  1690,    83,
    -279,  -279,  -279,   151,   350,  -279,    38,   101,   252,    81,
     262,   260,  -279,    12,   219,   164,   134,   281,  -279,   191,
    -279,  -279,   249,  1661,  -279,   232,   236,   247,  -279,    41,
     356,  -279,   423,  -279,   890,   890,   358,    41,    41,  1682,
     248,  -279,  -279,   414,   380,   890,  1682,    41,  -279,  -279,
      47,    47,    47,    47,    47,    41,   890,    41,   439,   357,
    -279,    -6,  -279,   116,     0,  -279,   217,   376,   392,  -279,
      95,  -279,  -279,   126,   808,  -279,   130,   180,   183,  -279,
     381,   346,   384,   207,   106,   125,   -17,     5,   370,   280,
     207,   386,   -17,  1092,   242,   457,  -279,   166,   387,    71,
     401,   207,   323,   386,   438,   225,    25,  -279,   455,   125,
     452,  -279,  -279,  -279,  -279,  -279,    31,   293,  -279,   382,
    -279,  -279,   389,   479,   406,    41,    47,  -279,  -279,  -279,
    -279,  -279,  -279,   205,   212,   405,   397,   484,   101,   101,
     101,   101,   101,   401,   401,   401,   401,   401,   410,  1682,
     330,  -279,  -279,   412,   415,   416,   413,   417,   411,  -279,
      82,   418,   421,   425,  -279,   428,   436,  -279,   141,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,   698,   453,  -279,   246,
    -279,   435,  1682,   -26,   -21,  -279,  -279,    -9,  -279,    19,
    -279,  -279,  -279,   446,   470,  -279,   512,  -279,   456,  -279,
     458,   361,    23,  -279,   207,   386,  -279,   -17,  1710,  1710,
    1710,  1710,  1710,  1710,  1690,  1690,  1569,    41,  1569,  1690,
    -279,  -279,   459,   461,   466,   468,   541,   534,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,   377,   377,  -279,
    -279,  -279,   465,   478,   472,  -279,  -279,  -279,  1682,  1682,
    -279,  -279,  -279,  -279,  -279,  -279,  1682,  1682,  -279,  1145,
      41,  -279,  -279,  -279,  -279,  1198,   471,  -279,  -279,  -279,
    -279,    24,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   553,
    -279,  -279,   517,  -279,  -279,    27,  1251,  -279,  -279,  1682,
    -279,  -279,   476,  1304,   343,  -279,  -279,   490,   491,   493,
     495,  -279,   500,  -279,    41,  -279,  1357,  1569,    83,  -279,
     503,  -279,  -279,   576,   494,     1,  -279,  1410,  -279,  -279,
    -279,  -279,  1682,   507,  -279,  -279,   510,  -279,  1463,   511,
    -279,  -279,  -279,  -279,   518,   502,  1569,  -279,  -279,  1622,
    -279,  -279,  -279,  1622,  1516,  -279
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,   221,     0,     0,     0,   101,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,     0,     0,     0,     5,
       3,     9,    10,     6,    22,    23,     0,    20,     0,     0,
     108,     0,    18,     0,    19,     7,    77,    78,     0,    98,
      96,    94,   100,    97,    92,   213,   214,     0,   215,    93,
      71,    64,     0,   111,     0,     0,    64,   221,   170,   171,
     222,   102,     0,    70,     0,   226,    11,    12,    28,     0,
     221,    24,    71,   221,    26,    25,    34,     0,     0,    88,
      95,   144,   223,   221,    41,   227,     0,     0,    68,   197,
     195,   196,   179,     0,   192,   147,     0,     0,   183,   194,
     105,   146,   198,   145,   176,   189,   190,   191,   185,     0,
       0,    13,     0,    21,     0,     0,     0,     0,     0,   111,
       0,    75,     8,     0,     0,     0,   111,     0,   172,   173,
       0,     0,     0,     0,     0,     0,     0,     0,    68,     0,
      35,   221,   197,   195,   196,   115,   192,     0,   112,   113,
     147,   126,   194,   198,   193,   116,   189,   190,   191,   127,
       0,   221,     0,     0,     0,     0,     0,     0,     0,   221,
      45,     0,    44,     0,     0,     0,    14,     0,     0,     0,
       0,   195,   196,   192,   155,   158,     0,   159,   154,   198,
     193,   156,   189,   190,   191,   157,     0,   221,    90,     0,
      91,    89,     0,     0,     0,     0,     0,   224,   131,   225,
     130,   141,   145,   221,     0,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   111,
      64,   202,   201,     0,     0,     0,    49,    47,     0,    76,
       0,     0,     0,     0,   212,     0,     0,   216,   193,   217,
     218,   219,   220,    55,   199,   200,   145,    46,    66,     0,
      70,   107,     0,   203,   204,   205,    74,   221,    30,     0,
      36,    40,    38,     0,    71,    70,    15,    69,    27,    29,
       0,   221,     0,   153,   152,   151,   160,   150,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,    62,     0,     0,    42,     0,     0,     0,   148,    70,
      63,   142,   143,   139,   140,   138,   147,   133,   134,   135,
     136,   137,     0,     0,     0,   206,   207,   208,   111,   111,
     109,   110,   209,   210,   211,   106,   111,   111,    65,     0,
       0,   114,    31,    37,    39,     0,     0,    16,    72,    73,
      32,     0,   163,   164,   165,   166,   161,   162,   167,   168,
      70,   129,    79,   169,    86,     0,     0,   203,   204,   111,
     132,    67,     0,     0,     0,   149,    70,     0,     0,     0,
       0,    57,    48,    58,     0,    33,     0,     0,    88,    60,
       0,    70,    61,     0,     0,     0,    82,     0,    53,    54,
      51,    50,   111,     0,   128,    80,     0,    43,     0,     0,
      70,    81,    83,    56,     0,     0,     0,    59,    70,    85,
      52,    70,    87,    84,     0,    17
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,  -279,    14,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,   420,   588,   527,   322,  -278,   -16,  -279,   127,  -279,
     313,  -168,    22,  -279,   -60,   467,  -136,  -279,     2,  -279,
    -279,  -279,   211,  -279,   220,  -279,  -279,  -279,   454,  -279,
    -103,  -279,   351,  -249,  -279,  -279,   620,   -76,   375,   659,
    -279,    69,   -85,  -279,   199,   -74,   803,  -129,  -279,   634,
    -279,   -87,    -2,   724,   326,   661,   255,   780
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   287,    31,    32,   357,    33,    34,    35,
      36,    79,    37,    65,   279,   280,   152,    38,   191,    40,
     192,    42,   155,   103,   149,   224,   183,    43,    44,    45,
      46,   405,   406,    47,   209,    48,    49,    50,   193,    52,
     157,   158,   159,   372,   217,   218,   160,   106,   107,    53,
     296,   195,   196,   197,   162,   110,   111,    55,    56,   199,
      58,    59,   164,   165,   202,   203,   204,   169
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,   353,   211,   206,    68,    69,   178,    61,    99,   281,
     212,   277,    62,     5,    82,    82,    30,   265,    81,    85,
     145,   221,   113,    66,   120,   277,   248,     5,   226,   277,
     277,     5,     5,   255,   130,   304,   305,   304,   305,   133,
     -72,   304,   305,    92,    67,   -73,   102,    67,   283,    83,
     241,   242,    92,   179,    75,   403,   404,   131,   134,   374,
    -118,   254,   176,   -72,     6,     7,  -125,   147,   -73,    94,
     182,   187,   264,   187,    63,  -118,   214,   179,   227,   -34,
     129,  -125,   125,   353,    28,   200,   200,    60,    18,   207,
       3,   208,   421,    94,   219,   222,   278,   126,    28,   127,
       6,     7,    28,    28,    91,     9,   306,    67,    99,    99,
     352,   281,   308,    70,   360,   395,   398,   238,   216,    99,
      61,    96,   113,   113,   281,   246,   247,    62,    82,    39,
      99,   176,   249,   113,   349,   256,   333,    72,   258,   258,
     258,   258,   258,   263,   266,   267,   102,   102,   415,   355,
     283,   100,   321,   322,   323,   324,   325,   102,   138,   139,
      73,  -122,  -186,   283,   134,   228,   229,   212,   102,   290,
    -186,   341,   291,   293,   376,   284,  -122,   432,   145,   282,
     334,    60,  -124,   383,    63,   176,    64,   297,   134,   276,
     153,   173,  -123,   281,   -34,   135,  -117,  -124,   126,   180,
     127,    54,   230,   231,   232,   136,   136,  -123,   136,   137,
     137,  -117,   137,   314,   258,    74,    39,   213,   170,   368,
     369,   171,   172,   109,   375,   147,   222,   222,   222,   222,
     222,    63,   283,   214,   396,   387,   388,   298,   299,   300,
     301,    75,   185,   389,   390,  -177,  -120,   186,    78,  -119,
     407,   100,   100,  -177,    80,    91,   153,    92,   223,    75,
     173,  -120,   100,   153,  -119,   418,    87,    76,    77,     6,
       7,   -66,  -182,   100,    94,    86,   400,   284,   316,   117,
    -182,   282,   121,  -121,   429,    63,   -66,   214,   210,   126,
     284,   127,   433,   317,   282,   434,   302,   303,  -121,   134,
    -178,   134,   200,   200,    60,   373,    60,   200,  -178,   424,
      39,   211,   316,  -174,   173,    41,   294,  -175,   168,    88,
     371,  -174,   371,   109,   109,  -175,    96,   348,  -181,   136,
    -187,    97,   190,   137,   109,    90,  -181,   101,  -187,    89,
     129,  -188,   122,  -184,   126,   109,   127,    60,   392,  -188,
     115,  -184,   119,    60,   233,   234,   235,   236,   237,   284,
      63,   243,   214,   282,   244,   245,   153,   362,   363,   364,
     365,   366,   367,    63,    60,    64,   154,    41,   123,   117,
     117,    60,    54,   251,   168,    41,   252,   253,   124,   166,
     117,   168,   413,   128,    60,    60,    60,   403,   404,   153,
     208,   117,    41,   129,    91,    60,    92,   179,    75,   312,
     148,   371,   313,   172,   132,   150,    60,   177,     6,     7,
     179,   184,   220,    94,    60,    62,    63,    60,   214,   274,
     187,    60,    60,    39,   215,    39,   239,   101,   101,   240,
     371,    63,   154,   214,   359,   268,    41,   270,   101,   154,
     115,   115,   235,   236,   237,   166,    51,   271,   272,   101,
     285,   115,   166,   289,   273,   153,   153,   275,   134,   138,
     139,   309,   115,   153,   153,    96,    39,   292,   104,   310,
      97,   190,    39,  -145,  -145,   311,   318,   319,   307,   145,
     320,   332,   340,   338,   168,   335,    41,   339,   336,   337,
      41,   342,    41,    39,   343,    54,   153,    54,   344,   345,
      39,  -147,  -147,  -147,  -147,  -147,   346,   156,   174,   350,
    -145,  -145,  -145,    39,    39,    39,   181,   168,  -146,  -146,
    -146,  -146,  -146,   347,    39,   354,   147,   146,   356,   153,
     185,   358,   377,   181,   378,    39,   379,   381,    54,   380,
     382,   394,   154,    39,    54,   384,    39,   138,   139,   385,
      39,    39,   386,   304,   397,   166,   401,   140,   141,   142,
     143,   408,   409,   144,   410,    54,   411,   145,   104,   104,
     412,    92,    54,   156,   417,   154,   420,   250,   425,   104,
     156,   426,   431,   168,   168,    54,    54,   210,   166,   430,
     104,   168,   168,   428,   288,    84,    54,   146,   327,   328,
     329,   330,   331,   188,   361,   269,   422,    54,   416,    41,
       0,    41,     0,   351,   147,    54,     0,     0,    54,     0,
       0,     0,    54,    54,   168,     0,    57,    51,     0,     0,
       0,   174,     0,   295,   105,     0,     0,     0,     0,     0,
       0,   154,   154,     0,     0,     0,     0,     0,   112,   154,
     154,     0,    41,     0,   166,   166,     0,   168,    41,     0,
       0,     0,   166,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,     0,   116,     0,     0,     0,    41,
       0,     0,   154,   156,     0,     0,    41,   163,   175,     0,
       0,     0,     0,     0,     0,   166,   175,   194,   194,    41,
      41,    41,     0,     0,     0,   138,   139,     0,   225,     0,
      41,     0,   161,    57,   167,   154,   156,     0,     0,   419,
       0,    41,    71,     0,     0,   145,     0,     0,   166,    41,
       0,     0,    41,     0,   105,   105,    41,    41,   114,     0,
       0,     0,     0,     0,     0,   105,     0,     0,   112,   112,
      51,     0,    51,   163,     0,   146,   105,   175,     0,   112,
     163,  -193,  -193,  -193,  -193,  -193,     0,     0,     0,  -180,
     112,     0,   147,   108,   108,   116,   116,  -180,   161,     0,
     167,     0,   156,   156,   108,   161,   116,   167,     0,     0,
     156,   156,     0,    51,   118,   108,     0,   116,     0,    51,
     225,   201,   201,     0,     0,     0,     0,    57,     0,     0,
       0,   175,     0,   175,     0,   138,   139,     0,     0,     0,
      51,     0,     0,   156,     0,     0,     0,    51,     0,  -145,
    -145,     0,     0,     0,     0,   145,     0,     0,   114,   114,
      51,    51,   181,   326,   326,   326,   326,   326,     0,   114,
       0,    51,     0,     0,     0,     0,   156,   205,   205,     0,
     114,     0,    51,   163,     0,     0,  -145,  -145,  -145,     0,
      51,     0,     0,    51,     0,     0,     0,    51,    51,     0,
     198,   198,   147,    91,    70,    92,    93,    75,   161,     0,
     167,     0,     0,     0,   118,   118,   163,     6,     7,     0,
       0,     0,    94,     0,     0,   118,     0,     0,   194,   194,
     194,   194,   194,   194,   194,   194,   118,     0,     0,   194,
       0,   161,     0,   167,     0,     0,     0,     0,     0,     0,
      57,     0,    57,   257,   259,   260,   261,   262,    26,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,    97,
      98,     0,   163,   163,     0,     0,     0,     0,     0,     0,
     163,   163,     0,    57,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,   161,   161,   167,
     167,     0,     0,     0,     0,   161,   161,   167,   167,     0,
      57,     0,     0,   163,     0,     0,     0,    57,     0,   315,
       0,     0,   201,   201,   201,   201,   201,   201,   201,   201,
      57,    57,    57,   201,     0,     0,     0,     0,   161,     0,
     167,    57,     0,     0,     0,     0,   163,     0,     0,     0,
       0,     0,    57,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,    57,     0,     0,     0,    57,    57,     0,
       0,   161,     0,   167,     0,     0,     0,     0,   205,   205,
     205,   205,   205,   205,   205,   205,     0,     0,     0,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       5,   198,   198,   198,   198,   198,   198,   198,   198,     6,
       7,     0,   198,     8,     9,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,     0,     0,
      26,     4,     0,     5,    27,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     0,     0,     8,     9,     0,     0,
      10,    28,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    29,     0,   286,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,    26,     4,     0,     5,    27,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     0,     0,     8,
       9,     0,     0,    10,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    29,     0,   391,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
      24,    25,     0,     0,     0,     0,    26,     4,     0,     5,
      27,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       0,     0,     8,     9,     0,     0,    10,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    29,     0,   393,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,    26,
       4,     0,     5,    27,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     0,     0,     8,     9,     0,     0,    10,
      28,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      29,     0,   399,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,    26,     4,     0,     5,    27,     0,     0,     0,
       0,     0,     0,     0,     6,     7,     0,     0,     8,     9,
       0,     0,    10,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    29,     0,   402,    12,    13,    14,    15,
      16,    17,    18,    19,     0,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,    26,     4,     0,     5,    27,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     0,
       0,     8,     9,     0,     0,    10,    28,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    29,     0,   414,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,    26,     4,
       0,     5,    27,     0,     0,     0,     0,     0,     0,     0,
       6,     7,     0,     0,     8,     9,     0,     0,    10,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    29,
       0,   423,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,    26,     4,     0,     5,    27,     0,     0,     0,     0,
       0,     0,     0,     6,     7,     0,     0,     8,     9,     0,
       0,    10,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    29,     0,   427,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,    24,    25,
       0,     0,     0,     0,    26,     4,     0,     5,    27,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
       8,     9,     0,     0,    10,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    29,     0,   435,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,    26,     4,     0,
       5,    27,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     0,     0,     8,     9,     0,     0,    10,    28,     0,
       0,     0,     0,     0,     0,     0,     0,    11,    29,   370,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,     0,     0,   138,   139,
      26,     0,     0,     0,    27,    91,    70,    92,   151,    75,
       0,     0,     0,    91,    70,    92,   179,    75,   145,     6,
       7,    28,     0,     0,    94,     0,     0,     6,     7,     0,
       0,    29,    94,    91,    70,    92,   179,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     6,     7,     0,
       0,     0,    94,     0,  -193,  -193,  -193,  -193,  -193,     0,
      26,     0,  -180,    95,     0,   147,     0,     0,     0,     0,
    -180,    95,     0,     0,     0,     0,    96,     0,     0,     0,
       0,    97,    98,     0,    96,     0,     0,     0,   189,    97,
     190,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,     0,    97,
     190
};

static const yytype_int16 yycheck[] =
{
       2,   279,    89,    88,     6,     7,    66,    16,    24,   177,
      16,     6,    23,     8,    16,    17,     2,   146,    16,    17,
      37,    97,    24,    16,    26,     6,   129,     8,    16,     6,
       6,     8,     8,   136,    66,    10,    11,    10,    11,    63,
      66,    10,    11,     5,     6,    66,    24,     6,   177,     6,
     124,   125,     5,     6,     7,    54,    55,    89,    82,   308,
      66,   135,    64,    89,    17,    18,    66,    84,    89,    22,
      72,    82,   146,    82,    80,    81,    82,     6,    66,    90,
      80,    81,    67,   361,    79,    87,    88,    89,    45,     6,
       0,    89,    91,    22,    96,    97,    91,    82,    79,    84,
      17,    18,    79,    79,     3,    22,    81,     6,   124,   125,
      91,   279,    81,     4,    91,    91,    89,   119,    80,   135,
      16,    74,   124,   125,   292,   127,   128,    23,   130,     2,
     146,   133,   130,   135,   270,   137,   239,    84,   140,   141,
     142,   143,   144,   145,   146,   147,   124,   125,   397,   285,
     279,    24,   228,   229,   230,   231,   232,   135,    17,    18,
      90,    66,    81,   292,    82,    31,    32,    16,   146,     3,
      89,    89,     6,   189,   310,   177,    81,   426,    37,   177,
     240,   183,    66,   319,    80,   187,    82,   189,    82,    83,
      63,    64,    66,   361,    90,    67,    66,    81,    82,    72,
      84,     2,    68,    69,    70,    80,    80,    81,    80,    84,
      84,    81,    84,   215,   216,    34,    89,    66,     3,   304,
     305,     6,     7,    24,   309,    84,   228,   229,   230,   231,
     232,    80,   361,    82,   370,   338,   339,    12,    13,    14,
      15,     7,    84,   346,   347,    81,    66,    89,     6,    66,
     386,   124,   125,    89,     6,     3,   129,     5,     6,     7,
     133,    81,   135,   136,    81,   401,    80,    12,    13,    17,
      18,    66,    81,   146,    22,     6,   379,   279,    66,    24,
      89,   279,    27,    66,   420,    80,    81,    82,    89,    82,
     292,    84,   428,    81,   292,   431,    71,    72,    81,    82,
      81,    82,   304,   305,   306,   307,   308,   309,    89,   412,
     183,   398,    66,    81,   187,     2,   189,    81,    63,    80,
     306,    89,   308,   124,   125,    89,    74,    81,    81,    80,
      81,    79,    80,    84,   135,     6,    89,    24,    89,    80,
      80,    81,     6,    81,    82,   146,    84,   349,   350,    89,
      24,    89,    80,   355,    73,    74,    75,    76,    77,   361,
      80,     3,    82,   361,     6,     7,   239,   298,   299,   300,
     301,   302,   303,    80,   376,    82,    63,    64,    89,   124,
     125,   383,   183,     3,   129,    72,     6,     7,    67,    63,
     135,   136,   394,    84,   396,   397,   398,    54,    55,   272,
     398,   146,    89,    80,     3,   407,     5,     6,     7,     3,
      80,   397,     6,     7,    89,     6,   418,    90,    17,    18,
       6,    67,    96,    22,   426,    23,    80,   429,    82,    83,
      82,   433,   434,   306,    84,   308,    80,   124,   125,    16,
     426,    80,   129,    82,    83,     6,   133,    90,   135,   136,
     124,   125,    75,    76,    77,   129,     2,    81,    66,   146,
      90,   135,   136,     6,    83,   338,   339,    83,    82,    17,
      18,    89,   146,   346,   347,    74,   349,    90,    24,    90,
      79,    80,   355,    31,    32,     6,    81,    90,    36,    37,
       6,    81,    81,    80,   239,    83,   183,    80,    83,    83,
     187,    83,   189,   376,    83,   306,   379,   308,    83,    81,
     383,    73,    74,    75,    76,    77,    80,    63,    64,    84,
      68,    69,    70,   396,   397,   398,    72,   272,    73,    74,
      75,    76,    77,    80,   407,    89,    84,    67,    26,   412,
      84,    83,    83,    89,    83,   418,    80,     6,   349,    81,
      16,    80,   239,   426,   355,    90,   429,    17,    18,    81,
     433,   434,    90,    10,    47,   239,    90,    27,    28,    29,
      30,    81,    81,    33,    81,   376,    81,    37,   124,   125,
      80,     5,   383,   129,    81,   272,    92,   133,    81,   135,
     136,    81,    90,   338,   339,   396,   397,   398,   272,    81,
     146,   346,   347,    92,   184,    17,   407,    67,   233,   234,
     235,   236,   237,    86,   292,   148,   405,   418,   398,   306,
      -1,   308,    -1,   272,    84,   426,    -1,    -1,   429,    -1,
      -1,    -1,   433,   434,   379,    -1,     2,   183,    -1,    -1,
      -1,   187,    -1,   189,    24,    -1,    -1,    -1,    -1,    -1,
      -1,   338,   339,    -1,    -1,    -1,    -1,    -1,    24,   346,
     347,    -1,   349,    -1,   338,   339,    -1,   412,   355,    -1,
      -1,    -1,   346,   347,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    24,    -1,    -1,    -1,   376,
      -1,    -1,   379,   239,    -1,    -1,   383,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,   379,    72,    87,    88,   396,
     397,   398,    -1,    -1,    -1,    17,    18,    -1,    98,    -1,
     407,    -1,    63,    89,    63,   412,   272,    -1,    -1,   403,
      -1,   418,     8,    -1,    -1,    37,    -1,    -1,   412,   426,
      -1,    -1,   429,    -1,   124,   125,   433,   434,    24,    -1,
      -1,    -1,    -1,    -1,    -1,   135,    -1,    -1,   124,   125,
     306,    -1,   308,   129,    -1,    67,   146,   133,    -1,   135,
     136,    73,    74,    75,    76,    77,    -1,    -1,    -1,    81,
     146,    -1,    84,   124,   125,   124,   125,    89,   129,    -1,
     129,    -1,   338,   339,   135,   136,   135,   136,    -1,    -1,
     346,   347,    -1,   349,    24,   146,    -1,   146,    -1,   355,
     190,    87,    88,    -1,    -1,    -1,    -1,   183,    -1,    -1,
      -1,   187,    -1,   189,    -1,    17,    18,    -1,    -1,    -1,
     376,    -1,    -1,   379,    -1,    -1,    -1,   383,    -1,    31,
      32,    -1,    -1,    -1,    -1,    37,    -1,    -1,   124,   125,
     396,   397,   398,   233,   234,   235,   236,   237,    -1,   135,
      -1,   407,    -1,    -1,    -1,    -1,   412,    87,    88,    -1,
     146,    -1,   418,   239,    -1,    -1,    68,    69,    70,    -1,
     426,    -1,    -1,   429,    -1,    -1,    -1,   433,   434,    -1,
      87,    88,    84,     3,     4,     5,     6,     7,   239,    -1,
     239,    -1,    -1,    -1,   124,   125,   272,    17,    18,    -1,
      -1,    -1,    22,    -1,    -1,   135,    -1,    -1,   298,   299,
     300,   301,   302,   303,   304,   305,   146,    -1,    -1,   309,
      -1,   272,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
     306,    -1,   308,   140,   141,   142,   143,   144,    58,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    79,
      80,    -1,   338,   339,    -1,    -1,    -1,    -1,    -1,    -1,
     346,   347,    -1,   349,    -1,    -1,    -1,    -1,    -1,   355,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,   339,   338,
     339,    -1,    -1,    -1,    -1,   346,   347,   346,   347,    -1,
     376,    -1,    -1,   379,    -1,    -1,    -1,   383,    -1,   216,
      -1,    -1,   298,   299,   300,   301,   302,   303,   304,   305,
     396,   397,   398,   309,    -1,    -1,    -1,    -1,   379,    -1,
     379,   407,    -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,
      -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     426,    -1,    -1,   429,    -1,    -1,    -1,   433,   434,    -1,
      -1,   412,    -1,   412,    -1,    -1,    -1,    -1,   298,   299,
     300,   301,   302,   303,   304,   305,    -1,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
       8,   298,   299,   300,   301,   302,   303,   304,   305,    17,
      18,    -1,   309,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,
      58,     6,    -1,     8,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,
      25,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    89,    -1,    91,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    53,    -1,
      -1,    -1,    -1,    58,     6,    -1,     8,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    -1,    -1,    25,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    89,    -1,    91,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    58,     6,    -1,     8,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    -1,    -1,    25,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    89,    -1,    91,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,
       6,    -1,     8,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,
      79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      89,    -1,    91,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    58,     6,    -1,     8,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      -1,    -1,    25,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    89,    -1,    91,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    -1,    -1,    -1,    -1,    58,     6,    -1,     8,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    25,    79,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    89,    -1,    91,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    -1,    -1,    -1,    -1,    58,     6,
      -1,     8,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    -1,    -1,    25,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    89,
      -1,    91,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
      -1,    58,     6,    -1,     8,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    -1,
      -1,    25,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    89,    -1,    91,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      -1,    -1,    -1,    -1,    58,     6,    -1,     8,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    25,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    89,    -1,    91,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    -1,    58,     6,    -1,
       8,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    -1,    -1,    25,    79,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    89,    90,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    52,    53,    -1,    -1,    17,    18,
      58,    -1,    -1,    -1,    62,     3,     4,     5,     6,     7,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    37,    17,
      18,    79,    -1,    -1,    22,    -1,    -1,    17,    18,    -1,
      -1,    89,    22,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    -1,    73,    74,    75,    76,    77,    -1,
      58,    -1,    81,    61,    -1,    84,    -1,    -1,    -1,    -1,
      89,    61,    -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      -1,    79,    80,    -1,    74,    -1,    -1,    -1,    78,    79,
      80,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    -1,    -1,    -1,    79,
      80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    94,    95,     0,     6,     8,    17,    18,    21,    22,
      25,    35,    39,    40,    41,    42,    43,    44,    45,    46,
      48,    49,    50,    51,    52,    53,    58,    62,    79,    89,
      96,    97,    98,   100,   101,   102,   103,   105,   110,   111,
     112,   113,   114,   120,   121,   122,   123,   126,   128,   129,
     130,   131,   132,   142,   147,   150,   151,   152,   153,   154,
     155,    16,    23,    80,    82,   106,    16,     6,   155,   155,
       4,   156,    84,    90,    34,     7,   159,   159,     6,   104,
       6,   121,   155,     6,   105,   121,     6,    80,    80,    80,
       6,     3,     5,     6,    22,    61,    74,    79,    80,   109,
     111,   113,   115,   116,   131,   139,   140,   141,   142,   147,
     148,   149,   152,   155,   156,   157,   158,   159,   160,    80,
     155,   159,     6,    89,    67,    67,    82,    84,    84,    80,
      66,    89,    89,    63,    82,    67,    80,    84,    17,    18,
      27,    28,    29,    30,    33,    37,    67,    84,    80,   117,
       6,     6,   109,   111,   113,   115,   131,   133,   134,   135,
     139,   142,   147,   152,   155,   156,   157,   158,   159,   160,
       3,     6,     7,   111,   131,   152,   155,    90,   117,     6,
     111,   131,   155,   119,    67,    84,    89,    82,   106,    78,
      80,   111,   113,   131,   139,   144,   145,   146,   149,   152,
     155,   156,   157,   158,   159,   160,   145,     6,   121,   127,
     147,   154,    16,    66,    82,    84,    80,   137,   138,   155,
     157,   140,   155,     6,   118,   139,    16,    66,    31,    32,
      68,    69,    70,    73,    74,    75,    76,    77,   155,    80,
      16,   148,   148,     3,     6,     7,   155,   155,   133,   121,
     131,     3,     6,     7,   148,   133,   155,   149,   155,   149,
     149,   149,   149,   155,   148,   150,   155,   155,     6,   118,
      90,    81,    66,    83,    83,    83,    83,     6,    91,   107,
     108,   114,   121,   150,   155,    90,    91,    96,   104,     6,
       3,     6,    90,   109,   111,   131,   143,   155,    12,    13,
      14,    15,    71,    72,    10,    11,    81,    36,    81,    89,
      90,     6,     3,     6,   155,   149,    66,    81,    81,    90,
       6,   140,   140,   140,   140,   140,   139,   141,   141,   141,
     141,   141,    81,   133,   117,    83,    83,    83,    80,    80,
      81,    89,    83,    83,    83,    81,    80,    80,    81,   119,
      84,   135,    91,   108,    89,   119,    26,    99,    83,    83,
      91,   107,   144,   144,   144,   144,   144,   144,   145,   145,
      90,    96,   136,   155,   136,   145,   119,    83,    83,    80,
      81,     6,    16,   119,    90,    81,    90,   133,   133,   133,
     133,    91,   155,    91,    80,    91,   119,    47,    89,    91,
     133,    90,    91,    54,    55,   124,   125,   119,    81,    81,
      81,    81,    80,   155,    91,   136,   127,    81,   119,   157,
      92,    91,   125,    91,   133,    81,    81,    91,    92,   119,
      81,    90,   136,   119,   119,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    94,    95,    95,    96,    96,    96,    96,    96,
      96,    97,    97,    97,    97,    98,    98,    99,   100,   100,
     100,   100,   100,   100,   101,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   106,   106,   107,   107,   108,   108,
     108,   109,   109,   109,   110,   110,   111,   111,   111,   111,
     112,   112,   112,   112,   112,   113,   114,   114,   114,   115,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   119,
     119,   120,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   124,   124,   125,   125,   126,   126,   127,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     132,   133,   133,   134,   134,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     137,   137,   138,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   141,   142,
     143,   143,   143,   143,   144,   144,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   146,
     147,   147,   147,   147,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   151,   151,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   153,   154,   154,   154,   154,   154,   154,   154,
     154,   155,   156,   157,   158,   158,   159,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     2,     1,
       1,     2,     2,     2,     3,     4,     5,     7,     1,     1,
       1,     2,     1,     1,     2,     2,     2,     4,     1,     3,
       4,     5,     5,     6,     0,     2,     1,     2,     1,     2,
       1,     1,     3,     6,     3,     3,     3,     3,     6,     3,
       6,     6,     9,     6,     6,     3,     7,     6,     6,     7,
       5,     5,     3,     3,     0,     3,     1,     3,     0,     2,
       0,     1,     4,     4,     4,     2,     3,     1,     1,     5,
       7,     7,     1,     2,     4,     3,     5,     9,     0,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     2,     4,     4,     1,     4,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     1,     1,     1,     1,     3,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     1,     1,     1,     2,     2,     1,     1
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
#line 71 "a.y"
                                   { execAndFreeNode((yyvsp[0].node));}
#line 2007 "y.tab.c"
    break;

  case 5: /* statement: ';'  */
#line 75 "a.y"
                   { (yyval.node) = opr(';' , 0 ); }
#line 2013 "y.tab.c"
    break;

  case 6: /* statement: declar_stmt  */
#line 76 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2019 "y.tab.c"
    break;

  case 7: /* statement: con_ctl_stmt  */
#line 77 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2025 "y.tab.c"
    break;

  case 8: /* statement: simple_stmt ';'  */
#line 78 "a.y"
                            { (yyval.node) = (yyvsp[-1].node); }
#line 2031 "y.tab.c"
    break;

  case 9: /* statement: require_stmt  */
#line 79 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2037 "y.tab.c"
    break;

  case 10: /* statement: try_stmt  */
#line 80 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2043 "y.tab.c"
    break;

  case 11: /* require_stmt: REQUIRE string_expr  */
#line 85 "a.y"
                                      { (yyval.node) = opr(REQUIRE , 1 , (yyvsp[0].node)); }
#line 2049 "y.tab.c"
    break;

  case 12: /* require_stmt: REQUIRE_ONCE string_expr  */
#line 86 "a.y"
                                      { (yyval.node) = opr(REQUIRE_ONCE , 1 , (yyvsp[0].node)); }
#line 2055 "y.tab.c"
    break;

  case 13: /* require_stmt: XINCLUDE string_expr  */
#line 87 "a.y"
                                      { (yyval.node) = opr(XINCLUDE , 1 , (yyvsp[0].node)); }
#line 2061 "y.tab.c"
    break;

  case 14: /* require_stmt: REF namespace_name_stmt ';'  */
#line 88 "a.y"
                                      { (yyval.node) = opr(REF , 1, string((yyvsp[-1].sValue))); }
#line 2067 "y.tab.c"
    break;

  case 15: /* try_stmt: XTRY '{' expr_list '}'  */
#line 93 "a.y"
                                   { (yyval.node) = opr(XTRY, 2,(yyvsp[-1].node),NULL); }
#line 2073 "y.tab.c"
    break;

  case 16: /* try_stmt: XTRY '{' expr_list '}' catch_block_stmt  */
#line 94 "a.y"
                                                   { (yyval.node) = opr(XTRY, 2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2079 "y.tab.c"
    break;

  case 17: /* catch_block_stmt: XCATCH '(' id_expr ')' '{' expr_list '}'  */
#line 98 "a.y"
                                                    { (yyval.node) = opr(XCATCH, 2, (yyvsp[-4].node),(yyvsp[-1].node)); }
#line 2085 "y.tab.c"
    break;

  case 18: /* declar_stmt: func_declar_stmt  */
#line 103 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2091 "y.tab.c"
    break;

  case 19: /* declar_stmt: var_declar_stmt  */
#line 104 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2097 "y.tab.c"
    break;

  case 20: /* declar_stmt: class_declar_stmt  */
#line 105 "a.y"
                                             { (yyval.node) = (yyvsp[0].node); }
#line 2103 "y.tab.c"
    break;

  case 21: /* declar_stmt: namespace_declar_stmt ';'  */
#line 106 "a.y"
                                    { (yyval.node) = (yyvsp[-1].node); }
#line 2109 "y.tab.c"
    break;

  case 22: /* declar_stmt: const_declar_stmt  */
#line 107 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2115 "y.tab.c"
    break;

  case 23: /* declar_stmt: local_declar_stmt  */
#line 108 "a.y"
                                             { (yyval.node) = (yyvsp[0].node); }
#line 2121 "y.tab.c"
    break;

  case 24: /* const_declar_stmt: XCONST var_declar_stmt  */
#line 114 "a.y"
                                 { (yyval.node) = opr(XCONST , 1,(yyvsp[0].node)); }
#line 2127 "y.tab.c"
    break;

  case 25: /* local_declar_stmt: XLOCAL var_declar_stmt  */
#line 119 "a.y"
                                   { (yyval.node) = opr(XLOCAL , 1,(yyvsp[0].node)); }
#line 2133 "y.tab.c"
    break;

  case 26: /* local_declar_stmt: XLOCAL class_declar_stmt  */
#line 120 "a.y"
                                   { (yyval.node) = opr(XLOCAL , 1,(yyvsp[0].node)); }
#line 2139 "y.tab.c"
    break;

  case 27: /* namespace_declar_stmt: XSET XPUBLIC '=' namespace_name_stmt  */
#line 125 "a.y"
                                               { (yyval.node) = changeNameSpace((yyvsp[0].sValue)); }
#line 2145 "y.tab.c"
    break;

  case 28: /* namespace_name_stmt: IDENTIFIER  */
#line 129 "a.y"
                      { (yyval.sValue) = (yyvsp[0].sValue) ; }
#line 2151 "y.tab.c"
    break;

  case 29: /* namespace_name_stmt: namespace_name_stmt '.' IDENTIFIER  */
#line 130 "a.y"
                                             { (yyval.sValue) = namespaceNameCat((yyvsp[-2].sValue),(yyvsp[0].sValue)) ; }
#line 2157 "y.tab.c"
    break;

  case 30: /* class_declar_stmt: IDENTIFIER extends_stmt '{' '}'  */
#line 135 "a.y"
                                                     {  (yyval.node) = claxx((yyvsp[-3].sValue) , (yyvsp[-2].sValue), NULL,false); }
#line 2163 "y.tab.c"
    break;

  case 31: /* class_declar_stmt: IDENTIFIER extends_stmt '{' class_body '}'  */
#line 136 "a.y"
                                                     { (yyval.node) = claxx((yyvsp[-4].sValue) , (yyvsp[-3].sValue), (yyvsp[-1].node),false); }
#line 2169 "y.tab.c"
    break;

  case 32: /* class_declar_stmt: AUTO IDENTIFIER extends_stmt '{' '}'  */
#line 137 "a.y"
                                                          {  (yyval.node) = claxx((yyvsp[-3].sValue) , (yyvsp[-2].sValue), NULL,true); }
#line 2175 "y.tab.c"
    break;

  case 33: /* class_declar_stmt: AUTO IDENTIFIER extends_stmt '{' class_body '}'  */
#line 138 "a.y"
                                                          {  (yyval.node) = claxx((yyvsp[-4].sValue) , (yyvsp[-3].sValue), (yyvsp[-1].node), true); }
#line 2181 "y.tab.c"
    break;

  case 34: /* extends_stmt: %empty  */
#line 143 "a.y"
                              { (yyval.sValue) = NULL; }
#line 2187 "y.tab.c"
    break;

  case 35: /* extends_stmt: EXTENDS IDENTIFIER  */
#line 144 "a.y"
                              { (yyval.sValue) = (yyvsp[0].sValue); }
#line 2193 "y.tab.c"
    break;

  case 36: /* class_body: class_body_stmt  */
#line 149 "a.y"
                                     { (yyval.node) = opr(CLAXX_BODY, 1, (yyvsp[0].node)); }
#line 2199 "y.tab.c"
    break;

  case 37: /* class_body: class_body class_body_stmt  */
#line 150 "a.y"
                                     { (yyval.node) = opr(CLAXX_BODY, 2, (yyvsp[-1].node), (yyvsp[0].node)); }
#line 2205 "y.tab.c"
    break;

  case 38: /* class_body_stmt: var_declar_stmt  */
#line 154 "a.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2211 "y.tab.c"
    break;

  case 39: /* class_body_stmt: single_assign_stmt ';'  */
#line 155 "a.y"
                                 { (yyval.node) = (yyvsp[-1].node); }
#line 2217 "y.tab.c"
    break;

  case 40: /* class_body_stmt: func_declar_stmt  */
#line 156 "a.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 2223 "y.tab.c"
    break;

  case 41: /* this_stmt: THIS  */
#line 161 "a.y"
                  { (yyval.node) = opr(THIS , 0 ); }
#line 2229 "y.tab.c"
    break;

  case 42: /* this_stmt: THIS '.' id_expr  */
#line 162 "a.y"
                             {  (yyval.node) = opr(THIS,1,(yyvsp[0].node)); }
#line 2235 "y.tab.c"
    break;

  case 43: /* this_stmt: THIS '.' id_expr '(' args_list ')'  */
#line 164 "a.y"
                                             { (yyval.node) = opr(THIS, 1 , opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) ) ); }
#line 2241 "y.tab.c"
    break;

  case 44: /* this_member_stmt: THIS '.' id_expr  */
#line 169 "a.y"
                              {  (yyval.node) = opr(THIS,1,(yyvsp[0].node)); }
#line 2247 "y.tab.c"
    break;

  case 45: /* this_member_stmt: THIS '.' class_member_stmt  */
#line 170 "a.y"
                                      {  (yyval.node) = opr(THIS, 1, (yyvsp[0].node) ); }
#line 2253 "y.tab.c"
    break;

  case 46: /* class_member_stmt: id_expr '.' id_expr  */
#line 175 "a.y"
                                { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 2259 "y.tab.c"
    break;

  case 47: /* class_member_stmt: class_member_func_stmt '.' id_expr  */
#line 176 "a.y"
                                                          { (yyval.node) =  opr(CLAXX_MEMBER,2, (yyvsp[-2].node),(yyvsp[0].node) );  }
#line 2265 "y.tab.c"
    break;

  case 48: /* class_member_stmt: IDENTIFIER '(' args_list ')' '.' id_expr  */
#line 177 "a.y"
                                                   { (yyval.node) = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var((yyvsp[-5].sValue)), argsNode((yyvsp[-3].args)) ) , (yyvsp[0].node)); }
#line 2271 "y.tab.c"
    break;

  case 49: /* class_member_stmt: class_member_stmt '.' id_expr  */
#line 178 "a.y"
                                         { (yyval.node) = opr(CLAXX_MEMBER,2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 2277 "y.tab.c"
    break;

  case 50: /* class_member_func_stmt: id_expr '.' id_expr '(' args_list ')'  */
#line 183 "a.y"
                                                 { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[-5].node), opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) ) );}
#line 2283 "y.tab.c"
    break;

  case 51: /* class_member_func_stmt: array_ele_stmt '.' id_expr '(' args_list ')'  */
#line 184 "a.y"
                                                        { (yyval.node) = opr(CLAXX_FUNC_CALL , 2, (yyvsp[-5].node), opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) ) );}
#line 2289 "y.tab.c"
    break;

  case 52: /* class_member_func_stmt: IDENTIFIER '(' args_list ')' '.' id_expr '(' args_list ')'  */
#line 185 "a.y"
                                                                     { (yyval.node) = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var((yyvsp[-8].sValue)), argsNode((yyvsp[-6].args)) ) , opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) )); }
#line 2295 "y.tab.c"
    break;

  case 53: /* class_member_func_stmt: class_member_stmt '.' id_expr '(' args_list ')'  */
#line 186 "a.y"
                                                                  { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[-5].node),opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) ) ); }
#line 2301 "y.tab.c"
    break;

  case 54: /* class_member_func_stmt: class_member_func_stmt '.' id_expr '(' args_list ')'  */
#line 187 "a.y"
                                                                  { (yyval.node) = opr(CLAXX_FUNC_CALL,2,(yyvsp[-5].node),opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) ) ); }
#line 2307 "y.tab.c"
    break;

  case 55: /* static_member_stmt: id_expr SCOPE id_expr  */
#line 192 "a.y"
                                  { (yyval.node) = opr(SCOPE, 2 ,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2313 "y.tab.c"
    break;

  case 56: /* func_declar_stmt: '~' IDENTIFIER FUNC_OP param_list '{' expr_list '}'  */
#line 198 "a.y"
                                                              { (yyval.node) = dtrt((yyvsp[-5].sValue),(yyvsp[-3].params),(yyvsp[-1].node));}
#line 2319 "y.tab.c"
    break;

  case 57: /* func_declar_stmt: IDENTIFIER FUNC_OP param_list '{' expr_list '}'  */
#line 199 "a.y"
                                                          { (yyval.node) = func((yyvsp[-5].sValue),(yyvsp[-3].params),(yyvsp[-1].node));}
#line 2325 "y.tab.c"
    break;

  case 58: /* func_declar_stmt: OPERATOR_X__ FUNC_OP param_list '{' expr_list '}'  */
#line 200 "a.y"
                                                            { (yyval.node) = func((yyvsp[-5].sValue),(yyvsp[-3].params),(yyvsp[-1].node));}
#line 2331 "y.tab.c"
    break;

  case 59: /* lambda_stmt: '(' parameter ')' FUNC_OP '{' expr_list '}'  */
#line 205 "a.y"
                                                      { (yyval.node) = lambda((yyvsp[-5].params),(yyvsp[-1].node)) ;}
#line 2337 "y.tab.c"
    break;

  case 60: /* lambda_stmt: IDENTIFIER FUNC_OP '{' expr_list '}'  */
#line 206 "a.y"
                                                 { (yyval.node) = lambda(params(NULL, (yyvsp[-4].sValue)),(yyvsp[-1].node)) ; }
#line 2343 "y.tab.c"
    break;

  case 61: /* lambda_stmt: lambda_args_stmt FUNC_OP '{' expr_list '}'  */
#line 207 "a.y"
                                                       { (yyval.node) = lambda((yyvsp[-4].params),(yyvsp[-1].node)) ; }
#line 2349 "y.tab.c"
    break;

  case 62: /* lambda_args_stmt: IDENTIFIER ',' IDENTIFIER  */
#line 211 "a.y"
                                    { (yyval.params) = params2((yyvsp[-2].sValue),(yyvsp[0].sValue));  }
#line 2355 "y.tab.c"
    break;

  case 63: /* lambda_args_stmt: lambda_args_stmt ',' IDENTIFIER  */
#line 212 "a.y"
                                           { (yyval.params) = params((yyvsp[-2].params),(yyvsp[0].sValue));  }
#line 2361 "y.tab.c"
    break;

  case 64: /* param_list: %empty  */
#line 216 "a.y"
                    { (yyval.params) = NULL; }
#line 2367 "y.tab.c"
    break;

  case 65: /* param_list: '(' parameter ')'  */
#line 217 "a.y"
                              { (yyval.params) = (yyvsp[-1].params); }
#line 2373 "y.tab.c"
    break;

  case 66: /* parameter: IDENTIFIER  */
#line 221 "a.y"
                     { (yyval.params) = params(NULL, (yyvsp[0].sValue)); }
#line 2379 "y.tab.c"
    break;

  case 67: /* parameter: parameter ',' IDENTIFIER  */
#line 222 "a.y"
                                   { (yyval.params) = params((yyvsp[-2].params),(yyvsp[0].sValue)); }
#line 2385 "y.tab.c"
    break;

  case 68: /* parameter: %empty  */
#line 223 "a.y"
                 { (yyval.params) = NULL; }
#line 2391 "y.tab.c"
    break;

  case 69: /* expr_list: expr_list statement  */
#line 227 "a.y"
                              { (yyval.node) = opr(';',2,(yyvsp[-1].node), (yyvsp[0].node)); }
#line 2397 "y.tab.c"
    break;

  case 70: /* expr_list: %empty  */
#line 228 "a.y"
            { (yyval.node) = NULL; }
#line 2403 "y.tab.c"
    break;

  case 71: /* element_var_declar_stmt: id_expr  */
#line 232 "a.y"
                                                                        { (yyval.node) = (yyvsp[0].node); }
#line 2409 "y.tab.c"
    break;

  case 72: /* element_var_declar_stmt: IDENTIFIER '[' XINTEGER ']'  */
#line 233 "a.y"
                                                { (yyval.node) = arrayNode((yyvsp[-3].sValue),(yyvsp[-1].iValue),NULL); }
#line 2415 "y.tab.c"
    break;

  case 73: /* element_var_declar_stmt: IDENTIFIER '[' IDENTIFIER ']'  */
#line 234 "a.y"
                                                     {  (yyval.node) = arrayNode((yyvsp[-3].sValue),-1,var((yyvsp[-1].sValue))); }
#line 2421 "y.tab.c"
    break;

  case 74: /* element_var_declar_stmt: IDENTIFIER '[' call_statement ']'  */
#line 235 "a.y"
                                                                { (yyval.node) = arrayNode((yyvsp[-3].sValue),-1,(yyvsp[-1].node)); }
#line 2427 "y.tab.c"
    break;

  case 75: /* var_declar_stmt: element_var_declar_stmt ';'  */
#line 240 "a.y"
                                       { (yyval.node) = opr(VAR_DECLAR , 1, (yyvsp[-1].node) ); }
#line 2433 "y.tab.c"
    break;

  case 76: /* var_declar_stmt: element_var_declar_stmt ',' var_declar_stmt  */
#line 241 "a.y"
                                                      { (yyval.node) = opr(VAR_DECLAR , 2, (yyvsp[-2].node),(yyvsp[0].node));}
#line 2439 "y.tab.c"
    break;

  case 77: /* con_ctl_stmt: selection_stmt  */
#line 246 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2445 "y.tab.c"
    break;

  case 78: /* con_ctl_stmt: loop_stmt  */
#line 247 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2451 "y.tab.c"
    break;

  case 79: /* selection_stmt: IF '(' logic_stmt ')' block  */
#line 252 "a.y"
                                                { (yyval.node) = opr(IF ,2,(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2457 "y.tab.c"
    break;

  case 80: /* selection_stmt: IF '(' logic_stmt ')' block ELSE block  */
#line 253 "a.y"
                                                 { (yyval.node) = opr(IF ,3,(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)) ; }
#line 2463 "y.tab.c"
    break;

  case 81: /* selection_stmt: SWITCH '(' id_expr ')' '{' case_stmt_list '}'  */
#line 254 "a.y"
                                                         { (yyval.node) = opr(SWITCH, 2 , (yyvsp[-4].node),(yyvsp[-1].node)); pretreatSwitch( (yyval.node) ) ; }
#line 2469 "y.tab.c"
    break;

  case 82: /* case_stmt_list: case_stmt  */
#line 258 "a.y"
                               { (yyval.node) = opr(CASE_LIST , 1 ,(yyvsp[0].node) ); }
#line 2475 "y.tab.c"
    break;

  case 83: /* case_stmt_list: case_stmt_list case_stmt  */
#line 259 "a.y"
                                   { (yyval.node) = opr(CASE_LIST , 2 ,(yyvsp[-1].node), (yyvsp[0].node) ); }
#line 2481 "y.tab.c"
    break;

  case 84: /* case_stmt: CASE double_expr ':' expr_list  */
#line 263 "a.y"
                                                { (yyval.node) = opr(CASE, 2 , (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2487 "y.tab.c"
    break;

  case 85: /* case_stmt: DEFAULT ':' expr_list  */
#line 264 "a.y"
                                                { (yyval.node) = opr(DEFAULT , 1, (yyvsp[0].node)); }
#line 2493 "y.tab.c"
    break;

  case 86: /* loop_stmt: WHILE '(' logic_stmt ')' block  */
#line 268 "a.y"
                                         { (yyval.node) = opr(WHILE , 2, (yyvsp[-2].node), (yyvsp[0].node) ); }
#line 2499 "y.tab.c"
    break;

  case 87: /* loop_stmt: FOR '(' for_1_stmt ';' logic_stmt ';' for_1_stmt ')' block  */
#line 269 "a.y"
                                                                     { (yyval.node) = opr(FOR,4,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2505 "y.tab.c"
    break;

  case 88: /* for_1_stmt: %empty  */
#line 274 "a.y"
              { (yyval.node) = NULL ; }
#line 2511 "y.tab.c"
    break;

  case 89: /* for_1_stmt: assign_stmt  */
#line 275 "a.y"
                       { (yyval.node) = (yyvsp[0].node); }
#line 2517 "y.tab.c"
    break;

  case 90: /* for_1_stmt: var_declar_stmt  */
#line 276 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2523 "y.tab.c"
    break;

  case 91: /* for_1_stmt: self_inc_dec_stmt  */
#line 277 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2529 "y.tab.c"
    break;

  case 92: /* simple_stmt: self_inc_dec_stmt  */
#line 282 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2535 "y.tab.c"
    break;

  case 93: /* simple_stmt: assign_stmt  */
#line 283 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2541 "y.tab.c"
    break;

  case 94: /* simple_stmt: call_statement  */
#line 284 "a.y"
                                          { (yyval.node) = (yyvsp[0].node); }
#line 2547 "y.tab.c"
    break;

  case 95: /* simple_stmt: DELETE IDENTIFIER  */
#line 285 "a.y"
                            { (yyval.node) = opr(DELETE, 1 ,(yyvsp[0].sValue) ); }
#line 2553 "y.tab.c"
    break;

  case 96: /* simple_stmt: interrupt_stmt  */
#line 286 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2559 "y.tab.c"
    break;

  case 97: /* simple_stmt: new_expr  */
#line 287 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2565 "y.tab.c"
    break;

  case 98: /* simple_stmt: restrict_stmt  */
#line 288 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2571 "y.tab.c"
    break;

  case 99: /* simple_stmt: XCONTINUE  */
#line 289 "a.y"
                    { (yyval.node) = opr(XCONTINUE , 0 ); }
#line 2577 "y.tab.c"
    break;

  case 100: /* simple_stmt: call_statement_pipeline  */
#line 290 "a.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 2583 "y.tab.c"
    break;

  case 101: /* restrict_stmt: RESTRICT  */
#line 295 "a.y"
                         { (yyval.node) = opr(RESTRICT,0);}
#line 2589 "y.tab.c"
    break;

  case 102: /* restrict_stmt: RESTRICT bool_expr  */
#line 296 "a.y"
                              { (yyval.node) = opr(RESTRICT,1,(yyvsp[0].node)); }
#line 2595 "y.tab.c"
    break;

  case 103: /* interrupt_stmt: BREAK  */
#line 300 "a.y"
                { (yyval.node) = opr(BREAK, 0); }
#line 2601 "y.tab.c"
    break;

  case 104: /* interrupt_stmt: RETURN  */
#line 301 "a.y"
                 { (yyval.node) = opr(RETURN , 0); }
#line 2607 "y.tab.c"
    break;

  case 105: /* interrupt_stmt: RETURN assign_stmt_value  */
#line 302 "a.y"
                                   { (yyval.node) = opr(RETURN , 1 ,(yyvsp[0].node));}
#line 2613 "y.tab.c"
    break;

  case 106: /* call_statement: array_ele_stmt '(' args_list ')'  */
#line 307 "a.y"
                                           { (yyval.node) = opr(FUNC_CALL,2, (yyvsp[-3].node), argsNode((yyvsp[-1].args)) ); }
#line 2619 "y.tab.c"
    break;

  case 107: /* call_statement: IDENTIFIER '(' args_list ')'  */
#line 308 "a.y"
                                       { (yyval.node) = opr(FUNC_CALL,2, var((yyvsp[-3].sValue)), argsNode((yyvsp[-1].args)) ); }
#line 2625 "y.tab.c"
    break;

  case 108: /* call_statement: class_member_func_stmt  */
#line 309 "a.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 2631 "y.tab.c"
    break;

  case 109: /* call_statement: static_member_stmt '(' args_list ')'  */
#line 310 "a.y"
                                               { (yyval.node) = opr(SCOPE_FUNC_CALL,2,(yyvsp[-3].node),argsNode((yyvsp[-1].args))); }
#line 2637 "y.tab.c"
    break;

  case 110: /* call_statement_pipeline: call_statement PIPELINE_OP call_statement ';'  */
#line 314 "a.y"
                                                        { (yyval.node) = opr(PIPELINE_OP,2, (yyvsp[-3].node), (yyvsp[-1].node)); }
#line 2643 "y.tab.c"
    break;

  case 111: /* args_list: %empty  */
#line 320 "a.y"
               { (yyval.args) = NULL; }
#line 2649 "y.tab.c"
    break;

  case 112: /* args_list: args_expr  */
#line 321 "a.y"
                     { (yyval.args) = (yyvsp[0].args); }
#line 2655 "y.tab.c"
    break;

  case 113: /* args_expr: args_expr_collection  */
#line 325 "a.y"
                                 { (yyval.args) = xArgs(NULL, (yyvsp[0].node)); }
#line 2661 "y.tab.c"
    break;

  case 114: /* args_expr: args_expr ',' args_expr_collection  */
#line 326 "a.y"
                                               { (yyval.args) = xArgs((yyvsp[-2].args), (yyvsp[0].node)); }
#line 2667 "y.tab.c"
    break;

  case 115: /* args_expr_collection: lambda_stmt  */
#line 330 "a.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 2673 "y.tab.c"
    break;

  case 116: /* args_expr_collection: bool_expr  */
#line 331 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 2679 "y.tab.c"
    break;

  case 117: /* args_expr_collection: double_expr  */
#line 332 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2685 "y.tab.c"
    break;

  case 118: /* args_expr_collection: IDENTIFIER  */
#line 333 "a.y"
                                        { (yyval.node) = var((yyvsp[0].sValue)); }
#line 2691 "y.tab.c"
    break;

  case 119: /* args_expr_collection: string_expr  */
#line 334 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2697 "y.tab.c"
    break;

  case 120: /* args_expr_collection: uminus_expr  */
#line 335 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 2703 "y.tab.c"
    break;

  case 121: /* args_expr_collection: call_statement  */
#line 336 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 2709 "y.tab.c"
    break;

  case 122: /* args_expr_collection: arithmetic_stmt  */
#line 337 "a.y"
                          { (yyval.node) = (yyvsp[0].node);}
#line 2715 "y.tab.c"
    break;

  case 123: /* args_expr_collection: array_ele_stmt  */
#line 338 "a.y"
                          { (yyval.node) = (yyvsp[0].node);}
#line 2721 "y.tab.c"
    break;

  case 124: /* args_expr_collection: class_member_stmt  */
#line 339 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2727 "y.tab.c"
    break;

  case 125: /* args_expr_collection: static_member_stmt  */
#line 340 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2733 "y.tab.c"
    break;

  case 126: /* args_expr_collection: new_expr  */
#line 341 "a.y"
                          { (yyval.node) = (yyvsp[0].node);}
#line 2739 "y.tab.c"
    break;

  case 127: /* args_expr_collection: null_expr  */
#line 342 "a.y"
                                  { (yyval.node) = (yyvsp[0].node); }
#line 2745 "y.tab.c"
    break;

  case 128: /* block: '{' expr_list '}'  */
#line 346 "a.y"
                             { (yyval.node) = (yyvsp[-1].node);}
#line 2751 "y.tab.c"
    break;

  case 129: /* block: statement  */
#line 347 "a.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2757 "y.tab.c"
    break;

  case 130: /* double_or_ps_expr: double_expr  */
#line 353 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2763 "y.tab.c"
    break;

  case 131: /* double_or_ps_expr: parentheses_stmt  */
#line 354 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 2769 "y.tab.c"
    break;

  case 132: /* parentheses_stmt: '(' assign_stmt_value_eq ')'  */
#line 359 "a.y"
                                        { (yyval.node) = (yyvsp[-1].node); }
#line 2775 "y.tab.c"
    break;

  case 133: /* arithmetic_stmt: arithmetic_stmt_factor '+' arithmetic_stmt_factor  */
#line 365 "a.y"
                                                            { (yyval.node) = opr('+',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2781 "y.tab.c"
    break;

  case 134: /* arithmetic_stmt: arithmetic_stmt_factor '-' arithmetic_stmt_factor  */
#line 366 "a.y"
                                                            { (yyval.node) = opr('-',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2787 "y.tab.c"
    break;

  case 135: /* arithmetic_stmt: arithmetic_stmt_factor '*' arithmetic_stmt_factor  */
#line 367 "a.y"
                                                            { (yyval.node) = opr('*',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2793 "y.tab.c"
    break;

  case 136: /* arithmetic_stmt: arithmetic_stmt_factor '/' arithmetic_stmt_factor  */
#line 368 "a.y"
                                                            { (yyval.node) = opr('/',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2799 "y.tab.c"
    break;

  case 137: /* arithmetic_stmt: arithmetic_stmt_factor '%' arithmetic_stmt_factor  */
#line 369 "a.y"
                                                            { (yyval.node) = opr('%',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2805 "y.tab.c"
    break;

  case 138: /* arithmetic_stmt: bit_opr_factor '&' bit_opr_factor  */
#line 370 "a.y"
                                             { (yyval.node) = opr('&',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2811 "y.tab.c"
    break;

  case 139: /* arithmetic_stmt: bit_opr_factor '|' bit_opr_factor  */
#line 371 "a.y"
                                             { (yyval.node) = opr('|',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2817 "y.tab.c"
    break;

  case 140: /* arithmetic_stmt: bit_opr_factor '^' bit_opr_factor  */
#line 372 "a.y"
                                             { (yyval.node) = opr('^',2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2823 "y.tab.c"
    break;

  case 141: /* arithmetic_stmt: '~' bit_opr_factor  */
#line 373 "a.y"
                              { (yyval.node) = opr('~',1,(yyvsp[0].node)); }
#line 2829 "y.tab.c"
    break;

  case 142: /* arithmetic_stmt: bit_opr_factor LEFT_SHIFT bit_opr_factor  */
#line 374 "a.y"
                                                    { (yyval.node) = opr(LEFT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2835 "y.tab.c"
    break;

  case 143: /* arithmetic_stmt: bit_opr_factor RIGHT_SHIFT bit_opr_factor  */
#line 375 "a.y"
                                                     { (yyval.node) = opr(RIGHT_SHIFT,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2841 "y.tab.c"
    break;

  case 144: /* bit_opr_factor: XINTEGER  */
#line 380 "a.y"
                   { (yyval.node) = xint((yyvsp[0].iValue)); }
#line 2847 "y.tab.c"
    break;

  case 145: /* bit_opr_factor: id_expr  */
#line 381 "a.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2853 "y.tab.c"
    break;

  case 146: /* arithmetic_stmt_factor: assign_stmt_value_eq  */
#line 386 "a.y"
                                  { (yyval.node) = (yyvsp[0].node) ; }
#line 2859 "y.tab.c"
    break;

  case 147: /* arithmetic_stmt_factor: arithmetic_stmt  */
#line 387 "a.y"
                                  { (yyval.node) = (yyvsp[0].node) ; }
#line 2865 "y.tab.c"
    break;

  case 148: /* arithmetic_stmt_factor: '(' arithmetic_stmt ')'  */
#line 388 "a.y"
                                  { (yyval.node) = (yyvsp[-1].node) ; }
#line 2871 "y.tab.c"
    break;

  case 149: /* new_expr: NEW id_expr '(' args_list ')'  */
#line 393 "a.y"
                                        { (yyval.node) = opr(NEW ,2, (yyvsp[-3].node) , argsNode((yyvsp[-1].args)) ); }
#line 2877 "y.tab.c"
    break;

  case 150: /* not_expr_value: id_expr  */
#line 397 "a.y"
                                                { (yyval.node) = (yyvsp[0].node); }
#line 2883 "y.tab.c"
    break;

  case 151: /* not_expr_value: call_statement  */
#line 398 "a.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 2889 "y.tab.c"
    break;

  case 152: /* not_expr_value: class_member_stmt  */
#line 399 "a.y"
                                { (yyval.node) = (yyvsp[0].node); }
#line 2895 "y.tab.c"
    break;

  case 153: /* not_expr_value: this_stmt  */
#line 400 "a.y"
                                        { (yyval.node) = (yyvsp[0].node); }
#line 2901 "y.tab.c"
    break;

  case 154: /* bool_param_expr: assign_stmt_value_eq  */
#line 405 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 2907 "y.tab.c"
    break;

  case 155: /* bool_param_expr: arithmetic_stmt  */
#line 406 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2913 "y.tab.c"
    break;

  case 156: /* bool_param_expr: bool_expr  */
#line 407 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 2919 "y.tab.c"
    break;

  case 157: /* bool_param_expr: null_expr  */
#line 408 "a.y"
                              { (yyval.node) = (yyvsp[0].node); }
#line 2925 "y.tab.c"
    break;

  case 158: /* logic_stmt: bool_param_expr  */
#line 413 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2931 "y.tab.c"
    break;

  case 159: /* logic_stmt: type_judge_stmt  */
#line 414 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 2937 "y.tab.c"
    break;

  case 160: /* logic_stmt: '!' not_expr_value  */
#line 415 "a.y"
                                 { (yyval.node) = opr('!', 1, (yyvsp[0].node));}
#line 2943 "y.tab.c"
    break;

  case 161: /* logic_stmt: bool_param_expr '>' bool_param_expr  */
#line 416 "a.y"
                                              { (yyval.node) = opr('>',2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2949 "y.tab.c"
    break;

  case 162: /* logic_stmt: bool_param_expr '<' bool_param_expr  */
#line 417 "a.y"
                                              { (yyval.node) = opr('<',2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2955 "y.tab.c"
    break;

  case 163: /* logic_stmt: bool_param_expr LE_OP bool_param_expr  */
#line 418 "a.y"
                                                { (yyval.node) = opr( LE_OP,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2961 "y.tab.c"
    break;

  case 164: /* logic_stmt: bool_param_expr GE_OP bool_param_expr  */
#line 419 "a.y"
                                                { (yyval.node) = opr( GE_OP,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2967 "y.tab.c"
    break;

  case 165: /* logic_stmt: bool_param_expr EQ_OP bool_param_expr  */
#line 420 "a.y"
                                                { (yyval.node) = opr( EQ_OP,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2973 "y.tab.c"
    break;

  case 166: /* logic_stmt: bool_param_expr NE_OP bool_param_expr  */
#line 421 "a.y"
                                                { (yyval.node) = opr( NE_OP,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2979 "y.tab.c"
    break;

  case 167: /* logic_stmt: logic_stmt AND_OP logic_stmt  */
#line 422 "a.y"
                                       { (yyval.node) = opr(AND_OP,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2985 "y.tab.c"
    break;

  case 168: /* logic_stmt: logic_stmt OR_OP logic_stmt  */
#line 423 "a.y"
                                       { (yyval.node) = opr(OR_OP,2,(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2991 "y.tab.c"
    break;

  case 169: /* type_judge_stmt: id_expr XIS id_expr  */
#line 428 "a.y"
                               { (yyval.node) = opr(XIS ,2 , (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2997 "y.tab.c"
    break;

  case 170: /* self_inc_dec_stmt: INC_OP id_expr  */
#line 433 "a.y"
                         { (yyval.node) = opr(INC_OP,1, (yyvsp[0].node) ); }
#line 3003 "y.tab.c"
    break;

  case 171: /* self_inc_dec_stmt: DEC_OP id_expr  */
#line 434 "a.y"
                         { (yyval.node) = opr(DEC_OP,1, (yyvsp[0].node) ); }
#line 3009 "y.tab.c"
    break;

  case 172: /* self_inc_dec_stmt: id_expr INC_OP  */
#line 435 "a.y"
                         { (yyval.node) = sopr(INC_OP,1, (yyvsp[-1].node) ); }
#line 3015 "y.tab.c"
    break;

  case 173: /* self_inc_dec_stmt: id_expr DEC_OP  */
#line 436 "a.y"
                         { (yyval.node) = sopr(DEC_OP,1, (yyvsp[-1].node) ); }
#line 3021 "y.tab.c"
    break;

  case 174: /* assign_stmt_value: double_expr  */
#line 441 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3027 "y.tab.c"
    break;

  case 175: /* assign_stmt_value: uminus_expr  */
#line 442 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3033 "y.tab.c"
    break;

  case 176: /* assign_stmt_value: bool_expr  */
#line 443 "a.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 3039 "y.tab.c"
    break;

  case 177: /* assign_stmt_value: arithmetic_stmt  */
#line 444 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 3045 "y.tab.c"
    break;

  case 178: /* assign_stmt_value: call_statement  */
#line 445 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 3051 "y.tab.c"
    break;

  case 179: /* assign_stmt_value: lambda_stmt  */
#line 446 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3057 "y.tab.c"
    break;

  case 180: /* assign_stmt_value: id_expr  */
#line 447 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3063 "y.tab.c"
    break;

  case 181: /* assign_stmt_value: string_expr  */
#line 448 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3069 "y.tab.c"
    break;

  case 182: /* assign_stmt_value: self_inc_dec_stmt  */
#line 449 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3075 "y.tab.c"
    break;

  case 183: /* assign_stmt_value: new_expr  */
#line 450 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 3081 "y.tab.c"
    break;

  case 184: /* assign_stmt_value: class_member_stmt  */
#line 451 "a.y"
                                            { (yyval.node) = (yyvsp[0].node); }
#line 3087 "y.tab.c"
    break;

  case 185: /* assign_stmt_value: null_expr  */
#line 452 "a.y"
                         { (yyval.node) = (yyvsp[0].node); }
#line 3093 "y.tab.c"
    break;

  case 186: /* assign_stmt_value: this_stmt  */
#line 453 "a.y"
                                     { (yyval.node) = (yyvsp[0].node); }
#line 3099 "y.tab.c"
    break;

  case 187: /* assign_stmt_value: array_ele_stmt  */
#line 454 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 3105 "y.tab.c"
    break;

  case 188: /* assign_stmt_value: static_member_stmt  */
#line 455 "a.y"
                             { (yyval.node) =(yyvsp[0].node) ;}
#line 3111 "y.tab.c"
    break;

  case 189: /* assign_stmt_value_eq: double_expr  */
#line 460 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3117 "y.tab.c"
    break;

  case 190: /* assign_stmt_value_eq: uminus_expr  */
#line 461 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3123 "y.tab.c"
    break;

  case 191: /* assign_stmt_value_eq: string_expr  */
#line 462 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3129 "y.tab.c"
    break;

  case 192: /* assign_stmt_value_eq: call_statement  */
#line 463 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3135 "y.tab.c"
    break;

  case 193: /* assign_stmt_value_eq: id_expr  */
#line 464 "a.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 3141 "y.tab.c"
    break;

  case 194: /* assign_stmt_value_eq: self_inc_dec_stmt  */
#line 465 "a.y"
                            { (yyval.node) = (yyvsp[0].node); }
#line 3147 "y.tab.c"
    break;

  case 195: /* assign_stmt_value_eq: class_member_stmt  */
#line 466 "a.y"
                                             { (yyval.node) = (yyvsp[0].node); }
#line 3153 "y.tab.c"
    break;

  case 196: /* assign_stmt_value_eq: static_member_stmt  */
#line 467 "a.y"
                             { (yyval.node) = (yyvsp[0].node); }
#line 3159 "y.tab.c"
    break;

  case 197: /* assign_stmt_value_eq: this_stmt  */
#line 468 "a.y"
                                         { (yyval.node) = (yyvsp[0].node); }
#line 3165 "y.tab.c"
    break;

  case 198: /* assign_stmt_value_eq: array_ele_stmt  */
#line 469 "a.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 3171 "y.tab.c"
    break;

  case 199: /* single_assign_stmt: id_expr '=' assign_stmt_value  */
#line 474 "a.y"
                                        { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 3177 "y.tab.c"
    break;

  case 200: /* single_assign_stmt: id_expr '=' single_assign_stmt  */
#line 475 "a.y"
                                         { (yyval.node) = opr('=',2, (yyvsp[-2].node), (yyvsp[0].node) ); }
#line 3183 "y.tab.c"
    break;

  case 201: /* class_member_assign_stmt: class_member_stmt '=' assign_stmt_value  */
#line 479 "a.y"
                                                   { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 3189 "y.tab.c"
    break;

  case 202: /* class_member_assign_stmt: this_member_stmt '=' assign_stmt_value  */
#line 480 "a.y"
                                                   { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) ); }
#line 3195 "y.tab.c"
    break;

  case 203: /* array_ele_stmt: IDENTIFIER '[' XINTEGER ']'  */
#line 485 "a.y"
                                         { (yyval.node) = arr((yyvsp[-3].sValue), (yyvsp[-1].iValue), NULL); }
#line 3201 "y.tab.c"
    break;

  case 204: /* array_ele_stmt: IDENTIFIER '[' IDENTIFIER ']'  */
#line 486 "a.y"
                                         { (yyval.node) = arr((yyvsp[-3].sValue), -1, var((yyvsp[-1].sValue))) ; }
#line 3207 "y.tab.c"
    break;

  case 205: /* array_ele_stmt: IDENTIFIER '[' TSTRING ']'  */
#line 487 "a.y"
                                      { (yyval.node) = arr((yyvsp[-3].sValue), -1, string((yyvsp[-1].sValue))) ; }
#line 3213 "y.tab.c"
    break;

  case 206: /* array_ele_stmt: class_member_stmt '[' XINTEGER ']'  */
#line 488 "a.y"
                                              {  (yyval.node) = arr2((yyvsp[-3].node), (yyvsp[-1].iValue), NULL) ; }
#line 3219 "y.tab.c"
    break;

  case 207: /* array_ele_stmt: class_member_stmt '[' IDENTIFIER ']'  */
#line 489 "a.y"
                                                {  (yyval.node) = arr2((yyvsp[-3].node), -1, var((yyvsp[-1].sValue))) ; }
#line 3225 "y.tab.c"
    break;

  case 208: /* array_ele_stmt: class_member_stmt '[' TSTRING ']'  */
#line 490 "a.y"
                                             {  (yyval.node) = arr2((yyvsp[-3].node), -1, string((yyvsp[-1].sValue))) ; }
#line 3231 "y.tab.c"
    break;

  case 209: /* array_ele_stmt: call_statement '[' XINTEGER ']'  */
#line 491 "a.y"
                                           {  (yyval.node) = arr2((yyvsp[-3].node),  (yyvsp[-1].iValue), NULL ) ; }
#line 3237 "y.tab.c"
    break;

  case 210: /* array_ele_stmt: call_statement '[' IDENTIFIER ']'  */
#line 492 "a.y"
                                             {  (yyval.node) = arr2((yyvsp[-3].node), -1, var((yyvsp[-1].sValue))) ; }
#line 3243 "y.tab.c"
    break;

  case 211: /* array_ele_stmt: call_statement '[' TSTRING ']'  */
#line 493 "a.y"
                                          {  (yyval.node) = arr2((yyvsp[-3].node), -1, string((yyvsp[-1].sValue))) ; }
#line 3249 "y.tab.c"
    break;

  case 212: /* array_ele_assign_stmt: array_ele_stmt '=' assign_stmt_value  */
#line 499 "a.y"
                                                { (yyval.node) = opr('=',2, (yyvsp[-2].node),(yyvsp[0].node) );  }
#line 3255 "y.tab.c"
    break;

  case 213: /* assign_stmt: single_assign_stmt  */
#line 504 "a.y"
                               { (yyval.node) = (yyvsp[0].node); }
#line 3261 "y.tab.c"
    break;

  case 214: /* assign_stmt: class_member_assign_stmt  */
#line 505 "a.y"
                                   { (yyval.node) = (yyvsp[0].node) ;}
#line 3267 "y.tab.c"
    break;

  case 215: /* assign_stmt: array_ele_assign_stmt  */
#line 506 "a.y"
                                 { (yyval.node) = (yyvsp[0].node); }
#line 3273 "y.tab.c"
    break;

  case 216: /* assign_stmt: id_expr ADD_EQ assign_stmt_value_eq  */
#line 507 "a.y"
                                              { (yyval.node) = opr(ADD_EQ,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3279 "y.tab.c"
    break;

  case 217: /* assign_stmt: id_expr SUB_EQ assign_stmt_value_eq  */
#line 508 "a.y"
                                              { (yyval.node) = opr(SUB_EQ,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3285 "y.tab.c"
    break;

  case 218: /* assign_stmt: id_expr MUL_EQ assign_stmt_value_eq  */
#line 509 "a.y"
                                              { (yyval.node) = opr(MUL_EQ,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3291 "y.tab.c"
    break;

  case 219: /* assign_stmt: id_expr DIV_EQ assign_stmt_value_eq  */
#line 510 "a.y"
                                              { (yyval.node) = opr(DIV_EQ,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3297 "y.tab.c"
    break;

  case 220: /* assign_stmt: id_expr MOD_EQ assign_stmt_value_eq  */
#line 511 "a.y"
                                              { (yyval.node) = opr(MOD_EQ,2,(yyvsp[-2].node),(yyvsp[0].node));}
#line 3303 "y.tab.c"
    break;

  case 221: /* id_expr: IDENTIFIER  */
#line 526 "a.y"
                     { (yyval.node) = var((yyvsp[0].sValue)); }
#line 3309 "y.tab.c"
    break;

  case 222: /* bool_expr: TBOOL  */
#line 530 "a.y"
                  { (yyval.node) = number((yyvsp[0].iValue)); }
#line 3315 "y.tab.c"
    break;

  case 223: /* double_expr: TDOUBLE  */
#line 548 "a.y"
                  { (yyval.node) = number((yyvsp[0].dValue)); }
#line 3321 "y.tab.c"
    break;

  case 224: /* uminus_expr: '-' double_or_ps_expr  */
#line 552 "a.y"
                                             { (yyval.node) = opr(UMINUS, 1, (yyvsp[0].node) ); }
#line 3327 "y.tab.c"
    break;

  case 225: /* uminus_expr: '-' id_expr  */
#line 553 "a.y"
                                             { (yyval.node) = opr(UMINUS, 1, (yyvsp[0].node) ); }
#line 3333 "y.tab.c"
    break;

  case 226: /* string_expr: TSTRING  */
#line 557 "a.y"
                   { (yyval.node) = string((yyvsp[0].sValue)); }
#line 3339 "y.tab.c"
    break;

  case 227: /* null_expr: XNULL  */
#line 561 "a.y"
                  { (yyval.node) = xnull(); }
#line 3345 "y.tab.c"
    break;


#line 3349 "y.tab.c"

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

#line 622 "a.y"



int main(int argc, char *argv[]){

	return programRun(argc, argv);
}
