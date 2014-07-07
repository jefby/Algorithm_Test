#include <iostream>
#include <vector>

using namespace std;

/*
	��Ŀ������
	Say you have an array for which the ith element is the price of a given stock on day i.

	Design an algorithm to find the maximum profit. You may complete as many transactions 
	as you like (ie, buy one and sell one share of the stock multiple times). However, you 
	may not engage in multiple transactions at the same time (ie, you must sell the stock 
	before you buy again).
	��Ҫ˼�룺
	����ÿ����������ĵ���ֵ֮��

*/
int maxProfit(vector<int> &prices) {
	int res = 0;
	if(prices.empty())//����Ϊ�յ��쳣���
		return 0;
	vector<int>::size_type pos = 1;

	for(;pos < prices.size ();++pos){
		if(prices.at(pos-1) < prices.at(pos))//����
			res += prices.at(pos)-prices.at(pos-1);//����ֵ
	}
	return res;
}
int main()
{
	return 0;
}