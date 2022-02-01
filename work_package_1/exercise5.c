// The  program calculates statistical values for an array of integers.
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 5
// Submission code: OP8qDyMb

//Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations   ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq);


// ------ Function definitions   ----------

void create_random(int *tab)
{
    //Seed the random number generator
    srand(time(NULL));
    //Loop through the table
    for (int i = 0; i < MAX; i++)
    {
        //Generate a random number for every position of the table
        int random = rand() % MAXNUMBER;
        //Assign the number
        *tab = random;
        //Increment through the table
        *tab++;
    }
}

void count_frequency(int *tab, int *freq)
{
    int count = 0; //Initiate the variable for counting the frequency
    int new[MAX];  //Create a new table
    //Iterate through the old table
    for (int i = 0; i < MAX; i++)
    {
        //Assign the new table it's value
        new[i] = *tab;
        //Increment the table position
        *tab++;
    }
    //Iterate through the possible values
    for (int i = 0; i < MAXNUMBER; i++)
    {
        //Iterate through the table
        for (int j = 0; j < MAX; j++)
        {
            //Check if the value at the current table possition is the same
            if (new[j] == i)
            {
                //Increase the count
                count++;
            }
        }
        //Assign the count value to the frequency table
        *freq = count;
        //Increment the frequency table
        *freq++;
        //Reset the count
        count = 0;
    }
}

void draw_histogram(int *freq)
{
    //Loop through the possible values
    for (int i = 0; i < MAXNUMBER; i++)
    {
        //Check if the current elment is not zero
        if (*freq != 0)
        {
            //Print the current value
            printf("%d\t", i);
            //Iterate through the current evelent value
            for (int j = 0; j < *freq; j++)
            {
                //Print "x" the approopriate amout of times
                printf("x");
            }
            //Go to a new line for the next value
            printf("\n");
        }
        //Increment the current position of the frequency table
        *freq++;
    }
}

// ------ Main   --------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{
    int table[MAX], n;
    //Generate the random number of the table
    create_random(table);

    int frequency[MAXNUMBER];
    //Calculate the frequency of the table
    count_frequency(table, frequency);

    //Draw the histogram
    draw_histogram(frequency);
}
