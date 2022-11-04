#include<stdio.h>
int main()
{
    int num;
    int i;
    int j=0;
    printf("Enter the number of even numbers to be printed:\n");
    scanf("%d",&num);

    for(i=1;i<=num;i++)//Please be careful about the incrementing step
    {
        j+=2;
        printf("%d ",j);
    }

    printf("\n");
    return 0;
}