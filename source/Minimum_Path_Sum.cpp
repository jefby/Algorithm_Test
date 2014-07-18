#include <iostream>
#include <vector>

using namespace std;

/*
	求最短距离
*/
int minPathSum(vector<vector<int> > &grid) 
{
	static int dp[1000][1000];
	int m = grid.size();
	if(m <= 0)
		return 0;
	int n = grid[0].size();
	int i=0,j=0;
	for(i=0;i<m;++i){
		for(j=0;j<n;++j){
			if(i==0&&j==0)dp[0][0]=grid[0][0];
			else if(i==0)dp[i][j]=dp[0][j-1]+grid[i][j];
			else if(j==0)dp[i][j]=dp[i-1][0]+grid[i][j];
			else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
		}
	}
    return dp[m-1][n-1];
}
int main()
{
	int a[3][3]={{1,3,1},{1,5,1},{4,2,1}};
	vector<vector<int> >ivec;
	vector<int> temp;

	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			temp.push_back(a[i][j]);
		}
		ivec.push_back(temp);
		temp.clear();
	}
	cout<<"最短距离是:"<<minPathSum(ivec)<<endl;
	
	fflush(stdin);
	getchar();

}