#include<stdio.h>
void printminmax(int num1, int num2)
{
    if(num1>num2)
    {
        printf("Maximum is %d\n",num1);
        printf("Minimum is %d\n",num2);
    }
    else
    {
        printf("Maximum is %d\n",num2);
        printf("Minimum is %d\n",num1);
    }
}

int main()
{
    int num1, num2;
    printf("Enter number 1:\n");
    scanf("%d",&num1);
    printf("Enter number 2:\n");
    scanf("%d",&num2);

    printminmax(num1,num2);

    return 0;
}