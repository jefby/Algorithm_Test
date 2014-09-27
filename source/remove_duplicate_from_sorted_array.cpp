/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/
#include <iostream>
using namespace std;

//时间复杂度为O(n)
int removeDuplicates(int A[], int n) 
{
	int i=0,j=0;
	//处理异常情况
	if(n<0)
		return 0;
	if(n>=0 && n<2)
		return n;

	int last = A[0];
	int num	 = 1;
	int count= 1;
	for(i = 1;i < n;++i){
		if(A[i] == last && num < 2){//小于2并且等于last
			A[++j] = last;
			++num;
			count += 1;
		}else if(A[i] != last){
			A[++j] = A[i];
			num    = 1;
			count += 1;
			last   = A[i];//更新last
		}
	}
	return count;
}

int main()
{
	int A[]={1,1,1,1,3,3};
	int len=sizeof(A)/sizeof(A[0]);
	int i=0;
	int n=0;

	n=removeDuplicates(A,len);
	for(i=0;i<n;++i)
		cout<<A[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}