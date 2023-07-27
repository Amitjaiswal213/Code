import java.util.Scanner;
public class Hostel implements Department
{
	String hostelName, hostelLocation;
	int noOfRoom;
	
	public void getData()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the hostel name");
		hostelName = sc.next();
		System.out.println("Enter the hostel location");
 	 	hostelLocation = sc.next();
		System.out.println("Enter the number of rooms");
		noOfRoom = sc.nextInt();
	}
	
	public void printData()
	{
	 System.out.println("Department Name: "+depName);
	 System.out.println("Department Head: "+depHead);
	 System.out.println("Hostel Name: "+hostelName);
	 System.out.println("Hostel Location: "+hostelLocation);
	 System.out.println("Number of Rooms: "+noOfRoom);
	}
}

class Student extends Hostel implements Department
{
	String studentName, electiveSubject;
	int regNo, avgMarks;
	
	public void getData()
	{
	
		Scanner sc = new Scanner(System.in);
		super.getData();
		System.out.println("Enter the Student Name");
		studentName = sc.next();
		System.out.println("Enter the Elective Subject");
 	 	electiveSubject = sc.next();
		System.out.println("Enter the Registration Number");
		regNo = sc.nextInt();
		System.out.println("Enter the average Marks");
		avgMarks = sc.nextInt();
	}
	
	public void printData()
	{
	 super.printData();
	 System.out.println("Student Name: "+studentName);
	 System.out.println("electiveSubject: "+electiveSubject);
	 System.out.println("Registration Number: "+regNo);
	 System.out.println("Average Marks: "+avgMarks);
	}
}


class Driver
{
 public static void main(String args[])
 {
 	Student s = new Student();
 	s.getData();
 	s.printData();
 }
}
