/*	
	矩阵原地转置，要求O(1)复杂度
	Author:jefby
	Email:jef199006@gmail.com
	算法参考博文：
	http://my.oschina.net/u/1785330/blog/275274
*/

#include <stdio.h>

//下标为i的元素的前驱
int 
getPre(int i,int row,int col)
{
	return col*(i%row)+i/row;
}
//下标为i的元素后继
int 
getNext(int i,int row,int col)
{
	return row*(i%col)+i/col;
}
//处理以i为起点的环
void 
movedata(int *matrix,int i,int row,int col)
{
	int temp = matrix[i];
	int cur = i;
	int pre = getPre(i,row,col);
	while(pre != i){
		matrix[cur]=matrix[pre];
		cur = pre;
		pre = getPre(cur,row,col);
	}
	matrix[cur]=temp;
}
//转置
void
transpose(int *matrix,int row,int col)
{
	int i = 0,next = 0;
	for(i=0;i<row*col;++i){
		next = getNext(i,row,col);//求后继
		while(next > i)//如果后继小于起点，则说明环重复，中断，不作处理
			next = getNext(next,row,col);
		if(next == i)
			movedata(matrix,i,row,col);//处理当前环
	}
}

void 
print_matrix(int *matrix,int row,int col)
{
	int i = 0, j = 0;
	for(i=0;i<row*col;++i){
		if((i+1)%col == 0)
			printf("%d\n",matrix[i]);
		else
			printf("%d ",matrix[i]);
	}//for
}
int 
main()
{
	int a[]={1,2,3,4,5,6,7,8};
	printf("转置前为:\n");
	print_matrix(a,4,2);
	transpose(a,4,2);
	printf("转置后为:\n");
	print_matrix(a,2,4);
	getchar();
	
	return 0;
}
