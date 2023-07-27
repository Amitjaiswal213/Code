import java.util.Scanner;
public class FibonacciSeries {
    public static void main(String[] args){
        Scanner s= new Scanner(System.in);
        System.out.print("How many times you want to execute the Fibonacci Series- ");
        int no= s.nextInt();
        System.out.print("Enter the value of a- ");
        int a= s.nextInt();
        System.out.print("Enter the value of b- ");
        int b=s.nextInt();

        for(int i=1; i<=no; i++)
        {
            int c;
            c=a+b;
            System.out.println(c);
            a=b;
            b=c;
        }
    }
}
