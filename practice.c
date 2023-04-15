#include<stdio.h>
#include<stdlib.h>

int binarysearch(int a[],int l,int h, int key)
{
    int mid;

    if (l<=h)
    {
        mid=(l+h)/2;
        if (key==a[mid])
           return mid;
        else if (key<a[mid])
           return binarysearch(a,l,mid-1,key);
        else
           return binarysearch(a,mid+1,h,key);
    }
    return -1;
}

int* arraysIntersection(int* arr1, int arr1Size, int* arr2, int arr2Size, int* arr3, int arr3Size, int* returnSize){
    static int m=0;
    int *res = (int *)malloc(sizeof(int)*(*returnSize));
    for(int k=0;k<arr1Size;k++)
    {
        if ( ((binarysearch(arr1,0,arr1Size-1,arr1[k])>=0) && (binarysearch(arr2,0,arr2Size-1,arr1[k])>=0)) && (binarysearch(arr3,0,arr3Size-1,arr1[k])>=0))
        {res[m++]=arr1[k];
        }
             
    }
    return res;
}

int main()
{
    int a=5,b=6,c=7;
    int *size=NULL;
    int m = 5;
    size = &m;
    int *yo = (int *)malloc(sizeof(int)*5);
    int *hi = (int *)malloc(sizeof(int)*6);
    int *hello = (int *)malloc(sizeof(int)*7);
    for(int k=0;k<5;k++)
    {
        yo[k]=k*2;
    }   
    for(int k=0;k<6;k++)
    {
        hi[k]=k*3;
    } 
    for(int k=0;k<7;k++)
    {
        hello[k]=k*6;
    }  
    int *new = arraysIntersection(yo,5,hi,6,hello,7,size);

    for(int k=0;k<5;k++)
    {
        printf("%d ",yo[k]);
    }   
    printf("\n");
    for(int k=0;k<6;k++)
    {
        printf("%d ",hi[k]);
    } 
    printf("\n");
    for(int k=0;k<7;k++)
    {
        printf("%d ",hello[k]);
    }  
    printf("\n");

    for(int k=0;k<m;k++)
    {
        printf("%d ",new[k]);
    }
    printf("\n");
    return 0;

}