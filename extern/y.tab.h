/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Skeleton interface for Bison GLR parsers in C

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
    INC_OP = 299,                  /* INC_OP  */
    DEC_OP = 300,                  /* DEC_OP  */
    OPR_NODE_LIST = 301,           /* OPR_NODE_LIST  */
    OPR_CHANGE_NAME_SPACE = 302,   /* OPR_CHANGE_NAME_SPACE  */
    OPR_GET_NAME_SPACE = 303,      /* OPR_GET_NAME_SPACE  */
    OPR_CLASS_DECLARE = 304,       /* OPR_CLASS_DECLARE  */
    OPR_INC_DEC = 305,             /* OPR_INC_DEC  */
    OPR_IF_ELSE = 306,             /* OPR_IF_ELSE  */
    OPR_MULTIPLE_ID = 307,         /* OPR_MULTIPLE_ID  */
    OPR_START_IF = 308,            /* OPR_START_IF  */
    OPR_ARGS_LIST = 309,           /* OPR_ARGS_LIST  */
    KEY_REQUIRE = 310,             /* KEY_REQUIRE  */
    KEY_REQUIRE_ONCE = 311,        /* KEY_REQUIRE_ONCE  */
    KEY_INCLUDE = 312,             /* KEY_INCLUDE  */
    KEY_AUTO = 313,                /* KEY_AUTO  */
    KEY_CONST = 314,               /* KEY_CONST  */
    KEY_LOCAL = 315,               /* KEY_LOCAL  */
    ADD_EQ = 316,                  /* ADD_EQ  */
    SUB_EQ = 317,                  /* SUB_EQ  */
    MUL_EQ = 318,                  /* MUL_EQ  */
    DIV_EQ = 319,                  /* DIV_EQ  */
    MOD_EQ = 320,                  /* MOD_EQ  */
    LE_OP = 321,                   /* LE_OP  */
    GE_OP = 322,                   /* GE_OP  */
    EQ_OP = 323,                   /* EQ_OP  */
    NE_OP = 324,                   /* NE_OP  */
    AND_OP = 325,                  /* AND_OP  */
    OR_OP = 326,                   /* OR_OP  */
    IFX = 327,                     /* IFX  */
    ELSE = 328,                    /* ELSE  */
    PIPELINE_OP = 329,             /* PIPELINE_OP  */
    INC_OP_BACK = 330,             /* INC_OP_BACK  */
    PRIORITY3 = 331,               /* PRIORITY3  */
    PRIORITY2 = 332,               /* PRIORITY2  */
    PRIORITY1 = 333,               /* PRIORITY1  */
    UMINUS = 334                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

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

#line 147 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
