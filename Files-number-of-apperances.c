#include<stdio.h>
#include<string.h>
int main()
{
char desiredCharacter;
char filename [20] = { 0 };
int countAppearances = 0;
FILE* fp;
printf ("Enter a desired character:\n");
scanf (" %c",&desiredCharacter); //The space with the format specifier is very important.
printf ("Enter a filename you want to test:\n");
scanf ("%s",filename);
fp = fopen (filename, "r");
if (fp != NULL)
{
   while (!feof (fp))
    {if (fgetc (fp) == desiredCharacter)
        countAppearances++;
    }
}

printf("Total appearances of character %c: %d\n", desiredCharacter, countAppearances) ;
return 0;
}