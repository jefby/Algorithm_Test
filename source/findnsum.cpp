/*
	题目描述：在一个给定的序列中，寻找和为m的任意组合
	01背包问题
*/
#include <list>
#include <iostream>

using namespace std;

list<int>list1
/*	
	递归解决：
	和为m的组合中，从元素n的观点考虑，那么有两种情况：
		一种是包含n，那么其他的组合为f(m-n,n-1)；
		另一种是不包含n,那么其他的组合为f(m,n-1)
	参数说明：
	@sum ： 表示和值
	@n ：表示元素个数

*/;
void find_factor(int sum,int n)
{
	//递归出口
	if(n <= 0 || sum <= 0)
		return;
	//输出找到的结果
	if(sum == n)
	{
		//反转list1
		list1.reverse();//反转为从大到小的顺序
		for(list<int>::iterator iter = list1.begin();iter != list1.end();++iter)
			cout << *iter << "+";
		cout<<n<<endl;
		list1.reverse();//恢复原始序列
	}
	list1.push_front(n);//典型的01背包问题
	find_factor(sum-n,n-1);//放n,n-1个数填满sum-n
	list1.pop_front();
	find_factor(sum,n-1);//不放n,n-1个数填满sum
}
int main()
{
	int sum = 0, n = 0;
	cout<<"请输入要等于多少的数值sum:"<<endl;
	cin>>sum;
	cout<<"请输入从1...n数列取值的n:"<<endl;
	cin>>n;
	find_factor(sum,n);
	fflush(stdin);
	getchar();

	return 0;
}