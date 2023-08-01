// Use functions changev1() and changev2() to illustrate
// passing by value vs. reference. 

#include <stdio.h>

void changev1(int);
void changev2(int *);
void changev3();

int x = 7;

int main()
{
//int x;

  //x = 7;

  changev1(x);
  printf("%d\n",x);

  changev2(&x);
  printf("%d\n",x);
  
  changev3(&x);
  printf("%d\n",x);
}


void changev1(int b)
{
  b = 2;
}


void changev2(int *b)
{
  b = 2;
}

void changev3() 
{
  x = 5;
}
