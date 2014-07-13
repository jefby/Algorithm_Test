#include <iostream>
#include <vector>

using namespace std;



vector<int> plusOne(vector<int> &digits) 
{
        int carry = 1;
		int len = (int)digits.size();
		vector<int> res(digits);//¿½±´digits
		if(digits.empty())
			return res;

        for(int i=len-1;i>=0;--i){
            if(carry+digits[i]==10){
                carry = 1;
                res[i]=0;
            }else{
                res[i] += carry;
                carry = 0;
            }
        }
        if(carry == 1)
			res.insert(res.begin(),1);
        return res;
}

int main()
{
	int a[]={9,9,9,9,9};
	int len = sizeof(a)/sizeof(a[0]);
	vector<int> ivec,res;
	int i = 0;
	for(i=0;i<len;++i)
		ivec.push_back(a[i]);
	res = plusOne(ivec);
	for(i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	cout<<endl;
	fflush(stdin);
	getchar();

	return 0;
}