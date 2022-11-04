#include<stdio.h>

int main()
{
    double num1 ;
    double num2 ;
    printf("Please enter number 1\n");
    scanf("%lf",&num1);
    printf("Please enter number 2\n");
    scanf("%lf",&num2);
     if(num1>num2)
     printf("Number 1 is greater than number 2\n\n Thank You");
     if(num1<num2)
     printf("Number 2 is greater than number 1\n\n Thank You");

     if(num1==num2)
     printf("Both the numbers are equal\n\n Thank You");
     return 0;
}