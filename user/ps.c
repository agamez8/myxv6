#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/pstat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  struct pstat uproc[NPROC];
  int nprocs;
  struct pstat *u; // Pointer variable for uproc
  static char *states[] = { // Array of process states
  [UNUSED]    "unused ",
  [SLEEPING]  "sleep  ",
  [RUNNABLE]  "runble ",
  [RUNNING]   "run    ",
  [ZOMBIE]    "zombie "
  }; 
  
  nprocs = getprocs(uproc);

  if (nprocs < 0)
    exit(-1);
  //printf("%d processes\n", nprocs);
   
  // Display all processes information
  printf("pid\tstate\tsize\tcputime\tppid\tname\n"); // Category display
  for (u = uproc; u < &uproc[nprocs]; u++){ // Iterate to find every process in the uproc
   // Display processes info in order
   printf("%d\t%s\t%d\t%d\t%d\t%s\n", u->pid, states[u->state], u->size, u->cputime, u->ppid, u->name);
  }
  exit(0);
}
