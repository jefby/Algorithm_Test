/*
	*	This is for 6174 question 
	*	input : a number which is in [1234,9876],and every bit is not equal
	*	output : the process of transform until some number equals to number ealier occurs
	*	author: jefby
	*	email: jef199006@gmail.com
	*	example :
	*	input 1234 
	*	output: 1234 3087 8352 6174
*/

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5005
typedef char  type;
#if 0
//ð������
int bubble_sort(type *a,int len)
{
//	char *_a = (char*)a;
	int ok = 1;
	assert(a&&len>0);
	for(int i=0;i<len-1;++i)
	{
		int ok = 1;
		for(int j=len-1;j>i;--j)
		{
			if(a[j] < a[j-1])
			{
				type tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;	
				ok = 0;
			}
		}
		if(ok)
			break;
	}
	return 0;
}
int get_next(int x)
{
	assert(x>=1234 && x <= 9876);
	char tmp[5];
	memset(tmp,0,sizeof(tmp));//�ַ������ʼ��Ϊ0
	sprintf(tmp,"%d",x);//��xת��Ϊ�ַ���
	bubble_sort(tmp,4);//��С��������
	int min,max;
	sscanf(tmp,"%d",&min);//��tmpת��Ϊ����,�洢��min��
	
	//invert the order,���򻯴���
	for(int i=0;i<4/2;++i)
	{
		int xx = tmp[i];
		tmp[i] = tmp[3-i];
		tmp[3-i] = xx;
	}
	sscanf(tmp,"%d",&max);//��tmpת��Ϊ���֣��洢��max��
	printf("max=%d,min=%d\n",max,min);//�����С�����ֵ

	return max-min;	//�õ���ֵ
}
#endif
/*
	����˵�������ڿ�������ıȽϺ���
	����˵����
	@op1����1
	@op2����2
*/
int fcmp(const void*op1,const void*op2)
{
	return *(char*)op1-*(char*)op2;
}

/*
	�������ܣ����x��������������Сֵ������x��������x>=1234����x<=9876
	����˵����
	@x��4λ������
	����ֵ��
	����x�����������ֵ����Сֵ�Ĳ�ֵ
*/
int get_next(int x)
{
	assert(x>=1234 && x <= 9876);
	char tmp[5];
	memset(tmp,0,sizeof(tmp));//�ַ������ʼ��Ϊ0
	sprintf(tmp,"%d",x);//��xת��Ϊ�ַ���
	qsort(tmp,4,sizeof(char),fcmp);//��С��������
	int min,max;
	sscanf(tmp,"%d",&min);//��tmpת��Ϊ����,�洢��min��
	
	//invert the order,���򻯴����õ����ֵ
	for(int i=0;i<4/2;++i)
	{
		int xx = tmp[i];
		tmp[i] = tmp[3-i];
		tmp[3-i] = xx;
	}
	sscanf(tmp,"%d",&max);//��tmpת��Ϊ���֣��洢��max��
	//printf("max=%d,min=%d\n",max,min);//�����С�����ֵ

	return max-min;	//�õ���ֵ
}

int num[MAX];

int main()
{
	int count = 0;
	int i = 0;
	printf("6174���⣬������4λ����������ÿһλֵ��ͬ\n");
	scanf("%d",&num[0]);
	int ok = 1;
	while(1)
	{	
		int x = get_next(num[count]);	
		//����֮ǰ�Ƿ���ֹ�
		ok = 1;
		for(i=0;i<count;i++)
		{
			if(num[i] == num[count])//�Ѿ����ֹ�
			{
				ok = 0;//��ǲ��˳�
				break;
			}
		}
		if(ok)
			num[++count] = x;//���û�г��ֹ����򱣴浽�����count+1λ�ô���������count
		else
			break;//�����˳�
	}
	printf("ת��˳��");
	for(i=0;i<count;++i)//��ӡ���ֵ�˳��
	{
		printf("%d",num[i]);
		if(i!=count-1)
			printf("=>");
	}
	printf("\n");
	fflush(stdin);//����vs2008����ͣ
	getchar();
	return 0;
}
