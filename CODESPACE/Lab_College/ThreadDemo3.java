import java.util.Scanner;
class ThreadDemo3 extends Thread
{
	String s;
	int r;
	ThreadDemo3(String s,int r)
	{
		this.s = s;
		this.r = r;
	}
	public void run()
	{
		int x;
		if(s.equals("Odd"))
		x=1;
		else
		x=2;
		for(;x<=r;x+=2)
		{
			System.out.println(x);
			try{ Thread.sleep(1000); } catch(Exception e) {}
		}
	}
} 
class Driver
{
	public static void main(String args[])throws InterruptedException
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter limit");
		int r = sc.nextInt();
		ThreadDemo3 obj1 = new ThreadDemo3("Odd",r);
		ThreadDemo3 obj2 = new ThreadDemo3("Even",r);
		obj1.start();
		Thread.sleep(500);
		obj2.start();
	}
}