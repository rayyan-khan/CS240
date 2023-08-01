#include "mycpp.h"
#include "myglobal.h"


int readinput2(void) {
    if(N > 15) {
        return -1;
    }
    else {
        // check that all inputs are 1 or 0 and the lines are all n long

        for(int i = 0; i < N; i++) {
            int j = scanf("%d", &X[i]);
            if(j != 1) {
                printf("x: Error scanned in %d ints", j);
                exit(1);
            }
            if(X[i] != 1 && X[i] != 0) {
                printf("x: Error not 1 or 0");
                exit(1);
            }
        }
        for(int i = 0; i < N; i++) {
            int j = scanf("%d", &Y[i]);
            if(j != 1) {
                printf("y: Error scanned in %d ints", j);
                exit(1);
            }
            if(Y[i] != 1 && Y[i] != 0) {
                printf("y: Error not 1 or 0");
                exit(1);
            }
        }
        return 0;
    }
}