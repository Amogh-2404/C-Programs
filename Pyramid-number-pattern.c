#include<stdio.h>//Very Important exercise.
int main()
{
   int i,j,k;
   int blankspaces;
   int n;
   int currentvalue=1;
    printf("Enter the number of steps of the pyramid:\n");
    scanf("%d",&n);
    blankspaces=n-1;

    for(i=1;i<=n;i++)//Iterate over all of the rows.
    { 
        for(k=blankspaces;k>=1;k--){
        printf(" ");
        }
        
        for(j=1;j<=i;j++)
        {
            printf("%d ",currentvalue);
            currentvalue+=1;
        }
        printf("\n");
        blankspaces--;
    }



 return 0;
}
    
