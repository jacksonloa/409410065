#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ssort.h"
#define datacnt 100000

int *ssortd(int  *number)
{
    int i;
    int j;
    int min;
    int x;

    for(i = 0; i < datacnt; i ++)
    {
        min = i;
        for(j = i + 1; j < datacnt; j ++)
        {
            if(number[j] < number[min])
            {
                min = j;
            }
        }  
        x = number[i];
        number[i] = number[min];
        number[min] = x;
    }
    return number;
}

char **ssorts(char **word1)
{
    int i;
    int j;
    int min;
    char *save = malloc(sizeof(char)*101);

    for(i = 0; i < datacnt; i ++)
    {
        min = i;
        for(j = i + 1; j < datacnt; j ++)
        {
            if(strcmp(*(word1+j), *(word1+min)) < 0)
            {
                min = j;
            }
        }  
        strcpy(save, *(word1+i));
        strcpy(*(word1+i), *(word1+min));
        strcpy(*(word1+min), save);
    }
    free(save);
    return word1;
}