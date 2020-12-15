#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct{
  element **queue;
  int size;
  int front, rear;
  int count;
}Queue;

Queue *createQueue(int size){
  int i=0;
  Queue *pQueue=(Queue*)malloc(sizeof(Queue));
  if(pQueue==NULL) return NULL;

  pQueue->queue = (element**)malloc(size*sizeof(element*));
  for(i=0;i<size;i++){
    pQueue->queue[i]=(element*)malloc(sizeof(element)*100);
  }

  if(pQueue->queue==NULL){
    free(pQueue);
    return NULL;
  }
  pQueue->size = size;
  pQueue->front=0;
  pQueue->rear=0;
  pQueue->count=0;

  return pQueue;
}

int isFullQueue(Queue *pQueue){
  if((pQueue->rear+1)%pQueue->size ==pQueue->front) return 1;
  else return 0;
}

int isEmptyQueue(Queue *pQueue){
  if(pQueue->rear==pQueue->front) return 1;
  else return 0;
}

void enQueue(Queue *pQueue, element *item){
  char ch;
  int i=0;
  if(isFullQueue(pQueue)) printf("Queue is full !\n");
  
  else{
    pQueue->rear=(pQueue->rear+1)%pQueue->size;
    while(item[i]!=0){
      ch=item[i];
      pQueue->queue[pQueue->rear][i]=ch;
      i++;
    }
    pQueue->count++;
    /*printf("%d번째 item = %s\n",pQueue->rear,pQueue->queue[pQueue->rear]);
    printf("front %d, item = %s\n",pQueue->front,pQueue->queue[pQueue->front+1]);
    잘 들어가는지 확인*/
  }
}

element *deQueue(Queue *pQueue){
  element *k;
  if(isEmptyQueue(pQueue)){
    printf("Queue is empty !\n");
    return 0;
  }

  else{
    k=pQueue->queue[pQueue->front+1];
    pQueue->queue[pQueue->front]=0;
    pQueue->front=(pQueue->front+1)%pQueue->size;
    pQueue->count--;
  }
  return k;
}

element *queueFront(Queue *pQueue){
  return pQueue->queue[pQueue->front];
}

element *queueRear(Queue *pQueue){
  return pQueue->queue[pQueue->rear];
}

element *queueTop(Queue *pQueue){
  return pQueue->queue[pQueue->front+1];
}

void printQueue(Queue *pQueue){
  int f,r;
  Queue *temp;
  temp = pQueue;
  f=temp->front;
  r=temp->rear;
  while(f!=r){
    f=(f+1)%pQueue->size;
    printf(" %s%d",temp->queue[f],r-f+1);
  }
}

void destroyQueue(Queue *pQueue){
  int i;
  for(i=0;i<pQueue->size;i++){
    free(pQueue->queue[i]);
  }
  free(pQueue);
}
