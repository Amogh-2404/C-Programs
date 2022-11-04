#include<stdio.h>
int main()
{
    int i;
    int n;
    int sum=0;

    printf("Please enter the number upto which sum of numbers which are divisible by 3 and 5 must be calculated:\n");
    scanf("%d",&n);

   /* for(i=1;i<=n;i++)
    {
        if ((i%3==0)&&(i%5==0))
        {
            sum=sum+i;
        }
        
    }     Trivial solution Optimal is written below . */

    for(i=15;i<=n;i+=15)
    {
        printf("%d is divisible by both 3 and 5\n",i);
        sum=sum+i;
    }


    printf("The sum of numbers divisible by 3 and 5 upto %d numbers is %d\n",n,sum);
    return 0;
}