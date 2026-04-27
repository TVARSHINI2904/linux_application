#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int cpid, status;
        pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("Child (PID=%d) exiting...\n", getpid());
        exit(0);   // child finishes immediately
    }
    else
    {
        // Parent process
        printf("Parent (PID=%d) sleeping...\n", getpid());
        sleep(20);   // parent does NOT call wait()

        // After sleep, parent exits
        printf("Parent exiting\n");
    }

}
