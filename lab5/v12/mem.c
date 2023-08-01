#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *memnote[10];
extern int mem_index;

void mem(char * buf) {
    char str[100];
    int i = 4;
    int strlen = 0;
    char curr = buf[i];

    while(curr != '\0') {
        if(buf[i] != ' ') {
            str[strlen] = buf[i];
            strlen++;
            curr = buf[++i];
        }
        else {
            curr = buf[++i];
        }
    }
    str[strlen] = '\0';

    if(strlen > 0) {
        memnote[mem_index] = (char *)malloc(strlen * sizeof(char));
        strcpy(memnote[mem_index], str);
        mem_index++;
        if(mem_index == 10) {
            mem_index = 0;
        }
    }
    else {
        printf("Your memnote contains:\n");
        for(i = 0; i < 10; i++) {
            if(memnote[i] == NULL) {
                printf("%d. No string stored.\n", i);
            }
            else {
                printf("%d. %s\n ", i, memnote[i]);
            }
        }
    }

}