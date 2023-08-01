#include <stdio.h>
#include <string.h>

int checkuppercase(char * candidatepw) {
    for(int i = 0; i < strlen(candidatepw); i++) {
        int asc = candidatepw[i];
        if(asc > 64 && asc < 91) {
            return 0;
        }
    }
    return -1;
}