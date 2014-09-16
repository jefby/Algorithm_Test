/*编写一个程序，以每行一个单词的形式打印其输入*/
#include <stdio.h>

#define OUT 0
#define IN 1

int main()
{
	int state , c;

	state = OUT;
	while( (c=getchar()) != EOF){
		switch(state){
			case OUT:
			if(c == '\t' || c == ' ' || c == '\n')
				;
			else{
				state = IN;
				putchar(c);
			}
			break;
			case IN:
			if(c == '\t' || c == ' ' || c == '\n'){
				putchar('\n');
				state = OUT;
			}
			else{
				putchar(c);
			}
			break;
		}
	}//while
	return 0;

}