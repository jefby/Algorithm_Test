#include <iostream>
#include <vector>
#include <algorithm>

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



/*
	Say you have an array for which the ith element is the price of a given stock on day i.

	If you were only permitted to complete at most one transaction (ie, buy one and sell one 
	
	share of the stock), design an algorithm to find the maximum profit.

*/

int maxProfit1(vector<int> &prices) 
{
	if(prices.empty())
		return 0;
	int i=0;
	int maxpro = prices[prices.size()-1];
	int res = 0;
	//����i�����룬��ô����׬������������Ƕ����أ�����i + 1 ~ n�������Ĺɼۼ�ȥ��i���
	for(i=prices.size()-1;i>=0;--i){
		maxpro = max(maxpro,prices[i]);
		res = max(res,maxpro-prices[i]);
	}
	return res;
}
int main()
{
	int a[]={1,2,4};
	int len = sizeof(a)/sizeof(a[0]);
	int i=0;
	vector<int> ivec;
	for(i=0;i<len;++i)
		ivec.push_back(a[i]);
	i=maxProfit1(ivec);
	cout<<"���������"<<i<<endl;
	fflush(stdin);
	getchar();
	return 0;
}