/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 71 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 12/27/16
* Time: 01:14:42
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2016Äê11ÔÂ14ÈÕ
****************************************************************************/
#include<stdio.h>
#include<string.h>
#include "myparser.h"
#include "treenode.h"
#include "util.h"

extern int lineno = 1;

extern TreeNode* yylval;


#line 59 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 35 ".\\mylexer.l"
/* skip whitespace */
#line 180 "mylexer.c"
		}
		break;
	case 2:
		{
#line 37 ".\\mylexer.l"

#line 187 "mylexer.c"
		}
		break;
	case 3:
		{
#line 38 ".\\mylexer.l"
lineno++;
#line 194 "mylexer.c"
		}
		break;
	case 4:
		{
#line 39 ".\\mylexer.l"
return SEMICOLON;
#line 201 "mylexer.c"
		}
		break;
	case 5:
		{
#line 40 ".\\mylexer.l"
return COMMA;
#line 208 "mylexer.c"
		}
		break;
	case 6:
		{
#line 41 ".\\mylexer.l"
return QUO;
#line 215 "mylexer.c"
		}
		break;
	case 7:
		{
#line 42 ".\\mylexer.l"
return LPACE;
#line 222 "mylexer.c"
		}
		break;
	case 8:
		{
#line 43 ".\\mylexer.l"
return RPACE;
#line 229 "mylexer.c"
		}
		break;
	case 9:
		{
#line 44 ".\\mylexer.l"
return LBRACE;
#line 236 "mylexer.c"
		}
		break;
	case 10:
		{
#line 45 ".\\mylexer.l"
return RBRACE;
#line 243 "mylexer.c"
		}
		break;
	case 11:
		{
#line 46 ".\\mylexer.l"
return ADD;
#line 250 "mylexer.c"
		}
		break;
	case 12:
		{
#line 47 ".\\mylexer.l"
return SUB;
#line 257 "mylexer.c"
		}
		break;
	case 13:
		{
#line 48 ".\\mylexer.l"
return MUL;
#line 264 "mylexer.c"
		}
		break;
	case 14:
		{
#line 49 ".\\mylexer.l"
return DIV;
#line 271 "mylexer.c"
		}
		break;
	case 15:
		{
#line 50 ".\\mylexer.l"
return MOD;
#line 278 "mylexer.c"
		}
		break;
	case 16:
		{
#line 51 ".\\mylexer.l"
return OR;
#line 285 "mylexer.c"
		}
		break;
	case 17:
		{
#line 52 ".\\mylexer.l"
return AND;
#line 292 "mylexer.c"
		}
		break;
	case 18:
		{
#line 53 ".\\mylexer.l"
return EQ;
#line 299 "mylexer.c"
		}
		break;
	case 19:
		{
#line 54 ".\\mylexer.l"
return GE;
#line 306 "mylexer.c"
		}
		break;
	case 20:
		{
#line 55 ".\\mylexer.l"
return LE;
#line 313 "mylexer.c"
		}
		break;
	case 21:
		{
#line 56 ".\\mylexer.l"
return GT;
#line 320 "mylexer.c"
		}
		break;
	case 22:
		{
#line 57 ".\\mylexer.l"
return LT;
#line 327 "mylexer.c"
		}
		break;
	case 23:
		{
#line 58 ".\\mylexer.l"
return GREATER;
#line 334 "mylexer.c"
		}
		break;
	case 24:
		{
#line 59 ".\\mylexer.l"
return LESS;
#line 341 "mylexer.c"
		}
		break;
	case 25:
		{
#line 60 ".\\mylexer.l"
return NE;
#line 348 "mylexer.c"
		}
		break;
	case 26:
		{
#line 61 ".\\mylexer.l"
return ASSIGN;
#line 355 "mylexer.c"
		}
		break;
	case 27:
		{
#line 62 ".\\mylexer.l"
return IF;
#line 362 "mylexer.c"
		}
		break;
	case 28:
		{
#line 63 ".\\mylexer.l"
return ELSE;
#line 369 "mylexer.c"
		}
		break;
	case 29:
		{
#line 64 ".\\mylexer.l"
return WHILE;
#line 376 "mylexer.c"
		}
		break;
	case 30:
		{
#line 65 ".\\mylexer.l"
return FOR;
#line 383 "mylexer.c"
		}
		break;
	case 31:
		{
#line 66 ".\\mylexer.l"
return INPUT;
#line 390 "mylexer.c"
		}
		break;
	case 32:
		{
#line 67 ".\\mylexer.l"
return PRINT;
#line 397 "mylexer.c"
		}
		break;
	case 33:
		{
#line 68 ".\\mylexer.l"
yylval = MakeTypeNode("int");yylval->lineno = lineno;yylval->type = "Integer";return INT;
#line 404 "mylexer.c"
		}
		break;
	case 34:
		{
#line 69 ".\\mylexer.l"
yylval = MakeTypeNode("char");yylval->lineno = lineno;yylval->type = "Character";return CHAR;
#line 411 "mylexer.c"
		}
		break;
	case 35:
		{
#line 70 ".\\mylexer.l"
yylval = MakeTypeNode("bool");yylval->lineno = lineno;yylval->type = "Boolean";return BOOL;
#line 418 "mylexer.c"
		}
		break;
	case 36:
		{
#line 71 ".\\mylexer.l"
yylval = MakeNumberNode(yytext);yylval->lineno = lineno;yylval->type = "Integer";return NUMBER;
#line 425 "mylexer.c"
		}
		break;
	case 37:
		{
#line 72 ".\\mylexer.l"
yylval = MakeIdNode(yytext);yylval->lineno = lineno;return ID;
#line 432 "mylexer.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 193;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 4, 1 },
	{ 3, 3 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 16, 16 },
	{ 45, 26 },
	{ 51, 61 },
	{ 34, 15 },
	{ 36, 18 },
	{ 37, 18 },
	{ 56, 46 },
	{ 0, 61 },
	{ 35, 15 },
	{ 46, 26 },
	{ 57, 46 },
	{ 3, 1 },
	{ 5, 1 },
	{ 3, 3 },
	{ 39, 20 },
	{ 40, 20 },
	{ 6, 1 },
	{ 7, 1 },
	{ 8, 1 },
	{ 9, 1 },
	{ 10, 1 },
	{ 11, 1 },
	{ 12, 1 },
	{ 13, 1 },
	{ 14, 1 },
	{ 42, 23 },
	{ 15, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 16, 1 },
	{ 43, 24 },
	{ 17, 1 },
	{ 18, 1 },
	{ 19, 1 },
	{ 20, 1 },
	{ 44, 25 },
	{ 32, 5 },
	{ 47, 27 },
	{ 48, 28 },
	{ 49, 30 },
	{ 51, 34 },
	{ 0, 35 },
	{ 52, 41 },
	{ 53, 42 },
	{ 54, 43 },
	{ 55, 44 },
	{ 38, 19 },
	{ 58, 47 },
	{ 59, 48 },
	{ 60, 50 },
	{ 62, 51 },
	{ 63, 52 },
	{ 64, 53 },
	{ 65, 54 },
	{ 66, 56 },
	{ 67, 58 },
	{ 68, 59 },
	{ 62, 60 },
	{ 33, 7 },
	{ 69, 66 },
	{ 70, 67 },
	{ 71, 68 },
	{ 41, 22 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 22, 1 },
	{ 23, 1 },
	{ 0, 0 },
	{ 24, 1 },
	{ 25, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 26, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 27, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 28, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 29, 1 },
	{ 30, 1 },
	{ 31, 1 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 21, 71 },
	{ 0, 0 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 },
	{ 21, 71 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 71, -8, 0 },
	{ 1, 0, 0 },
	{ 0, -6, 1 },
	{ 0, 0, 3 },
	{ 0, -5, 0 },
	{ 0, 0, 15 },
	{ 0, 40, 0 },
	{ 0, 0, 6 },
	{ 0, 0, 7 },
	{ 0, 0, 8 },
	{ 0, 0, 13 },
	{ 0, 0, 11 },
	{ 0, 0, 5 },
	{ 0, 0, 12 },
	{ 0, -26, 14 },
	{ 0, -44, 36 },
	{ 0, 0, 4 },
	{ 0, -43, 22 },
	{ 0, 5, 26 },
	{ 0, -34, 21 },
	{ 71, 0, 37 },
	{ 71, -29, 37 },
	{ 71, -66, 37 },
	{ 71, -58, 37 },
	{ 71, -56, 37 },
	{ 71, -88, 37 },
	{ 71, -57, 37 },
	{ 71, -46, 37 },
	{ 0, 0, 9 },
	{ 0, -65, 0 },
	{ 0, 0, 10 },
	{ 0, 0, 25 },
	{ 0, 0, 17 },
	{ -50, 18, 0 },
	{ -35, 51, 2 },
	{ 0, 0, 24 },
	{ 0, 0, 20 },
	{ 0, 0, 18 },
	{ 0, 0, 19 },
	{ 0, 0, 23 },
	{ 71, -49, 37 },
	{ 71, -34, 37 },
	{ 71, -51, 37 },
	{ 71, -49, 37 },
	{ 71, 0, 27 },
	{ 71, -93, 37 },
	{ 71, -38, 37 },
	{ 71, -37, 37 },
	{ 0, 0, 16 },
	{ -50, 27, 0 },
	{ 61, 23, 0 },
	{ 71, -37, 37 },
	{ 71, -42, 37 },
	{ 71, -28, 37 },
	{ 71, 0, 30 },
	{ 71, -43, 37 },
	{ 71, 0, 33 },
	{ 71, -35, 37 },
	{ 71, -32, 37 },
	{ 0, 30, 0 },
	{ -61, -27, 0 },
	{ 0, 0, 2 },
	{ 71, 0, 35 },
	{ 71, 0, 34 },
	{ 71, 0, 28 },
	{ 71, -37, 37 },
	{ 71, -36, 37 },
	{ 71, -20, 37 },
	{ 71, 0, 31 },
	{ 71, 0, 32 },
	{ 0, 70, 29 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 73 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section
