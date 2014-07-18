#include <iostream>
#include <vector>

using namespace std;
/*
	题目描述：
	旋转图像n*n图像
	分两步：
	1.沿对角线翻转
	2.沿中轴线翻转


*/
void rotate(vector<vector<int> > &matrix)
{
	int n = matrix.size();
	int i = 0,j = 0;
	int temp = 0;
	//沿副对角线翻转
	for(i=0;i<n;++i){
		for(j=0;j<n-i;++j){//交换matrix[i][j]与matrix[n-1-i][n-1-j]
			temp = matrix[i][j];
			matrix[i][j]=matrix[n-j-1][n-i-1];
			matrix[n-1-j][n-1-i]=temp;
		}
	}

	//沿水平中轴线翻转
	for(i=0;i<n/2;++i){
		for(j=0;j<n;++j){//交换matrix[i][j]与matrix[n-1-i][j]
			temp = matrix[i][j];
			matrix[i][j] = matrix[n-i-1][j];
			matrix[n-i-1][j]=temp;
		}
	}

}
int main()
{
	vector<int>ivec;
	vector<vector<int> > res;
	int i = 0;
	cout<<"请输入n"<<endl;
	int n =0;
	cin>>n;
	
	for(i=1;i<=n*n;++i){
		ivec.push_back(i);
		if(i%n==0){
			res.push_back(ivec);
			ivec.clear();
		}
	}

	int j = 0;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	rotate(res);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	fflush(stdin);
	getchar();
	return 0;
}