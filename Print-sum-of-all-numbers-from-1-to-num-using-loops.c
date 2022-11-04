#include<stdio.h>
int main()
{
    int num;
    int i;
    int sum=0;

    printf("Please enter the number upto which the sum needs to be calculated:\n");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        sum=sum+i;
    }

    printf("The sum of first %d natural numbers is equal to %d\n",num,sum);
    return 0;
}