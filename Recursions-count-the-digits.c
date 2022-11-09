#include<stdio.h>
int countofdigits(int n)
{
    
    if(n<=9)  
      return 1;
    else
      return 1+countofdigits(n/10);

}
int main()
{
    int num;
    printf("Enter a number whose count of digit needs to be calculated:\n");
    scanf("%d",&num);
    int ans;

    ans = countofdigits(num);

    printf("The count of digits of number %d is %d\n",num,ans);
    
}