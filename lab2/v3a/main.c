// Another passing by reference exercise.

#include "bbb.h"

int main()
{
int x;

  x = 7;

  printf("%d\n",x);
  printf("%p\n",&x);

  modv(&x);

  printf("%d\n",x);
  printf("%p\n",&x);

}



