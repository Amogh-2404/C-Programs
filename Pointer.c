#include<stdio.h>
int main()
{
    int a=10;
    int *p;
    p=&a;
    printf("%d\n",&a);
    printf("%d\n",p);
    printf("%d\n",sizeof(size_t));
    return 0;
}