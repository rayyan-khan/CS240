#include <stdio.h>
#include <stdlib.h>

int readinput(int *n, int *x, int *y) {
    if(*n > 15) {
        return -1;
    }
    else {
        
        // check that all inputs are 1 or 0 and the lines are all n long

        for(int i = 0; i < *n; i++) {
            int j = scanf("%d", &x[i]);
            if(j != 1) {
                printf("x: Error scanned in %d ints", j);
                exit(1);
            }
            if(x[i] != 1 && x[i] != 0) {
                printf("x: Error not 1 or 0");
                exit(1);
            }
        }
        for(int i = 0; i < *n; i++) {
            int j = scanf("%d", &y[i]);
            if(j != 1) {
                printf("y: Error scanned in %d ints", j);
                exit(1);
            }
            if(y[i] != 1 && y[i] != 0) {
                printf("y: Error not 1 or 0");
                exit(1);
            }
        }
        return 0;
    }
}