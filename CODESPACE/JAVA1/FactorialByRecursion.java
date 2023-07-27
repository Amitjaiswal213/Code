import java.util.Scanner;
public class FactorialByRecursion{
    
    static int fact=1;
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter the no- ");
        int no=s.nextInt();
        FactorialByRecursion ob = new FactorialByRecursion();
        ob.calcFact(no);
        System.out.println("The factorial of "+no +" is: " +fact);


    }
    void calcFact(int no)
    {
        if(no>=1)
        {
            fact=fact*no;
            calcFact(no-1);
        }
    }
}

//NOT COMPLETELY UNDERSTAND!!!