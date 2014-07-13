/*
	文件描述：
	单链表的一些常用函数集合，本文件主要实现了单链表的插入，构建，打印等函数
	另外，增加了单链表查找倒数第k个节点功能,其中定义链表的倒数第0个指针为尾指针
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int ElementType;

struct ListNode{
	ElementType val;//节点值
	struct ListNode *next;//单链表，next指针
};

struct ListNode *head ;
/*
	函数功能：链表的初始化
	参数说明：
	@head：单链表头的指针地址
*/
void ListInit(struct ListNode **head)
{
	*head = NULL;
}
/*
	函数功能：头插法，在节点p所指向的地方插入一个值为val的节点
	参数说明：
	@p：要插入的节点指针
	@val：元素值
*/
ListNode* ListInsert(struct ListNode *p,ElementType val)
{
	struct ListNode * tmp = (ListNode*)malloc(sizeof(struct ListNode));
	tmp->val = val;
	tmp->next = p;
	p = tmp;
	return p;
}

/*
	函数功能：插入节点
	参数说明：
	@p：要插入的位置
	@insert：要插入的节点指针
*/
void ListInsertList(struct ListNode *p,struct ListNode *insert)
{
	struct ListNode * tmp = NULL;
	if(!p)
		p = insert;
	else{
		tmp = insert;
		while(tmp->next != NULL)//寻找insert起始的尾节点指针
			tmp =  tmp->next;
		tmp->next = p->next;//链接到p->next处
		p->next = insert;//链接p->next到insert
	}
}
/*
	函数功能：单链表的就地逆置
	参数说明：
	@head：单链表的头指针
*/
void ListRevert(struct ListNode **head)
{
	struct ListNode * p = *head,*last = NULL,*tmp = NULL;

	while(p->next != NULL){
		tmp = p;
		tmp = tmp->next;//记录下下一个指针
		p ->next = last;//将当前节点指向last指针
		last = p;//更新last指针
		p = tmp;//更新p指针
	}
	p->next = last;//处理尾指针
	last = p;//更新
	*head = last;//将新的头指针赋值给*head指针
}
/*
	函数功能：打印单链表
*/
void PrintList(struct ListNode *head)
{
	struct ListNode * p = head;
	while(p!=NULL){
		printf("%d ",p->val);
		p = p->next ;
	}
	printf("\n");
}
/*
	函数功能：构建单链表
	参数说明：
	@head：单链表头指针地址
	@a：数据元素数组指针
	@len：元素个数
*/
void buildList(struct ListNode **head,ElementType * a,int len)
{
	int i = 0;
	ListInit(head);//初始化链表
	for(i=0;i<len;++i)
		*head = ListInsert(*head,a[i]);//使用头插法将数据插入链表
}
/*
	函数功能：寻找单链表的倒数第k个节点，并输出此节点值
	参数说明：
	@heaed：链表的头指针
	@k：倒数第k个节点
*/
ListNode* SearchKelem(ListNode*head,int k)
{
	struct ListNode *p1 = NULL,*p2 = NULL;
	int i = 0;
	p1 = head;
	p2 = head;
	for(i=0;p2->next!=NULL&&i<k;++i)
		p2 = p2->next ;
	if(i==k){//如果k值大于等于链表的元素个数
		while(p2->next!=NULL){
			p2 = p2->next ;
			p1 = p1->next;
		}
		return p1;
	}else//如果k小于链表的元素个数则输出NULL
		return NULL;
}
/*
	函数功能：判断相交两个链表的第一个相交节点，暂时假设链表均为无环链表
	参数说明：
	@head1：链表1
	@head2：链表2
*/
struct ListNode *getFirstNode(struct ListNode * head1,struct ListNode *head2)
{
	int k = 0,i =0,j=0;
	struct ListNode *p1 = head1,*p2 = head2,*shortp=NULL,*longp=NULL;
	//计算链表1和2的长度
	while(p1 != NULL){
		p1 = p1->next;
		++i;
	}
	while(p2 != NULL){
		p2 = p2->next;
		++j;
	}
	//使用shortp指向较短的链表，longp指向较长的链表
	if(i>j){
		k = i-j;
		shortp = head2;
		longp = head1;
	}else{
		k = j-i;
		shortp = head1;
		longp = head2;
	}
	//较长的链表走k步
	while(k--)
		longp = longp->next;
	//查找第一个相交的节点，如果指针相同则退出循环
	while((longp!=NULL) && (shortp!=NULL) && (longp!=shortp)){
		longp = longp->next;
		shortp = shortp->next;
	}
	//找到则返回，否则退出
	if((longp!=NULL) && (shortp!=NULL) && (longp==shortp))
		return shortp;
	else
		return NULL;
}
/*
	函数功能：判断链表是否有环
	参数说明：
	@head：链表的头指针
	@node：返回的环链表相遇节点
	返回值：
	true表示链表中有环
	false表示链表中无环
*/
bool isCircleList(struct ListNode *head,struct ListNode **node)
{
	assert(head != NULL);
	struct ListNode * low = head, *fast = head;
	do{
		low = low->next;//low每次走1步
		fast = fast->next;//fast每次走2步
		if(fast != NULL)
			fast = fast->next;
	}while(low!=NULL && fast!=NULL && low != fast);
	if(low!=NULL && fast!=NULL && low == fast){
		*node = low;//返回相遇点指针
		return true;
	}else{
		*node = NULL;	
		return false;
	}
}
/*
	函数功能：如果一个链表中存在环，检测环的入口点
	参数说明：
	@head：链表的头指针
	返回值：
	有环链表的入口点，或者NULL(当链表中不存在环时)
*/
struct ListNode *getCircleEntry( struct ListNode* head)
{
	struct ListNode * low = head, *fast = head,*meet=NULL;
	assert(head != NULL);
	do{
		low = low->next;
		fast = fast->next;
		if(fast != NULL)
			fast = fast->next;
	}while(low!=NULL && fast!=NULL && low != fast);
	if(low!=NULL && fast!=NULL && low == fast)//相遇点
		meet = fast;
	else//无环，退出
		return NULL;
	//low指针指向头，meet指向相遇点，单步走，相遇的第一个节点就是环的入口点
	low = head;
	while(low != meet){
		low = low->next ;
		meet = meet->next ;
	}
	return low;
}
/*
	函数功能：检测两个链表是否相交(任意单链表，可以存在环)
	参数说明：
	@head1：链表1
	@head2：链表2
*/
bool isCrossed(ListNode*head1,ListNode*head2)
{
	bool f1=false,f2=false,flag = false;
	struct ListNode * first = NULL,*second = NULL,*tmp = NULL;
	int i = 0, len = 0;//len表示环链表的长度
	assert(head1 != NULL && head2 != NULL);
	if(head1 ==  head2)//判断同一个链表的情况
		return true;
	//1.判断链表是否有环
	f1 = isCircleList(head1,&first);
	f2 = isCircleList(head2,&second);
	//2.若均有环，则找到相遇点，然后在head2中查找是否存在此节点，若不存在则返回
	if(f1 && f2){
		//检测first指针是否属于链表2中
		//获得环的入口点
		tmp = getCircleEntry(head2);
		second = tmp;
		//从环的入口点开始判断相遇点是否属于head2链表中
		//tmp != second表示未到相遇节点,tmp != first表示未找到相遇点
		while((flag == false || tmp != second) && tmp != first){
			flag = true;//设置标志位
			tmp = tmp ->next;
		}//while
		if(tmp == first)
			return true;
		else
			return false;
	}else if(f1==false && f2==false){//3.若无环，查找到最后一个节点是否指向相同的节点
		first = head1;
		second = head2;
		//找两个链表的尾指针
		while(first->next != NULL)
			first = first->next;
		while(second->next != NULL)
			second = second->next;
		//判断尾指针是否相同，相同则返回true
		if(first == second)
			return true;
		else
			return false;
	}else
		return false;//其他情况（一个有环，一个无环）返回false
}

/*
	Lettcode题目：
	删除顺序链表中的重复元素

*/
ListNode *deleteDuplicates(ListNode *head) 
{
	ListNode * low = head,*fast = NULL;
	if(head == NULL)
		return NULL;
	fast = head->next;
	while(fast != NULL){
		while(fast != NULL && low->val == fast->val){//连续删除重复元素
			low->next = fast->next;
			fast = fast->next;
		}
		if(low != NULL){
			low = low->next;
			if(fast != NULL)
				fast = fast->next;
		}
	}
	return head;
}
/*
	题目描述：
	合并两个有序链表
*/
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
{
       ListNode *p1 = l1,*p2 = l2;
		ListNode *res = NULL,*tmp=NULL;
		if(p1==NULL&&p2 != NULL)
			return p2;
		if(p1!=NULL&&p2==NULL)
			return p1;
		if(p1==NULL&&p2==NULL)
			return NULL;
		if(p1->val <= p2->val){
			res = p1;
			p1=p1->next;
		}else{
			res = p2;
			p2=p2->next;
		}
		tmp = res;

		while(p1 != NULL && p2 != NULL){
			if(p1->val <= p2->val){
				tmp->next = p1;
				p1 = p1->next;
				tmp->next->next = NULL;
			}else{
				tmp->next = p2;
				p2 = p2->next;
			    tmp->next->next = NULL;
			}
			tmp = tmp->next;
		}
		if(p1 != NULL)
			tmp->next = p1;
		if(p2 != NULL)
			tmp->next = p2;
		return res;  
}

/*
	Swap Nodes in Pairs 
	Given a linked list, swap every two adjacent nodes and return its head.

	For example,
	Given 1->2->3->4, you should return the list as 2->1->4->3.

	Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

ListNode *swapPairs(ListNode *head) 
{
	   ListNode *p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;//p4指针用于保存两个节点的后一个，以便连接多个pair对
    	if(head == NULL || head->next == NULL)
    		return head;
    	p1 = head;
    	p2 = head->next ;
    	p3 = p2;//保存结果链表的起始地址
		ListNode *tmp = 0;
		
    	while(p1 != NULL && p2 != NULL){
			p1->next = p2->next;
    		p2->next = p1;
			tmp = p1;
			p1 =  p2;
			p2 = tmp;//交换两个指针
			if(p4)
				p4->next = p1;//连接两个pair对
			p4 = p2;//记录新的pair对位置
			if(p2->next){
				p2 = p2->next->next;//更新节点
				p1 = p1->next->next;
			}else
				p2 = p2->next;
    	}
        return p3; 
}
struct ListNode * head2 = NULL,*head3 = NULL,*head4 = NULL,*head5 = NULL,*head6 = NULL,*head7=NULL,*head8=NULL,*head9=NULL;
int main()
{
	int i = 0,k=0;
	bool flag = false;
	ElementType a[]={1,2,3,4,5,6};
	ElementType b[]={-1,-2,9,8,0,12};
	ElementType c[]={0,1,2,34,8,4,2,14,10};
	ElementType d[]={-1,5,2,3,1};
	ElementType e[]={0,1,2,3,4,5};
	ElementType f[]={1,1,2,2,3,4};

	ElementType g[]={5};
	ElementType h[]={4,2,1,6};

	struct ListNode * p = NULL,*tmp = NULL;
	int len = sizeof(a)/sizeof(a[0]);
	buildList(&head,a,len);
	PrintList(head);
	printf("请输入倒数第k个节点,k=");
	scanf("%d",&k);
	
	p = SearchKelem(head,k);
	
	if(p != NULL)
		printf("%d\n",p->val);
	else
		printf("k val error\n");

	len = sizeof(b)/sizeof(b[0]);
	buildList(&head2,b,len);
	p = head;
	for(i=0;i<3;++i)
		p=p->next;
	tmp = head2;
	while(tmp->next !=NULL)
		tmp = tmp->next;
	ListInsertList(tmp,p);//构造相交的单链表head1和head2

	PrintList(head2);

	tmp = getFirstNode(head,head2);
	if(tmp != NULL){
		printf("first node is %d\n",tmp->val);
	}
	len = sizeof(c)/sizeof(c[0]);
	buildList(&head3,c,len);
	PrintList(head3);
	tmp = getFirstNode(head,head3);//head和head3不相交
	if(tmp != NULL){
		printf("first node is %d\n",tmp->val);
	}else{
		printf("not getFirstNode\n");
	}


	p = head3;
	tmp = head3;
	for(i=0;i<4;++i)
		tmp = tmp->next;
	while(p->next != NULL)//找到尾指针
		p = p->next;
	p->next = tmp;//构造环1

	p = getCircleEntry(head3);//获得环的入口点
	if(p!=NULL)
		printf("head3 circle Entry is %d\n",p->val);
	else
		printf("head3 not circle\n");
	
	p = getCircleEntry(head);//获得环的入口点
	if(p!=NULL)
		printf("head circle Entry is %d\n",p->val);
	else
		printf("head not circle");

	if(isCircleList(head2,&tmp))
		printf("head2 has circle\n");
	else
		printf("head2 not circle\n");
	if(isCircleList(head3,&tmp))
		printf("head3 has circle\n");
	else
		printf("head3 not circle\n");	

	len = sizeof(d)/sizeof(d[0]);
	buildList(&head4,d,len);//构建单链表
	p = head4;
	while(p->next!=NULL)//找到尾指针
		p = p->next;
	tmp = head3;
	for(i=0;i<6;++i)
		tmp = tmp->next;//入口点+1
	p->next = tmp;
	
	//PrintList(head4);
	flag = isCrossed(head3,head4);
	if(flag == true)
		printf("crossed.\n");
	else
		printf("not crossed.\n");
	
	flag = isCrossed(head4,head4);
	if(flag == true)
		printf("crossed.\n");
	else
		printf("not crossed.\n");


	len = sizeof(e)/sizeof(e[0]);
	buildList(&head5,e,len);
	PrintList(head5);
	ListRevert(&head5);
	PrintList(head5);

	len = sizeof(f)/sizeof(f[0]);
	buildList(&head6,f,len);
	deleteDuplicates(head6);
	PrintList(head6);
#if 0
	len = sizeof(g)/sizeof(g[0]);
	buildList(&head7,g,len);

	PrintList(head7);

	len = sizeof(h)/sizeof(h[0]);
	buildList(&head8,h,len);

	PrintList(head8);
	head9=mergeTwoLists(head7,head8);
	PrintList(head8);
#endif
	len = sizeof(h)/sizeof(h[0]);
	buildList(&head8,h,len);
	PrintList(head8);
	head7 = swapPairs(head8);
	PrintList(head7);
	fflush(stdin);
	getchar();
}