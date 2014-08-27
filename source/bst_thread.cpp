/*
	测试数据:
	124#6###3##
	或者
	123#4#####
	后序遍历输出：
	6->4->2->3->1->
	中序遍历输出：
	4->6->2->1->3->
	先序遍历输出：
	1->2->4->6->3->

	中序遍历线索化二叉树

*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>//队列，用于辅助层次遍历

using namespace std;

//Link==0表示指向左右孩子指针，Thread==1表示指向前驱或者后继的线索
typedef enum{Link,Thread} PointerTag;
typedef int TElemType;

//线索化二叉树结点定义
typedef struct BiThrNode{
	TElemType val;
	BiThrNode *left;
	BiThrNode *right;
	PointerTag LTag;
	PointerTag RTag;//左右状态
	BiThrNode(int x):val(x),left(NULL),right(NULL),LTag(Link),RTag(Link){}//构造函数
}BiThrNode,*BiThrTree;

/*
	函数功能：创建根节点，递归创建
*/
void CreateTree(BiThrTree * root)
{
	char ch ;
	cin>>ch;
	if(ch == '#'){
		*root = NULL;
		return;
	}else{
		*root = (BiThrNode*)malloc(sizeof(BiThrNode));
		(*root)->val = ch;
		(*root)->LTag = Link;
		(*root)->RTag = Link;
		CreateTree(&(*root)->left);
		CreateTree(&(*root)->right);
	}
}

/*
	函数功能：递归的后序遍历
	参数说明：
	@root：根节点指针
*/
void PostOrderTraverse_rec(BiThrNode * root)
{
	if(!root)
		return;
	else{
		PostOrderTraverse_rec(root->left);
		PostOrderTraverse_rec(root->right);
		printf("%c->",root->val);
	}
}
/*
	函数功能：递归的前序遍历
	参数说明：
	@root：树根节点指针

*/
void PreOrderTraverse_rec(BiThrNode * root)
{
	if(!root)
		return;
	else{
		printf("%d->",root->val);
		PreOrderTraverse_rec(root->left);
		PreOrderTraverse_rec(root->right);
	}
}
/*
	函数功能：递归的中序遍历
	参数说明：
	@root：根节点指针
*/
void InOrderTraverse_rec(BiThrNode * root)
{
	if(!root)
		return;
	else{
		InOrderTraverse_rec(root->left);
		printf("%c->",root->val);
		InOrderTraverse_rec(root->right);
	}
}
BiThrTree pre;//全局变量，始终指向刚刚访问过的结点
/*
	中序遍历进行中序线索化
*/
void 
InThreading(BiThrTree p) 
{
	if(p){
		InThreading(p->left);//递归左子树线索化
		if(!p->left){//没有左孩子
			p->LTag = Thread;//前驱线索化
			p->left = pre;//左孩子指针指向前驱
		}
		if(pre && !pre->right){//前驱没有右孩子
			pre->RTag = Thread;//后继线索
			pre->right = p;//右孩子指针指向后继（当前节点p）
		}
		pre = p;//保持pre指向p的前驱
		InThreading(p->right);//递归右子树线索化
	}
}
/*
	中序线索化之后进行遍历，类似于双向链表。
*/
void 
InOrderTraverse_Thr(BiThrTree root)
{
	while(root != NULL){
		while(root->LTag == Link)//向左走
			root=root->left;
		printf("%c",root->val);
		while(root->RTag == Thread && root->right != NULL){
			root = root->right;
			printf("%c",root->val);
		}
		root=root->right;//root进其右子树根
	}
}
BiThrNode * root = NULL;

int main()
{
	vector<int>ivec;
	int i=0,j=0;

	CreateTree(&root);
	cout<<"后序遍历"<<endl;
	PostOrderTraverse_rec(root);//后序遍历
	cout<<endl<<"先序遍历"<<endl;
	PreOrderTraverse_rec(root);//先序遍历
	cout<<endl<<"中序遍历"<<endl;
	InOrderTraverse_rec(root);//中序遍历

	InThreading(root);//中序线索化
	InOrderTraverse_Thr(root);//遍历

	fflush(stdin);
	getchar();

}