// Simple shell example using fork() and execl().

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

	fprintf(stdout, "$ ");
	getchar();

	// create child: worker process
  	k = fork();
  	if (k==0) { // child code
	  fprintf(stdout, "I'm the child: %d\n", getpid());
    	  execl("/bin/date", "/bin/date", NULL);
  	}
  	else { // parent code 
	  fprintf(stdout, "I'm the parent: %d\n", getpid());
	  waitpid(k, &status, 0);
  	}
  }

}
