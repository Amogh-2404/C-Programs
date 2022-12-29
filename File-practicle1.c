#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE* fl;
    fl=fopen("firstfileinc","w");
    if(fl==0)
      printf("The opening of the file has failed.\n");
    else
    {
        printf("The opening of the file has been sucessful.\n");
        
    
        fclose(fl);
    }
    return 0;

}