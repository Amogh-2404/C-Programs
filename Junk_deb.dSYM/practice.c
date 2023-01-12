#include<stdio.h>
int main()
{
    int arr[7];
    int count =0;
    int max = arr[0];
    for(int k=0;k<7;k++){
        scanf("%d",&arr[k]);
    }
    for(int i=0;i<7;i++)
    {
      if(arr[i]>=max)
      {
        max=arr[i];
      }

    }
    for(int j=0;j<7;j++)
    {
        if (max==arr[j])
        {
            count++;
        }
    }
    printf("%d %d",max,count);
    return 0;
}
