// The porpus reads  in  an  integer  number  between  1  and  5  from  the  keyboard  and  prints  out  one  of
// existing five sentences on the console depending on what number was entered
// (C) Taofik Arnouk, Erdem Halil, Vlad Liteanu, group: 8 (2022)
// Work package 1
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

//Include section
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double number = 999;
    int size = floor(log2(number)) + 1;
    printf("%f\n", number);
    char rest[size];
    for (int i = 0; i < size; i++)
    {
        number = number / 2;
        if (ceilf(number) == number)
        {
            rest[i] = 0;
        }
        else if (ceilf(number) != number)
        {
            rest[i] = 1;
            if (number != 0)
            {
                number = ceilf(number) - 1;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d", rest[size - 1 - i]);
    }

    return 0;
}
