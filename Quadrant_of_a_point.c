#include<stdio.h>
int main()
{
    int x;
    int y;
    printf("Enter the value of x-coordinate of the point : \n");
    scanf("%d",&x);
    printf("Enter the value of y-coordinate of the point : \n");
    scanf("%d",&y);

    if(x>0 && y>0)
    printf("The given point in the First Quadrant\n");
    else if(x>0 && y<0)
    printf("The given point is in the Fourth Quadrant\n");
    else if(x<0 && y>0)
    printf("The given point is in the Second Quadrant\n");
    else if(x<0 && y<0)
    printf("The given point is in the Third Quadrant\n");
    else
    printf("The given point is the origin\n");
    
    return 0;
}