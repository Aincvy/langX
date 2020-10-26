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

#line 213 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
