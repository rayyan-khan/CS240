// C++ is a superset of C with OO (objective oriented) extensions.
// However, there are subtle differences that must be taken into account
// when porting C code.

#include <stdio.h>

int main()
{
int s;
void changev(int &);

  s = 7;
  printf("%d\n",s);

  changev(s);
  printf("%d\n",s);

}


void changev(int &x)
{
  x = 2;
}
