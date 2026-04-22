#include <linux/kernel.h>
//#include <linux/sys.h>
#include <stdio.h>
#include <sys/sysinfo.h>


int main() {
	const long minute = 60;
	const long hour = minute *60;
	const long day = hour * 24;
	const double megabyte = 1024 * 1024;
	struct sysinfo si;
	
	//TODO 1: Get the system info using sysinfo system call
        sysinfo(&si);


	//TODO 2: Print the total up time
        printf("total up time : %ld\n",si.uptime);
	
	//TODO 3: Print the total RAM in MB
	printf("total RAM in MB : %lu\n",si.totalram/(1024*1024));

	//TODO 4: Print the Free Ram
	printf("Free Ram : %lu\n",si.freeram/(1024*1024));
 
	//TODO 5: Print the process count 
	printf("process count : %u\n",si.procs);

	return 0;
}
