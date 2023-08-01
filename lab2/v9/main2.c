//Pointers, program memory, and silent run-time errors.
// Good programming practice.

#include <stdio.h>

int abc[5];

int main()
{
//int abc[5];
int k;

  for(k=0; k<5; k++)
	abc[k] = k;

  for(k=0; k<5; k++)
  	printf("%d\n",*(abc+k));

  for(k=0; k<1017; k++)
	abc[k] = k;

  for(k=0; k<1017; k++)
	printf("%d\n",*(abc+k));

}
