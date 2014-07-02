/*
	题目描述：
	输入一个字符串，统计其出现频率最高的字符，并输出。若存在两个字符出现频率相同，则输出字典序较小的哪一个
	输入描述
	一个字符串，保证没有空格，以回车符结束，字符串长度<=20
	输出描述
	一个字符
	输入样例
	aabbcc
	输出样例
	a
*/
#include <stdio.h>
#include <string.h>

char str[5005];
char frq[256];
int main()
{
	int i = 0 ,len = 0,max = 0;
	scanf("%s",&str);
	len = strlen(str);
	if(len > 20)
		len = 20;
	for(i=0;i<len;++i)
		++frq[str[i]];
	
	for(i=0;i<256;++i){
		if(frq[i] > max){
			max = frq[i];
			len = i;
		}
	}
	printf("%c",len);
	fflush(stdin);
	getchar();
}