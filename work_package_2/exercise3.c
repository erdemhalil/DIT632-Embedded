// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 2
// Exercise 1
// Submission code: enN8B0Bc

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Functions
void write_new_file(PERSON *inrecord) // Creates a file and writes the first record
{
    FILE *file; // Initiate a file pointer
    // Open or create a new file
    file = fopen("file.bin", "wb");
    // Add the premade user to the file
    fwrite(inrecord, sizeof(PERSON), 1, file);
    // Close the file
    fclose(file);
}

void printfile(void) // Prints out all persons in the file
{
    PERSON *ppost; // Create a person pointer
    FILE *file;    // Create a file pointer
    // Open the file to read from it
    file = fopen("file.bin", "rb");
    // Check if the file exists
    if (file != NULL)
    {
        // Goto the end of the file
        fseek(file, 0, SEEK_END);
        // Check if the position of the last character is 0 aka if the file is empty
        if (ftell(file) == 0)
        {
            // Inform the user
            printf("The file is empty.\n");
        }
        // Go to the beginning of the file to allow it to be read if not empty
        fseek(file, 0, SEEK_SET);
        // Infinite loop to itterate through the while file
        while (1)
        {
            // Read the first name from the file and assign it as the ppost firstname
            fread(&ppost->firstname, sizeof(ppost->firstname), 1, file);
            // Read the last name from the file and assign it as the ppost famname
            fread(&ppost->famname, sizeof(ppost->famname), 1, file);
            // Read the personal number from the file and assign it as the ppost pers_number
            fread(&ppost->pers_number, sizeof(ppost->pers_number), 1, file);
            // Check if the end of the file is reached
            if (feof(file))
            {
                // Break the loop if at the end
                break;
            }
            // Print the person
            printf("First Name = %s, Last Name = %s, Personal Number = %s\n", ppost->firstname, ppost->famname, ppost->pers_number);
        }
    }
    // If the file doesn't exist, inform the user
    else
    {
        printf("The file doesn't exist.\n");
    }
    // Close the file
    fclose(file);
}

void search_by_firstname(char *name) // Prints out the person if in list
{
    PERSON *ppost; // Create a person pointer
    FILE *file;    // Create a file pointer
    // Open the file to read from it
    file = fopen("file.bin", "rb");
    // Check if the file exists
    if (file != NULL)
    {
        // Goto the end of the file
        fseek(file, 0, SEEK_END);
        // Check if the position of the last character is 0 aka if the file is empty
        if (ftell(file) == 0)
        {
            // Inform the user
            printf("The file is empty.\n");
        }
        // Go to the beginning of the file to allow it to be read if not empty
        fseek(file, 0, SEEK_SET);
        // Infinite loop to search through the while file
        while (1)
        {
            // Read the first name from the file and assign it as the ppost firstname
            fread(&ppost->firstname, sizeof(ppost->firstname), 1, file);
            // Read the last name from the file and assign it as the ppost famname
            fread(&ppost->famname, sizeof(ppost->famname), 1, file);
            // Read the personal number from the file and assign it as the ppost pers_number
            fread(&ppost->pers_number, sizeof(ppost->pers_number), 1, file);
            // Check if the end of the file is reached
            if (feof(file))
            {
                // Break the loop if at the end
                break;
            }
            int compare; // Initiate variable to compare the names
            // Check if the name in the file and the name asked for match
            compare = strcmp(ppost->firstname, name);
            // If the names match, print the person
            if (!compare)
            {
                printf("First Name = %s, Last Name = %s, Personal Number = %s\n", ppost->firstname, ppost->famname, ppost->pers_number);
            }
        }
    }
    // If the file doesn't exist, inform the user
    else
    {
        printf("The file doesn't exist.\n");
    }
    // Close the file
    fclose(file);
}

void search_by_lastname(char *name) // Prints out the person if in list
{
    PERSON *ppost; // Create a person pointer
    FILE *file;    // Create a file pointer
    // Open the file to read from it
    file = fopen("file.bin", "rb");
    // Check if the file exists
    if (file != NULL)
    {
        // Goto the end of the file
        fseek(file, 0, SEEK_END);
        // Check if the position of the last character is 0 aka if the file is empty
        if (ftell(file) == 0)
        {
            // Inform the user
            printf("The file is empty.\n");
        }
        // Go to the beginning of the file to allow it to be read if not empty
        fseek(file, 0, SEEK_SET);
        // Infinite loop to search through the while file
        while (1)
        {
            // Read the first name from the file and assign it as the ppost firstname
            fread(&ppost->firstname, sizeof(ppost->firstname), 1, file);
            // Read the last name from the file and assign it as the ppost famname
            fread(&ppost->famname, sizeof(ppost->famname), 1, file);
            // Read the personal number from the file and assign it as the ppost pers_number
            fread(&ppost->pers_number, sizeof(ppost->pers_number), 1, file);
            // Check if the end of the file is reached
            if (feof(file))
            {
                // Break the loop if at the end
                break;
            }
            int compare; // Initiate variable to compare the names
            // Check if the name in the file and the name asked for match
            compare = strcmp(ppost->famname, name);
            // If the names match, print the person
            if (!compare)
            {
                printf("First Name = %s, Last Name = %s, Personal Number = %s\n", ppost->firstname, ppost->famname, ppost->pers_number);
            }
        }
    }
    // If the file doesn't exist, inform the user
    else
    {
        printf("The file doesn't exist.\n");
    }
    // Close the file
    fclose(file);
}

void append_file(PERSON *inrecord) // appends a new person to the file
{
    FILE *file; // Create a person pointer
    // Open the file to append a person
    file = fopen("file.bin", "ab");
    // Check if the file exists
    if (file != NULL)
    {
        // Add the person to the end of the file
        fwrite(inrecord, sizeof(PERSON), 1, file);
    }
    // If the person doens't exist, inform the user
    else
    {
        printf("The file doesn't exist.\n");
    }
    // Close the file
    fclose(file);
}

int main(void)
{
    int num = 1;  // Initiate an integer
    PERSON ppost; // Initiate a person variable
    // Run as long as the number entered is between 1 and 4
    while (num < 5 && num > 0)
    {
        // Print the possible choises
        printf("\n1 Create a new and delete the old file. \n");
        printf("2 Add a new person to the file. \n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file. \n");
        printf("5 Exit the program. \n\n");
        // Get the user input
        scanf("%d", &num);
        // Switch based on the input
        switch (num)
        {
        case 1:
            // Create a first person to be added to the file
            strcpy(ppost.firstname, "Sven");
            strcpy(ppost.famname, "Svensson");
            strcpy(ppost.pers_number, "190005124432");
            // Call the function
            write_new_file(&ppost);
            break;
        case 2:
            // Ask the user for a first name
            printf("Please input the first name. \n");
            // get the first name
            scanf("%s", &ppost.firstname);
            // Ask the user for a last name
            printf("Please input the last name. \n");
            // Get the last name
            scanf("%s", &ppost.famname);
            // Ask the user for a personal number
            printf("Please input the personal number. \n");
            // Get the personal numeber
            scanf("%s", &ppost.pers_number);
            // Call the function
            append_file(&ppost);
            break;
        case 3:
            // Ask the user to choose a method of search
            printf("Choose '1' to search by the first name and '2' to search with the last name. \n");
            int choise; // Initiate integer for user choise
            // Get the use input
            scanf("%d", &choise);
            // If the use chose to search by the first name
            if (choise == 1)
            {
                char fName[20]; // Initiate string for user unput
                // Ask the user for name
                printf("Please enter the first name. \n");
                // Get user name
                scanf("%s", &fName);
                // Call the function
                search_by_firstname(fName);
            }
            else if (choise == 2)
            {
                char lName[20]; // Initiate string for user unput
                // Ask the user for name
                printf("Please enter the last name. \n");
                // Get user name
                scanf("%s", &lName);
                // Call the function
                search_by_lastname(lName);
            }
            // Inform the user if they made a bad choise
            else
            {
                printf("Invalid input.\n");
            }
            break;
        case 4:
            // Call the function
            printfile();
            break;
        default:
            return 0;
            break;
        }
    }

    return (0);
}
