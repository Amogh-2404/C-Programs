#include<stdio.h>
#define size 7
float hottest(float temp [])
{
    int j;
    float z=temp[0];
    for(j=0;j<size;j++)
    {
      if(temp[j]>z)
      z=temp[j];
    }
    return z;
}

float coldest(float temp[])
{
    int k;
    float x=temp[0];
    for(k=0;k<size;k++)
    {
      if(temp[k]<x)
      x=temp[k];
    }
    return x;
}
int main()
{
    printf("Welcome to Weather Station v2.0.\nPlease enter the temperature of last 7 days one by one.\n\n");
    float temp[7];
    float avg,result=0,hot,cold;
    printf("Please enter the temperature of day 1\n");
    scanf("%f",&temp[0]);
    printf("Please enter the temperature of day 2\n");
    scanf("%f",&temp[1]);
    printf("Please enter the temperature of day 3\n");
    scanf("%f",&temp[2]);
    printf("Please enter the temperature of day 4\n");
    scanf("%f",&temp[3]);
    printf("Please enter the temperature of day 5\n");
    scanf("%f",&temp[4]);
    printf("Please enter the temperature of day 6\n");
    scanf("%f",&temp[5]);
    printf("Please enter the temperature of day 7\n");
    scanf("%f",&temp[6]);

int i;
    for(i=0;i<size;i++)
    {
       result=result+temp[i];
    }
    avg=result/7;
    printf("Average temperature of 7 days = %f \n\n",avg);

    hot=hottest(temp);
    int dayh=0;
    for(i=0;i<size;i++)
    {
        if(temp[i]==hot)
        dayh=i+1;
    }
    printf("Hottest day of the week is Day %d\n\n",dayh);

    cold=coldest(temp);
    int dayc=0;
    for(i=0;i<size;i++)
    {
        if(temp[i]==cold)
        dayc=i+1;
    }
    printf("The coldest day of the week is Day %d\n\n",dayc);

    return 0;

}
