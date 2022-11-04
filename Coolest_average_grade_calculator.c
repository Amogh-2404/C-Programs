#include<stdio.h>
int main()
{
    int grade;
    int totalsum = 0, gradescount = 0;

    printf("Please enter your grades or '-1' to stop:");
    scanf("%d",&grade);

    while(grade!=-1)
    {
        totalsum = totalsum + grade ;
        gradescount++;
        printf("Please enter your grades or '-1' to stop:");
        scanf("%d,&grade");
    }
    return 0;
    printf("You've entered %d grades! \n",gradescount);
    if(gradescount!=0)
      printf("And your average grade is %f\n",(float)totalsum/gradescount);
}