#include <iostream>
#include <vector>
#include <string>
#include <deque>//双端队列
#include <stack>

using namespace std;

/*
	题目描述：
	Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

	For example, given n = 3, a solution set is:

	该问题和《编程之美》的买票找零问题一样，通过买票找零问题我们可以知道，
	针对一个长度为2n的合法排列，第1到2n个位置都满足如下规则：
			左括号的个数大于等于右括号的个数。
	所以，我们就可以按照这个规则去打印括号：
	假设在位置k我们还剩余left个左括号和right个右括号，如果left>0，则我们可以
	直接打印左括号，而不违背规则。能否打印右括号，我们还必须验证left和right
	的值是否满足规则，如果left>=right，则我们不能打印右括号，因为打印会违背
	合法排列的规则，否则可以打印右括号。如果left和right均为零，则说明我们已
	经完成一个合法排列，可以将其打印出来。通过深搜，我们可以很快地解决问题，
	针对n=2，问题的解空间如下：

	参数说明：
	leftNum：剩余的左括号个数
	rightNum：剩余的右括号个数
	s：保存当前的排列
	result：所有的排列
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
	题目描述：
	数组的入栈出栈顺序问题：给定一个长度为n的不重复数组，求所有可能的入栈出栈顺序。

	解释：
	在某一个特定时刻，入栈的次数大于或者等于出栈的次数。在生成括号的问题中，我们
	利用一个string来保存结果，由于打印左括号时不影响打印右括号，所以无需复杂的状态
	恢复。在入栈出栈顺序问题中，由于两次递归调用共享同一个栈和队列，所以我们需要手动
	恢复其内容。在恢复时，队列会从头部删除和添加，所以我们采用了deque，它可以在头部
	添加和删除元素。queue只能在头部删除元素，所以没有采用。

	参数说明：
	@in：剩余的入栈元素个数，初始值为数组元素个数
	@out：剩余的出栈元素个数
	@q：队列
	@s：栈
	@seq：初始的不重复数组
	@result：所有的出入栈顺序组合
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
	cout<<"请输入n对括号的有效排列"<<endl;
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