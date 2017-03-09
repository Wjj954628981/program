/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 13 of your 30 day trial period.
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
* Date: 10/30/16
* Time: 16:08:00
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

Date: 2016Äê10ÔÂ30ÈÕ
****************************************************************************/
enum{
	LOOKUP = 0,
	VERB,
	ADJ,
	ADV,
	NOUN,
	PREP,
	PRON,
	CONJ
};

int state;

int add_word(int type, char *word);
int lookup_word(char *word);

#include<stdio.h>
#include<string.h>

#line 67 "mylexer.c"
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
#line 37 ".\\mylexer.l"
 state = LOOKUP; 
#line 188 "mylexer.c"
		}
		break;
	case 2:
		{
#line 39 ".\\mylexer.l"
 state = VERB; 
#line 195 "mylexer.c"
		}
		break;
	case 3:
		{
#line 40 ".\\mylexer.l"
 state = ADJ; 
#line 202 "mylexer.c"
		}
		break;
	case 4:
		{
#line 41 ".\\mylexer.l"
 state = ADV; 
#line 209 "mylexer.c"
		}
		break;
	case 5:
		{
#line 42 ".\\mylexer.l"
 state = NOUN; 
#line 216 "mylexer.c"
		}
		break;
	case 6:
		{
#line 43 ".\\mylexer.l"
 state = PREP; 
#line 223 "mylexer.c"
		}
		break;
	case 7:
		{
#line 44 ".\\mylexer.l"
 state = PRON; 
#line 230 "mylexer.c"
		}
		break;
	case 8:
		{
#line 45 ".\\mylexer.l"
 state = CONJ; 
#line 237 "mylexer.c"
		}
		break;
	case 9:
		{
#line 47 ".\\mylexer.l"

			if(state != LOOKUP){
				add_word(state, yytext);
			}else{
				switch(lookup_word(yytext)){
					case VERB: printf("%s: verb\n", yytext); break;
					case ADJ: printf("%s: adjective\n", yytext); break;
					case ADV: printf("%s: adverb\n", yytext); break;
					case NOUN: printf("%s: noun\n", yytext); break;
					case PREP: printf("%s: preposition\n", yytext); break;
					case PRON: printf("%s: pronoun\n", yytext); break;
					case CONJ: printf("%s: conjunction\n", yytext); break;
					default:
						printf("%s: don't recognize\n", yytext);
						break;
				}
			}
		  
#line 261 "mylexer.c"
		}
		break;
#line 65 ".\\mylexer.l"
					
#line 266 "mylexer.c"
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

int YYNEAR YYDCDECL yytransitionmax = 81;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 12, 7 },
	{ 13, 8 },
	{ 14, 9 },
	{ 3, 1 },
	{ 17, 11 },
	{ 18, 12 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 4, 26 },
	{ 5, 2 },
	{ 19, 13 },
	{ 6, 2 },
	{ 10, 5 },
	{ 15, 10 },
	{ 21, 14 },
	{ 22, 17 },
	{ 23, 18 },
	{ 24, 19 },
	{ 25, 20 },
	{ 26, 21 },
	{ 20, 13 },
	{ 11, 6 },
	{ 7, 2 },
	{ 0, 0 },
	{ 8, 2 },
	{ 16, 10 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 9, 2 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 26, 20, 0 },
	{ 1, -38, 0 },
	{ 0, 0, 1 },
	{ 26, 0, 9 },
	{ 26, -38, 9 },
	{ 26, -40, 9 },
	{ 26, -84, 9 },
	{ 26, -86, 9 },
	{ 26, -72, 9 },
	{ 26, -43, 9 },
	{ 26, -79, 9 },
	{ 26, -85, 9 },
	{ 26, -41, 9 },
	{ 26, -50, 9 },
	{ 26, 0, 3 },
	{ 26, 0, 4 },
	{ 26, -41, 9 },
	{ 26, -44, 9 },
	{ 26, -45, 9 },
	{ 26, -42, 9 },
	{ 26, -29, 9 },
	{ 26, 0, 8 },
	{ 26, 0, 5 },
	{ 26, 0, 6 },
	{ 26, 0, 7 },
	{ 0, -64, 2 }
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
	0
};

#line 68 ".\\mylexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section

main(){
	yylex();
}

struct word{
	char *word_name;
	int word_type;
	struct word *next;
};

struct word *word_list;

extern void *malloc();

int
add_word(int type, char *word){
	struct word *wp;
	
	if(lookup_word(word) != LOOKUP){
		printf("!!!warning : word %s is already defined \n", word);
		return 0;
	}
	
	wp = (struct word *)malloc(sizeof(struct word));
	
	wp->next = word_list;
	
	wp->word_name = (char *)malloc(strlen(word)+1);
	strcpy(wp->word_name, word);
	wp->word_type = type;
	word_list = wp;
	return 1;
}

int
lookup_word(char *word){
	struct word *wp = word_list;
	
	for(;wp;wp = wp->next){
		if(strcmp(wp->word_name, word) == 0)
			return wp->word_type;
	}
	
	return LOOKUP;
}
