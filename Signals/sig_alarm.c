#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Handler called! Signal = %d\n", sig);
}

int main()
{
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    act.sa_handler = handler;
    sigaction(SIGALRM, &act, NULL);
    
    //alarm(5);
    printf("My PID: %d\n", getpid());
   if(fork()==NULL){
           printf("from Child :%d\n",getpid());
	   if(!alarm(5)){
	     printf("signal called\n");
	   }

	   sleep(15);
   }
   else{
	   sleep(25);
   }
    return 0;
}
