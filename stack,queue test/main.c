#include "Queue_Link.h"
#include "Stack_Array.h"

void changeNum(Stack *Stack,int num){
  int k=0;

  while(num!=0){
    k=num%8;
    push(Stack,k);
    num=num/8;
  }
}

int main(void) {
  int order,num,i;
  int *ch=(int*)malloc(sizeof(int)*100);
  Queue *qQueue=createQueue(100);
  Stack *pStack=createStack(100);
  
  while(1){
    printf("Insert(0), Search(1), Delete(2), Exit(3) : ");
    scanf("%d",&order);

    if(order==0){
      i=0;
      printf("Decimal : ");
      scanf("%d",&num);
      changeNum(pStack,num);
      //printf("%d\n",top(pStack));
      while(i<5){//여기
        ch[i]=pop(pStack);
        i++;
      }

      enQueue(qQueue,ch,num);
    }

    else if(order==1){
      printf("Deciaml : ");
      scanf("%d",&num);
      searchQueue(qQueue,num);
    }

    else if(order==2){
      deQueue(qQueue);
    }

    else{
      destroyQueue(qQueue);
      destroyStack(pStack);
      free(ch);
      exit(1);
    }

    printf("Queue List : ");
    
    printQueue(qQueue);

    printf("(%d)\n\n",qQueue->count);

    
  }

  return 0;
}