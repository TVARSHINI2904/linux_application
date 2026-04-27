#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t child_pid;

	printf("The main program process id is %d\n", (int)getpid());
	//TODO 1: Invoke the fork and get the return value in child_pid
	child_pid=fork();
        if(child_pid==0){
          printf("from child process pid is %d\n",(int)getpid());
	  printf("from child process :Parent pid is %d\n",(int)getppid());
	}



	//TODO 2: Display the parent, self and child process id in parent process
	else{
	    printf("From parent :Parent process id is %d\n",(int)getppid());
	    printf("self process id is %d\n",(int)getpid());
	    printf("From Parent:the child process id is %d\n",child_pid);

	
	
	}
	//TODO 3: Display the self and parent process id in the child process
	return 0;
}
