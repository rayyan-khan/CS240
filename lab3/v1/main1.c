// Local vs. global variables:
// 1. Where they live.
// 2. Local variables are transient, global variables are persistent.

#include <stdio.h>

void myftn(void);
void myinter(void);

int x = 7000;


int main()
{

  myftn();
  myinter();
  myftn();
  myinter();
  myftn();

}


void myftn(void)
{
int y;

  y = y + 1;
  x = x + 1;
  printf("x=%d, y=%d\n", x, y);

}


void myinter(void)
{
int z[100];
int j;

  for(j=0; j<100; j++)
	z[j] = 1000;

}

