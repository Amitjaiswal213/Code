class ThreadDemo extends Thread
{
	String s;
	ThreadDemo(String s)
	{
		this.s = s;
	}
	public void run()
	{
		display(s);
		try{ Thread.sleep(500); } catch(Exception e){}
	}
	public void display(String s)
	{
		for(int i=0;i<s.length();i++)
		{
			System.out.println(s.charAt(i));
			
			
		}
	}
}
class Driver
{
	public static void main(String args[])
	{
		ThreadDemo obj1 = new ThreadDemo("Hello");
		ThreadDemo obj2 = new ThreadDemo("World");
        ThreadDemo obj3 = new ThreadDemo("Java");
		obj1.start();
		obj3.start();
        try{
            Thread.sleep(1000);
        }
        catch(Exception e){}
        obj2.start();
	}
}