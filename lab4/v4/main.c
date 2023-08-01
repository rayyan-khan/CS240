#include "mycpp.h"
#include "myglobal.h"

int readinput2(void);
int calchamm2(void);
void calcdiff(void);
void write1Darray(int, int *);

int main() {
    scanf("%d\n", &N);

    readinput2();
    int calc = calchamm2();
    calcdiff();
    write1Darray(N, Z);
}