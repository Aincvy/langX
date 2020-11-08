/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    OPR_GET_NAME_SPACE = 301,      /* OPR_GET_NAME_SPACE  */
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
#define OPR_GET_NAME_SPACE 301
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

#line 229 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
