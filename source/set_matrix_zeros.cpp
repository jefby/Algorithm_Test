#include <iostream>
#include <vector>

using namespace std;
#if 0
//方法1：
//如果某一个元素为0，则设置该元素的一行和一列全为0，使用了m*n的辅助空间
void set_matrix_zeroes(vector<vector<int> > &matrix)
{
	int i=0,j=0,k=0,q=0;
	vector<vector<int> >ivec = matrix;
	for(i=0;i<matrix.size();++i){
		for(j=0;j<matrix[i].size();++j){
			if(matrix[i][j] == 0){
				for(k=0;k<matrix[i].size();++k)
					ivec[i][k]=0;
				for(q=0;q<matrix.size();++q){
					ivec[q][j]=0;
				}
			}
		}
	}
	for(i=0;i<ivec.size();++i){
		for(j=0;j<ivec[i].size();++j){
			cout<<ivec[i][j]<<" ";
		}
		cout<<endl;
	}
}
#endif 
/*
方法2：
使用O(1)的空间复杂度，O(m*n)的时间复杂度
常数空间的话，第一可以考虑是不是固定数量的几个变量能搞定；否则可以考虑是不是问题本身已经提供了足够的空间。
这道题属于后者，就是利用矩阵的第一行和第一列来作为辅助空间使用。不用开辟新的存储空间。方法就是：
1.先确定第一行和第一列是否需要清零
即，看看第一行中是否有0，记下来。也同时记下来第一列中有没有0。

2.扫描剩下的矩阵元素，如果遇到了0，就将对应的第一行和第一列上的元素赋值为0
这里不用担心会将本来第一行或第一列的1改成了0，因为这些值最后注定要成为0的。

3.根据第一行和第一列的信息，已经可以将剩下的矩阵元素赋值为结果所需的值了
即，拿第一行为例，如果扫描到一个0，就将这一列都清0.

4.根据1中确定的状态，处理第一行和第一列。
如果最开始得到的第一行中有0的话，就整行清零。同理对列进行处理。
*/
void set_matrix_zeroes(vector<vector<int> > &matrix)
{
	bool firstrow = false,firstcol = false;
	int i=0,j=0;
	if(!matrix.size() || !matrix[0].size())
		return;
	//1.处理第一列和第一行
	for(i=0;i<matrix.size();++i){
		if(!matrix[i][0]){
			firstcol = true;
			break;
		}
	}
	for(j=0;j<matrix[0].size();++j){
		if(!matrix[0][j]){
			firstrow = true;
			break;
		}
	}
	//处理其他行和其他列，标记到第0行和第0列对应的位置
	for(i=1;i<matrix.size();++i){
		for(j=1;j<matrix[0].size();++j){
			if(!matrix[i][j]){
				matrix[0][j]=0;
				matrix[i][0]=0;
			}
		}
	}
	//处理行
	for(i=1;i<matrix.size();++i){
		if(!matrix[i][0]){//清除某一行
			for(j=0;j<matrix[0].size();++j)
				matrix[i][j]=0;
		}
	}
	//处理列
	for(j=1;j<matrix[0].size();++j){
		if(matrix[0][j] == 0){//清除某一列
			for(i=0;i<matrix.size();++i)
				matrix[i][j] = 0;
		}
	}
	//处理第一行
	if(firstrow){
		for(j=0;j<matrix[0].size();++j)
			matrix[0][j]=0;
	}
	//处理第一列
	if(firstcol){
		for(i=0;i<matrix.size();++i)
			matrix[i][0]=0;
	}
	//输出结果
	for(i=0;i<matrix.size();++i){
		for(j=0;j<matrix[i].size();++j){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int
main()
{
	int a[3][3]={0,1,2,3,4,5,6,7,8};
	int i=0,j=0;
	vector<vector<int> >ivec;
	vector<int> rvec;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j)
			rvec.push_back(a[i][j]);
		ivec.push_back(rvec);
		rvec.clear();
	}
	set_matrix_zeroes(ivec);
	system("pause");

	return 0;
}