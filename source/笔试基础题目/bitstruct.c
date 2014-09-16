/*
	题目描述：
	In little-endian systems,what is the result of following C program?
	输出：
	5,-2
*/
#include <stdio.h>
#include <string.h>

typedef struct bitstruct{
	int b1:5;
	int :2;
	int b2:2;
}bitstruct;

int main()
{
	bitstruct b;
	memcpy(&b,"EMC EXAMINATION",sizeof(b));
	printf("%d,%d\n",b.b1,b.b2);
	return 0;
}