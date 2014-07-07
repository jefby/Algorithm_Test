#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
	函数功能：字符串翻转单词
	具体描述：
	Clarification:
	What constitutes a word?
	A sequence of non-space characters constitutes a word.//非空字符串组成一个单词
	Could the input string contain leading or trailing spaces?
	Yes. However, your reversed string should not contain leading or trailing spaces.//删除前导和后置空格
	How about multiple spaces between two words?
	Reduce them to a single space in the reversed string.//截短多个空格为1个空格
	
	参数说明：
	@s：字符串
*/
void reverseWord(string &s)
{
	string ss;//空字符串
    int i = s.length()-1;  
    while(i>=0)
    {  
        while(i>=0&&s[i] == ' ')//处理多个空格的情况
            --i;  
        if(i<0) break;//前导0
        if(ss.length()!=0)//第一个单词不加' ',其他的单词加' '
            ss.push_back(' ');  
        string temp ;  
        for(;i>=0&&s[i]!=' ';i--)//暂存到temp中,逆序的
            temp.push_back(s[i]);  
        reverse(temp.begin(),temp.end());//翻转字符顺序
        ss.append(temp);//添加temp到ss中  
    }  
    s=ss;//赋值给s
}
int main()
{
	string s = "  abcd  ";

	cout << s;
	fflush(stdin);
	getchar();
}