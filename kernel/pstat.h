struct pstat {
	int pid;               	// Process ID
	enum procstate state;   // Process state
	uint64 size;           	// Size of process memory (bytes)
	uint cputime;           // CPU time in ticks
	uint tsticks;			// Ticks
	int ppid;              	// Parent ID
	char name[16];         	// Process command name
};

struct rusage {
	uint cputime;
};