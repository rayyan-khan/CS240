#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

void coption(char *, char *);
void hoption(char *, char *);
void noption(char *, char *);

char pattern[100];

void grep(char * buf) {
    int i = 4;
    char curr = buf[i];
    char option[2];
    int option_index = 0;
    int pattern_index = 0;
    char filename[100];
    int filename_index = 0;

    // skip spaces before option
    while(curr == ' ') {
        curr = buf[i++];
    }

    // take in option
    while(curr != ' ') {
        option[option_index++] = curr;
        curr = buf[i++];
    }
    //printf("Option: %s\n", option);

    // skip spaces before pattern
    while(curr == ' ' || curr == '"') {
        curr = buf[i++];
    }

    // take in pattern
    while(curr != ' ' && curr != '"') {
        pattern[pattern_index++] = curr;
        curr = buf[i++];
    }
    curr = buf[i++];
    //printf("Pattern: %s\n", pattern);

    // skip spaces before filename
    while(curr == ' ') {
        curr = buf[i++];
    }

    // take in filename
    while(curr != ' ' && curr != '\n' && curr != '\0') {
        filename[filename_index++] = curr;
        curr = buf[i++];
    }
    filename[filename_index] = '\0';
    //printf("Filename: %s\n", filename);

    // handle options
    if(option[1] == 'c') {
        coption(filename, pattern);
    }
    else if(option[1] == 'h') {
        hoption(filename, pattern);
    }
    else if(option[1] == 'n') {
        noption(filename, pattern);
    }
    else {
        printf("Invalid option, exiting program.\n");
        exit(0);
    }

}

void coption(char * filename, char * pattern) {
    int sum = 0;

    // open file
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file. Exiting.\n");
        exit(1);
    }

    char line[250];

    regex_t regex;
    int value = regcomp(&regex, pattern, 0);

    while(fgets(line, 250, file) != NULL) {
        value = regexec(&regex, line, 0, NULL, 0);
        if(value == 0) 
            sum++;
    }

    printf("%d\n", sum);
    fclose(file);
}

void hoption(char * filename, char * pattern) {
    // open file
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file. Exiting.\n");
        exit(1);
    }

    char line[250];

    regex_t regex;
    int value = regcomp(&regex, pattern, 0);

    while(fgets(line, 250, file) != NULL) {
        value = regexec(&regex, line, 0, NULL, 0);
        if(value == 0) 
            printf("%s", line);
    }
}

void noption(char * filename, char * pattern) {
    // open file
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file. Exiting.\n");
        exit(1);
    }

    char line[250];
    int line_num = 1;
    regex_t regex;
    int value = regcomp(&regex, pattern, 0);

    while(fgets(line, 250, file) != NULL) {
        value = regexec(&regex, line, 0, NULL, 0);
        if(value == 0) 
            printf("%d: %s", line_num, line);
        line_num++;
    }
}