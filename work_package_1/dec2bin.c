// This program gives the binary representation of a provided decimal number
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 4
// Submission code: OP8qDyMb

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


void dec2Bin(long number);
bool valid_number(char number[]);

int main(int argc, char* argv[])
{

    //If there's one argument provided
    if (argc == 2)
    {
        //Check whether the argument is a valid number
        int numberCheck = valid_number(argv[1]);

        //If -h is passed as the argument, print out help message
        if (!strcmp("-h", argv[1]))
        {
            printf("This program gets the binary and/or hexadecimal value of a provided decimal number \n");
            printf("For instance: dec2bin 12 | bin2hex \n");
        }
        //If a valid number is provided
        else if (numberCheck == 1)
        {
            long inputNum = 0;
            char *inputString = argv[1];
            //Turn the char into a long to be passed into the function
            sscanf(inputString, "%ld", &inputNum);
            dec2Bin(inputNum);
        }
        //If the input is invalid, print out a message and exit
        else
        {
            printf("Not a valid input. Conversion unsuccessful \n");
            // Exit the program
            return 2;
        }
    }
    
    return 0;
}

// Check whether the provided array of character is actually a number
bool valid_number(char number[])
{
    int i = 0;

    //Check for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if the number is not a digit return false
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

void dec2Bin(long number) {

    // Get the number of bits the number takes
    int bits = (long)(log2(number)+1);

    // Get the smallest number of bytes for the number
    int typeSize = 0;
    if (bits <= 8) {
        typeSize = 8;
    } else if (bits <= 16) {
        typeSize = 16;
    } else if (bits <= 32) {
        typeSize = 32;
    } else if (bits <= 64) {
        typeSize = 64;
    }

    // String that will contain the binary value
    char binary[typeSize + 1];
    
    //// Decimal to Binary
    int id = typeSize - 1;
    while (number > 0) {
        binary[id--] = (number % 2) +'0';
        number = number / 2;
    }

    // Fill the empty parts of the array with zeroes
    for (int i = 0; i < typeSize - bits; i++) {
        binary[i] = '0';
    }

    printf("%s\n", binary);
}