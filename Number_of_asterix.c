#include<stdio.h>
int main()
{
    int A;
    int i;
    i=1;
    printf("Enter the number of asterix:\n");
    scanf("%d",&A);

    while(i<=A)
    {printf("*");
     i++;
    }
    printf("\n\n");
}