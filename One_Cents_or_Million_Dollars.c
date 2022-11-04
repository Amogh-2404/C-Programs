#include<stdio.h>
int main()
{
    int i;
    double money=0.01;//0.01 dollars
    int days;
    printf("Please enter the number of days of investment:\n");
    scanf("%d",&days);
    for(i=1;i<=days;i++)//money doubles everyday
    {
        printf("Day=%d : Amount=%.3lf\n",i,money);
        money=money*2;
    
    }
    
    printf("The amount after given number of days will be\n%.3lf\n",money);
    return 0;
}