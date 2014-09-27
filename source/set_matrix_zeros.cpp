#include <iostream>
#include <vector>

using namespace std;
#if 0
//����1��
//���ĳһ��Ԫ��Ϊ0�������ø�Ԫ�ص�һ�к�һ��ȫΪ0��ʹ����m*n�ĸ����ռ�
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
����2��
ʹ��O(1)�Ŀռ临�Ӷȣ�O(m*n)��ʱ�临�Ӷ�
�����ռ�Ļ�����һ���Կ����ǲ��ǹ̶������ļ��������ܸ㶨��������Կ����ǲ������Ȿ���Ѿ��ṩ���㹻�Ŀռ䡣
��������ں��ߣ��������þ���ĵ�һ�к͵�һ������Ϊ�����ռ�ʹ�á����ÿ����µĴ洢�ռ䡣�������ǣ�
1.��ȷ����һ�к͵�һ���Ƿ���Ҫ����
����������һ�����Ƿ���0����������Ҳͬʱ��������һ������û��0��

2.ɨ��ʣ�µľ���Ԫ�أ����������0���ͽ���Ӧ�ĵ�һ�к͵�һ���ϵ�Ԫ�ظ�ֵΪ0
���ﲻ�õ��ĻὫ������һ�л��һ�е�1�ĳ���0����Ϊ��Щֵ���ע��Ҫ��Ϊ0�ġ�

3.���ݵ�һ�к͵�һ�е���Ϣ���Ѿ����Խ�ʣ�µľ���Ԫ�ظ�ֵΪ��������ֵ��
�����õ�һ��Ϊ�������ɨ�赽һ��0���ͽ���һ�ж���0.

4.����1��ȷ����״̬�������һ�к͵�һ�С�
����ʼ�õ��ĵ�һ������0�Ļ������������㡣ͬ����н��д���
*/
void set_matrix_zeroes(vector<vector<int> > &matrix)
{
	bool firstrow = false,firstcol = false;
	int i=0,j=0;
	if(!matrix.size() || !matrix[0].size())
		return;
	//1.�����һ�к͵�һ��
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
	//���������к������У���ǵ���0�к͵�0�ж�Ӧ��λ��
	for(i=1;i<matrix.size();++i){
		for(j=1;j<matrix[0].size();++j){
			if(!matrix[i][j]){
				matrix[0][j]=0;
				matrix[i][0]=0;
			}
		}
	}
	//������
	for(i=1;i<matrix.size();++i){
		if(!matrix[i][0]){//���ĳһ��
			for(j=0;j<matrix[0].size();++j)
				matrix[i][j]=0;
		}
	}
	//������
	for(j=1;j<matrix[0].size();++j){
		if(matrix[0][j] == 0){//���ĳһ��
			for(i=0;i<matrix.size();++i)
				matrix[i][j] = 0;
		}
	}
	//�����һ��
	if(firstrow){
		for(j=0;j<matrix[0].size();++j)
			matrix[0][j]=0;
	}
	//�����һ��
	if(firstcol){
		for(i=0;i<matrix.size();++i)
			matrix[i][0]=0;
	}
	//������
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