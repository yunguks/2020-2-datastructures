#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;

typedef struct tListNode{
  element data;
  struct tListNode *next;
}ListNode;

typedef struct {
  int count;
  ListNode *head;
  ListNode *pos;
}List;

List *createList(){
  List *NewList=(List*)malloc(sizeof(List));
  if(NewList == NULL) return NULL;

  NewList->count=0;
  NewList->head=NULL;
  
  return NewList;
}

void _insertList(List *List,ListNode *pPre, element data){
  ListNode *pNewNode =(ListNode*)malloc(sizeof(ListNode));
  pNewNode->data = data;

  if(pPre==NULL){
    pNewNode->next = List->head;
    List->head = pNewNode;
  }
  else{
    pNewNode->next = pPre->next;
    pPre->next = pNewNode; 
  }

  List->count++;
}

int _searchList(List *List, ListNode **ppPre, ListNode **ppLoc, element data){
  for(*ppPre=NULL,*ppLoc=List->head;*ppLoc!=NULL;*ppPre=*ppLoc,*ppLoc=(*ppLoc)->next){
    if((*ppLoc)->data == data) return 1;
    else if((*ppLoc)->data>data) break;
  }
  return 0; 
}

void addNodeList(List *pList, element data){
  ListNode *pPre=NULL,*pLoc=NULL;
  bool found= _searchList(pList,&pPre,&pLoc,data);

  if(!found) _insertList(pList,pPre,data);
}

void _deleteList(List *pList, ListNode *pPre,ListNode *pLoc){
  if(pPre == NULL) pList->head = pLoc->next;
  else pPre->next=pLoc->next;

  free(pLoc);
  pList->count--;
}

void removeList(List *pList, element data){
  ListNode *pPre=NULL,*pLoc=NULL;
  bool found = _searchList(pList, &pPre, &pLoc,data);
  if(found) _deleteList(pList,pPre,pLoc);
  else printf("My List does not have %d.\n",data);
}

int searchList(List *pList,element data){
  ListNode *pPre=NULL,*pLoc=NULL;
  bool found = _searchList(pList, &pPre, &pLoc,data);

  if(found) return 1;
  else return false;

}

bool traverseList(List *pList, int fromWhere, element *pDataOut){
  if(fromWhere == 0 || pList->pos ==NULL) pList->pos = pList->head;
  else { 
    pList->pos = pList->pos->next;
  }

  if(pList->pos !=NULL){
    *pDataOut = pList->pos->data;
    return true;
  }
  else{
    *pDataOut=0;
    return false;
  }
}

void destroyList(List *pList){
  ListNode *pDel =NULL, *pNext=NULL;

  for(pDel=pList->head;pDel!=NULL;pDel=pNext){
    pNext = pDel->next;
    free(pDel);
  }

  free(pList);
}

void printList(List *pList){
  ListNode *p;
  p=pList->head;
  printf("%d",p->data);
  while(p->next!=NULL){
    p=p->next;
    printf(", %d",p->data);
  }
  printf("\n");
}

