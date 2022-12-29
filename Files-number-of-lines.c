#include<stdio.h>
#include<string.h>
int main()
{
    char c;
    FILE* fp;
    fp=fopen("firstfileinc","r");
    if(fp==NULL)
       printf("The opening of file was failed.\n");
    else
    printf("The opening of the file was sucessful,\n");
    int line=1;
    while((c=getc(fp))!=EOF)    
    {
        printf("%c",c);
        if(c=='\n') 
          line++;
        
    };

    printf("The number of lines in the file is %d.\n",line);
    fclose(fp);
    return 0;
}