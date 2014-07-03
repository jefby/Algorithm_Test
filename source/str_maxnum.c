/*
	题目描述：
	输入一个字符串，输出其出现次数最多的数字，如果有两个数字出现次数相同，则输出较小的那一个
	输入描述
	一个字符串，保证没有空格，以回车符结束，字符串长度<=20
	输出描述
	一行，一个数字
*/
#include <stdio.h>
#include <stdlib.h>
char str[5005];
unsigned char frq[10];

int main()
{
	int i=0,len=0,max=0;
	scanf("%s",str);
	len = strlen(str);
	if(len > 20)
		len = 20;
	for(i=0;i<len;++i){
		if(str[i]>='0'&&str[i]<='9')
			++frq[str[i]-'0'];
	}

	len = -1;//记录数下标
	for(i=0;i<10;++i){
		if(frq[i] > max){
			max = frq[i];
			len = i;
		}
	}
	if(len > -1)//这里主要是避免当没有任何数字出现的情况
		printf("%d",len);
	fflush(stdin);
	getchar();
	return 0;
}