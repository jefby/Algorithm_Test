#include <iostream>
using namespace std;

class A5{
public:
	double d;
	float a;
	int b;
	char c;
	A5();
	~A5();
};
int main()
{
	cout<<"sizeof(A5)="<<sizeof(A5)<<endl;
	return 0;
}