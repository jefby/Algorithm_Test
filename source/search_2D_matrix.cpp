#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target) 
{
	int i=0,j=0;
	for(i=0;i<matrix.size();++i){
		if(matrix[i][0] < target){
			for(j=0;j<matrix[i].size();++j){
				if(target == matrix[i][j])
					return true;
			}
		}
	}
	return false;
}
int main()
{
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int i=0,j=0;
	vector<vector<int> >matrix;
	int target = 0;
	vector<int> ivec;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			ivec.push_back(a[i][j]);
		}
		matrix.push_back(ivec);
		ivec.clear();
	}
	cout<<"please input target"<<endl;
	cin>>target;
	cout<<searchMatrix(matrix,target)<<endl; 
	system("pause");
	return 0;
}