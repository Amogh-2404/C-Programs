#include<stdio.h>
#include<stdlib.h>
int sign_check(int *p,int *j)
{
if(p == j)
{
    return 1;
}
int num1 = *p;
int num2 = *(p+1);
if(num1*num2 == -1)
{
    return sign_check(&(*(p+1)) , &(*j));
}
else
{
    return 0;
}

}
int main()
{
    int n=0; 
    scanf("%d",&n);
    printf("\n");
    int *a = malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int result = sign_check(&a[0],&a[n-1]);
    printf("%d\n",result);

    return 0;
}