#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int ret;
	// TODO 1: Declare the argument list for "ls -l /"
	char *const argv[]={"ls","-l","/",NULL};
    // TODO 2: Create the process with fork
       ret=fork();
	if (ret == 0)
	{
    	// TODO 3: Invoke execv in the child process with above argument list
	        execv("/bin/ls",argv);
		perror("error");
		printf("\nThis will not print, if all ok\n");
	}

    return 0;
}
