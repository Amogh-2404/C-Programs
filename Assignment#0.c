//
//  main.c
//  File_operations
//
//  Created by R.AMOGH on 18/04/23.
//

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

int main(int argc,char* argv[]) {

    FILE *ptr=fopen(argv[1], "r");
    int max = -INT_MAX;
    int min = INT_MAX;

    if(ptr==NULL)
        printf("File not found\n");
    int temp=0,sum=0,count=0;
    while(fscanf(ptr,"%d",&temp)==1) {
        sum+=temp;
        count++;
        if(temp>=max)
            max = temp;
        if(temp<=min)
            min = temp;
    }
    fclose(ptr);
    double avg = (double)sum/count;
    
//Writing output to a new file
    FILE *rptr=fopen("output.txt", "w");
    fprintf(rptr,"%d\n%d\n%d\n%d\n%.2lf",count,min,max,sum,avg);
    fclose(rptr);
    return 0;
  
}
