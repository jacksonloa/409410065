#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include "bsort.h"
#include "ssort.h"
#include "isort.h"
#define datacnt 1000000

int number[datacnt];
char **word;

int main()
{
    FILE *xfile;
    FILE *yfile;
    FILE *afile;
    FILE *bfile;
    struct timeval start;//起始點
	struct timeval end;//結束點
	unsigned long diff;//儲存計算的時間差

    int i, j;
    int *data = malloc(sizeof(int)*datacnt);
    char **data2 = malloc(sizeof(char *)*datacnt);
    word = malloc(sizeof(char *)*datacnt);
    if(!word)
    {
        printf("erro\n");
    }
    srand(10);

    xfile = fopen("dataset1.txt", "w");
    for(i = 0; i < datacnt; i ++)
    {
        *(data+i) = (rand()%10000) + 1;
    }
    for(i = 0; i < datacnt; i ++)
    {
        fprintf(xfile, "%d\n", *(data+i));
    }
    fclose(xfile);//

    yfile = fopen("dataset1.txt", "r");
    FILE *ifile = yfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(ifile,"%d", &number[i]);
    }

    afile = fopen("dataset2.txt", "w");
    for(i = 0; i < datacnt; i ++)
    {
        *(data2+i) = malloc(sizeof(char)*101);
        for(j = 0; j < 100; j ++)
        {
            *(*(data2+i)+j) = rand()%26 + 'a';
        }
    }
    for(i = 0; i < datacnt; i ++)
    {
        fprintf(afile, "%s\n", *(data2+i));
        free(*(data2+i));
    }
    fclose(afile);

    bfile = fopen("dataset2.txt", "r");
    FILE *jfile = bfile;
    for(i = 0; i < datacnt; i ++)
    {
        *(word+i) = malloc(sizeof(char)*101);
        fscanf(jfile, "%s", *(word+i));
    }

    gettimeofday(&start, NULL);//開始
    bsortd(number);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("%f sec\n", diff / 1000000.0);//印出結果

    gettimeofday(&start, NULL);//開始
    bsorts(word);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("%f sec\n", diff / 1000000.0);//印出結果
    fclose(yfile);

    yfile = fopen("dataset1.txt", "r");
    ifile = yfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(ifile,"%d", &number[i]);
    }
    fclose(bfile);

    bfile = fopen("dataset2.txt", "r");
    jfile = bfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(jfile, "%s", *(word+i));
    }
    gettimeofday(&start, NULL);//開始
    ssortd(number);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("%f sec\n", diff / 1000000.0);//印出結果

    gettimeofday(&start, NULL);//開始
    ssorts(word);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("%f sec\n", diff / 1000000.0);//印出結果
    fclose(yfile);

    yfile = fopen("dataset1.txt", "r");
    ifile = yfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(ifile,"%d", &number[i]);
    }
    fclose(bfile);
    
    bfile = fopen("dataset2.txt", "r");
    jfile = bfile;
    for(i = 0; i < datacnt; i ++)
    {
        fscanf(jfile, "%s", *(word+i));
    }
    
    gettimeofday(&start, NULL);//開始
    isortd(number);
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("%f sec\n", diff / 1000000.0);//印出結果

    gettimeofday(&start, NULL);//開始
    isorts(word); 
    gettimeofday(&end, NULL);//結束
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//實際時間差
	printf("%f sec\n", diff / 1000000.0);//印出結果

    for(i = 0; i < datacnt; i ++)
    {
        free(*(word+i));
    }
    
    fclose(yfile);
    fclose(bfile);
    fclose(ifile);
    fclose(jfile);
    free(data);
    free(data2);
    free(word);
    return 0;
}
