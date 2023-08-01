// Example involving command-line arguments.

#include <stdio.h>
#include <unistd.h>

int main()
{
int i;

  fprintf(stdout,"This is a.out: part I\n");
  fflush(stdout);

  execlp("argprint", "argprint", "5", "6", "-e", "-f", NULL);

  fprintf(stdout,"This is a.out: part II\n");
  fflush(stdout);

  return 0;

}
