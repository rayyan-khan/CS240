#include "myheader.h"

void inputcheck(void);

int main() {
    unsigned int decpos; // convert numpos to unsigned int
    char new_file_name[MAXSIZE + 3]; // make name of new file
    int len; // find length of original filename
    int i; 

    inputcheck();

    decpos = (unsigned int)(numpos - '0');    
    if(decpos < 0 || decpos > 7) {
        printf("Input number out of correct range (0-7). Ending program.");
        exit(1);
    }
    //printf("%u\n", decpos);

    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening first file %s, ending program.\n", filename);
        exit(1);
    }
    
    len = 0; // getting length of file
    while(filename[len] != '\0') {
        len++;
    }

    // creating new file name
    if(filename[len - 2] == 'E' && filename[len - 1] == '2') {
        for(i = 0; i < len - 3; i++) {
            new_file_name[i] = filename[i];
        }
        new_file_name[i] = '\0';
    }
    else {
        for(i = 0; i < len; i++) {
            new_file_name[i] = filename[i];
        }
        new_file_name[i] = '.';
        new_file_name[i+1] = 'E';
        new_file_name[i+2] = '2';
        new_file_name[i+3] = '\0';
    }

    FILE *new_file = fopen(new_file_name, "w");
    if(new_file == NULL) {
        printf("Error opening file %s, ending program.\n", new_file_name);
        exit(1);
    }

    char c = fgetc(file);
    while(c != EOF) {
        //encryption stuff
        c ^= 1 << decpos;
        fputc(c, new_file);

        // get next
        c = fgetc(file);
    }

    fclose(new_file);
    remove(filename);
    fclose(file);

}