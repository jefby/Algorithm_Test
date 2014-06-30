//字符串左旋m个,
//第一种方法：使用暴力移位方法，一次向左移动一位
//第二种方法：利用指针进行操作，完成左移
/*
	1、首先让 p1=ch[0]，p2=ch[m]，即让 p1，p2 相隔 m 的距离；
	2、判断 p2+m-1 是否越界，如果没有越界转到 3，否则转到 4（abcdefgh 这
		8 个字母的字符串，以 4 左旋，那么初始时 p2 指向 e，p2+4 越界了，但事实
		上 p2 至 p2+m-1 是 m 个字符，可以再做一个交换）。
	3、不断交换*p1 与*p2，然后 p1++，p2++，循环 m 次，然后转到 2。
	4、此时 p2+m-1 已经越界，在此只需处理尾巴。过程如下：
	4.1 通过 n-p2 得到 p2 与尾部之间元素个数 r，即我们要前移的元素个数。
	4.2 以下过程执行 r 次： ch[p2]<->ch[p2-1]， ch[p2-1]<->ch[p2-2]， ....，ch[p1+1]<->ch[p1]；p1++；p2++；

*/
/*
	第三种解法(三次翻转方法)
	将需要左旋的字符串划分为两部分，长度分别为m和len-m，为了方便起见，将左边的子字符串标记为1，右边的标记为2.则具体步骤如下：
	1.翻转字符串1
	2.翻转字符串2
	3.翻转整体字符串
	得出结果
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

#define CONFIG_THREE

char str[] = "abcdefg";//如果用char *str = "abcdefg"编译器只会分配4字节的数据，当在函数LeftPerOnebit中不能操作数据
//第一种解法
#if defined(CONFIG_ONE)
//左移一位
void LeftPerOnebit(char *str,int len)
{
	char ch = str[0];
	
	if(len <= 0 || str == NULL){
		printf("str error!\n");
		return;
	}
	
	for(int i=1;i<len;++i)
		*(str+i-1)=*(str+i);
	str[len-1]=ch;
}
void LeftRotate(char *str,int len,int m)
{
	while(m--){
		LeftPerOnebit(str,len);
	}
}
#endif
//第二种解法
#if defined(CONFIG_TWO)
/*
	函数功能：将字符串str左旋m位
	@str :字符串指针
	@len :字符串长度
	@m   :要左旋的位数
	需要满足的条件:m < len
*/
	void LeftRotate(char *str,int len,int m)
	{
		int p1 = 0,p2 =m;
		int i = 0;
		int r = 0;
		char ch  = 0;
		//处理异常情况，注意当要左旋的个数大于或者等于字符串长度时,直接退出
		if(m <= 0 || !str || len <=0 || len <= m)
			return;
		r = len /m -1;//次数
	//正常情况
			while(r--){
				for(i=0;i<m;++i){
					swap(str[p1],str[p2]);
					++p1;
					++p2;
				}
			}
	//处理尾巴
			if(len%m!=0){
				r = len - p2;//需要左移的次数
				while(r--){
					ch = str[p2];//保存P2的值
					for(i=m;i>0;--i)
						str[p1+i]=str[p1+i-1];
					str[p1]=ch;//赋给P1
					++p1;//移动指针
					++p2;
				}
			}
	}
#endif

#if defined(CONFIG_THREE)
	void myswap(char *a,char *b)
	{
		char tmp = 0;
		if(!a || !b)
			return;
		if(a != b){//判断是否地址相同
			tmp = *a;
			*a= *b;
			*b = tmp;
		}
	}
	/*
		辅助函数：翻转字符串beg和end标记内的字符
		参数:
			@str：字符串指针
			@beg: 字符串起始地址
			@end: 字符串结束地址+1
	*/
	void helper(char *str,int beg,int end)
	{
		int len = end - beg;
		int i = 0;
		//处理异常情况:str指针无效，beg<=end
		if(!str || beg >= end || beg < 0 || end < 0 )
			return;
		for(i=0;i<len/2;++i)
			myswap(&str[beg+i],&str[end-1-i]);

	}
	/*
		字符串左旋m个
		参数：
			@str: 字符串
			@len: 字符串长度
			@m  : 要左旋的字符个数
			必须满足条件m < len，并且m>0
	*/
	void LeftRotate(char *str,int len,int m)
	{
		if(m > 0 && m < len){//有效性控制，排除m<=0，或者m>=len的情况
			//翻转[0,m-1]左边字符串
			helper(str,0,m);
			//翻转[m,len-1]右边字符串
			helper(str,m,len);
			//翻转[0,len-1]整体字符串
			helper(str,0,len);
		}
	}
#endif
int main()
{
	int m = sizeof(str);
	printf("original string is : %s\n",str);
	LeftRotate(str,sizeof(str)-1,m);

	printf("left rotate %d is : %s\n",m,str);
	getchar();
	return 0;
}