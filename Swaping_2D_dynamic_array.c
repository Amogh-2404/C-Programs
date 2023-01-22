#include<stdio.h>
#include<stdlib.h>

int rows=0, columns=0;

void swaprow(int **ptr,int r)
{
   int i = r;
   int *temp=NULL;
   for(i=r;i>0;i--)
   {temp=ptr[(rows-1)-i];
   ptr[(rows-1)-r]=ptr[i];
   ptr[i] = temp;}
   
   
}

void swapcolums(int **ptr,int c1,int c2,int r)
{
    int temp=0;
    for(int i=0;i<r;i++)
    {
        temp = ptr[i][c1];
        ptr[i][c1]=ptr[i][c2];
        ptr[i][c2] = temp;
    }
    
}

int main()
{
   
    printf("Enter the number of rows:\n");
    scanf("%d",&rows);

    int **arr=(int**)malloc(rows*sizeof(int*));
    printf("\nRows sucessfully allocated\n");
    printf("Enter number of columns:\n");
    scanf("%d",&columns);
    for(int i=0;i<rows;i++)
    {
        arr[i]=(int*)malloc(sizeof(int)*columns);
    }
    printf("\nColumns sucessfully allocated\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    printf("Before the swap\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%10d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    swaprow(arr,rows-1);
    swapcolums(arr,0,1,rows);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            printf("%10d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i =0;i<rows;i++)
    {
        free(arr[i]);
    }
    free(arr);
    printf("Wooo! Memory freed.\n");

    return 0;
}