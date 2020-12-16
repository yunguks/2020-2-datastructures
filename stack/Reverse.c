#include "Stack_Array.h"

int main(void) {
  int i;
  Stack *p;
  char k;

  p=createStack(10);
  while(1){
    printf("Enter a number: <Ctrl+d> to Stop: ");
    k=scanf("%d",&i);

    if(k==EOF){
      printf("\n"); 
      break;
    }
    else push(p,i);

    if(isFullStack(p)) break;
  
  }

  printf("The List of numbers reversed:\n");

  while(countStackItem(p)!=-1){
    printf("%d\n",pop(p));
  }

  destroyStack(p);
  return 0;
}