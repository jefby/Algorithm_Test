/*	
	��Ŀ������
	����n���ַ����������е�������ȡ����������֣��������
	��������
	��һ�У���һ������n��֮��n�У�ÿ��һ���ַ���
	�������
	n�У�ÿ�����ź���֮���һ������
*/
#include <stdio.h>
#include <stdlib.h>


/*��ȡ�ַ����е�����*/
unsigned int mystrtoul(const char*str)
{
	unsigned int res = 0;

	if(!str)
		return res;
	while(*str++){
		if(*str >= '0' && *str <= '9')
			res = 10*res + (*str-'0');
	}
	return res;
}
/*�Ƚ�������*/
int fcmp(const void *op1,const void*op2)
{
	return *(unsigned int*)op2 - *(unsigned int*)op1;
}
int main()
{
	int n = 0,i = 0;
	char **p =NULL;
	unsigned int * helper = NULL;
	scanf("%d",&n);
	//����ռ�
	p = (char**)malloc(n*sizeof(char*));//
	helper = (unsigned int*)calloc(n,sizeof(unsigned int));//���븨���ռ�
	for(i=0;i<n;++i){
		p[i] = (char*)malloc(1000*sizeof(char));
		scanf("%s",p[i]);//��ȡn���ַ���
		helper[i] = mystrtoul(p[i]);
	}
	qsort(helper,n,sizeof(unsigned int),fcmp);
	for(i=0;i<n;++i)
		printf("%d\n",helper[i]);
	//�ͷŶ�̬������ڴ�
	for(i=0;i<n;++i){
		free(p[i]);
	}
	free(p);
	fflush(stdin);
	getchar();
	return 0;
}