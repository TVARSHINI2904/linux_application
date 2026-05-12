#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

sig_atomic_t sigintcnt = 0;

void handler(int signum)
{
	++sigintcnt;
	if (signum == SIGUSR1)
	{
		printf("Sleeping ...\n");
		sleep(10);
		printf("Done\n");
	}
}

int main()
{
	struct sigaction sa;
	sigset_t mask;

	//TODO 1: Register the same signal handler for SIGINT
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler=&handler;
	//TODO 2: Mask the SIGINT during the SIGUSR1 handler. Use sigaddset for the same.
       
        sigemptyset(&mask);
        sigaddset(&mask,SIGINT);	
        
	sigprocmask(SIG_BLOCK, &mask, NULL);

          // --- SIGUSR1 is blocked here, won't be delivered ---
         printf("SIGINT is masked now\n");


         sigaction(SIGINT,&sa,NULL);

	//TODO 3: Register the same handler as SIGINT for SIGUSR1
             sigaction(SIGUSR1,&sa,NULL);
             raise(SIGUSR1);
            // Unblock it
            
	     sigprocmask(SIG_UNBLOCK, &mask, NULL);
                


	for(;;)
	{
		printf("Signal Count: %d\n", (int)sigintcnt);	
		sleep(5); // Would return when signalled
	}
	return 0;
}
