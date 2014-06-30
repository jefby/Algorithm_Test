/*
	������O(n*logn)
	�����鶨�壺���±�1��ʼ���±�0�洢��Ԫ�ظ���

*/
#include <stdio.h>


//#define MAX_HEAP
#define MIN_HEAP
/*�йضѵ�һЩ����*/
#define PARENT(i) ((i)/2)
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)

/*����Ԫ��*/
void swap(int *a,int *b)
{
	int tmp = *a;
	if(a!=b){
		*a = *b;
		*b = tmp;
	}
}
/*
	�������ܣ��ѵ�������������iΪroot�Ķѵ���Ϊ����
	����˵����
		@a : ָ��
		@i : ���ڵ��±�����ֵ
*/
void max_heapify(int *a,int i)
{
	int largest = 0;//�洢��ǰ����ֵ�����±�
	int l = LEFT(i);//��ڵ�
	int r = RIGHT(i);//�ҽڵ�
	if(l <= a[0] && a[l] > a[i])//����ڶ��У�����a[l]>a[i],�������������ԣ�����
		largest = l;
	else
		largest = i;
	if(r <= a[0] && a[r] > a[largest])//������ڶ��У�����a[r]>a[largest],���������ѵ�����
		largest = r;
	
	if(largest != i){//���ֵ�����±겻��i���򽻻����ڵ㴦��ֵ��Ȼ�����µݹ������
		swap(&a[largest],&a[i]);//������Ԫ��	
		max_heapify(a,largest);//�ݹ������largestΪroot�Ķ�
	}
}
/*
	�������ܣ���������,a[0]��ʾ��Ԫ�ظ���
	������
	@a : ����ָ��
	@len : ����Ԫ�ظ���
*/
void build_maxheap(int *a,int len)
{
	int i = 0;
	a[0] = len;//��Ԫ�ظ���

	for(i=len/2;i>0;--i)
		max_heapify(a,i);
}

/*
	�������ܣ���С�ѵ�������������iΪroot�Ķѵ���Ϊ��С��
	����˵����
		@a : ָ��
		@i : ���ڵ��±�����ֵ
*/
void min_heapify(int *a,int i)
{
	int least = 0;//�洢��ǰ����ֵ��С���±�
	int l = LEFT(i);//��ڵ�
	int r = RIGHT(i);//�ҽڵ�
	if(l <= a[0] && a[l] < a[i])//����ڶ��У�����a[l]>a[i],��������С�����ԣ�����
		least = l;
	else
		least = i;
	if(r <= a[0] && a[r] < a[least])//������ڶ��У�����a[r]>a[largest],��������С�ѵ�����
		least = r;
	
	if(least != i){//���ֵ�����±겻��i���򽻻����ڵ㴦��ֵ��Ȼ�����µݹ������
		swap(&a[least],&a[i]);//������Ԫ��	
		min_heapify(a,least);//�ݹ������largestΪroot�Ķ�
	}
}
/*
	�������ܣ���������,a[0]��ʾ��Ԫ�ظ���
	������
	@a : ����ָ��
	@len : ����Ԫ�ظ���
*/
void build_minheap(int *a,int len)
{
	int i = 0;
	a[0] = len;//��Ԫ�ظ���

	for(i=len/2;i>0;--i)
		min_heapify(a,i);
}
/*
	������ʵ�֣�˼·��
	ÿ��ѡȡ���ڵ㣬Ȼ����������һ��Ԫ�ػ������ݼ���Ԫ�ظ����������ѡ�
	����˵����
	@a : ����ָ��
	@len : ����Ԫ�ظ���
*/
void heap_sort(int *a,int len)
{
	int i = 0;
#if defined(MAX_HEAP)
	build_maxheap(a,len);//��������
#else 
	build_minheap(a,len);//������С��
#endif
	for(i=len;i>1;--i){
		swap(&a[1],&a[i]);//�������һ��Ԫ��
		--a[0];//heapsize -= 1
#if defined(MAX_HEAP)
		max_heapify(a,1);//��������
#else
		min_heapify(a,1);//������С��
#endif
	}		
}

int main()
{
	int i = 0;
	int a[]={0,2,3,4,5,1,-1,10};
	int len = (sizeof(a))/sizeof(a[0])-1;
	heap_sort(a,len);
	for(i=1;i<len+1;++i)
		printf("%d ",a[i]);
	getchar();

}