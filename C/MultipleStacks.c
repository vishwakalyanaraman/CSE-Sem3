#include <stdio.h>
#define MAX 10

typedef struct {
	int top1, top2, st1[MAX];
} STACK;

void Push1(STACK s, int ele){
	if (s.top1 == s.top2){
		printf("Stack Full!\n");
	}
	else {
		s.st1[++(s.top1)] = ele;
	}
}

void Push2(STACK s, int ele){
	if (s.top1 == s.top2){
		printf("Stack Full!\n");
	}
	else s.st1[--(s.top2)] = ele;
}

int Pop1(STACK s){
	if (s.top1 == -1){
		printf("Empty!\n");
		return 9999;
	}
	else 
	return s.st1[(s.top1)--];
}

int Pop2(STACK s){
	if (s.top2 == MAX-1){
		printf("Empty!\n");
		return 9999;
	}
	else 
	return s.st1[(s.top2)++];
}

void Display1(STACK s){
	int i;
	/*if (s.top1 == -1){
		printf("Empty!\n");
		return;
	}*/
	for (i = 0; i <= s.top1; i++){
		printf("test %d\n",s.top1/*s.st1[i]*/);
	}
}

void Display2(STACK s){
	int i;
	if (s.top2 == MAX-1){
		printf("Empty!\n");
		return;
	}
	for (i = MAX-1; i > s.top1; i--){
		printf("TEST%d\n",s.st1[i]);
	}
}


void main(){
	int choice, ele;
	STACK s;
	s.top1 = -1;
	s.top2 = MAX-1;
	do{
		printf("\n1.Push Stack 1\n2. Push Stack 2\n3.Pop Stack 1\n4. Pop Stack 2\n5.Disp 1\n6.Disp 2\n9.Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:{ 
				printf("Enter element\n");
				scanf("%d",&ele);
				Push1(s, ele);
				break;
			}
			case 2:{
				printf("Enter element\n");
				scanf("%d", &ele);
				Push2(s, ele);
				break;
			}
			case 3:{
				ele = Pop1(s);
				printf("Element popped: %d", ele);
				break;
			}
			case 4:{
				ele = Pop2(s);
				printf("Element popped: %d", ele);
				break;
			}
			case 5:{
				Display1(s);
				break;
			}
			case 6:{
				Display2(s);
				break;
			}
			default: printf("Error!\n");
		}
	}
	while (choice != 9);
}