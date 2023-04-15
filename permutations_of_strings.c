#include<stdio.h>
#include<string.h>
void swap(char *A, char *B)
{
    char temp;
    temp=*A;
    *A=*B;
    *B=temp;
}

void premswap(char s[],int l,int h)
{
   int i;
   if(l==h)
   {
    printf("%s\n",s);
   }
   else{
   for(i=l;i<=h;i++) 
   {
    swap(&s[l],&s[i]);
    premswap(s,l+1,h);
    swap(&s[l],&s[i]);
   }
   }
}

void perm_space_tree(char s[],int k)
{
    static int A[20]={0};
    static char result[20];
    int i;
    if (s[k]=='\0')
    {
        result[k]='\0';
        printf("%s\n",result);
    }
    else{
        for(i=0;s[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                result[k]=s[i];
                A[i]=1;
                perm_space_tree(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{
    char string[]="abc";
    int k;
    for(k=0;k<sizeof(string);k++)
    {;}
    
    // premswap(string,0,k-2);
    perm_space_tree(string,0);
    return 0;
}