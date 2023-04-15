#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*first,*last;

void create(int a[],int size)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = a[0];
    t->next = NULL;
    first = last = t;

    for(int i=1;i<size;i++)
    {
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next=first;
        last->next=t;
        last = t;
    }
}

void display(struct node *p)
{
   
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=first);
    printf("\n");
}

void sortedinsert(struct node *p,int x)
{
        struct node *t=(struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next=NULL;
        struct node *temp;
        while(p->data<x)
        {
            temp=p;
            p=p->next;
        }
        temp->next=t;
        t->next = p;
}

void insert(struct node *p,int pos,int x)
{
    struct node *temp,*t=malloc(sizeof(struct node));
    temp = NULL;
    if(p==NULL){
        t->data = x;
        t->next = NULL;
        first=t;
    }
    else{
    for(int i=1;i<pos;i++)
    {
       temp=p;
       p=p->next;
    }
    t->data=x;
    t->next = p;
    temp->next = t;
    }
}

void removeduplicates(struct node *p)
{

        struct node *q;
        q=p->next;
        while(q!=first)
        {
            if(p->data!=q->data)
            {
                p=q;
                q=q->next;
            }
            else{
            
              p->next=q->next;
              free(q);
              q=p->next;
            }
            
        }
    
}

// int main()
// {
//     int array[]={10,10,20,20,20,30};  //Position is considered to start from 1.
//     create(array,6);
//     //sortedinsert(first,45);
//     //insert(first,3,300);
//     removeduplicates(first);
//     display(first);
//     return 0;
// }