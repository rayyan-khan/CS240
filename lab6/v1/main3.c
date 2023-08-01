// Example involving command-line arguments.

#include <stdio.h>

int main(int argc, char **argv, char **env)
{
int i;

  while (*env != NULL) {
	printf("%s\n", *env);
	env++;
  }

  return 0;
}
