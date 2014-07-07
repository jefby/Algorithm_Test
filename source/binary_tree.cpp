#include <iosteam>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}//构造函数
 };

 bool isSameTree(TreeNode *p, TreeNode *q)
 {
	 if(!p && !q)//全为NULL的情况
		 return true;
	 if((!p && p != q) || (!q && p != q))//其中有一个为NULL，而另一个不为NULL的情况
		 return false;
	 //两个都不为NULL的情况
	 if(p->val != q ->val)
		 return false;
	 else
		 return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
 }