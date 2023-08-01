/* 	version 4 of z = x - y
	same as version 3 but supports
	real numbers */

#include <stdio.h>

int main()
{
float x, y, z;

// read input
  scanf("%f %f",&x,&y);

// subtract
  z = x - y;

// print result
  printf("result of %f - %f is %f\n", x, y, z);

}
