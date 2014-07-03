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
//冒泡排序
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
	memset(tmp,0,sizeof(tmp));//字符数组初始化为0
	sprintf(tmp,"%d",x);//将x转换为字符串
	bubble_sort(tmp,4);//从小到大排序
	int min,max;
	sscanf(tmp,"%d",&min);//将tmp转换为数字,存储到min中
	
	//invert the order,逆序化处理
	for(int i=0;i<4/2;++i)
	{
		int xx = tmp[i];
		tmp[i] = tmp[3-i];
		tmp[3-i] = xx;
	}
	sscanf(tmp,"%d",&max);//将tmp转换为数字，存储到max中
	printf("max=%d,min=%d\n",max,min);//输出最小和最大值

	return max-min;	//得到差值
}
#endif
/*
	函数说明：用于快速排序的比较函数
	参数说明：
	@op1：数1
	@op2：数2
*/
int fcmp(const void*op1,const void*op2)
{
	return *(char*)op1-*(char*)op2;
}

/*
	函数功能：获得x的排序后的最大和最小值，其中x必须满足x>=1234并且x<=9876
	参数说明：
	@x：4位正整数
	返回值：
	返回x经排序后的最大值和最小值的差值
*/
int get_next(int x)
{
	assert(x>=1234 && x <= 9876);
	char tmp[5];
	memset(tmp,0,sizeof(tmp));//字符数组初始化为0
	sprintf(tmp,"%d",x);//将x转换为字符串
	qsort(tmp,4,sizeof(char),fcmp);//从小到大排序
	int min,max;
	sscanf(tmp,"%d",&min);//将tmp转换为数字,存储到min中
	
	//invert the order,逆序化处理，得到最大值
	for(int i=0;i<4/2;++i)
	{
		int xx = tmp[i];
		tmp[i] = tmp[3-i];
		tmp[3-i] = xx;
	}
	sscanf(tmp,"%d",&max);//将tmp转换为数字，存储到max中
	//printf("max=%d,min=%d\n",max,min);//输出最小和最大值

	return max-min;	//得到差值
}

int num[MAX];

int main()
{
	int count = 0;
	int i = 0;
	printf("6174问题，请输入4位正整数，且每一位值不同\n");
	scanf("%d",&num[0]);
	int ok = 1;
	while(1)
	{	
		int x = get_next(num[count]);	
		//查找之前是否出现过
		ok = 1;
		for(i=0;i<count;i++)
		{
			if(num[i] == num[count])//已经出现过
			{
				ok = 0;//标记并退出
				break;
			}
		}
		if(ok)
			num[++count] = x;//如果没有出现过，则保存到数组的count+1位置处，并递增count
		else
			break;//否则退出
	}
	printf("转换顺序");
	for(i=0;i<count;++i)//打印出现的顺序
	{
		printf("%d",num[i]);
		if(i!=count-1)
			printf("=>");
	}
	printf("\n");
	fflush(stdin);//用于vs2008的暂停
	getchar();
	return 0;
}
