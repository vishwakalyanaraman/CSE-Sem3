import java.util.*;

class Table{

	static synchronized void display(int x){
		for(int i = 0; i <= x; i++)
		System.out.println(x+" * "+i+" = "+ x*i);
	}
}

class DisplayTable extends Thread{
	int x;
	DisplayTable(int x){
		this.x = x;
		Thread t = new Thread(this);
		t.start();
	}
	public void run(){
		Table.display(x);
	}
}

class TableDemo{
	public static void main(String[] args) {
		DisplayTable d1 = new DisplayTable(5);
		DisplayTable d2 = new DisplayTable(7);
	}
}
