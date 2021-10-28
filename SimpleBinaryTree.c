#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// struct for node

typedef struct node {
  char data;
  struct node *left;
  struct node *right;
} NODE ; 

// node implementation

NODE* CreateTree(NODE *left, char item, NODE *right)
{
  NODE *newNodePtr = (NODE*)malloc(sizeof(NODE));
  if(newNodePtr == NULL)
    return NULL;

  newNodePtr->data = item;
  newNodePtr->left = left;
  newNodePtr->right = right;

  return newNodePtr;
}

// PreOrder function NLR

void preOrder(NODE* root){
    if(root != NULL){
      printf("%c", root->data);
      preOrder(root->left);
      preOrder(root->right);
    }
}

// InOrder function

void InOrder(NODE* root){
    if(root != NULL){
      InOrder(root->left);
      printf("%c", root->data);
      InOrder(root->right);
    }
}

// PostOrder function

void PostOrder(NODE* root){
    if(root != NULL){
      PostOrder(root->left);
      PostOrder(root->right);
      printf("%c", root->data);
    }
}

// main function

int main(){
  // subtrees
  NODE *a = CreateTree(NULL, 'a', NULL);
  NODE *b = CreateTree(NULL, 'b', NULL);
  NODE *c = CreateTree(NULL, 'c', NULL);
  NODE *d = CreateTree(NULL, 'd', NULL);

  // Intermediate nodes
  NODE *plus1 = CreateTree(b, '+', c);
  NODE *multiply = CreateTree(a, '*', plus1);

  // root node
  NODE *root = CreateTree(multiply, '+', d);

  // testing 
  //printf("%c\n", root->data);
  //printf("%c\n", root->left->data);
  //printf("%c\n", root->right->data);
  //printf("%c\n", root->left->left->data);
  //printf("%c\n", root->left->right->left->data);

  // testing for preOrder
  printf("PreOrder : ");
  preOrder(root);
  printf("\n");
  
    // testing for InOrder
  printf("InOrder : ");
  InOrder(root);
  printf("\n");
  

    // testing for PostOrder
  printf("PostOrder : ");
  PostOrder(root);
  printf("\n");
  
  







  return 0;
}

