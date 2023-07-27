package mypack;

public class math {
    public static void add(int x, int y){
        System.out.println("Addition = "+(x+y));
    }

    public static void sub(int x,int y){
        System.out.println("Subtraction = "+(x-y));

    }

    public static void div(int x, int y){
        if(y!=0)
            System.out.println("Division = "+((float)x/y));
        else
            System.out.println("Division by 0: Invalid");
    }

    public static void multiply(int x, int y)
    {
        System.out.println("Multiplication = "+(x*y));
    }
}
