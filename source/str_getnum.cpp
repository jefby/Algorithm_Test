/*
	�������ܣ�����һ���ַ����������е�������ȡ����������֣�����������
	����������
	һ���ַ�������֤û�пո��Իس����������ַ�������<=20
	�������
	һ�У�һ������
	����������
	a177d298u29dee0
	���������
	177298290
*/
#include <stdio.h>
#include <string.h>
char str[5005];
/*�����κ��ַ���*/
int main()
{
	char ch;
	int i = 0;
	int flag = 0,len = 0;
#if 0
	for(i=0;i<20;++i){//ֻ����ǰ20���ַ�
		scanf("%c",&ch);
		if(ch == '\n')
			break;
		if(ch >= '0' && ch <= '9'){
			if(flag == 0 && ch == '0'){
				flag = 1;
				continue;
			}//����ǰ��0
			printf("%c",ch);//��������������
		}//if(ch >= '0' && ch <= '9')
	}//for
#endif
	scanf("%s",&str);
	len = strlen(str);
	if(len > 20)//�������20�����
		len = 20;
	for(i=0;i<len;++i){
		if(str[i]>='0'&&str[i]<='9'){
			if(str[i] == '0' && !flag){//ǰ��'0'
				flag = 1;
				continue;
			}
			printf("%c",str[i]);
		}
	}
	fflush(stdin);
	getchar();
	return 0;

}