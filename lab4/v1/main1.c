// Program to inspect the 32 bits of unsigned int and int numbers.

#include <stdio.h>

int main()
{
int i;
unsigned int x, y, m;
int a, b;

  // read input unsigned
  scanf("%u", &x);

  // read input signed
  scanf("%d", &a);

  // set mask to 00 ... 01
  m = ~(~0 << 1);

  // loop over all 32 bits from lsb to msb: unsigned
  for(i=0; i<32; i++) {
	// zero out all bits but for lsb
	y = x & m;
  	printf("%u", y);
	// right shift to inspect the next significant bit
	x = x >> 1;
  }

  printf("\n");

  // loop over all 32 bits from lsb to msb: signed
  for(i=0; i<32; i++) {
	// zero out all bits but for lsb
	b = a & m;
  	printf("%d", b);
	// right shift to inspect the next significant bit
	a = a >> 1;
  }

  printf("\n");

}

