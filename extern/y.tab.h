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
#define ADD_EQ 278
#define SUB_EQ 279
#define MUL_EQ 280
#define DIV_EQ 281
#define AUTO 282
#define IF 283
#define ELSE 284
#define WHILE 285
#define FOR 286
#define DELETE 287
#define BREAK 288
#define RETURN 289
#define SWITCH 290
#define CASE 291
#define DEFAULT 292
#define CASE_LIST 293
#define CLAXX_BODY 294
#define NEW 295
#define CLAXX_MEMBER 296
#define CLAXX_FUNC_CALL 297
#define XNULL 298
#define NONASSOC 299
#define IFX 300
#define UMINUS 301
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
