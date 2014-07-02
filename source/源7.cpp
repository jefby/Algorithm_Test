/*
	题目描述
	输入10个整数，按各个位上的和从小到大排序，如果相同，则按数字从小到大排序
	输入描述
	10个正整数，保证都在int范围内，用空格隔开
	输出描述
	10个数字，其从大到小的值，用空格隔开，最后一个数字后不加空格
*/
#include <stdio.h>
#include <stdlib.h>

void myswap(int *a,int *b)
{
	int tmp = *a;
	if(a != b){
		*a = *b;
		*b = tmp;
	}
}
/*
	函数功能：计算数值n的位数和
*/
int bitsum(int n)
{
	int m = 0;
	if(n < 0)
		return 0;
	do{
		m += n%10;
		n = n/10;
	}while(n);
	return m;
}

void mysort(int *a,int len)
{
	int i = 0,j=0;
	int tmp[10]={0};
	int min = 0;

	if(len != 10)//检测数值元素个数
		return;
	for(i=0;i<len;++i)//求位数和,并保存到tmp数组中
		tmp[i] = bitsum(a[i]);
	for(i=0;i<len;++i){//选择排序
		min = i;
		for(j=i+1;j<len;++j){
			if(tmp[j] < tmp[min])
				min = j;
			else if(tmp[j] == tmp[min]){//如果位数和相同，则比较原始数值
				if(a[j] < a[min])//根据原始数值比较,小的具有优先级
					min = j;
			}//else if
		}//for(j=i+1;j<len;++j)
		if(min != i){
			myswap(&a[i],&a[min]);
			myswap(&tmp[i],&tmp[min]);
		}//if(min != i)
	}//for(i=0;i<len;++i)
}
int main()
{
	int a[10];
	int i = 0;
	scanf("%d %d %d %d %d %d %d %d %d %d" ,&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);
	mysort(a,10);
	for(i=0;i<10;++i)
		printf("%d ",a[i]);
	fflush(stdin);
	getchar();
}