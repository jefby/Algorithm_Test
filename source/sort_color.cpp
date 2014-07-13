/*
	题目描述：sort color
	Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

	Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

	Note:
	You are not suppose to use the library's sort function for this problem.

	click to show follow up.

	Follow up:
	A rather straight forward solution is a two-pass algorithm using counting sort.
	First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

	Could you come up with an one-pass algorithm using only constant space?
*/

#include <iostream>

using namespace std;

#if defined(CONFIG_ONE)
/*
	函数功能：按颜色进行排序，其中‘0’表示红色，‘1’表示白色，‘2’表示蓝色，最终顺序是0-》1-》2.
	参数说明：
	@A：数组地址
	@n：元素个数
*/
void sortColors(int A[], int n) 
{
	int i=-1,j=-1,k=-1;
	int p = 0;
	for(p=0;p<n;++p){
		if(A[p] == 0){
			A[++k]=2;
			A[++j]=1;
			A[++i]=0;
		}else if(A[p] == 1){
			A[++k]=2;
			A[++j]=1;
		}else if(A[p] == 2)
			A[++k]=2;
	}	
}

#endif
/*
	函数功能：按颜色进行排序，其中‘0’表示红色，‘1’表示白色，‘2’表示蓝色，最终顺序是0-》1-》2.
	参数说明：
	@A：数组地址
	@n：元素个数
*/
void sortColors(int A[], int n) 
{
	int i=-1,j=-1,v=0;
	int p = 0;
	for(p=0;p<n;++p){
		v = A[p];//记录当前的值
		A[p]=2;//写新值'2'
		if(v == 0){//比较当前值，如果等于0，则更新值
			A[++j]=1;
			A[++i]=0;
		}else if(v == 1)
			A[++j]=1;
	}	
}
int main()
{
	int a[]= {0,0,0,2,2,1,2,0};
	int len = sizeof(a)/sizeof(a[0]);
	sortColors(a,len);
	for(int i=0;i<len;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	fflush(stdin);
	getchar();
	return 0;
}