// Chasing custom data types: what is my2_t

#include <stdio.h>
#include <stdlib.h>

typedef int my_t;
typedef my_t my1_t;
typedef my1_t my2_t;


int main()
{
my2_t x;

  x = 3;
  printf("%d\n",x);

}
