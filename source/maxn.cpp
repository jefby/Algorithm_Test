/*
	��Ŀ������
	��һ������Ϊ100����𣬸�30����Ʒ��ÿ����Ʒ�������֪�������װ���ٸ���Ʒ�����
	����������
	һ��30�����������ÿո��������ʾÿ����Ʒ�����
	���������
	һ�����֣�Ϊ�����װ�µ���Ʒ��
	˼·��
	���������洢ÿ����Ʒ��������ȴ�С����������ɺ�ݼӺͣ���<=100�����ǰn����
*/

#include <stdio.h>
#include <string.h>//memset
#include <stdlib.h>//qsort

int fcmp(const void *op1,const void *op2)
{
	return *(int*)op1 -*(int*)op2;
}
int main()
{
	int i = 0,sum = 0;
	int a[30]={0};
	memset(a,100,sizeof(int)*30);
	a[0]=5;
	a[1]=59;
	a[2]=40;
	a[3]=10;
	a[4]=10;
	
	qsort(a,30,sizeof(int),fcmp);
	for(i=0;i<30;++i)
	{
		sum += a[i];
		if(sum > 100)
			break;
	}
	printf("%d",i);
	getchar();


	return 0;
}
