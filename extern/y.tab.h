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

#line 215 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
