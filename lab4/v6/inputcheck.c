#include "myheader.h"

void inputcheck(void) {
    int i = 0;
    char c = getchar();
    while(c != ' ' && c != '\t' && i < MAXLEN) {
        filename[i] = c;
        c = getchar();
        if(c == '\n') {
            printf("Did not include input number. Ending program.\n");
            exit(1);
        }
        i++;
    }

    if (i >= MAXLEN) {
        printf("File exceeds max length. Ending program.\n");
        exit(1);
    }
    else {
        filename[i] = '\0';
    }

    numpos = getchar();
}
