#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//A swapping function
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function for finding partition index
int partition(int a[],int l,int h)
{
    //Finding the index of pivot of the given array
    int i=l,j=h;
    int pivot=a[l];           //Considering the first element as the pivot
    do
    {
        do{i++;}while(a[i]<=pivot); //Stops when it finds an element larger than the considered pivot
        do{j--;}while(a[j]>pivot);  //Stops when it finds an element smaller than or equal to the considered pivot
        if (i<j)
           swap(&a[i],&a[j]);      //Swapping the elements found in the loop
    } while (i<j);

    swap(&a[l],&a[j]);            //Swap the considered piviot with the last index obtained
    return j;                     //Returning the pivot index
}

void quicksort(int a[],int l,int h)
{ /*------Performing one pass of bubblesort to move the largest element to the end ------------*/
    static int m = 0;
    if(m==0)
    {
        int y=0;
        for(int z=y+1;z<=h;z++,y++)
        {
           if (a[z]<a[y])
              swap(&a[y],&a[z]);
        }
        m++;
    }
    /*---------------------------------------*/
    if(l<h){
        //Finding the index of partition
        int p = partition(a,l,h);
        //Calling quicksort on both the small partitions recursively
        quicksort(a,l,p);
        quicksort(a,p+1,h);
    }
}

int main(int argc,char *argv[]){
    //Reading from the given File from command line
    FILE *iptr = fopen(argv[1],"r");
    //Counting the number of inputs
    int count = 0;
    int hello = 0;
    while (fscanf(iptr,"%d",&hello)==1) {
        count++;
    }
    
    //Resetting the pointer to point to the beginning again
    rewind(iptr);
    
    //Creating an array of intergers of 'count' length
    int *array = (int *)malloc(sizeof(int)*count);
    
    //Reading all the intergers one by one
    int temp = 0,i=0;
    while (fscanf(iptr,"%d",&temp)==1) {
        array[i++] = temp;
    }
    
    quicksort(array,0,count-1);
    
    //Writing output to a file
    FILE *optr = fopen("quicksort.txt","w");
    for(int k = 0;k<count;k++) {
        fprintf(optr,"%d ",array[k]);
    }
    return 0;
}
