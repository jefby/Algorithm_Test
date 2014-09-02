/*
	功能描述：
	去除重复元素的全排列

*/
//#include <stdio.h>
//#include <string.h>
#include <iostream>
#include <vector>


using namespace std;
#if 0
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
#endif
//在pszStr数组中，[nBegin,nEnd)中是否有数字与下标为nEnd的数字相等  
bool IsSwapPermute(vector<int> &num, int begin,int end)  
{  
	int size = num.size();
    for (int i = begin; i < end; i++)  
        if (num[i] == num[end])  
            return false;  
    return true;
}
void internalPermute(vector<int> &num, int index, vector<int> &perm, vector<vector<int> > &result) 
{
		int size = num.size();
        
        if (size == index) {
            result.push_back(perm);
        }
        else {
            for (int i = index; i < size; ++i) {
				if(IsSwapPermute(num,index,i)){
					swap(num[index], num[i]);
					perm.push_back(num[index]);
					internalPermute(num, index + 1, perm, result);
					perm.pop_back();
					swap(num[index], num[i]);
				}
            }
        }
}
    
vector<vector<int> > permute(vector<int> &num) 
{
	vector<vector<int> > result;
	vector<int> perm;
        
	internalPermute(num, 0, perm, result);
        
    return result;
}



int main()
{
#if 0
	char str[10];/**/
	printf("递归的全排列.\n请输入字符串：（长度小于等于10）");
	scanf("%s",str);
	foo(str);
#endif
	vector<vector<int> >res;
	vector<int>num;
	int i=1;
	
	num.push_back('a');
	num.push_back('l');
	num.push_back('i');
	num.push_back('b');
	num.push_back('a');
	num.push_back('b');
	num.push_back('a');
	res = permute(num);
	for(i=0;i<res.size();++i){
		for(int j=0;j<res[i].size();++j)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	printf("共有%d中不同的排列\n",res.size());
	fflush(stdin);
	getchar();
	return 0;
}