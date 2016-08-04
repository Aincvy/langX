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
#define ADD_EQ 272
#define SUB_EQ 273
#define MUL_EQ 274
#define DIV_EQ 275
#define AUTO 276
#define IF 277
#define ELSE 278
#define WHILE 279
#define FOR 280
#define DELETE 281
#define IFX 282
#define UMINUS 283
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
