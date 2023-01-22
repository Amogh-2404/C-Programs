#include<stdio.h>
#include<stdlib.h>
void createarray(int **p,int n)
{
    *p=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",(*p+i));
    }
}
int main()
{
    int num =0;
    scanf("%d",&num);
    int *ptr = NULL;
    createarray(&ptr,num);
    
    for(int i=0;i<num;i++)
    {
        printf("%d ",*(ptr+i));
    }
    printf("\n");
    return 0;
}