#include<stdio.h>

int main()
 { int hours;
   double salary;
    printf("This program calculates the total amount of salary for the given amount of hours\n\n");
    printf("Enter the salary per hour :  \n");
    scanf("%lf", &salary);
    printf("Enter the total hours worked in the month : \n");
    scanf("%d",&hours);
    double total;
    total = (salary*hours);
    printf("Salary for the month :%.2lf \n\n ", total);
    printf("Units are the same as that of the salay per hour\n\n");
    return 0;
     }