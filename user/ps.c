#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  struct uproc uproc[NPROC];
  int nprocs;

  /********************************
   * Add any additional variables or data structures you will need
   ********************************/
   
  struct uproc *u; // Pointer variable for uproc
  static char *states[] = { // Array of existing structs
  [UNUSED]    "unused",
  [SLEEPING]  "sleep ",
  [RUNNABLE]  "runble",
  [RUNNING]   "run   ",
  [ZOMBIE]    "zombie"
  }; 
  
  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);
  // You can remove the following print statement
  // printf("%d processes\n", nprocs);

  /*********************************
   * Add your code here to output information returned by getprocs()
   * Hint: see procdump() code in kernel/console.c, except that here
   * you will be outputting the first nprocs elements of the uproc array
   * and all will have active states.
   *********************************/ 
   
  // Display all processes information
  char *state;
  printf("pid\tstate\tsize\tppid\tname\n"); // Category display
  for (u = uproc; u < &uproc[NPROC]; u++){ // Iterate to find every process in the uproc space
    if (u->state == UNUSED)
      continue;
    if(u->state >= 0 && u->state < NELEM(states) && states[u->state])
      state = states[u->state];
    else
   // Display processes info in order
   printf("%d\t%s\t%d\t%d\t%s\n", u->pid, states[u->state], u->size, u->ppid, u->name);
  }
  exit(0);
}
