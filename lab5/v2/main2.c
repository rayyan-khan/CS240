// malloc() example involving 2-D tables containing integers.

#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *fp;
int row, column;
int **table2d;
int i, j;

  fp = fopen("test1.dat","r");
  if(fp == NULL) {
	fprintf(stderr,"file test1.dat does not exist\n");
	exit(1);
  }

  // read the size of 2-D table
  fscanf(fp, "%d %d", &row, &column);

  // allocate space for pointers for rows
  table2d = (int **) malloc(row * sizeof(int *));
  if(table2d == NULL) {
	fprintf(stderr,"malloc failed\n");
	exit(1);
  }

  // for each row, allocate space for columns
  for(i=0; i<row; i++)
	*(table2d + i) = (int *) malloc(column * sizeof(int));

  // read 2D integer table values
  for(i=0; i<row; i++)
  	for(j=0; j<column; j++)
	  fscanf(fp, "%d", &table2d[i][j]);

  // print to stdout
  for(i=0; i<row; i++)
  	for(j=0; j<column; j++)
	  printf("%d\n", table2d[i][j]);

}
