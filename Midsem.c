//
//  main.c
//  Mid_sem_stack
//
//  Created by R.AMOGH on 09/06/23.
//

#include <stdio.h>
#include<stdlib.h>
//stack_array.h
#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include<limits.h>

/*----------------------------STACK STUFF-----------------------*/
struct stack{
    int top;
    int size;
    int *s_array;
};
int dummy;//printing variable
int pop(struct stack *st,FILE *output);
void push(struct stack *st,int x,FILE *output);
int stacktop(struct stack *st);
bool isEmpty(struct stack *st);
bool isFull(struct stack *st);
void display_stack(struct stack *st,FILE *output);

//Stack_array.c
int pop_stack(struct stack *st,FILE *output)
{
    if(st->top==-1){
        fprintf(output,"underflow\n");
        return -1;
    }
    else{
        int x = st->s_array[st->top];
        st->s_array[st->top] = -1;
        fprintf(output, "popped %d\n",x);
        st->top--;
        return x;
    }
}
void push_stack(struct stack *st,int x,FILE *output)
{
    if(st->top==(st->size)-1){
        fprintf(output,"overflow\n");}
    else{
        st->top++;
        st->s_array[st->top] = x;
        fprintf(output,"pushed %d\n",x);
    }
    
}
int stacktop(struct stack *st)
{
    return st->s_array[st->top];
}
bool isEmpty(struct stack *st)
{
    return st->top==-1?1:0;
}
bool isFull(struct stack *st){
    return st->top==(st->size-1)?1:0;
}
void display_stack(struct stack *st,FILE *output){
    for(int i=st->top;i>=0;i--){
        fprintf(output,"%d ",st->s_array[i]);
    }
    fprintf(output,"\n");
}

bool stackSearch(struct stack *st,int x){
    for(int i=st->top;i>=0;i--){
        if(st->s_array[i]==x)
            return true;
    }
    return false;
}
/*----------------------------STACK STUFF-----------------------*/

/*----------------------------QUEUE STUFF-----------------------*/
//Creating nodes using a structure
struct node{
    int data;
    struct node *next;
};
//Creating a circular queue using a structure
struct queue{
    struct node *first;
    struct node *last;
    int numberOfItems;
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
        q->numberOfItems++;
    }
    else{ //If element is being enqueued in a queue with elements in it
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = x;
        q->last->next = temp;
        temp->next = q->first;
        q->last = temp;
        q->numberOfItems++;
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
        qu->numberOfItems--;
        return x;
    }
    else{
        int x = qu->first->data;
        struct node *temp = qu->first;
        qu->first = qu->first->next;
        qu->last->next = qu->first;
        free(temp);
        qu->numberOfItems--;
        return x;
    }
}

void display(struct queue *q,FILE *optr){
    if(q->first==NULL && q->last==NULL){
        fprintf(optr,"\n");
    }
    else{
        struct node *traverser = q->first;
        while (traverser!=q->last) {
            fprintf(optr, "%d ",traverser->data);
            traverser = traverser->next;
        }
        fprintf(optr, "%d \n",traverser->data);
    }
}

bool queueSearch(struct queue *q,int x){
    if(q->first==NULL && q->last==NULL){
        return false;
    }
    else{
        struct node *traverser = q->first;
        while (traverser!=q->last) {
            if(traverser->data==x)
                return true;
            traverser = traverser->next;
        }
        if(q->first!=NULL && q->first==q->last)
        {
            if(q->first->data==x)
                return true;
        }
    }
    return false;
}
/*----------------------------QUEUE STUFF-----------------------*/


/*----------------------------DLL STUFF-----------------------*/
struct dnode{
    struct dnode *prev;
    int data;
    struct dnode *next;
};

void dInsert(struct dnode **head,int number){
    if(*head==NULL){
        struct dnode *temp = (struct dnode *)malloc(sizeof(struct dnode));
        temp->data = number;
        temp->next = NULL;
        temp->prev = NULL;
        *head = temp;
    }
    else{
        struct dnode *temp = (struct dnode *)malloc(sizeof(struct dnode));
        struct dnode *temp2 = *head;
        temp->data = number;
        temp2->prev = temp;
        temp->next = temp2;
        temp->prev = NULL;
        *head = temp;
    }
}

int dDelete(struct dnode **head,int number){
    int result = -1;
    if(*head==NULL){
        return result;
    }
    else{
        struct dnode *temp = *head;
        struct dnode *p = NULL;
        while(temp!=NULL){
            if(temp->data==number){
                result = temp->data;
                if(*head==temp){
                    *head = temp->next;
                }
                if(temp->next!=NULL){
                    temp->next->prev = temp->prev;}
                if(temp->prev!=NULL){
                    temp->prev->next = temp->next;}
                p = temp;
                free(p);
                return result;
            }
            temp = temp->next;
        }
        return -1;
    }
}

bool dSearch(struct dnode *head,int number){
    struct dnode *temp = head;
    if(head==NULL){
        return false;
    }
    else{
        while(temp!=NULL){
            if(temp->data == number){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
}

void dDisplay(struct dnode *head,FILE* output){
    struct dnode *temp = head;
    while(temp!=NULL){
        fprintf(output, "%d ",temp->data);
        temp = temp->next;
    }
}

/*----------------------------DLL STUFF-----------------------*/



//DRIVER CODE
int main(int argc,char **argv){
    FILE *inputFile = fopen(argv[1],"r");
    FILE *outputFile = fopen("stack.txt","w");
    const int stackOrQueueSize = atoi(argv[2]);
    /*----------------------STACK RELATED CODE------------------------------------*/
    //Stack initialization
    struct stack st;
    st.top = -1;
    st.size = stackOrQueueSize;
    st.s_array = (int*)malloc(stackOrQueueSize*sizeof(int));
    for(int i=0;i<stackOrQueueSize;i++){
        st.s_array[i]=-1;
    }
    //Also initializing some input storing variables
    char symbol[10] = "\0";
    int commandNumber = -1;//Since they are usually positive integers
    
    while(1){  //Opening of while loop for reading stack
        //Reading inputs for the stack case
        fscanf(inputFile, "%s",symbol);
        if(strcmp(symbol,"?")==0 || strcmp(symbol,"-")==0 || strcmp(symbol,"+")==0){
            fscanf(inputFile, "%d",&commandNumber);
        }
        if(feof(inputFile)){break;}//stop reading when end of file is encountered
        
        //Seeing which is the command and calling the corresponding operations
        if(strcmp(symbol,"+")==0){
            push_stack(&st,commandNumber,outputFile);
        }
        else if(strcmp(symbol,"-")==0){
            pop_stack(&st, outputFile);
        }
        else if (strcmp(symbol,"?")==0){
            bool var = stackSearch(&st, commandNumber);
            if(var){fprintf(outputFile, "found %d\n",commandNumber);}
            else{
                fprintf(outputFile, "not found %d\n",commandNumber);
            }
        }
        else if(strcmp(symbol,"!")==0){
            if(isEmpty(&st)){fprintf(outputFile, "\n");}
            else{display_stack(&st,outputFile);}
        }
        else{fprintf(outputFile,"Invalid command\n");}
    }//Closing while loop for reading stack
    
/*----------------------STACK RELATED CODE------------------------------------*/
    
//Rewinding the file to read input again
    rewind(inputFile);
    
/*----------------------QUEUE RELATED CODE------------------------------------*/
    FILE *outputFileQueue = fopen("queue.txt","w");
    //Queue initialization
    struct queue *qu = (struct queue *)malloc(sizeof(struct queue));
    qu->first = NULL;
    qu -> last = NULL;
    qu->numberOfItems = 0;
    int numberOfQueueItems = atoi(argv[2]);
    
    //Also initializing some input storing variables
    char symbolForQueue[10] = "\0";
    int queueNumber = -1;//Since they are usually positive integers
    
    while(1){  //Opening of while loop for reading queue
        //Reading inputs for the queue case
        fscanf(inputFile, "%s",symbolForQueue);
        if(strcmp(symbolForQueue,"?")==0 || strcmp(symbolForQueue,"-")==0 || strcmp(symbolForQueue,"+")==0){
            fscanf(inputFile, "%d",&queueNumber);
        }
        if(feof(inputFile)){break;}//stop reading when end of file is encountered
        
        //Seeing which is the command and calling the corresponding operations
        if(strcmp(symbolForQueue,"+")==0){
            if(qu->numberOfItems>=numberOfQueueItems){
                fprintf(outputFileQueue, "overflow\n");
            }
            else{
                enqueue(qu,queueNumber);
                fprintf(outputFileQueue, "enqueued %d\n",queueNumber);}
        }
        else if(strcmp(symbolForQueue,"-")==0){
                int tempNum = dequeue(qu);
                if(tempNum==INT_MIN){
                    fprintf(outputFileQueue, "underflow\n");   //Exception of poping from empty queue
                }
                else
                    fprintf(outputFileQueue, "dequeued %d\n",tempNum);   //Printing Deleted value
        }
        else if (strcmp(symbolForQueue,"?")==0){
            bool var = queueSearch(qu, queueNumber);
            if(var){fprintf(outputFileQueue, "found %d\n",queueNumber);}
            else{
                fprintf(outputFileQueue, "not found %d\n",queueNumber);
            }
        }
        else if(strcmp(symbolForQueue,"!")==0){
            display(qu, outputFileQueue);
        }
        else{fprintf(outputFileQueue,"Invalid command\n");}
    }//Closing while loop for reading queue

    
    
    
/*----------------------QUEUE RELATED CODE------------------------------------*/

    
//Resetting the input pointer
    rewind(inputFile);

/*----------------------DLL RELATED CODE------------------------------------*/
    //Creating an output file
    FILE *outputFileList = fopen("dll.txt", "w");
    //Intializing the list
    struct dnode *head = NULL;
    //variable for storing command
    char symbolForList[10] = "\0";
    int numberForList = -1;

    while(1){  //Opening of while loop for reading List
        //Reading inputs for the list case
        fscanf(inputFile, "%s",symbolForList);
        if(strcmp(symbolForList,"?")==0 || strcmp(symbolForList,"-")==0 || strcmp(symbolForList,"+")==0){
            fscanf(inputFile, "%d",&numberForList);
        }
        if(feof(inputFile)){break;}//stop reading when end of file is encountered

        //Seeing which is the command and calling the corresponding operations
        if(strcmp(symbolForList,"+")==0){
                dInsert(&head, numberForList);
                fprintf(outputFileList, "inserted %d\n",numberForList);
        }
        else if(strcmp(symbolForList,"-")==0){
                int tempNum = dDelete(&head, numberForList);
                if(tempNum==-1){
                    fprintf(outputFileList, "cannot delete %d\n",numberForList);   //Exception of deleting from empty list
                }
                else
                    fprintf(outputFileList, "deleted %d\n",numberForList);   //Printing Deleted value
        }
        else if (strcmp(symbolForList,"?")==0){
            bool var = dSearch(head,numberForList);
            if(var){fprintf(outputFileList, "found %d\n",numberForList);}
            else{
                fprintf(outputFileList, "not found %d\n",numberForList);
            }
        }
        else if(strcmp(symbolForList,"!")==0){
            dDisplay(head,outputFileList);
            fprintf(outputFileList, "\n");
        }
        else{fprintf(outputFileList,"Invalid command\n");}
    }//Closing while loop for reading List

    
/*----------------------DLL RELATED CODE------------------------------------*/
//closing files
    fclose(inputFile);
    fclose(outputFile);
    //fclose(outputFileQueue);
    fclose(outputFileList);
    return 0;
}
