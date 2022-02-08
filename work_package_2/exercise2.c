// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 2
// Exercise 2
// Submission code: enN8B0Bc

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs          ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations   #####

REGTYPE *random_list(void);  //function to create doubly linked lists
REGTYPE *add_first(REGTYPE *temp, int data); //function to add a number to the begining of the list
void *displayList(REGTYPE *act_post, REGTYPE *head); //function to print out linked list

//==========================================================

    // Function to create doubly linked lists while using the MAX amount of items (nodes)
REGTYPE *random_list(void)
{
    int nr, i = 0; //set variables and set them to 0
    REGTYPE *top, *old, *item; //create pointers for REGTYPE
    top = NULL; //set top (head) to null

    for (i = 0; i < MAX; i++) // for loop incrementing i and iterating MAX amount of numbers in the list
    {
        item = (REGTYPE *)malloc(sizeof(REGTYPE)); // Allocate memory for struct item
        item->number = rand() % 100 + 1;  //Generate random numbers between 1-100 https://www.javatpoint.com/random-function-in-c

        if (top == NULL) //see if top is null
        {
            item->prev = NULL; //set prev to null, when top is empty
            item->next = NULL; //set next to null, when top is empty
            top = item;        //set top to item, since it is the first node in list
        }
        else  // if top is not null/empty 
        {
            old = top; // the old pointer is set as current head(top) 
            while (old->next != NULL) //while any node within the list does not equal the last node 
            {
                old = old->next; //the old is set to the nest item(node) in the list
            }
            old->next = item; //set the old item next to the new item in the list
            item->prev = old; //set the new items prev to the old item (the previous node) in the list
        }
    }
    return (top); //return top of the list 
}

//==========================================================
    //function to add item(node) to the begining to the list
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *item = (REGTYPE *)malloc(sizeof(REGTYPE));  // Allocate memory for item

    temp->prev = item; // set the temps previous to the current new node addeded   https://www.youtube.com/watch?v=v4szCPs9yEY
    item->next = temp; // set the current item's(first node) next to the temps node
    item->number = data; // the item's number is set to the data of the node
    return item; // return the first item(head) of the list
}
//==========================================================

    //function to display the linked lists 
void *displayList(REGTYPE *act_post, REGTYPE *head)
{

    int nr = 0; // the counter for the data(nodes) in the list  
    act_post = head; // set position to head 

    while (act_post != NULL) //loop until the postion is not null
    {
        printf("\n Post nr %d : %d", nr++, act_post->number); //display the data(nodes) of the list with current positions
        act_post = act_post->next; //iterate through the list by seting postion to new item 
    }
    printf("\n"); //line break 
}

//###### Main program #######
int main(int argc, char *argv[])
{
    REGTYPE *act_post, *head = NULL;  //initiate pointers 

    srand(time(0)); //   Random seed
    head = random_list(); // function to create linked list 
    displayList(act_post, head); //print and iterate items in linked list

    head = add_first(head, 77); //add new list head, which is 77 to the begining of the list  
    displayList(act_post, head); //print and iterate items in linked list

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}