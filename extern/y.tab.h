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
#define ADD_EQ 275
#define SUB_EQ 276
#define MUL_EQ 277
#define DIV_EQ 278
#define AUTO 279
#define IF 280
#define ELSE 281
#define WHILE 282
#define FOR 283
#define DELETE 284
#define BREAK 285
#define RETURN 286
#define SWITCH 287
#define CASE 288
#define DEFAULT 289
#define CASE_LIST 290
#define CLAXX_BODY 291
#define NEW 292
#define CLAXX_MEMBER 293
#define CLAXX_FUNC_CALL 294
#define XNULL 295
#define NONASSOC 296
#define IFX 297
#define UMINUS 298
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
