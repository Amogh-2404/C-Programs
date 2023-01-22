#include<stdio.h>
void binary_finder(int n)
{
   if(n == 1)
   {
    printf("1");
   }
   else if (n==0)
   {
    printf("0");
   }
   else{
    binary_finder(n/2);
    printf("%d",n%2);
   }

}
int main(){
    int num=0;
    scanf("%d",&num);
    binary_finder(num);

    printf("\n");
    return 0;
}