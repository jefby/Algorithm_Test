
/*
	Ⅰ(1)、X(10)、C (100)、M (1000),V (5)、L(50)、D (500)。记数的方法：
	(1)相同的数字连写，所表示的数等于这些数字相加得到的数，如，Ⅲ = 3；
	(2)小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如，Ⅷ = 8,Ⅻ = 12；
	(3)小的数字，（限于Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如，Ⅳ = 4，Ⅸ = 9；
*/
#include <iostream>
#include <string>


using namespace std;


int romanToInt(string s) 
{
	if(s.empty())//处理字符串为空的情况
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
		if(pos+1 < s.size()){//检测下一个元素的值
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
		if(before && temp<temp2)//小的在大的前面
			res += -temp;
		else
			res += temp;
	}
	return res;
}


int main()
{
	string s;
	cout<<"请输入罗马数字"<<endl;
	cin >> s;
	cout<<romanToInt(s);
	fflush(stdin);
	getchar();
	return 0;
}