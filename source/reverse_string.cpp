#include <iostream> 
#include <string> 
using namespace std; 

/*
	Ԥ�����ַ���string,ɾ���ظ��Ŀո�ֻ����һ��
*/
void pre_handle_string(string &str)
{
	string::iterator it ,beg ;
	for(it = str.begin();it < str.end();){
		if(*it == ' '){
			beg = it;
			while(it < str.end() && *it == ' ')//����ͳ��str���ظ��Ŀո�
				++it;
			if(beg < it-1)
				it = str.erase(beg,it-1);//ɾ�����ظ��Ŀո�ֻ�������һ��
		}else
			++it;
	}
	it = str.begin();
	if(it != str.end() && *it == ' ')
		str.erase(it);//ɾ��ǰ���ո�	
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
			while(it < str.end() && *it == ' ')//����ͳ��str���ظ��Ŀո�
				++it;
			if(beg < it-1)
				it = str.erase(beg,it-1);//ɾ�����ظ��Ŀո�ֻ�������һ��
		}else
			++it;
	}
	it = str.begin();
	if(it != str.end() && *it == ' ')
		str.erase(it);//ɾ��ǰ���ո�	
	string::size_type pos = 0;
	if(str.size() > 1){
		pos = str.size()-1;
		if(str[pos] == ' ')
			str.erase(pos);
	}
	
    for(j=len-1,i=len-1,k=0;j>=-1;--j){
    	if((j>=0&&str[j] == 0x20) || j == -1){//�����ո񣬴�ϵ�ǰ���̣����Ƶ��µ��ַ�����
    		m = j-1;//��¼�µ�λ��
    		++j;//�ƶ�jָ��
    		if(j>i){
    			tmp[k]='\0';
    			break;
    		}
    		for(;j<=i;++j)//����word�������µ��ַ���
    			tmp[k++]=str[j];
    		tmp[k++]=0x20;
    		j=m;//����j��iָ��
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