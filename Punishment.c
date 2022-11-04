#include<stdio.h>
int main()
{
    int i;
    int rep;
    printf("Enter the number of times punishment message should be printed:\n");
    scanf("%d",&rep);
    for(i=1;i<=rep;i++)
    {
        printf("I'm sorry for not listening to *My Teacher*.I will practice more next time!\n");
    }

    return 0;
}