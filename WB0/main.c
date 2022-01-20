// (C) Ediz, Bassam, Bardha, Group: 23 (2022)
// Work package 0
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

/*
------------------------------------------------------------------
A program using the GNU Compiler Collections(GCC) through provided
arguments and error handling for the major possible cases.
------------------------------------------------------------------
*/

// Included libraries
#include <stdio.h>
#include <string.h>

// Main function in the program with two arguments; 1st for index & 2nd for string charachters
int main(int argc, char* argv[])
{
    // The case whether argument is provided
    if (argv[1] == NULL) {
        // Print the string for the user as warning that argument input can not be empty
        printf("%s", "You have not entered any arguments, type \"./filename -h\" for help!");
    }
    // The case of error handling the number of arguments.
    else if (argc > 2) {
        // Print the string for the user as warning to input the right arguments
        printf("%s", "It should be provided only one argument, type \"-h\" for help!");
    }
    // The case of supporting the end-user in case of help.
    else if (strcmp(argv[1], "-h") == 0) {
        // Print the string for the user help
        printf("%s", "To be able to run the program, type \".exe\" file, a whitespace, type the argument! [i.e.= \"./filename <argument>\" ]");
    }
    // The case when the input as expected
    else {
        // Print a string to the console
        printf("%s %s %s", "Hello World! I'm", argv[1], "\n");
    }
    // The program executed (successfully) as it was intended to do with no errors.
    return 0;
}