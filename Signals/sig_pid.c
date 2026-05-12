#include <stdlib.h>
#include <string.h>
#include <signal.h>

void return_handler(int sig_no)
{
	printf("signal called\n");
	printf("pid of the handler process:%d\n",getpid());
}

int main()
{
        struct sigaction sigchld_action;

        /* Handle SIGCHLD, SIGCONT */
	printf("pid of the process is:%d\n",getpid());
        memset(&sigchld_action, 0, sizeof(sigchld_action));
        sigchld_action.sa_handler = &return_handler;
        sigaction(SIGINT, &sigchld_action, NULL);
        sleep(10);
	return 0;
        
}
