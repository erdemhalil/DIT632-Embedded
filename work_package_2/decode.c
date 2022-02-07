// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 2
// Exercise 4
// Submission code:

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to check whether input is a valid hexadecimal number
int valid_hex(char *hex)
{
    int len = strlen(hex); // Get the length of the input
    for(int i = 0; i < len; i++) // For each character of the input
    {
        char c = hex[i]; // Get the character

        if((c < '0' || c > '9') && (c < 'A' || c > 'F') && (c < 'a' || c > 'f')) // Check whether it's not 0-9, a-f or A-F, if so return 0
        {
            return 0; 
        }
    }

    return 1; // If it's valid return 1
}

int main(int argc, char *argv[])
{
    // Variable declarations
    unsigned int hex;
    unsigned int engine_on;
    unsigned int gear_pos;
    unsigned int key_pos;
    unsigned int brake1;
    unsigned int brake2;

    // Check whether we have only one provided argument
    if (argc == 2)
    {
        int arg_len = strlen(argv[1]); // Get the length of the argument
        if (arg_len > 0 && arg_len < 3) // Check if the length is 1 or 2
        {
            if (valid_hex) // if the provided argument is a valid hexadecimal
            {
                hex = (unsigned int)strtol(argv[1], NULL, 16); // Convert hexadecimal to long int and then cast it to unsigned int

                engine_on = hex >> 7; // To get the most significant bit, shift by 7 bits
                gear_pos = hex & 127; // To disregard the MSB, perform AND-operation with 127 (01111111) -> MSB will always be 0
                gear_pos = gear_pos >> 4; // Shift by 4 bits so we get bits number 4,5,6 as result, bit no 7 is already 0
                key_pos = hex & 15; // To disregard bits no 4-7, perform AND-operation with 15 (00001111) -> Bits no 4,5,6,7 will always be 0
                key_pos = key_pos >> 2; // Shift by 2 bits so we get bits no 2 and 3 as result, bits no 4-7 are already 0
                brake1 = hex & 3; // To disregegard bits no 2-7, perform AND-operation with 3 (00000011) -> Bits no 2,3,4,5,6,7 will always be 0
                brake1 = brake1 >> 1; // Shift by 1 bit so we get bit no 1 as result, bits 2-7 are already 0
                brake2 = hex & 1; // To get the least significant bit, perform AND-operation with 1 (00000001) - > All bits apart from LSB will always be 0

                // Print out values
                printf("engine_on: %d \n", engine_on);
                printf("gear_pos: %d \n", gear_pos);
                printf("key_pos: %d \n", key_pos);
                printf("brake1: %d \n", brake1);
                printf("brake2: %d \n", brake2);
            }
            else  // If the argument is not a valid hexadecimal, print out an error message
            {
                printf("Not a valid hexadecimal number! \n");
            }
        }
        else // If the length is different than 1 or 2, print out an error message
        {
            printf("Please enter a hexadecimal value of max 2 characters! \n");
        }
    } 
    else // If there is more than 1 argument provided, print out an error message
    {
        printf("Please enter only one argument with max input of 2 character! \n");
    }
}