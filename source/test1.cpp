#include <stdio.h>
#include <stdlib.h>

#define LOCAL 
//读入一个正整数n，然后读入n个整数，接着读入一个数m，输出n个整数中小于m的值的个数
int main()
{
#ifdef LOCAL
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
#endif

	int n = 0;
	int cnt = 0;
	int tmp = 0;
	if(scanf("%d",&n) == 1)
	{
		int *a=(int*)malloc(sizeof(int)*n);
		int i=0;
		if(n >= 1 )
		{
			while(scanf("%d",&tmp) == 1 && i < n)
			{
				a[i] = tmp;
				++i;
			}
			if(scanf("%d",&tmp) == 1);
			for(i=0;i<n;++i)
			{
				if(a[i] < tmp)
					++cnt;
			}
		}
		free(a);
		printf("cnt=%d\n",cnt);
	}
	
	return 0;
}