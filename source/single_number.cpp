#include <iostream>

using namespace std;
/*
	��Ŀ������
	��֪����A�У�����һ��Ԫ���⣬����Ԫ�ض��ǳ������Ρ��ҳ�ֻ����һ�ε�����Ҫ��ռ临�Ӷ�ΪO(1)��ʱ�临�Ӷ�ΪO(n)
	����˵����
	@A��������ʼ��ַ
	@n������Ԫ�ظ���
*/
int singleNumber(int A[], int n) {
    int i = 0;
	int res = A[0];
	if( n <= 0 || A == NULL)//�����쳣���
		return 0;
	for(i = 1;i < n;++i)
		  res ^= A[i];
	return res; 
}
/*
	��Ŀ������
	��֪����A�У�����һ��Ԫ���⣬����Ԫ�ض��ǳ������Ρ��ҳ�ֻ����һ�ε�����Ҫ��ռ临�Ӷ�ΪO(1)��ʱ�临�Ӷ�ΪO(n)
	˼�룺
	ͳ��ÿ��Ԫ���е�ÿһλ�ĺͣ�Ȼ��ÿһλ��λ��mod (k) ������λ��mod(k)��ֵѡ���Ե���λ���������ֻ����һ�ε���
*/
int singleNumberII(int A[],int n)
{
	int i = 0,j=0;
	int helper[32];
	int res = 0;
	memset(helper,0,sizeof(int)*32);
	if(n <= 0 || A == NULL)//�����쳣���
		return 0;
	for(i=0;i<n;++i){
		//��Ԫ�ص�ÿһλ��ӣ���mod (3)�������
		for(j=0;j<32;++j){
			helper[j]+=((A[i]&(1<<j)) != 0)?1:0;
		}
	}
	for(i=0;i<32;++i)//��ԭsingle number
		if(helper[i]%3 != 0)//����ǳ��������Σ����޸�helper[i]%3Ϊhelper[i]%k����
			res |= (1<<i);
	return res;
}

int main()
{
	int A1[]={2,2,2,3,5,3,3,6,6,6,5,5,8};
	int A2[]={2,2,3,3,3,3,2,2,4};
	int n = sizeof(A1)/sizeof(A1[0]);
	int res = 0;
	res = singleNumberII(A1,n);
	cout<<res<<endl;
	n = sizeof(A2)/sizeof(A2[0]);
	res = singleNumber(A2,n);
	cout<<res<<endl;
	fflush(stdin);
	getchar();
	return 0;
}