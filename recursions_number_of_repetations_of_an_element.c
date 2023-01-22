#include<stdio.h>
#include<stdlib.h>
int count;
int number;
int length;
int repetations(int *p)
{
if(count==(length))
{
    return 0 ;
}
else if(*p == number)
{
    count++;
    return repetations(p+1)+1;
}
else
{
    count++;
    return 0 + repetations(p+1);
}
}

int main()
{
    
    scanf("%d",&length);
    int *arr = malloc(length*sizeof(int));
    
    scanf("%d",&number);

    for(int i =0;i<length;i++)
    {
        scanf("%d",(arr+i));
    }

    for(int i =0;i<length;i++)
    {
        printf("%d ",(*(arr+i)));
    }
    


    int result = repetations(arr);
    free(arr);
    printf("\n%d\n",result);

    return 0;

}