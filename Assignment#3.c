//
//  main.c
//  Circular_queue_using_singly_linked_list
//
//  Created by R.AMOGH on 06/05/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//Creating nodes using a structure
struct node{
    int data;
    struct node *next;
};
//Creating a circular queue using a structure
struct queue{
    struct node *first;
    struct node *last;
};

//enqueue function of the queue
void enqueue(struct queue *q,int x){
    //If it is the first element being enqueued
    if(q->first==NULL && q->last==NULL){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->next = temp;
        temp->data = x;
        q->first = temp;
        q->last = temp;
    }
    else{ //If element is being enqueued in a queue with elements in it
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        q->last->next = temp;
        temp->next = q->first;
        q->last = temp;
    }
}

int dequeue(struct queue *qu){
    if(qu->first==NULL && qu->last==NULL){
        return INT_MIN;
    }
    else if(qu->first==qu->last){  // If there is only one element in the queue
        int x = qu->first->data;
        qu->last = NULL;
        free(qu->first);
        qu->first = NULL;
        return x;
    }
    else{
        int x = qu->first->data;
        struct node *temp = qu->first;
        qu->first = qu->first->next;
        qu->last->next = qu->first;
        free(temp);
        return x;
    }
}

void display(struct queue *q,FILE *optr){
    if(q->first==NULL && q->last==NULL){
        fprintf(optr,"Queue is Empty\n");
    }
    else{
        struct node *traverser = q->first;
        fprintf(optr, "Elements of the queue: ");
        while (traverser!=q->last) {
            fprintf(optr, "%d ",traverser->data);
            traverser = traverser->next;
        }
        fprintf(optr, "%d\n",traverser->data);
    }
}

//Driver code
int main(int argc,char *argv[]) {
    //Some input variables
    int enqueueValue;
    char inputString[100] = "";
    
    //Queue initialization
    struct queue *qu = (struct queue *)malloc(sizeof(struct queue));
    qu->first = NULL;
    qu -> last = NULL;
    
    //Reading input from the file
    FILE *ptr = fopen(argv[1],"r");
    //Opening a file to write the outputs
    FILE *optr = fopen("output.txt", "w");
    
   // Reading inputs from a while loop
    if(ptr==NULL){
        fprintf(optr,"File not found.\n");
    }
    else{
        while(!feof(ptr)){
            fscanf(ptr,"%s %d",inputString,&enqueueValue);
            //Calling corresponding functions
            if(strcmp(inputString,"enqueue")==0){
                //            enqueueValue = getw(stdin);
                enqueue(qu,enqueueValue);
                fprintf(optr, "Inserted value: %d\n",enqueueValue);   //Printing the newly inserted value
            }
            else if(strcmp(inputString, "display")==0){
                display(qu,optr);}
            else if(strcmp(inputString, "dequeue")==0){
                int tempNum = dequeue(qu);
                if(tempNum==INT_MIN){
                    fprintf(optr, "Queue is Empty\n");   //Exception of poping from empty queue
                }
                else
                    fprintf(optr, "deleted value: %d\n",tempNum);   //Printing Deleted value
                
            }
            else
                fprintf(optr, "Invalid expression");  //Error handling in file reading
        }
    }
    fclose(ptr);
    fclose(optr);
    
    free(qu);
    return 0;
}

