/*
	��Ŀ������
	����һ�����֣����䵹�����������������λ�ϵĳ˻�
*/
#include <stdio.h>

int main()
{
	unsigned int n = 0 ,res =1,m = 0;
	char a[33]={0};
	scanf("%d",&n);
	int i = 0;
	do{
		m = n%10;
		if(i!= 0 || m != 0)
			a[i++]=m+'0';//ע��ǰ��0����
		res *= m;
		n = n / 10;
	}while(n);

	printf("%s %d",a,res);
	fflush(stdin);
	getchar();
}