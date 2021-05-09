#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "isort.h"
#define datacnt 100000

int *isortd(int *number)
{
    int i;
    int j;
    int key;

    for(i = 1; i < datacnt; i++)
    {
        key = number[i];
        j = i - 1;
        while(j >= 0 && number[j] > key)
        {
            number[j + 1] = number[j];
            j --;
        }
        number[j + 1] = key;
    }
    return number;
}

char **isorts(char **word)
{
    int i;
    int j;
    char *save = malloc(sizeof(char)*101);

    for(i = 1; i < datacnt; i++)
    {
        strcpy(save, *(word+i));
        j = i - 1;
        while(j >= 0 && strcmp(*(word+j), save) > 0)
        {
            strcpy(*(word+j+1), *(word+j));
            j --;
        }
        strcpy(*(word+j+1), save);
    }
    free(save);
    return word;
}
