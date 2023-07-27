import java.util.Scanner;
class Mathoperation
{
	static double PI = 3.14;
	
	static double mul(double a, double b)
	{
		return a * b;
	}
	
	static double div(double a, double b)
	{
		return a / b;
	}

}

class Driver
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the diameter of the circle: ");
		double d = sc.nextDouble();
		double r = Mathoperation.div(d,2);
		double area = Mathoperation.mul(Mathoperation.PI , Mathoperation.mul(r,r));
		double halfArea = Mathoperation.div(area,2);
		System.out.println("Area of Half Circle: "+halfArea);
	}
}
