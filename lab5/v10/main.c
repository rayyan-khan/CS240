#include <stdio.h>
#include <stdlib.h>

int readinput(int *n, int *x, int *y);
int calchamm(int, int *, int *);
void writeoutput(int);

int main() {
    int n;
    scanf("%d\n", &n);

    // malloc
    int *x = (int *)malloc(n * sizeof(int));
    if(x == NULL) {
        printf("Malloc for X failed.\n");
        exit(1);
    }

    int *y = (int *)malloc(n * sizeof(int));
    if(y == NULL) {
        printf("Malloc for Y failed.\n");
        exit(1);
    }

    readinput(&n, x, y);

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