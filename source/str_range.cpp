/*
	题目描述：
	输入n个字符串，做排序
	输入样例
	3
	abcdef
	ab
	xyz
	输出样例
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
	if(op1 != op2){//不相等才交换
		for(i=0;i<bytes;++i){
			tmp = *((unsigned char*)op1+i);
			*((unsigned char*)op1+i)=*((unsigned char*)op2+i);
			*((unsigned char*)op2+i)=tmp;//交换
		}
	}//if(op1 != op2)
}
/*
	函数功能：冒泡排序
	参数：
		@ptr : 数组指针
		@len : 数组长度
		@fcmp : 比较函数

*/
void bubble_sort(void * base,int numOfEelements,int sizeOfElements,int (*fcmp)(const void*op1,const void *op2))
{
    bool ok;//用于记录当前趟数中是否有逆序对，如果有ok = 0,否则ok值不变
    for(int i=0;i<numOfEelements-1;++i)//最坏情况下需要len-1趟
    {
        ok = 1;
        for(int j=numOfEelements-1;j>i;--j)//从右向左移动，根据比较函数进行动作
        {
            if(fcmp(((char*)base+j*sizeOfElements),((char*)base+(j-1)*sizeOfElements)) < 0)/*ptr[j] > ptr[j-1]时候交换*/
            {
				myswap((char*)base+j*sizeOfElements,(char*)base+(j-1)*sizeOfElements,sizeOfElements);
                ok = 0;
            }
        }
        if(ok)//如果没有逆序对，说明排序已经完成
            return;
    }

}
int main()
{
	int n = 0,i = 0;
	char **p =NULL;
	printf("请输入n个字符串：");
	scanf("%d",&n);
	//申请内存
	p = (char**)calloc(n,sizeof(char*));
	for(i=0;i<n;++i){
		p[i]=(char*)calloc(100,sizeof(char));
		//读取n个字符串
		scanf("%s",p[i]);
	}
	//使用快速排序
	//qsort((char**)p,n,sizeof(char*),fcmp);
	bubble_sort((char**)p,n,sizeof(char*),fcmp);
	//释放内存
	for(i=0;i<n;++i){
		printf("%s\n",p[i]);	
		free(p[i]);
	}
	free(p);
	fflush(stdin);
	getchar();
	

	return 0;
}