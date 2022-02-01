// The  program  “shifts  characters” in  the  ASCII-code  table  of  a  given
// input string.
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 2
// Submission code: OP8qDyMb

//Include section
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Main section
int main(int argc, char *argv[])
{
    //Defining section
    int number = atoi(argv[1]); // Get the character shift amount from the program arguments
    int loop = 1;               //Initiate loop
    char word[100];             //Initiate variable for user input

    //Logic section
    //Get user input and loop for as long as the input is not EOF
    while (scanf("%s", &word) != EOF) //shorturl.at/pAF47
    {
        int new; //Initiate the output variable

        //Go throgh each letter of the input
        for (int i = 0; i < strlen(word); i++)
        {
            //Check if the current character is between "a" and "z"
            if (word[i] >= 97 && word[i] <= 122)
            {
                //Shift the lettter
                new = word[i] + number;
                //Check if the new letter is after "z"
                if (!(new <= 122))
                {
                    //Shift the letter backwards
                    new = new - (number * 2);
                }
            }
            //Check if the letter is between "A" and "Z"
            else if (word[i] >= 65 && word[i] <= 90)
            {
                //Shift the lettter
                new = word[i] + number;
                //Check if the new letter is after "Z"
                if (!(new <= 90))
                {
                    //Shift the letter backwards
                    new = new - (number * 2);
                }
            }
            //If the current character is not a letter
            //don't shift it.
            else
            {
                new = word[i];
            }
            //Print the encripted word
            printf("%c", new);
        }
        //Go to a new line after a word has been encrypted
        printf("\n");
    }

    return 0;
}
