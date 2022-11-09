#include<stdio.h> //Basic idea for recursions.
int sumofnumbers(int n)
{   
     if(n==1)
       return 1;
    
    return n+sumofnumbers(n-1);


    
}
int main()
{
    int num;int sum;
    printf("Enter the number upto which sum needs to be calculated:\n");
    scanf("%d",&num);

    sum=sumofnumbers(num);

    printf("Sum of %d numbers = %d\n",num,sum);

    return 0;

}