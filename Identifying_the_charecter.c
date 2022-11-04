#include<stdio.h>
int main()
{
    char A;
    int D;
    printf("Please enter a charecter\n");
    scanf("%c",&A);
    if(A >= 'A' && A <= 'Z')
    printf("It's a uppercase\n");
    else if(A >='a' && A <='z')
    printf("It's a lowercase\n");
    else if(A >= '0' && A <= '9')
    printf("It's a digit\n");
    else
    printf("Other\n");

    return 0;

}