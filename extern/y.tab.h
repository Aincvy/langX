/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TINTEGER = 258,
     TBOOL = 259,
     TDOUBLE = 260,
     IDENTIFIER = 261,
     TSTRING = 262,
     OPERATOR_X__ = 263,
     OP_CALC = 264,
     FUNC_OP = 265,
     FUNC_CALL = 266,
     VAR_DECLAR = 267,
     ARRAY_ELE = 268,
     KEY_TRY = 269,
     KEY_PUBLIC = 270,
     KEY_SET = 271,
     KEY_IS = 272,
     KEY_REF = 273,
     KEY_CONTINUE = 274,
     KEY_NEW = 275,
     KEY_CATCH = 276,
     KEY_THIS = 277,
     KEY_EXTENDS = 278,
     KEY_RESTRICT = 279,
     KEY_AUTO = 280,
     KEY_CONST = 281,
     KEY_LOCAL = 282,
     KEY_IF = 283,
     KEY_ELSE = 284,
     KEY_WHILE = 285,
     KEY_FOR = 286,
     KEY_DELETE = 287,
     KEY_BREAK = 288,
     KEY_RETURN = 289,
     KEY_SWITCH = 290,
     KEY_CASE = 291,
     KEY_DEFAULT = 292,
     KEY_NULL = 293,
     CASE_LIST = 294,
     CLAXX_BODY = 295,
     CLAXX_MEMBER = 296,
     CLAXX_FUNC_CALL = 297,
     SCOPE_FUNC_CALL = 298,
     SCOPE = 299,
     LEFT_SHIFT = 300,
     RIGHT_SHIFT = 301,
     INC_OP = 302,
     DEC_OP = 303,
     OPR_NODE_LIST = 304,
     OPR_CHANGE_NAME_SPACE = 305,
     OPR_GET_NAME_SPACE = 306,
     OPR_CLASS_DECLARE = 307,
     OPR_INC_DEC = 308,
     OPR_IF_ELSE = 309,
     OPR_MULTIPLE_ID = 310,
     OPR_START_IF = 311,
     OPR_ARGS_LIST = 312,
     KEY_REQUIRE = 313,
     KEY_REQUIRE_ONCE = 314,
     KEY_INCLUDE = 315,
     ADD_EQ = 316,
     SUB_EQ = 317,
     MUL_EQ = 318,
     DIV_EQ = 319,
     MOD_EQ = 320,
     LE_OP = 321,
     GE_OP = 322,
     EQ_OP = 323,
     NE_OP = 324,
     AND_OP = 325,
     OR_OP = 326,
     IFX = 327,
     ELSE = 328,
     PIPELINE_OP = 329,
     INC_OP_BACK = 330,
     PRIORITY3 = 331,
     PRIORITY2 = 332,
     PRIORITY1 = 333,
     UMINUS = 334
   };
#endif


/* Copy the first part of user declarations.  */
#line 1 "a.y"


#include <string.h>
#include "../include/NodeCreator.h"
#include "../include/Program.h"



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE 
#line 9 "a.y"
{
 int iValue;
 double dValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
}
/* Line 2616 of glr.c.  */
#line 145 "y.tab.h"
	YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{

  char yydummy;

} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;



