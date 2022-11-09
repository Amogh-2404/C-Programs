#include<stdio.h>
#define SIZE 5
int main()
{
    int arr[SIZE],i,reallysorted=1;
    printf("Enter %d integers one by one:\n",SIZE);

    for(i=0;i<SIZE;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<SIZE-1;i++)
    {
        if(arr[i+1]<arr[i])
        {reallysorted=0;}
        else if(arr[i+1]==arr[i])
         {reallysorted=0;}
    }

    if(reallysorted == 1)
    {
        printf("The array is really sorted.\n");
    }
    else if(reallysorted == 0)
    {
        printf("The array is not sorted.\n");
    }

    return 0;
}