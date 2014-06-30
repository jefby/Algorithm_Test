/*
	字符串包含问题
	求字符串A是否包含字符串B的全部字符
	思路1：
	使用构造映射表，256个字符组成一个单一的映射表，记录字符在A中是否出现
*/
#include <stdio.h>
#include <string.h>

int helper(char *a,char *b)
{
	size_t i=0;
	//p1指向较长字符串，p2指向较短字符串
	char *p1,*p2;


	unsigned char map[256];
	if(!a || !b)
		return -1;
	//判断字符串a和b的长短
	
	if(strlen(a) < strlen(b)){
		p1 = b;
		p2 = a;
	}else{
		p1 = a;
		p2 = b;
	}
		
	memset(map,0,sizeof(map));//初始化映射表
	for(i=0;i<strlen(p1);++i)//标记A中存在的字符
		map[p1[i]]=1;
	for(i=0;i<strlen(p2);++i){//寻找是否完全存在
		if(!map[p2[i]])
			return 0;
	}
	return 1;
}
int main()
{
	int res;
	char a[]="hello,I am";
	char b[]="helx";
	res = helper(a,b);
	if(res == 0)
		printf("no");
	else if(res == 1)
		printf("yes");
	else
		printf("error");
	getchar();
	return 0;
}