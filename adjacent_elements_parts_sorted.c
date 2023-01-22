#include<stdio.h>
#include<math.h>
int sort(float *arr,int num)
{
    if (num==1)
    {
        return 1;
    }
    float num1 = *(arr)-floor(*(arr));
    float num2 = *(arr+1)-floor(*(arr+1));
    if((floor(*(arr))<floor(*(arr+1)))&&(num1>num2))
       {
        return sort(arr+1,num-1);
       }
    else
       {
        return 0;
       }
            
}
int main()
{
    int size=0;
    scanf("%d",&size);
    float array[size];
    
    for(int i=0;i<size;i++)
    { 
        scanf("%f",&array[i]);
    }

    int result = sort(array,size);
    printf("\n%d\n",result);

    return 0;
}