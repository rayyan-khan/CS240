#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char buf[100]; // contains command-line args, passed to execvp() later
extern char **commandcomp; // array where the input is stored before parsing

int parsecommand(void) {
    int strlen = 0; // to track string length for allocating memory
    int buf_index = 0; // to track location in buf
    int command_index = 0; // to determine which string # is being placed in commandcomp
    int str_index = 0; // to determine position in string when placing in commandcomp
    int num_spaces = 0; // to use number of spaces to determine number of words
    int space = 0; // to check for multiple spaces in a row
    int curr = buf[0]; // to track current item in buf


    /*************************************
    *  CHECK FOR AND TERMINATE PROGRAM WHEN 
    *  THERE ARE MULTIPLE SPACES IN A ROW
    *************************************/
    while(curr != '\0') {
        if(curr == ' ') {
            if(space == 1) {
                printf("You may not have more than one space in a row. Ending program.");
                exit(1);
            }
            else {
                space = 1;
            }
        }
        else {
            space = 0;
        }
        curr = buf[++buf_index];
    }


    /*********************************************
     *  ALLOCATE FOR NUMBER OF WORDS IN COMMANDCOMP
     * *******************************************/
    curr = buf[0];
    buf_index = 0;
    while(curr != '\0') {
        if(curr == ' ') {
            num_spaces++;
        }
        curr = buf[++buf_index];
    }
    commandcomp = malloc(sizeof(char) * (num_spaces + 1));


    /***********************************
     *  MALLOC FOR EACH INDIVIDUAL WORD
     * *********************************/
    curr = buf[0];
    buf_index = 0;
    while(curr != '\0') {
        if(curr == ' ') {
            commandcomp[command_index] = (char *)malloc(sizeof(char) * strlen);
            command_index++;
            strlen = 0;
        }
        strlen++;
        curr = buf[++buf_index];
    }


    /*********************************************************
     *  ALLOCATE SPACE FOR NULL POINTER AND ADD TO COMMANDCOMP
     * *******************************************************/
    commandcomp[command_index] = (char *)malloc(sizeof(char));
    commandcomp[command_index][0]= '\0';


    /**************************************
     *  ADD STRINGS TO COMMANDCOMP
     * ************************************/
    command_index = 0;
    buf_index = 0;
    curr = buf[0];
    while(curr != '\0') {
        if(curr == ' ') {
            command_index++;
            str_index = 0;
        }
        else {
            commandcomp[command_index][str_index] = curr;
            str_index++;
        }
        curr = buf[++buf_index];
    }
}