/*
	��Ŀ������
	����һ���ַ�����ͳ�������Ƶ����ߵ��ַ���������������������ַ�����Ƶ����ͬ��������ֵ����С����һ��
	��������
	һ���ַ�������֤û�пո��Իس����������ַ�������<=20
	�������
	һ���ַ�
	��������
	aabbcc
	�������
	a
*/
#include <stdio.h>
#include <string.h>

char str[5005];
char frq[256];
int main()
{
	int i = 0 ,len = 0,max = 0;
	scanf("%s",&str);
	len = strlen(str);
	if(len > 20)
		len = 20;
	for(i=0;i<len;++i)
		++frq[str[i]];
	
	for(i=0;i<256;++i){
		if(frq[i] > max){
			max = frq[i];
			len = i;
		}
	}
	printf("%c",len);
	fflush(stdin);
	getchar();
}