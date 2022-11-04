#include<stdio.h>
int main()
{
    int i;
    int num;
    int j;

    printf("Please enter the number of steps of the triangle:\n");
    scanf("%d",&num);
    printf("\n");

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
