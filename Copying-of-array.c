#include<stdio.h>
int main()
{
    int date[3];
    printf("Enter Day:\n");
    scanf("%d",&date[0]);
    printf("Enter Month:\n");
    scanf("%d",&date[1]);
    printf("Enter Year:\n");
    scanf("%d",&date[2]);

    printf("Date: %d / %d / %d\n",date[0],date[1],date[2]);


    int datecopy[3],i;
    for(i=0;i<3;i++)
    {
        datecopy[i]=date[i];
    }
    
     printf("Date: %d / %d / %d\n",datecopy[0],datecopy[1],datecopy[2]);



}