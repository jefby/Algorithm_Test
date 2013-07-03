#include <stdio.h>

int main()
{
	long long a,b;
	while(scanf("%lld %lld",&a,&b) == 2)
	{
		//printf("%lld\n",(a-b)>0?a-b:b-a);
		if(a>b)
			printf("%lld\n",a-b);
		else
			printf("%lld\n",b-a);
	}	
	return 0;
}
