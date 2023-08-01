// Basic file I/O.

#include <stdio.h>
#include <stdlib.h>


int main() {

FILE *fp, *fp1;
int i, j, z[100];

  // open file to read
  if((fp = fopen("test1.txt","r")) == NULL) {
	fprintf(stderr,"file test1.txt does not exist\n");
	exit(1);
  }

  // open file to write
  fp1 = fopen("result.dat","w");
  if(fp == NULL) {
	fprintf(stderr,"creating file result.dat failed\n");
	exit(1);
  }

  // read data
  i = 0;
  while(fscanf(fp,"%d", &z[i]) != EOF) 
	i++;

  // write data
  for(j=0; j<i; j++)
  	fprintf(fp1,"%d\n", z[j]*100);

  fclose(fp);
  fclose(fp1);

}
