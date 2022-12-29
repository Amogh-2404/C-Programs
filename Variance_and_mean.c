#include<stdio.h>
int main()
{
    int num[10];
    float mean=0, variance=0;
    printf("Enter 10 numbers:\n");
    for(int i=0;i<10;i++)
    {
       scanf("%d",&num[i]);
    }
   int sum=0;
    for(int j=0;j<10;j++)
    {
        sum += num[j];
    }
    mean = (float)sum/10;
    int snum[10];
    int sum2=0;
    for(int i=0;i<10;i++)
    {
       snum[i] = num[i]*num[i];
       sum2+=snum[i];
    }
    float savg={0};
    savg = (float)sum2/10;
    
    variance = savg - (float)(mean*mean);

    printf("Mean: %0.3f\nVariance: %0.3f\n",mean,variance);
    return 0;
}