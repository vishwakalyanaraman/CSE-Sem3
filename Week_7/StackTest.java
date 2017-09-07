import java.util.*;

interface Stack{
		void push(int a);
		void pop();
		void display();
	}


class FixedStack implements Stack{
	int top = -1;
	int stack[];
	FixedStack(int n){
		stack = new int[n];
	}

	public void push(int ele){
		if (top == stack.length-1){
			System.out.println("Stack Overflow!");
		}
		else stack[++top] = ele;
	}

	public void pop(){
		if (top == -1){
			System.out.println("Stack Underflow!");
		}
		else System.out.println("Deleted: "+stack[top--]);
	}

	public void display(){
		for (int i = 0; i <= top; i++){
			System.out.println(stack[i]);
		}
	}
}

class DynamicStack implements Stack{
	int top = -1;
	int stack[];

	DynamicStack(int n){
		stack = new int[n];
	}

	public void push(int ele){
		if (top == stack.length-1){
			System.out.println("Increasing Memory by twice");
			int temp[] = new int[stack.length*2];
			for(int i = 0; i < stack.length; i++){
				temp[i]=stack[i];
			}
			stack=temp;
		}
		else stack[++top] = ele;
	}

	public void pop(){
		if (top == -1){
			System.out.println("Stack Underflow!");
		}
		else System.out.println("Deleted: "+stack[top--]);
	}

	public void display(){
		for (int i = 0; i <= top; i++){
			System.out.println(stack[i]);
		}
	}
}

class StackTest{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of Fixed and Dynamic Array");
		int a = sc.nextInt();
		int b = sc.nextInt();
		FixedStack fix = new FixedStack(a);
		DynamicStack dyn = new DynamicStack(b);

		System.out.println("1. Fixed\n2. Dynamic");
		int choice = sc.nextInt();
		while (1>0){
			if (choice == 1){
				System.out.println("***Fixed Array***");
				System.out.println("1.Push\n2.Pop\n3.Display\n*****\n");
				int choicefix = sc.nextInt();
				switch (choicefix){
					case 1:{
						System.out.println("Enter the element");
						int ele = sc.nextInt();
						fix.push(ele);
						break;
					}
					case 2:{
						fix.pop();
						break;
					}
					case 3:{
						fix.display();
						break;
					}
				}
			}

			if (choice == 2){
				System.out.println("***Dynamic Array***");
				System.out.println("1.Push\n2.Pop\n3.Display");
				int choicedyn = sc.nextInt();
				switch (choicedyn){
					case 1:{
						System.out.println("Enter the element");
						int ele = sc.nextInt();
						dyn.push(ele);
						break;
					}
					case 2:{
						dyn.pop();
						break;
					}
					case 3:{
						dyn.display();
						break;
					}
				}
			}
		}
	}
}