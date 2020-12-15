#include "Queue_Link.h"

int main(void) {
  Queue *q=createQueue(20);
  int num;
  char *name=(char*)malloc(sizeof(char)*100);
  char *name1=(char*)malloc(sizeof(char)*100);

  while(1){
    printf("In (0), Out (1), Exit (2) :");
    scanf("%d",&num);

    if(num==0){
      printf("Customer : ");
      scanf(" %[^\n]s",name);
      enQueue(q,name);
    }

    if(num==1){
      name1=deQueue(q);
      if(name1!=NULL) printf("Customer dequeued : %s\n",name1);
    }

    if(num==2){
      destroyQueue(q);
      free(name);
      free(name1);
      exit(1);
    }

    printf("The current status of Queue : (");

    printQueue(q);

    printf(" )\n\n");
  }
}