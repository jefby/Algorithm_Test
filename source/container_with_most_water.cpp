#include <iostream>
#include <vector>
using namespace std;

/*computer the water area this */
int area_water(vector<int> &height,int i,int j)
{
	if(height[i] < height[j])
		return (i-j)*height[i];
	else
		return (i-j)*height[j];
}
#if 0
/*求最大区域，使用穷举法来解决此问题,算法复杂度是O(n^2)*/
int maxArea(vector<int> &height)
{
	int i=0,j=0;
	int maxarea = 0;
	int area = 0;
	for(i=1;i<height.size();++i){
		if(height[i] == 0) continue;
		for(j=0;j<i;++j){
			area = area_water(height,i,j);//compute the area
			if(area > maxarea)//refresh 
				maxarea = area;
		}
	}
	return maxarea;
}
#endif

/*

	O(n)的复杂度。

	保持两个指针i,j；分别指向长度数组的首尾。
	如果ai 小于aj，则移动i向后（i++）。反之，移动j向前（j--）。
	如果当前的area大于了所记录的area，替换之。这个想法的基础是，
	如果i的长度小于j，无论如何移动j，短板在i，不可能找到比当前
	记录的area更大的值了，只能通过移动i来找到新的可能的更大面积。

*/
int maxArea(vector<int> &height)
{
	int i=0,j=height.size()-1;
	int area = 0,maxarea = 0;
	while(i<j){
		area = area_water(height,j,i);
		if(height[i] < height[j])
			++i;
		else
			--j;
		if(area > maxarea)
			maxarea = area;
	}
	return maxarea;
}

int 
main()
{

	vector<int> ivec;
	int a[]={1,5,1,1,1,5};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0;
	for(i=0;i<len;++i)
		ivec.push_back(a[i]);
	cout<<maxArea(ivec)<<endl;
	system("pause");

	return 0;
}