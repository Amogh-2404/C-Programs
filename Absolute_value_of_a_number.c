#include<stdio.h>
int main()
{
    int A;
    printf("Enter a number: \n");
    scanf("%d",&A);

    if(A>=0)
    printf("The absolute value of A is %d\n",A);
    if(A<0)
    printf("The absolute value of A is %d\n",-A);

    return 0;
}
