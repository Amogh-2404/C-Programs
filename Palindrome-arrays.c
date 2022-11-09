#include<stdio.h>
#define SIZE 5
int main()
{
    int i;
    int flag=1;
    int arr[SIZE];

    printf("Enter the numbers of the sequence one by one.\n");

    for(i=0;i<SIZE;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<SIZE/2;i++)
    {
        if(arr[i] != arr[SIZE-1-i])
        {
            flag = 0;
            break;
        }
    }
    if(flag ==1)
       printf("The Array is a Palindrome.\n");
    else if(flag ==0)
       printf("The Array is NOT a Palindrome.\n");

    return 0;
}