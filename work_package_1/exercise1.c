// The porpus reads  in  an  integer  number  between  1  and  5  from  the  keyboard  and  prints  out  one  of
// existing five sentences on the console depending on what number was entered
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

//Include section
#include <stdio.h>

// Main program section
int main(int argc, char *argv[])
{
    //Declaration section
    int num; //Initialize the input number
    char *sentences[] = {"I like spaghetti.", "He reads many books.", "He obtained his degree.",
                         "She completed her literature review.", "He organized his sources by theme."}; //Add the scentences
    int isnum = 1;                                                                                      //Number to check if the input is in range

    //Logic section
    // Create a loop for as long as the inpout is between 1 and 5
    while (isnum)
    {
        //Ask for user input
        printf("Please imput a number between 1 and 5.\n");
        //Get user input
        scanf("%s", &num);
        //Create a switch for the number inputed
        switch (num)
        {
        // Check what is number is
        case '1':
            //Print sentence
            printf("%s\n\n", sentences[num - '1']);
            // Exit the switch
            break;
        case '2':
            printf("%s\n\n", sentences[num - '1']);
            break;
        case '3':
            printf("%s\n\n", sentences[num - '1']);
            break;
        case '4':
            printf("%s\n\n", sentences[num - '1']);
            break;
        case '5':
            printf("%s\n\n", sentences[num - '1']);
            break;
        default:
            //If the input is outside the range, break the loop
            isnum = 0;
            break;
        }
    }

    return 0;
}
