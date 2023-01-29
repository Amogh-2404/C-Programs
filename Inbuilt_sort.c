#include<stdio.h>
#include<stdlib.h>
#define SIZE 25
int compare(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
int array[SIZE]={1,3,21,41,4,1,51,51,4441,41,41,41,1,41,4,6,43,456,6,3,475,633,2,21,14};
//char array[SIZE] = {'a','c','b','e','d'};
for (int i=0;i<sizeof(array)/sizeof(int);i++)
{
    printf("%d ",array[i]);
}

qsort(array,SIZE,sizeof(int),compare);
printf("\nAfter sorting\n");
for (int i=0;i<sizeof(array)/sizeof(int);i++)
{
    printf("%d ",array[i]);
}
printf("\n");
return 0;
}