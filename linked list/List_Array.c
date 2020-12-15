#include "List_Array.h"

int main(void) {
  List *pList=createList(100);
  int order;
  element data;

  while(1){
    printf("In (0), Search (1), Out (2), Exit (3) :");
    scanf("%d",&order);

    if(order==0){
      printf("In : ");
      scanf("%d", &data);
      addList(pList,data);
    }

    else if(order==1){
      printf("Search : ");
      scanf("%d",&data);
      if(searchList(pList,data)==0){
        printf("My List does not have %d.\n",data);
      }

      else printf("My List has %d.\n",data);
    }

    else if(order==2){
      printf("Out : ");
      scanf("%d",&data);
      removeList(pList,data);
    }

    else{
      destroyList(pList);
      exit(1);
    }

    printf("The current statis of List : ");
    printList(pList);
    printf("\n");
  }

}