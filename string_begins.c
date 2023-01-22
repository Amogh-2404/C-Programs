#include<stdio.h>
#include<string.h>
int string_begins(char string1[20],char string2[30],char *s)
{
    char *c = strstr(string2,string1);
    if(c == s)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char string1[20];
    char string2[30];
    fgets(string1,20,stdin);
    fgets(string2,30,stdin);
    
    printf("%s",string1);
    printf("%s",string2);
    int result = string_begins(string1,string2,string2);
    printf("%d",result);
    
return 0;
}