/*
	二叉查找树C语言实现
	Author : jefby
	Email : jef199006@gmail.com
*/

#include <stdio.h>

typedef int TElemType;

typedef struct bstNode{
	sturct bstNode * left,*right;
	TElemType val;
}BSTNode,*BSTree；

BSTree 
iterative_Tree_Search(BSTree x,TElemType k)
{
	while(x != NULL && k != x->val){
		if(k < x->val)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

TElemType 
tree_minimum(BSTree x)
{
	while(!x && x->left != NULL){
		x = x->left;
	}
	return x->val;
}
TElemType 
tree_maximum(BSTree x)
{
	while(!x && x->right != NULL){
		x = x->right;
	}
	return x->val;
}


int 
main()
{
	return 0;
}