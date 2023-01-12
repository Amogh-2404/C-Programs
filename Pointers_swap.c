#include<stdio.h>
void swap(int *ptr1,int *ptr2)
{
*ptr1=*ptr1 + *ptr2;
*ptr2=*ptr1-*ptr2;
*ptr1=*ptr1 - *ptr2;

}
int main(){
    int a=10,b=20;
    printf("Variables before swap : %d %d\n",a,b);

    swap(&a,&b);

    printf("Variables after swap : %d %d\n",a,b);

    return 0;

}