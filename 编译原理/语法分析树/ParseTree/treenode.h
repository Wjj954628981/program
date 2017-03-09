#ifndef _TREENODE_H_
#define _TREENODE_H_


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct TreeNode{
	char *tree_type;
	char *tree_value;
	int lineno;
	char *type;
	struct TreeNode *child[5];
}TreeNode;

typedef struct Symbol{
	char *symbol_type;
	char *symbol_name;
	int symbol_value;
	struct Symbol *next;
}Symbol;

#endif
