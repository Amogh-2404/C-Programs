#include<stdio.h>

int main()
{
    int sum = 0, i, j;

    for(i = 0; i < 3; i++)
    {
        sum += i;
        for(j = 0; j < 3; j++)
        {
            sum += j;
            if(((i + j) % 2) == 1)
                break;
        }
    }

    printf("%d",sum);

    return 0;
}