#include<stdio.h>
int main()
{
    int A;
    
    printf("Please enter a number\n");
    scanf("%d",&A);
    if(A%2==0)
    printf("The given number is Even\n");
    else
    printf("The given number is Odd\n");

    return 0;
}