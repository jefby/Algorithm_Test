#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
	�������ܣ��ַ�����ת����
	����������
	Clarification:
	What constitutes a word?
	A sequence of non-space characters constitutes a word.//�ǿ��ַ������һ������
	Could the input string contain leading or trailing spaces?
	Yes. However, your reversed string should not contain leading or trailing spaces.//ɾ��ǰ���ͺ��ÿո�
	How about multiple spaces between two words?
	Reduce them to a single space in the reversed string.//�ض̶���ո�Ϊ1���ո�
	
	����˵����
	@s���ַ���
*/
void reverseWord(string &s)
{
	string ss;//���ַ���
    int i = s.length()-1;  
    while(i>=0)
    {  
        while(i>=0&&s[i] == ' ')//�������ո�����
            --i;  
        if(i<0) break;//ǰ��0
        if(ss.length()!=0)//��һ�����ʲ���' ',�����ĵ��ʼ�' '
            ss.push_back(' ');  
        string temp ;  
        for(;i>=0&&s[i]!=' ';i--)//�ݴ浽temp��,�����
            temp.push_back(s[i]);  
        reverse(temp.begin(),temp.end());//��ת�ַ�˳��
        ss.append(temp);//���temp��ss��  
    }  
    s=ss;//��ֵ��s
}
int main()
{
	string s = "  abcd  ";

	cout << s;
	fflush(stdin);
	getchar();
}