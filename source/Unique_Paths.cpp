#include <iostream>

using namespace std;
/*
	����˵����
	A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

	The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

	How many possible unique paths are there?
	����˵����

*/
int uniquePaths(int m, int n) 
{
	//��̬����ռ�
    int **f=(int**)calloc(m,sizeof(int*));
	int i = 0,j=0;
	if(m<=0||n<=0)
		return 0;
	for(i=0;i<m;++i)
		f[i]=(int*)calloc(n,sizeof(int));
	
	//��ʼ������,��һ�к͵�һ�г�ʼ��Ϊ1
	for(i=0;i<m;++i)
		f[i][0]=1;
	for(j=0;j<n;++j)
		f[0][j]=1;

	for(i=1;i<m;++i)
		for(j=1;j<n;++j)
			f[i][j]=f[i-1][j]+f[i][j-1];
	j = f[m-1][n-1];//������
	//�ͷ��ڴ�
	for(i=0;i<m;++i)
		free(f[i]);
	free(f);
    return j;   
}
int main()
{
	cout<<"������m��nֵ"<<endl;
	int m=0,n=0;
	cin>>m>>n;
	cout<<"��"<<uniquePaths(m,n)<<"�ֽ��"<<endl;
	fflush(stdin);
	getchar();
}