import java.util.Scanner;

abstract class ThreeDObject
{
	abstract void wholeSurfaceArea();
	abstract void volume();
}


//BOX
class Box extends ThreeDObject
{
	private int length, breadth, height;
	Box(int l, int b, int h)
	{
		length = l;
		breadth = b;
		height = h;
	}
	
	void wholeSurfaceArea()
	{
		double area = 2 * (length*breadth + breadth*height + height*length);
		System.out.println("Area of Box: "+area);
	}
	
	void volume()
	{
		double volume = length * breadth * height;
		System.out.println("Volume of Box: "+volume);
	}
}

//CUBE
class Cube extends ThreeDObject
{
	private int a;
	Cube(int a)
	{
		this.a = a;
	}
	
	void wholeSurfaceArea()
	{
		double area = 6 * a * a;
		System.out.println("Area of Cube: "+area);
	}
	
	void volume()
	{
		double volume = a * a * a;
		System.out.println("Volume of Cube: "+volume);
	}
}


//CYLINDER
class Cylinder extends ThreeDObject
{
	private int radius, height;
	Cylinder(int r, int h)
	{
		radius = r;
		height = h;
	}
	
	void wholeSurfaceArea()
	{
		double area = 2 * Math.PI * radius * (radius + height);
		System.out.println("Area of Cylinder: "+area);
	}
	
	void volume()
	{
		double volume = Math.PI * radius * radius * height;
		System.out.println("Volume of Cylinder: "+volume);
	}
}

//CONE
class Cone extends ThreeDObject
{
	private int radius, height;
	Cone(int r, int h)
	{
		radius = r;
		height = h;
	}
	
	void wholeSurfaceArea()
	{
	
		double l = Math.sqrt(height * height + radius * radius);  //slant height l
		double area = Math.PI * radius * (radius + l);
		System.out.println("Area of Cone: "+area);
	}
	
	void volume()
	{
		double volume = (1 / 3.0) *  Math.PI * radius * radius * height;
		System.out.println("Volume of Cone: "+volume);
	}
}


//DRIVER
class Driver
{
 public static void main(String args[])
 {
 	Scanner sc = new Scanner(System.in);
 
 	int l, b, h, r, a;
	 //BOX
	 System.out.println("Enter the length breadth and height of the Box:");
	  l = sc.nextInt(); 
	  b = sc.nextInt();
	  h = sc.nextInt(); 
	 Box bo = new Box(l, b, h);
	 bo.wholeSurfaceArea();
	 bo.volume();
	 
	 //CUBE
	 System.out.println("Enter the side of the Cube:");
	 a = sc.nextInt(); 
	 Cube cu = new Cube(a);
	 cu.wholeSurfaceArea();
	 cu.volume();
	 
	 //CYLINDER
	 System.out.println("Enter the radius and height of the Cylinder:");
	 r = sc.nextInt(); 
	 h = sc.nextInt(); 
	 Cylinder cy = new Cylinder(r,h);
	 cy.wholeSurfaceArea();
	 cy.volume();
	 
		//CONE
	 System.out.println("Enter the radius and height of the Cone:");
	 r = sc.nextInt(); 
	 h = sc.nextInt(); 
	 Cone co = new Cone(r, h);
	 co.wholeSurfaceArea();
	 co.volume();
  }
 
 }

