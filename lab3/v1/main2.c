// Local vs. global variables:
// 3. Scope and conflicting conflicting names.

#include <stdio.h>

void myftn(void);

int x = 1;


int main()
{
int x = 2;

  printf("main: x = %d\n", x);

  myftn();

}


void myftn(void)
{
int x = 3;

  printf("myftn: x = %d\n", x);

}
