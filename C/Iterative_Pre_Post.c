#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * rl;
    struct node * ll;
}*NODE;

NODE create(){
    NODE p;
    int x;
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    printf("\nEnter left children(-1 TO BREAK)");
    p->ll=create();
    printf("\nenter right child nodes(-1 TO BREAK)");
    p->rl=create();
    return p;
}

void push(NODE s[],int * top,NODE val){
    s[++(*top)]=val;
}

NODE pop(NODE s[],int *top){
    return(s[(*top)--]);
}

void iter_preorder(NODE root){
    NODE stack[20],cur=root;
    int top=-1;
    if(root==NULL)
        printf("\nEmpty");
    while(1){
        while(cur){
            printf("%d\t",cur->data);
            push(stack,&top,cur);
            cur=cur->ll;
        }
        if(top>=0){
            cur=pop(stack,&top);
            cur=cur->rl;
        }
        else if(top==-1)
            break;
    }
}


void iter_postorder(NODE root){
    // Check for empty tree
    if (root == NULL)
        return;

   NODE stack[20],cur=root;
   int top=-1;
    do{
        // Move to leftmost node
        while (cur){
            // Push root's right child and then root to stack.
            if (cur->rl)
                push(stack,&top,cur->rl);
            push(stack, &top,cur);

            // Set root as root's left child
            cur = cur->ll;
        }

        // Pop an item from stack and set it as root
        cur = pop(stack,&top);

        if (cur->rl && stack[top] == cur->rl){
            pop(stack,&top);  
            push(stack, &top,cur);
            cur = cur->rl; 
        }
        else{
            printf("%d\t", cur->data);
            cur = NULL;
        }
    } while (top!=-1);
}
void main(){
    NODE root=NULL;
    printf("Enter ROOT node\n");
    root=create(root);
    printf("\n***Preorder***\n");
    iter_preorder(root);
     printf("\n***PostOrder***\n");
    iter_postorder(root);
}
