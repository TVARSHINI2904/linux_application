#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t child_pid;

	child_pid = fork();
	if(child_pid==0){
	   sleep(30);
	}
	else{
	sleep(2);
        printf("parent terminated\n");
        }
	return 0;
}
