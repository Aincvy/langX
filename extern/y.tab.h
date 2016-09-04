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
#define AUTO 290
#define IF 291
#define ELSE 292
#define WHILE 293
#define FOR 294
#define DELETE 295
#define BREAK 296
#define RETURN 297
#define SWITCH 298
#define CASE 299
#define DEFAULT 300
#define CASE_LIST 301
#define CLAXX_BODY 302
#define NEW 303
#define CLAXX_MEMBER 304
#define CLAXX_FUNC_CALL 305
#define XNULL 306
#define NONASSOC 307
#define IFX 308
#define UMINUS 309
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
