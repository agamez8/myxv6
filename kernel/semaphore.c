#include "types.h"
#include "riscv.h"
#include "param.h"
#include "defs.h"
#include "spinlock.h"

struct semtab semtable;

void 
seminit(void)
{
  initlock(&semtable.lock, "semtable");
  for (int i = 0; i < NSEM; i++){
    initlock(&semtable.sem[i].lock, "sem");
  }
}

int
semalloc(void)
{
  acquire(&semtable.lock); // acquire lock
  for (int index = 0; index < NSEM; index++) { // iterate through the table
    if(semtable.sem[index].valid == 0) { // check for unused location in semtable
      semtable.sem[index].valid = 1;
      release(&semtable.lock); // release when value is found
      
      return index; // return unused location
    }
  }
  release(&semtable.lock); // release lock

  return -1; // no empty location found
}

void 
semdealloc(int index)
{
  acquire(&semtable.lock); // acquire lock
  semtable.sem[index].valid = 0; // invalidate entry in semaphore table
  release(&semtable.lock); // release lock
}