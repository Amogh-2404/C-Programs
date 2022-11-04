#include<stdio.h>
int main()
{
    int i;
    int num;
    printf("Please enter the highest number to be printed:\n");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        printf("%d ",i);
    }

    printf("\n");

    for(i=i-1;i>0;i--)//i=i-1 because the previous loop stops after incrementing the value of i to num+1. But we want i to be equal to num for execution of second loop 
    {
        printf("%d ",i);
    }

    return 0;
}