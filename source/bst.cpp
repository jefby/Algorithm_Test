/*
	测试数据:
	124#6###3##
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

using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

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
	函数功能：树的后序遍历（非递归实现）
	参数说明：
	@root：树的根节点指针
*/

vector<int> PostOrderTraverse(TreeNode * root)
{
	vector<int> ivec;
	struct tagTreeNode{
		TreeNode *root;
		bool tag;//用于标记右节点是否已经被访问过
		tagTreeNode(TreeNode*r,bool tag):root(r),tag(tag){};
	};
	
	stack<tagTreeNode>istack;
	struct tagTreeNode tmp(NULL,false);
	if(!root)//处理树为空的情况
		return ivec;
	while(root){//一路向左走，一直到为NULL
		istack.push(tagTreeNode(root,false));//构造数据结构tagTreeNode(指针+tag)，tag初始化为false
		root=root->left;
	}
	while(!istack.empty()){//如果栈非空
		tmp = istack.top();//取树根节点
		while( tmp.tag == true || tmp.root->right == NULL){//当该节点的左右子树都访问完后，弹栈（右子树为空或者已经访问过，此时左子树已经为NULL）
			ivec.push_back(tmp.root->val);//存入vector中
			istack.pop();//出栈
			if(istack.empty())//栈为空退出
				break;
			tmp = istack.top();//取新的节点
		}//while(tmp.tag == true || tmp.root->right == NULL)

		if(!istack.empty()){
			root=tmp.root;
			tmp.tag = true;//标记访问了该节点的右子树
			istack.pop();
			istack.push(tmp);//修改后放回栈中
			root = root->right;//访问右子树
			while(root){//一直向左走
				istack.push(tagTreeNode(root,false));
				root = root->left;
			}//while(root)
		}//if(!istack.empty())
	}//while(!istack.empty())

	return ivec;
}
/*
	函数功能：树的前序遍历（非递归实现）
	参数说明：
	@root：树的根节点指针
*/
vector<int> PreOrderTraverse(TreeNode * root)
{
		vector<int> ivec;
		stack<TreeNode*>istack;
		if(!root)//处理树为空的情况
			return ivec;
		while(root || !istack.empty()){
			while(root){
				istack.push(root);
				ivec.push_back(root->val);
				root=root->left;
			}//一直向左走到头
			root=istack.top();
			istack.pop();
			root = root->right;
		}
		return ivec;
}
/*
	函数功能：树的中序遍历（非递归实现）
	参数说明：
	@root：树的根节点指针
*/
vector<int> InOrderTraverse(TreeNode * root)
{
	vector<int> ivec;
	stack<TreeNode*>istack;
	if(!root)//处理树为空的情况
		return ivec;
	while(root || !istack.empty()){
		while(root){
			istack.push(root);
			root=root->left;
		}//一直向左走到头
		root=istack.top();
		ivec.push_back(root->val);
		istack.pop();
		root = root->right;
	}
	return ivec;
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
		printf("%c->",root->val);
		InOrderTraverse_rec(root->right);
	}
}
/*
	Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
	关键点在于：高度平衡的二叉查找树

*/
TreeNode *sortedArrayToBST(vector<int>&num,int start,int end)
{
	if(start > end)
		return NULL;
	vector<int>::size_type mid = start + (end-start)/2;
	TreeNode *node = new TreeNode(num[mid]);
	node->left = sortedArrayToBST(num,start,mid-1);
	node->right = sortedArrayToBST(num,mid+1,end);
	return node;
}
TreeNode *sortedArrayToBST(vector<int> &num) 
{
	return sortedArrayToBST(num,0,num.size()-1);
}
/*
	求解树的高度.
	定义root=NULL的高度为0。
*/
int height(TreeNode *root)//使用递归方法求解树的高度
{
    if( root== NULL)
		return 0;
	int left = 0,right = 0;
    left = height(root->left)+1;
    right = height(root->right)+1;
	if(left < right)
		return right;
	else
		return left;
}
/*
	判断树是否为平衡二叉树
*/
bool isBalanced(TreeNode *root) 
{
    if(!root)
		return true;
    int left = height(root->left);//求左子树的高度
    int right = height(root->right);//求右子树的高度
    if(abs(left-right)<=1)//如果高度差不大于1，则继续判断其左子树和右子树
		return isBalanced(root->left)&&isBalanced(root->right);
    else
        return false;//否则返回false
}

TreeNode * root = NULL;
int main()
{
	vector<int>ivec;

	CreateTree(&root);
	cout<<"后序遍历"<<endl;
	PostOrderTraverse_rec(root);//后序遍历
	cout<<endl<<"先序遍历"<<endl;
	PreOrderTraverse_rec(root);//先序遍历
	cout<<endl<<"中序遍历"<<endl;
	InOrderTraverse_rec(root);//中序遍历

	ivec = PreOrderTraverse(root);//先序遍历
	vector<int>::iterator it = ivec.begin();
	cout<<endl<<"非递归的先序遍历"<<endl;
	for(;it != ivec.end();++it)
		cout<<(char)*it<<"->";
	ivec = InOrderTraverse(root);
	it = ivec.begin();
	cout<<endl<<"非递归的中序遍历"<<endl;
	for(;it != ivec.end();++it)
		cout<<(char)*it<<"->";
	ivec = PostOrderTraverse(root);
	it = ivec.begin();
	cout<<endl<<"非递归的后序遍历"<<endl;
	for(;it != ivec.end();++it)
		cout<<(char)*it<<"->";
	cout<<endl<<isBalanced(root)<<endl;;
	#if 0
	int a[]={1,2,3,4,5,6};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;
	for(i=0;i<len;++i)
		ivec.push_back(a[i]);
	root = sortedArrayToBST(ivec);
	PreOrderTraverse_rec(root);//先序遍历
	#endif
	fflush(stdin);
	getchar();

}