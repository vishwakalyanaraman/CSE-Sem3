#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}NODE;

NODE* newNode(int data){
  NODE* node = (NODE*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
   
  return(node);
}

void mirror(NODE* node) {
  if (node==NULL) 
    return;  
  else{
    struct node* temp;
     
    //Traverse subtrees
    mirror(node->left);
    mirror(node->right);
 
    // Swap pointers
    temp = node->left;
    node->left  = node->right;
    node->right = temp;
  }
} 
 
void inOrder(NODE* node){
  if (node == NULL) 
    return;
   
  inOrder(node->left);
  printf("%d ", node->data);
 
  inOrder(node->right);
}

NODE *create(NODE *root, int ele){
  if(root == NULL){
    root = (NODE*) malloc(sizeof(NODE));
    root->data = ele;
    root->left = root->right = NULL;
  }
  else if (ele > root->data)
    root->right = create(root->right, ele);
  else if (ele < root->data)
    root->left = create(root->left, ele);
  else{
    printf("Duplicate Node!\n");
    exit(0);
  }
  return (root);
}  
 
 
void main(){
  int x, ele, i;
  NODE* root;
  root = NULL;
  printf("Enter the number of elements in the BST\n");
  scanf("%d", &x);

  printf("Enter the elements of the BST\n");
  for(i = 0; i < x; i++){
    scanf("%d", &ele);
    root = create(root,ele);
  }  

  //Print current tree
  printf("\n Inorder traversal of the constructed tree is \n");
  inOrder(root);
   
  //Convert tree to its mirror image
  mirror(root); 
   
  //Print new tree
  printf("\n Inorder traversal of the *mirror* tree is \n");  
  inOrder(root);
}