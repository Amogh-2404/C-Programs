#include<stdio.h>
void printnum(int n)
{
    if(n>0) // Will print in reverse.
    {
    printnum(n-1);     //Order of these two lines matter.
    printf("%d ",n);
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