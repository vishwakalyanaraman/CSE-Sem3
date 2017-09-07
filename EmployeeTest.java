import java.util.*;
import java.io.*;

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
		Integer ageobj = new Integer(age); 

		System.out.println("Enter the gross salary and home salary");
		gross_sal = sc.nextDouble();
		home_sal = sc.nextFloat();
		Double grossobj = new Double(gross_sal);
		Float homeobj = new Float(home_sal);

		System.out.println("Enter the grade");
		InputStreamReader ir = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(ir);
		
		try{
			String s = br.readLine();
			grade = s.charAt(0);
		}
		catch(IOException e){
			System.out.println("Error!");
			e.printStackTrace();
		}
	}

	void display(){
		System.out.println("\nName:"+name+"\n\nAge:"+age+"\n\nGross_Sal:"+gross_sal+"\n\nHome_Sal:"+home_sal+"\n\nGrade:"+grade);
	}
}

class EmployeeTest{
	public static void main(String args[]){

	Employee obj = new Employee();
	obj.input();
	obj.display();
}
}