#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct tQueueNode {
  element *data;
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

void enQueue(Queue *q, element *item) {
	QueueNode *pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL) return;
  int i=0;
  char ch;

	pNewNode->data =(element*)malloc(sizeof(element)*100);
  while(item[i]!=0){
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

element *deQueue(Queue *q) {
	QueueNode *NewFront = (QueueNode*)malloc(sizeof(QueueNode));
  if(NewFront ==NULL) return 0;
	element *item=0;
	int k;

  k=q->count;
	if (k <= 0) {
		printf("Queue is empty !\n");
    free(NewFront);
		return 0;
	}
  else{
  	NewFront = q->front; // 노드 연결
	  item = q->front->data;

	  if (k == 1) {
		  q->front = NULL;
		  q->rear = NULL;
	  }
	  else {
		  q->front = NewFront->next; // 다음 노드 가리키기
	  }

	  q->count--;
    free(NewFront);
	  return item;
  }
}

element queueTop(Queue *q){
  return *q->front->data;
}

void printQueue(Queue *q){
  QueueNode *tem;
  int i=0;
  tem=q->front;
  while(tem!=NULL){
    i++;
    printf(" %s%d",tem->data,i);
    tem=tem->next;
  }
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
