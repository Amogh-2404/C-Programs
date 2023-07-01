//
//  main.c
//  Assignment_4
//
//  Created by R.AMOGH on 30/05/23.
//References:- Textbook(Introduction to algorithms) and Notes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node{
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node* binaryTreeInsert(struct node *p,int x,FILE *Output)
{
    if(p==NULL){
        struct node *t =(struct node *)malloc(sizeof(struct node));
        t->data = x;
        fprintf(Output, "%d inserted\n",x);
        t->lchild=NULL;
        t->rchild=NULL;
        return t;
    }
    else{
        if(x>p->data){
            p->rchild = binaryTreeInsert(p->rchild, x, Output);
            
        }
        else if(x<p->data){
            p->lchild = binaryTreeInsert(p->lchild, x, Output);
        }
        return p;
    }
}

int binaryTreeSearch(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key > p->data)
        {
            return binaryTreeSearch(p->rchild, key);
        }
        else if (key < p->data)
        {
            return binaryTreeSearch(p->lchild, key);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void binaryTreePreorder(struct node *p,FILE *Output)
{
    if(p){
        fprintf(Output,"%d ",p->data);
        binaryTreePreorder(p->lchild,Output);
        binaryTreePreorder(p->rchild,Output);}
}

void binaryTreeInorder(struct node *p,FILE *Output)
{
   if(p){
        binaryTreeInorder(p->lchild,Output);
        fprintf(Output,"%d ",p->data);
        binaryTreeInorder(p->rchild,Output);}
}

void binaryTreePostorder(struct node *p,FILE *Output)
{
  if(p){
        binaryTreePostorder(p->lchild,Output);
        binaryTreePostorder(p->rchild,Output);
        fprintf(Output,"%d ",p->data);}
}

int binaryTreeMinimum(struct node* p){ //Searches for the leftmost node of the tree
    while (p!=NULL && p->lchild!=NULL) {
        p = p->lchild;
    }
    return p->data;
}


int binaryTreeMaximum(struct node* p){ //Searches for the leftmost node of the tree
    while (p!=NULL && p->rchild!=NULL) {
        p = p->rchild;
    }
    return p->data;
}


int binaryTreePredecessor(struct node* p,int x){
    struct node* predecessor = NULL; // to store the potential predecessor node
    struct node* current = p;

    while (current != NULL) {
        if (x > current->data) {
            predecessor = current;
            current = current->rchild;
        } else if (x < current->data) {
            current = current->lchild;
        } else {
            // node with given value found
            if (current->lchild != NULL) {
                // if left subtree exists, find rightmost node in left subtree
                struct node* temp = current->lchild;
                while (temp->rchild != NULL) {
                    temp = temp->rchild;
                }
                return temp->data;
            } else {
                // if left subtree does not exist, return predecessor
                if (predecessor == NULL) {
                    return -1; // no inorder predecessor found
                } else {
                    return predecessor->data;
                }
            }
        }
    }
    return -1; // value not found in tree
}


int binaryTreeSuccessor(struct node* p,int x){
        struct node* successor = NULL;  //to store the potential successor node
        struct node* current = p;

        while (current != NULL) {
            if (x < current->data) {
                successor = current;
                current = current->lchild;
            } else if (x > current->data) {
                current = current->rchild;
            } else {
                 //node with given value found
                if (current->rchild != NULL) {
                     //if right subtree exists, find leftmost node in right subtree
                    struct node* temp = current->rchild;
                    while (temp->lchild != NULL) {
                        temp = temp->lchild;
                    }
                    return temp->data;
                } else {
                     //if right subtree does not exist, return successor
                    if (successor == NULL) {
                        return -1;  //no inorder successor found
                    } else {
                        return successor->data;
                    }
                }
            }
        }
        return -1;  //value not found in tree
    }



//int binaryTreeSuccessor(struct node* p,int x){
//static int temp = -1;
//static int result = -1;
//if(p){
// binaryTreeSuccessor(p->lchild,x);
//if(temp==x){
//result = p->data;
//return result;
//}
//temp = p->data;
//binaryTreeSuccessor(p->rchild,x);
//}
//return result;
//}

//Driver code
int main(int argc, const char * argv[]) {
    //Just getting some variable ready to get input
    struct node *root = NULL;
    char command[50];
    int inputValue = -1;
    
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen("output.txt","w");
    
    if(inputFile==NULL){
        fprintf(outputFile,"File not found.\n");
    }else{

        char line[100];
        
        while (1) {
            // input part
            fscanf(inputFile,"%s",command);
            if((strcmp(command, "insert")==0) || (strcmp(command, "successor")==0) || (strcmp(command, "predecessor")==0) || (strcmp(command, "search")==0))
            {
                fscanf(inputFile,"%d",&inputValue);
            }
            if(feof(inputFile)) {
                           break;}

            if(strcmp(command, "insert")==0){
                if(binaryTreeSearch(root,inputValue)==0){
                    root = binaryTreeInsert(root,inputValue,outputFile);}
                else if(binaryTreeSearch(root,inputValue)==1){
                    fprintf(outputFile,"%d inserted\n",inputValue);
                }
            }
            else if(strcmp(command, "inorder")==0){
                binaryTreeInorder(root,outputFile);
                fprintf(outputFile, "\n");
            }
            else if(strcmp(command, "preorder")==0){
                binaryTreePreorder(root,outputFile);
                fprintf(outputFile, "\n");
            }
            else if(strcmp(command, "postorder")==0){
                binaryTreePostorder(root,outputFile);
                fprintf(outputFile, "\n");
            }
            else if(strcmp(command, "search")==0){
                int result = binaryTreeSearch(root,inputValue);
                if(result==1){fprintf(outputFile,"%d found",inputValue);}
                else{fprintf(outputFile,"%d not found",inputValue);}
                fprintf(outputFile, "\n");
            }
            else if(strcmp(command, "minimum")==0){
                if(root!=NULL){
                    int result = binaryTreeMinimum(root);
                    fprintf(outputFile,"%d\n",result);
                }
                else{
                    fprintf(outputFile, "\n");
                }
            }
            else if(strcmp(command, "maximum")==0){
                if(root!=NULL){
                    int result = binaryTreeMaximum(root);
                    fprintf(outputFile,"%d\n",result);
                }
                else{
                    fprintf(outputFile, "\n");
                }
            }
            else if(strcmp(command, "successor")==0){
                if(root==NULL){fprintf(outputFile, "Tree is empty\n");}
                else{
                   
                    if(binaryTreeSearch(root,inputValue)==0){
                        fprintf(outputFile,"%d does not exist\n",inputValue);
                    }
                    else if(binaryTreeMaximum(root) == inputValue){
                        fprintf(outputFile,"successor of %d does not exist\n",inputValue);
                    }
                    else{
                        int result = binaryTreeSuccessor(root,inputValue);
                        if(result!=-1){fprintf(outputFile,"%d\n",result);}
                    }
                }
                
            }
            else if(strcmp(command, "predecessor")==0){
                if(root==NULL){
                    fprintf(outputFile, "Tree is empty\n");
                }
                else{
                    
                    if(root!=NULL){
                        if(binaryTreeSearch(root,inputValue)==0){
                            fprintf(outputFile,"%d does not exist\n",inputValue);
                        }
                        else if(binaryTreeMinimum(root)==inputValue){
                            fprintf(outputFile,"predecessor of %d does not exist\n",inputValue);
                        }
                        else{
                            int result = binaryTreePredecessor(root,inputValue);
                            if(result!=-1){fprintf(outputFile,"%d\n",result);}
                        }
                    }
                }
            }
            else{fprintf(outputFile,"Invalid command\n");}
            
        }
        fclose(inputFile);
        fclose(outputFile);}
    
    return 0;
}
