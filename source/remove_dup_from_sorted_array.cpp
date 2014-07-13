#include <stdio.h>

/*
	函数说明：
	删除数组中的重复元素，并且返回新的数组长度
	Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

	Do not allocate extra space for another array, you must do this in place with constant memory.

	For example,
	Given input array A = [1,1,2],

	Your function should return length = 2, and A is now [1,2].
*/
int removeDuplicates(int A[], int n) 
{
	int i = 0,start=0,key = 0;
	if(n <= 0)
		return 0;
	key = A[0];
	for(i=1;i<n;++i){
		if(A[i] != key){
			A[++start]=A[i];
			key = A[i];
		}
	}
	return start+1;
}



int main()
{
	int a[]={1,1,1,1,2,2,3,4};
	int len = sizeof(a)/sizeof(a[0]);
	len = removeDuplicates(a,len);
	printf("len=%d",len);
	int i = 0;
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	fflush(stdin);
	getchar();
	return 0;
}