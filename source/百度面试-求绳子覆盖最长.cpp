#include <stdio.h>
#define ARRAYMAX 100

int 
calcucate(int *array,int pointNum,int coverLen)
{
	int frontPtr = 0,rearPtr = 1,coverNum = 1;
	if(array == NULL || pointNum == 0 || coverLen == 0)
		return 0;
	while(rearPtr < pointNum){
		while(array[rearPtr] - array[frontPtr] > coverLen)
			++frontPtr;
		coverNum = (rearPtr-frontPtr+1)>coverNum?(rearPtr-frontPtr+1):coverNum;
		++rearPtr;
	}
	return coverNum;
}


int 
main()
{
	int pointNum,coverLen;
	int i = 0;
	int pointArray[ARRAYMAX];
	scanf("%d %d",&pointNum,&coverLen);
	for(i=0;i<pointNum;++i)
		scanf("%d",&pointArray[i]);
	printf("\n%d",calcucate(pointArray,pointNum,coverLen));
	return 0;
}