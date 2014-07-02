/*
	文件描述：
	单链表的一些常用函数集合，本文件主要实现了单链表的插入，构建，打印等函数
	另外，增加了单链表查找倒数第k个节点功能,其中定义链表的倒数第0个指针为尾指针
*/
#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

struct ListNode{
	ElementType value;//节点值
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
	ListNode * tmp = (ListNode*)malloc(sizeof(struct ListNode));
	tmp->value = val;
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
	ListNode * tmp = NULL;
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
	函数功能：打印单链表
*/
void PrintList(struct ListNode *head)
{
	ListNode * p = head;
	while(p!=NULL){
		printf("%d ",p->value);
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
*/
ListNode* SearchKelem(ListNode*head,int k)
{
	ListNode *p1 = NULL,*p2 = NULL;
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
*/
ListNode *getFirstNode(struct ListNode * head1,struct ListNode *head2)
{
	int k = 0,i =0,j=0;
	ListNode *p1 = head1,*p2 = head2,*shortp=NULL,*longp=NULL;
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


ListNode * head2 = NULL,*head3 = NULL;
int main()
{
	int i = 0,k=0;
	ElementType a[]={1,2,3,4,5,6};
	ElementType b[]={-1,-2,9,8,0,12};
	ElementType c[]={0,1,2,34};
	struct ListNode * p = NULL,*tmp = NULL;
	int len = sizeof(a)/sizeof(a[0]);
	buildList(&head,a,len);
	PrintList(head);
	printf("请输入倒数第k个节点,k=");
	scanf("%d",&k);
	
	p = SearchKelem(head,k);
	
	if(p != NULL)
		printf("%d\n",p->value);
	else
		printf("k value error\n");

	len = sizeof(b)/sizeof(b[0]);
	buildList(&head2,b,len);
	p = head;
	for(i=0;i<3;++i)
		p=p->next;
	tmp = head2;
	while(tmp->next !=NULL)
		tmp = tmp->next;
	ListInsertList(tmp,p);//构造相交的单链表

	PrintList(head2);

	tmp = getFirstNode(head,head2);
	if(tmp != NULL){
		printf("first node is %d\n",tmp->value);
	}
	len = sizeof(c)/sizeof(c[0]);
	buildList(&head3,c,len);
	PrintList(head3);
	tmp = getFirstNode(head,head3);
	if(tmp != NULL){
		printf("first node is %d\n",tmp->value);
	}else{
		printf("not getFirstNode\n");
	}
	fflush(stdin);
	getchar();
}