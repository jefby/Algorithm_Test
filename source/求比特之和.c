/*
	输入n求1..n上的比特值为1之和
	Author : jefby
	Email  : jef199006@gmail.com
*/
#include <stdio.h>

//求n的bit之和
int getNsumbit(int n)
{
	int cnt = 0;
	while(n>0){
		n=n&(n-1);
		++cnt;
	}
	return cnt;
}

//求1~n的比特值之和
int 
sum1ton(int n)
{
	int sum = 0;
	while(n>0){
		sum += getNsumbit(n--);
	}
	return sum;
}

//判断是否为比特级的回文数
int
bitHuiwen(int n)
{
	int low = 0, high = 31;
	int x = 0,y = 0;
	while(low < high){
		x = n &(1<<low);
		y = n &(1<<high);
		if((x!=0 && y!=0) || (x==0 && y == 0)){
			++low;
			--high;
		}else
			return 0;
	} 
	return  1;
}

int 
main()
{
	//int n = 0;
	//canf("%d",&n);
	//printf("n=%d,value = %d",n,sum1ton(n));
	if(bitHuiwen(0x10000001)){
		printf("yes");
	}else
		printf("no");
	return 0;
}
