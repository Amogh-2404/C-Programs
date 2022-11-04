#include<stdio.h>
int main()
{
    int month;
    printf("Please enter the number of the month(1-12) whoes name is to be known\n");
    scanf("%d",&month);

    switch(month)
    {
        case 1 :
        printf("January\n");
        break;

        case 2 :
        printf("February\n");
        break;

        case 3:
        printf("March\n");
        break;

        case 4:
        printf("April\n");
        break;

        case 5:
        printf("May\n");
        break;

        case 6:
        printf("June\n");
        break;

        case 7:
        printf("July\n");
        break;

        case 8:
        printf("August\n");
        break;

        case 9:
        printf("September\n");
        break;

        case 10:
        printf("October\n");
        break;

        case 11:
        printf("November\n");
        break;

        case 12:
        printf("December\n");
        break;

        default:
        printf("Enter a valid number i.e, 1-12");
    }

    return 0;

}