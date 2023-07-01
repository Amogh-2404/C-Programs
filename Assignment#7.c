//
//  main.c
//  Dijkstra’s algorithm
//
//  Created by R.AMOGH on 22/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

//Creating a structure used to represent the graph
struct edge {
    int fromVertex;
    int toVertex;
    int edgeWeight;
    struct edge *next;
};

//Globally declaring my graph
struct edge *Graph = NULL;

//function to add the edges to my graph
void addEdge(int from, int to, int edgeWeight) {
    struct edge* newEdge = (struct edge*)malloc(sizeof(struct edge));
    newEdge->fromVertex = from;
    newEdge->toVertex = to;
    newEdge->edgeWeight = edgeWeight;
    newEdge->next = Graph;
    Graph = newEdge;
}

//A function to get the edgeweight between two vertices
int weight(int u, int v){
    struct edge *temp = Graph;
    while(temp != NULL){
        if(temp->fromVertex == u && temp->toVertex == v){
            return temp->edgeWeight;
        }
        temp = temp->next;
    }
    return -1;
}

/*To avoid the implementation of priority queue, I'm using a function which finds the minimum edge from the given set of edges*/
int findMinDistance(long int distance[], bool visited[], int numVertices) {
    long int minDistance = LONG_MAX;
    int minVertex = -1;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i] && (minVertex == -1 || distance[i] < minDistance)) {
            //Only if the vertex is not visited and its distance is minimum among the other non visited vertices
            minDistance = distance[i];
            minVertex = i;
        }
    }
    return minVertex;
}


//The Dijksta algorithm
void Dijkstra(long int distance[],bool visited[],int numVertices, int source) {
    distance[source] = 0; //Initializing source distance from itself as 0
    
    for (int i = 0; i < numVertices - 1; i++) //So that we have visited all the vertex in the graph
    {
        //Storing the vertex with the minimum distance
        int minVertex = findMinDistance(distance, visited, numVertices);
        visited[minVertex] = true;  //Marking it as visited
        struct edge* traverser = Graph;
        //Exploring all the neighbouring vertices of that particular minVertex
        while(traverser!=NULL)
        {
            if(traverser->fromVertex==minVertex){
                int neighbor = traverser->toVertex;
                int edgeWeight = traverser->edgeWeight;
                //RELAX step
                if (!visited[neighbor] && distance[minVertex] != LONG_MAX && distance[minVertex] + edgeWeight < distance[neighbor]) {
                    distance[neighbor] = distance[minVertex] + edgeWeight;
                }
            }
            traverser = traverser->next;
        }
    }
}

void printResult (FILE *output, int numVertices, long int distance[], bool visited[], int source) {
    for(int i = 0;i<numVertices;i++){
//        if(visited[i] && i != source){
            if(distance[i]!=LONG_MAX){
                fprintf(output,"%d %ld\n",i,distance[i]);
            }
            else if(i == source){
                fprintf(output,"%d %d\n",i,0);  //If it is the source
            }
            else{
                fprintf(output,"%d %d\n",i,-1); //If the path does not exist
            }
        }
//        else if (visited[i] && i == source){
//            fprintf(output,"%d %d\n",i,0);
//        }
    }


int main(int argc, const char * argv[]) {
    //Opening Files to read and write
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen("dijkstra.txt","w");
    
    //Handling file not found exception
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }


    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    int SOURCE = atoi(argv[2]);  //Reading the source vertex number
    int fromVertex = 0,toVertex = 0,numberOfEdges = 0,numberOfVertices = 0,edgeWeight = 0;
    int maxVertex = 1;//To create distance and visited arrays

    //Reading necessary inputs from the file line-by-line and updating our matrix
    while(fscanf(inputFile, "%d %d %d",&fromVertex,&toVertex,&edgeWeight) == 3) {
        addEdge(fromVertex, toVertex, edgeWeight);
        if(fromVertex > maxVertex) {
            maxVertex = fromVertex;
        }
        if(toVertex > maxVertex) {
            maxVertex = toVertex;
        }
    }

    maxVertex += 1;   //To take care of the corner case

    //Auxillary arrays 'distance'- stores the distance from source to that particular vertex
    //'Visited'-keeps track of the visited vertex
    long int distance[maxVertex]; //Declared it as long int to handle any greater distances
    bool visited[maxVertex];

    //Initializing arrays
    for(int i = 0; i < maxVertex; i++){
        visited[i] = false;
        distance[i] = LONG_MAX;
    }
    distance[SOURCE] = 0;

    //Calling Dijkstra
    Dijkstra(distance, visited, maxVertex, SOURCE);

    //Printing the output to the output file
    printResult(outputFile, maxVertex, distance, visited, SOURCE);

    //Closing the file
    fclose(inputFile);
    fclose(outputFile);

    //Freeing the memory allocated step-by-step
    struct edge* temp = Graph;
    while(temp != NULL) {
        struct edge* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
