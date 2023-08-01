// Static variables: persistence across multiple function calls.

#include <stdio.h>

int ftn(void);


int main() {
int x;

  x = ftn();
  printf("%d\n",x);

  x = ftn();
  printf("%d\n",x);

  x = ftn();
  printf("%d\n",x);

  return 0;

}


int ftn() {
static int a = 1;

  return ++a;
}
