#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int argnum;

void cprompt(char * buf) {
    int i = 7;
    int foundarg = 0;

    while(foundarg == 0) {
        if(buf[i] == '0' || buf[i] == '1' || buf[i] == '2' || buf[i] == '3') {
            argnum = buf[i];
            foundarg = 1;
        }
        else if(buf[i] != ' ') {
            printf("Invalid argument. Ending program.\n");
            exit(1);
        }
        i++;
    }

    if(argnum == '0') {
        fprintf(stdout, "$ ");
    }
    else if(argnum == '1') {
        fprintf(stdout, "> ");
    }
    else if(argnum == '2') {
        fprintf(stdout, "%d ", getpid());
    }
    else if(argnum == '3') {
        fprintf(stdout, "# "); // the prompt is a hashtag
    }
    else {
        printf("Not a valid argument."); 
        exit(1);
    }

}