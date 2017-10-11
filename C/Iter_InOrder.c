#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *rl;
    struct node *ll;
} *NODE;

void push(NODE s[],int * top,NODE val){
    s[++(*top)]=val;
}

NODE pop(NODE s[],int *top){
    return(s[(*top)--]);
}

NODE create(){
    NODE p;
    int x;
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(struct node*) malloc(sizeof(struct node));
    p->data=x;
    printf("\nEnter left children(-1 TO BREAK)");
    p->ll=create();
    printf("\nEnter right child nodes(-1 TO BREAK)");
    p->rl=create();
    return p;
}

void iter_inorder(NODE root){
    NODE stack[20],cur=root;
    int top=-1;
    if(root==NULL)
        printf("\nempty");
    while(1){
        while(cur){
            push(stack,&top,cur);
            cur=cur->ll;
        }
        if(top>=0){
            cur=pop(stack,&top);
            printf("%d\t",cur->data);
            cur=cur->rl;
        }
        else if(top==-1)
            break;
    }
}

void preorder(NODE root){
    if(root==NULL){
        return;
    }
    if(root!=NULL){
         printf("%d\t",root->data);
        iter_inorder(root->ll);
        iter_inorder(root->rl);
    }
}
void postorder(NODE root){
    if(root==NULL){
        return;
    }
    if(root!=NULL){
        iter_inorder(root->ll);
        iter_inorder(root->rl);
        printf("%d\t",root->data);
    }
}
int main(){
    NODE root=NULL;
    printf("Enter ROOT node\n");
    root=create(root);
    printf("\n***InOrder***\n");
    iter_inorder(root);
    printf("\n***PreOrder***\n");
    preorder(root);
    printf("\n***PostOrder***\n");
    postorder(root);
    return 0;
}