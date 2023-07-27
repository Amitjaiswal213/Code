import java.util.Scanner;
public class UserInput {
    public static void main(String[] args){

         Scanner s =new Scanner(System.in);

         System.out.print("Enter your name- ");
         String name = s.next();
         System.out.print("Enter your age- ");
         int age = s.nextInt();
         System.out.print("Enter your gender- ");
         char gender = s.next().charAt(0);
         System.out.print("Enter your Phno - ");
         long phno = s.nextLong();

         System.out.println("Name : "+name);
         System.out.println("Age : "+age);
         System.out.println("Gender : "+gender);
         System.out.println("Phno : "+phno);


    }
    
}
