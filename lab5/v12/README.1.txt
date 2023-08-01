For the bonus, I wrote a modified grep command. 
My grep command works with the format: 

grep <option> <pattern> <filename>

Unlike the traditional grep command, mine only accepts one option and filename.
It also only accepts the -c, -h, and -n options. The pattern must be a regex pattern 
enclosed by double quotes. 

When using the -c option, my grep command will open the given file, and count the
number of lines containing the given pattern using regex. It will then output
that count. 

When using the -h option, my grep command will open the given file, use regex to
determine the lines containing the given pattern, and print out those lines. 

When using the -n option, my grep command will open the given file, use regex to 
determine the lines containing the given pattern, and print out those lines with
their accompanying line numbers preceding each line. 