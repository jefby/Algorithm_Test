#include <stdio.h>
#include <stdlib.h>

#define LOCAL 
//����һ��������n��Ȼ�����n�����������Ŷ���һ����m�����n��������С��m��ֵ�ĸ���
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