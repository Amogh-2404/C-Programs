#include<stdio.h>
#include<stdlib.h>
int compare (const void * a, const void * b)
{
  float fa = *(const float*) a;
  float fb = *(const float*) b;
  return (fa > fb) - (fa < fb);     //Combining the 1 and the 0 output of the operatorand returning it as int 1 or -1. Clever.
}

int main(){
    int LEN=0;
    scanf("%d",&LEN);
    float *p=(float*)malloc(sizeof(float)*LEN);
    float *q=(float*)malloc(sizeof(float)*LEN);

    for(int i=0;i<LEN;i++)
    {
        scanf("%f",&p[i]);
    }
    for(int i=1;i<LEN-1;i++)
    {
       q[i]=(p[i-1]+p[i]+p[i+1])/3;
    }
    q[0]=(p[0]+p[1]+p[LEN-1])/3;
    q[LEN-1]=(p[0]+p[LEN-1]+p[LEN-2])/3;

    qsort(q,LEN,sizeof(float),compare);

    for(int i=0;i<LEN;i++)
    {
        printf("%.1f ",q[i]);
    }
printf("\n%.1f\n",q[LEN-1]);
return 0;
}