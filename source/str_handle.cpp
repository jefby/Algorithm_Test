/*
	题目描述：
	输入一个字符串，删除其中所有的数字，所有大写字母改成小写，其他不变，并输出
	输入描述：
	一个字符串，保证没有空格，以回车符结束，字符串长度<=20
	输出描述
	一个字符串，为题目要求的结果
	输入样例
	aAbB13A
	输出样例
	aabba

*/
#include <stdio.h>
#include <string.h>

char str[5005];
char res[5005];

int main()
{
	int i = 0,len = 0,j=0;
	scanf("%s",&str);
	len = strlen(str);
	if(len > 20)
		len = 20;
	for(i=0;i<20;++i){
		if(str[i] >= 'A' && str[i] <= 'Z'){//处理大写字母
			res[j++] = str[i] + 0x20;//转换为小写
		}else if(str[i] >= '0' && str[i] <= '9')//数字的话删除
			continue;
		else
			res[j++] = str[i];//其他的字符存入res
	}
	printf("%s",res);
	fflush(stdin);
	getchar();
	return 0;
}