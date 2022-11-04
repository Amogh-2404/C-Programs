#include<stdio.h>  

int main()
{   
    float a1,d;
    int n;
    printf("Enter the initial term (a1) : \n\n");
    scanf("%f" , &a1);
    printf("Enter the diffference in the aithmetic progression : \n\n");
    scanf("%f", &d );
    printf("Enter the number of the element to be calculated:\n\n");
    scanf("%d", &n);
    
    printf("The n-th term of the arithmetic progression = %f\n\n", a1+(n-1)*d);
    return 0;
}