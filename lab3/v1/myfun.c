// Local vs. global variables:
// 4. Referencing globals from different files.

#include <stdio.h>

extern int x;


void myfun(void)
{

  printf("myfun: x = %d\n", x);

}
