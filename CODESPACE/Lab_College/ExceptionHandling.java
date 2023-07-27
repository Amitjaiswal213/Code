import java.util.Scanner;

public class ExceptionHandling {
    public static void main(String args[]){
        System.out.println("Enter your Email");
    String email;
    Scanner sc=new Scanner(System.in);
    email=sc.next();
    try
    {
        if (email.indexOf("@gmail.com") != email.lastIndexOf("@gmail.com"))
            throw new Exception();
        if (email.length() < 11)
            throw new Exception();
        System.out.println("Valid");
    }
    catch(Exception e)
    {
        System.out.println("Invalid");

    }
 }
}