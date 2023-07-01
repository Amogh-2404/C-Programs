//
//  main.c
//  DFS_AGAIN
//
//  Created by R.AMOGH on 30/06/23.
//

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct properties{
    int predecessor;
    int colour;
    int key;  //Distance from source
    int startTime;
    int endTime;
};
int Time = 0;
//THE MONSTER, THE LEGEND, THE DFS
void DFS(int **graph,struct properties* ver,int vertice,int V){
    Time += 1;
    ver[vertice].startTime = Time;
    ver[vertice].colour = 1;
    for(int i = 0;i<V;i++){
        if(graph[vertice][i]!=INT_MAX){
            if(ver[i].colour == 0){
                ver[i].predecessor = vertice;
                ver[i].key = ver[vertice].key + 1;
                DFS(graph, ver, i, V);
            }
            
        }
    }
    ver[vertice].colour = 2;
    Time+=1;
    ver[vertice].endTime = Time;

}

//printing the results
void report(struct properties *vertices,FILE *output,int V){
    for(int i = 0;i<V;i++){
        fprintf(output,"%d %d %d %d %d\n",i,vertices[i].predecessor,vertices[i].startTime,vertices[i].endTime,vertices[i].key);
    }
}
int main(int argc, const char * argv[]) {
    /*This code is designed to take inputs form a file in the form
    numberofvertices numberofedges
     fromVertex      toVertex
     Note that the graph is considered to be undirected and thus mentioning the edges once would be fine.*/
    
    //Getting files ready for input
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen("output.txt","w");
    
    //Reading essentials from the file;
    int numberOfVertices = 0,numberOfEdges = 0, fromVertex = -1,toVertex = -1;
    fscanf(input, "%d %d",&numberOfVertices,&numberOfEdges);
    
    
    //Creating an Adjacency matrix of required size and intializing it
      // Allocate memory for the matrix
      int **graph = (int **) malloc(numberOfVertices * sizeof(int *));
      for (int i = 0; i < numberOfVertices; i++) {
          graph[i] = (int *) malloc(numberOfVertices * sizeof(int));
      }
      for(int i = 0;i<numberOfVertices;i++){
          for(int j = 0;j<numberOfVertices;j++){
              graph[i][j] = INT_MAX;
          }
      }
    //Creating an array of structs
    struct properties vertices[numberOfVertices];
    for(int i = 0;i<numberOfVertices;i++){
        vertices[i].key = INT_MAX;
        vertices[i].colour = 0;
        vertices[i].startTime = -1;
        vertices[i].endTime = -1;
        vertices[i].predecessor = -1;
    }
    //Reading from the file
    while(1){
        if(feof(input)){break;}
        else{
            fscanf(input, "%d %d",&fromVertex,&toVertex);
            graph[fromVertex][toVertex] = 1;
            graph[toVertex][fromVertex] = 1;
        }
    }
    
    //calling DFS
    int source = 0;
    vertices[0].key = 0;
    for(int i = 0;i<numberOfVertices;i++){
        if(vertices[i].colour == 0){
            DFS(graph,vertices,i,numberOfVertices);
        }
    }
    
    report(vertices, output, numberOfVertices);
    
    return 0;
}
