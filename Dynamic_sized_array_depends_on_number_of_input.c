#include<stdio.h>
#include<stdlib.h>
int *adjustablereallocation(int *arrsize)
{
    int num,lastindex=0,size=2;
    int*arr=NULL;
    int*temp=NULL;
    printf("Enter num:");
    scanf("%d",&num);

    if(num == -1)
    {
      return NULL;
    }
    else 
    {  temp = (int*)malloc(size*sizeof(int));
      if(!temp) return NULL;
      arr=temp;
    }

    while(num!=-1)
    {
        if(lastindex==size)
        {
            size+=1;
            temp=(int*)realloc(arr,size*sizeof(int));
            if(!temp) return NULL;
            arr=temp;
        }
        arr[lastindex]=num;
        lastindex++;
        printf("Enter num:");
        scanf("%d",&num);
    }
*arrsize=size;
return arr;
}
int main()
{
    int sizea =0;
    int *p =NULL;
    p=&sizea;
   int *r=adjustablereallocation(p);
   for(int i=0;i<sizea;i++)
   {
    printf("%d ",r[i]);
   }
   printf("\n");
   return 0;
}