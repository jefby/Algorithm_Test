#include <stdio.h>


int partion(int *a,int low,int high)
{
	int privot = a[low];
	while(low < high){
		while(low<high && a[high] >= privot) --high;
		a[low] = a[high];
		while(low<high && a[low] <= privot) ++low;
		a[high] = a[low];
	}
	a[low] = privot;
	return low;
}

void myqsort(int *a,int low,int high)
{
	int privotloc = 0;
	if(low < high){
		privotloc = partion(a,low,high);
		myqsort(a,low,privotloc-1);
		myqsort(a,privotloc+1,high);
	}
}
int 
main()
{
	int a[]={3,4,1,2,5,6,10,7};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;
	myqsort(a,0,len-1);
	for (i = 0; i < len; ++i)
	{
		/* code */
		printf("%d ", a[i]);
	}
	return 0;
}