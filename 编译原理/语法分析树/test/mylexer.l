%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2016Äê11ÔÂ14ÈÕ
****************************************************************************/
#include<stdio.h>
#include<string.h>
#include "myparser.h"

extern char* yylval;

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here
digit [0-9]
letter [a-zA-Z]
ID ({letter}|[_])({letter}|{digit}|[_])*
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
{ID} {printf("%s\n",yytext);yylval = yytext;return ID;}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section