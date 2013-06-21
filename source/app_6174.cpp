/*
	*	This is for 6174 question 
	*	input : a number which is in [1234,9876],and every bit is not equal
	*	output : the process of transform until some number equals to number ealier occurs
	*	author: jefby
	*	email: jef199006@gmail.com
	*	example :
	*	input 1234 
	*	output: 1234 3087 8352 6174
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX 5005
typedef char  type;

int bubble_sort(type *a,int len)
{
//	char *_a = (char*)a;
	int ok = 1;
	assert(a&&len>0);
	for(int i=0;i<len-1;++i)
	{
		int ok = 1;
		for(int j=len-1;j>i;--j)
		{
			if(a[j] < a[j-1])
			{
				type tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;	
				ok = 0;
			}
		}
		if(ok)
			break;
	}
	return 0;
}

int get_next(int x)
{
	assert(x>=1234 && x <= 9876);
	char tmp[5];
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"%d",x);
	bubble_sort(tmp,4);
	int min,max;
	sscanf(tmp,"%d",&min);
	
	//invert the order 
	for(int i=0;i<4/2;++i)
	{
		int xx = tmp[i];
		tmp[i] = tmp[3-i];
		tmp[3-i] = xx;
	}
	sscanf(tmp,"%d",&max);
	printf("max=%d,min=%d\n",max,min);

	return max-min;	
}

int num[MAX];

int main()
{
//	int a[]={3,2,1,4};
//	int len = sizeof(a)/sizeof(a[0]);
//	typedef int type;
//	bubble_sort(a,len);
//	for(int i=0;i<len;++i)
//	{
//		printf("%d ",a[i]);
//	}
	int count = 0;
	int i = 0;
	scanf("%d",&num[0]);
	int ok = 1;
	while(1)
	{	
		int x = get_next(num[count]);	
		ok = 1;
		for(i=0;i<count;i++)
		{
			if(num[i] == num[count])
			{
				ok = 0;
				break;
			}
		}
		if(ok)
			num[++count] = x;
		else
			break;
	}
	for(i=0;i<count;++i)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
	return 0;
}
