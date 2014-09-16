#include <iostream>
using namespace std;

class A{
public:
	int _a;
	A(){_a=1;};
	void print(){printf("%d",_a);};
};

class B:public A{
public:
	int _a;
	B(){
		_a = 2;
	}
};


struct S{
	int i;
	int *p;
};
int main()
{
	B b;
	b.print();
	printf("%d",b._a);

	S s;
	int *p = &s.i;
	p[0] = 4;
	p[5] = 3;
	s.p = p;
	s.p[1] = 1;
	//s.p[0] = 2;

	int a[]={1,2,3,4,5};
	int *ptr = (int*)(&a+1);
	printf("%d %d",*(a+1),*(ptr-1));

	getchar();
	return 0;
}