//print the max 2 prime <= m(from stdin )
//author : jefby
//email: jef199006@gmail.com
#include <stdio.h>
#include <math.h> 
#include <assert.h>

//judge x is prime or not
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


int main()
{
	int i,m;
	scanf("%d",&m);
	for(i=m-2;i>=3;--i)
	if(is_prime(i)&&is_prime(i+2))
	{
		printf("%d %d\n",i,i+2);
		break;
	}
	return 0;
}
