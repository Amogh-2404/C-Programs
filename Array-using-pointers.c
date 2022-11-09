#include<stdio.h>
int main()
{
   int arr[3]={1,2,3};
   int *ptr=arr;

    
    printf("%d %d %d\n",arr[0],arr[1],arr[2]);
    ptr[0]=5;
    ptr[1]=6;
    ptr[2]=7;

    printf("%d %d %d\n",arr[0],arr[1],arr[2]);
    

    return 0;
}