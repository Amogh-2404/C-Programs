#include<stdio.h>

float derivative(float c,float x, float n)
{
    int i;
    float ans=1;
    for(i=1;i<n;i++)
    {
        ans = ans*x;
    }
    ans=c*n*ans;

    return ans;
}
int main()
{
    float c,x,n,result;
    printf("This program calculates the derivative of a single function i.e, cx^n\nPlease enter the value of constant(c):\n");
    scanf("%f",&c);
    printf("Please enter the value of x:\n");
    scanf("%f",&x);
    printf("Please enter the value of n:\n");
    scanf("%f",&n);

    result=derivative(c,x,n);

    printf("The derivative of %.0fx^%.0f for the value of x %f is :\n%f\n",c,n,x,result);
    return 0;
}