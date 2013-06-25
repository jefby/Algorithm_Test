/*
 *
 *
 *	果园里的树排列成矩形。它们的x和y坐标均是1~99的整数。输入若干次统计每一
 *	个三角形内部和边界上共有多少棵树
 *	ctrl+D 结束输入
 *	例子:
 *
 *	input:
 *	1.5 1.5 1.5 6.8 6.8 1.5
 *	10.7 6.9 8.5 1.5 14.5 1.5
 *	output:
 *	15
 *	17
 *
 * 	Author:jefby	Email: jef199006@gmail.com
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 100
int arr[MAX_N];

double square_determinant(double x0,double y0,double x1,double y1,double x2,double y2)
{
	return x0*y1+x1*y2+x2*y0-x2*y1-x0*y2-x1*y0;
}

int main()
{
	printf("please input the tangle's position\n format is (x0,y0) (x1,y1) (x2,y2) \n");
	double x0,x1,x2,y0,y1,y2;
	int count = 0;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x0,&y0,&x1,&y1,&x2,&y2) == 6)
	{
		double a,b;
		a = fabs(square_determinant(x0,y0,x1,y1,x2,y2));
		double s0,s1,s2;
	
		for(int x=1;x<100;++x)
		{
			for(int y=1;y<100;++y)
			{
			s0 = fabs(square_determinant(x,y,x0,y0,x1,y1));
		       	s1 = fabs(square_determinant(x,y,x0,y0,x2,y2));
  			s2 = fabs(square_determinant(x,y,x1,y1,x2,y2));
			b = s0+s1+s2;
//               		printf("x=%d,y=%d:\na=%.2lf,b=%.2lf\n",x,y,a,b);
	         	if(fabs(a-b) <= 0.001)
				++arr[count];
			}
		}
		++count;
	}
	for(int i=0;i<count;++i)
	printf(" %d\n",arr[i]);
	return 0;
}
