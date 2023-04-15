#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *s;
};

void create(struct stack *p)
{
p=(struct stack *)malloc(sizeof(struct stack));
printf("Enter the size of the stack: ");
scanf("%d",&(p->size));
p->s=(int*)malloc(sizeof(int)*p->size);
p->top=-1;
if(p->s)
    printf("Stack initialzed.\n");
}

void push(struct stack *p,int x)
{
    if (p->top==(p->size)-1)
       printf("Stack is full.\n");
    else{
        p->top++;
        p->s[p->top]=x;
        //printf("%d succesfully pushed on the stack.\n",x);
    }
}

int pop(struct stack *p)
{
    if(p->top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        int x = p->s[p->top];
        p->top--;
        return x;
    }
}

int peek(struct stack *p,int pos)
{
    if(p->top-pos+1<0)   //index = top-pos+1
    {
        printf("Invalid position.\n");
        return -1;
    }
    else{
        return p->top-pos+1;  //position is taken from the top of the stack.
    }
}

int stacktop(struct stack *p){
    if(p->top==-1)
       return -1;
    else 
       return p->s[p->top];
}

int isEmpty(struct stack *p)
{
    if(p->top==-1)
       return 1;
    else 
       return 0;
}

int isFull(struct stack *p)
{
    if(p->top==p->size-1)
       return 1;
    else
       return 0;
}

int main(){
    struct stack *p;
    create(p);
    push(p,10);
    push(p,20);
    push(p,30);
    printf("%d\n",pop(p));
    
    return 0;
}