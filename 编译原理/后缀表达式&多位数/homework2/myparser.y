%{
/************************************************************
calc.y
Simple calculator. Features floating point arithmetic using
the addition, subtraction, multiplication and divide
operators, and unary minus. Expressions can be grouped
using parentheses, and simple error recovery is supported.
************************************************************/

#include <ctype.h>
#include <stdio.h>
%}

%include {
#ifndef YYSTYPE
#define YYSTYPE double
#endif
}
 
%token ADD
%token SUB
%token MUL
%token DIV
%token LE
%token RE

%left ADD SUB
%left MUL DIV
%right UMINUS


%%
lines	:	lines expr '\n'
		|	lines '\n'
		|
		;

expr	:	expr ADD expr	{ printf("%g %g +\n", $1, $3); }
		|	expr SUB expr	{ printf("%g %g -\n", $1, $3); }
		|	expr MUL expr	{ printf("%g %g *\n", $1, $3); }
		|	expr DIV expr	{ printf("%g %g /\n", $1, $3); }
		|	LE expr RE	{ $$ = $2; }
		|	SUB expr %prec UMINUS	{ $$ = -$2; }
		|	DIGIT
		;

NUMBER	:	'0'				{ $$ = 0.0; }
		|	'1'				{ $$ = 1.0; }
		|	'2'				{ $$ = 2.0; }
		|	'3'				{ $$ = 3.0; }
		|	'4'				{ $$ = 4.0; }
		|	'5'				{ $$ = 5.0; }
		|	'6'				{ $$ = 6.0; }
		|	'7'				{ $$ = 7.0; }
		|	'8'				{ $$ = 8.0; }
		|	'9'				{ $$ = 9.0; }
		;		

DIGIT   :   NUMBER            { $$ = $1; }
        |   NUMBER DIGIT      { $$ = $1 * 10 + $2;}
        ;

%%
int yygettoken(void)
{	
	int token;
    token = getchar();
    while(token == ' '){
		token = getchar();
    }
	switch(token)
	{
		case '+':
		return ADD;
		break;
		case '-':
			return SUB;
			break;
		case '*':
			return MUL;
			break;
		case '/':
			return DIV;
			break;
		case '(':
			return LE;
			break;
		case ')':
			return RE;
			break;
		default:
			return token;
	}
	
}

int main(void)
{
	return yyparse();
}




