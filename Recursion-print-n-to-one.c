#include<stdio.h>
void printnum(int n)
{
    if(n>0) // Will print in reverse.
    {
    printf("%d ",n);
    printnum(n-1);
    }

}
int main()
{
    int num,dummy;
    printf("Enter a number:\n");
    scanf("%d",&num);

    printnum(num);

    return 0;

}