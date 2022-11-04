#include<stdio.h>
int main()

{
    double A = 10.25;
    double B = 20.97; 
    double temp;
    printf("A= %lf  and B= %lf  \n \n", A,B);
    temp = A ;
     A = B;
     B = temp;
     printf("A= %lf  and B= %lf  \n \n", A,B);
     return 0;
     }