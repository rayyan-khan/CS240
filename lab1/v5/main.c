/* 	version 5 of z = x - y
	same as version 4 but uses separate
	function subtwo() to perform subtraction */ 

#include <stdio.h>

float subtwo(float, float);

void main()
{
float x, y, z;

// read input
  scanf("%f %f",&x,&y);

// compute subtraction
  z = subtwo(x,y);

// print result
  printf("result of %f - %f is %.3f\n", x, y, z);

}


/*	function subtwo(a,b) takes two
	arguments of type float, subtracts them 
	and returns the result to the calling
	function */

float subtwo(float a, float b)
{
float c;

// subtract argument b from argument a
// and store the result in local variable c
  c = a - b;

  return c;
}
