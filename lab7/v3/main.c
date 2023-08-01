// Signal handler example to catch SIGSEGV.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main()
{
void my_segv_handler(int);
int *x;

  printf("main: %d\n", getpid());

  // register signal handler my_segv_handler() with OS
  signal(SIGSEGV, &my_segv_handler);

  *x = 7;

}


// signal handler catches segmentation fault interrupts

void my_segv_handler(int sigval)
{

  if (sigval == SIGSEGV) {
	printf("process accessing memory it shouldn't\n");
	printf("my_segv_handler: %d\n", getpid());
	while(1);
  }

}
