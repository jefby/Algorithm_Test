/*
	题目描述：
	输入一个数字，将其倒序输出，并输出其各个位上的乘积
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
			a[i++]=m+'0';//注意前导0问题
		res *= m;
		n = n / 10;
	}while(n);

	printf("%s %d",a,res);
	fflush(stdin);
	getchar();
}