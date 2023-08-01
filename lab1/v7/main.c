/* 	version 7 of z = x - y
	same as version 6 but puts function
	declaration of subtwo()
	in a separate file, myheader.c */ 

#include <stdio.h>
#include "v7sub/myheader.h"

int main() 
{
float x, y, z;

// read input
  scanf("%f %f",&x,&y);

// compute subtraction
  z = subtwo(x,y);

// print result
  printf("result of %f minus %f is %.2f\n", x, y, z);

}
