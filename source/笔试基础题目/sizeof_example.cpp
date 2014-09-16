#include <iostream>
using namespace std;

class A5{
public:
	/*
	double d;
	float a;
	int b;
	char c;
	static const int e = 0;
	
	void g(){};
	virtual void vg(){};
	void g2(){};
	void g3(){};
	virtual void vg2(){};
	A5();
	~A5();
	*/
	static int ab;
};
class A{
};
class A2{
};
class B : public A
{
};
class C : public virtual B
{
};

class D : public A,public A2
{
};
int main()
{
	cout<<"sizeof(A5)="<<sizeof(A5)<<endl;
	cout<<"sizeof(A)="<<sizeof(A)<<endl;
	cout<<"sizeof(A2)="<<sizeof(A2)<<endl;
	cout<<"sizeof(B)="<<sizeof(B)<<endl;
	cout<<"sizeof(C)="<<sizeof(C)<<endl;
	cout<<"sizeof(D)="<<sizeof(D)<<endl;
	getchar();
	return 0;
}