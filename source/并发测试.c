#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void Print(char c)
{
	printf("%c\n",c);
}


int 
main()
{
	pid_t pid;
	if((pid=fork())==0)
		return 0;
	waitpid(pid,NULL,0);
	if(fork() && fork())
		while(waitpid(-1,NULL,0)>0) Print('X');
	
	return 0;
}