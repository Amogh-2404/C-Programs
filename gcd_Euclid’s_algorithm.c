#include<stdio.h>
int gcd(int j, int k)
{
int temp;
temp = j -(j/k)*k;
if (temp ==0)
{
return k;
}
return gcd(k,temp);
}
int main()
{
    int a=0,b=0;
    scanf("%d",&a);
    scanf("%d",&b);
    int result = 0;
    if(a>=b){
    printf("%d\n",gcd(a,b));
    }
    else{
    printf("%d\n",gcd(b,a));
    }
    
    return 0;
}