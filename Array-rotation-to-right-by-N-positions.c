#include<stdio.h>
#define size 5
int main()
{
    int arr[size],i,j;
    printf("Enter %d integers for the number:\n",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Elements of an array: %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);

    int N;
    printf("Enter number of positions to be shifted:\n");
    scanf("%d",&N);
int k;
for(k=1;k <= N;k++)
  { int useless;
   useless=arr[size-1];
   for(j=size-1;j>0;j--)
   {
    arr[j]=arr[j-1];
   }
   arr[0]=useless;
  }

   
   printf("Elements of an array: %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);

   return 0;
}