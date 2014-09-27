#include <iostream>
#include <vector>

using namespace std;
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

举个例子自己从头到尾把数字列出来，很容易就找到规律了：
假设一维数组的坐标为x，取值范围是xMin~xMax；二维数组的坐标为y，取值范围是yMin~yMax。（也就是数组表示为int[y][x]）
1. 从左到右，y=yMin，x: xMin->xMax，yMin++
2. 从上到下，x=xMax，y: yMin->yMax，xMax--
3. 从右到左，y=yMax，x: xMax->xMin，yMax--
4. 从下到上，x=xMin，y: yMax->uMin，xMin++
结束条件，xMin==xMax或者yMin==yMax
*/
vector<int> spiralOrder(vector<vector<int> > &matrix) 
{
	vector<int> res;
	if(matrix.size()==0)
		return res;
	int xMin = 0;
	int yMin = 0;
	int xMax = matrix[0].size()-1;//列
	int yMax = matrix.size()-1;//行

	int i=0,j=0;
	res.push_back(matrix[0][0]);
	while(1){
		while(j<xMax)res.push_back(matrix[i][++j]);//向右走
		if(++yMin > yMax)//下一行
			break;
		while(i<yMax)res.push_back(matrix[++i][j]);//向下走
		if(xMin > --xMax)//下一列
			break;
		while(j>xMin)res.push_back(matrix[i][--j]);//向左走
		if(yMin > --yMax)//上一行
			break;
		while(i>yMin)res.push_back(matrix[--i][j]);//向上走
		if(++xMin>xMax)//上一列
			break;
	}
	return res;
}
int main()
{
	int a[2][2]={1,2,3,4};
	int i=0,j=0;
	vector<vector<int> >matrix;
	vector<int> ivec;

	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			ivec.push_back(a[i][j]);
		}
		matrix.push_back(ivec);
		ivec.clear();
	}
	ivec = spiralOrder(matrix);

	for(i=0;i<ivec.size();++i)
		cout<<ivec[i]<<" ";
	system("pause");

	return 0;
}