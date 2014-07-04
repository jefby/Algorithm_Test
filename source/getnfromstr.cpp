/*	
	题目描述：
	输入n个字符串，将其中的数字提取出来组成数字，排序输出
	输入描述
	第一行，读一个数字n，之后n行，每行一个字符串
	输出描述
	n行，每行是排好序之后的一个数字
*/
#include <stdio.h>
#include <stdlib.h>


/*提取字符串中的数字*/
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
/*比较排序函数*/
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
	//申请空间
	p = (char**)malloc(n*sizeof(char*));//
	helper = (unsigned int*)calloc(n,sizeof(unsigned int));//申请辅助空间
	for(i=0;i<n;++i){
		p[i] = (char*)malloc(1000*sizeof(char));
		scanf("%s",p[i]);//读取n个字符串
		helper[i] = mystrtoul(p[i]);
	}
	qsort(helper,n,sizeof(unsigned int),fcmp);
	for(i=0;i<n;++i)
		printf("%d\n",helper[i]);
	//释放动态申请的内存
	for(i=0;i<n;++i){
		free(p[i]);
	}
	free(p);
	fflush(stdin);
	getchar();
	return 0;
}