#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"
#define MAXARGS 16

int 
main(int argc, char *argv[])
{
	// Time command failed
  	if(argc < 2) { // Arguments statement
    	fprintf(1, "An error has occurred.\n");
    	exit(0); // Exit program when error occurs
  	}

	int starttime, elapsedtime;
	int pid = fork();
	struct rusage r;
	char *newargv[MAXARGS];

	for(int i = 1; i < argc; i++) {
		newargv[i-1] = argv[i];
	}
	newargv[argc-1] = 0;

	starttime = uptime();

  	if (pid < 0) {
  		exit(0);
  	}

  	if (pid == 0) {
  		exec(newargv[0], newargv);
  	}
	wait2(0, &r);
	elapsedtime = uptime() - starttime;
	int cpuUsage = 100*r.cputime/elapsedtime; // CPU usage
	printf("elapsed time: %d ticks, cpu time: %d ticks, %d% CPU\n", elapsedtime, r.cputime, cpuUsage);
	exit(0);
}

// %CPU = 100*cputime/elapsedtime