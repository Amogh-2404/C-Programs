#include<stdio.h>
void twodigits(N)
{
   int ones;
   int tens;
   ones = N%10;
   tens = N/10;

    printf("The digit in the once place is %d\nThe digit in the tens place is %d\n",ones,tens);
}
int main()
{
    int num;
    do
    {
       printf("Please enter a two digit number:\n");
       scanf("%d",&num);
    } while ((num<10)||(num>99));
    
    twodigits(num);
return 0;
   
}