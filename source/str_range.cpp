/*
	��Ŀ������
	����n���ַ�����������
	��������
	3
	abcdef
	ab
	xyz
	�������
	ab
	abcdef
	xyz
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fcmp(const void *op1,const void *op2)
{
	return strcmp(*(const char**)op1,*(const char**)op2);
}

void myswap(void *op1,void *op2,unsigned bytes)
{
	
	int i = 0;
	unsigned char tmp = 0;
	if(op1 != op2){//����ȲŽ���
		for(i=0;i<bytes;++i){
			tmp = *((unsigned char*)op1+i);
			*((unsigned char*)op1+i)=*((unsigned char*)op2+i);
			*((unsigned char*)op2+i)=tmp;//����
		}
	}//if(op1 != op2)
}
/*
	�������ܣ�ð������
	������
		@ptr : ����ָ��
		@len : ���鳤��
		@fcmp : �ȽϺ���

*/
void bubble_sort(void * base,int numOfEelements,int sizeOfElements,int (*fcmp)(const void*op1,const void *op2))
{
    bool ok;//���ڼ�¼��ǰ�������Ƿ�������ԣ������ok = 0,����okֵ����
    for(int i=0;i<numOfEelements-1;++i)//��������Ҫlen-1��
    {
        ok = 1;
        for(int j=numOfEelements-1;j>i;--j)//���������ƶ������ݱȽϺ������ж���
        {
            if(fcmp(((char*)base+j*sizeOfElements),((char*)base+(j-1)*sizeOfElements)) < 0)/*ptr[j] > ptr[j-1]ʱ�򽻻�*/
            {
				myswap((char*)base+j*sizeOfElements,(char*)base+(j-1)*sizeOfElements,sizeOfElements);
                ok = 0;
            }
        }
        if(ok)//���û������ԣ�˵�������Ѿ����
            return;
    }

}
int main()
{
	int n = 0,i = 0;
	char **p =NULL;
	printf("������n���ַ�����");
	scanf("%d",&n);
	//�����ڴ�
	p = (char**)calloc(n,sizeof(char*));
	for(i=0;i<n;++i){
		p[i]=(char*)calloc(100,sizeof(char));
		//��ȡn���ַ���
		scanf("%s",p[i]);
	}
	//ʹ�ÿ�������
	//qsort((char**)p,n,sizeof(char*),fcmp);
	bubble_sort((char**)p,n,sizeof(char*),fcmp);
	//�ͷ��ڴ�
	for(i=0;i<n;++i){
		printf("%s\n",p[i]);	
		free(p[i]);
	}
	free(p);
	fflush(stdin);
	getchar();
	

	return 0;
}