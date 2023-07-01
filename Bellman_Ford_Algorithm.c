//
//  main.c
//  Bellman_Ford
//
//  Created by R.AMOGH on 19/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>


void BELLMANFORD(int **graph,int distance[],int source,int V, int E){
    distance[source] = 0;
    for(int count = 0;count<V-1;count++){
        //Going through all the edges
        for(int k = 0;k<E;k++){
            if(distance[graph[1][k]] > (distance[graph[0][k]] + graph[2][k])){
                distance[graph[1][k]] = (distance[graph[0][k]] + graph[2][k]);
            }
        }
    }
    //For identifying the presence of negative cycles
//    for(int k = 0;k<E;k++){
//        if(distance[graph[1][k]] > (distance[graph[0][k]] + graph[2][k])){
//            printf("Negative Edge found\n");
//        }
//    }
}

int main(int argc, const char * argv[]) {
    //Opening Files to read and write
        FILE *inputFile = fopen(argv[1], "r");
        FILE *outputFile = fopen("Bellman-Ford.txt","w");
        
        //Declaring some necessary variables
        int fromVertex = 0,toVertex = 0,numberOfEdges = 0,numberOfVertices = 0,edgeWeight = 0;
        
        //Reading number of vertices and edges form the file
        fscanf(inputFile, "%d %d",&numberOfVertices,&numberOfEdges);
        
        //Creating an array of edges to represent the matrix, it would be of the form V X 3, where V is the number of vertices and each row has fromVertex,toVertex and edge weight respectively (Even for undirected grapha it is ok to follow this, no need to do it twice)
        
        // Allocate memory for the matrix
        int **graph = (int **) malloc(3 * sizeof(int *));
        for (int i = 0; i < 3; i++) {
            graph[i] = (int *) malloc(numberOfEdges * sizeof(int));
        }
        for(int i = 0;i<3;i++){
            for(int j = 0;j<numberOfEdges;j++){
                graph[i][j] = 0;
                
            }
        }
        
        //Some random variable to assist in inserting
        int dummy = 0;
        
        //Reading necessary inputs from the file line-by-line and updating our matrix
        while(1){
            if(feof(inputFile)){
                break;
            }
            else{
                fscanf(inputFile, "%d %d %d",&fromVertex,&toVertex,&edgeWeight);
                graph[0][dummy] = fromVertex;
                graph[1][dummy] = toVertex;
                graph[2][dummy] = edgeWeight;
                dummy++;
            }
        }

    //Creating addtional 'distance' array
    int distance[numberOfVertices];
    //Initializing to INT_MAX
    for(int i = 0;i<numberOfVertices;i++){
        distance[i] = INT_MAX;
    }
//Calling Bellman-Ford function
    BELLMANFORD(graph, distance, 0,numberOfVertices,numberOfEdges);
    
    //printing the results
    for(int i = 0;i<numberOfVertices;i++){
        fprintf(outputFile, "%d\n",distance[i]);
    }
    
    //Freeing up memory allocated for the graph
    for(int i = 0;i<3;i++){
        free(graph[i]);
    }
    free(graph);
    
    //Closing the files
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
