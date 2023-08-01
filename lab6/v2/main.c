// A version of cat <filename> command.

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
FILE *fp;
char c;

  fp = fopen(argv[1],"r");
  if(fp == NULL) {
        fprintf(stderr,"file %s cannot be opened\n", argv[1]);
        exit(1);
  }

  while((c = fgetc(fp)) != EOF)
	fprintf(stdout,"%c",c);

  return 0;
}
