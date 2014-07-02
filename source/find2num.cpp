/*
	题目描述：寻找和为定值的两个数
	思路：使用快排先排序，然后使用和减去数组的每个元素，得到一个新的数组，利用指针来进行
	排序后得到的原始序列：1、 2、 4、 7、11、15     用输入数字15减一下各个数，得到对应的序列为：
对应序列：14、13、11、8、4、 0     

	要达到O(N)的复杂度，第一个数组以一指针i 从数组最左端开始向右扫描，第二个数组以一指针j 
	从数组最右端开始向左扫描，首先初始i指向元素1，j指向元素0，谁指的元素小，谁先移动，由于
	1（i）>0（j），所以i不动，j向左移动。然后j移动到元素4发现大于元素1，故而停止移动j，开始移动i，
	直到i指向4，这时,i指向的元素与j指向的元素相等，故而判断4是满足条件的第一个数；然后同时
	移动i,j再进行判断，直到它们到达边界
*/
#include <stdio.h>
#include <stdlib.h>

int fcmp(const void*op1,const void *op2)
{
	return *(int*)op1- *(int*)op2;
}
/*
	函数功能：寻找和为定值的两个数
	参数说明：
	@a：数组指针
	@len：数组元素个数
	@m：定值和
*/
int find2sum(int *a,int len,int m)
{
	int * b = NULL;
	int i = 0,j = 0 ;
	b = (int*)malloc(len*sizeof(int));
	int flag = 0;

	qsort(a,len,sizeof(int),fcmp);//从小到大排序
	for(i=0;i<len;++i)
		b[i]=m-a[i];//得到辅助数组b
	//i从左向右扫描，j从右向左扫描
	for(i=0,j=len-1;i<j;){
		if(a[i] < b[j])//如果i所指向的元素值小，则移动i,j不变
			++i;
		else if(a[i] > b[j])//如果j所指向的元素值小,则移动j,i不变
			--j;
		else{//相等，则输出位置和值
			printf("pos:%d %d value:%d %d\n",i,j,a[i],m-a[i]);
			flag = 1;
			++i;
			--j;
		}
	}
	return flag;
}
int main()
{
	int a[]={2,3,1,4};
	int *b =NULL;
	int i =0,j=0;
	int m = 0;
	int len = sizeof(a)/sizeof(a[0]);
	printf("请输入和值\n");
	scanf("%d",&m);

	if(find2sum(a,len,m) == 0)
		printf("not found.\n");
	fflush(stdin);
	getchar();
}