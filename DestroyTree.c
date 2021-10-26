void destroyTree(NODE *root)
{
  if(root != NULL){
    if(root->left)
      destroyTree(root->left);
    if(root->right)
      destroyTree(root->right);
    free(root);
    }
}
