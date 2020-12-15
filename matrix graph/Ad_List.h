#include <stdbool.h>
#include "Ad_Queue.h"

int compare(void* argu1, void* argu2){
    return strcmp((char*)argu1,(char*)argu2);
}

typedef struct{
    int count;
    struct vertex* first;
    int (*compare)(void* argu1, void* argu2);
}Graph;

typedef struct vertex{
    struct vertex* pNextVertex;
    void* dataPtr;
    int inDegree;
    int outDegree;
    int processed;
    struct arc* pArc;
}Vertex;

typedef struct arc{
    struct vertex* destination;
    struct arc* pNextArc;
}Arc;

Graph* createGraph(int c){
    Graph *g=(Graph*)malloc(sizeof(Graph));
    g->count=0;
    g->first=NULL;
    
    return g;
}

void destroyArc(Arc* arc){
    if(arc==NULL) return;
    
    Arc* arc1;
    arc1=arc->pNextArc;
    free(arc);
    destroyArc(arc1);
}

void destroyVertex(Vertex* v){
    if(v==NULL) return;
    
    Vertex* tem;
    tem=v->pNextVertex;
    destroyArc(v->pArc);
    free(v);
    destroyVertex(tem);
}

void destroyGraph(Graph* g){
    if(!g->first) return;
    
    destroyVertex(g->first);
    free(g);
}

void insertVertex(Graph* g, void* data){
    Vertex* newPtr;
    Vertex* temPtr;
    Vertex* prePtr;
    
    newPtr=(Vertex*)malloc(sizeof(Vertex));
    if(newPtr==NULL) return;
    
    newPtr->pNextVertex=NULL;
    newPtr->dataPtr=data;
    newPtr->inDegree=0;
    newPtr->outDegree=0;
    newPtr->processed=0;
    newPtr->pArc=NULL;
    (g->count)++;
    
    temPtr=g->first;
    if(!temPtr) g->first=newPtr;
    else{
        prePtr=NULL;
        while(temPtr!=NULL){
            prePtr = temPtr;
            temPtr= temPtr->pNextVertex;
        }
        if(!prePtr) g->first=newPtr;
        else prePtr->pNextVertex=newPtr;
        newPtr->pNextVertex = temPtr;
    }
    return;
}

int deleteVertex(Graph* g, void* key){
    Vertex* prePtr;
    Vertex* temPtr;
    
    if(g->first==NULL) return -2;
    
    prePtr=NULL;
    temPtr= g->first;
    while(temPtr!=NULL){
        prePtr = temPtr;
        temPtr= temPtr->pNextVertex;
    }
   if(temPtr==NULL) return -2;
   if((temPtr->inDegree>0)||(temPtr->outDegree)>0) return -1;
   if(prePtr==NULL) g->first = temPtr->pNextVertex;
   else prePtr->pNextVertex = temPtr->pNextVertex;
   g->count--;
   free(temPtr);
   return 1;
}

int insertArc(Graph* g, void* from, void* to){
    Arc* newArc;
    Arc* preArc;
    Arc* temArc;
    Vertex* fromVer;
    Vertex* toVer;
    
    newArc=(Arc*)malloc(sizeof(Arc));
    if(newArc==NULL) return 0;
    
    fromVer = g->first;
    while(fromVer!=NULL){
        fromVer = fromVer->pNextVertex;
    }
    if(fromVer==NULL) return -2;
    
    toVer = g->first;
    while(toVer!=NULL){
        toVer=toVer->pNextVertex;
    }
    if(toVer==NULL) return -3;
    
    fromVer->outDegree++;
    toVer->inDegree++;
    newArc->destination = toVer;
    
    if(fromVer->pArc==NULL){
        fromVer->pArc= newArc;
        newArc->pNextArc=NULL;
        return 1;
    }
    
    preArc=NULL;
    temArc=fromVer->pArc;
    while(temArc!=NULL){
        preArc = temArc;
        temArc = temArc->pNextArc;
    }
    
    if(preArc==NULL) fromVer->pArc = newArc;
    else preArc->pNextArc = newArc;
    
    newArc->pNextArc = temArc;
    free(temArc);
    return 1;
}

int deleteArc(Graph* g, void* from, void* to){
    Vertex* fromVer;
    Vertex* toVer;
    Arc* preArc;
    Arc* temArc;
    
    if(g->first==NULL) return -2;
    
    fromVer = g->first;
    
    while(fromVer!=NULL){
        fromVer = fromVer->pNextVertex;
    }
    
    if(fromVer==NULL) return -2;
    
    if(fromVer->pArc==NULL) return -3;
    
    preArc = NULL;
    temArc = fromVer->pArc;
    
    while(temArc){
        preArc = temArc;
        temArc=temArc->pNextArc;
    }
    
    if(temArc==NULL) return -3;
    
    toVer = temArc->destination;
    
    fromVer->outDegree--;
    toVer->inDegree--;
    
    if(preArc==NULL) fromVer->pArc = temArc->pNextArc;
    else preArc->pNextArc = temArc->pNextArc;
    
    free(temArc);
    return 1;
}

void depthTraversal(Vertex* root){
    Arc *arc =NULL;
 
    if(root->processed) return;
    
    for(arc=root->pArc; arc!=NULL; arc=arc->pNextArc){
        printf(" %c",*(char*)root->dataPtr);
        if(!(arc->destination->processed)) depthTraversal(arc->destination);
    }
}

void breadthTraversal(Graph *g){
    Queue *qt=createQueue(20);
    
}

void printVertex(Vertex* root){
    //if(root->dataPtr==NULL) return;
    printf(" %c",*(char*)root->dataPtr);
    printVertex(root->pNextVertex);
}
