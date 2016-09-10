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
#define AUTO 292
#define IF 293
#define ELSE 294
#define WHILE 295
#define FOR 296
#define DELETE 297
#define BREAK 298
#define RETURN 299
#define SWITCH 300
#define CASE 301
#define DEFAULT 302
#define CASE_LIST 303
#define CLAXX_BODY 304
#define NEW 305
#define CLAXX_MEMBER 306
#define CLAXX_FUNC_CALL 307
#define XNULL 308
#define NONASSOC 309
#define IFX 310
#define priority3 311
#define priority2 312
#define priority1 313
#define UMINUS 314
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
