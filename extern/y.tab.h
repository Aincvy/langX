#define TDOUBLE 257
#define VARIABLE 258
#define TSTRING 259
#define TBOOL 260
#define OP_CALC 261
#define AND_OP 262
#define OR_OP 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define FUNC_OP 268
#define AUTO 269
#define IF 270
#define ELSE 271
#define WHILE 272
#define FOR 273
#define IFX 274
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
 double iValue; /* double value */
 bool bValue; /* bool value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
