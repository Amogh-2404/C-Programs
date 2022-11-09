#include<stdio.h> // Similar to fibonacci sequence.
int Lucas(int n)
{
    if(n==0)
       {return 2;} //This step makes the difference.
    if(n==1)
       {return 1;}
   
    

    return Lucas(n-1) + Lucas(n-2);
}
int main()
{
    int num,ans;
    printf("Enter the index whose Fibonacci value needs to be calculated:\n");
    scanf("%d",&num);

    ans=Lucas(num);

    printf("The value of the index %d is %d\n",num,ans);

    return 0;
}