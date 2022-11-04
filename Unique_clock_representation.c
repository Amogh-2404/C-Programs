#include<stdio.h>
int main()
{
    int seconds;
    printf("Please enter the number of seconds: \n");
    scanf("%d",&seconds);
    int H,M,S;
    H=seconds/3600;
    M=(seconds - H*3600) / 60;
    S=(seconds - H*3600) % 60;

    if(H<10)
    printf("0");
    printf("%d:",H);

    if(M<10)
    printf("0");
    printf("%d:",M);

    if(S<10)
    printf("0");
    printf("%d:",S);

    return 0;

}