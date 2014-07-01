/*
	自己实现的有关字符串的函数
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>//断言

/*
	函数说明：求字符串长度函数
	参数：
		@str 字符串指针
	不进行边界检测
*/
int mystrlen(const char *str)
{
	char *p = str;
	assert(str != NULL);//检测str指针的有效性
	while(*p++);
	return (p-str-1);
}
/*
	函数说明：求子字符串
	参数说明：
			@str : 字符串指针
			@substr : 子字符串指针
	返回值：子字符串在字符串str中的位置，如果不属于此字符串，则返回-1
*/
int mystrstr(const char *str,const char *substr)
{
	int lenstr = 0;
	int lensub = 0;
	int i = 0,j = 0;
	/*
	if(!str  || !substr)
		return -1;
	修改这里的判断为assert宏，删除原来的定义
	*/
	assert(str != NULL && substr != NULL);//检测指针的有效性
	lenstr = mystrlen(str);//求字符串长度
	lensub = mystrlen(substr);//求子字符串长度
	if(lenstr < lensub)//处理异常情况
		return -1;
	for(i=0;i<lenstr;++i){
		for(j=0;j<lensub;++j){//子字符串
			if(str[i+j] != substr[j])//如果有一个字符不相等，中断内循环
				break;
		}
		if(j == lensub)//判断是否完全匹配
			return i;
	}
	return -1;
}

/*
	函数功能：字符串拷贝
	参数说明：
	@src：源字符串
	@dst：目的字符串
*/
char *mystrcpy(char *dst,const char *src)
{
	char * p = dst;//记录dst指针
	if(dst == src)return dst;//检测是否指向相同的内存处
	assert(dst != NULL && src != NULL);//检测指针的有效性
	while(*p++=*src++);//拷贝
	return dst;//返回dst指针
}


/*
	函数功能：求在字符串中第一次出现的只出现一次的字符
	参数说明：
	@str : 字符串指针
	@len : 字符串长度
	返回值：只出现一次的字符索引
	思路：可以使用哈希表的方法来实现，具体描述如下：
	1.建立一个256个元素的整型数组，均初始化为-1
	2.然后扫描字符串，如果出现一次，记录下其索引值
	3.扫描哈希数组，寻找索引值最小元素，然后打印出字符
*/
int FindOnlyChar(const char *str,int len)
{
	int i = 0,min=len;
	int map[256];
	assert(str != NULL && len > 0);//检测指针的有效性
	memset(map,-1,sizeof(map));//初始化为-1
	//2.扫描字符串
	for(i=0;i<len;++i){
		if(map[str[i]] == -1)
			map[str[i]] = i;//记录索引值,仅仅记录第一次出现的值
		else
			map[str[i]] = -2;//将值赋值为-2,表示出现次数多于一次
	}
	for(i=0;i<256;++i){
		if(map[i] != -1 && map[i] != -2){
			if(map[i] < min)
				min = map[i];//更新只出现一次的最小索引号
		}
	}
	if(min < len){
		printf("only one char is :%c\n",str[min]);
		return min;
	}else
		return -1;//表示没有满足条件的字符
}

/*
	函数功能：内存拷贝，可以处理重叠区域拷贝
	参数说明：
	@dst : 拷贝内存的目的地
	@src ：拷贝内存的原始地
	@count : 拷贝的字节数
*/
void * mymemmove(void * dst,const void *src,size_t count)
{
	char * pdst = (char*)dst;
	char * psrc = (char*)src;
	assert(dst != NULL && src != NULL);
	if(pdst == psrc )
		return dst;
	//处理目的内存地址>源内存地址，并且两个重叠,则从后向前拷贝
	if(pdst > psrc && (pdst-psrc) < count){
		while(count--)
			*(pdst+count)=*(psrc+count);//从后向前拷贝
	}else{
		while(count--)//从前向后拷贝
			*pdst++=*psrc;
	}
	return dst;
}

/*
	函数功能：字符串划分函数
	参数说明：
	@str : 字符串指针
	@delim : 要分割的字符串,也可以称为分割符
	返回值：
	返回分割后的字符串指针
*/
char * mystrtok(char * str,const char *delim)
{
	static char * last = NULL;//用于进行下次分割做准备
	char * s = NULL,*d = delim;//初始化
	int len = 0;
	assert(delim != NULL );
	if( (str == NULL) && ((str=last) == NULL))
		return NULL;
	s = str;
	len = mystrlen(delim);

	while(*s){
		d = delim;
		while(*d){
			while(*s && *d && *s == *d){//判断如果相等一直递增指针
				++s;
				++d;
			}
			if(*d == '\0' ){//判断假如匹配字符串到达末尾，则截断原始字符串。
				*(str+(s-str-len)) = '\0';
				last = s;//记录下一次匹配字符串的起始地址
				return str;
			}else
				++d;//不匹配
		}//while(*d)
		++s;
	}//while(*s)
	if(last != NULL && *s == '\0' )//处理str字符串未完，而匹配已经完成的情况
		return last;
	return NULL;

}
int main()
{
	int res = -1,len = 0,i=0;
	char str[]="abcdefg";
	char substr[]="h";
	char str1[]="aaaabcceaedb";
	char str2[100]="abcdefghijklmn";
	char str3[]="abcdef-,ghi-,jkl";
	char *p = NULL;
	res = mystrstr(str,substr);
	if(res != -1)
		printf("ok");
	else
		printf("substr \"%s\" is not included by str \"%s\"\n",substr,str);
	
	len = mystrlen(str1);
	FindOnlyChar(str1,len);
	p = (char*)malloc(len+1);
	mystrcpy(p,str1);
	printf("after copied string is %s\n",p);
	mymemmove(str2+2,str2,20);
	for(i=0;i<100;++i)
		printf("%c ",str2[i]);
	p = mystrtok(str3,"-,");//根据"-,"符号来分割字符串str3
	while(p!= NULL){
		printf("strtok : %s\n",p);
		p = mystrtok(NULL,"-,");
	}//while(p!=NULL)

	getchar();
	return 0;
}