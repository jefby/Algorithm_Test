#include <iostream>

using namespace std;
/*
	函数说明：
	A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

	The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

	How many possible unique paths are there?
	参数说明：

*/
int uniquePaths(int m, int n) 
{
	//动态申请空间
    int **f=(int**)calloc(m,sizeof(int*));
	int i = 0,j=0;
	if(m<=0||n<=0)
		return 0;
	for(i=0;i<m;++i)
		f[i]=(int*)calloc(n,sizeof(int));
	
	//初始化棋盘,第一行和第一列初始化为1
	for(i=0;i<m;++i)
		f[i][0]=1;
	for(j=0;j<n;++j)
		f[0][j]=1;

	for(i=1;i<m;++i)
		for(j=1;j<n;++j)
			f[i][j]=f[i-1][j]+f[i][j-1];
	j = f[m-1][n-1];//保存结果
	//释放内存
	for(i=0;i<m;++i)
		free(f[i]);
	free(f);
    return j;   
}
int main()
{
	cout<<"请输入m和n值"<<endl;
	int m=0,n=0;
	cin>>m>>n;
	cout<<"有"<<uniquePaths(m,n)<<"种结果"<<endl;
	fflush(stdin);
	getchar();
}