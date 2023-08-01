// Basic way to track down where in code a run-time error occurs.

#include <stdio.h>

// New C preprocessor directive.
#define MYDEBUG

void changev(int *);


int main()
{
int x;

  x = 7;
  printf("%d\n",x);

#ifdef MYDEBUG
printf("ok 1\n");
#endif

  changev(&x);

#ifdef MYDEBUG
printf("ok 2\n");
#endif

  printf("%d\n",x);

#ifdef MYDEBUG
printf("ok 3\n");
#endif

  changev(x);

#ifdef MYDEBUG
printf("ok 4\n");
#endif

  printf("%d\n",x);

}


void changev(int *a)
{
  *a = 2;
}
