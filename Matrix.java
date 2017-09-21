import java.util.*;

class MatrixTest{
	private int arr[][];

	MatrixTest(int a, int b){
		arr = new int[a][b];
	}

	public int[] getRow(int a){
		return arr[a];
	}

	public void initializeMatrix(){
		Scanner sc = new Scanner(System.in);
		int i, j;
		System.out.println("Enter the elements of the matrix");
		for(i = 0; i < arr.length; i++){
			for(j = 0; j < arr.length; j++){
				arr[i][j] = sc.nextInt();
			}
		}
	}
}

class RowSum implements Runnable{
	private int arr[];
	private int sum;
	static int tsum = 0;

	RowSum(int a[]){
		arr = a;
		sum = 0;
	}

	public int getRowSum(){
		return sum;
	}

	public void run(){
			int sum = 0;
			for (int i = 0; i < arr.length; i++)
				sum += arr[i];
			tsum += sum;
		
	}
}

class Matrix{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of rows: ");
		int a = sc.nextInt();
		System.out.println("Enter the number of columns: ");
		int b = sc.nextInt();

		MatrixTest m = new MatrixTest(a,b);
		m.initializeMatrix();

		Thread threads[] = new Thread[a];
		RowSum rowsum[] = new RowSum[a];

		for (int i = 0; i < a; i++){
			rowsum[i] = new RowSum(m.getRow(i));
			threads[i] = new Thread(rowsum[i]);
			threads[i].start();
		}

		int sum = 0;

			for (int i = 0; i < a; i++){
				sum += rowsum[i].getRowSum();
				RowSum.tsum += sum;
				System.out.println("***New Thread Created***");
			}


		System.out.println("\nTotal sum = " + RowSum.tsum);

	}
}