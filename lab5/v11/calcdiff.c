#include "mycpp.h"
#include "myglobal.h"

void calcdiff(void) {
    for(int i = 0; i < N; i++) {
        if(X[i] != Y[i]) {
            Z[i] = 1;
        }
        else {
            Z[i] = 0;
        }
    }
}