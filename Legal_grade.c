#include<stdio.h>
int main()
{
    int g;
    do
    {
       printf("Please enter a valid grade\n");
       scanf("%d",&g);
       if((g>=0)&&(g<=100))
          printf("Thanks! You've inserted %d, which is a legit grade!\n",g);
    } while ((g<0)||(g>100));
    
    return 0;
}