// Simple shell example using fork() and execlp().

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **commandcomp; // contains command-line args, passed to execvp() later
char buf[100]; // array where the input is stored before parsing
int readcommand_continue = 0; // variable that determines whether to continue in while loop

void readcommand(void); // read user input from stdin
int parsecommand(void); // parse input from buf[] to **commandcomp


int main()
{
	pid_t k; // pid_t storing the new child process passed to waitpid()
	int status;

  while(1) {
	readcommand_continue = 0;

	// print prompt as PID%
  	fprintf(stdout,"%d %% ",getpid());

	// read user command
	readcommand();

	// if read command is 0, skip everything and loop again
	if(readcommand_continue == 1) {
		continue;
	}

	// parse command from buf into **commandcomp
	int parse = parsecommand();

	// create worker bee
  	k = fork();
  	if (k==0) { // child code
    	  if(execvp(commandcomp[0],commandcomp) == -1)  // loader can fail: if so terminate worker process
	  	exit(1);
  	}
  	else { // parent code 
	  waitpid(k, &status, 0);
  	} 
  }
}
