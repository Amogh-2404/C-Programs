#include<stdio.h>
#include<string.h>
int main()
{
    FILE* fp;
    fp=fopen("firstfileinc","r");
    if(fp==NULL)
       printf("The opening of file was failed.\n");
    else
    printf("The opening of the file was sucessful,\n");
    int count=0;
    while(!feof(fp))    //Instead of the following code we can also write while((c=getc(fp))!=EOF).
    {
        char c;
        c=getc(fp);
        printf("%c",c);
        if(c=='\n')
          count=count;
        else if(c=='\0')
          count=count;
        else if(c==EOF)    // Important step.
          count=count;
        else
          count++;
    };

    printf("The number of charecters in the file is %d.\n",count);
    fclose(fp);
    return 0;
}