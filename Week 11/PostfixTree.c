#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data;
	struct node *left;
	struct node *right;
}NODE;

/*void push(NODE*);
NODE *pop();
int eval(NODE*);
int result(char);
//void inOrder(NODE*);
void operand(char);
void operators(char);*/


int top = -1;
NODE *stack[20];
NODE *root;

void push(NODE *root){
	stack[++top] = root;
}

NODE *pop(){
	return(stack[--top]);
}

int result(char a){
	if (a == '+' || a == '-' || a == '*' || a == '/' || a == '$' || a == '^')
		return 1;
    return 0;
}

int eval(NODE *root){
	int check;
	check = result(root->data);
	if (check == 1)
		return root->data;
	else if(check == 2){
		if(root->data == '+')
			return(eval(root->left)+eval(root->right));
		if(root->data == '-')
			return(eval(root->left)-eval(root->right));
		if(root->data == '*')
			return(eval(root->left)*eval(root->right));
		if(root->data == '/')
			return(eval(root->left)/eval(root->right));
		/*if(root->data == '$')
			return(eval(NODE->left)+eval(NODE->right));
		if(root->data == '^')
			return(eval(NODE->left)+eval(NODE->right));*/
	}
}

void operand(char x){
	NODE *cur = (NODE*)malloc(sizeof(NODE));
	cur->data = x;
	cur->left = NULL;
	cur->right = NULL;
	push(cur);
}

void operators(char a){
	NODE *cur = (NODE*)malloc(sizeof(NODE));
	cur->data = a;
	cur->right = pop();
	cur->left = pop();
	push(cur);
}

void main(){
	int i,p,k,ans;
	char s[20];

	printf("Enter the postfix expression\n");
	scanf("%s", s);
	k = strlen(s);
	for(i = 0; i < k; i++){
		p = result(s[i]);
		if(p == 1)
			operand(s[i]);
		else if(p == 2)
			operators(s[i]);
	}

	ans = eval(stack[top]);
	printf("The value of the postfix is: %d\n", ans);
}

