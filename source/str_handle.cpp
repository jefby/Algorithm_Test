/*
	��Ŀ������
	����һ���ַ�����ɾ���������е����֣����д�д��ĸ�ĳ�Сд���������䣬�����
	����������
	һ���ַ�������֤û�пո��Իس����������ַ�������<=20
	�������
	һ���ַ�����Ϊ��ĿҪ��Ľ��
	��������
	aAbB13A
	�������
	aabba

*/
#include <stdio.h>
#include <string.h>

char str[5005];
char res[5005];

int main()
{
	int i = 0,len = 0,j=0;
	scanf("%s",&str);
	len = strlen(str);
	if(len > 20)
		len = 20;
	for(i=0;i<20;++i){
		if(str[i] >= 'A' && str[i] <= 'Z'){//�����д��ĸ
			res[j++] = str[i] + 0x20;//ת��ΪСд
		}else if(str[i] >= '0' && str[i] <= '9')//���ֵĻ�ɾ��
			continue;
		else
			res[j++] = str[i];//�������ַ�����res
	}
	printf("%s",res);
	fflush(stdin);
	getchar();
	return 0;
}