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
		if (root == NULL) return 0;//情况1
		if (root->left == NULL && root->right == NULL)
			return sum * 10 + root->val;//情况2。访问节点，把父母及以上层的值乘以10，然后和当前节点值+
		else//情况3。把当前节点值和父母及以上层节点值*10，当做参数传递给下一层为下一层节点的：父母及以上层节点值。
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