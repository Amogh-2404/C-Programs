#include<stdio.h>
#include<string.h>

char *check(char* p)
{
    if(*p !=' ')
    {
        return p;
    }
    else if(*p == '\0')
    {
        return NULL;
    }
    else
    {
        return check(p+1);
    }
}


int main()
{
    char arr[50];
    scanf("%[^\n]s",arr);

    char *fc = check(arr);
    printf("%c\n",*fc);

    return 0;
}