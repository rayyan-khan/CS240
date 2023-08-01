// Using pointers (i.e., variables that contain addresses) directly in
// a program.

#include <stdio.h>

int main()
{
int a;
int *b;
int **c;

  a = 7;
  printf("%d\n",a);
  printf("%p\n",&a);

  b = &a;
  printf("%d\n",*b);
  printf("%p\n",b);
  
  c = &b;
  printf("%d\n", **c);
  printf("%ls\n", *c);
  printf("%p\n", c);
}
