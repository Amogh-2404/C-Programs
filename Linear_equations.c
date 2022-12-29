#include<stdio.h>
int main()
{
    int a,b,c,d,e,f;
    int x,y;
    printf("Enter the linear equations to be solved in the form ax+by+c=0 and dx+ey+f=0\nInput the values of a,b,c,d,e and f\n");
    printf("Enter a:\n");
    scanf("%d",&a);
    printf("Enter b:\n");
    scanf("%d",&b);
    printf("Enter c:\n");
    scanf("%d",&c);
    printf("Enter d:\n");
    scanf("%d",&d);
    printf("Enter e:\n");
    scanf("%d",&e);
    printf("Enter f:\n");
    scanf("%d",&f);

    if ((a/d == b/e)&&(b/e != c/f))
    {printf("No solutions for the given equation.\n");}
    else if ((a/d == b/e)&&(b/e == c/f))
    {
        printf("Given equations have infinitely many solutions.\n");
    }
    else if (a==d)
    {
      y = (f-c)/(b-e);
      x = (-(c-b*y))/a ;
    }
    else if (b == e)
    {
      x = (f-c)/(a-d);
      y = (-(c+a*x))/b ;
    }
    else
    {
        x=((f*b)-(e*c))/((a*e)-(d*b));
        y = (-(c+a*x))/b;
    }
    

    return 0;


}