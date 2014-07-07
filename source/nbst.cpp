#include <stdio.h>
#include <stdlib.h>

/*
	��Ŀ������
	Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

	For example,
	Given n = 3, there are a total of 5 unique BST's.
	���˼�룺
	����������Ӧ��
	s[0] = 1
	s[1] = 1
	s[i] = sum{ s[j]*s[i-1-j]},0<=j<=i-1
*/
int nbst(int n)
{
	int i=0,j=0;
	if(n < 2){
		return 1;
	}
	int *a = (int*)calloc(n+1,sizeof(int));
	a[0] = 1;
	a[1] = 1;//��ʼֵ
	//����s[i],i>=2..n
	for(i=2;i<=n;++i){
		for(j=0;j<i;++j)
				a[i] += a[j] * a[i-j-1];//
	}//����a[n]
	i = a[n];//�ݴ���
	free(a);//�ͷ�������ڴ�
	return i;
}	
int main()
{
	int n = 0;
	scanf("%d",&n);
	printf("\n%d\n",nbst(n));
	fflush(stdin);
	getchar();
	
}