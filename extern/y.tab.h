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
    IFX = 318,                     /* IFX  */
    PIPELINE_OP = 319,             /* PIPELINE_OP  */
    INC_OP_BACK = 320,             /* INC_OP_BACK  */
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
#define IFX 318
#define PIPELINE_OP 319
#define INC_OP_BACK 320
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

#line 213 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
