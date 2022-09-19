#include "kernel/param.h"
#include "kernel/types.h"
#include "user/uproc.h"
#include "user/user.h"

struct uproc uproc[NPROC];
int nprocs;

// helper function to output the process tree rooted at pid
// calls itself recursively on any children of pid
void mktree(int indent, int pid)
{
  struct uproc *u; // Pointer to uproc processes
  int count; // Indentation count

  for (u = uproc; u < &uproc[NPROC]; u++){ // Iterate through processes
    count = indent; // Set count to increment indentation

    if (count == 0 && u->pid == pid){ // Save process id to uproc
      printf("(%d)%s\n", u->pid, u->name); // Display pid and name of process
      mktree(count+=1, pid); // Indent for every process found
    }

    if (u->ppid == pid){ // Indentation to show child processes
      if (count > 0){ // Several processes found
        printf("--"); // Add branch to trees processes, indentation
        count-=1; // Stop indentation
      }
      printf("(%d)%s\n", u->pid, u->name); 
      mktree(count+=1, u->pid);
    }
  }
  return;
}

int
main(int argc, char **argv)
{
  int pid = 1;
  if (argc == 2)
    pid = atoi(argv[1]);
  nprocs = getprocs(uproc);
  if (nprocs < 0)
    exit(-1);

  // You can remove the following print statement
  //printf("%d processes\n", nprocs);

  mktree(0, pid);
  exit(0);
}
