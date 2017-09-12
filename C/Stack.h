#define MAX 50

typedef struct {
	int top;
	arr[];
} Stack; 

int isEmpty(Stack *s){
	if (s->top == -1){
		return 1;
	}
	else return 0;
}

int isFull(Stack *s){
	if (s->top == MAX-1){
		return 1;;
	}
	else return 0;
}

void push(Stack *s, int ele){
	if (isFull(s)){
		printf("Stack Overflow!\n");
	}
	else{
	s->arr[++(s->top)] = ele;
	}	
}

int pop(Stack *s){
	if (isEmpty(s)){
		printf("Stack Underflow!\n");
	}

	return (s->arr[(s->top)--];);
}

void Disp(){
	if (isEmpty(s)){
		printf("Stack Underflow!\n");
	}
	else{
		while (top >= 0){
			printf("%d\n",s->arr[(s->top)--]);
		}
	}
}
