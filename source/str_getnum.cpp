/*
	函数功能：输入一个字符串，将其中的数字提取处理组成数字，输出这个数字
	输入描述：
	一个字符串，保证没有空格，以回车符结束，字符串长度<=20
	输出描述
	一行，一个数字
	输入样例：
	a177d298u29dee0
	输出样例：
	177298290
*/
#include <stdio.h>
#include <string.h>
char str[5005];
/*不存任何字符串*/
int main()
{
	char ch;
	int i = 0;
	int flag = 0,len = 0;
#if 0
	for(i=0;i<20;++i){//只处理前20个字符
		scanf("%c",&ch);
		if(ch == '\n')
			break;
		if(ch >= '0' && ch <= '9'){
			if(flag == 0 && ch == '0'){
				flag = 1;
				continue;
			}//处理前导0
			printf("%c",ch);//其他情况输出数字
		}//if(ch >= '0' && ch <= '9')
	}//for
#endif
	scanf("%s",&str);
	len = strlen(str);
	if(len > 20)//处理大于20的情况
		len = 20;
	for(i=0;i<len;++i){
		if(str[i]>='0'&&str[i]<='9'){
			if(str[i] == '0' && !flag){//前导'0'
				flag = 1;
				continue;
			}
			printf("%c",str[i]);
		}
	}
	fflush(stdin);
	getchar();
	return 0;

}