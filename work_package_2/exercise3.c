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

// Function declaration (to be extend)
PERSON input_record(void); // Reads a person’s record.

void write_new_file(PERSON *inrecord) // Creates a file and writes the first record
{
    FILE *file;
    file = fopen("file.bin", "wb");
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}

void printfile(void) // Prints out all persons in the file
{
    PERSON *ppost;
    FILE *file;
    file = fopen("file.bin", "rb");
    while (1)
    {
        fread(&ppost->firstname, sizeof(ppost->firstname), 1, file);
        fread(&ppost->famname, sizeof(ppost->famname), 1, file);
        fread(&ppost->pers_number, sizeof(ppost->pers_number), 1, file);
        if (feof(file))
        {
            break;
        }
        printf("First Name = %s, Last Name = %s, Personal Number = %s\n", ppost->firstname, ppost->famname, ppost->pers_number);
    }
    // close file
    fclose(file);
}

void search_by_firstname(char *name); // Prints out the person if in list

void append_file(PERSON *inrecord) // appends a new person to the file
{
    FILE *file;
    file = fopen("file.bin", "ab");
    fwrite(inrecord, sizeof(PERSON), 1, file);
    fclose(file);
}

int main(void)
{
    int num;

    PERSON ppost;
    while (num < 5)
    {
        printf("\n1 Create a new and delete the old file. \n");
        printf("2 Add a new person to the file. \n");
        printf("3 Search for a person in the file. \n");
        printf("4 Print out all in the file. \n");
        printf("5 Exit the program. \n\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            strcpy(ppost.firstname, "Sven");
            strcpy(ppost.famname, "Svensson");
            strcpy(ppost.pers_number, "190005124432");
            write_new_file(&ppost);
            break;
        case 2:
            printf("Please input the first name. \n");
            char fName[20];
            scanf("%s", &fName);
            printf("Please input the last name. \n");
            char lName[20];
            scanf("%s", &lName);
            printf("Please input the personal number. \n");
            char pNum[13];
            scanf("%s", &pNum);

            strcpy(ppost.firstname, fName);
            strcpy(ppost.famname, lName);
            strcpy(ppost.pers_number, pNum);
            append_file(&ppost);
            break;
        case 3:
            /* code */
            break;
        case 4:
            printfile();
            break;
        default:
            return 0;
            break;
        }
    }

    return (0);
}
