// Exercise: Write 2 functions:
//- Function #1 - gets a point variable and prints its information.
//- Function #2 - responsible for getting a point input from the user
//                and then return it.

#include<stdio.h>

typedef struct point{
        int x;
        int y;
    }Point;

Point inputpoint()
{
    struct point temp;
    printf("Enter the x-coordinate of the point:\n");
    scanf("%d",&temp.x);
    printf("Enter the y-coordinate of the point:\n");
    scanf("%d",&temp.y);

    return temp;
}

void printpoint(Point out)
{
    printf("The coordinates of the point are (%d,%d).\n",out.x,out.y);
}

int main()
{
    
    Point p1=inputpoint();

    printpoint(p1);

    return 0;
}