#include "Stack_Link.h"

int main(void) {
  int i;
  
  Stack *pStack=createStack(100);

  
  printf("Enter a number: ");
  scanf("%d",&i);
  
  printf("The binary number of %d : ",i);

  while(i!=0){
    if(i%2==1){
      push(pStack,1);
    }

    else push(pStack,0);

    i=i/2;
  }

  while(countStackitem(pStack)!=0){
    printf("%d",pop(pStack));
  }

  destroyStack(pStack);
  return 0;
}