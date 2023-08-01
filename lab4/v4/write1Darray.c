#include "mycpp.h"
#include "myglobal.h"

void write1Darray(int num, int *data1d) {
    for(int i = 0; i < num; i++) {
        printf("%d ", data1d[i]);
    }
}