#include <iostream>

using namespace std;
/*
	题目描述：
	已知数组A中，除了一个元素外，其他元素都是出现两次。找出只出现一次的数，要求空间复杂度为O(1)，时间复杂度为O(n)
	参数说明：
	@A：数组起始地址
	@n：数组元素个数
*/
int singleNumber(int A[], int n) {
    int i = 0;
	int res = A[0];
	if( n <= 0 || A == NULL)//处理异常情况
		return 0;
	for(i = 1;i < n;++i)
		  res ^= A[i];
	return res; 
}
/*
	题目描述：
	已知数组A中，除了一个元素外，其他元素都是出现两次。找出只出现一次的数，要求空间复杂度为O(1)，时间复杂度为O(n)
	思想：
	统计每个元素中的每一位的和，然后将每一位的位和mod (k) ，根据位和mod(k)的值选择性的置位，结果就是只出现一次的数
*/
int singleNumberII(int A[],int n)
{
	int i = 0,j=0;
	int helper[32];
	int res = 0;
	memset(helper,0,sizeof(int)*32);
	if(n <= 0 || A == NULL)//处理异常情况
		return 0;
	for(i=0;i<n;++i){
		//把元素的每一位相加，和mod (3)如果等于
		for(j=0;j<32;++j){
			helper[j]+=((A[i]&(1<<j)) != 0)?1:0;
		}
	}
	for(i=0;i<32;++i)//还原single number
		if(helper[i]%3 != 0)//如果是出现奇数次，则修改helper[i]%3为helper[i]%k即可
			res |= (1<<i);
	return res;
}

int main()
{
	int A1[]={2,2,2,3,5,3,3,6,6,6,5,5,8};
	int A2[]={2,2,3,3,3,3,2,2,4};
	int n = sizeof(A1)/sizeof(A1[0]);
	int res = 0;
	res = singleNumberII(A1,n);
	cout<<res<<endl;
	n = sizeof(A2)/sizeof(A2[0]);
	res = singleNumber(A2,n);
	cout<<res<<endl;
	fflush(stdin);
	getchar();
	return 0;
}