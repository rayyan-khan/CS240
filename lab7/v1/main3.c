#include <stdio.h>

void abc(int * const);

int main() {
int x, y;

  x = 5;
  abc(&x);
  printf("%d\n", x);

}


void abc(int * const a) {

  *a = 9;

}
