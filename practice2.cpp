// #include<stdio.h>
// #include<string.h>
// int main()
// {
//     struct students
//     {
//         char name[30];
//         int roll_number;
//     };

//     struct students array[5];
//     for(int i=0;i<5;i++)
//     {
//         scanf("%s %d",array[i].name,&array[i].roll_number);

//     }
    
//     printf("Name\trollno\temailid");
//     printf("\n");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%s\t%d\t%%%d@iitdh.ac.in%%",array[i].name,array[i].roll_number,array[i].roll_number);
//         printf("\n");
//     }
    
//     return 0 ;
// }
#include<iostream>
using namespace std;
int f(int &x, int c) 
{
c-=1;
if (c == 0) return 1; 
x = x + 1; 
cout<<x<<","<<c<<endl;
return f(x,c) * x;
}
int main()
{
    int p = 5;
    cout<<f(p,3)<<endl;
    return 0;
}