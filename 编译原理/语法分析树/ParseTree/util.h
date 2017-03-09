#ifndef _UTIL_H_
#define _UTIL_H_

TreeNode *MakeStmtNode(char *tree_value);

TreeNode *MakeIdlistNode();

TreeNode *MakeExprNode(char *tree_value);

TreeNode *MakeNumberNode(char *tree_value);

TreeNode *MakeIdNode(char *tree_value);

TreeNode *MakeTypeNode(char *tree_value); 

TreeNode *MakeNullNode();

void inorder(struct TreeNode* r,int height);

void typecheck(TreeNode* r);

Symbol *add_symbol(char *symbol_type, char *symbol_name, Symbol *symbol_list);

char *lookup_symbol(char *symbol_name, Symbol *symbol_list);

void gen_code(TreeNode* r);

void recursive_gen_code(TreeNode *t);

void gen_header();

void gen_decl(TreeNode *t);

void expr_gen_code(TreeNode *t);

void stmt_gen_code(TreeNode *t);

#endif
