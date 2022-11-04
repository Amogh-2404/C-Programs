#include<stdio.h>
int area(int a, int b)
{
    int Area;
  Area=a*b;
  return Area;
}

int main ()
{
    int h,b;
    int final;
    
    printf("Enter Height:\n");
    scanf("%d",&h);
    printf("Enter Width:\n");
    scanf("%d",&b);

    final=area(h,b);

    printf("Area of rectangle is %d\n",final);

    return 0;

}