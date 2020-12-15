#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct tQueueNode {
  element *data;
  int number;
	struct tQueueNode *next;
}QueueNode;

typedef struct {
	QueueNode *front, *rear;
	int count;
}Queue;

Queue *createQueue(int size) {
	Queue *pNewQueue = (Queue*)malloc(sizeof(Queue));
	if (pNewQueue == NULL) return NULL;

	pNewQueue->count = 0;
	pNewQueue->front = NULL;
	pNewQueue->rear = NULL;

	return pNewQueue;
}

void enQueue(Queue *q, element *item, int num) {
	QueueNode *pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL) return;
  int i=0;
  int ch;

  pNewNode->number = num;
	pNewNode->data =(element*)malloc(sizeof(element)*100);
  while(item[i]!='\0'){
    ch=item[i];
    pNewNode->data[i]=ch;
    i++;
  }
  

	pNewNode->next = NULL;

	if (q->count <= 0) {
		q->front = pNewNode;
		q->rear = pNewNode;
	}
	else {
		q->rear->next = pNewNode;
		q->rear = pNewNode;
	}
  /*printf("enqueue data : %s\n",q->rear->data);
  printf("front joosu : %p\n", q->front);
  printf("front data : %s\n",q->front->data);확인용*/
	q->count++;
  
}

void deQueue(Queue *q) {
	QueueNode *NewFront = (QueueNode*)malloc(sizeof(QueueNode));
  if(NewFront ==NULL) return ;
	element item[100]={};
	int k,i;

  k=q->count;
	if (k <= 0) {
		printf("Queue is empty !\n");
    free(NewFront);
		return ;
	}
  else{
  	NewFront = q->front;
    
    printf("%d [",q->front->number);
    i=0;
    while(q->front->data[i]!='\0'){
      printf("%d",q->front->data[i]);
      i++;
    }
    printf("] is in Queue\n");

	  if (k == 1) {
		  q->front = NULL;
		  q->rear = NULL;
	  }
	  else {
		  q->front = NewFront->next; // 다음 노드 가리키기
	  }
    
	  q->count--;
    free(NewFront);
  }
}

element queueTop(Queue *q){
  return *q->front->data;
}

void printQueue(Queue *q){
  QueueNode *tem;
  int k;
  tem=q->front;
  while(tem!=NULL){
    k=0;
    while(tem->data[k]!='\0'){
      printf("%d",tem->data[k]);
      k++;
    }
    printf(" ");
    tem=tem->next;
  }
}

void searchQueue(Queue *q,int num){
  Queue *h;
  int i=0;
  h=q;
  if(num==h->front->number){
    printf("%d [",h->front->number);
    i=0;
    while(h->front->data[i]!='\0'){
      printf("%d",h->front->data[i]);
      i++;
    }
    printf("] is in Queue\n");
    
  }

  else if(num==h->rear->number){
    printf("%d [",h->rear->number);
    i=0;
    while(h->rear->data[i]!='\0'){
      printf("%d",h->rear->data[i]);
      i++;
    }
  printf("] is in Queue\n");
  }
  else printf("%d is not in Queue\n",num);
}


void destroyQueue(Queue *q) {
	QueueNode *Newfront = NULL;
	QueueNode *Newrear = NULL;

  Newfront=q->front;
  while(Newfront!=NULL){
    Newrear=Newfront->next;
    Newfront=Newrear;
    free(Newrear);
  }
  free(q);
}
