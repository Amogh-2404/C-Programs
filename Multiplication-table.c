#include<stdio.h>
int main()
{
    int num;
    int num2;
    int i;
    printf("Please enter the number whoes multiplication table is required:\n");
    scanf("%d",&num);
    printf("Enter the number upto which table is required:\n");
    scanf("%d",&num2);

    for(i=1;i<=num2;i++)
    {printf("%d * %d = %d\n",num,i,num*i);}

    return 0;
}