#include "mycpp.h"
#include "myglobal.h"

int calchamm2(void) {
    int dist = 0;
    for(int i = 0; i < N; i++) {
        if(X[i] != Y[i]) {
            dist++;
        }
    }
    return dist;
}