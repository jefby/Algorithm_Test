/*Divide two integers without using multiplication, division and mod operator.*/

#include <iostream>

using namespace std;
/*
	����˵����
	�������
	����˵����
	@dividend��������
	@divisor������
	����ʹ�ü򵥵�ֱ�ӵ���divisor�ķ��������������ܴ󣬶�������Сʱ���ᳬʱ������������ӱ�divisor,ÿ�γɹ���ӱ�
*/
int divide(int dividend, int divisor)
{
	long long a =0,b =0;
	long long sum  = 0;
	int count = 0,res = 0;
	if(divisor == 0)//����Ϊ0�����
		return 0;
	if(divisor == 1)//����Ϊ1�����
		return dividend;
	if(divisor == -1)//����Ϊ-1�����
		return (-dividend);

	long long c = dividend;    //��������long long����һ�£���Ȼ����abs(-2147483648)���������Ϊ����intֻ�ܵ�2147483647
    long long d = divisor;
	b = abs(d);
	a = abs(c);//ȡ����ֵ
	while(a >= b){
		count = 1;
		sum = b;
		while(sum + sum <= a){//�������ӱ�
			sum += sum;
			count += count;//����ֵҲ�ӱ�
		}
		a -= sum;//�������ȥsum
		res += count;//ͬʱ�ݼ�count
	}
	if((dividend>0 && divisor<0) || (dividend<0&&divisor>0))
		res = -res;
	return res;
}
int main()
{
	printf("�����������������\n");
	int a=0,b=0;
	scanf("%d,%d",&a,&b);
	printf("\nresult=%d",divide(a,b));
	fflush(stdin);
	getchar();

}