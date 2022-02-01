// The  program  is a simple guessing game 
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 3
// Submission code: OP8qDyMb

//Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 50 //Number of guesses

//Main section
int main(int argc, char *argv[])
{
    //Seed the random number with the time
    srand(time(NULL));         //https://stackoverflow.com/questions/1108780/why-do-i-always-get-the-same-sequence-of-random-numbers-with-rand
    int random = rand() % 101; //Generate a number between 0 and 100
    int exit = 0;              //Initiate variable for exit
    int guesses = 1;           //Initiate variable for counting the guesses
    int answer = 0;            //Initiate the variable for the user input
    int again = 0;             //Initiate the variable for playing again

    //Logic section

    //printf("%d\n", random); //See the random number for testing
    //Ask the user to make a guess
    printf("Please make a guess!\n");
    //Get the user input
    scanf("%d", &answer);
    //Ask for input as long as there are guesses left and the user want to continue to play
    while (!exit && guesses <= MAX_NUMBER)
    {
        //Check if the guess is correct
        if (answer == random)
        {
            //Inform the user and present the amout of guesses spent 
            printf("You have guessed %d times and your guess is correct!\n", guesses);
            //Ask if they want to play another round
            printf("Would you like to try again? 0 = no, 1 = yes\n");
            //Get user input
            scanf("%d", &again);
            //Check if the user wants to play again
            if (again)
            {
                random = rand() % 101; //Generate another nnumber
                guesses = 1;           //Reset guesses
                again = 0;             //Reset another round bool
                //Ask for user input
                printf("Please make a guess!\n");
                //Get user input
                scanf("%d", &answer);
            }
            //If the user doesn't want to play another round
            //Exit the program
            else
            {
                exit = 1;
            }
        }
        //If the answer wasn't correct
        else
        {
            //Check if the answer is lower than the number
            if (answer < random)
            {
                //Inform the user
                printf("Your guess was too low. Please try again!\n");
                //Get user input
                scanf("%d", &answer);
                //Increment the guesses
                guesses++;
            }
            //Check if the answer is higher than the number
            else if (answer > random)
            {
                //Inform the user
                printf("Your guess was too high. Please try again!\n");
                //Get user input
                scanf("%d", &answer);
                //Increment the guesses
                guesses++;
            }
        }
    }

    return 0;
}
