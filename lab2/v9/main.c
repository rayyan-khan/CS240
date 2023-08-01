// Pointers, program memory, and silent run-time errors.
// Good programming practice.

#include <stdio.h>


int main()
{
int abc[5];
int k;

  for(k=0; k<5; k++)
	abc[k] = k;

  for(k=0; k<5; k++)
  	printf("%d\n",*(abc+k));

  for(k=0; k<6; k++)
	abc[k] = k;

  for(k=0; k<6; k++)
	printf("%d\n",*(abc+k));

}
