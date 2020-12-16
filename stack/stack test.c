#include "Stack_Link.h"
#include <string.h>

int binary(int num) {
	int bi;
  char k[10],*all; 
	Stack *bStack;
  
  all=(char*)malloc(sizeof(char)*100);
  bStack=createStack(100);

  while (num != 0) {
		if (num % 2 == 1) {
			push(bStack,1);
		}
		else push(bStack,0);
		num = num / 2;
	}

  //여기만 고치면됨
  while(countStackitem(bStack)!=0){
    sprintf(k,"%d",pop(bStack));
    strcat(all,k);
  }

	bi=atoi(all);
  free(all);
  destroyStack(bStack);
	return bi;
}

int main(void) {
	int i, num,k;
	Stack *pStack = createStack(100);

	while (1) {
		i = 0;
		printf("Push (0), Pop (1), exit (2) : ");
		scanf("%d", &i);

		if (i == 0) {
			printf("Push :");
			scanf("%d", &num);
			push(pStack, binary(num));
		}

		if (i == 1) {
			printf("Pop :");
			printf("%d (%d)\n", num, pop(pStack));
		}

		if (i == 2) {
			destroyStack(pStack);
			exit(1);
		}

		printf("STACK Stat : ");
		
		printStackList(pStack);
	
		printf("(%d)\n", countStackitem(pStack));
	}
	return 0;
}