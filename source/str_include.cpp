/*
	�ַ�����������
	���ַ���A�Ƿ�����ַ���B��ȫ���ַ�
	˼·1��
	ʹ�ù���ӳ���256���ַ����һ����һ��ӳ�����¼�ַ���A���Ƿ����
*/
#include <stdio.h>
#include <string.h>

int helper(char *a,char *b)
{
	size_t i=0;
	//p1ָ��ϳ��ַ�����p2ָ��϶��ַ���
	char *p1,*p2;


	unsigned char map[256];
	if(!a || !b)
		return -1;
	//�ж��ַ���a��b�ĳ���
	
	if(strlen(a) < strlen(b)){
		p1 = b;
		p2 = a;
	}else{
		p1 = a;
		p2 = b;
	}
		
	memset(map,0,sizeof(map));//��ʼ��ӳ���
	for(i=0;i<strlen(p1);++i)//���A�д��ڵ��ַ�
		map[p1[i]]=1;
	for(i=0;i<strlen(p2);++i){//Ѱ���Ƿ���ȫ����
		if(!map[p2[i]])
			return 0;
	}
	return 1;
}
int main()
{
	int res;
	char a[]="hello,I am";
	char b[]="helx";
	res = helper(a,b);
	if(res == 0)
		printf("no");
	else if(res == 1)
		printf("yes");
	else
		printf("error");
	getchar();
	return 0;
}