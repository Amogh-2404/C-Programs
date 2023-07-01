//
//  main.c
//  Stack_assignment
//
//  Created by R.AMOGH on 21/04/23.
//
// COMPLETELY TESTED.

#include <stdio.h>
#include<stdlib.h>
//stack_array.h
#include <stdio.h>
#include <stdbool.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char *s_array;
};
char dummy;//printing variable
char pop(struct stack *st);
void push(struct stack *st,char x);
char stacktop(struct stack *st);
bool isEmpty(struct stack *st);
bool isFull(struct stack *st);
void display_stack(struct stack *st);


//Stack_array.c
char pop(struct stack *st)
{
    char x = st->s_array[st->top];
    st->s_array[st->top] = '\0';
    st->top--;
    return x;
}
void push(struct stack *st,char x)
{
    if(st->top==(st->size)-1)
        printf("Stack overflow.\n");
    else{
        st->top++;
        st->s_array[st->top] = x;}
    
}
char stacktop(struct stack *st)
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
void display_stack(struct stack *st){
    for(int i=0;i<=st->top;i++){
        printf("%c ",st->s_array[i]);
    }
    printf("\n");
}


//conversion code
void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap_paren(char *str){
    int k = 0;
    while(str[k]!='\0'){
        if(str[k]=='(')
            str[k++]=')';
        else if(str[k]==')')
            str[k++] = '(';
        else
            k++;
        
    }
}

void string_reverse(char *str){
    int first=0,last = 0;
    while(str[last] != '\0'){
        last++;
    }
    last--;
    while (first<last) {
        swap(&str[first++],&str[last--]);
    }
}

int isoperand(char a)
{
    if(a=='+'||a=='-')
        return 0;
    else if(a=='*'||a=='/'||a=='%')
        return 0;
    else if(a=='(')
        return 0;
    else if(a=='^')
        return 0;
    else if(a=='('||a==')')
        return 0;
    else
        return 1;
}

int isparen(char a)
{
if(a=='(' || a==')')
  return 1;
else
  return 0;
}

int isoperator(char a)
{
if(!isoperand(a) && !isparen(a))
  return 1;
else
  return 0;
}

int precedence(char a)
{
    if(a=='+'||a=='-')
        return 1;
    else if(a=='*'||a=='/'||a=='%')
        return 2;
    else if(a=='(')
        return 0;
    else if(a=='^')
        return 3;
    else
        return 4;
    
}

/*----------------Exceptional handling code begins----------------------------------*/
int checkParen(char *infix)
{
    //Stack initialization
    const int STRUCT_SIZE_2 = strlen(infix);
    struct stack temp;
    temp.top = -1;
    temp.size = STRUCT_SIZE_2;
    temp.s_array = (char*)malloc(STRUCT_SIZE_2*sizeof(char));
    for(int i=0;i<STRUCT_SIZE_2;i++){
        temp.s_array[i]='n';
    } 
    int travind = 0;
    while (infix[travind]!='\0') {
        if(infix[travind]=='('){
            push(&temp,infix[travind]);
            travind++;
        }
        else if(infix[travind]==')'){
            if(!isEmpty(&temp)){
                pop(&temp);
                travind++;
            }
            else{
                return 0;
            }
        }
        else{travind++;}
        
    }
    if(isEmpty(&temp)){
        return 1;
    }
    else{
        return 0;
    }
}

void invalid_expression(char * infix,FILE *optr)
{
    //PRANENTHESES COUNTING
            if(checkParen(infix)==0){
        fprintf(optr,"Unequal Parathesis\n");
        exit(5);}
int lead = 1, prev = 0 ;
while(infix[lead]!='\0')
{
// NO consecutive operators or operands
if((isoperand(infix[lead])) && (isoperand(infix[prev]))){
    fprintf(optr,"Invalid expression\n");
exit(1);
}
else if((isoperator(infix[lead])&&isoperator(infix[prev])) == 1)
{
    fprintf(optr,"Invalid expression\n");
exit(2);
}
else if((infix[lead]==')') && (infix[prev]=='('))
{ //No empty brackets
    fprintf(optr,"Invalid expression\n");
exit(3);
}
else if((infix[lead]=='(') && (infix[prev]==')'))
{ //No empty brackets
    fprintf(optr,"Invalid expression\n");
exit(4);
}
//else if((isoperator(infix[lead])&&isoperator(infix[prev])))
//{
//    fprintf(optr,"Invalid expression\n");
//exit(2);
//}
else
{
    lead++;
    prev++;
}
}
int operandcount = 0 , operatorcount = 0;
lead = 1, prev = 0;

//Counting the number of operator and operands
while(infix[prev]!='\0')
{
if(isoperand(infix[prev])){
operandcount+=1;
    prev++;
}
else if(!(isparen(infix[prev])) && !(isoperand(infix[prev]))){
operatorcount+=1;
    prev++;
}
else{prev++;}
}

//operandcount-operatorcount must be 1
if(operandcount-operatorcount !=1){
    fprintf(optr,"Invalid Expression\n");
exit(4);
}

return;
}



/*----------------Exceptional handling code ends----------------------------------*/
//Driver code
int main(int argc,char* argv[]) {
    //Taking input from a file
    char infix[100]= "",postfix[100]= "",prefix[100]= "";
    FILE *inptr = fopen(argv[1],"r");
    FILE *optr = fopen("output.txt","w");
    fscanf(inptr,"%s",infix);
    
    //Stack initialization
    const int STRUCT_SIZE = strlen(infix);
    struct stack st;
    st.top = -1;
    st.size = STRUCT_SIZE;
    st.s_array = (char*)malloc(STRUCT_SIZE*sizeof(char));
    for(int i=0;i<STRUCT_SIZE;i++){
        st.s_array[i]='n';
    }
    
//    Checking for execeptions
    invalid_expression(infix,optr);
    
    //Converting into prefix
    int j = 0,k=0;
    while(infix[j]!='\0'){
        
        //If its a parenthesis
        if(infix[j]=='('){
            dummy = infix[j];
            push(&st,infix[j++]);
            fprintf(optr,"%c is pushed into the stack.\n",dummy);}
        else if (infix[j]==')'){
            j++;
            while (stacktop(&st)!='('){
                dummy = pop(&st);
                fprintf(optr,"%c is popped from the stack.\n",dummy);
                postfix[k++] = dummy;
            }
            st.s_array[st.top]='n';
            st.top--;
            fprintf(optr,"( is popped from the stack.\n");
        }
        // Insert the condition for unary operators here
        else{
            if(isoperand(infix[j]))   //If it is an operand
                postfix[k++] = infix[j++];
            else
            {
                if(precedence(infix[j])>precedence(stacktop(&st))||isEmpty(&st)){ //If it is an operator check the precedence and then take action.
                    dummy = infix[j];
                    push(&st,infix[j++]);
                    fprintf(optr,"%c is pushed into the stack.\n",dummy);}
                else{
                    dummy = pop(&st);
                    fprintf(optr,"%c is popped from the stack.\n",dummy);
                    postfix[k++] = dummy;}
            }
        }
    }
    //Emptying the stack
    if(!isEmpty(&st))
    {
        while(!isEmpty(&st)){
            dummy = pop(&st);
            fprintf(optr,"%c is popped from the stack.\n",dummy);
            postfix[k++] = dummy;
        }
    }
    //printing postfix
    postfix[k]='\0';
    fprintf(optr,"Postfix expression is: %s\n",postfix);
    fclose(inptr);
    fclose(optr);
    return 0;
}

