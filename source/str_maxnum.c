/*
	��Ŀ������
	����һ���ַ������������ִ����������֣�������������ֳ��ִ�����ͬ���������С����һ��
	��������
	һ���ַ�������֤û�пո��Իس����������ַ�������<=20
	�������
	һ�У�һ������
*/
#include <stdio.h>
#include <stdlib.h>
char str[5005];
unsigned char frq[10];

int main()
{
	int i=0,len=0,max=0;
	scanf("%s",str);
	len = strlen(str);
	if(len > 20)
		len = 20;
	for(i=0;i<len;++i){
		if(str[i]>='0'&&str[i]<='9')
			++frq[str[i]-'0'];
	}

	len = -1;//��¼���±�
	for(i=0;i<10;++i){
		if(frq[i] > max){
			max = frq[i];
			len = i;
		}
	}
	if(len > -1)//������Ҫ�Ǳ��⵱û���κ����ֳ��ֵ����
		printf("%d",len);
	fflush(stdin);
	getchar();
	return 0;
}