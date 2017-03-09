/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 7 of your 30 day trial period.
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
* myparser.c
* C source file generated from myparser.y.
* 
* Date: 10/24/16
* Time: 19:59:03
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\myparser.y"

/************************************************************
calc.y
Simple calculator. Features floating point arithmetic using
the addition, subtraction, multiplication and divide
operators, and unary minus. Expressions can be grouped
using parentheses, and simple error recovery is supported.
************************************************************/

#include <ctype.h>
#include <stdio.h>

#line 53 "myparser.c"
/* repeated because of possible precompiled header */
#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\myparser.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yystack_t YYNEAR yystack[(YYSTACK_SIZE)];
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = yystack;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = yystack;
#else
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = NULL;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yyattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = yyattributestack;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = yyattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = (char YYFAR *) yyattributestack;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = (char YYFAR *) yyattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yysstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yyval;
YYSTYPE YYNEAR yylval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yyvalptr = &yyval;
void YYFAR *YYNEAR YYDCDECL yylvalptr = &yylval;
#else
char YYFAR *YYNEAR YYDCDECL yyvalptr = (char *) &yyval;
char YYFAR *YYNEAR YYDCDECL yylvalptr = (char *) &yylval;
#endif

size_t YYNEAR YYDCDECL yyattribute_size = sizeof(YYSTYPE);

/* yyattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yyattribute1(int index)
#else
static YYSTYPE YYFAR *yyattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR *) yyattributestackptr)[yytop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yyinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yyinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yyparseraction(int action)
#else
void YYCDECL yyparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 26 ".\\myparser.y"
 printf("%g\n", yyattribute(2 - 3)); 
#line 179 "myparser.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 31 ".\\myparser.y"
 yyval = yyattribute(1 - 3) + yyattribute(3 - 3); 
#line 192 "myparser.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 32 ".\\myparser.y"
 yyval = yyattribute(1 - 3) - yyattribute(3 - 3); 
#line 205 "myparser.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 33 ".\\myparser.y"
 yyval = yyattribute(1 - 3) * yyattribute(3 - 3); 
#line 218 "myparser.c"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 34 ".\\myparser.y"
 yyval = yyattribute(1 - 3) / yyattribute(3 - 3); 
#line 231 "myparser.c"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 35 ".\\myparser.y"
 yyval = yyattribute(2 - 3); 
#line 244 "myparser.c"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 36 ".\\myparser.y"
 yyval = -yyattribute(2 - 2); 
#line 257 "myparser.c"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 39 ".\\myparser.y"
 yyval = 0.0; 
#line 270 "myparser.c"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 40 ".\\myparser.y"
 yyval = 1.0; 
#line 283 "myparser.c"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 41 ".\\myparser.y"
 yyval = 2.0; 
#line 296 "myparser.c"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 42 ".\\myparser.y"
 yyval = 3.0; 
#line 309 "myparser.c"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 43 ".\\myparser.y"
 yyval = 4.0; 
#line 322 "myparser.c"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 44 ".\\myparser.y"
 yyval = 5.0; 
#line 335 "myparser.c"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 45 ".\\myparser.y"
 yyval = 6.0; 
#line 348 "myparser.c"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 46 ".\\myparser.y"
 yyval = 7.0; 
#line 361 "myparser.c"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 47 ".\\myparser.y"
 yyval = 8.0; 
#line 374 "myparser.c"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 48 ".\\myparser.y"
 yyval = 9.0; 
#line 387 "myparser.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yysymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yysymbol[] = {
	{ "$end", 0 },
	{ "\'\\n\'", 10 },
	{ "\'(\'", 40 },
	{ "\')\'", 41 },
	{ "\'*\'", 42 },
	{ "\'+\'", 43 },
	{ "\'-\'", 45 },
	{ "\'/\'", 47 },
	{ "\'0\'", 48 },
	{ "\'1\'", 49 },
	{ "\'2\'", 50 },
	{ "\'3\'", 51 },
	{ "\'4\'", 52 },
	{ "\'5\'", 53 },
	{ "\'6\'", 54 },
	{ "\'7\'", 55 },
	{ "\'8\'", 56 },
	{ "\'9\'", 57 },
	{ "error", 256 },
	{ "UMINUS", 257 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: lines",
	"lines: lines expr \'\\n\'",
	"lines: lines \'\\n\'",
	"lines:",
	"expr: expr \'+\' expr",
	"expr: expr \'-\' expr",
	"expr: expr \'*\' expr",
	"expr: expr \'/\' expr",
	"expr: \'(\' expr \')\'",
	"expr: \'-\' expr",
	"expr: NUMBER",
	"NUMBER: \'0\'",
	"NUMBER: \'1\'",
	"NUMBER: \'2\'",
	"NUMBER: \'3\'",
	"NUMBER: \'4\'",
	"NUMBER: \'5\'",
	"NUMBER: \'6\'",
	"NUMBER: \'7\'",
	"NUMBER: \'8\'",
	"NUMBER: \'9\'"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 3, 0 },
	{ 1, 2, -1 },
	{ 1, 0, -1 },
	{ 2, 3, 1 },
	{ 2, 3, 2 },
	{ 2, 3, 3 },
	{ 2, 3, 4 },
	{ 2, 3, 5 },
	{ 2, 2, 6 },
	{ 2, 1, -1 },
	{ 3, 1, 7 },
	{ 3, 1, 8 },
	{ 3, 1, 9 },
	{ 3, 1, 10 },
	{ 3, 1, 11 },
	{ 3, 1, 12 },
	{ 3, 1, 13 },
	{ 3, 1, 14 },
	{ 3, 1, 15 },
	{ 3, 1, 16 }
};

int YYNEAR YYDCDECL yytokenaction_size = 33;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 23, YYAT_SHIFT, 3 },
	{ 15, YYAT_SHIFT, 19 },
	{ 27, YYAT_SHIFT, 20 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 23, YYAT_SHIFT, 4 },
	{ -1, YYAT_ERROR, 0 },
	{ 27, YYAT_SHIFT, 23 },
	{ 23, YYAT_SHIFT, 5 },
	{ 23, YYAT_SHIFT, 6 },
	{ 23, YYAT_SHIFT, 7 },
	{ 23, YYAT_SHIFT, 8 },
	{ 23, YYAT_SHIFT, 9 },
	{ 23, YYAT_SHIFT, 10 },
	{ 23, YYAT_SHIFT, 11 },
	{ 23, YYAT_SHIFT, 12 },
	{ 23, YYAT_SHIFT, 13 },
	{ 23, YYAT_SHIFT, 14 },
	{ 17, YYAT_SHIFT, 24 },
	{ 17, YYAT_SHIFT, 20 },
	{ 17, YYAT_SHIFT, 21 },
	{ 1, YYAT_ACCEPT, 0 },
	{ 17, YYAT_SHIFT, 22 },
	{ 26, YYAT_SHIFT, 20 },
	{ 17, YYAT_SHIFT, 23 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 26, YYAT_SHIFT, 23 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 1, YYAT_SHIFT, 2 },
	{ 15, YYAT_ERROR, 0 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ 0, 0, YYAT_REDUCE, 3 },
	{ 21, 1, YYAT_DEFAULT, 23 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ 0, 0, YYAT_DEFAULT, 23 },
	{ 0, 0, YYAT_DEFAULT, 23 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ 0, 0, YYAT_REDUCE, 16 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ 0, 0, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ -9, 1, YYAT_DEFAULT, 17 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ -23, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ 0, 0, YYAT_DEFAULT, 23 },
	{ 0, 0, YYAT_DEFAULT, 23 },
	{ 0, 0, YYAT_DEFAULT, 23 },
	{ -40, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ -19, 1, YYAT_REDUCE, 4 },
	{ -40, 1, YYAT_REDUCE, 5 },
	{ 0, 0, YYAT_REDUCE, 7 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 9;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 23, 28 },
	{ 23, 16 },
	{ 22, 27 },
	{ 21, 26 },
	{ 20, 25 },
	{ 4, 18 },
	{ 3, 17 },
	{ 1, 15 },
	{ 0, 1 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 7, -1 },
	{ 5, 23 },
	{ 0, -1 },
	{ 4, 23 },
	{ 3, 23 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 2, 23 },
	{ 1, 23 },
	{ 0, 23 },
	{ -2, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 53 ".\\myparser.y"

int yygettoken(void)
{	
	return getchar();
}

int main(void)
{
	return yyparse();
}





