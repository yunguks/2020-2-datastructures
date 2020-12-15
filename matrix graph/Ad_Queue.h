#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef char element;

typedef struct{
  element *data;
  int front,rear;
  int count;
  int size;
}Queue;

Queue *createQueue(int size){
  int i=0;
  Queue *q=(Queue*)malloc(sizeof(Queue));
  if(q==NULL) return NULL;
  q->data=(element*)malloc(size*sizeof(element));
  if(q->data==NULL){
    free(q->data);
    return NULL;
  }

  q->size=size;
  q->front=0;
  q->rear=0;
  q->count=0;

  return q;
}

int isFullQueue(Queue *q){
  if((q->rear+1)%q->size==q->front) return 1;
  else return 0;
}

int isEmptyQueue(Queue *q){
  if(q->rear==q->front) return 1;
  else return 0;
}

void enQueue(Queue *q,element item){

  if(isFullQueue(q)) printf("Queue is Full\n");

  else{
    q->rear=(q->rear+1)%q->size;
    q->data[q->rear]=item;
    q->count++;
  }
}

element deQueue(Queue *q){
  element k;
  if(isEmptyQueue(q)){
    printf("Queue is empty !\n");
    return 0;
  }

  else{
    k=q->data[q->front+1];
    q->data[q->front]=0;
    q->front=(q->front+1)%q->size;
    q->count--;
  }
  return k;
}

void printQueue(Queue *q){
  int f,r;
  Queue *temp;
  temp=q;
  f=temp->front;
  r=temp->rear;
  while(f!=r){
    f=(f+1)%q->size;
    printf("%c",temp->data[f]);
  }

}

void destroyQueue(Queue *q){
  free(q->data);
  free(q);
}

int checkQueue(Queue *q, element item){
    int i;
    int k=0;
    i=q->front+1;
    while(q->data[i]){
        if(q->data[i]==item) return k;
        i=(i+1)%q->size;
        k++;
    }
    return -1;
}

void sortQueue(Queue *q){
    int i,j;
    element temp;
    for(i=0;i<q->count;i++){
        for(j=i;j<q->count;j++){
            if(q->data[i]>q->data[j]){
                temp=q->data[i];
                q->data[i]=q->data[j];
                q->data[j]=temp;
            }
        }
    }
}
