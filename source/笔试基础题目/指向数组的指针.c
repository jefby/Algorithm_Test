#include <stdio.h>


int main()
{
	float c=0.1;
	int b=1;
	double d = 3.0;



	int a[][4] = {1,2,3,4,5,6,7,8};
	int (*p)[4];
	p=&a[0];
	d = c+d+b;
	printf("a[0]=%p,p=%p",a[0],p[1][0]);
	printf("\n%d",sizeof(c));//4
	return 0;
}