#include <stdio.h>

int 
main()
{
	unsigned int a = 0xFFFFFFF7;
	unsigned char i = (unsigned char)a;
	char *b = (char*)&a;
	printf("%d",sizeof(*b));
	printf("%08x,%08x",i,*(b));
	getchar();
}