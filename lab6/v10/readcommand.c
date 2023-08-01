#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char buf[100]; // global array where input is initially stored by main
extern int readcommand_continue; // global variable to decide whether to continue loop in main.c


void readcommand(void) {
	int len; // stores length of buf up to null pointer

    // read user command
	fgets(buf, 100, stdin);

    len = strlen(buf);
	if(len == 1)	// if only ENTER/RET key pressed, skip rest of loop in main()
	  readcommand_continue = 1;
	buf[len-1] = '\0'; // shift EOS to where '\n' is stored

}