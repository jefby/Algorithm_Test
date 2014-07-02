#include <stdio.h>

void myswap(int *a,int *b)
{
	int tmp = *a;
	if(a != b){
		*a = *b;
		*b = tmp;
	}
}
/*
	�������ܣ�ѡ������
	����˵����
	@a��Ҫ�������������ָ��
	@len��Ԫ�ظ���
*/
void select_sort(int *a,int len)
{
	int i = 0,j=0,min=0;
	for(i=0;i<len;++i){
		min = i;
		for(j=i+1;j<len;++j){
			if(a[j] < a[min])
				min = j;
		}
		if(min != i)
			myswap(&a[i],&a[min]);
	}
}
int main()
{
	int a[]={3,4,2,1,59,6,7};
	int i = 0;
	int len = sizeof(a)/sizeof(a[0]);
	select_sort(a,len);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	fflush(stdin);
	getchar();
}