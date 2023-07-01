//
//  main.c
//  BFS_assignment
//
//  Created by R.AMOGH on 07/06/23.
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include <stdbool.h>

struct gNode{
int data;
char colour;
int distanceFromSource;
int predecessor;
struct gNode* next;
};

struct queueNode{
struct gNode *vertice;
struct queueNode *next;};

struct queue{
struct queueNode *front;
struct queueNode *rear;
};

void enqueue(struct queue *q,struct gNode * vertice){
    if(q->front==NULL && q->rear==NULL){
        struct queueNode* temp = (struct queueNode *)malloc(sizeof(struct queueNode));
        temp->vertice = vertice;
        temp->next = NULL;
        q->rear = q->front = temp;
    }
    else{
        struct queueNode* temp = (struct queueNode *)malloc(sizeof(struct queueNode));
        temp->vertice = vertice;
        q->rear->next = temp;
        temp->next = NULL;
        q->rear = temp;}
}

struct gNode* dequeue(struct queue *q){
    if(q->front==q->rear){
        struct gNode *temp = q->front->vertice;
        struct queueNode *p = q->front;
        q->front = NULL;
        q->rear = NULL;
        free(p);
        return temp;
    }
    else{
        struct gNode *temp = q->front->vertice;
        struct queueNode *p = q->front;
        temp = q->front->vertice;
        q->front = q->front->next;
        free(p);
        return temp;
    }
}


bool isEmpty(struct queue *q){
    if(q->front==NULL && q->rear==NULL){return true;}
    else{return false;}
}

void insert(struct gNode *list[],int from, int to){
struct gNode* temp = (struct gNode *)malloc(sizeof(struct gNode));
temp->data = to;
temp->colour = 'w';
temp->distanceFromSource = INT_MAX;
temp->predecessor = -1;
temp->next = list[from];
list[from] = temp;
}

//Fucntion to mark all the vertices
//void mark(struct gNode *adjList[],int VertexData,int numberOfVertices,char col,int distance,int pred){
//    for(int i = 0;i<numberOfVertices;i++){
//        struct gNode *temp = adjList[i]->next;
//        while (temp!=NULL) {
//            if(temp->data==VertexData){
//                temp->colour = col;
//                temp->predecessor = pred;
//                temp->distanceFromSource = distance;
//            }
//            temp = temp->next;
//        }
//    }
//}
void mark(struct gNode *adjList[], int rootVertexData,int numberOfVertices, char col, int distance, int pred) {
    struct gNode *root = NULL;
    for (int i = 0; i < numberOfVertices; i++) {
        if (adjList[i]->data == rootVertexData) {
            root = adjList[i];
            break;
        }
    }
    if (root == NULL) {
        return;
    }
    root->colour = col;
    root->predecessor = pred;
    root->distanceFromSource = distance;
    struct gNode *temp = root->next;
    while (temp != NULL) {
        if (temp->colour == 'w') {
            mark(adjList, temp->data,numberOfVertices,col, distance + 1, rootVertexData);
        }
        temp = temp->next;
    }
}

void breadthFirstSearch(struct gNode *adjList[],int rootVertexData,int numberOfVertices,struct queue *q){
    //Marking the root
    mark(adjList,rootVertexData,numberOfVertices,'g',0,-1);
    enqueue(q,adjList[rootVertexData]);
    while (!isEmpty(q)) {
        struct gNode *temp = dequeue(q);
        int currentRootsData = temp->data;
        int currentVertexDistanceFromSource = temp->distanceFromSource;
        int currentVertexPredecessor = temp->predecessor;
        temp = temp->next;
        while (temp!=NULL) {
            if(temp->colour=='w'){
                mark(adjList,temp->data,numberOfVertices,'g',currentVertexDistanceFromSource+1,currentRootsData);
                enqueue(q, adjList[temp->data]);
            }
            temp = temp->next;
        }
        mark(adjList, currentRootsData, numberOfVertices, 'b', currentVertexDistanceFromSource, currentVertexPredecessor);
    }

}

int getDistanceFromSource(struct gNode *adj[],int a,int vertices){
    int returnValue = INT_MAX;
    for(int i = 0;i<vertices;i++){
        struct gNode* temp = adj[i]->next;
        while (temp!=NULL) {
            if(temp->data==a){
                returnValue = temp->distanceFromSource;
                return returnValue;
            }
            temp = temp->next;
        }
    }
    return returnValue;
}

void printEdge(struct gNode *adj[],int a, int b, FILE *output,int vertices){
    struct gNode *temp = adj[a]->next;
    bool flag = false;
    while(temp!=NULL){
        if(temp->data==b){
            fprintf(output,"%d",getDistanceFromSource(adj,b, vertices)-getDistanceFromSource(adj, a, vertices));
            flag = true;
        }
        temp = temp->next;
    }
    if(flag==false){
        fprintf(output, "%d",-1);
    }
}

int main(int argc,char **argv){
//Open file
    FILE *inputFile = fopen(argv[1],"r");
    FILE *outputFile = fopen("sd.txt","w");
//Declaring some variables
int numberOfVertices = 0,numberOfEdges = 0;
int fromVertex = -1, toVertex = -1;

//Initializing a queue variable
struct queue *q =(struct queue *)malloc(sizeof(struct queue));
q->front = NULL;
q->rear = NULL;

//Reading first line
fscanf(inputFile,"%d %d",&numberOfVertices,&numberOfEdges);

//Creating a Adjacncy List
    struct gNode* adjList[numberOfVertices];
    for (int i = 0; i < numberOfVertices; i++) {
    adjList[i] = NULL;
    }


while(fscanf(inputFile,"%d %d",&fromVertex,&toVertex)==1)
{
insert(adjList,fromVertex,toVertex);
}

//Doing a Breadth First Search
    breadthFirstSearch(adjList, 0, numberOfVertices, q);


//Writing the output
//    rewind(inputFile);
//    int a = 0, b = 0;
//    fscanf(inputFile, "%d %d",&a,&b);
//    while (fscanf(inputFile, "%d %d",&a,&b)==2) {
//        printEdge(adjList,a,b,outputFile,numberOfVertices);
//        fprintf(outputFile, "\n");
//    }


    for(int k = 0;k<numberOfVertices;k++){
        printEdge(adjList, 0, k, outputFile, numberOfVertices);
        fprintf(outputFile, "\n");
    }
    fclose(inputFile);
    fclose(outputFile);

return 0;
}



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define INF 99999999
//
//int main(int argc,char **argv) {
//    int n, m;
//    int u, v;
//    int i, j, k;
//
//
//    // Open the graph file for reading
//    FILE *fp = fopen(argv[1],"r");
//    FILE *outputFile = fopen("sd.txt","w");
//    if (fp == NULL) {
//        fprintf(stderr, "Error: could not open graph file.\n");
//        exit(EXIT_FAILURE);
//    }
//
//    // Read the number of vertices and edges from the file
//    fscanf(fp, "%d %d", &n, &m);
//    int dist[n][m];
//    // Initialize the distance matrix
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            if (i == j) {
//                dist[i][j] = 0;
//            } else {
//                dist[i][j] = INF;
//            }
//        }
//    }
//
//    // Read the edges from the file and update the distance matrix
//    for (i = 0; i < m; i++) {
//        fscanf(fp, "%d %d", &u, &v);
//        dist[u][v] = 1;
//        dist[v][u] = 1; // if the graph is undirected
//    }
//
//    // Compute shortest paths using Floyd-Warshall algorithm
//    for (k = 0; k < n; k++) {
//        for (i = 0; i < n; i++) {
//            for (j = 0; j < n; j++) {
//                if (dist[i][k] + dist[k][j] < dist[i][j]) {
//                    dist[i][j] = dist[i][k] + dist[k][j];
//                }
//            }
//        }
//    }
//    rewind(fp);
//    fscanf(fp, "%d %d", &n, &m);
//    // Read vertex pairs from standard input and output their distances
//    for(int i = 0;i<n;i++) {
//        if (dist[0][i] == INF) {
//            fprintf(outputFile,"-1\n");
//        } else {
//            fprintf(outputFile,"%d\n", dist[0][i]);
//        }
//    }
//
//    // Close the file and exit
//    fclose(fp);
//    fclose(outputFile);
//    return 0;
//}
