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
/*���������ʹ����ٷ������������,�㷨���Ӷ���O(n^2)*/
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

	O(n)�ĸ��Ӷȡ�

	��������ָ��i,j���ֱ�ָ�򳤶��������β��
	���ai С��aj�����ƶ�i���i++������֮���ƶ�j��ǰ��j--����
	�����ǰ��area����������¼��area���滻֮������뷨�Ļ����ǣ�
	���i�ĳ���С��j����������ƶ�j���̰���i���������ҵ��ȵ�ǰ
	��¼��area�����ֵ�ˣ�ֻ��ͨ���ƶ�i���ҵ��µĿ��ܵĸ��������

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