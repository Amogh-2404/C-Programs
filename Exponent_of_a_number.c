#include<stdio.h>
int main()
{
    int num;
    int pow;
    int result=1;
    printf("Enter the number:\n");
    scanf("%d",&num);
    printf("Enter the power that needs to be calculated:\n");
    scanf("%d",&pow);

    while(pow>0)
    {
        result = result * num ;
        pow--;
    }
    printf("The required number is %d\n",result);

    return 0;

}