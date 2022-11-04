#include<stdio.h>

int divisorsum(num)
{
    int i,sum=0;
    for(i=1;i<=num;i++)
    {
        if(num%i==0)
        sum=sum+i;
        else
        sum=sum+0;
    }

return sum;
}
int main()
{
    printf("This function prints the sum of divisors of a given number\n(Please note that this is not optimal and is applicable only to small numbers)\n");
    int num,result;
    printf("Please enter the number:\n");
    scanf("%d",&num);

    result=divisorsum(num);

    printf("The sum of divisors of the given number is:%d\n",result);
    return 0;
}