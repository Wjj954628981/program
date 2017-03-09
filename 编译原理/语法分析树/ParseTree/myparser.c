/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 74 of your 30 day trial period.
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
* Date: 12/29/16
* Time: 22:50:33
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

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2016Äê11ÔÂ14ÈÕ
****************************************************************************/
#include<stdio.h>
#include<string.h>
#include "mylexer.h"
#include "treenode.h"
#include "util.h"

//extern FILE * yyin;
extern int lineno;

char *type;

struct Symbol *symbol_list = NULL;

#define YYSTYPE TreeNode*


#line 64 "myparser.c"
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
			YYSTYPE YYFAR *yya[7];
			yyinitdebug(yya, 7);
#endif
			{
#line 48 ".\\myparser.y"
struct TreeNode *root = MakeStmtNode("{}");root->child[0] = yyattribute(1 - 6);root->child[1] = yyattribute(5 - 6);root->lineno = lineno;typecheck(root);/*inorder(root,0);*/wgen_code(root);
#line 190 "myparser.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 51 ".\\myparser.y"
yyval = MakeStmtNode("{}");yyval->child[0] = yyattribute(1 - 2);yyval->child[1] = yyattribute(2 - 2);yyval->lineno = lineno;
#line 203 "myparser.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 52 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 216 "myparser.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 55 ".\\myparser.y"
yyval = yyattribute(1 - 2);
#line 229 "myparser.c"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 56 ".\\myparser.y"
yyval = yyattribute(1 - 2);
#line 242 "myparser.c"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 57 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 255 "myparser.c"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 58 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 268 "myparser.c"
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
#line 59 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 281 "myparser.c"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 60 ".\\myparser.y"
yyval = yyattribute(1 - 2);
#line 294 "myparser.c"
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
#line 61 ".\\myparser.y"
yyval = MakeNullNode();yyval->lineno = lineno;
#line 307 "myparser.c"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 62 ".\\myparser.y"
yyval = yyattribute(2 - 3);
#line 320 "myparser.c"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 63 ".\\myparser.y"
yyval = yyattribute(1 - 2);
#line 333 "myparser.c"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 64 ".\\myparser.y"
yyval = yyattribute(1 - 2);
#line 346 "myparser.c"
			}
		}
		break;
	case 13:
		{
#line 65 ".\\myparser.y"
yyval = MakeNullNode();yyval->lineno = lineno;
#line 354 "myparser.c"
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 69 ".\\myparser.y"
yyval = MakeStmtNode("declare");yyval->child[0] = yyattribute(1 - 2);yyval->child[1] = yyattribute(2 - 2);yyval->lineno = lineno;
#line 366 "myparser.c"
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
#line 72 ".\\myparser.y"
yyval = yyattribute(1 - 1);type = yyattribute(1 - 1)->type;
#line 379 "myparser.c"
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
#line 73 ".\\myparser.y"
yyval = yyattribute(1 - 1);type = yyattribute(1 - 1)->type;
#line 392 "myparser.c"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 74 ".\\myparser.y"
yyval = yyattribute(1 - 1);type = yyattribute(1 - 1)->type;
#line 405 "myparser.c"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 77 ".\\myparser.y"
yyval = MakeIdlistNode();yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;yyval->type = type;
#line 418 "myparser.c"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 78 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 431 "myparser.c"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 81 ".\\myparser.y"
yyval = yyattribute(1 - 1);
						if(lookup_symbol(yyval->tree_value,symbol_list)==NULL){
							yyval->type = type;
							symbol_list = add_symbol(type,yyattribute(1 - 1)->tree_value,symbol_list);
						}else{
							yyval->type = "The variable has been declared!";
						}
					
#line 451 "myparser.c"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 90 ".\\myparser.y"
yyval = MakeExprNode("=");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
								if(lookup_symbol(yyattribute(1 - 3)->tree_value,symbol_list)==NULL){
									yyval->type = type;
									yyattribute(1 - 3)->type = type;
									symbol_list = add_symbol(type,yyattribute(1 - 3)->tree_value,symbol_list);
								}else{
									yyattribute(1 - 3)->type = "The variable has been declared!";
								}
								
#line 472 "myparser.c"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 102 ".\\myparser.y"
yyval = MakeStmtNode("if");yyval->child[0] = yyattribute(3 - 5);yyval->child[1] = yyattribute(5 - 5);yyval->lineno = lineno;
#line 485 "myparser.c"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 103 ".\\myparser.y"
yyval = MakeStmtNode("if");yyval->child[0] = yyattribute(3 - 7);yyval->child[1] = yyattribute(5 - 7);yyval->child[2] = yyattribute(7 - 7);yyval->lineno = lineno;
#line 498 "myparser.c"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 106 ".\\myparser.y"
yyval = MakeStmtNode("while");yyval->child[0] = yyattribute(3 - 5);yyval->child[1] = yyattribute(5 - 5);yyval->lineno = lineno;
#line 511 "myparser.c"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[10];
			yyinitdebug(yya, 10);
#endif
			{
#line 110 ".\\myparser.y"
yyval = MakeStmtNode("for");yyval->child[0] = yyattribute(3 - 9);yyval->child[1] = yyattribute(5 - 9);yyval->child[2] = yyattribute(7 - 9);yyval->child[3] = yyattribute(9 - 9);yyval->lineno = lineno;
#line 524 "myparser.c"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 113 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 537 "myparser.c"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 114 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 550 "myparser.c"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 115 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 563 "myparser.c"
			}
		}
		break;
	case 29:
		{
#line 116 ".\\myparser.y"
yyval = MakeNullNode();yyval->lineno = lineno;
#line 571 "myparser.c"
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 119 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 583 "myparser.c"
			}
		}
		break;
	case 31:
		{
#line 120 ".\\myparser.y"
yyval = MakeNullNode();yyval->lineno = lineno;
#line 591 "myparser.c"
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 123 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 603 "myparser.c"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 124 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 616 "myparser.c"
			}
		}
		break;
	case 34:
		{
#line 125 ".\\myparser.y"
yyval = MakeNullNode();yyval->lineno = lineno;
#line 624 "myparser.c"
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 129 ".\\myparser.y"
yyval = MakeStmtNode("print");yyval->child[0] = yyattribute(3 - 4);yyval->lineno = lineno;
#line 636 "myparser.c"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 130 ".\\myparser.y"
yyval = MakeStmtNode("print");yyval->child[0] = yyattribute(3 - 4);yyval->lineno = lineno;
#line 649 "myparser.c"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 135 ".\\myparser.y"
yyval = MakeStmtNode("input");yyval->child[0] = yyattribute(3 - 4);yyval->lineno = lineno;
#line 662 "myparser.c"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 140 ".\\myparser.y"
yyval = MakeExprNode("||");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 675 "myparser.c"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 141 ".\\myparser.y"
yyval = MakeExprNode("&&");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 688 "myparser.c"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 142 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 701 "myparser.c"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 146 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 714 "myparser.c"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 147 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 727 "myparser.c"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 152 ".\\myparser.y"
yyval = MakeExprNode("=");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
								if(lookup_symbol(yyattribute(1 - 3)->tree_value,symbol_list)==NULL){
									yyattribute(1 - 3)->type = "The variable is not declared!";
								}else{
									yyattribute(1 - 3)->type = lookup_symbol(yyattribute(1 - 3)->tree_value,symbol_list);
								}
								
#line 746 "myparser.c"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 162 ".\\myparser.y"
yyval = MakeExprNode("==");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 759 "myparser.c"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 163 ".\\myparser.y"
yyval = MakeExprNode(">=");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 772 "myparser.c"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 164 ".\\myparser.y"
yyval = MakeExprNode("<=");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 785 "myparser.c"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 165 ".\\myparser.y"
yyval = MakeExprNode(">");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 798 "myparser.c"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 166 ".\\myparser.y"
yyval = MakeExprNode("<");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 811 "myparser.c"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 167 ".\\myparser.y"
yyval = MakeExprNode(">>");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 824 "myparser.c"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 168 ".\\myparser.y"
yyval = MakeExprNode("<<");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 837 "myparser.c"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 169 ".\\myparser.y"
yyval = MakeExprNode("!=");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 850 "myparser.c"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 170 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 863 "myparser.c"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 174 ".\\myparser.y"
yyval = MakeExprNode("+");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 876 "myparser.c"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 175 ".\\myparser.y"
yyval = MakeExprNode("-");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 889 "myparser.c"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 176 ".\\myparser.y"
yyval = MakeExprNode("%");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 902 "myparser.c"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 177 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 915 "myparser.c"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 180 ".\\myparser.y"
yyval = MakeExprNode("*");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 928 "myparser.c"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 181 ".\\myparser.y"
yyval = MakeExprNode("/");yyval->child[0] = yyattribute(1 - 3);yyval->child[1] = yyattribute(3 - 3);yyval->lineno = lineno;
#line 941 "myparser.c"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 182 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 954 "myparser.c"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 185 ".\\myparser.y"
yyval = yyattribute(1 - 1);
				if(lookup_symbol(yyattribute(1 - 1)->tree_value,symbol_list)==NULL){
					yyval->type = "The variable is not declared!";
				}else{
					yyval->type = lookup_symbol(yyattribute(1 - 1)->tree_value,symbol_list);
				}
				
#line 973 "myparser.c"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 192 ".\\myparser.y"
yyval = yyattribute(1 - 1);
#line 986 "myparser.c"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 193 ".\\myparser.y"
yyval = yyattribute(2 - 3);
#line 999 "myparser.c"
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
	{ "error", 256 },
	{ "ID", 257 },
	{ "NUMBER", 258 },
	{ "INT", 259 },
	{ "CHAR", 260 },
	{ "BOOL", 261 },
	{ "SEMICOLON", 262 },
	{ "COMMA", 263 },
	{ "LPACE", 265 },
	{ "RPACE", 266 },
	{ "LBRACE", 267 },
	{ "RBRACE", 268 },
	{ "ADD", 269 },
	{ "SUB", 270 },
	{ "MUL", 271 },
	{ "DIV", 272 },
	{ "MOD", 273 },
	{ "OR", 274 },
	{ "AND", 275 },
	{ "EQ", 276 },
	{ "GE", 277 },
	{ "LE", 278 },
	{ "GT", 279 },
	{ "LT", 280 },
	{ "GREATER", 281 },
	{ "LESS", 282 },
	{ "NE", 283 },
	{ "IF", 284 },
	{ "ELSE", 285 },
	{ "WHILE", 286 },
	{ "FOR", 287 },
	{ "ASSIGN", 288 },
	{ "INPUT", 289 },
	{ "PRINT", 290 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: programs",
	"programs: programs program",
	"programs: program",
	"program: ID LPACE RPACE LBRACE stmts RBRACE",
	"stmts: stmt stmts",
	"stmts: stmt",
	"stmt: declare_stmt SEMICOLON",
	"stmt: assign_expr SEMICOLON",
	"stmt: if_stmt",
	"stmt: while_stmt",
	"stmt: for_stmt",
	"stmt: logic_expr SEMICOLON",
	"stmt: SEMICOLON",
	"stmt: LBRACE stmts RBRACE",
	"stmt: print_stmt SEMICOLON",
	"stmt: input_stmt SEMICOLON",
	"stmt:",
	"declare_stmt: type idlist",
	"type: INT",
	"type: CHAR",
	"type: BOOL",
	"idlist: declare_args COMMA idlist",
	"idlist: declare_args",
	"declare_args: ID",
	"declare_args: ID ASSIGN expr",
	"if_stmt: IF LPACE logic_expr RPACE stmt",
	"if_stmt: IF LPACE logic_expr RPACE stmt ELSE stmt",
	"while_stmt: WHILE LPACE logic_expr RPACE stmt",
	"for_stmt: FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt",
	"for_expr1: assign_expr",
	"for_expr1: logic_expr",
	"for_expr1: declare_stmt",
	"for_expr1:",
	"for_expr2: logic_expr",
	"for_expr2:",
	"for_expr3: assign_expr",
	"for_expr3: expr",
	"for_expr3:",
	"print_stmt: PRINT LPACE ID RPACE",
	"print_stmt: PRINT LPACE NUMBER RPACE",
	"input_stmt: INPUT LPACE ID RPACE",
	"logic_expr: if_expr OR logic_expr",
	"logic_expr: if_expr AND logic_expr",
	"logic_expr: if_expr",
	"if_expr: assign_expr",
	"if_expr: bool_expr",
	"assign_expr: ID ASSIGN expr",
	"bool_expr: expr EQ expr",
	"bool_expr: expr GE expr",
	"bool_expr: expr LE expr",
	"bool_expr: expr GT expr",
	"bool_expr: expr LT expr",
	"bool_expr: expr GREATER expr",
	"bool_expr: expr LESS expr",
	"bool_expr: expr NE expr",
	"bool_expr: expr",
	"expr: expr ADD term",
	"expr: expr SUB term",
	"expr: expr MOD term",
	"expr: term",
	"term: term MUL factor",
	"term: term DIV factor",
	"term: factor",
	"factor: ID",
	"factor: NUMBER",
	"factor: LPACE expr RPACE"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 2, -1 },
	{ 1, 1, -1 },
	{ 2, 6, 0 },
	{ 3, 2, 1 },
	{ 3, 1, 2 },
	{ 4, 2, 3 },
	{ 4, 2, 4 },
	{ 4, 1, 5 },
	{ 4, 1, 6 },
	{ 4, 1, 7 },
	{ 4, 2, 8 },
	{ 4, 1, 9 },
	{ 4, 3, 10 },
	{ 4, 2, 11 },
	{ 4, 2, 12 },
	{ 4, 0, 13 },
	{ 5, 2, 14 },
	{ 6, 1, 15 },
	{ 6, 1, 16 },
	{ 6, 1, 17 },
	{ 7, 3, 18 },
	{ 7, 1, 19 },
	{ 8, 1, 20 },
	{ 8, 3, 21 },
	{ 9, 5, 22 },
	{ 9, 7, 23 },
	{ 10, 5, 24 },
	{ 11, 9, 25 },
	{ 12, 1, 26 },
	{ 12, 1, 27 },
	{ 12, 1, 28 },
	{ 12, 0, 29 },
	{ 13, 1, 30 },
	{ 13, 0, 31 },
	{ 14, 1, 32 },
	{ 14, 1, 33 },
	{ 14, 0, 34 },
	{ 15, 4, 35 },
	{ 15, 4, 36 },
	{ 16, 4, 37 },
	{ 17, 3, 38 },
	{ 17, 3, 39 },
	{ 17, 1, 40 },
	{ 18, 1, 41 },
	{ 18, 1, 42 },
	{ 19, 3, 43 },
	{ 20, 3, 44 },
	{ 20, 3, 45 },
	{ 20, 3, 46 },
	{ 20, 3, 47 },
	{ 20, 3, 48 },
	{ 20, 3, 49 },
	{ 20, 3, 50 },
	{ 20, 3, 51 },
	{ 20, 1, 52 },
	{ 21, 3, 53 },
	{ 21, 3, 54 },
	{ 21, 3, 55 },
	{ 21, 1, 56 },
	{ 22, 3, 57 },
	{ 22, 3, 58 },
	{ 22, 1, 59 },
	{ 23, 1, 60 },
	{ 23, 1, 61 },
	{ 23, 3, 62 }
};

int YYNEAR YYDCDECL yytokenaction_size = 199;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 119, YYAT_SHIFT, 8 },
	{ 119, YYAT_SHIFT, 9 },
	{ 119, YYAT_SHIFT, 10 },
	{ 119, YYAT_SHIFT, 11 },
	{ 119, YYAT_SHIFT, 12 },
	{ 119, YYAT_SHIFT, 13 },
	{ 86, YYAT_SHIFT, 67 },
	{ 86, YYAT_SHIFT, 68 },
	{ 119, YYAT_SHIFT, 14 },
	{ 118, YYAT_SHIFT, 119 },
	{ 119, YYAT_SHIFT, 15 },
	{ 113, YYAT_SHIFT, 8 },
	{ 113, YYAT_SHIFT, 9 },
	{ 113, YYAT_SHIFT, 10 },
	{ 113, YYAT_SHIFT, 11 },
	{ 113, YYAT_SHIFT, 12 },
	{ 113, YYAT_SHIFT, 13 },
	{ 114, YYAT_SHIFT, 8 },
	{ 114, YYAT_SHIFT, 9 },
	{ 113, YYAT_SHIFT, 14 },
	{ 112, YYAT_SHIFT, 114 },
	{ 113, YYAT_SHIFT, 15 },
	{ 109, YYAT_SHIFT, 113 },
	{ 103, YYAT_SHIFT, 8 },
	{ 103, YYAT_SHIFT, 9 },
	{ 114, YYAT_SHIFT, 14 },
	{ 96, YYAT_SHIFT, 61 },
	{ 119, YYAT_SHIFT, 16 },
	{ 83, YYAT_SHIFT, 106 },
	{ 119, YYAT_SHIFT, 17 },
	{ 119, YYAT_SHIFT, 18 },
	{ 103, YYAT_SHIFT, 14 },
	{ 119, YYAT_SHIFT, 19 },
	{ 119, YYAT_SHIFT, 20 },
	{ 95, YYAT_SHIFT, 38 },
	{ 95, YYAT_SHIFT, 9 },
	{ 85, YYAT_SHIFT, 67 },
	{ 85, YYAT_SHIFT, 68 },
	{ 113, YYAT_SHIFT, 16 },
	{ 82, YYAT_SHIFT, 105 },
	{ 113, YYAT_SHIFT, 17 },
	{ 113, YYAT_SHIFT, 18 },
	{ 95, YYAT_SHIFT, 14 },
	{ 113, YYAT_SHIFT, 19 },
	{ 113, YYAT_SHIFT, 20 },
	{ 102, YYAT_SHIFT, 8 },
	{ 102, YYAT_SHIFT, 9 },
	{ 102, YYAT_SHIFT, 10 },
	{ 102, YYAT_SHIFT, 11 },
	{ 102, YYAT_SHIFT, 12 },
	{ 102, YYAT_SHIFT, 13 },
	{ 84, YYAT_SHIFT, 67 },
	{ 84, YYAT_SHIFT, 68 },
	{ 102, YYAT_SHIFT, 14 },
	{ 81, YYAT_SHIFT, 104 },
	{ 102, YYAT_SHIFT, 15 },
	{ 101, YYAT_SHIFT, 8 },
	{ 101, YYAT_SHIFT, 9 },
	{ 101, YYAT_SHIFT, 10 },
	{ 101, YYAT_SHIFT, 11 },
	{ 101, YYAT_SHIFT, 12 },
	{ 101, YYAT_SHIFT, 13 },
	{ 45, YYAT_SHIFT, 82 },
	{ 45, YYAT_SHIFT, 83 },
	{ 101, YYAT_SHIFT, 14 },
	{ 79, YYAT_SHIFT, 103 },
	{ 101, YYAT_SHIFT, 15 },
	{ 117, YYAT_SHIFT, 50 },
	{ 117, YYAT_SHIFT, 51 },
	{ 107, YYAT_SHIFT, 50 },
	{ 107, YYAT_SHIFT, 51 },
	{ 117, YYAT_SHIFT, 52 },
	{ 102, YYAT_SHIFT, 16 },
	{ 107, YYAT_SHIFT, 52 },
	{ 102, YYAT_SHIFT, 17 },
	{ 102, YYAT_SHIFT, 18 },
	{ 78, YYAT_REDUCE, 29 },
	{ 102, YYAT_SHIFT, 19 },
	{ 102, YYAT_SHIFT, 20 },
	{ 76, YYAT_SHIFT, 102 },
	{ 94, YYAT_SHIFT, 50 },
	{ 94, YYAT_SHIFT, 51 },
	{ 75, YYAT_SHIFT, 101 },
	{ 101, YYAT_SHIFT, 16 },
	{ 94, YYAT_SHIFT, 52 },
	{ 101, YYAT_SHIFT, 17 },
	{ 101, YYAT_SHIFT, 18 },
	{ 70, YYAT_SHIFT, 8 },
	{ 101, YYAT_SHIFT, 19 },
	{ 101, YYAT_SHIFT, 20 },
	{ 21, YYAT_SHIFT, 8 },
	{ 21, YYAT_SHIFT, 9 },
	{ 21, YYAT_SHIFT, 10 },
	{ 21, YYAT_SHIFT, 11 },
	{ 21, YYAT_SHIFT, 12 },
	{ 21, YYAT_SHIFT, 13 },
	{ 36, YYAT_SHIFT, 69 },
	{ 36, YYAT_SHIFT, 70 },
	{ 21, YYAT_SHIFT, 14 },
	{ 63, YYAT_SHIFT, 96 },
	{ 21, YYAT_SHIFT, 15 },
	{ 15, YYAT_SHIFT, 8 },
	{ 15, YYAT_SHIFT, 9 },
	{ 15, YYAT_SHIFT, 10 },
	{ 15, YYAT_SHIFT, 11 },
	{ 15, YYAT_SHIFT, 12 },
	{ 15, YYAT_SHIFT, 13 },
	{ 35, YYAT_SHIFT, 67 },
	{ 35, YYAT_SHIFT, 68 },
	{ 15, YYAT_SHIFT, 14 },
	{ 61, YYAT_SHIFT, 95 },
	{ 15, YYAT_SHIFT, 15 },
	{ 93, YYAT_SHIFT, 50 },
	{ 93, YYAT_SHIFT, 51 },
	{ 92, YYAT_SHIFT, 50 },
	{ 92, YYAT_SHIFT, 51 },
	{ 93, YYAT_SHIFT, 52 },
	{ 21, YYAT_SHIFT, 16 },
	{ 92, YYAT_SHIFT, 52 },
	{ 21, YYAT_SHIFT, 17 },
	{ 21, YYAT_SHIFT, 18 },
	{ 44, YYAT_SHIFT, 81 },
	{ 21, YYAT_SHIFT, 19 },
	{ 21, YYAT_SHIFT, 20 },
	{ 40, YYAT_SHIFT, 73 },
	{ 91, YYAT_SHIFT, 50 },
	{ 91, YYAT_SHIFT, 51 },
	{ 32, YYAT_SHIFT, 66 },
	{ 15, YYAT_SHIFT, 16 },
	{ 91, YYAT_SHIFT, 52 },
	{ 15, YYAT_SHIFT, 17 },
	{ 15, YYAT_SHIFT, 18 },
	{ 31, YYAT_SHIFT, 65 },
	{ 15, YYAT_SHIFT, 19 },
	{ 15, YYAT_SHIFT, 20 },
	{ 7, YYAT_SHIFT, 8 },
	{ 7, YYAT_SHIFT, 9 },
	{ 7, YYAT_SHIFT, 10 },
	{ 7, YYAT_SHIFT, 11 },
	{ 7, YYAT_SHIFT, 12 },
	{ 7, YYAT_SHIFT, 13 },
	{ 30, YYAT_SHIFT, 64 },
	{ 24, YYAT_SHIFT, 49 },
	{ 7, YYAT_SHIFT, 14 },
	{ 23, YYAT_SHIFT, 48 },
	{ 7, YYAT_SHIFT, 15 },
	{ 26, YYAT_SHIFT, 50 },
	{ 26, YYAT_SHIFT, 51 },
	{ 90, YYAT_SHIFT, 50 },
	{ 90, YYAT_SHIFT, 51 },
	{ 26, YYAT_SHIFT, 52 },
	{ 22, YYAT_SHIFT, 47 },
	{ 90, YYAT_SHIFT, 52 },
	{ 26, YYAT_SHIFT, 53 },
	{ 26, YYAT_SHIFT, 54 },
	{ 26, YYAT_SHIFT, 55 },
	{ 26, YYAT_SHIFT, 56 },
	{ 26, YYAT_SHIFT, 57 },
	{ 26, YYAT_SHIFT, 58 },
	{ 26, YYAT_SHIFT, 59 },
	{ 26, YYAT_SHIFT, 60 },
	{ 20, YYAT_SHIFT, 45 },
	{ 7, YYAT_SHIFT, 16 },
	{ 19, YYAT_SHIFT, 44 },
	{ 7, YYAT_SHIFT, 17 },
	{ 7, YYAT_SHIFT, 18 },
	{ 18, YYAT_SHIFT, 43 },
	{ 7, YYAT_SHIFT, 19 },
	{ 7, YYAT_SHIFT, 20 },
	{ 43, YYAT_SHIFT, 8 },
	{ 43, YYAT_SHIFT, 9 },
	{ 43, YYAT_SHIFT, 10 },
	{ 43, YYAT_SHIFT, 11 },
	{ 43, YYAT_SHIFT, 12 },
	{ 17, YYAT_SHIFT, 42 },
	{ 39, YYAT_SHIFT, 72 },
	{ 16, YYAT_SHIFT, 41 },
	{ 43, YYAT_SHIFT, 14 },
	{ 39, YYAT_SHIFT, 50 },
	{ 39, YYAT_SHIFT, 51 },
	{ 89, YYAT_SHIFT, 50 },
	{ 89, YYAT_SHIFT, 51 },
	{ 39, YYAT_SHIFT, 52 },
	{ 8, YYAT_SHIFT, 37 },
	{ 89, YYAT_SHIFT, 52 },
	{ 88, YYAT_SHIFT, 50 },
	{ 88, YYAT_SHIFT, 51 },
	{ 87, YYAT_SHIFT, 50 },
	{ 87, YYAT_SHIFT, 51 },
	{ 88, YYAT_SHIFT, 52 },
	{ 6, YYAT_SHIFT, 7 },
	{ 87, YYAT_SHIFT, 52 },
	{ 71, YYAT_SHIFT, 50 },
	{ 71, YYAT_SHIFT, 51 },
	{ 4, YYAT_SHIFT, 6 },
	{ 2, YYAT_ACCEPT, 0 },
	{ 71, YYAT_SHIFT, 52 },
	{ 1, YYAT_SHIFT, 4 },
	{ 0, YYAT_SHIFT, 1 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ -59, 1, YYAT_ERROR, 0 },
	{ -68, 1, YYAT_ERROR, 0 },
	{ 195, 1, YYAT_DEFAULT, 0 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ -72, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ -77, 1, YYAT_ERROR, 0 },
	{ -122, 1, YYAT_REDUCE, 16 },
	{ -105, 1, YYAT_REDUCE, 63 },
	{ 0, 0, YYAT_REDUCE, 64 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ 0, 0, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ -156, 1, YYAT_REDUCE, 16 },
	{ -89, 1, YYAT_ERROR, 0 },
	{ -91, 1, YYAT_ERROR, 0 },
	{ -99, 1, YYAT_ERROR, 0 },
	{ -102, 1, YYAT_ERROR, 0 },
	{ -104, 1, YYAT_ERROR, 0 },
	{ -167, 1, YYAT_REDUCE, 5 },
	{ -111, 1, YYAT_ERROR, 0 },
	{ -118, 1, YYAT_REDUCE, 44 },
	{ -126, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ -123, 1, YYAT_REDUCE, 55 },
	{ 0, 0, YYAT_DEFAULT, 96 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ -121, 1, YYAT_ERROR, 0 },
	{ -130, 1, YYAT_ERROR, 0 },
	{ -135, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 45 },
	{ 0, 0, YYAT_REDUCE, 62 },
	{ -164, 1, YYAT_REDUCE, 59 },
	{ -178, 1, YYAT_REDUCE, 43 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_REDUCE, 63 },
	{ -91, 1, YYAT_ERROR, 0 },
	{ -144, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 70 },
	{ 0, 0, YYAT_DEFAULT, 70 },
	{ -88, 1, YYAT_REDUCE, 32 },
	{ -136, 1, YYAT_ERROR, 0 },
	{ -195, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 4 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ 0, 0, YYAT_REDUCE, 7 },
	{ 0, 0, YYAT_REDUCE, 3 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ -178, 1, YYAT_REDUCE, 23 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ -164, 1, YYAT_REDUCE, 22 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 95 },
	{ 0, 0, YYAT_DEFAULT, 70 },
	{ -170, 1, YYAT_DEFAULT, 95 },
	{ -77, 1, YYAT_REDUCE, 46 },
	{ 0, 0, YYAT_REDUCE, 65 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 44 },
	{ -184, 1, YYAT_ERROR, 0 },
	{ -187, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 31 },
	{ -186, 1, YYAT_REDUCE, 44 },
	{ -197, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ -212, 1, YYAT_ERROR, 0 },
	{ -227, 1, YYAT_ERROR, 0 },
	{ -238, 1, YYAT_ERROR, 0 },
	{ -220, 1, YYAT_REDUCE, 56 },
	{ -235, 1, YYAT_REDUCE, 57 },
	{ -265, 1, YYAT_REDUCE, 58 },
	{ -82, 1, YYAT_REDUCE, 47 },
	{ -84, 1, YYAT_REDUCE, 48 },
	{ -89, 1, YYAT_REDUCE, 49 },
	{ -121, 1, YYAT_REDUCE, 50 },
	{ -144, 1, YYAT_REDUCE, 51 },
	{ -155, 1, YYAT_REDUCE, 52 },
	{ -157, 1, YYAT_REDUCE, 53 },
	{ -189, 1, YYAT_REDUCE, 54 },
	{ -223, 1, YYAT_ERROR, 0 },
	{ -231, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 60 },
	{ 0, 0, YYAT_REDUCE, 61 },
	{ 0, 0, YYAT_REDUCE, 41 },
	{ 0, 0, YYAT_REDUCE, 42 },
	{ -201, 1, YYAT_REDUCE, 16 },
	{ -212, 1, YYAT_REDUCE, 16 },
	{ -234, 1, YYAT_REDUCE, 34 },
	{ 0, 0, YYAT_REDUCE, 40 },
	{ 0, 0, YYAT_REDUCE, 38 },
	{ 0, 0, YYAT_REDUCE, 39 },
	{ -200, 1, YYAT_REDUCE, 24 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ -263, 1, YYAT_REDUCE, 25 },
	{ 0, 0, YYAT_REDUCE, 27 },
	{ 0, 0, YYAT_REDUCE, 33 },
	{ -242, 1, YYAT_ERROR, 0 },
	{ -246, 1, YYAT_REDUCE, 16 },
	{ -240, 1, YYAT_REDUCE, 37 },
	{ 0, 0, YYAT_REDUCE, 26 },
	{ 0, 0, YYAT_REDUCE, 35 },
	{ -202, 1, YYAT_REDUCE, 36 },
	{ -257, 1, YYAT_ERROR, 0 },
	{ -257, 1, YYAT_REDUCE, 16 },
	{ 0, 0, YYAT_REDUCE, 28 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 60;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 119, 120 },
	{ 119, 22 },
	{ 119, 27 },
	{ 113, 115 },
	{ 70, -1 },
	{ 119, 28 },
	{ 119, 25 },
	{ 119, 29 },
	{ 70, 100 },
	{ 43, 77 },
	{ 43, 27 },
	{ 119, 31 },
	{ 119, 32 },
	{ 119, 30 },
	{ 102, 110 },
	{ 119, 23 },
	{ 43, 79 },
	{ 96, 108 },
	{ 96, 63 },
	{ 101, 109 },
	{ 103, 112 },
	{ 43, 80 },
	{ 69, 99 },
	{ 43, 78 },
	{ 103, 111 },
	{ 103, 36 },
	{ 103, 74 },
	{ 103, 33 },
	{ 103, 26 },
	{ 114, 118 },
	{ 95, 107 },
	{ 95, 35 },
	{ 52, 86 },
	{ 52, 34 },
	{ 114, 116 },
	{ 68, 98 },
	{ 114, 117 },
	{ 21, 46 },
	{ 21, 21 },
	{ 0, 2 },
	{ 0, 3 },
	{ 67, 97 },
	{ 60, 94 },
	{ 59, 93 },
	{ 58, 92 },
	{ 57, 91 },
	{ 56, 90 },
	{ 55, 89 },
	{ 54, 88 },
	{ 53, 87 },
	{ 51, 85 },
	{ 50, 84 },
	{ 42, 76 },
	{ 41, 75 },
	{ 37, 71 },
	{ 27, 62 },
	{ 15, 40 },
	{ 14, 39 },
	{ 7, 24 },
	{ 2, 5 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 38, -1 },
	{ 0, -1 },
	{ 57, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 55, 21 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 36, 95 },
	{ 53, 21 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 34, 119 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 48, 96 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 33, 95 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 36, 70 },
	{ 35, 70 },
	{ 4, 70 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 29, 52 },
	{ 28, 52 },
	{ 10, -1 },
	{ 28, 95 },
	{ 27, 95 },
	{ 26, 95 },
	{ 25, 95 },
	{ 24, 95 },
	{ 23, 95 },
	{ 22, 95 },
	{ 21, 95 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 18, -1 },
	{ 12, -1 },
	{ 5, 70 },
	{ -9, 103 },
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
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 9, 52 },
	{ 10, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 15, 119 },
	{ 10, 119 },
	{ 7, 95 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -1, 119 },
	{ 15, 95 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -4, 70 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 195 ".\\myparser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

/*main()
{	fopen_s(&yyin,"D:\\test.txt","r+");
	yyparse();
	inorder(root,0);
	getch();
}*/

main(int argc, char *argv[])
{	++argv, --argc;
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else  yyin = stdin;
	yyparse();
}

