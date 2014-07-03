/*
	功能描述：
	去除重复元素的全排列

*/
#include <stdio.h>
#include <string.h>

void swap(char *a,char*b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
//在pszStr数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等  
bool IsSwap(char *pszStr, int nBegin, int nEnd)  
{  
    for (int i = nBegin; i < nEnd; i++)  
        if (pszStr[i] == pszStr[nEnd])  
            return false;  
    return true;  
}  
/*
	k表示当前选取到第几个数，m表示共有多少个数-1的值
*/
void allrange(char *szStr,int k,int m)
{
	if(k == m){
		static int s_i = 1;
		printf("第%3d个排列\t%s\n",s_i++,szStr);
	}else{
		for(int i = k;i<=m;++i){//第i个数分别于它后面的数字交换就能得到新的排列
			if(IsSwap(szStr,k,i)){
				swap(szStr+k,szStr+i);//交换顺序
				allrange(szStr,k+1,m);//从k+1个数开始选取
				swap(szStr+k,szStr+i);
			}
		}
	}
}
void foo(char *str)
{
	allrange(str,0,strlen(str)-1);
}

int main()
{
	char str[10];/**/
	printf("递归的全排列.\n请输入字符串：（长度小于等于10）");
	scanf("%s",str);
	foo(str);
	fflush(stdin);
	getchar();
	return 0;
}