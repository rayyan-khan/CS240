// A fork example to illustrate variable sharing between parent and child processes.

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int a;

int main()
{
pid_t mypid;
void letsfork(void);

  a = 10;
  mypid = getpid();
  printf("I am the parent: pid=%d  a=%d\n", mypid, a);

  letsfork();

  mypid = getpid();
  a++;
  printf("who am I: pid=%d  a=%d\n", mypid, a);

}


// Function that performs fork() call.

void letsfork()
{
pid_t mypid, pidafterfork;
static int b = 100;

  mypid = getpid();
  printf("inside letsfork before fork(): pid=%d  b=%d\n", mypid, b);

  pidafterfork = fork();

  // track the value of b
  if (pidafterfork == 0) {	// I'm the child process!
	b++;
	printf("inside letsfork after fork() - I'm the child: pid=%d  b=%d\n",getpid(),b);
	// note: child does not invoke loader through execlp()
  }
  else {			// I'm the parent process
	b++;
	printf("inside letsfork after fork() - I'm the parent: pid=%d  b=%d\n",getpid(),b);
	// note: parent does not wait on child to terminate
  }

}
