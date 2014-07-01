/*
	�Լ�ʵ�ֵ��й��ַ����ĺ���
*/
#include <stdio.h>
#include <string.h>
#include <assert.h>//����

/*
	����˵�������ַ������Ⱥ���
	������
		@str �ַ���ָ��
	�����б߽���
*/
int mystrlen(const char *str)
{
	char *p = str;
	assert(str != NULL);//���strָ�����Ч��
	while(*p++);
	return (p-str-1);
}
/*
	����˵���������ַ���
	����˵����
			@str : �ַ���ָ��
			@substr : ���ַ���ָ��
	����ֵ�����ַ������ַ���str�е�λ�ã���������ڴ��ַ������򷵻�-1
*/
int mystrstr(const char *str,const char *substr)
{
	int lenstr = 0;
	int lensub = 0;
	int i = 0,j = 0;
	/*
	if(!str  || !substr)
		return -1;
	�޸�������ж�Ϊassert�꣬ɾ��ԭ���Ķ���
	*/
	assert(str != NULL && substr != NULL);//���ָ�����Ч��
	lenstr = mystrlen(str);//���ַ�������
	lensub = mystrlen(substr);//�����ַ�������
	if(lenstr < lensub)//�����쳣���
		return -1;
	for(i=0;i<lenstr;++i){
		for(j=0;j<lensub;++j){//���ַ���
			if(str[i+j] != substr[j])//�����һ���ַ�����ȣ��ж���ѭ��
				break;
		}
		if(j == lensub)//�ж��Ƿ���ȫƥ��
			return i;
	}
	return -1;
}

/*
	�������ܣ��ַ�������
	����˵����
	@src��Դ�ַ���
	@dst��Ŀ���ַ���
*/
char *mystrcpy(char *dst,const char *src)
{
	char * p = dst;//��¼dstָ��
	if(dst == src)return dst;//����Ƿ�ָ����ͬ���ڴ洦
	assert(dst != NULL && src != NULL);//���ָ�����Ч��
	while(*p++=*src++);//����
	return dst;//����dstָ��
}


/*
	�������ܣ������ַ����е�һ�γ��ֵ�ֻ����һ�ε��ַ�
	����˵����
	@str : �ַ���ָ��
	@len : �ַ�������
	����ֵ��ֻ����һ�ε��ַ�����
	˼·������ʹ�ù�ϣ��ķ�����ʵ�֣������������£�
	1.����һ��256��Ԫ�ص��������飬����ʼ��Ϊ-1
	2.Ȼ��ɨ���ַ������������һ�Σ���¼��������ֵ
	3.ɨ���ϣ���飬Ѱ������ֵ��СԪ�أ�Ȼ���ӡ���ַ�
*/
int FindOnlyChar(const char *str,int len)
{
	int i = 0,min=len;
	int map[256];
	assert(str != NULL && len > 0);//���ָ�����Ч��
	memset(map,-1,sizeof(map));//��ʼ��Ϊ-1
	//2.ɨ���ַ���
	for(i=0;i<len;++i){
		if(map[str[i]] == -1)
			map[str[i]] = i;//��¼����ֵ,������¼��һ�γ��ֵ�ֵ
		else
			map[str[i]] = -2;//��ֵ��ֵΪ-2,��ʾ���ִ�������һ��
	}
	for(i=0;i<256;++i){
		if(map[i] != -1 && map[i] != -2){
			if(map[i] < min)
				min = map[i];//����ֻ����һ�ε���С������
		}
	}
	if(min < len){
		printf("only one char is :%c\n",str[min]);
		return min;
	}else
		return -1;//��ʾû�������������ַ�
}

/*
	�������ܣ��ڴ濽�������Դ����ص����򿽱�
	����˵����
	@dst : �����ڴ��Ŀ�ĵ�
	@src �������ڴ��ԭʼ��
	@count : �������ֽ���
*/
void * mymemmove(void * dst,const void *src,size_t count)
{
	char * pdst = (char*)dst;
	char * psrc = (char*)src;
	assert(dst != NULL && src != NULL);
	if(pdst == psrc )
		return dst;
	//����Ŀ���ڴ��ַ>Դ�ڴ��ַ�����������ص�,��Ӻ���ǰ����
	if(pdst > psrc && (pdst-psrc) < count){
		while(count--)
			*(pdst+count)=*(psrc+count);//�Ӻ���ǰ����
	}else{
		while(count--)//��ǰ��󿽱�
			*pdst++=*psrc;
	}
	return dst;
}

/*
	�������ܣ��ַ������ֺ���
	����˵����
	@str : �ַ���ָ��
	@delim : Ҫ�ָ���ַ���,Ҳ���Գ�Ϊ�ָ��
	����ֵ��
	���طָ����ַ���ָ��
*/
char * mystrtok(char * str,const char *delim)
{
	static char * last = NULL;//���ڽ����´ηָ���׼��
	char * s = NULL,*d = delim;//��ʼ��
	int len = 0;
	assert(delim != NULL );
	if( (str == NULL) && ((str=last) == NULL))
		return NULL;
	s = str;
	len = mystrlen(delim);

	while(*s){
		d = delim;
		while(*d){
			while(*s && *d && *s == *d){//�ж�������һֱ����ָ��
				++s;
				++d;
			}
			if(*d == '\0' ){//�жϼ���ƥ���ַ�������ĩβ����ض�ԭʼ�ַ�����
				*(str+(s-str-len)) = '\0';
				last = s;//��¼��һ��ƥ���ַ�������ʼ��ַ
				return str;
			}else
				++d;//��ƥ��
		}//while(*d)
		++s;
	}//while(*s)
	if(last != NULL && *s == '\0' )//����str�ַ���δ�꣬��ƥ���Ѿ���ɵ����
		return last;
	return NULL;

}
int main()
{
	int res = -1,len = 0,i=0;
	char str[]="abcdefg";
	char substr[]="h";
	char str1[]="aaaabcceaedb";
	char str2[100]="abcdefghijklmn";
	char str3[]="abcdef-,ghi-,jkl";
	char *p = NULL;
	res = mystrstr(str,substr);
	if(res != -1)
		printf("ok");
	else
		printf("substr \"%s\" is not included by str \"%s\"\n",substr,str);
	
	len = mystrlen(str1);
	FindOnlyChar(str1,len);
	p = (char*)malloc(len+1);
	mystrcpy(p,str1);
	printf("after copied string is %s\n",p);
	mymemmove(str2+2,str2,20);
	for(i=0;i<100;++i)
		printf("%c ",str2[i]);
	p = mystrtok(str3,"-,");//����"-,"�������ָ��ַ���str3
	while(p!= NULL){
		printf("strtok : %s\n",p);
		p = mystrtok(NULL,"-,");
	}//while(p!=NULL)

	getchar();
	return 0;
}