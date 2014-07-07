/**/
#include <iostream>
#include <vector>

using namespace std;
/*
	题目描述：
	Reverse digits of an integer.

	Example1: x = 123, return 321
	Example2: x = -123, return -321

*/

int reverse(int x) {
        int res = 0;
    	int tmp = x;
    	if(x < 0)//处理符号位
    		tmp = -x;
    	do{
    		res = res*10 +tmp%10;
    		tmp = tmp/10;
    	}while(tmp);//翻转数字,res保存反转后的数据
    
    	if(x<0)//处理符号位
    		res = -res;
    	if(x > 0 && res <0 )//抛出的异常，处理溢出异常
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