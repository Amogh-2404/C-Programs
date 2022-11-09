// Very important and intelligent approach.
#include<stdio.h>
int sumofdigits(int n)
{
    if(n<=9)  //Never miss conditions in recursions. It will keep executing forever or show something called segmentation error.
      return n;

   return (n%10)+sumofdigits(n/10);
}
int main()
{
    int num;
    printf("Enter a number whose sum of digit needs to be calculated:\n");
    scanf("%d",&num);
    int ans;

    ans = sumofdigits(num);

    printf("The sum of digits number %d is %d\n",num,ans);
    
}