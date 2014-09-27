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

�ٸ������Լ���ͷ��β�������г����������׾��ҵ������ˣ�
����һά���������Ϊx��ȡֵ��Χ��xMin~xMax����ά���������Ϊy��ȡֵ��Χ��yMin~yMax����Ҳ���������ʾΪint[y][x]��
1. �����ң�y=yMin��x: xMin->xMax��yMin++
2. ���ϵ��£�x=xMax��y: yMin->yMax��xMax--
3. ���ҵ���y=yMax��x: xMax->xMin��yMax--
4. ���µ��ϣ�x=xMin��y: yMax->uMin��xMin++
����������xMin==xMax����yMin==yMax
*/
vector<int> spiralOrder(vector<vector<int> > &matrix) 
{
	vector<int> res;
	if(matrix.size()==0)
		return res;
	int xMin = 0;
	int yMin = 0;
	int xMax = matrix[0].size()-1;//��
	int yMax = matrix.size()-1;//��

	int i=0,j=0;
	res.push_back(matrix[0][0]);
	while(1){
		while(j<xMax)res.push_back(matrix[i][++j]);//������
		if(++yMin > yMax)//��һ��
			break;
		while(i<yMax)res.push_back(matrix[++i][j]);//������
		if(xMin > --xMax)//��һ��
			break;
		while(j>xMin)res.push_back(matrix[i][--j]);//������
		if(yMin > --yMax)//��һ��
			break;
		while(i>yMin)res.push_back(matrix[--i][j]);//������
		if(++xMin>xMax)//��һ��
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