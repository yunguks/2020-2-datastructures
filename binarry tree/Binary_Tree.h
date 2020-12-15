#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct tTreeNode{
  element data;
  struct tTreeNode *left, *right;
}TreeNode;

TreeNode* createTree(TreeNode *left,element item,TreeNode *right){
  TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
  if(pNewNode == NULL) return NULL;
  strcpy(&pNewNode->data,&item);

  pNewNode->left=left;
  pNewNode->right=right;
  return pNewNode;
}

void preorder(TreeNode *root){
  if(root==NULL) return;

  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(TreeNode *root){
  if(root==NULL) return;

  inorder(root->left);
  printf("%c",root->data);
  inorder(root->right);
}

void postorder(TreeNode *root){
  if(root==NULL) return;

  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data);
}

void destroyTree(TreeNode *root){
  if(root==NULL) return;

  destroyTree(root->left);
  destroyTree(root->right);
  
}

TreeNode *copyTree(TreeNode *root){
  if(root==NULL) return NULL;

  return createTree(copyTree(root->left),root->data,copyTree(root->right));
  
}

int isEmpty(TreeNode *root){
  if(root->left==NULL||root->right==NULL) return 1;
  else return 0;
}
