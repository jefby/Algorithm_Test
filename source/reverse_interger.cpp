/**/
#include <iostream>
#include <vector>

using namespace std;
/*
	��Ŀ������
	Reverse digits of an integer.

	Example1: x = 123, return 321
	Example2: x = -123, return -321

*/

int reverse(int x) {
        int res = 0;
    	int tmp = x;
    	if(x < 0)//�������λ
    		tmp = -x;
    	do{
    		res = res*10 +tmp%10;
    		tmp = tmp/10;
    	}while(tmp);//��ת����,res���淴ת�������
    
    	if(x<0)//�������λ
    		res = -res;
    	if(x > 0 && res <0 )//�׳����쳣����������쳣
    		return 0;
    	return res;	
}
int main()
{
	int x = 0;
	cin>>x;
	cout<<x<<endl;
	x=reverse(x);
	cout<<x<<endl;
	fflush(stdin);
	getchar();
	return 0;
}