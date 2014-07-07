/*
         ��������
         ���Ӷ���O(n*n)
*/
#include <stdio.h>
/*
	�����㷨���ۣ�
	for j <- 2 to  length(A)
		do key <- A[j]
		//����A[j]�������������A[1...j-1]��
		i < j-1
		while i > 0 and A[i] > key
			do A[i+1] <- A[i]
			i <- i-1
		A[i+1] = key

	 ������
		@ a ������ָ��
		@ n �����鳤��
		@ fcmp : �ȽϺ���,����*op1-*op2>0
	 �޷���ֵ
*/

void insert_sort(int *a,int n,int(*fcmp)(const void *op1,const void *op2))
{
	int i,j,key;
	for(j=1;j<n;++j){
		key = a[j];
//insert A[j] into the sorted sequence A[0...j-1],��������
		for(i=j-1;i>=0&&(fcmp(&a[i],&key)>0);--i)
			a[i+1]=a[i];
		a[i+1] = key;
	}
}
//��������
int fcmp1(const void *op1,const void *op2)
{
	return *(int*)op1 - *(int*)op2;
}
//�ݼ�����
int fcmp2(const void *op1,const void *op2)
{
	return *(int*)op2 - *(int*)op1;
}
	
int main()
{
	int i;
	int a[]={3,1,2,4,5,9,0};
	int length = sizeof(a)/sizeof(a[0]);
	insert_sort(a,length,fcmp1);
	for(i=0;i<length;++i)
		printf("%d ",a[i]);
	getchar();
	return 0;
}