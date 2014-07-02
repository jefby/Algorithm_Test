/*
	�ļ�������
	�������һЩ���ú������ϣ����ļ���Ҫʵ���˵�����Ĳ��룬��������ӡ�Ⱥ���
	���⣬�����˵�������ҵ�����k���ڵ㹦��,���ж�������ĵ�����0��ָ��Ϊβָ��
*/
#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

struct ListNode{
	ElementType value;//�ڵ�ֵ
	struct ListNode *next;//������nextָ��
};

struct ListNode *head ;
/*
	�������ܣ�����ĳ�ʼ��
	����˵����
	@head��������ͷ��ָ���ַ
*/
void ListInit(struct ListNode **head)
{
	*head = NULL;
}
/*
	�������ܣ�ͷ�巨���ڽڵ�p��ָ��ĵط�����һ��ֵΪval�Ľڵ�
	����˵����
	@p��Ҫ����Ľڵ�ָ��
	@val��Ԫ��ֵ
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
	�������ܣ�����ڵ�
	����˵����
	@p��Ҫ�����λ��
	@insert��Ҫ����Ľڵ�ָ��
*/
void ListInsertList(struct ListNode *p,struct ListNode *insert)
{
	ListNode * tmp = NULL;
	if(!p)
		p = insert;
	else{
		tmp = insert;
		while(tmp->next != NULL)//Ѱ��insert��ʼ��β�ڵ�ָ��
			tmp =  tmp->next;
		tmp->next = p->next;//���ӵ�p->next��
		p->next = insert;//����p->next��insert
	}
}
/*
	�������ܣ���ӡ������
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
	�������ܣ�����������
	����˵����
	@head��������ͷָ���ַ
	@a������Ԫ������ָ��
	@len��Ԫ�ظ���
*/
void buildList(struct ListNode **head,ElementType * a,int len)
{
	int i = 0;
	ListInit(head);//��ʼ������
	for(i=0;i<len;++i)
		*head = ListInsert(*head,a[i]);//ʹ��ͷ�巨�����ݲ�������
}
/*
	�������ܣ�Ѱ�ҵ�����ĵ�����k���ڵ㣬������˽ڵ�ֵ
*/
ListNode* SearchKelem(ListNode*head,int k)
{
	ListNode *p1 = NULL,*p2 = NULL;
	int i = 0;
	p1 = head;
	p2 = head;
	for(i=0;p2->next!=NULL&&i<k;++i)
		p2 = p2->next ;
	if(i==k){//���kֵ���ڵ��������Ԫ�ظ���
		while(p2->next!=NULL){
			p2 = p2->next ;
			p1 = p1->next;
		}
		return p1;
	}else//���kС�������Ԫ�ظ��������NULL
		return NULL;
}

/*
	�������ܣ��ж��ཻ��������ĵ�һ���ཻ�ڵ㣬��ʱ���������Ϊ�޻�����
*/
ListNode *getFirstNode(struct ListNode * head1,struct ListNode *head2)
{
	int k = 0,i =0,j=0;
	ListNode *p1 = head1,*p2 = head2,*shortp=NULL,*longp=NULL;
	//��������1��2�ĳ���
	while(p1 != NULL){
		p1 = p1->next;
		++i;
	}
	while(p2 != NULL){
		p2 = p2->next;
		++j;
	}
	//ʹ��shortpָ��϶̵�����longpָ��ϳ�������
	if(i>j){
		k = i-j;
		shortp = head2;
		longp = head1;
	}else{
		k = j-i;
		shortp = head1;
		longp = head2;
	}
	//�ϳ���������k��
	while(k--)
		longp = longp->next;
	//���ҵ�һ���ཻ�Ľڵ㣬���ָ����ͬ���˳�ѭ��
	while((longp!=NULL) && (shortp!=NULL) && (longp!=shortp)){
		longp = longp->next;
		shortp = shortp->next;
	}
	//�ҵ��򷵻أ������˳�
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
	printf("�����뵹����k���ڵ�,k=");
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
	ListInsertList(tmp,p);//�����ཻ�ĵ�����

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