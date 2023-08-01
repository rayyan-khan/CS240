#include <stdio.h>
#include <stdlib.h>

int calchamm(int n, int x[15], int y[15]) {
    int dist = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] != y[i]) {
            dist++;
        }
    }
    return dist;
}
