/* 2-D arrays viewed as pointers to pointers. */
/* That is, double indirection. */

#include <stdio.h>

int main()
{
int i, j;
int x[3][4];

// initialize 2-D array

  for (i=0; i<3; i++)
	for (j=0; j<4; j++)
	  x[i][j] = i + 10 * j;

// print 2-D array
  for (i=0; i<3; i++)
	for (j=0; j<4; j++)
	  if (j != 3)
	  	printf("x[%d][%d] = %d  ", i, j, x[i][j]);
	  else
	  	printf("x[%d][%d] = %d\n", i, j, x[i][j]);

  printf("%d\n", **x);
  printf("%d\n", *((*x)+1));
  printf("%d\n", *(*x+2));
  printf("%d\n", **(x+1));
  printf("%d\n", **(x+2));

}
