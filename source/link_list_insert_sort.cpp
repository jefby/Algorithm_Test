#include <iostream>

using namespace std;

typedef struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL) {}
}ListNode;

ListNode *CreateListNode(int *a,int len)
{
	ListNode *head=NULL,*last=NULL,*p= NULL;
	int i=0;
	last = head;
	for(i=0;i<len;++i){
		p = (ListNode*)malloc(sizeof(ListNode));
		p->val = a[i];
		p->next = NULL;
		if(last == NULL){
			last = p;
			head = last;
		}else{		
			last->next = p;
			last = last->next;
		}
	}
	return head;
}
//²åÈëÅÅÐò
ListNode *insertionSortList(ListNode *head)
{
	if(head == NULL)  
		return NULL;  
	ListNode *helper = new ListNode(0);  
    ListNode *pre = helper;  
    ListNode *cur = head;  
    while(cur != NULL){  
		ListNode *next = cur->next;  
		pre = helper;  
        while(pre->next!=NULL && pre->next->val<=cur->val)   
			pre = pre->next;  
        cur->next = pre->next;  
        pre->next = cur;  
        cur = next;  
   }  
   return helper->next;  
}
void PrintList(ListNode *head)
{
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	int a[]={1,5,3,7,2,0};
	int n = sizeof(a)/sizeof(a[0]);
	ListNode *head = NULL,*res = NULL;
	head = CreateListNode(a,n);
	res = insertionSortList(head);

	PrintList(res);
	system("pause");
	return 0;
}