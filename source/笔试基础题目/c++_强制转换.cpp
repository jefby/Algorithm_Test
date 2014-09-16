#include <iostream>

using namespace std;
class A{
public:
	A(){m_a = 1;m_b=2;};
	~A(){};
	void fun() {printf("%d%d",m_a,m_b);};
public:
	int m_a;
	int m_b;
};

class B{
public:
	B(){m_c = 3;};
	~B();
	void fun(){printf("%d\n",m_c );}
public:
	int m_c;
};
int main()
{
	A a;
	B* pb = (B*)(&a);
	cout<<&a<<endl;
	cout<<&(a.m_a)<<endl;
	printf("%p\n",&A::m_a );
	printf("%p\n",&A::m_b );
	printf("%p\n",&B::m_c );
	pb->fun();
	int *ptr;
	ptr = (int*)0x8000;
	*ptr = 0xaabb;
	getchar();
	return 0;
}