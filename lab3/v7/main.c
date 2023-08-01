// Basic file I/O.

#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fp;
int x; 
float y; 
char z[100];

  // open file to read
  fp = fopen("test.txt","r");

  // open failed
  if(fp == NULL) {
	fprintf(stderr,"file test.txt does not exist\n");
	exit(1);
  }

  fscanf(fp,"%d %f %s",&x,&y,z);
  fprintf(stdout,"%d %f %s\n",x,y,z);

}
