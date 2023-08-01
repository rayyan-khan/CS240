/************************
*    PROBLEM 3 MYSH
************************/

main.c: 
    - main.c includes the main() function and globals used by cprompt.c, mem.c, and d.c
    - the main() function prints a prompt and then reads in from stdin
    - once the input is read in, main() checks if it is an applicable command and then calls
      the functions cprompt.c, mem.c, or d.c to help perform the command (each described below)
    - if none of the applicable functions are used, it creates a "worker bee"

cprompt.c: 
    - if the user inputs the cprompt command, main calls cprompt(char *) and passes the argument 
      buf, the input it read in from stdin
    - there may be any number of spaces between cprompt and the argument
    - main() prevents the default prompt from printing out and allows cprompt() to print its own
    - cprompt() allows for any number of spaces before the argument
    - once it determines the argument, if the argument is invalid, it quits the program
    - if the argument is:
        0: prints the prompt "$ "
        1: prints the prompt "> "
        2: prints the prompt reflecting the PID number
        3: prints a prompt of my choosing, "# "
    - after cprompt prints its prompt, the next prompt will be the default prompt unless cprompt() 
      run again

mem.c: 
    - when the user inputs the argument "mem", main() calls mem(char *) where the argument is the 
      input read from stdin 
    - there may be any number of spaces between mem and the argument
    - when mem is run without an argument, it prints the string contents of its 10-index array
    - if there is no string stored at an index, it prints "No string stored."
    - if mem is run with an argument, that argument is added as a string in the array
    - if the array reaches 10 strings entered, it loops over and starts replacing strings at the 
      beginning

d.c: 
    - d is called with two following arguments, e.g.: d <sec> <binexec>
    - the command d will delay running the legacy executable <binexec> by <sec> seconds
    - there may be any number of spaces between the command d and each argument
