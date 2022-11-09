#include<stdio.h>
int digitsum(int n)
{
    if(n<=9)
      return n;

return (n%10)+digitsum(n/10);
    
}
int main()
{
    int num;
    int ans;
    printf("Enter an integer:\n");
    scanf("%d",&num);

    ans=digitsum(num);

    if(ans%2==0)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }

    return 0;
}
