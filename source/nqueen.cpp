/*
	 N�ʺ�����
	 ���ݷ����
	 ˼·������
	 �ݹ����/�ǵݹ���ݽ��
	 α��������
	 queen(int row)
	 {
		if(n == row)//����Ѿ��ҵ������ӡ���
			print_result;
		else{
			for(k=0 to N-1)//��̽��row�е�ÿһ��
				if(���Է�����һ��){
					//�Żʺ���x[row]=k
					//����̽����һ��
				}
		}
	 }	
*/

#include <stdio.h>
#include <stdlib.h>

static int n = 0;
static int *a = NULL;
int sum = 0;
/*
	�������ܣ����ʺ�row�ɷ����row,kλ�ô�
	������
	@row���ʺ�row
	@k����λ��
*/
int can_place(int row,int k)
{
	/*
		��һά������±��ʾ�ʺ�i�����Բ������г�ͻ
		�ж��г�ͻ��б�߳�ͻ
		�г�ͻ��a[i]==k
		б�߳�ͻ��|a[i]-k|=|i-row|
	*/
	int i = 0;
	for(i=0;i<row;++i){
		if(a[i]==k || abs(a[i]-k) == (row-i))
			return 0;
	}
	return 1;
}
void queen(int row)
{
	int k = 0;
	if(n == row)//����Ѿ��ҵ������ӡ���
		++sum;//��������1
	else{
		for(k=0;k<n;++k){//��̽���ʺ�row������ÿһ��
			if(can_place(row,k)){//̽���Ƿ���Խ��ʺ�����ڴ���
				a[row] = k;//���ûʺ���k��
				queen(row+1);//����̽����һ��
			}//if()
		}//for
	}
}
int main()
{
	printf("N�ʺ�������N(N<=13)��");
	scanf("%d",&n);//����N�ʺ��ֵN
	a = (int*)calloc(n,sizeof(int));
	queen(0);
	printf("\n����%d�ַŷ�\n",sum);
	free(a);//�ͷ��ڴ�
	fflush(stdin);
	getchar();
	return 0;
}