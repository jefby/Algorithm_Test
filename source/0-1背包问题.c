/*
	求01背包问题
	测试数据:
	$10 3
	$3 4
	$4 6
	$7 8
*/
#include <stdio.h>


int maxV[201]; //记录前i个物品中容量为v时的最大值
int weight[11];//记录i个物品的重量
int value[11];//记录i个物品的价值
int V,N;

int 
main()
{
	int i,j;
	int tmp = 0;
	scanf("%d %d",&V,&N);
	for(i=0;i<N;++i)
		scanf("%d %d",&weight[i],&value[i]);
	//对于第i轮循环，求出了前i个物品中面对容量为v的最大价值
	for(i=0;i<N;++i){
		//内循环实际上将maxV[0...v]滚动覆盖前一轮的maxV[0 ..v]
		//可输出对照使用二维数组时的情况，j从V至0逆序是防止有的物品放入背包多次
		for(j = V;j >= weight[i];--j){//循环到第i次时，只有容积大于第i个物品的体积才可能装下第i个物品
			tmp = maxV[j-weight[i]] + value[i];// weight > j 的物品不会影响状态f[0,weight[i-1]]  
			maxV[j] = (maxV[j]>tmp) ? maxV[j] : tmp;
		}
	}
	printf("%d",maxV[V]);
}