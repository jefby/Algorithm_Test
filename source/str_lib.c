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
	lenstr -= lensub;//求解子字符串和主串的长度差
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
	Boyer-Moore算法
	KMP的匹配是从模式串的开头开始匹配的，而1977年，德克萨斯大学的Robert S. Boyer教授和J Strother Moore教授发明了一种新的字符串匹配算法：Boyer-Moore算法，简称BM算法。
	该算法从模式串的尾部开始匹配，且拥有在最坏情况下O(N)的时间复杂度。在实践中，比KMP算法的实际效能高。

    BM算法定义了两个规则：

	坏字符规则：当文本串中的某个字符跟模式串的某个字符不匹配时，我们称文本串中的这个失配字符为坏字符，此时模式串需要向右移动，移动的位数 = 坏字符在模式串中的位置 - 坏字符在模式串中最右出现的位置。
				此外，如果"坏字符"不包含在模式串之中，则最右出现位置为-1。
	好后缀规则：当字符失配时，后移位数 = 好后缀在模式串中的位置 - 好后缀在模式串上一次出现的位置，且如果好后缀在模式串中没有再次出现，则为-1。

	@param
	@str : 主字符串
	@substr ： 匹配串

int badpos(const char *str,char ch){
	char *p = str;
	if(!p)
		return -2;
	while(*(p+1)) 
		++p;
	while(p != str && *p != ch)
		--p;
	if(p == str && *p != ch)
		return -1;
	return p-str;
}
int boyer-moore(const char *str,const char *substr)
{
	char *psub = substr;
	char *pstr = str;
	int pos = 0;
	if(!substr || !str || strlen(str) < strlen(substr))//检查指针有效性
		return -1;
	
	while(*(psub+1))
		++psub;
	pstr += (psub-substr);
	
	while(*pstr  && *psub ){
		if(*psub != *pstr){//坏字符
			pos = badpos(substr,*pstr);//寻找最右位置
			pstr += (psub-substr)-pos; //右移这些位
		}else{//匹配
			while(psub != substr && *pstr == *psub){
				--pstr;
				--psub;
			}
			if(psub == substr && *psub == *pstr)//完全匹配
				return pstr - str;//返回位置
			else{//好后缀原则
				//未写完，暂时放弃
			}

		}
	}//while


}
*/
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
	if(last != NULL && *s == '\0' ){//处理str字符串未完，而匹配已经完成的情况
		s = last;//增加最后一个指针的处理,s保存last的值,last=>NULL
		last = NULL;
		return s;
	}
	return NULL;

}

/*
	函数功能：返回第一个不在指定字符串中出现的字符位置
	参数说明
	@str：字符串指针
	@accept : 指定字符串
	返回值：
	int类型
*/
int mystrspn(const char *str,const char *accept)
{
	const char *p1 = str;
	const char *p2 = accept;
	assert(str!=NULL&&accept!=NULL);
	
	while(*p1 && *p2 && *p1 == *p2){
		++p1;
		++p2;
	}
	return (p1 - str);
}
/*
	函数功能：字符串比较函数
	参数说明：
	@str1：字符串1
	@str2：字符串2
	返回：
		比较结果，str1-str2
*/
int mystrcmp(const char *str1,const char *str2)
{
	assert(str1 != NULL && str2 != NULL);
	while(*str1 && *str2 && *str1 == *str2){
		++str1;
		++str2;
	}
	return (*str1-*str2);
}

/*
	函数功能：依次检验字符串s1中的字符，当被检验字符在字符串s2中也包含时，则停止检验，并返回该字符开始的字符串指针，空字符NULL不包括在内。如果不满足此条件，则返回NULL
	参数说明：
	@s1	：字符串1
	@s2 ：字符串2
*/
char *mystrpbrk(const char *s1,const char *s2)
{
	const char * p2 = NULL,*p1 = NULL;
	unsigned char map[256]={0};
	assert(s1 != NULL && s2 != NULL);
	//扫描字符串2，构建哈希表
	p2 = s2;
	while(*p2){
		map[*p2] = 1;
		++p2;
	}
	p1 = s1;
	while(*p1){
		if(map[*p1])
			return p1;
		++p1;
	}
	return NULL;
}
int main()
{
	int res = -1,len = 0,i=0;
	char str[]="abcdefg";
	char substr[]="def";
	char str1[]="aaaabcceaedb";
	char str2[100]="abcdefghijklmn";
	char str3[]="abcdef-,ghi-,jkl";
	char *p = NULL;
	res = mystrstr(str,substr);
	if(res != -1)
		printf("ok\n");
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
	while(p != NULL){
		printf("strtok : %s\n",p);
		p = mystrtok(NULL,"-,");
	}//while(p!=NULL)
	res = mystrspn(str1,"aaa");
	printf("mystrspn %d\n",res);
	res = mystrcmp("str1","str");
	printf("\"str1\" %d \"str2\"\n",res);
	p = strpbrk("str3","actdb");
	printf("mystrpbrk %s\n",p);
	getchar();
	return 0;
}