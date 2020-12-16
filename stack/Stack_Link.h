#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct tStackNode{
  element data;
  struct tStackNode *next;
}StackNode;

typedef struct{
  int count;
  StackNode *top;
}Stack;

Stack *createStack(int size){
  Stack *pStack=(Stack*)malloc(sizeof(Stack));
  if(pStack==NULL) return NULL;
  pStack->count =0;
  pStack->top = NULL;
  return pStack;
}

void push(Stack *pStack, element item){
  StackNode *pNewNode=(StackNode*)malloc(sizeof(StackNode));
  if(pNewNode ==NULL) return;

  pNewNode->data = item;
  pNewNode->next = pStack->top;
  pStack->top = pNewNode;
  pStack->count++;
}

element pop(Stack *pStack){
  element k;
  k = pStack->top->data;
  pStack->top->data =0;
  pStack->top = pStack->top->next;
  pStack->count--;
  return k;
}

element top(Stack *pStack){
  return pStack->top->data;
}

void destroyStack(Stack *pStack){
  while(pStack->count!=0){
    StackNode *temp;
    temp= pStack->top->next;
    free(pStack->top);
    pStack->top = temp;
    pStack->count--;
  }
  free(pStack);
  if(pStack==NULL) printf("destroy Stack\n");
}

bool isEmptyStack(Stack *pStack){
  if(pStack->count==0) return true;

  else return false;
}

int countStackitem(Stack *pStack){
  return pStack->count;
}