/*
 *	问题描述
 *	输入正整数n(2<=n<=100),把阶乘n!=1*2*3...*n分解成素因子相乘的形式，
 *	从小到大输出各个素数（2，3，5...）的指数。例如825=3*5^2*11应表示成
 *	(0,1,2,0,1)
 *      author:jefby
 *	email:jef199006@gmail.com
 */
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_N 100 //judge x is prime or not
//@param x 
//@return 0 means x is not prime , 1 means x is prime  
int is_prime(int x)
{
	int m,i;
	assert(x >= 0);
	if(x==1)return 0;
	m=floor(sqrt(x)+0.5);
	for(i=2;i<=m;++i)
		if(x%i==0) return 0;
	return 1;
}

int prime_table[MAX_N];
int main()
{
	int n;
	int i;
	int count = 0;
	int p[MAX_N];

	for(i = 2;i < MAX_N;++i)
	{
		if(is_prime(i))
			prime_table[count++] = i;
	}
	printf("count = %d",count);
	scanf("%d",&n); 
	{
		printf("%d! =",n);	
		memset(p,0,sizeof(p));
	
		int maxp = 0;
		for(i=1;i<=n;++i)
		{
			int m=i;
			for(int j=0;j<count;++j)
			{
				while(m % prime_table[j] == 0)
				{
					m /= prime_table[j];
					++p[j];
					if(j > maxp) maxp = j;//更新最大元素因子下标
				}
			}
		}
		for(i=0;i<=maxp;++i)
			printf(" %d",p[i]);
		printf("\n");

	}
	return 0;
}
