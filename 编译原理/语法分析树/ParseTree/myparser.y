%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2016年11月14日
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

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section```	

// attribute type

%token ID NUMBER INT CHAR BOOL
%token SEMICOLON COMMA QUO LPACE RPACE LBRACE RBRACE ADD SUB MUL DIV MOD OR AND EQ GE LE GT LT GREATER LESS NE IF ELSE WHILE FOR ASSIGN INPUT PRINT

/*%left ADD SUB
%left MUL DIV*/
// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)
programs	:	programs program
			|	program
			;
		

program	:	ID LPACE RPACE LBRACE stmts RBRACE	{struct TreeNode *root = MakeStmtNode("{}");root->child[0] = $1;root->child[1] = $5;root->lineno = lineno;typecheck(root);/*inorder(root,0);*/wgen_code(root);}
		;

stmts	:	stmt stmts	{$$ = MakeStmtNode("{}");$$->child[0] = $1;$$->child[1] = $2;$$->lineno = lineno;}
		|	stmt	{$$ = $1;}
		;

stmt	:	declare_stmt SEMICOLON	{$$ = $1;}
		|	assign_expr SEMICOLON	{$$ = $1;}
		|	if_stmt	{$$ = $1;}
		|	while_stmt	{$$ = $1;}
		|	for_stmt	{$$ = $1;}
		|	logic_expr SEMICOLON	{$$ = $1;}
		|	SEMICOLON	{$$ = MakeNullNode();$$->lineno = lineno;}
		|	LBRACE stmts RBRACE	{$$ = $2;}
		|	print_stmt SEMICOLON	{$$ = $1;}
		|	input_stmt SEMICOLON	{$$ = $1;}
		|	{$$ = MakeNullNode();$$->lineno = lineno;}
		;

//定义段
declare_stmt	:	type idlist	{$$ = MakeStmtNode("declare");$$->child[0] = $1;$$->child[1] = $2;$$->lineno = lineno;}
				;

type	:	INT	{$$ = $1;type = $1->type;}
		|	CHAR{$$ = $1;type = $1->type;}
		|	BOOL{$$ = $1;type = $1->type;}
		;
		
idlist	:	declare_args COMMA idlist	{$$ = MakeIdlistNode();$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;$$->type = type;}
		|	declare_args	{$$ = $1;}
		;

declare_args	:	ID	{$$ = $1;
						if(lookup_symbol($$->tree_value,symbol_list)==NULL){
							$$->type = type;
							symbol_list = add_symbol(type,$1->tree_value,symbol_list);
						}else{
							$$->type = "The variable has been declared!";
						}
					}
				|	//assign_expr	{$$ = $1;$$->type = type;}
					ID ASSIGN expr	{$$ = MakeExprNode("=");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;
								if(lookup_symbol($1->tree_value,symbol_list)==NULL){
									$$->type = type;
									$1->type = type;
									symbol_list = add_symbol(type,$1->tree_value,symbol_list);
								}else{
									$1->type = "The variable has been declared!";
								}
								}
				;

//分支段
if_stmt	:	IF LPACE logic_expr RPACE stmt	{$$ = MakeStmtNode("if");$$->child[0] = $3;$$->child[1] = $5;$$->lineno = lineno;}
		|	IF LPACE logic_expr RPACE stmt ELSE  stmt	{$$ = MakeStmtNode("if");$$->child[0] = $3;$$->child[1] = $5;$$->child[2] = $7;$$->lineno = lineno;}
		;

while_stmt	:	WHILE LPACE logic_expr RPACE stmt	{$$ = MakeStmtNode("while");$$->child[0] = $3;$$->child[1] = $5;$$->lineno = lineno;}
			;

//循环段
for_stmt	:	FOR LPACE for_expr1 SEMICOLON for_expr2 SEMICOLON for_expr3 RPACE stmt	{$$ = MakeStmtNode("for");$$->child[0] = $3;$$->child[1] = $5;$$->child[2] = $7;$$->child[3] = $9;$$->lineno = lineno;}
			;

for_expr1	:	assign_expr	{$$ = $1;}
			|	logic_expr	{$$ = $1;}
			|	declare_stmt	{$$ = $1;}
			|	{$$ = MakeNullNode();$$->lineno = lineno;}
			;

for_expr2	:	logic_expr	{$$ = $1;}
			|	{$$ = MakeNullNode();$$->lineno = lineno;}
			;
			
for_expr3	:	assign_expr	{$$ = $1;}
			|	expr	{$$ = $1;}
			|	{$$ = MakeNullNode();$$->lineno = lineno;}
			;
			
//输出语句
print_stmt	:	PRINT LPACE ID RPACE	{$$ = MakeStmtNode("print");$$->child[0] = $3;$$->lineno = lineno;}
			|	PRINT LPACE NUMBER RPACE	{$$ = MakeStmtNode("print");$$->child[0] = $3;$$->lineno = lineno;}
			;


//输入语句
input_stmt	:	INPUT LPACE ID RPACE	{$$ = MakeStmtNode("input");$$->child[0] = $3;$$->lineno = lineno;}
			;
		

//逻辑语句（进行布尔计算）
logic_expr	:	if_expr OR logic_expr	{$$ = MakeExprNode("||");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	if_expr AND logic_expr	{$$ = MakeExprNode("&&");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	if_expr	{$$ = $1;}
			;

//布尔条件（得到布尔值或者数值）
if_expr	:	assign_expr	{$$ = $1;}
		|	bool_expr	{$$ = $1;}
		;


//赋值语句（得到ID的数值）
assign_expr	:	ID ASSIGN expr	{$$ = MakeExprNode("=");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;
								if(lookup_symbol($1->tree_value,symbol_list)==NULL){
									$1->type = "The variable is not declared!";
								}else{
									$1->type = lookup_symbol($1->tree_value,symbol_list);
								}
								}
			;

//布尔语句（得到布尔值）
bool_expr	:	expr EQ expr	{$$ = MakeExprNode("==");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr GE expr	{$$ = MakeExprNode(">=");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr LE expr	{$$ = MakeExprNode("<=");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr GT expr	{$$ = MakeExprNode(">");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr LT expr	{$$ = MakeExprNode("<");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr GREATER expr	{$$ = MakeExprNode(">>");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr LESS expr	{$$ = MakeExprNode("<<");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr  NE expr	{$$ = MakeExprNode("!=");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
			|	expr	{$$ = $1;}
			;

//表达式语句（得到一个数值）	
expr	:	expr ADD term	{$$ = MakeExprNode("+");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
		|	expr SUB term	{$$ = MakeExprNode("-");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
		|	expr MOD term	{$$ = MakeExprNode("%");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
		|	term	{$$ = $1;}
		;
			
term	:	term MUL factor	{$$ = MakeExprNode("*");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
		|	term DIV factor	{$$ = MakeExprNode("/");$$->child[0] = $1;$$->child[1] = $3;$$->lineno = lineno;}
		|	factor	{$$ = $1;}
		;
		
factor	:	ID	{$$ = $1;
				if(lookup_symbol($1->tree_value,symbol_list)==NULL){
					$$->type = "The variable is not declared!";
				}else{
					$$->type = lookup_symbol($1->tree_value,symbol_list);
				}
				}
		|	NUMBER	{$$ = $1;}
		|	LPACE expr RPACE	{$$ = $2;}
		;
%%

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
