/*
	二叉查找树C语言实现
	Author : jefby
	Email : jef199006@gmail.com
*/

#include <stdio.h>

typedef int TElemType;

//二叉搜索树数据结构定义
typedef struct bstNode{
	struct bstNode * left,*right,*p;//p表示父节点指针
	TElemType key;
}BSTNode,*BSTree;

//二叉搜索树头结点定义
typedef struct{
	BSTree root;
}BSTHeadNode,*BSTHead;

BSTHead
init_bstTree()
{
	BSTHead head = (BSTHead)malloc(sizeof(BSTHeadNode));
	head->root = NULL;//初始化root指针为NULL
}


BSTree 
iterative_Tree_Search(BSTree x,TElemType k)
{
	while(x != NULL && k != x->key){
		if(k < x->key)
			x = x->left;
		else
			x = x->right;
	}
	return x;
}

BSTree
tree_minimum(BSTree x)
{
	while(!x && x->left != NULL){
		x = x->left;
	}
	return x;
}
BSTree
tree_maximum(BSTree x)
{
	while(!x && x->right != NULL){
		x = x->right;
	}
	return x;
}

BSTree 
tree_successor(BSTree x)
{
	BSTree y;
	if(!x && x->right != NULL)
		return tree_minimum(x->right);
	//从节点x开始沿树而上直到遇到这样的一个结点：该结点是其双亲的左孩子
	y = x->p;
	while(y != NULL && x == y->right){
		x = y;
		y = y->p;
	}
	return y;
}

void 
tree_insert(BSTHead T,BSTree z)
{
	//x记录一条向下的简单路径，并查找要替换的输入项z的插入位置x , NULL
	BSTree y = NULL;
	BSTree x = T->root;
	while(x != NULL){
		y = x;
		if(z->key < x->key){
			x = x->left;
		}else
			x = x->right;
	}
	z->p = y;
	//插入结点z
	if(y == NULL)
		T->root = z;//tree was empty
	else if(z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

//用另一棵子树来替换一棵子树并成为其双亲的孩子结点。
//用一棵以v为根的子树来替换一棵以u为根的子树时，结点u的双亲就变为结点v的双亲，并且最后v成为u的双亲的相应孩子
//T是二叉搜索树指针
void 
transplant(BSTHead T,BSTree u,BSTree v)
{
	if(u->p == NULL)//处理u是树根的情况
		T->root = v;
	else if(u == u->p->left)//处理u是双亲的左孩子
		u->p->left = v;
	else//右孩子
		u->p->right = v;
	if(v != NULL)//如果v为非NULL，更新v->p,v.left和v.right由调用者负责
		v->p = u->p;
}

void
tree_delete(BSTHead T,BSTree z)
{
	BSTree y;
	if(z->left == NULL){//z没有左孩子
		transplant(T,z,z->right);
	}else if(z->right == NULL){//z有一个左孩子，但没有右孩子
		transplant(T,z,z->left);
	}else{//有两个孩子的情况
		y = tree_minimum(z->right);//查找z的后继，z的右子树非空
	}	
	if(y->p != z){//如果y不是z的左孩子，那么用y的右孩子替换y并成为y的双亲的一个孩子
		transplant(T,y,y->right);
		y->right = z->right;
		y->right->p = y;
	}
	transplant(T,z,y);
	y->left = z->left;
	y->left->p = y;
}

void 
inTree_transval(BSTree root)
{
	if(!root)
		return;
	inTree_transval(root->left);
	printf("%d->",root->key);
	inTree_transval(root->right);
}

int 
main()
{
	TElemType a[]={15,6,3,2,4,7,13,9,18,17,20};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;
	BSTree res = NULL;
	BSTHead head = init_bstTree();

	for(i=0;i<len;++i){
		res = iterative_Tree_Search(head->root,a[i]);
		if(!res){
			res = (BSTree)malloc(sizeof(BSTNode));
			res->right = NULL;
			res->left = NULL;
			res->p = NULL;
			res->key = a[i];
			tree_insert(head,res);
		}//如果未找到键为a[i]的结点则插入
	}
	inTree_transval(head->root);

	return 0;
}