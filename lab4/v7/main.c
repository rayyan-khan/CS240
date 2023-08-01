#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXSIZE 16
#define MAXLEN 15

int main() {
    
    char filename[MAXSIZE];
    int i = 0;
    char c = getchar();
    while(c != '\n' && i < MAXLEN) {
        filename[i] = c;
        c = getchar();
        i++;
    }

    if (i >= MAXLEN) {
        printf("File exceeds max length. Ending program.");
        exit(1);
    }
    else {
        filename[i] = '\0';
    }

    // count chars in file
    FILE *file0 = fopen(filename, "r");
    if(file0 == NULL) {
        printf("Error opening file %s, ending program.\n", filename);
        exit(1);
    }
    int count = 0;
    char ch;
    for (ch = getc(file0); ch != EOF; ch = getc(file0)) {
        count++;
    }
    fclose(file0);

    // calculate file ending number
    int endnum;
	count--;
    if(count % 8 == 0) {
        endnum = 0;
    } 
    else {
        endnum = 8 - (count % 8);
    }

    // calculate new file name
    char new_file_name[MAXSIZE + 3];
    int x;
    for(x = 0; x < i; x++) {
            new_file_name[x] = filename[x];
    }
    new_file_name[x] = '.';
    new_file_name[x+1] = 'P';
    new_file_name[x+2] = endnum + '0';
    new_file_name[x+3] = '\0';


    // reopen file
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening first file %s, ending program.\n", filename);
        exit(1);
    }

    // open new file
    FILE *new_file = fopen(new_file_name, "w");
    if(new_file == NULL) {
        printf("Error opening first file %s, ending program.\n", new_file_name);
        exit(1);
    }

    char rawdat[8];
    for(int i = 0; i < 8; i++) {
        rawdat[i] = '0';
    }
    
    while(fgets(rawdat, 9, file) != NULL) {
        unsigned int intdat[8];
        for(int i = 0; i < 8; i++) {
            intdat[i] = (unsigned int)(rawdat[i] - '0');
            //printf("%u", intdat[i]);
        }
        //printf("\n");

        uint8_t bin;
        for(int j = 0; j < 8; ++j) {
            bin |= (intdat[j] << j);
        }
        bin = ~bin;

        fwrite(&bin, 1, 1, new_file);

        for(int k = 0; k < 8; k++) {
            rawdat[i] = '0';
        }
    }   
}
