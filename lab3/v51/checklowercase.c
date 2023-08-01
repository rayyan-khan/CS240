#include <stdio.h>
#include <string.h>

int checklowercase(char * candidatepw) {
    for(int i = 0; i < strlen(candidatepw); i++) {
        int asc = candidatepw[i];
        if(asc > 96 && asc < 123) {
            return 0;
        }
    }
    return -1;
}