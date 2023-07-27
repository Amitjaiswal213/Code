class ThreadDemo2 extends Thread
{
	int max,arr[];
	double avg;
	String s;
	ThreadDemo2(String s,int a[])
	{
		arr = new int[a.length];
		for(int i=0;i<a.length;i++)
		{
			arr[i] = a[i];
		}
		this.s = s;
		start();
	}
	public void findMax()
	{
		max = arr[0];
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]>max)
			max = arr[i];
		}
	}
	public int getMax()
	{
		return max;
	}
	public void findAvg()
	{
		int sum=0;
		for(int i=0;i<arr.length;i++)
		{
			sum = sum+arr[i];
		}
		avg = sum/arr.length;
	}
	public double getAvg()
	{
		return avg;
	}
	public void run()
	{
		if(s.equals("Max"))
		findMax();
		else
		findAvg();
	}
}
class Driver
{
	public static void main(String args[])throws InterruptedException
	{
		int arr[] = new int[args.length];
		for(int i=0;i<args.length;i++)
		{
			arr[i] = Integer.parseInt(args[i]);
		}
		ThreadDemo2 obj1 = new ThreadDemo2("Max",arr);
		ThreadDemo2 obj2 = new ThreadDemo2("Avg",arr);
		obj1.join();
		obj2.join();
		double finalval = obj1.getMax()/obj2.getAvg();
		System.out.println("The final value is ="+finalval);
	}
}
