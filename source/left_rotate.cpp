//�ַ�������m��,
//��һ�ַ�����ʹ�ñ�����λ������һ�������ƶ�һλ
//�ڶ��ַ���������ָ����в������������
/*
	1�������� p1=ch[0]��p2=ch[m]������ p1��p2 ��� m �ľ��룻
	2���ж� p2+m-1 �Ƿ�Խ�磬���û��Խ��ת�� 3������ת�� 4��abcdefgh ��
		8 ����ĸ���ַ������� 4 ��������ô��ʼʱ p2 ָ�� e��p2+4 Խ���ˣ�����ʵ
		�� p2 �� p2+m-1 �� m ���ַ�����������һ����������
	3�����Ͻ���*p1 ��*p2��Ȼ�� p1++��p2++��ѭ�� m �Σ�Ȼ��ת�� 2��
	4����ʱ p2+m-1 �Ѿ�Խ�磬�ڴ�ֻ�账��β�͡��������£�
	4.1 ͨ�� n-p2 �õ� p2 ��β��֮��Ԫ�ظ��� r��������Ҫǰ�Ƶ�Ԫ�ظ�����
	4.2 ���¹���ִ�� r �Σ� ch[p2]<->ch[p2-1]�� ch[p2-1]<->ch[p2-2]�� ....��ch[p1+1]<->ch[p1]��p1++��p2++��

*/
/*
	�����ֽⷨ(���η�ת����)
	����Ҫ�������ַ�������Ϊ�����֣����ȷֱ�Ϊm��len-m��Ϊ�˷������������ߵ����ַ������Ϊ1���ұߵı��Ϊ2.����岽�����£�
	1.��ת�ַ���1
	2.��ת�ַ���2
	3.��ת�����ַ���
	�ó����
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

#define CONFIG_THREE

char str[] = "abcdefg";//�����char *str = "abcdefg"������ֻ�����4�ֽڵ����ݣ����ں���LeftPerOnebit�в��ܲ�������
//��һ�ֽⷨ
#if defined(CONFIG_ONE)
//����һλ
void LeftPerOnebit(char *str,int len)
{
	char ch = str[0];
	
	if(len <= 0 || str == NULL){
		printf("str error!\n");
		return;
	}
	
	for(int i=1;i<len;++i)
		*(str+i-1)=*(str+i);
	str[len-1]=ch;
}
void LeftRotate(char *str,int len,int m)
{
	while(m--){
		LeftPerOnebit(str,len);
	}
}
#endif
//�ڶ��ֽⷨ
#if defined(CONFIG_TWO)
/*
	�������ܣ����ַ���str����mλ
	@str :�ַ���ָ��
	@len :�ַ�������
	@m   :Ҫ������λ��
	��Ҫ���������:m < len
*/
	void LeftRotate(char *str,int len,int m)
	{
		int p1 = 0,p2 =m;
		int i = 0;
		int r = 0;
		char ch  = 0;
		//�����쳣�����ע�⵱Ҫ�����ĸ������ڻ��ߵ����ַ�������ʱ,ֱ���˳�
		if(m <= 0 || !str || len <=0 || len <= m)
			return;
		r = len /m -1;//����
	//�������
			while(r--){
				for(i=0;i<m;++i){
					swap(str[p1],str[p2]);
					++p1;
					++p2;
				}
			}
	//����β��
			if(len%m!=0){
				r = len - p2;//��Ҫ���ƵĴ���
				while(r--){
					ch = str[p2];//����P2��ֵ
					for(i=m;i>0;--i)
						str[p1+i]=str[p1+i-1];
					str[p1]=ch;//����P1
					++p1;//�ƶ�ָ��
					++p2;
				}
			}
	}
#endif

#if defined(CONFIG_THREE)
	void myswap(char *a,char *b)
	{
		char tmp = 0;
		if(!a || !b)
			return;
		if(a != b){//�ж��Ƿ��ַ��ͬ
			tmp = *a;
			*a= *b;
			*b = tmp;
		}
	}
	/*
		������������ת�ַ���beg��end����ڵ��ַ�
		����:
			@str���ַ���ָ��
			@beg: �ַ�����ʼ��ַ
			@end: �ַ���������ַ+1
	*/
	void helper(char *str,int beg,int end)
	{
		int len = end - beg;
		int i = 0;
		//�����쳣���:strָ����Ч��beg<=end
		if(!str || beg >= end || beg < 0 || end < 0 )
			return;
		for(i=0;i<len/2;++i)
			myswap(&str[beg+i],&str[end-1-i]);

	}
	/*
		�ַ�������m��
		������
			@str: �ַ���
			@len: �ַ�������
			@m  : Ҫ�������ַ�����
			������������m < len������m>0
	*/
	void LeftRotate(char *str,int len,int m)
	{
		if(m > 0 && m < len){//��Ч�Կ��ƣ��ų�m<=0������m>=len�����
			//��ת[0,m-1]����ַ���
			helper(str,0,m);
			//��ת[m,len-1]�ұ��ַ���
			helper(str,m,len);
			//��ת[0,len-1]�����ַ���
			helper(str,0,len);
		}
	}
#endif
int main()
{
	int m = sizeof(str);
	printf("original string is : %s\n",str);
	LeftRotate(str,sizeof(str)-1,m);

	printf("left rotate %d is : %s\n",m,str);
	getchar();
	return 0;
}