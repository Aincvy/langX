#define NUMBER 257
#define VARIABLE 258
#define OP_CALC 259
#define AND_OP 260
#define OR_OP 261
#define LE_OP 262
#define GE_OP 263
#define EQ_OP 264
#define NE_OP 265
#define FUNC_OP 266
#define AUTO 267
#define IF 268
#define ELSE 269
#define WHILE 270
#define FOR 271
#define GE 272
#define LE 273
#define EQ 274
#define NE 275
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
 double iValue; /* integer value */
 bool bValue; /* bool value */
 char* sValue; /* string value */
 XNode* node;  /* var value */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
