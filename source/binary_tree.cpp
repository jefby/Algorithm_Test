#include <iosteam>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}//���캯��
 };

 bool isSameTree(TreeNode *p, TreeNode *q)
 {
	 if(!p && !q)//ȫΪNULL�����
		 return true;
	 if((!p && p != q) || (!q && p != q))//������һ��ΪNULL������һ����ΪNULL�����
		 return false;
	 //��������ΪNULL�����
	 if(p->val != q ->val)
		 return false;
	 else
		 return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
 }