#include<stdio.h>
#include<stdlib.h>
int sumofarray(int *arr,int size)
{
    if(size==1)
    {return arr[0];}
    
    int sum = sumofarray((arr+1),size-1);
    return sum+arr[0];
}
int main()
{
    int num=0;
    scanf("%d",&num);
    printf("\n");
    int *ptr=(int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",(ptr+i));
    }
    int result = sumofarray(ptr,num);
    printf("\nThe sum of the elements of the given array is %d\n",result);
    return 0;

}