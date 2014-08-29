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

*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>//队列，用于辅助层次遍历

using namespace std;
typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode;

/*
	函数功能：创建根节点，递归创建
*/
void CreateTree(TreeNode ** root)
{
	char ch ;
	cin>>ch;
	if(ch == '#'){
		*root = NULL;
		return;
	}else{
		*root = (TreeNode*)malloc(sizeof(TreeNode));
		(*root)->val = ch;
		CreateTree(&(*root)->left);
		CreateTree(&(*root)->right);
	}
}

/*
	函数功能：递归的后序遍历
	参数说明：
	@root：根节点指针
*/
void PostOrderTraverse_rec(TreeNode * root)
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
void PreOrderTraverse_rec(TreeNode * root)
{
	if(!root)
		return;
	else{
		printf("%d->",root->val);
		PreOrderTraverse_rec(root->left);
		PreOrderTraverse_rec(root->right);
	}
}

static int cnt = 0;
static int a[1001];
/*
	函数功能：递归的中序遍历
	参数说明：
	@root：根节点指针
*/
void InOrderTraverse_rec(TreeNode * root)
{
	if(!root)
		return;
	else{
		InOrderTraverse_rec(root->left);
		//printf("%c->",root->val);
		a[cnt++]=root->val;
		InOrderTraverse_rec(root->right);
	}
}

int 
compare (const void *elem1, const void *elem2 )
{
    return *(int*)elem1-*(int*)elem2;
}
unsigned int 
max_tree(TreeNode* root,int(*cmp)(const void *elem1, const void *elem2 ))
{
    InOrderTraverse_rec(root);
    qsort(a,cnt,sizeof(int),cmp);
    return a[cnt-1]-a[0];
}


TreeNode * root = NULL;
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
	cout<<max_tree(root,compare)<<endl;
	
	getchar();

}