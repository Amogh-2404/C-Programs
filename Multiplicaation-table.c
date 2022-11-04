#include<stdio.h>
#define SIZE 11

int main ()
{
    int i,j;
    int mat[SIZE][SIZE];

    //Step1- Fill values in the table.
    for(i=1;i<SIZE;i++)
      for(j=1;j<SIZE;j++)
       mat[i][j]=i*j;

       //Step2-Printing the multiplication table.
       for(i=1;i<SIZE;i++)
       {
        for(j=1;j<SIZE;j++)
          printf("%5d ",mat[i][j]);
        printf("\n");
       }

return 0;
}