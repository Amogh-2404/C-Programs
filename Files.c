#include<stdio.h>
int main()
{
// Step #1 - Creating a Pointer that points to a FILE type
FILE* fp;
// Step #2 - opening/access to a file
// fp = fopen (<file_name›, <type_of_operations);
// Types of operation:
/*
"W"
- Writing.
"p"
Reading.
"a"
Appending.*/
fp = fopen(); //TODO - Complete.

//Step #3 -Make sure the opening was successful
// if (fp!=NULL) - to make sure that the open operation was successful

//Step #4 - Work with the file (Reading/writing/etc)
// Code for working with the file..

//Step $5 - Close the file.
fclose (fp);
return 0;
}