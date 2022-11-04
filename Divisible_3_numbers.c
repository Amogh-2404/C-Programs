#include<stdio.h>
int main()
{
    int A,B,C;
    printf("Please enter the first number: \n");
    scanf("%d",&A);
    printf("Please enter the second number: \n");
    scanf("%d",&B);
    printf("Please enter the third number: \n");
    scanf("%d",&C);
    if((A==0) || (B==0) || (C==0))
    printf("Cannot divide by 0! Check your input once again.\n");

    if((A%B==0 || B%A==0) && (B%C==0 || C%B==0) && (C%A==0 || A%C==0))
    printf("Divisible\n");
    else
    printf("Not-divisible\n");

    return 0;
}