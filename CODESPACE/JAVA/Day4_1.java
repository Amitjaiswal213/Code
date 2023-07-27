import java.util.Scanner;

class Vehicle
{
	private int license_number, speed;
	private String color, owner_name;
	
	Vehicle(int lc, int s, String c, String ow)
	{
		license_number = lc;
		speed = s;
		color = c;
		owner_name = ow;
	}
	
	void showdata()
	{
		System.out.println("License Number: "+license_number);
		System.out.println("Speed: "+speed);
		System.out.println("Color: "+color);
		System.out.println("Owner Name: "+owner_name);
	}
	
	
}


class Car extends Vehicle
{
	private int route_no;
	
	Car(int lc, int s, String c, String ow, int rn)
	{
		super(lc, s, c, ow);
		route_no = rn;
	}
	
	void showdata()
	{
		super.showdata();
		System.out.println("Route no : "+route_no);
	}
	
}


class Bus extends Vehicle
{
	private String manufacturer_name;
	
	Bus(int lc, int s, String c, String ow, String mn)
	{
		super(lc, s, c, ow);
		manufacturer_name = mn;
	}
	
	void showdata()
	{
		super.showdata();
		System.out.println("Manufacturer Name : "+manufacturer_name);
	}
}

class Driver
{
	public static void main(String args[])
	{
	Scanner sc = new Scanner(System.in);
	int lc, s, rn; 
  String c, ow, mn;
  
	System.out.println("Enter the License Number: ");
	lc = sc.nextInt();
  System.out.println("Enter the Speed: ");
  s = sc.nextInt();
	System.out.println("Enter the Color: ");
	c = sc.next();
	System.out.println("Enter the Owner Name: ");
	ow = sc.next();
	
	System.out.println("Enter the Manufacturer Name: ");
	mn = sc.next();
	System.out.println("Enter the Route Number: ");
	rn= sc.nextInt();
	
  Bus b = new Bus(lc, s, c, ow, mn);
  b.showdata();
  }
}
