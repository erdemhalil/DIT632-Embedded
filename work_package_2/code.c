// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 2
// Exercise 4
// Submission code: enN8B0Bc

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    unsigned char result = 0; // Initiate unsigned character
    int check = 0;            // Initiare variable to check argument validity

    // Check if there are 5 arguments
    if (argc != 6)
    {
        // Inform the user if there are too few or too many arguments
        printf("Too few too many arguments passed.\n");
        // Exit the program
        return 1;
    }

    // Check if the first argument is in the correct range
    if (atoi(argv[1]) == 0 || atoi(argv[1]) == 1)
        // Add the value to the result if correct to the correct shifted position
        result += atoi(argv[1]) << 7;
    else
        // Flag the check if the argument is wrong
        check = 1;

    // Check if the second argument is in the correct range
    if (atoi(argv[2]) >= 0 || atoi(argv[2]) <= 4)
        result += atoi(argv[2]) << 4;
    else
        check = 1;

    // Check if the third argument is in the correct range
    if (atoi(argv[3]) >= 0 || atoi(argv[3]) <= 2)
        result += atoi(argv[3]) << 2;
    else
        check = 1;

    // Check if the forth argument is in the correct range
    if (atoi(argv[4]) == 0 || atoi(argv[4]) == 1)
        result += atoi(argv[4]) << 1;
    else
        check = 1;

    // Check if the fifth argument is in the correct range
    if (atoi(argv[5]) == 0 || atoi(argv[5]) == 1)
        result += atoi(argv[5]);
    else
        check = 1;

    // Check if there are any wrong arguments
    if (check)
    {
        // Inform the user
        printf("There was someting wrong with the entered arguments");
        // Exit the program
        return 1;
    }

    // Print the result in hexadecimal
    printf("%x\n", result);
    return 0;
}
