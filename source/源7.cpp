/*
	��Ŀ����
	����10��������������λ�ϵĺʹ�С�������������ͬ�������ִ�С��������
	��������
	10������������֤����int��Χ�ڣ��ÿո����
	�������
	10�����֣���Ӵ�С��ֵ���ÿո���������һ�����ֺ󲻼ӿո�
*/
#include <stdio.h>
#include <stdlib.h>

void myswap(int *a,int *b)
{
	int tmp = *a;
	if(a != b){
		*a = *b;
		*b = tmp;
	}
}
/*
	�������ܣ�������ֵn��λ����
*/
int bitsum(int n)
{
	int m = 0;
	if(n < 0)
		return 0;
	do{
		m += n%10;
		n = n/10;
	}while(n);
	return m;
}

void mysort(int *a,int len)
{
	int i = 0,j=0;
	int tmp[10]={0};
	int min = 0;

	if(len != 10)//�����ֵԪ�ظ���
		return;
	for(i=0;i<len;++i)//��λ����,�����浽tmp������
		tmp[i] = bitsum(a[i]);
	for(i=0;i<len;++i){//ѡ������
		min = i;
		for(j=i+1;j<len;++j){
			if(tmp[j] < tmp[min])
				min = j;
			else if(tmp[j] == tmp[min]){//���λ������ͬ����Ƚ�ԭʼ��ֵ
				if(a[j] < a[min])//����ԭʼ��ֵ�Ƚ�,С�ľ������ȼ�
					min = j;
			}//else if
		}//for(j=i+1;j<len;++j)
		if(min != i){
			myswap(&a[i],&a[min]);
			myswap(&tmp[i],&tmp[min]);
		}//if(min != i)
	}//for(i=0;i<len;++i)
}
int main()
{
	int a[10];
	int i = 0;
	scanf("%d %d %d %d %d %d %d %d %d %d" ,&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
	mysort(a,10);
	for(i=0;i<10;++i)
		printf("%d ",a[i]);
	fflush(stdin);
	getchar();
}