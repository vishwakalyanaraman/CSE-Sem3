#include <stdio.h>
#define MAX 10
typedef struct{
	int f;
	int r;
	int s[MAX];
}QUEUE;

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
void insert(QUEUE *q,int a){
	int i;
	if(isFull(*q))
	printf("Queue is full.\n");	
	else{
		i=q->r;
		q->r = (q->r)+1;
		if(q->f==-1){
			q->f=0;
		}
		while(q->s[i]>a && i>=0){
			q->s[i+1]=q->s[i];
			i--;
		}
		q->s[i+1]=a;
		printf("Inserted.\n");	
	}
}
void delete(QUEUE *q){
	if(isEmpty(*q)){
		printf("Queue is empty.\n");	
	}
	else{
		if(q->r==q->f){
			printf("%d is deleted.\n",q->s[q->f]);	
			q->r=q->f=-1;
		}
		else{
			printf("%d is deleted.\n",q->s[q->f]);	
			q->f=q->f+1;
		}
	}
}
void display(QUEUE q){
	int i;
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		return;	
	}
	for(i=q.f;i<=q.r;i++){
		printf("%d \t",q.s[i]);
	}
}
void main(){
	QUEUE q;
	q.f=-1;
	q.r=-1;
	int choice=0;
    do{
	printf("\nPress\n1. Insert\n2. Delete\n3. Display\n4. Exit\n*****\n");
	scanf("%d",&choice);
    	int ele;	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%d",&ele);
			 insert(&q,ele);
			 break;
		case 2 : delete(&q);
			 break;
		case 3 : display(q);
			 break;		
	}
    }while(choice!=4);
}
