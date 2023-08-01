// Program to illustrate content vs. address
// of a local variable.

#include <stdio.h>

int main()
{
int s;

  s = 7;
  printf("%d\n",s);

  // format %p is for printing address
  printf("%u\n",&s);

}
