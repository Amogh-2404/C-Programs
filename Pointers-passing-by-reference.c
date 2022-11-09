#include<stdio.h>
void findmaxmin(int num1 , int num2,int *pMax,int *pMin)
{
  if(num1>num2)
  {
    *pMax=num1;
    *pMin=num2;
  }
  else
  {
    *pMax=num2;
    *pMin=num1;
  }
}
int main()
{
    int a,b,max,min;
    printf("Enter number 1:\n");
    scanf("%d",&a);
    printf("Enter number 2:\n");
    scanf("%d",&b);
    findmaxmin(a,b,&max,&min);

    printf("Maximum between %d and %d is %d\n",a,b,max);
    printf("Minimum between %d and %d is %d\n",a,b,min);
}