#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "a.y"

#include <stdio.h>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

extern int yyget_lineno(void);
extern int column; 
extern char * yytext;

#line 18 "a.y"
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
#line 50 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define BREAK 282
#define RETURN 283
#define SWITCH 284
#define CASE 285
#define DEFAULT 286
#define CASE_LIST 287
#define IFX 288
#define UMINUS 289
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   37,   37,    1,    1,    1,    1,    2,    2,    5,
   33,   33,   34,   34,   34,    7,    7,    6,    6,    3,
    3,    8,    8,    8,   31,   31,   32,   32,    9,    9,
   12,   12,   12,   12,    4,    4,    4,    4,   24,   24,
   24,   16,   35,   35,   36,   36,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   30,   30,   30,   30,   25,   26,   27,   28,
   29,   23,   23,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   15,   15,   15,   15,   21,   21,   21,   21,
   21,   21,   21,   21,   20,   20,   20,   20,   20,   22,
   22,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    1,    6,
    0,    3,    1,    3,    0,    2,    0,    2,    3,    1,
    1,    5,    7,    7,    1,    2,    4,    3,    5,    9,
    0,    1,    1,    1,    1,    1,    3,    1,    1,    1,
    2,    4,    0,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    3,    3,
    3,    3,    1,    1,    1,    3,    1,    1,    1,    2,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    3,    1,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,   39,    0,    0,
    4,    2,    5,    6,    0,    8,    9,   20,   21,   35,
   36,  102,   38,    0,    0,    0,    0,    0,    0,    0,
   69,   68,    0,   71,    0,    0,    0,    0,    0,    0,
    0,   63,   41,    0,   89,    0,    0,    0,    0,    0,
    7,    0,    0,    0,    0,    0,    0,   18,    0,    0,
    0,   99,    0,   45,    0,   47,    0,    0,    0,    0,
    0,    0,    0,   97,    0,    0,    0,   95,   96,   64,
    0,   67,   33,    0,   32,   34,    0,   37,   83,   84,
    0,   70,   57,   56,    0,   85,   86,    0,    0,    0,
    0,    0,  103,  104,  105,  106,   19,    0,  100,  101,
    0,   13,    0,   17,   42,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   66,   65,
    0,    0,   61,   62,    0,    0,   12,    0,   46,   81,
   82,   17,   55,    0,   77,   78,   79,   80,   75,   76,
   29,    0,   58,    0,   14,   10,   16,    0,    0,    0,
    0,    0,    0,   25,   54,   23,    0,    0,   17,   24,
   26,    0,   17,    0,   30,    0,
};
static const short yydgoto[] = {                          1,
  143,   13,   14,   15,   16,   17,  138,   18,   19,   72,
  144,   84,   20,   73,   62,   74,   64,   92,   93,   75,
   43,   22,   76,   23,   77,   45,   78,   79,   80,   49,
  163,  164,   60,  113,   70,   71,    2,
};
static const short yysindex[] = {                         0,
    0,  103,  -28,  -24,  -18,  -14, -229,    0,  -16,   25,
    0,    0,    0,    0,  -17,    0,    0,    0,    0,    0,
    0,    0,    0,  -40,   42,  -16,  -12,  -12, -219,   35,
    0,    0,   63,    0, -152, -152,  -37,  -12,    0,    0,
    0,    0,    0, -214,    0,    0,    0,    0,  108, -152,
    0,   -8,   -8,   -8,   -8, -152,  -16,    0, -149,   12,
    0,    0,    0,    0, -214,    0,    0,    0,    0,   83,
   74,   -7,    0,    0,    0,   39, -214,    0,    0,    0,
   11,    0,    0,   75,    0,    0,  -44,    0,    0,    0,
   -8,    0,    0,    0,   99,    0,    0,  -12,  -12,  -12,
  -12,  101,    0,    0,    0,    0,    0,   -6,    0,    0,
  -56,    0,   -5,    0,    0,  -16,  -12,  -12,   64,  -12,
  -12,  -12,  -12,  -12,  -12,   64,  -12,  107,    0,    0,
   30,   30,    0,    0,   21, -105,    0,   77,    0,    0,
    0,    0,    0, -117,    0,    0,    0,    0,    0,    0,
    0,  -53,    0, -154,    0,    0,    0,   90,   64, -219,
  -93,  119, -116,    0,    0,    0,  124,  126,    0,    0,
    0,   64,    0,  103,    0,  103,
};
static const short yyrindex[] = {                         0,
    0,  166,  -36,    0,    0,    0,    0,    0,  123,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   66,  150,    0,    0,  138,    0,
    0,    0,    2,    0,    0,    0,    0,    0,  158,  365,
  396,    0,    0,  133,    0,  406,  415,  455,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   40,    0,
  446,    0,  488,    0,  508,    0,  515,  525,  532,    0,
  157,    0,   33,    0,   55,  -39,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  143,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  475,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   46,   68,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  163,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -114,    0, -112,
};
static const short yygindex[] = {                         0,
    5,    0,    0,    0,    0,  -15, -115,    0,    0,   29,
  -43,   47,  -19,   95,  110,  389,   92,    0,    0,  379,
  149,  155,  204,    0,  366,    6,   22,    9,  111,   59,
    0,   53,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 579
static const short yytable[] = {                         56,
   22,   74,   91,   56,   57,  160,   12,   67,  170,   85,
   28,   26,   27,   83,   58,   27,   57,   47,   58,   74,
   57,   28,   67,   38,   67,   29,  158,   38,   37,   30,
   46,   66,   37,  119,   68,  137,   37,   56,  136,   82,
  107,   51,   67,   67,   67,   67,   67,   67,   67,   35,
   36,  126,   58,  174,   96,   97,   81,  176,   94,   22,
   67,   67,   67,   67,   50,   47,   98,   98,   98,   98,
   98,  100,   98,   73,   65,   65,  101,   65,   46,   65,
   15,   59,  151,   15,   98,   98,   59,   98,   59,   59,
   59,   73,   73,   88,   73,   72,   63,   63,  125,   63,
  124,   63,   26,   39,   59,   59,   82,   59,   60,  112,
   60,   60,   60,   72,   72,  166,   72,  116,   40,   48,
   61,   66,   11,  115,   68,   22,   60,   60,  175,   60,
  161,  162,   95,  127,  114,   11,   69,   67,   86,  129,
   85,  135,  157,  154,   83,  140,  141,  153,   11,  100,
   98,   39,   99,  155,  101,  152,  131,  132,  133,  134,
  159,   11,  157,   31,  172,    1,   40,   48,  161,  162,
   28,   28,   27,   27,   98,   98,  169,   98,  157,   98,
  157,   40,  168,  173,   65,   65,  142,   65,   11,   65,
   43,   92,  130,  130,  130,  130,   31,   44,   90,   65,
   65,  156,   65,   31,   65,  109,  167,  139,  117,  118,
   61,  110,   96,   97,  165,  171,   90,    0,    0,   31,
    0,    0,   74,   74,   96,   97,   69,   52,   53,   54,
   55,   52,   53,   54,   55,   67,   67,   67,   67,   25,
   31,   32,   33,   34,   31,    0,   33,   34,   31,    0,
   33,    0,   35,   36,  117,  118,   35,   36,    0,   22,
   35,   36,    0,   67,   67,   67,   67,   67,   67,   86,
   67,   67,  117,  118,    0,    0,    0,   22,    0,   22,
   22,   22,   22,   22,   22,   22,   22,   98,   98,   98,
   98,   98,   98,    0,   73,   73,   73,   73,   73,   73,
    0,    0,  120,  121,  122,  123,    0,   59,   59,   59,
   59,   59,   59,    0,    0,    0,   72,   72,   72,   72,
   72,   72,    3,  145,  146,  147,  148,  149,  150,   60,
   60,   60,   60,   60,   60,    3,    0,    0,    0,    0,
    4,    0,    5,    6,    7,    8,    9,   10,    3,    0,
    0,    0,    0,    4,    0,    5,    6,    7,    8,    9,
   10,    3,    0,    0,    0,    0,    4,   24,    5,    6,
    7,    8,    9,   10,   44,    0,    0,    0,    0,    4,
    0,    5,    6,    7,    8,    9,   10,   42,    0,    0,
   21,   65,    0,    0,   87,    0,    0,   41,    0,    0,
   89,   90,    0,    0,   42,   94,   99,   99,    0,   99,
    0,   99,    0,    0,   63,  102,   42,    0,    0,    0,
    0,  108,  111,   94,    0,    0,    0,    0,    0,    0,
  103,  104,  105,  106,    0,   42,   91,   97,   97,    0,
   97,    0,   97,    0,    0,   41,   87,   95,   95,    0,
   95,    0,   95,    0,   91,   88,   96,   96,    0,   96,
    0,   96,    0,    0,   87,    0,    0,    0,    0,  128,
    0,    0,    0,   88,    0,    0,   42,   42,   42,   42,
    0,   65,    0,    0,   24,    0,   53,   65,   65,   53,
   65,   24,   65,    0,   42,   93,   64,   64,    0,   64,
    0,   64,    0,   24,   63,    0,    0,   21,    0,    0,
    0,    0,    0,   93,   21,   92,   98,   98,    0,   98,
    0,   98,    0,   24,   24,   87,   21,    0,   52,   97,
   97,   52,   97,   92,   97,    0,    0,   24,    0,   24,
    0,   24,    0,    0,    0,    0,   21,   21,   49,   98,
   98,   49,   98,    0,   98,   48,   95,   95,   48,   95,
   21,   95,   21,    0,   21,   51,   96,   96,   51,   96,
    0,   96,   50,   64,   64,   50,   64,    0,   64,
};
static const short yycheck[] = {                         44,
    0,   41,   40,   44,   61,   59,    2,   44,  125,   29,
  125,   40,  125,   29,   59,   40,   61,    9,   59,   59,
   61,   40,   59,   40,   61,   40,  142,   40,   45,  259,
    9,   26,   45,   41,   26,   41,   45,   44,   44,  259,
   56,   59,   41,   42,   43,   44,   45,   26,   47,  269,
  270,   41,   59,  169,  269,  270,   28,  173,   37,   59,
   59,   60,   61,   62,   40,   57,   41,   42,   43,   44,
   45,   42,   47,   41,   42,   43,   47,   45,   57,   47,
   41,   40,  126,   44,   59,   60,   41,   62,   43,   44,
   45,   59,   60,   59,   62,   41,   42,   43,   60,   45,
   62,   47,   40,    9,   59,   60,  259,   62,   41,  259,
   43,   44,   45,   59,   60,  159,   62,   44,    9,    9,
   26,  116,   59,   41,  116,  125,   59,   60,  172,   62,
  285,  286,   38,   59,  123,   59,   26,  116,   29,   41,
  160,   41,  138,  123,  160,  117,  118,   41,   59,   42,
   43,   57,   45,  259,   47,  127,   98,   99,  100,  101,
  278,   59,  158,  257,   41,    0,   57,   57,  285,  286,
  285,  286,  285,  286,   42,   43,   58,   45,  174,   47,
  176,   59,  161,   58,   42,   43,  123,   45,  123,   47,
   41,   59,   98,   99,  100,  101,   59,   41,   41,   42,
   43,  125,   45,   41,   47,   57,  160,  116,  262,  263,
  116,   57,  269,  270,  125,  163,   59,   -1,   -1,  257,
   -1,   -1,  262,  263,  269,  270,  116,  272,  273,  274,
  275,  272,  273,  274,  275,  272,  273,  274,  275,  268,
  257,  258,  259,  260,  257,   -1,  259,  260,  257,   -1,
  259,   -1,  269,  270,  262,  263,  269,  270,   -1,  259,
  269,  270,   -1,  262,  263,  264,  265,  266,  267,  160,
  269,  270,  262,  263,   -1,   -1,   -1,  277,   -1,  279,
  280,  281,  282,  283,  284,  285,  286,  262,  263,  264,
  265,  266,  267,   -1,  262,  263,  264,  265,  266,  267,
   -1,   -1,  264,  265,  266,  267,   -1,  262,  263,  264,
  265,  266,  267,   -1,   -1,   -1,  262,  263,  264,  265,
  266,  267,  259,  120,  121,  122,  123,  124,  125,  262,
  263,  264,  265,  266,  267,  259,   -1,   -1,   -1,   -1,
  277,   -1,  279,  280,  281,  282,  283,  284,  259,   -1,
   -1,   -1,   -1,  277,   -1,  279,  280,  281,  282,  283,
  284,  259,   -1,   -1,   -1,   -1,  277,    2,  279,  280,
  281,  282,  283,  284,    9,   -1,   -1,   -1,   -1,  277,
   -1,  279,  280,  281,  282,  283,  284,    9,   -1,   -1,
    2,   26,   -1,   -1,   29,   -1,   -1,    9,   -1,   -1,
   35,   36,   -1,   -1,   26,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   26,   50,   38,   -1,   -1,   -1,
   -1,   56,   57,   59,   -1,   -1,   -1,   -1,   -1,   -1,
   52,   53,   54,   55,   -1,   57,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   57,   41,   42,   43,   -1,
   45,   -1,   47,   -1,   59,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   59,   -1,   -1,   -1,   -1,   91,
   -1,   -1,   -1,   59,   -1,   -1,   98,   99,  100,  101,
   -1,  116,   -1,   -1,  119,   -1,   41,   42,   43,   44,
   45,  126,   47,   -1,  116,   41,   42,   43,   -1,   45,
   -1,   47,   -1,  138,  116,   -1,   -1,  119,   -1,   -1,
   -1,   -1,   -1,   59,  126,   41,   42,   43,   -1,   45,
   -1,   47,   -1,  158,  159,  160,  138,   -1,   41,   42,
   43,   44,   45,   59,   47,   -1,   -1,  172,   -1,  174,
   -1,  176,   -1,   -1,   -1,   -1,  158,  159,   41,   42,
   43,   44,   45,   -1,   47,   41,   42,   43,   44,   45,
  172,   47,  174,   -1,  176,   41,   42,   43,   44,   45,
   -1,   47,   41,   42,   43,   44,   45,   -1,   47,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 289
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,
"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TDOUBLE","TBOOL","IDENTIFIER","TSTRING","OP_CALC",
"AND_OP","OR_OP","LE_OP","GE_OP","EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP",
"FUNC_CALL","ADD_EQ","SUB_EQ","MUL_EQ","DIV_EQ","AUTO","IF","ELSE","WHILE",
"FOR","DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT","CASE_LIST","IFX",
"UMINUS",
};
static const char *yyrule[] = {
"$accept : program",
"program : statement_list",
"statement_list : statement_list statement",
"statement_list :",
"statement : ';'",
"statement : declar_stmt",
"statement : con_ctl_stmt",
"statement : simple_stmt ';'",
"declar_stmt : func_declar_stmt",
"declar_stmt : var_declar_stmt",
"func_declar_stmt : IDENTIFIER FUNC_OP param_list '{' expr_list '}'",
"param_list :",
"param_list : '(' parameter ')'",
"parameter : IDENTIFIER",
"parameter : parameter ',' IDENTIFIER",
"parameter :",
"expr_list : expr_list statement",
"expr_list :",
"var_declar_stmt : id_expr ';'",
"var_declar_stmt : id_expr ',' var_declar_stmt",
"con_ctl_stmt : selection_stmt",
"con_ctl_stmt : loop_stmt",
"selection_stmt : IF '(' logic_stmt ')' block",
"selection_stmt : IF '(' logic_stmt ')' block ELSE block",
"selection_stmt : SWITCH '(' id_expr ')' '{' case_stmt_list '}'",
"case_stmt_list : case_stmt",
"case_stmt_list : case_stmt_list case_stmt",
"case_stmt : CASE double_expr ':' expr_list",
"case_stmt : DEFAULT ':' expr_list",
"loop_stmt : WHILE '(' logic_stmt ')' block",
"loop_stmt : FOR '(' for_1_stmt ';' logic_stmt ';' for_1_stmt ')' block",
"for_1_stmt :",
"for_1_stmt : assign_stmt",
"for_1_stmt : var_declar_stmt",
"for_1_stmt : self_inc_dec_stmt",
"simple_stmt : assign_stmt",
"simple_stmt : call_statement",
"simple_stmt : DELETE IDENTIFIER ';'",
"simple_stmt : interrupt_stmt",
"interrupt_stmt : BREAK",
"interrupt_stmt : RETURN",
"interrupt_stmt : RETURN assign_stmt_value",
"call_statement : IDENTIFIER '(' args_list ')'",
"args_list :",
"args_list : args_expr",
"args_expr : args_expr_collection",
"args_expr : args_expr ',' args_expr_collection",
"args_expr_collection : t_bool_expr",
"args_expr_collection : double_expr",
"args_expr_collection : id_expr",
"args_expr_collection : string_expr",
"args_expr_collection : uminus_expr",
"args_expr_collection : call_statement",
"args_expr_collection : arithmetic_stmt",
"block : '{' expr_list '}'",
"block : statement",
"double_or_ps_expr : double_expr",
"double_or_ps_expr : parentheses_stmt",
"parentheses_stmt : '(' assign_stmt_value_eq ')'",
"arithmetic_stmt : arithmetic_stmt_factor '+' arithmetic_stmt_factor",
"arithmetic_stmt : arithmetic_stmt_factor '-' arithmetic_stmt_factor",
"arithmetic_stmt : arithmetic_stmt_factor '*' arithmetic_stmt_factor",
"arithmetic_stmt : arithmetic_stmt_factor '/' arithmetic_stmt_factor",
"arithmetic_stmt_factor : assign_stmt_value_eq",
"arithmetic_stmt_factor : string_expr",
"arithmetic_stmt_factor : arithmetic_stmt",
"arithmetic_stmt_factor : '(' arithmetic_stmt ')'",
"id_expr : IDENTIFIER",
"t_bool_expr : TBOOL",
"double_expr : TDOUBLE",
"uminus_expr : '-' double_or_ps_expr",
"string_expr : TSTRING",
"bool_param_expr : assign_stmt_value_eq",
"bool_param_expr : arithmetic_stmt",
"logic_stmt : bool_param_expr",
"logic_stmt : bool_param_expr '>' bool_param_expr",
"logic_stmt : bool_param_expr '<' bool_param_expr",
"logic_stmt : bool_param_expr LE_OP bool_param_expr",
"logic_stmt : bool_param_expr GE_OP bool_param_expr",
"logic_stmt : bool_param_expr EQ_OP bool_param_expr",
"logic_stmt : bool_param_expr NE_OP bool_param_expr",
"logic_stmt : logic_stmt AND_OP logic_stmt",
"logic_stmt : logic_stmt OR_OP logic_stmt",
"self_inc_dec_stmt : INC_OP id_expr",
"self_inc_dec_stmt : DEC_OP id_expr",
"self_inc_dec_stmt : id_expr INC_OP",
"self_inc_dec_stmt : id_expr DEC_OP",
"assign_stmt_value : double_expr",
"assign_stmt_value : uminus_expr",
"assign_stmt_value : t_bool_expr",
"assign_stmt_value : arithmetic_stmt",
"assign_stmt_value : call_statement",
"assign_stmt_value : id_expr",
"assign_stmt_value : string_expr",
"assign_stmt_value : self_inc_dec_stmt",
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
"single_assign_stmt : id_expr '=' single_assign_stmt",
"assign_stmt : single_assign_stmt",
"assign_stmt : id_expr ADD_EQ assign_stmt_value_eq",
"assign_stmt : id_expr SUB_EQ assign_stmt_value_eq",
"assign_stmt : id_expr MUL_EQ assign_stmt_value_eq",
"assign_stmt : id_expr DIV_EQ assign_stmt_value_eq",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 300 "a.y"


void yyerror(char *s) {
 fprintf(stderr, "%s on line %d,column %d. near by '%s' \n", s ,yyget_lineno(),column , yytext  );
}

int main(int argc, char *argv[]){
	if(argc <= 1){
		printf("no input file.\n");
		return 1;
	}
	
	FILE *fp = fopen(argv[1],"r");
	if(fp == NULL){
		printf("file %s not found.\n" , argv[1]);
		return 1;
	}
	
	extern FILE* yyin; 
	yyin=fp;
	initLangX();
    yyparse();
	closeLangX();
	fclose(fp);
	
	printf("parse over!\n");
	return 0;
}
#line 531 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 58 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 62 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 63 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 64 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 65 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 70 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 71 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 10:
#line 76 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 11:
#line 80 "a.y"
	{ yyval.params = NULL; }
break;
case 12:
#line 81 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 13:
#line 85 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 14:
#line 86 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 15:
#line 87 "a.y"
	{ yyval.params = NULL; }
break;
case 16:
#line 91 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 17:
#line 92 "a.y"
	{ yyval.node = NULL; }
break;
case 18:
#line 97 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 19:
#line 98 "a.y"
	{ yyval.node = opr(',' , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 20:
#line 103 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 21:
#line 104 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 22:
#line 109 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 23:
#line 110 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 24:
#line 111 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 25:
#line 115 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 26:
#line 116 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 27:
#line 120 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 28:
#line 121 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 29:
#line 125 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 30:
#line 126 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 31:
#line 131 "a.y"
	{ yyval.node = NULL ; }
break;
case 32:
#line 132 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 33:
#line 133 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 34:
#line 134 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 35:
#line 139 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 36:
#line 140 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 37:
#line 141 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 38:
#line 142 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 39:
#line 146 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 40:
#line 147 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 41:
#line 148 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 42:
#line 153 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 43:
#line 157 "a.y"
	{ yyval.args = NULL; }
break;
case 44:
#line 158 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 45:
#line 162 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 46:
#line 163 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 47:
#line 167 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 48:
#line 168 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 49:
#line 169 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 50:
#line 170 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 51:
#line 171 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 52:
#line 172 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 53:
#line 173 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 54:
#line 177 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 55:
#line 178 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 184 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 57:
#line 185 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 58:
#line 190 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 59:
#line 196 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 60:
#line 197 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 61:
#line 198 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 62:
#line 199 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 63:
#line 204 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 64:
#line 205 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 65:
#line 206 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 66:
#line 207 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 67:
#line 211 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 68:
#line 215 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 69:
#line 219 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 70:
#line 223 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 71:
#line 227 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 72:
#line 232 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 233 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 238 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 239 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 76:
#line 240 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 77:
#line 241 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 78:
#line 242 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 79:
#line 243 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 80:
#line 244 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 81:
#line 245 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 82:
#line 246 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 83:
#line 251 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 84:
#line 252 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 85:
#line 253 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 86:
#line 254 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 87:
#line 259 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 260 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 261 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 262 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 263 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 264 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 265 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 94:
#line 266 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 95:
#line 271 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 96:
#line 272 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 97:
#line 273 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 98:
#line 274 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 99:
#line 275 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 100:
#line 280 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 101:
#line 281 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 102:
#line 293 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 103:
#line 294 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 104:
#line 295 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 105:
#line 296 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 106:
#line 297 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1153 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
