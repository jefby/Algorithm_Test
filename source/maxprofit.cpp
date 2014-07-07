#include <iostream>
#include <vector>

using namespace std;

/*
	题目描述：
	Say you have an array for which the ith element is the price of a given stock on day i.

	Design an algorithm to find the maximum profit. You may complete as many transactions 
	as you like (ie, buy one and sell one share of the stock multiple times). However, you 
	may not engage in multiple transactions at the same time (ie, you must sell the stock 
	before you buy again).
	主要思想：
	计算每个递增区间的递增值之和

*/
int maxProfit(vector<int> &prices) {
	int res = 0;
	if(prices.empty())//处理为空的异常情况
		return 0;
	vector<int>::size_type pos = 1;

	for(;pos < prices.size ();++pos){
		if(prices.at(pos-1) < prices.at(pos))//升序
			res += prices.at(pos)-prices.at(pos-1);//递增值
	}
	return res;
}
int main()
{
	return 0;
}