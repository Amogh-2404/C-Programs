#include<stdio.h>
int main()
{
    #ifdef __STDC_NO_COMPLEX__
     printf("Not defined");
    #else
     printf("Defined");
    #endif

    return 0;
}