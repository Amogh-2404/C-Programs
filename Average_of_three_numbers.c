#include<stdio.h>

int main()
 {  int A,B,C;
   printf("Enter grade A : ");
   scanf("%d" ,&A);
   printf("Enter grade B : ");
   scanf("%d", &B);
   printf("Enter grade C : ");
   scanf("%d", &C);

   double average;
   average=(((double)A + B + C)/3) ;

   printf("Average grade = %lf",average);
   return 0;

 }