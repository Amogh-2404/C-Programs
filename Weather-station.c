#include<stdio.h>

int main()
{
   double F,C ;
   printf("Temperature in °F :  \n") ;
   scanf("%lf", &F) ;
    C=((F-32)/1.8) ;
    printf("Temperature in °C :%lf  \n", C);

   return 0;

}