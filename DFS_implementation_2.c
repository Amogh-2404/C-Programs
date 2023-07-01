//
//  main.c
//  Depth_first_search
//
//  Created by R.AMOGH on 14/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>


/*0-White
  1-Grey
  2-Black*/

struct node{
    int data;
    struct node *next;
};

struct properties{
    int color;
    int predecessor;
    int startTime;
    int endTime;
    int distancefromSource;
};
int T = 0; //Global definition of time

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

// Helper function for qsort to compare integers
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void DFSVISIT(struct node *graph[],int V,int number,struct properties* props,FILE *output){
    fprintf(output,"%d ",number);
    T+=1;
    props[number].startTime = T;
    props[number].color = 1;
    
    struct node *temp = graph[number];
    
    // Create an array to store the available neighbors of the current vertex
    int num_neighbors = 0;
    int neighbors[V];
    
    while(temp!=NULL){
        if(props[temp->data].color==0){
            neighbors[num_neighbors] = temp->data;
            num_neighbors++;
        }
        temp = temp->next;
    }
    
    // Sort the available neighbors in ascending order
    qsort(neighbors, num_neighbors, sizeof(int), compare);
    
    // Visit the neighbors in ascending order
    for(int i = 0;i<num_neighbors;i++){
        if(props[neighbors[i]].color==0){
            props[neighbors[i]].predecessor = number;
            DFSVISIT(graph, V, neighbors[i], props,output);
        }
    }
    
    props[number].color = 2;
    T+=1;
    props[number].endTime = T;
}

void print_results(int V,struct properties prop[],FILE *output){
    for(int i = 0;i<V;i++){
        fprintf(output,"%d %d %d\n",i,prop[i].startTime,prop[i].endTime);
    }
    for(int i = 0;i<V;i++){
        fprintf(output,"%d %d %d\n",i,prop[i].predecessor,prop[i].);
    }
}
int main(int argc, const char * argv[]) {
    //Reading the file for number of vertices
    FILE *inputFile = fopen(argv[1],"r");
    FILE *outputFile = fopen("dfs.txt","w");
    int numberOfVertices = 0, numberOfEdges = 0,fromVertex = 0,toVertex = 0;
    fscanf(inputFile, "%d %d",&numberOfVertices,&numberOfEdges);
    
    //Creating and initializing some essential variables
    struct properties propArray[numberOfVertices];
    //Initializing propArray
    for(int i = 0;i<numberOfVertices;i++){
        propArray[i].color = 0;
        propArray[i].startTime = INT_MAX;
        propArray[i].endTime = INT_MAX;
        propArray[i].predecessor = -1;
    }
    
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
    
    
    //Selecting source
    int source = 0;
    
    //Performing DFS
    for(int i = 0;i<numberOfVertices;i++){
        if(propArray[i].color==0){
            DFSVISIT(graph, numberOfVertices, i, propArray,outputFile);
            fprintf(outputFile,"\n");
        }
    }
    
    //Printing the result i.e, starting and ending times
    print_results(numberOfVertices, propArray, outputFile);
    //Closing the File
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

