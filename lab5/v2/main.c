// Dynamic memory allocation in processes using malloc().

#include <stdio.h>
#include <stdlib.h>

int main() {

int x; 
int *y; 

  x = 10;

  // request that Linux allocate 4 bytes in main memory and returns beginning address
  y = (int *) malloc(sizeof(int));

  *y = 20;

  fprintf(stdout,"%d %d\n",x,*y);

}
