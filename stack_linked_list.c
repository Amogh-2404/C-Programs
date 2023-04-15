#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct stack{
    struct node *top;
};

void push(struct stack *p,int x)
{
    struct node *t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
       printf("Stack overflow.\n");
    else{
        t->data=x;
        t->next=p->top;
        p->top = t;
    }
}

int pop(struct stack *p)
{
  struct node *t;
  int x = -1;
  if(p->top==NULL)
     printf("Stack is empty.\n");
  else{
    t=p->top;
    p->top = t->next;
    x = t->data;
    free(t);
  }
  return x;
}

int peek(struct stack *p,int pos){
    struct node *t = p->top;
    for(int i=0;i<pos-1;i++){
        t = t->next;
    }
    if(t!=NULL)
       return t->data;
    else
       return -1;
}

int stacktop(struct stack *p)
{
    if(p->top)
      return p->top->data;
    return -1;
}

int isFull(struct stack *p)
{
    struct node *t = (struct Node*)malloc(sizeof(struct node));
    if(t==NULL)
      return 1;
    else 
      free(t);
      return 0;
      
}

int isEmpty(struct stack *p)
{
    return p->top?0:1;
}

int main()
{
    struct stack *new=(struct stack *)malloc(sizeof(struct stack));
    push(new,10);
    push(new,20);
    push(new,30);
    printf("Element popped: %d\n",pop(new));
    printf("%d\n",peek(new,1));

    printf("Element popped: %d\n",pop(new));
    printf("isEmpty: %d\n",isEmpty(new));

    printf("Element popped: %d\n",pop(new));
    printf("isEmpty: %d\n",isEmpty(new));
    
    return 0;
}