#include <iostream>
#include <vector>
#include <string>
#include <deque>//˫�˶���
#include <stack>

using namespace std;

/*
	��Ŀ������
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

	For example, given n = 3, a solution set is:

	������͡����֮��������Ʊ��������һ����ͨ����Ʊ�����������ǿ���֪����
	���һ������Ϊ2n�ĺϷ����У���1��2n��λ�ö��������¹���
			�����ŵĸ������ڵ��������ŵĸ�����
	���ԣ����ǾͿ��԰����������ȥ��ӡ���ţ�
	������λ��k���ǻ�ʣ��left�������ź�right�������ţ����left>0�������ǿ���
	ֱ�Ӵ�ӡ�����ţ�����Υ�������ܷ��ӡ�����ţ����ǻ�������֤left��right
	��ֵ�Ƿ�����������left>=right�������ǲ��ܴ�ӡ�����ţ���Ϊ��ӡ��Υ��
	�Ϸ����еĹ��򣬷�����Դ�ӡ�����š����left��right��Ϊ�㣬��˵��������
	�����һ���Ϸ����У����Խ����ӡ������ͨ�����ѣ����ǿ��Ժܿ�ؽ�����⣬
	���n=2������Ľ�ռ����£�

	����˵����
	leftNum��ʣ��������Ÿ���
	rightNum��ʣ��������Ÿ���
	s�����浱ǰ������
	result�����е�����
*/
void generate(int leftNum,int rightNum,string s,vector<string> &result)  
    {  
        if(leftNum==0&&rightNum==0)  
        {  
            result.push_back(s);  
        }  
        if(leftNum>0)  
        {  
            generate(leftNum-1,rightNum,s+'(',result);  
        }  
        if(rightNum>0&&leftNum<rightNum)  
        {  
            generate(leftNum,rightNum-1,s+')',result);  
        }  
}  

/*
	��Ŀ������
	�������ջ��ջ˳�����⣺����һ������Ϊn�Ĳ��ظ����飬�����п��ܵ���ջ��ջ˳��

	���ͣ�
	��ĳһ���ض�ʱ�̣���ջ�Ĵ������ڻ��ߵ��ڳ�ջ�Ĵ��������������ŵ������У�����
	����һ��string�������������ڴ�ӡ������ʱ��Ӱ���ӡ�����ţ��������踴�ӵ�״̬
	�ָ�������ջ��ջ˳�������У��������εݹ���ù���ͬһ��ջ�Ͷ��У�����������Ҫ�ֶ�
	�ָ������ݡ��ڻָ�ʱ�����л��ͷ��ɾ������ӣ��������ǲ�����deque����������ͷ��
	��Ӻ�ɾ��Ԫ�ء�queueֻ����ͷ��ɾ��Ԫ�أ�����û�в��á�

	����˵����
	@in��ʣ�����ջԪ�ظ�������ʼֵΪ����Ԫ�ظ���
	@out��ʣ��ĳ�ջԪ�ظ���
	@q������
	@s��ջ
	@seq����ʼ�Ĳ��ظ�����
	@result�����еĳ���ջ˳�����
*/
void inoutstack(int in,int out,deque<int> &q,stack<int> &s,deque<int> seq,vector<deque<int>> &result)
	{
		if(!in&&!out)
		{
			result.push_back(q);
			return;
		}

		if(in>0)
		{
			s.push(seq.front());
			seq.pop_front();
			inoutstack(in-1,out,q,s,seq,result);
			seq.push_front(s.top());
			s.pop();
		}

		if(out>0&&in<out)
		{
			q.push_back(s.top());
			s.pop();
			inoutstack(in,out-1,q,s,seq,result);
			s.push(q.back());
			q.pop_back();
		}
	}
int main()
{
	vector<string> res;
	string s;
	cout<<"������n�����ŵ���Ч����"<<endl;
	int n = 0;
	cin>>n;
	generate(n,n,s,res);
	vector<string>::size_type pos = 0;
	for(pos=0;pos < res.size();++pos)
		cout<<res.at(pos)<<endl;

	deque<int> ideq ,q;
	stack<int> istack;
	vector<deque<int> > ivec;
	int a[]={1,2,3};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;
	for(i=0;i<len;++i)
		ideq.push_back(a[i]);
	inoutstack(len,len,q,istack,ideq,ivec);
	for(i=0;i<ivec.size();++i){
		for(int j=0;j<ivec.at(i).size();++j)
			cout<<ivec.at(i).at(j)<<" ";
		cout<<endl;
	}
	fflush(stdin);
	getchar();
}