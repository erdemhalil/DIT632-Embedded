// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 2
// Exercise 1
// Submission code:

#include <ctype.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h> 


// enum declaration for robot's directions
enum DIRECTION
{
    N,
    E,
    S,
    W
};

// robot struct declaration
typedef struct
{
    int xpos; // x position of the robot
    int ypos; // y position of the robot
    enum DIRECTION dir; // direction of the robot
} ROBOT;

// Function declaration
void move(ROBOT*);
void turn(ROBOT*);
int valid_coordinate(int input);
int valid_move(char* input);

int main()
{
    ROBOT robot; // initialize robot
    robot.dir = 'N'; // set direction to north as per requirement

    // variable declarations
    int x_coordinate;
    int y_coordinate;
    char moves[100];
    bool continuePlaying = true;
    char userInput;

    // While user wants to continue playing
    while (continuePlaying)
    {
        // Boolean declarations for the input loops
        bool valid_x = false;
        bool valid_y = false;
        bool valid_m = false;
        bool valid_i = false;
        // If the user enters a valid x coordinate set the robot's x position to the input and exit loop
        // Else keep asking for new input
        while (!valid_x)
        {
            printf("Select starting x-axis position for the robot (0-99): \n");
            scanf("%d", &x_coordinate);
            if (valid_coordinate(x_coordinate))
            {
                robot.xpos = x_coordinate;
                valid_x = true;
            }
        }

        // If the users enters a valid y coordinate set the robot's y position to the input and exit loop
        // Else keep asking for new input
        while (!valid_y)
        {
            printf("Select starting y-axis position for the robot (0-99): \n");
            scanf("%d", &y_coordinate);
            if (valid_coordinate(y_coordinate))
            {
                robot.ypos = y_coordinate;
                valid_y = true;
            }
        }

        // If the user enters a valid movement string, move the robot accordingly
        // Else keep asking for new input
        while (!valid_m)
        {
            printf("\n Enter robot's movement. Type 'm' to make it move 1 position forward and 't' to make it turn 90 degrees. Example: mmmtmttttm \n");
            scanf("%s", &moves);
            if (valid_move(moves))
            {
                // Go through the validated input and call turn or move function according to the character
                int move_length = strlen(moves);
                for (int i = 0; i < move_length; i++)
                {
                    if (moves[i] == 't' || moves[i] == 'T')
                    {                                          // If the character is t or T, turn the robot 
                        turn(&robot);
                    }
                    else if (moves[i] == 'm' || moves[i] == 'M')
                    {                                          // If the character is m or M, move the robot
                        move(&robot);
                    }
                }
                printf("The robot is facing %c at x:%d, y:%d. \n", robot.dir, robot.xpos, robot.ypos);
                valid_m = true;
            }
        }

        // Ask the user whether they want to continue playing, check whether their input is valid (y,Y,n,N) and behave accordingly
        // If the input is not valid, keep asking until valid input is received
        while (!valid_i)
        {
            printf("Would you like to continue? Type 'y' for Yes and 'n' for No! \n");
            scanf(" %c", &userInput);
            if (userInput == 'n' || userInput == 'N')
            {
                continuePlaying = false;
                valid_i = true;
            }
            else if (userInput = 'y' || userInput == 'Y')
            {
                valid_i = true;
            }
            else
            {
                printf("Invalid input! \n");
            }
        }
    }
}

// Function to make the robot move from user's input
void move(ROBOT* robot)
{
    switch (robot->dir) {
    case 'N':           // If the robot is facing north, add 1 to Y axis
        robot->ypos++;
        break;
    case 'E':           // If the robot is facing east, add 1 to X axis     
        robot->xpos++;
        break;
    case 'S':           // If the robot is facing south, subtract 1 from Y axis
        robot->ypos--;
        break;
    case 'W':           // If the robot is facing west, subtract 1 from X axis
        robot->xpos--;
        break;
    }
}

// Function to make the robot turn from user's input
void turn(ROBOT* robot)
{
    switch (robot->dir) {
    case 'N':           // If the robot is facing north, make it turn to east
        robot->dir = 'E';
        break;
    case 'E':           // If the robot is facing east, make it turn to south   
        robot->dir = 'S';
        break;
    case 'S':           // If the robot is facing south, make it turn to west
        robot->dir = 'W';
        break;
    case 'W':           // If the robot is facing west, make it turn to north
        robot->dir = 'N';
        break;
    }
}

// Function to validate a coordinate
int valid_coordinate(int input)
{
    if (input < 0 || input > 99) // If the coordinate is outside the scope print out an error message and return false
    {
        printf("Invalid coordinate. Please enter a number between 0 and 99! \n");
        return 0;
    }
    return 1; // If the coordinate is valid, return true
}

// Function to validate a move
int valid_move(char input[])
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (!(input[i] == 'm' || input[i] == 't' || input[i] == 'M' || input[i] == 'T')) // If the input does not consist of desired characters (m and t) print out an error message and return false
        {
            printf("Invalid move. You can only use 'm' to advance and/or 't' to turn 90 degrees clockwise");
            return 0;
        }
    }
    return 1; // If the input is valid, return true
}
