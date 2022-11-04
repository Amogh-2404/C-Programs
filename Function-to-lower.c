#include<stdio.h>
char tolower(char input)
{
    if(input >= 'A' && input <= 'Z')
      return ((input - 'A')+'a');
    else
    printf("Error!\n");
      
}
int main()
{
    char input;
    printf("Please enter a Capital alphabet:\n");
    scanf("%c",&input);
    char ans;
    ans = tolower(input);
    printf("%c\n",ans);


    return 0;
}