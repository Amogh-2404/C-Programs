#include<stdio.h>
int totalchar(char refc)
{
    char in;
    printf("Enter a charecter:\n");
    scanf("%c ",&in);
    
    if(in=='$')
      return 0;
    if(in==refc)
      return 1+totalchar(refc);
    return totalchar(refc);
}
int main()
{
    char ref;
    int ans;
    printf("Enter the reference charecter:\n");
    scanf("%c",&ref);
    printf("You will be asked to enter a sequence of charecters to give the output of number of reference charecter in the sequence.\nYou can stop the sequence by entering '$'.\n");

    ans = totalchar(ref);

    printf("Total number of matching charecters in the sequence is %d",ans);

    return 0;
}