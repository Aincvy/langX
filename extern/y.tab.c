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
#define AUTO 287
#define IF 288
#define ELSE 289
#define WHILE 290
#define FOR 291
#define DELETE 292
#define BREAK 293
#define RETURN 294
#define SWITCH 295
#define CASE 296
#define DEFAULT 297
#define CASE_LIST 298
#define CLAXX_BODY 299
#define NEW 300
#define CLAXX_MEMBER 301
#define CLAXX_FUNC_CALL 302
#define XNULL 303
#define NONASSOC 304
#define IFX 305
#define UMINUS 306
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,   55,   55,    1,    1,    1,    1,    1,   26,   26,
   27,    2,    2,    2,   36,   36,   54,   54,   37,   37,
   38,   38,   38,   45,   45,   45,   46,   46,   39,   39,
   39,   39,   41,   41,   41,   41,   42,   42,   42,    5,
   50,   50,   51,   51,   51,    7,    7,    6,    6,    6,
    6,    6,    6,    3,    3,    8,    8,    8,   34,   34,
   35,   35,    9,    9,   12,   12,   12,   12,    4,    4,
    4,    4,    4,    4,    4,   44,   44,   24,   24,   24,
   16,   16,   52,   52,   53,   53,   17,   17,   17,   17,
   17,   17,   17,   11,   11,   18,   18,   19,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   49,
   49,   33,   33,   33,   33,   33,   33,   25,   28,   29,
   30,   30,   31,   32,   43,   23,   23,   23,   23,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   15,   15,
   15,   15,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   20,   20,   20,   20,   20,
   22,   22,   40,   40,   47,   47,   48,   13,   13,   13,
   13,   13,   13,   13,   13,
};
static const short yylen[] = {                            2,
    1,    2,    0,    1,    1,    1,    2,    1,    4,    5,
    7,    1,    1,    1,    4,    5,    0,    2,    1,    2,
    1,    2,    1,    1,    3,    6,    3,    3,    3,    3,
    6,    3,    6,    9,    6,    6,    8,   10,    5,    6,
    0,    3,    1,    3,    0,    2,    0,    2,    3,    5,
    6,    5,    6,    1,    1,    5,    7,    7,    1,    2,
    4,    3,    5,    9,    0,    1,    1,    1,    1,    1,
    3,    1,    1,    1,    1,    1,    2,    1,    1,    2,
    4,    1,    0,    1,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    3,    3,    1,
    1,    1,    1,    1,    1,    1,    3,    5,    1,    1,
    1,    1,    2,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    2,
    2,    2,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    3,    3,    3,    3,    4,    4,    3,    1,    1,    1,
    3,    3,    3,    3,    3,
};
static const short yydefred[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   78,    0,    0,    0,    4,    2,    5,    6,    0,   12,
   13,   54,   55,   69,   70,  168,   72,   73,    8,    0,
   14,    0,  169,    0,    0,   75,    0,    0,  170,    0,
    0,    0,    0,    0,  120,   77,    0,   47,    0,    0,
    0,    0,    0,  121,    0,  124,    0,    0,    0,  125,
    0,    0,    0,    0,    0,    0,  112,   80,  151,    0,
  145,    0,    0,    0,    0,    0,  153,  154,    0,    0,
    0,  119,    0,    7,    0,    0,    0,    0,    0,    0,
    0,   48,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,    0,  160,    0,   85,    0,   87,    0,    0,
    0,    0,  116,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  158,    0,    0,    0,  128,
  156,  157,    0,    0,    0,   67,    0,   66,   68,    0,
   71,    0,    0,  139,  140,    0,  122,    0,  123,   97,
   96,  110,  111,  107,    0,  113,  141,  142,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  171,    0,    0,  172,  173,  174,  175,    0,
   49,    0,  161,  162,    0,    0,  163,    0,    0,    0,
  164,  167,   43,    0,   47,    0,    0,    0,    0,    0,
   15,   23,   21,    0,    0,    0,   19,    0,    0,   46,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  117,    0,  114,    0,
    0,    0,  101,  102,  108,  109,  104,  105,  106,    0,
    0,    0,    0,    0,    0,    0,    0,   42,    0,    0,
    0,   86,    0,   50,    0,   52,   22,   16,   20,    0,
    0,   10,  137,  138,   47,   95,    0,  133,  134,  135,
  136,  131,  132,   63,    0,    0,  165,  166,    0,   98,
    0,    0,  118,    0,    0,    0,    0,    0,   39,   44,
   40,    0,    0,   51,   53,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   59,    0,    0,    0,   35,
   36,    0,    0,    0,   94,   57,    0,   26,   33,    0,
   47,   58,   60,    0,   37,    0,    0,    0,   47,    0,
    0,   34,   47,   64,    0,    0,    0,   38,   11,
};
static const short yydgoto[] = {                          1,
  210,   17,   18,   19,   20,   21,  123,   22,   23,  124,
  267,  137,   24,  103,  104,  126,  106,  149,  150,   67,
   68,   26,  128,   27,   28,   29,  262,  129,  108,  131,
  132,  111,   75,  305,  306,   31,  206,  207,  112,   33,
   34,   35,   77,   36,   78,   37,  113,   39,   80,  101,
  194,  114,  115,   44,    2,
};
static const short yysindex[] = {                         0,
    0,  393,  -19, -250,  -11,  -80,   19,   25,   27, -203,
    0,  336,   37, -157,    0,    0,    0,    0,   60,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  396,
    0,   20,    0,   82, -124,    0,   92,   94,    0,  120,
  -98,  291, -223,   52,    0,    0,  -79,    0,  291,  291,
 -197,  124,    0,    0,  -22,    0, -157, -157,  145,    0,
    7,  -84,  859,    0,    0,    0,    0,    0,    0,  -39,
    0,    0,    0,    0,  301,  164,    0,    0,    0,  -12,
 -157,    0,  173,    0,  176,  176,  176,  176,  176,  -43,
  336,    0, -157,  336, -157, -157,  174,  336,  336,  -25,
  117,    0,    0,    0,    0,    0,  -39,    0,    0,    0,
    0,  164,    0,  207,  212,  168,  175, -117,  238,  234,
  164,   82,  499,   21,    0,    0,    0,  259,  -39,    0,
    0,    0,    0,   39,    8,    0,  222,    0,    0,  230,
    0,  291,  -78,    0,    0, -157,    0,  176,    0,    0,
    0,    0,    0,    0,  247,    0,    0,    0, -157,  859,
  859,  859,  859,  859,  -84,  -84,  -84,  -84,  -84,  253,
  291,  252,    0,  -39,  164,    0,    0,    0,    0,  210,
    0,   51,    0,    0,   29,  264,    0,  266,  269,  291,
    0,    0,    0,  148,    0,  -15,  291,   63,   70,  -89,
    0,    0,    0,  256,   54, -110,    0,  291,   38,    0,
  291,  291,  569,  291,  291,  291,  291,  291,  291,  569,
  291,  279,  229,  237,  283,  299,    0,  292,    0,   58,
   58,   58,    0,    0,    0,    0,    0,    0,    0,  224,
  310,  -64,  291,  291,  291,  312,   95,    0,  592,  320,
 -157,    0,  -43,    0,  -43,    0,    0,    0,    0,  317,
  326,    0,    0,    0,    0,    0,   78,    0,    0,    0,
    0,    0,    0,    0,  -55,  323,    0,    0,  291,    0,
  291, -170,    0,  281,  287,  343,  346,  349,    0,    0,
    0,  291,  351,    0,    0,  323, -157,  615,  569, -197,
  353,  355,  -59,  334, -112,    0,   63,   70,  138,    0,
    0,  371,  291,  373,    0,    0,  374,    0,    0,  360,
    0,    0,    0,  384,    0,  402,  321,  569,    0,  393,
  291,    0,    0,    0,  393,  409,  642,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,  454,  462,  401,    0,    0,    0,    0,    0,    0,
    0,  404,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  939,  407,    0,    0,    0,    0,  345,
    0,  429,    0,    0,    0,    0,    0,    0,    0,    0,
  413,    0,  497,    0,  443,    0,    0,    0,   -9,    0,
    0,    0,    0,  600,  607, 1090,    0,    0,    0,  -18,
    0, 1099, 1114, 1138,    0, 1204,    0,    0, 1332,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  159,
    0,    0, 1057,    0, 1341,    0,  531,    0, 1378, 1387,
 1419,  969,    0,    0,  432,    0,    0,    0,   84,  414,
  416,    0,    0,    0, 1002,    0, 1026,   -5,  571,    0,
    0,    0, 1033,    0,  318,    0,    0,    0,    0,    0,
    0,  429,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  733,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  429,   12,    0,   -8,    0,    0,    0,    0,    0,  112,
    0,    0,    0,    0,  -18,  113,    0,  692,  759,  429,
    0,    0,    0,    0,    0,  419,    0,  418,  422,   93,
    0,    0,    0,    0,    0,    0,    0,  429,  111,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    5,    0,    0,  902,    0,  659,
  959, 1046,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  429,  429,  429,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  135,    0,    0,    0,
    0,    0,    0,    0,    0,  993,    0,    0,  429,    0,
  429,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  429,  928,    0,    0,    0,    0,    0,    0,  450,
    0,    0,    0,    0,    0,    0,    0,    0,  102,    0,
    0,    0,  429,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -95,
  429,    0,    0,    0,   17,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    9,    0,    0,    0, -104,  -48,  132,    0,    0,  -34,
 -181,  192,  -45, 1189,   10,   26,  296,    0,    0, 1279,
  284,  -74,  593,    0,   40,    0,    0,   -2, 1122,  251,
  274, 1232,  500,    0,  193,    0,    0,  293,  139,    0,
  -46,    0,    0,    0,    0,    0,  121,    0,  557,    0,
    0, 1173,    0,    0,    0,
};
#define YYTABLESIZE 1504
static const short yytable[] = {                         30,
  122,  242,  136,  300,  122,  138,  159,  201,   45,   70,
   16,   83,  322,  202,  258,  134,  184,  142,  159,  111,
   42,   65,  148,  159,  159,  167,  159,   25,  159,   62,
  251,   24,  159,  116,   47,  130,  117,   66,  274,  107,
  148,  181,   48,  204,  120,   25,  148,  208,  140,   24,
  159,   69,  119,  130,  144,  145,   52,  119,   49,  153,
  139,  213,  135,   25,   50,   95,   51,  105,  143,  203,
  119,   43,   57,   58,  159,  111,   81,    5,  170,  220,
   94,  169,  174,  174,  174,  174,  174,  182,  185,   91,
  186,   70,  188,  189,   90,   70,   70,   90,   43,  163,
   65,  202,   82,   65,  164,  111,  253,   65,   65,   92,
    9,  168,   92,  255,   91,  205,   66,  316,   84,   66,
   30,  254,   38,   66,   66,  303,  304,   96,  256,  119,
   69,  204,   79,   69,   56,   97,  119,   69,   69,  107,
   32,   61,  200,  225,  119,  174,  334,   33,   25,  200,
   76,  119,   98,  119,   99,  119,  228,  203,   29,  100,
   33,  102,  153,  153,  153,  153,  153,  105,  107,    9,
  119,   38,  152,   29,  118,   82,  263,  264,  223,   40,
  119,  224,  141,  303,  304,  121,  275,  107,  248,   32,
  146,  247,  284,   56,  107,  285,  105,  147,   54,   45,
   62,   62,   45,  205,  294,  107,  295,  211,  212,   95,
   30,   79,  171,  190,   79,  105,  180,   30,   79,   79,
   61,  266,  105,  175,  175,  175,  175,  175,  266,   76,
  157,  158,   76,  105,  193,    9,   76,   76,   25,  195,
  107,  107,  107,   38,  250,   25,   30,  196,  293,   40,
  182,  136,  182,  122,  138,  197,   41,  130,  130,   56,
  198,   32,   72,  147,   54,  111,  111,  199,  105,  105,
  105,  165,  166,   90,   25,  159,  107,  208,  107,  159,
  221,  119,  119,  211,  212,   73,  175,  227,   92,  107,
   91,  142,  109,  240,  314,   30,   30,  140,  157,  158,
  242,  211,  212,  243,  105,  244,  105,  266,  245,  139,
  107,  151,   61,   61,  257,  110,  261,  105,  219,  276,
  218,  277,  279,   25,   25,   30,  249,   30,  107,  278,
   63,  281,   30,   38,   30,   61,  266,  162,  105,  280,
   38,   72,  163,  160,   72,  161,  282,  164,   72,   72,
  283,   32,  289,   25,  290,   25,  105,  296,   32,  292,
   25,  119,   25,  119,   73,  297,  299,   73,  251,   38,
    9,   73,   73,  307,  183,   63,  119,  187,  119,  308,
   61,  191,  192,  309,    9,    9,  310,   32,    9,  311,
  313,  321,  109,  318,   56,  319,  298,  324,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,   56,   56,
    9,  325,   56,  327,  328,  110,   62,  329,   38,   38,
   38,  109,   56,  331,   56,   56,   56,   56,   56,   56,
   56,   56,  147,   54,   56,  172,   32,   32,   32,   90,
  109,   93,  332,  333,  110,   57,   58,  109,   38,  338,
   38,   15,  330,    1,   92,   38,   91,   38,  109,   76,
  335,   62,   79,  110,  337,   74,   32,   41,   32,   83,
  110,   65,   84,   32,   27,   32,   28,   81,  165,  119,
  119,  110,  166,  119,  119,  119,  119,  119,  119,  119,
   65,  317,  252,  109,  109,  109,    0,  323,  259,  157,
  158,  119,  119,  119,  119,  119,    0,  119,    0,   85,
   86,   87,   88,    0,    0,   89,  110,  110,  110,    0,
  119,    0,  119,  214,  215,  216,  217,    0,    0,  109,
    0,  109,    0,  122,  110,    0,  119,  122,  122,  122,
  122,  122,  109,  122,    0,    0,    0,   53,   54,   45,
   55,   56,  110,  320,  110,  122,  122,   15,  122,    0,
   57,   58,    0,  109,    0,  110,  119,  159,  111,    0,
    0,   89,  159,  159,   89,  159,    0,  159,    0,    0,
    0,  109,    0,    0,   17,    0,  110,  119,  119,    0,
  110,    0,   53,   54,   45,   55,   56,  119,  119,  119,
  119,    0,    0,  119,  110,   57,   58,  159,  111,    0,
   59,  159,  159,  159,  159,  159,    0,  159,  154,    0,
  110,    0,    0,  209,  111,    0,    0,   15,    0,  159,
  159,    0,  159,    0,    0,   14,  114,    0,   60,    0,
  146,  114,  114,  160,  114,    0,  114,  150,  160,  160,
   15,  160,    3,  160,  111,    0,    0,    0,  146,  230,
  231,  232,  233,  234,  111,  150,    4,    5,    0,    0,
    6,    0,    0,   15,    0,   85,   86,   87,   88,    0,
    7,   89,    8,    9,   10,   11,   12,   13,    0,    0,
    0,  265,   14,    0,  111,   99,    0,    0,    0,   99,
   15,   99,   99,   99,    0,  119,  119,  119,  119,  119,
  119,    0,  119,  119,    0,    0,  291,   99,   99,    0,
   99,  235,  236,  237,  238,  239,  119,  119,   32,    0,
    0,    0,   32,   32,   32,   32,   32,   32,   32,  315,
    0,  119,  119,  119,  119,    0,    0,  119,    0,    0,
   32,   32,   32,   32,    0,    0,    0,    0,    3,  122,
  122,  122,  122,  122,  122,    0,  339,    0,    0,  114,
    0,    0,    4,    5,  114,  114,    6,  114,    0,  114,
  110,  110,    0,    0,    0,    0,    7,    0,    8,    9,
   10,   11,   12,   13,    0,   30,    0,    0,   14,   30,
   30,   30,   30,   30,   30,   30,  268,  269,  270,  271,
  272,  273,    0,    0,  111,  111,    0,   30,   30,   30,
   30,    0,    0,    0,    0,    0,    0,    0,    3,    0,
    0,    0,    0,  159,  159,  159,  159,  159,  159,    0,
    0,    0,    4,    5,    0,    0,    6,    0,    0,    0,
    0,    3,    0,    0,  111,  111,    7,    0,    8,    9,
   10,   11,   12,   13,    0,    4,    5,    0,   14,    6,
    0,    0,    0,    0,    3,    0,    0,    0,    0,    7,
    0,    8,    9,   10,   11,   12,   13,    0,    4,    5,
    0,   14,    6,    0,    0,    0,    0,    0,   63,    0,
    0,    3,    7,   61,    8,    9,   10,   11,   12,   13,
    0,    0,    0,    0,   14,    4,    5,    0,    0,    6,
    0,   99,   99,   99,   99,   99,   99,    0,    0,    7,
    0,    8,    9,   10,   11,   12,   13,    0,   29,    0,
    0,   14,   29,   29,   29,   29,   29,   29,   29,    0,
    0,    0,    0,    0,   32,   32,   32,   32,   32,   32,
   29,   29,   29,   29,   31,    0,    0,    0,   31,   31,
   31,   31,   31,   31,   31,   82,    0,    0,    0,   82,
   82,   82,   82,   82,   62,   82,   31,   31,   31,   31,
    0,    0,    0,    0,    0,  100,    0,   82,   82,  100,
   82,  100,  100,  100,    0,  115,    0,    0,    0,  115,
  115,  115,  115,  115,    0,  115,    0,  100,  100,    0,
  100,   30,   30,   30,   30,   30,   30,  115,  115,   81,
  115,    0,    0,   81,   81,   81,   81,   81,  114,   81,
    0,    0,  127,  114,  114,    0,  114,    0,  114,    0,
    0,   81,   81,    0,   81,    0,    0,    0,    0,    0,
  127,  127,  112,  127,    0,    0,  126,  112,  112,  113,
  112,    0,  112,  129,  113,  113,    0,  113,    0,  113,
    0,    0,  103,    0,  126,  126,  103,  126,  103,  103,
  103,  129,  129,  114,  129,    0,    0,   93,  114,  114,
   93,  114,    0,  114,  103,  103,    0,  103,    0,    0,
    0,    0,    0,    0,    0,   53,   54,    0,   55,   56,
    0,    0,    0,    0,    0,   46,  158,    0,   57,   58,
  147,  158,  158,   71,  158,  156,  158,    0,    0,  143,
  156,  156,    0,  156,    0,  156,    0,    0,  147,    0,
  157,    0,    0,    0,  144,  157,  157,  143,  157,    0,
  157,    0,    0,    0,   29,   29,   29,   29,   29,   29,
  130,  130,  144,    0,  113,    0,    0,    0,  149,  113,
  113,    0,  113,    0,  113,    0,    0,    0,    0,    0,
   31,   31,   31,   31,   31,   31,  149,    0,    0,    0,
   64,   82,   82,   82,   82,   82,   82,    0,    0,    0,
    0,    0,   71,    0,    0,   71,    0,    0,    0,   71,
   71,  100,  100,  100,  100,  100,  100,    0,    0,    0,
    0,  115,  115,  115,  115,  115,  115,  125,  125,    0,
  115,    0,    0,   74,  152,  115,  115,    0,  115,    0,
  115,  155,    0,    0,    0,   81,   81,   81,   81,   81,
   81,    0,  152,    0,  127,  127,  127,  127,  127,  127,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   64,
  133,  133,   64,    0,    0,    0,   64,   64,  126,  126,
  126,  126,  126,  126,  156,  129,  129,  129,  129,  129,
  129,    0,    0,    0,    0,    0,    0,    0,  103,  103,
  103,  103,  103,  103,  222,    0,    0,    0,    0,    0,
    0,    0,   74,    0,    0,   74,    0,  127,  127,   74,
   74,    0,  130,  130,    0,  130,  130,  130,  130,  130,
  130,    0,  130,  241,    0,    0,    0,    0,  229,  229,
  229,  229,  229,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  246,  173,  176,  177,  178,  179,  116,    0,
    0,    0,  155,  116,  116,    0,  116,  158,  116,    0,
  260,   92,  158,  158,   92,  158,    0,  158,    0,    0,
  155,  156,  156,  156,  156,  156,    0,    0,    0,  125,
  125,    0,  125,  125,  125,  125,  125,  125,    0,  125,
    0,    0,    0,    0,  156,  286,  287,  288,   88,  156,
  156,   88,  156,  157,  156,    0,  226,   91,  157,  157,
   91,  157,    0,  157,    0,    0,    0,    0,    0,    0,
    0,    0,  133,  133,    0,  133,  133,  133,  133,  133,
  133,  301,  133,  302,    0,  113,    0,    0,    0,   90,
  113,  113,   90,  113,  312,  113,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  326,    0,    0,    0,  127,
  127,    0,  127,  127,  127,  127,  127,  127,    0,  127,
    0,    0,    0,  336,
};
static const short yycheck[] = {                          2,
   47,   91,   51,   59,   51,   51,   46,  125,  259,   12,
    2,   14,  125,  118,  125,   50,   91,   40,   37,   38,
   40,   12,   41,   42,   43,   38,   45,    2,   47,  125,
   46,   41,   41,  257,   46,   41,  260,   12,  220,   42,
   59,   90,  123,  118,   47,   41,   40,   40,   51,   59,
   59,   12,   41,   59,   57,   58,  260,   46,   40,   62,
   51,   41,  260,   59,   40,   46,   40,   42,   91,  118,
   59,   91,  270,  271,   46,   94,   40,  275,   81,   41,
   61,   94,   85,   86,   87,   88,   89,   90,   91,   61,
   93,   94,   95,   96,   44,   98,   99,   44,   91,   42,
   91,  206,  260,   94,   47,  124,   44,   98,   99,   59,
    0,  124,   59,   44,   61,  118,   91,  299,   59,   94,
  123,   59,    2,   98,   99,  296,  297,   46,   59,   46,
   91,  206,   12,   94,    0,  260,   44,   98,   99,  142,
    2,  125,  260,  146,   61,  148,  328,   46,  123,  260,
   12,   59,   61,   61,   61,   44,  159,  206,   46,   40,
   59,  260,  165,  166,  167,  168,  169,  142,  171,   59,
   59,   51,  257,   61,  123,  260,  211,  212,  257,  269,
  260,  260,   59,  296,  297,   47,  221,  190,   41,   51,
   46,   44,  257,   59,  197,  260,  171,  257,  258,   41,
  296,  297,   44,  206,  253,  208,  255,  263,  264,   46,
  213,   91,   40,   40,   94,  190,  260,  220,   98,   99,
   45,  213,  197,   85,   86,   87,   88,   89,  220,   91,
  270,  271,   94,  208,  260,  125,   98,   99,  213,  123,
  243,  244,  245,  123,  260,  220,  249,   41,  251,  269,
  253,  300,  255,  300,  300,   44,  276,  263,  264,  125,
   93,  123,   12,  257,  258,  284,  285,   93,  243,  244,
  245,  284,  285,   44,  249,   46,  279,   40,  281,   46,
   59,  270,  271,  263,  264,   12,  148,   41,   59,  292,
   61,   40,   42,   41,  297,  298,  299,  300,  270,  271,
   91,  263,  264,   40,  279,   40,  281,  299,   40,  300,
  313,   61,  296,  297,   59,   42,  279,  292,   60,   41,
   62,   93,   40,  298,  299,  328,  195,  330,  331,   93,
   40,   40,  335,  213,  337,   45,  328,   37,  313,   41,
  220,   91,   42,   43,   94,   45,  123,   47,   98,   99,
   41,  213,   41,  328,  260,  330,  331,   41,  220,   40,
  335,   44,  337,   46,   91,   40,  289,   94,   46,  249,
  260,   98,   99,   93,   91,   40,   59,   94,   61,   93,
   45,   98,   99,   41,  274,  275,   41,  249,  278,   41,
   40,   58,  142,   41,  260,   41,  265,  260,  288,  289,
  290,  291,  292,  293,  294,  295,  296,  297,  274,  275,
  300,   41,  278,   41,   41,  142,  126,   58,  298,  299,
  300,  171,  288,   40,  290,  291,  292,  293,  294,  295,
  296,  297,  257,  258,  300,  260,  298,  299,  300,   44,
  190,   46,   41,  123,  171,  270,  271,  197,  328,   41,
  330,   59,  321,    0,   59,  335,   61,  337,  208,   59,
  329,  126,   59,  190,  333,   59,  328,  123,  330,   41,
  197,   59,   41,  335,   61,  337,   61,   59,   61,   37,
   38,  208,   61,   41,   42,   43,   44,   45,   46,   47,
   41,  300,  197,  243,  244,  245,   -1,  305,  206,  270,
  271,   59,   60,   61,   62,   44,   -1,   46,   -1,  280,
  281,  282,  283,   -1,   -1,  286,  243,  244,  245,   -1,
   59,   -1,   61,  265,  266,  267,  268,   -1,   -1,  279,
   -1,  281,   -1,   37,   38,   -1,   94,   41,   42,   43,
   44,   45,  292,   47,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  279,  303,  281,   59,   60,   59,   62,   -1,
  270,  271,   -1,  313,   -1,  292,  124,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,  331,   -1,   -1,  123,   -1,  313,  270,  271,   -1,
   94,   -1,  257,  258,  259,  260,  261,  280,  281,  282,
  283,   -1,   -1,  286,  331,  270,  271,   37,   38,   -1,
  275,   41,   42,   43,   44,   45,   -1,   47,   62,   -1,
  124,   -1,   -1,  125,   94,   -1,   -1,   59,   -1,   59,
   60,   -1,   62,   -1,   -1,  300,   37,   -1,  303,   -1,
   41,   42,   43,   37,   45,   -1,   47,   41,   42,   43,
   59,   45,  260,   47,  124,   -1,   -1,   -1,   59,  160,
  161,  162,  163,  164,   94,   59,  274,  275,   -1,   -1,
  278,   -1,   -1,   59,   -1,  280,  281,  282,  283,   -1,
  288,  286,  290,  291,  292,  293,  294,  295,   -1,   -1,
   -1,  123,  300,   -1,  124,   37,   -1,   -1,   -1,   41,
   59,   43,   44,   45,   -1,  263,  264,  265,  266,  267,
  268,   -1,  270,  271,   -1,   -1,  125,   59,   60,   -1,
   62,  165,  166,  167,  168,  169,  284,  285,   37,   -1,
   -1,   -1,   41,   42,   43,   44,   45,   46,   47,  125,
   -1,  280,  281,  282,  283,   -1,   -1,  286,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,  260,  263,
  264,  265,  266,  267,  268,   -1,  125,   -1,   -1,   37,
   -1,   -1,  274,  275,   42,   43,  278,   45,   -1,   47,
  284,  285,   -1,   -1,   -1,   -1,  288,   -1,  290,  291,
  292,  293,  294,  295,   -1,   37,   -1,   -1,  300,   41,
   42,   43,   44,   45,   46,   47,  214,  215,  216,  217,
  218,  219,   -1,   -1,  284,  285,   -1,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,   -1,
   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,   -1,
   -1,   -1,  274,  275,   -1,   -1,  278,   -1,   -1,   -1,
   -1,  260,   -1,   -1,  284,  285,  288,   -1,  290,  291,
  292,  293,  294,  295,   -1,  274,  275,   -1,  300,  278,
   -1,   -1,   -1,   -1,  260,   -1,   -1,   -1,   -1,  288,
   -1,  290,  291,  292,  293,  294,  295,   -1,  274,  275,
   -1,  300,  278,   -1,   -1,   -1,   -1,   -1,   40,   -1,
   -1,  260,  288,   45,  290,  291,  292,  293,  294,  295,
   -1,   -1,   -1,   -1,  300,  274,  275,   -1,   -1,  278,
   -1,  263,  264,  265,  266,  267,  268,   -1,   -1,  288,
   -1,  290,  291,  292,  293,  294,  295,   -1,   37,   -1,
   -1,  300,   41,   42,   43,   44,   45,   46,   47,   -1,
   -1,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   59,   60,   61,   62,   37,   -1,   -1,   -1,   41,   42,
   43,   44,   45,   46,   47,   37,   -1,   -1,   -1,   41,
   42,   43,   44,   45,  126,   47,   59,   60,   61,   62,
   -1,   -1,   -1,   -1,   -1,   37,   -1,   59,   60,   41,
   62,   43,   44,   45,   -1,   37,   -1,   -1,   -1,   41,
   42,   43,   44,   45,   -1,   47,   -1,   59,   60,   -1,
   62,  263,  264,  265,  266,  267,  268,   59,   60,   37,
   62,   -1,   -1,   41,   42,   43,   44,   45,   37,   47,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   59,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   59,   60,   37,   62,   -1,   -1,   41,   42,   43,   37,
   45,   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   37,   -1,   59,   60,   41,   62,   43,   44,
   45,   59,   60,   37,   62,   -1,   -1,   41,   42,   43,
   44,   45,   -1,   47,   59,   60,   -1,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,   -1,  260,  261,
   -1,   -1,   -1,   -1,   -1,    4,   37,   -1,  270,  271,
   41,   42,   43,   12,   45,   37,   47,   -1,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   59,   -1,
   37,   -1,   -1,   -1,   41,   42,   43,   59,   45,   -1,
   47,   -1,   -1,   -1,  263,  264,  265,  266,  267,  268,
   49,   50,   59,   -1,   37,   -1,   -1,   -1,   41,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  263,  264,  265,  266,  267,  268,   59,   -1,   -1,   -1,
   12,  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,
   -1,   -1,   91,   -1,   -1,   94,   -1,   -1,   -1,   98,
   99,  263,  264,  265,  266,  267,  268,   -1,   -1,   -1,
   -1,  263,  264,  265,  266,  267,  268,   49,   50,   -1,
   37,   -1,   -1,   12,   41,   42,   43,   -1,   45,   -1,
   47,   63,   -1,   -1,   -1,  263,  264,  265,  266,  267,
  268,   -1,   59,   -1,  263,  264,  265,  266,  267,  268,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,
   49,   50,   94,   -1,   -1,   -1,   98,   99,  263,  264,
  265,  266,  267,  268,   63,  263,  264,  265,  266,  267,
  268,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,  264,
  265,  266,  267,  268,  142,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   91,   -1,   -1,   94,   -1,   49,   50,   98,
   99,   -1,  211,  212,   -1,  214,  215,  216,  217,  218,
  219,   -1,  221,  171,   -1,   -1,   -1,   -1,  160,  161,
  162,  163,  164,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  190,   85,   86,   87,   88,   89,   37,   -1,
   -1,   -1,   41,   42,   43,   -1,   45,   37,   47,   -1,
  208,   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   59,  160,  161,  162,  163,  164,   -1,   -1,   -1,  211,
  212,   -1,  214,  215,  216,  217,  218,  219,   -1,  221,
   -1,   -1,   -1,   -1,   37,  243,  244,  245,   41,   42,
   43,   44,   45,   37,   47,   -1,  148,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  211,  212,   -1,  214,  215,  216,  217,  218,
  219,  279,  221,  281,   -1,   37,   -1,   -1,   -1,   41,
   42,   43,   44,   45,  292,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  313,   -1,   -1,   -1,  211,
  212,   -1,  214,  215,  216,  217,  218,  219,   -1,  221,
   -1,   -1,   -1,  331,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
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
"DIV_EQ","LEFT_SHIFT","RIGHT_SHIFT","MOD_EQ","AUTO","IF","ELSE","WHILE","FOR",
"DELETE","BREAK","RETURN","SWITCH","CASE","DEFAULT","CASE_LIST","CLAXX_BODY",
"NEW","CLAXX_MEMBER","CLAXX_FUNC_CALL","XNULL","NONASSOC","IFX","UMINUS",
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
#line 447 "a.y"


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
    yyparse();
	closeLangX();
	fclose(fp);
	
	printf("parse over!\n");
	return 0;
}
#line 877 "y.tab.c"

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
#line 102 "a.y"
	{ /*if($2 != NULL) printf("parentName: %s\n",$2);*/ yyval.node = claxx(yystack.l_mark[-3].sValue , yystack.l_mark[-2].sValue, NULL); }
break;
case 16:
#line 103 "a.y"
	{ /*if($2 != NULL) printf("parentName: %s\n",$2);*/ yyval.node = claxx(yystack.l_mark[-4].sValue , yystack.l_mark[-3].sValue, yystack.l_mark[-1].node); }
break;
case 17:
#line 108 "a.y"
	{ yyval.sValue = NULL; }
break;
case 18:
#line 109 "a.y"
	{ yyval.sValue = yystack.l_mark[0].sValue; }
break;
case 19:
#line 114 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 1, yystack.l_mark[0].node); }
break;
case 20:
#line 115 "a.y"
	{ yyval.node = opr(CLAXX_BODY, 2, yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 21:
#line 119 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 22:
#line 120 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 23:
#line 121 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 24:
#line 126 "a.y"
	{ yyval.node = opr(THIS , 0 ); }
break;
case 25:
#line 127 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 26:
#line 129 "a.y"
	{ yyval.node = opr(THIS, 1 , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 27:
#line 134 "a.y"
	{  yyval.node = opr(THIS,1,yystack.l_mark[0].node); }
break;
case 28:
#line 135 "a.y"
	{  yyval.node = opr(THIS, 1, yystack.l_mark[0].node ); }
break;
case 29:
#line 140 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 30:
#line 141 "a.y"
	{ yyval.node =  opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 31:
#line 142 "a.y"
	{ yyval.node = opr( CLAXX_MEMBER ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-5].sValue), argsNode(yystack.l_mark[-3].args) ) , yystack.l_mark[0].node); }
break;
case 32:
#line 143 "a.y"
	{ yyval.node = opr(CLAXX_MEMBER,2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 33:
#line 148 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL , 2, yystack.l_mark[-5].node, opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) );}
break;
case 34:
#line 149 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL ,2, opr(FUNC_CALL,2, var(yystack.l_mark[-8].sValue), argsNode(yystack.l_mark[-6].args) ) , opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) )); }
break;
case 35:
#line 150 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 36:
#line 151 "a.y"
	{ yyval.node = opr(CLAXX_FUNC_CALL,2,yystack.l_mark[-5].node,opr(FUNC_CALL,2, yystack.l_mark[-3].node, argsNode(yystack.l_mark[-1].args) ) ); }
break;
case 37:
#line 156 "a.y"
	{  yyval.node = NULL; }
break;
case 38:
#line 157 "a.y"
	{ yyval.node = NULL; }
break;
case 39:
#line 158 "a.y"
	{ yyval.node = NULL; }
break;
case 40:
#line 163 "a.y"
	{ yyval.node = func(yystack.l_mark[-5].sValue,yystack.l_mark[-3].params,yystack.l_mark[-1].node);}
break;
case 41:
#line 167 "a.y"
	{ yyval.params = NULL; }
break;
case 42:
#line 168 "a.y"
	{ yyval.params = yystack.l_mark[-1].params; }
break;
case 43:
#line 172 "a.y"
	{ yyval.params = params(NULL, yystack.l_mark[0].sValue); }
break;
case 44:
#line 173 "a.y"
	{ params(yystack.l_mark[-2].params,yystack.l_mark[0].sValue); }
break;
case 45:
#line 174 "a.y"
	{ yyval.params = NULL; }
break;
case 46:
#line 178 "a.y"
	{ yyval.node = opr(';',2,yystack.l_mark[-1].node, yystack.l_mark[0].node); }
break;
case 47:
#line 179 "a.y"
	{ yyval.node = NULL; }
break;
case 48:
#line 184 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, yystack.l_mark[-1].node ); }
break;
case 49:
#line 185 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 50:
#line 186 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,yystack.l_mark[-2].intValue,NULL) ); }
break;
case 51:
#line 187 "a.y"
	{ yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,yystack.l_mark[-3].intValue,NULL),yystack.l_mark[0].node); }
break;
case 52:
#line 188 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 1, arrayNode(yystack.l_mark[-4].sValue,-1,var(yystack.l_mark[-2].sValue)) ); }
break;
case 53:
#line 189 "a.y"
	{  yyval.node = opr(VAR_DECLAR , 2, arrayNode(yystack.l_mark[-5].sValue,-1,var(yystack.l_mark[-3].sValue)),yystack.l_mark[0].node); }
break;
case 54:
#line 194 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 55:
#line 195 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 56:
#line 200 "a.y"
	{ yyval.node = opr(IF ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 57:
#line 201 "a.y"
	{ yyval.node = opr(IF ,3,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node) ; }
break;
case 58:
#line 202 "a.y"
	{ yyval.node = opr(SWITCH, 2 , yystack.l_mark[-4].node,yystack.l_mark[-1].node); }
break;
case 59:
#line 206 "a.y"
	{ yyval.node = opr(CASE_LIST , 1 ,yystack.l_mark[0].node ); }
break;
case 60:
#line 207 "a.y"
	{ yyval.node = opr(CASE_LIST , 2 ,yystack.l_mark[-1].node, yystack.l_mark[0].node ); }
break;
case 61:
#line 211 "a.y"
	{ yyval.node = opr(CASE, 2 , yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 62:
#line 212 "a.y"
	{ yyval.node = opr(DEFAULT , 1, yystack.l_mark[0].node); }
break;
case 63:
#line 216 "a.y"
	{ yyval.node = opr(WHILE , 2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 64:
#line 217 "a.y"
	{ yyval.node = opr(FOR,4,yystack.l_mark[-6].node,yystack.l_mark[-4].node,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 65:
#line 222 "a.y"
	{ yyval.node = NULL ; }
break;
case 66:
#line 223 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 67:
#line 224 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 68:
#line 225 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 69:
#line 230 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 70:
#line 231 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 71:
#line 232 "a.y"
	{ yyval.node = opr(DELETE, 1 ,yystack.l_mark[-1].sValue ); }
break;
case 72:
#line 233 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 234 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 74:
#line 235 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 75:
#line 236 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 76:
#line 242 "a.y"
	{ yyval.node = opr(RESTRICT,0);}
break;
case 77:
#line 243 "a.y"
	{ yyval.node = opr(RESTRICT,1,yystack.l_mark[0].node); }
break;
case 78:
#line 247 "a.y"
	{ yyval.node = opr(BREAK, 0); }
break;
case 79:
#line 248 "a.y"
	{ yyval.node = opr(RETURN , 0); }
break;
case 80:
#line 249 "a.y"
	{ yyval.node = opr(RETURN , 1 ,yystack.l_mark[0].node);}
break;
case 81:
#line 254 "a.y"
	{ /*$$ = call($1,$3 );*/  yyval.node = opr(FUNC_CALL,2, var(yystack.l_mark[-3].sValue), argsNode(yystack.l_mark[-1].args) ); }
break;
case 82:
#line 255 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 83:
#line 259 "a.y"
	{ yyval.args = NULL; }
break;
case 84:
#line 260 "a.y"
	{ yyval.args = yystack.l_mark[0].args; }
break;
case 85:
#line 264 "a.y"
	{ yyval.args = xArgs(NULL, yystack.l_mark[0].node); }
break;
case 86:
#line 265 "a.y"
	{ yyval.args = xArgs(yystack.l_mark[-2].args, yystack.l_mark[0].node); }
break;
case 87:
#line 269 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 88:
#line 270 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 89:
#line 271 "a.y"
	{ /*printf("IDENTIFIER $1= %s\n" , $1);*/ yyval.node = yystack.l_mark[0].node; }
break;
case 90:
#line 272 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 273 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 92:
#line 274 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 275 "a.y"
	{ yyval.node = yystack.l_mark[0].node;}
break;
case 94:
#line 279 "a.y"
	{ yyval.node = yystack.l_mark[-1].node;}
break;
case 95:
#line 280 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 96:
#line 286 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 97:
#line 287 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 98:
#line 292 "a.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 99:
#line 298 "a.y"
	{ yyval.node = opr('+',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 100:
#line 299 "a.y"
	{ yyval.node = opr('-',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 101:
#line 300 "a.y"
	{ yyval.node = opr('*',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 102:
#line 301 "a.y"
	{ yyval.node = opr('/',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 103:
#line 302 "a.y"
	{ yyval.node = opr('%',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 104:
#line 303 "a.y"
	{ yyval.node = opr('&',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 105:
#line 304 "a.y"
	{ yyval.node = opr('|',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 106:
#line 305 "a.y"
	{ yyval.node = opr('^',2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 107:
#line 306 "a.y"
	{ /* printf("get a ~ opr.\n"); */ yyval.node = opr('~',1,yystack.l_mark[0].node); }
break;
case 108:
#line 307 "a.y"
	{ yyval.node = opr(LEFT_SHIFT,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 109:
#line 308 "a.y"
	{ yyval.node = opr(RIGHT_SHIFT,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 110:
#line 313 "a.y"
	{ yyval.node = xint(yystack.l_mark[0].intValue); }
break;
case 111:
#line 314 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 112:
#line 319 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 113:
#line 320 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 114:
#line 321 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 115:
#line 322 "a.y"
	{ yyval.node = yystack.l_mark[0].node ; }
break;
case 116:
#line 323 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 117:
#line 324 "a.y"
	{ yyval.node = yystack.l_mark[-1].node ; }
break;
case 118:
#line 329 "a.y"
	{ yyval.node = opr(NEW ,2, yystack.l_mark[-3].node , argsNode(yystack.l_mark[-1].args) ); }
break;
case 119:
#line 333 "a.y"
	{ yyval.node = var(yystack.l_mark[0].sValue); }
break;
case 120:
#line 337 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 121:
#line 341 "a.y"
	{ yyval.node = number(yystack.l_mark[0].iValue); }
break;
case 122:
#line 342 "a.y"
	{ yyval.node = number(yystack.l_mark[0].intValue); }
break;
case 123:
#line 346 "a.y"
	{ yyval.node = opr(UMINUS, 1, yystack.l_mark[0].node ); }
break;
case 124:
#line 350 "a.y"
	{ yyval.node = string(yystack.l_mark[0].sValue); }
break;
case 125:
#line 354 "a.y"
	{ yyval.node = xnull();}
break;
case 126:
#line 359 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 127:
#line 360 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 128:
#line 361 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 129:
#line 362 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 130:
#line 367 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 131:
#line 368 "a.y"
	{ yyval.node = opr('>',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 132:
#line 369 "a.y"
	{ yyval.node = opr('<',2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 133:
#line 370 "a.y"
	{ yyval.node = opr( LE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 134:
#line 371 "a.y"
	{ yyval.node = opr( GE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 135:
#line 372 "a.y"
	{ yyval.node = opr( EQ_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 136:
#line 373 "a.y"
	{ yyval.node = opr( NE_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 137:
#line 374 "a.y"
	{ yyval.node = opr(AND_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 138:
#line 375 "a.y"
	{ yyval.node = opr(OR_OP,2,yystack.l_mark[-2].node,yystack.l_mark[0].node); }
break;
case 139:
#line 380 "a.y"
	{ yyval.node = opr(INC_OP,1, yystack.l_mark[0].node ); }
break;
case 140:
#line 381 "a.y"
	{ yyval.node = opr(DEC_OP,1, yystack.l_mark[0].node ); }
break;
case 141:
#line 382 "a.y"
	{ yyval.node = sopr(INC_OP,1, yystack.l_mark[-1].node ); }
break;
case 142:
#line 383 "a.y"
	{ yyval.node = sopr(DEC_OP,1, yystack.l_mark[-1].node ); }
break;
case 143:
#line 388 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 144:
#line 389 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 145:
#line 390 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 146:
#line 391 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 147:
#line 392 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 148:
#line 393 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 149:
#line 394 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 150:
#line 395 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 151:
#line 396 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 152:
#line 397 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 153:
#line 398 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 154:
#line 399 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 155:
#line 400 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 156:
#line 405 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 157:
#line 406 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 158:
#line 407 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 159:
#line 408 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 160:
#line 409 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 161:
#line 414 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 162:
#line 415 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node, yystack.l_mark[0].node ); }
break;
case 163:
#line 419 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 164:
#line 420 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node ); }
break;
case 165:
#line 425 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, yystack.l_mark[-1].intValue, NULL); }
break;
case 166:
#line 426 "a.y"
	{ yyval.node = arr(yystack.l_mark[-3].sValue, -1, var(yystack.l_mark[-1].sValue)) ; }
break;
case 167:
#line 432 "a.y"
	{ yyval.node = opr('=',2, yystack.l_mark[-2].node,yystack.l_mark[0].node );  }
break;
case 168:
#line 437 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 169:
#line 438 "a.y"
	{ yyval.node = yystack.l_mark[0].node ;}
break;
case 170:
#line 439 "a.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 171:
#line 440 "a.y"
	{ yyval.node = opr(ADD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 172:
#line 441 "a.y"
	{ yyval.node = opr(SUB_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 173:
#line 442 "a.y"
	{ yyval.node = opr(MUL_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 174:
#line 443 "a.y"
	{ yyval.node = opr(DIV_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
case 175:
#line 444 "a.y"
	{ yyval.node = opr(MOD_EQ,2,yystack.l_mark[-2].node,yystack.l_mark[0].node);}
break;
#line 1775 "y.tab.c"
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
