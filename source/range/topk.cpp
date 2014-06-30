/*
	问题描述：
	Top K问题
	方法1：使用快排排序，然后输出前K个元素即可

*/
#include <stdio.h>
#include <stdlib.h>


#define CONFIG_ONE

#if defined(CONFIG_ONE)
int len = 0;
void swap(int *a,int*b)
{
	int tmp = *a;
	if(a != b){//检测相同元素
		*a = *b;
		*b = tmp;
	}
}

/*
	函数功能描述：原地划分子序列,返回枢纽元素的下标
	参数：
		@a : 整形数组指针
		@p : 起始地址
		@r : 结束地址
	说明：
	a[p..i]表示的是小于枢纽元素a[r]的值
	a[j..r]表示的是大于枢纽元素a[r]的值

*/
int partition(int *a,int p,int r)
{
	int pivot=0,i=0,j=0;
	/*
	printf("p=%d,r=%d\n",p,r);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	*/
	pivot = a[r];
	i = p-1;
	for(j=p;j<r;++j)
		if(a[j]<=pivot){//j指向的元素都大于pivot,i指向的元素都小于pivot
			i=i+1;
			swap(&a[i],&a[j]);//交换a[i]和a[j]
		}
	swap(&a[i+1],&a[r]);//交换枢纽元素
	//printf("partition\n");
	return i+1;
}
/*
	函数：快速排序,参考算法导论
	参数:
		@a :数组指针
		@p :起始位置
		@r :结束位置

*/
void quicksort(int *a,int p,int r)
{
	int q;
	if(p < r){
		q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q,r);
	}
}

//比较函数
int cmp(const void * a,const void *b)
{
	return *(int*)a-*(int*)b;
}
void topk(int a[],int len,int k)
{
	int i = 0;
	if(k<0 || k > len)
		return;
	printf("len=%d\n",len);
	qsort(a,len,sizeof(a[0]),cmp);//使用qsort进行快速排序
	for(i=0;i<k;++i)//输出前K个元素
		printf("%d ",a[i]);
	printf("\n");
}
#endif
int main()
{
	int i=0;
	int  a[]={1,0,2,10,100,1000,999,88};
	len = sizeof(a)/sizeof(a[0]);

	quicksort(a,0,len-1);
	for(i=0;i<len;++i)
		printf("%d ",a[i]);
	topk(a,len,2);
	getchar();
}