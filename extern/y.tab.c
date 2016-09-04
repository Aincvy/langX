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
#include <string>
#include "../include/YLlangX.h"

#define YYDEBUG 1

extern "C" {
	extern int yylex(void);
	void yyerror(char *);
}

extern int yyget_lineno(void);
extern int column; 
extern char * yytext;

/* 正在解析的文件 的文件名*/
const char * parseFileName=NULL;

#line 22 "a.y"
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
#line 55 "y.tab.c"

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
#define AUTO 289
#define IF 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define DELETE 294
#define BREAK 295
#define RETURN 296
#define SWITCH 297
#define CASE 298
#define DEFAULT 299
#define CASE_LIST 300
#define CLAXX_BODY 301
#define NEW 302
#define CLAXX_MEMBER 303
#define CLAXX_FUNC_CALL 304
#define XNULL 305
#define NONASSOC 306
#define IFX 307
#define UMINUS 308
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   57,   57,    1,    1,    1,    1,    1,   26,   26,
   27,    2,    2,    2,    2,   39,   56,   56,   36,   36,
   55,   55,   37,   37,   38,   38,   38,   46,   46,   46,
   47,   47,   40,   40,   40,   40,   42,   42,   42,   42,
   43,   43,   43,    5,   51,   51,   52,   52,   52,    7,
    7,    6,    6,    6,    6,    6,    6,    3,    3,    8,
    8,    8,   34,   34,   35,   35,    9,    9,   12,   12,
   12,   12,    4,    4,    4,    4,    4,    4,    4,   45,
   45,   24,   24,   24,   16,   16,   53,   53,   54,   54,
   17,   17,   17,   17,   17,   17,   17,   11,   11,   18,
   18,   19,   14,   14,   14,   14,   14,   14,   14,   14,
   14,   14,   14,   50,   50,   33,   33,   33,   33,   33,
   33,   25,   28,   29,   30,   30,   31,   32,   44,   23,
   23,   23,   23,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   15,   15,   15,   15,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   20,
   20,   20,   20,   20,   22,   22,   41,   41,   48,   48,
   49,   13,   13,   13,   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    4,    5,
    7,    1,    1,    1,    2,    4,    1,    3,    4,    5,
    0,    2,    1,    2,    1,    2,    1,    1,    3,    6,
    3,    3,    3,    3,    6,    3,    6,    9,    6,    6,
    8,   10,    5,    6,    0,    3,    1,    3,    0,    2,
    0,    2,    3,    5,    6,    5,    6,    1,    1,    5,
    7,    7,    1,    2,    4,    3,    5,    9,    0,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    1,    1,
    2,    1,    1,    2,    4,    1,    0,    1,    1,    3,
    1,    1,    1,    1,    1,    1,    1,    3,    1,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    3,    3,    1,    1,    1,    1,    1,    1,    1,
    3,    5,    1,    1,    1,    1,    2,    1,    1,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    2,    2,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    3,    3,    3,    3,    4,    4,
    3,    1,    1,    1,    3,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   82,    0,    0,    0,    4,    2,    5,    6,    0,
   12,   13,   58,   59,   73,   74,  172,   76,   77,    8,
    0,   14,    0,    0,  173,    0,    0,   79,    0,    0,
  174,    0,    0,    0,    0,    0,  124,   81,    0,   51,
    0,    0,    0,    0,    0,    0,  125,    0,  128,    0,
    0,    0,  129,    0,    0,    0,    0,    0,    0,  116,
   84,  155,    0,  149,    0,    0,    0,    0,    0,  157,
  158,    0,    0,    0,  123,    0,    7,    0,    0,    0,
    0,    0,    0,    0,   52,    0,   15,    0,    0,    0,
    0,    0,    0,    0,    0,   22,    0,  164,    0,   89,
    0,   91,    0,    0,    0,    0,  120,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  162,    0,    0,    0,  132,  160,  161,    0,    0,    0,
   71,    0,   70,   72,    0,   75,    0,    0,  143,  144,
    0,  126,    0,  127,  101,  100,  114,  115,  111,    0,
  117,  145,  146,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  175,    0,    0,
  176,  177,  178,  179,    0,   53,    0,  165,  166,    0,
    0,  167,    0,    0,    0,  168,  171,   47,    0,   51,
    0,    0,    0,    0,    0,   19,   27,   25,    0,    0,
    0,   23,    0,    0,   50,   17,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  121,    0,  118,    0,    0,    0,  105,
  106,  112,  113,  108,  109,  110,    0,    0,    0,    0,
    0,    0,    0,    0,   46,    0,    0,    0,   90,    0,
   54,    0,   56,   26,   20,   24,    0,    0,   10,    0,
  141,  142,   51,   99,    0,  137,  138,  139,  140,  135,
  136,   67,    0,    0,  169,  170,    0,  102,    0,    0,
  122,    0,    0,    0,    0,    0,   43,   48,   44,    0,
    0,   55,   57,    0,    0,   18,    0,    0,    0,    0,
    0,    0,    0,    0,   63,    0,    0,    0,   39,   40,
    0,    0,    0,   98,   61,    0,   30,   37,    0,   51,
   62,   64,    0,   41,    0,    0,    0,   51,    0,    0,
   38,   51,   68,    0,    0,    0,   42,   11,
};
static const short yydgoto[] = {                          1,
  215,   18,   19,   20,   21,   22,  127,   23,   24,  129,
  275,  142,   25,  107,  108,  131,  110,  154,  155,   70,
   71,   27,  133,   28,   29,   30,  269,  134,  112,  136,
  137,  115,   78,  314,  315,   32,  211,  212,   33,  116,
   35,   36,   37,   80,   38,   81,   39,  117,   41,   83,
  105,  199,  118,  119,   46,  217,    2,
};
static const short yysindex[] = {                         0,
    0,  573,  -25, -230,   31,  -30, -182,   75,   97,   98,
 -117,    0,  176,  127,  -84,    0,    0,    0,    0,  118,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  209,    0,  144,  -10,    0,  153,  -56,    0,  149,  151,
    0,  165,  -46,  626, -220,  101,    0,    0,  -40,    0,
  169,  626,  626, -110,  204,    0,    0,  -13,    0,  -84,
  -84,  221,    0,  -35, -176,  900,    0,    0,    0,    0,
    0,    0,   -5,    0,    0,    0,    0,  792,  228,    0,
    0,    0,   33,  -84,    0,  235,    0,   76,   76,   76,
   76,   76,   29,  176,    0,  -84,    0,  176,  -84,  -84,
  241,  176,  176,   35,  163,    0,    0,    0,    0,    0,
   -5,    0,    0,    0,    0,  228,    0,  252,  253,  206,
  211, -107,  268,  263,  228,  153,  349,   51,   16,    0,
    0,    0,  125,   -5,    0,    0,    0,    0,   27,  -12,
    0,  254,    0,    0,  608,    0,  626, -141,    0,    0,
  -84,    0,   76,    0,    0,    0,    0,    0,    0,  271,
    0,    0,    0,  -84,  900,  900,  900,  900,  900, -176,
 -176, -176, -176, -176,  274,  626,  276,    0,   -5,  228,
    0,    0,    0,    0,  239,    0,   21,    0,    0,  -42,
  286,    0,  301,  305,  626,    0,    0,    0,  140,    0,
  -43,  626,   26,  119,  -75,    0,    0,    0,  289,   85,
 -105,    0,  626,   70,    0,    0,  306,  626,  626,  390,
  626,  626,  626,  626,  626,  626,  390,  626,  309,  260,
  262,  316,  317,    0,  322,    0,   94,   94,   94,    0,
    0,    0,    0,    0,    0,    0,  240,  324,  -71,  626,
  626,  626,  327,  113,    0,  421,  334,  -84,    0,   29,
    0,   29,    0,    0,    0,    0,  339,  346,    0,  136,
    0,    0,    0,    0,   96,    0,    0,    0,    0,    0,
    0,    0,  -28,  348,    0,    0,  626,    0,  626, -238,
    0,  314,  323,  369,  376,  382,    0,    0,    0,  626,
  389,    0,    0,  348,  -84,    0,  476,  390, -110,  391,
  397, -185,  372, -116,    0,   26,  119,  171,    0,    0,
  398,  626,  399,    0,    0,  401,    0,    0,  386,    0,
    0,    0,  405,    0,  411,  330,  390,    0,  573,  626,
    0,    0,    0,  573,  413,  548,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  456,  574,  414,    0,    0,    0,    0,    0,    0,
    0,    0,  420,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  939,  423,    0,    0,    0,
    0,  335,    0,  431,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  425,    0,  535,    0,  461,    0,    0,
    0,   -9,    0,    0,    0,    0,  418,  661,  738,    0,
    0,    0,  506,    0, 1071, 1097, 1122,    0, 1131,    0,
    0, 1142,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  202,    0,    0, 1171,    0, 1208,    0,
  377,    0, 1292, 1307, 1346,  963,    0,    0,  444,    0,
    0,    0,   -7,  427,  432,    0,    0,    0,    0,  996,
    0, 1003,    8,  546,    0,    0,    0, 1027,    0,  630,
    0,    0,    0,    0,    0,    0,  431,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  872,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  431,  -29,    0,   -3,    0,
    0,    0,    0,    0,  131,    0,    0,    0,    0,  506,
  134,    0,  696,  861,  431,    0,    0,    0,    0,    0,
  437,    0,  439,  448,   95,    0,    0,    0,    0,    0,
    0,    0,  431,  107,    0,    0,  451,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    0,  887,    0, 1016, 1036, 1047,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  431,
  431,  431,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  264,    0,    0,    0,    0,    0,
    0,    0,    0,  972,    0,    0,  431,    0,  431,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  431,
  928,    0,    0,    0,    0,    0,    0,    0,  470,    0,
    0,    0,    0,    0,    0,    0,    0,  -11,    0,    0,
    0,  431,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -102,  431,
    0,    0,    0,  -61,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    6,    0,    0,    0,  -98,  -47, -190,    0,    0,  -27,
 -206,  177,  -52, 1264,    1,   32,  310,    0,    0, 1233,
  198,  -69,  304,    0,   30,    0,    0,   -2, 1244,  175,
  281, 1275,  445,    0,  200,    0,    0,  307,    0,   20,
    0,  -48,    0,    0,    0,    0,    0,  104,    0,  296,
    0,    0, 1184,    0,    0,    0,    0,
};
#define YYTABLESIZE 1524
static const short yytable[] = {                         31,
  126,  143,  258,  164,  153,  126,  141,   17,  331,  256,
   73,  123,   86,   68,   44,  249,  123,  206,   94,  265,
  282,   34,   66,  207,  189,  139,  147,  213,   47,  123,
  309,   28,   79,   26,   37,   99,  120,  163,  123,  121,
  164,  111,   72,   29,   69,  186,  124,   37,  134,   28,
   98,  145,  209,  123,  144,  163,  220,  149,  150,  312,
  313,   29,  158,   65,   93,   45,  134,  227,  125,  260,
  172,  152,   57,   34,  208,  109,   49,  148,   45,   95,
  157,  175,  307,   85,  261,  179,  179,  179,  179,  179,
  187,  190,   50,  191,   68,   73,  193,  194,   68,   73,
   73,  325,   68,   68,   51,   40,    9,  180,  180,  180,
  180,  180,  207,   79,   52,  230,   82,   79,  231,  210,
   64,   79,   79,   72,   31,   69,  174,   72,   93,   69,
  343,   72,   72,   69,   69,  168,   53,   54,  123,  339,
  169,  209,   55,   95,  111,   94,   34,  344,  232,  140,
  179,  346,  205,  123,  205,  123,  173,   40,   26,   60,
   61,  235,  262,  208,    5,    9,   84,  158,  158,  158,
  158,  158,  180,  111,  123,   85,   87,  263,  109,   33,
  255,  312,  313,  254,  226,  292,  225,   75,  293,  123,
  271,  272,  111,   42,   33,   66,   66,   82,  100,  111,
  283,   82,   97,  101,  104,   82,   82,  109,  210,  102,
  111,  103,  302,  106,  303,   66,  257,   31,  113,  123,
   64,  152,   57,  122,   31,  274,  109,  162,  163,  128,
   40,    9,  274,  109,  218,  219,   65,   65,  156,   34,
  123,  123,   49,   42,  109,   49,   34,  111,  111,  111,
   43,   26,   93,   31,   96,  301,  143,  187,   26,  187,
  126,  141,  146,   60,  162,  163,  151,   95,   75,   94,
  134,  134,   75,   99,  176,   34,   75,   75,  218,  219,
  195,  109,  109,  109,  111,  200,  111,   26,  185,  218,
  219,  188,  201,   76,  198,  192,  202,  111,  203,  196,
  197,   65,  323,  204,   31,   31,  145,  213,  164,  144,
  216,  234,  228,  274,  247,  147,  170,  171,  109,  111,
  109,  113,   60,   40,  114,  250,   34,   34,   34,  249,
   40,  109,  152,   57,   31,  177,   31,  111,   26,   26,
  251,   31,  274,   31,  252,   60,   61,  264,  268,  284,
  113,  270,  285,  109,  286,  287,   34,  288,   34,   40,
  159,  289,  290,   34,  291,   34,    9,  297,   26,  113,
   26,  109,  298,  300,   76,   26,  113,   26,   76,  304,
    9,    9,   76,   76,    9,  305,  308,  113,   60,  221,
  222,  223,  224,  258,    9,  306,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,  316,   16,    9,  318,
   40,   40,   40,  163,  115,  317,  319,   93,  163,  163,
   93,  163,  320,  163,  113,  113,  113,  114,  322,  330,
  333,  327,   56,   57,   47,   58,   59,  328,  334,  336,
   40,  337,   40,  338,  340,   60,   61,   40,   16,   40,
   62,  341,  342,  347,  118,    1,  114,   45,  150,  118,
  118,  113,  118,  113,  118,  242,  243,  244,  245,  246,
  115,   87,   80,  214,  113,  114,  150,   15,   83,   16,
   63,   78,  114,   69,   88,  326,  329,   31,   88,   89,
   90,   91,   32,  114,   92,   85,  113,  123,  123,  169,
  115,  123,  123,  123,  123,  123,  123,  123,  170,   16,
   69,  259,  273,  332,  113,    0,    0,  266,    0,  123,
  123,  123,  123,   60,  276,  277,  278,  279,  280,  281,
  114,  114,  114,    0,   16,    0,    0,   60,   60,    0,
    0,   60,  163,  115,    0,  299,  152,  163,  163,    0,
  163,   60,  163,   60,  123,   60,   60,   60,   60,   60,
   60,   60,   60,    0,  152,   60,    0,  114,    0,  114,
    0,  126,  114,    0,    0,  126,  126,  126,  126,  126,
  114,  126,  163,  115,  123,    0,  163,  163,  163,  163,
  163,    0,  163,  126,  126,    0,  126,    0,    0,  115,
  324,    0,  114,    0,  163,  163,   16,  163,    3,  237,
  238,  239,  240,  241,    0,    0,    0,  123,    0,  123,
  114,    0,    4,    5,    0,    0,    6,    0,  114,  115,
    0,   16,  123,    0,  123,    0,    7,    0,    8,  115,
    9,   10,   11,   12,   13,   14,    0,    0,    0,    3,
   15,   93,    0,  164,    0,    0,    0,    0,  114,    0,
  115,  115,    0,    4,    5,   66,   95,    6,   94,  115,
   64,    0,  348,  123,    0,  123,    0,    7,    0,    8,
    3,    9,   10,   11,   12,   13,   14,    0,  123,    0,
  123,   15,    0,    0,    4,    5,   21,  164,    6,    0,
    0,  154,  164,  164,    0,  164,    0,  164,    7,    0,
    8,    0,    9,   10,   11,   12,   13,   14,    0,  154,
    0,    0,   15,  123,  123,  123,  123,  123,  123,    0,
  123,  123,   36,    0,    0,    3,   36,   36,   36,   36,
   36,   36,   36,    0,  123,  123,    0,    0,    0,    4,
    5,   65,    0,    6,   36,   36,   36,   36,    0,    0,
    0,    0,    0,    7,    0,    8,    0,    9,   10,   11,
   12,   13,   14,    0,  162,    0,    0,   15,  151,  162,
  162,    0,  162,    0,  162,    0,    0,    0,    0,  115,
  115,    0,    0,    0,    0,    0,  151,  126,  126,  126,
  126,  126,  126,    0,    0,    0,    0,    3,  163,  163,
  163,  163,  163,  163,    0,    0,    0,    0,  114,  114,
    0,    4,    5,    0,    0,    6,    0,    0,  167,  115,
  115,    0,    3,  168,  165,    7,  166,    8,  169,    9,
   10,   11,   12,   13,   14,    0,    4,    5,    0,   15,
    6,    0,    0,  123,  123,  123,  123,    0,    0,  123,
    7,    0,    8,    0,    9,   10,   11,   12,   13,   14,
    0,    0,    0,    0,   15,    0,    0,  162,  163,    0,
    0,    0,   56,   57,   47,   58,   59,   88,   89,   90,
   91,    0,    0,   92,    0,   60,   61,   34,    0,  123,
  123,   34,   34,   34,   34,   34,   34,   34,  118,  123,
  123,  123,  123,  118,  118,  123,  118,    0,  118,   34,
   34,   34,   34,   33,    0,    0,    0,   33,   33,   33,
   33,   33,   33,   33,    0,    0,    0,    0,    0,   66,
    0,    0,    0,    0,   64,   33,   33,   33,   33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   36,   36,
   36,   36,   36,   36,   35,    0,    0,    0,   35,   35,
   35,   35,   35,   35,   35,   86,    0,    0,    0,   86,
   86,   86,   86,   86,    0,   86,   35,   35,   35,   35,
    0,    0,    0,    0,    0,    0,    0,   86,   86,  119,
   86,    0,    0,  119,  119,  119,  119,  119,   85,  119,
    0,    0,   85,   85,   85,   85,   85,    0,   85,    0,
    0,  119,  119,    0,  119,   65,    0,    0,    0,    0,
   85,   85,  118,   85,    0,    0,  131,  118,  118,  116,
  118,    0,  118,  130,  116,  116,    0,  116,    0,  116,
    0,    0,  103,    0,  131,  131,  103,  131,  103,  103,
  103,  130,  130,  117,  130,    0,    0,  133,  117,  117,
    0,  117,  104,  117,  103,  103,  104,  103,  104,  104,
  104,    0,    0,  107,    0,  133,  133,  107,  133,  107,
  107,  107,    0,    0,  104,  104,    0,  104,    0,    0,
    0,    0,    0,    0,    0,  107,  107,  160,  107,    0,
    0,  147,  160,  160,    0,  160,    0,  160,    0,    0,
    0,    0,    0,   34,   34,   34,   34,   34,   34,  147,
    0,    0,    0,  161,    0,    0,    0,  148,  161,  161,
    0,  161,    0,  161,    0,    0,    0,    0,    0,   33,
   33,   33,   33,   33,   33,  148,   56,   57,  117,   58,
   59,    0,  153,  117,  117,    0,  117,  119,  117,   60,
   61,  156,  119,  119,    0,  119,    0,  119,  120,    0,
  153,    0,  159,  120,  120,    0,  120,    0,  120,  156,
   35,   35,   35,   35,   35,   35,    0,    0,    0,    0,
  159,   86,   86,   86,   86,   86,   86,  118,    0,    0,
    0,   97,  118,  118,   97,  118,    0,  118,    0,    0,
    0,    0,    0,    0,    0,  119,  119,  119,  119,  119,
  119,    0,    0,    0,   85,   85,   85,   85,   85,   85,
    0,    0,    0,    0,  162,    0,    0,   48,   96,  162,
  162,   96,  162,    0,  162,    0,   74,    0,  131,  131,
  131,  131,  131,  131,    0,  130,  130,  130,  130,  130,
  130,    0,    0,    0,    0,    0,   67,    0,  103,  103,
  103,  103,  103,  103,  132,  132,    0,   77,    0,  133,
  133,  133,  133,  133,  133,  135,  135,    0,  104,  104,
  104,  104,  104,  104,    0,    0,    0,    0,    0,  107,
  107,  107,  107,  107,  107,  130,  130,    0,    0,    0,
  178,  181,  182,  183,  184,    0,  138,  138,  160,  160,
  229,    0,   92,  160,  160,   92,  160,   74,  160,    0,
  161,   74,    0,  161,    0,   74,   74,   95,  161,  161,
   95,  161,    0,  161,    0,    0,    0,   67,    0,  248,
    0,   67,    0,    0,    0,   67,   67,    0,   77,    0,
    0,    0,   77,    0,    0,    0,   77,   77,  253,    0,
    0,    0,  117,    0,    0,  233,   94,  117,  117,   94,
  117,    0,  117,    0,    0,    0,  267,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  236,  236,
  236,  236,  236,  294,  295,  296,    0,    0,    0,  161,
  161,  161,  161,  161,    0,    0,    0,    0,    0,    0,
  132,  132,    0,  132,  132,  132,  132,  132,  132,    0,
  132,  135,  135,    0,  135,  135,  135,  135,  135,  135,
  310,  135,  311,    0,    0,    0,    0,    0,    0,    0,
    0,  130,  130,  321,  130,  130,  130,  130,  130,  130,
    0,  130,  138,  138,    0,  138,  138,  138,  138,  138,
  138,    0,  138,    0,    0,  335,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  345,
};
static const short yycheck[] = {                          2,
   49,   54,   46,   46,   40,   54,   54,    2,  125,  200,
   13,   41,   15,   13,   40,   91,   46,  125,   61,  125,
  227,    2,  125,  122,   94,   53,   40,   40,  259,   59,
   59,   41,   13,    2,   46,   46,  257,   41,   46,  260,
   46,   44,   13,   41,   13,   93,   49,   59,   41,   59,
   61,   54,  122,   61,   54,   59,   41,   60,   61,  298,
  299,   59,   65,  125,   44,   91,   59,   41,   49,   44,
   38,  257,  258,   54,  122,   44,   46,   91,   91,   59,
  257,   84,  273,  260,   59,   88,   89,   90,   91,   92,
   93,   94,  123,   96,   94,   98,   99,  100,   98,  102,
  103,  308,  102,  103,  287,    2,    0,   88,   89,   90,
   91,   92,  211,   94,   40,  257,   13,   98,  260,  122,
   45,  102,  103,   94,  127,   94,   94,   98,   44,   98,
  337,  102,  103,  102,  103,   42,   40,   40,   44,  330,
   47,  211,  260,   59,  147,   61,  127,  338,  151,  260,
  153,  342,  260,   59,  260,   61,  124,   54,  127,  270,
  271,  164,   44,  211,  275,   59,   40,  170,  171,  172,
  173,  174,  153,  176,   44,  260,   59,   59,  147,   46,
   41,  298,  299,   44,   60,  257,   62,   13,  260,   59,
  218,  219,  195,  269,   61,  298,  299,   94,   46,  202,
  228,   98,   59,  260,   40,  102,  103,  176,  211,   61,
  213,   61,  260,  260,  262,   40,  260,  220,   44,  260,
   45,  257,  258,  123,  227,  220,  195,  270,  271,   61,
  127,  125,  227,  202,  263,  264,  298,  299,   64,  220,
  270,  271,   41,  269,  213,   44,  227,  250,  251,  252,
  276,  220,   44,  256,   46,  258,  309,  260,  227,  262,
  309,  309,   59,    0,  270,  271,   46,   59,   94,   61,
  263,  264,   98,   46,   40,  256,  102,  103,  263,  264,
   40,  250,  251,  252,  287,  123,  289,  256,  260,  263,
  264,   94,   41,   13,  260,   98,   44,  300,   93,  102,
  103,  126,  305,   93,  307,  308,  309,   40,   46,  309,
  260,   41,   59,  308,   41,   40,  284,  285,  287,  322,
  289,  147,   59,  220,   44,   40,  307,  308,  309,   91,
  227,  300,  257,  258,  337,  260,  339,  340,  307,  308,
   40,  344,  337,  346,   40,  270,  271,   59,  279,   41,
  176,   46,   93,  322,   93,   40,  337,   41,  339,  256,
   65,   40,  123,  344,   41,  346,  260,   41,  337,  195,
  339,  340,  260,   40,   94,  344,  202,  346,   98,   41,
  274,  275,  102,  103,  278,   40,  291,  213,  125,  265,
  266,  267,  268,   46,  288,  260,  290,  291,  292,  293,
  294,  295,  296,  297,  298,  299,   93,   59,  302,   41,
  307,  308,  309,   37,   38,   93,   41,   41,   42,   43,
   44,   45,   41,   47,  250,  251,  252,  147,   40,   58,
  260,   41,  257,  258,  259,  260,  261,   41,   41,   41,
  337,   41,  339,   58,   40,  270,  271,  344,   59,  346,
  275,   41,  123,   41,   37,    0,  176,  123,   41,   42,
   43,  287,   45,  289,   47,  170,  171,  172,  173,  174,
   94,   41,   59,  125,  300,  195,   59,  302,   59,   59,
  305,   59,  202,   59,   41,  309,  312,   61,  280,  281,
  282,  283,   61,  213,  286,   59,  322,   37,   38,   61,
  124,   41,   42,   43,   44,   45,   46,   47,   61,   59,
   41,  202,  123,  314,  340,   -1,   -1,  211,   -1,   59,
   60,   61,   62,  260,  221,  222,  223,  224,  225,  226,
  250,  251,  252,   -1,   59,   -1,   -1,  274,  275,   -1,
   -1,  278,   37,   38,   -1,  125,   41,   42,   43,   -1,
   45,  288,   47,  290,   94,  292,  293,  294,  295,  296,
  297,  298,  299,   -1,   59,  302,   -1,  287,   -1,  289,
   -1,   37,   38,   -1,   -1,   41,   42,   43,   44,   45,
  300,   47,   37,   38,  124,   -1,   41,   42,   43,   44,
   45,   -1,   47,   59,   60,   -1,   62,   -1,   -1,   94,
  125,   -1,  322,   -1,   59,   60,   59,   62,  260,  165,
  166,  167,  168,  169,   -1,   -1,   -1,   44,   -1,   46,
  340,   -1,  274,  275,   -1,   -1,  278,   -1,   94,  124,
   -1,   59,   59,   -1,   61,   -1,  288,   -1,  290,   94,
  292,  293,  294,  295,  296,  297,   -1,   -1,   -1,  260,
  302,   44,   -1,   46,   -1,   -1,   -1,   -1,  124,   -1,
  284,  285,   -1,  274,  275,   40,   59,  278,   61,  124,
   45,   -1,  125,   44,   -1,   46,   -1,  288,   -1,  290,
  260,  292,  293,  294,  295,  296,  297,   -1,   59,   -1,
   61,  302,   -1,   -1,  274,  275,  123,   37,  278,   -1,
   -1,   41,   42,   43,   -1,   45,   -1,   47,  288,   -1,
  290,   -1,  292,  293,  294,  295,  296,  297,   -1,   59,
   -1,   -1,  302,  263,  264,  265,  266,  267,  268,   -1,
  270,  271,   37,   -1,   -1,  260,   41,   42,   43,   44,
   45,   46,   47,   -1,  284,  285,   -1,   -1,   -1,  274,
  275,  126,   -1,  278,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,  288,   -1,  290,   -1,  292,  293,  294,
  295,  296,  297,   -1,   37,   -1,   -1,  302,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  284,
  285,   -1,   -1,   -1,   -1,   -1,   59,  263,  264,  265,
  266,  267,  268,   -1,   -1,   -1,   -1,  260,  263,  264,
  265,  266,  267,  268,   -1,   -1,   -1,   -1,  284,  285,
   -1,  274,  275,   -1,   -1,  278,   -1,   -1,   37,  284,
  285,   -1,  260,   42,   43,  288,   45,  290,   47,  292,
  293,  294,  295,  296,  297,   -1,  274,  275,   -1,  302,
  278,   -1,   -1,  280,  281,  282,  283,   -1,   -1,  286,
  288,   -1,  290,   -1,  292,  293,  294,  295,  296,  297,
   -1,   -1,   -1,   -1,  302,   -1,   -1,  270,  271,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  280,  281,  282,
  283,   -1,   -1,  286,   -1,  270,  271,   37,   -1,  270,
  271,   41,   42,   43,   44,   45,   46,   47,   37,  280,
  281,  282,  283,   42,   43,  286,   45,   -1,   47,   59,
   60,   61,   62,   37,   -1,   -1,   -1,   41,   42,   43,
   44,   45,   46,   47,   -1,   -1,   -1,   -1,   -1,   40,
   -1,   -1,   -1,   -1,   45,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,
  265,  266,  267,  268,   37,   -1,   -1,   -1,   41,   42,
   43,   44,   45,   46,   47,   37,   -1,   -1,   -1,   41,
   42,   43,   44,   45,   -1,   47,   59,   60,   61,   62,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   37,
   62,   -1,   -1,   41,   42,   43,   44,   45,   37,   47,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,
   -1,   59,   60,   -1,   62,  126,   -1,   -1,   -1,   -1,
   59,   60,   37,   62,   -1,   -1,   41,   42,   43,   37,
   45,   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   37,   -1,   59,   60,   41,   62,   43,   44,
   45,   59,   60,   37,   62,   -1,   -1,   41,   42,   43,
   -1,   45,   37,   47,   59,   60,   41,   62,   43,   44,
   45,   -1,   -1,   37,   -1,   59,   60,   41,   62,   43,
   44,   45,   -1,   -1,   59,   60,   -1,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   60,   37,   62,   -1,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   59,
   -1,   -1,   -1,   37,   -1,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,  263,
  264,  265,  266,  267,  268,   59,  257,  258,   37,  260,
  261,   -1,   41,   42,   43,   -1,   45,   37,   47,  270,
  271,   41,   42,   43,   -1,   45,   -1,   47,   37,   -1,
   59,   -1,   41,   42,   43,   -1,   45,   -1,   47,   59,
  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,   -1,
   59,  263,  264,  265,  266,  267,  268,   37,   -1,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,
  268,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,   37,   -1,   -1,    4,   41,   42,
   43,   44,   45,   -1,   47,   -1,   13,   -1,  263,  264,
  265,  266,  267,  268,   -1,  263,  264,  265,  266,  267,
  268,   -1,   -1,   -1,   -1,   -1,   13,   -1,  263,  264,
  265,  266,  267,  268,   52,   53,   -1,   13,   -1,  263,
  264,  265,  266,  267,  268,   52,   53,   -1,  263,  264,
  265,  266,  267,  268,   -1,   -1,   -1,   -1,   -1,  263,
  264,  265,  266,  267,  268,   52,   53,   -1,   -1,   -1,
   88,   89,   90,   91,   92,   -1,   52,   53,   37,   66,
  147,   -1,   41,   42,   43,   44,   45,   94,   47,   -1,
   66,   98,   -1,   37,   -1,  102,  103,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   94,   -1,  176,
   -1,   98,   -1,   -1,   -1,  102,  103,   -1,   94,   -1,
   -1,   -1,   98,   -1,   -1,   -1,  102,  103,  195,   -1,
   -1,   -1,   37,   -1,   -1,  153,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,  213,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  165,  166,
  167,  168,  169,  250,  251,  252,   -1,   -1,   -1,  165,
  166,  167,  168,  169,   -1,   -1,   -1,   -1,   -1,   -1,
  218,  219,   -1,  221,  222,  223,  224,  225,  226,   -1,
  228,  218,  219,   -1,  221,  222,  223,  224,  225,  226,
  287,  228,  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  218,  219,  300,  221,  222,  223,  224,  225,  226,
   -1,  228,  218,  219,   -1,  221,  222,  223,  224,  225,
  226,   -1,  228,   -1,   -1,  322,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  340,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,
0,0,0,0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"XINTEGER","TDOUBLE",
"TBOOL","IDENTIFIER","TSTRING","OP_CALC","AND_OP","OR_OP","LE_OP","GE_OP",
"EQ_OP","NE_OP","FUNC_OP","INC_OP","DEC_OP","FUNC_CALL","VAR_DECLAR","RESTRICT",
"THIS","EXTENDS","ARRAY_ELE","XTRY","XCATCH","ADD_EQ","SUB_EQ","MUL_EQ",
"DIV_EQ","LEFT_SHIFT","RIGHT_SHIFT","MOD_EQ","XPUBLIC","XSET","AUTO","IF",
"ELSE","WHILE","FOR","DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT",
"CASE_LIST","CLAXX_BODY","NEW","CLAXX_MEMBER","CLAXX_FUNC_CALL","XNULL",
"NONASSOC","IFX","UMINUS",
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
"statement : try_stmt",
"try_stmt : XTRY '{' expr_list '}'",
"try_stmt : XTRY '{' expr_list '}' catch_block_stmt",
"catch_block_stmt : XCATCH '(' id_expr ')' '{' expr_list '}'",
"declar_stmt : func_declar_stmt",
"declar_stmt : var_declar_stmt",
"declar_stmt : class_declar_stmt",
"declar_stmt : namespace_declar_stmt ';'",
"namespace_declar_stmt : XSET XPUBLIC '=' namespace_name_stmt",
"namespace_name_stmt : IDENTIFIER",
"namespace_name_stmt : namespace_name_stmt '.' IDENTIFIER",
"class_declar_stmt : IDENTIFIER extends_stmt '{' '}'",
"class_declar_stmt : IDENTIFIER extends_stmt '{' class_body '}'",
"extends_stmt :",
"extends_stmt : EXTENDS IDENTIFIER",
"class_body : class_body_stmt",
"class_body : class_body class_body_stmt",
"class_body_stmt : var_declar_stmt",
"class_body_stmt : single_assign_stmt ';'",
"class_body_stmt : func_declar_stmt",
"this_stmt : THIS",
"this_stmt : THIS '.' id_expr",
"this_stmt : THIS '.' id_expr '(' args_list ')'",
"this_member_stmt : THIS '.' id_expr",
"this_member_stmt : THIS '.' class_member_stmt",
"class_member_stmt : id_expr '.' id_expr",
"class_member_stmt : class_member_func_stmt '.' id_expr",
"class_member_stmt : IDENTIFIER '(' args_list ')' '.' id_expr",
"class_member_stmt : class_member_stmt '.' id_expr",
"class_member_func_stmt : id_expr '.' id_expr '(' args_list ')'",
"class_member_func_stmt : IDENTIFIER '(' args_list ')' '.' id_expr '(' args_list ')'",
"class_member_func_stmt : class_member_stmt '.' id_expr '(' args_list ')'",
"class_member_func_stmt : class_member_func_stmt '.' id_expr '(' args_list ')'",
"class_func_serial_stmt : IDENTIFIER '(' args_list ')' IDENTIFIER '(' args_list ')'",
"class_func_serial_stmt : id_expr '.' id_expr '(' args_list ')' IDENTIFIER '(' args_list ')'",
"class_func_serial_stmt : class_func_serial_stmt IDENTIFIER '(' args_list ')'",
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
"var_declar_stmt : IDENTIFIER '[' XINTEGER ']' ';'",
"var_declar_stmt : IDENTIFIER '[' XINTEGER ']' ',' var_declar_stmt",
"var_declar_stmt : IDENTIFIER '[' IDENTIFIER ']' ';'",
"var_declar_stmt : IDENTIFIER '[' IDENTIFIER ']' ',' var_declar_stmt",
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
"simple_stmt : new_expr",
"simple_stmt : class_func_serial_stmt",
"simple_stmt : restrict_stmt",
"restrict_stmt : RESTRICT",
"restrict_stmt : RESTRICT t_bool_expr",
"interrupt_stmt : BREAK",
"interrupt_stmt : RETURN",
"interrupt_stmt : RETURN assign_stmt_value",
"call_statement : IDENTIFIER '(' args_list ')'",
"call_statement : class_member_func_stmt",
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
"arithmetic_stmt : arithmetic_stmt_factor '%' arithmetic_stmt_factor",
"arithmetic_stmt : bit_opr_factor '&' bit_opr_factor",
"arithmetic_stmt : bit_opr_factor '|' bit_opr_factor",
"arithmetic_stmt : bit_opr_factor '^' bit_opr_factor",
"arithmetic_stmt : '~' bit_opr_factor",
"arithmetic_stmt : bit_opr_factor LEFT_SHIFT bit_opr_factor",
"arithmetic_stmt : bit_opr_factor RIGHT_SHIFT bit_opr_factor",
"bit_opr_factor : XINTEGER",
"bit_opr_factor : id_expr",
"arithmetic_stmt_factor : assign_stmt_value_eq",
"arithmetic_stmt_factor : string_expr",
"arithmetic_stmt_factor : arithmetic_stmt",
"arithmetic_stmt_factor : class_member_stmt",
"arithmetic_stmt_factor : array_ele_stmt",
"arithmetic_stmt_factor : '(' arithmetic_stmt ')'",
"new_expr : NEW id_expr '(' args_list ')'",
"id_expr : IDENTIFIER",
"t_bool_expr : TBOOL",
"double_expr : TDOUBLE",
"double_expr : XINTEGER",
"uminus_expr : '-' double_or_ps_expr",
"string_expr : TSTRING",
"null_expr : XNULL",
"bool_param_expr : assign_stmt_value_eq",
"bool_param_expr : arithmetic_stmt",
"bool_param_expr : t_bool_expr",
"bool_param_expr : string_expr",
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
"assign_stmt_value : new_expr",
"assign_stmt_value : class_member_stmt",
"assign_stmt_value : null_expr",
"assign_stmt_value : this_stmt",
"assign_stmt_value : array_ele_stmt",
"assign_stmt_value_eq : double_expr",
"assign_stmt_value_eq : uminus_expr",
"assign_stmt_value_eq : call_statement",
"assign_stmt_value_eq : id_expr",
"assign_stmt_value_eq : self_inc_dec_stmt",
"single_assign_stmt : id_expr '=' assign_stmt_value",
"single_assign_stmt : id_expr '=' single_assign_stmt",
"class_member_assign_stmt : class_member_stmt '=' assign_stmt_value",
"class_member_assign_stmt : this_member_stmt '=' assign_stmt_value",
"array_ele_stmt : IDENTIFIER '[' XINTEGER ']'",
"array_ele_stmt : IDENTIFIER '[' IDENTIFIER ']'",
"array_ele_assign_stmt : array_ele_stmt '=' assign_stmt_value",
"assign_stmt : single_assign_stmt",
"assign_stmt : class_member_assign_stmt",
"assign_stmt : array_ele_assign_stmt",
"assign_stmt : id_expr ADD_EQ assign_stmt_value_eq",
"assign_stmt : id_expr SUB_EQ assign_stmt_value_eq",
"assign_stmt : id_expr MUL_EQ assign_stmt_value_eq",
"assign_stmt : id_expr DIV_EQ assign_stmt_value_eq",
"assign_stmt : id_expr MOD_EQ assign_stmt_value_eq",

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
#line 458 "a.y"


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
	
	parseFileName = argv[1];
	extern FILE* yyin; 
	yyin=fp;
	initLangX();
	changeScriptEnv(parseFileName);
    yyparse();
	closeLangX();
	fclose(fp);
	
	printf("parse over!\n");
	return 0;
}
#line 892 "y.tab.c"

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
#line 72 "a.y"
	{ execAndFreeNode(yystack.l_mark[0].node);}
break;
case 4:
#line 76 "a.y"
	{ yyval.node = opr(';' , 0 ); }
break;
case 5:
#line 77 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 6:
#line 78 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 79 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 8:
#line 80 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 9:
#line 85 "a.y"
	{ yyval.node = opr(XTRY, 2,yystack.l_mark[-1].node,NULL); }
break;
case 10:
#line 86 "a.y"
	{ yyval.node = opr(XTRY, 2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 11:
#line 90 "a.y"
	{ yyval.node = opr(XCATCH, 2, yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 12:
#line 95 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 13:
#line 96 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 14:
#line 97 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 15:
#line 98 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 16:
#line 103 "a.y"
	{ yyval.node = changeNameSpace(yystack.l_mark[0].sValue); }
break;
case 17:
#line 107 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue ; }
break;
case 18:
#line 108 "a.y"
	{ yyval.sValue = NULL ; }
break;
case 19:
#line 113 "a.y"
	{ /*if($2 != NULL) printf("parentName: %s\n",$2);*/ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-2].sValue, NULL); }
break;
case 20:
#line 114 "a.y"
	{ /*if($2 != NULL) printf("parentName: %s\n",$2);*/ yyval.node = claxx(yystack.l_mark[-4].sValue , yystack.l_mark[-3].sValue, yystack.l_mark[-1].node); }
break;
case 21:
#line 119 "a.y"
	{ yyval.sValue = NULL; }
break;
case 22:
#line 120 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue; }
break;
case 23:
#line 125 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 24:
#line 126 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 25:
#line 130 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 26:
#line 131 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 27:
#line 132 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 28:
#line 137 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 29:
#line 138 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 30:
#line 140 "a.y"
	{ yyval.node = opr(THIS, 1 , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 31:
#line 145 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 32:
#line 146 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 33:
#line 151 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 34:
#line 152 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 35:
#line 153 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 36:
#line 154 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 37:
#line 159 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 38:
#line 160 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 39:
#line 161 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 40:
#line 162 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 41:
#line 167 "a.y"
	{  yyval.node = NULL; }
break;
case 42:
#line 168 "a.y"
	{ yyval.node = NULL; }
break;
case 43:
#line 169 "a.y"
	{ yyval.node = NULL; }
break;
case 44:
#line 174 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 45:
#line 178 "a.y"
	{ yyval.params = NULL; }
break;
case 46:
#line 179 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 47:
#line 183 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 48:
#line 184 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 49:
#line 185 "a.y"
	{ yyval.params = NULL; }
break;
case 50:
#line 189 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 51:
#line 190 "a.y"
	{ yyval.node = NULL; }
break;
case 52:
#line 195 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 53:
#line 196 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 54:
#line 197 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,yystack.l_mark[-2].intValue,NULL) ); }
break;
case 55:
#line 198 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,yystack.l_mark[-3].intValue,NULL),yystack.l_mark[0].node); }
break;
case 56:
#line 199 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,-1,var(yystack.l_mark[-2].sValue)) ); }
break;
case 57:
#line 200 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,-1,var(yystack.l_mark[-3].sValue)),yystack.l_mark[0].node); }
break;
case 58:
#line 205 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 59:
#line 206 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 60:
#line 211 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 61:
#line 212 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 62:
#line 213 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 63:
#line 217 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 64:
#line 218 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 65:
#line 222 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 66:
#line 223 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 67:
#line 227 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 68:
#line 228 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 69:
#line 233 "a.y"
	{ yyval.node = NULL ; }
break;
case 70:
#line 234 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 71:
#line 235 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 72:
#line 236 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 241 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 242 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 243 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 76:
#line 244 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 77:
#line 245 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 78:
#line 246 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 79:
#line 247 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 253 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 81:
#line 254 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 82:
#line 258 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 83:
#line 259 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 84:
#line 260 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 85:
#line 265 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 86:
#line 266 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 87:
#line 270 "a.y"
	{ yyval.args = NULL; }
break;
case 88:
#line 271 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 89:
#line 275 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 90:
#line 276 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 91:
#line 280 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 281 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 282 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 94:
#line 283 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 95:
#line 284 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 96:
#line 285 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 97:
#line 286 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 98:
#line 290 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 99:
#line 291 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 100:
#line 297 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 101:
#line 298 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 102:
#line 303 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 103:
#line 309 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 104:
#line 310 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 105:
#line 311 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 106:
#line 312 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 107:
#line 313 "a.y"
	{ yyval.node = opr('%',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 108:
#line 314 "a.y"
	{ yyval.node = opr('&',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 109:
#line 315 "a.y"
	{ yyval.node = opr('|',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 110:
#line 316 "a.y"
	{ yyval.node = opr('^',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 111:
#line 317 "a.y"
	{ /* printf("get a ~ opr.\n"); */ yyval.node = opr('~',1,yystack.l_mark[0].node); }
break;
case 112:
#line 318 "a.y"
	{ yyval.node = opr(LEFT_SHIFT,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 113:
#line 319 "a.y"
	{ yyval.node = opr(RIGHT_SHIFT,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 114:
#line 324 "a.y"
	{ yyval.node = xint(yystack.l_mark[0].intValue); }
break;
case 115:
#line 325 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 116:
#line 330 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 117:
#line 331 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 118:
#line 332 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 119:
#line 333 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 120:
#line 334 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 121:
#line 335 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 122:
#line 340 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 123:
#line 344 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 124:
#line 348 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 125:
#line 352 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 126:
#line 353 "a.y"
	{ yyval.node = number(yystack.l_mark[0].intValue); }
break;
case 127:
#line 357 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 128:
#line 361 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 129:
#line 365 "a.y"
	{ yyval.node = xnull();}
break;
case 130:
#line 370 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 131:
#line 371 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 132:
#line 372 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 133:
#line 373 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 134:
#line 378 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 135:
#line 379 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 136:
#line 380 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 137:
#line 381 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 138:
#line 382 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 139:
#line 383 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 140:
#line 384 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 141:
#line 385 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 142:
#line 386 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 143:
#line 391 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 144:
#line 392 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 145:
#line 393 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 146:
#line 394 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 147:
#line 399 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 148:
#line 400 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 149:
#line 401 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 150:
#line 402 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 151:
#line 403 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 152:
#line 404 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 153:
#line 405 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 154:
#line 406 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 155:
#line 407 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 156:
#line 408 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 157:
#line 409 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 158:
#line 410 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 159:
#line 411 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 160:
#line 416 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 161:
#line 417 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 162:
#line 418 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 163:
#line 419 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 164:
#line 420 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 165:
#line 425 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 166:
#line 426 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 167:
#line 430 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 168:
#line 431 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 169:
#line 436 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, yystack.l_mark[-1].intValue, NULL); }
break;
case 170:
#line 437 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, -1, var(yystack.l_mark[-1].sValue)) ; }
break;
case 171:
#line 443 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 172:
#line 448 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 173:
#line 449 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 174:
#line 450 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 175:
#line 451 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 176:
#line 452 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 177:
#line 453 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 178:
#line 454 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 179:
#line 455 "a.y"
	{ yyval.node = opr(MOD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1806 "y.tab.c"
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
