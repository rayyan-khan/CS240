#include <stdio.h>

int abc(const int);

int main() {
int x, y;

  x = 5;
  y = abc(x);
  printf("%d\n", y);

}


int abc(const int a) {

  return 2*a;

}
