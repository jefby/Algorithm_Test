#include <iostream>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
       if(root == NULL)
        return;
        TreeLinkNode *lastHead = root;//lastHead保存的是每一层的首地址
        TreeLinkNode *pre = NULL;
        TreeLinkNode *curHead = NULL;
        while(lastHead != NULL)
        {
            TreeLinkNode* lastCur = lastHead;
            while(lastCur != NULL)
            {
                if(lastCur->left!=NULL)//有左子树
                {
                    if(curHead == NULL)//当前头指针是NULL
                    {
                        curHead = lastCur->left;//保存上一次的左子树指针
                        pre = curHead;
                    }else{
                        pre->next = lastCur->left;
                        pre = pre->next;
                    }
                }
                if(lastCur->right!=NULL)//有右子树
                {
                    if(curHead == NULL)
                    {
                        curHead = lastCur->right;
                        pre = curHead;
                    }else{
                        pre->next = lastCur->right;
                        pre = pre->next;
                    }
                }                
                lastCur = lastCur->next;
            }
            lastHead = curHead;
            curHead = NULL;
        }
    }
};
void printTreeViaLevel(TreeLinkNode *root)
{
	TreeLinkNode *curHead=root,*next = NULL;
	while(curHead){
		if(curHead->left)
			next=curHead->left;
		else
			next=curHead->right;
			
		while(curHead != NULL){
			cout<<curHead->val<<" ";
			curHead = curHead->next;
		}
		cout<<endl;
		curHead=next;
	}

}
int main()
{
	TreeLinkNode root(1);
	TreeLinkNode left(2);
	TreeLinkNode right(3);
	TreeLinkNode *head = &root;
	//head->left=&left;
	head->right=&right;
	right.left=&left;

	Solution su;
	su.connect(head);
	printTreeViaLevel(head);
	system("pause");

}