import java.util.Scanner;
class Matrix
{
 
	private int arr[][];
	private int r, c ;
	
	Matrix(int n)
	{
		arr = new int[n][n];
		r = c = n;
	}
	
	Matrix(int m, int n)
	{
		arr = new int[m][n];
		r = m;
		c = n;
	}
	
	void print_Mat()
	{
		for(int i = 0; i < arr.length; i++)
		{
			for(int j = 0; j < arr[0].length; j++)
						System.out.print(arr[i][j] + "  ");
		  System.out.println();
		}
		 System.out.println();
	}
	
	void get_Data()
	{
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
				arr[i][j] = sc.nextInt();
		}
	}
	
	Matrix add_Mat(Matrix m1)
	{
		Matrix res = new Matrix(m1.r,m1.c);
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				res.arr[i][j] = arr[i][j] + m1.arr[i][j];
			}
		}
		
		return res;
	}
	
	boolean mult_Mat(Matrix m1, Matrix m2)
	{
		if(m1.c != m2.r) return false;
		
		for(int i = 0; i < m1.r; i++)
		{
			for(int j = 0; j < m2.c; j++)
			{
				arr[i][j] = 0;
				
				for(int k = 0; k < m1.c; k++)
				
				 arr[i][j] += m1.arr[i][k] * m2.arr[k][j];
			}
		}
		
		return true;
	}

}

class Driver
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the row and column for the matrix1: ");
		int r, c;
		r = sc.nextInt();
		c = sc.nextInt();
		
		//Object Creation
		Matrix m1 = new Matrix(r,c);
		Matrix m2 = new Matrix(r,c);
		
		//INPUT
		System.out.println("Enter the elements for matrix1");
		m1.get_Data();
		System.out.println("Enter the elements for matrix2");
		m2.get_Data();
		
		//PRINT
		System.out.println("ELEMENTS IN MATRIX 1:");
		m1.print_Mat();
		System.out.println("ELEMENTS IN MATRIX 2:");
		m2.print_Mat();
		
		//ADD 
		Matrix m3 = new Matrix(r,c);
		m3 = m1.add_Mat(m2);
		System.out.println("Addition Result:");
		m3.print_Mat();
		
		//Multiply
		Matrix m4 = new Matrix(r,c);
		boolean status = m4.mult_Mat(m1,m2);
		if(!status) System.out.println("Matrix multiplication is not possible!");
		
		//PRINT
		else 
		{
		System.out.println("ELEMENTS IN MATRIX 1:");
		m1.print_Mat();
		System.out.println("ELEMENTS IN MATRIX 2:");
		m2.print_Mat();
		System.out.println("Matrix Multiplication:");
		m4.print_Mat();
		}
	}
}
