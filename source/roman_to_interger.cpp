
/*
	��(1)��X(10)��C (100)��M (1000),V (5)��L(50)��D (500)�������ķ�����
	(1)��ͬ��������д������ʾ����������Щ������ӵõ��������磬�� = 3��
	(2)С�������ڴ�����ֵ��ұߣ�����ʾ����������Щ������ӵõ��������磬�� = 8,�� = 12��
	(3)С�����֣������ڢ�X �� C���ڴ�����ֵ���ߣ�����ʾ�������ڴ�����С���õ��������磬�� = 4���� = 9��
*/
#include <iostream>
#include <string>


using namespace std;


int romanToInt(string s) 
{
	if(s.empty())//�����ַ���Ϊ�յ����
		return 0;

	int res = 0;
	string::size_type pos = 0;
	int temp = 0;
	int temp2 = 0;
	bool before=false;
	for(pos = 0;pos < s.size();++pos){
		before = false;

		switch(s[pos]){
			case 'I':
				temp = 1;before = true;break;
			case 'X':
				temp = 10;before = true;break;
			case 'C':
				temp = 100;before = true;break;
			case 'M':
				temp = 1000;break;
			case 'V':
				temp = 5;break;
			case 'L':
				temp = 50;break;
			case 'D':
				temp = 500;break;
			default:
				temp = 0;break;
		}
		if(pos+1 < s.size()){//�����һ��Ԫ�ص�ֵ
			switch(s[pos+1]){
			case 'I':
				temp2 = 1;break;
			case 'X':
				temp2 = 10;break;
			case 'C':
				temp2 = 100;break;
			case 'M':
				temp2 = 1000;break;
			case 'V':
				temp2 = 5;break;
			case 'L':
				temp2 = 50;break;
			case 'D':
				temp2 = 500;break;
			default:
				temp2 = 0;break;
			}//switch(s[pos+1]
		}
		if(before && temp<temp2)//С���ڴ��ǰ��
			res += -temp;
		else
			res += temp;
	}
	return res;
}


int main()
{
	string s;
	cout<<"��������������"<<endl;
	cin >> s;
	cout<<romanToInt(s);
	fflush(stdin);
	getchar();
	return 0;
}