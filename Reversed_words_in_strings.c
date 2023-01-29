#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int LEN=0;
    scanf("%d",&LEN);
    getchar();
    char **p=(char**)malloc((sizeof(char*))*LEN);
    for(int i=0;i<LEN;i++)
    {
        p[i]=(char*)malloc(sizeof(char)*100);
    }
    for(int i=0;i<LEN;i++)
    {
        fgets(p[i],100,stdin);
        
    }
    for(int i=0;i<LEN;i++)
    {
        for(int j=strlen(p[i]);j>=0;j--)
        {
            if(p[i][j]=='\n' || p[i][j]==' ')
            {
                continue;
            }
            else{
            printf("%c",p[i][j]); 
            }  
        }
        
        printf(" ");
    }
    return 0;
}