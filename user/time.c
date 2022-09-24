#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int 
main(int argc, char *argv[])
{
	// Time command failed
  	if(argc < 2) { // Arguments statement
    	fprintf(1, "An error has occurred.\n");
    	exit(0); // Exit program when error occurs
  	}

	int pid = fork();
	int elapsedtime = uptime();


  	if (pid < 0) {
  		exit(0);
  	}

  	if (pid == 0) {
  		exec(argv[1], argv);
  		printf("exec() args failed\n");
  	} else {
  		//wait2();
  		int cputime = uptime();
  		int cpuUsage = 100*cputime/elapsedtime;

  		printf("elapsed time: %d ticks, cpu time: %dticks, %d CPU\n", elapsedtime, cputime, cpuUsage);
  	}

  	return 0;
}

// %CPU = 100*cputime/elapsedtime