#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// structure for BST node
typedef struct bstnode{
  int data; // key
  struct bstnode * left;
  struct bstnode * right;
} BSTNODE;

BSTNODE* createBStNode(int data){
  // allocate the space 
  BSTNODE* newBSTNode = (BSTNODE*)malloc(sizeof(BSTNODE));
  // initialize the node
  if(newBSTNode == NULL){
    return NULL;
  }
  newBSTNode->data = data;
  newBSTNode->left = NULL;
  newBSTNode->right = NULL;

  return newBSTNode;
  //
}


BSTNODE* insertBSTNode(BSTNODE* root, int data){
  // base case
  if(root == NULL){
    // create the node
    BSTNODE* newNode = createBStNode(data);
    if (newNode == NULL){
      return NULL;
    }
    return newNode;
  }
  // recursive case
  if(data < root->data)
    root->left = insertBSTNode(root->left, data);
  else
    root->right = insertBSTNode(root->right, data);
  
  return root;


}

void InOrder(BSTNODE* root){
    if(root != NULL){
      InOrder(root->left);
      printf("%d ", root->data);
      InOrder(root->right);
    }
}

BSTNODE* searchBST(BSTNODE* root, int key){
  if(root == NULL){
    return NULL;
  }
  if(key < root->data){
    return searchBST(root->left, key);
  }
  else if(key > root->data){
    return searchBST(root->right, key);
  }

    return root;
}



int main(void) {
// create simple BST for (int)
  BSTNODE* myBST = NULL;


// add ndoes int BST
  myBST = insertBSTNode(myBST, 23);
  insertBSTNode(myBST, 18);
  insertBSTNode(myBST, 12);
  insertBSTNode(myBST, 44);

//printf("Trees are :\n");
//InOrder(myBST);
  //printf("%d\n", myBST->data);
  //printf("%d\n", myBST->left->data);
  //printf("%d\n", myBST->left->left->data);

  
  BSTNODE* isFound = searchBST(myBST, 12);
  if (isFound != NULL){
    printf("\n");
    printf("we found the target : %d ", isFound->data);
  }
  else{
    printf("we could not find the target");
  }
  

  //printf("Trees are :\n");
  //InOrder(myBST);

  
  return 0;
}
