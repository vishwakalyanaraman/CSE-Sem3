#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
	int f;
	int r;
	char s[MAX][10];
} QUEUE;

int isFull(QUEUE q){
 if(q.r==MAX-1)
	return 1;
 return 0;
}

int isEmpty(QUEUE q){
 if(q.f == -1)
	return 1;
 return 0;
}

void insertR(QUEUE *q, char ele[]){
	if (isFull(*q)){
		printf("The Queue full!\n");
	}
	if (q->f == -1){
		q->f = 0;
	}
	strcpy(q->s[++(q->r)], ele); 
}

void insertF(QUEUE *q, char ele[]){
	if (q->f < 1){
		printf("Can't add from front\n");
	}
	else strcpy(q->s[--(q->f)], ele);
}

void delete(QUEUE *q){
	if (isEmpty(*q))
		printf("Empty!\n");
	else{
		++(q->f);
	}
}

void display(QUEUE q){
	int i;
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		return;	
	}
	for(i=q.f;i<=q.r;i++){
		printf("%s \t",q.s[i]);
	}
}

void main(){
	QUEUE q;
	q.f=-1;
	q.r=-1;
	char x[10];
	int choice=0;
    do{
	printf("\nPress\n1. Insert Rear\n2. Insert Front\n3. Delete\n4. Display\n0. Exit\n*****\n");
	scanf("%d",&choice);
    	int ele;	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%s",x);
			 printf("*****\n");
			 insertR(&q, x);
			 break;
		case 2: printf("Enter element to be inserted -  \n");	
			 scanf("%s",x);
			 printf("*****\n");
			 insertF(&q,x);
			 break;
		case 3 : delete(&q);
			 break;
		case 4 : display(q);
			 break;
		case 0: exit(0);	
		default: printf("Error!\n");	
	}
    }while(choice!=0);
}