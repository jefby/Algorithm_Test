#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#if 0
/*
	�������ܣ�ʹ�õݹ�ķ�����ʵ�ָ������
*/
vector<int> grayCode(int n)
{
	    static vector<int> ivec;
		vector<int>::iterator it;
		int temp = 0;
		ivec.push_back(0);
        if(n==0)
            return ivec;
        if(n == 1){
            ivec.push_back(1);
            return ivec;
        }
        grayCode(n-1);
            //(n+1)λ�������е�ǰ2n�����ֵ���nλ����������֣���˳����д����ǰ׺0
            //(n+1)λ�������еĺ�2n�����ֵ���nλ����������֣���������д����ǰ׺1
            //grayCode(i+1);
		vector<int> store(ivec);
		
		reverse(store.begin(),store.end());
		for(it=store.begin();it != store.end();++it){
			temp = *it;
			temp |= 1<<(n-1);
			ivec.push_back(temp);
		}
		return ivec;
}
#endif
/*
	�������ܣ�ʹ�õݹ�ķ�����ʵ�ָ������
*/
vector<int> grayCode(int n)
{
		vector<int> ivec;
		int pos = 0;
		int temp = 0,i = 0;
		ivec.push_back(0);
        if(n==0)
            return ivec;
        ivec.push_back(1);
        if(n == 1)
            return ivec;
		
		for(i=1;i<n;++i){
			//(n+1)λ�������еĺ�2n�����ֵ���nλ����������֣���������д����ǰ׺1
			for(pos=ivec.size()-1;pos>=0;--pos){
				temp = ivec.at(pos);
				temp |= (1<<i);
				ivec.push_back(temp);
			}
		}
		return ivec;
}

int main()
{
#if 0
	int a[]={1,2,3,4,5};
	vector<int> ivec;
	int len = sizeof(a)/sizeof(a[0]);
	int i =0;
	
	for(i=0;i<len;++i)
		ivec.push_back(a[i]);
	reverse(ivec.begin(),ivec.end());
	for(i=0;i<len;++i)
		cout<<ivec.at(i)<<" ";
	cout<<endl;
#endif

	cout<<"������nλ������"<<endl;
	vector<int> iv;
	int n = 0,i=0;
	cin>>n;
	iv = grayCode(n);
	for(i=0;i<iv.size();++i)
		cout<<iv.at(i)<<" ";
	cout<<endl;
	fflush(stdin);
	getchar();
	return 0;
}