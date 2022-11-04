#include<stdio.h> 


int main()
{
   //Edit below this line
   float weight;
   float height;
   float BMI;
  
   scanf("%f", &weight);
   scanf("%f", &height);
   BMI=((double)weight/((double)height*height/10000.00));
   
     if(BMI > 25)
     {
     printf("BMI=%f\n",BMI);
     printf("Overweight");
     }
     else if(BMI >= 19 || BMI <= 25)
     {
     printf("BMI=%f\n",BMI);
     printf("Normal");
     }
     else if(BMI < 19)
     {
     printf("BMI=%f\n",BMI);
     printf("Lean");
     }

    return 0; 
}