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
  printf("%c\n", root->data);
  printf("%c\n", root->left->data);
  printf("%c\n", root->right->data);
  printf("%c\n", root->left->left->data);
  printf("%c\n", root->left->right->left->data);







  return 0;
}
