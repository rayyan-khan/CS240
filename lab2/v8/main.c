// Pointers and arrays.

#include <stdio.h>

#define MYDEBUG

int main()
{
int *abc;
int def; 

  abc = &def;

#ifdef MYDEBUG
printf("ok 1\n");
#endif

  *abc = 100;

#ifdef MYDEBUG 
printf("ok 2\n");
#endif

  *(abc+1) = 200;

#ifdef MYDEBUG
printf("ok 3\n");
#endif

  *(abc+2) = 300;

#ifdef MYDEBUG
printf("ok 4\n");
#endif

  printf("%d\n",*abc);

#ifdef MYDEBUG
printf("ok 5\n");
#endif

  printf("%d\n",*(abc+1));

#ifdef MYDEBUG
printf("ok 6\n");
#endif

  printf("%d\n",*(abc+2));

#ifdef MYDEBUG
printf("ok 7\n");
#endif
}
