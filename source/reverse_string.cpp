#include <iostream> 
#include <string> 
using namespace std; 

/*
	预处理字符串string,删除重复的空格，只保留一个
*/
void pre_handle_string(string &str)
{
	string::iterator it ,beg ;
	for(it = str.begin();it < str.end();){
		if(*it == ' '){
			beg = it;
			while(it < str.end() && *it == ' ')//递增统计str中重复的空格
				++it;
			if(beg < it-1)
				it = str.erase(beg,it-1);//删除掉重复的空格，只保留最后一个
		}else
			++it;
	}
	it = str.begin();
	if(it != str.end() && *it == ' ')
		str.erase(it);//删除前导空格	
	string::size_type pos = 0;
	if(str.size() > 1){
		pos = str.size()-1;
		if(str[pos] == ' ')
			str.erase(pos);
	}
}
void reverseWord(string &str){
	
	int i=0,j = 0,k = 0,m=0;
    int len = str.length();
	string::iterator it ,beg ;
	string tmp=str;

	for(it = str.begin();it < str.end();){
		if(*it == ' '){
			beg = it;
			while(it < str.end() && *it == ' ')//递增统计str中重复的空格
				++it;
			if(beg < it-1)
				it = str.erase(beg,it-1);//删除掉重复的空格，只保留最后一个
		}else
			++it;
	}
	it = str.begin();
	if(it != str.end() && *it == ' ')
		str.erase(it);//删除前导空格	
	string::size_type pos = 0;
	if(str.size() > 1){
		pos = str.size()-1;
		if(str[pos] == ' ')
			str.erase(pos);
	}
	
    for(j=len-1,i=len-1,k=0;j>=-1;--j){
    	if((j>=0&&str[j] == 0x20) || j == -1){//碰见空格，打断当前过程，复制到新的字符串中
    		m = j-1;//记录新的位置
    		++j;//移动j指针
    		if(j>i){
    			tmp[k]='\0';
    			break;
    		}
    		for(;j<=i;++j)//将给word拷贝给新的字符串
    			tmp[k++]=str[j];
    		tmp[k++]=0x20;
    		j=m;//调整j和i指针
    		i=m;
    	}
    }
    str = tmp;
}

int main() 
{
	string    str("    "); 
	
	pre_handle_string(str);
	if(!str.empty())
		cout << str << endl; 
	reverseWord(str);
	if(!str.empty())
		cout << str << endl; 
	//reverseWord(str);
	//cout << str << endl; 
	fflush(stdin);
	getchar();
}