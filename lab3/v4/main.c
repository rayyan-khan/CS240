// Function that returns pointer.

#include <stdio.h>

char *removelastname(char *);


int main()
{
char a[8];
char *b;

  a[0] = 'A';
  a[1] = 'L';
  a[2] = 'I';
  a[3] = 'C';
  a[4] = 'E';
  a[5] = ' ';
  a[6] = 'G';
  a[7] = '\0';

  printf("%s\n", a);

  b = removelastname(a);

  printf("%s\n", b);

}


/* Remove last name. */

char *removelastname(char *s) {
int i;

  i = 0;
  while(s[i] != ' ')
	i++;

  s[i] = '\0';

  return(s);
}
