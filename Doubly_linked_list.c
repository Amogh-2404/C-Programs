#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL,*last=NULL;

void dcreate(int a[],int size)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->prev=NULL;
    t->data = a[0];
    t->next = NULL;
    first = last = t;

    for(int i=1;i<size;i++)
    {
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->prev=last;
        t->next=first;
        first->prev=t;
        last->next=t;
        last = t;
    }

}

void display(struct node *p)
{
    printf("In forward order:\n");
    do
    {
       printf("%d ",p->data);
       p=p->next;
    }while(p!=first);
    printf("\nIn reverse order.\n");
    p=last;
    do
    {
        printf("%d ",p->data);
        p=p->prev;
    }while(p!=last);
    printf("\n");
}

void sortedinsert(struct node *p,int x)
{
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->prev=NULL;
        t->data = x;
        t->next=NULL;
        struct node *temp;
        while(p->data<x)
        {
            temp=p;
            p=p->next;
        }
        t->prev=temp;
        t->next=p;
        p->prev=t;
        temp->next=t;
        
}

int main()
{   
    int array[]={10,20,30,40,50,60};
    dcreate(array,6);
    sortedinsert(first,45);
    display(first);
    return 0;
}