#include "Stack_Array.h"

int main(void) {
  int i,k;
  Stack *p=createStack(100);
  
  printf("Enter a number: ");
  scanf("%d",&i);
  k=i;

  while(k!=0){
    if(k%2==1){
      push(p,1);
    }
    else push(p,0);

    k=k/2;
    
  }

  printf("The binary number of %d : ",i);
  while(countStackItem(p)!=-1){
    printf("%d",pop(p));
  }

  destroyStack(p);
  return 0;
}