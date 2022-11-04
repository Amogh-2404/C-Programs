#include<stdio.h>
int main()
{
    int num;
    int pow;
    int result=1;
    int i;
    printf("Please enter the number:\n");
    scanf("%d",&num);
    printf("Please enter the power\n");
    scanf("%d",&pow);

    for(i=1;i<=pow;i++)
    {
        result=result*num;
    }
    printf("The answer is %d\n",result);
    return 0;

}