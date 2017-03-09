%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2016Äê11ÔÂ14ÈÕ
****************************************************************************/
#include<stdio.h>
#include<string.h>
#include "mylexer.h"

extern FILE * yyin;

#define YYSTYPE char*

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// attribute type

%token ID
// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

expr	:	ID	{printf("%s\n",$1);}
		;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

main()
{	fopen_s(&yyin,"D:\\basic.txt","r+");
	yyparse();
	getch();
}