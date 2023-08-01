#include <stdio.h>
#include <stdlib.h>

extern int first_arg;
extern char binexec[100];

void d(char * buf) {
    int i = 1;
    char curr = buf[i];
    char first_arg_str[100];
    int first_arg_index = 0;
    int binexec_index = 0;

    while(curr == ' ') {
        //printf("while loop 1 i: %d\n", i);
        curr = buf[i++];
    }

    while(curr != ' ') {
        //printf("while loop 2 i: %d\n", i);
        first_arg_str[first_arg_index++] = curr;
        curr = buf[i++];
    }

    //printf("first arg: %s\n", first_arg_str);

    first_arg = atoi(first_arg_str);

    while(curr == ' ') {
        //printf("while loop 3 i: %d\n", i);
        curr = buf[i++];
    }

    while(curr != ' ' && curr != '\0' && curr != '\n') {
        //printf("while loop 4 i: %d\n", i);
        binexec[binexec_index++] = curr;
        curr = buf[i++];
    }

    //printf("binexec arg: %s\n", binexec);
}