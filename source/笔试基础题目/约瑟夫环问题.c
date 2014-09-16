/*
下面给出递推式：
 f [1] = 0; 
 f [ i ] = ( f [i -1] + m) % i; (i>1) 
有了递推公式，实现就非常简单了，给出循环的两种实现方式。再次表明用标准库的便捷性。
*/
#include <stdio.h>
#include <string.h>

int Josephus_problem(int m,int n)
{
	int i;
	int f = 0;
	for(i=2;i<=n;++i)
		f =(f + m)%i;
	return f+1;
}
int main()
{
	int m,n;
	printf("input m,n");
	scanf("%d,%d",&m,&n);
	printf("%d",Josephus_problem(m,n));
	return 0;
}
