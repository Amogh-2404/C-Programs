#include<stdio.h> 
#include<math.h> 
#include<stdlib.h>//Very important logic used.
#define size 4
int main()
{
    int i,j;
    int values[size]={-1,2,3,-6};
    int minsum = values[0] + values[1];
    int currentsum;

    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            currentsum = values[i] + values[j];
            if(abs(currentsum)<abs(minsum)) //Most important step. abs means the absolute value of the function.
               minsum = currentsum;
        }
    }
    
printf("The sum closest to 0: %d\n",minsum);
return 0;
}
