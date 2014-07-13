/*
	��������:
	124#6###3##
	������������
	6->4->2->3->1->
	������������
	4->6->2->1->3->
	������������
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
	�������ܣ��������ڵ㣬�ݹ鴴��
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
	�������ܣ����ĺ���������ǵݹ�ʵ�֣�
	����˵����
	@root�����ĸ��ڵ�ָ��
*/

vector<int> PostOrderTraverse(TreeNode * root)
{
	vector<int> ivec;
	struct tagTreeNode{
		TreeNode *root;
		bool tag;//���ڱ���ҽڵ��Ƿ��Ѿ������ʹ�
		tagTreeNode(TreeNode*r,bool tag):root(r),tag(tag){};
	};
	
	stack<tagTreeNode>istack;
	struct tagTreeNode tmp(NULL,false);
	if(!root)//������Ϊ�յ����
		return ivec;
	while(root){//һ·�����ߣ�һֱ��ΪNULL
		istack.push(tagTreeNode(root,false));//�������ݽṹtagTreeNode(ָ��+tag)��tag��ʼ��Ϊfalse
		root=root->left;
	}
	while(!istack.empty()){//���ջ�ǿ�
		tmp = istack.top();//ȡ�����ڵ�
		while( tmp.tag == true || tmp.root->right == NULL){//���ýڵ������������������󣬵�ջ��������Ϊ�ջ����Ѿ����ʹ�����ʱ�������Ѿ�ΪNULL��
			ivec.push_back(tmp.root->val);//����vector��
			istack.pop();//��ջ
			if(istack.empty())//ջΪ���˳�
				break;
			tmp = istack.top();//ȡ�µĽڵ�
		}//while(tmp.tag == true || tmp.root->right == NULL)

		if(!istack.empty()){
			root=tmp.root;
			tmp.tag = true;//��Ƿ����˸ýڵ��������
			istack.pop();
			istack.push(tmp);//�޸ĺ�Ż�ջ��
			root = root->right;//����������
			while(root){//һֱ������
				istack.push(tagTreeNode(root,false));
				root = root->left;
			}//while(root)
		}//if(!istack.empty())
	}//while(!istack.empty())

	return ivec;
}
/*
	�������ܣ�����ǰ��������ǵݹ�ʵ�֣�
	����˵����
	@root�����ĸ��ڵ�ָ��
*/
vector<int> PreOrderTraverse(TreeNode * root)
{
		vector<int> ivec;
		stack<TreeNode*>istack;
		if(!root)//������Ϊ�յ����
			return ivec;
		while(root || !istack.empty()){
			while(root){
				istack.push(root);
				ivec.push_back(root->val);
				root=root->left;
			}//һֱ�����ߵ�ͷ
			root=istack.top();
			istack.pop();
			root = root->right;
		}
		return ivec;
}
/*
	�������ܣ���������������ǵݹ�ʵ�֣�
	����˵����
	@root�����ĸ��ڵ�ָ��
*/
vector<int> InOrderTraverse(TreeNode * root)
{
	vector<int> ivec;
	stack<TreeNode*>istack;
	if(!root)//������Ϊ�յ����
		return ivec;
	while(root || !istack.empty()){
		while(root){
			istack.push(root);
			root=root->left;
		}//һֱ�����ߵ�ͷ
		root=istack.top();
		ivec.push_back(root->val);
		istack.pop();
		root = root->right;
	}
	return ivec;
}
/*
	�������ܣ��ݹ�ĺ������
	����˵����
	@root�����ڵ�ָ��
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
	�������ܣ��ݹ��ǰ�����
	����˵����
	@root�������ڵ�ָ��

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
	�������ܣ��ݹ���������
	����˵����
	@root�����ڵ�ָ��
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
	�ؼ������ڣ��߶�ƽ��Ķ��������

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
	������ĸ߶�.
	����root=NULL�ĸ߶�Ϊ0��
*/
int height(TreeNode *root)//ʹ�õݹ鷽��������ĸ߶�
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
	�ж����Ƿ�Ϊƽ�������
*/
bool isBalanced(TreeNode *root) 
{
    if(!root)
		return true;
    int left = height(root->left);//���������ĸ߶�
    int right = height(root->right);//���������ĸ߶�
    if(abs(left-right)<=1)//����߶Ȳ����1��������ж�����������������
		return isBalanced(root->left)&&isBalanced(root->right);
    else
        return false;//���򷵻�false
}

TreeNode * root = NULL;
int main()
{
	vector<int>ivec;

	CreateTree(&root);
	cout<<"�������"<<endl;
	PostOrderTraverse_rec(root);//�������
	cout<<endl<<"�������"<<endl;
	PreOrderTraverse_rec(root);//�������
	cout<<endl<<"�������"<<endl;
	InOrderTraverse_rec(root);//�������

	ivec = PreOrderTraverse(root);//�������
	vector<int>::iterator it = ivec.begin();
	cout<<endl<<"�ǵݹ���������"<<endl;
	for(;it != ivec.end();++it)
		cout<<(char)*it<<"->";
	ivec = InOrderTraverse(root);
	it = ivec.begin();
	cout<<endl<<"�ǵݹ���������"<<endl;
	for(;it != ivec.end();++it)
		cout<<(char)*it<<"->";
	ivec = PostOrderTraverse(root);
	it = ivec.begin();
	cout<<endl<<"�ǵݹ�ĺ������"<<endl;
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
	PreOrderTraverse_rec(root);//�������
	#endif
	fflush(stdin);
	getchar();

}