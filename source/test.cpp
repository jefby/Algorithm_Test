// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>
#include <math.h>

//��λ����ת
void ConvertNumber(int n)
{
	if(n >= 100 && n < 1000)
	{
		int res = (n%10)*100+(n/10%10)*10+n/100;
		printf("%d convert to %03d\n",n,res);
	}
}

//function : ������aabb����ȫƽ����
//	floor����ȡ��
//@para : no 
void IsPerfectSquare()
{
	int m,n;
	for(int i = 1; i < 10;++i)
	{
		for(int j = 1; j < 10;++j)
		{
			m = i*1100+j*11;
			double f = (double)sqrt((double)m);
			if( floor(f+0.5) == f)
				printf("%d,",m);
		}
	}
}

//function : ���������������n,���n=�����������Ϊ3n+1���������Ϊ�����һ�룬�ܻὫ�������Ϊ1����仯�Ĵ���
void ChangeNto1(int n)
{
	int cnt=0;
	int ori = 0;
	if(n > 1)
	{
		ori = n;
		double t = n;
		//printf("%d",n);
		while(t > 1)
		{
			if((int)t%2 == 1)//����
			{
				t = floor((double)(3*t+1) + 0.5)/2;
				cnt+=2;
			}
			else
			{
				t/=2;
			//printf("->%d",n);
				++cnt;
			}
		}
		printf("\n");
		printf("through %d N=%d to 1\n",cnt,ori);
	}
}

//����������λ�� n <10^9
int Count_Of_N(int n)
{
	int cnt = 0;
	int ori = n;
	while(n/10 > 0)
	{
		n/=10;
		++cnt;
	}
	++cnt;
	printf("%d's count=%d\n",ori,cnt);
	return 0;
}
//���ŵ������
int Computer_Soldier(int a,int b,int c)
{
	int i;
	if(a<3&&b<5&&c<7 && a>=0 && b >=0 && c>= 0)
	{
		for(i=10;i<100;++i)
		{
			if(i%3==a&&i%5==b&&i%7==c)
			{
				printf("%d",i);
				break;
			}
		}
		if(i >= 100)
		{
			printf("No answer\n");
		}
	}
	return 0;
}

//��������,n<=20

int Pyramid(int n)
{
	if(n >= 1 && n <= 20)
	{
		for(int i=n;i>=1;--i)
		{
			for(int k=0;k<n-i;++k)
				printf(" ");//���ǰ���ո�
			for(int j=0;j<2*i-1;++j)//���#
				printf("#");
			printf("\n");//����
		}
	}
	return 0;
}
int main(int argc, char* argv[])
{
	printf("%.11f\n",8.0/5);
	ConvertNumber(990);
	//system("pause");
	IsPerfectSquare();
	ChangeNto1(987654321);
	Count_Of_N(0);
	Computer_Soldier(2,1,3);
	Pyramid(5);
	while(getchar() != '0');
	
	return 0;
}

