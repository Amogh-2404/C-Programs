#include <stdio.h>

int main()
{
    int day, month, year;
    int leapYear = 0; // Default

    printf("Enter the day: ");
    scanf("%d", &day);

    printf("Enter the month: ");
    scanf("%d", &month);

    printf("Enter the year: ");
    scanf("%d", &year);

    // Find if a given year is Leap or Not Leap
    if (month == 2) // If it's February
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
            leapYear = 1;

    day += 1; // day = day + 1;

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day <= 31)//From here day is taken after it is implemented i.e, day+1
            break;// That's OK :)
    case 4:
    case 6:
    case 9:
    case 11:
        if (day <= 30)
            break;
    case 2: // February
        if (day <= 29 && leapYear == 1)
            break;
        else if (day <= 28)
            break;
    default:
        day = 1;
        month += 1; // month = month + 1
        if (month > 12)
        {
            month = 1;
            year += 1; // year = year + 1
        }
    }
        printf("The Next Awesome Day is: %d/ %d/ %d\n", day, month, year);
}

