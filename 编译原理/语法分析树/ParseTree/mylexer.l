%{
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

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here
digit [0-9]
letter [a-zA-Z]
ID ({letter}|[_])({letter}|{digit}|[_])*
NUMBER {digit}+
WHITESPACE [ \t]+
%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your Lex rules here
{WHITESPACE} {/* skip whitespace */}
//"/*"([^\*]|(\*)*[^\*/])*(\*)*"*/"	{}
"//"[^\n]*|"/*"([^*]*|\*[^/]*)"*/"	{}
"\n"	{lineno++;}
";" {return SEMICOLON;}
","	{return COMMA;}
"'"	{return QUO;}
"(" {return LPACE;}
")" {return RPACE;}
"{" {return LBRACE;}
"}" {return RBRACE;}
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
"%"	{return MOD;}
"||"	{return OR;}
"&&"	{return AND;}
"==" {return EQ;}
">=" {return GE;}
"<=" {return LE;}
">" {return GT;}
"<"	{return LT;}
">>"	{return GREATER;}
"<<"	{return LESS;}
"!=" {return NE;}
"=" {return ASSIGN;}
"if" {return IF;}
"else" {return ELSE;}
"while" {return WHILE;}
"for" {return FOR;}
"input"	{return INPUT;}
"print"	{return PRINT;}
"int" {yylval = MakeTypeNode("int");yylval->lineno = lineno;yylval->type = "Integer";return INT;}
"char" {yylval = MakeTypeNode("char");yylval->lineno = lineno;yylval->type = "Character";return CHAR;}
"bool" {yylval = MakeTypeNode("bool");yylval->lineno = lineno;yylval->type = "Boolean";return BOOL;}
{NUMBER} {yylval = MakeNumberNode(yytext);yylval->lineno = lineno;yylval->type = "Integer";return NUMBER;}
{ID} {yylval = MakeIdNode(yytext);yylval->lineno = lineno;return ID;}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section