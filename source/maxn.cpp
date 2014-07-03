/*
	题目描述：
	有一个容量为100的箩筐，给30个物品，每个物品的体积已知：最多能装多少个物品进箩筐
	输入描述：
	一行30个正整数，用空格隔开，表示每个物品的体积
	输出描述：
	一个数字，为最多能装下的物品数
	思路：
	用数组来存储每个物品的体积，先从小到大排序，完成后递加和，求<=100的最多前n个数
*/

#include <stdio.h>
#include <string.h>//memset
#include <stdlib.h>//qsort

int fcmp(const void *op1,const void *op2)
{
	return *(int*)op1 -*(int*)op2;
}
int main()
{
	int i = 0,sum = 0;
	int a[30]={0};
	memset(a,100,sizeof(int)*30);
	a[0]=5;
	a[1]=59;
	a[2]=40;
	a[3]=10;
	a[4]=10;
	
	qsort(a,30,sizeof(int),fcmp);
	for(i=0;i<30;++i)
	{
		sum += a[i];
		if(sum > 100)
			break;
	}
	printf("%d",i);
	getchar();


	return 0;
}
