//
//  main.c
//  CLRS_matrix_approach
//
//  Created by R.AMOGH on 11/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

/*0-white
  1-grey
  2-black*/

/*---------------------------------------Additional Queue Implementation-----------------------------------------*/
//Creating nodes using a structure
struct qnode{
    int data;
    struct qnode *next;
};
//Creating a circular queue using a structure
struct queue{
    struct qnode *first;
    struct qnode *last;
};

//enqueue function of the queue
void enqueue(struct queue *q,int x){
    //If it is the first element being enqueued
    if(q->first==NULL && q->last==NULL){
        struct qnode *temp = (struct qnode*)malloc(sizeof(struct qnode));
        temp->next = temp;
        temp->data = x;
        q->first = temp;
        q->last = temp;
    }
    else{ //If element is being enqueued in a queue with elements in it
        struct qnode *temp = (struct qnode*)malloc(sizeof(struct qnode));
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
        struct qnode *temp = qu->first;
        qu->first = qu->first->next;
        qu->last->next = qu->first;
        free(temp);
        return x;
    }
}

bool isEmpty(struct queue *q){
    if(q->first==NULL && q->last==NULL){
        return true;
    }
    else
        return false;
}
/*---------------------------------------Additional Queue Implementation-----------------------------------------*/


struct node{
    int data;
    struct node *next;
};

int min(int a,int b){
    return (a<b)?a:b;
}

void color_initializer(int arr[],int V){
    for(int i = 0;i<V;i++){
        arr[i] = 0;
    }
}

void distance_initializer(int arr[],int V){
    for(int i = 0;i<V;i++){
        arr[i] = INT_MAX;
    }
}

void insertToList(struct node* graph[],int a,int b){
    struct node* temp = (struct node *)malloc(sizeof(struct node));
    struct node* temp2 = (struct node *)malloc(sizeof(struct node));
    //For list of a
    if(graph[a]==NULL)
    {
        temp->data = b;
        temp->next = NULL;
        graph[a] = temp;
    }
    else{
        temp->data = b;
        temp->next = graph[a];
        graph[a] = temp;
    }
    
    //For List of B
    if(graph[b]==NULL)
    {
        temp2->data = a;
        temp2->next = NULL;
        graph[b] = temp2;
    }
    else{
        temp2->data = a;
        temp2->next = graph[b];
        graph[b] = temp2;
    }
}


void BFS(struct node *graph[],int color[],int distance[],struct queue *qu,int source){
    int u = -1;//temporary integer
    struct node *temp = NULL;//Traversal pointer

    enqueue(qu,source);
    while(!isEmpty(qu)){
        u = dequeue(qu);
        temp = graph[u];
        while (temp!=NULL) {
            if(color[temp->data]==0){
                color[temp->data] = 1;
                distance[temp->data] = distance[u] + 1;
                enqueue(qu, temp->data);
            }
            temp = temp->next;
        }
        color[u] = 2;
    }
}

void print_solution(int distance[],int V,FILE *output){
    for(int i = 0;i<V;i++){
        if(distance[i]==INT_MAX){fprintf(output, "%d\n",-1);}
        else{
            fprintf(output, "%d\n",distance[i]);}
    }
}

int main(int argc, const char * argv[]) {
    // Preparing file pointers
    FILE* inputFile = fopen(argv[1],"r");
    FILE* outputFile = fopen("sd.txt", "w");
    
    const int SOURCE = 0;//Defining a source
    //Declaring some variables
    int numberOfVertices = 0,numberOfEdges = 0;
    int fromVertex = 0, toVertex = 0;
    fscanf(inputFile, "%d %d",&numberOfVertices,&numberOfEdges);
    
    int colour[numberOfVertices];
    color_initializer(colour,numberOfVertices);
    int distaceFromSource[numberOfVertices];
    distance_initializer(distaceFromSource,numberOfVertices);
    
    //Declaring and initializing a necessary queue
    struct queue * qu = (struct queue *)malloc(sizeof(struct queue));
    qu->first = NULL;
    qu->last = NULL;
    
    //Declaring and initializing Adjacency List
    struct node* graph[numberOfVertices];
    for(int i = 0;i<numberOfVertices;i++){
        graph[i] = NULL;
    }
    //Reading input file
    while (1) {
        fscanf(inputFile, "%d %d",&fromVertex,&toVertex);
        if(feof(inputFile)){
            break;
        }
        else{
            insertToList(graph, fromVertex, toVertex);
        }
    }
    
    //Special initialization of source
    distaceFromSource[SOURCE] = 0;
    colour[SOURCE] = 1;
    BFS(graph,colour,distaceFromSource,qu,SOURCE);
    print_solution(distaceFromSource,numberOfVertices,outputFile);
    
    return 0;
}
