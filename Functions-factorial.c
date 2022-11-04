#include<stdio.h>
int factorial(n)
{
  int i,fact=1;
  for(i=1;i<=n;i++)
  {
    fact=fact*i;
  }
  
 return fact;

}
int main()
{
    int n,result;
    printf("Enter the number whoes factorial is to be calculated:\n");
    scanf("%d",&n);

    result=factorial(n);
    printf("The factorial of %d is %d\n",n,result);

    return 0;

}