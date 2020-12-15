#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct{ // typedef 후 이름을 맨뒤로쓰면 struct 를 안써도 된다.
  element *stack;
  int size;
  int top;
}Stack;

Stack *createStack(int size){
  Stack *pStack = (Stack*)malloc(sizeof(Stack));
  if(pStack == NULL) return NULL;

  pStack->stack = (element*)malloc(size*sizeof(element));
  
  if(pStack->stack==NULL){
    free(pStack);
    return NULL;
  }

  pStack->size = size;
  pStack->top= -1;
  
  return pStack;
}


void push(Stack *pStack, element item){
  if(pStack->top == pStack->size-1) return;
  // 꽉차면 넣지 않는다
  ++pStack->top;
  pStack->stack[pStack->top] = item;
  //stack의 [++top]번째에 item을 넣는다.
}


element pop(Stack *pStack){
  if(pStack->top == -1) return 0;
  
  int top=0;
  top = pStack->stack[pStack->top];
  pStack->stack[pStack->top]=0;
  pStack->top--;

  return top;
}


element top(Stack *pStack){
  if(pStack->top == -1) return 0;
  
  return pStack->stack[pStack->top];
}

void destroyStack(Stack *pStack){
  while(pStack->top >0){
    free(pStack->stack++);
    pStack->top--;
  }
  free(pStack);
}

bool isFullStack(Stack *pStack){
  if(pStack->top == pStack->size-1) return true;
  
  else return false;
}

bool isEmptyStack(Stack *pStack){
  if(pStack->top == pStack->size-1) return false;

  else return true;
}

int countStackItem(Stack *pStack){
  return pStack->top;
}

void clearStack(Stack *pStack){
  int i;
  for(i=0;i<pStack->top;i++){
    pStack->stack[i]=0;
  }
  pStack->top=-1;
}