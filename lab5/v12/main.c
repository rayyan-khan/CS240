// Simple shell example using fork() and execlp().

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void cprompt(char *);
void mem(char *);
void d(char *);
void grep(char *);

// globals for cprompt
int argnum;

// globals for mem.c
char *memnote[10];
int mem_index = 0;

// globals for d.c
int first_arg;
char binexec[100];


int main()
{
pid_t k;
char buf[100];
int status;
int len;
int c = 0;

  while(1) {

	// print prompt
  	if(c == 0) {
		fprintf(stdout,"%d %% ",getpid());
	}
	c = 0;

	// read user command
	fgets(buf, 100, stdin);

	len = strlen(buf);
	if(len == 1)	// only ENTER/RET key pressed
	  continue;
	buf[len-1] = '\0'; // shift EOS to where '\n' is stored
	
	
	// watch out for built-in commands
	if(buf[0] == 'c' && buf[1] == 'p' && buf[2] == 'r' && 
		buf[3] == 'o' && buf[4] == 'm' && buf[5] == 'p' && buf[6] == 't') {
		c = 1;
		
		// call cprompt() from cprompt.c file
		cprompt(buf);
	}
	else if(buf[0] == 'm' && buf[1] == 'e' && buf[2] == 'm') {

		// call memnote() from memnote.c file
		mem(buf);

	}
	else if(buf[0] == 'd') {
		
		// call d() from d.c file
		d(buf);

		k = fork();
		if (k==0) { // child code
			sleep(first_arg);
			if(execlp(binexec,binexec,NULL) == -1)  // loader can fail: if so terminate worker process
				exit(1);
		}
	}
	else if(buf[0] == 'x') {

		// terminate shell
		printf("Terminating shell...\n");
		exit(0);
	}
	else if(buf[0] == 'g' && buf[1] == 'r' && buf[2] == 'e' && buf[3] == 'p') {

		// call grep.c (bonus problem)
		grep(buf);
	}
	else {
		// create worker bee
		k = fork();
		if (k==0) { // child code
			if(execlp(buf,buf,NULL) == -1)  // loader can fail: if so terminate worker process
			exit(1);
		}
		else { // parent code 
		waitpid(k, &status, 0);
		}
	}	
  }
}
