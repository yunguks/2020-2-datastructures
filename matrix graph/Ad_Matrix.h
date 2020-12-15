#include <stdio.h>
#include <stdlib.h>
#include "Ad_Queue.h"

typedef struct{
    int vertex;
    int **Node;
}Graph;

Graph* createGraph(int number){
    int i;
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->vertex=number;
    graph->Node=(int**)malloc(sizeof(int*)*number);
    
    for(i=0;i<number;i++){
        graph->Node[i]=(int*)malloc(sizeof(int)*number);
        
    }
    return graph;
}

int visit1[100]={};
int visit2[100]={};

void newEdge(Graph* graph,int startNode, int endNode){
    if(graph->vertex<(startNode-1)||graph->vertex<(endNode)-1) {
        printf("그래프 정점 번호 오류\n");
        return;
    }
    graph->Node[startNode][endNode]=1;
}

void printGraph(Graph *graph){
    int i,j;
    for(i=0;i<graph->vertex;i++){
        for(j=0;j<graph->vertex;j++){
            printf(" [%d]",graph->Node[i][j]);
        }
        printf("\n");
    }
}

void destroyGraph(Graph *graph){
    int i;
    for(i=0;i<graph->vertex;i++){
        free(graph->Node[i]);
    }
    free(graph->Node);
    free(graph);
}

void depthTraversal(Graph *g, int start,char* ver){
    int k;
    visit1[start]=1;
    printf(" %c",ver[start]);
    for(k=0;k<g->vertex;k++){
        if(g->Node[start][k]&&!visit1[k]) depthTraversal(g,k,ver);
    }
}

void breadthTraversal(Graph *g, int start,char* ver){
    int k,i;
    char c;
    Queue *qt=createQueue(20);
    visit2[start]=1;
    enQueue(qt,ver[start]);
    while(!isEmptyQueue(qt)){
        c = deQueue(qt);
        printf(" %c",c);
        i=0;
        while(c!=ver[i]){
            i++;
        }
        for(k=0;k<g->vertex;k++){
            if(g->Node[i][k]&&!visit2[k]){
                visit2[k]=1;
                enQueue(qt,ver[k]);
            }
        }
    }
}