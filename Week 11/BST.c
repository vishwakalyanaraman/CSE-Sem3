#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}NODE;

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

int height(NODE *root){ //Calculates MAX height of tree
	if (root == NULL)
		return 0;
	else{
		int lheight = height(root->left);
		int rheight = height(root->right);

		if(lheight>rheight)
			return (lheight+1);
		else return (rheight+1);
	}
}

NODE  *FindMin(NODE *root){
   if (root == NULL){
      return 0;
	}
   if (root->left != NULL){
      return FindMin(root->left); // left tree is smaller
	}
   return root;
}

void displayCurrentLevel(NODE *root, int level){ //Prints individual levels
	if(root == NULL)
		return;
	if (level == 1)
		printf("%d\n", root->data);
	else if(level > 1){
		displayCurrentLevel(root->left, level-1);
		displayCurrentLevel(root->right, level-1);
	}
}

void displayLevelOrder(NODE *root){ //Prints entire tree
	int h = height(root);
	int i;
	for(i = 1; i <= h; i++)
		displayCurrentLevel(root, i);
}

NODE *Delete(NODE *root, int data) {
  if (root == NULL) {
     return NULL;
  }
  if (data < root->data) {  // data is in the left sub tree.
      root->left = Delete(root->left, data);
  } else if (data > root->data) { // data is in the right sub tree.
      root->right = Delete(root->right, data);
  } else {
     // case 1: no children
     if (root->left == NULL && root->right == NULL) {
        free(root);
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->left == NULL){
        NODE *temp = root; // save current node as a backup
        root = root->right;
        free(temp);
     }
     // case 3: one child (left)
     else if (root->right == NULL) {
        NODE *temp = root; // save current node as a backup
        root = root->left;
        free(temp);
     }
     // case 4: two children
     else {
        NODE *temp = FindMin(root->right); // find minimal value of right sub tree
        root->data = temp->data; // duplicate the node
        root->right = Delete(root->right, temp->data); // delete the duplicate node
     }
  }
  return root;
}	

void main(){
	NODE *root;
	int ele, choice, del;
	root = NULL;
	while(1){
		printf("1. Enter an element\n2. Display Level Order\n3. Delete element \n-1. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				scanf("%d", &ele);
				root = create(root,ele);
				break;
			case 2:
				printf("*****Level Order*****\n");
				displayLevelOrder(root);
				break;
			case 3:
				printf("Enter element to delete:\n");
				scanf("%d", &del);
				root = Delete(root, del);
				break;
			case -1:
				exit(0);
				break;
			default:
				printf("Error!\n");
		}
	}
}