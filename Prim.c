//
//  main.c
//  Prim's Algorithm
//
//  Created by R.AMOGH on 17/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

//Additional function min
int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

//Function to calculate MST using Prim's Algorithm
int PrimMST(int **graph,int V){
    //Creating a Key array and initializing a variable to store the final cost
    int key[V],minimumCost = 0;
    
    //initializing the key array
    for(int i = 0;i<V;i++){
        key[i] = INT_MAX;
    }
    
    //Starting from vertex zero
    key[0] = 0;
    
    //Additionaly also creating a boolean array to keep track of the vertices in the tree
    bool spanningSet[V];
    for(int i = 0;i<V;i++){
        spanningSet[i] = false;
    }
    
    //To choose the minimum among the available edges
    for(int count = 0;count<V;count++){
        int u = -1;
        for(int i = 0;i<V;i++){
            if(!spanningSet[i] && (u==-1 || key[i]<key[u]))
                u = i;
        }
        
        spanningSet[u] = true; //The best vertex choice is made
        
        
        if (key[u] != INT_MAX) {
                    minimumCost += key[u];  //Updating minimum cost
                }
        
        for(int v = 0;v<V;v++){
            if(graph[u][v]!=0 && !spanningSet[v]){
                key[v] = min(key[v],graph[u][v]);
            }
        }
    }
    return minimumCost;
}


int main(int argc, const char * argv[]) {
    // Preparing file pointers
    FILE* inputFile = fopen(argv[1],"r");
    FILE* outputFile = fopen("Prim.txt", "w");
    
    //Declaring some variables
    int numberOfVertices = 0,numberOfEdges = 0;
    int fromVertex = 0, toVertex = 0, edgeWeight = 0;
    fscanf(inputFile, "%d %d",&numberOfVertices,&numberOfEdges);
    
    //Creating an Adjacency matrix of required size and intializing it
    // Allocate memory for the matrix
    int **graph = (int **) malloc(numberOfVertices * sizeof(int *));
    for (int i = 0; i < numberOfVertices; i++) {
        graph[i] = (int *) malloc(numberOfVertices * sizeof(int));
    }
    for(int i = 0;i<numberOfVertices;i++){
        for(int j = 0;j<numberOfVertices;j++){
            graph[i][j] = 0;
        }
    }
    
    //Reading from the file and filling the matrix
    while (1) {
        fscanf(inputFile, "%d %d %d",&fromVertex,&toVertex,&edgeWeight);
        if(feof(inputFile)){
            break;
        }
        else{
            graph[fromVertex][toVertex] = edgeWeight;
        }
    }
    
    //Using Prim's algorithms on the graph to get MST
    int result = PrimMST(graph, numberOfVertices);
    
    fprintf(outputFile,"Minimum cost = %d\n",result);
    
    // Free the memory allocated for the matrix
    for (int i = 0; i < numberOfVertices; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}
