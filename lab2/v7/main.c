// Pointers and arrays

#include <stdio.h>


int main()
{
int x[4];

  x[0] = 1;
  x[1] = 2;
  x[2] = 3;
  x[3] = 4;

  printf("%d\n",x[0]);
  printf("%d\n",x[1]);
  printf("%d\n",x[2]);
  printf("%d\n\n",x[3]);

  printf("%d\n",*x);
  printf("%d\n",*(x+1));
  printf("%d\n",*(x+2));
  printf("%d\n\n",*(x+3));


  *x = 10;
  *(x+1) = 20;
  *(x+2) = 30;
  *(x+3) = 40;

  printf("%d\n",x[0]);
  printf("%d\n",x[1]);
  printf("%d\n",x[2]);
  printf("%d\n",x[3]);

}
