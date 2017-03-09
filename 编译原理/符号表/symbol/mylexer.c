/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 22 of your 30 day trial period.
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
* Date: 11/08/16
* Time: 18:46:30
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

Date: 2016Äê11ÔÂ7ÈÕ
****************************************************************************/
#include<stdio.h>
#include<string.h>

int num = 0;

struct symbol{
	char *symbol_name;
	int symbol_value;
	struct symbol *next;
};

struct symbol *symbol_list;

extern void *malloc();

add_symbol(char *symbol){

	struct symbol *al;
	
	al = (struct symbol *)malloc(sizeof(struct symbol));
	
	al->next = symbol_list;
	
	al->symbol_name = (char *)malloc(strlen(symbol)+1);
	strcpy(al->symbol_name, symbol);
	
	al->symbol_value = num;
	
	num++;
	
	symbol_list = al;
	
}

int
lookup_symbol(char *symbol_name){

	struct symbol *al = symbol_list;
	
	for(;al;al = al->next){
		if(strcmp(al->symbol_name, symbol_name) == 0)
			return al->symbol_value;
	}
	
	return -1;
	
}

#line 96 "mylexer.c"
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
#line 86 ".\\mylexer.l"

#line 217 "mylexer.c"
		}
		break;
	case 2:
		{
#line 87 ".\\mylexer.l"
printf("SEMICOLON   %s\n",yytext);
#line 224 "mylexer.c"
		}
		break;
	case 3:
		{
#line 88 ".\\mylexer.l"
printf("LPACE    %s\n",yytext);
#line 231 "mylexer.c"
		}
		break;
	case 4:
		{
#line 89 ".\\mylexer.l"
printf("RPACE    %s\n",yytext);
#line 238 "mylexer.c"
		}
		break;
	case 5:
		{
#line 90 ".\\mylexer.l"
printf("LBRACE   %s\n",yytext);
#line 245 "mylexer.c"
		}
		break;
	case 6:
		{
#line 91 ".\\mylexer.l"
printf("RBRACE   %s\n",yytext);
#line 252 "mylexer.c"
		}
		break;
	case 7:
		{
#line 92 ".\\mylexer.l"
printf("ADD      %s\n",yytext);
#line 259 "mylexer.c"
		}
		break;
	case 8:
		{
#line 93 ".\\mylexer.l"
printf("SUB      %s\n",yytext);
#line 266 "mylexer.c"
		}
		break;
	case 9:
		{
#line 94 ".\\mylexer.l"
printf("MUL      %s\n",yytext);
#line 273 "mylexer.c"
		}
		break;
	case 10:
		{
#line 95 ".\\mylexer.l"
printf("DIV      %s\n",yytext);
#line 280 "mylexer.c"
		}
		break;
	case 11:
		{
#line 96 ".\\mylexer.l"
printf("EQ       %s\n",yytext);
#line 287 "mylexer.c"
		}
		break;
	case 12:
		{
#line 97 ".\\mylexer.l"
printf("IF       %s\n",yytext);
#line 294 "mylexer.c"
		}
		break;
	case 13:
		{
#line 98 ".\\mylexer.l"
printf("INT      %s\n",yytext);
#line 301 "mylexer.c"
		}
		break;
	case 14:
		{
#line 99 ".\\mylexer.l"
printf("ASSIGN   %s\n",yytext);
#line 308 "mylexer.c"
		}
		break;
	case 15:
		{
#line 100 ".\\mylexer.l"
printf("NUMBER   %s\n",yytext);
#line 315 "mylexer.c"
		}
		break;
	case 16:
		{
#line 101 ".\\mylexer.l"
if(lookup_symbol(yytext)==-1){add_symbol(yytext);}printf("ID       %s   %d\n",yytext,lookup_symbol(yytext));
#line 322 "mylexer.c"
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

int YYNEAR YYDCDECL yytransitionmax = 176;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 10, 10 },
	{ 18, 14 },
	{ 3, 3 },
	{ 20, 19 },
	{ 17, 12 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 19, 14 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 4, 1 },
	{ 5, 1 },
	{ 6, 1 },
	{ 7, 1 },
	{ 0, 0 },
	{ 8, 1 },
	{ 0, 0 },
	{ 9, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 10, 1 },
	{ 0, 0 },
	{ 11, 1 },
	{ 0, 0 },
	{ 12, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 14, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 15, 1 },
	{ 0, 0 },
	{ 16, 1 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 13, 20 },
	{ 0, 0 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 },
	{ 13, 20 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 20, -8, 0 },
	{ 1, 0, 0 },
	{ 0, 4, 1 },
	{ 0, 0, 3 },
	{ 0, 0, 4 },
	{ 0, 0, 9 },
	{ 0, 0, 7 },
	{ 0, 0, 8 },
	{ 0, 0, 10 },
	{ 0, -46, 15 },
	{ 0, 0, 2 },
	{ 0, -46, 14 },
	{ 20, 0, 16 },
	{ 20, -90, 16 },
	{ 0, 0, 5 },
	{ 0, 0, 6 },
	{ 0, 0, 11 },
	{ 20, 0, 12 },
	{ 20, -102, 16 },
	{ 0, 53, 13 }
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
	0
};

#line 103 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

main(int argc, char *argv[])
{	++argv, --argc;
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else  yyin = stdin;
	yylex();
}




