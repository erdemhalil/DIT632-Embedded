// This program gives the hexadecimal representation of a provided binary number
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 4
// Submission code: OP8qDyMb

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define BUFFERSIZE 70

void bin2Hex(char binString[]);

int main(int argc, char *argv[]) {
    
    //If there's an argument provided
    if (argc == 2) {
        const char* argString = argv[1];
        if(!strcmp(argv[1],"-h")){
            printf("This program gets the binary and/or hexadecimal value of a provided decimal number \n");
            printf("For instance: dec2bin 12 | bin2hex \n");
        } else {       
            for (int i = 0; i < (int) strlen(argString); i++){
                if(argString[i] != '1' && argString[i] != '0'){
                    printf("\nERROR: not a binaty number!\n");
                    return 2;
                }
            }
            bin2Hex(argString);
        }
    } else {
        char inputString[BUFFERSIZE];
        fgets(inputString, BUFFERSIZE, stdin);
        bool streamEmpty = inputString[1] == '\0'; // checks if imput string is empty

        if (streamEmpty) {
            return 2;
        }
        bin2Hex(inputString);
        
    } 
    return 0;
}


void bin2Hex(const char binString[]) {

    // Separate the stream array into 4 bit chunks (nibbles)
    // in order to convert and store their value in an int and print them as hex
    int inputLength = (int) strlen(binString) - 1;
    for (int i = 0; i < inputLength; i += 4) {
        char digit[5];
        strncpy(digit, &binString[i], 4);
        int digitAsHex = (int) strtol(digit, NULL, 2);
        printf("%X", digitAsHex);
    }
    printf("\n");
}