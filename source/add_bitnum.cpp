/*
	��Ŀ����
	����һ�����֣���������λ�ϵĺ�
	��������
	һ������������֤��int��Χ��
	�������
	һ��������
*/
#include <stdio.h>

int main()
{
	unsigned int n = 0,res = 0;
	scanf("%d",&n);
	do{
		res += n%10;
		n = n/10;
	}while(n);
	printf("%d",res);
	fflush(stdin);
	getchar();
}