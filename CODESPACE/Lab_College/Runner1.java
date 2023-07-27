import pack1.Mathop;
import java.util.Scanner;
public class Runner1 {
    public static void main(String[] args) {
        int x,y;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the two numbers ");
        x=s.nextInt();
        y=s.nextInt();
        Mathop ob= new Mathop(x,y);
        System.out.println(ob.add());
    }
}
