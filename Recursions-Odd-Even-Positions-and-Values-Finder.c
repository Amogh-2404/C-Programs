#include<stdio.h>
int tillnow;
int positionsvalue(int n)
{
  int count=0;
if(n<10)
{
    if((count%2==0) && (n%2==0))
      return 1;
    if((count%2!=0)&&(n%2!=0))
      return 1;
    else
      return 0;
}
  if(count%2==0)
  {
    if((n%10)%2==0)
    {
        tillnow=1;
        count++;
        positionsvalue(n/10);
    }
    else
    {tillnow=0;}
  }
  else
  {
    if((n%10)%2!=0)
    {
        tillnow=1;
        count++;
        positionsvalue(n/10);
    }
    else
    {
        tillnow=0;
    }
  }

  return tillnow;
}
int main()
{
    int num,ans;
    printf("Enter number:\n");
    scanf("%d",&num);

    ans=positionsvalue(num);

    if(ans==1)
      printf("%d\n",ans);
    if(ans==0)
      printf("%d\n",ans);
}