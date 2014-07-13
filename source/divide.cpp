/*Divide two integers without using multiplication, division and mod operator.*/

#include <iostream>

using namespace std;
/*
	函数说明：
	整数相除
	参数说明：
	@dividend：被除数
	@divisor：除数
	不能使用简单的直接递增divisor的方法，当被除数很大，而除数很小时，会超时，解决方法：加倍divisor,每次成功后加倍
*/
int divide(int dividend, int divisor)
{
	long long a =0,b =0;
	long long sum  = 0;
	int count = 0,res = 0;
	if(divisor == 0)//除数为0的情况
		return 0;
	if(divisor == 1)//除数为1的情况
		return dividend;
	if(divisor == -1)//除数为-1的情况
		return (-dividend);

	long long c = dividend;    //先用两个long long来存一下，不然下面abs(-2147483648)会溢出，因为正数int只能到2147483647
    long long d = divisor;
	b = abs(d);
	a = abs(c);//取绝对值
	while(a >= b){
		count = 1;
		sum = b;
		while(sum + sum <= a){//被除数加倍
			sum += sum;
			count += count;//计数值也加倍
		}
		a -= sum;//超过则减去sum
		res += count;//同时递加count
	}
	if((dividend>0 && divisor<0) || (dividend<0&&divisor>0))
		res = -res;
	return res;
}
int main()
{
	printf("请输入相除的两个数\n");
	int a=0,b=0;
	scanf("%d,%d",&a,&b);
	printf("\nresult=%d",divide(a,b));
	fflush(stdin);
	getchar();

}