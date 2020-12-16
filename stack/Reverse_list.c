#include "Stack_Link.h"

int main(void) {
  int i;
  char k;
  Stack *pStack=createStack(100);

  while(1){
    printf("Enter a number: <Ctrl+d> to stop: ");
    k=scanf("%d",&i);
    
    if(k==EOF){
      printf("\n");
      break;
    }
    push(pStack,i);
  }

  printf("The List of numbers reversed:\n");
  
  while(countStackitem(pStack)!=0){
    printf("%d\n",pop(pStack));
  }

  destroyStack(pStack);
  return 0;
}