/*
	����������
	ȥ���ظ�Ԫ�ص�ȫ����

*/
#include <stdio.h>
#include <string.h>

void swap(char *a,char*b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
//��pszStr�����У�[nBegin,nEnd)���Ƿ����������±�ΪnEnd���������  
bool IsSwap(char *pszStr, int nBegin, int nEnd)  
{  
    for (int i = nBegin; i < nEnd; i++)  
        if (pszStr[i] == pszStr[nEnd])  
            return false;  
    return true;  
}  
/*
	k��ʾ��ǰѡȡ���ڼ�������m��ʾ���ж��ٸ���-1��ֵ
*/
void allrange(char *szStr,int k,int m)
{
	if(k == m){
		static int s_i = 1;
		printf("��%3d������\t%s\n",s_i++,szStr);
	}else{
		for(int i = k;i<=m;++i){//��i�����ֱ�������������ֽ������ܵõ��µ�����
			if(IsSwap(szStr,k,i)){
				swap(szStr+k,szStr+i);//����˳��
				allrange(szStr,k+1,m);//��k+1������ʼѡȡ
				swap(szStr+k,szStr+i);
			}
		}
	}
}
void foo(char *str)
{
	allrange(str,0,strlen(str)-1);
}

int main()
{
	char str[10];/**/
	printf("�ݹ��ȫ����.\n�������ַ�����������С�ڵ���10��");
	scanf("%s",str);
	foo(str);
	fflush(stdin);
	getchar();
	return 0;
}