import java.util.Scanner;
public class factorial {
    long fact(long n) {
        if(n==0 || n==1)
        return 1;
        return n* fact (n-1);
    }    
}
class Driver{
    public static void main(String args[]){
        factorial obj=new factorial();
        long n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number");
        n=sc.nextLong();
        long f=obj.fact(n);
        System.out.println("Factorial of " +n+ " is " +f);
    }
}
