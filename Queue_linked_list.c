#include<stdio.h>
#include<stdlib.h>
#include "Linked_list.c"

struct queue{
    struct node *front;
    struct node *rear;
};

void enqueue(struct queue *q,int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if(q->front==NULL)
    {
        t->data = x;
        t->next=NULL;
        q->front=q->rear=t;
    }
    else{
    t->data = x;
    t->next = NULL;
    q->rear->next = t;
    q->rear = t;
    }
}

int dequeue(struct queue *q)
{
    if(q->front==NULL)
    {printf("Queue is empty.\n");
       return -1;}
    else{
        int x = q->front->data ;
        struct node *temp=NULL;
        temp = q->front;
        q->front = q->front->next;
        free(temp);
        return x;
    }   
}

int isEmpty(struct queue *q)
{
    return q->front==q->rear?1:0 ;
}

int isFull(struct queue *q)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    return t==NULL?1:0 ;
}

int firstq(struct queue *q)
{
   return q->front->data;
}

int lastq(struct queue *q)
{
    return q->rear->data;
}

void displayq(struct node *p)
{
   
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct queue *qu; 
    qu->front=qu->rear=NULL;
    enqueue(qu,10);
    printf("%d \n",dequeue(qu));
    enqueue(qu,20);
    enqueue(qu,30);
    enqueue(qu,40);
    printf("%d \n",isEmpty(qu));
    printf("%d \n",isFull(qu));
    printf("%d \n",firstq(qu));
    printf("%d \n",lastq(qu));
    
    displayq(qu->front);
    return 0;
}