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

void DFSVISIT(struct node *graph[],int V,int number,struct properties* props,FILE *output){
    fprintf(output,"%d ",number);
    T+=1;
    props[number].startTime = T;
    props[number].color = 1;
    struct node *temp = graph[number];
    while(temp!=NULL){
        if(props[temp->data].color==0){
            props[temp->data].predecessor = number;
            DFSVISIT(graph, V, temp->data, props,output);
        }
        temp = temp->next;
    }
    props[number].color = 2;
    T+=1;
    props[number].endTime = T;
}

void print_results(int V,struct properties prop[],FILE *output){
    for(int i = 0;i<V;i++){
        fprintf(output,"%d %d\n",prop[i].startTime,prop[i].endTime);
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
