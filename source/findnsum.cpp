/*
	��Ŀ��������һ�������������У�Ѱ�Һ�Ϊm���������
	01��������
*/
#include <list>
#include <iostream>

using namespace std;

list<int>list1
/*	
	�ݹ�����
	��Ϊm������У���Ԫ��n�Ĺ۵㿼�ǣ���ô�����������
		һ���ǰ���n����ô���������Ϊf(m-n,n-1)��
		��һ���ǲ�����n,��ô���������Ϊf(m,n-1)
	����˵����
	@sum �� ��ʾ��ֵ
	@n ����ʾԪ�ظ���

*/;
void find_factor(int sum,int n)
{
	//�ݹ����
	if(n <= 0 || sum <= 0)
		return;
	//����ҵ��Ľ��
	if(sum == n)
	{
		//��תlist1
		list1.reverse();//��תΪ�Ӵ�С��˳��
		for(list<int>::iterator iter = list1.begin();iter != list1.end();++iter)
			cout << *iter << "+";
		cout<<n<<endl;
		list1.reverse();//�ָ�ԭʼ����
	}
	list1.push_front(n);//���͵�01��������
	find_factor(sum-n,n-1);//��n,n-1��������sum-n
	list1.pop_front();
	find_factor(sum,n-1);//����n,n-1��������sum
}
int main()
{
	int sum = 0, n = 0;
	cout<<"������Ҫ���ڶ��ٵ���ֵsum:"<<endl;
	cin>>sum;
	cout<<"�������1...n����ȡֵ��n:"<<endl;
	cin>>n;
	find_factor(sum,n);
	fflush(stdin);
	getchar();

	return 0;
}