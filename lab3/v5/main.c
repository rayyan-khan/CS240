// Pointers of functions and passing them as arguments.

#include <stdio.h>

int twotimes(int);
int runftn(int (*f)(int), int);


int main()
{
int x, y;
int (*h)(int);

  x = 7;
  y = twotimes(x);
  printf("result = %d\n",y);

  x = 7;
  h = twotimes;
  y = (*h)(x);
  printf("result = %d\n",y);

  x = 7;
  y = runftn(&twotimes, x);
  printf("result = %d\n",y);

  // shortcuts: h(x), runftn(twotimes, x)

}


// Multiply by 2.

int twotimes(int a)
{
  return 2*a;
}


// Run function with a single argument.

int runftn(int (*u)(), int a)
{
int b;

  b = (*u)(a);
  return b;

}
