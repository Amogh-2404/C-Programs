//Perfect number is a number which is equal to the sum of its divisors(Not including the number itself).
//This program also is the most optimal way to find the sum of divisors of a number.
#include<stdio.h>

int sumofdivisors(int num)
{
    int i,sum=0;
    for(i=1;i*i<=num;i++)
    {
        if((i*i<num)&&(num%i==0))
        {
         sum = sum + i + (num/i);
        }
        if((i*i==num)&&(num%i==0))
        {
            sum = sum + i;
        }
    }
    sum =sum-num;
    return sum;
}
int main()
{
    int num,output;
    printf("Please enter a number:\n");
    scanf("%d",&num);

   output=sumofdivisors(num);

   printf("Sum of divisors = %d\n",output);

  if(output==num)
   {
    printf("The number entered is a perfect number\n");
   }
   else{printf("The number entered is not a perfect number.\n");}

   return 0;
}