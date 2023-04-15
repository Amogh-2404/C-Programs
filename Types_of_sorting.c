#include<stdio.h>
#include<stdbool.h> // Header-file for boolean data-type.


void swap(int *i,int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}

void display(const int arr[],size_t n)
{
    for(int k=0;k<n;k++)
    {
        printf("%d ",arr[k]);
    }
    printf("\n");
}

void bubblesort(int a[],int n)
{
    
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        bool flag = false;
        for(j=i;j<n;j++)
        {
            if (a[i]>a[j])
               swap(&a[i],&a[j]);
               flag=true;
            
        }
        if(flag==false)
        {
            return;
        }
    }
}

void insertionsort(int a[],int n)
{
    int i,j,x;
    for(i=0;i<n;i++)
    {
       j=i-1;
       x=a[i];
       while(j>-1 && x<a[j])
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=x;
    }
}

void selectionsort(int a[],int n)
{
   int i,j,k;
   for (i=0;i<n;i++)
   {
    for(k=j=i;j<n;j++)
    {
        if (a[j]<a[k])
          k=j;
    }
    swap(&a[k],&a[i]);
   }
}

/*-----------------------------------------------------------------------------------------------------------------------
-------------------------------------------------QUICKSORT---------------------------------------------------------------*/
int partition(int a[],int l,int h)
{
    int i=l,j=h;
    int pivot=a[l];
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if (i<j)
           swap(&a[i],&a[j]);
    } while (i<j);

    swap(&a[l],&a[j]);
    return j; 
}

void quicksort(int a[],int l,int h)
{   static int m = 0;
    if(m==0)
    { 
        int y=0;
        for(int z=y+1;z<=h;z++,y++)
        {
           if (a[z]<a[y])
              swap(&a[y],&a[z]);
        }
    }
    if(l<h){
        int p = partition(a,l,h);
        quicksort(a,l,p);
        quicksort(a,p+1,h);
    }
}
/*-----------------------------------------------------------------------------------------------------------------------*/

void shellsort(int a[],int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=a[i];
            j=i-gap;
            while(j>=0 && a[j]>temp)
            {
                a[j+gap]=a[j];
                j= j - gap;
            }
            a[j+gap]=temp;
        }
    }
}

int main()
{
    int  A[]={100,20,3920,40,11};
    int n = sizeof(A)/sizeof(int);
    sort(A);
    display(A,n);
    printf("\n");
    return 0;
}