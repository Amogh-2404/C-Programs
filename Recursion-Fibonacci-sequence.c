#include<stdio.h>
int fibonacci(int n)
{
    if(n==0)
       {return 0;}
    if(n==1)
       {return 1;}
   
    

    return fibonacci(n-1) + fibonacci(n-2);
}
int main()
{
    int num,ans;
    printf("Enter the index whose Fibonacci value needs to be calculated:\n");
    scanf("%d",&num);

    ans=fibonacci(num);

    printf("The value of the index %d is %d\n",num,ans);

    return 0;
}