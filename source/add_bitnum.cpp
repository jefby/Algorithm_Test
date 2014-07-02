/*
	题目描述
	输入一个数字，输出其各个位上的和
	输入描述
	一个正整数，保证在int范围内
	输出描述
	一个正整数
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