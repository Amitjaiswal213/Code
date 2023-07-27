import mypack.math;
import java.util.Scanner;
public class Runner {
    public static void main(String[] args) {
        int a,b,c;
        Scanner s = new Scanner(System.in);
        while(true) {
            System.out.print("-----MAIN MENU-----\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nEnter your choice: ");
            c = s.nextInt();
            System.out.print("Enter two numbers: ");
            a = s.nextInt();
            b = s.nextInt();
            math Op = new math();
            switch (c){
                case 1:
                    Op.add(a,b);
                    break;
                case 2:
                    Op.sub(a,b);
                    break;
                case 3:
                    Op.multiply(a,b);
                    break;
                case 4:
                    Op.div(a,b);
                    break;
                case 5:
                    System.exit(0);
                default:
                    System.out.println("Kindly enter valid choice");

            }
        }
    }
}
