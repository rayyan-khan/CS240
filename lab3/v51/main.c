#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int checklowercase(char *);
int checkuppercase(char *);
int checknumerical(char *);
int checkspecial(char *);

int main() {
    char candidatepw[13];
    char ch;
    int i = 0;

    // get the string
    ch = getchar();
    while(ch != '\n') {
        candidatepw[i] = ch;
        i++;
        ch = getchar();
    }

    candidatepw[i] = '\0';

    // check length of password
    int len = strlen(candidatepw);
    if(len < 6 || len > 12) {
        printf("Error: Length not between 6 and 12.\n");
        exit(1);
    }

    // check that characters do not fall outside four sets
    // ascii for A-Z is 65-90, a-z is 97-122, 0-9=48-57, and #$%& = 35-38
    for(int i = 0; i < len; i++) {
        int asc = candidatepw[i];
        if(!((asc > 34 && asc < 39) || (asc > 47 && asc < 58) || (asc > 64 && asc < 91) || (asc > 96 && asc < 123))) {
            printf("Error: Character %c falls outside expected sets.\n", candidatepw[i]);
            exit(1);
        }
    }

    // call four checker functions
    int check = checklowercase(candidatepw) + checkuppercase(candidatepw) + checknumerical(candidatepw) + checkspecial(candidatepw);
    if(check != 0) {
        printf("Error: There is not at least one character from each set.\n");
        exit(1);
    }

    printf("Your password %s passes the requirements.\n", candidatepw);
}