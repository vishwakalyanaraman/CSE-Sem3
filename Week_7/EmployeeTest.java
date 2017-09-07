import java.util.*;

class Employee{
	String name;
	int age;
	double gross_sal;
	float home_sal;
	char grade;

	void input(){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the name and age");
		name = sc.nextLine();
		age = sc.nextInt();
	}
}