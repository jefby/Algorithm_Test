/*
	堆排序：O(n*logn)
	堆数组定义：从下标1开始，下标0存储堆元素个数

*/
#include <stdio.h>


//#define MAX_HEAP
#define MIN_HEAP
/*有关堆的一些定义*/
#define PARENT(i) ((i)/2)
#define LEFT(i) (2*(i))
#define RIGHT(i) (2*(i)+1)

/*交换元素*/
void swap(int *a,int *b)
{
	int tmp = *a;
	if(a!=b){
		*a = *b;
		*b = tmp;
	}
}
/*
	函数功能：堆调整，将给定以i为root的堆调整为最大堆
	参数说明：
		@a : 指针
		@i : 根节点下标索引值
*/
void max_heapify(int *a,int i)
{
	int largest = 0;//存储当前堆中值最大的下标
	int l = LEFT(i);//左节点
	int r = RIGHT(i);//右节点
	if(l <= a[0] && a[l] > a[i])//如果在堆中，并且a[l]>a[i],不满足最大堆特性，调整
		largest = l;
	else
		largest = i;
	if(r <= a[0] && a[r] > a[largest])//如果是在堆中，并且a[r]>a[largest],不满足最大堆的特性
		largest = r;
	
	if(largest != i){//如果值最大的下标不是i，则交换根节点处的值，然后向下递归调整堆
		swap(&a[largest],&a[i]);//调整堆元素	
		max_heapify(a,largest);//递归调整以largest为root的堆
	}
}
/*
	函数功能：构建最大堆,a[0]表示堆元素个数
	参数：
	@a : 数组指针
	@len : 数组元素个数
*/
void build_maxheap(int *a,int len)
{
	int i = 0;
	a[0] = len;//堆元素个数

	for(i=len/2;i>0;--i)
		max_heapify(a,i);
}

/*
	函数功能：最小堆调整，将给定以i为root的堆调整为最小堆
	参数说明：
		@a : 指针
		@i : 根节点下标索引值
*/
void min_heapify(int *a,int i)
{
	int least = 0;//存储当前堆中值最小的下标
	int l = LEFT(i);//左节点
	int r = RIGHT(i);//右节点
	if(l <= a[0] && a[l] < a[i])//如果在堆中，并且a[l]>a[i],不满足最小堆特性，调整
		least = l;
	else
		least = i;
	if(r <= a[0] && a[r] < a[least])//如果是在堆中，并且a[r]>a[largest],不满足最小堆的特性
		least = r;
	
	if(least != i){//如果值最大的下标不是i，则交换根节点处的值，然后向下递归调整堆
		swap(&a[least],&a[i]);//调整堆元素	
		min_heapify(a,least);//递归调整以largest为root的堆
	}
}
/*
	函数功能：构建最大堆,a[0]表示堆元素个数
	参数：
	@a : 数组指针
	@len : 数组元素个数
*/
void build_minheap(int *a,int len)
{
	int i = 0;
	a[0] = len;//堆元素个数

	for(i=len/2;i>0;--i)
		min_heapify(a,i);
}
/*
	堆排序实现，思路：
	每次选取根节点，然后与堆中最后一个元素互换，递减堆元素个数，调整堆。
	参数说明：
	@a : 数组指针
	@len : 数组元素个数
*/
void heap_sort(int *a,int len)
{
	int i = 0;
#if defined(MAX_HEAP)
	build_maxheap(a,len);//构建最大堆
#else 
	build_minheap(a,len);//构建最小堆
#endif
	for(i=len;i>1;--i){
		swap(&a[1],&a[i]);//交换最后一个元素
		--a[0];//heapsize -= 1
#if defined(MAX_HEAP)
		max_heapify(a,1);//调整最大堆
#else
		min_heapify(a,1);//调整最小堆
#endif
	}		
}

int main()
{
	int i = 0;
	int a[]={0,2,3,4,5,1,-1,10};
	int len = (sizeof(a))/sizeof(a[0])-1;
	heap_sort(a,len);
	for(i=1;i<len+1;++i)
		printf("%d ",a[i]);
	getchar();

}