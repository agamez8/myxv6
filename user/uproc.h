enum uprocstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

struct uproc {
	int pid;               	// Process ID
	enum uprocstate state;  // Process state
	uint64 size;           	// Size of process memory (bytes)
	uint cputime;           // CPU time in ticks
	uint arrtime;			// Arrival time in ticks
	uint tsticks;           // Ticks accumulated in current time slice
	int ppid;              	// Parent ID
	char name[16];         	// Process command name
};
