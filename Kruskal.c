//
//  main.c
//  Kruskal's_Algorithm
//
//  Created by R.AMOGH on 18/06/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

//Some Disjoint set associated functions
void Union(int arr[],int a,int b){
    if(arr[a]<arr[b]){  //Since the root elements are represented by negative integrs with value equal to number of vertices ,including them, in the set
        //Here weighted union is taken
        arr[a] =  arr[a] + arr[b];
        arr[b] = a;
    }
    else{
        arr[b]+=arr[a];
        arr[a] = b;
    }
}

//Finds the parent of the element i.e, unltimately which set it belongs to identified by the root element
int find(int arr[],int a){
    int x = a;
    while(arr[x]>0){  //Keeping going untill the negative value is found i.e, the root
        x = arr[x];}
    return x;
}

//The Kruskal Function
int Kruskal(int **graph,int set[],int included [],int E,int V){
    int cost = 0;
    int i = 0,j =0,k = 0,n = V,e = E,min = -1,u = -1,v = -1;
    while (i<n) {
        min = INT_MAX;
        for(int j = 0;j<e;j++)//Looks for the next minimum that is not included
        {
            if(included[j]==0 && graph[2][j]<min){
                min = graph[2][j];
                k = j;
                u = graph[0][j];
                v = graph[1][j];
            }
        }
        
        if(find(set, u)!=find(set,v)){
            Union(set, find(set, u), find(set, v)); //Performing union
            cost+=min;  //incrementing cost
        }
        included[k] = 1; //Marking the edge as included
        i++;
    }
    return cost;
}

int main(int argc, const char * argv[]) {
//Opening Files to read and write
    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen("Kruskal.txt","w");
    
    //Declaring some necessary variables
    int fromVertex = 0,toVertex = 0,numberOfEdges = 0,numberOfVertices = 0,edgeWeight = 0;
    
    //Reading number of vertices and edges form the file
    fscanf(inputFile, "%d %d",&numberOfEdges,&numberOfVertices);
    
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
    
    //Sorting the edges according to their weight
    
    
    //Creating additional two integer array, one for Disjoint-set operation and other to keep track of the included Edges
    //Also this set will have the number of the parent vertex at the corresponing member vertex if union is performed
    int setArray[numberOfVertices];
    int includedArray[numberOfEdges];
    //Initializing the setArray. Here I'm using -1 to denote it is a root i.e, parent of that set
    for(int i = 0;i<numberOfVertices;i++){setArray[i] = -1;}
    //Initializing the includedArray with zeros
    for(int i = 0;i<numberOfEdges;i++){includedArray[i] = 0;}
    
    //Calling the Kruskal function to calculate the cost
    int result = Kruskal(graph,setArray,includedArray,numberOfEdges,numberOfVertices);

    //Printing the result
    fprintf(outputFile,"Minimum Cost = %d\n",result);
    
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
