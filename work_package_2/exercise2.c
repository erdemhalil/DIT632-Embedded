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

REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
void *displayList(REGTYPE *act_post, REGTYPE *head);

// create random list using MAX

REGTYPE *random_list(void)
{
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    top = NULL; //the head is empty

    for (i = 0; i < MAX; i++)
    {
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        item->number = rand() % 100 + 1;  //Generate random numbers https://www.javatpoint.com/random-function-in-c

        if (top == NULL)
        {
            item->prev = NULL;
            item->next = NULL;
            top = item;
        }
        else
        {
            old = top;
            while (old->next != NULL)
            {
                old = old->next;
            }
            old->next = item;
            item->prev = old;
        }
    }
    return (top);
}

//==========================================================
//asumption that the list is not emty, we are going to add a node
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *item = (REGTYPE *)malloc(sizeof(REGTYPE));

    temp->prev = item;
    item->next = temp;
    item->number = data;
    return item;
}
//==========================================================

void *displayList(REGTYPE *act_post, REGTYPE *head)
{

    int nr = 0;
    act_post = head;

    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }
    printf("\n");
}

//###### Main program #######
int main(int argc, char *argv[])
{
    REGTYPE *act_post, *head = NULL;

    srand(time(0)); //   Random seed
    head = random_list();
    displayList(act_post, head);

    head = add_first(head, 77);
    displayList(act_post, head);

    // --- Free the allocated memory  ---

    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }

    return 0;
}