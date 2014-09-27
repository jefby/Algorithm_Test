#include <iostream>
using namespace std;
/*根据参数n，生成蛇形矩阵*/
vector<vector<int> > generateMatrix(int n) 
{
	int i=0,j=0;
	int xMin = 0;
	int yMin = 0;
	int xMax = n-1;
	int yMax = n-1;
	int num = 1;
	int **a= (int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;++i)
		a[i]=(int*)malloc(sizeof(int)*n);
	i=0;
	j=0;
	a[0][0]=num;
	while(1){
		while(j<xMax) a[i][++j]=++num;
		if(++yMin > yMax)break;
		while(i<yMax) a[++i][j]=++num;
		if(--xMax < xMin)break;
		while(j>xMin) a[i][--j]=++num;
		if(--yMax < yMin)break;
		while(i>yMin) a[--i][j]=++num;
		if(--yMax < yMin)break;
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			ivec.push_back(a[i][j]);
		}
		res.push_back(ivec);
		ivec.clear();
	}
	return res;
}
int main()
{

}