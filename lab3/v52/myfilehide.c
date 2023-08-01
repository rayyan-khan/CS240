#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[11];
    char new_file_name[13];
    int i, len;
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file %s", filename);
        exit(1);
    }
    
    len = 0;
    while(filename[len] != '\0') {
        len++;
    }

    if(filename[len - 1] == 'E') {
        for(i = 0; i < len - 2; i++) {
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
        new_file_name[i+2] = '\0';
    }

    FILE *new_file = fopen(new_file_name, "w");
    if(new_file == NULL) {
        printf("Error opening file %s", new_file_name);
        exit(1);
    }

    char c = fgetc(file);
    while(c != EOF) {
        int asc = c;
        int encrypt = 255 - asc;
        fputc(encrypt, new_file);
        c = fgetc(file);
    }

    fclose(new_file);
    remove(filename);
    fclose(file);
}