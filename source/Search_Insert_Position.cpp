#include <stdio.h>

/*
	��Ŀ˵����
	Given a sorted array and a target value, return the index if the target is found.
	If not, return the index where it would be if it were inserted in order.

	You may assume no duplicates in the array.

	Here are few examples.
	[1,3,5,6], 5 �� 2
	[1,3,5,6], 2 �� 1
	[1,3,5,6], 7 �� 4
	[1,3,5,6], 0 �� 0
*/
int searchInsert(int a[], int n, int target) 
{
        int low = 0,high = n-1,mid = 0;
		if(target < a[0])//����С����Сֵ��target
			return 0;
		if(target > a[high])//����������ֵ��target
			return n;
		while(low <= high){//��Χ��
			mid = (low+high)/2;
			if(a[mid] == target)//�ҵ��򷵻�mid�±�
				return mid;
			else if(a[mid] < target)//���target > a[mid],��low=mid
				low = mid+1;
			else//���target < a[mid],high = mid
				high = mid-1;
		}
        return low;
}
int main()
{
	int A[]={1,3,5,6};
	int len = sizeof(A)/sizeof(A[0]);
	int target = 0;
	printf("������target:\n");
	scanf("%d",&target);
	printf("\nindex=%d\n",searchInsert(A,len,target));
	fflush(stdin);
	getchar();
	return 0;
}