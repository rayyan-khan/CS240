// Signal handler example to catch SIGINT: default CTRL-C

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
int *y;
void my_int_handler(int);

  // register signal handler for CTRL-C with OS
  if (signal(SIGINT, my_int_handler) == SIG_ERR) {
	fprintf(stderr, "signal handler registration failed\n");
	exit(1);
  }

  // program is infinite loop
  while(1);

}


// signal handler my_int_handler() catches CTRL-C key input

void my_int_handler(int sigval)
{

  if (sigval == SIGINT) {
	printf("I'm immune to CTRL-C.\n");
	return;
  }

  return;

}
