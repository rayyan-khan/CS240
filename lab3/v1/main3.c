// Local vs. global variables:
// 3. Scope and conflicting conflicting names.

#include <stdio.h>

void myfun(void);

int x = 1;


int main()
{
int x = 2;

  printf("main: x = %d\n", x);

  myfun();

}
