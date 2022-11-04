#include<stdio.h>
int main()
{
    int currentDigit;
    int num;
    int evensum=0 , oddsum=0;
    printf("Enter num: \n");
    scanf("%d",&num);

    while(num>0)
    {
        currentDigit=num%10;
        if(currentDigit%2==0)
           evensum+=currentDigit;
           else
           oddsum+=currentDigit;

        num=num/10;
    }
    printf("Evensum = %d\nOddsum = %d\nEvensum-Oddsum=%d\n",evensum,oddsum,evensum-oddsum);
    return 0;
}