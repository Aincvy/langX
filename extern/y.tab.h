#define XINTEGER 257
#define TDOUBLE 258
#define TBOOL 259
#define IDENTIFIER 260
#define TSTRING 261
#define OP_CALC 262
#define AND_OP 263
#define OR_OP 264
#define LE_OP 265
#define GE_OP 266
#define EQ_OP 267
#define NE_OP 268
#define FUNC_OP 269
#define INC_OP 270
#define DEC_OP 271
#define FUNC_CALL 272
#define VAR_DECLAR 273
#define RESTRICT 274
#define THIS 275
#define EXTENDS 276
#define ARRAY_ELE 277
#define XTRY 278
#define XCATCH 279
#define ADD_EQ 280
#define SUB_EQ 281
#define MUL_EQ 282
#define DIV_EQ 283
#define LEFT_SHIFT 284
#define RIGHT_SHIFT 285
#define MOD_EQ 286
#define XPUBLIC 287
#define XSET 288
#define XIS 289
#define SCOPE 290
#define SCOPE_FUNC_CALL 291
#define REQUIRE 292
#define REQUIRE_ONCE 293
#define AUTO 294
#define IF 295
#define ELSE 296
#define WHILE 297
#define FOR 298
#define DELETE 299
#define BREAK 300
#define RETURN 301
#define SWITCH 302
#define CASE 303
#define DEFAULT 304
#define CASE_LIST 305
#define CLAXX_BODY 306
#define NEW 307
#define CLAXX_MEMBER 308
#define CLAXX_FUNC_CALL 309
#define XNULL 310
#define NONASSOC 311
#define IFX 312
#define PRIORITY3 313
#define PRIORITY2 314
#define PRIORITY1 315
#define UMINUS 316
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
