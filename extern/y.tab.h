#define TDOUBLE 257
#define TBOOL 258
#define IDENTIFIER 259
#define TSTRING 260
#define OP_CALC 261
#define AND_OP 262
#define OR_OP 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define FUNC_OP 268
#define INC_OP 269
#define DEC_OP 270
#define FUNC_CALL 271
#define VAR_DECLAR 272
#define RESTRICT 273
#define THIS 274
#define EXTENDS 275
#define ADD_EQ 276
#define SUB_EQ 277
#define MUL_EQ 278
#define DIV_EQ 279
#define AUTO 280
#define IF 281
#define ELSE 282
#define WHILE 283
#define FOR 284
#define DELETE 285
#define BREAK 286
#define RETURN 287
#define SWITCH 288
#define CASE 289
#define DEFAULT 290
#define CASE_LIST 291
#define CLAXX_BODY 292
#define NEW 293
#define CLAXX_MEMBER 294
#define CLAXX_FUNC_CALL 295
#define XNULL 296
#define NONASSOC 297
#define IFX 298
#define UMINUS 299
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
 double iValue; /* double value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
 XParamsList* params; /* params value */
 XArgsList *args;    /* args value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
