/*
	����������
	Top K����
	����1��ʹ�ÿ�������Ȼ�����ǰK��Ԫ�ؼ���

*/
#include <stdio.h>
#include <stdlib.h>


#define CONFIG_ONE

#if defined(CONFIG_ONE)
int len = 0;
void swap(int *a,int*b)
{
	int tmp = *a;
	if(a != b){//�����ͬԪ��
		*a = *b;
		*b = tmp;
	}
}

/*
	��������������ԭ�ػ���������,������ŦԪ�ص��±�
	������
		@a : ��������ָ��
		@p : ��ʼ��ַ
		@r : ������ַ
	˵����
	a[p..i]��ʾ����С����ŦԪ��a[r]��ֵ
	a[j..r]��ʾ���Ǵ�����ŦԪ��a[r]��ֵ

*/
int partition(int *a,int p,int r)
{
	int pivot=0,i=0,j=0;
	/*
	printf("p=%d,r=%d\n",p,r);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	*/
	pivot = a[r];
	i = p-1;
	for(j=p;j<r;++j)
		if(a[j]<=pivot){//jָ���Ԫ�ض�����pivot,iָ���Ԫ�ض�С��pivot
			i=i+1;
			swap(&a[i],&a[j]);//����a[i]��a[j]
		}
	swap(&a[i+1],&a[r]);//������ŦԪ��
	//printf("partition\n");
	return i+1;
}
/*
	��������������,�ο��㷨����
	����:
		@a :����ָ��
		@p :��ʼλ��
		@r :����λ��

*/
void quicksort(int *a,int p,int r)
{
	int q;
	if(p < r){
		q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q,r);
	}
}

//�ȽϺ���
int cmp(const void * a,const void *b)
{
	return *(int*)a-*(int*)b;
}
void topk(int a[],int len,int k)
{
	int i = 0;
	if(k<0 || k > len)
		return;
	printf("len=%d\n",len);
	qsort(a,len,sizeof(a[0]),cmp);//ʹ��qsort���п�������
	for(i=0;i<k;++i)//���ǰK��Ԫ��
		printf("%d ",a[i]);
	printf("\n");
}
#endif
int main()
{
	int i=0;
	int  a[]={1,0,2,10,100,1000,999,88};
	len = sizeof(a)/sizeof(a[0]);

	quicksort(a,0,len-1);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	topk(a,len,2);
	getchar();
}