/*
	自己实现的有关字符串的函数
*/
#include <stdio.h>
/*
	函数说明：求字符串长度函数
	参数：
		@str 字符串指针
	不进行边界检测
*/
int mystrlen(const char *str)
{
	char *p = str;
	if(!str)
		return -1;
	while(*p++);
	return (p - str-1);
}
int mystrstr(const char *str,const char *substr)
{
	int lenstr = 0;
	int lensub = 0;
	int i = 0,j = 0;
	if(!str  || !substr)
		return -1;
	lenstr = mystrlen(str);
	lensub = mystrlen(substr);
	if(lenstr < lensub)
		return -1;
	for(i=0;i<lenstr;++i){
		for(j=0;j<lensub;++j){
			if(str[i+j] != substr[j])
				break;
		}
		if(j == lensub)
			return i;
	}
	return -1;
}



int main()
{
	int res = -1;
	char str[]="abcdefg";
	char substr[]="h";
	res = mystrstr(str,substr);
	if(res != -1)
		printf("ok");
	getchar();
	return 0;
}