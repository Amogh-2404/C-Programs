#include<stdio.h>
double factorial(int n)
{
    if(n==1)
     return 1;

return n*factorial(n-1);
}
int main()
{
    int num;
    double ans;
    printf("Enter the number whose factorial needs to be printed:\n");
    scanf("%d",&num);
 ans=factorial(num);

 printf("The factorial of %d is %.0lf \n",num,ans);

 return 0;

}