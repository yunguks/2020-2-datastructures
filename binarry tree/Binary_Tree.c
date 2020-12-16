#include "Binary_Tree.h"
#include "Tree_Queue.h"

int main(void) {
  char name[100];
  int i;
  char a1,a2,a3,a4,a5,a6,a7;
  TreeNode *tree;
  Queue *q=createQueue(100);

  printf("Input a string : ");
  scanf("%[^\ns]",name);
  printf("\n");

  a1=name[0];
  a2=name[1];
  a3=name[2];
  a4=name[3];
  a5=name[4];
  a6=name[5];
  a7=name[6];
  enQueue(q,a1);
  enQueue(q,a2);
  enQueue(q,a3);
  enQueue(q,a4);
  enQueue(q,a5);
  enQueue(q,a6);
  enQueue(q,a7);

  TreeNode *name3=createTree(NULL,a4,NULL);
  TreeNode *name4=createTree(NULL,a5,NULL);
  TreeNode *name5=createTree(NULL,a6,NULL);
  TreeNode *name6=createTree(NULL,a7,NULL);
  TreeNode *name1=createTree(name3,a2,name4);
  TreeNode *name2=createTree(name5,a3,name6);
  TreeNode *name0=createTree(name1,a1,name2);


  printf("Pre-order : ");
  preorder(name0);
  printf("\n\n");

  printf("In-order : ");
  inorder(name0);
  printf("\n\n");

  printf("Post-order : ");
  postorder(name0);
  printf("\n\n");

  printf("Breadth First : ");
  printQueue(q);
  destroyQueue(q);
  destroyTree(name0);
  return 0;
}