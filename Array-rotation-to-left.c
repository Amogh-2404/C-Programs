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

   int useless;
   useless=arr[0];
   for(j=0;j<size-1;j++)
   {
    arr[j]=arr[j+1];
   }
   arr[size-1]=useless;
   
   printf("Elements of an array: %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);

   return 0;
}