// Exercise //
/* Develop a recursive function that receives an integer num.
/ The function should observe the digits (from left to right) and return:
- 1, if they are very ascending.
-1, if they are very descending.
- 0, otherwise.
// Assumptions:
Initial "num" is of 2+ digits. (num >= 10).
- All digits in "num" are different (no pair of digits are the same). All different
For example:
"124" - - > 1
"12342" - -> 0
"96431 _-> _1 */

//Very important question.
int dummy=0;
#include<stdio.h>
int digitsofnumber(int n)
{
    int units = n%10;
    int tens =  (n/10)%10;
    int sortedsofar;

    if(n<100)
    {
        if(tens<units)
          return 1;
        else 
         return -1;
    }
    sortedsofar = digitsofnumber(n/10);

    if(sortedsofar == 1 && tens<units)
      return 1;
    if(sortedsofar == -1 && tens>units)
      return -1;
    
    return 0;
}
int main()
{
    int num,ans;
    printf("Please enter a number(>=10). Make sure that none of the digits of the number are repeating.\n");
    scanf("%d",&num);
    printf("The program returns:\n1, if they are very ascending.\n-1, if they are very descending.\n0, otherwise.\n");
    
    ans=digitsofnumber(num);
    printf("\n\n%d\n\n",ans);

    return 0;
}