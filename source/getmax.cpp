/*
	��Ŀ������
	��������������������⣬Ҫ��ʱ�临�Ӷ�ΪO(n��
	˼��������
	����һ��ֵb��bΪǰn��Ԫ�ص���Ӻͣ����
	b < 0����b = a[i]
	����b+=a[i]
*/

#include <stdio.h>

int getmax_arrary(int *a,int len)
{
	int i = 0,sum = 0,max = a[0];

	for(i=0;i<len;++i){
		if(sum < 0)
			sum = a[i];
		else
			sum += a[i];
		if(sum > max)
			max = sum;
	}
	return max;
}
int main()
{
	int a[]={1, -2, 3, 10, -4, 7, 2,-5};
	int i = 0;
	int len = sizeof(a)/sizeof(a[0]);
	int b[] = {-1,-2,-3,-4};
	printf("%d ",getmax_arrary(a,len));
	len = sizeof(b)/sizeof(b[0]);
	printf("%d ",getmax_arrary(b,len));

	getchar();
	return 0;
}