#include <stdio.h>
#include <string.h>

int checkspecial(char * candidatepw) {
    for(int i = 0; i < strlen(candidatepw); i++) {
        int asc = candidatepw[i];
        if(asc > 34 && asc < 39) {
            return 0;
        }
    }
    return -1;
}