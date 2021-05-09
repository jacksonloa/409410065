#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bsort.h"
#define datacnt 100000

int *bsortd(int *number)
{
    int i;
    int j;
    int x;
 
    for (i = 0; i < datacnt; i ++)
    {
        /*if(i>9990)
            printf("%d\n", i);*/
        for (j = 0; j < datacnt - i - 1; j ++)
        {
            if (number[j] > number[j+1])
            {
                x = number[j];
                number[j] = number[j + 1];
                number[j + 1] = x;
            }
        }
    }
    return number;
}

char **bsorts(char **word)
{
    int i;
    int j;
    char *save = malloc(sizeof(char)*101);

    for (i = 0; i < datacnt; i ++)
    {
        for (j = 0; j < datacnt - i - 1; j ++)
        {
            if (strcmp(*(word+j), *(word+j+1)) > 0)
            {
                strcpy(save, *(word+j));
                strcpy(*(word+j), *(word+j+1));
                strcpy(*(word+j+1), save);
            }
        }
    }
    free(save);
    return word;
}