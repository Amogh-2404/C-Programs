#include<stdio.h>
int main()
{
    int A ;
    int B ;
    int C ;
    int max , min;

    printf("Enter number 1\n");
    scanf("%d",&A);
    printf("Enter number 2\n");
    scanf("%d",&B);
    printf("Enter number 3\n");
    scanf("%d",&C);
    max = A;
    min = B;
    if(A<B)
    {
        max = B;
        min = A;
    }
    if(max < C)
       max = C;
    if(C < min)
       min = C;

       printf("Maximum = %d \n minimum = %d\n",max ,min);
   return 0;
}