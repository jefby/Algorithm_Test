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
*/

vector<int> PostOrderTraverse(TreeNode * root)
{
	
		
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
		printf("%c->",root->val);
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

TreeNode * root = NULL;
int main()
{
	CreateTree(&root);
	cout<<"�������"<<endl;
	PostOrderTraverse_rec(root);//�������
	cout<<endl<<"�������"<<endl;
	PreOrderTraverse_rec(root);//�������
	cout<<endl<<"�������"<<endl;
	InOrderTraverse_rec(root);//�������
	fflush(stdin);
	getchar();

}