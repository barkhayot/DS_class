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

BSTNODE* deleteBST(BSTNODE* root, int data){
  // base case 
  if(root == NULL){
    return NULL;
  }
  // recursive case
  if(data < root->data){
    root->left = deleteBST(root->left, data);
    return root;
   
  }
  else if(data < root->data) {
    root->right = deleteBST(root->right, data);
    return root;

  }
  else{
    if(root->left == NULL && root->right ==NULL){
      // Delete the Node
      free(root);
      return NULL;
    }
  }

  // case 2
  if(root->left != NULL && root->right == NULL){
    BSTNODE* newRoot = root->left;
    free(root);
    return newRoot;

  }

  // case 3

  if(root->left == NULL && root->right != NULL){
    BSTNODE* newRoot = root->right;
    free(root);
    return newRoot;

  }


  // last case
  if(root->left != NULL && root->right != NULL){
    BSTNODE* maxNode = root->left;
    while(maxNode->right != NULL){
      maxNode = maxNode->right;
    }
  root->data = maxNode->data;
  root->left = deleteBST(root->left, maxNode->data);
  return root;
  }

  // find the node to deleteBST
    // 1 case node to delete is a leaf
      // delete the node
    // 2 cade node to delete is a leaf-like node
      // node has child on the leaf
      // node has child on the right
    // 3 case node has 2 children
      // find biggest node on the left subtree
      // swap values of max node and node to delete
      // delete the max node on the left subtree
  return root;

}


int main(void) {
// create simple BST for (int)
  BSTNODE* myBST = NULL;


// add ndoes int BST
  myBST = insertBSTNode(myBST, 23);
  insertBSTNode(myBST, 18);
  insertBSTNode(myBST, 15);
  insertBSTNode(myBST, 12);
  insertBSTNode(myBST, 44);

//printf("Trees are :\n");
//InOrder(myBST);
  //printf("%d\n", myBST->data);
  //printf("%d\n", myBST->left->data);
  //printf("%d\n", myBST->left->left->data);

  
  BSTNODE* isFound = searchBST(myBST, 18);
  if (isFound != NULL){
    printf("\n");
    printf("we found the target : %d ", isFound->data);
  }
  else{
    printf("we could not find the target");
  }
  

  //printf("Trees are :\n");
  //InOrder(myBST);

  // deletion of Leaf
  deleteBST(myBST, 18);
  printf("Trees are :\n");
  InOrder(myBST);

  return 0;
}
