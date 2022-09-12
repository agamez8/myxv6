// sleep command should pause for a user-specified number of ticks
// ticks: time between two interrupts from the timer chip
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  int ticks; // User input timer variable

  // Sleep command failed
  if(argc < 2){ // Arguments statement
    fprintf(2, "An error has occurred.\n");
    exit(1); // Exit program when error occurs
  }

  ticks = atoi(argv[1]); // Convert ticks input to an integer
  sleep(ticks); // Sleep timer for the amount of ticks inputed
  exit(0); // Exit program
}
