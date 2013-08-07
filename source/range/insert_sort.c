#include <stdio.h>

void insert_sort(int *a,int n)
{
	int i,j,key;
	for(j=1;j<n;++j){
		key = a[j];
		for(i=j-1;i>=0&&a[i]>key;--i)
			a[i+1]=a[i];
		a[i+1] = key;
	}
}
int main()
{
	int i;
	int a[]={3,1,2,4,5,9,0};
	int length = sizeof(a)/sizeof(a[0]);
	insert_sort(a,length);
	for(i=0;i<length;++i)
		printf("%d ",a[i]);
	return 0;
}
