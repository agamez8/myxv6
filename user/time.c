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

	int starttime = uptime();
	// printf("%d\n", starttime);
	int pid = fork();
	struct rusage r;
	// printf("%d\n", r.cputime);

  	if (pid < 0) {
  		exit(0);
  	}

  	if (pid == 0) {
  		exec(argv[1], argv);
  		printf("exec() args failed\n");
  	} else {
  		//printf("%d\n", r.cputime);
  		wait2(0, &r);
  		//printf("%d\n", r.cputime);
  		int elapsedtime = uptime() - starttime; // Turnaround time
  		//printf("%d\n", elapsedtime);
  		//printf("%d\n", starttime);
  		int cpuUsage = 100*r.cputime/elapsedtime; // CPU usage
  		printf("elapsed time: %d ticks, cpu time: %d ticks, %d% CPU\n", elapsedtime, r.cputime, cpuUsage);
  	}

  	exit(0);
}

// %CPU = 100*cputime/elapsedtime