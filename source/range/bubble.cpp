/*
	ð��������ʱ��ĺ���Ҫ
	����˼�룺�Ƚ���������Ԫ�أ�������С��ǰһ��Ԫ�أ���������Ԫ�ص�
			  ֵ�����һ�˱Ƚ������κ�Ԫ��������ֹͣ��
	���Ӷȣ�O��N*N)
*/
#include <stdio.h>
#include <stdlib.h>

/*
	*op1 > *op2,�ȽϺ���1
*/
int fcmp1(const void *op1,const void *op2)
{
	return *(int*)op1 - *(int*)op2;
}
/*
	*op2 > *op1���ȽϺ���2
*/
int fcmp2(const void *op1,const void *op2)
{
	return *(int*)op2 - *(int*)op1;
}
/*
	�������ܣ�ð������
	������
		@ptr : ����ָ��
		@len : ���鳤��
		@fcmp : �ȽϺ���

*/
void bubble(int * ptr,int len,int (*fcmp)(const void*op1,const void *op2))
{
    bool ok;//���ڼ�¼��ǰ�������Ƿ�������ԣ������ok = 0,����okֵ����
    for(int i=0;i<len-1;++i)//��������Ҫlen-1��
    {
        ok = 1;
        for(int j=len-1;j>i;--j)//���������ƶ������ݱȽϺ������ж���
        {
            if(fcmp(&ptr[j],&ptr[j-1]) > 0)/*ptr[j] > ptr[j-1]ʱ�򽻻�*/
            {
                int temp = ptr[j];
                ptr[j] = ptr[j-1];
                ptr[j-1] = temp;
                ok = 0;
            }
        }
        if(ok)//���û������ԣ�˵�������Ѿ����
            return;
    }

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
	int i = 0,len = 0;
	int a[] = {0,2,3,4,10,8,7};
	len = sizeof(a)/sizeof(a[0]);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	bubble(a,len,fcmp2);

	printf("\nafter bubble:\n ");
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	getchar();
	return 0;
}