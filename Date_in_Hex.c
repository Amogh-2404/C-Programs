#include<stdio.h>
int main()
{
    int day;
    int month;
    int year;
    printf("Day=\n");
    scanf("%d",&day);
    printf("Month=\n");
    scanf("%d",&month);
    printf("Year=\n");
    scanf("%d",&year);

    printf("\n\nDay=0x%X\nMonth=0x%X\nYear=0x%X\n",day,month,year);

    return 0;
}