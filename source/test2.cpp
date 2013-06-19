#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

//计算调和级数
void harmony()
{
	int n;
	scanf("%d",&n);
	if(n > 0)
	{
		double sum = 0;
		for(int i=0;i<n;++i)
		{
			sum += (double)1.0/(i+1);
		}
		printf("sum=%.2f\n",sum);
	}
	fflush(stdin);
	
}
//计算PI/4=1-1/3+1/5-1/7直至最后一项小于10^-6
void approximation()
{
	double sum = 0;
	double add = 0;
	int i = 0;
	
	for(i=0;(add = ((double)1.0)/(2*i+1)) >= (0.000001);++i)
	{
		if(i%2 == 1)//奇数
			sum+=-add;
		else//偶数
			sum+=add;
	}
	printf("sum=%.3f\t",sum);
	printf("PI/4=%.3f",atan(1.0));
}

//计算子序列的值
//1/n^2+1/(n+1)^2+...+1/m^2
//参数 1<n<m<10^6
void subsequence(int n,int m)
{
	double n_f,sum=0;
	if(n > 0&&n < m && m < 1000000)
	{
		for(int i=n;i<=m;++i)
		{
			n_f = i;
			sum += 1.0/(n_f*n_f);
		}
		printf("\nsum=%.5f\n",sum);
	}
}

//输入a,b,a,b<=10^6,c<=100,c指定输出宽度
//计算a/b
void decimal(int a,int b,int c)
{
	if(a>0&&b>0&&a<=1000000&&b<=1000000&&c>0&&c<=100)
	{
		const int count = c;
		printf("%.*f",c,(double)a/(double)b);
	}
}


//用1,2,3..9中组成3个三位数，其中每个数恰好使用一次，并且abc:def:ghi之比为1:2:3
void permutation()
{
	int i,i_2,i_3,k;
	int map[10];
	bool ok = 0;
	for(i=123;i<=987/3;++i)
	{
		i_2=i*2;
		i_3=i*3;
		memset(map,0,sizeof(int)*10);

		map[i/100]=map[i/10%10]=map[i%10]=1;
		map[i_2/100]=map[i_2/10%10]=map[i_2%10]=1;
		map[i_3/100]=map[i_3/10%10]=map[i_3%10]=1;

		ok=0;
		//检查是否完全映射，若有一个不为1，说明非完全映射。
		for(k=1;k<10;++k)
		{
			if(map[k] != 1)
			{
				ok = 1;
				break;
			}
		}
		if(ok==0)
		{
			printf("\n%d:%d:%d\n",i,i_2,i_3);
		}
	}
}


//蛇形方阵问题
void Serpentine_matrix(int n)
{
	if(n> 0 && n < 9)
	{

		//malloc memory
		int**a=(int**)malloc(sizeof(int*)*(n+1));
		int i,j;
		for(i=0;i<n+1;++i)
		{
			a[i]=(int*)malloc(sizeof(int)*(n+1));
		}
		if(a!=NULL)
		{
			//initialize the array which malloc
			for(i=0;i<n+1;++i)
			{
				for(j=0;j<n+1;++j)
				{
					a[i][j]=0;
				}
			}//initialize 
			int total = a[i=0][j=n-1]=1;
			//loop ,down -> left -> up -> right 
			while(total < n*n)
			{
				while(i+1 < n && !a[i+1][j]){++total;a[++i][j]=total;}//down
				while(j-1 >= 0 && !a[i][j-1]){++total;a[i][--j]=total;}//left
				while(i-1 >= 0 && !a[i-1][j]){++total;a[--i][j]=total;}//up
				while(j+1 < n && !a[i][j+1]){++total;a[i][++j]=total;}//right
			}
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}//initialize 
		for(i=0;i<n+1;++i)
		{
			free(a[i]);
		}//free
		free(a);
	}	
}
int main()
{
	harmony();
	approximation();
	subsequence(1,2);
	decimal(1,6,4);
	permutation();
	Serpentine_matrix(4);
	getchar();
	return 0;
}