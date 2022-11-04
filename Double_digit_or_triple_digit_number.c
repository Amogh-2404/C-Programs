#include<stdio.h>
int main()
{
    int A;
    printf("Enter a number: \n");
    scanf("%d",&A);
    if(10<=A && A<=99)
    printf("It is a two digit number\n");
    if(100<=A && A<=999)
    printf("It is a three digit number\n");
    if(A<10 || A>999)
    printf("Neither double nor triple\n");

    return 0;
}