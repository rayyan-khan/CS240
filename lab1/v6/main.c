/* 	version 6 of z = x - y
	same as version 5 but puts subtwo()
	in a separate file, subtwo.c */ 

#include <stdio.h>

float subtwo(float, float);

int main() 
{
float x, y, z;

// read input
  scanf("%f %f",&x,&y);

// subtract
  z = subtwo(x,y);

// print result
  printf("result of %f minus %f equals %.3f\n", x, y, z);

}
