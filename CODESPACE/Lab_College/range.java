import java.util.Scanner;

public class range {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter n: ");
        n = sc.nextInt();

        try{
            if(n<0)
                throw new Exception();
        }
        catch(Exception e){
            System.out.println("The value cannot be -ve.");
            System.exit(0);
        }
            long[] arr = new long[n+1];
            arr[0] = 1;
        for(int i=1; i<=n; i++){
            try {
                arr[i] = i * arr[i - 1];
                if(arr[i]<0)
                    throw new Exception();
            }
            catch(Exception e){
                System.out.println("Value out of range.");
                System.exit(1);
            }
        }
        System.out.println(arr[n]);
    }
}