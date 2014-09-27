#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) 
{
	int k=0,j=0,i=0; 
    vector<int> level;
    if(rowIndex < 0)
		return level;
    for(i=0;i<=rowIndex;++i){    
		k = (int)level.size();
		for(j=k-1;j>=1;--j)
			level[j] += level[j-1];
        level.push_back(1);
    }
    return level;
}
int main()
{
	vector<int> res;
	int n = 0;
	cout<<"please input the rowIndex(pascal triangle)"<<endl;
	cin>>n;
	res = getRow(n);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}