/*
	 N皇后问题
	 回溯法解决
	 思路描述：
	 递归回溯/非递归回溯解决
	 伪码描述：
	 queen(int row)
	 {
		if(n == row)//如果已经找到，则打印结果
			print_result;
		else{
			for(k=0 to N-1)//试探第row行的每一列
				if(可以放在这一列){
					//放皇后到列x[row]=k
					//继续探测下一行
				}
		}
	 }	
*/

#include <stdio.h>
#include <stdlib.h>

static int n = 0;
static int *a = NULL;
int sum = 0;
/*
	函数功能：检测皇后row可否放在row,k位置处
	参数：
	@row：皇后row
	@k：列位置
*/
int can_place(int row,int k)
{
	/*
		因一维数组的下标表示皇后i，所以不存在行冲突
		判断列冲突和斜线冲突
		列冲突：a[i]==k
		斜线冲突：|a[i]-k|=|i-row|
	*/
	int i = 0;
	for(i=0;i<row;++i){
		if(a[i]==k || abs(a[i]-k) == (row-i))
			return 0;
	}
	return 1;
}
void queen(int row)
{
	int k = 0;
	if(n == row)//如果已经找到，则打印结果
		++sum;//方案数加1
	else{
		for(k=0;k<n;++k){//试探将皇后row放置在每一列
			if(can_place(row,k)){//探测是否可以将皇后放置在此列
				a[row] = k;//放置皇后在k列
				queen(row+1);//继续探测下一行
			}//if()
		}//for
	}
}
int main()
{
	printf("N皇后，请输入N(N<=13)：");
	scanf("%d",&n);//输入N皇后的值N
	a = (int*)calloc(n,sizeof(int));
	queen(0);
	printf("\n共有%d种放法\n",sum);
	free(a);//释放内存
	fflush(stdin);
	getchar();
	return 0;
}