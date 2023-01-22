#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
int main()
{
    int maxLen, numstrings, i=0;
    char **ptr = NULL;
    char *holder = NULL;

    scanf("%d",&maxLen);
    scanf("%d",&numstrings);
    
    ptr = malloc(numstrings*sizeof(char*));
    
    
    for(i=0;i<numstrings;i++)
    {
     ptr[i] = (char*)malloc(maxLen*sizeof(char));
     scanf("%s",ptr[i]);
    }

    assert((ptr!=NULL)&&(*ptr!=NULL)&&(ptr+numstrings != NULL));
    printf("\n");   
    for(i=numstrings-1;i>=0;i--)
    {
        for (int j = maxLen; j >=0 ; j--)
        {
            if(ptr[i][j]=='\0')
              continue;
            else
              printf("%c",ptr[i][j]);
        }
        printf("\n");
    }

    free(holder);
    free(ptr);
    return 0;
}