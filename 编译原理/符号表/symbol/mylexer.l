%{
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
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
digit [0-9]
letter [a-zA-Z]
ID ({letter}|[_])({letter}|{digit}|[_])*
NUMBER {digit}+
WHITESPACE [\t]+
SEMICOLON ";"
LPACE "("
RPACE ")"
LBRACE "{"
RBRACE "}"
ADD "+"
SUB "-"
MUL "*"
DIV "/"
EQ "=="
IF "if"
INT "int"
ASSIGN "="

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
{WHITESPACE} {}
{SEMICOLON} {printf("SEMICOLON   %s\n",yytext);}
{LPACE} {printf("LPACE    %s\n",yytext);}
{RPACE} {printf("RPACE    %s\n",yytext);}
{LBRACE} {printf("LBRACE   %s\n",yytext);}
{RBRACE} {printf("RBRACE   %s\n",yytext);}
{ADD} {printf("ADD      %s\n",yytext);}
{SUB} {printf("SUB      %s\n",yytext);}
{MUL} {printf("MUL      %s\n",yytext);}
{DIV} {printf("DIV      %s\n",yytext);}
{EQ} {printf("EQ       %s\n",yytext);}
{IF} {printf("IF       %s\n",yytext);}
{INT} {printf("INT      %s\n",yytext);}
{ASSIGN} {printf("ASSIGN   %s\n",yytext);}
{NUMBER} {printf("NUMBER   %s\n",yytext);}
{ID} {if(lookup_symbol(yytext)==-1){add_symbol(yytext);}printf("ID       %s   %d\n",yytext,lookup_symbol(yytext));}

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

main(int argc, char *argv[])
{	++argv, --argc;
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else  yyin = stdin;
	yylex();
}



