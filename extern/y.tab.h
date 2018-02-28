#define XINTEGER 257
#define TDOUBLE 258
#define TBOOL 259
#define IDENTIFIER 260
#define TSTRING 261
#define OPERATOR_X__ 262
#define OP_CALC 263
#define AND_OP 264
#define OR_OP 265
#define LE_OP 266
#define GE_OP 267
#define EQ_OP 268
#define NE_OP 269
#define FUNC_OP 270
#define INC_OP 271
#define DEC_OP 272
#define FUNC_CALL 273
#define VAR_DECLAR 274
#define RESTRICT 275
#define THIS 276
#define EXTENDS 277
#define ARRAY_ELE 278
#define XTRY 279
#define XCATCH 280
#define ADD_EQ 281
#define SUB_EQ 282
#define MUL_EQ 283
#define DIV_EQ 284
#define LEFT_SHIFT 285
#define RIGHT_SHIFT 286
#define MOD_EQ 287
#define XPUBLIC 288
#define XSET 289
#define XIS 290
#define SCOPE 291
#define SCOPE_FUNC_CALL 292
#define REQUIRE 293
#define REQUIRE_ONCE 294
#define REF 295
#define XCONTINUE 296
#define XCONST 297
#define XLOCAL 298
#define AUTO 299
#define IF 300
#define ELSE 301
#define WHILE 302
#define FOR 303
#define DELETE 304
#define BREAK 305
#define RETURN 306
#define SWITCH 307
#define CASE 308
#define DEFAULT 309
#define CASE_LIST 310
#define CLAXX_BODY 311
#define NEW 312
#define CLAXX_MEMBER 313
#define CLAXX_FUNC_CALL 314
#define XNULL 315
#define XINCLUDE 316
#define ANNOTATION 317
#define NONASSOC 318
#define IFX 319
#define PRIORITY3 320
#define PRIORITY2 321
#define PRIORITY1 322
#define UMINUS 323
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
 int intValue;
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
