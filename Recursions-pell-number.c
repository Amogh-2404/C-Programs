#include<stdio.h>
int pell(int n)
{
    if(n==0)
       {return 0;}
    if(n==1)
       {return 1;}
   
    

    return 2*pell(n-1) + pell(n-2);
}
int main()
{
    int num,ans;
    printf("Enter the index whose pell value needs to be calculated:\n");
    scanf("%d",&num);

    ans=pell(num);

    printf("The value of the index %d is %d\n",num,ans);

    return 0;
}