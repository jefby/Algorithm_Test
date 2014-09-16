/*
	计数排序实现
	数组元素不小于1000
	Author: jefby
	Email:  jef199006@gmail.com
*/

#include <stdio.h>
#include <string.h>
	
#define MAX 1000

int countSort(int *a,int n)
{
	int i = 0,j=0;
	int *count=(int*)malloc(sizeof(int)*MAX);
	memset(count,0,sizeof(int)*1000);
	if(n<0||a==NULL)
		return -1;
	for(i=0;i<n;++i)
		++count[a[i]];
	for(i=0;i<MAX;++i){
		while(count[i]){
			--count[i];
			a[j++]=i;
		}
	}
}

int main()
{
	int a[]={1,3,2,4,5,2,9,8,7};
	int i = 0;
	int len = sizeof(a)/sizeof(a[0]);

	countSort(a,len);
	for(i=0;i<len;++i){
		printf("%d ",a[i]);
	}

	return 0;
}