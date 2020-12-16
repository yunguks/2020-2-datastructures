#include "Queue_Stack.h"

int main(void) {
  Queue *q=createQueue(20);
  int num;
  int f,r;
  char name[100];

  while(1){
    printf("In (0), Out (1), Exit (2) : ");
    scanf(" %d",&num);
  

    if(num==0){
      printf("Customer : ");
      scanf(" %[^\n]s",name);
      enQueue(q,name);
    }

    if(num==1){
      if(isEmptyQueue(q)!=1) printf("Customer dequeued : %s\n",deQueue(q));
      else printf("Queue is empty !\n");
    }

    if(num==2){
      destroyQueue(q);
      exit(1);
    }

    printf("The current status of Queue : (");

    printQueue(q);

    printf(" )\n\n");
  }
}