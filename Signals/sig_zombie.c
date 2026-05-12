#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void handler()
{
        
        printf("Trigger from Child.\n");
	wait(NULL);
}
int main()
{
        struct sigaction act;
        int i, j;
        memset(&act, 0, sizeof(act));
        act.sa_handler = &handler;
        sigaction(SIGCHLD, &act, NULL);
        
	if (fork()) // Parent
	{
                for(i = 0; i < 10; i++)
                {
                        sleep(1);
                        printf("Brrrrrm\n");
                }
        }
        else // Child
        {
                sleep(5);
               // kill(getppid(), SIGUSR1);
                printf("In a child.\n");
        }
        //printf("SIGUSR1 was raised %d times\n", sigusr1_count);
        return 0;
}


