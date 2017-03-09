#include "treenode.h"
#include "util.h"

TreeNode *MakeStmtNode(char *tree_value){
	
	struct TreeNode *pt=(struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	
	pt->tree_value = (char *)malloc(strlen(tree_value)+1);
	strcpy(pt->tree_value, tree_value);
	
	pt->tree_type = "Statement";

	pt->lineno = NULL;

	pt->type = "";

	for(int i=0;i<5;i++){
		pt->child[i] = NULL;
	}
	
	return pt;
}

TreeNode *MakeIdlistNode(){

	struct TreeNode *pt = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	pt->tree_value = ",";

	pt->tree_type = "Idlist";

	pt->lineno = NULL;

	pt->type = "";

	for (int i = 0; i<5; i++){
		pt->child[i] = NULL;
	}

	return pt;
}

TreeNode *MakeExprNode(char *tree_value){
	
	struct TreeNode *pt=(struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	
	pt->tree_value = (char *)malloc(strlen(tree_value)+1);
	strcpy(pt->tree_value, tree_value);
	
	pt->tree_type = "Expr";

	pt->lineno = NULL;

	pt->type = "";

	for(int i=0;i<5;i++){
		pt->child[i] = NULL;
	}
	
	return pt;
}

TreeNode *MakeNumberNode(char *tree_value){

	struct TreeNode *pt = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	pt->tree_value = (char *)malloc(strlen(tree_value) + 1);
	strcpy(pt->tree_value, tree_value);

	pt->tree_type = "Number";

	pt->lineno = NULL;

	pt->type = "";

	for (int i = 0; i<5; i++){
		pt->child[i] = NULL;
	}

	return pt;
}

TreeNode *MakeIdNode(char *tree_value){
	
	struct TreeNode *pt=(struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	
	pt->tree_value = (char *)malloc(strlen(tree_value)+1);
	strcpy(pt->tree_value, tree_value);
	
	pt->tree_type = "Id";

	pt->lineno = NULL;

	pt->type = "";

	for(int i=0;i<5;i++){
		pt->child[i] = NULL;
	}
	
	return pt;
}


TreeNode *MakeTypeNode(char *tree_value){
	
	struct TreeNode *pt=(struct TreeNode*)malloc(sizeof(struct TreeNode)); 
	
	pt->tree_value = (char *)malloc(strlen(tree_value)+1);
	strcpy(pt->tree_value, tree_value);
	
	pt->tree_type = "Type";
	
	pt->lineno = NULL;

	pt->type = "";

	for(int i=0;i<5;i++){
		pt->child[i] = NULL;
	}
	
	return pt;
}

TreeNode *MakeNullNode(){

	struct TreeNode *pt = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	pt->tree_value = "NULL";

	pt->lineno = NULL;

	pt->tree_type = "NullNode";

	pt->type = "";

	for (int i = 0; i<5; i++){
		pt->child[i] = NULL;
	}

	return pt;
}

void inorder(TreeNode* r, int height){
	if (r != NULL){
		printf("%d", r->lineno);
		for (int i = 0; i < height; i++){
			printf("   ");
		}
		printf("%s[%s]  %s\n", r->tree_type, r->tree_value, r->type);
		for (int i = 0; i < 5; i++){
			inorder(r->child[i],height + 1);
		}
	}
}



Symbol *add_symbol(char *symbol_type, char *symbol_name, Symbol *symbol_list){

	struct Symbol *al;

	al = (struct Symbol *)malloc(sizeof(struct Symbol));

	al->next = symbol_list;

	al->symbol_type = (char *)malloc(strlen(symbol_type) + 1);
	strcpy(al->symbol_type, symbol_type);

	al->symbol_name = (char *)malloc(strlen(symbol_name) + 1);
	strcpy(al->symbol_name, symbol_name);

	al->symbol_value = NULL;

	symbol_list = al;

	return al;
}

char *lookup_symbol(char *symbol_name, Symbol *symbol_list){

	struct Symbol *al = symbol_list;

	for (; al; al = al->next){
		if (strcmp(al->symbol_name, symbol_name) == 0)
			return al->symbol_type;
	}

	return NULL;
}

void typecheck(TreeNode* r){
	if (r != NULL){

		for (int i = 0; i < 5; i++){
			typecheck(r->child[i]);
		}

		if (strcmp(r->tree_type,"Expr")==0){
			if (strcmp(r->tree_value, "+") == 0 || strcmp(r->tree_value, "-") == 0 || strcmp(r->tree_value, "*") == 0 || strcmp(r->tree_value, "/") == 0 || strcmp(r->tree_value, "=") == 0){
				if (strcmp(r->child[0]->type, "Integer") == 0 && strcmp(r->child[1]->type, "Integer") == 0){
					r->type = "Integer";
				}
				if (strcmp(r->child[0]->type, "Character") == 0 && strcmp(r->child[1]->type, "Character") == 0){
					r->type = "Character";
				}
				if (strcmp(r->child[0]->type, "Boolean") == 0 && strcmp(r->child[1]->type, "Boolean") == 0){
					r->type = "Boolean";
				}
				if (strcmp(r->child[0]->type, r->child[1]->type) != 0){
					r->type = "OP no match";
				}
				if (strcmp(r->child[0]->type, r->child[1]->type) != 0){
					r->type = "Op no match";
				}
			}
			if (strcmp(r->tree_value, "==") == 0 || strcmp(r->tree_value, "!=") == 0 || strcmp(r->tree_value, ">") == 0 || strcmp(r->tree_value, "<") == 0 || strcmp(r->tree_value, ">=") == 0 || strcmp(r->tree_value, "<=") == 0 || strcmp(r->tree_value, ">>") == 0 || strcmp(r->tree_value, "<<") == 0){
				r->type = "Boolean";
			}
		}

		if (strcmp(r->tree_type, "Statement")==0){
			if (strcmp(r->tree_value, "if") == 0 || strcmp(r->tree_value, "while") == 0){
				if (strcmp(r->child[0]->type, "Boolean") != 0 && strcmp(r->child[0]->type, "Integer") != 0){
					r->type = "if or while test is not Boolean or Integer";
				}
			}
		}
	}
}

void gen_code(TreeNode* r){
	gen_header();
	printf(".data\n");
	printf("\tdata1 db '%%d', 0 \n");
	if (strcmp(r->child[1]->child[0]->tree_value, "declare")==0){
		gen_decl(r->child[1]->child[0]);
	}
	printf(".code\n");
	printf("start:\n");
	recursive_gen_code(r->child[1]->child[1]);
	printf("ret\n");
	printf("end start \n");
}

void gen_header(){
	printf(".386\n");
	printf(".model flat, stdcall\n");
	printf("\n");
	printf("include \\masm32\\include\\msvcrt.inc\n");
	printf("\n");
	printf("includelib \\masm32\\lib\\msvcrt.lib\n");
	printf("\n");
}

void gen_decl(TreeNode *t){
	if (t != NULL){
		/*if (strcmp(t->tree_type, "Statement")){
			gen_decl(t->child[1]);
		}*/
		//if (strcmp(t->tree_type, "Idlist") == 0){
			gen_decl(t->child[0]);
			gen_decl(t->child[1]);
		//}
		if (strcmp(t->tree_type, "Id")==0){
			printf("\t%s",t->tree_value);
			printf(" dd ?\n");
		}
		if (strcmp(t->tree_type, "Expr") == 0){
			printf("\t%s", t->child[0]->tree_value);
			printf(" dd ");
			printf("%s\n",t->child[1]->tree_value);
		}
	}
}

void recursive_gen_code(TreeNode *t){
	if (t != NULL){
		if (strcmp(t->tree_type, "Expr") == 0){
			recursive_gen_code(t->child[1]);
			expr_gen_code(t);
		}
		if (strcmp(t->tree_type, "Statement") == 0 && strcmp(t->tree_value, "{}") != 0){
			stmt_gen_code(t);
		}
		if (strcmp(t->tree_type, "Statement") == 0 && strcmp(t->tree_value, "{}") == 0){
			recursive_gen_code(t->child[0]);
			recursive_gen_code(t->child[1]);
		}
	}
}

void expr_gen_code(TreeNode *t){
	TreeNode *t1 = t->child[0];
	TreeNode *t2 = t->child[1];
	if (strcmp(t->tree_value, "+")==0){
		printf("\tmov eax,");
		printf("%s\n",t1->tree_value);
		printf("\tadd eax,");
		printf("%s\n", t2->tree_value);
	}
	if (strcmp(t->tree_value, "-") == 0){
		printf("\tmov eax,");
		printf("%s\n", t1->tree_value);
		printf("\tsub eax,");
		printf("%s\n", t2->tree_value);
	}
	if (strcmp(t->tree_value, "*") == 0){
		printf("\tmov eax,");
		printf("%s\n", t1->tree_value);
		printf("\tmul eax,");
		printf("%s\n", t2->tree_value);
	}
	if (strcmp(t->tree_value, "/") == 0){
		printf("\tmov edx,0\n");
		printf("\tmov eax,");
		printf("%s\n", t1->tree_value);
		printf("\tmov ecx,");
		printf("%s\n", t2->tree_value);
		printf("\tdiv ecx\n");
	}
	if (strcmp(t->tree_value, "%") == 0){
		printf("\tmov edx,0\n");
		printf("\tmov eax,");
		printf("%s\n", t1->tree_value);
		printf("\tmov ecx,");
		printf("%s\n", t2->tree_value);
		printf("\tdiv ecx\n");
		printf("\tmov eax,edx\n");
	}

	if (strcmp(t->tree_value, "=") == 0){
		if (strcmp(t2->tree_type, "Expr") == 0){
			printf("\tmov ");
			printf("%s", t1->tree_value);
			printf(",eax\n");
		}
		else{
			printf("\tmov eax,");
			printf("%s\n",t2->tree_value);
			printf("\tmov ");
			printf("%s", t1->tree_value);
			printf(",eax\n");
		}
	}
	if (strcmp(t->tree_value, "<") == 0){
		printf("\tmov eax,");
		printf("%s\n", t1->tree_value);
		printf("\tcmp eax,");
		printf("%s\n", t2->tree_value);
		printf("\tjl @1\n");
		printf("\tjmp @2\n");
	}
}

void stmt_gen_code(TreeNode *t){
	if (strcmp(t->tree_value, "while") == 0){
		printf("@0:\n");
		recursive_gen_code(t->child[0]);
		printf("@1:\n");
		recursive_gen_code(t->child[1]);
		printf("\tjmp @0\n");
		printf("@2:\n");
	}
	if (strcmp(t->tree_value, "print") == 0){
		printf("\tinvoke crt_printf, addr data1, ");
		printf("%s\n",t->child[0]->tree_value);
	}
	if (strcmp(t->tree_value, "input") == 0){
		printf("\tinvoke crt_scanf, addr data1, addr ");
		printf("%s\n", t->child[0]->tree_value);
	}
	if (strcmp(t->tree_value, "if") == 0){
		recursive_gen_code(t->child[0]);
		printf("ifentity:\n");
		recursive_gen_code(t->child[1]);
		if (t->child[2] != NULL){
			recursive_gen_code(t->child[2]);
		}
	}
}
