#include <iostream>
#include <string>

using namespace std;
/*쳲������������*/
int climbStairs(int n) 
{
	int i = 0;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	int *a = (int*)calloc(n+1,sizeof(int));
	a[0] = 1;a[1] = 1;
	for(i=2;i<=n;++i)
		a[i] = a[i-1]+a[i-2];
	i = a[n];
	free(a);
	return i;
}
/*
	������ת��Ϊ������
*/
string inttoRoman(int m)
{
	int values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	int i = 0;
	string numerals[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	string res;
	for(i=0;i<sizeof(values)/sizeof(values[0]);++i){
		while(m >= values[i]){
			m -= values[i];
			res.append(numerals[i]);
		}
	}
	return res;
}
/*
	��Ŀ������
	Given an array and a value, remove all instances of that value in place and return the new length.

	The order of elements can be changed. It doesn't matter what you leave beyond the new length.
	ɾ�������е�ָ��Ԫ�أ����ҷ����������Ч���ȣ�ע�⣺ɾ����ɺ������Ԫ����ǰlen��λ�ô��

*/
int removeElement(int A[], int n, int elem) 
{
	int cnt = 0,i=0,j=0;
	for(i=n-1;i>=0;--i){
		if(A[i] == elem){
			++cnt;
			for(j=i;j<n-cnt;++j){
				A[j] = A[j+1];
			}
		}
	}
        
	return n-cnt;
}
int main()
{
	int m = 0;
	string s;
	cout<<"������Ҫת����������ֵ����"<<endl;
	cin>>m;
	s = inttoRoman(m);
	cout<<s;
	int A[]={3,3,4,5};
	int len = sizeof(A)/sizeof(A[0]);
	int n =removeElement(A,len,5);
	cout << "n="<<n<<endl;
	for(int i=0;i<n;++i)
		cout<<A[i]<<" ";

	fflush(stdin);
	getchar();
	return 0;
}