#include<stdio.h>
#include<string.h>
int main()
{
    printf("Please enter a sentence:\n");
    char str[100];
    gets(str);

    int length;
    length=strlen(str);

    int words=0;
    int i;
    for(i=0;i<=length;i++)
    {
        if((str [i]==' ') || (str [i]=='\0'))
          {
            words++;
          }
    }
    printf("Total number of words in the given sentence is %d\n",words);
    return 0;
}