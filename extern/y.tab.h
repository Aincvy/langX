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
#define AUTO 284
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
#define NONASSOC 301
#define IFX 302
#define UMINUS 303
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
