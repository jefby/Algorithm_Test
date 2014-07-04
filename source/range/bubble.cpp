/*
	冒泡排序，有时真的很重要
	基本思想：比较相邻两个元素，若后面小于前一个元素，交换两个元素的
			  值，如果一趟比较中无任何元素逆序，则停止。
	复杂度：O（N*N)
*/
#include <stdio.h>
#include <stdlib.h>

/*
	*op1 > *op2,比较函数1
*/
int fcmp1(const void *op1,const void *op2)
{
	return *(int*)op1 - *(int*)op2;
}
/*
	*op2 > *op1，比较函数2
*/
int fcmp2(const void *op1,const void *op2)
{
	return *(int*)op2 - *(int*)op1;
}
/*
	函数功能：冒泡排序
	参数：
		@ptr : 数组指针
		@len : 数组长度
		@fcmp : 比较函数

*/
void bubble(int * ptr,int len,int (*fcmp)(const void*op1,const void *op2))
{
    bool ok;//用于记录当前趟数中是否有逆序对，如果有ok = 0,否则ok值不变
    for(int i=0;i<len-1;++i)//最坏情况下需要len-1趟
    {
        ok = 1;
        for(int j=len-1;j>i;--j)//从右向左移动，根据比较函数进行动作
        {
            if(fcmp(&ptr[j],&ptr[j-1]) > 0)/*ptr[j] > ptr[j-1]时候交换*/
            {
                int temp = ptr[j];
                ptr[j] = ptr[j-1];
                ptr[j-1] = temp;
                ok = 0;
            }
        }
        if(ok)//如果没有逆序对，说明排序已经完成
            return;
    }

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