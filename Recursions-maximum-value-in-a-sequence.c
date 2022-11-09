#include<stdio.h>
int max=0;
int maxvalue(int l)
{
    if(l>0)
    {
        int in;
        printf("Please enter an integer:\n");
        scanf("%d",&in);
        if(in>max)
          max=in;
        maxvalue(l-1);
    }
   return max;
}
int main()
{
    int length,ans;
    printf("Enter the length of the sequence:\n");
    scanf("%d",&length);
    
    ans=maxvalue(length);
    printf("The maximum value in the sequence of integers entered is %d\n",ans);

    return 0;
}