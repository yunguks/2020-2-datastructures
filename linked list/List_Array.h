#include <stdio.h>
#include <stdlib.h>

typedef int element;

/*typedef struct{
  element data;
}*/

typedef struct {
  element *data;
  int size;
  int count;
}List;

List *createList(int size){
  List *pList=(List*)malloc(sizeof(List));
  if(pList==NULL) return NULL;

  pList->data =(element*)malloc(sizeof(element)*size);
  if(pList->data==NULL){
    free(pList);
    return NULL;
  }

  pList->size=size;
  pList->count=0;

  return pList;
}

int isEmptyList(List *List){
  if(List->count==0) return 1;
  else return 0;
}

int isFullList(List *List){
  if(List->count==List->size) return 1;
  else return 0;
}

void addList(List *List, element data){
  int i,k,temp;
  if(List->count==0){
    List->data[0]=data;
    List->count++;
  }
  
  else if(List->count<List->size){
    for(i=0;i<List->count;i++){
      if(data<List->data[i]) break;
    }

    if(data<List->data[i]){
      k=List->count;
      while(k!=i-1){
        List->data[k+1]=List->data[k];
        k--;
      }
      List->data[k+1]=data;
    }
    else List->data[i]=data; 
    
    List->count++;
  }

  else {
    printf("List is Full\n");
    return;
  }
}

int searchList(List *List, element data){
  int i=0,k=0;
  while(i!=List->count){
    if(List->data[i]==data) {
      k++;
    }
    i++;
  }

  /*if(k==0) printf("My List does not have %d.\n",data);
  else if(k==1) printf("My List has %d.\n",data);
  else printf("My List have %d, count %d",data,k);*/
  return k;
}

void removeList(List *List, element data){
  int i=0;
  if(searchList(List,data)!=0){
    for(i=0;i<List->count;i++){
      if(data==List->data[i]) break;
    }
    while(i!=List->count){
      List->data[i]=List->data[i+1];
      i++;
    }
    List->count--;
    printf("%d was removed.\n",data);
  }
  else printf("%d was not List\n",data);
}



void destroyList(List *List){
  free(List->data);
  free(List);
}



void printList(List *List){
  int i=0;
  if(List->count==1){
    printf("%d\n",List->data[i]);
  }
  else {
    printf("%d",List->data[i]);
    while(i!=List->count-1){
      i++;
      printf(", %d",List->data[i]);
    }
    printf("\n");
  }
}