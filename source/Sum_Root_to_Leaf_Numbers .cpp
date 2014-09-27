#include<iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode *root) {
		return sumAll(root, 0);
	}

	int sumAll(TreeNode *root, int sum) {
		if (root == NULL) return 0;//���1
		if (root->left == NULL && root->right == NULL)
			return sum * 10 + root->val;//���2�����ʽڵ㣬�Ѹ�ĸ�����ϲ��ֵ����10��Ȼ��͵�ǰ�ڵ�ֵ+
		else//���3���ѵ�ǰ�ڵ�ֵ�͸�ĸ�����ϲ�ڵ�ֵ*10�������������ݸ���һ��Ϊ��һ��ڵ�ģ���ĸ�����ϲ�ڵ�ֵ��
			return sumAll(root->left, sum * 10 + root->val)
			+ sumAll(root->right, sum * 10 + root->val);
	}
};

int main()
{
	TreeNode root(0);
	TreeNode *r;
	TreeNode l1(6);
	TreeNode l2(2);
	TreeNode r1(4);
	TreeNode r2(5);

	r=&root;
	root.right = &r1;
	root.right->right = &r2;
	root.left = &l1;
	root.left->left = &l2;
	Solution solu;
	cout<<solu.sumNumbers(r)<<endl;
	system("pause");

	return 0;
}