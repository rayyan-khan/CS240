// Simple shell example using fork() and execlp().

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
pid_t k;
int status;

  while(1) {

	// print prompt 
  	fprintf(stdout, "%d$ ", getpid());

	// wait for user input
  	getchar();

	// create child process
  	k = fork();
  	if (k==0) { // child code
	  fprintf(stdout, "I'm the child: %d\n", getpid());
	  // ask loader to load executable file ls after finding it
    	  execlp("ls", "ls", NULL);
  	}
  	else { // parent code 
	  fprintf(stdout, "I'm the parent: %d\n", getpid());
	  // wait until child terminates: makes sense for certain servers
	  waitpid(k, &status, 0);
  	}
  }

}
