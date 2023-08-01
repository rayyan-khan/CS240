#include <stdio.h>
#include <string.h>

int checknumerical(char * candidatepw) {
    for(int i = 0; i < strlen(candidatepw); i++) {
        int asc = candidatepw[i];
        if(asc > 47 && asc < 58) {
            return 0;
        }
    }
    return -1;
}