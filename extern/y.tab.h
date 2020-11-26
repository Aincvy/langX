/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
     KEY_IF = 280,
     KEY_ELSE = 281,
     KEY_WHILE = 282,
     KEY_FOR = 283,
     KEY_DELETE = 284,
     KEY_BREAK = 285,
     KEY_RETURN = 286,
     KEY_SWITCH = 287,
     KEY_CASE = 288,
     KEY_DEFAULT = 289,
     KEY_NULL = 290,
     CASE_LIST = 291,
     CLAXX_BODY = 292,
     CLAXX_MEMBER = 293,
     CLAXX_FUNC_CALL = 294,
     SCOPE_FUNC_CALL = 295,
     SCOPE = 296,
     LEFT_SHIFT = 297,
     RIGHT_SHIFT = 298,
     OPR_NODE_LIST = 299,
     OPR_CHANGE_NAME_SPACE = 300,
     OPR_GET_NAME_SPACE = 301,
     OPR_CLASS_DECLARE = 302,
     OPR_INC_DEC = 303,
     OPR_IF_ELSE = 304,
     OPR_MULTIPLE_ID = 305,
     OPR_START_IF = 306,
     KEY_REQUIRE = 307,
     KEY_REQUIRE_ONCE = 308,
     KEY_INCLUDE = 309,
     KEY_AUTO = 310,
     KEY_CONST = 311,
     KEY_LOCAL = 312,
     ADD_EQ = 313,
     SUB_EQ = 314,
     MUL_EQ = 315,
     DIV_EQ = 316,
     MOD_EQ = 317,
     LE_OP = 318,
     GE_OP = 319,
     EQ_OP = 320,
     NE_OP = 321,
     INC_OP = 322,
     DEC_OP = 323,
     AND_OP = 324,
     OR_OP = 325,
     IFX = 326,
     ELSE = 327,
     PIPELINE_OP = 328,
     INC_OP_BACK = 329,
     PRIORITY3 = 330,
     PRIORITY2 = 331,
     PRIORITY1 = 332,
     UMINUS = 333
   };
#endif
/* Tokens.  */
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
#define OPR_START_IF 306
#define KEY_REQUIRE 307
#define KEY_REQUIRE_ONCE 308
#define KEY_INCLUDE 309
#define KEY_AUTO 310
#define KEY_CONST 311
#define KEY_LOCAL 312
#define ADD_EQ 313
#define SUB_EQ 314
#define MUL_EQ 315
#define DIV_EQ 316
#define MOD_EQ 317
#define LE_OP 318
#define GE_OP 319
#define EQ_OP 320
#define NE_OP 321
#define INC_OP 322
#define DEC_OP 323
#define AND_OP 324
#define OR_OP 325
#define IFX 326
#define ELSE 327
#define PIPELINE_OP 328
#define INC_OP_BACK 329
#define PRIORITY3 330
#define PRIORITY2 331
#define PRIORITY1 332
#define UMINUS 333




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
/* Line 1529 of yacc.c.  */
#line 214 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

