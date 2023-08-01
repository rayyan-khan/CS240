// Usefulness of system() utility function.

#include <stdio.h>
#include <stdlib.h>

#define FULLPATHPURDUEWEB "/usr/bin/host www.purdue.edu"


int main()
{
char fullpathhostname[] = FULLPATHPURDUEWEB;

  system("/usr/bin/host www.purdue.edu");
  system(FULLPATHPURDUEWEB);
  system(fullpathhostname);

  fullpathhostname[0] = 'l';
  fullpathhostname[1] = 's';
  fullpathhostname[2] = ' ';
  fullpathhostname[3] = '-';
  fullpathhostname[4] = 'l';
  fullpathhostname[5] = '\0';

  system(fullpathhostname);
}
