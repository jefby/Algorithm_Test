/*
	题目描述：调整数组顺序使得奇数位于偶数前面
	调整数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。要求时间复杂度为O(n)
*/

#include <stdio.h>
#include <assert.h>

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void sort_odd_even(int *a,int len)
{
	assert(len > 0  && a != NULL);
	int *p1 = NULL,*p2 = NULL;
	p1 = &a[0];
	p2 = &a[len-1];
	while(*p1 && *p2 && p1 < p2){
		if(*p1%2 == 1)//如果是奇数，移动指针p1
			++p1;
		else
			swap(p1,p2);//否则，交换p1和p2的数据
		if(*p2%2 == 0)//如果是偶数，则移动指针p2
			--p2;
		else
			swap(p1,p2);
	}
}
int main()
{
	int a[]={3,4,5,6,7,8,9,10};
	int i = 0;
	int len = sizeof(a)/sizeof(a[0]);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	printf("\n");
	sort_odd_even(a,len);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	printf("\n");
	getchar();
}