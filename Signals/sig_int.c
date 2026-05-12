#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
void  handler(void);
static int v=0;
void  handler(void){
  printf("shows the signal handler\n");
  
  v++;
  //printf("the handler called for %d\n",v);

}



int main()
{
	int i;
	//TODO 1: Declare the variable of type struct sigaction;
	

        struct sigaction sa;

	//TODO 2: Nullify the variable
	memset(&sa,0,sizeof(sa));
        sa.sa_handler= handler;
	//TODO 3: Register the handler

	
	for(i = 0; i < 20; i++)
	{
		printf("Hmmmmm\n");
		sleep(1);
         if(v==0){
             sigaction(SIGINT,&sa,NULL);
        }
        else{
            sa.sa_handler=SIG_DFL;
            sigaction(SIGINT,&sa,NULL);
        }


	
	}
	  printf("the handler called for %d\n",v);

	return 0;
}
