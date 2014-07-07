/*
	�ļ�������
	�������һЩ���ú������ϣ����ļ���Ҫʵ���˵�����Ĳ��룬��������ӡ�Ⱥ���
	���⣬�����˵�������ҵ�����k���ڵ㹦��,���ж�������ĵ�����0��ָ��Ϊβָ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


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
	struct ListNode * tmp = (ListNode*)malloc(sizeof(struct ListNode));
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
	struct ListNode * tmp = NULL;
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
	�������ܣ�������ľ͵�����
	����˵����
	@head���������ͷָ��
*/
void ListRevert(struct ListNode **head)
{
	struct ListNode * p = *head,*last = NULL,*tmp = NULL;

	while(p->next != NULL){
		tmp = p;
		tmp = tmp->next;//��¼����һ��ָ��
		p ->next = last;//����ǰ�ڵ�ָ��lastָ��
		last = p;//����lastָ��
		p = tmp;//����pָ��
	}
	p->next = last;//����βָ��
	last = p;//����
	*head = last;//���µ�ͷָ�븳ֵ��*headָ��
}
/*
	�������ܣ���ӡ������
*/
void PrintList(struct ListNode *head)
{
	struct ListNode * p = head;
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
	����˵����
	@heaed�������ͷָ��
	@k��������k���ڵ�
*/
ListNode* SearchKelem(ListNode*head,int k)
{
	struct ListNode *p1 = NULL,*p2 = NULL;
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
	����˵����
	@head1������1
	@head2������2
*/
struct ListNode *getFirstNode(struct ListNode * head1,struct ListNode *head2)
{
	int k = 0,i =0,j=0;
	struct ListNode *p1 = head1,*p2 = head2,*shortp=NULL,*longp=NULL;
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
/*
	�������ܣ��ж������Ƿ��л�
	����˵����
	@head�������ͷָ��
	@node�����صĻ����������ڵ�
	����ֵ��
	true��ʾ�������л�
	false��ʾ�������޻�
*/
bool isCircleList(struct ListNode *head,struct ListNode **node)
{
	assert(head != NULL);
	struct ListNode * low = head, *fast = head;
	do{
		low = low->next;//lowÿ����1��
		fast = fast->next;//fastÿ����2��
		if(fast != NULL)
			fast = fast->next;
	}while(low!=NULL && fast!=NULL && low != fast);
	if(low!=NULL && fast!=NULL && low == fast){
		*node = low;//����������ָ��
		return true;
	}else{
		*node = NULL;	
		return false;
	}
}
/*
	�������ܣ����һ�������д��ڻ�����⻷����ڵ�
	����˵����
	@head�������ͷָ��
	����ֵ��
	�л��������ڵ㣬����NULL(�������в����ڻ�ʱ)
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
	if(low!=NULL && fast!=NULL && low == fast)//������
		meet = fast;
	else//�޻����˳�
		return NULL;
	//lowָ��ָ��ͷ��meetָ�������㣬�����ߣ������ĵ�һ���ڵ���ǻ�����ڵ�
	low = head;
	while(low != meet){
		low = low->next ;
		meet = meet->next ;
	}
	return low;
}
/*
	�������ܣ�������������Ƿ��ཻ(���ⵥ�������Դ��ڻ�)
	����˵����
	@head1������1
	@head2������2
*/
bool isCrossed(ListNode*head1,ListNode*head2)
{
	bool f1=false,f2=false,flag = false;
	struct ListNode * first = NULL,*second = NULL,*tmp = NULL;
	int i = 0, len = 0;//len��ʾ������ĳ���
	assert(head1 != NULL && head2 != NULL);
	if(head1 ==  head2)//�ж�ͬһ����������
		return true;
	//1.�ж������Ƿ��л�
	f1 = isCircleList(head1,&first);
	f2 = isCircleList(head2,&second);
	//2.�����л������ҵ������㣬Ȼ����head2�в����Ƿ���ڴ˽ڵ㣬���������򷵻�
	if(f1 && f2){
		//���firstָ���Ƿ���������2��
		//��û�����ڵ�
		tmp = getCircleEntry(head2);
		second = tmp;
		//�ӻ�����ڵ㿪ʼ�ж��������Ƿ�����head2������
		//tmp != second��ʾδ�������ڵ�,tmp != first��ʾδ�ҵ�������
		while((flag == false || tmp != second) && tmp != first){
			flag = true;//���ñ�־λ
			tmp = tmp ->next;
		}//while
		if(tmp == first)
			return true;
		else
			return false;
	}else if(f1==false && f2==false){//3.���޻������ҵ����һ���ڵ��Ƿ�ָ����ͬ�Ľڵ�
		first = head1;
		second = head2;
		//�����������βָ��
		while(first->next != NULL)
			first = first->next;
		while(second->next != NULL)
			second = second->next;
		//�ж�βָ���Ƿ���ͬ����ͬ�򷵻�true
		if(first == second)
			return true;
		else
			return false;
	}else
		return false;//���������һ���л���һ���޻�������false
}
struct ListNode * head2 = NULL,*head3 = NULL,*head4 = NULL,*head5 = NULL;
int main()
{
	int i = 0,k=0;
	bool flag = false;
	ElementType a[]={1,2,3,4,5,6};
	ElementType b[]={-1,-2,9,8,0,12};
	ElementType c[]={0,1,2,34,8,4,2,14,10};
	ElementType d[]={-1,5,2,3,1};
	ElementType e[]={0,1,2,3,4,5};

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
	ListInsertList(tmp,p);//�����ཻ�ĵ�����head1��head2

	PrintList(head2);

	tmp = getFirstNode(head,head2);
	if(tmp != NULL){
		printf("first node is %d\n",tmp->value);
	}
	len = sizeof(c)/sizeof(c[0]);
	buildList(&head3,c,len);
	PrintList(head3);
	tmp = getFirstNode(head,head3);//head��head3���ཻ
	if(tmp != NULL){
		printf("first node is %d\n",tmp->value);
	}else{
		printf("not getFirstNode\n");
	}


	p = head3;
	tmp = head3;
	for(i=0;i<4;++i)
		tmp = tmp->next;
	while(p->next != NULL)//�ҵ�βָ��
		p = p->next;
	p->next = tmp;//���컷1

	p = getCircleEntry(head3);//��û�����ڵ�
	if(p!=NULL)
		printf("head3 circle Entry is %d\n",p->value);
	else
		printf("head3 not circle\n");
	
	p = getCircleEntry(head);//��û�����ڵ�
	if(p!=NULL)
		printf("head circle Entry is %d\n",p->value);
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
	buildList(&head4,d,len);//����������
	p = head4;
	while(p->next!=NULL)//�ҵ�βָ��
		p = p->next;
	tmp = head3;
	for(i=0;i<6;++i)
		tmp = tmp->next;//��ڵ�+1
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
	fflush(stdin);
	getchar();
}