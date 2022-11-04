#include<stdio.h> 

int main()
{
   //Edit below this line
   int A;
   int B;
   int choice;
   scanf("%d",&A);
   scanf("%d",&B);
   printf("Press\n1 for sum\n 2 for sub\n3 for multiplication\n4 for division(only quotient)\n5 for remainder");
   scanf("%d",&choice);
   
   switch(choice)
  { case 1:
    {printf("sum = %d\n",A+B);
     break;}
   case 2:
     {printf("sub=%d\n",A-B);
     break;}
   case 3:
     {printf("Product=%d\n",A*B);
     break;}
   case 4:
     {printf("Quotient=%0.3lf\n",(double)A/B);
     break;}
     case 5:
     {
      printf("Remainder=%d",A%B);
     }
  }
    return 0; 
}