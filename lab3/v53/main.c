#include <stdio.h>
#include <stdlib.h>

int readinput(int *n, int (*)[15], int (*)[15]);
int calchamm(int, int *, int *);
void writeoutput(int);

int main() {
    int n;
    scanf("%d\n", &n);

    int x[15];
    int y[15];

    readinput(&n, &x, &y);
    int calc = calchamm(n, x, y);
    writeoutput(calc);
}

int calchamm(int n, int x[15], int y[15]) {
    int dist = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] != y[i]) {
            dist++;
        }
    }
    return dist;
}

void writeoutput(int dist) {
    printf("%d\n", dist);
}