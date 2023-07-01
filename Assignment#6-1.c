//
//  main.c
//  Best BFS
//
//  Created by R.AMOGH on 10/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct properties{
    int distance;
    int colour;
};
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

void BFS(int** graph,struct properties ver[],int source,int V,struct queue* qu){
    int u = -1;
    enqueue(qu,source);
    ver[source].colour = 1;
    ver[source].distance = 0;
    while(!isEmpty(qu)){
        u = dequeue(qu);
        for(int i = 0;i<V;i++){
            if(graph[u][i]!=INT_MAX && ver[i].colour==0){
                enqueue(qu,i);
                ver[i].colour = 1;
                ver[i].distance = ver[u].distance + graph[u][i];
            }
        }
        ver[u].colour = 2;
    }
}

void report(struct properties* ver,FILE* output,int V){
    for(int i = 0;i<V;i++){
        if(ver[i].distance!=INT_MAX){
            fprintf(output,"%d\n",ver[i].distance);}
        else{fprintf(output,"%d\n",-1);}
    }
}

int main(int argc, const char * argv[]) {
    //Initalizing some variables
    int numberOfVertices = 0;
    int numberofEdges = 0;
    int fromVertex = 0;
    int toVertex = 0;
    
    //Reading the file
    FILE *inputFile = fopen(argv[1],"r");
    FILE *outputFile = fopen("graph.txt","w");
    
    fscanf(inputFile,"%d %d",&numberOfVertices,&numberofEdges);
    //Creating a matrix of required size
    int **myGraph;
    myGraph = (int**)malloc(numberOfVertices * sizeof *myGraph);
    for (int i=0; i<numberOfVertices; i++)
    {
        myGraph[i] = (int*)malloc(numberOfVertices * sizeof *myGraph[i]);
    }
    //A temporary matrix
//    int **temp;
//    temp = malloc(numberOfVertices * sizeof *temp);
//    for (int i=0; i<numberOfVertices; i++)
//    {
//        temp[i] = malloc(numberOfVertices * sizeof *temp[i]);
//    }
    //initializing my matrix
    for(int i = 0;i<numberOfVertices;i++){
        for(int j =0;j<numberOfVertices;j++){
            if(i==j)
                myGraph[i][j] = INT_MAX;
            else
                myGraph[i][j] = INT_MAX;
        }
    }
    
    //Reading the inputs
    while (1) {
        fscanf(inputFile,"%d %d",&fromVertex,&toVertex);
        if(feof(inputFile)){
            break;}
        else{
            myGraph[fromVertex][toVertex] = 1;
            myGraph[toVertex][fromVertex] = 1;
        }
    }

    //Creating an array of structures
    struct properties vertices[numberOfVertices];
    for(int i = 0;i<numberOfVertices;i++){
        vertices[i].distance = INT_MAX;
        vertices[i].colour = 0;
    }
    
    //Declaring and initializing a necessary queue
    struct queue * qu = (struct queue *)malloc(sizeof(struct queue));
    qu->first = NULL;
    qu->last = NULL;
    
    int source = 0;
    BFS(myGraph,vertices,source,numberOfVertices,qu);
    
    report(vertices,outputFile,numberOfVertices);
    free(qu);
    for(int i = 0;i<numberOfVertices;i++){
        free(myGraph[i]);
    }
    free(myGraph);
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}
